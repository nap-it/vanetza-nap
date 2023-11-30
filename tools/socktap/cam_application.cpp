#include "cam_application.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using namespace boost::asio;
using namespace rapidjson;

std::map<long, std::map<std::string, double>> persistence;

prometheus::Counter *cam_rx_counter;
prometheus::Counter *cam_tx_counter;
prometheus::Counter *cam_rx_latency;
prometheus::Counter *cam_tx_latency;

boost::asio::io_service cam_io_service_;
ip::udp::socket cam_udp_socket(cam_io_service_);
ip::udp::endpoint cam_remote_endpoint;
boost::system::error_code cam_err;

SpeedValue_t last_speed = LLONG_MIN;
double time_speed = 0;

HeadingValue_t last_heading = LLONG_MIN;
double time_heading = 0;

CamApplication::CamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, vanetza::geonet::Router* timer_router_, int priority_) :
    positioning_(positioning), runtime_(rt), cam_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), timer_router(timer_router_), priority(priority_)
{
    persistence = {};
    if(config_s.cam.mqtt_enabled) {
        pubsub->manual_subscribe(config_s.cam, config_s.cam.topic_in, this);
        pubsub->manual_subscribe(config_s.cam, config_s.full_cam_topic_in, this);
    }
    if(config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) {
        pubsub->manual_subscribe(config_s.cam, config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_in, this);
        pubsub->manual_subscribe(config_s.cam, config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_cam_topic_in, this);
    }
    if(config_s.cam.dds_enabled) {
        pubsub->manual_provision(config_s.cam, config_s.cam.topic_out);
        pubsub->manual_provision(config_s.cam, config_s.full_cam_topic_out);
        pubsub->manual_provision(config_s.cam, config_s.own_cam_topic_out);
        pubsub->manual_provision(config_s.cam, config_s.own_full_cam_topic_out);
    }

    cam_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "tx"}}));
    cam_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "tx"}}));

    if(config_s.cam.udp_out_port != 0) {
        cam_udp_socket.open(ip::udp::v4());
        cam_remote_endpoint = ip::udp::endpoint(ip::address::from_string(config_s.cam.udp_out_addr), config_s.cam.udp_out_port);
    }
}

void CamApplication::set_interval(Clock::duration interval)
{
    cam_interval_ = interval;
    runtime_.cancel(this);
    if (interval != std::chrono::milliseconds(0)) schedule_timer();
}

CamApplication::PortType CamApplication::port()
{
    return btp::ports::CAM;
}

void CamApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Cam> visitor;
    std::shared_ptr<const asn1::Cam> cam = boost::apply_visitor(visitor, *packet);

    CAM_t cam_t = {(*cam)->header, (*cam)->cam};
    Document cam_json_full(kObjectType);
    Document cam_json = buildJSON(cam_t, cam_json_full, cp.time_received, cp.rssi, cp.size(), true, true, true);

    StringBuffer simpleBuffer;
    Writer<StringBuffer> simpleWriter(simpleBuffer);
    cam_json.Accept(simpleWriter);
    const char* simpleJSON = simpleBuffer.GetString();

    if(config_s.cam.dds_enabled) pubsub->dds->publish(config_s.cam.topic_out, simpleJSON);
    const double time_simple_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.cam.mqtt_enabled) pubsub->local_mqtt->publish(config_s.cam.topic_out, simpleJSON);
    const double time_simple_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_out, simpleJSON);
    const double time_simple_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    cam_json_full.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    if(config_s.full_cam_topic_out != "" && config_s.cam.udp_out_port != 0) {
        if(config_s.mcs_enabled) {
            Value mapValue(rapidjson::kObjectType);
            for (const auto& entry : cp.mcs) {
                Value key(entry.first.c_str(), cam_json_full.GetAllocator());
                Value value(entry.second);
                mapValue.AddMember(key, value, cam_json_full.GetAllocator());
            }
            cam_json_full["test"].AddMember("mcs", mapValue, cam_json_full.GetAllocator());

            StringBuffer fullBufferMCS;
            Writer<StringBuffer> fullWriterMCS(fullBufferMCS);
            cam_json_full.Accept(fullWriterMCS);
            const char* fullJSON_MCS = fullBufferMCS.GetString();

            cam_udp_socket.send_to(buffer(fullJSON_MCS, strlen(fullJSON_MCS)), cam_remote_endpoint, 0, cam_err);
        }
        else cam_udp_socket.send_to(buffer(fullJSON, strlen(fullJSON)), cam_remote_endpoint, 0, cam_err);
    }
    const double time_full_udp = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.full_cam_topic_out != "" && config_s.cam.dds_enabled) pubsub->dds->publish(config_s.full_cam_topic_out, fullJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.full_cam_topic_out != "" && config_s.cam.mqtt_enabled) pubsub->local_mqtt->publish(config_s.full_cam_topic_out, fullJSON);
    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.full_cam_topic_out != "" && config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_cam_topic_out, fullJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    cam_rx_counter->Increment();
    cam_rx_latency->Increment(time_full_remote - cp.time_received);

    if(config_s.cam.mqtt_test_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();
        if (config_s.cam.dds_enabled != 0) cam_json["test"].AddMember("simple_dds_timestamp", time_simple_dds, allocator);
        if (config_s.cam.mqtt_enabled != 0) cam_json["test"].AddMember("simple_local_timestamp", time_simple_local, allocator);
        if (config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) cam_json["test"].AddMember("simple_remote_timestamp", time_simple_remote, allocator);
        if (config_s.full_cam_topic_out != "") {
            if (config_s.cam.udp_out_port != 0) cam_json["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
            if (config_s.cam.dds_enabled) cam_json["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
            if (config_s.cam.mqtt_enabled) cam_json["test"].AddMember("full_local_timestamp", time_full_local, allocator);
            if (config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) cam_json["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);
        }
        StringBuffer testBuffer;
        Writer<StringBuffer> testWriter(testBuffer);
        cam_json.Accept(testWriter);
        const char* testJSON = testBuffer.GetString();
        pubsub->local_mqtt->publish(config_s.cam.topic_test, testJSON);
        if(pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_test, testJSON);

        if(config_s.full_cam_topic_test != "") {
            if (config_s.cam.dds_enabled != 0) cam_json_full["test"].AddMember("simple_dds_timestamp", time_simple_dds, allocator);
            if (config_s.cam.mqtt_enabled != 0) cam_json_full["test"].AddMember("simple_local_timestamp", time_simple_local, allocator);
            if (config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) cam_json_full["test"].AddMember("simple_remote_timestamp", time_simple_remote, allocator);
            if (config_s.full_cam_topic_out != "") {
                if (config_s.cam.udp_out_port != 0) cam_json_full["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
                if (config_s.cam.dds_enabled) cam_json_full["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
                if (config_s.cam.mqtt_enabled) cam_json_full["test"].AddMember("full_local_timestamp", time_full_local, allocator);
                if (config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) cam_json_full["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);
            }
            StringBuffer fullTestBuffer;
            Writer<StringBuffer> fullTestWriter(fullTestBuffer);
            cam_json_full.Accept(fullTestWriter);
            const char* testJSON = fullTestBuffer.GetString();
            pubsub->local_mqtt->publish(config_s.full_cam_topic_test, testJSON);
            if(pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_cam_topic_test, testJSON);
        }
    }

    if(config_s.enable_json_prints) std::cout << "CAM JSON: " << simpleJSON << std::endl;
}

long double CamApplication::toRadians(const long double & degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double CamApplication::calcDistance(long double lat1, long double long1, long double lat2, long double long2) {
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

bool CamApplication::isNewInfo(long stationID, long latitude, long longitude, double speed, long heading, double time_reception) {
    // unavailable values
    if (latitude == 900000001 || longitude == 1800000001 || speed == 16383 || heading == 3601) {
        return true;
    }

    auto last_map = persistence.find(stationID);
    if (last_map == persistence.end()) {
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

void CamApplication::schedule_timer()
{
    runtime_.schedule(cam_interval_, std::bind(&CamApplication::on_timer, this, std::placeholders::_1), this);
}

Document CamApplication::buildJSON(CAM_t message, Document& cam_json_full, double time_reception, int rssi, int packet_size, bool include_fields, bool rx, bool full) {
    ItsPduHeader_t& header = message.header;
    CoopAwareness_t& cam = message.cam;
    BasicContainer_t& basic = cam.camParameters.basicContainer;
    BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    AccelerationControl_t* acc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.accelerationControl;

    string driveDirection = "UNAVAILABLE"; 
    switch(bvc.driveDirection) {
        case(0):
            driveDirection = "FORWARD";
            driveDirection = "FORWARD";
            break;
        case(1):
            driveDirection = "BACKWARD";
            break;
        default:
            driveDirection = "UNAVAILABLE";
            break;
    }
    
    long latitude = (long) basic.referencePosition.latitude;
    long longitude = (long) basic.referencePosition.longitude;
    long speed = (double) bvc.speed.speedValue;
    long heading = (long) bvc.heading.headingValue;

    bool new_info = isNewInfo(header.stationID, latitude, longitude, speed, heading, time_reception);

    Document::AllocatorType& fullAllocator = cam_json_full.GetAllocator();

    Document simpleDocument(kObjectType);
    Document::AllocatorType& simpleAllocator = simpleDocument.GetAllocator();

    if(full) {
        cam_json_full.AddMember("fields", to_json(message, fullAllocator), fullAllocator);
    }
    
    // RapidJSON does not implement MergePatch. Implementing it would be computationally expensive. This is preferrable.
    if(include_fields) {
        if(full) {
            cam_json_full.AddMember("timestamp", time_reception, fullAllocator)
                    .AddMember("newInfo", new_info, fullAllocator)
                    .AddMember("rssi", rssi, fullAllocator)
                    .AddMember("stationID", Value(static_cast<int64_t>(header.stationID)), fullAllocator)
                    .AddMember("receiverID", config_s.station_id, fullAllocator)
                    .AddMember("receiverType", config_s.station_type, fullAllocator)
                    .AddMember("packet_size", packet_size, fullAllocator);
        }
        
        simpleDocument.AddMember("timestamp", time_reception, simpleAllocator)
                    .AddMember("newInfo", new_info, simpleAllocator)
                    .AddMember("rssi", rssi, simpleAllocator)
                    .AddMember("stationID", Value(static_cast<int64_t>(header.stationID)), simpleAllocator)
                    .AddMember("receiverID", config_s.station_id, simpleAllocator)
                    .AddMember("receiverType", config_s.station_type, simpleAllocator)
                    .AddMember("packet_size", packet_size, simpleAllocator);
    }

    simpleDocument.AddMember("generationDeltaTime", static_cast<int64_t>(cam.generationDeltaTime), simpleAllocator)
                .AddMember("stationType", static_cast<int64_t>(basic.stationType), simpleAllocator)
                .AddMember("latitude", (latitude == 900000001) ? latitude : static_cast<double>(latitude) / pow(10, 7), simpleAllocator)
                .AddMember("longitude", (longitude == 1800000001) ? longitude : static_cast<double>(longitude) / pow(10, 7), simpleAllocator)
                .AddMember("semiMajorConf", static_cast<int64_t>(basic.referencePosition.positionConfidenceEllipse.semiMajorConfidence), simpleAllocator)
                .AddMember("semiMinorConf", static_cast<int64_t>(basic.referencePosition.positionConfidenceEllipse.semiMinorConfidence), simpleAllocator)
                .AddMember("semiMajorOrient", static_cast<int64_t>(basic.referencePosition.positionConfidenceEllipse.semiMajorOrientation), simpleAllocator)
                .AddMember("altitude", (basic.referencePosition.altitude.altitudeValue == 800001) ? static_cast<int64_t>(basic.referencePosition.altitude.altitudeValue) : static_cast<double>(basic.referencePosition.altitude.altitudeValue) / pow(10, 2), simpleAllocator)
                .AddMember("altitudeConf", static_cast<int64_t>(basic.referencePosition.altitude.altitudeConfidence), simpleAllocator)
                .AddMember("heading", (heading == 3601) ? heading : static_cast<double>(heading) / pow(10, 1), simpleAllocator)
                .AddMember("headingConf", ((bvc.heading.headingConfidence == 126) || (bvc.heading.headingConfidence == 127)) ? bvc.heading.headingConfidence : static_cast<double>(bvc.heading.headingConfidence) / pow(10, 1), simpleAllocator)
                .AddMember("speed", (speed == 16383) ? speed : static_cast<double>(speed) / pow(10, 2), simpleAllocator)
                .AddMember("speedConf", ((bvc.speed.speedConfidence == 126) || (bvc.speed.speedConfidence == 127)) ? bvc.speed.speedConfidence : static_cast<double>(bvc.speed.speedConfidence) / pow(10, 2), simpleAllocator)
                .AddMember("driveDirection", Value().SetString(driveDirection.c_str(), driveDirection.size()), simpleAllocator)
                .AddMember("length", (bvc.vehicleLength.vehicleLengthValue == 1023) ? bvc.vehicleLength.vehicleLengthValue : static_cast<double>(bvc.vehicleLength.vehicleLengthValue) / pow(10, 1), simpleAllocator)
                .AddMember("width", ((bvc.vehicleWidth == 61) || (bvc.vehicleWidth == 62)) ? bvc.vehicleWidth : static_cast<double>(bvc.vehicleWidth) / pow(10, 1), simpleAllocator)
                .AddMember("acceleration", (bvc.longitudinalAcceleration.longitudinalAccelerationValue == 161) ? bvc.longitudinalAcceleration.longitudinalAccelerationValue : static_cast<double>(bvc.longitudinalAcceleration.longitudinalAccelerationValue) / pow(10, 1), simpleAllocator)
                .AddMember("curvature", static_cast<int64_t>(bvc.curvature.curvatureValue), simpleAllocator)
                .AddMember("yawRate", (bvc.yawRate.yawRateValue == 32767) ? bvc.yawRate.yawRateValue : static_cast<double>(bvc.yawRate.yawRateValue) / pow(10, 2), simpleAllocator)
                .AddMember("brakePedal", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 0))) : false), simpleAllocator)
                .AddMember("gasPedal", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 1))) : false), simpleAllocator)
                .AddMember("emergencyBrake", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 2))) : false), simpleAllocator)
                .AddMember("collisionWarning", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 3))) : false), simpleAllocator)
                .AddMember("accEngaged", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 4))) : false), simpleAllocator)
                .AddMember("cruiseControl", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 5))) : false), simpleAllocator)
                .AddMember("speedLimiter", static_cast<bool>(bvc.accelerationControl != nullptr ? (*(bvc.accelerationControl->buf) & (1 << (7 - 6))) : false), simpleAllocator)
                .AddMember("specialVehicle", Value(Type::kNullType), simpleAllocator);

    if (cam.camParameters.specialVehicleContainer != 0) {
        simpleDocument.AddMember("specialVehicle", to_json(*(cam.camParameters.specialVehicleContainer), simpleAllocator), simpleAllocator);
    }

    if(new_info) persistence[header.stationID] = {{"lat", (double) latitude}, {"lng", (double) longitude}, {"speed", (double) speed}, {"heading", (long) heading}, {"time", time_reception}};

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if (full) {
        cam_json_full.AddMember("test", Value(kObjectType).AddMember("json_timestamp", time_now, fullAllocator), fullAllocator);
    }
    simpleDocument.AddMember("test", Value(kObjectType).AddMember("json_timestamp", time_now, simpleAllocator), simpleAllocator);
    return simpleDocument;
}

void CamApplication::on_message(string topic, string mqtt_message, vanetza::geonet::Router* router) {

    const double time_reception = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

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

    vanetza::asn1::Cam message;
    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;  
    header.messageID = ItsPduHeader__messageID_cam;

    Value& payload = document.GetObject();
    if(topic == config_s.full_cam_topic_in) {
        CoopAwareness_t cam;
        try {
            from_json(payload, cam, "CAM");
        } catch (VanetzaJSONException& e) {
            std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
        } catch(...) {
            std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
            std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
            return;
        }
        header.stationID = config_s.station_id;
        message->cam = cam;
    }
    else if(topic == config_s.cam.topic_in) {
        try {
            CoopAwareness_t* cam = vanetza::asn1::allocate<CoopAwareness_t>();
            header.stationID = payload["stationID"].GetUint64();
            const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
            uint16_t gen_delta_time = time_now.count();
            cam->generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;
            cam->camParameters.basicContainer.referencePosition.latitude = (payload["latitude"].GetDouble() == 900000001) ? (long) payload["latitude"].GetDouble() : (long) ((double) payload["latitude"].GetDouble() * pow(10, 7));
            cam->camParameters.basicContainer.referencePosition.longitude = (payload["longitude"].GetDouble() == 1800000001) ? (long) payload["longitude"].GetDouble() : (long) ((double) payload["longitude"].GetDouble() * pow(10, 7));
            cam->camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorConfidence = payload["semiMajorConf"].GetInt64();
            cam->camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMinorConfidence = payload["semiMinorConf"].GetInt64();
            cam->camParameters.basicContainer.referencePosition.positionConfidenceEllipse.semiMajorOrientation = payload["semiMajorOrient"].GetInt64();
            cam->camParameters.basicContainer.referencePosition.altitude.altitudeValue = (payload["altitude"].GetDouble() == 800001) ? (long) payload["altitude"].GetDouble() : (long) ((double) payload["altitude"].GetDouble() * pow(10, 2));
            cam->camParameters.basicContainer.referencePosition.altitude.altitudeConfidence = payload["altitudeConf"].GetInt64();
            cam->camParameters.basicContainer.stationType = payload["stationType"].GetInt64();
            cam->camParameters.highFrequencyContainer.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
            cam->camParameters.highFrequencyContainer.choice.rsuContainerHighFrequency.protectedCommunicationZonesRSU = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingValue = (payload["heading"].GetDouble() == 3601) ? ((long) payload["heading"].GetDouble()) : (long) ((double) payload["heading"].GetDouble() * pow(10, 1));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingConfidence = (payload["headingConf"].GetInt64() == 126 || payload["headingConf"].GetInt64() == 127) ? (long) payload["headingConf"].GetInt64() : (long) ((double) payload["headingConf"].GetInt64() * pow(10, 1));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedValue = (payload["speed"].GetDouble() == 16383) ? (long) payload["speed"].GetDouble() : (long) ((double) payload["speed"].GetDouble() * pow(10, 2));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedConfidence = (payload["speedConf"].GetInt64() == 126 || payload["speedConf"].GetInt64() == 127) ? (long) payload["speedConf"].GetInt64() : (long) ((double) payload["speedConf"].GetInt64() * pow(10, 2));
            if(payload["driveDirection"] == "FORWARD") cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.driveDirection = DriveDirection_forward;
            else if(payload["driveDirection"] == "BACKWARD") cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.driveDirection = DriveDirection_backward;
            else cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.driveDirection = DriveDirection_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthValue = (payload["length"].GetDouble() == 1023) ? (long) payload["length"].GetDouble() : (long) ((double) payload["length"].GetDouble() * pow(10, 1));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleWidth = (payload["width"].GetDouble() == 61 || payload["width"].GetDouble() == 62) ? (long) payload["width"].GetDouble() : (long) ((double) payload["width"].GetDouble() * pow(10,1));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationValue = (payload["acceleration"].GetDouble() == 161) ? (long) payload["acceleration"].GetDouble() : (long) ((double) payload["acceleration"].GetDouble() * pow(10,1));
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.curvature.curvatureValue = payload["curvature"].GetInt64();
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.yawRate.yawRateValue = (payload["yawRate"].GetInt64() == 32767) ? (long) payload["yawRate"].GetInt64() : (long) ((double) payload["yawRate"].GetInt64() * pow(10,2));
            AccelerationControl_t* p_tmp = vanetza::asn1::allocate<AccelerationControl_t>();
            bool brakePedalEngaged = payload["brakePedal"].GetBool();
            bool gasPedalEngaged = payload["gasPedal"].GetBool();
            bool emergencyBrakeEngaged = payload["emergencyBrake"].GetBool();
            bool collisionWarningEngaged = payload["collisionWarning"].GetBool();
            bool accEngaged = payload["accEngaged"].GetBool();
            bool cruiseControlEngaged = payload["cruiseControl"].GetBool();
            bool speedLimiterEngaged = payload["speedLimiter"].GetBool();
            p_tmp->size = (7 / 8) + 1;
            p_tmp->bits_unused = (7 % 8) != 0 ? 8 - (7 % 8) : 0;
            p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
            *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
            if (brakePedalEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
            if (gasPedalEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
            if (emergencyBrakeEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
            if (collisionWarningEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
            if (accEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
            if (cruiseControlEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
            if (speedLimiterEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.accelerationControl = p_tmp;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.lanePosition = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.steeringWheelAngle = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.lateralAcceleration = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.verticalAcceleration = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.performanceClass = nullptr;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.cenDsrcTollingZone = nullptr;
            cam->camParameters.lowFrequencyContainer = nullptr;
            cam->camParameters.specialVehicleContainer = nullptr;
            if (payload.HasMember("specialVehicle")) {
                cam->camParameters.specialVehicleContainer = vanetza::asn1::allocate<SpecialVehicleContainer_t>();
                try {
                    from_json(payload["specialVehicle"], *(cam->camParameters.specialVehicleContainer), "specialVehicle");
                } catch (VanetzaJSONException& e) {
                    std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
                    std::cout << e.what() << std::endl;
                    std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
                } catch(...) {
                    std::cout << "-- Vanetza ETSI Encoding Error --\nCheck that the message format follows ETSI spec" << std::endl;
                    std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
                    return;
                }
            } else {
                cam->camParameters.specialVehicleContainer = nullptr;
            }
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationConfidence = AccelerationConfidence_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.yawRate.yawRateConfidence = YawRateConfidence_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingConfidence = HeadingConfidence_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedConfidence = SpeedConfidence_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.curvature.curvatureConfidence = CurvatureConfidence_unavailable;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.curvatureCalculationMode = CurvatureCalculationMode_yawRateUsed;
            cam->camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.vehicleLength.vehicleLengthConfidenceIndication = VehicleLengthConfidenceIndication_noTrailerPresent;
            message->cam = *(cam);
            delete cam;
        } catch(...) {
            std::cout << "-- Vanetza JSON Decoding Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
            std::cout << "Invalid payload: " << mqtt_message << std::endl;
            return;
        }
    }

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
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

    if(config_s.cam.mqtt_time_enabled) {
        Document simpleDocument;
        Document::AllocatorType& simpleAllocator = simpleDocument.GetAllocator();
        Value simplePayload(kObjectType);

        simplePayload.AddMember("timestamp", time_reception, simpleAllocator)
                    .AddMember("stationID", config_s.station_id, simpleAllocator)
                    .AddMember("receiverID", config_s.station_id, simpleAllocator)
                    .AddMember("receiverType", config_s.station_type, simpleAllocator)
                    .AddMember("fields", Value(kObjectType).AddMember("cam", payload, simpleAllocator), simpleAllocator);

        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        simplePayload.AddMember("test", Value(kObjectType).AddMember("wave_timestamp", time_now, simpleAllocator), simpleAllocator);

        StringBuffer simpleBuffer;
        Writer<StringBuffer> simpleWriter(simpleBuffer);
        simplePayload.Accept(simpleWriter);
        const char* simpleJSON = simpleBuffer.GetString();

        if(topic == config_s.full_cam_topic_in) {
            pubsub->local_mqtt->publish(config_s.full_cam_topic_time, simpleJSON);
            if (pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.full_cam_topic_time, simpleJSON);
        }
        else {
            pubsub->local_mqtt->publish(config_s.cam.topic_time, simpleJSON);
            if (pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_time, simpleJSON);
        }
    }

    cam_tx_counter->Increment();
    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    cam_tx_latency->Increment(time_now - time_reception);
}

void CamApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cam message;

    const double time_now_mqtt = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cam;
    header.stationID = config_s.station_id;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();

    CoopAwareness_t& cam = message->cam;
    cam.generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();
    
    SpeedValue_t speed = SpeedValue_unavailable;
    if (position.speed.value().value() >= 0 && position.speed.value().value() <= 16382) speed = position.speed.value().value() * 100;
    LongitudinalAccelerationValue_t acceleration = LongitudinalAccelerationValue_unavailable;

    const double millis_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    if(time_speed == 0) time_speed = millis_now;
    if (last_speed != LLONG_MIN && (speed != last_speed || millis_now - time_speed >= 1)) {
        acceleration = (int)((speed - last_speed) * 10);
        if (acceleration < -160 || acceleration > 160) acceleration = LongitudinalAccelerationValue_unavailable;
        time_speed = millis_now;
    }
    last_speed = speed;

    HeadingValue_t heading = HeadingValue_unavailable;
    if (position.course.value().value() >= 0 && position.course.value().value() <= 3600) heading = position.course.value().value();
    YawRateValue_t yaw_rate = YawRateValue_unavailable;

    if(time_heading == 0) time_heading = millis_now;
    if (last_heading != LLONG_MIN && (heading != last_heading || millis_now - time_heading >= 1)) {
        yaw_rate = (int)((heading - last_heading) * 100);
        if (yaw_rate < -32766 || yaw_rate > 32766) yaw_rate = YawRateValue_unavailable;
        time_heading = millis_now;
    }
    last_heading = heading;

    //if (!position.confidence) {
    //    std::cerr << "Skipping CAM, because no good position is available, yet." << std::endl;
    //    return;
    //}

    BasicContainer_t& basic = cam.camParameters.basicContainer;
    basic.stationType = config_s.station_type;
    copy(position, basic.referencePosition);

    cam.camParameters.highFrequencyContainer.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;

    BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    bvc.heading.headingValue = heading;
    bvc.heading.headingConfidence = HeadingConfidence_unavailable;
    if (position.course.confidence().value() > 0 && position.course.confidence().value() <= 125) bvc.heading.headingConfidence = position.course.confidence().value();


    bvc.speed.speedValue = speed;
    bvc.speed.speedConfidence = SpeedConfidence_unavailable; 
    if (position.speed.confidence().value() > 0 && position.speed.confidence().value() <= 125) bvc.speed.speedConfidence = position.speed.confidence().value();

    bvc.driveDirection = DriveDirection_forward;
    bvc.longitudinalAcceleration.longitudinalAccelerationValue = acceleration;

    bvc.vehicleLength.vehicleLengthValue = config_s.length * 10;
    bvc.vehicleLength.vehicleLengthConfidenceIndication = VehicleLengthConfidenceIndication_noTrailerPresent;
    bvc.vehicleWidth = config_s.width * 10;

    bvc.curvature.curvatureValue = CurvatureValue_unavailable;
    bvc.curvature.curvatureConfidence = CurvatureConfidence_unavailable;
    bvc.curvatureCalculationMode = CurvatureCalculationMode_yawRateUsed;

    bvc.yawRate.yawRateValue = yaw_rate;

    bvc.accelerationControl = vanetza::asn1::allocate<AccelerationControl_t>();
    bvc.accelerationControl->buf = (uint8_t *) calloc(1, sizeof(uint8_t));
    bvc.accelerationControl->size = 1;
    bvc.accelerationControl->bits_unused = 1;
    *(bvc.accelerationControl->buf) = (uint8_t) 0b10111110;

    std::string error;
    if (!message.validate(error)) {
        throw std::runtime_error("Invalid high frequency CAM: %s" + error);
    }

    CAM_t cam_t = {message->header, message->cam};
    Document cam_json_full(kObjectType);
    Document::AllocatorType& fullAllocator = cam_json_full.GetAllocator();
    Document cam_json = buildJSON(cam_t, cam_json_full, time_now_mqtt, -255, 0, true, false, true);
    Document::AllocatorType& simpleAllocator = cam_json.GetAllocator();

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        if (!Application::request(request, std::move(packet), nullptr, this->timer_router)) {
            return;
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
    }

    const double time_wave = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    cam_json_full["test"].AddMember("wave_timestamp", time_wave, fullAllocator);
    cam_json["test"].AddMember("wave_timestamp", time_wave, simpleAllocator);

    StringBuffer simpleBuffer;
    Writer<StringBuffer> simpleWriter(simpleBuffer);
    cam_json.Accept(simpleWriter);
    const char* simpleJSON = simpleBuffer.GetString();

    if(config_s.cam.dds_enabled) pubsub->dds->publish(config_s.own_cam_topic_out, simpleJSON);
    if(config_s.cam.mqtt_enabled) pubsub->local_mqtt->publish(config_s.own_cam_topic_out, simpleJSON);
    if(config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.own_cam_topic_out, simpleJSON);

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    cam_json_full.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    if(config_s.full_cam_topic_out != "") {
        if(config_s.cam.dds_enabled && config_s.own_full_cam_topic_out != "") pubsub->dds->publish(config_s.own_full_cam_topic_out, fullJSON);
        if(config_s.cam.mqtt_enabled && config_s.own_full_cam_topic_out != "") pubsub->local_mqtt->publish(config_s.own_full_cam_topic_out, fullJSON);
        if(config_s.cam.mqtt_enabled && config_s.own_full_cam_topic_out != "" && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.own_full_cam_topic_out, fullJSON);
    }

    const double time_now_latency = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    cam_tx_counter->Increment();
    cam_tx_latency->Increment(time_now_latency - time_now_mqtt);
}
