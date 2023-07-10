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

replace_types = {
    "Temperature": "ITS_Container_Temperature"
}

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

def get_element_name(m, self, opt):
    return ('*' if "optional" in m and m["optional"] and opt else '') + \
            '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + \
            (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_")

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

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        result = """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    """
        
        member_strs = []
        for m in self.members:
            if "optional" in m and m["optional"]:
                continue
            
            member_str = ('json.AddMember("' + m["name"] + '", ' + ('to_json_' + m["type"].replace("-", "_") + '(' if m["type"] in bitstrings else 'to_json('))
            
            if m["type"] in transformation:
                condition_str = " || ".join([(get_element_name(m, self, True) + \
                                            ") == " + str(n)) for n in transformation[m["type"]][1]])
                
                if len(transformation[m["type"]][1]) > 0:
                    member_str += "(" + condition_str + ") ? " + \
                                    get_element_name(m, self, True) + ') : '
                
                member_str += '(double)' + get_element_name(m, self, False) + \
                                ') / ' + str(float(transformation[m["type"]][0]))
            else:
                member_str += get_element_name(m, self, False) + ')'
            
            member_str += ', allocator), allocator);'
            member_strs.append(member_str)
        
        result += '\n    '.join(member_strs) + """
"""
        
        member_strs = []
        for m in self.members:
            if "optional" in m and m["optional"]:
                member_str = ('if ' + get_element_name(m, self, False) + ' != 0) ' + \
                                'json.AddMember("' + m["name"] + '", ' + ('to_json_' + m["type"] + '(' if m["type"] in bitstrings else 'to_json('))
                                
                if m["type"] in transformation:
                    condition_str = " && ".join([(get_element_name(m, self, True) + \
                                                ") != " + str(n)) for n in transformation[m["type"]][1]])

                    if len(transformation[m["type"]][1]) > 0:
                        member_str += "(" + condition_str + ") ? "
                    
                    member_str += '(double) *' + get_element_name(m, self, False) + \
                                    ') / ' + str(float(transformation[m["type"]][0]))

                    if len(transformation[m["type"]][1]) > 0:
                        member_str += ' : *' + get_element_name(m, self, False) + ')'

                else:
                    member_str += get_element_name(m, self, True) + ')'
            
                member_str += ', allocator), allocator);'
                member_strs.append(member_str)
        
        result += '    ' + '\n    '.join(member_strs)
        
        result += """
    return json;
}

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    p._asn_ctx.ptr = nullptr;
    """
        
        member_strs = []
        for m in self.members:
            needs_closing = False
            member_str = ""

            if m["type"] in transformation:
                member_str += 'double ' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '; '
            
            if "optional" in m and m["optional"]:
                needs_closing = True
                type_name = m["type"] if m["type"] not in replace_types else replace_types[m["type"]]
                member_str += 'if (j.HasMember("' + m["name"] + '")) { ' + \
                                get_element_name(m, self, False)[1:] + \
                                ' = vanetza::asn1::allocate<' + type_name.replace("-", "_") + '_t>(); '
            
            if m["type"] not in bitstrings:
                member_str += 'from_json(j["' + m["name"] + '"], '
            else:
                member_str += 'from_json_' + m["type"].replace("-", "_") + '(j["' + m["name"] + '"],'
            
            if m["type"] not in transformation:
                member_str += get_element_name(m, self, True) + '));'
            else:
                member_str += '(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ')); ' + \
                                get_element_name(m, self, True) + \
                                ') ='
                if len(transformation[m["type"]][1]) > 0:
                    member_str += ' (' + ' && '.join([('(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ') != ' + str(n)) for n in transformation[m["type"]][1]]) + ') ? ' + \
                                    (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ' * ' + str(int(transformation[m["type"]][0])) + ' : ' + \
                                    (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ';'
                else:
                    member_str += (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ' * ' + str(int(transformation[m["type"]][0])) + ';'
                                    
            if needs_closing:
                member_str += ' }\n    else { ' + \
                                 get_element_name(m, self, False)[1:] + '=nullptr; }'
            
            member_strs.append(member_str)

        for m in self.ignored_members:
            member_str = ""
            if "optional" in m and m["optional"]:
                member_str += get_element_name(m, self, False)[1:] + '=nullptr;'
            member_strs.append(member_str)

        result += '\n    '.join(member_strs)

        result += """
}

"""
        
        return result



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

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        result =  """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if """

        member_strs = []
        for m in self.members:
            member_str = '(p.present == ' + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + \
                        '_PR_' + m["name"].replace("-", "_") + ') {\n        json.AddMember("' + m["name"] + '", '
            
            if m["type"] not in bitstrings:
                member_str += 'to_json(p.choice.' + m["name"].replace("-", "_") + ', allocator), allocator);'
            else:
                member_str += 'to_json_' + m["type"].replace("-", "_") + '(p.choice.' + m["name"].replace("-", "_") + ', allocator), allocator);'
            
            member_strs.append(member_str)

        result += '\n    } else if '.join(member_strs)
        result += """
    }
    return json;
}

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    if """ 

        member_strs = []
        for m in self.members:
            member_str = '(j.HasMember("' + m["name"] + '")) {\n        p.present = ' + \
                        (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + \
                        '_PR_' + m["name"].replace("-", "_") + ';\n        '
            
            if m["type"] not in bitstrings:
                member_str += 'from_json(j["' + m["name"] + '"], '
            else:
                member_str += 'from_json_' + m["type"].replace("-", "_") + '(j["' + m["name"] + '"], '

            member_str += 'p.choice.' + m["name"].replace("-", "_") + ');'

            member_strs.append(member_str)

        result += '\n    } else if '.join(member_strs)
        result += """\n    } else {
        p.present = """ + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + """_PR_NOTHING;
    }
}"""

        return result

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

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const """ + self.element.replace("-", "_") + """_t po = *(p.list.array[i]);
        """ + ('// ' if self.element in basic else '') + """Value obj = to_json(po, allocator);
        json.PushBack(""" + ('po' if self.element in basic else 'obj') + """, allocator);
    }
    return json;
}

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p) {
    """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """* p_tmp = vanetza::asn1::allocate<""" + \
          (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        """ + self.element.replace("-", "_") + """_t *element = vanetza::asn1::allocate<""" + self.element.replace("-", "_") + """_t>();
        from_json(item, *element);
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

Value to_json_""" + self.name.replace("-", "_") + """(const """ + self.name.replace("-", "_") + """_t p, Document::AllocatorType& allocator);

void from_json_""" + self.name.replace("-", "_") + """(const Value& j, """ + self.name.replace("-", "_") + """_t& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json_""" + self.name.replace("-", "_") + """(const """ + self.name.replace("-", "_") + """_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    """ + '\n    '.join(['json.AddMember("' + m[0] + '", ' + '(bool) (*(p.buf + (sizeof(uint8_t) * (' + str(m[1]) + ' / 8))) & (1 << ((7 * ((' + str(int(m[1])) + ' / 8) + 1))-(' + \
                         str(m[1]) + ' % 8)))), allocator);' for m in self.members]) + """
    return json;
}

void from_json_""" + self.name.replace("-", "_") + """(const Value& j, """ + self.name.replace("-", "_") + """_t& p) {
    """ + self.name.replace("-", "_") + """_t* p_tmp = vanetza::asn1::allocate<""" + self.name.replace("-", "_") + """_t>();
    """ + '\n    '.join(["bool " + m[0].replace("-", "_") + ";" for m in self.members]) + """
    """ + '\n    '.join(['if (j.HasMember("' + m[0] + '")) from_json(j["' + m[0] + '"], ' + '(' + m[0].replace("-", "_") + '));' for m in self.members]) + """
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

Value to_json(const """ + (self.name + "_t" if self.name in add_t else self.name) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.name + "_t" if self.name in add_t else self.name) + """& p);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.name + "_t" if self.name in add_t else self.name) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, """ + (self.name + "_t" if self.name in add_t else self.name) + """& p) {
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

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator) {
    long tmp;
    asn_INTEGER2long(&p, &tmp);
    return Value(tmp);
}

void from_json(const Value& j, TimestampIts_t& p) {
    p.buf = nullptr;
    asn_long2INTEGER(&p, j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64());
}

Value to_json(const long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, long& p) {
    p = j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64();
}

Value to_json(const unsigned long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned long& p) {
    p = j.GetUint64();
}

Value to_json(const unsigned& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned& p) {
    if (j.IsBool()) p = j.GetBool();
    else p = j.GetUint();
}

Value to_json(const double& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, double& p) {
    p = j.GetDouble();
}

Value to_json(const bool& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, bool& p) {
    p = j.GetBool();
}

"""

header_intro = """/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <iostream>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/vam.hpp>
#include <vanetza/asn1/spatem.hpp>
#include <vanetza/asn1/mapem.hpp>

""" + '\n'.join(['#include <vanetza/asn1/its/' + inc.replace("-", "_") + '.h>' for inc in include]) + """

using namespace rapidjson;

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, TimestampIts_t& p);
Value to_json(const long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long& p);
Value to_json(const unsigned long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned long& p);
Value to_json(const unsigned& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned& p);
Value to_json(const double& p, Document::AllocatorType& allocator);
void from_json(const Value& j, double& p);
Value to_json(const bool& p, Document::AllocatorType& allocator);
void from_json(const Value& j, bool& p);
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