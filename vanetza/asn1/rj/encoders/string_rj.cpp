// encoders/string_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"

extern "C" {
#include "OCTET_STRING.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

rapidjson::Value encode_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)td;
    const OCTET_STRING_t* str = static_cast<const OCTET_STRING_t*>(struct_ptr);

    if (str->buf && str->size > 0) {
        return rapidjson::Value(
            reinterpret_cast<const char*>(str->buf),
            static_cast<rapidjson::SizeType>(str->size),
            ctx.allocator
        );
    }

    // Empty string - use StringRef to avoid allocation
    return rapidjson::Value(rapidjson::StringRef(""));
}

rapidjson::Value encode_octet_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)td;
    const OCTET_STRING_t* str = static_cast<const OCTET_STRING_t*>(struct_ptr);

    if (!str->buf || str->size == 0) {
        return rapidjson::Value(rapidjson::StringRef(""));
    }

    // Convert to hex string - use stack buffer for small strings
    static constexpr char hex_chars[] = "0123456789ABCDEF";
    const size_t hex_len = str->size * 2;

    // Stack buffer for small octet strings (up to 64 bytes = 128 hex chars)
    char stack_buf[129];
    char* buf;

    if (hex_len <= 128) {
        buf = stack_buf;
    } else {
        buf = static_cast<char*>(ctx.allocator.Malloc(hex_len + 1));
    }

    for (size_t i = 0; i < str->size; ++i) {
        buf[i * 2]     = hex_chars[(str->buf[i] >> 4) & 0x0F];
        buf[i * 2 + 1] = hex_chars[str->buf[i] & 0x0F];
    }
    buf[hex_len] = '\0';

    // SetString will copy from stack_buf, or from heap buf (still copies, but we avoid one alloc for small strings)
    rapidjson::Value result;
    result.SetString(buf, static_cast<rapidjson::SizeType>(hex_len), ctx.allocator);
    return result;
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza