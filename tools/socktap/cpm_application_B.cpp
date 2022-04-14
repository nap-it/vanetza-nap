#include "cpm_application.hpp"
//#include "asn1json.hpp"
#include <vanetza/btp/ports.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/packet_visitor.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.

using namespace vanetza;
using namespace vanetza::facilities;
using namespace std::chrono;
using json = nlohmann::json;

Mqtt *mqtt_cpm;

CpmApplication::CpmApplication(PositionProvider& positioning, Runtime& rt) :
    positioning_(positioning), runtime_(rt), cpm_interval_(seconds(1))
{
    vector<string> subscription_topic_list;
    //mqtt_cpm = new Mqtt("pc-client2", "vanetza/cpm", subscription_topic_list, "127.0.0.1", 1883);
    schedule_timer();
}

void CpmApplication::set_interval(Clock::duration interval)
{
    cpm_interval_ = interval;
    runtime_.cancel(this);
    schedule_timer();
}

void CpmApplication::print_generated_message(bool flag)
{
    print_tx_msg_ = flag;
}

void CpmApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

CpmApplication::PortType CpmApplication::port()
{
    return btp::ports::CPM;
}

void CpmApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    asn1::PacketVisitor<asn1::Cpm> visitor;
    std::shared_ptr<const asn1::Cpm> cpm = boost::apply_visitor(visitor, *packet);

    std::cout << "CPM application received a packet with " << (cpm ? "decodable" : "broken") << " content" << std::endl;
    //mqtt_cpm->publish(buildJSON(*cpm));
    std::cout << buildJSON(*cpm) <<std::endl;
}

void CpmApplication::schedule_timer()
{
    runtime_.schedule(cpm_interval_, std::bind(&CpmApplication::on_timer, this, std::placeholders::_1), this);
}

std::string CpmApplication::buildJSON(vanetza::asn1::Cpm message) {
    ItsPduHeader_t& header = message->header;
    CollectivePerceptionMessage_t & cpm = message->cpm;
    CpmManagementContainer_t & mgc = cpm.cpmParameters.managementContainer;
    ReferencePosition_t & rfp = mgc.referencePosition;
    // //json j = denm;
    // //std::cout << "DENM JSON: " << j << std::endl;

    nlohmann::json json_payload = {
            {"timestamp", time_reception},
            {"newInfo", true},
            {"rssi", -255},
            {"test", {
                {"json_timestamp", (double) duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count() / 1000.0}
            }
            },
            {"stationID", (long) header.stationID},
            {"stationType", (long) mgc.stationType},
            {"latitude", (long) rfp.latitude},
            {"longitude", (long) rfp.longitude},
    };
    return json_payload.dump();
}
 
void CpmApplication::on_timer(Clock::time_point)
{
    schedule_timer();
    vanetza::asn1::Cpm message;

    ItsPduHeader_t& header = message->header;
    header.protocolVersion = 2;
    header.messageID = ItsPduHeader__messageID_cpm;
    header.stationID = 99;

    const auto time_now = duration_cast<milliseconds>(runtime_.now().time_since_epoch());
    uint16_t gen_delta_time = time_now.count();
    message->cpm.generationDeltaTime = gen_delta_time * GenerationDeltaTime_oneMilliSec;

    auto position = positioning_.position_fix();

    CpmManagementContainer_t& management = message->cpm.cpmParameters.managementContainer;
    management.stationType = StationType_passengerCar;
    management.perceivedObjectContainerSegmentInfo; // optional
    copy(position, management.referencePosition);

    StationDataContainer_t& stationData = message->cpm.cpmParameters.stationDataContainer;

    OriginatingVehicleContainer_t& originatingVehicle = stationData.choice.originatingVehicleContainer;
    originatingVehicle.heading = 0;
    originatingVehicle.speed = 0;
    originatingVehicle.vehicleOrientationAngle;     // optional
    originatingVehicle.driveDirection; // default forward
    originatingVehicle.longitudinalAcceleration;    // optional
    originatingVehicle.lateralAcceleration;     // optional
    originatingVehicle.verticalAcceleration;    // optional
    originatingVehicle.yawRate;     // optional
    originatingVehicle.pitchAngle;  // optional
    originatingVehicle.rollAngle;   // optional
    originatingVehicle.vehicleLength;   // optional
    originatingVehicle.vehicleWidth;    // optional
    originatingVehicle.vehicleHeight;   // optional
    originatingVehicle.trailerDataContainer;    // optional

    OriginatingRSUContainer_t& originatingRsu = stationData.choice.originatingRSUContainer;

    IntersectionReferenceID_t& ir = originatingRsu.choice.intersectionReferenceId;
    ir.id;
    ir.region;  // optional

    RoadSegmentReferenceID_t& rsr = originatingRsu.choice.roadSegmentReferenceId;
    rsr.id;
    rsr.region; // optional

    SensorInformationContainer_t& sensorInfoContainer = message->cpm.cpmParameters.sensorInformationContainer;
    sensorInfoContainer.list;

    SensorInformation_t& sensorInfo;
    sensorInfo.sensorID;
    sensorInfo.type;
    sensorInfo.detectionArea;
    sensorInfo.freeSpaceConfidence; // optional

    int result = asn_set_add();
    if(result != 0){
        std::cout "ERROR" <<std::endl;
    }    

    PerceivedObjectContainer_t& perceivedObjContainer = message->cpm.cpmParameters.perceivedObjectContainer;
    perceivedObjContainer.list;

    PerceivedObject_t& perceivedObject;
    perceivedObject.objectID;
    perceivedObject.sensorIDList;   // optional
    perceivedObject.timeOfMeasurement;
    perceivedObject.objectAge;  // optional
    perceivedObject.objectConfidence;   // default 0
    perceivedObject.xDistance;
    perceivedObject.yDistance;
    perceivedObject.zDistance;  // optional
    perceivedObject.xSpeed;
    perceivedObject.ySpeed;
    perceivedObject.zSpeed;     // optional
    perceivedObject.xAcceleration;  // optional
    perceivedObject.yAcceleration;  // optional
    perceivedObject.zAcceleration;  // optional
    perceivedObject.yawAngle;   // optional
    perceivedObject.planarObjectDimension1; // optional
    perceivedObject.planarObjectDimension2; // optional
    perceivedObject.verticalObjectDimension;    // optional
    perceivedObject.objectRefPoint; // default 0
    perceivedObject.dynamicStatus;  // optional
    perceivedObject.classification; // optional
    perceivedObject.matchedPosition;    // optional

    int result = asn_set_add();
    if(result != 0){
        std::cout "ERROR" <<std::endl;
    }   

    DetectionArea_t& detectionArea;

    VehicleSensor_t& vehicleSensor = detectionArea.choice.vehicleSensor;
    vehicleSensor.refPointId;
    vehicleSensor.xSensorOffset;
    vehicleSensor.ySensorOffset;    // optional
    vehicleSensor.vehicleSensorPropertyList;

    VehicleSensorProperties_t& vehicleSensorProperties;
    vehicleSensorProperties.range;
    vehicleSensorProperties.horizontalOpeningAngleStart;
    vehicleSensorProperties.horizontalOpeningAngleEnd;
    vehicleSensorProperties.verticalOpeningAngleStart;
    vehicleSensorProperties.verticalOpeningAngleEnd;

    AreaRadial_t& areaRadial = detectionArea.choice.stationarySensorRadial;
    areaRadial.range;
    areaRadial.stationaryHorizontalOpeningAngleStart;
    areaRadial.stationaryHorizontalOpeningAngleEnd;
    areaRadial.verticalOpeningAngleStart;   // optional
    areaRadial.verticalOpeningAngleEnd; // optional
    areaRadial.sensorPositionOffset;    // optional
    areaRadial.sensorHeight;    // optional

    AreaPolygon_t& areaPolygon = detectionArea.choice.stationarySensorPolygon;
    areaPolygon.polyPointList;

    AreaCircular_t& areaCircular = detectionArea.choice.stationarySensorCircular;
    areaCircular.nodeCenterPoint;   // optional
    areaCircular.radius;

    AreaEllipse_t& areaEllipse = detectionArea.choice.stationarySensorEllipse;
    areaEllipse.nodeCenterPoint; // optional
    areaEllipse.semiMinorRangeLength;
    areaEllipse.semiMajorRangeLength;
    areaEllipse.semiMajorRangeOrientation;
    areaEllipse.semiHeight;     // optional

    AreaRectangle_t& areaRectangle = detectionArea.choice.stationarySensorRectangle;
    areaRectangle.nodeCenterPoint;  // optional
    areaRectangle.semiMinorRangeLength;
    areaRectangle.semiMajorRangeLength;
    areaRectangle.semiMajorRangeOrientation;
    areaRectangle.semiHeight;     // optional

    FreeSpaceAddendumContainer_t& freeSpaceAddendumContainer = message->cpm.cpmParameters.freeSpaceAddendumContainer;
    
    FreeSpaceAddendum_t& freeSpaceAddendum;
    freeSpaceAddendum.freeSpaceConfidence;
    freeSpaceAddendum.freeSpaceArea;
    freeSpaceAddendum.sensorIDList;
    freeSpaceAddendum.shadowingApplies;

    // FreeSpaceArea_t& freeSpaceArea;
    // AreaCircular_t& areaCircular = freeSpaceArea.choice.freeSpaceCircular;
    // areaCircular.nodeCenterPoint;   // optional
    // areaCircular.radius;

    ObjectDistanceWithConfidence_t& objDistConfidande;
    objDistConfidande.value;
    objDistConfidande.confidence;

    ObjectDimension_t& objDimension;
    objDimension.value;
    objDimension.confidence;

    CartesianAngle_t& cartAng;
    cartAng.value;
    cartAng.confidence;

    WGS84Angle_t& wgsAng;
    wgsAng.value;
    wgsAng.confidence;

    SpeedExtended_t& speedExt;
    speedExt.value;
    speedExt.confidence;

    TrailerData_t& trailerData;
    trailerData.refPointId;
    trailerData.hitchPointOffset;
    trailerData.frontOverhang;
    trailerData.rearOverhang;
    trailerData.trailerWidth;   // optional
    trailerData.hitchAngle; // optional

    LongitudinalLanePosition_t& longLanePos;
    longLanePos.longitudinalLanePositionValue;
    longLanePos.longitudinalLanePositionConfidence;

    MatchedPosition_t& matchedPos;
    matchedPos.laneID; // optional
    matchedPos.longitudinalLanePosition; // optional

    PerceivedObjectContainerSegmentInfo_t& perceivedObjectContainerSegmentInfo;
    perceivedObjectContainerSegmentInfo.totalMsgSegments;
    perceivedObjectContainerSegmentInfo.thisSegmentNum;

    DownPacketPtr packet { new DownPacket() };
    packet->layer(OsiLayer::Application) = std::move(message);

    DataRequest request;
    request.its_aid = aid::DEN;
    request.transport_type = geonet::TransportType::SHB;
    request.communication_profile = geonet::CommunicationProfile::ITS_G5;

    auto confirm = Application::request(request, std::move(packet));
    if (!confirm.accepted()) {
        throw std::runtime_error("CPM application data request failed");
    }

}
