// encoders/sequence_of_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "constr_SET_OF.h"
#include "asn_SET_OF.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_sequence_of(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    rapidjson::Value arr(rapidjson::kArrayType);

    // The list is at offset 0 of the struct (the struct IS the list)
    // Use the asn1c macro to cast properly
    const asn_anonymous_set_* list = _A_CSET_FROM_VOID(struct_ptr);

    // Pre-allocate array capacity
    arr.Reserve(static_cast<rapidjson::SizeType>(list->count), ctx.allocator);

    // Element type is the first (and only) element descriptor
    const asn_TYPE_member_t* elm = &td->elements[0];

    // Encode each element
    for (int i = 0; i < list->count; ++i) {
        const void* element_ptr = list->array[i];
        if (element_ptr) {
            rapidjson::Value element_value = encode_any(elm->type, element_ptr, ctx);
            arr.PushBack(element_value, ctx.allocator);
        }
    }

    return arr;
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza