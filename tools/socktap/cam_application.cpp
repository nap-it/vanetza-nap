#include "cam_application.hpp"
#include "complete_packet.hpp"
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
using json = nlohmann::json;
using namespace boost::asio;

std::map<long, std::map<std::string, double>> persistence;

prometheus::Counter *cam_rx_counter;
prometheus::Counter *cam_tx_counter;
prometheus::Counter *cam_rx_latency;
prometheus::Counter *cam_tx_latency;

boost::asio::io_service cam_io_service_;
ip::udp::socket cam_udp_socket(cam_io_service_);
ip::udp::endpoint cam_remote_endpoint;
boost::system::error_code cam_err;

CamApplication::CamApplication(PositionProvider& positioning, Runtime& rt, Mqtt *mqtt_, config_t config_s_, metrics_t metrics_s_) :
    positioning_(positioning), runtime_(rt), cam_interval_(seconds(1)), mqtt(mqtt_), config_s(config_s_), metrics_s(metrics_s_)
{
    persistence = {};
    mqtt->subscribe(config_s.cam.topic_in, this);
    
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

    std::cout << "CAM application received a packet with " << (cam ? "decodable" : "broken") << " content" << std::endl;

    CAM_t cam_t = {(*cam)->header, (*cam)->cam};
    string cam_json = buildJSON(cam_t, cp.time_received, cp.rssi);

    mqtt->publish(config_s.cam.topic_out, cam_json);
    std::cout << "CAM JSON: " << cam_json << std::endl;
    cam_rx_counter->Increment();

    if(config_s.full_cam_topic_out != "") { 
        json fields_json = cam_t;
        json full_json = {
            {"timestamp", cp.time_received},
            {"rssi", cp.rssi},
            {"others", {
                "json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
            },
            {"fields", fields_json}
        };
        string json_dump = full_json.dump();
        mqtt->publish(config_s.full_cam_topic_out, json_dump);
        if(config_s.cam.udp_out_port != 0) {
            cam_udp_socket.send_to(buffer(json_dump, json_dump.length()), cam_remote_endpoint, 0, cam_err);
        }
    }
}

void CamApplication::schedule_timer()
{
    runtime_.schedule(cam_interval_, std::bind(&CamApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CamApplication::buildJSON(CAM_t message, double time_reception, int rssi) { 
    ItsPduHeader_t& header = message.header;
    CoopAwareness_t& cam = message.cam;
    BasicContainer_t& basic = cam.camParameters.basicContainer;
    BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    AccelerationControl_t* acc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.accelerationControl;
    //json j = cam;
    //std::cout << "CAM JSON: " << j << std::endl;

    string driveDirection = "UNAVAILABLE"; 
    switch(bvc.driveDirection) {
        case(0):
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

    auto last_map = persistence.find(header.stationID);
    
    bool new_info = last_map == persistence.end() || ((last_map->second)["lat"] != (double) latitude) || ((last_map->second)["lng"] != (double) longitude) || ( time_reception - (last_map->second)["time"] >= 1);

    const double time_now = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", new_info},
            {"rssi", rssi},
            {"test", {
                {"json_timestamp", time_now}
            }
            },
            {"stationID", (long) header.stationID},
            {"stationType", (long) basic.stationType},
            {"latitude", latitude},
            {"longitude", longitude},
            {"semiMajorConf", (long) basic.referencePosition.positionConfidenceEllipse.semiMajorConfidence},
            {"semiMinorConf", (long) basic.referencePosition.positionConfidenceEllipse.semiMinorConfidence},
            {"semiMajorOrient", (long) basic.referencePosition.positionConfidenceEllipse.semiMajorOrientation},
            {"altitude", (long) basic.referencePosition.altitude.altitudeValue},
            {"altitudeConf", (long) basic.referencePosition.altitude.altitudeConfidence},
            {"heading", (long) bvc.heading.headingValue},
            {"headingConf", (long) bvc.heading.headingConfidence},
            {"speed", (long) bvc.speed.speedValue},
            {"speedConf", (long) bvc.speed.speedConfidence},
            {"driveDirection", driveDirection},
            {"lenght",(long) bvc.vehicleLength.vehicleLengthValue},
            {"width", (long) bvc.vehicleWidth},
            {"acceleration", (long) bvc.longitudinalAcceleration.longitudinalAccelerationValue},
            {"curvature", (long) bvc.curvature.curvatureValue},
            {"yawRate", (long) bvc.yawRate.yawRateValue},
            {"brakePedal", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-0)))},
            {"gasPedal", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-1)))},
            {"emergencyBrake", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-2)))},
            {"collisionWarning", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-3)))},
            {"accEngaged", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-4)))},
            {"cruiseControl", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-5)))},
            {"speedLimiter", (bool) (*(bvc.accelerationControl->buf) & (1 << (7-6)))},
            {"specialVehicle", {
                  {"publicTransport", {
                     {"embarkationStatus", false},
                     {"ptActivation", nullptr}
                  }
                  }
            }}
    };

    if(new_info) persistence[header.stationID] = {{"lat", (double) latitude}, {"lng", (double) longitude}, {"time", time_reception}};

    cam_rx_latency->Increment(time_now - time_reception);
    return json_payload.dump();
}

void CamApplication::on_message(string mqtt_message) {

    const double time_reception = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    CoopAwareness_t cam;

    try {
        json payload = json::parse(mqtt_message);
        cam = payload.get<CoopAwareness_t>();
    } catch(nlohmann::detail::type_error& e) {
        std::cout << "-- Vanetza JSON Decoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
        return;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't decode the JSON message.\nNo other info available\n" << std::endl;
        return;
    }

    vanetza::asn1::Cam message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cam;
    header.stationID = config_s.station_id;

    cam.camParameters.highFrequencyContainer.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;

    message->cam = cam;

    json j = message->cam;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    auto confirm = Application::request(request, std::move(packet));
    if (!confirm.accepted()) {
        throw std::runtime_error("CAM application data request failed");
    }

    const double time_now = (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0;

    cam_tx_counter->Increment();
    cam_tx_latency->Increment(time_now - time_reception);
}

void CamApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cam message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cam;
    header.stationID = config_s.station_id;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();

    CoopAwareness_t& cam = message->cam;
    cam.generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();

    //if (!position.confidence) {
    //    std::cerr << "Skipping CAM, because no good position is available, yet." << std::endl;
    //    return;
    //}

    BasicContainer_t& basic = cam.camParameters.basicContainer;
    basic.stationType = config_s.station_type;
    copy(position, basic.referencePosition);

    cam.camParameters.highFrequencyContainer.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;

    BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    bvc.heading.headingValue = 0;
    bvc.heading.headingConfidence = HeadingConfidence_equalOrWithinOneDegree;

    bvc.speed.speedValue = 0;
    bvc.speed.speedConfidence = SpeedConfidence_equalOrWithinOneCentimeterPerSec;

    bvc.driveDirection = DriveDirection_forward;
    bvc.longitudinalAcceleration.longitudinalAccelerationValue = LongitudinalAccelerationValue_unavailable;

    bvc.vehicleLength.vehicleLengthValue = VehicleLengthValue_unavailable;
    bvc.vehicleLength.vehicleLengthConfidenceIndication = VehicleLengthConfidenceIndication_noTrailerPresent;
    bvc.vehicleWidth = VehicleWidth_unavailable;

    bvc.curvature.curvatureValue = 0;
    bvc.curvature.curvatureConfidence = CurvatureConfidence_unavailable;
    bvc.curvatureCalculationMode = CurvatureCalculationMode_yawRateUsed;

    bvc.yawRate.yawRateValue = YawRateValue_unavailable;

    bvc.accelerationControl = new AccelerationControl_t();
    bvc.accelerationControl->buf = (uint8_t *) calloc(1, sizeof(uint8_t));
    bvc.accelerationControl->size = 1;
    bvc.accelerationControl->bits_unused = 1;
    *(bvc.accelerationControl->buf) = (uint8_t) 0b10111110;

    std::string error;
    if (!message.validate(error)) {
        throw std::runtime_error("Invalid high frequency CAM: %s" + error);
    }

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::CA;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    try {
        auto confirm = Application::request(request, std::move(packet));
        if (!confirm.accepted()) {
            throw std::runtime_error("CAM application data request failed");
        }
    } catch(std::runtime_error& e) {
        std::cout << "-- Vanetza UPER Encoding Error --\nCheck that the message format follows ETSI spec\n" << e.what() << std::endl;
    } catch(...) {
        std::cout << "-- Unexpected Error --\nVanetza couldn't send the requested message but did not throw a runtime error on UPER encode.\nNo other info available\n" << std::endl;
    }

    cam_tx_counter->Increment();
}
