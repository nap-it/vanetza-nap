#include "application.hpp"
#include <vanetza/btp/header.hpp>
#include <vanetza/btp/header_conversion.hpp>
#include <cassert>

using namespace vanetza;

void initialize_request(const Application::DataRequest& generic, geonet::DataRequest& geonet)
{
    geonet.upper_protocol = geonet::UpperProtocol::BTP_B;
    geonet.communication_profile = generic.communication_profile;
    geonet.its_aid = generic.its_aid;
    if (generic.maximum_lifetime) {
        geonet.maximum_lifetime = generic.maximum_lifetime.get();
    }
    geonet.repetition = generic.repetition;
    geonet.traffic_class = generic.traffic_class;
}

static geonet::GbcDataRequest request_gbc(const vanetza::btp::DataRequestGeoNetParams& generic, vanetza::geonet::Router* router)
{
    assert(router);
    geonet::GbcDataRequest gbc(router->get_mib());
    initialize_request(generic, gbc);
    gbc.destination = boost::get<geonet::Area>(generic.destination);
    return gbc;
}

static geonet::ShbDataRequest request_shb(const vanetza::btp::DataRequestGeoNetParams& generic, vanetza::geonet::Router* router)
{
    assert(router);
    geonet::ShbDataRequest shb(router->get_mib());
    initialize_request(generic, shb);
    return shb;
}

Application::PromiscuousHook* Application::promiscuous_hook()
{
    return nullptr;
}

bool Application::request(const DataRequest& request, DownPacketPtr packet, std::string* mqtt_message, vanetza::geonet::Router* router)
{
    btp::HeaderB btp_header;
    btp_header.destination_port = this->port();
    btp_header.destination_port_info = host_cast<uint16_t>(0);
    packet->layer(OsiLayer::Transport) = btp_header;
    vanetza::geonet::DataConfirm confirm(vanetza::geonet::DataConfirm::ResultCode::Rejected_Unspecified);
    try {
        if (router && packet) {
            switch (request.transport_type) {
                case geonet::TransportType::SHB:
                    confirm = router->request(request_shb(request, router), std::move(packet));
                    break;
                case geonet::TransportType::GBC:
                    confirm = router->request(request_gbc(request, router), std::move(packet));
                    break;
                default:
                    // TODO remaining transport types are not implemented
                    break;
            }
        }
        if (confirm.accepted()) {
            return true;
        } else {
            std::cout << "Application data request failed. Reason: " << static_cast<std::underlying_type<vanetza::geonet::DataConfirm::ResultCode>::type>(confirm.result_code) << std::endl;
            return false;
        }
    } catch(std::runtime_error& e) {
        std::cout << "--- Vanetza UPER Encoding Error ---\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        if (mqtt_message != nullptr) std::cout << "Invalid payload: " << *(mqtt_message) << std::endl;
        return false;
    } catch(...) {
        std::cout << "--- Unexpected Error ---\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
        if (mqtt_message != nullptr) std::cout << "Invalid payload: " << *(mqtt_message) << std::endl;
        return false;
    }
}
