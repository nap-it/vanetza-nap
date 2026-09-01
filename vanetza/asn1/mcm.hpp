#ifndef MCM_HPP_XGC8NRDI
#define MCM_HPP_XGC8NRDI

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/r2/MCM.h>

namespace vanetza
{
namespace asn1
{

class Mcm : public asn1c_per_wrapper<Vanetza_ITS2_MCM_t>
{
public:
    using wrapper = asn1c_per_wrapper<Vanetza_ITS2_MCM_t>;
    Mcm() : wrapper(asn_DEF_Vanetza_ITS2_MCM) {}
};


} // namespace asn1
} // namespace vanetza

#endif /* DENM_HPP_XGC8NRDI */
