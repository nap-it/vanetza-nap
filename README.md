# NAP-Vanetza
### Introduction and Containerized Usage Guide

[Vanetza](https://github.com/riebl/vanetza) is an open-source C++ implementation of the ETSI C-ITS protocol suite designed to operate on ITS-G5 channels in a Vehicular Ad Hoc Network (VANET) using IEEE 802.11p (WAVE).

NAP-Vanetza extends the base Vanetza project to integrate MQTT and JSON capabilities, as well as additional types of ETSI C-ITS messages.

The following message types are supported:
* Cooperative Awareness Messages (CAM)
* Decentralized Environmental Notification Message (DENM)
* Collective Perception Message (CPM)
* Vulnerable Road User Awareness Message (VAM)
* Signal Phase And Timing Extended Message (SPATEM)
* MAP (topology) Extended Message (MAPEM)
* GeoNetworking Beacons



## Building (Docker)

1. Install docker and docker-compose
```
sudo apt update
sudo apt install docker docker-compose
```

2. Clone NAP-Vanetza's repository and navigate to the project's root directory

3. Build the docker image

```
docker build -t vanetza:test .
```
2. Create the Docker network that the Vanetza containers will use to exchange ETSI C-ITS messages 

```
docker network create vanetzalan0 --subnet 192.168.98.0/24
```

## Usage (Docker)

To start the Vanetza containers run:
```
docker-compose up
```


By default, docker-compose creates a container 


To run in the background:

```
docker-compose up -d
```
To stop:
```
docker-compose down
```
To consult the logs of a particular container:
```
docker-compose logs obu
```

### Wireshark

Wireshark can be used to sniff and analyse the ETSI C-ITS messages exchanged between the different containers on the virtual network interface created by Docker

To find out the correct interface name run: 
```
ifconfig
```
And find the interface whose IP address is **192.168.98.1**.
Its name will usually start with 'br-'

To filter out miscellaneous packets and protocols and show only ETSI C-ITS messages, use the following filter:
```
eth.type == 0x8947
```

Note: CPMs are only supported/interpreted by Wireshark since version 3.6, which is not yet available to install on Linux OSs.

To circumvent this, compile Wireshark 3.7 from source by running:
```
wget -q -O - https://gist.githubusercontent.com/RodrigoRosmaninho/be85885b1cd415a2b1621d2ac9875cb8/raw/2bea6639e1eddbaee1ca316668f48792893888b3/build.sh | bash
```
The script will print out further instructions on how to run the compiled binary.

### MQTT



For quick tests on the command line, install the mosquitto-clients package
```
sudo apt install mosquitto-clients
```

```
mosquitto_sub -h 192.168.98.10 -t "#" -v
```

```
mosquitto_pub -h 192.168.98.10 -t "vanetza/in/cam_full" -m ""
```

MQTT can also be easily integrated into your application's code by using third-party libraries such as [paho-mqtt](https://pypi.org/project/paho-mqtt/), available for multiple programming languages.


### Constructing the JSON messages according to ETSI specifications

## Configuration

NAP-Vanetza has a set of configurable attributes to allow for fine-tuning of its mode of operation. 

These attributes are generally set in the **config.ini** file located in tools/socktap/config.ini
However

| .ini file key | Environment var key | Description | Default | Notes |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| general.interface | VANETZA_INTERFACE | Network interface where the ETSI messages are exchanged | wlan0 | Docker: eth0 |
| general.mqtt_broker | VANETZA_MQTT_BROKER | MQTT Broker's IP address or DNS name | 127.0.0.1 | |
| general.mqtt_port | VANETZA_MQTT_PORT | MQTT Broker's Port | 1883 | |
| general.prometheus_port | VANETZA_PROMETHEUS_PORT | Port on which Vanetza exposes metrics | 9100 | |
| general.rssi_port | VANETZA_RSSI_PORT | Port on which Vanetza communicates with the RSSI_Discovery service | 3000 | Not used on Docker; 0 to disable |
| general.ignore_own_messages | VANETZA_IGNORE_OWN_MESSAGES | Don't capture or decode messages originating from the station itself | true | |
| general.ignore_rsu_messages | VANETZA_IGNORE_RSU_MESSAGES | Ignore messages from RSUs - Usually set on RSUs | false | |
| general.to_dds_port | VANETZA_TO_DDS_PORT | Port on which Vanetza sends JSON to be published in DDS topics | 6060 | Advanced usage to minimize communication latency |
| general.from_dds_port | VANETZA_FROM_DDS_PORT | Port on which Vanetza receives JSON from DDS topics | 6061 | Advanced usage to minimize communication latency |
| station.id | VANETZA_STATION_ID | ETSI Station ID field | 99 | |
| station.type | VANETZA_STATION_TYPE | ETSI Station Type field | 15 | |
| station.mac_address | VANETZA_MAC_ADDRESS | Virtual Mac Address used as the source on L2 ethernet headers | interface's address | |
| station.beacons_enabled | VANETZA_BEACONS_ENABLED | Send GeoNetworking Beacons every 3 seconds | true | |
| station.use_hardcoded_gps | VANETZA_USE_HARDCODED_GPS | Use hardcoded gps coordinates instead of information provided by a GPS module | true | |
| station.latitude | VANETZA_LATITUDE | Hardcoded GPS latitude - Usually set on static RSUs | 40 | |
| station.longitude | VANETZA_LONGITUDE | Hardcoded GPS longitude - Usually set on static RSUs | -8 | |
| station.length | VANETZA_LENGTH | Vehicle lenght in meters | 10 | |
| station.width | VANETZA_WIDTH | Vehicle width in meters | 3 | |
| cam.full_topic_in | VANETZA_CAM_FULL_TOPIC_IN | MQTT/DDS topic from which Vanetza receives JSON CAMs in the full ETSI spec format | vanetza/in/cam_full | |
| cam.full_topic_out | VANETZA_CAM_FULL_TOPIC_OUT | MQTT/DDS topic to which Vanetza sends JSON CAMs in the full ETSI spec format | vanetza/out/cam_full | |
| vam.full_topic_in | VANETZA_VAM_FULL_TOPIC_IN | MQTT/DDS topic from which Vanetza receives JSON VAMs in the full ETSI spec format | vanetza/in/vam_full | |
| vam.full_topic_out | VANETZA_VAM_FULL_TOPIC_OUT | MQTT/DDS topic to which Vanetza sends JSON VAMs in the full ETSI spec format | vanetza/out/vam_full | |
| --- | START_EMBEDDED_MOSQUITTO | Start an MQTT server inside the container to simulate a full OBU or RSU with a local MQTT broker | false | |

 
| .ini file key | Environment var key | Description | Default | Notes |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| cam.enabled | VANETZA_CAM_ENABLED | Enable the CAM application | true | |
| cam.mqtt_enabled | VANETZA_CAM_MQTT_ENABLED | Enable publishing and subscribing to MQTT topics | true | |
| cam.dds_enabled | VANETZA_CAM_DDS_ENABLED | Enable publishing and subscribing to DDS topics | true  | |
| cam.periodicity | VANETZA_CAM_PERIODICITY | Periodicity with which to send the default CAM, in milliseconds | 1000 | Only available on CAMs, 0 to disable |
| cam.topic_in | VANETZA_CAM_TOPIC_IN | MQTT/DDS topic from which Vanetza receives JSON CAMs to encode and send | vanetza/in/cam |  |
| cam.topic_out | VANETZA_CAM_TOPIC_OUT | MQTT/DDS topic to which Vanetza sends JSON CAMs that were received and decoded | vanetza/out/cam | |
| cam.udp_out_addr | VANETZA_CAM_UDP_OUT_ADDR | Address of the UDP server to which Vanetza sends decoded JSON CAMs, in order to minimize communication latency - Used in NAP's Connection Manager v1 | 127.0.0.1 | |
| cam.udp_out_port | VANETZA_CAM_UDP_OUT_PORT | Port of the UDP server to which Vanetza sends decoded JSON CAMs, in order to minimize communication latency - Used in NAP's Connection Manager v1 | 5051 | 0 to disable |


## Project's State and Missing Fields

The NAP-Vanetza project is still under active development and is frequently updated to introduce new features and correct issues.
Please report any problems you encounter.

The following field types are not yet supported by Vanetza. As such, they will be absent from JSON messages generated by Vanetza and ignored in messages received by Vanetza.
These fields are generally optional and relatively unimportant. They will be added later on a case-by-case basis, should they become necessary.

* PhoneNumber
* OpeningDaysHours
* MessageFrame
* DescriptiveName
* RegionalExtension
* Iso3833VehicleType
* REG-EXT-ID-AND-TYPE.&id
* REG-EXT-ID-AND-TYPE.&Type
* MESSAGE-ID-AND-TYPE.&id 
* MESSAGE-ID-AND-TYPE.&Type
* PreemptPriorityList 
* WMInumber 
* VDS
* TemporaryID


## Authors

Development of Vanetza is part of ongoing research work at [Technische Hochschule Ingolstadt](https://www.thi.de/forschung/carissma/labore/car2x-labor/).
Maintenance is coordinated by Raphael Riebl.

Development of NAP-Vanetza is part of ongoing research work at [Instituto de Telecomunicações's Network Protocols and Architectures Group](https://www.it.pt/Groups/Index/36).

Questions and Bug Reports: @rrosmaninho / r.rosmaninho@av.it.pt

## License

Vanetza is licensed under LGPLv3, see [license file](LICENSE.md) for details.
