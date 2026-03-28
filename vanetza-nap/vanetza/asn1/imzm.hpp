#ifndef IMZM_HPP_D5N8Q2JO
#define IMZM_HPP_D5N8Q2JO

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/IMZM.h>

namespace vanetza
{
namespace asn1
{

class Imzm : public asn1c_per_wrapper<IMZM_t>
{
public:
    using wrapper = asn1c_per_wrapper<IMZM_t>;
    Imzm() : wrapper(asn_DEF_IMZM) {}
};

} // namespace asn1
} // namespace vanetza

#endif // IMZM_HPP_D5N8Q2JO
