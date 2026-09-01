# Prometheus Metrics

Vanetza-NAP exposes operational metrics via a Prometheus HTTP endpoint. These metrics cover message throughput and end-to-end processing latency for every ITS message type in both directions, making it straightforward to integrate into any standard monitoring stack.

---

## Configuration

The exporter is enabled by setting a non-zero port in `config.ini`:

```ini
[general]
prometheus_port=9100
```

Setting `prometheus_port=0` disables the exporter entirely. When enabled, Vanetza-NAP binds an HTTP server on `0.0.0.0:<port>` and serves the standard Prometheus text exposition format at `/metrics`.

---

## Available Metrics

Two metric families are exposed, each labelled by message type and direction:

### `observed_packets_count_total`

A monotonically increasing counter of processed packets. Labels:

- `message` — the ITS message type (`cam`, `denm`, `cpm`, `vam`, `spatem`, `mapem`, `ssem`, `srem`, `rtcmem`, `ivim`, ...)
- `direction` — `rx` for received (over-the-air → published to middleware) or `tx` for transmitted (received from middleware → sent over-the-air)

### `observed_packets_latency_total`

A monotonically increasing counter accumulating the total processing latency in seconds across all packets. Dividing this by `observed_packets_count_total` for the same label set gives the average end-to-end latency per message.

- `rx` latency is measured from the moment the raw packet arrived on the network interface (`time_received`) to the moment the last pub/sub publish (including remote MQTT) completes.
- `tx` latency is measured from the moment the JSON was received from the middleware to the moment the GeoNetworking router accepted the packet for transmission.

---

## Example Output

```
# HELP observed_packets_count_total Number of observed packets
# TYPE observed_packets_count_total counter
observed_packets_count_total{direction="rx",message="cam"} 1042
observed_packets_count_total{direction="tx",message="cam"} 87
observed_packets_count_total{direction="rx",message="cpm"} 310
observed_packets_count_total{direction="rx",message="denm"} 5

# HELP observed_packets_latency_total Processing latency of observed packets
# TYPE observed_packets_latency_total counter
observed_packets_latency_total{direction="rx",message="cam"} 0.523
observed_packets_latency_total{direction="tx",message="cam"} 0.031
```

Average RX latency for CAMs: `0.523 / 1042 ≈ 0.50 ms`

---

## Integration

The endpoint is compatible with any standard Prometheus scrape configuration:

```yaml
scrape_configs:
  - job_name: vanetza
    static_configs:
      - targets: ['<host>:9100']
```

From there, metrics can be visualised in Grafana, used for alerting via Alertmanager, or consumed by any other tool in the Prometheus ecosystem. The per-message-type labels make it easy to build dashboards that break down throughput and latency by message class, or to set alerts when a message type stops being received or latency exceeds a threshold.
