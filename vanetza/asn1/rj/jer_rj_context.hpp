// jer_rj_context.hpp
#ifndef VANETZA_ASN1_RJ_JER_RJ_CONTEXT_HPP
#define VANETZA_ASN1_RJ_JER_RJ_CONTEXT_HPP

#include <rapidjson/document.h>

namespace vanetza {
namespace asn1 {
namespace rj {

/**
 * Context passed through recursive encoding.
 * Wraps the RapidJSON allocator needed for all Value operations.
 */
struct EncodeContext {
    rapidjson::Document::AllocatorType& allocator;

    explicit EncodeContext(rapidjson::Document::AllocatorType& alloc)
        : allocator(alloc) {}
};

} // namespace rj
} // namespace asn1
} // namespace vanetza

#endif // VANETZA_ASN1_RJ_JER_RJ_CONTEXT_HPP