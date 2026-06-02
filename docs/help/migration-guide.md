# NAP Vanetza Migration Guide
## From NAP Fork → Clean github-vanetza + NAP Features

**Goal:** Start with latest github-vanetza (V2/V3 security with certificates, UDP, VAMv2, MAPEM/SPATEM/SSEM/etc...V2.1.1, bug fixes) and add all NAP custom features.


**Repository Structure:**
- **Base:** `vanetza-nap` repository, branch `og` (contains original github-vanetza)
- **Target:** Create `release2` branch from `og` for migration
- **Reference:** `vanetza-nap-atcll` clone (default branch with all NAP custom features)

**Scope:**
- Include: 10 core applications (CAM, DENM, CPM, VAM, SPATEM, MAPEM, SSEM, SREM, RTCMEM, IVIM)
- Exclude initially: MCM (to be added later)
- Drop permanently: EVCSNM, EVRSRM, IMZM, TIS-TPG
- Add later: AVM (after migration is stable)
---

## Overview

This migration follows a **dependency-ordered approach**, ensuring each component is built on top of working foundations.

### Migration Phases

| Phase | Components | Validation |
|-------|------------|------------|
| **Phase 0: Preparation** | Setup, analysis | Environment ready |
| **Phase 1: Foundation** | ASN.1 JSON, Config, Main | JSON conversion works (hardcoded if necessary) |
| **Phase 2: Core Features** | Pub/Sub, Applications, Multi-threading | Integration Tests Script between 2 APUs |
| **Phase 3: Extended** | RSSI, Metadata, Filtering, Overrides | Full feature parity |
---

# Phase 0: Preparation

## Step 0.1: Create Clean Base

```bash
cd /home/nap

# Clone vanetza-nap repository
git clone https://code.nap.av.it.pt/mobility-networks/vanetza-nap.git

# Navigate to repository
cd vanetza-nap

# Checkout the 'og' branch (contains original github-vanetza)
git checkout og

# Create release2 branch from og for clean migration
git checkout -b release2

# Tag the base for reference
git tag baseline-github-vanetza

# Clone a second copy for reference to NAP features (default branch)
cd /home/nap
git clone https://code.nap.av.it.pt/mobility-networks/vanetza-nap.git vanetza-nap-atcll
# This second clone will be on default branch with all NAP custom features
```

## Step 0.2: Remove Unwanted Components

These are not needed for NAP deployment:

```bash
cd /home/nap/vanetza-nap

# Remove hardware support we don't use
rm -f tools/socktap/cohda*
rm -f tools/socktap/autotalks*
rm -f tools/socktap/nfiniity_cube*

# Remove example applications
rm -f tools/socktap/hello_application.*

# Remove benchmarking tools
rm -rf tools/benchmark
rm -rf tools/fuzz-harness

# Remove other unused tools...
```

**Update CMakeLists.txt:**

Edit `CMakeLists.txt` (root):
```cmake
# Comment out or remove unused modules
# ...
```

Edit `tools/socktap/CMakeLists.txt`:
- Remove references to cohda, autotalks, nfiniity_cube, hello_application
- Remove conditional hardware support sections
- Ensure only core applications and features remain without breaking dependencies

## Step 0.3: Verify Base Builds

```bash
# Test that clean github-vanetza builds
docker build -t vanetza-github-baseline .
```

**Expected:** Should build successfully with V2/V3 security support.

---

# Phase 1: Foundation - ASN.1 JSON Encoder/Decoder & Configuration

## Overview

Phase 1 implements a custom **JER-RapidJSON encoder and decoder** that converts between ASN.1 structures and RapidJSON objects with automatic unit transformations. This replaces the old `asn1json.py` approach.

**Key Benefits:**
- Direct conversion between `rapidjson::Value`/`Document` and ASN.1 structures
- O(1) gperf-based unit transformation lookup (encode: divide, decode: multiply)
- Human-readable BIT STRING output with named bits
- ~100-200µs encoding/decoding time for typical CAMs
- Easy to maintain (no code generation required)
- Roundtrip support: ASN.1 → JSON → ASN.1

**Implementation Guide:** See `RAPIDJSON_JER_IMPLEMENTATION_GUIDE.md` for full details.

---

## Step 1.1: Verify ASN.1 Schemas

GitHub-vanetza has pre-generated C code for Release 2 schemas:
- `vanetza/asn1/its/r2/` - ITS messages (`Vanetza_ITS2_` prefix)
- `vanetza/asn1/security/r2/` - Security (`Vanetza_Security2_` prefix)

We use these as-is. No schema modifications needed.

**Messages included (10 total):**
- CAM, DENM, CPM, VAM (Release 2)
- SPATEM, MAPEM, SSEM, SREM, RTCMEM, IVIM (v2.1.1)

**Excluded:** MCM (later), AVM (later), EVCSNM, EVRSRM, IMZM, TIS-TPG (dropped)

---

## Step 1.2: Create JER-RapidJSON Encoder/Decoder Library

The encoder and decoder live in `vanetza/asn1/rj/` with this structure:

```
vanetza/asn1/rj/
├── CMakeLists.txt                # Library build config
│
├── jer_rj_encode.hpp             # Encoder public API
├── jer_rj_encode.cpp             # Encoder entry points
├── jer_rj_encode_types.hpp       # Encoder internal declarations
│
├── jer_rj_decode.hpp             # Decoder public API
├── jer_rj_decode.cpp             # Decoder entry points
├── jer_rj_decode_types.hpp       # Decoder internal declarations
│
├── jer_rj_context.hpp            # Shared allocator wrapper
│
├── encoders/                     # Type-specific encoders
│   ├── dispatcher.cpp            # Routes by ASN.1 type
│   ├── integer_rj.cpp            # Integers with transforms (÷ scale)
│   ├── sequence_rj.cpp           # SEQUENCE → Object
│   ├── choice_rj.cpp             # CHOICE → Object
│   ├── sequence_of_rj.cpp        # SEQUENCE OF → Array
│   ├── boolean_rj.cpp            # BOOLEAN → true/false
│   ├── enumerated_rj.cpp         # ENUMERATED → integer
│   ├── string_rj.cpp             # String types
│   └── bitstring_rj.cpp          # BIT STRING → named bits
│
├── decoders/                     # Type-specific decoders
│   ├── dispatcher.cpp            # Routes by ASN.1 type + get_struct_size()
│   ├── integer_rj.cpp            # Integers with transforms (× scale)
│   ├── sequence_rj.cpp           # Object → SEQUENCE
│   ├── choice_rj.cpp             # Object → CHOICE
│   ├── sequence_of_rj.cpp        # Array → SEQUENCE OF
│   ├── boolean_rj.cpp            # true/false → BOOLEAN
│   ├── enumerated_rj.cpp         # integer → ENUMERATED
│   ├── string_rj.cpp             # String types
│   └── bitstring_rj.cpp          # Named bits or hex → BIT STRING
│
├── transformations/              # Unit transformations (gperf) - SHARED
│   ├── jer_transformations.gperf # Source definitions
│   ├── jer_transformations.hpp   # Header
│   └── jer_transformations.cpp   # Generated (committed)
│
└── bitnames/                     # Named bits for BIT STRING - SHARED
    ├── jer_bitnames.hpp          # Lookup header
    └── jer_bitnames.cpp          # Type definitions
```

---

## Step 1.3: Implement Unit Transformations (gperf)

The transformation system uses gperf for O(1) lookup of type-specific unit conversions. Transformations are **shared** between encoder and decoder.

**Key transformations:**
| Type | Encode (÷) | Decode (×) | Unavailable (sentinel) |
|------|------------|------------|------------------------|
| Latitude | ÷10,000,000 | ×10,000,000 | 900000001 |
| Longitude | ÷10,000,000 | ×10,000,000 | 1800000001 |
| SpeedValue | ÷100 | ×100 | 16383 |
| HeadingValue | ÷10 | ×10 | 3601 |
| AltitudeValue | ÷100 | ×100 | 800001 |
| TimestampIts | ÷1000 | ×1000 | (none) |

**Sentinel values** are "unavailable" indicators that are output as-is (integers, no transformation).

**To regenerate** (only when adding/modifying transforms):
```bash
cd vanetza/asn1/rj/transformations
gperf --language=C++ --struct-type --readonly-tables \
    jer_transformations.gperf > jer_transformations.cpp
```

The generated `jer_transformations.cpp` is committed to the repo. No gperf needed at build time.

---

## Step 1.4: Implement Named Bits for BIT STRING

BIT STRING types output as objects with boolean fields:

```json
{
  "lowBeamHeadlightsOn": true,
  "highBeamHeadlightsOn": false,
  "leftTurnSignalOn": true,
  ...
}
```

**Supported types:** ExteriorLights, AccelerationControl, GNSSstatus, LightBarSirenInUse, EnergyStorageType, and more.

**To add a new BIT STRING type**, edit `bitnames/jer_bitnames.cpp`:
```cpp
BITNAMES(MyType, "bit0name", "bit1name", "bit2name");
// ... then add to lookup table:
ENTRY(MyType),
```

Unknown types fall back to hex format: `{"value": "C0", "length": 7}`

---

## Step 1.5: Update CMakeLists

**Add to `vanetza/asn1/CMakeLists.txt`:**
```cmake
add_subdirectory(rj)
```

**Add to `tools/socktap/CMakeLists.txt`:**
```cmake
target_link_libraries(socktap PRIVATE asn1_rj)
```

The `asn1_rj` library handles RapidJSON discovery (system or vendored).

---

## Step 1.6: Copy Configuration System

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy configuration files from NAP reference
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.cpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config_reader.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.ini .

# Copy entrypoint script
cp /home/nap/vanetza-nap-atcll/entrypoint.sh ../../
chmod +x ../../entrypoint.sh
```

---

## Step 1.7: Usage in Applications

### Encoding: ASN.1 → JSON

**Option 1: Encode to Document (Recommended)**
```cpp
#include <vanetza/asn1/rj/jer_rj_encode.hpp>
#include <vanetza/asn1/cam.hpp>

void on_cam_received(const vanetza::asn1::Cam& cam, int rssi) {
    // Encode CAM to self-contained Document
    rapidjson::Document doc = vanetza::asn1::rj::jer_encode_rj_doc(
        &asn_DEF_Vanetza_ITS2_CAM,
        cam.content()
    );

    // Add custom metadata
    doc.AddMember("rssi", rssi, doc.GetAllocator());
    doc.AddMember(rapidjson::StringRef("source"),
                  rapidjson::StringRef("its-g5"), doc.GetAllocator());

    // Serialize to string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    publish_to_mqtt(buffer.GetString(), buffer.GetSize());
}
```

**Option 2: Encode to Value (when you already have a Document)**
```cpp
rapidjson::Document doc;
auto& alloc = doc.GetAllocator();

rapidjson::Value json = vanetza::asn1::rj::jer_encode_rj(
    &asn_DEF_Vanetza_ITS2_CAM,
    cam.content(),
    alloc
);
```

**Option 3: Encode directly to string**
```cpp
std::string json_str = vanetza::asn1::rj::jer_encode_rj_string(
    &asn_DEF_Vanetza_ITS2_CAM,
    cam.content()
);
```

### Decoding: JSON → ASN.1

**Option 1: Decode in-place (Recommended for wrappers)**
```cpp
#include <vanetza/asn1/rj/jer_rj_decode.hpp>
#include <vanetza/asn1/cam.hpp>

void on_json_received(const char* json_str) {
    // Parse JSON
    rapidjson::Document doc;
    doc.Parse(json_str);

    // Decode into wrapper (memory managed automatically)
    vanetza::asn1::Cam cam;
    bool success = vanetza::asn1::rj::jer_decode_rj_inplace(
        &asn_DEF_Vanetza_ITS2_CAM,
        cam.content(),
        doc
    );

    if (success) {
        // Use cam for transmission
        transmit_cam(cam);
    }
}
```

**Option 2: Decode with allocation (caller must free)**
```cpp
auto result = vanetza::asn1::rj::jer_decode_rj(
    &asn_DEF_Vanetza_ITS2_CAM,
    doc
);

if (result) {
    Vanetza_ITS2_CAM_t* cam = static_cast<Vanetza_ITS2_CAM_t*>(result.structure);
    // Use cam...

    // IMPORTANT: Must free when done
    ASN_STRUCT_FREE(asn_DEF_Vanetza_ITS2_CAM, cam);
} else {
    std::cerr << "Decode error: " << result.error << std::endl;
}
```

### Complete Roundtrip Example

```cpp
#include <vanetza/asn1/rj/jer_rj_encode.hpp>
#include <vanetza/asn1/rj/jer_rj_decode.hpp>
#include <vanetza/asn1/cam.hpp>

void roundtrip_test(const vanetza::asn1::Cam& original_cam) {
    // 1. Encode to JSON Document
    auto t1 = std::chrono::high_resolution_clock::now();
    rapidjson::Document doc = vanetza::asn1::rj::jer_encode_rj_doc(
        &asn_DEF_Vanetza_ITS2_CAM,
        original_cam.content()
    );
    auto t2 = std::chrono::high_resolution_clock::now();

    // 2. Serialize to string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);
    auto t3 = std::chrono::high_resolution_clock::now();

    // 3. Parse JSON string (simulating network transmission)
    rapidjson::Document received_doc;
    received_doc.Parse(buffer.GetString());
    auto t4 = std::chrono::high_resolution_clock::now();

    // 4. Decode back to CAM
    vanetza::asn1::Cam decoded_cam;
    bool success = vanetza::asn1::rj::jer_decode_rj_inplace(
        &asn_DEF_Vanetza_ITS2_CAM,
        decoded_cam.content(),
        received_doc
    );
    auto t5 = std::chrono::high_resolution_clock::now();

    // Print timing
    using namespace std::chrono;
    std::cout << "Encode: " << duration_cast<microseconds>(t2 - t1).count() << " us\n";
    std::cout << "Stringify: " << duration_cast<microseconds>(t3 - t2).count() << " us\n";
    std::cout << "Parse: " << duration_cast<microseconds>(t4 - t3).count() << " us\n";
    std::cout << "Decode: " << duration_cast<microseconds>(t5 - t4).count() << " us\n";

    if (success) {
        // decoded_cam is now ready for transmission
    }
}
```

---

## Step 1.8: Test Build

```bash
cd /home/nap/vanetza-nap
mkdir -p build && cd build
cmake ..
make asn1_rj -j$(nproc)  # Build encoder/decoder library
make socktap -j$(nproc)  # Build socktap
```

**Expected:** Compiles successfully. Socktap won't fully run yet (needs pub/sub from Phase 2).

**Checkpoint:** JER-RapidJSON encoder/decoder library + configuration system compiles

---

## Phase 1 Complete

Phase 1 delivers:
- **Encoder**: ASN.1 → RapidJSON with automatic unit transformations
- **Decoder**: RapidJSON → ASN.1 with reverse transformations
- **Roundtrip**: Encode → Serialize → Parse → Decode works correctly
- **Performance**: ~100-200µs per encode/decode operation
- **Named bits**: Human-readable BIT STRING fields
- **Sentinel handling**: "Unavailable" values preserved correctly

---

# Phase 2: Core Features - Pub/Sub & Applications

## Step 2.1: Copy Pub/Sub Middleware Infrastructure

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy pub/sub core from NAP reference
cp /home/nap/vanetza-nap-atcll/tools/socktap/pubsub.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/pubsub.cpp .

# Copy MQTT integration
cp /home/nap/vanetza-nap-atcll/tools/socktap/mqtt.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/mqtt.cpp .

# Copy DDS integration
cp /home/nap/vanetza-nap-atcll/tools/socktap/dds.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/dds.cpp .

# Copy Fast-DDS IDL files
cp -r /home/nap/vanetza-nap-atcll/tools/socktap/fastdds ./

# Copy Zenoh configuration
cp /home/nap/vanetza-nap-atcll/tools/socktap/zenoh_config.json5 .
```

## Step 2.2: Update CMakeLists for Pub/Sub

Edit `tools/socktap/CMakeLists.txt`:

```cmake
# Find dependencies
find_package(zenohc REQUIRED)
find_package(zenohcxx REQUIRED)
find_package(Threads REQUIRED)

# Glob Fast-DDS generated sources
file(GLOB FASTDDS_SRC fastdds/*.cpp fastdds/*.cxx fastdds/*.hpp)

# Add to sources
set(SOCKTAP_SOURCES
    # ... existing ...
    pubsub.cpp
    pubsub.hpp
    mqtt.cpp
    mqtt.hpp
    dds.cpp
    dds.hpp
    ${FASTDDS_SRC}
)

# Link libraries
target_link_libraries(socktap PUBLIC
    mosquittopp
    fastrtps
    fastcdr
    zenohc::lib
    zenohcxx::zenohc
    Threads::Threads
)
```

## Step 2.3: Copy Application Base Class

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy application infrastructure from NAP reference
cp /home/nap/vanetza-nap-atcll/tools/socktap/application.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/application.cpp .
```

## Step 2.4: Copy Applications Directory

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Create applications directory
mkdir -p applications

# Copy application files (excluding MCM and dropped apps)
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/cam_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/denm_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/cpm_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/vam_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/spatem_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/mapem_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/ssem_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/srem_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/rtcmem_application.* applications/
cp /home/nap/vanetza-nap-atcll/tools/socktap/applications/ivim_application.* applications/

# Verify applications are present
ls applications/*.cpp | wc -l  # Should be 10
```

**Applications copied (10 total):**
- cam_application.cpp/hpp
- denm_application.cpp/hpp
- cpm_application.cpp/hpp
- vam_application.cpp/hpp
- spatem_application.cpp/hpp
- mapem_application.cpp/hpp
- ssem_application.cpp/hpp
- srem_application.cpp/hpp
- rtcmem_application.cpp/hpp
- ivim_application.cpp/hpp

**Excluded (not copied):**
- mcm_application (to be added later)
- evcsnm_application (dropped)
- evrsrm_application (dropped)
- imzm_application (dropped)
- tistpgm_application (dropped)

**To be added after migration:**
- avm_application (will be added once migration is stable)

## Step 2.5: Update CMakeLists for Applications

Edit `tools/socktap/CMakeLists.txt`:

```cmake
# Glob all application sources
file(GLOB APPLICATIONS_SRC applications/*.cpp applications/*.hpp)

# Add to sources
set(SOCKTAP_SOURCES
    # ... existing ...
    application.cpp
    application.hpp
    ${APPLICATIONS_SRC}
)
```

## Step 2.6: Copy Main Entry Point

The main.cpp in github-vanetza is different from NAP's. We need to adapt NAP's main to work with github-vanetza's structure.

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Backup github version
mv main.cpp main.cpp.github-backup

# Copy NAP version as starting point
cp /home/nap/vanetza-nap-atcll/tools/socktap/main.cpp .
```

**Edit main.cpp:**

1. Update includes to match github-vanetza structure
2. Verify RouterContext initialization
3. Ensure security integration matches github-vanetza's API
4. Check link_layer creation
5. Update multi_link support (for its-g5 & udp usage)

**Key differences to handle:**
- GitHub uses `boost::asio::io_context`, NAP might use `io_service`
- Security API may have changed
- Router initialization may differ
- Multi-link handling
- Config.ini parsing and usage (and incorporate new security configs for none/dummy with non-strict)

## Step 2.7: Copy/Modify Router Context

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy/modify router context (multi-threaded routing)
cp /home/nap/vanetza-nap-atcll/tools/socktap/router_context.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/router_context.cpp .
```

**Note:** This has significant changes from github-vanetza:
- Multi-router support (thread pool)
- Message filtering (ignore_own_messages, ignore_rsu_messages)
- Integration with pub/sub queues

## Step 2.8: Copy Supporting Files

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy time trigger (if different from github)
cp /home/nap/vanetza-nap-atcll/tools/socktap/time_trigger.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/time_trigger.cpp .

# Copy ethernet device handling
cp /home/nap/vanetza-nap-atcll/tools/socktap/ethernet_device.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/ethernet_device.cpp .

# Copy multi-link handling
cp /home/nap/vanetza-nap-atcll/tools/socktap/multi_link.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/multi_link.cpp .
```

## Step 2.9: Update Dockerfile

```bash
cd /home/nap/vanetza-nap

# Backup github Dockerfile
mv Dockerfile Dockerfile.github-backup

# Copy NAP Dockerfile
cp /home/nap/vanetza-nap-atcll/Dockerfile .
```

**Edit Dockerfile to add missing dependencies:**

```dockerfile
# Add Zenoh libs stage (if not present)
FROM code.nap.av.it.pt:5050/mobility-networks/middleware-images/zenoh-libs:1.4.0 AS zenoh-libs

# In build stage, add dependencies
RUN apt-get update && apt-get install -y \
    libmosquittopp-dev \
    # ... existing packages ...

# Copy Zenoh libraries
COPY --from=zenoh-libs /usr/local /usr/local

# Build Fast-DDS stack (already in NAP Dockerfile)
# Build Prometheus (already in NAP Dockerfile)
```

## Step 2.10: Build and Test

```bash
cd /home/nap/vanetza-nap

# Build Docker image
docker build -t vanetza-nap-v2:phase2 .
```

**If build fails:**
1. Check error messages for missing includes
2. Verify all dependencies in CMakeLists.txt
3. Check for API mismatches between github-vanetza and NAP code

**When build succeeds:**

```bash
# Test run
docker run --rm -it \
    --network host \
    --ipc host \
    -v $(pwd)/tools/socktap/config.ini:/config.ini \
    vanetza-nap-v2:phase2
```

**Expected:**
- Socktap starts
- Reads config.ini
- Initializes MQTT/DDS/Zenoh
- Starts listening for packets
- No crashes

## Step 2.11: Test with VW CAMs

**Validation Test:**
1. Replay VW CAMs (with security V3) them to socktap
4. Verify:
   - V3 secured packets are properly parsed (not dropped)
   - CAM is decoded to JSON
   - JSON is published to MQTT/DDS/Zenoh
   - No "Security_Entity_Missing" errors

**Run with security:**
```bash
docker run --rm -it \
    --network host \
    -v $(pwd)/tools/socktap/config.ini:/config.ini \
    vanetza-nap-v2:phase2 \
    socktap -c /config.ini --security=dummy
```

**Checkpoint:** CAM works with VW V3 secured packets, JSON published, all other messages work with in/out/time/test. Security none/dummy modes work without errors. Multi-threaded routing is functional.

---

# Phase 3: Extended Features

## Phase 3 Status Overview

| Step | Component |
|------|-----------|
| 3.1 | RSSI Monitoring |
| 3.2 | Packet Metadata (CohesivePacket) |
| 3.3 | Link Layer RSSI Integration |
| 3.4 | Message Filtering | COMPLETE |
| 3.5 | Queue Corruption Detection |
| 3.6 | MAC/Position Override |

---

## Step 3.1: Add RSSI Monitoring

The RSSI reader uses nl80211 (netlink WiFi) interface for kernel-level RSSI data collection:
- Queries neighbor stations with signal strength, TX rate, throughput
- Channel survey data collection (frequency, noise, channel utilization)
- MCS (Modulation and Coding Scheme) mapping (1-8 from TX rate)
- Timeout-based cleanup for stale entries (1-second expiry)
- Functions: `start_rssi_reader()`, `get_rssi()`, `get_mcs()`, `get_survey()`

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy RSSI reader
cp /home/nap/vanetza-nap-atcll/tools/socktap/rssi_reader.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/rssi_reader.cpp .
```

**CMakeLists.txt Note:**
NetLink dependencies are already present in CMakeLists.txt compile flags:
```cmake
-I/usr/include/libnl3 -lnl-genl-3 -lnl-3
```

No additional CMakeLists changes needed for dependencies.

---

## Step 3.2: Add Packet Metadata Support

CohesivePacket metadata fields are already present in `vanetza/net/cohesive_packet.hpp` (lines 88-97):

```cpp
int rssi;                      // Signal strength in dBm (default: -255)
std::map<std::string, int> mcs;  // MCS per MAC address
int frequency;                 // Channel frequency in MHz (default: -1)
int noise;                     // Noise level (default: -1)
double chan_busy_time;         // Channel utilization (default: -1)
double chan_rx_time;           // Channel RX time fraction (default: -1)
double chan_tx_time;           // Channel TX time fraction (default: -1)
double time_received;          // Reception timestamp (default: -1)
double time_queue;             // Queue timestamp
std::string source;            // Source MAC address
```

Constructor initialization in `cohesive_packet.cpp` properly sets default values.

---

## Step 3.3: Update Link Layer for RSSI Integration


**Changes to constructor:**
- `link_layer.hpp`: `create_link_layer()` signature includes `rssi_enabled` parameter

**Missing in RawSocketLink:**

The atcll version has these changes that need to be applied:

**1. Constructor signature change** (`raw_socket_link.hpp`):
```cpp
// Default:
RawSocketLink(boost::asio::generic::raw_protocol::socket&&);

// Changed:
RawSocketLink(boost::asio::generic::raw_protocol::socket&&,
              const std::string& device_name,
              bool rssi_enabled);
```

**2. Global state variable** (`raw_socket_link.cpp`):
```cpp
bool rssi_enabled = false;  // Global flag for RSSI collection
```

**3. RSSI reader initialization** (in constructor):
```cpp
if (rssi_enabled) {
    start_rssi_reader(device_name);
}
```

**4. Packet metadata population** (in `on_read()` callback):
```cpp
// After extracting source MAC from packet:
packet.source = mac_to_string(source_mac);
packet.rssi = -255;  // Default

if (rssi_enabled) {
    packet.rssi = get_rssi(source_mac);
    packet.mcs = get_mcs();

    auto survey = get_survey();
    packet.frequency = survey.frequency;
    packet.noise = survey.noise;
    packet.chan_busy_time = survey.chan_busy_time;
    packet.chan_rx_time = survey.chan_rx_time;
    packet.chan_tx_time = survey.chan_tx_time;
}

packet.time_received = current_timestamp();
```

**5. Update link_layer.cpp** to pass parameters:
```cpp
// In create_link_layer():
return std::make_unique<RawSocketLink>(std::move(socket), device_name, rssi_enabled);
```

**6. Add include** (`raw_socket_link.cpp`):
```cpp
#include "rssi_reader.hpp"
```

**To complete this step:**
```bash
cd /home/nap/vanetza-nap/tools/socktap

# Option A: Copy and adapt from atcll (recommended)
cp /home/nap/vanetza-nap-atcll/tools/socktap/raw_socket_link.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/raw_socket_link.cpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/link_layer.cpp .

# Option B: Manually apply the changes listed above
```

---

## Step 3.4: Add Message Filtering

Message filtering is already implemented in router_context.cpp and configured in config.ini:

```ini
[general]
ignore_own_messages=true
ignore_rsu_messages=false
```

---

## Step 3.5: Add Queue Corruption Detection

The queue corruption detection hack prevents crashes when the runtime queue becomes corrupted.

**Add to `vanetza/common/manual_runtime.cpp`** in the `trigger()` function, before processing the queue:

```cpp
void ManualRuntime::trigger(Clock::time_point tp)
{
    m_now = tp;
    while (!m_queue.empty()) {
        auto& top = m_queue.get<by_deadline>().top();

        // Queue corruption detection hack (add these lines)
        if(&top != nullptr && top.get_node() != nullptr &&
           top.get_node()->right() != nullptr &&
           top.get_node()->right() == top.get_node()->right()->left()) {
            std::cout << "[DEBUG] - Runtime queue corruption was detected and cleared" << std::endl;
            m_queue.get<by_deadline>().clear();
            break;  // Exit after clearing
        }

        // ... rest of existing code ...
    }
}
```

---

## Step 3.6: Add MAC/Position Override


Override fields are already present in both files:

**`vanetza/btp/data_request.hpp`** (lines 30-31):
```cpp
boost::optional<MacAddress> source_mac_override;
boost::optional<geonet::LongPositionVector> source_position_override;
```

**`vanetza/geonet/data_request.hpp`** (lines 52-53):
```cpp
boost::optional<MacAddress> source_mac_override;
boost::optional<LongPositionVector> source_position_override;
```

---

# Phase 4: Advanced Features 

## Step 4.1: Add Prometheus Metrics

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy from NAP
ls -la | grep prometheus || cp /home/nap/vanetza-nap-atcll/tools/socktap/prometheus* .
```

Update main.cpp to initialize Prometheus endpoint:
```cpp
// Add Prometheus exposer
#include <prometheus/exposer.h>

// In main():
prometheus::Exposer exposer{"0.0.0.0:9100"};
auto registry = std::make_shared<prometheus::Registry>();
exposer.RegisterCollectable(registry);
```

## Step 4.3: Add GPS Position Provider Enhancements

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Custom GPS handling
cp /home/nap/vanetza-nap-atcll/tools/socktap/gps_position_provider.* . 2>/dev/null || true
```

---

## Step 4.4: CAM Multi-Decoder Fallback System

### Background: The Problem

CAM messages are encoded using **UPER (Unaligned Packed Encoding Rules)**, a binary ASN.1 encoding where every field's bit-width is determined at compile time by its ASN.1 constraints. There is no self-describing information in the bitstream — the decoder must use the exact same constraint as the encoder.

The critical field is `pathHistory` inside `BasicVehicleContainerLowFrequency`. Its **length prefix** (the number of bits used to encode "how many items are in this list") differs between ASN.1 releases:

| Variant | ASN.1 Constraint | Bits for count | Max items |
|---------|-----------------|----------------|-----------|
| R1 (TS 102 894-2) | `PathHistory SIZE(0..40)` | **6 bits** | 40 |
| R2 (TS 103 900) | `pathHistory Path (SIZE(0..23))` | **5 bits** | 23 |
| R2 6bit (solution) | No inline constraint → inherits `Path SIZE(0..40)` | **6 bits** | 40 |

**The key problem:** VW vehicles set `protocolVersion = 2` in the ITS PDU header but encode `pathHistory` with 6 bits (R1-style). When Vanetza decodes using strict R2 (5-bit), the length prefix is read with one fewer bit, which misaligns every subsequent bit in the message. UPER decoding **might not fail** on bit misalignment — it silently produces garbage values.

**Wireshark decodes VW CAMs correctly** because its R2 ASN.1 schema does not have the inline `SIZE(0..23)` constraint on `pathHistory`, so it falls back to the base `Path` definition with `SIZE(0..40)` = 6 bits.

---

### The Three Decoder Variants

#### Compact R2 (6-bit) — `asn_DEF_Vanetza_ITS2_BasicVehicleContainerLowFrequency_Compact`
A manually-added type descriptor in `BasicVehicleContainerLowFrequency.c`. The `pathHistory` member has **no inline PER constraint**, so it inherits the base `Path SIZE(0..40)` definition and uses a 6-bit length prefix.

#### R1 — `asn_DEF_CAM`
Standard generated code from the R1 schema (`TS 102 894-2`). `PathHistory SIZE(0..40)` = 6-bit length prefix.

#### Strict R2 (5-bit) — `asn_DEF_Vanetza_ITS2_BasicVehicleContainerLowFrequency` (default generated)
Standard generated code from the R2 schema (`TS 103 900`). The `pathHistory` member has inline constraint `SIZE(0..23)` = 5-bit length prefix.

---

### Runtime Swapping Mechanism (`CompactR2DecodeGuard`)

ASN.1c generates a global pointer chain that is resolved at runtime. By swapping one pointer in this chain, both the encoder and decoder can be switched between variants without regenerating code.

The chain from the top-level CAM type down to the affected field:
```
asn_DEF_Vanetza_ITS2_CAM
  └── CamPayload → CamParameters
        └── LowFrequencyContainer
              └── asn_MBR_Vanetza_ITS2_LowFrequencyContainer_1[0].type
                            ↑
                    swapped at runtime by CompactR2DecodeGuard
```

`CompactR2DecodeGuard` is an RAII class defined in `vanetza/asn1/cam.hpp`:
- **Constructor:** saves the current pointer and replaces it with `&asn_DEF_Vanetza_ITS2_BasicVehicleContainerLowFrequency_Compact`
- **Destructor:** restores the original pointer automatically when the guard goes out of scope (even on exceptions)

This is the same RAII pattern as `std::lock_guard` — the variable does not need to be explicitly used; its lifetime controls the side effect.

---

### Decoding Flow (Receive Path — `indicate()`)

```
Incoming raw UPER bytes
         │
         ▼
┌──────────────────┐
  Step 1: Compact R2 (6-bit)            ← CompactR2DecodeGuard active
  type pointer → Compact variant     (scope block restores on exit)
└──────────────────┘
               │ success?
          ┌────┴────┐
         YES        NO
          │    ┌────▼───────┐
          │      Step 2: R1               
          │      asn_DEF_CAM (6-bit)      
          │    └────┬───────┘
          │         │ success?
          │    ┌────┴────┐
          │   YES        NO
          │    │    ┌────▼────────┐
          │    │      Step 3: Strict R2 (5-bit)    
          │    │      default type pointer         
          │    │    └────┬────────┘
          │    │         │ success?
          │    │    ┌────┴────┐
          │    │   YES       NO → DROP + log error
          │    │    │
          └────┴────┘
               │
         JSON encode + publish
```

Code location: `tools/socktap/applications/cam_application.cpp`, function `indicate()`.

---

### Encoding Flow (Send Path)

Both outgoing paths use `CompactR2DecodeGuard` wrapping the `Application::request()` call. Since the ASN.1c encoder traverses the same type descriptor chain as the decoder, the pointer swap causes the encoder to write 6-bit pathHistory length prefixes, matching VW and Wireshark.

```
JSON / internal CAM struct
         │
         ▼
┌──────────────────────┐
  CompactR2DecodeGuard active         
  Application::request()              
  → UPER encode with 6-bit pathHistory
└──────────────────────┘
         │
         ▼
Raw UPER bytes transmitted over ITS-G5
```

**Affected paths:**
- `on_message()` — CAMs received from MQTT/external sources and forwarded to air
- `on_timer()` — Periodic self-generated CAMs

---

### Scenario Matrix

| Sender | `protocolVersion` | `pathHistory` bits | Compact R2 | R1 | Strict R2 | Outcome |
|--------|:-----------------:|:-----------------:|:----------:|:--:|:---------:|---------|
| VW / OEM | 2 | 6 | Pass | — | — | Decoded as Compact R2 |
| Legacy R1 device | 2 | 6 | Pass | Pass | — | Decoded as Compact R2 |
| True R2 encoder | 2 | 5 | Fail | Fail | Pass | Decoded as Strict R2 |
| Vanetza Github / ATCLL | 2 | 6 | Pass | Pass | — | Decoded as Compact R2 |
| Vanetza R2 (itself after fix) | 2 | 6 | Pass | — | — | Decoded as Compact R2 |
| Malformed / unknown | any | ? | Fail | Fai | Fail | Dropped with error log |

> **Known limitation:** Compact R2 and R1 both use 6-bit encoding, so a true Strict R2 CAM (5-bit) is only reached if both prior decoders structurally fail. If a 5-bit CAM happens to parse without structural error under 6-bit assumptions (possible due to UPER's lack of framing), it will be silently misread. This is an inherent limitation of UPER — there is no reliable way to detect bit-width mismatches without out-of-band signalling.

---

### Files Changed

| File | Change |
|------|--------|
| `vanetza/asn1/its/r2/BasicVehicleContainerLowFrequency.c` | Added `asn_DEF_Vanetza_ITS2_BasicVehicleContainerLowFrequency_Compact` with no inline pathHistory PER constraint |
| `vanetza/asn1/its/r2/BasicVehicleContainerLowFrequency.h` | Added `extern` declarations for compact variant symbols |
| `vanetza/asn1/cam.hpp` | Added `CompactR2DecodeGuard` RAII class in `namespace r2` |
| `tools/socktap/applications/cam_application.cpp` | `indicate()`: 3-step fallback decoder; `on_message()` and `on_timer()`: encoding with compact guard |
