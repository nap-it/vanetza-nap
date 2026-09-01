// decoders/choice_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "asn_internal.h"
#include "constr_CHOICE.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

bool decode_choice(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    if (!json.IsObject()) {
        ctx.set_error("Expected JSON object for CHOICE");
        return false;
    }

    const asn_CHOICE_specifics_t* specs =
        static_cast<const asn_CHOICE_specifics_t*>(td->specifics);

    char* base = static_cast<char*>(struct_ptr);

    // CHOICE JSON should have exactly one field - find which variant it is
    if (json.MemberCount() != 1) {
        ctx.set_error("CHOICE JSON must have exactly one field");
        return false;
    }

    // Get the single member
    auto it = json.MemberBegin();
    const char* variant_name = it->name.GetString();
    const rapidjson::Value& variant_json = it->value;

    // Find matching element in type descriptor
    for (size_t edx = 0; edx < td->elements_count; ++edx) {
        const asn_TYPE_member_t* elm = &td->elements[edx];

        // Compare variant name
        if (std::strcmp(elm->name, variant_name) != 0) {
            continue;
        }

        // Found the variant - set the "present" discriminator
        // present values are 1-indexed (0 = PR_NOTHING)
        unsigned present = static_cast<unsigned>(edx + 1);
        void* pres_ptr = base + specs->pres_offset;

        switch (specs->pres_size) {
            case sizeof(int):
                *static_cast<int*>(pres_ptr) = static_cast<int>(present);
                break;
            case sizeof(short):
                *static_cast<short*>(pres_ptr) = static_cast<short>(present);
                break;
            default:
                *static_cast<unsigned char*>(pres_ptr) = static_cast<unsigned char>(present);
                break;
        }

        // Allocate and decode the variant value
        void* member_ptr;

        if (elm->flags & ATF_POINTER) {
            size_t member_size = get_struct_size(elm->type);
            if (member_size == 0) {
                ctx.set_error("Unknown struct size for CHOICE variant");
                return false;
            }
            void* allocated = CALLOC(1, member_size);
            if (!allocated) {
                ctx.set_error("Memory allocation failed for CHOICE variant");
                return false;
            }
            *reinterpret_cast<void**>(base + elm->memb_offset) = allocated;
            member_ptr = allocated;
        } else {
            member_ptr = base + elm->memb_offset;
        }

        if (ctx.verbose) {
            ctx.path.push_back(elm->name);
            bool result = decode_any(elm->type, member_ptr, variant_json, ctx);
            return result;
        } else {
            return decode_any(elm->type, member_ptr, variant_json, ctx);
        }
    }

    // Add the unknown variant name to the path for better error reporting
    if (ctx.verbose) {
        ctx.path.push_back(variant_name);
    }
    ctx.set_error("Unknown CHOICE variant");
    return false;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza