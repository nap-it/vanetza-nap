#!/usr/bin/env python3

"""
Vanetza MQTT Message Integrity Tester
This script tests the integrity of various V2X messages (CAM, CPM, DENM, etc.)
transmission through the Vanetza V2X stack via MQTT.
Workflow:
1. Sender publishes message to MQTT broker
2. Message goes through Vanetza processing
3. Receiver echoes the message back
4. Sender compares echoed message with original using hash comparison
Usage:
    python3 vanetza_test.py sender --broker <ip> --station-id <id>
    python3 vanetza_test.py receiver --broker <ip> [--filter-station <id>]
    python3 vanetza_test.py batch --broker <ip> --station-id <id>
"""

import argparse
import json
import os
import signal
import sys
import threading
import time
from threading import Event
from typing import Any, Dict, List, Optional

import paho.mqtt.client as mqtt
from deepdiff import DeepDiff

# ============================================================================
# CONSTANTS AND DEFAULTS
# ============================================================================

DEFAULT_BROKER = "127.0.0.1"
DEFAULT_PORT = 1883
DEFAULT_TIMEOUT = 10
DEFAULT_INPUT_FILE = "message_examples/in_cam.json"
DEFAULT_TOPIC_IN = "vanetza/in/cam"
DEFAULT_TOPIC_OUT = "vanetza/out/#"
DEFAULT_STATION_ID = 111
DEFAULT_EXAMPLE_DIR = "message_examples/"


# ============================================================================
# GLOBAL STATE
# ============================================================================

# Event to signal message received (for sender mode)
received_event = Event()

# Flag to track test result
test_passed = False
test_error_message = ""

# MQTT client (global for signal handler access)
mqtt_client: Optional[mqtt.Client] = None


# ============================================================================
# SIGNAL HANDLERS
# ============================================================================


def signal_handler(sig, frame):
    """Handle SIGINT and SIGTERM for graceful shutdown."""
    print("\nShutting down gracefully...", file=sys.stderr)
    if mqtt_client:
        mqtt_client.loop_stop()
        mqtt_client.disconnect()
    sys.exit(1)


signal.signal(signal.SIGINT, signal_handler)
signal.signal(signal.SIGTERM, signal_handler)


# ============================================================================
# UTILITY FUNCTIONS
# ============================================================================


def load_json_file(filepath: str) -> Dict[str, Any]:
    """Load and parse JSON file."""
    try:
        with open(filepath, "r") as f:
            return json.load(f)
    except FileNotFoundError:
        print(f"ERROR: File not found: {filepath}", file=sys.stderr)
        sys.exit(1)
    except json.JSONDecodeError as e:
        print(f"ERROR: Invalid JSON in {filepath}: {e}", file=sys.stderr)
        sys.exit(1)


def create_mqtt_client(broker: str, port: int, on_connect, on_message) -> mqtt.Client:
    """Create and connect MQTT client."""
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message

    try:
        client.connect(broker, port, 60)
        return client
    except Exception as e:
        print(
            f"ERROR: Failed to connect to MQTT broker {broker}:{port}", file=sys.stderr
        )
        print(f"       {e}", file=sys.stderr)
        sys.exit(1)


def log(message: str, verbose: bool = True):
    """Print message if verbose mode enabled."""
    if verbose:
        print(message)


def print_field_differences(
    original: Dict[str, Any], received: Dict[str, Any], verbose: bool
):
    """Print detailed field-level differences between original and received messages.

    Args:
        original: Original message data (sorted)
        received: Received message data (sorted)
        verbose: If True, also print full dictionary dumps
    """
    # Compute deep differences
    diff = DeepDiff(original, received, ignore_order=False, report_repetition=True)

    # Always print diff to stderr
    print("\n=== FIELD DIFFERENCES ===", file=sys.stderr)

    if not diff:
        print(
            "No differences found (this shouldn't happen with hash mismatch!)",
            file=sys.stderr,
        )
        return

    # Print values that changed
    if "values_changed" in diff:
        print("\nValues Changed:", file=sys.stderr)
        for path, change in diff["values_changed"].items():
            print(f"  {path}:", file=sys.stderr)
            print(f"    - Original: {change['old_value']}", file=sys.stderr)
            print(f"    + Received: {change['new_value']}", file=sys.stderr)

    # Print items removed
    if "dictionary_item_removed" in diff:
        print(
            "\nFields Removed (present in original, missing in received):",
            file=sys.stderr,
        )
        for item in diff["dictionary_item_removed"]:
            print(f"  {item}", file=sys.stderr)

    # Print items added
    if "dictionary_item_added" in diff:
        print(
            "\nFields Added (missing in original, present in received):",
            file=sys.stderr,
        )
        for item in diff["dictionary_item_added"]:
            print(f"  {item}", file=sys.stderr)

    # Print type changes
    if "type_changes" in diff:
        print("\nType Changes:", file=sys.stderr)
        for path, change in diff["type_changes"].items():
            old_type = change["old_type"].__name__
            new_type = change["new_type"].__name__
            print(f"  {path}: {old_type} -> {new_type}", file=sys.stderr)
            print(f"    - Original: {change['old_value']}", file=sys.stderr)
            print(f"    + Received: {change['new_value']}", file=sys.stderr)

    # Print iterable item changes (for lists/arrays)
    if "iterable_item_removed" in diff:
        print("\nList Items Removed:", file=sys.stderr)
        for path, value in diff["iterable_item_removed"].items():
            print(f"  {path}: {value}", file=sys.stderr)

    if "iterable_item_added" in diff:
        print("\nList Items Added:", file=sys.stderr)
        for path, value in diff["iterable_item_added"].items():
            print(f"  {path}: {value}", file=sys.stderr)

    # Print repetition changes (if items appear different number of times)
    if "repetition_change" in diff:
        print("\nRepetition Changes:", file=sys.stderr)
        for path, change in diff["repetition_change"].items():
            print(f"  {path}:", file=sys.stderr)
            print(f"    Original count: {change['old_repeat']}", file=sys.stderr)
            print(f"    Received count: {change['new_repeat']}", file=sys.stderr)

    print("\n=== END DIFFERENCES ===\n", file=sys.stderr)

    # If verbose mode, also print full dictionaries
    if verbose:
        print(f"Original data: {original}", file=sys.stderr)
        print(f"Received data: {received}", file=sys.stderr)


# ============================================================================
# SENDER MODE FUNCTIONS
# ============================================================================


def sender_on_connect(client, userdata, flags, rc, *args):
    """Callback when sender connects to MQTT broker."""
    args_dict = userdata
    topic_out = args_dict["topic_out"]
    verbose = args_dict["verbose"]

    if rc != 0:
        print(f"ERROR: Failed to connect to broker, return code {rc}", file=sys.stderr)
        sys.exit(1)

    log(f"Connected to broker. Subscribing to: {topic_out}", verbose)
    client.subscribe(topic_out)


def sender_on_message(client, userdata, msg):
    """Callback when sender receives message (the echo)."""
    global test_passed, test_error_message

    args_dict = userdata
    station_id = args_dict["station_id"]
    input_file = args_dict["input_file"]
    verbose = args_dict["verbose"]
    topic_in = msg.topic.replace("out", "in")
    message_type = topic_in.split("/")[-1]

    try:
        message = msg.payload.decode("utf-8")
        obj = json.loads(message)
        received_station_id = obj.get("stationID", "unknown")

        log(f"Received message from station ID: {received_station_id}", verbose)

        # Check if this is our echo
        if received_station_id == station_id:
            log("Validating received message...", verbose)

            # Extract message data
            if "fields" in obj and message_type in obj["fields"]:
                print("Echoing message type:", message_type)
                received_cam = obj["fields"][message_type]
            else:
                content_key = list(obj["fields"].keys())[1]
                print("Echoing message type:", content_key)
                received_cam = obj["fields"][content_key]

            # Load original message
            original_data = load_json_file(input_file)

            # Sort for consistent comparison
            sorted_received = dict(sorted(received_cam.items()))
            sorted_original = dict(sorted(original_data.items()))

            # Hash comparison
            received_hash = hash(json.dumps(sorted_received, sort_keys=True))
            original_hash = hash(json.dumps(sorted_original, sort_keys=True))

            log(f"Original hash:  {original_hash}", verbose)
            log(f"Received hash:  {received_hash}", verbose)

            if received_hash == original_hash:
                log("✓ SUCCESS: Data matches!", verbose)
                test_passed = True
            else:
                log("✗ FAILURE: Data mismatch!", verbose)
                print_field_differences(sorted_original, sorted_received, verbose)
                test_passed = False
                test_error_message = "Hash mismatch between sent and received data"

            # Signal that we received the echo
            received_event.set()
        else:
            log(
                f"Ignoring message from station ID {received_station_id} (expecting {station_id})",
                verbose,
            )

    except Exception as e:
        print(f"ERROR: Failed to process received message: {e}", file=sys.stderr)
        test_passed = False
        test_error_message = str(e)
        received_event.set()


def send_message(client, input_file: str, topic_in: str, verbose: bool):
    """Send CAM message to MQTT broker."""
    try:
        data = load_json_file(input_file)
        payload = json.dumps(data)

        log(f"Sending CAM message to topic: {topic_in}", verbose)
        log(f"Message size: {len(payload)} bytes", verbose)

        client.publish(topic_in, payload)
        log("Message sent successfully", verbose)

    except Exception as e:
        print(f"ERROR: Failed to send message: {e}", file=sys.stderr)
        received_event.set()  # Exit immediately
        sys.exit(1)


def run_sender(args):
    """Run in sender mode: send message and verify echo."""
    global mqtt_client, test_passed, test_error_message

    log(f"Starting SENDER mode...", args.verbose)
    log(f"  Broker:      {args.broker}:{args.port}", args.verbose)
    log(f"  Station ID:  {args.station_id}", args.verbose)
    log(f"  Input file:  {args.input_file}", args.verbose)
    log(f"  Input file:  {args.input_file}", args.verbose)
    log(f"  Example dir: {args.example_dir}", args.verbose)
    log(f"  Timeout:     {args.timeout}s", args.verbose)
    log(f"  Topic IN:    {args.topic_in}", args.verbose)
    log(f"  Topic OUT:   {args.topic_out}", args.verbose)

    # Prepare userdata for callbacks
    userdata = {
        "station_id": args.station_id,
        "input_file": args.input_file,
        "example_dir": args.example_dir,
        "topic_in": args.topic_in,
        "topic_out": args.topic_out,
        "verbose": args.verbose,
    }

    # Create MQTT client
    mqtt_client = create_mqtt_client(
        args.broker, args.port, sender_on_connect, sender_on_message
    )
    mqtt_client.user_data_set(userdata)

    # Start background MQTT loop
    mqtt_client.loop_start()

    # Wait a moment for connection to establish
    time.sleep(1)

    # Send the message
    start_time = time.time()
    send_message(mqtt_client, args.input_file, args.topic_in, args.verbose)

    # Wait for echo response
    log(f"Waiting for echo response (timeout: {args.timeout}s)...", args.verbose)
    received = received_event.wait(timeout=args.timeout)
    duration = time.time() - start_time

    # Stop MQTT loop
    mqtt_client.loop_stop()
    mqtt_client.disconnect()

    # Check result
    if not received:
        print(
            f"ERROR: Test timeout after {args.timeout}s - no echo received",
            file=sys.stderr,
        )
        sys.exit(1)

    if test_passed:
        log(f"Test completed successfully in {duration:.2f}s", args.verbose)
        sys.exit(0)
    else:
        print(f"ERROR: Test failed - {test_error_message}", file=sys.stderr)
        sys.exit(1)


# ============================================================================
# RECEIVER MODE FUNCTIONS
# ============================================================================


def receiver_on_connect(client, userdata, flags, rc, *args):
    """Callback when receiver connects to MQTT broker."""
    args_dict = userdata
    topic_out = args_dict["topic_out"]
    verbose = args_dict["verbose"]

    if rc == 0:
        log(f"Connected to broker. Listening on: {topic_out}", verbose)
        client.subscribe(topic_out)
    else:
        print(f"ERROR: Failed to connect to broker, return code {rc}", file=sys.stderr)
        sys.exit(1)


def receiver_on_message(client, userdata, msg):
    """Callback when receiver gets message - echo it back."""
    args_dict = userdata
    topic_in = msg.topic.replace("out", "in")
    filter_station = args_dict["filter_station"]
    verbose = args_dict["verbose"]
    message_type = topic_in.split("/")[-1]

    print("Message received on topic:", msg.topic)

    try:
        # Parse incoming message
        payload = msg.payload.decode("utf-8")
        data = json.loads(payload)
        station_id = data.get("stationID", "unknown")

        # Apply station ID filter if configured
        if filter_station is not None and station_id != filter_station:
            log(
                f"Ignoring message (filter requires station ID {filter_station})",
                verbose,
            )
            return

        # Extract message data and echo it back
        if "fields" in data and message_type in data["fields"]:
            print("Echoing message type:", message_type)
            response_payload = json.dumps(data["fields"][message_type])
        else:
            # data should be equal to structure after data['fields']['header']
            content_key = list(data["fields"].keys())[1]
            print("Echoing message type:", content_key)
            response_payload = json.dumps(data["fields"][content_key])

        log(f"Echoing message back to: {topic_in}", verbose)
        client.publish(topic_in, response_payload)
        log("Echo sent successfully", verbose)

    except Exception as e:
        print(f"ERROR: Failed to process message: {e}", file=sys.stderr)


def run_receiver(args):
    """Run in receiver mode: echo messages back."""
    global mqtt_client

    log(f"Starting RECEIVER mode...", args.verbose)
    log(f"  Broker:         {args.broker}:{args.port}", args.verbose)
    log(f"  Topic OUT:      {args.topic_out} (listen)", args.verbose)
    log(f"  Topic IN:       {args.topic_in} (echo to)", args.verbose)
    if args.filter_station:
        log(f"  Filter station: {args.filter_station}", args.verbose)
    else:
        log(f"  Filter station: None (echo all)", args.verbose)

    # Prepare userdata for callbacks
    userdata = {
        "topic_in": args.topic_in,
        "topic_out": args.topic_out,
        "filter_station": args.filter_station,
        "verbose": args.verbose,
    }

    # Create MQTT client
    mqtt_client = create_mqtt_client(
        args.broker, args.port, receiver_on_connect, receiver_on_message
    )
    mqtt_client.user_data_set(userdata)

    # Run forever (until interrupted)
    log("Receiver service started. Press Ctrl+C to stop.", args.verbose)
    mqtt_client.loop_forever()


# ============================================================================
# BATCH MODE FUNCTIONS
# ============================================================================
def discover_message_files(example_dir: str, exclude: List[str] = None) -> List[str]:
    """Find all JSON files in examples directory, excluding specified types."""
    if not os.path.exists(example_dir):
        print(f"ERROR: Example directory not found: {example_dir}", file=sys.stderr)
        sys.exit(1)

    # Find all JSON files
    json_files = []
    for filename in os.listdir(example_dir):
        if filename.endswith(".json"):
            file_path = os.path.join(example_dir, filename)
            json_files.append(file_path)

    # Sort for consistent order
    json_files.sort()

    # Filter out excluded types
    if exclude:
        filtered_files = []
        for file_path in json_files:
            message_type = get_message_type(file_path)
            if message_type not in exclude:
                filtered_files.append(file_path)
        json_files = filtered_files

    return json_files


def get_message_type(file_path: str) -> str:
    """Extract message type from filename."""
    filename = os.path.basename(file_path)  # "in_cam.json"
    # Remove "in_" prefix and ".json" suffix
    message_type = filename.replace("in_", "").replace(".json", "")
    return message_type


def inject_station_id(message_data: Dict[str, Any], station_id: int) -> Dict[str, Any]:
    """Inject station ID into message data, overriding any existing station ID."""
    # Create a copy to avoid modifying original
    modified_data = message_data.copy()

    # Handle different station ID locations
    # 1. Direct stationID
    if "stationID" in modified_data:
        modified_data["stationID"] = station_id

    # 2. Nested in basicContainer
    if "basicContainer" in modified_data:
        modified_data["basicContainer"]["stationID"] = station_id

    # 3. Nested in management.actionId.originatingStationId
    if "management" in modified_data and "actionId" in modified_data["management"]:
        modified_data["management"]["actionId"]["originatingStationId"] = station_id

    # 4. Nested in managementContainer (for CPM)
    if "managementContainer" in modified_data:
        # CPM messages might not have station ID, but we can add it if needed
        pass

    return modified_data


def test_single_message(file_path: str, args, mqtt_client) -> Dict[str, Any]:
    """Test one message file and return result dictionary."""
    global test_passed, test_error_message, received_event

    # Reset global state for this test
    test_passed = False
    test_error_message = ""
    received_event.clear()

    result = {
        "file": os.path.basename(file_path),
        "message_type": get_message_type(file_path),
        "status": "fail",
        "error": "",
        "duration": 0.0,
        "original_hash": 0,
        "received_hash": 0,
    }

    try:
        # Load and modify message data
        original_data = load_json_file(file_path)
        modified_data = inject_station_id(original_data, args.station_id)

        log(f"Testing: {result['file']} (type: {result['message_type']})", args.verbose)

        # Send the message
        start_time = time.time()
        payload = json.dumps(modified_data)

        log(f"Sending {result['message_type']} message...", args.verbose)
        mqtt_client.publish(args.topic_in, payload)

        # Wait for echo response
        received = received_event.wait(timeout=args.timeout)
        duration = time.time() - start_time
        result["duration"] = duration

        if not received:
            result["error"] = f"Timeout after {args.timeout}s - no echo received"
            log(f"✗ FAIL: {result['error']}", args.verbose)
        elif test_passed:
            result["status"] = "pass"
            result["original_hash"] = hash(
                json.dumps(dict(sorted(original_data.items())), sort_keys=True)
            )
            result["received_hash"] = hash(
                json.dumps(dict(sorted(modified_data.items())), sort_keys=True)
            )
            log(
                f"✓ PASS ({duration:.2f}s) - Station ID: {args.station_id}",
                args.verbose,
            )
        else:
            result["error"] = test_error_message
            log(f"✗ FAIL: {result['error']}", args.verbose)

    except Exception as e:
        result["error"] = str(e)
        result["duration"] = time.time() - start_time
        log(f"✗ FAIL: {result['error']}", args.verbose)

    return result


def run_batch(args):
    """Run batch tests for all message files."""
    global mqtt_client, test_passed, test_error_message, received_event

    log(f"Starting BATCH mode...", args.verbose)
    log(f"  Broker:      {args.broker}:{args.port}", args.verbose)
    log(f"  Station ID:  {args.station_id}", args.verbose)
    log(f"  Example dir: {args.example_dir}", args.verbose)
    log(f"  Timeout:     {args.timeout}s", args.verbose)
    log(f"  Wait between: {args.wait_between_tests}s", args.verbose)

    # Parse exclude list
    exclude_list = []
    if args.exclude:
        exclude_list = [x.strip() for x in args.exclude.split(",")]
        log(f"  Excluding:   {', '.join(exclude_list)}", args.verbose)

    # Discover message files
    message_files = discover_message_files(args.example_dir, exclude_list)

    if not message_files:
        print("ERROR: No message files found to test", file=sys.stderr)
        sys.exit(1)

    log(f"Found {len(message_files)} message files to test", args.verbose)

    # Create MQTT client (reuse across all tests)
    userdata = {
        "station_id": args.station_id,
        "input_file": None,  # Will be set per test
        "topic_in": args.topic_in,
        "topic_out": args.topic_out,
        "verbose": args.verbose,
    }

    mqtt_client = create_mqtt_client(
        args.broker, args.port, sender_on_connect, sender_on_message
    )
    mqtt_client.user_data_set(userdata)
    mqtt_client.loop_start()

    # Wait for connection to establish
    time.sleep(1)

    # Run tests for each message file
    results = []
    for i, file_path in enumerate(message_files):
        # Update userdata for this test
        userdata["input_file"] = file_path
        mqtt_client.user_data_set(userdata)

        # Change the topic where to sending the message
        args.topic_in = "vanetza/in/" + get_message_type(file_path)

        # Run single test
        result = test_single_message(file_path, args, mqtt_client)
        results.append(result)

        # Wait between tests (except after last test)
        if i < len(message_files) - 1:
            time.sleep(args.wait_between_tests)

    # Cleanup MQTT client
    mqtt_client.loop_stop()
    mqtt_client.disconnect()

    # Print summary
    print("\nBatch Test Summary:")
    print("==================")

    passed_count = sum(1 for r in results if r["status"] == "pass")
    failed_count = len(results) - passed_count

    print(f"Total tests: {len(results)}")
    print(f"Passed: {passed_count}")
    print(f"Failed: {failed_count}")

    if failed_count > 0:
        print("\nFailed tests:")
        for result in results:
            if result["status"] == "fail":
                print(f"  - {result['file']}: {result['error']}")

    print(f"\nOverall status: {'PASSED' if failed_count == 0 else 'FAILED'}")

    # Exit with appropriate code
    sys.exit(0 if failed_count == 0 else 1)


# ============================================================================
# CLI ARGUMENT PARSING
# ============================================================================


def parse_arguments():
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(
        description="Vanetza MQTT CAM Message Integrity Tester",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
        Examples:
        # Receiver (echo all messages)
        %(prog)s receiver --broker 192.168.1.100

        # Receiver (only echo station ID 100)
        %(prog)s receiver --broker 192.168.1.100 --filter-station 100

        # Sender (send as station 111, verify echo)
        %(prog)s sender --broker 192.168.1.100 --station-id 111

        # Sender with custom input file and timeout
        %(prog)s sender --broker 192.168.1.100 --station-id 111 \\
                --input custom_cam.json --timeout 15

                # Batch test all message types
                %(prog)s batch --broker 192.168.1.100 --station-id 111

                # Batch test with exclusions
                %(prog)s batch --broker 192.168.1.100 --station-id 111 \\
                        --exclude cam,cpm --wait-between-tests 3
                        """,
    )

    # Required: mode selection
    parser.add_argument("mode", choices=["sender", "receiver"], help="Operation mode")

    # MQTT connection settings
    parser.add_argument(
        "--broker",
        default=DEFAULT_BROKER,
        help=f"MQTT broker address (default: {DEFAULT_BROKER})",
    )
    parser.add_argument(
        "--port",
        type=int,
        default=DEFAULT_PORT,
        help=f"MQTT broker port (default: {DEFAULT_PORT})",
    )

    # Topic configuration
    parser.add_argument(
        "--topic-in",
        default=DEFAULT_TOPIC_IN,
        help=f"MQTT topic for incoming messages (default: {DEFAULT_TOPIC_IN})",
    )
    parser.add_argument(
        "--topic-out",
        default=DEFAULT_TOPIC_OUT,
        help=f"MQTT topic for outgoing messages (default: {DEFAULT_TOPIC_OUT})",
    )

    # Station ID configuration
    parser.add_argument(
        "--station-id",
        type=int,
        default=DEFAULT_STATION_ID,
        help=f"Station ID for sender mode (default: {DEFAULT_STATION_ID})",
    )
    parser.add_argument(
        "--filter-station",
        type=int,
        default=None,
        help="Station ID to filter in receiver mode (default: accept all)",
    )

    # Sender-specific options
    parser.add_argument(
        "--input-file",
        default=DEFAULT_INPUT_FILE,
        help=f"Input CAM JSON file for sender mode (default: {DEFAULT_INPUT_FILE})",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT,
        help=f"Timeout in seconds for sender mode (default: {DEFAULT_TIMEOUT})",
    )

    parser.add_argument(
        "--example-dir",
        default=DEFAULT_EXAMPLE_DIR,
        help=f"Directory for example message files (default: {DEFAULT_EXAMPLE_DIR})",
    )

    # General options
    parser.add_argument(
        "--verbose",
        action="store_true",
        default=True,
        help="Enable verbose output (default: enabled)",
    )
    parser.add_argument("--quiet", action="store_true", help="Disable verbose output")

    # Batch-specific arguments
    parser.add_argument(
        "--exclude",
        default=None,
        help="Comma-separated list of message types to exclude (e.g., 'cam,cpm')",
    )

    parser.add_argument(
        "--wait-between-tests",
        type=float,
        default=2.0,
        help="Seconds to wait between tests (default: 2.0)",
    )

    args = parser.parse_args()

    # Handle quiet flag
    if args.quiet:
        args.verbose = False

    return args


# ============================================================================
# MAIN ENTRY POINT
# ============================================================================


def main():
    """Main entry point."""
    args = parse_arguments()

    # Route to appropriate mode
    if args.mode == "sender":
        run_batch(args)
    elif args.mode == "receiver":
        run_receiver(args)
    else:
        print(f"ERROR: Unknown mode: {args.mode}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
