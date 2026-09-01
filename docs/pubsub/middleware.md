# Middleware

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Vanetza-NAP bridges the ITS-G5 wireless radio stack with the rest of your system through a unified publish/subscribe middleware layer. Every ITS message received over the air is decoded to JSON and published to one or more technologies. At the same time, any service that wants to transmit a message over the air simply publishes JSON to the corresponding input topic using a supported middleware, and Vanetza-NAP takes care of encoding and transmission.

---

## Why Publish/Subscribe?

A modern ITS deployment is not a single monolithic application — it is a collection of independent services, each with a distinct responsibility: a perception service transmiting cooperative objects, a traffic controller injecting signal phase data or a cloud pipeline logging every event.

In a microservice architecture, services are designed to be small, focused, and independently deployable. They communicate through well-defined interfaces rather than direct function calls or shared memory. This is where pub/sub fits naturally: instead of Vanetza-NAP needing to know about every consumer and producer, all services simply connect to a shared middleware and exchange data through topics.

The practical consequences of this decoupling are significant:

- <o>Independent deployment</o> — Vanetza-NAP can be updated, restarted, or replaced without touching any consumer.
- <o>No direct dependencies</o> — a traffic controller that injects SPATEMs does not need to link against Vanetza or know its internal API. It just publishes JSON to a topic.
- <o>Fan-out without coordination</o> — one received CAM can simultaneously reach a tracker, a logger, a UI, and a cloud forwarder. None of them need to know the others exist, and adding a new consumer requires zero changes to any existing service.
- <o>Fault isolation</o> — if an awareness service crashes, Vanetza-NAP keeps running. If Vanetza-NAP restarts, the awareness service reconnects and resumes. Services fail independently.
- <o>Testability</o> — any service in the system can be tested in isolation by publishing synthetic messages to its input topic or asserting on its output topic, with no real hardware required.

---

## The Three Middlewares

Vanetza-NAP supports three middlewares simultaneously. Each has a different deployment profile and set of trade-offs; all three can be active at the same time, and each can be enabled or disabled independently per message type.

### MQTT (Eclipse Mosquitto)

MQTT is a lightweight, TCP-based publish/subscribe protocol designed for constrained devices and high-latency or unreliable links. Messages are routed through a central broker; clients publish to topics and subscribe to topics independently.

Vanetza-NAP maintains two independent MQTT connections:

- <o>Local broker</o> — always present, running on `127.0.0.1:1883` by default. Used for intra-host communication between co-located services.
- <o>Remote broker</o> — optional. When configured, received messages are additionally forwarded to a remote broker under a station-prefixed topic (`<prefix><station_id>/<topic>`), enabling fleet-wide data collection without any changes to local consumers.

### DDS (Fast-DDS)

DDS (Data Distribution Service) is an OMG standard for real-time, peer-to-peer publish/subscribe. Unlike MQTT, there is no central broker: participants discover each other automatically on the local network using RTPS/UDP multicast. Topics are strongly typed, defined via IDL, and messages carry QoS policies (reliability, durability, deadline, etc.).

Vanetza-NAP publishes two IDL types per topic:

- `JSONMessage` — the decoded, human-readable JSON payload. Used for most integrations.
- `EncodedITSMessage` — the raw binary payload plus metadata (RSSI, packet size, station ID, receiver ID, timestamp). Used when the downstream consumer needs to re-encode or log the original packet.

**Interface blocking:** DDS uses multicast discovery, which by default propagates across all network interfaces — including the ITS-G5 radio. To prevent DDS traffic from leaking onto the ITS-G5 medium, the `dds_blocked_interfaces` setting specifies which interfaces the DDS participant must *not* use. If unset, the ITS interface from `[general]` is blocked automatically.

### Zenoh

Zenoh (Eclipse Zenoh) is a next-generation pub/sub and geo-distributed storage protocol. It unifies pub/sub, queries, and storage under a single key/value model, with efficient routing across heterogeneous transports (TCP, UDP, shared memory, serial, ...). Unlike MQTT it is brokerless by default and unlike DDS it does not rely on multicast.

 Zenoh excels at low-latency intra-host and inter-host communication. Its shared memory transport eliminates serialization overhead for co-located processes — a decoded CAM can be delivered to a consumer on the same host with effectively zero copy. For high-throughput scenarios (CPM dense environments, high-rate CAMs) this makes a measurable difference.

Vanetza-NAP starts a Zenoh **router** (not a peer) so that remote Zenoh clients can connect to it over TCP without needing multicast.

---

## Topic Types

Each application also publishes to auxiliary topics:

| Topic key             | Purpose                                                               |
|-----------------------|-----------------------------------------------------------------------|
| `topic_out`           | Decoded JSON of received ITS messages                                 |
| `topic_in`            | JSON input for transmission                                           |
| `topic_time`          | Timing metadata after transmission                                    |
| `topic_test`          | Timing metadata after reception                                       |
| `own_topic_out`       | JSON of messages transmitted by this station (CAM only)               |
| `udp_out_addr/port`   | Optional UDP unicast output for latency-sensitive local consumers     |

---

## Configuration

All pub/sub settings live in `config.ini`.

### Global broker settings

```ini
[mqtt]
local_mqtt_broker=127.0.0.1
local_mqtt_port=1883
remote_mqtt_broker=""       ; leave empty to disable
remote_mqtt_port=0          ; 0 to disable
remote_mqtt_username=""
remote_mqtt_password=""

[dds]
dds_domain_id=0
dds_participant_name=Vanetza
dds_blocked_interfaces=wlan0   ; interfaces DDS must NOT use

[zenoh]
zenoh_local_only=true          ; true = bind to loopback only
zenoh_interfaces=""            ; comma-separated interfaces allowed for remote Zenoh peers
```

### Per-message-type settings

Every message type (cam, denm, cpm, vam, spatem, mapem, ...) has its own section:

```ini
[cam]
enabled=true
mqtt_enabled=true
dds_enabled=true
zenoh_enabled=true
mqtt_time_enabled=true
mqtt_test_enabled=false
periodicity=1000              ; TX interval in ms, 0 to disable periodic TX
topic_in=vanetza/in/cam
topic_out=vanetza/out/cam
topic_time=vanetza/time/cam
topic_test=vanetza/test/cam
own_topic_out=vanetza/own/cam
udp_out_addr=127.0.0.1
udp_out_port=5004             ; 0 to disable UDP output
```

Disabling a broker for a specific message type (`dds_enabled=false`) prevents that message from being published or subscribed via that broker, with no effect on the others.

---

## Options Reference

### Remote MQTT

When `remote_mqtt_port` is non-zero, received messages are forwarded to the remote broker. The topic is prefixed with `remote_mqtt_prefix` + `station_id` so that a single remote broker can aggregate data from an entire fleet without topic collisions.

```ini
remote_mqtt_broker=192.168.1.10
remote_mqtt_port=1883
remote_mqtt_username=vanetza
remote_mqtt_password=secret
```

### DDS Interface Blocking

DDS uses UDP multicast for participant discovery. Without restriction, DDS control traffic would appear on the ITS-G5 interface. `dds_blocked_interfaces` takes a comma-separated list of interfaces that the DDS participant is prohibited from using:

```ini
dds_blocked_interfaces=wlan0
```

If left empty, the ITS interface specified in `[general] interface` is used as the default block list.

### Zenoh Local-Only Mode

When `zenoh_local_only=true`, the Zenoh router binds only to `127.0.0.1:7447`. Remote Zenoh clients cannot connect. This is the safe default for single-host deployments.

When `zenoh_local_only=false`, the router binds to `0.0.0.0:7447` and accepts remote connections. Use `zenoh_interfaces` to restrict which network interfaces remote peers may use (access control is enforced by the Zenoh router before any message is forwarded):

```ini
zenoh_local_only=false
zenoh_interfaces=eth0,eth1   ; only allow Zenoh peers on these interfaces
```

### Zenoh Shared Memory

When a Zenoh publisher and subscriber are on the same host, Zenoh can use POSIX shared memory instead of TCP sockets. Vanetza-NAP initialises a 10 MB shared memory provider at startup. Any subscriber that supports the SHM transport will receive messages with zero-copy semantics.

This is transparent to the application code — no configuration is required on the Vanetza side. The consumer must be a Zenoh client compiled with SHM support.

## Advantages

- <o>No single point of failure</o> — MQTT, DDS and Zenoh operate independently.
- <o>Incremental adoption</o> — existing services using MQTT require no changes; DDS and Zenoh consumers can be added alongside them.
- <o>Low-latency local path</o> — Zenoh shared memory gives co-located consumers near-zero delivery overhead.
- <o>Fleet aggregation</o> — the remote MQTT bridge allows a single backend to receive telemetry from hundreds of stations without any per-station configuration.
- <o>ITS network isolation</o> — DDS interface blocking and Zenoh local-only mode prevent middleware traffic from polluting the ITS-G5 medium.
