#ifndef PMM_HPP_RSEIP89V
#define PMM_HPP_RSEIP89V

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/r2/PMM.h>

namespace vanetza
{
namespace asn1
{


namespace r2
{

class Pmm : public asn1c_per_wrapper<Vanetza_ITS2_PMM_t>
{
public:
    Pmm() : asn1c_per_wrapper(asn_DEF_Vanetza_ITS2_PMM) {}
};

} // namespace r2


} // namespace asn1
} // namespace vanetza

#endif /* PMM_HPP_RSEIP89V */
