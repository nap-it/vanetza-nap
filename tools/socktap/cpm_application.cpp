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

prometheus::Counter *cpm_rx_counter;
prometheus::Counter *cpm_tx_counter;
prometheus::Counter *cpm_rx_latency;
prometheus::Counter *cpm_tx_latency;

CpmApplication::CpmApplication(PositionProvider& positioning, Runtime& rt, Mqtt* mqtt_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), cpm_interval_(seconds(1)), mqtt(mqtt_), config_s(config_s_), metrics_s(metrics_s_)
{
    //persistence = {};
    mqtt->subscribe(config_s.cpm.topic_in, this);
    
    cpm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "cpm"}, {"direction", "rx"}}));
    cpm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "cpm"}, {"direction", "tx"}}));
    cpm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "cpm"}, {"direction", "rx"}}));
    cpm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "cpm"}, {"direction", "tx"}}));
}

void CpmApplication::set_interval(Clock::duration interval)
{
    cpm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

CpmApplication::PortType CpmApplication::port()
{
    return btp::ports::CPM;
}

void CpmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Cpm> visitor;
    std::shared_ptr<const asn1::Cpm> cpm = boost::apply_visitor(visitor, *packet);

    std::cout << "CPM application received a packet with " << (cpm ? "decodable" : "broken") << " content" << std::endl;

    CPM_t cpm_t = {(*cpm)->header, (*cpm)->cpm};
    string cpm_json = buildJSON(cpm_t, cp.time_received, cp.rssi);

    mqtt->publish(config_s.cpm.topic_out, cpm_json);
    std::cout << "CPM JSON: " << cpm_json << std::endl;
    cpm_rx_counter->Increment();
}

void CpmApplication::schedule_timer()
{
    runtime_.schedule(cpm_interval_, std::bind(&CpmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CpmApplication::buildJSON(CPM_t message, double time_reception, int rssi) {
    ItsPduHeader_t& header = message.header;
    nlohmann::json j = message;

    const double time_now = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", rssi},
            {"test", {
                    {"json_timestamp", time_now}
                },
            },
            {"fields", j},
            {"stationID", (long) header.stationID},
            {"receiverID", 1},
            {"receiverType", 15}
    };

    cpm_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void CpmApplication::on_message(string mqtt_message) {

    const double time_reception = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    CollectivePerceptionMessage_t cpm;

    try {
        json payload = json::parse(mqtt_message);
        cpm = payload.get<CollectivePerceptionMessage_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        return;
    }

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

    const double time_now = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    cpm_tx_counter->Increment();
    cpm_tx_latency->Increment(time_now - time_reception);
}

void CpmApplication::on_timer(Clock::time_point)
{

}
