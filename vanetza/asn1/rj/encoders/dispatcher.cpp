// encoders/dispatcher.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

// ASN.1 support headers
extern "C" {
#include "asn_application.h"
#include "constr_TYPE.h"
#include "constr_SEQUENCE.h"
#include "constr_CHOICE.h"
#include "constr_SET_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "NativeInteger.h"
#include "INTEGER.h"
#include "BOOLEAN.h"
#include "NativeEnumerated.h"
#include "ENUMERATED.h"
#include "OCTET_STRING.h"
#include "BIT_STRING.h"
#include "IA5String.h"
#include "UTF8String.h"
#include "VisibleString.h"
#include "NumericString.h"
#include "OPEN_TYPE.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {

rapidjson::Value encode_any(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    // Dispatch ordered by frequency in ITS messages:
    // SEQUENCE(295) > NativeInteger(221) > SEQUENCE_OF(107) > NativeEnumerated(61) > CHOICE(35) > BIT_STRING(29) > OCTET_STRING(21) > ...

    const asn_TYPE_operation_t* op = td->op;

    // Most common: SEQUENCE (295 occurrences)
    if (op == &asn_OP_SEQUENCE) {
        return detail::encode_sequence(td, struct_ptr, ctx);
    }
    // Second most common: NativeInteger (221 occurrences)
    if (op == &asn_OP_NativeInteger) {
        return detail::encode_native_integer(td, struct_ptr, ctx);
    }
    // Third: SEQUENCE_OF (107 occurrences)
    if (op == &asn_OP_SEQUENCE_OF || op == &asn_OP_SET_OF) {
        return detail::encode_sequence_of(td, struct_ptr, ctx);
    }
    // Fourth: NativeEnumerated (61 occurrences)
    if (op == &asn_OP_NativeEnumerated) {
        return detail::encode_enumerated(td, struct_ptr, ctx);
    }
    // Fifth: CHOICE (35 occurrences)
    if (op == &asn_OP_CHOICE || op == &asn_OP_OPEN_TYPE) {
        return detail::encode_choice(td, struct_ptr, ctx);
    }
    // Sixth: BIT_STRING (29 occurrences)
    if (op == &asn_OP_BIT_STRING) {
        return detail::encode_bit_string(td, struct_ptr, ctx);
    }
    // Seventh: OCTET_STRING (21 occurrences)
    if (op == &asn_OP_OCTET_STRING) {
        return detail::encode_octet_string(td, struct_ptr, ctx);
    }
    // Less common types
    if (op == &asn_OP_BOOLEAN) {
        return detail::encode_boolean(td, struct_ptr, ctx);
    }
    if (op == &asn_OP_INTEGER) {
        return detail::encode_integer(td, struct_ptr, ctx);
    }
    if (op == &asn_OP_ENUMERATED) {
        return detail::encode_enumerated(td, struct_ptr, ctx);
    }
    if (op == &asn_OP_IA5String || op == &asn_OP_UTF8String ||
        op == &asn_OP_VisibleString || op == &asn_OP_NumericString) {
        return detail::encode_string(td, struct_ptr, ctx);
    }

    return rapidjson::Value(rapidjson::kNullType);
}

} // namespace rj
} // namespace asn1
} // namespace vanetza