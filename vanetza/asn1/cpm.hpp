#ifndef CPM_HPP_WEWZK69S
#define CPM_HPP_WEWZK69S

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/CollectivePerceptionMessage.h>

namespace vanetza
{
namespace asn1
{

class Cpm : public asn1c_per_wrapper<CollectivePerceptionMessage_t>
{
public:
    using wrapper = asn1c_per_wrapper<CollectivePerceptionMessage_t>;
    Cpm() : asn1c_per_wrapper(asn_DEF_CollectivePerceptionMessage) {}
};

} // namespace asn1
} // namespace vanetza

#endif /* CPM_HPP_WEWZK69S */

