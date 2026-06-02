# Packet Metadata

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Every ITS packet that Vanetza-NAP receives carries more information than just the message payload. By the time an application processes a packet, it has already travelled through the radio interface, a reception queue, a GeoNetworking router, and a processing queue. Vanetza-NAP captures contextual information at each of these stages and attaches it to the packet as metadata, which is then published alongside the decoded JSON.

---

## What Is Captured

All metadata is stored directly on the `CohesivePacket` — the internal structure that carries a packet from the radio interface up through the entire stack.

### Source Address

`source` is the MAC address of the station that transmitted the packet, extracted from the Ethernet frame header at reception time. It is published in the JSON output as `stationAddr` and is also used internally to look up RSSI and MCS values for that specific sender.

This is distinct from the `stationID` field inside the ITS message itself, which is a logical identifier assigned by the application. `stationAddr` is the physical layer identity of the transmitter.

### Station and Receiver IDs

Each published message includes:

- **`stationID`** — the logical station identifier extracted from the ITS message header (e.g. the CAM's `stationId`). Identifies who sent the message at the application layer.
- **`receiverID`** — the station ID of this Vanetza-NAP instance, from `config.ini`. Identifies who received it.

Together these two fields allow a backend or data pipeline to reconstruct the full sender–receiver relationship for every message without any additional correlation step.

### Timestamps

Vanetza-NAP records Unix timestamps (seconds with microsecond precision) at several points in the processing pipeline:

| Field | Captured at |
|---|---|
| `time_received` (`timestamp` in JSON) | The moment the raw packet arrived on the network interface |
| `time_queue` | The moment the packet was dequeued for processing by a worker thread |

The difference between these two timestamps is the time the packet spent waiting in the processing queue — a direct indicator of how loaded the system is. Both are attached to the `CohesivePacket` as it moves through the stack and are available to every application without any extra instrumentation.

When the test channel is enabled (`mqtt_test_enabled=true`), additional timestamps are published covering the full path: encoding time, DDS publish time, Zenoh publish time, MQTT publish time, and remote MQTT publish time. This gives a complete end-to-end latency breakdown for performance analysis.

### Packet Size

The total size of the received ITS packet in bytes is included and is useful for bandwidth accounting and for detecting unexpectedly large or malformed packets.

---

## Where It Appears

All metadata fields are included in the JSON published to MQTT, DDS, and Zenoh on the `topic_out` for each message type. A typical CAM output looks like:

```json
{
  "timestamp": 1718000000.123456,
  "stationID": 12345678,
  "stationAddr": "aa:bb:cc:dd:ee:ff",
  "receiverID": 99,
  "rssi": -72,
  "cam": { ... }
}
```

The radio metrics (`rssi`, `mcs`, `frequency`, `noise`, `chan_busy_time`, `chan_rx_time`, `chan_tx_time`) documented in the [RSSI Measurement](rssi.md) page are part of the same metadata layer and are published in the same message.

For encoded payloads over DDS (`_enc` topics), the metadata is carried as typed fields in the `EncodedITSMessage` IDL structure rather than embedded in JSON.
