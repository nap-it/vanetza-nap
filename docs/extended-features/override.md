# MAC & Position Override


<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Vanetza-NAP supports per-message station identity overrides: a single running instance can transmit ITS messages that appear to originate from any number of different stations, each with a distinct MAC address, GeoNetworking identity, and position vector. This is set entirely from the JSON payload published to the input topic — no configuration change or restart is required.

---

## Why This Matters

A standard ITS station has a fixed identity: one MAC address, one station ID, one GeoNetworking address. This is appropriate for a vehicle or roadside unit in a real deployment. But there are important scenarios where a single Vanetza-NAP instance needs to represent multiple stations simultaneously:

<o>Datacenter-scale simulation</o> — a server running one Vanetza-NAP instance connected to a UDP multicast network can emulate an entire fleet of vehicles. Each simulated vehicle sends its own CAMs with its own identity. Without MAC override, all messages would appear to come from the same station, making the simulation useless for testing systems that track individual vehicles.

<o>Digital twin and replay</o> — when replaying recorded ITS traffic for testing or analysis, the original station identities need to be preserved. A replay system can publish the original `stationID` in each JSON message and have Vanetza-NAP transmit it as if it were the original sender.

<o>Multi-station RSU emulation</o> — a traffic management testbed may need to emulate several RSUs at different locations, all driven by the same backend, each appearing as a distinct network entity to vehicles under test.

---

## How It Works

### The stationID Field

Every application checks for a `stationID` field in the inbound JSON message. If present and non-negative, it is treated as an override for the transmitting station's identity. If absent or `-1`, the instance's own station ID from `config.ini` is used as the fallback.

```json
{
  "stationID": 42001,
  "cam": { ... }
}
```

### MAC Address Derivation

The MAC address is not supplied directly in the JSON — it is **derived deterministically from the station type and station ID** using a fixed algorithm:

```
MAC = 6e:06:e0:[type_byte]:[id_high]:[id_low]
```

Where:
- `6e:06:e0` — fixed NAP prefix
- `[type_byte]` — `0x01` for RSU (station type 15), `0x02` for passenger car (station type 5), `0x00` for all others
- `[id_high]` — `station_id / 255`
- `[id_low]` — `station_id % 255`

For example, station ID `42001` of type RSU (15) produces:

```
station_id = 42001
id_high = 42001 / 255 = 164
id_low  = 42001 % 255 = 241 (0xF1)
type    = RSU → 0x01

MAC = 6e:06:e0:01:a4:f1
```

This means any two components that know the station type and ID can independently compute the expected MAC address — there is no lookup table or coordination required.

### GeoNetworking Position Override

The MAC address override alone is not sufficient. GeoNetworking embeds the sender's MAC address inside the **Long Position Vector** (LPV) carried in every packet header. If only the Ethernet source MAC is overridden, the LPV would still carry the real instance MAC, creating an inconsistency that receiving stations and security entities would detect.

`apply_station_overrides` therefore sets both:

1. `source_mac_override` — overrides the Ethernet frame source address
2. `source_position_override` — takes the current local position vector and replaces its embedded GeoNetworking address with the derived MAC, then passes this as the source LPV for the packet

This ensures the transmitted packet is fully consistent: the Ethernet header, the GeoNetworking header, and the position vector all carry the same overridden identity.

---

## What Changes in the Message

When a `stationID` override is active, the application also sets the `stationId` field inside the ASN.1 message itself to match, and uses the derived MAC as the `stationAddr` in the published time and output topics. The entire chain — wire packet, GeoNetworking header, ITS message content, and pub/sub metadata — is consistent with the overridden identity.

---

## Use Cases Summary

| Scenario | How it's used |
|---|---|
| Fleet simulation | Publish CAMs with different `stationID` values from one instance |
| Traffic replay | Preserve original `stationID` from recorded data |
| RSU emulation | Drive multiple RSU identities from one backend service |
| Multi-vehicle testbed | One Vanetza-NAP per server, many simulated vehicles per instance |

---

## Ease of Use

From the perspective of the service publishing the message, the override requires adding a single field to the JSON:

```json
{ "stationID": 12345, "cam": { ... } }
```

No configuration change, no restart, no per-station instance. The MAC is computed automatically, the GeoNetworking headers are patched transparently, and the transmitted packet is indistinguishable from one originating from a dedicated physical station with that identity.
