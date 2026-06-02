// jer_rj_decode.hpp
#ifndef VANETZA_ASN1_RJ_JER_RJ_DECODE_HPP
#define VANETZA_ASN1_RJ_JER_RJ_DECODE_HPP

#include <rapidjson/document.h>
#include <string>

// Forward declare ASN.1 type descriptor
struct asn_TYPE_descriptor_s;
typedef struct asn_TYPE_descriptor_s asn_TYPE_descriptor_t;

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Decode result structure.
 */
struct DecodeResult {
    void* structure;           // Pointer to allocated ASN.1 structure (or nullptr on failure)
    const char* error;         // Error message (or nullptr on success)
    std::string verbose_error; // Verbose error with path (only populated if verbose=true)

    explicit operator bool() const { return structure != nullptr; }
};

/**
 * Decode a RapidJSON Value to an ASN.1 structure.
 *
 * Unit transformations are applied in reverse (Latitude×10^7, Speed×100, etc.)
 * Named bits are parsed from boolean object fields.
 *
 * @param td      Type descriptor (e.g., &asn_DEF_Vanetza_ITS2_CAM)
 * @param json    RapidJSON Value to decode (must match expected structure)
 * @param verbose Enable verbose error tracking with JSON path (default: false)
 * @return        DecodeResult with allocated structure or error
 *
 * IMPORTANT: Caller owns the returned structure and must free it with:
 *   ASN_STRUCT_FREE(asn_DEF_Vanetza_ITS2_CAM, result.structure);
 *
 * Example:
 * @code
 *   rapidjson::Document doc;
 *   doc.Parse(json_string);
 *
 *   auto result = jer_decode_rj(&asn_DEF_Vanetza_ITS2_CAM, doc);
 *   if (result) {
 *       Vanetza_ITS2_CAM_t* cam = static_cast<Vanetza_ITS2_CAM_t*>(result.structure);
 *       // Use cam...
 *
 *       // When done:
 *       ASN_STRUCT_FREE(asn_DEF_Vanetza_ITS2_CAM, cam);
 *   } else {
 *       std::cerr << "Decode error: " << result.error << std::endl;
 *       // Or with verbose=true:
 *       std::cerr << result.verbose_error << std::endl;
 *   }
 * @endcode
 */
DecodeResult jer_decode_rj(
    const asn_TYPE_descriptor_t* td,
    const rapidjson::Value& json,
    bool verbose = false
);

/**
 * Convenience function: parse JSON string and decode to ASN.1 structure.
 *
 * @param td          Type descriptor
 * @param json_string JSON string to parse and decode
 * @param verbose     Enable verbose error tracking with JSON path (default: false)
 * @return            DecodeResult with allocated structure or error
 */
DecodeResult jer_decode_rj_string(
    const asn_TYPE_descriptor_t* td,
    const char* json_string,
    bool verbose = false
);

/**
 * Convenience overload for std::string.
 */
inline DecodeResult jer_decode_rj_string(
    const asn_TYPE_descriptor_t* td,
    const std::string& json_string,
    bool verbose = false)
{
    return jer_decode_rj_string(td, json_string.c_str(), verbose);
}

/**
 * Decode into an existing (pre-allocated) structure.
 * Useful when you want to reuse a structure or have custom allocation.
 *
 * @param td         Type descriptor
 * @param struct_ptr Pre-allocated structure to populate
 * @param json       RapidJSON Value to decode
 * @param verbose_error Optional pointer to string for verbose error output
 * @return           true on success, false on error
 *
 * Note: On failure, the structure may be partially populated.
 * Use ASN_STRUCT_RESET() to clear it before retry.
 */
bool jer_decode_rj_inplace(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    std::string* verbose_error = nullptr
);

} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_RJ_DECODE_HPP
