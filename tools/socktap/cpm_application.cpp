#include "cpm_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;

CpmApplication::CpmApplication(PositionProvider& positioning, Runtime& rt, Mqtt *mqtt_) :
    positioning_(positioning), runtime_(rt), cpm_interval_(seconds(1))
{
    mqtt = mqtt_;
    //persistence = {};
    //schedule_timer();
    mqtt->subscribe("target/cpm", this);
}

void CpmApplication::set_interval(Clock::duration interval)
{
    cpm_interval_ = interval;
    runtime_.cancel(this);
    //schedule_timer();
}

void CpmApplication::print_generated_message(bool flag)
{
    print_tx_msg_ = flag;
}

void CpmApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

CpmApplication::PortType CpmApplication::port()
{
    return btp::ports::CPM;
}

void CpmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    asn1::PacketVisitor<asn1::Cpm> visitor;
    std::shared_ptr<const asn1::Cpm> cpm = boost::apply_visitor(visitor, *packet);

    std::cout << "CPM application received a packet with " << (cpm ? "decodable" : "broken") << " content" << std::endl;
    mqtt->publish("vanetza/cpm", buildJSON(*cpm));
    
}

void CpmApplication::schedule_timer()
{
    runtime_.schedule(cpm_interval_, std::bind(&CpmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CpmApplication::buildJSON(vanetza::asn1::Cpm message) {
    ItsPduHeader_t& header = message->header;
    CollectivePerceptionMessage_t & cpm = message->cpm;
    CpmManagementContainer_t & mgc = cpm.cpmParameters.managementContainer;

    nlohmann::json j = message->cpm;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", -255},
            {"test", {
                    {"json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
                },
            },
            {"fields", j},
            {"stationID", (long) header.stationID},
            {"receiverID", 1},
            {"receiverType", 15}
    };
    std::cout << "CPM JSON: " << j << std::endl;

    return json_payload.dump();
}

void CpmApplication::on_message(string mqtt_message) {
    json payload = json::parse(mqtt_message);
    CollectivePerceptionMessage_t cpm = payload.get<CollectivePerceptionMessage_t>();

    vanetza::asn1::Cpm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 1;
    header.messageID = ItsPduHeader__messageID_cpm;
    header.stationID = 1; // TODO

    message->cpm = cpm;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        auto confirm = Application::request(request, std::move(packet));
        if (!confirm.accepted()) {
            throw std::runtime_error("CPM application data request failed");
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
    }
}

void CpmApplication::on_timer(Clock::time_point)
{

}
