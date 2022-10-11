# To run:
# python3 asn1json.py cpp > asn1json.cpp
# python3 asn1json.py hpp > asn1json.hpp

from email import header
import asn1tools
from datetime import datetime
import time, sys
from math import pow

######

base_dir = "../../asn1"
asn1_files = ["TS102894-2v131-CDD.asn", "EN302637-2v141-CAM.asn", "EN302637-3v131-DENM.asn", "TS103300-3v211-VAM.asn",
              "DSRC.asn", "DSRC_REGION_noCircular.asn", "TR103562v211-CPM.asn", "TS103301v211-MAPEM.asn", "TS103301v211-SPATEM.asn"]

default_types = ["INTEGER", "BOOLEAN", "ENUMERATED", "BIT STRING", "IA5String",
                 "SEQUENCE", "OCTET STRING", "SEQUENCE OF", "UTF8String", "NumericString", "CHOICE"]

######

transformation = {
    "Latitude": (pow(10,7),[900000001]),
    "Longitude": (pow(10,7),[1800000001]),
    "AltitudeValue": (pow(10,2),[800001]),
#    "AltitudeConfidence": (pow(10,2),[14,15]),
    "HeadingValue": (pow(10,1),[3601]),
    "HeadingConfidence": (pow(10,1),[126,127]),
    "SpeedValue": (pow(10,2),[16383]),
    "SpeedConfidence": (pow(10,2),[126,127]),
    "AccelerationConfidence": (pow(10,1),[102]),
    "VehicleLengthValue": (pow(10,1),[1023]),
    "VehicleWidth": (pow(10,1),[61,62]),
    "LongitudinalAccelerationValue": (pow(10,1),[161]),
    "YawRateValue": (pow(10,2),[32767]),
    "DistanceValue": (pow(10,2),[]),
    "DistanceConfidence": (pow(10,2),[101,102]),
    "SpeedValueExtended": (pow(10,2),[16383]),
    "LateralAccelerationValue": (pow(10,1),[161]),
    "LongitudinalAccelerationValue": (pow(10,1),[161]),
    "VerticalAccelerationValue": (pow(10,1),[161]),
    "ObjectDimensionValue": (pow(10,1),[]),
    "WGS84AngleValue": (pow(10,1),[3601]),
    "CartesianAngleValue": (pow(10,1),[3601]),
    "SensorHeight": (pow(10,2),[]),
    "SemiRangeLength": (pow(10,1),[]),
    "Radius": (pow(10,1),[])
}

printed = ["PhoneNumber", "VehicleHeight", "PreemptPriorityList", "WMInumber", "VDS",
           "RegionalExtension", "TemporaryID", "DescriptiveName", "MessageFrame", "OpeningDaysHours"]

include = ["NodeXY", "VehicleID", "TransitVehicleStatus", "TransmissionAndSpeed", "DigitalMap",
           "Position3D", "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", "DataParameters", "EnabledLaneList"]

add_t = ["ObjectClass", "VehicleID", "VehicleLength", "VerticalAcceleration", "DeltaReferencePosition", "ItsPduHeader", "PtActivationData", "MapData",
         "NodeAttributeSetXY", "NodeXY", "DigitalMap", "TransmissionAndSpeed", "Position3D", "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", "DataParameters", "EnabledLaneList", "PerceivedObjectContainer"]

ignore_member_names = ['regional', 'shadowingApplies', 'expiryTime']
ignore_member_types = ["PhoneNumber", "OpeningDaysHours", "MessageFrame", "DescriptiveName", "RegionalExtension", "Iso3833VehicleType",
                                                                                                "REG-EXT-ID-AND-TYPE.&id", "REG-EXT-ID-AND-TYPE.&Type", 'MESSAGE-ID-AND-TYPE.&id', 'MESSAGE-ID-AND-TYPE.&Type', 'PreemptPriorityList', "WMInumber", "VDS", "TemporaryID"]

treat_as_optional = ["validityDuration"]

capitalize_first_letter = ["class", "long"]

######

basic = []
asn1_types = []
bitstrings = {}

initial_len = len(printed)

# Sorry for the one-liners on the __str__() methods :(

class ASN1Sequence:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = [m for m in definition["members"] if m is not None and m["type"] not in ignore_member_types and m['name'] not in ignore_member_names]
        self.ignored_members = [m for m in definition["members"] if m is not None and (m["type"] in ignore_member_types or m['name'] in ignore_member_names)]
        self.dependencies = [
            m for m in self.members if m["type"] not in default_types]
        self.parent_name = parent_name
        self.parent_file = parent_file

        for m in self.members:
            if m["name"] in treat_as_optional:
                m["optional"] = True

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    j = json{""" + ', '.join(['{"' + m["name"] + '", ' + ('to_json_' + m["type"].replace("-", "_") + '(' if m["type"] in bitstrings else '') + ((((("(" + " || ".join([('*' if "optional" in m and m["optional"] else '') + ('(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ") == " + str(n)) for n in transformation[m["type"]][1]])) + ") ? " + ('(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')') + " : ") if len(transformation[m["type"]][1]) > 0 else "") + (('(double)(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')') + (" / " + str(float(transformation[m["type"]][0])))) ) if m["type"] in transformation else ('(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')')) + (')' if m["type"] in bitstrings else '') + '}' for m in self.members if "optional" not in m or not m["optional"]]) + """};
    """ + '\n    '.join(['if (p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ' != 0) j[\"' + m["name"] + '\"] = ' + ('to_json_' + m["type"] + '(' if m["type"] in bitstrings else '') + (((((("(" + " && ".join([('*' if "optional" in m and m["optional"] else '') + ('(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ") != " + str(n)) for n in transformation[m["type"]][1]])) + ") ? " + ('*(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')') + " : ") if len(transformation[m["type"]][1]) > 0 else "") + (('(double) *(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')') + (" / " + str(float(transformation[m["type"]][0])))) ) if m["type"] in transformation else ('*(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')'))) + (')' if m["type"] in bitstrings else '') + ';' for m in self.members if "optional" in m and m["optional"]]) + """
}

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    p._asn_ctx.ptr= nullptr;
    """ + '\n    '.join([(("double " + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + "; ") if m["type"] in transformation else "") + (('if (j.contains("' + m["name"] + '")) { p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ' = vanetza::asn1::allocate<' + m["type"].replace("-", "_") + '_t>(); ') if "optional" in m and m["optional"] else '') + 'j.at("' + m["name"] + '").get_to(' + ((('*' if "optional" in m and m["optional"] else '') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '')) if m["type"] not in transformation else "(") + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '));' + ((' *' if "optional" in m and m["optional"] else ' ') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ") =" + ((" (" + " && ".join([(("(" + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title())).replace("-", "_") + ") != " + str(n)) for n in transformation[m["type"]][1]]) + ")" if len(transformation[m["type"]][1]) > 0 else "") + (" ? " if len(transformation[m["type"]][1]) > 0 else " ") + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + " * " + str(int(transformation[m["type"]][0])) + (" : " + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") if len(transformation[m["type"]][1]) > 0 else "") + ";") if m["type"] in transformation else "") + (' } ' if "optional" in m and m["optional"] else '') + ('\n    else { ' + 'p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '=nullptr; }' if "optional" in m and m["optional"] else '') for m in self.members if m["type"] not in bitstrings]) + """
    """ + '\n    '.join([(('if (j.contains("' + m["name"] + '")) { p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ' = vanetza::asn1::allocate<' + m["type"].replace("-", "_") + '_t>(); ') if "optional" in m and m["optional"] else '') + 'from_json_' + m["type"].replace("-", "_") + '(j["' + m["name"] + '"],' + ('*' if "optional" in m and m["optional"] else '') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '));' + (' } ' if "optional" in m and m["optional"] else '') + ('\n    else { ' + 'p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '=nullptr; }' if "optional" in m and m["optional"] else '') for m in self.members if m["type"] in bitstrings]) + """
    """ + '\n    '.join(['p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '=nullptr;' for m in self.ignored_members if "optional" in m and m["optional"]]) + """
}"""


class ASN1Choice:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.actual_type = definition['actual_type'] if 'actual_type' in definition else None
        self.members = [m for m in definition["members"] if m is not None and m["type"] not in ignore_member_types and m['name'] not in ignore_member_names]
        self.dependencies = [
            m for m in self.members if m["type"] not in default_types]
        self.parent_name = parent_name
        self.parent_file = parent_file

        for m in self.members:
            if m['name'] in capitalize_first_letter:
                m['name'] = m['name'].title()

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    j = json{};
    if """ + '\n    } else if '.join(['(p.present == ' + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + '_PR_' + m['name'].replace("-", "_") + ') {\n        j[\"' + m['name'] + '\"] = ' + ('p.choice.' + m['name'].replace("-", "_") if m["type"] not in bitstrings else ('to_json_' + m["type"].replace("-", "_") + '(p.choice.' + m['name'].replace("-", "_") + ')')) + ';' for m in self.members]) + """
    }
}

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    if """ + '\n    } else if '.join(['(j.contains("' + m["name"] + '")) {\n        p.present = ' + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + '_PR_' + m['name'].replace("-", "_") + ';\n        ' + (('j.at("' + m["name"] + '").get_to(') if m["type"] not in bitstrings else ('from_json_' + m["type"].replace("-", "_") + '(' + 'j["' + m["name"] + '"], ')) + 'p.choice.' + m["name"].replace("-", "_") + ');' for m in self.members]) + """
    } else {
        p.present = """ + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + """_PR_NOTHING;
    }
}"""

class ASN1SequenceOf:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        # print(definition)
        self.element = definition["element"]["type"]
        self.members = [definition["element"]]
        self.dependencies = [self.element] if self.element not in default_types else []
        self.parent_name = parent_name
        self.parent_file = parent_file

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const """ + self.element.replace("-", "_") + """_t po = *(p.list.array[i]);
        """ + ('// ' if self.element in basic else '') + """to_json(obj, po);
        j.push_back(""" + ('po' if self.element in basic else 'obj') + """);
    }
}

void from_json(const json& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """* p_tmp = vanetza::asn1::allocate<""" + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """>();
    for (const auto& item : j.items())
    {
        """ + self.element.replace("-", "_") + """_t *element = vanetza::asn1::allocate<""" + self.element.replace("-", "_") + """_t>();
        item.value().get_to(*element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}"""


class ASN1BitString:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = [m for m in definition["named-bits"]
                        if m is not None] if "named-bits" in definition else []
        self.parent_name = parent_name
        self.parent_file = parent_file

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

json to_json_""" + self.name.replace("-", "_") + """(const """ + self.name.replace("-", "_") + """_t p);

void from_json_""" + self.name.replace("-", "_") + """(const json& j, """ + self.name.replace("-", "_") + """_t& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

json to_json_""" + self.name.replace("-", "_") + """(const """ + self.name.replace("-", "_") + """_t p) {
    return json{""" + ', '.join(['{"' + m[0] + '", ' + '(bool) (*(p.buf + (sizeof(uint8_t) * (' + str(m[1]) + ' / 8))) & (1 << ((7 * ((' + str(int(m[1])) + ' / 8) + 1))-(' + str(m[1]) + ' % 8))))}' for m in self.members]) + """};
}

void from_json_""" + self.name.replace("-", "_") + """(const json& j, """ + self.name.replace("-", "_") + """_t& p) {
    """ + self.name.replace("-", "_") + """_t* p_tmp = vanetza::asn1::allocate<""" + self.name.replace("-", "_") + """_t>();
    """ + '\n    '.join(["bool " + m[0].replace("-", "_") + ";" for m in self.members]) + """
    """ + '\n    '.join(['j.at("' + m[0] + '").get_to(' + '(' + m[0].replace("-", "_") + '));' for m in self.members]) + """
    p_tmp->size = (""" + str(len(self.members)) + """ / 8) + 1;
    p_tmp->bits_unused = (""" + str(len(self.members)) + """ % 8) != 0 ? 8 - (""" + str(len(self.members)) + """ % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    """ + '\n    '.join(['*(p_tmp->buf + (sizeof(uint8_t) * ' + str(i) + ')) = (uint8_t) 0;' for i in range(int(len(self.members) / 8) + 1)]) + """
    """ + '\n    '.join(['if (' + m[0].replace("-", "_") + ') *(p_tmp->buf + (sizeof(uint8_t) * ' + str(int(int(m[1])/8)) + ')) |= (1 << ' + str(7 - (int(m[1]) % 8)) + ');' for m in self.members]) + """
    p = *p_tmp;
    delete p_tmp;
}"""


class ASN1TODO:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.parent_name = parent_name
        self.parent_file = parent_file

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name + "_t" if self.name in add_t else self.name) + """& p);

void from_json(const json& j, """ + (self.name + "_t" if self.name in add_t else self.name) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name + "_t" if self.name in add_t else self.name) + """& p) {
    j = json{}; // TODO
}

void from_json(const json& j, """ + (self.name + "_t" if self.name in add_t else self.name) + """& p) {
    // TODO
}"""


def parse_type(type_name, top_level_key, asn1_file, asn1_type):
    if asn1_type["type"] in ["SEQUENCE"]:
        for m in asn1_type["members"]:
            if m is not None and m['type'] == "CHOICE":
                #print(m)
                m['actual_type'] = type_name + '__' + m['name']
                m['type'] = type_name + "::" + m['actual_type']
                parse_type(type_name + "::" + type_name + '__' + m['name'], top_level_key, asn1_file, {'type': 'CHOICE', 'members': m['members'], 'name': type_name + "::" + type_name + '__' + m['name'], 'actual_type': m['actual_type']})
        asn1_types.append(ASN1Sequence(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["CHOICE"]:
        asn1_types.append(ASN1Choice(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["SEQUENCE OF"]:
        asn1_types.append(ASN1SequenceOf(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["BIT STRING"]:
        asn1_types.append(ASN1BitString(
            type_name, asn1_type, top_level_key, asn1_file))
        bitstrings[type_name] = ASN1BitString(
            type_name, asn1_type, top_level_key, asn1_file)
    elif asn1_type["type"] in ["OCTET STRING", "NumericString", "UTF8String", "IA5String", "NodeOffsetPointXY", "NodeOffsetPointZ"]:
        asn1_types.append(
            ASN1TODO(type_name, asn1_type, top_level_key, asn1_file))
    else:
        basic.append(type_name)
        printed.append(type_name)


for asn1_file in asn1_files:
    parsed_info = asn1tools.parse_files(base_dir + "/" + asn1_file)
    top_level_key = list(parsed_info.keys())[0]
    for type_name in parsed_info[top_level_key]["types"]:
        asn1_type = parsed_info[top_level_key]["types"][type_name]
        parse_type(type_name, top_level_key, asn1_file, asn1_type)

intro = """/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#include "asn1json.hpp"
#include <boost/optional.hpp>

using json = nlohmann::json;

namespace nlohmann {
    template <typename T>
    struct adl_serializer<boost::optional<T>> {
        static void to_json(json& j, const boost::optional<T>& opt) {
            if (opt == boost::none) {
                j = nullptr;
            } else {
              j = *opt; // this will call adl_serializer<T>::to_json which will
                        // find the free function to_json in T's namespace!
            }
        }

        static void from_json(const json& j, boost::optional<T>& opt) {
            if (j.is_null()) {
                opt = boost::none;
            } else {
                opt = j.get<T>(); // same as above, but with
                                  // adl_serializer<T>::from_json
            }
        }
    };
}

void to_json(json& j, const TimestampIts_t& p) {
    long tmp;
    asn_INTEGER2long(&p, &tmp);
    j = tmp;
}

void from_json(const json& j, TimestampIts_t& p) {
    p.buf = nullptr;
    asn_long2INTEGER(&p, stol(j.dump()));
}
"""

header_intro = """/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include <nlohmann/json.hpp>
#include <iostream>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/vam.hpp>
#include <vanetza/asn1/spatem.hpp>
#include <vanetza/asn1/mapem.hpp>

""" + '\n'.join(['#include <vanetza/asn1/its/' + inc.replace("-", "_") + '.h>' for inc in include]) + """

using json = nlohmann::json;

void to_json(json& j, const TimestampIts_t& p);
void from_json(const json& j, TimestampIts_t& p);
"""

if sys.argv[1] == "hpp":
    print(header_intro)
else:
    print(intro)

b = len(printed)

# TODO: Replace with better algorithm when there's time
# for i in range(10):
while len(printed) + initial_len != len(asn1_types) + b:
    for t in asn1_types:
        if t.name not in printed and (t.definition["type"] in ["BIT STRING", "OCTET STRING", "NumericString", "UTF8String", "IA5String", "CLASS"] or all([d["type"] in printed + default_types for d in t.members])):
            print(t.header_str() if sys.argv[1] == "hpp" else t)
            printed.append(t.name)
        # elif t.name not in printed:
        #    print(t.name + " " + t.definition["type"])
        #    print(all([d["type"] in printed + default_types for d in t.members]))
        #    print([d["type"] for d in t.members if d["type"] not in printed + default_types])
    # print('\n\n\n\n')
    # time.sleep(1)

if sys.argv[1] == "hpp":
    print("\n#endif")