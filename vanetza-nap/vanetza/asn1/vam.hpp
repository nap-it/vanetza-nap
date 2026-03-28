#ifndef VAM_HPP_XAA1ARFI
#define VAM_HPP_XAA1ARFI

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/VAM.h>

namespace vanetza
{
namespace asn1
{

class Vam : public asn1c_per_wrapper<VAM_t>
{
public:
    using wrapper = asn1c_per_wrapper<VAM_t>;
    Vam() : wrapper(asn_DEF_VAM) {}
};

} // namespace asn1
} // namespace vanetza

#endif //VAM_HPP_XAA1ARFI