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

ImzmApplication::ImzmApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), imzm_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    if(config_s.imzm.mqtt_enabled) local_mqtt->subscribe(config_s.imzm.topic_in, this);
    if(config_s.imzm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.imzm.topic_in, this);
    if(config_s.imzm.dds_enabled) dds->subscribe(config_s.imzm.topic_in, this);
    
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

    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    imzm_json.Accept(writer);
    const char* imzmJSON = fullBuffer.GetString();

    if(config_s.imzm.udp_out_port != 0) {
        imzm_udp_socket.send_to(buffer(imzmJSON, strlen(imzmJSON)), imzm_remote_endpoint, 0, imzm_err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.imzm.dds_enabled) dds->publish(config_s.imzm.topic_out, imzmJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.imzm.mqtt_enabled) local_mqtt->publish(config_s.imzm.topic_out, imzmJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.imzm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.imzm.topic_out, imzmJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    
    imzm_rx_counter->Increment();
    imzm_rx_latency->Increment(time_full_remote - cp.time_received);

    if(config_s.imzm.mqtt_test_enabled) {
        Document::AllocatorType& allocator = imzm_json.GetAllocator();
        if (config_s.imzm.udp_out_port != 0) imzm_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
        if (config_s.imzm.dds_enabled != 0) imzm_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
        if (config_s.imzm.mqtt_enabled != 0) imzm_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
        if (config_s.imzm.mqtt_enabled && remote_mqtt != NULL) imzm_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);

        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        imzm_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        local_mqtt->publish(config_s.imzm.topic_test, testJSON);
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.imzm.topic_test, testJSON);
    }

    if(config_s.enable_json_prints) std::cout << "imzm JSON: " << imzmJSON << std::endl;    
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

void ImzmApplication::on_message(string topic, string mqtt_message) {

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

        StringBuffer fullBuffer;
        Writer<StringBuffer> writer(fullBuffer);
        timePayload.Accept(writer);
        const char* timeJSON = fullBuffer.GetString();

        local_mqtt->publish(config_s.imzm.topic_time, timeJSON);
        if (remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.imzm.topic_time, timeJSON);
    
    }

    imzm_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    imzm_tx_latency->Increment(time_now - time_reception);
}

void ImzmApplication::on_timer(Clock::time_point)
{

}
