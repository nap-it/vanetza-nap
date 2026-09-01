---
title: Configuration Reference
---

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# Configuration Reference

Vanetza-NAP is configured through a `config.ini` file, which is an INI-format file with sections and key-value pairs. The default configuration template is located at `tools/socktap/config.ini`.

All configuration fields can be overritten via **environment variables**, which take precedence over `config.ini` values. This is useful for Docker deployments where you want a base config file but need to override specific values per-instance (e.g., Station ID, MAC address).

## `[general]` — General Settings

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `interface` | `VANETZA_INTERFACE` | Network interface for ITS-G5 message exchange | `wlan0` |
| `gpsd_host` | `VANETZA_GPSD_HOST` | GPSD position provider host | `127.0.0.1` |
| `gpsd_port` | `VANETZA_GPSD_PORT` | GPSD position provider port | `2947` |
| `prometheus_port` | `VANETZA_PROMETHEUS_PORT` | Port for Prometheus metrics endpoint | `9100` |
| `rssi_enabled` | `VANETZA_RSSI_ENABLED` | Extract RSSI (signal strength) from inbound ITS-G5 packets via kernel interface | `true` |
| `mcs_enabled` | `VANETZA_MCS_ENABLED` | Track MCS (Modulation and Coding Scheme) rates per source MAC | `false` |
| `ignore_own_messages` | `VANETZA_IGNORE_OWN_MESSAGES` | Don't capture or decode messages originating from this station | `true` |
| `ignore_rsu_messages` | `VANETZA_IGNORE_RSU_MESSAGES` | Ignore messages from RSU stations (typically set on RSUs) | `false` |
| `num_threads` | `VANETZA_NUM_THREADS` | Number of threads per queue stage (`-1` = auto, uses `hardware_concurrency / 2`) | `-1` |
| `publish_encoded_payloads` | `VANETZA_PUBLISH_ENCODED_PAYLOADS` | Publish raw ASN.1 UPER-encoded payloads in addition to JSON | `false` |
| `enable_json_prints` | `VANETZA_ENABLE_JSON_PRINTS` | Print JSON representations of incoming messages to logs | `false` |
| `debug_enabled` | `VANETZA_DEBUG_ENABLED` | Enable debug prints in logs | `false` |
| `security` | `VANETZA_SECURITY` | Security mode: `none` or `dummy` | `none` |

## `[station]` — Station Identity & Positioning

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `id` | `VANETZA_STATION_ID` | ETSI ITS Station ID | `99` |
| `type` | `VANETZA_STATION_TYPE` | ETSI Station Type (`5` = OBU/vehicle, `15` = RSU) | `15` |
| `mac_address` | `VANETZA_MAC_ADDRESS` | Virtual MAC address used as source on L2 Ethernet headers | Interface's address |
| `beacons_enabled` | `VANETZA_BEACONS_ENABLED` | Send GeoNetworking beacons every 3 seconds | `true` |
| `use_hardcoded_gps` | `VANETZA_USE_HARDCODED_GPS` | Use static GPS coordinates instead of live gpsd data | `true` |
| `latitude` | `VANETZA_LATITUDE` | Hardcoded GPS latitude (decimal degrees) | `40` |
| `longitude` | `VANETZA_LONGITUDE` | Hardcoded GPS longitude (decimal degrees) | `-8` |
| `length` | `VANETZA_LENGTH` | Vehicle length in meters | `10` |
| `width` | `VANETZA_WIDTH` | Vehicle width in meters | `3` |

## `[mqtt]` — MQTT Broker Settings

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `local_mqtt_broker` | `VANETZA_LOCAL_MQTT_BROKER` | Local MQTT broker IP address or hostname | `127.0.0.1` |
| `local_mqtt_port` | `VANETZA_LOCAL_MQTT_PORT` | Local MQTT broker port | `1883` |
| `remote_mqtt_broker` | `VANETZA_REMOTE_MQTT_BROKER` | Remote MQTT broker IP address or hostname (empty to disable) | `""` |
| `remote_mqtt_port` | `VANETZA_REMOTE_MQTT_PORT` | Remote MQTT broker port (`0` to disable) | `0` |
| `remote_mqtt_username` | `VANETZA_REMOTE_MQTT_USERNAME` | Remote MQTT broker authentication username | `""` |
| `remote_mqtt_password` | `VANETZA_REMOTE_MQTT_PASSWORD` | Remote MQTT broker authentication password | `""` |


## `[dds]` — DDS Settings

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `dds_domain_id` | `VANETZA_DDS_DOMAIN_ID` | DDS domain ID for publishing and subscribing | `0` |
| `dds_participant_name` | `VANETZA_DDS_PARTICIPANT_NAME` | DDS participant name | `Vanetza` |
| `dds_blocked_interfaces` | `VANETZA_DDS_BLOCKED_INTERFACES` | Network interfaces to exclude from DDS discovery | `wlan0` |

## `[zenoh]` — Zenoh Settings

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `zenoh_local_only` | `VANETZA_ZENOH_LOCAL_ONLY` | Restrict Zenoh to same-host communication only (shared memory IPC) | `true` |
| `zenoh_interfaces` | `VANETZA_ZENOH_INTERFACES` | Comma-separated list of interfaces for Zenoh when not in local-only mode (e.g., `lo,eth0`) | `""` |

## `[ipv4]` — UDP/IPv4 Multicast Transport

An alternative link layer that uses UDP multicast instead of raw ITS-G5 Ethernet frames. Useful for testing without 802.11p hardware.

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `enabled` | `VANETZA_IPV4_ENABLED` | Enable the UDP/IPv4 multicast transport | `false` |
| `address` | `VANETZA_IPV4_ADDRESS` | Multicast group address | `239.118.122.97` |
| `port` | `VANETZA_IPV4_PORT` | Multicast port | `8947` |
| `interface` | `VANETZA_IPV4_INTERFACE` | Network interface for multicast traffic | `eth0` |

## Per-Application Configuration

Each supported message type has its own INI section with the same set of configuration fields. The environment variable prefix follows the pattern `VANETZA_<APP>_<FIELD>` (e.g., `VANETZA_CAM_ENABLED`, `VANETZA_DENM_TOPIC_OUT`).

The following table uses CAM as an example:

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `enabled` | `VANETZA_CAM_ENABLED` | Enable this application | `true` |
| `mqtt_enabled` | `VANETZA_CAM_MQTT_ENABLED` | Enable MQTT publishing and subscribing | `true` |
| `dds_enabled` | `VANETZA_CAM_DDS_ENABLED` | Enable DDS publishing and subscribing | `true` |
| `zenoh_enabled` | `VANETZA_CAM_ZENOH_ENABLED` | Enable Zenoh publishing and subscribing | `false` |
| `mqtt_time_enabled` | `VANETZA_CAM_MQTT_TIME_ENABLED` | Publish transmission timing metadata to the time topic | `true` |
| `mqtt_test_enabled` | `VANETZA_CAM_MQTT_TEST_ENABLED` | Publish diagnostic metadata to the test topic | `false` |
| `periodicity` | `VANETZA_CAM_PERIODICITY` | Self-generation interval in milliseconds (`0` to disable) | `0` |
| `topic_in` | `VANETZA_CAM_TOPIC_IN` | Input topic for messages to transmit over-the-air | `vanetza/in/cam` |
| `topic_out` | `VANETZA_CAM_TOPIC_OUT` | Output topic for messages received over-the-air | `vanetza/out/cam` |
| `topic_time` | `VANETZA_CAM_TOPIC_TIME` | Topic for transmission timing metadata | `vanetza/time/cam` |
| `topic_test` | `VANETZA_CAM_TOPIC_TEST` | Topic for diagnostic/test metadata | `vanetza/test/cam` |
| `udp_out_addr` | `VANETZA_CAM_UDP_OUT_ADDR` | UDP output address for application-level forwarding | `127.0.0.1` |
| `udp_out_port` | `VANETZA_CAM_UDP_OUT_PORT` | UDP output port (`0` to disable) | `0` |

### CAM-Specific Fields

The CAM application has one additional field:

| INI Key | Environment Variable | Description | Default |
|---|---|---|---|
| `own_topic_out` | `VANETZA_CAM_OWN_TOPIC_OUT` | Topic for self-generated CAM messages (empty to disable) | `vanetza/own/cam` |

## Error Messages

If your application publishes an invalid JSON message, the following errors will appear in the container's logs:

<o>**JSON parsing error** </o> - The message is malformed and cannot be parsed:
```
-- Vanetza JSON Decoding Error --
Check that the message format follows JSON spec
<Exception Info>
```

<o>**ETSI structure error** </o> - The JSON is valid but does not match the expected ETSI message structure:
```
-- Vanetza ETSI Decoding Error --
Check that the message format follows ETSI spec
<Exception Info>
```

<o>**UPER encoding error** </o> - Field values do not fit the types or constraints defined in the ETSI specifications:
```
-- Vanetza UPER Encoding Error --
Check that the message format follows ETSI spec
<Exception Info>
```

<o>**Unexpected error** </o> - An unhandled error occurred:
```
-- Unexpected Error --
Vanetza couldn't decode the JSON message. No other info available
```

## Example Configuration

A minimal configuration for an OBU with live GPS and MQTT only:

```ini
[general]
interface=wlan0
num_threads=-1

[station]
id=42
type=5
use_hardcoded_gps=false

[mqtt]
local_mqtt_broker=127.0.0.1
local_mqtt_port=1883

[cam]
enabled=true
mqtt_enabled=true
dds_enabled=false
zenoh_enabled=false
periodicity=1000

[denm]
enabled=true
mqtt_enabled=true
dds_enabled=false
zenoh_enabled=false
```

For the full default configuration template, see `tools/socktap/config.ini`.
