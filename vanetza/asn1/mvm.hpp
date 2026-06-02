#ifndef MVM_HPP_RSEIP89V
#define MVM_HPP_RSEIP89V

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/r2/MVM.h>

namespace vanetza
{
namespace asn1
{


namespace r2
{

class Mvm : public asn1c_per_wrapper<Vanetza_ITS2_MVM_t>
{
public:
    Mvm() : asn1c_per_wrapper(asn_DEF_Vanetza_ITS2_MVM) {}
};

} // namespace r2


} // namespace asn1
} // namespace vanetza

#endif /* MVM_HPP_RSEIP89V */
