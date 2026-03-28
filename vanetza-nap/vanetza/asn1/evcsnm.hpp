#ifndef EVCSN_HPP_G458S63A
#define EVCSN_HPP_G458S63A

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/EvcsnPdu.h>

namespace vanetza
{
namespace asn1
{

class Evcsnm : public asn1c_per_wrapper<EvcsnPdu_t>
{
public:
    using wrapper = asn1c_per_wrapper<EvcsnPdu_t>;
    Evcsnm() : wrapper(asn_DEF_EvcsnPdu) {}
};

} // namespace asn1
} // namespace vanetza

#endif // EVCSN_HPP_G458S63A
