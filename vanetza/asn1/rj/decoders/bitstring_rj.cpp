// decoders/bitstring_rj.cpp
#include "../jer_rj_decode_types.hpp"
#include "../bitnames/jer_bitnames.hpp"
#include <bits/stdint-uintn.h>
#include <cstddef>
#include <sys/types.h>

extern "C" {
#include "asn_internal.h"
#include "BIT_STRING.h"
}

#include <cstring>

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

// Helper to set a bit (MSB first ordering)
inline void set_bit(BIT_STRING_t* bs, uint8_t bit_index, bool value) {
    const int byte_idx = bit_index / 8;
    const int bit_idx = 7 - (bit_index % 8);  // MSB first

    if (byte_idx >= static_cast<int>(bs->size)) return;

    if (value) {
        bs->buf[byte_idx] |= (1 << bit_idx);
    } else {
        bs->buf[byte_idx] &= ~(1 << bit_idx);
    }
}

// Helper to decode hex string
static bool decode_hex_to_bits(const char* hex, size_t hex_len, uint8_t* out, size_t* byte_len) {
    if (hex_len % 2 != 0) return false;

    *byte_len = hex_len / 2;

    for (size_t i = 0; i < *byte_len; ++i) {
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

bool decode_bit_string(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    BIT_STRING_t* bs = static_cast<BIT_STRING_t*>(struct_ptr);

    // Check if this type has named bits
    const jer_bitnames_entry* bitnames = jer_find_bitnames(td->name);

    if (bitnames && json.IsObject()) {
        // Named bits format: {"bit0": true, "bit1": false, ...}

        // Calculate required bytes
        uint8_t total_bits = bitnames->count;
        size_t byte_count = (total_bits + 7) / 8;

        bs->buf = static_cast<uint8_t*>(CALLOC(1, byte_count));
        if (!bs->buf) {
            ctx.set_error("Memory allocation failed for BIT STRING");
            return false;
        }
        bs->size = static_cast<int>(byte_count);
        bs->bits_unused = static_cast<int>((byte_count * 8) - total_bits);

        // Set bits based on boolean fields
        for (uint8_t i = 0; i < bitnames->count; ++i) {
            auto it = json.FindMember(bitnames->names[i]);
            if (it != json.MemberEnd() && it->value.IsBool()) {
                set_bit(bs, i, it->value.GetBool());
            }
        }

        return true;
    }

    // Hex format: {"value": "C0", "length": 7} or just "C0" for fixed size
    if (json.IsString()) {
        // Fixed size - just hex string
        const char* hex = json.GetString();
        size_t hex_len = json.GetStringLength();

        if (hex_len == 0) {
            bs->buf = nullptr;
            bs->size = 0;
            bs->bits_unused = 0;
            return true;
        }

		// Check for JER contraints for fixed-size BIT STRING
		const asn_jer_constraints_t* constraints = td->encoding_constraints.jer_constraints;
		if (constraints && constraints->size > 0) {
			// Fixed size BIT STRING with known bit count
			size_t required_bits = static_cast<size_t>(constraints->size);
			size_t required_bytes = (required_bits + 7) / 8;

			bs->buf = static_cast<uint8_t*>(CALLOC(1, required_bytes));
			if (!bs->buf) {
				ctx.set_error("Memory allocation failed for BIT STRING");
				return false;
			}

			size_t input_bytes = hex_len / 2;
			uint8_t temp_buf[16];
			if (input_bytes > sizeof(temp_buf)) {
				FREEMEM(bs->buf);
				bs->buf = nullptr;
				ctx.set_error("Input hex string too long for BIT STRING constraints");
				return false;
			}

			size_t actual_len;
			if (!decode_hex_to_bits(hex, hex_len, temp_buf, &actual_len)) {
				FREEMEM(bs->buf);
				bs->buf = nullptr;
				ctx.set_error("Invalid hex string for BIT STRING");
				return false;
			}

			size_t copy_bytes = (actual_len < required_bytes) ? actual_len : required_bytes;
			memcpy(bs->buf, temp_buf, copy_bytes);
			bs->size = static_cast<int>(required_bytes);
			bs->bits_unused = static_cast<int>((required_bytes * 8) - required_bits);
			return true;
		}

        size_t byte_len = hex_len / 2;
        bs->buf = static_cast<uint8_t*>(MALLOC(byte_len));
        if (!bs->buf) {
            ctx.set_error("Memory allocation failed for BIT STRING");
            return false;
        }

        size_t actual_len;
        if (!decode_hex_to_bits(hex, hex_len, bs->buf, &actual_len)) {
            FREEMEM(bs->buf);
            bs->buf = nullptr;
            ctx.set_error("Invalid hex string for BIT STRING");
            return false;
        }

        bs->size = static_cast<int>(actual_len);
        bs->bits_unused = 0;  // Fixed size - all bits used
        return true;
    }

    if (json.IsObject()) {
        // Variable size: {"value": "C0", "length": 7}
        auto value_it = json.FindMember("value");
        auto length_it = json.FindMember("length");

        if (value_it == json.MemberEnd() || !value_it->value.IsString()) {
            ctx.set_error("BIT STRING object must have 'value' string field");
            return false;
        }

        const char* hex = value_it->value.GetString();
        size_t hex_len = value_it->value.GetStringLength();

        int64_t bit_length = 0;
        if (length_it != json.MemberEnd() && length_it->value.IsInt64()) {
            bit_length = length_it->value.GetInt64();
        } else {
            bit_length = static_cast<int64_t>(hex_len * 4);  // Default: all bits
        }

        if (hex_len == 0 || bit_length == 0) {
            bs->buf = nullptr;
            bs->size = 0;
            bs->bits_unused = 0;
            return true;
        }

        size_t byte_len = hex_len / 2;
        bs->buf = static_cast<uint8_t*>(MALLOC(byte_len));
        if (!bs->buf) {
            ctx.set_error("Memory allocation failed for BIT STRING");
            return false;
        }

        size_t actual_len;
        if (!decode_hex_to_bits(hex, hex_len, bs->buf, &actual_len)) {
            FREEMEM(bs->buf);
            bs->buf = nullptr;
            ctx.set_error("Invalid hex string for BIT STRING");
            return false;
        }

        bs->size = static_cast<int>(actual_len);
        bs->bits_unused = static_cast<int>((actual_len * 8) - bit_length);
        return true;
    }

    ctx.set_error("Expected JSON object or string for BIT STRING");
    return false;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza
