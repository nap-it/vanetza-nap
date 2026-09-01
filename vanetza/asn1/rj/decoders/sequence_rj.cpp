// decoders/sequence_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "asn_internal.h"
#include "constr_SEQUENCE.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

bool decode_sequence(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    if (!json.IsObject()) {
        ctx.set_error("Expected JSON object for SEQUENCE");
        return false;
    }

    char* base = static_cast<char*>(struct_ptr);

    // Iterate through type descriptor elements
    for (size_t edx = 0; edx < td->elements_count; ++edx) {
        const asn_TYPE_member_t* elm = &td->elements[edx];

        // Look for this field in the JSON object
        auto it = json.FindMember(elm->name);
        if (it == json.MemberEnd()) {
            // Field not present in JSON
            if (elm->optional) {
                // Optional field - leave as nullptr/default
                continue;
            }
            // For non-optional fields, check if it has a default value
            if (elm->default_value_set) {
                continue;  // Will use default
            }
            // Required field missing - this is an error
            if (ctx.verbose) {
                ctx.path.push_back(elm->name);
            }
            ctx.set_error("Required field is missing");
            return false;
        }

        const rapidjson::Value& member_json = it->value;

        // Skip null values for optional fields
        if (member_json.IsNull() && elm->optional) {
            continue;
        }

        void* member_ptr;

        if (elm->flags & ATF_POINTER) {
            // Pointer field - allocate the member
            size_t member_size = get_struct_size(elm->type);
            if (member_size == 0) {
                ctx.set_error("Unknown struct size for SEQUENCE member");
                return false;
            }
            void* allocated = CALLOC(1, member_size);
            if (!allocated) {
                ctx.set_error("Memory allocation failed for SEQUENCE member");
                return false;
            }
            // Store pointer in struct
            *reinterpret_cast<void**>(base + elm->memb_offset) = allocated;
            member_ptr = allocated;
        } else {
            // Inline field
            member_ptr = base + elm->memb_offset;
        }

        // Recursively decode the member
        if (ctx.verbose) {
            ctx.path.push_back(elm->name);
            if (!decode_any(elm->type, member_ptr, member_json, ctx)) {
                return false;
            }
            ctx.path.pop_back();
        } else {
            if (!decode_any(elm->type, member_ptr, member_json, ctx)) {
                return false;
            }
        }
    }

    return true;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza
