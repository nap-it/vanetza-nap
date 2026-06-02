// encoders/bitstring_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"
#include "../bitnames/jer_bitnames.hpp"

extern "C" {
#include "BIT_STRING.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

// Helper to check if a bit is set (MSB first ordering)
inline bool is_bit_set(const BIT_STRING_t* bs, uint8_t bit_index) {
    const int byte_idx = bit_index / 8;
    const int bit_idx = 7 - (bit_index % 8);  // MSB first
    if (byte_idx >= static_cast<int>(bs->size)) return false;
    return ((bs->buf[byte_idx] >> bit_idx) & 1) != 0;
}

rapidjson::Value encode_bit_string(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    const BIT_STRING_t* bs = static_cast<const BIT_STRING_t*>(struct_ptr);

    // Check if this type has named bits
    const jer_bitnames_entry* bitnames = jer_find_bitnames(td->name);

    if (bitnames) {
        // Named bits: output as object with boolean fields
        rapidjson::Value obj(rapidjson::kObjectType);

        for (uint8_t i = 0; i < bitnames->count; ++i) {
            bool value = bs->buf && bs->size > 0 && is_bit_set(bs, i);
            obj.AddMember(
                rapidjson::StringRef(bitnames->names[i]),
                rapidjson::Value(value),
                ctx.allocator
            );
        }

        return obj;
    }

    // No named bits - fall back to hex encoding
    if (!bs->buf || bs->size == 0) {
        rapidjson::Value obj(rapidjson::kObjectType);
        obj.AddMember(rapidjson::StringRef("value"), rapidjson::Value("", ctx.allocator), ctx.allocator);
        obj.AddMember(rapidjson::StringRef("length"), 0, ctx.allocator);
        return obj;
    }

    // Check if fixed size (from JER constraints)
    const asn_jer_constraints_t* cts = td->encoding_constraints.jer_constraints;
    bool fixed_size = (cts && cts->size != -1);

    // Convert to hex string
    static constexpr char hex_chars[] = "0123456789ABCDEF";
    const size_t hex_len = bs->size * 2;

    char stack_buf[129];
    char* hex_buf = (hex_len <= 128) ? stack_buf
                                      : static_cast<char*>(ctx.allocator.Malloc(hex_len + 1));

    for (size_t i = 0; i < bs->size - 1; ++i) {
        hex_buf[i * 2]     = hex_chars[(bs->buf[i] >> 4) & 0x0F];
        hex_buf[i * 2 + 1] = hex_chars[bs->buf[i] & 0x0F];
    }

    if (bs->size > 0) {
        uint8_t last_byte = bs->buf[bs->size - 1] & (0xFF << bs->bits_unused);
        size_t last_idx = (bs->size - 1) * 2;
        hex_buf[last_idx]     = hex_chars[(last_byte >> 4) & 0x0F];
        hex_buf[last_idx + 1] = hex_chars[last_byte & 0x0F];
    }
    hex_buf[hex_len] = '\0';

    const rapidjson::SizeType rj_len = static_cast<rapidjson::SizeType>(hex_len);

    if (fixed_size) {
        rapidjson::Value result;
        result.SetString(hex_buf, rj_len, ctx.allocator);
        return result;
    }

    rapidjson::Value obj(rapidjson::kObjectType);
    rapidjson::Value hex_value;
    hex_value.SetString(hex_buf, rj_len, ctx.allocator);
    obj.AddMember(rapidjson::StringRef("value"), hex_value, ctx.allocator);
    obj.AddMember(rapidjson::StringRef("length"),
                  static_cast<int64_t>(bs->size * 8 - bs->bits_unused),
                  ctx.allocator);

    return obj;
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza