import json

import paho.mqtt.client as mqtt

"""
Receives a message on topic.
Echoes the message back to the sender.
"""

# Topic we listen to (published by Machine 1)
LISTEN_TOPIC = "vanetza/out/cam"
# Topic we send back to (subscribed by Machine 1)
RESPONSE_TOPIC = "vanetza/in/cam"


def on_connect(client, userdata, flags, rc, *args):
    if rc == 0:
        print(f"Connected to Broker! Listening on: {LISTEN_TOPIC}")
        client.subscribe(LISTEN_TOPIC)
    else:
        print(f"Failed to connect, return code {rc}")


def on_message(client, userdata, msg):
    try:
        # 1. Receive and parse the incoming message
        payload = msg.payload.decode("utf-8")
        data = json.loads(payload)
        station_id = data.get("stationID", "unknown")

        if station_id == 100:
            response_payload = json.dumps(data["fields"]["cam"])

            # 3. Publish back to the output topic
            print(f"Sending response to: {RESPONSE_TOPIC}")
            client.publish(RESPONSE_TOPIC, response_payload)

    except Exception as e:
        print(f"Error processing message: {e}")


# Setup Client
responder = mqtt.Client()
responder.on_connect = on_connect
responder.on_message = on_message

# Connect to the same broker IP
responder.connect("127.0.0.1", 1883, 60)

# This script stays running to act as a service/server
print("Responder service started. Press Ctrl+C to stop.")
responder.loop_forever()
