import json
import paho.mqtt.client as mqtt
import threading
from time import sleep


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("vanetza/out/cam")
    # client.subscribe("vanetza/out/denm")
    # ...


# É chamada automaticamente sempre que recebe uma mensagem nos tópicos subscritos em cima
def on_message(client, userdata, msg):
    message = json.loads(msg.payload.decode('utf-8'))
    
    print('Topic: ' + msg.topic)
    print('Message' + message)

    # lat = message["latitude"]
    # ...


def generate():
    f = open('examples/in_cam.json')
    m = json.load(f)
    m["latitude"] = 0
    m["longitude"] = 0
    m = json.dumps(m)
    client.publish("vanetza/in/cam",m)
    f.close()
    sleep(1)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.98.10", 1883, 60)

threading.Thread(target=client.loop_forever).start()

while(True):
    generate()
