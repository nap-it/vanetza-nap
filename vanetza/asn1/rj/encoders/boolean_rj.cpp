// encoders/boolean_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "BOOLEAN.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_boolean(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)td;
    (void)ctx;
    const BOOLEAN_t* value_ptr = static_cast<const BOOLEAN_t*>(struct_ptr);
    return rapidjson::Value(*value_ptr != 0);
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza