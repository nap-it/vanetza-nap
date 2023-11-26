#include "ivim_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/ivim.hpp>
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

prometheus::Counter *ivim_rx_counter;
prometheus::Counter *ivim_tx_counter;
prometheus::Counter *ivim_rx_latency;
prometheus::Counter *ivim_tx_latency;

boost::asio::io_service ivim_io_service_;
ip::udp::socket ivim_udp_socket(ivim_io_service_);
ip::udp::endpoint ivim_remote_endpoint;
boost::system::error_code ivim_err;

IvimApplication::IvimApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_) :
    positioning_(positioning), runtime_(rt), ivim_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_)
{
    this->pubsub->subscribe(config_s.ivim, this);
    
    ivim_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "ivim"}, {"direction", "rx"}}));
    ivim_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "ivim"}, {"direction", "tx"}}));
    ivim_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "ivim"}, {"direction", "rx"}}));
    ivim_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "ivim"}, {"direction", "tx"}}));

    if(config_s.ivim.udp_out_port != 0) {
        ivim_udp_socket.open(ip::udp::v4());
        ivim_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.ivim.udp_out_addr), config_s.ivim.udp_out_port);
    }
}

void IvimApplication::set_interval(Clock::duration interval)
{
    ivim_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

IvimApplication::PortType IvimApplication::port()
{
    return btp::ports::IVIM;
}

void IvimApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Ivim> visitor;
    std::shared_ptr<const asn1::Ivim> ivim = boost::apply_visitor(visitor, *packet);

    IVIM_t ivim_t = {(*ivim)->header, (*ivim)->ivi};
    Document ivim_json = buildJSON(ivim_t, cp.time_received, cp.rssi, cp.size());

    pubsub->publish(config_s.ivim, ivim_json, &ivim_udp_socket, &ivim_remote_endpoint, &ivim_err, ivim_rx_counter, ivim_rx_latency, cp.time_received, "IVIM");  
}

void IvimApplication::schedule_timer()
{
    runtime_.schedule(ivim_interval_, std::bind(&IvimApplication::on_timer, this, std::placeholders::_1), this);
}

Document IvimApplication::buildJSON(IVIM_t message, double time_reception, int rssi, int packet_size) {
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

void IvimApplication::on_message(string topic, string mqtt_message, std::unique_ptr<vanetza::geonet::Router> router) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    IviStructure_t ivim;

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
        from_json(payload, ivim, "IVIM");
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
    vanetza::asn1::Ivim message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_ivim;
    header.stationID = config_s.station_id;

    message->ivi = ivim;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::TLM;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        if (!Application::request(request, std::move(packet), nullptr, router.get())) {
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

    if(config_s.ivim.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("ivim", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        pubsub->publish_time(config_s.ivim, timePayload);
    
    }

    ivim_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    ivim_tx_latency->Increment(time_now - time_reception);
}

void IvimApplication::on_timer(Clock::time_point)
{

}
