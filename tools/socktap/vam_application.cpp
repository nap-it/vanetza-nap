#include "vam_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/vam.hpp>
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

prometheus::Counter *vam_rx_counter;
prometheus::Counter *vam_tx_counter;
prometheus::Counter *vam_rx_latency;
prometheus::Counter *vam_tx_latency;

boost::asio::io_service vam_io_service_;
ip::udp::socket vam_udp_socket(vam_io_service_);
ip::udp::endpoint vam_remote_endpoint;
boost::system::error_code vam_err;

VamApplication::VamApplication(PositionProvider& positioning, Runtime& rt, Mqtt *local_mqtt_, Mqtt *remote_mqtt_, Dds* dds_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), vam_interval_(seconds(1)), local_mqtt(local_mqtt_), remote_mqtt(remote_mqtt_), dds(dds_), config_s(config_s_), metrics_s(metrics_s_)
{
    //persistence = {};
    if(config_s.vam.mqtt_enabled) local_mqtt->subscribe(config_s.vam.topic_in, this);
    if(config_s.vam.mqtt_enabled) local_mqtt->subscribe(config_s.full_vam_topic_in, this);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe("obu" + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_in, this);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe("obu" + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_in, this);
    if(config_s.vam.dds_enabled) dds->subscribe(config_s.vam.topic_in, this);
    if(config_s.vam.dds_enabled) dds->subscribe(config_s.full_vam_topic_in, this);

    vam_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "vam"}, {"direction", "rx"}}));
    vam_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "vam"}, {"direction", "tx"}}));
    vam_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "vam"}, {"direction", "rx"}}));
    vam_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "vam"}, {"direction", "tx"}}));

    if(config_s.vam.udp_out_port != 0) {
        vam_udp_socket.open(ip::udp::v4());
        vam_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.vam.udp_out_addr), config_s.vam.udp_out_port);
    }
}

void VamApplication::set_interval(Clock::duration interval)
{
    vam_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

VamApplication::PortType VamApplication::port()
{
    return btp::ports::VAM;
}

void VamApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Vam> visitor;
    std::shared_ptr<const asn1::Vam> vam = boost::apply_visitor(visitor, *packet);

    //std::cout << "VAM application received a packet with " << (vam ? "decodable" : "broken") << " content" << std::endl;

    VAM_t vam_t = {(*vam)->header, (*vam)->vam};
    string vam_json = buildJSON(vam_t, cp.time_received, cp.rssi);

    if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.vam.topic_out, vam_json);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish("obu" + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_out, vam_json);
    if(config_s.vam.dds_enabled) dds->publish(config_s.vam.topic_out, vam_json);
    if(config_s.enable_json_prints) std::cout << "VAM JSON: " << vam_json << std::endl;
    vam_rx_counter->Increment();

    if(config_s.full_vam_topic_out != "") {
        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        json fields_json = vam_t;
        json full_json = {
            {"timestamp", cp.time_received},
            {"newInfo", true},
            {"rssi", cp.rssi},
            {"test", {
                    {"json_timestamp", time_now}
                },
            },
            {"fields", fields_json},
            {"stationID", (long) vam_t.header.stationID},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type}
        };
        string json_dump = full_json.dump();
        if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.full_vam_topic_out, json_dump);
        if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish("obu" + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_out, json_dump);
        if(config_s.vam.dds_enabled) dds->publish(config_s.full_vam_topic_out, json_dump);
        if(config_s.vam.udp_out_port != 0) {
            vam_udp_socket.send_to(buffer(json_dump, json_dump.length()), vam_remote_endpoint, 0, vam_err);
        }
    }
}

void VamApplication::schedule_timer()
{
    runtime_.schedule(vam_interval_, std::bind(&VamApplication::on_timer, this, std::placeholders::_1), this);
}

std::string VamApplication::buildJSON(VAM_t message, double time_reception, int rssi) {
    ItsPduHeader_t& header = message.header;
    VruAwareness_t& vam = message.vam;
    nlohmann::json j = message;

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", rssi},
            {"test", {
                    {"json_timestamp", time_now}
                },
            },
            {"fields", j},
            {"stationID", (long) header.stationID},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type}
    };

    vam_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void VamApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    VruAwareness_t vam;

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
        vam = payload.get<VruAwareness_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza ETSI Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        std::cout << "Invalid payload: " << mqtt_message << std::endl;
        return;
    }

    vanetza::asn1::Vam message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 1;
    header.messageID = ItsPduHeader__messageID_vam;
    header.stationID = config_s.station_id;

    message->vam = vam;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::VRU;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        auto confirm = Application::request(request, std::move(packet));
        if (!confirm.accepted()) {
            throw std::runtime_error("VAM application data request failed");
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

    if(config_s.vam.mqtt_time_enabled) {
        nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"test", {
                    {"wave_timestamp", time_now}
                },
            },
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type},
            {"fields", payload},
        };
        local_mqtt->publish(config_s.vam.topic_time, json_payload.dump());
        if(remote_mqtt != NULL) remote_mqtt->publish("obu" + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_time, json_payload.dump());
    }

    vam_tx_counter->Increment();
    vam_tx_latency->Increment(time_now - time_reception);
}

void VamApplication::on_timer(Clock::time_point)
{

}
