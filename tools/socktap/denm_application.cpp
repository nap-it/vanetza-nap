#include "denm_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.

using namespace vanetza;
//using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;


DenmApplication::DenmApplication(PositionProvider& positioning, Runtime& rt) :
    positioning_(positioning), runtime_(rt), denm_interval_(seconds(1))
{
    schedule_timer();
}

void DenmApplication::set_interval(Clock::duration interval)
{
    denm_interval_ = interval;
    runtime_.cancel(this);
    schedule_timer();
}

void DenmApplication::print_generated_message(bool flag)
{
    print_tx_msg_ = flag;
}

void DenmApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

DenmApplication::PortType DenmApplication::port()
{
    return btp::ports::DENM;
}

void DenmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    asn1::PacketVisitor<asn1::Denm> visitor;
    std::shared_ptr<const asn1::Denm> denm = boost::apply_visitor(visitor, *packet);

    std::cout << "DENM application received a packet with " << (denm ? "decodable" : "broken") << " content" << std::endl;
    mqtt->publish("vanetza/denm", buildJSON(*denm));
}

void DenmApplication::schedule_timer()
{
    runtime_.schedule(denm_interval_, std::bind(&DenmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string DenmApplication::buildJSON(vanetza::asn1::Denm message) {
    ItsPduHeader_t& header = message->header;
    DecentralizedEnvironmentalNotificationMessage_t & denm = message->denm;
    ManagementContainer_t & mgc = denm.management;
    ReferencePosition_t & evp = mgc.eventPosition;
    //json j = denm;
    //std::cout << "DENM JSON: " << j << std::endl;

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
            {"latitude", (long) evp.latitude},
            {"longitude", (long) evp.longitude},
    };
    return json_payload.dump();
}

void DenmApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Denm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_denm;
    header.stationID = 99;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    asn_long2INTEGER(&message->denm.management.detectionTime, time_now.count());
    asn_long2INTEGER(&message->denm.management.referenceTime, time_now.count());

    message->denm.management.stationType = 15;
    message->denm.management.transmissionInterval = new TransmissionInterval_t(232);
    message->denm.management.actionID.originatingStationID = 99;
    message->denm.management.actionID.sequenceNumber = 3879;


    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::DEN;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    auto confirm = Application::request(request, std::move(packet));
    if (!confirm.accepted()) {
        throw std::runtime_error("DENM application data request failed");
    }

}
