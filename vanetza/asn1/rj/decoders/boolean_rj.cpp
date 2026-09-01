// decoders/boolean_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "BOOLEAN.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

bool decode_boolean(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    (void)td;

    if (!json.IsBool()) {
        ctx.set_error("Expected JSON boolean for BOOLEAN");
        return false;
    }

    BOOLEAN_t* value_ptr = static_cast<BOOLEAN_t*>(struct_ptr);
    *value_ptr = json.GetBool() ? 1 : 0;

    return true;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza