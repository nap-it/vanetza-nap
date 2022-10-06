#include "application.hpp"
#include "dcc_passthrough.hpp"
#include "ethernet_device.hpp"
#include "router_context.hpp"
#include "time_trigger.hpp"
#include <vanetza/access/ethertype.hpp>
#include <vanetza/dcc/data_request.hpp>
#include <vanetza/dcc/interface.hpp>
#include <iostream>
#include <vanetza/common/byte_order.hpp>
#include <chrono>

using namespace vanetza;
using namespace std::chrono;

DccPassthrough* dccp = nullptr;

RouterContext::RouterContext(const geonet::MIB& mib, TimeTrigger& trigger, vanetza::PositionProvider& positioning, vanetza::security::SecurityEntity* security_entity, bool ignore_own_messages_, bool ignore_rsu_messages_, boost::asio::io_service& io_context) :
    mib_(mib), router_(trigger.runtime(), mib_), positioning_(positioning),
    ignore_own_messages(ignore_own_messages_), ignore_rsu_messages(ignore_rsu_messages_), io_context_(io_context)
{
    router_.packet_dropped = std::bind(&RouterContext::log_packet_drop, this, std::placeholders::_1);
    router_.set_address(mib_.itsGnLocalGnAddr);
    router_.set_transport_handler(geonet::UpperProtocol::BTP_B, &dispatcher_);
    router_.set_security_entity(security_entity);
}

RouterContext::~RouterContext()
{
    for (auto* app : applications_) {
        disable(app);
    }
}

void RouterContext::log_packet_drop(geonet::Router::PacketDropReason reason)
{
    auto reason_string = stringify(reason);
    std::cout << "Router dropped packet because of " << reason_string << " (" << static_cast<int>(reason) << ")\n";
}

void RouterContext::set_link_layer(LinkLayer* link_layer)
{
    namespace dummy = std::placeholders;

    if (link_layer) {

        dccp = new DccPassthrough { *link_layer, io_context_ };
        update_position_vector();
        dccp->get_trigger().schedule();

        request_interface_.reset(dccp);
        router_.set_access_interface(request_interface_.get());
        link_layer->indicate(std::bind(&RouterContext::indicate, this, dummy::_1, dummy::_2));
        update_packet_flow(router_.get_local_position_vector());
    } else {
        router_.set_access_interface(nullptr);
        request_interface_.reset();
    }
}

void RouterContext::indicate(CohesivePacket&& packet, const EthernetHeader& hdr)
{
    if ((!ignore_own_messages || hdr.source != mib_.itsGnLocalGnAddr.mid()) && (!ignore_rsu_messages || ((int) hdr.source.octets[3]) != 0x01) && hdr.type == access::ethertype::GeoNetworking) {
        //std::cout << "received packet from " << hdr.source << " (" << packet.size() << " bytes) \n";
        std::unique_ptr<PacketVariant> up { new PacketVariant(std::move(packet)) };
        dccp->get_trigger().schedule(); // ensure the clock is up-to-date for the security entity
        router_.indicate(std::move(up), hdr.source, hdr.destination);
        dccp->get_trigger().schedule(); // schedule packet forwarding
    }
}

void RouterContext::enable(Application* app)
{
    app->router_ = &router_;

    dispatcher_.add_promiscuous_hook(app->promiscuous_hook());
    if (app->port() != btp::port_type(0)) {
        dispatcher_.set_non_interactive_handler(app->port(), app);
    }
}

void RouterContext::disable(Application* app)
{
    if (app->port() != btp::port_type(0)) {
        dispatcher_.set_non_interactive_handler(app->port(), nullptr);
    }
    dispatcher_.remove_promiscuous_hook(app->promiscuous_hook());

    app->router_ = nullptr;
}

void RouterContext::require_position_fix(bool flag)
{
    require_position_fix_ = flag;
    update_packet_flow(router_.get_local_position_vector());
}

void RouterContext::update_position_vector()
{
    router_.update_position(positioning_.position_fix());
    vanetza::Runtime::Callback callback = [this](vanetza::Clock::time_point) { this->update_position_vector(); };
    vanetza::Clock::duration next = std::chrono::seconds(1);
    dccp->get_trigger().runtime().schedule(next, callback);
    dccp->get_trigger().schedule();

    update_packet_flow(router_.get_local_position_vector());
}

void RouterContext::update_packet_flow(const geonet::LongPositionVector& lpv)
{
    if (request_interface_) {
        if (require_position_fix_) {
            // Skip all requests until a valid GPS position is available
            request_interface_->allow_packet_flow(lpv.position_accuracy_indicator);
        } else {
            request_interface_->allow_packet_flow(true);
        }
    }
}

DccPassthrough &RouterContext::get_dccp() {
    return *(dccp);
}
