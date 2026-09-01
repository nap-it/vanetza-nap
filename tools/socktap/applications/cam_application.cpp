#include "cam_application.hpp"
#include <rapidjson/document.h>
#include <vanetza/asn1/rj/jer_rj_encode.hpp>
#include <vanetza/asn1/rj/jer_rj_decode.hpp>
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <vanetza/security/verify_service.hpp>
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

prometheus::Counter *cam_rx_counter;
prometheus::Counter *cam_tx_counter;
prometheus::Counter *cam_rx_latency;
prometheus::Counter *cam_tx_latency;

boost::asio::io_service cam_io_service_;
ip::udp::socket cam_udp_socket(cam_io_service_);
ip::udp::endpoint cam_remote_endpoint;
boost::system::error_code cam_err;

CamApplication::CamApplication(PositionProvider& positioning, Runtime& rt, PubSub* pubsub_, config_t config_s_, metrics_t metrics_s_, geonet::Router* timer_router_, int priority_, std::mutex& prom_mtx_) :
    PubSub_application(priority_),
    positioning_(positioning), runtime_(rt), cam_interval_(seconds(1)), pubsub(pubsub_), config_s(config_s_), metrics_s(metrics_s_), timer_router(timer_router_), priority(priority_), prom_mtx(prom_mtx_)
{
    cam_rx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_counter = &((*metrics_s.packet_counter).Add({{"message", "cam"}, {"direction", "tx"}}));
    cam_rx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "rx"}}));
    cam_tx_latency = &((*metrics_s.latency_counter).Add({{"message", "cam"}, {"direction", "tx"}}));

    this->pubsub->subscribe(config_s.cam, this);

    // Provision own_cam_topic_out for DDS/Zenoh if enabled
    if(config_s.cam.dds_enabled && config_s.own_cam_topic_out != "") {
        pubsub->manual_provision(config_s.cam, config_s.own_cam_topic_out);
    }
    if(config_s.cam.zenoh_enabled && config_s.own_cam_topic_out != "") {
        pubsub->declare_zenoh_publisher(config_s.cam, config_s.own_cam_topic_out);
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
    const double time_queue2 = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {
        CohesivePacket operator()(CohesivePacket& packet) {return packet;}
        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}
    } ivis;

    UpPacket* packet_ptr = packet.get();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    // Try decoding in order: Compact R2 (6-bit) → R1 → Strict R2 (5-bit)
    // Compact R2: For VW-style encoders that use 6-bit pathHistory with protocolVersion=2
    // R1: For legacy devices
    // Strict R2: For true R2 encoders that use 5-bit pathHistory

    std::shared_ptr<const asn1::r2::Cam> cam_r2 = nullptr;
    std::shared_ptr<const asn1::Cam> cam_r1 = nullptr;
    bool is_r2 = false;
    bool is_compact_r2 = false;
    bool is_strict_r2 = false;

    // Step 1: Try Compact R2 (6-bit pathHistory)
    {
        asn1::r2::CompactR2DecodeGuard guard;  // RAII: swaps to 6-bit variant
        asn1::PacketVisitor<asn1::r2::Cam> visitor_compact_r2;
        cam_r2 = boost::apply_visitor(visitor_compact_r2, *packet);
        if (cam_r2 != nullptr) {
            is_r2 = true;
            is_compact_r2 = true;
        } else {
            if(config_s.debug_enabled) std::cout << "DEBUG Compact R2 decode error: " << visitor_compact_r2.last_error() << std::endl;
        }
    }  // guard destructor restores original type descriptor

    // Step 2: Try R1 if Compact R2 failed
    if (!is_r2) {
        asn1::PacketVisitor<asn1::r1::Cam> visitor_r1;
        cam_r1 = boost::apply_visitor(visitor_r1, *packet);
        if (cam_r1 != nullptr) {
            std::cout << "Compact R2 failed, successfully decoded with R1" << std::endl;
        } else {
            if(config_s.debug_enabled) std::cout << "DEBUG R1 decode error: " << visitor_r1.last_error() << std::endl;
        }
    }

    // Step 3: Try Strict R2 (5-bit pathHistory) if both Compact R2 and R1 failed
    if (!is_r2 && cam_r1 == nullptr) {
        asn1::PacketVisitor<asn1::r2::Cam> visitor_strict_r2;
        cam_r2 = boost::apply_visitor(visitor_strict_r2, *packet);
        if (cam_r2 != nullptr) {
            is_r2 = true;
            is_strict_r2 = true;
            std::cout << "R1 failed, successfully decoded with Strict R2 (5-bit pathHistory)" << std::endl;
        } else {
            std::cout << "-- Vanetza Decoding Error --\nReceived an encoded CAM message that does not meet ETSI spec (tried Compact R2, R1, and Strict R2)" << std::endl;
            std::cout << "DEBUG Strict R2 decode error: " << visitor_strict_r2.last_error() << std::endl;
            return;
        }
    }

    // Get stationId from whichever format decoded successfully
    long stationId = is_r2 ? (*cam_r2)->header.stationId : (*cam_r1)->header.stationID;

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
            stationId,
            config_s.station_id,
            config_s.station_type,
            cp.time_received,
            test);
    }

    // Encode to JSON using appropriate ASN.1 definition
    rapidjson::Document cam_doc;
    if (is_r2) {
        cam_doc = vanetza::asn1::rj::jer_encode_rj_doc(&asn_DEF_Vanetza_ITS2_CAM, cam_r2->content());
    } else {
        cam_doc = vanetza::asn1::rj::jer_encode_rj_doc(&asn_DEF_CAM, cam_r1->content());
    }
    
    rapidjson::Document output_doc;
    auto& alloc = output_doc.GetAllocator();
    output_doc.SetObject();

    output_doc.AddMember("fields", cam_doc, alloc);

    // Security report handling
    bool is_secured = !boost::get<boost::blank>(&indication.security_report);
    output_doc.AddMember("secured", is_secured, alloc);

    if (is_secured) {
        auto* verification = boost::get<security::VerificationReport>(&indication.security_report);
        if (verification) {
            rapidjson::Value securityStatus(rapidjson::kObjectType);
            securityStatus.AddMember("value", static_cast<int>(*verification), alloc);
            securityStatus.AddMember("description", Value().SetString(security::to_string(*verification), alloc), alloc);
            output_doc.AddMember("security_report", securityStatus, alloc);
        }
    }

    // Add "test" field for publish function (required by pubsub when mqtt_test_enabled)
    Value jsonTest(kObjectType);
    jsonTest.AddMember("start_processing_timestamp", cp.time_queue, alloc);
    if(parse_channel_info(cp).frequency != -1) {
        jsonTest.AddMember("channel_frequency", parse_channel_info(cp).frequency, alloc);
        if (parse_channel_info(cp).noise != -1) jsonTest.AddMember("channel_noise", parse_channel_info(cp).noise, alloc);
        jsonTest.AddMember("channel_busy_time", parse_channel_info(cp).chan_busy_time, alloc);
        jsonTest.AddMember("channel_rx_time", parse_channel_info(cp).chan_rx_time, alloc);
        jsonTest.AddMember("channel_tx_time", parse_channel_info(cp).chan_tx_time, alloc);
    }
    const double time_json = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    jsonTest.AddMember("json_timestamp", time_json, alloc);
    if(config_s.mcs_enabled) {
        Value mcsValue(rapidjson::kObjectType);
        for (const auto& entry : cp.mcs) {
            Value key(entry.first.c_str(), alloc);
            Value value(entry.second);
            mcsValue.AddMember(key, value, alloc);
        }
        jsonTest.AddMember("mcs", mcsValue, alloc);
    }
    output_doc.AddMember("test", jsonTest, alloc);

    // Add metadata fields
    output_doc.AddMember("timestamp", cp.time_received, alloc);
    output_doc.AddMember("rssi", cp.rssi, alloc);
    output_doc.AddMember("stationID", Value(static_cast<int64_t>(stationId)), alloc);
    output_doc.AddMember("stationAddr", Value().SetString(cp.source.c_str(), cp.source.size(), alloc), alloc);
    output_doc.AddMember("receiverID", config_s.station_id, alloc);
    output_doc.AddMember("receiverType", config_s.station_type, alloc);
    output_doc.AddMember("packet_size", static_cast<int>(cp.size()), alloc);

    const double time_encoded = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;
    pubsub->publish(config_s.cam, output_doc, &cam_udp_socket, &cam_remote_endpoint, &cam_err, cam_rx_counter, cam_rx_latency, cp.time_received, time_encoded, cp.time_queue, time_queue2, "CAM");
}

void CamApplication::schedule_timer()
{
    runtime_.schedule(cam_interval_, std::bind(&CamApplication::on_timer, this, std::placeholders::_1), this);
}

void CamApplication::on_message(string topic, string mqtt_message, const std::vector<uint8_t>& bytes, bool is_encoded, double time_reception, string test, vanetza::geonet::Router* router) {

    const double time_processing = (double) duration_cast< microseconds >(system_clock::now().time_since_epoch()).count() / 1000000.0;

    DownPacketPtr packet { new DownPacket() };
    Document document;

    int payload_station_id = -1;

    if (!is_encoded) {
        vanetza::asn1::r2::Cam cam;
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

        payload_station_id = document.HasMember("stationId") ? document["stationId"].GetInt() : -1;

        // Check if this is a full CAM (with header and cam) or just the cam payload
        bool has_full_structure = document.HasMember("header") && document.HasMember("cam");

        if (!has_full_structure) {
            // Wrap the payload with header and cam structure
            Document wrapper;
            auto& allocator = wrapper.GetAllocator();
            wrapper.SetObject();

            Value header(kObjectType);
            header.AddMember("protocolVersion", 2, allocator)
                .AddMember("messageId", Vanetza_ITS2_MessageId_cam, allocator)
                .AddMember("stationId", payload_station_id != -1 ? payload_station_id : config_s.station_id, allocator);
            wrapper.AddMember("header", header, allocator);

            // Move the document content under "cam"
            Value camContent;
            camContent.CopyFrom(document, allocator);
            wrapper.AddMember("cam", camContent, allocator);

            document.Swap(wrapper);
        }

        try {
            std::string verbose_error;
            bool success = vanetza::asn1::rj::jer_decode_rj_inplace(
                &asn_DEF_Vanetza_ITS2_CAM,
                cam.content(),
                document,
                config_s.debug_enabled ? &verbose_error : nullptr);
            if (!success) {
                std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows ETSI spec\n" << std::endl;
                if (config_s.debug_enabled && !verbose_error.empty()) {
                    std::cout << verbose_error << std::endl;
                }
                std::cout << "\nInvalid payload: " << mqtt_message << std::endl;
                return;
            }
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

        packet->layer(OsiLayer::Application) = std::move(cam);
    } else {
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
        // Use Compact R2 (6-bit pathHistory) for encoding to match VW-style encoders
        asn1::r2::CompactR2DecodeGuard guard;
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

        Document::AllocatorType& allocator = document.GetAllocator();
        Value timePayload(kObjectType);
        Value timeTest(kObjectType);

        int station_id_time = resolve_station_id(payload_station_id, config_s.station_id);
        std::string mac_addr = resolve_station_mac(config_s.station_type, payload_station_id, config_s.mac_address);

        timePayload.AddMember("timestamp", time_reception, allocator)
            .AddMember("stationID", station_id_time, allocator)
            .AddMember("stationAddr", mac_addr, allocator)
            .AddMember("receiverID", config_s.station_id, allocator)
            .AddMember("receiverType", config_s.station_type, allocator);
        if(!is_encoded) timePayload.AddMember("fields", document, allocator);

        timeTest.AddMember("wave_timestamp", time_now, allocator);
        timeTest.AddMember("start_processing_timestamp", time_processing, allocator);
        if(test != "") timeTest.AddMember("request_info", Value().SetString(test.c_str(), test.size()), allocator);
        timePayload.AddMember("test", timeTest, allocator);

        pubsub->publish_time(config_s.cam, timePayload);
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
    vanetza::asn1::r2::Cam message;

    const double time_now_mqtt = (double) duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;

    // R2 header (Vanetza_ITS2_ prefix)
    Vanetza_ITS2_ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageId = Vanetza_ITS2_MessageId_cam;
    header.stationId = config_s.station_id;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();

    // R2 CAM payload
    Vanetza_ITS2_CamPayload_t& cam = message->cam;
    cam.generationDeltaTime = gen_delta_time;

    auto position = positioning_.position_fix();

    // Speed handling
    long speed = Vanetza_ITS2_SpeedValue_unavailable;
    if (position.speed.value().value() >= 0 && position.speed.value().value() <= 16382) {
        speed = static_cast<long>(position.speed.value().value() * 100);
    }

    // Acceleration calculation
    long acceleration = Vanetza_ITS2_AccelerationValue_unavailable;
    const double millis_now = (double) duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;

    if (time_speed == 0) time_speed = millis_now;
    if (last_speed != LLONG_MIN && (speed != last_speed || millis_now - time_speed >= 1)) {
        acceleration = static_cast<long>((speed - last_speed) * 10);
        if (acceleration < -160 || acceleration > 160) acceleration = Vanetza_ITS2_AccelerationValue_unavailable;
        time_speed = millis_now;
    }
    last_speed = speed;

    // Heading handling
    long heading = Vanetza_ITS2_HeadingValue_unavailable;
    if (position.course.value().value() >= 0 && position.course.value().value() <= 3600) {
        heading = static_cast<long>(position.course.value().value());
    }

    // Yaw rate calculation
    long yaw_rate = Vanetza_ITS2_YawRateValue_unavailable;
    if (time_heading == 0) time_heading = millis_now;
    if (last_heading != LLONG_MIN && (heading != last_heading || millis_now - time_heading >= 1)) {
        yaw_rate = static_cast<long>((heading - last_heading) * 100);
        if (yaw_rate < -32766 || yaw_rate > 32766) yaw_rate = Vanetza_ITS2_YawRateValue_unavailable;
        time_heading = millis_now;
    }
    last_heading = heading;

    // Basic container
    Vanetza_ITS2_BasicContainer_t& basic = cam.camParameters.basicContainer;
    basic.stationType = config_s.station_type;

    // Populate ReferencePositionWithConfidence manually (R2 uses different structure than R1)
    auto& refPos = basic.referencePosition;

    // Check if position is valid before using it
    if (std::isfinite(position.latitude.value()) && std::isfinite(position.longitude.value())) {
        // Convert to tenth microdegrees (units used in ASN.1): 1 degree = 10,000,000 tenth microdegrees
        refPos.latitude = std::round((position.latitude / units::degree) * 10000000.0);
        refPos.longitude = std::round((position.longitude / units::degree) * 10000000.0);
    } else {
        // Use unavailable values when position is not valid
        refPos.latitude = Vanetza_ITS2_Latitude_unavailable;
        refPos.longitude = Vanetza_ITS2_Longitude_unavailable;
    }

    if (std::isfinite(position.confidence.semi_major.value()) && std::isfinite(position.confidence.semi_minor.value())) {
        if ((position.confidence.semi_major.value() * 100 < Vanetza_ITS2_SemiAxisLength_outOfRange)
            && (position.confidence.semi_minor.value() * 100 < Vanetza_ITS2_SemiAxisLength_outOfRange)
            && (position.confidence.orientation.value() * 10 < Vanetza_ITS2_Wgs84AngleValue_unavailable)) {
            refPos.positionConfidenceEllipse.semiMajorAxisLength = position.confidence.semi_major.value() * 100;
            refPos.positionConfidenceEllipse.semiMinorAxisLength = position.confidence.semi_minor.value() * 100;
            refPos.positionConfidenceEllipse.semiMajorAxisOrientation = position.confidence.orientation.value() * 10;
        } else {
            refPos.positionConfidenceEllipse.semiMajorAxisLength = Vanetza_ITS2_SemiAxisLength_outOfRange;
            refPos.positionConfidenceEllipse.semiMinorAxisLength = Vanetza_ITS2_SemiAxisLength_outOfRange;
            refPos.positionConfidenceEllipse.semiMajorAxisOrientation = Vanetza_ITS2_Wgs84AngleValue_unavailable;
        }
    } else {
        refPos.positionConfidenceEllipse.semiMajorAxisLength = Vanetza_ITS2_SemiAxisLength_unavailable;
        refPos.positionConfidenceEllipse.semiMinorAxisLength = Vanetza_ITS2_SemiAxisLength_unavailable;
        refPos.positionConfidenceEllipse.semiMajorAxisOrientation = Vanetza_ITS2_Wgs84AngleValue_unavailable;
    }

    if (position.altitude) {
        refPos.altitude.altitudeValue = to_altitude_value(position.altitude->value());
        refPos.altitude.altitudeConfidence = static_cast<Vanetza_ITS2_AltitudeConfidence_t>(to_altitude_confidence(position.altitude->confidence()));
    } else {
        refPos.altitude.altitudeValue = Vanetza_ITS2_AltitudeValue_unavailable;
        refPos.altitude.altitudeConfidence = Vanetza_ITS2_AltitudeConfidence_unavailable;
    }

    // High frequency container
    if (config_s.station_type == 15) {
        // RSU
        cam.camParameters.highFrequencyContainer.present = Vanetza_ITS2_HighFrequencyContainer_PR_rsuContainerHighFrequency;
        cam.camParameters.highFrequencyContainer.choice.rsuContainerHighFrequency.protectedCommunicationZonesRSU = nullptr;
    } else {
        // Vehicle
        cam.camParameters.highFrequencyContainer.present = Vanetza_ITS2_HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
        Vanetza_ITS2_BasicVehicleContainerHighFrequency_t& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;

        bvc.heading.headingValue = heading;
        bvc.heading.headingConfidence = Vanetza_ITS2_HeadingConfidence_unavailable;
        if (position.course.confidence().value() > 0 && position.course.confidence().value() <= 125) {
            bvc.heading.headingConfidence = static_cast<long>(position.course.confidence().value());
        }

        bvc.speed.speedValue = speed;
        bvc.speed.speedConfidence = Vanetza_ITS2_SpeedConfidence_unavailable;
        if (position.speed.confidence().value() > 0 && position.speed.confidence().value() <= 125) {
            bvc.speed.speedConfidence = static_cast<long>(position.speed.confidence().value());
        }

        bvc.driveDirection = Vanetza_ITS2_DriveDirection_forward;
        bvc.longitudinalAcceleration.value = acceleration;
        bvc.longitudinalAcceleration.confidence = Vanetza_ITS2_AccelerationConfidence_unavailable;

        bvc.vehicleLength.vehicleLengthValue = config_s.length * 10;
        bvc.vehicleLength.vehicleLengthConfidenceIndication = Vanetza_ITS2_VehicleLengthConfidenceIndication_noTrailerPresent;
        bvc.vehicleWidth = config_s.width * 10;

        bvc.curvature.curvatureValue = Vanetza_ITS2_CurvatureValue_unavailable;
        bvc.curvature.curvatureConfidence = Vanetza_ITS2_CurvatureConfidence_unavailable;
        bvc.curvatureCalculationMode = Vanetza_ITS2_CurvatureCalculationMode_yawRateUsed;

        bvc.yawRate.yawRateValue = yaw_rate;
        bvc.yawRate.yawRateConfidence = Vanetza_ITS2_YawRateConfidence_unavailable;

        // AccelerationControl is optional - allocate and set
        bvc.accelerationControl = vanetza::asn1::allocate<Vanetza_ITS2_AccelerationControl_t>();
        bvc.accelerationControl->buf = static_cast<uint8_t*>(calloc(1, sizeof(uint8_t)));
        bvc.accelerationControl->size = 1;
        bvc.accelerationControl->bits_unused = 1;
        *(bvc.accelerationControl->buf) = static_cast<uint8_t>(0b10111110);
    }

    std::string error;
    if (config_s.debug_enabled && !message.validate(error)) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\nError message: " << error << std::endl;
        return;
    }

    // Encode to JSON using the R2 encoder - wrap in metadata structure
    Document wrapper(kObjectType);
    Document::AllocatorType& wrapperAlloc = wrapper.GetAllocator();
    Value jsonTest(kObjectType);

    // Encode CAM to JSON and copy with wrapper's allocator to avoid allocator mismatch
    Document encodedCam = vanetza::asn1::rj::jer_encode_rj_doc(&asn_DEF_Vanetza_ITS2_CAM, message.content());
    Value fieldsValue;
    fieldsValue.CopyFrom(encodedCam, wrapperAlloc);

    wrapper.AddMember("timestamp", time_now_mqtt, wrapperAlloc)
        .AddMember("rssi", 0, wrapperAlloc)
        .AddMember("stationID", Value(static_cast<int64_t>(config_s.station_id)), wrapperAlloc)
        .AddMember("stationAddr", Value().SetString(config_s.mac_address.c_str(), config_s.mac_address.size(), wrapperAlloc), wrapperAlloc)
        .AddMember("receiverID", config_s.station_id, wrapperAlloc)
        .AddMember("receiverType", config_s.station_type, wrapperAlloc)
        .AddMember("packet_size", -255, wrapperAlloc)
        .AddMember("fields", fieldsValue, wrapperAlloc);

    jsonTest.AddMember("start_processing_timestamp", 0.0, wrapperAlloc);

    // Transmit the CAM
    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        // Use Compact R2 (6-bit pathHistory) for encoding to match VW-style encoders
        asn1::r2::CompactR2DecodeGuard guard;
        if (!Application::request(request, std::move(packet), nullptr, this->timer_router)) {
            return;
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
        return;
    }

    const double time_wave = (double) duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;

    jsonTest.AddMember("wave_timestamp", time_wave, wrapperAlloc);
    wrapper.AddMember("test", jsonTest, wrapperAlloc);

    StringBuffer fullBuffer;
    Writer<StringBuffer> fullWriter(fullBuffer);
    wrapper.Accept(fullWriter);
    const char* fullJSON = fullBuffer.GetString();

    if (config_s.cam.topic_out != "") {
        if (config_s.cam.dds_enabled && config_s.dds_enabled && config_s.own_cam_topic_out != "") {
            pubsub->dds->publish(config_s.own_cam_topic_out, fullJSON);
        }
        if (config_s.cam.zenoh_enabled && config_s.own_cam_topic_out != "") {
            pubsub->zenoh_put_shm(config_s.own_cam_topic_out, fullJSON, strlen(fullJSON));
        }
        if (config_s.cam.mqtt_enabled && config_s.own_cam_topic_out != "") {
            pubsub->local_mqtt->publish(config_s.own_cam_topic_out, fullJSON);
        }
        if (config_s.cam.mqtt_enabled && config_s.own_cam_topic_out != "" && pubsub->remote_mqtt != NULL) {
            pubsub->remote_mqtt->publish(config_s.remote_mqtt_prefix + std::to_string(config_s.station_id) + "/" + config_s.own_cam_topic_out, fullJSON);
        }
    }

    const double time_now_latency = (double) duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;

    prom_mtx.lock();
    cam_tx_counter->Increment();
    cam_tx_latency->Increment(time_now_latency - time_now_mqtt);
    prom_mtx.unlock();
}