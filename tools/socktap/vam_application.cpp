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

std::map<long, std::map<std::string, double>> vam_persistence;

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
    vam_persistence = {};
    if(config_s.vam.mqtt_enabled) local_mqtt->subscribe(config_s.vam.topic_in, this);
    if(config_s.vam.mqtt_enabled) local_mqtt->subscribe(config_s.full_vam_topic_in, this);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_in, this);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->subscribe(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_in, this);
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
    string vam_json_full;
    string vam_json = buildJSON(vam_t, vam_json_full, cp.time_received, cp.rssi, cp.size());

    if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.vam.topic_out, vam_json);
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_out, vam_json);
    if(config_s.vam.dds_enabled) dds->publish(config_s.vam.topic_out, vam_json);
    if(config_s.enable_json_prints) std::cout << "VAM JSON: " << vam_json << std::endl;
    vam_rx_counter->Increment();

    if(config_s.full_vam_topic_out != "") {
        if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.full_vam_topic_out, vam_json_full);
        if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_out, vam_json_full);
        if(config_s.vam.dds_enabled) dds->publish(config_s.full_vam_topic_out, vam_json_full);
        if(config_s.vam.udp_out_port != 0) {
            vam_udp_socket.send_to(buffer(vam_json_full, vam_json_full.length()), vam_remote_endpoint, 0, vam_err);
        }
    }
}

void VamApplication::schedule_timer()
{
    runtime_.schedule(vam_interval_, std::bind(&VamApplication::on_timer, this, std::placeholders::_1), this);
}

std::string VamApplication::buildJSON(VAM_t message, std::string & vam_json_full, double time_reception, int rssi, int packet_size) {
    ItsPduHeader_t& header = message.header;
    VruAwareness_t& vam = message.vam;
    BasicContainer_t& basic = vam.vamParameters.basicContainer;
    VruHighFrequencyContainer* vhfc = vam.vamParameters.vruHighFrequencyContainer;

    json general_payload, json_payload;

    bool newInfo;

    if (basic.stationType == 1 || basic.stationType == 13) { // person or animal
        newInfo = isNewInfo(header.stationID, time_reception);

        if(newInfo) vam_persistence[header.stationID] = {{"time", time_reception}};

    } else {
        long latitude = (long) basic.referencePosition.latitude;
        long longitude = (long) basic.referencePosition.longitude;
        long speed = (long) vhfc->speed.speedValue;
        long heading = (long) vhfc->heading.headingValue;

        newInfo = isNewInfo(header.stationID, latitude, longitude, speed, heading, time_reception);

        if(newInfo) vam_persistence[header.stationID] = {{"lat", (double) latitude}, {"lng", (double) longitude}, {"speed", (double) speed}, {"heading", (long) heading}, {"time", time_reception}};
    }

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    general_payload = {
            {"timestamp",time_reception},
            {"newInfo", newInfo},
            {"rssi", rssi},
            {"test", {
                    {"json_timestamp", time_now}
                },
            },
            {"stationID", (long) header.stationID},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type},
            {"packet_size",    packet_size}
        };

    json_payload = {
        {"fields", message}
    };

    json_payload.merge_patch(general_payload);
    vam_json_full = json_payload.dump();    // vam_json_full
    
    // TODO: set json_payload to simplified format below

    vam_rx_latency->Increment(time_now - time_reception);
    // std::cout << "VAM JSON FULL: " << vam_json_full << std::endl;
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

    if(config_s.vam.mqtt_time_enabled) {
        json json_payload = {
            {"timestamp", time_reception},
            {"test", {
                    {"wave_timestamp", time_now}
                },
            },
            {"stationID", config_s.station_id},
            {"receiverID", config_s.station_id},
            {"receiverType", config_s.station_type},
            {"fields", {
                    {"vam", payload}
                },
            },
        };
        local_mqtt->publish(config_s.vam.topic_time, json_payload.dump());
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_time, json_payload.dump());
    }

    vam_tx_counter->Increment();
    vam_tx_latency->Increment(time_now - time_reception);
}

void VamApplication::on_timer(Clock::time_point)
{

}

long double VamApplication::toRadians(const long double & degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double VamApplication::calcDistance(long double lat1, long double long1, long double lat2, long double long2) {
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double dist = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
 
    dist = 2 * asin(sqrt(dist));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    long double R = 6371;
     
    // Calculate the result
    dist = dist * R;
 
    return dist;
}

bool VamApplication::isNewInfo(long stationID, long latitude, long longitude, double speed, long heading, double time_reception) {
    // unavailable values
    if (latitude == 900000001 || longitude == 1800000001 || speed == 16383 || heading == 3601) {
        return true;
    }

    auto last_map = vam_persistence.find(stationID);
    if (last_map == vam_persistence.end()) {
        return true;
    }
    if ((last_map->second)["lat"] == 900000001 || (last_map->second)["lng"] == 1800000001 || (last_map->second)["speed"] == 16383 || (last_map->second)["heading"] == 3601) {
        return true;
    }

    // traduzir unidades
    latitude = (double) ((double) latitude / pow(10, 7));
    longitude = (double) ((double) longitude / pow(10, 7));
    speed = (double) ((double) speed / pow(10, 2));
    heading = (double) ((double) heading / pow(10, 1));
    long last_lat = (double) ((double) (last_map->second)["lat"] / pow(10, 7));
    long last_lng = (double) ((double) (last_map->second)["lng"] / pow(10, 7));
    double last_speed = (double) ((double) (last_map->second)["speed"] / pow(10, 2));
    long last_heading = (double) ((double) (last_map->second)["heading"] / pow(10, 1));

    double dist = calcDistance(latitude, longitude, last_lat, last_lng);

    double speed_delta = speed - last_speed;
    double heading_delta = heading - last_heading;
    
    return dist >= 4 || speed_delta >= 0.5 || heading_delta >= 4 || (time_reception - (last_map->second)["time"] >= 1);
}

bool VamApplication::isNewInfo(long stationID, double time_reception) {
    auto last_map = vam_persistence.find(stationID);
    
    if (last_map == vam_persistence.end()) {
        return true;
    }

    if ((time_reception - (last_map->second)["time"]) >= 0.5) return true;

    return false;
}
