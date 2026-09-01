// jer_rj_decode_types.hpp
#ifndef VANETZA_ASN1_RJ_JER_RJ_DECODE_TYPES_HPP
#define VANETZA_ASN1_RJ_JER_RJ_DECODE_TYPES_HPP

#include <rapidjson/document.h>
#include <string>
#include <vector>

// Forward declare ASN.1 types
struct asn_TYPE_descriptor_s;
typedef struct asn_TYPE_descriptor_s asn_TYPE_descriptor_t;

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Context for decoding operations.
 * Tracks error state and JSON path during recursive decoding.
 *
 * When verbose=false (default), no path tracking overhead is incurred.
 * When verbose=true, decoders push/pop path elements for detailed error messages.
 */
struct DecodeContext {
    const char* error = nullptr;       // First error encountered (or nullptr)
    bool verbose = false;              // Enable verbose path tracking
    std::vector<std::string> path;     // Path stack (only used when verbose=true)

    void set_error(const char* msg) {
        if (!error) error = msg;  // Keep first error
    }

    // Get the full path as a string (for error messages)
    std::string get_path() const {
        if (path.empty()) return "(root)";
        std::string result;
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) result += " -> ";
            result += path[i];
        }
        return result;
    }

    // Get formatted error with path (for verbose mode)
    std::string get_verbose_error() const {
        if (!error) return "";
        std::string result = "Error: ";
        result += error;
        result += "\nIn: ";
        result += get_path();
        return result;
    }
};

/**
 * Get the struct size for a type descriptor.
 * Handles different type specifics (SEQUENCE, CHOICE, SET_OF, primitives).
 *
 * @param td  Type descriptor
 * @return    Size in bytes of the structure, or 0 if unknown
 */
size_t get_struct_size(const asn_TYPE_descriptor_t* td);

/**
 * Generic decoder dispatcher.
 * Routes to the appropriate type-specific decoder based on td->op.
 *
 * @param td         Type descriptor
 * @param struct_ptr Pre-allocated structure to populate
 * @param json       JSON value to decode
 * @param ctx        Decode context for error tracking
 * @return           true on success, false on error
 */
bool decode_any(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

// ============================================================================
// Type-specific decoders (internal use - called by dispatcher)
// ============================================================================
namespace decode {

bool decode_integer(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_native_integer(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_boolean(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_enumerated(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_sequence(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_choice(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_sequence_of(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_octet_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_bit_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

bool decode_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx
);

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_RJ_DECODE_TYPES_HPP
