Title: What is Vanetza-NAP

Vanetza-NAP is an extended version of [Vanetza](https://github.com/riebl/vanetza), an open-source C++ implementation of the ETSI C-ITS protocol suite designed to operate on ITS-G5 channels in a Vehicular Ad Hoc Network (VANET) using IEEE 802.11p (WAVE).

If you find this code useful in your research, please consider citing:
```
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
```
###Vanetza-NAP purpose

Vanetza-NAP extends the base Vanetza project to integrate MQTT/DDS/Zenoh and JSON capabilities, as well as additional types of ETSI C-ITS messages.

The following message types are supported:

## Supported Messages

| Application | Full Name | BTP Port | ASN.1 Release | ASN.1 Module | Priority |
|---|---|---|---|---|---|
| **CAM** | Cooperative Awareness Message | 2001 | R1 + R2 | [TS 103 900](https://forge.etsi.org/rep/ITS/asn1/cam_ts103900) | 1 |
| **DENM** | Decentralized Environmental Notification Message | 2002 | R2 | [TS 103 831](https://forge.etsi.org/rep/ITS/asn1/denm_ts103831) | 0 |
| **CPM** | Collective Perception Message | 2009 | R2 | [TS 103 324](https://forge.etsi.org/rep/ITS/asn1/cpm_ts103324) | 0 |
| **VAM** | Vulnerable Road User Awareness Message | 2018 | R2 | [TS 103 300](https://forge.etsi.org/rep/ITS/asn1/vam-ts103300_3) | 1 |
| **SPATEM** | Signal Phase and Timing Extended Message | 2004 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 1 |
| **MAPEM** | Map Extended Message | 2003 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 1 |
| **IVIM** | Infrastructure to Vehicle Information Message | 2006 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 2 |
| **SSEM** | Signal Status Extended Message | 2008 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 2 |
| **SREM** | Signal Request Extended Message | 2007 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 2 |
| **RTCMEM** | RTCM Corrections Extended Message | 2014 | R1 | [TS 103 301](https://forge.etsi.org/rep/ITS/asn1/is_ts103301) | 2 |
| **MIM** | Marshalling Infrastructure Message | 2026 | R2 | [TS 103 882](https://forge.etsi.org/rep/ITS/asn1/avp_ts103882) | 2 |
| **MVM** | Marshalling Vehicle Message | 2027 | R2 | [TS 103 882](https://forge.etsi.org/rep/ITS/asn1/avp_ts103882) | 2 |

**Note:** Both MIM and MVM are specified to use the same BTP port (2026), however Vanetza-NAP uses separate ports for each message type to allow for easier message handling and routing.

Put simply, NAP-Vanetza's purpose is to manage the encoding, decoding, sending, and receiving of ETSI C-ITS messages, thus abstracting those layers from VANET application developers.

### Features overview

The core features of Vanetza-NAP include:

- Support for a wide range of ETSI C-ITS message types.
- Support for GeoNetworking Beacons.
- Integration with MQTT, DDS, and Zenoh for flexible communication options.
- JSON encoding and decoding capabilities for easier message handling and interoperability.
- Multilink support, allowing for communication over multiple types of interfaces, such as ITS-G5 and UDP.
- Multi-threading capabilities to handle concurrent message processing.
- Channel and packet metadata.
