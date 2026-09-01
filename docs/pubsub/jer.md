# Encoding & Decoding

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Every ITS message that enters or leaves Vanetza-NAP crosses a boundary between two representations: the binary ASN.1 structure used by the ITS stack, and the JSON used by the pub/sub middleware. This page explains why that boundary exists, why JSON is the right representation on the middleware side, and how the conversion is implemented.

---

## Why JSON?

ITS messages are defined in ASN.1 and transmitted over the air as compact binary encodings (UPER or COER). This is appropriate for a radio medium where bandwidth is constrained. But binary ASN.1 is a poor interface for everything else in the system.

Consider the services that need to consume or produce ITS messages in a real deployment, none of these speak ASN.1 natively. Requiring every service to link against an ASN.1 codec, understand the ITS type hierarchy, and handle binary framing creates a steep integration barrier.

JSON removes that barrier entirely. It is the universal data format of modern software:

- <o>Every language has a JSON library</o> — no codec dependency, no custom toolchain.
- <o>Self-describing</o> — field names are part of the message, so consumers can extract only the fields they care about without understanding the full ASN.1 schema.
- <o>Native to pub/sub middlewares</o> — MQTT, DDS, and Zenoh all work naturally with string or byte payloads; JSON strings map directly onto these transports with no additional framing.

The result is that services integrating with Vanetza-NAP never need to know anything about ASN.1. They subscribe to a topic, receive a JSON object, and read the fields they need by name.

---

## ASN.1 Integers Are Not Human-Readable

There is one complication in the ASN.1 → JSON conversion: ITS messages store physical values as scaled integers. The standard does this to avoid floating-point arithmetic in constrained environments, but the raw values have no meaning without knowing the divisor:

| Field | Raw ASN.1 value | Human-readable |
|---|---|---|
| Latitude | `401234567` | `40.1234567°` |
| Longitude | `-86543210` | `-8.6543210°` |
| SpeedValue | `1523` | `15.23 m/s` |
| AltitudeValue | `35000` | `350.00 m` |
| HeadingValue | `1800` | `180.0°` |

Publishing raw integers to the middleware would defeat the purpose of using JSON — a consumer seeing `"latitude": 401234567` would need to know the ETSI-defined divisor for that specific type, which is exactly the kind of ITS-specific knowledge we want to keep out of downstream services. The encoder applies these transformations automatically so that every JSON field carries an immediately usable value in SI units.

---

## The Legacy Approach: asn1json.py

The original solution used a Python script (`asn1json.py`) that code-generated a C++ file (`asn1json.cpp`) containing hand-written conversion functions for every ASN.1 type. The result was a 25,800-line file that post-processed JSON after encoding: encode to binary → decode to internal representation → convert to RapidJSON → loop through all fields → apply divisors.

This worked, but had significant drawbacks:

- <o>Multi-pass</o>: encode and decode pipelines were separate, each requiring a full traversal.
- <o>O(n) lookup</o>: for every integer field, the code linearly searched a list of ~40 known types to find its divisor.
- <o>Hard to maintain</o>: adding a new message type meant editing the Python generator, regenerating the C++ file, and rebuilding.
- <o>Large footprint</o>: 25,800+ lines of generated code that is difficult to audit.

---

## The New Approach: JER-RapidJSON Library

The replacement is a custom library in `vanetza/asn1/rj/` that encodes ASN.1 structures **directly to RapidJSON objects**, applying unit transformations in a single pass during traversal. There is no intermediate string or binary representation.

### Encoding: ASN.1 → RapidJSON

The encoder walks the ASN.1 type descriptor tree recursively, dispatching to type-specific handlers:

| ASN.1 type | Output |
|---|---|
| SEQUENCE | JSON object |
| SEQUENCE OF | JSON array |
| CHOICE | JSON object with the chosen alternative |
| INTEGER | JSON number, with transformation applied if applicable |
| BOOLEAN | `true` / `false` |
| ENUMERATED | integer |
| BIT STRING | JSON object with named boolean fields (or hex fallback) |
| String types | JSON string |

The key insight is that the encoder works directly against the `asn_TYPE_descriptor_t` — the C structure that `asn1c` generates for every ASN.1 type. This descriptor already contains everything needed: field names, types, offsets, and optionality constraints. The encoder reads this metadata at runtime to construct the JSON object, rather than relying on any generated conversion code. 

The public API offers three variants depending on what the caller needs:

- **`jer_encode_rj`** — encodes into a `rapidjson::Value` using a caller-supplied allocator. Used when the result needs to be merged into an existing document (e.g. to add `rssi` or `timestamp` fields alongside the message).
- **`jer_encode_rj_doc`** — encodes into a self-contained `rapidjson::Document` that owns its own allocator. Convenient when the document will be serialized immediately or passed to the decoder.
- **`jer_encode_rj_string`** — encodes and serializes to a `std::string` in one call. Used when only the string is needed and no further manipulation is required.

### Decoding: RapidJSON → ASN.1

The decoder is the reverse path: it takes a parsed `rapidjson::Document` (or `Value`) and populates an ASN.1 structure in memory. It follows the same descriptor-driven approach — for each field in the ASN.1 type descriptor, it looks up the corresponding JSON key by name, reads the value, applies the reverse transformation (multiply instead of divide), and writes it into the correct memory offset of the C structure. Optional fields that are absent from the JSON are left unset.

Two variants are available:

- **`jer_decode_rj_inplace`** — populates a pre-allocated structure. This is the typical path used by applications, since they own an `asn1::Cam` (or equivalent) wrapper whose memory is managed by the wrapper's destructor.
- **`jer_decode_rj`** — allocates a new structure and returns it. The caller is responsible for freeing it with `ASN_STRUCT_FREE`.

Both support an optional verbose error mode that returns the JSON path where the decode failed, which is useful during development.

---

## Unit Transformations

Transformations are defined in `vanetza/asn1/rj/transformations/` as a gperf perfect hash table. Each entry maps an ASN.1 type name to a scale factor and a list of sentinel (unavailable) values.

How the lookup works:

1. During encoding/decoding, when an integer node is visited, `jer_find_transform(type_name)` is called.
2. gperf computes a hash of the type name in O(1) — no linear search, no string comparison loop.
3. If a match is found, the scale factor is retrieved.
4. If the value matches one of the sentinels (e.g. `900000001` for Latitude = "unavailable"), it is passed through unchanged. Otherwise the transformation is applied.

The complete transformation table (partial):

| Type | Scale | Sentinel values |
|---|---|---|
| Latitude | ÷ 10⁷ | 900000001 |
| Longitude | ÷ 10⁷ | 1800000001 |
| AltitudeValue | ÷ 10² | 800001 |
| SpeedValue | ÷ 10² | 16383 |
| HeadingValue | ÷ 10 | 3601 |
| Curvature | ÷ 10⁴ | 1023 |
| LongitudinalAcceleration | ÷ 10 | 161 |
| YawRate | ÷ 10² | 32767 |
| TimestampIts | ÷ 10³ | — |

See `vanetza/asn1/rj/transformations/jer_transformations.cpp` for the full list.

---

## BIT STRING Named Bits

Some ASN.1 types use BIT STRING to represent a set of boolean flags. Raw BIT STRING output (a hex string) is not useful for consumers. The library maps known types to their named bit positions, producing a JSON object with one boolean field per bit:

```json
{
  "lowBeamHeadlightsOn": true,
  "highBeamHeadlightsOn": false,
  "leftTurnSignalOn": true,
  "rightTurnSignalOn": false
}
```

The bit name lookup works the same way as transformations: `jer_find_bitnames(type_name)` returns a `jer_bitnames_entry` containing an array of names indexed by bit position. Supported types include `ExteriorLights`, `AccelerationControl`, `GNSSstatus`, `LightBarSirenInUse`, `EnergyStorageType`, and others.

Types not in the table fall back to a hex representation: `{"value": "C0", "length": 7}`.

---

## Performance

The library is designed for the tight loop of receiving and publishing ITS messages in a live deployment:

- <o>Single-pass</o>: the ASN.1 tree is walked once. There is no encode-to-string followed by parse-from-string.
- <o>O(1) lookups</o>: both transformation and bit name lookups use gperf perfect hashes — no linear search, no `std::map`, no `strcmp` loop.
- <o>No intermediate allocation</o>: encoding directly into a `rapidjson::Value` avoids the intermediate string buffer of the old approach.

Compared to the legacy `asn1json.py` approach for a CAM with ~20 integer fields: the old code performed up to 800 string comparisons (20 fields × ~40 transformation entries). The new code performs 20 O(1) hash lookups.

---

## Why This Approach Is Robust

Because the encoder and decoder operate directly on the `asn_TYPE_descriptor_t` structures generated by `asn1c`, they are inherently correct by construction. The descriptor is the authoritative source of truth for an ASN.1 type's structure — field names, types, nesting, and optionality all come from the same metadata that the ITS stack itself uses to encode and decode messages over the air. There is no separate conversion layer that could fall out of sync with the schema.

This has a particularly important consequence when adding new message types. Supporting a new ITS message — a new release of CPM, a new message class, or a future standard — requires only compiling the new `asn1c`-generated C code into the project. The encoder and decoder automatically handle the new type without any changes to the library. No conversion functions to write, no code generator to run, no thousands of lines of code to regenerate, no risk of an undefined reference or a missed field.

The transformation and named bit tables are the only additions that may be needed for a new type, and only when that type introduces new scaled integer fields or BIT STRING types not already in the table. These are small, declarative additions — a single line per entry — completely independent of the core encode/decode logic. Everything else works out of the box.

The end result is a conversion layer that is specification-correct, zero-maintenance for new message types, and immune to the class of bugs that plague code-generated approaches: stale generated files, mismatched schema versions, and missing type coverage.

---

## Extending the Library

<o>Adding a new unit transformation</o> — edit `vanetza/asn1/rj/transformations/jer_transformations.cpp`, add an entry with the ASN.1 type name, scale factor, and any sentinel values. Rebuild and the gperf hash is regenerated automatically.

<o>Adding named bits for a new BIT STRING type</o> — edit `vanetza/asn1/rj/bitnames/jer_bitnames.cpp`, add a `BITNAMES(TypeName, "bit0", "bit1", ...)` macro and register it in the lookup table.

Neither change requires modifying the encoder or decoder dispatch logic.