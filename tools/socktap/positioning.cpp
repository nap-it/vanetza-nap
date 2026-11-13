#include "positioning.hpp"
#include <vanetza/common/stored_position_provider.hpp>
#include <iostream>
#include <limits>

#ifdef SOCKTAP_WITH_GPSD
#   include "gps_position_provider.hpp"
#endif

using namespace vanetza;
namespace po = boost::program_options;

ExternalPositionProvider::ExternalPositionProvider()
{
    fix_.latitude = units::GeoAngle::from_value(std::numeric_limits<units::GeoAngle::value_type>::infinity());
    fix_.longitude = units::GeoAngle::from_value(std::numeric_limits<units::GeoAngle::value_type>::infinity());
}

const PositionFix& ExternalPositionProvider::position_fix()
{
    thread_local PositionFix snapshot;
    std::lock_guard<std::mutex> lock(mutex_);
    snapshot = fix_;
    return snapshot;
}

void ExternalPositionProvider::update(const PositionFix& fix)
{
    std::lock_guard<std::mutex> lock(mutex_);
    fix_ = fix;
}

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service& io_service, const po::variables_map& vm, config_t config_s, const Runtime& runtime)
{
    std::unique_ptr<vanetza::PositionProvider> positioning;

    if (config_s.positioning == "gpsd") {
#ifdef SOCKTAP_WITH_GPSD
        positioning.reset(new GpsPositionProvider {
            io_service, config_s.gpsd_host, config_s.gpsd_port
        });
#else
        throw PositioningException("positioning=gpsd, but this socktap was built without gpsd support");
#endif
    } else if (config_s.positioning == "static") {
        std::unique_ptr<StoredPositionProvider> stored { new StoredPositionProvider() };
        PositionFix fix;
        fix.timestamp = runtime.now();
        fix.latitude = config_s.latitude * units::degree;
        fix.longitude = config_s.longitude * units::degree;
        fix.confidence.semi_major = 1 * units::si::meter; // TODO
        fix.confidence.semi_minor = fix.confidence.semi_major;
        stored->position_fix(fix);
        positioning = std::move(stored);
    } else if (config_s.positioning == "none" || config_s.positioning == "external") {
        positioning.reset(new ExternalPositionProvider());
    } else {
        throw PositioningException("unknown positioning '" + config_s.positioning +
            "'; expected gpsd, static, none or external");
    }
    std::cout << "Positioning: " << config_s.positioning << std::endl;

    return positioning;
}
