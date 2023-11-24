#include "spatem_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/spatem.hpp>
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

prometheus::Counter *spatem_rx_counter;
prometheus::Counter *spatem_tx_counter;
prometheus::Counter *spatem_rx_latency;
prometheus::Counter *spatem_tx_latency;

boost::asio::io_service spatem_io_service_;
ip::udp::socket spatem_udp_socket(spatem_io_service_);
ip::udp::endpoint spatem_remote_endpoint;
boost::system::error_code spatem_err;

SpatemApplication::SpatemApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority) :
    positioning_(positioning), runtime_(rt), spatem_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_)
{
    this->pubsub.subscribe(config_s.spatem, this);
    
    spatem_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "spatem"}, {"direction", "rx"}}));
    spatem_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "spatem"}, {"direction", "tx"}}));
    spatem_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "spatem"}, {"direction", "rx"}}));
    spatem_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "spatem"}, {"direction", "tx"}}));

    if(config_s.spatem.udp_out_port != 0) {
        spatem_udp_socket.open(ip::udp::v4());
        spatem_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.spatem.udp_out_addr), config_s.spatem.udp_out_port);
    }
}

void SpatemApplication::set_interval(Clock::duration interval)
{
    spatem_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

SpatemApplication::PortType SpatemApplication::port()
{
    return btp::ports::SPAT;
}

void SpatemApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Spatem> visitor;
    std::shared_ptr<const asn1::Spatem> spatem = boost::apply_visitor(visitor, *packet);

    SPATEM_t spatem_t = {(*spatem)->header, (*spatem)->spat};
    Document spatem_json = buildJSON(spatem_t, cp.time_received, cp.rssi, cp.size());

    pubsub->publish(config_s.spatem, spatem_json, spatem_udp_socket, spatem_remote_endpoint, spatem_err, spatem_rx_counter, spatem_rx_latency, cp.time_received, "SPATEM");  
}

void SpatemApplication::schedule_timer()
{
    runtime_.schedule(spatem_interval_, std::bind(&SpatemApplication::on_timer, this, std::placeholders::_1), this);
}

Document SpatemApplication::buildJSON(SPATEM_t message, double time_reception, int rssi, int packet_size) {
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

void SpatemApplication::on_message(string topic, string mqtt_message, std::unique_ptr<vanetza::geonet::Router> router) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    SPAT_t spatem;

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
        from_json(payload, spatem, "SPATEM");
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
    vanetza::asn1::Spatem message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_spatem;
    header.stationID = config_s.station_id;

    message->spat = spatem;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::TLM;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        if (!Application::request(request, std::move(packet), nullptr, std::move(router))) {
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

    if(config_s.spatem.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("spatem", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        pubsub->publish_time(config_s.spatem, timePayload);
    
    }

    spatem_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    spatem_tx_latency->Increment(time_now - time_reception);
}

void SpatemApplication::on_timer(Clock::time_point)
{

}
