// jer_bitnames.hpp
#ifndef VANETZA_ASN1_RJ_JER_BITNAMES_HPP
#define VANETZA_ASN1_RJ_JER_BITNAMES_HPP

#include <cstdint>
#include <cstddef>

namespace vanetza {
namespace asn1 {
namespace rj {

// Simplified structure: bit names are sequential (index 0, 1, 2, ...)
struct jer_bitnames_entry {
    const char* type_name;
    const char* const* names;  // array of bit names, index = bit position
    uint8_t count;
};

// Lookup bit names for a BIT STRING type
// Returns nullptr if type has no named bits
const jer_bitnames_entry* jer_find_bitnames(const char* type_name);

} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_BITNAMES_HPP
