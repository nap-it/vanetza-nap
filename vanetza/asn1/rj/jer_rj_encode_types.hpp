// jer_rj_encode_types.hpp - Internal encoder type declarations
#ifndef VANETZA_ASN1_RJ_JER_RJ_ENCODE_TYPES_HPP
#define VANETZA_ASN1_RJ_JER_RJ_ENCODE_TYPES_HPP

#include "jer_rj_context.hpp"
#include <rapidjson/document.h>

// Forward declare ASN.1 types (avoid including heavy headers)
struct asn_TYPE_descriptor_s;
typedef struct asn_TYPE_descriptor_s asn_TYPE_descriptor_t;

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Generic encoder dispatcher.
 * Routes to the appropriate type-specific encoder based on td->op.
 */
rapidjson::Value encode_any(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

// ============================================================================
// Type-specific encoders (internal use - called by dispatcher)
// ============================================================================
namespace detail {

rapidjson::Value encode_integer(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_native_integer(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_boolean(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_enumerated(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_sequence(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_choice(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_sequence_of(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_octet_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_bit_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

rapidjson::Value encode_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx
);

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_RJ_ENCODE_TYPES_HPP