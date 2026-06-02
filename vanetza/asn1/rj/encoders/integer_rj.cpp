// encoders/integer_rj.cpp
#include "../jer_rj_encode_types.hpp"
#include "../jer_rj_context.hpp"
#include "../transformations/jer_transformations.hpp"

extern "C" {
#include "NativeInteger.h"
#include "INTEGER.h"
}

namespace vanetza {
namespace asn1 {
namespace rj {
namespace detail {

// Fast check: only names 6-29 chars could be in gperf table
// This avoids strlen + hash for most types
inline const jer_transform_entry* fast_find_transform(const char* name) {
    // Quick length bounds check before calling gperf
    // gperf table has MIN_WORD_LENGTH=6, MAX_WORD_LENGTH=29
    const char* p = name;
    // Check minimum length (6 chars)
    if (!p[0] || !p[1] || !p[2] || !p[3] || !p[4] || !p[5]) {
        return nullptr;
    }
    // Find length, bail if > 29
    size_t len = 6;
    while (p[len]) {
        if (++len > 29) return nullptr;
    }
    return jer_find_transform(name, len);
}

rapidjson::Value encode_native_integer(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)ctx;
    const long value = *static_cast<const long*>(struct_ptr);

    // Fast gperf lookup with length bounds check
    const jer_transform_entry* transform = fast_find_transform(td->name);

    if (transform) {
        if (!jer_is_unavailable(transform, value)) {
            return rapidjson::Value(static_cast<double>(value) / transform->scale);
        }
    }

    return rapidjson::Value(static_cast<int64_t>(value));
}

rapidjson::Value encode_integer(
    const asn_TYPE_descriptor_t* td,
    const void* struct_ptr,
    EncodeContext& ctx)
{
    (void)ctx;
    const INTEGER_t* st = static_cast<const INTEGER_t*>(struct_ptr);

    long value = 0;
    if (asn_INTEGER2long(st, &value) == 0) {
        const jer_transform_entry* transform = fast_find_transform(td->name);
        if (transform && !jer_is_unavailable(transform, value)) {
            return rapidjson::Value(static_cast<double>(value) / transform->scale);
        }
        return rapidjson::Value(static_cast<int64_t>(value));
    }

    unsigned long uvalue = 0;
    if (asn_INTEGER2ulong(st, &uvalue) == 0) {
        const jer_transform_entry* transform = fast_find_transform(td->name);
        if (transform && !jer_is_unavailable(transform, static_cast<int64_t>(uvalue))) {
            return rapidjson::Value(static_cast<double>(uvalue) / transform->scale);
        }
        return rapidjson::Value(static_cast<uint64_t>(uvalue));
    }

    return rapidjson::Value(static_cast<int64_t>(0));
}

} // namespace detail
} // namespace rj
} // namespace asn1
} // namespace vanetza