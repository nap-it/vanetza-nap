# Vanetza-NAP

Vanetza-NAP is an extended version of [Vanetza](https://github.com/riebl/vanetza) is an open-source C++ implementation of the ETSI C-ITS protocol suite designed to operate on ITS-G5 channels in a Vehicular Ad Hoc Network (VANET) using IEEE 802.11p (WAVE).

If you find this code useful in your research, please consider citing :

    @INPROCEEDINGS{Rosmaninho2024,
        author={Rosmaninho, Rodrigo and Figueiredo, Andreia and Almeida, Pedro and Rito, Pedro and Raposo, Duarte and Sargento, Susana},
        booktitle={2024 IEEE Vehicular Networking Conference (VNC)}, 
        title={Vanetza-NAP: Vehicular Communications and Services in MicroServices Architectures}, 
        year={2024},
        volume={},
        number={},
        pages={297-304},
        keywords={Runtime;Protocols;Microservice architectures;Computer architecture;Data processing;Delays;Vehicle-to-everything;ITS-G5;V2X;Vehicular Edge Computing;C-ITS;Data Distribution Service;Multi-access Edge Computing},
        doi={10.1109/VNC61989.2024.10575959}
    }

## Table of Contents

- [Vanetza-NAP](#vanetza-nap)
  - [Introduction and Containerized Usage Guide](#introduction-and-containerized-usage-guide)
  - [Setting up](#setting-up)
  - [Usage](#usage)
    - [Updating the Vanetza image](#updating-the-vanetza-image)
    - [Building the Vanetza image locally](#building-the-vanetza-image-locally)
    - [Running in the background](#running-in-the-background)
  - [Wireshark](#wireshark)
  - [MQTT](#mqtt)
  - [Constructing the JSON messages according to ETSI specifications](#constructing-the-json-messages-according-to-etsi-specifications)
    - [Error Messages](#error-messages)
  - [Configuration](#configuration)
  - [Variable transformations](#variable-transformations)
  - [Advanced Usage](#advanced-usage)
    - [Measuring processing performance & MQTT/DDS/Zenoh latency](#measuring-processing-performance--mqttddszenoh-latency)
    - [Simulating situations where stations become out of range from each other](#simulating-situations-where-stations-become-out-of-range-from-each-other)
    - [DDS](#dds)
    - [Zenoh](#zenoh)
    - [Prometheus Metrics](#prometheus-metrics)
  - [Project's State and Missing Fields](#projects-state-and-missing-fields)
  - [Authors](#authors)
  - [License](#license)


## Introduction and Containerized Usage Guide

Vanetza-NAP extends the base Vanetza project to integrate MQTT/DDS/Zenoh and JSON capabilities, as well as additional types of ETSI C-ITS messages.

The following message types are supported:
* Cooperative Awareness Messages (CAM)
* Decentralized Environmental Notification Message (DENM)
* Collective Perception Message (CPM)
* Vulnerable Road User Awareness Message (VAM)
* Signal Phase And Timing Extended Message (SPATEM)
* MAP (topology) Extended Message (MAPEM)
* Maneuver Coordination Message (MCM)
* Signal Status Extended Message (SSEM)
* Signal Request Extended Message (SREM)
* RTCM Extended Message (RTCMEM)
* Infrastructure to Vehicle Information Message (IVIM)
* Electric Vehicle Charging Spot Notification (EVCSN)
* Electric Vehicle Recharging Spot Reservation (EVRSR)
* Interference Management Zone Message (IMZM)
* Tyre Information System and Tyre Pressure Gauge (TISTPG)
* GeoNetworking Beacons

Put simply, NAP-Vanetza's purpose is to manage the encoding, decoding, sending, and receiving of ETSI C-ITS messages, thus abstracting those layers from VANET application developers.

Applications that need to send ETSI C-ITS messages interact with the service by building a JSON representation of the given message and publishing it in a specific MQTT topic, which Vanetza subscribes to.
Likewise, applications that need to receive incoming messages do so by subscribing to the respective MQTT/DDS/Zenoh topics, that Vanetza publishes JSON to.

Inside the folder **examples** you can find example JSON representations for some of the supported message types.

The following diagram examplifies a common usage pattern:

![Generic Diagram](https://i.ibb.co/PxRWMz5/generic-diagram.png)

Note: In the case of CAMs, NAP-Vanetza also has a pre-defined "hard-coded" CAM message which is periodically sent at a configurable frequency and with updated GPS values, without the need for an external application to publish JSON CAMs (which is also allowed). This behaviour can be disabled.

## Setting up

1. Install docker and docker-compose
```
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo bash -c 'echo "deb [arch=$(dpkg --print-architecture)] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" > /etc/apt/sources.list.d/docker-ce.list'
sudo apt update
sudo apt install docker-ce docker-compose
```

2. Clone NAP-Vanetza's repository and navigate to the project's root directory


3. Create the Docker network that the Vanetza containers will use to exchange ETSI C-ITS messages 

```
docker network create vanetzalan0 --subnet 192.168.98.0/24
```

## Usage 

To start the Vanetza containers run:
```
docker-compose up
```
To stop use CTRL-C.


By default, docker-compose creates two containers, emulating an RSU and OBU pair. This can, however, be freely extended just by duplicating the existing container specifications in **docker-compose.yml** (while making sure to set a unique IP address for each one).

Refer to the configuration section for more details on how to configure each container.

Each container includes an embeded MQTT broker in order to fully simulate the common environment described in the first section. This feature can be disabled if required.

![Docker Diagram](https://i.ibb.co/XxCzVZK/docker-diagram.png)

### Updating the Vanetza image

You may update Vanetza to the lastest version by running the following command:

```
docker pull ghcr.io/nap-it/vanetza-nap:latest
```

Try to do this regularly, since NAP-Vanetza is in active development and new features and bug fixes are frequently added.

### Building the Vanetza image locally

If you want to make changes to the Vanetza code or use a specific version of NAP-Vanetza, you can build the image locally by running the following command in the project's root directory:

```
docker build -t vanetza-nap:latest .
```

This will build the image using the Dockerfile located in the root directory and tag it as "vanetza-nap:latest". You can then use this image in your `docker-compose.yml` file by replacing `ghcr.io/nap-it/vanetza-nap:latest` with `vanetza-nap:latest`.


#### Running in the background

To run the containers in the background:

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

If docker-compose throws an error regarding version incompatibility on Ubuntu 18.04 hosts, run:
```
sudo apt install docker-compose-plugin
```
And run the commands above, replacing *docker-compose* with *docker compose*

## Wireshark

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


## MQTT



For quick tests on the command line, install the mosquitto-clients package
```
sudo apt install mosquitto-clients
```
To subscribe to MQTT topics and see every new message on the command line use:
```
# All topics
mosquitto_sub -h 192.168.98.10 -t "#" -v

# Subset of topics
mosquitto_sub -h 192.168.98.10 -t "vanetza/out/#" -v

# Specific topic
mosquitto_sub -h 192.168.98.10 -t "vanetza/out/cam" -v
```

To publish an MQTT message to a specific topic use:
```
mosquitto_pub -h 192.168.98.10 -t "vanetza/in/cam" -m '{"camParameters":{"basicContainer":{"stationType":5,"referencePosition":{"latitude":40.62834930419922,"longitude":-8.654390335083008,"positionConfidenceEllipse":{"semiMajorAxisLength":4095,"semiMinorAxisLength":4095,"semiMajorAxisOrientation":3601},"altitude":{"altitudeValue":800001,"altitudeConfidence":15}}},"highFrequencyContainer":{"basicVehicleContainerHighFrequency":{"heading":{"headingValue":153.0,"headingConfidence":127},"speed":{"speedValue":8.7,"speedConfidence":127},"driveDirection":2,"vehicleLength":{"vehicleLengthValue":1023,"vehicleLengthConfidenceIndication":4},"vehicleWidth":62,"longitudinalAcceleration":{"value":-0.4,"confidence":102},"curvature":{"curvatureValue":1023,"curvatureConfidence":7},"curvatureCalculationMode":2,"yawRate":{"yawRateValue":11.0,"yawRateConfidence":8},"accelerationControl":{"brakePedalEngaged":false,"gasPedalEngaged":false,"emergencyBrakeEngaged":false,"collisionWarningEngaged":false,"accEngaged":false,"cruiseControlEngaged":false,"speedLimiterEngaged":false},"steeringWheelAngle":{"steeringWheelAngleValue":512,"steeringWheelAngleConfidence":127}}}},"generationDeltaTime":13190}'
```

MQTT can also be easily integrated into your application's code by using third-party libraries such as [paho-mqtt](https://pypi.org/project/paho-mqtt/), available for multiple programming languages.


## Constructing the JSON messages according to ETSI specifications

In order to make the encoding and decoding process possible, the JSON messages received and sent by Vanetza through MQTT are required to follow the strict format specified in each message type's respective ETSI specification document.

You may consult those documents in the following links:
* [Common to some messages - ETSI TS 102 894-2 V1.2.1](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2/-/tree/v1.2.1)
* [Common to some messages - ETSI TS 102 894-2 V2.1.1](https://forge.etsi.org/rep/ITS/asn1/cdd_ts102894_2/-/tree/v2.1.1)
* [CAM - ETSI TS 103 900 V2.2.1](https://forge.etsi.org/rep/ITS/asn1/cam_ts103900/-/tree/v2.2.1)
* [DENM - ETSI TS 103 831 V2.2.1](https://forge.etsi.org/rep/ITS/asn1/denm_ts103831/-/tree/v2.2.1)
* [CPM - ETSI TR 103 562 V2.1.1](https://forge.etsi.org/rep/ITS/asn1/cpm_ts103324/-/tree/v2.1.1)
* [VAM - ETSI TS 103 300-3 V2.1.1](https://forge.etsi.org/rep/ITS/asn1/vam-ts103300_3/-/tree/v2.1.1)
* [SPATEM - ETSI TS 103 301 V1.1.1](https://forge.etsi.org/rep/ITS/asn1/is_ts103301/-/tree/v1.2.1?ref_type=tags)
* [MAPEM - ETSI TS 103 301 V1.1.1](https://forge.etsi.org/rep/ITS/asn1/is_ts103301/-/tree/v1.2.1?ref_type=tags)
  

NAP-Vanetza includes some examples of valid JSON messages in the examples folder.

Note that the ITS PDU Header must not be included in messages published to Vanetza, as it's automatically filled at encode time. It is, however, present in messages published by Vanetza, so as to give developers access to the stationId field. It is also possible to include the stationId attribute in each of the messages' examples in the high-level fields, which Vanetza will prioritize over the ITS PDU Header's stationId field.

#### Error Messages

If your application publishes an invalid JSON ETSI C-ITS message, the following errors will appear in the respective Vanetza container's logs:
* JSON is malformed and can't be parsed. Verify that the message follows JSON's schema rules.
```
-- Vanetza JSON Decoding Error --
Check that the message format follows JSON spec
<Exception Info>
```
* JSON is valid but can't be parsed as the specified ETSI C-ITS message. Verify that all required fields are present and that the messages follow the respective ETSI format correctly. 
```
-- Vanetza ETSI Decoding Error --
Check that the message format follows ETSI spec
<Exception Info>
```
* One or more values does not fit the type or constraints specified in ETSI documents listed above.
```
-- Vanetza UPER Encoding Error --
Check that the message format follows ETSI spec
<Exception Info>
```
* An unexpected error occurred. Please report it.
```
-- Unexpected Error --
Vanetza couldn't decode the JSON message. No other info available

or

-- Unexpected Error --
Vanetza couldn't send the requested message but did not throw a runtime error on UPER encode.
No other info available
```

## Configuration

NAP-Vanetza has a set of configurable attributes with the goal of allowing for fine-tuning its operation. 

These attributes are generally set in the **config.ini** file located in **tools/socktap/config.ini**

However, this becomes impractical for docker-compose deployments which include several Vanetza containers with heterogeneous configuration needs.
These situations would require a separate config file for each container mounted as a volume. 

To solve this, NAP-Vanetza also accepts configuration via environment variables that can be set in the environment section of **docker-compose.yml**. 
Any values set via environment variables have priority over the ones found in config.ini, thus making it possible to use config.ini for common configurations and environment variables for values that are unique to each container (i.e: Station ID, MAC Address, etc)

Note: If you decide to change the default values present in config.ini you must map the changed file inside the containers using volumes in each container's section in docker-compose.yml
```
volumes:
    - tools/socktap/config.ini:/config.ini

```

Environment variable changes, however, only require a restart of the running containers.
```
docker-compose down
docker-compose up
```

The following table summarizes the available configuration options:


| .ini file key | Environment var key | Description | Default | Notes |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| general.interface | VANETZA_INTERFACE | Network interface where the ETSI messages are exchanged | wlan0 | Docker: br0/eth0 |
| general.local_mqtt_broker | VANETZA_LOCAL_MQTT_BROKER | Local MQTT Broker's IP address or DNS name | 127.0.0.1 | |
| general.local_mqtt_port | VANETZA_LOCAL_MQTT_PORT | Local MQTT Broker's Port | 1883 | |
| general.remote_mqtt_broker | VANETZA_REMOTE_MQTT_BROKER | Remote MQTT Broker's IP address or DNS name | "" | Empty to disable |
| general.remote_mqtt_port | VANETZA_REMOTE_MQTT_PORT | Remote MQTT Broker's Port | 0 | 0 to disable |
| general.remote_mqtt_username | VANETZA_REMOTE_MQTT_USERNAME | Remote MQTT Broker's Auth Username | "" | Empty to disable |
| general.remote_mqtt_password | VANETZA_REMOTE_MQTT_PASSWORD | Remote MQTT Broker's Auth Password | "" | Empty to disable |
| general.gpsd_host | VANETZA_GPSD_HOST | GPSD position provider host | 127.0.0.1 | |
| general.gpsd_port | VANETZA_GPSD_PORT | GPSD position provider port | 2947 | |
| general.prometheus_port | VANETZA_PROMETHEUS_PORT | Port on which Vanetza exposes metrics | 9100 | 0 to disable |
| general.rssi_enabled | VANETZA_RSSI_ENABLED | Enable discovering the RSSI (signal strength) value associated with each inbound ITS-G5 message by interfacing with the kernel | true |  |
| general.ignore_own_messages | VANETZA_IGNORE_OWN_MESSAGES | Don't capture or decode messages originating from the station itself | true | |
| general.ignore_rsu_messages | VANETZA_IGNORE_RSU_MESSAGES | Ignore messages from RSUs - Usually set on RSUs | false | |
| general.enable_json_prints | VANETZA_ENABLE_JSON_PRINTS | Print a JSON representation of incoming messages on the terminal/logs | true | |
| general.dds_domain_id | VANETZA_DDS_DOMAIN_ID | DDS Domain ID to use when publishing and subscribing to DDS topics | 0 | Advanced usage only |
| general.dds_participant_name | VANETZA_DDS_PARTICIPANT_NAME | DDS Participant Name to use when publishing and subscribing to DDS topics | vanetza_participant | Advanced usage only |
| general.num_threads | VANETZA_NUM_THREADS | Number of threads to use in Vanetza's thread pool for parallel processing of messages | 4 | |
| general.publish_encoded_payloads | VANETZA_PUBLISH_ENCODED_PAYLOADS | Publish the raw ASN.1 encoded messages to DDS topics, in addition to the JSON representations | false | Only recommended for debugging purposes, as it may introduce significant latency |
| general.debug_enabled | VANETZA_DEBUG_ENABLED | Enable debug prints in the terminal/logs | false | |
| general.zenoh_local_only | VANETZA_ZENOH_LOCAL_ONLY | Use Zenoh in same host only mode, without connecting to any remote router or peer | true | Advanced usage only |
| general.zenoh_interfaces | VANETZA_ZENOH_INTERFACES | Comma-separated list of network interfaces to use for Zenoh communication when not in local-only mode |  | For example: lo,eth0,wlan0 |
| station.id | VANETZA_STATION_ID | ETSI Station ID field | 99 | |
| station.type | VANETZA_STATION_TYPE | ETSI Station Type field | 15 | |
| station.mac_address | VANETZA_MAC_ADDRESS | Virtual Mac Address used as the source on L2 ethernet headers | interface's address | |
| station.beacons_enabled | VANETZA_BEACONS_ENABLED | Send GeoNetworking Beacons every 3 seconds | true | |
| station.use_hardcoded_gps | VANETZA_USE_HARDCODED_GPS | Use hardcoded gps coordinates instead of information provided by a GPS module | true | |
| station.latitude | VANETZA_LATITUDE | Hardcoded GPS latitude - Usually set on static RSUs | 40 | |
| station.longitude | VANETZA_LONGITUDE | Hardcoded GPS longitude - Usually set on static RSUs | -8 | |
| station.length | VANETZA_LENGTH | Vehicle lenght in meters | 10 | |
| station.width | VANETZA_WIDTH | Vehicle width in meters | 3 | |
| --- | START_EMBEDDED_MOSQUITTO | Start an MQTT server inside the container to simulate a full OBU or RSU with a local MQTT broker | false | |
| --- | EMBEDDED_MOSQUITTO_PORT | The port on which the embedded MQTT broker listens for connections | 1883 | |
| --- | SUPPORT_MAC_BLOCKING | Start the container with ebtables support in order to dynamically block and unblock MAC addresses, simulating out-of-range scenarios | false | |

Each supported type of message (CAM, DENM, CPM, VAM, SPATEM, MAPEM) has its own set of configurations, which are specified in the following table (using CAMs as an example):
 
| .ini file key | Environment var key | Description | Default | Notes |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| cam.enabled | VANETZA_CAM_ENABLED | Enable the CAM module | true | |
| cam.mqtt_enabled | VANETZA_CAM_MQTT_ENABLED | Enable publishing and subscribing to MQTT topics | true | |
| cam.dds_enabled | VANETZA_CAM_DDS_ENABLED | Enable publishing and subscribing to DDS topics | true  | Advanced usage only |
| cam.zenoh_enabled | VANETZA_CAM_ZENOH_ENABLED | Enable publishing and subscribing to Zenoh keys | false | Advanced usage only |
| cam.mqtt_time_enabled | VANETZA_CAM_MQTT_TIME_ENABLED | Enable publishing to the respective time topic for performance measurement purposes | true | |
| cam.mqtt_test_enabled | VANETZA_CAM_MQTT_TEST_ENABLED | Enable publishing to the respective MQTT test topic for performance measurement purposes | false | |
| cam.periodicity | VANETZA_CAM_PERIODICITY | Periodicity with which to send the default CAM, in milliseconds | 1000 | Only available on CAMs, 0 to disable |
| cam.topic_in | VANETZA_CAM_TOPIC_IN | MQTT/DDS topic from which Vanetza receives JSON CAMs to encode and send | vanetza/in/cam |  |
| cam.topic_out | VANETZA_CAM_TOPIC_OUT | MQTT/DDS topic to which Vanetza sends JSON CAMs that were received and decoded | vanetza/out/cam | |
| cam.topic_time | VANETZA_CAM_TOPIC_TIME | MQTT/DDS topic to which Vanetza sends JSON CAMs that were received in vanetza/in/cam and sent through the WAVE interface | vanetza/time/cam | |
| cam.topic_test | VANETZA_CAM_TOPIC_TEST | MQTT/DDS topic to which Vanetza sends JSON CAMs that were received and decoded, with additional timestamp fields for performance measurement purposes | vanetza/test/cam | |
| cam.udp_out_addr | VANETZA_CAM_UDP_OUT_ADDR | Address of the UDP server to which Vanetza sends decoded JSON CAMs, in order to minimize communication latency - Used in NAP's Connection Manager v1 | 127.0.0.1 | |
| cam.udp_out_port | VANETZA_CAM_UDP_OUT_PORT | Port of the UDP server to which Vanetza sends decoded JSON CAMs, in order to minimize communication latency - Used in NAP's Connection Manager v1 | 5051 | 0 to disable |
| cam.own_topic_out | VANETZA_CAM_OWN_TOPIC_OUT | MQTT/DDS topic to which Vanetza sends a JSON representation of the hardcoded CAMs| vanetza/own/cam | "" to disable | Only available on CAMs |

## Variable transformations

To facilitate the construction of JSON messages, Vanetza performs some transformations on certain fields that are required to be in a specific format or unit according to the ETSI specifications. These transformations are applied both to incoming and outgoing messages.

For example, the latitude and longitude fields in CAM messages are represented in the JSON messages as decimal degrees, while the ETSI specifications require them to be in a fixed-point format with a specific scale factor. Vanetza automatically performs the necessary conversions to ensure that the messages conform to the ETSI specifications.

The file **tools/socktap/asn1json.py** contains a `transformation` dictionary that defines the transformations applied to each field.  Bellow, a table summarizing the transformations applied to the most common fields used in all supported message types:

| Variable Type | JSON Format | ETSI Format | Transformation Description |
| ----------- | ----------- | ----------- | ----------- |
| Latitude | Decimal degrees (e.g., 40.628349) | Integer value representing latitude in units of 10⁻⁷ degrees (e.g., 406283493) | Values are scaled by a factor of 10⁷ when converting between JSON and ETSI representations (ETSI = JSON × 10⁷, JSON = ETSI ÷ 10⁷) |
| Longitude | Decimal degrees (e.g., -8.654390) | Integer value representing longitude in units of 10⁻⁷ degrees (e.g., -865439000) | Values are scaled by a factor of 10⁷ when converting between JSON and ETSI representations (ETSI = JSON × 10⁷, JSON = ETSI ÷ 10⁷) |
| CartesianCoordinateLarge | Decimal meters (e.g., 123.45) | Integer value representing distance in units of 10⁻² meters (e.g., 12345) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| CartesianCoordinate | Decimal meters (e.g., 123.45) | Integer value representing distance in units of 10⁻² meters (e.g., 12345) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| SteeringWheelAngleValue | Decimal degrees (e.g., 15.0) | Integer value representing angle in units of 2/3 degrees (e.g., 22) | Values are scaled by a factor of 2/3 when converting between JSON and ETSI representations (ETSI = JSON × (2/3), JSON = ETSI ÷ (2/3)) |
| AltitudeValue | Decimal meters (e.g., 800.0) | Integer value representing altitude in units of 10⁻² meters (e.g., 80000) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| HeadingValue | Decimal degrees (e.g., 153.0) | Integer value representing heading in units of 10⁻¹ degrees (e.g., 1530) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| HeadingConfidence | Decimal between 0 and 1 (e.g., 0.9) | Integer value representing confidence level (e.g., 9) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| VelocityComponentValue | Decimal meters per second (e.g., 8.7) | Integer value representing speed in units of 10⁻² meters per second (e.g., 870) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| SpeedConfidence | Decimal between 0 and 1 (e.g., 0.95) | Integer value representing confidence level (e.g., 95) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| VehicleLengthValue | Decimal meters (e.g., 10.2) | Integer value representing vehicle length in units of 10⁻¹ meters (e.g., 102) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| VehicleWidth | Decimal meters (e.g., 3.0) | Integer value representing vehicle width in units of 10⁻¹ meters (e.g., 30) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| LongitudinalAccelerationValue | Decimal meters per second squared (e.g., -0.4) | Integer value representing acceleration in units of 10⁻¹ meters per second squared (e.g., -4) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| AccelerationValue | Decimal meters per second squared (e.g., -0.4) | Integer value representing acceleration in units of 10⁻¹ meters per second squared (e.g., -4) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| AccelerationConfidence | Decimal between 0 and 1 (e.g., 0.9) | Integer value representing confidence level (e.g., 9) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| YawRateValue | Decimal degrees per second (e.g., 11.0) | Integer value representing yaw rate in units of 10⁻² degrees per second (e.g., 1100) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| DistanceValue | Decimal meters (e.g., 10.0) | Integer value representing distance in units of 10⁻² meters (e.g., 1000) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| DistanceConfidence | Decimal between 0 and 1 (e.g., 0.95) | Integer value representing confidence level (e.g., 95) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| SpeedValueExtended | Decimal meters per second (e.g., 8.7) | Integer value representing speed in units of 10⁻² meters per second (e.g., 870) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| LateralAccelerationValue | Decimal meters per second squared (e.g., -0.4) | Integer value representing acceleration in units of 10⁻¹ meters per second squared (e.g., -4) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| LongitudinalAccelerationValue | Decimal meters per second squared (e.g., -0.4) | Integer value representing acceleration in units of 10⁻¹ meters per second squared (e.g., -4) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| VerticalAccelerationValue | Decimal meters per second squared (e.g., -0.4) | Integer value representing acceleration in units of 10⁻¹ meters per second squared (e.g., -4) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) | |
| ObjectDimensionValue | Decimal meters (e.g., 15.5) | Integer value representing object dimension in units of 10⁻¹ meters (e.g., 155) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| WGS84AngleValue | Decimal degrees (e.g., 15.5) | Integer value representing angle in units of 10⁻¹ degrees (e.g., 155) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| CartesianAngleValue | Decimal degrees (e.g., 15.5) | Integer value representing angle in units of 10⁻¹ degrees (e.g., 155) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| SensorHeight | Decimal meters (e.g., 1.5) | Integer value representing sensor height in units of 10⁻² meters (e.g., 150) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| SemiRangeLength | Decimal meters (e.g., 10.0) | Integer value representing semi-range length in units of 10⁻¹ meters (e.g., 100) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| Radius | Decimal meters (e.g., 5.0) | Integer value representing radius in units of 10⁻¹ meters (e.g., 50) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |
| DeltaLatitude | Decimal degrees (e.g., 0.0001) | Integer value representing latitude difference in units of 10⁻⁷ degrees (e.g., 10000) | Values are scaled by a factor of 10⁷ when converting between JSON and ETSI representations (ETSI = JSON × 10⁷, JSON = ETSI ÷ 10⁷) |
| DeltaLongitude | Decimal degrees (e.g., 0.0001) | Integer value representing longitude difference in units of 10⁻⁷ degrees (e.g., 10000) | Values are scaled by a factor of 10⁷ when converting between JSON and ETSI representations (ETSI = JSON × 10⁷, JSON = ETSI ÷ 10⁷) |
| DeltaAltitude | Decimal meters (e.g., 1.5) | Integer value representing altitude difference in units of 10⁻² meters (e.g., 150) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| CoordinateConfidence | Decimal between 0 and 1 (e.g., 0.95) | Integer value representing confidence level (e.g., 95) | Values are scaled by a factor of 10² when converting between JSON and ETSI representations (ETSI = JSON × 10², JSON = ETSI ÷ 10²) |
| TimestampIts | Decimal seconds (e.g., 123.456) | Integer value representing timestamp in units of 10⁻³ seconds (e.g., 123456) | Values are scaled by a factor of 10³ when converting between JSON and ETSI representations (ETSI = JSON × 10³, JSON = ETSI ÷ 10³) |
| AngleConfidence | Decimal between 0 and 1 (e.g., 0.9) | Integer value representing confidence level (e.g., 9) | Values are scaled by a factor of 10 when converting between JSON and ETSI representations (ETSI = JSON × 10, JSON = ETSI ÷ 10) |


## Advanced Usage

### Measuring processing performance & MQTT/DDS/Zenoh latency

Each JSON payload that is output by Vanetza contains two different timestamps in UNIX time format.

#### vanetza/out/xxx

- "timestamp": The instant at which the ASN.1 encoded message was received at the WAVE interface
- "test/json_timestamp": The instant at which Vanetza finished preparing the JSON payload in order to send it via MQTT and/or DDS.

The difference between these timestamps represents the total time elapsed while performing the decoding, parsing, and JSON generation tasks.

The difference between the "test/json_timestamp" field and the time at which a given client receives a message on this topic represents the total latency introduced by MQTT/DDS and the underlying network

#### vanetza/own/cam

- "timestamp": The instant at which the internal timer scheduled the transmission of a new self-generated CAM message
- "test/json_timestamp": The instant at which Vanetza finished preparing the JSON payload in order to send it via MQTT, DDS and/or Zenoh.

The difference between these timestamps represents the total time elapsed while performing the encoding and queueing of the ASN.1 message and the JSON generation pipeline.

The difference between the "test/json_timestamp" field and the time at which a given client receives a message on this topic represents the total latency introduced by MQTT/DDS/Zenoh and the underlying network

#### vanetza/time/xxx

- "timestamp": The instant at which the JSON payload was received in the "vanetza/in/xxx" MQTT/DDS/Zenoh topic
- "test/wave_timestamp": The instant at which Vanetza finished preparing and sending the ASN.1 encoded message through the WAVE interface

The difference between these timestamps represents the total time elapsed while parsing the JSON message and encoding and queueing the ASN.1 message. 

The difference between the "test/wave_timestamp" field and the time at which a given client receives a message on this topic represents the total latency introduced by MQTT/DDS and the underlying network


**Note**: The "json_timestamp" fields need to be included in the JSON payload itself. This introduces a slight error margin that is unavoidable in this scenario.

### Simulating situations where stations become out of range from each other

Within the Docker network every Vanetza container will always have conectivity with any other, meaning that out-of-range scenarios (which are common in VANETs) cannot be easily simulated.
To solve this, NAP-Vanetza uses ebtables to dynamically block L2 packets from certain source MAC addresses, on a per-container basis.

As an example, the following commands will simulate a condition where the OBU stops receiving any ETSI messages sent from the RSU and vice-versa:
```
# Enters the OBU container and starts blocking all messages with the RSU's MAC Address as the source
docker-compose exec obu block 6e:06:e0:03:00:01

# Enters the RSU container and starts blocking all messages with the OBU's MAC Address as the source
docker-compose exec rsu block 6e:06:e0:03:00:02
```

Note that 'obu' and 'rsu' are the names of the respective containers, as specified in docker-compose.yml

To simulate a scenario where connectivity is regained, execute:
```
docker-compose exec obu unblock 6e:06:e0:03:00:01
# ...
```

On Windows hosts this functionality will not work. To run Vanetza containers without this feature, the following environment variables must be set in docker-compose.yml:
- VANETZA_INTERFACE=eth0
- SUPPORT_MAC_BLOCKING=false

### DDS

In order to minimize communication latency between Vanetza and any critical producer/consumer applications, NAP-Vanetza also supports publishing and subscribing to OMG Data Distribution Service (DDS) topics. This is accomplished using an external Golang DDS module that is included in the Vanetza container, and SysV Message Queues.

To use it, simply activate the <message_type>.dds_enabled configuration flags. NAP-Vanetza will use the same topic names configured for MQTT. In fact, both technologies may be used simultaneously, if required.

The **tools/dds_service** folder includes simple python examples for producer and subscriber applications.

You may also use NAP's [dds-mqtt-adapter](https://code.nap.av.it.pt/atcll/dds-mqtt-adapter) project, which subscribes to every Vanetza DDS topic and relays any published messages to an MQTT broker.
This may be useful for:
* Allowing developers easy access to the exchanged messages, for debugging or monitoring purposes
* Allowing less critical services to effectively subscribe to a DDS topic via MQTT, if NAP-Vanetza's MQTT functionality is disabled for performance reasons.

### Zenoh
NAP-Vanetza also supports publishing and subscribing to Zenoh keys. This allows users to leverage Zenoh's unique features such as its efficient data dissemination through peer-to-peer communication and routing. Vanetza's Zenoh implementation supports both shared memory communication for intra-host data exchange and UDP communication for inter-host data exchange, making it a versatile choice for various deployment scenarios.

To use it, simply activate the <message_type>.zenoh_enabled configuration flags. NAP-Vanetza will use the same topic names configured for MQTT. All technologies may be used simultaneously, if required.

### Prometheus Metrics

When running, Vanetza continuously computes a set of metrics regarding its current status, message statistics, and latency information. These are exposed using the Prometheus format, at the port specified in the configuration file.

```
observed_packets_count_total{direction="tx",message="spatem"} 
observed_packets_count_total{direction="rx",message="spatem"} 
observed_packets_count_total{direction="tx",message="vam"} 
observed_packets_count_total{direction="rx",message="vam"} 
observed_packets_count_total{direction="rx",message="mapem"} 
observed_packets_count_total{direction="tx",message="cpm"} 
observed_packets_count_total{direction="tx",message="mapem"} 
observed_packets_count_total{direction="tx",message="denm"} 
observed_packets_count_total{direction="rx",message="denm"} 
observed_packets_count_total{direction="tx",message="cam"} 
observed_packets_count_total{direction="rx",message="cpm"} 
observed_packets_count_total{direction="rx",message="cam"} 
# ---
observed_packets_latency_total{direction="tx",message="spatem"} 
observed_packets_latency_total{direction="rx",message="spatem"} 
observed_packets_latency_total{direction="tx",message="vam"} 
observed_packets_latency_total{direction="rx",message="vam"} 
observed_packets_latency_total{direction="rx",message="mapem"} 
observed_packets_latency_total{direction="tx",message="cpm"} 
observed_packets_latency_total{direction="tx",message="mapem"} 
observed_packets_latency_total{direction="tx",message="denm"} 
observed_packets_latency_total{direction="rx",message="denm"} 
observed_packets_latency_total{direction="tx",message="cam"} 
observed_packets_latency_total{direction="rx",message="cpm"} 
observed_packets_latency_total{direction="rx",message="cam"} 
```

These are easily extensible.

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

Updates to new releases of the ETSI specifications may be introduced in the future.

## Authors

Development of Vanetza is part of ongoing research work at [Technische Hochschule Ingolstadt](https://www.thi.de/forschung/carissma/labore/car2x-labor/).
Maintenance is coordinated by Raphael Riebl.

Development of NAP-Vanetza is part of ongoing research work at [Instituto de Telecomunicações' Network Architectures and Protocols Group](https://www.it.pt/Groups/Index/36).

Questions and Bug Reports: jp.amaral@av.it.pt / andreiagf@av.it.pt

## License

Vanetza is licensed under LGPLv3, see [license file](LICENSE.md) for details.
