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

# Remove RPC module (not used)
rm -rf vanetza/rpc

# Remove benchmarking tools
rm -rf tools/benchmark
rm -rf tools/fuzz-harness

# Remove other unused tools...
```

**Update CMakeLists.txt:**

Edit `CMakeLists.txt` (root):
```cmake
# Comment out or remove unused modules
# add_subdirectory(vanetza/rpc)
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

# Phase 1: Foundation - ASN.1, Configuration and Main socktap

## Step 1.1: Check existing ASN.1 Schemas

NAP has custom ASN.1 schemas that github-vanetza doesn't have:

**Included in migration:**
- RTCMEM support (verify it doesn't conflict with github-vanetza's existing RTCMEM types, or use those)

**Excluded from initial migration:**
- MCM support (will NOT be included initially)
- IMZM support (will be dropped)
- EVCSNM support (will be dropped)
- EVRSRM support (will be dropped)
- TIS-TPG support (will be dropped)

**To be added later:**
- AVM support will be added after migration is complete and stable

```bash
cd /home/nap/vanetza-nap/asn1

# Check if all the necessary schemas are present, optionally removing unused message types (POIM?)
```

## Step 1.2: Understand ASN.1 Schema Organization

GitHub-vanetza organizes ASN.1 schemas in two releases:

**Release 1 (legacy - NOT using):**
- `asn1/EN302637-2v141-CAM.asn` - CAM v1.4.1
- `asn1/EN302637-3v131-DENM.asn` - DENM v1.3.1
- `asn1/TS102894-2v131-CDD.asn` - CDD v1.3.1
- `asn1/TR103562v211-CPM.asn` - CPM v2.1.1 (Release 1 version)
- `asn1/TS103300-3v211-VAM.asn` - VAM v2.1.1 (Release 1 version)

**Release 2 (using):**
- `release2/TS103900v211-CAM.asn` - CAM v2.1.1
- `release2/TS103831v221-DENM.asn` - DENM v2.2.1
- `release2/TS102894-2v221-CDD.asn` - CDD v2.2.1
- `release2/TS103324v211/CPM-*.asn` - CPM v2.1.1 (5 files)
- `release2/TS103300v221/VAM-*.asn` - VAM v2.2.1 (2 files)

**Other messages (using Release 1 versions v2.1.1):**
- `asn1/TS103301v211-MAPEM.asn` 
- `asn1/TS103301v211-SPATEM.asn` 
- `asn1/TS103301v211-IVIM.asn` 
- `asn1/TS103301v211-SREM.asn` 
- `asn1/TS103301v211-SSEM.asn` 
- `asn1/TS103301v211-RTCMEM.asn` 

**Security & PKI schemas:**
- `release2/TS103097v211.asn` - Security v2.1.1
- `release2/TS103097v211-Extension.asn`
- `release2/TS102941v221/*.asn` - PKI v2.2.1 (11 files for certificate management)

**Important:** GitHub-vanetza has pre-generated C code:
- `vanetza/asn1/its/r2/` - Release 2 generated code (with `Vanetza_ITS2_` prefix)
- `vanetza/asn1/security/r2/` - Security Release 2 (with `Vanetza_Security2_` prefix)

We'll use the pre-generated code from github-vanetza as-is.

## Step 1.3: Copy ASN.1 JSON Generator

This is **critical** - all pub/sub depends on this.

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy the generator script from NAP reference
cp /home/nap/vanetza-nap-atcll/tools/socktap/asn1json.py .

# Verify it's executable
chmod +x asn1json.py
```

**Inspect the script:**
- Check `base_dir = "../../asn1"` - ensure it points correctly
- Check `asn1_files = [...]` list - verify all schemas are listed
- Check `transformation = {...}` - SI unit conversions for lat/lon/speed/etc.

## Step 1.4: Update ASN.1 File List in Generator

Edit `asn1json.py` to use Release 2 schemas for CAM/DENM/CPM/VAM:

```python
asn1_files = [
    # Release 2 schemas for CAM, DENM, CPM, VAM (primary messages)
    "release2/TS102894-2v221-CDD.asn",  # CDD v2.2.1
    "release2/TS103900v211-CAM.asn",     # CAM v2.1.1
    "release2/TS103831v221-DENM.asn",    # DENM v2.2.1

    # CPM Release 2 (5 files)
    "release2/TS103324v211/CPM-PDU-Descriptions.asn",
    "release2/TS103324v211/CPM-OriginatingStationContainers.asn",
    "release2/TS103324v211/CPM-PerceivedObjectContainer.asn",
    "release2/TS103324v211/CPM-PerceptionRegionContainer.asn",
    "release2/TS103324v211/CPM-SensorInformationContainer.asn",

    # VAM Release 2 (2 files)
    "release2/TS103300v221/VAM-PDU-Descriptions.asn",
    "release2/TS103300v221/motorcyclist-special-container.asn",

    # Other messages (still supported by github-vanetza v2.1.1)
    "TS103301v211-MAPEM.asn",
    "TS103301v211-SPATEM.asn",
    "TS103301v211-IVIM.asn",
    "TS103301v211-SREM.asn",
    "TS103301v211-SSEM.asn",
    "TS103301v211-RTCMEM.asn",

    # Supporting ISO schemas (may need special handling - see troubleshooting)
    # These are fetched by github-vanetza during build
    # We may need to copy them from build/vanetza/asn1/iso/ to asn1/
    # OR adjust base_dir in asn1json.py to include build directory

    # Uncomment these if ISO files are available in asn1/ directory:
    # "ISO14816.asn",
    # "ISO14823.asn",
    # "ISO14906-0-6.asn",
    # "ISO14906-1-7.asn",
    # "ISO17419.asn",
    # "ISO19091.asn",  # Required for MAPEM/SPATEM
    # "ISO19321.asn",
    # "ISO24534-3.asn",
    # "DSRC.asn",
    # "DSRC_REGION_noCircular.asn",

    # Note: MCM, EVCSN, EV-RSR, IMZM, TIS-TPG excluded (per requirements)
    # AVM support will be added after migration is stable
]
```

**Important notes:**

1. **ISO Dependencies**: MAPEM/SPATEM/IVIM/SREM/SSEM depend on ISO standards that github-vanetza fetches automatically during CMake build. These go into `build/vanetza/asn1/iso/` directory.

2. **For asn1json.py to work**, we have two options:
   - **Option A (Initial)**: Comment out ISO-dependent messages (MAPEM/SPATEM/IVIM/SREM/SSEM) from asn1_files list initially
   - **Option B (After first build)**: Copy ISO .asn files from build directory to asn1/ directory, then enable all messages

3. **PKI schemas**: The `release2/TS102941v221/` files are for PKI (certificate enrollment, authorization). They're NOT needed for asn1json.py unless we start converting certificate messages to JSON.

**Verify all files exist:**
```bash
cd /home/nap/vanetza-nap/asn1
for file in $(grep '".*\.asn"' ../tools/socktap/asn1json.py | cut -d'"' -f2); do
    if [ ! -f "$file" ]; then
        echo "MISSING: $file"
    fi
done
```

## Step 1.5: Generate ASN.1 ↔ JSON Conversion Code

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Install Python dependencies if needed
pip3 install asn1tools

# Generate C++ code
python3 asn1json.py cpp > asn1json.cpp
python3 asn1json.py hpp > asn1json.hpp
```

**Expected output:**
- `asn1json.cpp`: Several thousand lines of generated code
- `asn1json.hpp`: Header file with conversion function declarations

**Checkpoint:** ASN.1 JSON conversion code generated successfully

## Step 1.6: Copy Configuration System

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy configuration infrastructure from NAP reference
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.cpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config_reader.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/config.ini .

# Copy entrypoint script
cp /home/nap/vanetza-nap-atcll/entrypoint.sh ../../
chmod +x ../../entrypoint.sh
```

## Step 1.7: Update CMakeLists for ASN.1 JSON

Edit `tools/socktap/CMakeLists.txt`:

Add to sources:
```cmake
set(SOCKTAP_SOURCES
    # ... existing sources ...
    asn1json.cpp
    asn1json.hpp
    config.cpp
    config.hpp
    config_reader.hpp
)
```

Add RapidJSON dependency and others:
```cmake
find_package(RapidJSON REQUIRED)
target_include_directories(socktap PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
(...)
```

## Step 1.8: Test Build (Foundation Only)

```bash
cd /home/nap/vanetza-nap

# Try building
mkdir -p build && cd build
cmake ..
make socktap -j$(nproc)
```

**Expected:** Should compile but socktap won't run yet (missing pub/sub integration).

**If build fails:** Check error messages, verify all dependencies are in CMakeLists.txt

**Checkpoint:** Configuration system + ASN.1 JSON compiles

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

**Checkpoint:** CAM works with VW V3 secured packets, JSON published

---

# Phase 3: Extended Features 

## Step 3.1: Add RSSI Monitoring

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy RSSI reader
cp /home/nap/vanetza-nap-atcll/tools/socktap/rssi_reader.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/rssi_reader.cpp .
```

**Update CMakeLists.txt:**
```cmake
# Add NetLink dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(NL3 REQUIRED libnl-3.0)
pkg_check_modules(NLGENL3 REQUIRED libnl-genl-3.0)

target_include_directories(socktap PRIVATE ${NL3_INCLUDE_DIRS} ${NLGENL3_INCLUDE_DIRS})
target_link_libraries(socktap PRIVATE nl-3 nl-genl-3)

# Add to sources
set(SOCKTAP_SOURCES
    # ... existing ...
    rssi_reader.cpp
    rssi_reader.hpp
)
```

## Step 3.2: Add Packet Metadata Support

**Modify core Vanetza library:**

```bash
cd /home/nap/vanetza-nap

# Backup github versions
cp vanetza/net/cohesive_packet.hpp vanetza/net/cohesive_packet.hpp.backup
cp vanetza/net/cohesive_packet.cpp vanetza/net/cohesive_packet.cpp.backup

# Copy NAP versions with metadata
cp /home/nap/vanetza-nap-atcll/vanetza/net/cohesive_packet.hpp vanetza/net/
cp /home/nap/vanetza-nap-atcll/vanetza/net/cohesive_packet.cpp vanetza/net/
```

**Verify additions in CohesivePacket:**
- `int rssi`
- `std::map<std::string, int> mcs`
- `int frequency, noise`
- `double chan_busy_time, chan_rx_time, chan_tx_time`
- `double time_received, time_queue`
- `std::string source`

## Step 3.3: Update Link Layer for RSSI

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Copy NAP's link layer
cp /home/nap/vanetza-nap-atcll/tools/socktap/link_layer.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/link_layer.cpp .

# Copy raw socket link with RSSI support
cp /home/nap/vanetza-nap-atcll/tools/socktap/raw_socket_link.hpp .
cp /home/nap/vanetza-nap-atcll/tools/socktap/raw_socket_link.cpp .
```

## Step 3.4: Add Message Filtering

Already included in router_context.cpp from Phase 2, but verify config.ini has:

```ini
[general]
ignore_own_messages=true
ignore_rsu_messages=false
```

## Step 3.5: Add Queue Corruption Detection

```bash
cd /home/nap/vanetza-nap

# Backup github version
cp vanetza/common/manual_runtime.cpp vanetza/common/manual_runtime.cpp.backup

# Copy NAP version with corruption detection
cp /home/nap/vanetza-nap-atcll/vanetza/common/manual_runtime.cpp vanetza/common/
```

**Verify the hack is present** (lines 65-72):
```cpp
if(&top != nullptr && top.get_node() != nullptr && ...) {
    std::cout << "[DEBUG] - Runtime queue corruption detected" << std::endl;
    m_queue.get<by_deadline>().clear();
}
```

## Step 3.6: Add MAC/Position Override (Testing)

```bash
cd /home/nap/vanetza-nap

# Copy modified data_request files
cp /home/nap/vanetza-nap-atcll/vanetza/btp/data_request.hpp vanetza/btp/
cp /home/nap/vanetza-nap-atcll/vanetza/geonet/data_request.hpp vanetza/geonet/
cp /home/nap/vanetza-nap-atcll/vanetza/geonet/data_request.cpp vanetza/geonet/
```

**Verify additions:**
- `boost::optional<MacAddress> source_mac_override`
- `boost::optional<LongPositionVector> source_position_override`

## Step 3.7: Build and Test Extended Features

```bash
cd /home/nap/vanetza-nap

# Rebuild
docker build -t vanetza-nap-v2:phase3 .

# Test with RSSI enabled
docker run --rm -it \
    --network host \
    --cap-add=NET_ADMIN \
    -v $(pwd)/tools/socktap/config.ini:/config.ini \
    vanetza-nap-v2:phase3
```

**Verify in config.ini:**
```ini
[general]
rssi_enabled=true
mcs_enabled=true
```

**Test RSSI:**
- Check JSON output has `rssi` field
- Check `mcs` map is populated
- Verify channel survey data
- Check for UDP packets with "transport type" field

**Checkpoint:** RSSI monitoring works, packet metadata populated

---

# Phase 4: Optional - Advanced Features 

## Step 4.1: Verify Multi-Threading

Already included from router_context.cpp in Phase 2.

**Test different thread counts:**

Edit config.ini:
```ini
[general]
num_threads=4  # Try different values: 1, 2, 4, 8
```

**Verify:**
- Check CPU usage scales with threads
- Monitor packet processing latency
- Ensure no race conditions

## Step 4.2: Add Prometheus Metrics

```bash
cd /home/nap/vanetza-nap/tools/socktap

# Check if github-vanetza already has Prometheus
# If not, copy from NAP
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

# If NAP has custom GPS handling
cp /home/nap/vanetza-nap-atcll/tools/socktap/gps_position_provider.* . 2>/dev/null || true
```

## Step 4.4: Final Build

```bash
cd /home/nap/vanetza-nap

# Final production build
docker build -t vanetza-nap-v2:latest .

# Tag for deployment
docker tag vanetza-nap-v2:latest vanetza-nap:2.0.0
```

**Checkpoint:** All features integrated and tested

---

# Phase 5: Validation & Testing 

## Step 5.1: Integration Testing

**Test Matrix:**

| Test Case | Expected Result |
|-----------|----------------|
| VW V3 CAM reception | Decoded, published |
| Own CAM transmission/reception | Sent, filtered in RX |
| MQTT pub/sub | JSON on configured topics |
| DDS pub/sub | JSONMessage + EncodedITSMessage |
| Zenoh pub/sub | Messages routed |
| RSSI monitoring | Values in JSON |
| Multi-threading | Scales with num_threads |
| Security=dummy --nonstrict | V3 packets processed, non-secure packets processed |
| All 10 applications | Each type works (CAM, DENM, CPM, VAM, SPATEM, MAPEM, SSEM, SREM, RTCMEM, IVIM) |


## Step 5.2: Regression Testing

**Compare with old NAP version:**
- Same config.ini
- Same test scenarios
- Same network conditions

**Verify no regressions in:**
- Message decoding accuracy
- MQTT/DDS/Zenoh reliability
- RSSI reading accuracy

## Step 5.3: Security Validation

**Test security modes:**

```bash
# Test dummy mode (current use case)
docker run ... socktap -c /config.ini --security=dummy --non-strict

# Test with no security (should drop V3 packets)
docker run ... socktap -c /config.ini --security=none
```

**Verify V3 security:**
- VW CAMs with V3 security are decoded
- No "Security_Entity_Missing" errors
- Proper payload extraction

**Checkpoint:** All tests pass, performance validated

---

# Completion Checklist

## Features Migrated

- **ASN.1 JSON Conversion** - Auto-generated from schemas
- **Configuration System** - INI files + env variables
- **MQTT Integration** - Local + remote brokers
- **DDS Integration** - Fast-DDS with dual message types
- **Zenoh Integration** - Router mode with SHM
- **10 Applications** - CAM, DENM, CPM, VAM, SPATEM, MAPEM, SSEM, SREM, RTCMEM, IVIM (MCM and AVM to be added later)
- **RSSI Monitoring** - nl80211 WiFi metrics
- **Packet Metadata** - RSSI, MCS, timing, channel stats
- **Message Filtering** - Ignore own/RSU messages
- **Multi-Threading** - Per-router thread pool
- **Queue Corruption Fix** - Runtime protection
- **MAC/Position Override** - Testing capability
- **UDP Test Output** - Per-application JSON streaming
- **Security Support** - V2/V3 with dummy mode

---

# Troubleshooting

## Build Errors

### Missing Dependencies

**Error:** `fatal error: zenoh.hxx: No such file or directory`

**Fix:**
```bash
# Verify Zenoh libs are copied from base image
# Check Dockerfile COPY --from=zenoh-libs line
```

### ASN.1 Compilation Errors

**Error:** `undefined reference to 'Vanetza_Security_*'`

**Fix:**
- Verify ASN.1 security files have `Vanetza_Security_` prefix
- Check CMakeLists.txt links `asn1_security` library

### RapidJSON Not Found

**Error:** `Could not find RapidJSON`

**Fix:**
```dockerfile
# Add to Dockerfile
RUN apt-get install -y rapidjson-dev
```

### ASN.1 JSON Generation Issues

**Error:** `asn1json.py` fails with missing ISO files (ISO14816.asn, ISO19091.asn, etc.)

**Root Cause:** GitHub-vanetza fetches ISO files during CMake build into `build/vanetza/asn1/iso/`, but `asn1json.py` runs before the build and expects files in `asn1/` directory.

**Solution Option A (Recommended for initial migration):**
```python
# In asn1json.py, comment out ISO-dependent messages temporarily
asn1_files = [
    "release2/TS102894-2v221-CDD.asn",
    "release2/TS103900v211-CAM.asn",
    "release2/TS103831v221-DENM.asn",
    # ... CPM and VAM files ...
    # "TS103301v211-MAPEM.asn",  # Commented out - needs ISO19091
    # "TS103301v211-SPATEM.asn", # Commented out - needs ISO19091
    # "TS103301v211-IVIM.asn",   # Commented out - needs ISO14823
    # "TS103301v211-SREM.asn",   # Commented out - needs ISO19091
    # "TS103301v211-SSEM.asn",   # Commented out - needs ISO19091
    "TS103301v211-RTCMEM.asn",  # This one doesn't need ISO files
]
```

**Solution Option B (After first successful build):**
```bash
cd /home/nap/vanetza-nap

# Build once to fetch ISO files
mkdir -p build && cd build
cmake -DVANETZA_ASN1_WITH_ISO=ON ..
make -j$(nproc)

# Copy ISO files to asn1/ directory for asn1json.py
cp iso/*.asn ../asn1/

# Now regenerate asn1json with full message set
cd ../tools/socktap
python3 asn1json.py cpp > asn1json.cpp
python3 asn1json.py hpp > asn1json.hpp
```

**Solution Option C (Adjust asn1json.py base_dir):**
```python
# Edit asn1json.py to support multiple base directories
import os

base_dirs = ["../../asn1", "../../build/vanetza/asn1/iso"]

def find_asn1_file(filename):
    for base_dir in base_dirs:
        path = os.path.join(base_dir, filename)
        if os.path.exists(path):
            return path
    raise FileNotFoundError(f"ASN.1 file not found: {filename}")
```

## Runtime Errors

### Security Entity Missing

**Error:** Packets dropped with "Security_Entity_Missing"

**Fix:**
```bash
# Ensure --security=dummy is used
socktap -c /config.ini --security=dummy
```

### RSSI Reader Fails

**Error:** `nl80211 initialization failed`

**Fix:**
- Verify `rssi_enabled=true` in config
- Ensure running with `--cap-add=NET_ADMIN`
- Check wireless interface exists (`wlan0`)

## Performance Issues

### High CPU Usage

**Symptom:** CPU at 100% continuously

**Diagnosis:**
- Check `num_threads` configuration
- Monitor queue sizes
- Look for packet storms

**Fix:**
- Reduce `num_threads` if too high
- Add rate limiting if needed
- Check for infinite loops in applications

### High Latency

**Diagnosis:**
- Check timing fields in JSON output
- Monitor thread pool utilization
- Look for blocking operations

**Fix:**
- Increase `num_threads` if underutilized
- Optimize pub/sub publishing
- Check network congestion

---

# Maintenance

## Keeping Up with Upstream

To pull new github-vanetza improvements:

```bash
cd /home/nap/vanetza-nap

# Add upstream remote if not already added
git remote add upstream https://github.com/riebl/vanetza.git

# Fetch upstream changes
git fetch upstream

# Review changes
git log HEAD..upstream/master --oneline

# Merge carefully (will have conflicts in modified files)
git merge upstream/master

# Resolve conflicts, prioritizing NAP features
# Test thoroughly after merge
```

---

# Reference

## File Locations

| Component | Source (NAP Reference) | Target (release2 branch) |
|-----------|------------------------|--------------------------|
| ASN.1 Schemas | `/home/nap/vanetza-nap-atcll/asn1/` | `/home/nap/vanetza-nap/asn1/` |
| JSON Generator | `/home/nap/vanetza-nap-atcll/tools/socktap/asn1json.py` | `/home/nap/vanetza-nap/tools/socktap/` |
| Configuration | `/home/nap/vanetza-nap-atcll/tools/socktap/config.*` | `/home/nap/vanetza-nap/tools/socktap/` |
| Pub/Sub | `/home/nap/vanetza-nap-atcll/tools/socktap/{pubsub,mqtt,dds}.*` | `/home/nap/vanetza-nap/tools/socktap/` |
| Applications | `/home/nap/vanetza-nap-atcll/tools/socktap/applications/` | `/home/nap/vanetza-nap/tools/socktap/applications/` |
| RSSI Monitor | `/home/nap/vanetza-nap-atcll/tools/socktap/rssi_reader.*` | `/home/nap/vanetza-nap/tools/socktap/` |
| Router Context | `/home/nap/vanetza-nap-atcll/tools/socktap/router_context.*` | `/home/nap/vanetza-nap/tools/socktap/` |

## Dependencies

**System packages:**
- libmosquittopp-dev (MQTT)
- libgeographic-dev (geodesy)
- libnl-3-dev, libnl-genl-3-dev (RSSI)
- rapidjson-dev (JSON)

**Libraries:**
- Fast-DDS (DDS pub/sub)
- Zenoh (pub/sub)
- Prometheus C++ (metrics)
- Boost 1.58+ (utilities)
- CryptoPP (crypto)
- ...

**Note:** This guide excludes MCM application initially (to be added later). AVM support will be added after migration is stable.