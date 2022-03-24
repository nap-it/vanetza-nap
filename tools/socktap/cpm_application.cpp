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

Mqtt *mqtt_cpm;

CpmApplication::CpmApplication(PositionProvider& positioning, Runtime& rt) :
    positioning_(positioning), runtime_(rt), cpm_interval_(seconds(1))
{
    vector<string> subscription_topic_list;
    //mqtt_cpm = new Mqtt("pc-client2", "vanetza/cpm", subscription_topic_list, "127.0.0.1", 1883);
    schedule_timer();
}

void CpmApplication::set_interval(Clock::duration interval)
{
    cpm_interval_ = interval;
    runtime_.cancel(this);
    schedule_timer();
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
    //mqtt_cpm->publish(buildJSON(*cpm));
    std::cout << buildJSON(*cpm) <<std::endl;
}

void CpmApplication::schedule_timer()
{
    runtime_.schedule(cpm_interval_, std::bind(&CpmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CpmApplication::buildJSON(vanetza::asn1::Cpm message) {
    ItsPduHeader_t& header = message->header;
    CollectivePerceptionMessage_t & cpm = message->cpm;
    CpmManagementContainer_t & mgc = cpm.cpmParameters.managementContainer;
    ReferencePosition_t & rfp = mgc.referencePosition;
    // //json j = denm;
    // //std::cout << "DENM JSON: " << j << std::endl;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", -255},
            {"test", {
                {"json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
            }
            },
            {"stationID", (long) header.stationID},
            {"stationType", (long) mgc.stationType},
            {"latitude", (long) rfp.latitude},
            {"longitude", (long) rfp.longitude},
    };
    return json_payload.dump();
}

void CpmApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cpm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cpm;
    header.stationID = 99;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();
    message->cpm.generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();

    CpmManagementContainer_t& management = message->cpm.cpmParameters.managementContainer;
    management.stationType = StationType_passengerCar;
    copy(position, management.referencePosition);

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::DEN;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    auto confirm = Application::request(request, std::move(packet));
    if (!confirm.accepted()) {
        throw std::runtime_error("CPM application data request failed");
    }

}
