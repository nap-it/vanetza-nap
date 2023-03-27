#include "denm_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

using namespace vanetza;
//using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;
using namespace boost::asio;

prometheus::Counter *denm_rx_counter;
prometheus::Counter *denm_tx_counter;
prometheus::Counter *denm_rx_latency;
prometheus::Counter *denm_tx_latency;

boost::asio::io_service denm_io_service_;
ip::udp::socket denm_udp_socket(denm_io_service_);
ip::udp::endpoint denm_remote_endpoint;
boost::system::error_code denm_err;

DenmApplication::DenmApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), denm_interval_(seconds(1)), local_mqtt(local_mqtt_),remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    if(config_s.denm.mqtt_enabled) local_mqtt->subscribe(config_s.denm.topic_in, this);
    if(config_s.denm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.denm.topic_in, this);
    if(config_s.denm.dds_enabled)  dds->subscribe(config_s.denm.topic_in, this);

    denm_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "denm"}, {"direction", "rx"}}));
    denm_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "denm"}, {"direction", "tx"}}));
    denm_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "denm"}, {"direction", "rx"}}));
    denm_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "denm"}, {"direction", "tx"}}));

    if(config_s.denm.udp_out_port != 0) {
        denm_udp_socket.open(ip::udp::v4());
        denm_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.denm.udp_out_addr), config_s.denm.udp_out_port);
    }
}

void DenmApplication::set_interval(Clock::duration interval)
{
    denm_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

DenmApplication::PortType DenmApplication::port()
{
    return btp::ports::DENM;
}

void DenmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Denm> visitor;
    std::shared_ptr<const asn1::Denm> denm = boost::apply_visitor(visitor, *packet);

    //std::cout << "DENM application received a packet with " << (denm ? "decodable" : "broken") << " content" << std::endl;

    DENM_t denm_t = {(*denm)->header, (*denm)->denm};
    string denm_json = buildJSON(denm_t, cp.time_received, cp.rssi, cp.size());

    if(config_s.denm.mqtt_enabled) local_mqtt->publish(config_s.denm.topic_out, denm_json);
    if(config_s.denm.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.denm.topic_out, denm_json);
    if(config_s.denm.dds_enabled) dds->publish(config_s.denm.topic_out, denm_json);
    if(config_s.enable_json_prints) std::cout << "DENM JSON: " << denm_json << std::endl;
    denm_rx_counter->Increment();

    if(config_s.denm.udp_out_port != 0) {
        denm_udp_socket.send_to(buffer(denm_json, denm_json.length()), denm_remote_endpoint, 0, denm_err);
    }
}

void DenmApplication::schedule_timer()
{
    runtime_.schedule(denm_interval_, std::bind(&DenmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string DenmApplication::buildJSON(DENM_t message, double time_reception, int rssi, int packet_size) {
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

    denm_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void DenmApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    DecentralizedEnvironmentalNotificationMessage_t denm;

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
        denm = payload.get<DecentralizedEnvironmentalNotificationMessage_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza ETSI Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    vanetza::asn1::Denm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_denm;
    header.stationID = config_s.station_id;

    message->denm = denm;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::DEN;
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

    if(config_s.denm.mqtt_time_enabled) {
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
                    {"denm", payload}
                },
            },
        };
        local_mqtt->publish(config_s.denm.topic_time, json_payload.dump());
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.denm.topic_time, json_payload.dump());
    }

    denm_tx_counter->Increment();
    denm_tx_latency->Increment(time_now - time_reception);
}

void DenmApplication::on_timer(Clock::time_point)
{

}
