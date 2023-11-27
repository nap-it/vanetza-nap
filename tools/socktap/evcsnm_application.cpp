#include "evcsnm_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/evcsnm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using namespace boost::asio;

prometheus::Counter *evcsnm_rx_counter;
prometheus::Counter *evcsnm_tx_counter;
prometheus::Counter *evcsnm_rx_latency;
prometheus::Counter *evcsnm_tx_latency;

boost::asio::io_service evcsnm_io_service_;
ip::udp::socket evcsnm_udp_socket(evcsnm_io_service_);
ip::udp::endpoint evcsnm_remote_endpoint;
boost::system::error_code evcsnm_err;

EvcsnmApplication::EvcsnmApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_) :
    positioning_(positioning), runtime_(rt), evcsnm_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_)
{
    this->pubsub->subscribe(config_s.evcsnm, this);
    
    evcsnm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "evcsnm"}, {"direction", "rx"}}));
    evcsnm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "evcsnm"}, {"direction", "tx"}}));
    evcsnm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "evcsnm"}, {"direction", "rx"}}));
    evcsnm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "evcsnm"}, {"direction", "tx"}}));

    if(config_s.evcsnm.udp_out_port != 0) {
        evcsnm_udp_socket.open(ip::udp::v4());
        evcsnm_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.evcsnm.udp_out_addr), config_s.evcsnm.udp_out_port);
    }
}

void EvcsnmApplication::set_interval(Clock::duration interval)
{
    evcsnm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

EvcsnmApplication::PortType EvcsnmApplication::port()
{
    return btp::ports::EVCSN_POI;
}

void EvcsnmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Evcsnm> visitor;
    std::shared_ptr<const asn1::Evcsnm> evcsnm = boost::apply_visitor(visitor, *packet);

    EvcsnPdu_t evcsnm_t = {(*evcsnm)->header, (*evcsnm)->evcsn};
    Document evcsnm_json = buildJSON(evcsnm_t, cp.time_received, cp.rssi, cp.size());

    pubsub->publish(config_s.evcsnm, evcsnm_json, &evcsnm_udp_socket, &evcsnm_remote_endpoint, &evcsnm_err, evcsnm_rx_counter, evcsnm_rx_latency, cp.time_received, "EVCSNM"); 
}

void EvcsnmApplication::schedule_timer()
{
    runtime_.schedule(evcsnm_interval_, std::bind(&EvcsnmApplication::on_timer, this, std::placeholders::_1), this);
}

Document EvcsnmApplication::buildJSON(EvcsnPdu_t message, double time_reception, int rssi, int packet_size) {
    ItsPduHeader_t& header = message.header;
    Document document(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();

    document.AddMember("timestamp", time_reception, allocator)
        .AddMember("rssi", rssi, allocator)
        .AddMember("stationID", Value(static_cast<int64_t>(header.stationID)), allocator)
        .AddMember("receiverID", config_s.station_id, allocator)
        .AddMember("receiverType", config_s.station_type, allocator)
        .AddMember("packet_size", packet_size, allocator)
        .AddMember("fields", to_json(message, allocator), allocator);

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    document.AddMember("test", Value(kObjectType).AddMember("json_timestamp", time_now, allocator), allocator);
    return document;
}

void EvcsnmApplication::on_message(string topic, string mqtt_message, vanetza::geonet::Router* router) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    EVChargingSpotNotificationPOIMessage_t evcsnm;

    Document document;
    
    try {
        document.Parse(mqtt_message.c_str());
        if(document.HasParseError() || !document.IsObject()) {
            std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows JSON spec\n" << std::endl;
            std::cout << "Invalid payload: " << mqtt_message << std::endl;
            return;
        }
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    Value& payload = document.GetObject();
    try {
        from_json(payload, evcsnm, "EVCSNM");
    } catch (VanetzaJSONException& e) {
        std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
        std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
        return;
    }
    vanetza::asn1::Evcsnm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_evcsn;
    header.stationID = config_s.station_id;

    message->evcsn = evcsnm;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::TLM;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        if (!Application::request(request, std::move(packet), nullptr, router)) {
            return;
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    if(config_s.evcsnm.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("evcsnm", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        pubsub->publish_time(config_s.evcsnm, timePayload);
    
    }

    evcsnm_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    evcsnm_tx_latency->Increment(time_now - time_reception);
}

void EvcsnmApplication::on_timer(Clock::time_point)
{

}
