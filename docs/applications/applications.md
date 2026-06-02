---
title: Supported Applications
---

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# Supported Applications

Vanetza-NAP implements the ETSI ITS-G5 V2X communication stack and currently supports 12 standardized message types. Each message type is handled by a dedicated application that manages encoding, decoding, and routing between the wireless ITS-G5 interface and the pub/sub messaging layer.

## Application Summary

The supported applications are described in [Overview](../index.md).
All applications use **SHB** (Single Hop Broadcast) transport with the **ITS-G5** communication profile. R1 applications use the [CDD TS 102 894-2 v2](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2) common data dictionary, while R2 applications use [CDD TS 102 894-2 v2.2.1](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2).

## Pub/Sub Topics

Each application uses a consistent topic naming convention:

| Topic Pattern | Direction | Description |
|---|---|---|
| `vanetza/in/<app>` | Inbound (to V2X) | Receive JSON/encoded messages from external systems to transmit over-the-air |
| `vanetza/out/<app>` | Outbound (from V2X) | Publish decoded messages received over-the-air |
| `vanetza/time/<app>` | Timing metadata | Publish transmission timing data for latency analysis |
| `vanetza/test/<app>` | Test metadata | Publish test/diagnostic information |
| `vanetza/own/cam` | Own CAM output | Publish self-generated CAM messages (CAM only) |

Where `<app>` is one of: `cam`, `denm`, `cpm`, `vam`, `spatem`, `mapem`, `ivim`, `mim`, `mvm`.

## Message Flow

### Receiving (Over-the-Air to Pub/Sub)

```
ITS-G5 Radio → Link Layer → GeoNetworking Router → BTP Port Dispatcher → Application.indicate()
    → ASN.1 UPER Decode → JER Encode to JSON → Add metadata → PubSub.publish()
    → MQTT / DDS / Zenoh / UDP
```

1. A V2X packet arrives on the wireless interface
2. The GN Router routes it to the BTP Port Dispatcher based on BTP port
3. The matching application's `indicate()` method is called
4. The application decodes the ASN.1 UPER payload to a JSON document
5. Metadata is attached (timestamp, RSSI, stationID, etc.)
6. The JSON message is published to all enabled pub/sub backends

### Transmitting (Pub/Sub to Over-the-Air)

```
MQTT / DDS / Zenoh → PubSub.on_message() → Application.on_message()
    → fillPosition() (GPS placeholder substitution) → JER Decode from JSON → ASN.1 UPER Encode
    → Application.request() → BTP Header → GN Router (SHB) → DCC → Link Layer → ITS-G5 Radio
```

1. A JSON or encoded message arrives on the application's input topic
2. If JSON: GPS placeholders (`$latitude`, `$longitude`, etc.) are substituted with live values
3. The JSON is decoded into the ASN.1 structure via JER
4. The application builds a `DataRequest` with the appropriate ITS-AID and transport type
5. The message is sent through the V2X stack to the wireless interface


## Per-Application Configuration

Every application shares the same configuration structure (`message_config_t`):

| Field | Type | Description |
|---|---|---|
| `enabled` | bool | Whether the application is active |
| `periodicity` | int | Self-generation interval in ms (0 = disabled) |
| `topic_in` | string | Pub/sub input topic (e.g., `vanetza/in/cam`) |
| `topic_out` | string | Pub/sub output topic (e.g., `vanetza/out/cam`) |
| `topic_time` | string | Timing metadata topic |
| `topic_test` | string | Test metadata topic |
| `udp_out_addr` | string | UDP output address (for application-level UDP forwarding) |
| `udp_out_port` | int | UDP output port (0 = disabled) |
| `mqtt_enabled` | bool | Enable MQTT publishing/subscribing |
| `dds_enabled` | bool | Enable DDS publishing/subscribing |
| `zenoh_enabled` | bool | Enable Zenoh publishing/subscribing |
| `mqtt_time_enabled` | bool | Enable MQTT timing metadata |
| `mqtt_test_enabled` | bool | Enable MQTT test metadata |

## Further Reading

- [Generic Application Architecture](generic.md) - Deep-dive into the application lifecycle, base classes, encoding/decoding pipeline, and internal architecture
