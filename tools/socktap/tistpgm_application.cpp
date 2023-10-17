#include "tistpgm_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/tistpgm.hpp>
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

prometheus::Counter *tistpgm_rx_counter;
prometheus::Counter *tistpgm_tx_counter;
prometheus::Counter *tistpgm_rx_latency;
prometheus::Counter *tistpgm_tx_latency;

boost::asio::io_service tistpgm_io_service_;
ip::udp::socket tistpgm_udp_socket(tistpgm_io_service_);
ip::udp::endpoint tistpgm_remote_endpoint;
boost::system::error_code tistpgm_err;

TistpgmApplication::TistpgmApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), tistpgm_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    if(config_s.tistpgm.mqtt_enabled) local_mqtt->subscribe(config_s.tistpgm.topic_in, this);
    if(config_s.tistpgm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.tistpgm.topic_in, this);
    if(config_s.tistpgm.dds_enabled) dds->subscribe(config_s.tistpgm.topic_in, this);
    
    tistpgm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "tistpgm"}, {"direction", "rx"}}));
    tistpgm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "tistpgm"}, {"direction", "tx"}}));
    tistpgm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "tistpgm"}, {"direction", "rx"}}));
    tistpgm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "tistpgm"}, {"direction", "tx"}}));

    if(config_s.tistpgm.udp_out_port != 0) {
        tistpgm_udp_socket.open(ip::udp::v4());
        tistpgm_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.tistpgm.udp_out_addr), config_s.tistpgm.udp_out_port);
    }
}

void TistpgmApplication::set_interval(Clock::duration interval)
{
    tistpgm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

TistpgmApplication::PortType TistpgmApplication::port()
{
    return btp::ports::TRM;
}

void TistpgmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Tistpgm> visitor;
    std::shared_ptr<const asn1::Tistpgm> tistpgm = boost::apply_visitor(visitor, *packet);

    TisTpgTransactionsPdu_t tistpgm_t = {(*tistpgm)->header, (*tistpgm)->tisTpgTransaction};
    Document tistpgm_json = buildJSON(tistpgm_t, cp.time_received, cp.rssi, cp.size());

    StringBuffer fullBuffer;
    Writer<StringBuffer> writer(fullBuffer);
    tistpgm_json.Accept(writer);
    const char* tistpgmJSON = fullBuffer.GetString();

    if(config_s.tistpgm.udp_out_port != 0) {
        tistpgm_udp_socket.send_to(buffer(tistpgmJSON, strlen(tistpgmJSON)), tistpgm_remote_endpoint, 0, tistpgm_err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.tistpgm.dds_enabled) dds->publish(config_s.tistpgm.topic_out, tistpgmJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.tistpgm.mqtt_enabled) local_mqtt->publish(config_s.tistpgm.topic_out, tistpgmJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.tistpgm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.tistpgm.topic_out, tistpgmJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    
    tistpgm_rx_counter->Increment();
    tistpgm_rx_latency->Increment(time_full_remote - cp.time_received);

    if(config_s.tistpgm.mqtt_test_enabled) {
        Document::AllocatorType& allocator = tistpgm_json.GetAllocator();
        if (config_s.tistpgm.udp_out_port != 0) tistpgm_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
        if (config_s.tistpgm.dds_enabled != 0) tistpgm_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
        if (config_s.tistpgm.mqtt_enabled != 0) tistpgm_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
        if (config_s.tistpgm.mqtt_enabled && remote_mqtt != NULL) tistpgm_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);

        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        tistpgm_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        local_mqtt->publish(config_s.tistpgm.topic_test, testJSON);
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.tistpgm.topic_test, testJSON);
    }

    if(config_s.enable_json_prints) std::cout << "tistpgm JSON: " << tistpgmJSON << std::endl;    
}

void TistpgmApplication::schedule_timer()
{
    runtime_.schedule(tistpgm_interval_, std::bind(&TistpgmApplication::on_timer, this, std::placeholders::_1), this);
}

Document TistpgmApplication::buildJSON(TisTpgTransactionsPdu_t message, double time_reception, int rssi, int packet_size) {
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

void TistpgmApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    TisTpgTransaction_t tistpgm;

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
        from_json(payload, tistpgm, "TISTPGM");
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
    vanetza::asn1::Tistpgm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_tistpgtransaction;
    header.stationID = config_s.station_id;

    message->tisTpgTransaction = tistpgm;

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

    if(config_s.tistpgm.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("tistpgm", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        StringBuffer fullBuffer;
        Writer<StringBuffer> writer(fullBuffer);
        timePayload.Accept(writer);
        const char* timeJSON = fullBuffer.GetString();

        local_mqtt->publish(config_s.tistpgm.topic_time, timeJSON);
        if (remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.tistpgm.topic_time, timeJSON);
    
    }

    tistpgm_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    tistpgm_tx_latency->Increment(time_now - time_reception);
}

void TistpgmApplication::on_timer(Clock::time_point)
{

}
