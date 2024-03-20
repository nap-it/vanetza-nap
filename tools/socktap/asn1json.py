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
asn1_files = ["TS102894-2v131-CDD.asn", "DSRC.asn", "ISO14816.asn", "ISO14823.asn", "ISO14906-0-6.asn", "ISO14906-1-7.asn", "ISO17419.asn", 
              "ISO24534-3.asn", "ISO19321IVIv2.asn", "EN302637-2v141-CAM.asn", "EN302637-3v131-DENM.asn", "TS103300-3v211-VAM.asn", 
              "DSRC_REGION_noCircular.asn", "TR103562v211-CPM.asn", "TS103301v211-MAPEM.asn", "TS103301v211-SPATEM.asn", 
              "TS103301v211-IVIM.asn", "TS103301v211-SREM.asn", "TS103301v211-SSEM.asn", "EVCSN-PDU-Descriptions.asn", 
              "EV-RSR-PDU-Descriptions.asn", "IMZM-PDU-Descriptions.asn", "TIS-TPG-Transactions-Descriptions.asn",
              "TS103301v211-RTCMEM.asn", "MCM-PDU-Descriptions.asn"]

default_types = ["INTEGER", "BOOLEAN", "ENUMERATED", "BIT STRING", "IA5String",
                 "SEQUENCE", "OCTET STRING", "SEQUENCE OF", "UTF8String", "NumericString", "CHOICE", "VisibleString"]

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
           "RegionalExtension", "TemporaryID", "DescriptiveName", "MessageFrame", "OpeningDaysHours",
           "Attributes", "GetStampedRq", "GetStampedRs", "SetInstanceRq", "SetStampedRq", "AttributeList",
           "AttributeIdList", "NULL", "CustomerContract"]

include = ["NodeXY", "VehicleID", "TransitVehicleStatus", "TransmissionAndSpeed", "DigitalMap",
           "Position3D", "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", 
           "DataParameters", "EnabledLaneList", "CS1", "CS2", "CS3", "CS4", "CS5", "CS7", "CS8", "ServiceNumber", 
           "GeoGraphicalLimit", "LicPlateNumber", "TaxCode", "AviEriDateTime", "ServiceApplicationLimit", 
           "FreightContainerData", "AddRq", "ChannelRq", "ChannelRs", "SubRq", "ContractAuthenticator", "DateCompact", 
           "Engine", "EquipmentOBUId", "EquipmentStatus", "ICC-Id", "LPN", "SignedValue", "PaymentSecurityData", 
           "PayUnit", "PersonalAccountNumber", "PurseBalance", "ReceiptOBUId", "ReceiptAuthenticator", "ReceiptText",
           "ResultFin", "SessionClass", "ReceiptContract", "SessionLocation", "DateAndTime", "ItsStationPosition", 
           "SignalHeadLocation", "ItsStationPositionList", "SignalHeadLocationList", "CurrentVehicleConfiguration", "ManouevreResponse"]

add_t = ["ObjectClass", "VehicleID", "VehicleLength", "VerticalAcceleration", "DeltaReferencePosition", "ItsPduHeader", 
         "PtActivationData", "MapData","NodeAttributeSetXY", "NodeXY", "DigitalMap", "TransmissionAndSpeed", "Position3D",
         "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", "DataParameters", 
         "EnabledLaneList", "PerceivedObjectContainer", "RTCMmessage", "FreightContainerData", "LPN", "SignedValue",
         "PurseBalance", "ReceiptContract", "SessionClass", "SessionLocation", "DateAndTime", "ItsStationPosition", 
         "SignalHeadLocation", "ItsStationPositionList", "SignalHeadLocationList", "BatteryType", "ChargingSpotLabel",
         "ContractID", "ExternalIdentificationMeans", "Pairing-ID", "Reservation-ID", "Reservation-Password", 
         "StationDetails", "CustomerContract", "ManouevreResponse"]

replace_types = {
    ("Temperature", "TS102894-2v131-CDD.asn"): "ITS_Container_Temperature",
    ("Temperature", "EN302637-3v131-DENM.asn"): "ITS_Container_Temperature",
    ("TrailerCharacteristics", "ISO14906-0-6.asn"): "EfcDsrcApplication_TrailerCharacteristics",
    ("DriverCharacteristics", "ISO14906-0-6.asn"): "EfcDsrcApplication_DriverCharacteristics",
    ("TrailerCharacteristics", "ISO19321IVIv2.asn"): "IVI_TrailerCharacteristics",
    ("DriverCharacteristics", "ISO19321IVIv2.asn"): "IVI_DriverCharacteristics",
    ("BasicContainer", "MCM-PDU-Descriptions.asn"): "BasicContainerMCM"
}

ignore_member_names = ['regional', 'shadowingApplies', 'expiryTime', 'fill', 'ownerCode', 'language', 'sessionLocation', 'avc', 'mlc', 'rsc']
ignore_member_types = ["PhoneNumber", "OpeningDaysHours", "MessageFrame", "DescriptiveName", "RegionalExtension", "Iso3833VehicleType",
                       "REG-EXT-ID-AND-TYPE.&id", "REG-EXT-ID-AND-TYPE.&Type", 'MESSAGE-ID-AND-TYPE.&id', 'MESSAGE-ID-AND-TYPE.&Type', 
                       'PreemptPriorityList', "WMInumber", "VDS", "TemporaryID", "Attributes", "GetStampedRq", "GetStampedRs", 
                       "SetInstanceRq", "SetStampedRq", "AttributeList", "AttributeIdList"]

treat_as_optional = ["validityDuration"]

capitalize_first_letter = ["class", "long"]

add_pointer = [
    ("GddAttribute", "ddd"),
    ("InternationalSign-destinationInformation", "ioList")
]

######

basic = []
asn1_types = []
bitstrings = {}

initial_len = len(printed)

def get_element_name(m, self, opt):
    return ('*' if "optional" in m and m["optional"] and opt else '') + \
            '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + \
            ((m["ext"] + '->') if m["ext"] != None else '') + \
            (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_")

class ASN1Sequence:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = []
        self.ignored_members = []
        ext = 0
        for i in range(len(definition["members"])):
            m = definition["members"][i]
            if m is None:
                if i != len(definition["members"]) - 2:
                    ext += 1
            elif m["type"] not in ignore_member_types and m['name'] not in ignore_member_names:
                m["ext"] = "ext" + str(ext) if ext > 0 else None
                self.members.append(m)
            else:
                m["ext"] = "ext" + str(ext) if ext > 0 else None
                self.ignored_members.append(m)
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

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field);
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

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field) {
    try {
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
                #type_name = m["type"] if m["type"] not in replace_types else replace_types[m["type"]]
                member_str += 'if (j.HasMember("' + m["name"] + '")) { ' + \
                                get_element_name(m, self, False)[1:] + \
                                ' = vanetza::asn1::allocate<' + m["type"].replace("-", "_").replace(" ", "_").replace("INTEGER", "long") +  \
                                    ('_t' if m["type"] not in ["INTEGER"] and "actual_type" not in m else '') + '>(); '
            
            if m["type"] not in bitstrings:
                member_str += 'from_json(j["' + m["name"] + '"], '
            else:
                member_str += 'from_json_' + m["type"].replace("-", "_") + '(j["' + m["name"] + '"],'
            
            if m["type"] not in transformation:
                member_str += get_element_name(m, self, True) + '), "' + m["name"] + '");'
            else:
                member_str += '(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '), "' + m["name"] + '"); ' + \
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
                member_str += ' }\n        else { ' + \
                                 get_element_name(m, self, False)[1:] + '=nullptr; }'
            
            member_strs.append(member_str)

        for m in self.ignored_members:
            member_str = ""
            if "optional" in m and m["optional"]:
                member_str += get_element_name(m, self, False)[1:] + '=nullptr;'
            member_strs.append(member_str)

        result += '\n        '.join(member_strs)

        result += """
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
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

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field);
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
                member_str += 'to_json_' + m["type"].replace("-", "_") + '(' + ('*' if "optional" in m and m["optional"] else '') + 'p.choice.' + m["name"].replace("-", "_") + ', allocator), allocator);'
            
            member_strs.append(member_str)

        result += '\n    } else if '.join(member_strs)
        result += """
    }
    return json;
}

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field) {
    try {
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

            member_str += ('*' if "optional" in m and m["optional"] else '') + 'p.choice.' + m["name"].replace("-", "_") + ', "' + m["name"] + '");'

            member_strs.append(member_str)

        result += '\n    } else if '.join(member_strs)
        result += """\n    } else {
        p.present = """ + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.name.replace("-", "_")) + """_PR_NOTHING;
        }
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
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

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field);
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

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field) {
    try {
        """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """* p_tmp = vanetza::asn1::allocate<""" + \
          (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """>();
        for (SizeType i = 0; i < j.Size(); i++) {
            const Value& item = j[i];
            """ + self.element.replace("-", "_") + """_t *element = vanetza::asn1::allocate<""" + self.element.replace("-", "_") + """_t>();
            from_json(item, *element, "index #" + std::to_string(i));
            asn_set_add(&(p_tmp->list), element);
        }
        p = *p_tmp;
        delete p_tmp;
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
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

void from_json_""" + self.name.replace("-", "_") + """(const Value& j, """ + self.name.replace("-", "_") + """_t& p, std::string field);
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

void from_json_""" + self.name.replace("-", "_") + """(const Value& j, """ + self.name.replace("-", "_") + """_t& p, std::string field) {
    try {
        """ + self.name.replace("-", "_") + """_t* p_tmp = vanetza::asn1::allocate<""" + self.name.replace("-", "_") + """_t>();
        """ + '\n        '.join(["bool " + m[0].replace("-", "_") + ";" for m in self.members]) + """
        """ + '\n        '.join(['if (j.HasMember("' + m[0] + '")) from_json(j["' + m[0] + '"], ' + '(' + m[0].replace("-", "_") + '), "' + m[0] + '");' for m in self.members]) + """
        p_tmp->size = (""" + str(len(self.members)) + """ / 8) + 1;
        p_tmp->bits_unused = (""" + str(len(self.members)) + """ % 8) != 0 ? 8 - (""" + str(len(self.members)) + """ % 8) : 0;
        p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
        """ + '\n        '.join(['*(p_tmp->buf + (sizeof(uint8_t) * ' + str(i) + ')) = (uint8_t) 0;' for i in range(int(len(self.members) / 8) + 1)]) + """
        """ + '\n        '.join(['if (' + m[0].replace("-", "_") + ') *(p_tmp->buf + (sizeof(uint8_t) * ' + str(int(int(m[1])/8)) + ')) |= (1 << ' + str(7 - (int(m[1]) % 8)) + ');' for m in self.members]) + """
        p = *p_tmp;
        delete p_tmp;
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
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

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, """ + (self.name.replace("-", "_") + "_t" if self.name in add_t else self.name.replace("-", "_")) + """& p, std::string field) {
    // TODO
}"""


def parse_type(type_name, top_level_key, asn1_file, asn1_type):
    type_name = type_name if (type_name, asn1_file) not in replace_types else replace_types[(type_name, asn1_file)]
    if "element" in asn1_type:
        asn1_type["element"]["type"] = asn1_type["element"]["type"] if (asn1_type["element"]["type"], asn1_file) not in replace_types else replace_types[(asn1_type["element"]["type"], asn1_file)]
    if "members" in asn1_type:
        for m in asn1_type["members"]:
            if m is not None:
                m["type"] = m["type"] if (m["type"], asn1_file) not in replace_types else replace_types[(m["type"], asn1_file)]
                if (type_name, m["name"]) in add_pointer:
                    m["optional"] = True 

    if "ISO14906" in asn1_file and "::" not in type_name:
        include.append(type_name)
        add_t.append(type_name)
    if asn1_type["type"] in ["SEQUENCE"]:
        for m in asn1_type["members"]:
            if m is not None and m['name'] not in ignore_member_names and m['type'] in ["SEQUENCE", "CHOICE", "SEQUENCE OF"]:
                escaped_type_name = type_name
                if "::" in type_name:
                    escaped_type_name = type_name.split("::")[-1]
                m['actual_type'] = escaped_type_name + '__' + m['name'] + "_PR::" + escaped_type_name + '__' + m['name']

                if m['type'] in ["SEQUENCE", "CHOICE"]:
                    parse_type(type_name + "::" + escaped_type_name + '__' + m['name'], top_level_key, asn1_file, {'type': m['type'], 'members': m['members'], 'name': type_name + "::" + escaped_type_name + '__' + m['name'], 'actual_type': m['actual_type']})
                if m['type'] in ["SEQUENCE OF"]:
                    parse_type(type_name + "::" + escaped_type_name + '__' + m['name'], top_level_key, asn1_file, {'type': m['type'], 'element': m['element'], 'name': type_name + "::" + escaped_type_name + '__' + m['name'], 'actual_type': m['actual_type']})

                m['type'] = type_name + "::" + escaped_type_name + '__' + m['name']
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
    elif asn1_type["type"] in ["OCTET STRING", "NumericString", "UTF8String", "IA5String", "NodeOffsetPointXY", "NodeOffsetPointZ", "VisibleString"]:
        asn1_types.append(
            ASN1TODO(type_name, asn1_type, top_level_key, asn1_file))
        if asn1_type["type"] == "OCTET STRING":
            add_t.append(type_name)
    else:
        #print(type_name)
        basic.append(type_name)
        printed.append(type_name)


for asn1_file in asn1_files:
    #print(asn1_file)
    parsed_info = asn1tools.parse_files(base_dir + "/" + asn1_file)
    for top_level_key in list(parsed_info.keys()):
        for type_name in parsed_info[top_level_key]["types"]:
            asn1_type = parsed_info[top_level_key]["types"][type_name]
            parse_type(type_name, top_level_key, asn1_file, asn1_type)

intro = """/*
*   JSON marshalling and unmarshalling functions for use by RapidJSON
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#include "asn1json.hpp"
#include <boost/optional.hpp>

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator) {
    long tmp;
    asn_INTEGER2long(&p, &tmp);
    return Value(tmp);
}

void from_json(const Value& j, TimestampIts_t& p, std::string field) {
    try {
        p.buf = nullptr;
        asn_long2INTEGER(&p, j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64());
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, long& p, std::string field) {
    try {  
        p = j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const unsigned long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned long& p, std::string field) {
    try {
        p = j.GetUint64();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const unsigned& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned& p, std::string field) {
    try {
        if (j.IsBool()) p = j.GetBool();
        else p = j.GetUint();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const double& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, double& p, std::string field) {
    try {
        p = j.GetDouble();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const bool& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, bool& p, std::string field) {
    try {
        p = j.GetBool();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, OCTET_STRING_t& p, std::string field) {
    // TODO
}

Value to_json(const NULL_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, NULL_t& p, std::string field) {
    // TODO
}

"""

header_intro = """/*
*   JSON marshalling and unmarshalling functions for use by RapidJSON
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/vam.hpp>
#include <vanetza/asn1/spatem.hpp>
#include <vanetza/asn1/mapem.hpp>
#include <vanetza/asn1/srem.hpp>
#include <vanetza/asn1/ssem.hpp>
#include <vanetza/asn1/ivim.hpp>
#include <vanetza/asn1/rtcmem.hpp>
#include <vanetza/asn1/evcsnm.hpp>
#include <vanetza/asn1/evrsrm.hpp>
#include <vanetza/asn1/imzm.hpp>
#include <vanetza/asn1/tistpgm.hpp>
#include <vanetza/asn1/mcm.hpp>

""" + '\n'.join(['#include <vanetza/asn1/its/' + inc + '.h>' for inc in include]) + """

using namespace rapidjson;

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, TimestampIts_t& p, std::string field);
Value to_json(const long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long& p, std::string field);
Value to_json(const unsigned long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned long& p, std::string field);
Value to_json(const unsigned& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned& p, std::string field);
Value to_json(const double& p, Document::AllocatorType& allocator);
void from_json(const Value& j, double& p, std::string field);
Value to_json(const bool& p, Document::AllocatorType& allocator);
void from_json(const Value& j, bool& p, std::string field);
Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, OCTET_STRING_t& p, std::string field);
Value to_json(const NULL_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, NULL_t& p, std::string field);
"""

if sys.argv[1] == "hpp":
    print(header_intro)
else:
    print(intro)

b = len(printed)

# TODO: Replace with better algorithm when there's time
# for i in range(10):
#while len(printed) + initial_len != len(asn1_types) + b:
while any([t.name not in printed for t in asn1_types]):
    for t in asn1_types:
        if t.name not in printed and (t.definition["type"] in ["BIT STRING", "OCTET STRING", "NumericString", "UTF8String", "IA5String", 
                                                                "CLASS", "VisibleString"] 
            or all([d["type"] in printed + default_types for d in t.members])):
            if t.definition["type"] not in ["OCTET STRING", "UTF8String", "VisibleString"]:
                #pass
                print(t.header_str() if sys.argv[1] == "hpp" else t)
            printed.append(t.name)
        #elif t.name not in printed:
            #print(t.name + " " + t.definition["type"])
            ##print(all([d["type"] in printed + default_types for d in t.members]))
            #print([d["type"] for d in t.members if d["type"] not in printed + default_types])
    #print('\n\n\n\n')
    #time.sleep(1)

if sys.argv[1] == "hpp":
    print("\n#endif")