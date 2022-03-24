import asn1tools
from datetime import datetime

asn1_types = []
printed = []

bitstrings = {}

add_t = ["DeltaReferencePosition", "ItsPduHeader", "PtActivationData"]
ignore = ["WMInumber", "VDS", "OpeningDaysHours", "PhoneNumber", "CLASS", "REG-EXT-ID-AND-TYPE.&id", "REG-EXT-ID-AND-TYPE.&Type"]

base_dir = "../../asn1"
asn1_files = ["TS102894-2v131-CDD.asn", "DSRC_REGION_noCircular.asn", "TR103562v211-CPM.asn"]

default_types = ["INTEGER", "BOOLEAN", "ENUMERATED", "BIT STRING", "IA5String", "SEQUENCE", "OCTET STRING", "SEQUENCE OF", "UTF8String", "NumericString", "CHOICE"]

class ASN1Sequence:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = [m for m in definition["members"] if m is not None]
        self.dependencies = [m for m in self.members if m["type"] not in default_types]
        self.parent_name = parent_name
        self.parent_file = parent_file
        

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name+ "_t" if self.name in add_t else self.name) + """& p) {
    std::cout << \"""" + self.name + """\" << std::endl;
    j = json{""" + ', '.join(['{"' + m["name"] + '", ' + ('to_json_' + m["type"] + '(' if m["type"] in bitstrings else '') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') +  m["name"] + ')' + (')' if m["type"] in bitstrings else '') + '}' for m in self.members if "optional" not in m or not m["optional"]]) + """};
    """ + '\n    '.join(['if (p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') +  m["name"] + ' != 0) j[\"' + m["name"] + '\"] = ' + ('to_json_' + m["type"] + '(' if m["type"] in bitstrings else '') + '*(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') +  m["name"] + ')' + (')' if m["type"] in bitstrings else '') + ';' for m in self.members if "optional" in m and m["optional"]]) + """
}

void from_json(const json& j, """ + (self.name+ "_t" if self.name in add_t else self.name) + """& p) {
    """ + '\n    '.join(['j.at("' + m["name"] + '").get_to(' + ('*' if "optional" in m and m["optional"] else '') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') +  m["name"] + '));' for m in self.members if m["type"] not in bitstrings]) + """
    """ + '\n    '.join(['from_json_' + m["type"] + '(j["' + m["name"] + '"],' + ('*' if "optional" in m and m["optional"] else '') + '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') +  m["name"] + '));' for m in self.members if m["type"] in bitstrings]) + """
}"""

class ASN1BitString:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = [m for m in definition["named-bits"] if m is not None] if "named-bits" in definition else []
        self.parent_name = parent_name
        self.parent_file = parent_file

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

json to_json_""" + self.name + """(const """ + self.name + """_t p) {
    std::cout << \"""" + self.name + """ bitstring\" << std::endl;
    return json{""" + ', '.join(['{"' + m[0] + '", '  + '(bool) (*(p.buf + (sizeof(uint8_t) * (' + str(m[1]) + ' / 8))) & (1 << ((7 * ((' + str(m[1]) + ' / 8) + 1))-(' + str(m[1]) + ' % 8))))}' for m in self.members]) + """};
}

void from_json_""" + self.name + """(const json& j, """ + self.name + """_t& p) {
    """ + '\n    '.join(["bool " + m[0] + ";" for m in self.members]) + """
    """ + '\n    '.join(['j.at("' + m[0] + '").get_to(' + '(' + m[0] + '));' for m in self.members]) + """
    p.size = (""" + str(len(self.members)) + """ / 8) + 1;
    p.bits_unused = 8 - (""" + str(len(self.members)) + """ % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    """ + '\n    '.join(['*(p.buf + (sizeof(uint8_t) * ' + str(i) + ')) = (uint8_t) 0;' for i in range(int(len(self.members) / 8) + 1)]) + """
    """ + '\n    '.join(['if (' + m[0] + ') *(p.buf + (sizeof(uint8_t) * ' + str(int(int(m[1])/8)) + ')) |= (1 << ' + str(int(m[1]) % 8) + ');' for m in self.members]) +  """
}"""


class ASN1TODO:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.parent_name = parent_name
        self.parent_file = parent_file

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

void to_json(json& j, const """ + (self.name+ "_t" if self.name in add_t else self.name) + """& p) {
    j = json{}; // TODO
}

void from_json(const json& j, """ + (self.name+ "_t" if self.name in add_t else self.name) + """& p) {
    // TODO
}"""


for asn1_file in asn1_files:
    parsed_info = asn1tools.parse_files(base_dir + "/" + asn1_file)
    top_level_key = list(parsed_info.keys())[0]
    for type_name in parsed_info[top_level_key]["types"]:
        if type_name in ignore:
            printed.append(type_name)
            continue
        asn1_type = parsed_info[top_level_key]["types"][type_name]
        if asn1_type["type"] in ["SEQUENCE", "CHOICE"]:
            asn1_types.append(ASN1Sequence(type_name, asn1_type, top_level_key, asn1_file))
        elif asn1_type["type"] in ["BIT STRING"]:
            asn1_types.append(ASN1BitString(type_name, asn1_type, top_level_key, asn1_file))
            bitstrings[type_name] = ASN1BitString(type_name, asn1_type, top_level_key, asn1_file)
        elif asn1_type["type"] in ["OCTET STRING", "NumericString", "UTF8String", "IA5String", "CLASS"]:
            asn1_types.append(ASN1TODO(type_name, asn1_type, top_level_key, asn1_file))
        else:
            printed.append(type_name)

intro = """/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#include <nlohmann/json.hpp>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>

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
}"""
print(intro)
b = len(printed)

# TODO: Replace with better algorithm when there's time
for i in range(10):
#while len(printed) != len(asn1_types) + b:
    print(str(len(printed)) + " vs " + (str(len(asn1_types) + b)))
    print("\n\n\n\n\n\n\n")
    for t in asn1_types:
        #if t.name not in printed:
        #    print(t.definition["type"])
        if t.name not in printed and (t.definition["type"] in ["BIT STRING", "OCTET STRING", "NumericString", "UTF8String", "IA5String", "CLASS"] or all([d["type"] in printed + default_types for d in t.members])):
            #print(t)
            printed.append(t.name)
        elif t.name not in printed:
            print(t.name + " " + t.definition["type"])
            print(all([d["type"] in printed + default_types for d in t.members]))
            print([d["type"] for d in t.members if d["type"] not in printed + default_types])

    