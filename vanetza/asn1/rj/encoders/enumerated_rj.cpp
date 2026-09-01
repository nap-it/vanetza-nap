// encoders/enumerated_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "NativeEnumerated.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_enumerated(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)td;
    (void)ctx;
    const long* value_ptr = static_cast<const long*>(struct_ptr);
    return rapidjson::Value(static_cast<int64_t>(*value_ptr));
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza