# Vanetza MQTT Tester - Usage Guide

## Overview

`vanetza_test.py` is a unified tool for testing CAM (Cooperative Awareness Message) integrity through the Vanetza V2X stack via MQTT.

**Test Workflow:**
1. Sender publishes a CAM message to MQTT broker
2. Message passes through Vanetza processing
3. Receiver echoes the message back
4. Sender validates the echo matches the original (using hash comparison)

## Installation

```bash
# Install dependencies
pip3 install -r requirements.txt

# Or install manually
pip3 install paho-mqtt
```

## Quick Start

### Local Testing (Same Machine)

**Terminal 1 - Start Receiver:**
```bash
python3 vanetza_test.py receiver --broker localhost
```

**Terminal 2 - Run Sender Test:**
```bash
python3 vanetza_test.py sender --broker localhost --station-id 111
```

### Remote Testing (Two Machines)

Assuming both machines can access MQTT broker at `192.168.1.100`:

**Machine A (Receiver):**
```bash
python3 vanetza_test.py receiver --broker 192.168.1.100
```

**Machine B (Sender):**
```bash
python3 vanetza_test.py sender --broker 192.168.1.100 --station-id 111
```

## Command Reference

### Receiver Mode

Start echo service that listens for CAM messages and echoes them back.

```bash
python3 vanetza_test.py receiver [OPTIONS]
```

**Common Options:**
- `--broker IP` - MQTT broker address (default: 127.0.0.1)
- `--port PORT` - MQTT broker port (default: 1883)
- `--filter-station ID` - Only echo messages from specific station ID
- `--quiet` - Suppress verbose output

**Examples:**
```bash
# Echo all messages
python3 vanetza_test.py receiver --broker 192.168.1.100

# Only echo messages from station ID 100
python3 vanetza_test.py receiver --broker 192.168.1.100 --filter-station 100

# Quiet mode (minimal output)
python3 vanetza_test.py receiver --broker 192.168.1.100 --quiet
```

### Sender Mode

Send a CAM message, wait for echo, and validate integrity.

```bash
python3 vanetza_test.py sender [OPTIONS]
```

**Common Options:**
- `--broker IP` - MQTT broker address (default: 127.0.0.1)
- `--station-id ID` - Station ID to use (default: 111)
- `--input-file FILE` - Input CAM JSON file (default: in_cam.json)
- `--timeout SECONDS` - Wait timeout (default: 10)
- `--quiet` - Suppress verbose output

**Examples:**
```bash
# Basic test with default settings
python3 vanetza_test.py sender --broker 192.168.1.100 --station-id 111

# Custom input file and longer timeout
python3 vanetza_test.py sender --broker 192.168.1.100 \
    --station-id 111 \
    --input-file custom_cam.json \
    --timeout 30

# Quiet mode (only show errors)
python3 vanetza_test.py sender --broker 192.168.1.100 --station-id 111 --quiet
```

## Exit Codes

The script uses standard exit codes for CI/CD integration:

- **0** - Test passed successfully
- **1** - Test failed (timeout, data mismatch, connection error, etc.)

**Check exit code in bash:**
```bash
python3 vanetza_test.py sender --broker localhost --station-id 111
echo $?  # Prints 0 for success, 1 for failure
```

## Advanced Configuration

### Custom MQTT Topics

```bash
# Receiver with custom topics
python3 vanetza_test.py receiver \
    --broker 192.168.1.100 \
    --topic-in vanetza/custom/in \
    --topic-out vanetza/custom/out

# Sender with custom topics (must match receiver!)
python3 vanetza_test.py sender \
    --broker 192.168.1.100 \
    --station-id 111 \
    --topic-in vanetza/custom/in \
    --topic-out vanetza/custom/out
```

### Environment Variables (Future Enhancement)

Currently, all configuration is via CLI flags. Environment variable support can be added:

```bash
# Potential future usage
export MQTT_BROKER=192.168.1.100
export MQTT_PORT=1883
export STATION_ID=111

python3 vanetza_test.py sender  # Uses env vars
```

## Troubleshooting

### "ERROR: Failed to connect to MQTT broker"

**Cause:** MQTT broker is not running or not accessible.

**Solutions:**
1. Verify broker is running: `netstat -tlnp | grep 1883`
2. Check broker address is correct
3. Test connectivity: `telnet 192.168.1.100 1883`
4. Check firewall rules

### "ERROR: Test timeout after 10s - no echo received"

**Cause:** Receiver is not running, not echoing, or message is filtered.

**Solutions:**
1. Verify receiver is running on the other machine
2. Check station ID matches (sender sends with `--station-id`, receiver filters with `--filter-station`)
3. Verify both machines use same broker address
4. Increase timeout: `--timeout 30`
5. Check MQTT topics match between sender and receiver

### "ERROR: File not found: in_cam.json"

**Cause:** Input file doesn't exist.

**Solutions:**
1. Create `in_cam.json` in current directory
2. Use `--input-file` to specify different file path
3. Use absolute path: `--input-file /path/to/cam.json`

### "ERROR: Test failed - Hash mismatch between sent and received data"

**Cause:** Message was modified during transmission (this is the actual test failure).

**Solutions:**
1. This indicates a real problem with Vanetza message processing
2. Check Vanetza logs for encoding/decoding errors
3. Compare original vs received data in verbose output
4. Verify JSON structure matches expected CAM format

## File Structure

```
vanetza-tester/
├── vanetza_test.py      # Main unified script
├── requirements.txt     # Python dependencies
├── in_cam.json         # Input CAM test data
├── out_cam.json        # Example output (reference)
├── sender.py           # Legacy sender (deprecated)
└── receiver.py         # Legacy receiver (deprecated)
```

**Note:** `sender.py` and `receiver.py` are the old separate scripts. Use `vanetza_test.py` for new work.

## CI/CD Integration

### GitLab CI Example (Conceptual)

```yaml
test_vanetza:
  stage: test
  script:
    # Start receiver on remote machine
    - ssh machine-a "cd /path/to/vanetza-tester && python3 vanetza_test.py receiver --broker 192.168.1.100 > receiver.log 2>&1 &"
    - sleep 2  # Let receiver initialize
    
    # Run sender test on another machine
    - ssh machine-b "cd /path/to/vanetza-tester && python3 vanetza_test.py sender --broker 192.168.1.100 --station-id 111"
    
    # Cleanup
    - ssh machine-a "pkill -f vanetza_test.py"
  only:
    - main
    - merge_requests
```

### Exit Code Usage

```bash
#!/bin/bash
# Simple CI script

# Start receiver in background
python3 vanetza_test.py receiver --broker localhost > receiver.log 2>&1 &
RECEIVER_PID=$!

# Wait for receiver to start
sleep 2

# Run sender test
python3 vanetza_test.py sender --broker localhost --station-id 111
TEST_RESULT=$?

# Cleanup
kill $RECEIVER_PID

# Exit with test result
exit $TEST_RESULT
```

## Migration from Old Scripts

If you're using the old `sender.py` and `receiver.py`:

**Old receiver:**
```bash
python3 receiver.py
```

**New equivalent:**
```bash
python3 vanetza_test.py receiver --broker 127.0.0.1 --filter-station 100
```

**Old sender:**
```bash
python3 sender.py
```

**New equivalent:**
```bash
python3 vanetza_test.py sender --broker 127.0.0.1 --station-id 111
```

## Getting Help

```bash
# General help
python3 vanetza_test.py --help

# Mode-specific help is the same (all options shown)
python3 vanetza_test.py sender --help
python3 vanetza_test.py receiver --help
```

## Next Steps

1. **Test locally** - Run both receiver and sender on same machine
2. **Test remotely** - Run on two separate machines
3. **Integrate with CI/CD** - Add to your GitLab pipeline
4. **Customize** - Adjust station IDs, topics, timeouts as needed
