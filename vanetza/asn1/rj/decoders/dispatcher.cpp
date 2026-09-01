// decoders/dispatcher.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "asn_application.h"
#include "constr_TYPE.h"
#include "constr_SEQUENCE.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_CHOICE.h"
#include "constr_SET_OF.h"
#include "OPEN_TYPE.h"
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
}

namespace vanetza {
namespace asn1 {
namespace rj {

size_t get_struct_size(const asn_TYPE_descriptor_t* td) {
    if (!td) return 0;

    const asn_TYPE_operation_t* op = td->op;

    // Constructed types have struct_size in their specifics
    if (op == &asn_OP_SEQUENCE) {
        const auto* specs = static_cast<const asn_SEQUENCE_specifics_t*>(td->specifics);
        return specs ? specs->struct_size : 0;
    }
    if (op == &asn_OP_CHOICE || op == &asn_OP_OPEN_TYPE) {
        const auto* specs = static_cast<const asn_CHOICE_specifics_t*>(td->specifics);
        return specs ? specs->struct_size : 0;
    }
    if (op == &asn_OP_SEQUENCE_OF || op == &asn_OP_SET_OF) {
        const auto* specs = static_cast<const asn_SET_OF_specifics_t*>(td->specifics);
        return specs ? specs->struct_size : 0;
    }

    // Primitive types have fixed known sizes
    if (op == &asn_OP_NativeInteger || op == &asn_OP_NativeEnumerated) {
        return sizeof(long);  // NativeInteger is stored as long
    }
    if (op == &asn_OP_INTEGER || op == &asn_OP_ENUMERATED) {
        return sizeof(INTEGER_t);
    }
    if (op == &asn_OP_BOOLEAN) {
        return sizeof(BOOLEAN_t);
    }
    if (op == &asn_OP_OCTET_STRING || op == &asn_OP_IA5String ||
        op == &asn_OP_UTF8String || op == &asn_OP_VisibleString ||
        op == &asn_OP_NumericString) {
        return sizeof(OCTET_STRING_t);
    }
    if (op == &asn_OP_BIT_STRING) {
        return sizeof(BIT_STRING_t);
    }

    return 0;  // Unknown type
}

bool decode_any(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    if (!td || !struct_ptr) {
        ctx.set_error("Null type descriptor or struct pointer");
        return false;
    }

    // Handle JSON null - leave structure at default (zero) values
    if (json.IsNull()) {
        return true;
    }

    const asn_TYPE_operation_t* op = td->op;

    // Dispatch ordered by frequency (same as encoder)
    if (op == &asn_OP_SEQUENCE) {
        return decode::decode_sequence(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_NativeInteger) {
        return decode::decode_native_integer(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_SEQUENCE_OF || op == &asn_OP_SET_OF) {
        return decode::decode_sequence_of(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_NativeEnumerated) {
        return decode::decode_enumerated(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_CHOICE || op == &asn_OP_OPEN_TYPE) {
        return decode::decode_choice(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_BIT_STRING) {
        return decode::decode_bit_string(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_OCTET_STRING) {
        return decode::decode_octet_string(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_BOOLEAN) {
        return decode::decode_boolean(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_INTEGER) {
        return decode::decode_integer(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_ENUMERATED) {
        return decode::decode_enumerated(td, struct_ptr, json, ctx);
    }
    if (op == &asn_OP_IA5String || op == &asn_OP_UTF8String ||
        op == &asn_OP_VisibleString || op == &asn_OP_NumericString) {
        return decode::decode_string(td, struct_ptr, json, ctx);
    }

    ctx.set_error("Unknown ASN.1 type");
    return false;
}

} // namespace rj
} // namespace asn1
} // namespace vanetza
