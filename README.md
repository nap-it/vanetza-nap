# Vanetza-NAP

Vanetza-NAP is an extended version of [Vanetza](https://github.com/riebl/vanetza), an open-source C++ implementation of the ETSI C-ITS protocol suite. It operates on ITS-G5 channels in a Vehicular Ad Hoc Network (VANET) using IEEE 802.11p (WAVE), and adds MQTT/DDS/Zenoh pub/sub integration, a custom JER-RapidJSON ASN.1 encoder/decoder, multi-link transport, and extended radio and monitoring features.

**[Full documentation](https://wiki.nap.av.it.pt/groups/nap/tutorials/vanetza-nap/)**

---

## Citation

If you find this project useful in your research, please consider citing:

```bibtex
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

---

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

---

## Quick Start

```bash
# Clone the repository
git clone https://github.com/nap-it/vanetza-nap
cd vanetza-nap
git checkout release2-main

# Start the default RSU + OBU pair
cd deployment/local
docker-compose up

# Or build locally
docker build -t vanetza-nap:latest .
```

<!-- See the [Getting Started guide](https://nap-it.github.io/vanetza-nap/getting-started/install/) for full setup instructions, configuration reference, and examples. -->


---
## Authors

Development of Vanetza is part of ongoing research work at [Technische Hochschule Ingolstadt](https://www.thi.de/forschung/carissma/labore/car2x-labor/).
Maintenance is coordinated by Raphael Riebl.

Development of NAP-Vanetza is part of ongoing research work at [Instituto de Telecomunicações' Network Architectures and Protocols Group](https://www.it.pt/Groups/Index/36).

Questions and Bug Reports: jp.amaral@av.it.pt / h.domingos@av.it.pt / andreiagf@av.it.pt

---

## License

This project is licensed under the LGPL-3.0 License — see the [LICENSE](LICENSE) file for details.

It is based on [Vanetza](https://github.com/riebl/vanetza) by Raphael Riebl, also licensed under LGPL-3.0.
