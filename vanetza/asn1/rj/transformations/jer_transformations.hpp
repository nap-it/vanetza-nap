// jer_transformations.hpp
#ifndef VANETZA_ASN1_RJ_JER_TRANSFORMATIONS_HPP
#define VANETZA_ASN1_RJ_JER_TRANSFORMATIONS_HPP

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Transformation entry for a single ASN.1 type.
 * Used to convert raw integer values to human-readable units.
 */
struct jer_transform_entry {
    const char* name;           // ASN.1 type name (e.g., "Latitude")
    double scale;               // Division factor (e.g., 10000000.0)
    int32_t unavailable[4];     // Sentinel values that should NOT be transformed
    uint8_t unavailable_count;  // Number of valid entries in unavailable[] (0-4)
};

/**
 * Look up transformation for an ASN.1 type by name.
 * Uses gperf-generated perfect hash for O(1) lookup.
 *
 * @param name  Type name (e.g., "Latitude")
 * @param len   Length of name string
 * @return      Pointer to transformation entry, or nullptr if no transformation
 */
const jer_transform_entry* jer_find_transform(const char* name, size_t len);

/**
 * Convenience overload that computes string length.
 */
inline const jer_transform_entry* jer_find_transform(const char* name) {
    return jer_find_transform(name, std::strlen(name));
}

/**
 * Check if a value is in the "unavailable" sentinel list.
 * These values should be output as-is, without transformation.
 *
 * Only checks the first `unavailable_count` entries in the array.
 * This means 0 can be a valid (transformable) value as long as it's
 * not in the first `unavailable_count` positions.
 *
 * @param t      Transformation entry (must not be nullptr)
 * @param value  Value to check
 * @return       true if value is an unavailable sentinel
 */
inline bool jer_is_unavailable(const jer_transform_entry* t, int64_t value) {
    for (uint8_t i = 0; i < t->unavailable_count; ++i) {
        if (value == t->unavailable[i]) {
            return true;
        }
    }
    return false;
}

/**
 * Apply transformation to a value.
 * Handles unavailable sentinel check internally.
 *
 * @param t      Transformation entry (if nullptr, returns value as double)
 * @param value  Raw ASN.1 integer value
 * @return       Transformed double, or original value if unavailable/no transform
 */
inline double jer_apply_transform(const jer_transform_entry* t, int64_t value) {
    if (!t || jer_is_unavailable(t, value)) {
        return static_cast<double>(value);
    }
    return static_cast<double>(value) / t->scale;
}

} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_TRANSFORMATIONS_HPP