// decoders/enumerated_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "NativeEnumerated.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

bool decode_enumerated(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    (void)td;

    if (!json.IsInt64() && !json.IsUint64()) {
        ctx.set_error("Expected JSON integer for ENUMERATED");
        return false;
    }

    long* value_ptr = static_cast<long*>(struct_ptr);
    *value_ptr = json.IsInt64() ? json.GetInt64() : static_cast<long>(json.GetUint64());

    return true;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza