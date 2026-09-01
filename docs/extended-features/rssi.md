# RSSI Measurement

<style>
r { color: Red }
o { color: Orange }
g { color: Green }
</style>

Vanetza-NAP enriches every received ITS message with radio channel metrics collected directly from the wireless interface. Signal strength, channel quality, and modulation information are attached to the decoded JSON and published alongside the message payload, giving downstream services a full picture of the radio environment at the moment of reception.

---

## Why Measure RSSI?

The raw content of an ITS message tells you what a vehicle reported. The radio metrics tell you how reliably that report was received and how crowded the channel is. Together they enable use cases that message content alone cannot support:

- <o>Link quality estimation</o> — a CAM received at −90 dBm from a vehicle 50 m away suggests a degraded radio path; the same CAM at −65 dBm indicates a healthy link.
- <o>Channel load monitoring</o> — busy time and RX/TX fractions reveal how saturated the ITS-G5 medium is, which is relevant for congestion control and adaptive beacon rate decisions.
- <o>Ranging and localisation support</o> — RSSI can be used as a coarse proximity indicator when combined with position data from the message itself.
- <o>Data quality filtering</o> — a service that fuses cooperative perception data can weight or discard messages received below a signal threshold.

---

## How It Works

The RSSI reader runs as a background thread that continuously queries the wireless driver through the **nl80211 kernel interface** (via Generic Netlink). This is the same interface used by tools like `iw` and `iwconfig` — it communicates with the 802.11 driver directly, without going through user space utilities or parsing command output.

Every **50 ms**, the reader sends three netlink queries to the driver:

1. **`NL80211_CMD_GET_INTERFACE`** — resolves the interface name to its kernel index.
2. **`NL80211_CMD_GET_STATION`** — retrieves per-neighbour station statistics: signal strength (dBm, averaged), TX bitrate, and expected throughput, indexed by MAC address.
3. **`NL80211_CMD_GET_SURVEY`** — retrieves channel survey data for the active frequency: noise floor, channel busy time, RX time fraction, and TX time fraction.

Results are stored in in-memory maps keyed by MAC address. Entries that have not been updated for more than 1 second are automatically evicted, so the tables always reflect only currently active neighbours.

When a packet arrives on the radio interface, the receiving thread looks up the source MAC address in the RSSI map and attaches the current values to the `CohesivePacket` before it is handed to the GeoNetworking router. By the time the application sees the packet, the radio metrics are already embedded.

---

## Collected Metrics

| Field | Source | Description |
|---|---|---|
| `rssi` | `NL80211_STA_INFO_SIGNAL_AVG` | Average signal strength of the sender in dBm |
| `mcs` | `NL80211_RATE_INFO_BITRATE` | MCS index (1–8) derived from TX bitrate |
| `frequency` | `NL80211_SURVEY_INFO_FREQUENCY` | Active channel frequency in MHz |
| `noise` | `NL80211_SURVEY_INFO_NOISE` | Noise floor in dBm |
| `chan_busy_time` | `NL80211_SURVEY_INFO_CHANNEL_TIME_BUSY` | Fraction of time the channel was busy (0.0–1.0) |
| `chan_rx_time` | `NL80211_SURVEY_INFO_CHANNEL_TIME_RX` | Fraction of time spent receiving |
| `chan_tx_time` | `NL80211_SURVEY_INFO_CHANNEL_TIME_TX` | Fraction of time spent transmitting |

The MCS index is derived from the TX bitrate reported by the driver, mapped to the 802.11p MCS table (1 = lowest, 8 = highest). A value of −1 indicates the bitrate falls outside the expected range.

---

## Configuration

RSSI collection is enabled in `config.ini`:

```ini
[general]
rssi_enabled=true
mcs_enabled=false
```

When `rssi_enabled=false`, the reader thread is never started and all metric fields default to their sentinel values (`rssi = -255`, `frequency = -1`, etc.). The rest of the pipeline is unaffected.

---

## Output in JSON

The collected metrics are included in every published JSON message under their respective fields, alongside the decoded ITS content:

```json
{
  "rssi": -72,
  "mcs": 5,
  "frequency": 5900,
  "noise": -95,
  "chan_busy_time": 0.12,
  "chan_rx_time": 0.09,
  "chan_tx_time": 0.03,
  "cam": { ... }
}
```

Consumers subscribed to any pub/sub topic receive these fields as part of the same message, with no additional queries or side channels required.
