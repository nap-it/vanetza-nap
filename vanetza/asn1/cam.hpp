#ifndef CAM_HPP_WXYNEKFN
#define CAM_HPP_WXYNEKFN

#include <vanetza/asn1/asn1c_conversion.hpp>
#include <vanetza/asn1/asn1c_wrapper.hpp>
#include <vanetza/asn1/its/CAM.h>
#include <vanetza/asn1/its/r2/CAM.h>
#include <vanetza/asn1/its/r2/LowFrequencyContainer.h>
#include <vanetza/asn1/its/r2/BasicVehicleContainerLowFrequency.h>

namespace vanetza
{
namespace asn1
{

namespace r1
{

class Cam : public asn1c_per_wrapper<CAM_t>
{
public:
    using wrapper = asn1c_per_wrapper<CAM_t>;
    Cam() : wrapper(asn_DEF_CAM) {}
};

} // namespace r1

namespace r2
{

class Cam : public asn1c_per_wrapper<Vanetza_ITS2_CAM_t>
{
public:
    using wrapper = asn1c_per_wrapper<Vanetza_ITS2_CAM_t>;
    Cam() : wrapper(asn_DEF_Vanetza_ITS2_CAM) {}
};

/**
 * RAII guard to temporarily swap the BasicVehicleContainerLowFrequency type descriptor
 * in LowFrequencyContainer to use the compact (6-bit) variant for decoding.
 *
 * This allows decoding CAMs from VW-style encoders that use R1's pathHistory
 * SIZE(0..40) = 6 bits even when protocolVersion=2.
 */
class CompactR2DecodeGuard
{
public:
    CompactR2DecodeGuard()
    {
        // Save original type descriptor pointer
        original_type_descriptor_ = asn_MBR_Vanetza_ITS2_LowFrequencyContainer_1[0].type;
        // Swap to compact variant (6-bit pathHistory)
        asn_MBR_Vanetza_ITS2_LowFrequencyContainer_1[0].type =
            &asn_DEF_Vanetza_ITS2_BasicVehicleContainerLowFrequency_Compact;
    }

    ~CompactR2DecodeGuard()
    {
        // Restore original type descriptor
        asn_MBR_Vanetza_ITS2_LowFrequencyContainer_1[0].type = original_type_descriptor_;
    }

    // Non-copyable
    CompactR2DecodeGuard(const CompactR2DecodeGuard&) = delete;
    CompactR2DecodeGuard& operator=(const CompactR2DecodeGuard&) = delete;

private:
    asn_TYPE_descriptor_t* original_type_descriptor_;
};

} // namespace r2

// alias for backward compatibility
using Cam = r1::Cam;

} // namespace asn1
} // namespace vanetza

#endif /* CAM_HPP_WXYNEKFN */
