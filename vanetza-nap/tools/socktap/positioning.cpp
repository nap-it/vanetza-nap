#include "positioning.hpp"
#include <vanetza/common/stored_position_provider.hpp>

#include "gps_position_provider.hpp"

using namespace vanetza;
namespace po = boost::program_options;

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service& io_service, const po::variables_map& vm, config_t config_s, const Runtime& runtime)
{
    std::unique_ptr<vanetza::PositionProvider> positioning;

    if (!config_s.use_hardcoded_gps) {
        positioning.reset(new GpsPositionProvider {
            io_service, config_s.gpsd_host, config_s.gpsd_port
        });
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

