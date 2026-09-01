# Threading & Queues

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Vanetza-NAP processes ITS messages on a multi-threaded pipeline. Rather than handling every packet synchronously in the radio receive loop, work is dispatched into priority queues and consumed by dedicated thread pools. This keeps the receive path non-blocking and ensures that high-priority messages are never delayed by a backlog of lower-priority ones.

---

## The Problem With a Single Thread

The original Vanetza architecture processed each received packet synchronously: receive → decode → publish. This is fine at low message rates, but in dense ITS environments — multiple vehicles sending CAMs at 10 Hz, CPMs with large object lists, simultaneous DENM events — a single-threaded pipeline becomes a bottleneck. A slow publish to a remote MQTT broker could delay the decode of the next safety-critical packet.

The solution is to decouple the stages with queues and process them in parallel across multiple threads.

---

## Three Pipeline Stages

The message pipeline has three distinct stages, each with its own queue and thread pool:

```
Air interface
     │
     ▼
[ Reception queue ]      ← raw packets off the wire
     │
     ▼
[ Processing queue ]     ← GeoNetworking decode + BTP dispatch (3 priority levels)
     │
     ▼
[ Transmission queue ]   ← ASN.1 → JSON + pub/sub publish (6 priority levels)
```

### Reception

Packets received from the network interface are pushed into a single reception queue and handled by a dedicated thread. This thread feeds the GeoNetworking router, which strips the GeoNetworking and BTP headers and dispatches the payload upward.

### Processing

Once the BTP port is known, the message is placed in the **processing queue** at the priority level of the registered application for that port. The processing queue has **3 priority levels** (0 = highest). Worker threads consume from the highest non-empty level first, then fall through to lower levels. Each worker thread has its own router instance, so multiple messages can be decoded in parallel without lock contention on the router state.

### Transmission

After ASN.1 decoding and JSON serialisation, the message is placed in the **transmission queue** for pub/sub delivery. This queue has **6 priority levels**, combining the application priority (0–2) with a source priority (0 = incoming middleware message, 1 = received over the air). Worker threads pull from the highest non-empty level and publish to all enabled brokers (MQTT local, MQTT remote, DDS, Zenoh) for that message.

---

## Priority Levels

Every application registers itself with a priority value (0, 1, or 2) that flows through both queues:

| Priority | Intended use |
|---|---|
| 0 | Safety-critical messages — DENM, SREM/SSEM |
| 1 | Regular cooperative awareness — CAM, VAM, CPM |
| 2 | Infrastructure / map data — MAPEM, SPATEM, RTCMEM, IVIM |

The transmission queue multiplies the priority space: `effective_priority = app_priority + (3 × source_priority)`, giving 6 distinct levels. A priority-0 message from the middleware (a DENM being injected for transmission) always outranks a priority-2 message received over the air.

---

## Thread Pool Size

The number of worker threads is set in `config.ini`:

```ini
[general]
num_threads=-1   ; -1 = auto (hardware_concurrency / 2)
```

Setting `-1` lets the runtime pick a sensible default based on the number of available CPU cores. On a platform with 4 cores it will use 2 worker threads; on an 8-core machine, 4. This can be overridden with an explicit count if needed.

Each worker thread in the processing stage gets its own `geonet::Router` instance, so decoding scales linearly with thread count up to the point where the network interface itself becomes the bottleneck.

---

## Why This Matters

In practice the threading architecture means:

- <o>The radio receive loop is never blocked</o> by a slow broker connection or a large CPM being serialised to JSON.
- <o>Safety messages jump the queue</o> — a DENM received during heavy CPM traffic will be published before any pending lower-priority messages.
- <o>Parallel decoding</o> — on a multi-core APU, multiple CAMs or CPMs arriving in the same interval can be decoded simultaneously rather than queued behind each other.
- <o>No added complexity for applications</o> — each application implements a single `on_message` callback; the threading and queuing is handled entirely by the infrastructure.
