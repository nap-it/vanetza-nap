// decoders/integer_rj.cpp
#include "../jer_rj_decode_types.hpp"
#include "../transformations/jer_transformations.hpp"

extern "C" {
#include "NativeInteger.h"
#include "INTEGER.h"
}

#include <cmath>

namespace vanetza {
namespace asn1 {
namespace rj {
namespace decode {

// Fast transform lookup (same as encoder)
inline const jer_transform_entry* fast_find_transform(const char* name) {
    const char* p = name;
    if (!p[0] || !p[1] || !p[2] || !p[3] || !p[4] || !p[5]) {
        return nullptr;
    }
    size_t len = 6;
    while (p[len]) {
        if (++len > 29) return nullptr;
    }
    return jer_find_transform(name, len);
}

bool decode_native_integer(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    long* value_ptr = static_cast<long*>(struct_ptr);

    // Check for transform - determines how to interpret the value
    const jer_transform_entry* transform = fast_find_transform(td->name);

    if (json.IsDouble()) {
        // Floating point value - always needs reverse transformation
        double json_value = json.GetDouble();
        if (transform) {
            *value_ptr = static_cast<long>(std::round(json_value * transform->scale));
        } else {
            *value_ptr = static_cast<long>(std::round(json_value));
        }
        return true;
    }

    if (json.IsInt64()) {
        int64_t int_value = json.GetInt64();

        if (transform) {
            // Type has a transform - check if this is a sentinel value
            // Sentinels are output as-is by the encoder (as integers)
            // Non-sentinels were output as doubles, but RapidJSON may parse
            // whole numbers like "0.0" as integers
            if (jer_is_unavailable(transform, int_value)) {
                // It's a sentinel - use as-is
                *value_ptr = static_cast<long>(int_value);
            } else {
                // Not a sentinel - apply reverse transformation
                *value_ptr = static_cast<long>(std::round(static_cast<double>(int_value) * transform->scale));
            }
        } else {
            // No transform - use as-is
            *value_ptr = static_cast<long>(int_value);
        }
        return true;
    }

    if (json.IsUint64()) {
        *value_ptr = static_cast<long>(json.GetUint64());
        return true;
    }

    ctx.set_error("Expected number for NativeInteger");
    return false;
}

bool decode_integer(
    const asn_TYPE_descriptor_t* td,
    void* struct_ptr,
    const rapidjson::Value& json,
    DecodeContext& ctx)
{
    INTEGER_t* st = static_cast<INTEGER_t*>(struct_ptr);

    // Check for transform
    const jer_transform_entry* transform = fast_find_transform(td->name);

    long value = 0;

    if (json.IsDouble()) {
        // Floating point - apply reverse transformation
        double json_value = json.GetDouble();
        if (transform) {
            value = static_cast<long>(std::round(json_value * transform->scale));
        } else {
            value = static_cast<long>(std::round(json_value));
        }
    } else if (json.IsInt64()) {
        int64_t int_value = json.GetInt64();

        if (transform) {
            // Check if this is a sentinel value
            if (jer_is_unavailable(transform, int_value)) {
                value = static_cast<long>(int_value);
            } else {
                // Apply reverse transformation
                value = static_cast<long>(std::round(static_cast<double>(int_value) * transform->scale));
            }
        } else {
            value = static_cast<long>(int_value);
        }
    } else if (json.IsUint64()) {
        // Handle as unsigned
        unsigned long uvalue = json.GetUint64();
        if (asn_ulong2INTEGER(st, uvalue) != 0) {
            ctx.set_error("Failed to set unsigned INTEGER value");
            return false;
        }
        return true;
    } else {
        ctx.set_error("Expected number for INTEGER");
        return false;
    }

    if (asn_long2INTEGER(st, value) != 0) {
        ctx.set_error("Failed to set INTEGER value");
        return false;
    }

    return true;
}

} // namespace decode
} // namespace rj
} // namespace asn1
} // namespace vanetza