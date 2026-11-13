#ifndef POSITIONING_HPP_VZRIW7PB
#define POSITIONING_HPP_VZRIW7PB

#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <memory>
#include <mutex>
#include <stdexcept>
#include "config.hpp"

namespace po = boost::program_options;

class PositioningException : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

/**
 * Position provider for positioning=none and positioning=external.
 *
 * It starts without a fix (latitude and longitude infinite, which fillPosition() turns into
 * the ETSI unavailable values). With positioning=none it stays that way. With
 * positioning=external, CamApplication feeds it the reference position of every CAM the
 * station is asked to send for itself; the routers pick it up on their 1 s position refresh.
 *
 * update() runs on the MQTT threads while the routers and the applications read, so the fix
 * is guarded, and each reader gets its own copy rather than a reference into shared state.
 */
class ExternalPositionProvider : public vanetza::PositionProvider
{
public:
    ExternalPositionProvider();
    const vanetza::PositionFix& position_fix() override;
    void update(const vanetza::PositionFix& fix);

private:
    std::mutex mutex_;
    vanetza::PositionFix fix_;
};

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service&, const po::variables_map& vm, config_t config_s, const vanetza::Runtime&);

#endif /* POSITIONING_HPP_VZRIW7PB */
