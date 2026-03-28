#ifndef TISTPGM_HPP_D5N8Q2JO
#define TISTPGM_HPP_D5N8Q2JO

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/TisTpgTransactionsPdu.h>

namespace vanetza
{
namespace asn1
{

class Tistpgm : public asn1c_per_wrapper<TisTpgTransactionsPdu_t>
{
public:
    using wrapper = asn1c_per_wrapper<TisTpgTransactionsPdu_t>;
    Tistpgm() : wrapper(asn_DEF_TisTpgTransactionsPdu) {}
};

} // namespace asn1
} // namespace vanetza

#endif // TISTPGM_HPP_D5N8Q2JO
