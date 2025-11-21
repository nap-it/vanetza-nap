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

ITS_Container_SpeedValue_t last_speed = LLONG_MIN;
double time_speed = 0;

ITS_Container_HeadingValue_t last_heading = LLONG_MIN;
double time_heading = 0;

std::mutex cam_persistence_mtx;

CamApplication::CamApplication(vanetza::PositionProvider& positioning, vanetza::Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, vanetza::geonet::Router* timer_router_, int priority_, std::mutex& prom_mtx_) :
    PubSub_application(priority_),
    positioning_(positioning), runtime_(rt), cam_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), timer_router(timer_router_), priority(priority_), prom_mtx(prom_mtx_)
{
    persistence = {};

    cam_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "tx"}}));
    cam_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "tx"}}));

    if(config_s.cam.mqtt_enabled) {
        pubsub->manual_subscribe(config_s.cam, config_s.cam.topic_in, this);
    }
    if(config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) {
        pubsub->manual_subscribe(config_s.cam, config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_in, this);
    }
    if(config_s.cam.dds_enabled) {
        pubsub->manual_provision(config_s.cam, config_s.cam.topic_out);
        pubsub->manual_provision(config_s.cam, config_s.own_cam_topic_out);
        pubsub->manual_provision(config_s.cam, config_s.cam.topic_time);
    }

    if(config_s.cam.zenoh_enabled) {
        pubsub->declare_zenoh_publisher(config_s.cam, config_s.cam.topic_out);
        pubsub->declare_zenoh_publisher(config_s.cam, config_s.own_cam_topic_out);
        pubsub->declare_zenoh_publisher(config_s.cam, config_s.cam.topic_time);
    }

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
    if (cam == 0) {
        std::cout << "-- Vanetza Decoding Error --\nReceived an encoded CAM message that does not meet ETSI spec" << std::endl;
        return;
    }

    CAM_PDU_Description_CAM_t cam_t = {(*cam)->header, (*cam)->cam};

    if(config_s.publish_encoded_payloads) {
        const std::vector<uint8_t> vec = std::vector<uint8_t>(cp[OsiLayer::Application].begin(), cp[OsiLayer::Application].end());
        double time_pre_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
        string test = "{\"encoded_timestamp\": " + to_string(time_pre_encoded) + ", \"stationAddr\": " + cp.source + "}";
        pubsub->publish_encoded(
            config_s.cam,
            vec, 
            cp.rssi,
            true,
            cp.size(),
            cam_t.header.stationId,
            config_s.station_id,
            config_s.station_type,
            cp.time_received,
            test);
    }
    const double time_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    Document cam_json_full = buildJSON(cam_t, cp.time_received, cp.time_queue, cp.rssi, cp.size(), parse_channel_info(cp), true, true, cp.source);

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    cam_json_full.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    if(config_s.cam.topic_out != "" && config_s.cam.udp_out_port != 0) {
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
    if(config_s.cam.topic_out != "" && config_s.cam.dds_enabled) pubsub->dds->publish(config_s.cam.topic_out, fullJSON);
    const double time_full_dds = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.cam.topic_out != "" && config_s.cam.mqtt_enabled) pubsub->local_mqtt->publish(config_s.cam.topic_out, fullJSON);
    
    const double time_full_zenoh = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.cam.topic_out != "" && config_s.cam.zenoh_enabled && pubsub->session != nullptr) {
        const size_t output_len = strlen(fullJSON);
        auto output_alloc_result = pubsub->shm_provider->alloc_gc_defrag_blocking(output_len, zenoh::AllocAlignment({0}));
        zenoh::ZShmMut&& output_buf = std::get<zenoh::ZShmMut>(std::move(output_alloc_result));
        memcpy(output_buf.data(), fullJSON, output_len);
        pubsub->session->put(config_s.cam.topic_out, std::move(output_buf));
    }

    const double time_full_local = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if(config_s.cam.topic_out != "" && config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_out, fullJSON);
    const double time_full_remote = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    prom_mtx.lock();
    cam_rx_counter->Increment();
    cam_rx_latency->Increment(time_full_remote - cp.time_received);
    prom_mtx.unlock();

    if(config_s.cam.mqtt_test_enabled) {
        Document document;
        Document::AllocatorType& allocator = document.GetAllocator();

        if(config_s.cam.topic_test != "") {
            if (config_s.cam.topic_out != "") {
                if (config_s.cam.udp_out_port != 0) cam_json_full["test"].AddMember("full_udp_timestamp", time_full_udp, allocator);
                if (config_s.cam.dds_enabled) cam_json_full["test"].AddMember("full_dds_timestamp", time_full_dds, allocator);
                if (config_s.cam.zenoh_enabled) cam_json_full["test"].AddMember("full_zenoh_timestamp", time_full_zenoh, allocator);
                if (config_s.cam.mqtt_enabled) cam_json_full["test"].AddMember("full_local_timestamp", time_full_local, allocator);
                if (config_s.cam.mqtt_enabled && pubsub->remote_mqtt != NULL) cam_json_full["test"].AddMember("full_remote_timestamp", time_full_remote, allocator);
            }
            StringBuffer fullTestBuffer;
            Writer<StringBuffer> fullTestWriter(fullTestBuffer);
            cam_json_full.Accept(fullTestWriter);
            const char* testJSON = fullTestBuffer.GetString();
            pubsub->local_mqtt->publish(config_s.cam.topic_test, testJSON);
            if(pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_test, testJSON);
        }
    }

    if(config_s.enable_json_prints) std::cout << "CAM JSON: " << fullJSON << std::endl;
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

Document CamApplication::buildJSON(CAM_PDU_Description_CAM_t message, double time_reception, double time_queue, int rssi, int packet_size, channel channel_info, bool include_fields, bool rx, string source) {
    ETSI_ITS_CDD_ItsPduHeader_t& header = message.header;
    CamPayload_t& cam = message.cam;
    ETSI_ITS_CDD_BasicContainer_t& basic = cam.camParameters.basicContainer;
    CAM_PDU_Description_HighFrequencyContainer& high = cam.camParameters.highFrequencyContainer;
    CAM_PDU_Description_BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    ETSI_ITS_CDD_AccelerationControl_t* acc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.accelerationControl;

    bool has_vehicle = cam.camParameters.highFrequencyContainer.present == CAM_PDU_Description_HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
    
    long latitude = (long) basic.referencePosition.latitude;
    long longitude = (long) basic.referencePosition.longitude;
    long speed = (double) bvc.speed.speedValue;
    long heading = (long) bvc.heading.headingValue;

    bool new_info = isNewInfo(header.stationId, latitude, longitude, speed, heading, time_reception);

    Document cam_json_full(kObjectType);
    Document::AllocatorType& fullAllocator = cam_json_full.GetAllocator();

    Value jsonTest(kObjectType);

    cam_json_full.AddMember("fields", to_json(message, fullAllocator), fullAllocator);

    if(include_fields) {
        cam_json_full.AddMember("timestamp", time_reception, fullAllocator)
                .AddMember("newInfo", new_info, fullAllocator)
                .AddMember("rssi", rssi, fullAllocator)
                .AddMember("stationID", Value(static_cast<int64_t>(header.stationId)), fullAllocator)
                .AddMember("stationAddr", source, fullAllocator)
                .AddMember("receiverID", config_s.station_id, fullAllocator)
                .AddMember("receiverType", config_s.station_type, fullAllocator)
                .AddMember("packet_size", packet_size, fullAllocator);
        
    }

    
    if(new_info) {
        cam_persistence_mtx.lock();
        persistence[header.stationId] = {{"lat", (double) latitude}, {"lng", (double) longitude}, {"speed", (double) speed}, {"heading", (long) heading}, {"time", time_reception}};
        cam_persistence_mtx.unlock();
    }

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    if (time_queue != 0) jsonTest.AddMember("start_processing_timestamp", time_queue, fullAllocator);
    if(channel_info.frequency != -1) {
        jsonTest.AddMember("channel_frequency", channel_info.frequency, fullAllocator);
        if (channel_info.noise != -1) jsonTest.AddMember("channel_noise", channel_info.noise, fullAllocator);
        jsonTest.AddMember("channel_busy_time", channel_info.chan_busy_time, fullAllocator);
        jsonTest.AddMember("channel_rx_time", channel_info.chan_rx_time, fullAllocator);
        jsonTest.AddMember("channel_tx_time", channel_info.chan_tx_time, fullAllocator);
    }
    jsonTest.AddMember("json_timestamp", time_now, fullAllocator);
    cam_json_full.AddMember("test", jsonTest, fullAllocator);
    return cam_json_full;
}

void CamApplication::on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router) {

    const double time_processing = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    DownPacketPtr packet { new DownPacket() };
    Document document;
    Value payload;
    int payload_station_id = -1;

    CamPayload_t* cam_ptr = vanetza::asn1::allocate<CamPayload_t>();
    ETSI_ITS_CDD_AccelerationControl_t* p_tmp = vanetza::asn1::allocate<ETSI_ITS_CDD_AccelerationControl_t>();

    vanetza::asn1::Cam message;
    ETSI_ITS_CDD_ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;  
    header.messageId = MessageId_cam;
    
    if (!is_encoded) {
        CamPayload_t cam;
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
        payload_station_id = payload.HasMember("stationId") ? payload["stationId"].GetInt() : -1;
        
        if(topic == config_s.cam.topic_in) {
            try {
                from_json(payload, cam, "CAM");
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
            if(payload_station_id != -1) header.stationId = payload_station_id;
            else header.stationId = config_s.station_id;
            message->cam = cam;
        }

        std::string error;
        if (config_s.debug_enabled && !message.validate(error)) {
            std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\nError message: " << error << std::endl;
            std::cout << "Invalid payload: " << mqtt_message << std::endl;
            return;
        }

        packet->layer(OsiLayer::Application) = std::move(message);
    } else {
        delete p_tmp;
        delete cam_ptr;
        std::vector<unsigned char> bytesCopy(bytes.begin(), bytes.end());
        packet->layer(OsiLayer::Application) = std::move(bytesCopy);
    }

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;
    if (payload_station_id != -1) {
        apply_station_overrides(request, router, config_s.station_type, payload_station_id);
    }

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
        const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

        Document simpleDocument;
        Document::AllocatorType& simpleAllocator = simpleDocument.GetAllocator();
        Value simplePayload(kObjectType);
        Value timeTest(kObjectType);

        
        int station_id_time = resolve_station_id(payload_station_id, config_s.station_id);
        std::string mac_addr = resolve_station_mac(config_s.station_type, payload_station_id, config_s.mac_address);


        simplePayload.AddMember("timestamp", time_reception, simpleAllocator)
                    .AddMember("stationID", station_id_time, simpleAllocator)
                    .AddMember("stationAddr", mac_addr, simpleAllocator)
                    .AddMember("receiverID", config_s.station_id, simpleAllocator)
                    .AddMember("receiverType", config_s.station_type, simpleAllocator);
        if(!is_encoded) simplePayload.AddMember("fields", Value(kObjectType).AddMember("cam", payload, simpleAllocator), simpleAllocator);

        timeTest.AddMember("wave_timestamp", time_now, simpleAllocator);
        timeTest.AddMember("start_processing_timestamp", time_processing, simpleAllocator);
        if(test != "") timeTest.AddMember("request_info", Value().SetString(test.c_str(), test.size()), simpleAllocator);
        simplePayload.AddMember("test", timeTest, simpleAllocator);

        StringBuffer simpleBuffer;        
        Writer<StringBuffer> simpleWriter(simpleBuffer);
        simplePayload.Accept(simpleWriter);
        const char* simpleJSON = simpleBuffer.GetString();

        if(topic == config_s.cam.topic_in || topic == config_s.cam.topic_in + "_enc") {
            pubsub->local_mqtt->publish(config_s.cam.topic_time, simpleJSON);
            if (pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.cam.topic_time, simpleJSON);
            if (config_s.cam.dds_enabled) pubsub->dds->publish(config_s.cam.topic_time, simpleJSON);
            if (config_s.cam.zenoh_enabled && pubsub->session != nullptr) {
                const size_t output_len = strlen(simpleJSON);
                auto output_alloc_result = pubsub->shm_provider->alloc_gc_defrag_blocking(output_len, zenoh::AllocAlignment({0}));
                zenoh::ZShmMut&& output_buf = std::get<zenoh::ZShmMut>(std::move(output_alloc_result));
                memcpy(output_buf.data(), simpleJSON, output_len);
                pubsub->session->put(config_s.cam.topic_time, std::move(output_buf));
            }
        }
    }

    const double time_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    prom_mtx.lock();
    cam_tx_counter->Increment();
    cam_tx_latency->Increment(time_now - time_reception);
    prom_mtx.unlock();
}

void CamApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cam message;

    const double time_now_mqtt = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    ETSI_ITS_CDD_ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageId = MessageId_cam;
    header.stationId = config_s.station_id;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();

    CamPayload_t& cam = message->cam;
    cam.generationDeltaTime = gen_delta_time * CAM_PDU_Descriptions_GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();
    
    ITS_Container_SpeedValue_t speed = ITS_Container_SpeedValue_unavailable;
    if (position.speed.value().value() >= 0 && position.speed.value().value() <= 16382) speed = position.speed.value().value() * 100;
    ITS_Container_LongitudinalAccelerationValue_t acceleration = ITS_Container_LongitudinalAccelerationValue_unavailable;

    const double millis_now = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    if(time_speed == 0) time_speed = millis_now;
    if (last_speed != LLONG_MIN && (speed != last_speed || millis_now - time_speed >= 1)) {
        acceleration = (int)((speed - last_speed) * 10);
        if (acceleration < -160 || acceleration > 160) acceleration = ITS_Container_LongitudinalAccelerationValue_unavailable;
        time_speed = millis_now;
    }
    last_speed = speed;

    ITS_Container_HeadingValue_t heading = ITS_Container_HeadingValue_unavailable;
    if (position.course.value().value() >= 0 && position.course.value().value() <= 3600) heading = position.course.value().value();
    ITS_Container_YawRateValue_t yaw_rate = ITS_Container_YawRateValue_unavailable;

    if(time_heading == 0) time_heading = millis_now;
    if (last_heading != LLONG_MIN && (heading != last_heading || millis_now - time_heading >= 1)) {
        yaw_rate = (int)((heading - last_heading) * 100);
        if (yaw_rate < -32766 || yaw_rate > 32766) yaw_rate = ITS_Container_YawRateValue_unavailable;
        time_heading = millis_now;
    }
    last_heading = heading;

    ETSI_ITS_CDD_BasicContainer_t& basic = cam.camParameters.basicContainer;
    basic.stationType = config_s.station_type;
    copy(position, basic.referencePosition);


    if (config_s.station_type == 15) {
        cam.camParameters.highFrequencyContainer.present = CAM_PDU_Description_HighFrequencyContainer_PR_rsuContainerHighFrequency;
        cam.camParameters.highFrequencyContainer.choice.rsuContainerHighFrequency.protectedCommunicationZonesRSU = nullptr;
    } else {
        cam.camParameters.highFrequencyContainer.present = CAM_PDU_Description_HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
        CAM_PDU_Description_BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
        bvc.heading.headingValue = heading;
        bvc.heading.headingConfidence = ITS_Container_HeadingConfidence_unavailable;
        if (position.course.confidence().value() > 0 && position.course.confidence().value() <= 125) bvc.heading.headingConfidence = position.course.confidence().value();

        bvc.speed.speedValue = speed;
        bvc.speed.speedConfidence = ITS_Container_SpeedConfidence_unavailable; 
        if (position.speed.confidence().value() > 0 && position.speed.confidence().value() <= 125) bvc.speed.speedConfidence = position.speed.confidence().value();

        bvc.driveDirection = ITS_Container_DriveDirection_forward;
        bvc.longitudinalAcceleration.value = acceleration;

        bvc.vehicleLength.vehicleLengthValue = config_s.length * 10;
        bvc.vehicleLength.vehicleLengthConfidenceIndication = ITS_Container_VehicleLengthConfidenceIndication_noTrailerPresent;
        bvc.vehicleWidth = config_s.width * 10;

        bvc.curvature.curvatureValue = ITS_Container_CurvatureValue_unavailable;
        bvc.curvature.curvatureConfidence = ITS_Container_CurvatureConfidence_unavailable;
        bvc.curvatureCalculationMode = ITS_Container_CurvatureCalculationMode_yawRateUsed;

        bvc.yawRate.yawRateValue = yaw_rate;

        bvc.accelerationControl = vanetza::asn1::allocate<ETSI_ITS_CDD_AccelerationControl_t>();
        bvc.accelerationControl->buf = (uint8_t *) calloc(1, sizeof(uint8_t));
        bvc.accelerationControl->size = 1;
        bvc.accelerationControl->bits_unused = 1;
        *(bvc.accelerationControl->buf) = (uint8_t) 0b10111110;
    }
    
    std::string error;
    if (config_s.debug_enabled && !message.validate(error)) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\nError message: " << error << std::endl;
        return;
    }

    CAM_PDU_Description_CAM_t cam_t = {message->header, message->cam};
       
    Document cam_json_full = buildJSON(cam_t, time_now_mqtt, 0, -255, 0, channel{-1,-1,-1,-1,-1}, true, false, config_s.mac_address);
    // Document::AllocatorType& simpleAllocator = cam_json_full.GetAllocator();
    Document::AllocatorType& fullAllocator = cam_json_full.GetAllocator();

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

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    cam_json_full.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    if(config_s.cam.topic_out != "") {
        if(config_s.cam.dds_enabled && config_s.own_cam_topic_out != "") pubsub->dds->publish(config_s.own_cam_topic_out, fullJSON);
        if(config_s.cam.zenoh_enabled && config_s.own_cam_topic_out != "" && pubsub->session != nullptr) {
            const size_t output_len = strlen(fullJSON);
            auto output_alloc_result = pubsub->shm_provider->alloc_gc_defrag_blocking(output_len, zenoh::AllocAlignment({0}));
            zenoh::ZShmMut&& output_buf = std::get<zenoh::ZShmMut>(std::move(output_alloc_result));
            memcpy(output_buf.data(), fullJSON, output_len);
            pubsub->session->put(config_s.own_cam_topic_out, std::move(output_buf));
        }
        if(config_s.cam.mqtt_enabled && config_s.own_cam_topic_out != "") pubsub->local_mqtt->publish(config_s.own_cam_topic_out, fullJSON);
        if(config_s.cam.mqtt_enabled && config_s.own_cam_topic_out != "" && pubsub->remote_mqtt != NULL) pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.own_cam_topic_out, fullJSON);
    }

    const double time_now_latency = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    prom_mtx.lock();
    cam_tx_counter->Increment();
    cam_tx_latency->Increment(time_now_latency - time_now_mqtt);
    prom_mtx.unlock();
}
