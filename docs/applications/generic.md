---
title: Generic Application Architecture
---

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# Generic Application Architecture

This document describes the internal architecture of Vanetza-NAP applications: the base classes, lifecycle, encoding/decoding pipeline, configuration, and how to develop new applications or integrate with existing ones.

## Class Hierarchy

Every application inherits from two base classes:

```
Application (application.hpp)
├── Provides V2X stack interface
├── BTP port binding 
├── GN router request handling 
├── GPS placeholder substitution 
└── Station override logic 

PubSub_application (pubsub.hpp)
├── Provides pub/sub interface
├── on_message() callback for incoming pub/sub messages
└── Priority level for DCC access
```

A message-specific application (e.g., `CamApplication`) inherits from both and implements:

- `port()` - Returns the BTP port for this message type
- `indicate()` - Handles packets received over-the-air
- `on_message()` - Handles messages received from pub/sub (MQTT/DDS/Zenoh)
- `on_timer()` - Handles periodic self-generation (optional)


## Application Lifecycle


### 1. Instantiation (main.cpp)

Each application is conditionally instantiated based on its `enabled` flag in `config.ini`. At creation, it receives:

- A **PositionProvider** (gpsd by default)
    - In order to use the hardcoded coordinates enable the flag: ```user_hardcoded_gps```
- A **Runtime** (clock and timer management)
- A **PubSub** reference (for subscribing and publishing)
- The **config_t** and **metrics_t** structs
- A **priority** level (0, 1, or 2)
- A **mutex** for thread-safe Prometheus metrics

```cpp
// Example: CAM application instantiation 
if (config_s.cam.enabled) {
    std::unique_ptr<CamApplication> cam_app {
        new CamApplication(*positioning, runtime, pubsub, config_s, metrics_s,
                           get_router(num_threads), 1, prom_mtx)
    };
    cam_app->set_interval(std::chrono::milliseconds(config_s.cam.periodicity));
    apps.emplace("cam", std::move(cam_app));
}
```

### 2. Subscription

During construction, each application subscribes to its input topic:

```cpp
this->pubsub->subscribe(config_s.cam, this);
```

This registers the application as a callback handler. When a message arrives on `vanetza/in/cam` (via MQTT, DDS, or Zenoh), the application's `on_message()` is invoked.

### 3. Registration with Router

After all applications are created, they are registered with the `RouterContext`:

```cpp
for (const auto& app : apps) {
    context.enable(app.second.get());
}
```

This binds each application's BTP port to the GeoNetworking router's port dispatcher, so incoming over-the-air packets are routed to the correct application.

### 4. Timer Setup

If `periodicity > 0`, the application's timer is activated:

```cpp
cam_app->set_interval(std::chrono::milliseconds(config_s.cam.periodicity));
```

The timer calls `on_timer()` at the configured interval. 
> <o> **_NOTE:_** Currently, only CAM implements meaningful self-generation logic in `on_timer()`.</o>

---

## Key Methods

### `port()` - BTP Port Binding

Returns the BTP port for this message type. Used by the Port Dispatcher to route inbound over-the-air packets to the correct application.

```cpp
CamApplication::PortType CamApplication::port() {
    return btp::ports::CAM;  // 2001
}
```

### `indicate()` - Receive Over-the-Air Messages

Called when a packet arrives from the GN stack. The processing pipeline is the following:

1. Extract packet data - Access raw bytes and gather RSII, source MAC, and channel info.
2. ASN.1 UPER decode - Decode the binary data into the ASN.1 structure
> <o> **_NOTE:_** CAM uses a 3-step fallback in order to handle the path history compatibility between different message versions, explained in greater detail in <r>dar link com a pagina do fallback</r></o>
3. Optional encoded payload publishing - If `publish_encoded_payloads=true`, publish the raw UPER bytes to a separate topic.
4. JER encode to JSON - Convert the ASN.1 structure to JSON.
5. Attach packet metadata - Add security report, timing data, and station metadata.
6. Publish - Send the JSON to all enabled pub/sub backends.


#### Output JSON Structure

All applications produce the same output envelope:

```json
{
    "fields": {
        "header": {
            "protocolVersion": 2,
            "messageId": 2,
            "stationId": 777
        },
        "<messageType>": {
            ... message-specific ASN.1 content ...
        }
    },
    "secured": false,
    "security_report": {
        "value": 0,
        "description": "Success"
    },
    "test": {
        "start_processing_timestamp": 1773073432.497463,
        "channel_frequency": 5890,
        "channel_noise": -95,
        "channel_busy_time": 0.004709,
        "channel_rx_time": 0.003141,
        "channel_tx_time": 0.000336,
        "json_timestamp": 1773073432.4984,
        "mcs": { "6e:06:e0:01:03:0c": 1 }
    },
    "timestamp": 1773073432.497263,
    "rssi": -21,
    "stationID": 777,
    "stationAddr": "6e:06:e0:01:03:0c",
    "receiverID": 229,
    "receiverType": 5,
    "packet_size": 104
}
```

| Field | Description |
|---|---|
| `fields` | The decoded ASN.1 message content in JER format |
| `secured` | Whether the message carried a security envelope |
| `security_report` | Verification result (only present if `secured=true`) |
| `test` | Diagnostic/timing information |
| `timestamp` | Unix timestamp when the packet was received |
| `rssi` | Received Signal Strength Indicator (dBm) |
| `stationID` | ITS Station ID of the sender |
| `stationAddr` | Source MAC address of the sender |
| `receiverID` | ITS Station ID of this node |
| `receiverType` | Station type of this node (5=vehicle, 15=RSU, etc) |
| `packet_size` | Size of the received packet in bytes |

The `test` object fields:

| Field | Description |
|---|---|
| `start_processing_timestamp` | When the packet entered the processing queue |
| `channel_frequency` | ITS-G5 channel frequency in MHz (e.g., 5900) |
| `channel_noise` | Channel noise floor in dBm |
| `channel_busy_time` | Channel busy ratio (0.0 - 1.0) |
| `channel_rx_time` | Channel receive time ratio |
| `channel_tx_time` | Channel transmit time ratio |
| `json_timestamp` | When JSON encoding completed |
| `mcs` | MCS (Modulation and Coding Scheme) rates per source MAC (when `mcs_enabled=true`) |

### `on_message()` - Transmit via Pub/Sub

Called when a message arrives from MQTT, DDS, or Zenoh on the application's input topic. The processing pipeline:

1. **Check encoding** - Messages can be JSON or pre-encoded UPER bytes
2. **If JSON**:
    - Run `fillPosition()` to replace GPS placeholders with live values
    - Parse the JSON document
    - Auto-wrap partial payloads (see [Input JSON Formats](#input-json-formats) below)
    - Decode via JER into the ASN.1 structure
3. **If encoded**: Use the raw bytes directly
4. **Build DataRequest** - Set ITS-AID, transport type (SHB), and communication profile (ITS_G5)
5. **Apply station overrides** - If the payload contains a `stationId`, override the source MAC and position
6. **Send** - Call `Application::request()` which adds the BTP header and sends through the GN Router → DCC → Link Layer
7. **Publish timing metadata** - If `mqtt_time_enabled`, publish transmission timing to the time topic

#### Input JSON Formats

Applications accept two JSON input formats:

**Full structure** (with header):
```json
{
    "header": {
        "protocolVersion": 2,
        "messageId": 2,
        "stationId": 99
    },
    "cam": {
        "generationDeltaTime": 13190,
        "camParameters": { ... }
    }
}
```

**Payload only** (auto-wrapped):
```json
{
    "generationDeltaTime": 13190,
    "camParameters": { ... }
}
```

When the payload-only format is used, the application automatically wraps it with a header using values from the payload or the node's configuration.

### `on_timer()` - Periodic Self-Generation

Called at the configured periodicity interval. Currently only CAM implements meaningful self-generation:

- Builds a complete CAM message using live GPS data 
- Calculates derived values: acceleration , yaw rate
- Populates specific high-frequency container based on `station_type`
- Transmits over-the-air and publishes to `vanetza/own/cam`

