#ifndef MCM_HPP_XAA1ARFI
#define MCM_HPP_XAA1ARFI

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/MCM.h>

namespace vanetza
{
namespace asn1
{

class Mcm : public asn1c_per_wrapper<MCM_t>
{
public:
    using wrapper = asn1c_per_wrapper<MCM_t>;
    Mcm() : wrapper(asn_DEF_MCM) {}
};

} // namespace asn1
} // namespace vanetza

#endif //MCM_HPP_XAA1ARFI