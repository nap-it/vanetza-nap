#ifndef EVRSR_HPP_G458S63A
#define EVRSR_HPP_G458S63A

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/EV-RSR.h>

namespace vanetza
{
namespace asn1
{

class Evrsrm : public asn1c_per_wrapper<EV_RSR_t>
{
public:
    using wrapper = asn1c_per_wrapper<EV_RSR_t>;
    Evrsrm() : wrapper(asn_DEF_EV_RSR) {}
};

} // namespace asn1
} // namespace vanetza

#endif // EVRSR_HPP_G458S63A
