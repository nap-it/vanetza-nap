// encoders/sequence_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "constr_SEQUENCE.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_sequence(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    rapidjson::Value obj(rapidjson::kObjectType);

    // Pre-compute base pointer once
    const char* base = static_cast<const char*>(struct_ptr);
    const size_t count = td->elements_count;

    for (size_t edx = 0; edx < count; ++edx) {
        const asn_TYPE_member_t* elm = &td->elements[edx];
        const void* member_ptr;

        if (elm->flags & ATF_POINTER) {
            member_ptr = *reinterpret_cast<const void* const*>(base + elm->memb_offset);
            if (!member_ptr) continue;
        } else {
            member_ptr = base + elm->memb_offset;
        }

        obj.AddMember(
            rapidjson::StringRef(elm->name),
            encode_any(elm->type, member_ptr, ctx),
            ctx.allocator
        );
    }

    return obj;
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza