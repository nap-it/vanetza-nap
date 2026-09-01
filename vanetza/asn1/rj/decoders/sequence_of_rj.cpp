// decoders/sequence_of_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "asn_internal.h"
#include "constr_SET_OF.h"
#include "asn_SET_OF.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

bool decode_sequence_of(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    if (!json.IsArray()) {
        ctx.set_error("Expected JSON array for SEQUENCE OF");
        return false;
    }

    // Get element type descriptor
    const asn_TYPE_member_t* elm = &td->elements[0];

    // The struct IS the list (at offset 0)
    asn_anonymous_set_* list = _A_SET_FROM_VOID(struct_ptr);

    // Get element size once
    size_t element_size = get_struct_size(elm->type);
    if (element_size == 0) {
        ctx.set_error("Unknown struct size for SEQUENCE OF element");
        return false;
    }

    // Decode each array element
    for (rapidjson::SizeType i = 0; i < json.Size(); ++i) {
        const rapidjson::Value& element_json = json[i];

        // Allocate element
        void* element = CALLOC(1, element_size);
        if (!element) {
            ctx.set_error("Memory allocation failed for SEQUENCE OF element");
            return false;
        }

        // Decode element
        if (ctx.verbose) {
            ctx.path.push_back("index #" + std::to_string(i));
            if (!decode_any(elm->type, element, element_json, ctx)) {
                FREEMEM(element);
                return false;
            }
            ctx.path.pop_back();
        } else {
            if (!decode_any(elm->type, element, element_json, ctx)) {
                FREEMEM(element);
                return false;
            }
        }

        // Add to list using asn1c's SET_OF helper
        if (asn_set_add(list, element) != 0) {
            ASN_STRUCT_FREE(*elm->type, element);
            ctx.set_error("Failed to add element to SEQUENCE OF");
            return false;
        }
    }

    return true;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza