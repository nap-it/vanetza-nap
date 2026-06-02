---
title: How to use Vanetza-NAP
---

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

# How to Use Vanetza-NAP

Vanetza-NAP is designed to be deployed as a **Docker container**. The container packages the `socktap` binary together with all required runtime dependencies (MQTT, DDS, Zenoh, GPS libraries, etc.) and is configured through a `config.ini` file mounted into the container.

## Prerequisites

- Docker
- A `config.ini` file (see [Configuration Reference](configuration.md))
- An ITS-G5 (802.11p) network interface, or a UDP/IPv4 link

## Quick Start

### 1. Prepare your configuration

Copy the default configuration template and adjust it to your deployment:

```bash
cp tools/socktap/config.ini ./config.ini
```

At minimum, you should configure:

- **`[station]`** section: set your station `id`, `type` (5 for OBU, 15 for RSU), and `mac_address`
- **`[general]`** section: set the network `interface` (e.g., `wlan0`)
- **`[mqtt]`** section: point `local_mqtt_broker` to your MQTT broker (or use the embedded one)

### 2. Run with Docker

```bash
docker run -d --name vanetza \
  --network host \
  --cap-add NET_ADMIN \
  --ipc shareable \
  --shm-size 300M \
  --volume ./config.ini:/config.ini \
  -e START_EMBEDDED_MOSQUITTO=true \
  code.nap.av.it.pt:5050/mobility-networks/vanetza-nap:atcll
```

> <o>**_NOTE:_** `--network host` is required so the container can access the host's network interfaces (ITS-G5 radio, Ethernet). `--cap-add NET_ADMIN` is required for raw socket access and optional bridge/ebtables operations.</o>

### 3. Run with Docker Compose

Create a `docker-compose.yml`:

```yaml
version: '2.4'
services:
  vanetza:
    hostname: vanetza
    restart: always
    image: code.nap.av.it.pt:5050/mobility-networks/vanetza-nap:atcll
    volumes:
      - ./config.ini:/config.ini
    cap_add:
      - "NET_ADMIN"
    network_mode: "host"
    ipc: shareable
    shm_size: 300M
    environment:
      - START_EMBEDDED_MOSQUITTO=true
```

Then start:

```bash
docker compose up -d
```

## Container Runtime Flags

| Flag | Required | Description |
|---|---|---|
| `--network host` | Yes | Direct access to host network interfaces |
| `--cap-add NET_ADMIN` | Yes | Raw socket access and network configuration |
| `--ipc shareable` | Recommended | Required for Zenoh shared memory IPC |
| `--shm-size 300M` | Recommended | Shared memory allocation for Zenoh (default 10 MB internal pool) |
| `--volume ./config.ini:/config.ini` | Yes | Mount your configuration file |

## Environment Variables

All configuration fields can be overridden via environment variables, which take precedence over `config.ini` values. This is useful for Docker deployments where you want a base config file but need to override specific values per-instance.

The naming pattern is `VANETZA_<FIELD>` for global settings, and `VANETZA_<APP>_<FIELD>` for per-application settings. See the [Configuration Reference](configuration.md) for the full list.

**Example**: Override station ID and interface without modifying the config file:

```bash
docker run -d --network host --cap-add NET_ADMIN \
  --volume ./config.ini:/config.ini \
  -e VANETZA_STATION_ID=42 \
  -e VANETZA_STATION_TYPE=5 \
  -e VANETZA_INTERFACE=wlan1 \
  -e VANETZA_USE_HARDCODED_GPS=false \
  -e START_EMBEDDED_MOSQUITTO=true \
  code.nap.av.it.pt:5050/mobility-networks/vanetza-nap:atcll
```

## Entrypoint Behavior

The container's entrypoint script (`/entrypoint.sh`) performs several setup steps before starting the application:

### 1. Global board config merge (optional)

If a file `/info.ini` is mounted into the container, the entrypoint reads fields from it and applies them to `/config.ini`. This is intended for fleet deployments where a central management system provides per-device identity:

| `/info.ini` field | Applied to `config.ini` |
|---|---|
| `[general] id` | `[station] id` and `[general] dds_domain_id` |
| `[mobility] stationType` | `[station] type` |
| `[mobility] latitude` | `[station] latitude` |
| `[mobility] longitude` | `[station] longitude` |
| `[mobility] macAddr` | `[station] mac_address` |
| `[mobility] interface` | `[general] interface` |

### 2. MAC blocking bridge (optional)

If the environment variable `SUPPORT_MAC_BLOCKING=true` is set, the entrypoint creates a network bridge (`br0`) and sets up `ebtables`-based MAC filtering. This provides `/bin/block <mac>` and `/bin/unblock <mac>` commands inside the container.

### 3. Embedded MQTT broker (optional)

If `START_EMBEDDED_MOSQUITTO=true` is set, the entrypoint starts a local Mosquitto broker inside the container on port `EMBEDDED_MOSQUITTO_PORT` (default: 1883). This is useful for standalone deployments where no external broker is available or even for contaneirized simulation environments.

### 4. Application start

The entrypoint launches the main application:

```
/usr/local/bin/socktap -c /config.ini
```

## Command-Line Options

The `socktap` binary accepts the following command-line arguments:

| Option | Description |
|---|---|
| `-c, --config <path>` | Path to the configuration file (default: `config.ini`) |
| `--require-gnss-fix` | Do not transmit packets until a valid GNSS fix is obtained |
| `--help` | Print available options |

## GPS Positioning

Vanetza-NAP supports two positioning modes:

### Live GPS (default for OBU)

Set `use_hardcoded_gps=false` in `config.ini`. The application connects to a `gpsd` daemon via TCP:

- <o>**Host**</o>: configured via `gpsd_host` (default: `127.0.0.1`)
- <o>**Port**</o>: configured via `gpsd_port` (default: `2947`)

The `gpsd` daemon must be running and accessible from the container. If using `--network host`, the container can reach a host-local `gpsd` at `127.0.0.1:2947`.

### Hardcoded GPS (default for RSU)

Set `use_hardcoded_gps=true` in `config.ini`. The application uses static coordinates from the `[station]` section:

```ini
[station]
use_hardcoded_gps=true
latitude=40.0
longitude=-8.0
```

## Interacting with Vanetza-NAP

Once running, you can interact with Vanetza-NAP through any of its pub/sub endpoints.

### Subscribing to received messages (MQTT)

```bash
# Listen for all received CAM messages
mosquitto_sub -h 127.0.0.1 -t vanetza/out/cam

# Listen for all received DENM messages
mosquitto_sub -h 127.0.0.1 -t vanetza/out/denm

# Listen for self-generated CAM messages
mosquitto_sub -h 127.0.0.1 -t vanetza/own/cam
```

### Sending a message over-the-air (MQTT)

```bash
# Send a CAM message (payload-only format, header auto-generated)
mosquitto_pub -h 127.0.0.1 -t vanetza/in/cam -f examples/in_cam.json

# Send a DENM message
mosquitto_pub -h 127.0.0.1 -t vanetza/in/denm -f examples/in_denm.json
```

### Monitoring timing metadata

```bash
# Monitor CAM transmission timing
mosquitto_sub -h 127.0.0.1 -t vanetza/time/cam
```

### Checking Prometheus metrics

```bash
curl http://localhost:9100/metrics
```


## Required Ports and Services

| Port | Service | Direction | Notes |
|---|---|---|---|
| 1883 | MQTT Broker | In/Out | Local message bus  |
| 2947 | gpsd | Out | GPS positioning (only if `use_hardcoded_gps=false`) |
| 9100 | Prometheus | Out | Metrics endpoint |
| 5004 | CAM UDP | Out | Optional UDP output for CAM (configurable per-app) |
| 7447 | Zenoh | In/Out | Zenoh session (loopback by default) |
| 8947 | IPv4 multicast | In/Out | Optional UDP multicast transport (disabled by default) |

## Building the Docker Image

To build the Docker image from source:

```bash
docker build -t vanetza-nap:latest .
```

