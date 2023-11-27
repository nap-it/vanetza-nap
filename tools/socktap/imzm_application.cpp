#include "imzm_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/imzm.hpp>
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

prometheus::Counter *imzm_rx_counter;
prometheus::Counter *imzm_tx_counter;
prometheus::Counter *imzm_rx_latency;
prometheus::Counter *imzm_tx_latency;

boost::asio::io_service imzm_io_service_;
ip::udp::socket imzm_udp_socket(imzm_io_service_);
ip::udp::endpoint imzm_remote_endpoint;
boost::system::error_code imzm_err;

ImzmApplication::ImzmApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_) :
    positioning_(positioning), runtime_(rt), imzm_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_)
{
    this->pubsub->subscribe(config_s.imzm, this);
    
    imzm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "imzm"}, {"direction", "rx"}}));
    imzm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "imzm"}, {"direction", "tx"}}));
    imzm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "imzm"}, {"direction", "rx"}}));
    imzm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "imzm"}, {"direction", "tx"}}));

    if(config_s.imzm.udp_out_port != 0) {
        imzm_udp_socket.open(ip::udp::v4());
        imzm_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.imzm.udp_out_addr), config_s.imzm.udp_out_port);
    }
}

void ImzmApplication::set_interval(Clock::duration interval)
{
    imzm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

ImzmApplication::PortType ImzmApplication::port()
{
    return btp::ports::IMZM;
}

void ImzmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Imzm> visitor;
    std::shared_ptr<const asn1::Imzm> imzm = boost::apply_visitor(visitor, *packet);

    IMZM_t imzm_t = {(*imzm)->header, (*imzm)->imzm};
    Document imzm_json = buildJSON(imzm_t, cp.time_received, cp.rssi, cp.size());

    pubsub->publish(config_s.imzm, imzm_json, &imzm_udp_socket, &imzm_remote_endpoint, &imzm_err, imzm_rx_counter, imzm_rx_latency, cp.time_received, "IMZM");  
}

void ImzmApplication::schedule_timer()
{
    runtime_.schedule(imzm_interval_, std::bind(&ImzmApplication::on_timer, this, std::placeholders::_1), this);
}

Document ImzmApplication::buildJSON(IMZM_t message, double time_reception, int rssi, int packet_size) {
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

void ImzmApplication::on_message(string topic, string mqtt_message, vanetza::geonet::Router* router) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    InterferenceManagementZoneMessage_t imzm;

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
        from_json(payload, imzm, "IMZM");
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
    vanetza::asn1::Imzm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_imzm;
    header.stationID = config_s.station_id;

    message->imzm = imzm;

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

    if(config_s.imzm.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("imzm", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        pubsub->publish_time(config_s.imzm, timePayload);
    
    }

    imzm_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    imzm_tx_latency->Increment(time_now - time_reception);
}

void ImzmApplication::on_timer(Clock::time_point)
{

}
