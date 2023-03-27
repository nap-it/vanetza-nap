#include "mapem_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/mapem.hpp>
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

prometheus::Counter *mapem_rx_counter;
prometheus::Counter *mapem_tx_counter;
prometheus::Counter *mapem_rx_latency;
prometheus::Counter *mapem_tx_latency;

boost::asio::io_service mapem_io_service_;
ip::udp::socket mapem_udp_socket(mapem_io_service_);
ip::udp::endpoint mapem_remote_endpoint;
boost::system::error_code mapem_err;

MapemApplication::MapemApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), mapem_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    //persistence = {};
    if(config_s.mapem.mqtt_enabled) local_mqtt->subscribe(config_s.mapem.topic_in, this);
    if(config_s.mapem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.mapem.topic_in, this);
    if(config_s.mapem.dds_enabled) dds->subscribe(config_s.mapem.topic_in, this);
    
    mapem_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "mapem"}, {"direction", "rx"}}));
    mapem_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "mapem"}, {"direction", "tx"}}));
    mapem_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "mapem"}, {"direction", "rx"}}));
    mapem_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "mapem"}, {"direction", "tx"}}));

    if(config_s.mapem.udp_out_port != 0) {
        mapem_udp_socket.open(ip::udp::v4());
        mapem_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.mapem.udp_out_addr), config_s.mapem.udp_out_port);
    }
}

void MapemApplication::set_interval(Clock::duration interval)
{
    mapem_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

MapemApplication::PortType MapemApplication::port()
{
    return btp::ports::TOPO;
}

void MapemApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Mapem> visitor;
    std::shared_ptr<const asn1::Mapem> mapem = boost::apply_visitor(visitor, *packet);

    //std::cout << "MAPEM application received a packet with " << (mapem ? "decodable" : "broken") << " content" << std::endl;

    MAPEM_t mapem_t = {(*mapem)->header, (*mapem)->map};
    string mapem_json = buildJSON(mapem_t, cp.time_received, cp.rssi, cp.size());

    if(config_s.mapem.mqtt_enabled) local_mqtt->publish(config_s.mapem.topic_out, mapem_json);
    if(config_s.mapem.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.mapem.topic_out, mapem_json);
    if(config_s.mapem.dds_enabled) dds->publish(config_s.mapem.topic_out, mapem_json);
    if(config_s.enable_json_prints) std::cout << "MAPEM JSON: " << mapem_json << std::endl;
    mapem_rx_counter->Increment();

    if(config_s.mapem.udp_out_port != 0) {
        mapem_udp_socket.send_to(buffer(mapem_json, mapem_json.length()), mapem_remote_endpoint, 0, mapem_err);
    }
}

void MapemApplication::schedule_timer()
{
    runtime_.schedule(mapem_interval_, std::bind(&MapemApplication::on_timer, this, std::placeholders::_1), this);
}

std::string MapemApplication::buildJSON(MAPEM_t message, double time_reception, int rssi, int packet_size) {
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

    mapem_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void MapemApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    MapData_t mapem;

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
        mapem = payload.get<MapData_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza ETSI Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    vanetza::asn1::Mapem message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_mapem;
    header.stationID = config_s.station_id;

    message->map = mapem;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::RLT;
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

    if(config_s.mapem.mqtt_time_enabled) {
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
                    {"mapem", payload}
                },
            },
        };
        local_mqtt->publish(config_s.mapem.topic_time, json_payload.dump());
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.mapem.topic_time, json_payload.dump());
    }

    mapem_tx_counter->Increment();
    mapem_tx_latency->Increment(time_now - time_reception);
}

void MapemApplication::on_timer(Clock::time_point)
{

}
