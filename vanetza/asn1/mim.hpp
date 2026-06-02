#ifndef MIM_HPP_RSEIP89V
#define MIM_HPP_RSEIP89V

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/r2/MIM.h>

namespace vanetza
{
namespace asn1
{


namespace r2
{

class Mim : public asn1c_per_wrapper<Vanetza_ITS2_MIM_t>
{
public:
    Mim() : asn1c_per_wrapper(asn_DEF_Vanetza_ITS2_MIM) {}
};

} // namespace r2


} // namespace asn1
} // namespace vanetza

#endif /* MIM_HPP_RSEIP89V */
