#include "cam_application.hpp"
#include "asn1json.hpp"
#include "complete_packet.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;

Mqtt *mqtt_cam;
std::map<long, std::map<std::string, double>> persistence;

CamApplication::CamApplication(PositionProvider& positioning, Runtime& rt) :
    positioning_(positioning), runtime_(rt), cam_interval_(seconds(1))
{
    vector<string> subscription_topic_list;
    mqtt_cam = new Mqtt("pc-client", "vanetza/cam", subscription_topic_list, "192.168.98.1", 1883);
    persistence = {};
    schedule_timer();
}

void CamApplication::set_interval(Clock::duration interval)
{
    cam_interval_ = interval;
    runtime_.cancel(this);
    schedule_timer();
}

void CamApplication::print_generated_message(bool flag)
{
    print_tx_msg_ = flag;
}

void CamApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

CamApplication::PortType CamApplication::port()
{
    return btp::ports::CAM;
}

void CamApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    struct indication_visitor : public boost::static_visitor<CohesivePacket>
    {

        CohesivePacket operator()(CohesivePacket& packet)
        {
           std::cout << "f0_CAM rssi: " << packet.rssi << std::endl;
           return packet;
        }

        CohesivePacket operator()(ChunkPacket& packet) {return CohesivePacket(std::move(ByteBuffer()), OsiLayer::Physical);}

    } ivis;

    UpPacket* packet_ptr = packet.get();
    //indication_visitor i_visitor();
    CohesivePacket cp = boost::apply_visitor(ivis, *packet_ptr);

    asn1::PacketVisitor<asn1::Cam> visitor;
    std::shared_ptr<const asn1::Cam> cam = boost::apply_visitor(visitor, *packet);

    std::cout << "CAM application received a packet with " << (cam ? "decodable" : "broken") << " content" << std::endl;


    mqtt_cam->publish(buildJSON(*cam, cp.rssi));
}

// void to_json(json& j, const Heading& p) {
//     j = json{{"value", p.headingValue}, {"confidence", p.headingConfidence}};
// }

// void to_json(json& j, const BasicVehicleContainerHighFrequency& p) {
//     j = json{{"heading", p.heading}};
// }

// void from_json(const json& j, ItsPduHeader_t& p) {
//     j.at("messageID").get_to(p.messageID);
//     j.at("protocolVersion").get_to(p.protocolVersion);
//     j.at("stationID").get_to(p.stationID);
// }
 // namespace ns

void CamApplication::schedule_timer()
{
    runtime_.schedule(cam_interval_, std::bind(&CamApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CamApplication::buildJSON(vanetza::asn1::Cam message, int rssi) {
    
    ItsPduHeader_t& header = message->header;
    CoopAwareness_t& cam = message->cam;
    BasicContainer_t& basic = cam.camParameters.basicContainer;
    BasicVehicleContainerHighFrequency& bvc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency;
    AccelerationControl_t* acc = cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.accelerationControl;
    json j = cam;
    std::cout << "CAM JSON: " << j << std::endl;

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

    json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", new_info},
            {"rssi", rssi},
            {"test", {
                {"json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
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
            {"emergencyBrake", !!(*(bvc.accelerationControl->buf) & (1 << (7-2)))},
            {"collisionWarning", !!(*(bvc.accelerationControl->buf) & (1 << (7-3)))},
            {"accEngaged", !!(*(bvc.accelerationControl->buf) & (1 << (7-4)))},
            {"cruiseControl", !!(*(bvc.accelerationControl->buf) & (1 << (7-5)))},
            {"speedLimiter", !!(*(bvc.accelerationControl->buf) & (1 << (7-6)))},
            {"specialVehicle", {
                  {"publicTransport", {
                     {"embarkationStatus", false},
                     {"ptActivation", nullptr}
                  }
                  }
            }}
    };

    if(new_info) persistence[header.stationID] = {{"lat", (double) latitude}, {"lng", (double) longitude}, {"time", time_reception}};

    //std::cout << *(bvc.accelerationControl->buf) << std::endl;
    //::cout << json_payload.dump() << std::endl;

    return json_payload.dump();
}

void CamApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cam message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cam;
    header.stationID = 1; // some dummy value

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
    basic.stationType = StationType_passengerCar;
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

    

    std::cout << "hmm" << std::endl; 

    bvc.accelerationControl = new AccelerationControl_t();
    bvc.accelerationControl->buf = (uint8_t *) calloc(1, sizeof(uint8_t));
    bvc.accelerationControl->size = 1;
    bvc.accelerationControl->bits_unused = 1;
    *(bvc.accelerationControl->buf) = (uint8_t) 0b10111110;

    std::string error;
    if (!message.validate(error)) {
        throw std::runtime_error("Invalid high frequency CAM: %s" + error);
    }

    if (print_tx_msg_) {
        std::cout << "Generated CAM contains\n";
        print_indented(std::cout, message, "  ", 1);
    }

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
}
