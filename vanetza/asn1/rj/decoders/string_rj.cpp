// decoders/string_rj.cpp
#include "../jer_rj_decode_types.hpp"

extern "C" {
#include "asn_internal.h"
#include "OCTET_STRING.h"
}

#include <cstring>

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

// Helper to decode hex string to bytes
static bool decode_hex_string(const char* hex, size_t hex_len, uint8_t* out, size_t* out_len) {
    if (hex_len % 2 != 0) return false;

    *out_len = hex_len / 2;

    for (size_t i = 0; i < *out_len; ++i) {
        char high = hex[i * 2];
        char low = hex[i * 2 + 1];

        uint8_t high_val, low_val;

        if (high >= '0' && high <= '9') high_val = high - '0';
        else if (high >= 'A' && high <= 'F') high_val = high - 'A' + 10;
        else if (high >= 'a' && high <= 'f') high_val = high - 'a' + 10;
        else return false;

        if (low >= '0' && low <= '9') low_val = low - '0';
        else if (low >= 'A' && low <= 'F') low_val = low - 'A' + 10;
        else if (low >= 'a' && low <= 'f') low_val = low - 'a' + 10;
        else return false;

        out[i] = (high_val << 4) | low_val;
    }

    return true;
}

bool decode_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    (void)td;

    if (!json.IsString()) {
        ctx.set_error("Expected JSON string for string type");
        return false;
    }

    OCTET_STRING_t* st = static_cast<OCTET_STRING_t*>(struct_ptr);

    const char* str = json.GetString();
    size_t len = json.GetStringLength();

    // Allocate and copy
    if (OCTET_STRING_fromBuf(st, str, static_cast<int>(len)) != 0) {
        ctx.set_error("Failed to set string value");
        return false;
    }

    return true;
}

bool decode_octet_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    (void)td;

    OCTET_STRING_t* st = static_cast<OCTET_STRING_t*>(struct_ptr);

    if (json.IsString()) {
        // Hex-encoded string
        const char* hex = json.GetString();
        size_t hex_len = json.GetStringLength();

        if (hex_len == 0) {
            st->buf = nullptr;
            st->size = 0;
            return true;
        }

        size_t byte_len = hex_len / 2;
        uint8_t* buf = static_cast<uint8_t*>(MALLOC(byte_len));
        if (!buf) {
            ctx.set_error("Memory allocation failed for OCTET STRING");
            return false;
        }

        size_t actual_len;
        if (!decode_hex_string(hex, hex_len, buf, &actual_len)) {
            FREEMEM(buf);
            ctx.set_error("Invalid hex string for OCTET STRING");
            return false;
        }

        st->buf = buf;
        st->size = static_cast<int>(actual_len);
        return true;
    }

    ctx.set_error("Expected JSON string for OCTET STRING");
    return false;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza