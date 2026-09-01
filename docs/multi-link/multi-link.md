# Multi-Link

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Vanetza-NAP can operate over two transport types simultaneously: a raw Ethernet link for ITS-G5 radio, and a UDP multicast link for IP networks. When both are enabled, the same GeoNetworking stack transmits on and receives from both interfaces at once, with no changes to applications or the pub/sub layer above.

---

## The Two Transport Types

### ITS-G5 (Raw Ethernet)

The ITS-G5 link uses a raw AF_PACKET socket bound directly to a wireless interface. GeoNetworking frames are sent and received as raw Ethernet frames using EtherType `0x8947`, bypassing the IP stack entirely. This is the standard transport for vehicle-to-vehicle (V2V) and vehicle-to-infrastructure (V2I) communication as defined in [ETSI EN 302 663](https://www.etsi.org/deliver/etsi_en/302600_302699/302663/01.03.01_60/en_302663v010301p.pdf).

This mode requires a compatible 802.11p radio (ITS-G5 / DSRC) or a PC5 interface. It provides the low-latency broadcast semantics that V2X use cases depend on: a CAM or DENM transmitted on ITS-G5 reaches all stations within radio range with no routing infrastructure required.

### UDP Multicast

The UDP link sends and receives GeoNetworking frames encapsulated in UDP multicast packets. By default it uses multicast group `239.118.122.97:8947`, configurable via `config.ini`. Any host on the same IP multicast domain receives the traffic, which makes it suitable for emulated or virtualised deployments where no real ITS-G5 radio is present.

UDP transport is also useful for connecting APUs to each other over a wired LAN, enabling multi-hop or infrastructure-assisted scenarios where the ITS stack runs on a server or in a container rather than directly on radio hardware.

---

## Running Both at Once

When `ipv4_enabled=true` in `config.ini`, Vanetza-NAP creates a `MultiLink` that wraps both the Ethernet and UDP link layers. Outbound packets are cloned and transmitted on both simultaneously. Inbound packets from either interface are fed into the same GeoNetworking router and processed identically.

```ini
[ipv4]
enabled=true
address=239.118.122.97
port=8947
interface=eth0
```

From the perspective of the router, applications, and pub/sub layer, there is no difference between a message received from ITS-G5 and one received from UDP — both arrive through the same indication callback with the same GeoNetworking metadata.

---

## Use Cases

<o>Simulation and testing</o> — run Vanetza-NAP in a virtual machine or container without any radio hardware. Use the UDP link to exchange ITS messages between multiple instances over a LAN or loopback, exercising the full protocol stack including security, GeoNetworking, and pub/sub publishing.

<o>Hybrid deployments</o> — an APU with an ITS-G5 radio talks to nearby vehicles over the air, while simultaneously forwarding all traffic to a server over UDP. The server runs its own Vanetza-NAP instance that receives and processes the same messages without a radio of its own.

---

## Abstraction

The `LinkLayer` interface is the only boundary between the transport and the rest of the stack. Both `RawSocketLink` (Ethernet/ITS-G5) and `UdpLink` implement the same two methods: `request` to send a packet and `indicate` to register a receive callback. `MultiLink` wraps a list of these implementations and fans out transmissions and aggregates receptions transparently.

This means adding a new transport type — a future PC5 sidelink, a serial radio, or a custom hardware interface — requires only implementing `LinkLayer` and adding it to the `MultiLink`. No changes to the router, applications, or pub/sub layer are needed.
