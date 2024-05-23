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

void Application::fillPosition(std::string& str, vanetza::PositionProvider& positionProvider) {
    if (str.find('$') != std::string::npos) {
        const vanetza::PositionFix position = positionProvider.position_fix();
        if (size_t pos = str.find("$latitude"); pos != std::string::npos) {
            double latitude = 900000001; 
            if (position.latitude.value() <= 900000000) latitude = position.latitude.value();
            str.replace(pos, std::string("$latitude").length(), std::to_string(latitude));
        }
        if (size_t pos = str.find("$longitude"); pos != std::string::npos) {
            double longitude = 1800000001; 
            if (position.longitude.value() <= 1800000000) longitude = position.longitude.value();
            str.replace(pos, std::string("$longitude").length(), std::to_string(longitude));
        }
        if (size_t pos = str.find("$altitude"); pos != std::string::npos) {
            double altitude = 800001; 
            if (position.altitude.is_initialized() && position.altitude.value().value().value() <= 800000) altitude = position.altitude.value().value().value();
            str.replace(pos, std::string("$altitude").length(), std::to_string(altitude));
        }
        if (size_t pos = str.find("$speed"); pos != std::string::npos) {
            double speed = 16383; 
            if (position.speed.value().value() >= 0 && position.speed.value().value() <= 16382) speed = position.speed.value().value();
            str.replace(pos, std::string("$speed").length(), std::to_string(speed));
        }
        if (size_t pos = str.find("$heading"); pos != std::string::npos) {
            double heading = 3601; 
            if (position.course.value().value() >= 0 && position.course.value().value() <= 3600) heading = position.course.value().value();
            str.replace(pos, std::string("$heading").length(), std::to_string(heading));
        }
        if (size_t pos = str.find("$semiMajorConfidence"); pos != std::string::npos) {
            str.replace(pos, std::string("$semiMajorConfidence").length(), std::to_string((int) position.confidence.semi_major.value()));
        }
        if (size_t pos = str.find("$semiMinorConfidence"); pos != std::string::npos) {
            str.replace(pos, std::string("$semiMinorConfidence").length(), std::to_string((int) position.confidence.semi_minor.value()));
        }
        if (size_t pos = str.find("$orientationConfidence"); pos != std::string::npos) {
            str.replace(pos, std::string("$orientationConfidence").length(), std::to_string((int) position.confidence.orientation.value()));
        }
        if (size_t pos = str.find("$altitudeConfidence"); pos != std::string::npos) {
            double altitudeConfidence = 15; 
            if(position.altitude.is_initialized()) altitudeConfidence = position.altitude.value().confidence().value();
            str.replace(pos, std::string("$altitudeConfidence").length(), std::to_string((int) altitudeConfidence));
        }
        if (size_t pos = str.find("$speedConfidence"); pos != std::string::npos) {
            double speedConfidence = 127; 
            if (position.speed.confidence().value() >= 0 && position.speed.confidence().value() <= 125) speedConfidence = position.speed.confidence().value();
            str.replace(pos, std::string("$speedConfidence").length(), std::to_string((int) speedConfidence));
        }
        if (size_t pos = str.find("$headingConfidence"); pos != std::string::npos) {
            double headingConfidence = 127; 
            if (position.course.confidence().value() >= 0 && position.course.confidence().value() <= 125) headingConfidence = position.course.confidence().value();
            str.replace(pos, std::string("$headingConfidence").length(), std::to_string((int) headingConfidence));
        }
    }
}