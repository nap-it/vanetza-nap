#include "ssem_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/ssem.hpp>
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

prometheus::Counter *ssem_rx_counter;
prometheus::Counter *ssem_tx_counter;
prometheus::Counter *ssem_rx_latency;
prometheus::Counter *ssem_tx_latency;

boost::asio::io_service ssem_io_service_;
ip::udp::socket ssem_udp_socket(ssem_io_service_);
ip::udp::endpoint ssem_remote_endpoint;
boost::system::error_code ssem_err;

SsemApplication::SsemApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), ssem_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    if(config_s.ssem.mqtt_enabled) local_mqtt->subscribe(config_s.ssem.topic_in, this);
    if(config_s.ssem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.ssem.topic_in, this);
    if(config_s.ssem.dds_enabled) dds->subscribe(config_s.ssem.topic_in, this);
    
    ssem_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "ssem"}, {"direction", "rx"}}));
    ssem_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "ssem"}, {"direction", "tx"}}));
    ssem_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "ssem"}, {"direction", "rx"}}));
    ssem_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "ssem"}, {"direction", "tx"}}));

    if(config_s.ssem.udp_out_port != 0) {
        ssem_udp_socket.open(ip::udp::v4());
        ssem_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.ssem.udp_out_addr), config_s.ssem.udp_out_port);
    }
}

void SsemApplication::set_interval(Clock::duration interval)
{
    ssem_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

SsemApplication::PortType SsemApplication::port()
{
    return btp::ports::SSEM;
}

void SsemApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Ssem> visitor;
    std::shared_ptr<const asn1::Ssem> ssem = boost::apply_visitor(visitor, *packet);

    SSEM_t ssem_t = {(*ssem)->header, (*ssem)->ssm};
    Document ssem_json = buildJSON(ssem_t, cp.time_received, cp.rssi, cp.size());

    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    ssem_json.Accept(writer);
    const char* ssemJSON = fullBuffer.GetString();

    if(config_s.ssem.udp_out_port != 0) {
        ssem_udp_socket.send_to(buffer(ssemJSON, strlen(ssemJSON)), ssem_remote_endpoint, 0, ssem_err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.ssem.dds_enabled) dds->publish(config_s.ssem.topic_out, ssemJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.ssem.mqtt_enabled) local_mqtt->publish(config_s.ssem.topic_out, ssemJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.ssem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.ssem.topic_out, ssemJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    
    ssem_rx_counter->Increment();
    ssem_rx_latency->Increment(time_full_remote - cp.time_received);

    if(config_s.ssem.mqtt_test_enabled) {
        Document::AllocatorType& allocator = ssem_json.GetAllocator();
        if (config_s.ssem.udp_out_port != 0) ssem_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
        if (config_s.ssem.dds_enabled != 0) ssem_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
        if (config_s.ssem.mqtt_enabled != 0) ssem_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
        if (config_s.ssem.mqtt_enabled && remote_mqtt != NULL) ssem_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);

        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        ssem_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        local_mqtt->publish(config_s.ssem.topic_test, testJSON);
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.ssem.topic_test, testJSON);
    }

    if(config_s.enable_json_prints) std::cout << "ssem JSON: " << ssemJSON << std::endl;    
}

void SsemApplication::schedule_timer()
{
    runtime_.schedule(ssem_interval_, std::bind(&SsemApplication::on_timer, this, std::placeholders::_1), this);
}

Document SsemApplication::buildJSON(SSEM_t message, double time_reception, int rssi, int packet_size) {
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

void SsemApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    SignalStatusMessage_t ssem;

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
        from_json(payload, ssem, "SSEM");
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
    vanetza::asn1::Ssem message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_ssem;
    header.stationID = config_s.station_id;

    message->ssm = ssem;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::TLM;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        if (!Application::request(request, std::move(packet), nullptr)) {
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

    if(config_s.ssem.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("ssem", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        StringBuffer fullBuffer;
        Writer<StringBuffer> writer(fullBuffer);
        timePayload.Accept(writer);
        const char* timeJSON = fullBuffer.GetString();

        local_mqtt->publish(config_s.ssem.topic_time, timeJSON);
        if (remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.ssem.topic_time, timeJSON);
    
    }

    ssem_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    ssem_tx_latency->Increment(time_now - time_reception);
}

void SsemApplication::on_timer(Clock::time_point)
{

}