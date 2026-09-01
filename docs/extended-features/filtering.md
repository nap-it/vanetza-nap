# Message Filtering

Vanetza-NAP can filter incoming ITS messages at the reception gate — before they enter the processing queue, before any decoding happens, and before anything is published to the middleware. This keeps unwanted traffic out of the pipeline entirely rather than filtering it downstream.

---

## Ignore Own Messages

When a station transmits an ITS message over ITS-G5, the raw Ethernet frame is broadcast and received by the same radio interface that sent it. Without filtering, Vanetza-NAP would process and publish its own outgoing CAMs as if they were received from another station — duplicating data and potentially confusing consumers that assume `topic_out` contains only messages from other vehicles.

`ignore_own_messages` prevents this. When enabled, the source MAC address of every incoming frame is compared against the local station's GeoNetworking address at the earliest possible point in the receive path — right at the `indicate` callback before the packet enters the reception queue. Frames originating from the local interface are silently dropped. Everything else proceeds normally.

```ini
[general]
ignore_own_messages=true
```

This is enabled by default and should remain on in all normal deployments.

## Ignore RSU Messages

`ignore_rsu_messages` is a configurable flag intended for deployments where messages from Road Side Units should be excluded from the processing pipeline — for example, a vehicle-only data collection scenario where RSU infrastructure traffic is irrelevant or would inflate message counts.

```ini
[general]
ignore_rsu_messages=false
```

This is disabled by default, meaning all received messages regardless of sender type are processed normally.

---

## Where Filtering Happens

Both filters operate at the lowest point in the stack — the `RouterContext::indicate` function, which is the direct callback from the link layer. A packet that does not pass the filter is discarded immediately and never touches the reception queue, the GeoNetworking router, or the pub/sub layer. There is no cost beyond the MAC comparison itself.

This is intentional: filtering as early as possible avoids wasting worker thread time on packets that would only be dropped later, which matters in high-density environments where the radio interface can deliver hundreds of packets per second.
