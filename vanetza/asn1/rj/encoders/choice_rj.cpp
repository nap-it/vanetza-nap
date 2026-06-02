// encoders/choice_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "constr_CHOICE.h"
#include "asn_internal.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_choice(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    rapidjson::Value obj(rapidjson::kObjectType);

    const asn_CHOICE_specifics_t* specs =
        static_cast<const asn_CHOICE_specifics_t*>(td->specifics);

    // Get the "present" discriminator
    unsigned present = 0;
    const void* pres_ptr = static_cast<const char*>(struct_ptr) + specs->pres_offset;

    switch (specs->pres_size) {
        case sizeof(int):
            present = *static_cast<const int*>(pres_ptr);
            break;
        case sizeof(short):
            present = *static_cast<const short*>(pres_ptr);
            break;
        default:
            present = *static_cast<const unsigned char*>(pres_ptr);
            break;
    }

    // present == 0 means PR_NOTHING (no selection)
    if (present == 0 || present > td->elements_count) {
        return obj;  // Return empty object
    }

    // Get the selected element (present is 1-indexed)
    const asn_TYPE_member_t* elm = &td->elements[present - 1];

    // Get pointer to the choice value
    const void* member_ptr;
    if (elm->flags & ATF_POINTER) {
        member_ptr = *reinterpret_cast<const void* const*>(
            static_cast<const char*>(struct_ptr) + elm->memb_offset
        );
        if (member_ptr == nullptr) {
            return obj;
        }
    } else {
        member_ptr = static_cast<const char*>(struct_ptr) + elm->memb_offset;
    }

    // Encode the selected variant
    rapidjson::Value member_value = encode_any(elm->type, member_ptr, ctx);

    // Add with variant name as key (StringRef for ZERO-COPY)
    obj.AddMember(
        rapidjson::StringRef(elm->name),
        member_value,
        ctx.allocator
    );

    return obj;
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza