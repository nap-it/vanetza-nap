#include "vam_application.hpp"
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

    VAM_t vam_t = {(*vam)->header, (*vam)->vam};
    Document vam_json_full(kObjectType);
    Document vam_json = buildJSON(vam_t, vam_json_full, cp.time_received, cp.rssi, cp.size());

    StringBuffer simpleBuffer;
    Writer<StringBuffer> simpleWriter(simpleBuffer);
    vam_json.Accept(simpleWriter);
    const char* simpleJSON = simpleBuffer.GetString();

    if(config_s.vam.udp_out_port != 0) {
        vam_udp_socket.send_to(buffer(simpleJSON, strlen(simpleJSON)), vam_remote_endpoint, 0, vam_err);
    }
    const double time_simple_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.dds_enabled) dds->publish(config_s.vam.topic_out, simpleJSON);
    const double time_simple_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.vam.topic_out, simpleJSON);
    const double time_simple_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_out, simpleJSON);
    const double time_simple_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    vam_json_full.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    /*
    if(config_s.vam.udp_out_port != 0) {
        vam_udp_socket.send_to(buffer(fullJSON, strlen(fullJSON)), vam_remote_endpoint, 0, vam_err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.dds_enabled) dds->publish(config_s.full_vam_topic_out, fullJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.mqtt_enabled) local_mqtt->publish(config_s.full_vam_topic_out, fullJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.vam.mqtt_enabled && remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_out, fullJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    */

    vam_rx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    vam_rx_latency->Increment(time_now - cp.time_received);

    if(config_s.vam.mqtt_test_enabled) {
        Document::AllocatorType& allocator = vam_json.GetAllocator();
        if (config_s.vam.udp_out_port != 0) vam_json["test"].AddMember("full_udp_timestamp", time_simple_udp, allocator);
        if (config_s.vam.dds_enabled != 0) vam_json["test"].AddMember("full_dds_timestamp", time_simple_dds, allocator);
        if (config_s.vam.mqtt_enabled != 0) vam_json["test"].AddMember("full_local_timestamp", time_simple_local, allocator);
        if (config_s.vam.mqtt_enabled && remote_mqtt != NULL) vam_json["test"].AddMember("full_remote_timestamp", time_simple_remote, allocator);
        /*
        if (config_s.full_vam_topic_out != "") {
            if (config_s.vam.udp_out_port != 0) vam_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
            if (config_s.vam.dds_enabled) vam_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
            if (config_s.vam.mqtt_enabled) vam_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
            if (config_s.vam.mqtt_enabled && remote_mqtt != NULL) vam_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);
        }
        */
        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        vam_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        local_mqtt->publish(config_s.vam.topic_test, testJSON);
        if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_test, testJSON);

        /*
        if(config_s.full_vam_topic_test != "") {
            allocator = vam_json_full.GetAllocator();
            if (config_s.vam.dds_enabled != 0) vam_json_full["test"].AddMember("simple_dds_timestamp", time_simple_dds, allocator);
            if (config_s.vam.mqtt_enabled != 0) vam_json_full["test"].AddMember("simple_local_timestamp", time_simple_local, allocator);
            if (config_s.vam.mqtt_enabled && remote_mqtt != NULL) vam_json_full["test"].AddMember("simple_remote_timestamp", time_simple_remote, allocator);
            if (config_s.full_vam_topic_out != "") {
                if (config_s.vam.udp_out_port != 0) vam_json_full["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
                if (config_s.vam.dds_enabled) vam_json_full["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
                if (config_s.vam.mqtt_enabled) vam_json_full["test"].AddMember("full_local_timestamp", time_full_local, allocator);
                if (config_s.vam.mqtt_enabled && remote_mqtt != NULL) vam_json_full["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);
            }
            StringBuffer fullTestBuffer;
            Writer<StringBuffer> fullTestWriter(fullTestBuffer);
            vam_json_full.Accept(fullTestWriter);
            const char* testJSON = fullTestBuffer.GetString();
            local_mqtt->publish(config_s.full_vam_topic_test, testJSON);
            if(remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_vam_topic_test, testJSON);
        }
        */
    }
    
    if(config_s.enable_json_prints) std::cout << "VAM JSON: " << simpleJSON << std::endl;
}

void VamApplication::schedule_timer()
{
    runtime_.schedule(vam_interval_, std::bind(&VamApplication::on_timer, this, std::placeholders::_1), this);
}

Document VamApplication::buildJSON(VAM_t message, Document& vam_json_full, double time_reception, int rssi, int packet_size) {
    ItsPduHeader_t& header = message.header;
    VruAwareness_t& vam = message.vam;
    BasicContainer_t& basic = vam.vamParameters.basicContainer;
    VruHighFrequencyContainer* vhfc = vam.vamParameters.vruHighFrequencyContainer;

    Document document(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();

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

    document.AddMember("timestamp", time_reception, allocator)
        .AddMember("newInfo", newInfo, allocator)
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

void VamApplication::on_message(string topic, string mqtt_message) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    VruAwareness_t vam;

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
        from_json(payload, vam);
    } catch(...) {
        std::cout << "-- Vanetza ETSI Decoding Error --\nCheck that the message format follows ETSI spec\n" << std::endl;
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

    if(config_s.vam.mqtt_time_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", config_s.station_id, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator)
            .AddMember("fields", Value(kObjectType).AddMember("vam", payload, allocator), allocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        timePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, allocator), allocator);

        StringBuffer fullBuffer;
        Writer<StringBuffer> writer(fullBuffer);
        timePayload.Accept(writer);
        const char* timeJSON = fullBuffer.GetString();

        local_mqtt->publish(config_s.vam.topic_time, timeJSON);
        if (remote_mqtt != NULL) remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.vam.topic_time, timeJSON);
    
    }

    vam_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
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
