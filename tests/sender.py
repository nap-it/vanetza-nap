import json
import threading
from threading import Event

import paho.mqtt.client as mqtt

# This event will keep the script alive until the message is received
received_event = Event()


def on_connect(client, userdata, flags, rc, *args):
    client.subscribe("vanetza/out/cam")


def on_message(client, userdata, msg):
    message = msg.payload.decode("utf-8")

    obj = json.loads(message)
    station_id = obj.get("stationID", "unknown")

    if station_id == 111:
        checker(obj["fields"]["cam"])
        # Signal that we have received the message
        received_event.set()


def generate(client):
    try:
        with open("in_cam.json", "r") as f:
            m = json.load(f)

        payload = json.dumps(m)

        client.publish("vanetza/in/cam", payload)
    except FileNotFoundError:
        print("Error: in_cam.json not found.")
        received_event.set()  # Exit if file is missing


# Check if the received data is the same message than sent
def checker(data):
    with open("in_cam.json", "r") as f:
        original_m = json.load(f)
    sorted_data = dict(sorted(data.items()))
    sorted_original = dict(sorted(original_m.items()))
    print("Original data:", sorted_original)
    print("Received data:", sorted_data)

    # Hash the data for comparison
    received_hash = hash(json.dumps(sorted_data, sort_keys=True))
    original_hash = hash(json.dumps(sorted_original, sort_keys=True))
    print(f"Received hash: {received_hash}")
    print(f"Original hash: {original_hash}")
    assert received_hash == original_hash, "Data mismatch!"
    print("Data matches!")


# Setup Client
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)

# Start the background networking thread
client.loop_start()

# 1. Send the single message
generate(client)

# 2. Wait here until received_event.set() is called in on_message
# You can add a timeout (e.g., .wait(timeout=10)) to avoid hanging forever
received_event.wait(timeout=10)

# 3. Stop the loop and disconnect
client.loop_stop()
client.disconnect()
