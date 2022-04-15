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


DenmApplication::DenmApplication(PositionProvider& positioning, Runtime& rt, Mqtt* mqtt_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), denm_interval_(seconds(1)), mqtt(mqtt_), config_s(config_s_), metrics_s(metrics_s_)
{
    schedule_timer();
}

void DenmApplication::set_interval(Clock::duration interval)
{
    denm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

DenmApplication::PortType DenmApplication::port()
{
    return btp::ports::DENM;
}

void DenmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Denm> visitor;
    std::shared_ptr<const asn1::Denm> denm = boost::apply_visitor(visitor, *packet);

    std::cout << "DENM application received a packet with " << (denm ? "decodable" : "broken") << " content" << std::endl;
    DENM_t denm_t = {(*denm)->header, (*denm)->denm};
    mqtt->publish("vanetza/denm", buildJSON(denm_t, cp.time_received, cp.rssi));
}

void DenmApplication::schedule_timer()
{
    runtime_.schedule(denm_interval_, std::bind(&DenmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string DenmApplication::buildJSON(DENM_t message, double time_reception, int rssi) {
    ItsPduHeader_t& header = message.header;
    DecentralizedEnvironmentalNotificationMessage_t & denm = message.denm;
    ManagementContainer_t & mgc = denm.management;
    ReferencePosition_t & evp = mgc.eventPosition;
    //json j = denm;
    //std::cout << "DENM JSON: " << j << std::endl;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", rssi},
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
