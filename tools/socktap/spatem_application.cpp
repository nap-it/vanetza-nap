#include "spatem_application.hpp"
//#include "asn1json.hpp"
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
using json = nlohmann::json;
using namespace boost::asio;

prometheus::Counter *spatem_rx_counter;
prometheus::Counter *spatem_tx_counter;
prometheus::Counter *spatem_rx_latency;
prometheus::Counter *spatem_tx_latency;

boost::asio::io_service spatem_io_service_;
ip::udp::socket spatem_udp_socket(spatem_io_service_);
ip::udp::endpoint spatem_remote_endpoint;
boost::system::error_code spatem_err;

SpatemApplication::SpatemApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), spatem_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    //persistence = {};
    if(config_s.spatem.mqtt_enabled) local_mqtt->subscribe(config_s.spatem.topic_in, this);
    if(config_s.spatem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.spatem.topic_in, this);
    if(config_s.spatem.dds_enabled) dds->subscribe(config_s.spatem.topic_in, this);
    
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

    //std::cout << "SPATEM application received a packet with " << (spatem ? "decodable" : "broken") << " content" << std::endl;

    SPATEM_t spatem_t = {(*spatem)->header, (*spatem)->spat};
    string spatem_json = buildJSON(spatem_t, cp.time_received, cp.rssi, cp.size());

    if(config_s.spatem.mqtt_enabled) local_mqtt->publish(config_s.spatem.topic_out, spatem_json);
    if(config_s.spatem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.spatem.topic_out, spatem_json);
    if(config_s.spatem.dds_enabled) dds->publish(config_s.spatem.topic_out, spatem_json);
    if(config_s.enable_json_prints) std::cout << "SPATEM JSON: " << spatem_json << std::endl;
    spatem_rx_counter->Increment();

    if(config_s.spatem.udp_out_port != 0) {
        spatem_udp_socket.send_to(buffer(spatem_json, spatem_json.length()), spatem_remote_endpoint, 0, spatem_err);
    }
}

void SpatemApplication::schedule_timer()
{
    runtime_.schedule(spatem_interval_, std::bind(&SpatemApplication::on_timer, this, std::placeholders::_1), this);
}

std::string SpatemApplication::buildJSON(SPATEM_t message, double time_reception, int rssi, int packet_size) {
    ItsPduHeader_t& header = message.header;
    nlohmann::json j = message;

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"rssi", rssi},
            {"test", {
                    {"json_timestamp", time_now}
                },
            },
            {"fields", j},
            {"stationID", (long) header.stationID},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type},
            {"packet_size", packet_size}
    };

    spatem_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void SpatemApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    SPAT_t spatem;

    json payload;

    try {
        payload = json::parse(mqtt_message);
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows JSON spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    try {
        spatem = payload.get<SPAT_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza ETSI Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
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

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    if(config_s.spatem.mqtt_time_enabled) {
        nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"test", {
                    {"wave_timestamp", time_now}
                },
            },
            {"stationID", config_s.station_id},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type},
            {"fields", {
                    {"spatem", payload}
                },
            },
        };
        local_mqtt->publish(config_s.spatem.topic_time, json_payload.dump());
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.spatem.topic_time, json_payload.dump());
    }

    spatem_tx_counter->Increment();
    spatem_tx_latency->Increment(time_now - time_reception);
}

void SpatemApplication::on_timer(Clock::time_point)
{

}
