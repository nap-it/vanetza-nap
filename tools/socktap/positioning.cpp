#include "positioning.hpp"
#include <vanetza/common/stored_position_provider.hpp>

#ifdef SOCKTAP_WITH_GPSD
#   include "gps_position_provider.hpp"
#endif

using namespace vanetza;
namespace po = boost::program_options;

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service& io_service, config_t config_s, const Runtime& runtime)
{
    std::unique_ptr<vanetza::PositionProvider> positioning;

    if (!config_s.use_hardcoded_gps) {
#ifdef SOCKTAP_WITH_GPSD
        positioning.reset(new GpsPositionProvider {
            io_service, vm["gpsd-host"].as<std::string>(), vm["gpsd-port"].as<std::string>()
        });
#endif
    } else {
        std::unique_ptr<StoredPositionProvider> stored { new StoredPositionProvider() };
        PositionFix fix;
        fix.timestamp = runtime.now();
        fix.latitude = config_s.latitude * units::degree;
        fix.longitude = config_s.longitude * units::degree;
        fix.confidence.semi_major = 1 * units::si::meter; // TODO
        fix.confidence.semi_minor = fix.confidence.semi_major;
        stored->position_fix(fix);
        positioning = std::move(stored);
    }

    return positioning;
}

