// jer_rj_encode.hpp - ASN.1 to RapidJSON encoding
#ifndef VANETZA_ASN1_RJ_JER_RJ_ENCODE_HPP
#define VANETZA_ASN1_RJ_JER_RJ_ENCODE_HPP

#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <string>

// Forward declare ASN.1 type descriptor
struct asn_TYPE_descriptor_s;
typedef struct asn_TYPE_descriptor_s asn_TYPE_descriptor_t;

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Encode an ASN.1 structure directly to a RapidJSON Value.
 *
 * Unit transformations (Latitude/10^7, Speed/100, etc.) are applied
 * automatically based on the type name.
 *
 * @param td         Type descriptor (e.g., &asn_DEF_Vanetza_ITS2_CAM)
 * @param struct_ptr Pointer to the ASN.1 structure
 * @param allocator  RapidJSON allocator (from your Document)
 * @return           RapidJSON Value representing the JSON object
 *
 * Example:
 * @code
 *   rapidjson::Document doc;
 *   auto& alloc = doc.GetAllocator();
 *
 *   Vanetza_ITS2_CAM_t cam = ...;
 *   rapidjson::Value json = jer_encode_rj(&asn_DEF_Vanetza_ITS2_CAM, &cam, alloc);
 *
 *   // Add custom fields
 *   json.AddMember("rssi", rssi, alloc);
 *   json.AddMember("timestamp_rx", timestamp, alloc);
 *
 *   // Serialize to string
 *   rapidjson::StringBuffer buffer;
 *   rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
 *   json.Accept(writer);
 *   std::string json_str = buffer.GetString();
 * @endcode
 */
rapidjson::Value jer_encode_rj(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    rapidjson::Document::AllocatorType& allocator
);

/**
 * Encode an ASN.1 structure to a RapidJSON Document.
 *
 * This is a convenience function when you need a self-contained Document
 * (owns its own allocator). Useful for roundtrip operations where the
 * Document will be passed to jer_decode_rj_inplace().
 *
 * @param td         Type descriptor (e.g., &asn_DEF_Vanetza_ITS2_CAM)
 * @param struct_ptr Pointer to the ASN.1 structure
 * @return           RapidJSON Document containing the JSON object
 *
 * Example:
 * @code
 *   Vanetza_ITS2_CAM_t cam = ...;
 *   rapidjson::Document doc = jer_encode_rj_doc(&asn_DEF_Vanetza_ITS2_CAM, &cam);
 *
 *   // Add custom fields
 *   doc.AddMember("rssi", rssi, doc.GetAllocator());
 *
 *   // Serialize to string
 *   rapidjson::StringBuffer buffer;
 *   rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
 *   doc.Accept(writer);
 * @endcode
 */
rapidjson::Document jer_encode_rj_doc(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr
);

/**
 * Convenience function: encode and serialize to string in one call.
 *
 * Use jer_encode_rj() instead if you need to add fields before serialization.
 *
 * @param td         Type descriptor
 * @param struct_ptr Pointer to the ASN.1 structure
 * @return           JSON string
 */
std::string jer_encode_rj_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr
);

/**
 * Serialize a RapidJSON Value to a pre-reserved StringBuffer.
 * Use this for better stringify performance - call buffer.Reserve(size) first.
 *
 * @param json       Value to serialize
 * @param buffer     Pre-reserved StringBuffer
 *
 * Recommended buffer sizes:
 *   - Small CAM: 2048 bytes
 *   - Large CAM (VW): 4096 bytes
 *   - CPM: 8192+ bytes
 */
void jer_stringify(const rapidjson::Value& json, rapidjson::StringBuffer& buffer);

} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_RJ_ENCODE_HPP