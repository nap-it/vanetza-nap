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

SsemApplication::SsemApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, int priority_, std::mutex& prom_mtx_) :
    PubSub_application(priority_),
    positioning_(positioning), runtime_(rt), ssem_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), priority(priority_), prom_mtx(prom_mtx_)
{   
    ssem_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "ssem"}, {"direction", "rx"}}));
    ssem_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "ssem"}, {"direction", "tx"}}));
    ssem_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "ssem"}, {"direction", "rx"}}));
    ssem_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "ssem"}, {"direction", "tx"}}));

    this->pubsub->subscribe(config_s.ssem, this);

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
    const double time_queue2 = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Ssem> visitor;
    std::shared_ptr<const asn1::Ssem> ssem = boost::apply_visitor(visitor, *packet);
    if (ssem == 0) {
        std::cout << "-- Vanetza Decoding Error --\nReceived an encoded SSEM message that does not meet ETSI spec" << std::endl;
        //std::cout << "\nInvalid sender: " << cp. << std::endl;
        return;
    }
    SSEM_t ssem_t = {(*ssem)->header, (*ssem)->ssm};

    if(config_s.publish_encoded_payloads) {
        const std::vector<uint8_t> vec = std::vector<uint8_t>(cp[OsiLayer::Application].begin(), cp[OsiLayer::Application].end());
        double time_pre_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        string test = "{\"encoded_timestamp\": " + to_string(time_pre_encoded) + ", \"stationAddr\": " + cp.source + "}";
        pubsub->publish_encoded(
            config_s.ssem,
            vec, 
            cp.rssi,
            true,
            cp.size(),
            ssem_t.header.stationID,
            config_s.station_id,
            config_s.station_type,
            cp.time_received,
            test);
    }
    const double time_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    Document ssem_json = buildJSON(ssem_t, cp.time_received, cp.rssi, cp.size(), cp.time_queue, parse_channel_info(cp), cp.source);
    pubsub->publish(config_s.ssem, ssem_json, &ssem_udp_socket, &ssem_remote_endpoint, &ssem_err, ssem_rx_counter, ssem_rx_latency, cp.time_received, time_encoded, cp.time_queue, time_queue2, "SSEM");

}

void SsemApplication::schedule_timer()
{
    runtime_.schedule(ssem_interval_, std::bind(&SsemApplication::on_timer, this, std::placeholders::_1), this);
}

Document SsemApplication::buildJSON(SSEM_t message, double time_reception, int rssi, int packet_size, double time_queue, channel channel_info, string source) {
    ITS_Container_ItsPduHeader_t& header = message.header;
    Document document(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();
    Value jsonTest(kObjectType);

    document.AddMember("timestamp", time_reception, allocator)
        .AddMember("rssi", rssi, allocator)
        .AddMember("stationID", Value(static_cast<int64_t>(header.stationID)), allocator)
        .AddMember("stationAddr", source, allocator)
        .AddMember("receiverID", config_s.station_id, allocator)
        .AddMember("receiverType", config_s.station_type, allocator)
        .AddMember("packet_size", packet_size, allocator)
        .AddMember("fields", to_json(message, allocator), allocator);

    jsonTest.AddMember("start_processing_timestamp", time_queue, allocator);
    if(channel_info.frequency != -1) {
        jsonTest.AddMember("channel_frequency", channel_info.frequency, allocator);
        if (channel_info.noise != -1) jsonTest.AddMember("channel_noise", channel_info.noise, allocator);
        jsonTest.AddMember("channel_busy_time", channel_info.chan_busy_time, allocator);
        jsonTest.AddMember("channel_rx_time", channel_info.chan_rx_time, allocator);
        jsonTest.AddMember("channel_tx_time", channel_info.chan_tx_time, allocator);
    }
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    jsonTest.AddMember("json_timestamp", time_now, allocator);
    document.AddMember("test", jsonTest, allocator);
    return document;
}

void SsemApplication::on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router) {

    const double time_processing = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    DownPacketPtr packet { new DownPacket() };
    Document document;
    Value payload;

    if (!is_encoded) {
        SignalStatusMessage_t ssem;
        fillPosition(mqtt_message, positioning_);
    
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

        payload = document.GetObject();

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

        ITS_Container_ItsPduHeader_t& header = message->header;
        header.protocolVersion = 2;
        header.messageID = MessageId_ssem;
        header.stationID = config_s.station_id;

        message->ssm = ssem;

        std::string error;
        if (config_s.debug_enabled && !message.validate(error)) {
            std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\nError message: " << error << std::endl;
            std::cout << "Invalid payload: " << mqtt_message << std::endl;
            return;
        }

        packet->layer(OsiLayer::Application) = std::move(message);
    } else {
        std::vector<unsigned char> bytesCopy(bytes.begin(), bytes.end());
        packet->layer(OsiLayer::Application) = std::move(bytesCopy);
    }

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

    if(config_s.ssem.mqtt_time_enabled) {
        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);
        Value timeTest(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("stationAddr", config_s.mac_address, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator);
        if(!is_encoded) timePayload.AddMember("fields", Value(kObjectType).AddMember("ssem", payload, allocator), allocator);

        timeTest.AddMember("wave_timestamp", time_now, allocator);
        timeTest.AddMember("start_processing_timestamp", time_processing, allocator);
        if(test != "") timeTest.AddMember("request_info", Value().SetString(test.c_str(), test.size()), allocator);
        timePayload.AddMember("test", timeTest, allocator);

        pubsub->publish_time(config_s.ssem, timePayload);
    }

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    prom_mtx.lock();
    ssem_tx_counter->Increment();
    ssem_tx_latency->Increment(time_now - time_reception);
    prom_mtx.unlock();
}

void SsemApplication::on_timer(Clock::time_point)
{

}
