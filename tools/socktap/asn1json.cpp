/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2022-04-04 09:05:26.917265
*/

#include "asn1json.hpp"
#include <boost/optional.hpp>

using json = nlohmann::json;

namespace nlohmann {
    template <typename T>
    struct adl_serializer<boost::optional<T>> {
        static void to_json(json& j, const boost::optional<T>& opt) {
            if (opt == boost::none) {
                j = nullptr;
            } else {
              j = *opt; // this will call adl_serializer<T>::to_json which will
                        // find the free function to_json in T's namespace!
            }
        }

        static void from_json(const json& j, boost::optional<T>& opt) {
            if (j.is_null()) {
                opt = boost::none;
            } else {
                opt = j.get<T>(); // same as above, but with
                                  // adl_serializer<T>::from_json
            }
        }
    };
}



/*
*   ItsPduHeader - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ItsPduHeader_t& p) {
    std::cout << "ItsPduHeader" << std::endl;
    j = json{{"protocolVersion", (p.protocolVersion)}, {"messageID", (p.messageID)}, {"stationID", (p.stationID)}};
    
}

void from_json(const json& j, ItsPduHeader_t& p) {
    std::cout << "ItsPduHeader" << std::endl;
    j.at("protocolVersion").get_to((p.protocolVersion));
    j.at("messageID").get_to((p.messageID));
    j.at("stationID").get_to((p.stationID));
    
}

/*
*   DeltaReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DeltaReferencePosition_t& p) {
    std::cout << "DeltaReferencePosition" << std::endl;
    j = json{{"deltaLatitude", (p.deltaLatitude)}, {"deltaLongitude", (p.deltaLongitude)}, {"deltaAltitude", (p.deltaAltitude)}};
    
}

void from_json(const json& j, DeltaReferencePosition_t& p) {
    std::cout << "DeltaReferencePosition" << std::endl;
    j.at("deltaLatitude").get_to((p.deltaLatitude));
    j.at("deltaLongitude").get_to((p.deltaLongitude));
    j.at("deltaAltitude").get_to((p.deltaAltitude));
    
}

/*
*   Altitude - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Altitude& p) {
    std::cout << "Altitude" << std::endl;
    j = json{{"altitudeValue", (p.altitudeValue)}, {"altitudeConfidence", (p.altitudeConfidence)}};
    
}

void from_json(const json& j, Altitude& p) {
    std::cout << "Altitude" << std::endl;
    j.at("altitudeValue").get_to((p.altitudeValue));
    j.at("altitudeConfidence").get_to((p.altitudeConfidence));
    
}

/*
*   PosConfidenceEllipse - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PosConfidenceEllipse& p) {
    std::cout << "PosConfidenceEllipse" << std::endl;
    j = json{{"semiMajorConfidence", (p.semiMajorConfidence)}, {"semiMinorConfidence", (p.semiMinorConfidence)}, {"semiMajorOrientation", (p.semiMajorOrientation)}};
    
}

void from_json(const json& j, PosConfidenceEllipse& p) {
    std::cout << "PosConfidenceEllipse" << std::endl;
    j.at("semiMajorConfidence").get_to((p.semiMajorConfidence));
    j.at("semiMinorConfidence").get_to((p.semiMinorConfidence));
    j.at("semiMajorOrientation").get_to((p.semiMajorOrientation));
    
}

/*
*   PathPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PathPoint& p) {
    std::cout << "PathPoint" << std::endl;
    j = json{{"pathPosition", (p.pathPosition)}};
    if (p.pathDeltaTime != 0) j["pathDeltaTime"] = *(p.pathDeltaTime);
}

void from_json(const json& j, PathPoint& p) {
    std::cout << "PathPoint" << std::endl;
    j.at("pathPosition").get_to((p.pathPosition));
    if (j.contains("pathDeltaTime")) { p.pathDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>(); j.at("pathDeltaTime").get_to(*(p.pathDeltaTime)); } 
    else { p.pathDeltaTime=nullptr; }
    
}

/*
*   PtActivationData - Type OCTET STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PtActivationData_t& p) {
    j = json{}; // TODO
}

void from_json(const json& j, PtActivationData_t& p) {
    // TODO
}

/*
*   AccelerationControl - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_AccelerationControl(const AccelerationControl_t p) {
    std::cout << "AccelerationControl bitstring" << std::endl;
    return json{{"brakePedalEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"gasPedalEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"emergencyBrakeEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"collisionWarningEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"accEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"cruiseControlEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"speedLimiterEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}};
}

void from_json_AccelerationControl(const json& j, AccelerationControl_t& p) {
    AccelerationControl_t* p_tmp = vanetza::asn1::allocate<AccelerationControl_t>();
    bool brakePedalEngaged;
    bool gasPedalEngaged;
    bool emergencyBrakeEngaged;
    bool collisionWarningEngaged;
    bool accEngaged;
    bool cruiseControlEngaged;
    bool speedLimiterEngaged;
    j.at("brakePedalEngaged").get_to((brakePedalEngaged));
    j.at("gasPedalEngaged").get_to((gasPedalEngaged));
    j.at("emergencyBrakeEngaged").get_to((emergencyBrakeEngaged));
    j.at("collisionWarningEngaged").get_to((collisionWarningEngaged));
    j.at("accEngaged").get_to((accEngaged));
    j.at("cruiseControlEngaged").get_to((cruiseControlEngaged));
    j.at("speedLimiterEngaged").get_to((speedLimiterEngaged));
    p_tmp->size = (7 / 8) + 1;
    std::cout << p_tmp->size << std::endl;
    p_tmp->bits_unused = 8 - (7 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (brakePedalEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (gasPedalEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (emergencyBrakeEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (collisionWarningEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (accEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (cruiseControlEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (speedLimiterEngaged) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
}

/*
*   CauseCode - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const CauseCode& p) {
    std::cout << "CauseCode" << std::endl;
    j = json{{"causeCode", (p.causeCode)}, {"subCauseCode", (p.subCauseCode)}};
    
}

void from_json(const json& j, CauseCode& p) {
    std::cout << "CauseCode" << std::endl;
    j.at("causeCode").get_to((p.causeCode));
    j.at("subCauseCode").get_to((p.subCauseCode));
    
}

/*
*   Curvature - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Curvature& p) {
    std::cout << "Curvature" << std::endl;
    j = json{{"curvatureValue", (p.curvatureValue)}, {"curvatureConfidence", (p.curvatureConfidence)}};
    
}

void from_json(const json& j, Curvature& p) {
    std::cout << "Curvature" << std::endl;
    j.at("curvatureValue").get_to((p.curvatureValue));
    j.at("curvatureConfidence").get_to((p.curvatureConfidence));
    
}

/*
*   Heading - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Heading& p) {
    std::cout << "Heading" << std::endl;
    j = json{{"headingValue", (p.headingValue)}, {"headingConfidence", (p.headingConfidence)}};
    
}

void from_json(const json& j, Heading& p) {
    std::cout << "Heading" << std::endl;
    j.at("headingValue").get_to((p.headingValue));
    j.at("headingConfidence").get_to((p.headingConfidence));
    
}

/*
*   DrivingLaneStatus - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_DrivingLaneStatus(const DrivingLaneStatus_t p) {
    std::cout << "DrivingLaneStatus bitstring" << std::endl;
    return json{};
}

void from_json_DrivingLaneStatus(const json& j, DrivingLaneStatus_t& p) {
    DrivingLaneStatus_t* p_tmp = vanetza::asn1::allocate<DrivingLaneStatus_t>();
    
    
    p_tmp->size = (0 / 8) + 1;
    p_tmp->bits_unused = 8 - (0 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
    p = *p_tmp;
}

/*
*   Speed - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Speed& p) {
    std::cout << "Speed" << std::endl;
    j = json{{"speedValue", (p.speedValue)}, {"speedConfidence", (p.speedConfidence)}};
    
}

void from_json(const json& j, Speed& p) {
    std::cout << "Speed" << std::endl;
    j.at("speedValue").get_to((p.speedValue));
    j.at("speedConfidence").get_to((p.speedConfidence));
    
}

/*
*   LongitudinalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const LongitudinalAcceleration& p) {
    std::cout << "LongitudinalAcceleration" << std::endl;
    j = json{{"longitudinalAccelerationValue", (p.longitudinalAccelerationValue)}, {"longitudinalAccelerationConfidence", (p.longitudinalAccelerationConfidence)}};
    
}

void from_json(const json& j, LongitudinalAcceleration& p) {
    std::cout << "LongitudinalAcceleration" << std::endl;
    j.at("longitudinalAccelerationValue").get_to((p.longitudinalAccelerationValue));
    j.at("longitudinalAccelerationConfidence").get_to((p.longitudinalAccelerationConfidence));
    
}

/*
*   LateralAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const LateralAcceleration& p) {
    std::cout << "LateralAcceleration" << std::endl;
    j = json{{"lateralAccelerationValue", (p.lateralAccelerationValue)}, {"lateralAccelerationConfidence", (p.lateralAccelerationConfidence)}};
    
}

void from_json(const json& j, LateralAcceleration& p) {
    std::cout << "LateralAcceleration" << std::endl;
    j.at("lateralAccelerationValue").get_to((p.lateralAccelerationValue));
    j.at("lateralAccelerationConfidence").get_to((p.lateralAccelerationConfidence));
    
}

/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VerticalAcceleration_t& p) {
    std::cout << "VerticalAcceleration" << std::endl;
    j = json{{"verticalAccelerationValue", (p.verticalAccelerationValue)}, {"verticalAccelerationConfidence", (p.verticalAccelerationConfidence)}};
    
}

void from_json(const json& j, VerticalAcceleration_t& p) {
    std::cout << "VerticalAcceleration" << std::endl;
    j.at("verticalAccelerationValue").get_to((p.verticalAccelerationValue));
    j.at("verticalAccelerationConfidence").get_to((p.verticalAccelerationConfidence));
    
}

/*
*   ExteriorLights - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_ExteriorLights(const ExteriorLights_t p) {
    std::cout << "ExteriorLights bitstring" << std::endl;
    return json{{"lowBeamHeadlightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"highBeamHeadlightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"leftTurnSignalOn", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"rightTurnSignalOn", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"daytimeRunningLightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"reverseLightOn", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"fogLightOn", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"parkingLightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}};
}

void from_json_ExteriorLights(const json& j, ExteriorLights_t& p) {
    ExteriorLights_t* p_tmp = vanetza::asn1::allocate<ExteriorLights_t>();
    bool lowBeamHeadlightsOn;
    bool highBeamHeadlightsOn;
    bool leftTurnSignalOn;
    bool rightTurnSignalOn;
    bool daytimeRunningLightsOn;
    bool reverseLightOn;
    bool fogLightOn;
    bool parkingLightsOn;
    j.at("lowBeamHeadlightsOn").get_to((lowBeamHeadlightsOn));
    j.at("highBeamHeadlightsOn").get_to((highBeamHeadlightsOn));
    j.at("leftTurnSignalOn").get_to((leftTurnSignalOn));
    j.at("rightTurnSignalOn").get_to((rightTurnSignalOn));
    j.at("daytimeRunningLightsOn").get_to((daytimeRunningLightsOn));
    j.at("reverseLightOn").get_to((reverseLightOn));
    j.at("fogLightOn").get_to((fogLightOn));
    j.at("parkingLightsOn").get_to((parkingLightsOn));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = 8 - (8 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (lowBeamHeadlightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (highBeamHeadlightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (leftTurnSignalOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (rightTurnSignalOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (daytimeRunningLightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (reverseLightOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (fogLightOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (parkingLightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    p = *p_tmp;
}

/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DangerousGoodsExtended& p) {
    std::cout << "DangerousGoodsExtended" << std::endl;
    j = json{{"dangerousGoodsType", (p.dangerousGoodsType)}, {"unNumber", (p.unNumber)}, {"elevatedTemperature", (p.elevatedTemperature)}, {"tunnelsRestricted", (p.tunnelsRestricted)}, {"limitedQuantity", (p.limitedQuantity)}};
    if (p.emergencyActionCode != 0) j["emergencyActionCode"] = *(p.emergencyActionCode);
    if (p.companyName != 0) j["companyName"] = *(p.companyName);
}

void from_json(const json& j, DangerousGoodsExtended& p) {
    std::cout << "DangerousGoodsExtended" << std::endl;
    j.at("dangerousGoodsType").get_to((p.dangerousGoodsType));
    j.at("unNumber").get_to((p.unNumber));
    j.at("elevatedTemperature").get_to((p.elevatedTemperature));
    j.at("tunnelsRestricted").get_to((p.tunnelsRestricted));
    j.at("limitedQuantity").get_to((p.limitedQuantity));
    if (j.contains("emergencyActionCode")) { p.emergencyActionCode = vanetza::asn1::allocate<IA5String_t>(); j.at("emergencyActionCode").get_to(*(p.emergencyActionCode)); } 
    else { p.emergencyActionCode=nullptr; }
    if (j.contains("companyName")) { p.companyName = vanetza::asn1::allocate<UTF8String_t>(); j.at("companyName").get_to(*(p.companyName)); } 
    else { p.companyName=nullptr; }
    
}

/*
*   SpecialTransportType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_SpecialTransportType(const SpecialTransportType_t p) {
    std::cout << "SpecialTransportType bitstring" << std::endl;
    return json{{"heavyLoad", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"excessWidth", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"excessLength", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"excessHeight", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}};
}

void from_json_SpecialTransportType(const json& j, SpecialTransportType_t& p) {
    SpecialTransportType_t* p_tmp = vanetza::asn1::allocate<SpecialTransportType_t>();
    bool heavyLoad;
    bool excessWidth;
    bool excessLength;
    bool excessHeight;
    j.at("heavyLoad").get_to((heavyLoad));
    j.at("excessWidth").get_to((excessWidth));
    j.at("excessLength").get_to((excessLength));
    j.at("excessHeight").get_to((excessHeight));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = 8 - (4 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (heavyLoad) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (excessWidth) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (excessLength) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (excessHeight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    p = *p_tmp;
}

/*
*   LightBarSirenInUse - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_LightBarSirenInUse(const LightBarSirenInUse_t p) {
    std::cout << "LightBarSirenInUse bitstring" << std::endl;
    return json{{"lightBarActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"sirenActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}};
}

void from_json_LightBarSirenInUse(const json& j, LightBarSirenInUse_t& p) {
    LightBarSirenInUse_t* p_tmp = vanetza::asn1::allocate<LightBarSirenInUse_t>();
    bool lightBarActivated;
    bool sirenActivated;
    j.at("lightBarActivated").get_to((lightBarActivated));
    j.at("sirenActivated").get_to((sirenActivated));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = 8 - (2 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (lightBarActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (sirenActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
}

/*
*   PositionOfOccupants - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_PositionOfOccupants(const PositionOfOccupants_t p) {
    std::cout << "PositionOfOccupants bitstring" << std::endl;
    return json{{"row1LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"row1RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"row1MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"row1NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"row1NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"row2LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"row2RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"row2MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"row2NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}, {"row2NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8))))}, {"row3LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8))))}, {"row3RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8))))}, {"row3MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (12 / 8))) & (1 << ((7 * ((12 / 8) + 1))-(12 % 8))))}, {"row3NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (13 / 8))) & (1 << ((7 * ((13 / 8) + 1))-(13 % 8))))}, {"row3NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (14 / 8))) & (1 << ((7 * ((14 / 8) + 1))-(14 % 8))))}, {"row4LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (15 / 8))) & (1 << ((7 * ((15 / 8) + 1))-(15 % 8))))}, {"row4RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (16 / 8))) & (1 << ((7 * ((16 / 8) + 1))-(16 % 8))))}, {"row4MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (17 / 8))) & (1 << ((7 * ((17 / 8) + 1))-(17 % 8))))}, {"row4NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (18 / 8))) & (1 << ((7 * ((18 / 8) + 1))-(18 % 8))))}, {"row4NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (19 / 8))) & (1 << ((7 * ((19 / 8) + 1))-(19 % 8))))}};
}

void from_json_PositionOfOccupants(const json& j, PositionOfOccupants_t& p) {
    PositionOfOccupants_t* p_tmp = vanetza::asn1::allocate<PositionOfOccupants_t>();
    bool row1LeftOccupied;
    bool row1RightOccupied;
    bool row1MidOccupied;
    bool row1NotDetectable;
    bool row1NotPresent;
    bool row2LeftOccupied;
    bool row2RightOccupied;
    bool row2MidOccupied;
    bool row2NotDetectable;
    bool row2NotPresent;
    bool row3LeftOccupied;
    bool row3RightOccupied;
    bool row3MidOccupied;
    bool row3NotDetectable;
    bool row3NotPresent;
    bool row4LeftOccupied;
    bool row4RightOccupied;
    bool row4MidOccupied;
    bool row4NotDetectable;
    bool row4NotPresent;
    j.at("row1LeftOccupied").get_to((row1LeftOccupied));
    j.at("row1RightOccupied").get_to((row1RightOccupied));
    j.at("row1MidOccupied").get_to((row1MidOccupied));
    j.at("row1NotDetectable").get_to((row1NotDetectable));
    j.at("row1NotPresent").get_to((row1NotPresent));
    j.at("row2LeftOccupied").get_to((row2LeftOccupied));
    j.at("row2RightOccupied").get_to((row2RightOccupied));
    j.at("row2MidOccupied").get_to((row2MidOccupied));
    j.at("row2NotDetectable").get_to((row2NotDetectable));
    j.at("row2NotPresent").get_to((row2NotPresent));
    j.at("row3LeftOccupied").get_to((row3LeftOccupied));
    j.at("row3RightOccupied").get_to((row3RightOccupied));
    j.at("row3MidOccupied").get_to((row3MidOccupied));
    j.at("row3NotDetectable").get_to((row3NotDetectable));
    j.at("row3NotPresent").get_to((row3NotPresent));
    j.at("row4LeftOccupied").get_to((row4LeftOccupied));
    j.at("row4RightOccupied").get_to((row4RightOccupied));
    j.at("row4MidOccupied").get_to((row4MidOccupied));
    j.at("row4NotDetectable").get_to((row4NotDetectable));
    j.at("row4NotPresent").get_to((row4NotPresent));
    p_tmp->size = (20 / 8) + 1;
    p_tmp->bits_unused = 8 - (20 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 2)) = (uint8_t) 0;
    if (row1LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (row1RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (row1MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (row1NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (row1NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (row2LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (row2RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (row2MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (row2NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (row2NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    if (row3LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    if (row3RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    if (row3MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    if (row3NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    if (row3NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    if (row4LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (row4RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 0);
    if (row4MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 1);
    if (row4NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 2);
    if (row4NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 3);
    p = *p_tmp;
}

/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleIdentification& p) {
    std::cout << "VehicleIdentification" << std::endl;
    j = json{};
    
}

void from_json(const json& j, VehicleIdentification& p) {
    std::cout << "VehicleIdentification" << std::endl;
    
    
}

/*
*   EnergyStorageType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_EnergyStorageType(const EnergyStorageType_t p) {
    std::cout << "EnergyStorageType bitstring" << std::endl;
    return json{{"hydrogenStorage", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"electricEnergyStorage", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"liquidPropaneGas", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"compressedNaturalGas", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"diesel", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"gasoline", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"ammonia", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}};
}

void from_json_EnergyStorageType(const json& j, EnergyStorageType_t& p) {
    EnergyStorageType_t* p_tmp = vanetza::asn1::allocate<EnergyStorageType_t>();
    bool hydrogenStorage;
    bool electricEnergyStorage;
    bool liquidPropaneGas;
    bool compressedNaturalGas;
    bool diesel;
    bool gasoline;
    bool ammonia;
    j.at("hydrogenStorage").get_to((hydrogenStorage));
    j.at("electricEnergyStorage").get_to((electricEnergyStorage));
    j.at("liquidPropaneGas").get_to((liquidPropaneGas));
    j.at("compressedNaturalGas").get_to((compressedNaturalGas));
    j.at("diesel").get_to((diesel));
    j.at("gasoline").get_to((gasoline));
    j.at("ammonia").get_to((ammonia));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = 8 - (7 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (hydrogenStorage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (electricEnergyStorage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (liquidPropaneGas) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (compressedNaturalGas) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (diesel) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (gasoline) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (ammonia) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
}

/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleLength_t& p) {
    std::cout << "VehicleLength" << std::endl;
    j = json{{"vehicleLengthValue", (p.vehicleLengthValue)}, {"vehicleLengthConfidenceIndication", (p.vehicleLengthConfidenceIndication)}};
    
}

void from_json(const json& j, VehicleLength_t& p) {
    std::cout << "VehicleLength" << std::endl;
    j.at("vehicleLengthValue").get_to((p.vehicleLengthValue));
    j.at("vehicleLengthConfidenceIndication").get_to((p.vehicleLengthConfidenceIndication));
    
}

/*
*   PathHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PathHistory& p) {
    std::cout << "PathHistory" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const PathPoint_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, PathHistory& p) {
    PathHistory* p_tmp = vanetza::asn1::allocate<PathHistory>();
    for (const auto& item : j.items())
    {
        PathPoint_t *element = vanetza::asn1::allocate<PathPoint_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   EmergencyPriority - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_EmergencyPriority(const EmergencyPriority_t p) {
    std::cout << "EmergencyPriority bitstring" << std::endl;
    return json{{"requestForRightOfWay", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"requestForFreeCrossingAtATrafficLight", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}};
}

void from_json_EmergencyPriority(const json& j, EmergencyPriority_t& p) {
    EmergencyPriority_t* p_tmp = vanetza::asn1::allocate<EmergencyPriority_t>();
    bool requestForRightOfWay;
    bool requestForFreeCrossingAtATrafficLight;
    j.at("requestForRightOfWay").get_to((requestForRightOfWay));
    j.at("requestForFreeCrossingAtATrafficLight").get_to((requestForFreeCrossingAtATrafficLight));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = 8 - (2 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (requestForRightOfWay) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (requestForFreeCrossingAtATrafficLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
}

/*
*   SteeringWheelAngle - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const SteeringWheelAngle& p) {
    std::cout << "SteeringWheelAngle" << std::endl;
    j = json{{"steeringWheelAngleValue", (p.steeringWheelAngleValue)}, {"steeringWheelAngleConfidence", (p.steeringWheelAngleConfidence)}};
    
}

void from_json(const json& j, SteeringWheelAngle& p) {
    std::cout << "SteeringWheelAngle" << std::endl;
    j.at("steeringWheelAngleValue").get_to((p.steeringWheelAngleValue));
    j.at("steeringWheelAngleConfidence").get_to((p.steeringWheelAngleConfidence));
    
}

/*
*   YawRate - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const YawRate& p) {
    std::cout << "YawRate" << std::endl;
    j = json{{"yawRateValue", (p.yawRateValue)}, {"yawRateConfidence", (p.yawRateConfidence)}};
    
}

void from_json(const json& j, YawRate& p) {
    std::cout << "YawRate" << std::endl;
    j.at("yawRateValue").get_to((p.yawRateValue));
    j.at("yawRateConfidence").get_to((p.yawRateConfidence));
    
}

/*
*   ActionID - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ActionID& p) {
    std::cout << "ActionID" << std::endl;
    j = json{{"originatingStationID", (p.originatingStationID)}, {"sequenceNumber", (p.sequenceNumber)}};
    
}

void from_json(const json& j, ActionID& p) {
    std::cout << "ActionID" << std::endl;
    j.at("originatingStationID").get_to((p.originatingStationID));
    j.at("sequenceNumber").get_to((p.sequenceNumber));
    
}

/*
*   ProtectedCommunicationZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ProtectedCommunicationZone& p) {
    std::cout << "ProtectedCommunicationZone" << std::endl;
    j = json{{"protectedZoneType", (p.protectedZoneType)}, {"protectedZoneLatitude", (p.protectedZoneLatitude)}, {"protectedZoneLongitude", (p.protectedZoneLongitude)}};
    if (p.protectedZoneRadius != 0) j["protectedZoneRadius"] = *(p.protectedZoneRadius);
    if (p.protectedZoneID != 0) j["protectedZoneID"] = *(p.protectedZoneID);
}

void from_json(const json& j, ProtectedCommunicationZone& p) {
    std::cout << "ProtectedCommunicationZone" << std::endl;
    j.at("protectedZoneType").get_to((p.protectedZoneType));
    j.at("protectedZoneLatitude").get_to((p.protectedZoneLatitude));
    j.at("protectedZoneLongitude").get_to((p.protectedZoneLongitude));
    if (j.contains("protectedZoneRadius")) { p.protectedZoneRadius = vanetza::asn1::allocate<ProtectedZoneRadius_t>(); j.at("protectedZoneRadius").get_to(*(p.protectedZoneRadius)); } 
    else { p.protectedZoneRadius=nullptr; }
    if (j.contains("protectedZoneID")) { p.protectedZoneID = vanetza::asn1::allocate<ProtectedZoneID_t>(); j.at("protectedZoneID").get_to(*(p.protectedZoneID)); } 
    else { p.protectedZoneID=nullptr; }
    
}

/*
*   Traces - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Traces& p) {
    std::cout << "Traces" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const PathHistory_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, Traces& p) {
    Traces* p_tmp = vanetza::asn1::allocate<Traces>();
    for (const auto& item : j.items())
    {
        PathHistory_t *element = vanetza::asn1::allocate<PathHistory_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   PositionOfPillars - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PositionOfPillars& p) {
    std::cout << "PositionOfPillars" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const PosPillar_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, PositionOfPillars& p) {
    PositionOfPillars* p_tmp = vanetza::asn1::allocate<PositionOfPillars>();
    for (const auto& item : j.items())
    {
        PosPillar_t *element = vanetza::asn1::allocate<PosPillar_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   RestrictedTypes - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const RestrictedTypes& p) {
    std::cout << "RestrictedTypes" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const StationType_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, RestrictedTypes& p) {
    RestrictedTypes* p_tmp = vanetza::asn1::allocate<RestrictedTypes>();
    for (const auto& item : j.items())
    {
        StationType_t *element = vanetza::asn1::allocate<StationType_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   EventPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const EventPoint& p) {
    std::cout << "EventPoint" << std::endl;
    j = json{{"eventPosition", (p.eventPosition)}, {"informationQuality", (p.informationQuality)}};
    if (p.eventDeltaTime != 0) j["eventDeltaTime"] = *(p.eventDeltaTime);
}

void from_json(const json& j, EventPoint& p) {
    std::cout << "EventPoint" << std::endl;
    j.at("eventPosition").get_to((p.eventPosition));
    if (j.contains("eventDeltaTime")) { p.eventDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>(); j.at("eventDeltaTime").get_to(*(p.eventDeltaTime)); } 
    else { p.eventDeltaTime=nullptr; }
    j.at("informationQuality").get_to((p.informationQuality));
    
}

/*
*   ProtectedCommunicationZonesRSU - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ProtectedCommunicationZonesRSU& p) {
    std::cout << "ProtectedCommunicationZonesRSU" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ProtectedCommunicationZone_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ProtectedCommunicationZonesRSU& p) {
    ProtectedCommunicationZonesRSU* p_tmp = vanetza::asn1::allocate<ProtectedCommunicationZonesRSU>();
    for (const auto& item : j.items())
    {
        ProtectedCommunicationZone_t *element = vanetza::asn1::allocate<ProtectedCommunicationZone_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   CenDsrcTollingZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const CenDsrcTollingZone& p) {
    std::cout << "CenDsrcTollingZone" << std::endl;
    j = json{{"protectedZoneLatitude", (p.protectedZoneLatitude)}, {"protectedZoneLongitude", (p.protectedZoneLongitude)}};
    if (p.cenDsrcTollingZoneID != 0) j["cenDsrcTollingZoneID"] = *(p.cenDsrcTollingZoneID);
}

void from_json(const json& j, CenDsrcTollingZone& p) {
    std::cout << "CenDsrcTollingZone" << std::endl;
    j.at("protectedZoneLatitude").get_to((p.protectedZoneLatitude));
    j.at("protectedZoneLongitude").get_to((p.protectedZoneLongitude));
    if (j.contains("cenDsrcTollingZoneID")) { p.cenDsrcTollingZoneID = vanetza::asn1::allocate<CenDsrcTollingZoneID_t>(); j.at("cenDsrcTollingZoneID").get_to(*(p.cenDsrcTollingZoneID)); } 
    else { p.cenDsrcTollingZoneID=nullptr; }
    
}

/*
*   BasicVehicleContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicVehicleContainerHighFrequency& p) {
    std::cout << "BasicVehicleContainerHighFrequency" << std::endl;
    j = json{{"heading", (p.heading)}, {"speed", (p.speed)}, {"driveDirection", (p.driveDirection)}, {"vehicleLength", (p.vehicleLength)}, {"vehicleWidth", (p.vehicleWidth)}, {"longitudinalAcceleration", (p.longitudinalAcceleration)}, {"curvature", (p.curvature)}, {"curvatureCalculationMode", (p.curvatureCalculationMode)}, {"yawRate", (p.yawRate)}};
    if (p.accelerationControl != 0) j["accelerationControl"] = to_json_AccelerationControl(*(p.accelerationControl));
    if (p.lanePosition != 0) j["lanePosition"] = *(p.lanePosition);
    if (p.steeringWheelAngle != 0) j["steeringWheelAngle"] = *(p.steeringWheelAngle);
    if (p.lateralAcceleration != 0) j["lateralAcceleration"] = *(p.lateralAcceleration);
    if (p.verticalAcceleration != 0) j["verticalAcceleration"] = *(p.verticalAcceleration);
    if (p.performanceClass != 0) j["performanceClass"] = *(p.performanceClass);
    if (p.cenDsrcTollingZone != 0) j["cenDsrcTollingZone"] = *(p.cenDsrcTollingZone);
}

void from_json(const json& j, BasicVehicleContainerHighFrequency& p) {
    std::cout << "BasicVehicleContainerHighFrequency" << std::endl;
    j.at("heading").get_to((p.heading));
    j.at("speed").get_to((p.speed));
    j.at("driveDirection").get_to((p.driveDirection));
    j.at("vehicleLength").get_to((p.vehicleLength));
    j.at("vehicleWidth").get_to((p.vehicleWidth));
    j.at("longitudinalAcceleration").get_to((p.longitudinalAcceleration));
    j.at("curvature").get_to((p.curvature));
    j.at("curvatureCalculationMode").get_to((p.curvatureCalculationMode));
    j.at("yawRate").get_to((p.yawRate));
    if (j.contains("lanePosition")) { p.lanePosition = vanetza::asn1::allocate<LanePosition_t>(); j.at("lanePosition").get_to(*(p.lanePosition)); } 
    else { p.lanePosition=nullptr; }
    if (j.contains("steeringWheelAngle")) { p.steeringWheelAngle = vanetza::asn1::allocate<SteeringWheelAngle_t>(); j.at("steeringWheelAngle").get_to(*(p.steeringWheelAngle)); } 
    else { p.steeringWheelAngle=nullptr; }
    if (j.contains("lateralAcceleration")) { p.lateralAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); j.at("lateralAcceleration").get_to(*(p.lateralAcceleration)); } 
    else { p.lateralAcceleration=nullptr; }
    if (j.contains("verticalAcceleration")) { p.verticalAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); j.at("verticalAcceleration").get_to(*(p.verticalAcceleration)); } 
    else { p.verticalAcceleration=nullptr; }
    if (j.contains("performanceClass")) { p.performanceClass = vanetza::asn1::allocate<PerformanceClass_t>(); j.at("performanceClass").get_to(*(p.performanceClass)); } 
    else { p.performanceClass=nullptr; }
    if (j.contains("cenDsrcTollingZone")) { p.cenDsrcTollingZone = vanetza::asn1::allocate<CenDsrcTollingZone_t>(); j.at("cenDsrcTollingZone").get_to(*(p.cenDsrcTollingZone)); } 
    else { p.cenDsrcTollingZone=nullptr; }
    if (j.contains("accelerationControl")) { p.accelerationControl = vanetza::asn1::allocate<AccelerationControl_t>(); from_json_AccelerationControl(j["accelerationControl"],*(p.accelerationControl)); } 
    else { p.accelerationControl=nullptr; }
    std::cout << p.accelerationControl->size << std::endl;
}

/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicVehicleContainerLowFrequency& p) {
    std::cout << "BasicVehicleContainerLowFrequency" << std::endl;
    j = json{{"vehicleRole", (p.vehicleRole)}, {"exteriorLights", to_json_ExteriorLights((p.exteriorLights))}, {"pathHistory", (p.pathHistory)}};
    
}

void from_json(const json& j, BasicVehicleContainerLowFrequency& p) {
    std::cout << "BasicVehicleContainerLowFrequency" << std::endl;
    j.at("vehicleRole").get_to((p.vehicleRole));
    j.at("pathHistory").get_to((p.pathHistory));
    from_json_ExteriorLights(j["exteriorLights"],(p.exteriorLights));
}

/*
*   SpecialTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SpecialTransportContainer& p) {
    std::cout << "SpecialTransportContainer" << std::endl;
    j = json{{"specialTransportType", to_json_SpecialTransportType((p.specialTransportType))}, {"lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse))}};
    
}

void from_json(const json& j, SpecialTransportContainer& p) {
    std::cout << "SpecialTransportContainer" << std::endl;
    
    from_json_SpecialTransportType(j["specialTransportType"],(p.specialTransportType));
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}

/*
*   DangerousGoodsContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const DangerousGoodsContainer& p) {
    std::cout << "DangerousGoodsContainer" << std::endl;
    j = json{{"dangerousGoodsBasic", (p.dangerousGoodsBasic)}};
    
}

void from_json(const json& j, DangerousGoodsContainer& p) {
    std::cout << "DangerousGoodsContainer" << std::endl;
    j.at("dangerousGoodsBasic").get_to((p.dangerousGoodsBasic));
    
}

/*
*   RescueContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RescueContainer& p) {
    std::cout << "RescueContainer" << std::endl;
    j = json{{"lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse))}};
    
}

void from_json(const json& j, RescueContainer& p) {
    std::cout << "RescueContainer" << std::endl;
    
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}

/*
*   EmergencyContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const EmergencyContainer& p) {
    std::cout << "EmergencyContainer" << std::endl;
    j = json{{"lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse))}};
    if (p.incidentIndication != 0) j["incidentIndication"] = *(p.incidentIndication);
    if (p.emergencyPriority != 0) j["emergencyPriority"] = to_json_EmergencyPriority(*(p.emergencyPriority));
}

void from_json(const json& j, EmergencyContainer& p) {
    std::cout << "EmergencyContainer" << std::endl;
    if (j.contains("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); j.at("incidentIndication").get_to(*(p.incidentIndication)); } 
    else { p.incidentIndication=nullptr; }
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
    if (j.contains("emergencyPriority")) { p.emergencyPriority = vanetza::asn1::allocate<EmergencyPriority_t>(); from_json_EmergencyPriority(j["emergencyPriority"],*(p.emergencyPriority)); } 
    else { p.emergencyPriority=nullptr; }
}

/*
*   SafetyCarContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SafetyCarContainer& p) {
    std::cout << "SafetyCarContainer" << std::endl;
    j = json{{"lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse))}};
    if (p.incidentIndication != 0) j["incidentIndication"] = *(p.incidentIndication);
    if (p.trafficRule != 0) j["trafficRule"] = *(p.trafficRule);
    if (p.speedLimit != 0) j["speedLimit"] = *(p.speedLimit);
}

void from_json(const json& j, SafetyCarContainer& p) {
    std::cout << "SafetyCarContainer" << std::endl;
    if (j.contains("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); j.at("incidentIndication").get_to(*(p.incidentIndication)); } 
    else { p.incidentIndication=nullptr; }
    if (j.contains("trafficRule")) { p.trafficRule = vanetza::asn1::allocate<TrafficRule_t>(); j.at("trafficRule").get_to(*(p.trafficRule)); } 
    else { p.trafficRule=nullptr; }
    if (j.contains("speedLimit")) { p.speedLimit = vanetza::asn1::allocate<SpeedLimit_t>(); j.at("speedLimit").get_to(*(p.speedLimit)); } 
    else { p.speedLimit=nullptr; }
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}

/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RSUContainerHighFrequency& p) {
    std::cout << "RSUContainerHighFrequency" << std::endl;
    j = json{};
    if (p.protectedCommunicationZonesRSU != 0) j["protectedCommunicationZonesRSU"] = *(p.protectedCommunicationZonesRSU);
}

void from_json(const json& j, RSUContainerHighFrequency& p) {
    std::cout << "RSUContainerHighFrequency" << std::endl;
    if (j.contains("protectedCommunicationZonesRSU")) { p.protectedCommunicationZonesRSU = vanetza::asn1::allocate<ProtectedCommunicationZonesRSU_t>(); j.at("protectedCommunicationZonesRSU").get_to(*(p.protectedCommunicationZonesRSU)); } 
    else { p.protectedCommunicationZonesRSU=nullptr; }
    
}

/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const LocationContainer& p) {
    std::cout << "LocationContainer" << std::endl;
    j = json{{"traces", (p.traces)}};
    if (p.eventSpeed != 0) j["eventSpeed"] = *(p.eventSpeed);
    if (p.eventPositionHeading != 0) j["eventPositionHeading"] = *(p.eventPositionHeading);
    if (p.roadType != 0) j["roadType"] = *(p.roadType);
}

void from_json(const json& j, LocationContainer& p) {
    std::cout << "LocationContainer" << std::endl;
    if (j.contains("eventSpeed")) { p.eventSpeed = vanetza::asn1::allocate<Speed_t>(); j.at("eventSpeed").get_to(*(p.eventSpeed)); } 
    else { p.eventSpeed=nullptr; }
    if (j.contains("eventPositionHeading")) { p.eventPositionHeading = vanetza::asn1::allocate<Heading_t>(); j.at("eventPositionHeading").get_to(*(p.eventPositionHeading)); } 
    else { p.eventPositionHeading=nullptr; }
    j.at("traces").get_to((p.traces));
    if (j.contains("roadType")) { p.roadType = vanetza::asn1::allocate<RoadType_t>(); j.at("roadType").get_to(*(p.roadType)); } 
    else { p.roadType=nullptr; }
    
}

/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ImpactReductionContainer& p) {
    std::cout << "ImpactReductionContainer" << std::endl;
    j = json{{"heightLonCarrLeft", (p.heightLonCarrLeft)}, {"heightLonCarrRight", (p.heightLonCarrRight)}, {"posLonCarrLeft", (p.posLonCarrLeft)}, {"posLonCarrRight", (p.posLonCarrRight)}, {"positionOfPillars", (p.positionOfPillars)}, {"posCentMass", (p.posCentMass)}, {"wheelBaseVehicle", (p.wheelBaseVehicle)}, {"turningRadius", (p.turningRadius)}, {"posFrontAx", (p.posFrontAx)}, {"positionOfOccupants", to_json_PositionOfOccupants((p.positionOfOccupants))}, {"vehicleMass", (p.vehicleMass)}, {"requestResponseIndication", (p.requestResponseIndication)}};
    
}

void from_json(const json& j, ImpactReductionContainer& p) {
    std::cout << "ImpactReductionContainer" << std::endl;
    j.at("heightLonCarrLeft").get_to((p.heightLonCarrLeft));
    j.at("heightLonCarrRight").get_to((p.heightLonCarrRight));
    j.at("posLonCarrLeft").get_to((p.posLonCarrLeft));
    j.at("posLonCarrRight").get_to((p.posLonCarrRight));
    j.at("positionOfPillars").get_to((p.positionOfPillars));
    j.at("posCentMass").get_to((p.posCentMass));
    j.at("wheelBaseVehicle").get_to((p.wheelBaseVehicle));
    j.at("turningRadius").get_to((p.turningRadius));
    j.at("posFrontAx").get_to((p.posFrontAx));
    j.at("vehicleMass").get_to((p.vehicleMass));
    j.at("requestResponseIndication").get_to((p.requestResponseIndication));
    from_json_PositionOfOccupants(j["positionOfOccupants"],(p.positionOfOccupants));
}

/*
*   StationaryVehicleContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const StationaryVehicleContainer& p) {
    std::cout << "StationaryVehicleContainer" << std::endl;
    j = json{};
    if (p.stationarySince != 0) j["stationarySince"] = *(p.stationarySince);
    if (p.stationaryCause != 0) j["stationaryCause"] = *(p.stationaryCause);
    if (p.carryingDangerousGoods != 0) j["carryingDangerousGoods"] = *(p.carryingDangerousGoods);
    if (p.numberOfOccupants != 0) j["numberOfOccupants"] = *(p.numberOfOccupants);
    if (p.vehicleIdentification != 0) j["vehicleIdentification"] = *(p.vehicleIdentification);
    if (p.energyStorageType != 0) j["energyStorageType"] = to_json_EnergyStorageType(*(p.energyStorageType));
}

void from_json(const json& j, StationaryVehicleContainer& p) {
    std::cout << "StationaryVehicleContainer" << std::endl;
    if (j.contains("stationarySince")) { p.stationarySince = vanetza::asn1::allocate<StationarySince_t>(); j.at("stationarySince").get_to(*(p.stationarySince)); } 
    else { p.stationarySince=nullptr; }
    if (j.contains("stationaryCause")) { p.stationaryCause = vanetza::asn1::allocate<CauseCode_t>(); j.at("stationaryCause").get_to(*(p.stationaryCause)); } 
    else { p.stationaryCause=nullptr; }
    if (j.contains("carryingDangerousGoods")) { p.carryingDangerousGoods = vanetza::asn1::allocate<DangerousGoodsExtended_t>(); j.at("carryingDangerousGoods").get_to(*(p.carryingDangerousGoods)); } 
    else { p.carryingDangerousGoods=nullptr; }
    if (j.contains("numberOfOccupants")) { p.numberOfOccupants = vanetza::asn1::allocate<NumberOfOccupants_t>(); j.at("numberOfOccupants").get_to(*(p.numberOfOccupants)); } 
    else { p.numberOfOccupants=nullptr; }
    if (j.contains("vehicleIdentification")) { p.vehicleIdentification = vanetza::asn1::allocate<VehicleIdentification_t>(); j.at("vehicleIdentification").get_to(*(p.vehicleIdentification)); } 
    else { p.vehicleIdentification=nullptr; }
    if (j.contains("energyStorageType")) { p.energyStorageType = vanetza::asn1::allocate<EnergyStorageType_t>(); from_json_EnergyStorageType(j["energyStorageType"],*(p.energyStorageType)); } 
    else { p.energyStorageType=nullptr; }
}

/*
*   ReferenceDenms - Type SEQUENCE OF
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ReferenceDenms& p) {
    std::cout << "ReferenceDenms" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ActionID_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ReferenceDenms& p) {
    ReferenceDenms* p_tmp = vanetza::asn1::allocate<ReferenceDenms>();
    for (const auto& item : j.items())
    {
        ActionID_t *element = vanetza::asn1::allocate<ActionID_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const AdvisorySpeed& p) {
    std::cout << "AdvisorySpeed" << std::endl;
    j = json{{"type", (p.type)}};
    if (p.speed != 0) j["speed"] = *(p.speed);
    if (p.confidence != 0) j["confidence"] = *(p.confidence);
    if (p.distance != 0) j["distance"] = *(p.distance);
    if (p.Class != 0) j["class"] = *(p.Class);
}

void from_json(const json& j, AdvisorySpeed& p) {
    std::cout << "AdvisorySpeed" << std::endl;
    j.at("type").get_to((p.type));
    if (j.contains("speed")) { p.speed = vanetza::asn1::allocate<SpeedAdvice_t>(); j.at("speed").get_to(*(p.speed)); } 
    else { p.speed=nullptr; }
    if (j.contains("confidence")) { p.confidence = vanetza::asn1::allocate<SpeedConfidence_t>(); j.at("confidence").get_to(*(p.confidence)); } 
    else { p.confidence=nullptr; }
    if (j.contains("distance")) { p.distance = vanetza::asn1::allocate<ZoneLength_t>(); j.at("distance").get_to(*(p.distance)); } 
    else { p.distance=nullptr; }
    if (j.contains("class")) { p.Class = vanetza::asn1::allocate<RestrictionClassID_t>(); j.at("class").get_to(*(p.Class)); } 
    else { p.Class=nullptr; }
    
}

/*
*   AdvisorySpeedList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const AdvisorySpeedList_t& p) {
    std::cout << "AdvisorySpeedList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const AdvisorySpeed_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, AdvisorySpeedList_t& p) {
    AdvisorySpeedList_t* p_tmp = vanetza::asn1::allocate<AdvisorySpeedList_t>();
    for (const auto& item : j.items())
    {
        AdvisorySpeed_t *element = vanetza::asn1::allocate<AdvisorySpeed_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane::ComputedLane__offsetXaxis& p) {
    std::cout << "ComputedLane::ComputedLane__offsetXaxis" << std::endl;
    j = json{};
    if (p.present == ComputedLane__offsetXaxis_PR_small) {
        j["small"] = p.choice.small;
    } else if (p.present == ComputedLane__offsetXaxis_PR_large) {
        j["large"] = p.choice.large;
    }
}

void from_json(const json& j, ComputedLane::ComputedLane__offsetXaxis& p) {
    std::cout << "ComputedLane::ComputedLane__offsetXaxis" << std::endl;
    if (j.contains("small")) {
        p.present = ComputedLane__offsetXaxis_PR_small;
        j.at("small").get_to(p.choice.small);
    } else if (j.contains("large")) {
        p.present = ComputedLane__offsetXaxis_PR_large;
        j.at("large").get_to(p.choice.large);
    } else {
        p.present = ComputedLane__offsetXaxis_PR_NOTHING;
    }
}

/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane::ComputedLane__offsetYaxis& p) {
    std::cout << "ComputedLane::ComputedLane__offsetYaxis" << std::endl;
    j = json{};
    if (p.present == ComputedLane__offsetYaxis_PR_small) {
        j["small"] = p.choice.small;
    } else if (p.present == ComputedLane__offsetYaxis_PR_large) {
        j["large"] = p.choice.large;
    }
}

void from_json(const json& j, ComputedLane::ComputedLane__offsetYaxis& p) {
    std::cout << "ComputedLane::ComputedLane__offsetYaxis" << std::endl;
    if (j.contains("small")) {
        p.present = ComputedLane__offsetYaxis_PR_small;
        j.at("small").get_to(p.choice.small);
    } else if (j.contains("large")) {
        p.present = ComputedLane__offsetYaxis_PR_large;
        j.at("large").get_to(p.choice.large);
    } else {
        p.present = ComputedLane__offsetYaxis_PR_NOTHING;
    }
}

/*
*   ComputedLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane_t& p) {
    std::cout << "ComputedLane" << std::endl;
    j = json{{"referenceLaneId", (p.referenceLaneId)}, {"offsetXaxis", (p.offsetXaxis)}, {"offsetYaxis", (p.offsetYaxis)}};
    if (p.rotateXY != 0) j["rotateXY"] = *(p.rotateXY);
    if (p.scaleXaxis != 0) j["scaleXaxis"] = *(p.scaleXaxis);
    if (p.scaleYaxis != 0) j["scaleYaxis"] = *(p.scaleYaxis);
}

void from_json(const json& j, ComputedLane_t& p) {
    std::cout << "ComputedLane" << std::endl;
    j.at("referenceLaneId").get_to((p.referenceLaneId));
    j.at("offsetXaxis").get_to((p.offsetXaxis));
    j.at("offsetYaxis").get_to((p.offsetYaxis));
    if (j.contains("rotateXY")) { p.rotateXY = vanetza::asn1::allocate<Angle_t>(); j.at("rotateXY").get_to(*(p.rotateXY)); } 
    else { p.rotateXY=nullptr; }
    if (j.contains("scaleXaxis")) { p.scaleXaxis = vanetza::asn1::allocate<Scale_B12_t>(); j.at("scaleXaxis").get_to(*(p.scaleXaxis)); } 
    else { p.scaleXaxis=nullptr; }
    if (j.contains("scaleYaxis")) { p.scaleYaxis = vanetza::asn1::allocate<Scale_B12_t>(); j.at("scaleYaxis").get_to(*(p.scaleYaxis)); } 
    else { p.scaleYaxis=nullptr; }
    
}

/*
*   ConnectionManeuverAssist - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectionManeuverAssist_t& p) {
    std::cout << "ConnectionManeuverAssist" << std::endl;
    j = json{{"connectionID", (p.connectionID)}};
    if (p.queueLength != 0) j["queueLength"] = *(p.queueLength);
    if (p.availableStorageLength != 0) j["availableStorageLength"] = *(p.availableStorageLength);
    if (p.waitOnStop != 0) j["waitOnStop"] = *(p.waitOnStop);
    if (p.pedBicycleDetect != 0) j["pedBicycleDetect"] = *(p.pedBicycleDetect);
}

void from_json(const json& j, ConnectionManeuverAssist_t& p) {
    std::cout << "ConnectionManeuverAssist" << std::endl;
    j.at("connectionID").get_to((p.connectionID));
    if (j.contains("queueLength")) { p.queueLength = vanetza::asn1::allocate<ZoneLength_t>(); j.at("queueLength").get_to(*(p.queueLength)); } 
    else { p.queueLength=nullptr; }
    if (j.contains("availableStorageLength")) { p.availableStorageLength = vanetza::asn1::allocate<ZoneLength_t>(); j.at("availableStorageLength").get_to(*(p.availableStorageLength)); } 
    else { p.availableStorageLength=nullptr; }
    if (j.contains("waitOnStop")) { p.waitOnStop = vanetza::asn1::allocate<WaitOnStopline_t>(); j.at("waitOnStop").get_to(*(p.waitOnStop)); } 
    else { p.waitOnStop=nullptr; }
    if (j.contains("pedBicycleDetect")) { p.pedBicycleDetect = vanetza::asn1::allocate<PedestrianBicycleDetect_t>(); j.at("pedBicycleDetect").get_to(*(p.pedBicycleDetect)); } 
    else { p.pedBicycleDetect=nullptr; }
    
}

/*
*   DataParameters - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const DataParameters_t& p) {
    std::cout << "DataParameters" << std::endl;
    j = json{};
    if (p.processMethod != 0) j["processMethod"] = *(p.processMethod);
    if (p.processAgency != 0) j["processAgency"] = *(p.processAgency);
    if (p.lastCheckedDate != 0) j["lastCheckedDate"] = *(p.lastCheckedDate);
    if (p.geoidUsed != 0) j["geoidUsed"] = *(p.geoidUsed);
}

void from_json(const json& j, DataParameters_t& p) {
    std::cout << "DataParameters" << std::endl;
    if (j.contains("processMethod")) { p.processMethod = vanetza::asn1::allocate<IA5String_t>(); j.at("processMethod").get_to(*(p.processMethod)); } 
    else { p.processMethod=nullptr; }
    if (j.contains("processAgency")) { p.processAgency = vanetza::asn1::allocate<IA5String_t>(); j.at("processAgency").get_to(*(p.processAgency)); } 
    else { p.processAgency=nullptr; }
    if (j.contains("lastCheckedDate")) { p.lastCheckedDate = vanetza::asn1::allocate<IA5String_t>(); j.at("lastCheckedDate").get_to(*(p.lastCheckedDate)); } 
    else { p.lastCheckedDate=nullptr; }
    if (j.contains("geoidUsed")) { p.geoidUsed = vanetza::asn1::allocate<IA5String_t>(); j.at("geoidUsed").get_to(*(p.geoidUsed)); } 
    else { p.geoidUsed=nullptr; }
    
}

/*
*   EnabledLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const EnabledLaneList_t& p) {
    std::cout << "EnabledLaneList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const LaneID_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, EnabledLaneList_t& p) {
    EnabledLaneList_t* p_tmp = vanetza::asn1::allocate<EnabledLaneList_t>();
    for (const auto& item : j.items())
    {
        LaneID_t *element = vanetza::asn1::allocate<LaneID_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   IntersectionAccessPoint - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionAccessPoint_t& p) {
    std::cout << "IntersectionAccessPoint" << std::endl;
    j = json{};
    if (p.present == IntersectionAccessPoint_PR_lane) {
        j["lane"] = p.choice.lane;
    } else if (p.present == IntersectionAccessPoint_PR_approach) {
        j["approach"] = p.choice.approach;
    } else if (p.present == IntersectionAccessPoint_PR_connection) {
        j["connection"] = p.choice.connection;
    }
}

void from_json(const json& j, IntersectionAccessPoint_t& p) {
    std::cout << "IntersectionAccessPoint" << std::endl;
    if (j.contains("lane")) {
        p.present = IntersectionAccessPoint_PR_lane;
        j.at("lane").get_to(p.choice.lane);
    } else if (j.contains("approach")) {
        p.present = IntersectionAccessPoint_PR_approach;
        j.at("approach").get_to(p.choice.approach);
    } else if (j.contains("connection")) {
        p.present = IntersectionAccessPoint_PR_connection;
        j.at("connection").get_to(p.choice.connection);
    } else {
        p.present = IntersectionAccessPoint_PR_NOTHING;
    }
}

/*
*   IntersectionReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionReferenceID& p) {
    std::cout << "IntersectionReferenceID" << std::endl;
    j = json{{"id", (p.id)}};
    if (p.region != 0) j["region"] = *(p.region);
}

void from_json(const json& j, IntersectionReferenceID& p) {
    std::cout << "IntersectionReferenceID" << std::endl;
    if (j.contains("region")) { p.region = vanetza::asn1::allocate<RoadRegulatorID_t>(); j.at("region").get_to(*(p.region)); } 
    else { p.region=nullptr; }
    j.at("id").get_to((p.id));
    
}

/*
*   LaneSharing - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneSharing(const LaneSharing_t p) {
    std::cout << "LaneSharing bitstring" << std::endl;
    return json{{"overlappingLaneDescriptionProvided", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"multipleLanesTreatedAsOneLane", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"otherNonMotorizedTrafficTypes", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"individualMotorizedVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"busVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"taxiVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"pedestriansTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"cyclistVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"trackedVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}, {"pedestrianTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8))))}};
}

void from_json_LaneSharing(const json& j, LaneSharing_t& p) {
    LaneSharing_t* p_tmp = vanetza::asn1::allocate<LaneSharing_t>();
    bool overlappingLaneDescriptionProvided;
    bool multipleLanesTreatedAsOneLane;
    bool otherNonMotorizedTrafficTypes;
    bool individualMotorizedVehicleTraffic;
    bool busVehicleTraffic;
    bool taxiVehicleTraffic;
    bool pedestriansTraffic;
    bool cyclistVehicleTraffic;
    bool trackedVehicleTraffic;
    bool pedestrianTraffic;
    j.at("overlappingLaneDescriptionProvided").get_to((overlappingLaneDescriptionProvided));
    j.at("multipleLanesTreatedAsOneLane").get_to((multipleLanesTreatedAsOneLane));
    j.at("otherNonMotorizedTrafficTypes").get_to((otherNonMotorizedTrafficTypes));
    j.at("individualMotorizedVehicleTraffic").get_to((individualMotorizedVehicleTraffic));
    j.at("busVehicleTraffic").get_to((busVehicleTraffic));
    j.at("taxiVehicleTraffic").get_to((taxiVehicleTraffic));
    j.at("pedestriansTraffic").get_to((pedestriansTraffic));
    j.at("cyclistVehicleTraffic").get_to((cyclistVehicleTraffic));
    j.at("trackedVehicleTraffic").get_to((trackedVehicleTraffic));
    j.at("pedestrianTraffic").get_to((pedestrianTraffic));
    p_tmp->size = (10 / 8) + 1;
    p_tmp->bits_unused = 8 - (10 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (overlappingLaneDescriptionProvided) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (multipleLanesTreatedAsOneLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (otherNonMotorizedTrafficTypes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (individualMotorizedVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (busVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (taxiVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (pedestriansTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (cyclistVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (trackedVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (pedestrianTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    p = *p_tmp;
}

/*
*   ManeuverAssistList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ManeuverAssistList& p) {
    std::cout << "ManeuverAssistList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ConnectionManeuverAssist_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ManeuverAssistList& p) {
    ManeuverAssistList* p_tmp = vanetza::asn1::allocate<ManeuverAssistList>();
    for (const auto& item : j.items())
    {
        ConnectionManeuverAssist_t *element = vanetza::asn1::allocate<ConnectionManeuverAssist_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Node_LLmD_64b& p) {
    std::cout << "Node_LLmD_64b" << std::endl;
    j = json{{"lon", (p.lon)}, {"lat", (p.lat)}};
    
}

void from_json(const json& j, Node_LLmD_64b& p) {
    std::cout << "Node_LLmD_64b" << std::endl;
    j.at("lon").get_to((p.lon));
    j.at("lat").get_to((p.lat));
    
}

/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const OverlayLaneList& p) {
    std::cout << "OverlayLaneList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const LaneID_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, OverlayLaneList& p) {
    OverlayLaneList* p_tmp = vanetza::asn1::allocate<OverlayLaneList>();
    for (const auto& item : j.items())
    {
        LaneID_t *element = vanetza::asn1::allocate<LaneID_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Position3D_t& p) {
    std::cout << "Position3D" << std::endl;
    j = json{{"lat", (p.lat)}, {"long", (p.Long)}};
    if (p.elevation != 0) j["elevation"] = *(p.elevation);
}

void from_json(const json& j, Position3D_t& p) {
    std::cout << "Position3D" << std::endl;
    j.at("lat").get_to((p.lat));
    j.at("long").get_to((p.Long));
    if (j.contains("elevation")) { p.elevation = vanetza::asn1::allocate<Elevation_t>(); j.at("elevation").get_to(*(p.elevation)); } 
    else { p.elevation=nullptr; }
    
}

/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionUserType& p) {
    std::cout << "RestrictionUserType" << std::endl;
    j = json{};
    if (p.present == RestrictionUserType_PR_basicType) {
        j["basicType"] = p.choice.basicType;
    }
}

void from_json(const json& j, RestrictionUserType& p) {
    std::cout << "RestrictionUserType" << std::endl;
    if (j.contains("basicType")) {
        p.present = RestrictionUserType_PR_basicType;
        j.at("basicType").get_to(p.choice.basicType);
    } else {
        p.present = RestrictionUserType_PR_NOTHING;
    }
}

/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegmentReferenceID& p) {
    std::cout << "RoadSegmentReferenceID" << std::endl;
    j = json{{"id", (p.id)}};
    if (p.region != 0) j["region"] = *(p.region);
}

void from_json(const json& j, RoadSegmentReferenceID& p) {
    std::cout << "RoadSegmentReferenceID" << std::endl;
    if (j.contains("region")) { p.region = vanetza::asn1::allocate<RoadRegulatorID_t>(); j.at("region").get_to(*(p.region)); } 
    else { p.region=nullptr; }
    j.at("id").get_to((p.id));
    
}

/*
*   TimeChangeDetails - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const TimeChangeDetails& p) {
    std::cout << "TimeChangeDetails" << std::endl;
    j = json{{"minEndTime", (p.minEndTime)}};
    if (p.startTime != 0) j["startTime"] = *(p.startTime);
    if (p.maxEndTime != 0) j["maxEndTime"] = *(p.maxEndTime);
    if (p.likelyTime != 0) j["likelyTime"] = *(p.likelyTime);
    if (p.confidence != 0) j["confidence"] = *(p.confidence);
    if (p.nextTime != 0) j["nextTime"] = *(p.nextTime);
}

void from_json(const json& j, TimeChangeDetails& p) {
    std::cout << "TimeChangeDetails" << std::endl;
    if (j.contains("startTime")) { p.startTime = vanetza::asn1::allocate<TimeMark_t>(); j.at("startTime").get_to(*(p.startTime)); } 
    else { p.startTime=nullptr; }
    j.at("minEndTime").get_to((p.minEndTime));
    if (j.contains("maxEndTime")) { p.maxEndTime = vanetza::asn1::allocate<TimeMark_t>(); j.at("maxEndTime").get_to(*(p.maxEndTime)); } 
    else { p.maxEndTime=nullptr; }
    if (j.contains("likelyTime")) { p.likelyTime = vanetza::asn1::allocate<TimeMark_t>(); j.at("likelyTime").get_to(*(p.likelyTime)); } 
    else { p.likelyTime=nullptr; }
    if (j.contains("confidence")) { p.confidence = vanetza::asn1::allocate<TimeIntervalConfidence_t>(); j.at("confidence").get_to(*(p.confidence)); } 
    else { p.confidence=nullptr; }
    if (j.contains("nextTime")) { p.nextTime = vanetza::asn1::allocate<TimeMark_t>(); j.at("nextTime").get_to(*(p.nextTime)); } 
    else { p.nextTime=nullptr; }
    
}

/*
*   TransmissionAndSpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const TransmissionAndSpeed_t& p) {
    std::cout << "TransmissionAndSpeed" << std::endl;
    j = json{{"transmisson", (p.transmisson)}, {"speed", (p.speed)}};
    
}

void from_json(const json& j, TransmissionAndSpeed_t& p) {
    std::cout << "TransmissionAndSpeed" << std::endl;
    j.at("transmisson").get_to((p.transmisson));
    j.at("speed").get_to((p.speed));
    
}

/*
*   VehicleID - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const VehicleID_t& p) {
    std::cout << "VehicleID" << std::endl;
    j = json{};
    if (p.present == VehicleID_PR_stationID) {
        j["stationID"] = p.choice.stationID;
    }
}

void from_json(const json& j, VehicleID_t& p) {
    std::cout << "VehicleID" << std::endl;
    if (j.contains("stationID")) {
        p.present = VehicleID_PR_stationID;
        j.at("stationID").get_to(p.choice.stationID);
    } else {
        p.present = VehicleID_PR_NOTHING;
    }
}

/*
*   AllowedManeuvers - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_AllowedManeuvers(const AllowedManeuvers_t p) {
    std::cout << "AllowedManeuvers bitstring" << std::endl;
    return json{{"maneuverStraightAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"maneuverLeftAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"maneuverRightAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"maneuverUTurnAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"maneuverLeftTurnOnRedAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"maneuverRightTurnOnRedAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"maneuverLaneChangeAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"maneuverNoStoppingAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"yieldAllwaysRequired", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}, {"goWithHalt", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8))))}, {"caution", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8))))}, {"reserved1", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8))))}};
}

void from_json_AllowedManeuvers(const json& j, AllowedManeuvers_t& p) {
    AllowedManeuvers_t* p_tmp = vanetza::asn1::allocate<AllowedManeuvers_t>();
    bool maneuverStraightAllowed;
    bool maneuverLeftAllowed;
    bool maneuverRightAllowed;
    bool maneuverUTurnAllowed;
    bool maneuverLeftTurnOnRedAllowed;
    bool maneuverRightTurnOnRedAllowed;
    bool maneuverLaneChangeAllowed;
    bool maneuverNoStoppingAllowed;
    bool yieldAllwaysRequired;
    bool goWithHalt;
    bool caution;
    bool reserved1;
    j.at("maneuverStraightAllowed").get_to((maneuverStraightAllowed));
    j.at("maneuverLeftAllowed").get_to((maneuverLeftAllowed));
    j.at("maneuverRightAllowed").get_to((maneuverRightAllowed));
    j.at("maneuverUTurnAllowed").get_to((maneuverUTurnAllowed));
    j.at("maneuverLeftTurnOnRedAllowed").get_to((maneuverLeftTurnOnRedAllowed));
    j.at("maneuverRightTurnOnRedAllowed").get_to((maneuverRightTurnOnRedAllowed));
    j.at("maneuverLaneChangeAllowed").get_to((maneuverLaneChangeAllowed));
    j.at("maneuverNoStoppingAllowed").get_to((maneuverNoStoppingAllowed));
    j.at("yieldAllwaysRequired").get_to((yieldAllwaysRequired));
    j.at("goWithHalt").get_to((goWithHalt));
    j.at("caution").get_to((caution));
    j.at("reserved1").get_to((reserved1));
    p_tmp->size = (12 / 8) + 1;
    p_tmp->bits_unused = 8 - (12 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (maneuverStraightAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (maneuverLeftAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (maneuverRightAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (maneuverUTurnAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (maneuverLeftTurnOnRedAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (maneuverRightTurnOnRedAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (maneuverLaneChangeAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (maneuverNoStoppingAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (yieldAllwaysRequired) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (goWithHalt) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    if (caution) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    if (reserved1) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    p = *p_tmp;
}

/*
*   IntersectionStatusObject - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_IntersectionStatusObject(const IntersectionStatusObject_t p) {
    std::cout << "IntersectionStatusObject bitstring" << std::endl;
    return json{{"manualControlIsEnabled", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"stopTimeIsActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"failureFlash", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"preemptIsActive", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"signalPriorityIsActive", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"fixedTimeOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"trafficDependentOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"standbyOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"failureMode", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}, {"off", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8))))}, {"recentMAPmessageUpdate", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8))))}, {"recentChangeInMAPassignedLanesIDsUsed", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8))))}, {"noValidMAPisAvailableAtThisTime", (bool) (*(p.buf + (sizeof(uint8_t) * (12 / 8))) & (1 << ((7 * ((12 / 8) + 1))-(12 % 8))))}, {"noValidSPATisAvailableAtThisTime", (bool) (*(p.buf + (sizeof(uint8_t) * (13 / 8))) & (1 << ((7 * ((13 / 8) + 1))-(13 % 8))))}};
}

void from_json_IntersectionStatusObject(const json& j, IntersectionStatusObject_t& p) {
    IntersectionStatusObject_t* p_tmp = vanetza::asn1::allocate<IntersectionStatusObject_t>();
    bool manualControlIsEnabled;
    bool stopTimeIsActivated;
    bool failureFlash;
    bool preemptIsActive;
    bool signalPriorityIsActive;
    bool fixedTimeOperation;
    bool trafficDependentOperation;
    bool standbyOperation;
    bool failureMode;
    bool off;
    bool recentMAPmessageUpdate;
    bool recentChangeInMAPassignedLanesIDsUsed;
    bool noValidMAPisAvailableAtThisTime;
    bool noValidSPATisAvailableAtThisTime;
    j.at("manualControlIsEnabled").get_to((manualControlIsEnabled));
    j.at("stopTimeIsActivated").get_to((stopTimeIsActivated));
    j.at("failureFlash").get_to((failureFlash));
    j.at("preemptIsActive").get_to((preemptIsActive));
    j.at("signalPriorityIsActive").get_to((signalPriorityIsActive));
    j.at("fixedTimeOperation").get_to((fixedTimeOperation));
    j.at("trafficDependentOperation").get_to((trafficDependentOperation));
    j.at("standbyOperation").get_to((standbyOperation));
    j.at("failureMode").get_to((failureMode));
    j.at("off").get_to((off));
    j.at("recentMAPmessageUpdate").get_to((recentMAPmessageUpdate));
    j.at("recentChangeInMAPassignedLanesIDsUsed").get_to((recentChangeInMAPassignedLanesIDsUsed));
    j.at("noValidMAPisAvailableAtThisTime").get_to((noValidMAPisAvailableAtThisTime));
    j.at("noValidSPATisAvailableAtThisTime").get_to((noValidSPATisAvailableAtThisTime));
    p_tmp->size = (14 / 8) + 1;
    p_tmp->bits_unused = 8 - (14 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (manualControlIsEnabled) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (stopTimeIsActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (failureFlash) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (preemptIsActive) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (signalPriorityIsActive) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (fixedTimeOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (trafficDependentOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (standbyOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (failureMode) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (off) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    if (recentMAPmessageUpdate) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    if (recentChangeInMAPassignedLanesIDsUsed) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    if (noValidMAPisAvailableAtThisTime) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    if (noValidSPATisAvailableAtThisTime) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    p = *p_tmp;
}

/*
*   LaneAttributes-Barrier - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Barrier(const LaneAttributes_Barrier_t p) {
    std::cout << "LaneAttributes-Barrier bitstring" << std::endl;
    return json{{"median-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"median", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"whiteLineHashing", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"stripedLines", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"doubleStripedLines", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"trafficCones", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"constructionBarrier", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"trafficChannels", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"lowCurbs", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}, {"highCurbs", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8))))}};
}

void from_json_LaneAttributes_Barrier(const json& j, LaneAttributes_Barrier_t& p) {
    LaneAttributes_Barrier_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Barrier_t>();
    bool median_RevocableLane;
    bool median;
    bool whiteLineHashing;
    bool stripedLines;
    bool doubleStripedLines;
    bool trafficCones;
    bool constructionBarrier;
    bool trafficChannels;
    bool lowCurbs;
    bool highCurbs;
    j.at("median-RevocableLane").get_to((median_RevocableLane));
    j.at("median").get_to((median));
    j.at("whiteLineHashing").get_to((whiteLineHashing));
    j.at("stripedLines").get_to((stripedLines));
    j.at("doubleStripedLines").get_to((doubleStripedLines));
    j.at("trafficCones").get_to((trafficCones));
    j.at("constructionBarrier").get_to((constructionBarrier));
    j.at("trafficChannels").get_to((trafficChannels));
    j.at("lowCurbs").get_to((lowCurbs));
    j.at("highCurbs").get_to((highCurbs));
    p_tmp->size = (10 / 8) + 1;
    p_tmp->bits_unused = 8 - (10 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (median_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (median) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (whiteLineHashing) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (stripedLines) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (doubleStripedLines) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (trafficCones) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (constructionBarrier) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (trafficChannels) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (lowCurbs) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (highCurbs) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    p = *p_tmp;
}

/*
*   LaneAttributes-Bike - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Bike(const LaneAttributes_Bike_t p) {
    std::cout << "LaneAttributes-Bike bitstring" << std::endl;
    return json{{"bikeRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"pedestrianUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"isBikeFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"fixedCycleTime", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"biDirectionalCycleTimes", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"isolatedByBarrier", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"unsignalizedSegmentsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}};
}

void from_json_LaneAttributes_Bike(const json& j, LaneAttributes_Bike_t& p) {
    LaneAttributes_Bike_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Bike_t>();
    bool bikeRevocableLane;
    bool pedestrianUseAllowed;
    bool isBikeFlyOverLane;
    bool fixedCycleTime;
    bool biDirectionalCycleTimes;
    bool isolatedByBarrier;
    bool unsignalizedSegmentsPresent;
    j.at("bikeRevocableLane").get_to((bikeRevocableLane));
    j.at("pedestrianUseAllowed").get_to((pedestrianUseAllowed));
    j.at("isBikeFlyOverLane").get_to((isBikeFlyOverLane));
    j.at("fixedCycleTime").get_to((fixedCycleTime));
    j.at("biDirectionalCycleTimes").get_to((biDirectionalCycleTimes));
    j.at("isolatedByBarrier").get_to((isolatedByBarrier));
    j.at("unsignalizedSegmentsPresent").get_to((unsignalizedSegmentsPresent));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = 8 - (7 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (bikeRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (pedestrianUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (isBikeFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (fixedCycleTime) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (biDirectionalCycleTimes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (isolatedByBarrier) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (unsignalizedSegmentsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
}

/*
*   LaneAttributes-Crosswalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Crosswalk(const LaneAttributes_Crosswalk_t p) {
    std::cout << "LaneAttributes-Crosswalk bitstring" << std::endl;
    return json{{"crosswalkRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"bicyleUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"isXwalkFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"fixedCycleTime", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"biDirectionalCycleTimes", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"hasPushToWalkButton", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"audioSupport", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"rfSignalRequestPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}, {"unsignalizedSegmentsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8))))}};
}

void from_json_LaneAttributes_Crosswalk(const json& j, LaneAttributes_Crosswalk_t& p) {
    LaneAttributes_Crosswalk_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Crosswalk_t>();
    bool crosswalkRevocableLane;
    bool bicyleUseAllowed;
    bool isXwalkFlyOverLane;
    bool fixedCycleTime;
    bool biDirectionalCycleTimes;
    bool hasPushToWalkButton;
    bool audioSupport;
    bool rfSignalRequestPresent;
    bool unsignalizedSegmentsPresent;
    j.at("crosswalkRevocableLane").get_to((crosswalkRevocableLane));
    j.at("bicyleUseAllowed").get_to((bicyleUseAllowed));
    j.at("isXwalkFlyOverLane").get_to((isXwalkFlyOverLane));
    j.at("fixedCycleTime").get_to((fixedCycleTime));
    j.at("biDirectionalCycleTimes").get_to((biDirectionalCycleTimes));
    j.at("hasPushToWalkButton").get_to((hasPushToWalkButton));
    j.at("audioSupport").get_to((audioSupport));
    j.at("rfSignalRequestPresent").get_to((rfSignalRequestPresent));
    j.at("unsignalizedSegmentsPresent").get_to((unsignalizedSegmentsPresent));
    p_tmp->size = (9 / 8) + 1;
    p_tmp->bits_unused = 8 - (9 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (crosswalkRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (bicyleUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (isXwalkFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (fixedCycleTime) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (biDirectionalCycleTimes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (hasPushToWalkButton) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (audioSupport) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (rfSignalRequestPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (unsignalizedSegmentsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    p = *p_tmp;
}

/*
*   LaneAttributes-Parking - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Parking(const LaneAttributes_Parking_t p) {
    std::cout << "LaneAttributes-Parking bitstring" << std::endl;
    return json{{"parkingRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"parallelParkingInUse", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"headInParkingInUse", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"doNotParkZone", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"parkingForBusUse", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"parkingForTaxiUse", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"noPublicParkingUse", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}};
}

void from_json_LaneAttributes_Parking(const json& j, LaneAttributes_Parking_t& p) {
    LaneAttributes_Parking_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Parking_t>();
    bool parkingRevocableLane;
    bool parallelParkingInUse;
    bool headInParkingInUse;
    bool doNotParkZone;
    bool parkingForBusUse;
    bool parkingForTaxiUse;
    bool noPublicParkingUse;
    j.at("parkingRevocableLane").get_to((parkingRevocableLane));
    j.at("parallelParkingInUse").get_to((parallelParkingInUse));
    j.at("headInParkingInUse").get_to((headInParkingInUse));
    j.at("doNotParkZone").get_to((doNotParkZone));
    j.at("parkingForBusUse").get_to((parkingForBusUse));
    j.at("parkingForTaxiUse").get_to((parkingForTaxiUse));
    j.at("noPublicParkingUse").get_to((noPublicParkingUse));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = 8 - (7 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (parkingRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (parallelParkingInUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (headInParkingInUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (doNotParkZone) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (parkingForBusUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (parkingForTaxiUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (noPublicParkingUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
}

/*
*   LaneAttributes-Sidewalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Sidewalk(const LaneAttributes_Sidewalk_t p) {
    std::cout << "LaneAttributes-Sidewalk bitstring" << std::endl;
    return json{{"sidewalk-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"bicyleUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"isSidewalkFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"walkBikes", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}};
}

void from_json_LaneAttributes_Sidewalk(const json& j, LaneAttributes_Sidewalk_t& p) {
    LaneAttributes_Sidewalk_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Sidewalk_t>();
    bool sidewalk_RevocableLane;
    bool bicyleUseAllowed;
    bool isSidewalkFlyOverLane;
    bool walkBikes;
    j.at("sidewalk-RevocableLane").get_to((sidewalk_RevocableLane));
    j.at("bicyleUseAllowed").get_to((bicyleUseAllowed));
    j.at("isSidewalkFlyOverLane").get_to((isSidewalkFlyOverLane));
    j.at("walkBikes").get_to((walkBikes));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = 8 - (4 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (sidewalk_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (bicyleUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (isSidewalkFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (walkBikes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    p = *p_tmp;
}

/*
*   LaneAttributes-Striping - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Striping(const LaneAttributes_Striping_t p) {
    std::cout << "LaneAttributes-Striping bitstring" << std::endl;
    return json{{"stripeToConnectingLanesRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"stripeDrawOnLeft", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"stripeDrawOnRight", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"stripeToConnectingLanesLeft", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"stripeToConnectingLanesRight", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"stripeToConnectingLanesAhead", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}};
}

void from_json_LaneAttributes_Striping(const json& j, LaneAttributes_Striping_t& p) {
    LaneAttributes_Striping_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Striping_t>();
    bool stripeToConnectingLanesRevocableLane;
    bool stripeDrawOnLeft;
    bool stripeDrawOnRight;
    bool stripeToConnectingLanesLeft;
    bool stripeToConnectingLanesRight;
    bool stripeToConnectingLanesAhead;
    j.at("stripeToConnectingLanesRevocableLane").get_to((stripeToConnectingLanesRevocableLane));
    j.at("stripeDrawOnLeft").get_to((stripeDrawOnLeft));
    j.at("stripeDrawOnRight").get_to((stripeDrawOnRight));
    j.at("stripeToConnectingLanesLeft").get_to((stripeToConnectingLanesLeft));
    j.at("stripeToConnectingLanesRight").get_to((stripeToConnectingLanesRight));
    j.at("stripeToConnectingLanesAhead").get_to((stripeToConnectingLanesAhead));
    p_tmp->size = (6 / 8) + 1;
    p_tmp->bits_unused = 8 - (6 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (stripeToConnectingLanesRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (stripeDrawOnLeft) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (stripeDrawOnRight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (stripeToConnectingLanesLeft) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (stripeToConnectingLanesRight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (stripeToConnectingLanesAhead) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    p = *p_tmp;
}

/*
*   LaneAttributes-TrackedVehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_TrackedVehicle(const LaneAttributes_TrackedVehicle_t p) {
    std::cout << "LaneAttributes-TrackedVehicle bitstring" << std::endl;
    return json{{"spec-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"spec-commuterRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"spec-lightRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"spec-heavyRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"spec-otherRailType", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}};
}

void from_json_LaneAttributes_TrackedVehicle(const json& j, LaneAttributes_TrackedVehicle_t& p) {
    LaneAttributes_TrackedVehicle_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_TrackedVehicle_t>();
    bool spec_RevocableLane;
    bool spec_commuterRailRoadTrack;
    bool spec_lightRailRoadTrack;
    bool spec_heavyRailRoadTrack;
    bool spec_otherRailType;
    j.at("spec-RevocableLane").get_to((spec_RevocableLane));
    j.at("spec-commuterRailRoadTrack").get_to((spec_commuterRailRoadTrack));
    j.at("spec-lightRailRoadTrack").get_to((spec_lightRailRoadTrack));
    j.at("spec-heavyRailRoadTrack").get_to((spec_heavyRailRoadTrack));
    j.at("spec-otherRailType").get_to((spec_otherRailType));
    p_tmp->size = (5 / 8) + 1;
    p_tmp->bits_unused = 8 - (5 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (spec_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (spec_commuterRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (spec_lightRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (spec_heavyRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (spec_otherRailType) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    p = *p_tmp;
}

/*
*   LaneAttributes-Vehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Vehicle(const LaneAttributes_Vehicle_t p) {
    std::cout << "LaneAttributes-Vehicle bitstring" << std::endl;
    return json{{"isVehicleRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"isVehicleFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"hovLaneUseOnly", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"restrictedToBusUse", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"restrictedToTaxiUse", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"restrictedFromPublicUse", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}, {"hasIRbeaconCoverage", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8))))}, {"permissionOnRequest", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8))))}};
}

void from_json_LaneAttributes_Vehicle(const json& j, LaneAttributes_Vehicle_t& p) {
    LaneAttributes_Vehicle_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Vehicle_t>();
    bool isVehicleRevocableLane;
    bool isVehicleFlyOverLane;
    bool hovLaneUseOnly;
    bool restrictedToBusUse;
    bool restrictedToTaxiUse;
    bool restrictedFromPublicUse;
    bool hasIRbeaconCoverage;
    bool permissionOnRequest;
    j.at("isVehicleRevocableLane").get_to((isVehicleRevocableLane));
    j.at("isVehicleFlyOverLane").get_to((isVehicleFlyOverLane));
    j.at("hovLaneUseOnly").get_to((hovLaneUseOnly));
    j.at("restrictedToBusUse").get_to((restrictedToBusUse));
    j.at("restrictedToTaxiUse").get_to((restrictedToTaxiUse));
    j.at("restrictedFromPublicUse").get_to((restrictedFromPublicUse));
    j.at("hasIRbeaconCoverage").get_to((hasIRbeaconCoverage));
    j.at("permissionOnRequest").get_to((permissionOnRequest));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = 8 - (8 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (isVehicleRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (isVehicleFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (hovLaneUseOnly) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (restrictedToBusUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (restrictedToTaxiUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (restrictedFromPublicUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (hasIRbeaconCoverage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (permissionOnRequest) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    p = *p_tmp;
}

/*
*   LaneDirection - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneDirection(const LaneDirection_t p) {
    std::cout << "LaneDirection bitstring" << std::endl;
    return json{{"ingressPath", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"egressPath", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}};
}

void from_json_LaneDirection(const json& j, LaneDirection_t& p) {
    LaneDirection_t* p_tmp = vanetza::asn1::allocate<LaneDirection_t>();
    bool ingressPath;
    bool egressPath;
    j.at("ingressPath").get_to((ingressPath));
    j.at("egressPath").get_to((egressPath));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = 8 - (2 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (ingressPath) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (egressPath) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
}

/*
*   TransitVehicleStatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_TransitVehicleStatus(const TransitVehicleStatus_t p) {
    std::cout << "TransitVehicleStatus bitstring" << std::endl;
    return json{{"loading", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8))))}, {"anADAuse", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8))))}, {"aBikeLoad", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8))))}, {"doorOpen", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8))))}, {"charging", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8))))}, {"atStopLine", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8))))}};
}

void from_json_TransitVehicleStatus(const json& j, TransitVehicleStatus_t& p) {
    TransitVehicleStatus_t* p_tmp = vanetza::asn1::allocate<TransitVehicleStatus_t>();
    bool loading;
    bool anADAuse;
    bool aBikeLoad;
    bool doorOpen;
    bool charging;
    bool atStopLine;
    j.at("loading").get_to((loading));
    j.at("anADAuse").get_to((anADAuse));
    j.at("aBikeLoad").get_to((aBikeLoad));
    j.at("doorOpen").get_to((doorOpen));
    j.at("charging").get_to((charging));
    j.at("atStopLine").get_to((atStopLine));
    p_tmp->size = (6 / 8) + 1;
    p_tmp->bits_unused = 8 - (6 % 8);
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (loading) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (anADAuse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (aBikeLoad) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (doorOpen) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (charging) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (atStopLine) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    p = *p_tmp;
}

/*
*   Node-XY-20b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_20b& p) {
    std::cout << "Node_XY_20b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_20b& p) {
    std::cout << "Node_XY_20b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_22b& p) {
    std::cout << "Node_XY_22b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_22b& p) {
    std::cout << "Node_XY_22b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_24b& p) {
    std::cout << "Node_XY_24b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_24b& p) {
    std::cout << "Node_XY_24b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_26b& p) {
    std::cout << "Node_XY_26b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_26b& p) {
    std::cout << "Node_XY_26b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_28b& p) {
    std::cout << "Node_XY_28b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_28b& p) {
    std::cout << "Node_XY_28b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_32b& p) {
    std::cout << "Node_XY_32b" << std::endl;
    j = json{{"x", (p.x)}, {"y", (p.y)}};
    
}

void from_json(const json& j, Node_XY_32b& p) {
    std::cout << "Node_XY_32b" << std::endl;
    j.at("x").get_to((p.x));
    j.at("y").get_to((p.y));
    
}

/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeAttributeXYList& p) {
    std::cout << "NodeAttributeXYList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const NodeAttributeXY_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, NodeAttributeXYList& p) {
    NodeAttributeXYList* p_tmp = vanetza::asn1::allocate<NodeAttributeXYList>();
    for (const auto& item : j.items())
    {
        NodeAttributeXY_t *element = vanetza::asn1::allocate<NodeAttributeXY_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const RegulatorySpeedLimit& p) {
    std::cout << "RegulatorySpeedLimit" << std::endl;
    j = json{{"type", (p.type)}, {"speed", (p.speed)}};
    
}

void from_json(const json& j, RegulatorySpeedLimit& p) {
    std::cout << "RegulatorySpeedLimit" << std::endl;
    j.at("type").get_to((p.type));
    j.at("speed").get_to((p.speed));
    
}

/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const SegmentAttributeXYList& p) {
    std::cout << "SegmentAttributeXYList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const SegmentAttributeXY_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, SegmentAttributeXYList& p) {
    SegmentAttributeXYList* p_tmp = vanetza::asn1::allocate<SegmentAttributeXYList>();
    for (const auto& item : j.items())
    {
        SegmentAttributeXY_t *element = vanetza::asn1::allocate<SegmentAttributeXY_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const SpeedLimitList& p) {
    std::cout << "SpeedLimitList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const RegulatorySpeedLimit_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, SpeedLimitList& p) {
    SpeedLimitList* p_tmp = vanetza::asn1::allocate<SpeedLimitList>();
    for (const auto& item : j.items())
    {
        RegulatorySpeedLimit_t *element = vanetza::asn1::allocate<RegulatorySpeedLimit_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   OriginatingRSUContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OriginatingRSUContainer& p) {
    std::cout << "OriginatingRSUContainer" << std::endl;
    j = json{};
    if (p.present == OriginatingRSUContainer_PR_intersectionReferenceId) {
        j["intersectionReferenceId"] = p.choice.intersectionReferenceId;
    } else if (p.present == OriginatingRSUContainer_PR_roadSegmentReferenceId) {
        j["roadSegmentReferenceId"] = p.choice.roadSegmentReferenceId;
    }
}

void from_json(const json& j, OriginatingRSUContainer& p) {
    std::cout << "OriginatingRSUContainer" << std::endl;
    if (j.contains("intersectionReferenceId")) {
        p.present = OriginatingRSUContainer_PR_intersectionReferenceId;
        j.at("intersectionReferenceId").get_to(p.choice.intersectionReferenceId);
    } else if (j.contains("roadSegmentReferenceId")) {
        p.present = OriginatingRSUContainer_PR_roadSegmentReferenceId;
        j.at("roadSegmentReferenceId").get_to(p.choice.roadSegmentReferenceId);
    } else {
        p.present = OriginatingRSUContainer_PR_NOTHING;
    }
}

/*
*   VehicleSensorProperties - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensorProperties& p) {
    std::cout << "VehicleSensorProperties" << std::endl;
    j = json{{"range", (p.range)}, {"horizontalOpeningAngleStart", (p.horizontalOpeningAngleStart)}, {"horizontalOpeningAngleEnd", (p.horizontalOpeningAngleEnd)}};
    if (p.verticalOpeningAngleStart != 0) j["verticalOpeningAngleStart"] = *(p.verticalOpeningAngleStart);
    if (p.verticalOpeningAngleEnd != 0) j["verticalOpeningAngleEnd"] = *(p.verticalOpeningAngleEnd);
}

void from_json(const json& j, VehicleSensorProperties& p) {
    std::cout << "VehicleSensorProperties" << std::endl;
    j.at("range").get_to((p.range));
    j.at("horizontalOpeningAngleStart").get_to((p.horizontalOpeningAngleStart));
    j.at("horizontalOpeningAngleEnd").get_to((p.horizontalOpeningAngleEnd));
    if (j.contains("verticalOpeningAngleStart")) { p.verticalOpeningAngleStart = vanetza::asn1::allocate<CartesianAngleValue_t>(); j.at("verticalOpeningAngleStart").get_to(*(p.verticalOpeningAngleStart)); } 
    else { p.verticalOpeningAngleStart=nullptr; }
    if (j.contains("verticalOpeningAngleEnd")) { p.verticalOpeningAngleEnd = vanetza::asn1::allocate<CartesianAngleValue_t>(); j.at("verticalOpeningAngleEnd").get_to(*(p.verticalOpeningAngleEnd)); } 
    else { p.verticalOpeningAngleEnd=nullptr; }
    
}

/*
*   ObjectDistanceWithConfidence - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectDistanceWithConfidence& p) {
    std::cout << "ObjectDistanceWithConfidence" << std::endl;
    j = json{{"value", (p.value)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, ObjectDistanceWithConfidence& p) {
    std::cout << "ObjectDistanceWithConfidence" << std::endl;
    j.at("value").get_to((p.value));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   ObjectDimension - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectDimension& p) {
    std::cout << "ObjectDimension" << std::endl;
    j = json{{"value", (p.value)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, ObjectDimension& p) {
    std::cout << "ObjectDimension" << std::endl;
    j.at("value").get_to((p.value));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   CartesianAngle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CartesianAngle& p) {
    std::cout << "CartesianAngle" << std::endl;
    j = json{{"value", (p.value)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, CartesianAngle& p) {
    std::cout << "CartesianAngle" << std::endl;
    j.at("value").get_to((p.value));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   WGS84Angle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const WGS84Angle& p) {
    std::cout << "WGS84Angle" << std::endl;
    j = json{{"value", (p.value)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, WGS84Angle& p) {
    std::cout << "WGS84Angle" << std::endl;
    j.at("value").get_to((p.value));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   SpeedExtended - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SpeedExtended& p) {
    std::cout << "SpeedExtended" << std::endl;
    j = json{{"value", (p.value)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, SpeedExtended& p) {
    std::cout << "SpeedExtended" << std::endl;
    j.at("value").get_to((p.value));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   SensorIdList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorIdList& p) {
    std::cout << "SensorIdList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const Identifier_t po = *(p.list.array[i]);
        // to_json(obj, po);
        j.push_back(po);
    }
}

void from_json(const json& j, SensorIdList& p) {
    SensorIdList* p_tmp = vanetza::asn1::allocate<SensorIdList>();
    for (const auto& item : j.items())
    {
        Identifier_t *element = vanetza::asn1::allocate<Identifier_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   TrailerData - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const TrailerData& p) {
    std::cout << "TrailerData" << std::endl;
    j = json{{"refPointId", (p.refPointId)}, {"hitchPointOffset", (p.hitchPointOffset)}, {"frontOverhang", (p.frontOverhang)}, {"rearOverhang", (p.rearOverhang)}};
    if (p.trailerWidth != 0) j["trailerWidth"] = *(p.trailerWidth);
    if (p.hitchAngle != 0) j["hitchAngle"] = *(p.hitchAngle);
}

void from_json(const json& j, TrailerData& p) {
    std::cout << "TrailerData" << std::endl;
    j.at("refPointId").get_to((p.refPointId));
    j.at("hitchPointOffset").get_to((p.hitchPointOffset));
    j.at("frontOverhang").get_to((p.frontOverhang));
    j.at("rearOverhang").get_to((p.rearOverhang));
    if (j.contains("trailerWidth")) { p.trailerWidth = vanetza::asn1::allocate<VehicleWidth_t>(); j.at("trailerWidth").get_to(*(p.trailerWidth)); } 
    else { p.trailerWidth=nullptr; }
    if (j.contains("hitchAngle")) { p.hitchAngle = vanetza::asn1::allocate<CartesianAngle_t>(); j.at("hitchAngle").get_to(*(p.hitchAngle)); } 
    else { p.hitchAngle=nullptr; }
    
}

/*
*   LongitudinalLanePosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const LongitudinalLanePosition& p) {
    std::cout << "LongitudinalLanePosition" << std::endl;
    j = json{{"longitudinalLanePositionValue", (p.longitudinalLanePositionValue)}, {"longitudinalLanePositionConfidence", (p.longitudinalLanePositionConfidence)}};
    
}

void from_json(const json& j, LongitudinalLanePosition& p) {
    std::cout << "LongitudinalLanePosition" << std::endl;
    j.at("longitudinalLanePositionValue").get_to((p.longitudinalLanePositionValue));
    j.at("longitudinalLanePositionConfidence").get_to((p.longitudinalLanePositionConfidence));
    
}

/*
*   MatchedPosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const MatchedPosition& p) {
    std::cout << "MatchedPosition" << std::endl;
    j = json{};
    if (p.laneID != 0) j["laneID"] = *(p.laneID);
    if (p.longitudinalLanePosition != 0) j["longitudinalLanePosition"] = *(p.longitudinalLanePosition);
}

void from_json(const json& j, MatchedPosition& p) {
    std::cout << "MatchedPosition" << std::endl;
    if (j.contains("laneID")) { p.laneID = vanetza::asn1::allocate<LaneID_t>(); j.at("laneID").get_to(*(p.laneID)); } 
    else { p.laneID=nullptr; }
    if (j.contains("longitudinalLanePosition")) { p.longitudinalLanePosition = vanetza::asn1::allocate<LongitudinalLanePosition_t>(); j.at("longitudinalLanePosition").get_to(*(p.longitudinalLanePosition)); } 
    else { p.longitudinalLanePosition=nullptr; }
    
}

/*
*   PerceivedObjectContainerSegmentInfo - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObjectContainerSegmentInfo& p) {
    std::cout << "PerceivedObjectContainerSegmentInfo" << std::endl;
    j = json{{"totalMsgSegments", (p.totalMsgSegments)}, {"thisSegmentNum", (p.thisSegmentNum)}};
    
}

void from_json(const json& j, PerceivedObjectContainerSegmentInfo& p) {
    std::cout << "PerceivedObjectContainerSegmentInfo" << std::endl;
    j.at("totalMsgSegments").get_to((p.totalMsgSegments));
    j.at("thisSegmentNum").get_to((p.thisSegmentNum));
    
}

/*
*   VehicleSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSubclass& p) {
    std::cout << "VehicleSubclass" << std::endl;
    j = json{{"type", (p.type)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, VehicleSubclass& p) {
    std::cout << "VehicleSubclass" << std::endl;
    j.at("type").get_to((p.type));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   PersonSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PersonSubclass& p) {
    std::cout << "PersonSubclass" << std::endl;
    j = json{{"type", (p.type)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, PersonSubclass& p) {
    std::cout << "PersonSubclass" << std::endl;
    j.at("type").get_to((p.type));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   AnimalSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AnimalSubclass& p) {
    std::cout << "AnimalSubclass" << std::endl;
    j = json{{"type", (p.type)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, AnimalSubclass& p) {
    std::cout << "AnimalSubclass" << std::endl;
    j.at("type").get_to((p.type));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   OtherSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OtherSubclass& p) {
    std::cout << "OtherSubclass" << std::endl;
    j = json{{"type", (p.type)}, {"confidence", (p.confidence)}};
    
}

void from_json(const json& j, OtherSubclass& p) {
    std::cout << "OtherSubclass" << std::endl;
    j.at("type").get_to((p.type));
    j.at("confidence").get_to((p.confidence));
    
}

/*
*   NodeOffsetPointZ - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const NodeOffsetPointZ& p) {
    std::cout << "NodeOffsetPointZ" << std::endl;
    j = json{};
    if (p.present == NodeOffsetPointZ_PR_node_Z1) {
        j["node-Z1"] = p.choice.node_Z1;
    } else if (p.present == NodeOffsetPointZ_PR_node_Z2) {
        j["node-Z2"] = p.choice.node_Z2;
    } else if (p.present == NodeOffsetPointZ_PR_node_Z3) {
        j["node-Z3"] = p.choice.node_Z3;
    } else if (p.present == NodeOffsetPointZ_PR_node_Z4) {
        j["node-Z4"] = p.choice.node_Z4;
    } else if (p.present == NodeOffsetPointZ_PR_node_Z5) {
        j["node-Z5"] = p.choice.node_Z5;
    } else if (p.present == NodeOffsetPointZ_PR_node_Z6) {
        j["node-Z6"] = p.choice.node_Z6;
    }
}

void from_json(const json& j, NodeOffsetPointZ& p) {
    std::cout << "NodeOffsetPointZ" << std::endl;
    if (j.contains("node-Z1")) {
        p.present = NodeOffsetPointZ_PR_node_Z1;
        j.at("node-Z1").get_to(p.choice.node_Z1);
    } else if (j.contains("node-Z2")) {
        p.present = NodeOffsetPointZ_PR_node_Z2;
        j.at("node-Z2").get_to(p.choice.node_Z2);
    } else if (j.contains("node-Z3")) {
        p.present = NodeOffsetPointZ_PR_node_Z3;
        j.at("node-Z3").get_to(p.choice.node_Z3);
    } else if (j.contains("node-Z4")) {
        p.present = NodeOffsetPointZ_PR_node_Z4;
        j.at("node-Z4").get_to(p.choice.node_Z4);
    } else if (j.contains("node-Z5")) {
        p.present = NodeOffsetPointZ_PR_node_Z5;
        j.at("node-Z5").get_to(p.choice.node_Z5);
    } else if (j.contains("node-Z6")) {
        p.present = NodeOffsetPointZ_PR_node_Z6;
        j.at("node-Z6").get_to(p.choice.node_Z6);
    } else {
        p.present = NodeOffsetPointZ_PR_NOTHING;
    }
}

/*
*   ReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ReferencePosition& p) {
    std::cout << "ReferencePosition" << std::endl;
    j = json{{"latitude", (p.latitude)}, {"longitude", (p.longitude)}, {"positionConfidenceEllipse", (p.positionConfidenceEllipse)}, {"altitude", (p.altitude)}};
    
}

void from_json(const json& j, ReferencePosition& p) {
    std::cout << "ReferencePosition" << std::endl;
    j.at("latitude").get_to((p.latitude));
    j.at("longitude").get_to((p.longitude));
    j.at("positionConfidenceEllipse").get_to((p.positionConfidenceEllipse));
    j.at("altitude").get_to((p.altitude));
    
}

/*
*   PtActivation - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PtActivation& p) {
    std::cout << "PtActivation" << std::endl;
    j = json{{"ptActivationType", (p.ptActivationType)}, {"ptActivationData", (p.ptActivationData)}};
    
}

void from_json(const json& j, PtActivation& p) {
    std::cout << "PtActivation" << std::endl;
    j.at("ptActivationType").get_to((p.ptActivationType));
    j.at("ptActivationData").get_to((p.ptActivationData));
    
}

/*
*   ClosedLanes - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ClosedLanes& p) {
    std::cout << "ClosedLanes" << std::endl;
    j = json{};
    if (p.innerhardShoulderStatus != 0) j["innerhardShoulderStatus"] = *(p.innerhardShoulderStatus);
    if (p.outerhardShoulderStatus != 0) j["outerhardShoulderStatus"] = *(p.outerhardShoulderStatus);
    if (p.drivingLaneStatus != 0) j["drivingLaneStatus"] = to_json_DrivingLaneStatus(*(p.drivingLaneStatus));
}

void from_json(const json& j, ClosedLanes& p) {
    std::cout << "ClosedLanes" << std::endl;
    if (j.contains("innerhardShoulderStatus")) { p.innerhardShoulderStatus = vanetza::asn1::allocate<HardShoulderStatus_t>(); j.at("innerhardShoulderStatus").get_to(*(p.innerhardShoulderStatus)); } 
    else { p.innerhardShoulderStatus=nullptr; }
    if (j.contains("outerhardShoulderStatus")) { p.outerhardShoulderStatus = vanetza::asn1::allocate<HardShoulderStatus_t>(); j.at("outerhardShoulderStatus").get_to(*(p.outerhardShoulderStatus)); } 
    else { p.outerhardShoulderStatus=nullptr; }
    if (j.contains("drivingLaneStatus")) { p.drivingLaneStatus = vanetza::asn1::allocate<DrivingLaneStatus_t>(); from_json_DrivingLaneStatus(j["drivingLaneStatus"],*(p.drivingLaneStatus)); } 
    else { p.drivingLaneStatus=nullptr; }
}

/*
*   ItineraryPath - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ItineraryPath& p) {
    std::cout << "ItineraryPath" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ReferencePosition_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ItineraryPath& p) {
    ItineraryPath* p_tmp = vanetza::asn1::allocate<ItineraryPath>();
    for (const auto& item : j.items())
    {
        ReferencePosition_t *element = vanetza::asn1::allocate<ReferencePosition_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   EventHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const EventHistory& p) {
    std::cout << "EventHistory" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const EventPoint_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, EventHistory& p) {
    EventHistory* p_tmp = vanetza::asn1::allocate<EventHistory>();
    for (const auto& item : j.items())
    {
        EventPoint_t *element = vanetza::asn1::allocate<EventPoint_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   DigitalMap - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DigitalMap_t& p) {
    std::cout << "DigitalMap" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ReferencePosition_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, DigitalMap_t& p) {
    DigitalMap_t* p_tmp = vanetza::asn1::allocate<DigitalMap_t>();
    for (const auto& item : j.items())
    {
        ReferencePosition_t *element = vanetza::asn1::allocate<ReferencePosition_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const HighFrequencyContainer& p) {
    std::cout << "HighFrequencyContainer" << std::endl;
    j = json{};
    if (p.present == HighFrequencyContainer_PR_basicVehicleContainerHighFrequency) {
        j["basicVehicleContainerHighFrequency"] = p.choice.basicVehicleContainerHighFrequency;
    } else if (p.present == HighFrequencyContainer_PR_rsuContainerHighFrequency) {
        j["rsuContainerHighFrequency"] = p.choice.rsuContainerHighFrequency;
    }
}

void from_json(const json& j, HighFrequencyContainer& p) {
    std::cout << "HighFrequencyContainer" << std::endl;
    if (j.contains("basicVehicleContainerHighFrequency")) {
        p.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
        j.at("basicVehicleContainerHighFrequency").get_to(p.choice.basicVehicleContainerHighFrequency);
    } else if (j.contains("rsuContainerHighFrequency")) {
        p.present = HighFrequencyContainer_PR_rsuContainerHighFrequency;
        j.at("rsuContainerHighFrequency").get_to(p.choice.rsuContainerHighFrequency);
    } else {
        p.present = HighFrequencyContainer_PR_NOTHING;
    }
}

/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const LowFrequencyContainer& p) {
    std::cout << "LowFrequencyContainer" << std::endl;
    j = json{};
    if (p.present == LowFrequencyContainer_PR_basicVehicleContainerLowFrequency) {
        j["basicVehicleContainerLowFrequency"] = p.choice.basicVehicleContainerLowFrequency;
    }
}

void from_json(const json& j, LowFrequencyContainer& p) {
    std::cout << "LowFrequencyContainer" << std::endl;
    if (j.contains("basicVehicleContainerLowFrequency")) {
        p.present = LowFrequencyContainer_PR_basicVehicleContainerLowFrequency;
        j.at("basicVehicleContainerLowFrequency").get_to(p.choice.basicVehicleContainerLowFrequency);
    } else {
        p.present = LowFrequencyContainer_PR_NOTHING;
    }
}

/*
*   BasicContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicContainer& p) {
    std::cout << "BasicContainer" << std::endl;
    j = json{{"stationType", (p.stationType)}, {"referencePosition", (p.referencePosition)}};
    
}

void from_json(const json& j, BasicContainer& p) {
    std::cout << "BasicContainer" << std::endl;
    j.at("stationType").get_to((p.stationType));
    j.at("referencePosition").get_to((p.referencePosition));
    
}

/*
*   PublicTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const PublicTransportContainer& p) {
    std::cout << "PublicTransportContainer" << std::endl;
    j = json{{"embarkationStatus", (p.embarkationStatus)}};
    if (p.ptActivation != 0) j["ptActivation"] = *(p.ptActivation);
}

void from_json(const json& j, PublicTransportContainer& p) {
    std::cout << "PublicTransportContainer" << std::endl;
    j.at("embarkationStatus").get_to((p.embarkationStatus));
    if (j.contains("ptActivation")) { p.ptActivation = vanetza::asn1::allocate<PtActivation_t>(); j.at("ptActivation").get_to(*(p.ptActivation)); } 
    else { p.ptActivation=nullptr; }
    
}

/*
*   RoadWorksContainerBasic - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RoadWorksContainerBasic& p) {
    std::cout << "RoadWorksContainerBasic" << std::endl;
    j = json{{"lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse))}};
    if (p.roadworksSubCauseCode != 0) j["roadworksSubCauseCode"] = *(p.roadworksSubCauseCode);
    if (p.closedLanes != 0) j["closedLanes"] = *(p.closedLanes);
}

void from_json(const json& j, RoadWorksContainerBasic& p) {
    std::cout << "RoadWorksContainerBasic" << std::endl;
    if (j.contains("roadworksSubCauseCode")) { p.roadworksSubCauseCode = vanetza::asn1::allocate<RoadworksSubCauseCode_t>(); j.at("roadworksSubCauseCode").get_to(*(p.roadworksSubCauseCode)); } 
    else { p.roadworksSubCauseCode=nullptr; }
    if (j.contains("closedLanes")) { p.closedLanes = vanetza::asn1::allocate<ClosedLanes_t>(); j.at("closedLanes").get_to(*(p.closedLanes)); } 
    else { p.closedLanes=nullptr; }
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}

/*
*   ManagementContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ManagementContainer& p) {
    std::cout << "ManagementContainer" << std::endl;
    j = json{{"actionID", (p.actionID)}, {"eventPosition", (p.eventPosition)}, {"stationType", (p.stationType)}};
    if (p.termination != 0) j["termination"] = *(p.termination);
    if (p.relevanceDistance != 0) j["relevanceDistance"] = *(p.relevanceDistance);
    if (p.relevanceTrafficDirection != 0) j["relevanceTrafficDirection"] = *(p.relevanceTrafficDirection);
    if (p.transmissionInterval != 0) j["transmissionInterval"] = *(p.transmissionInterval);
}

void from_json(const json& j, ManagementContainer& p) {
    std::cout << "ManagementContainer" << std::endl;
    j.at("actionID").get_to((p.actionID));
    if (j.contains("termination")) { p.termination = vanetza::asn1::allocate<Termination_t>(); j.at("termination").get_to(*(p.termination)); } 
    else { p.termination=nullptr; }
    j.at("eventPosition").get_to((p.eventPosition));
    if (j.contains("relevanceDistance")) { p.relevanceDistance = vanetza::asn1::allocate<RelevanceDistance_t>(); j.at("relevanceDistance").get_to(*(p.relevanceDistance)); } 
    else { p.relevanceDistance=nullptr; }
    if (j.contains("relevanceTrafficDirection")) { p.relevanceTrafficDirection = vanetza::asn1::allocate<RelevanceTrafficDirection_t>(); j.at("relevanceTrafficDirection").get_to(*(p.relevanceTrafficDirection)); } 
    else { p.relevanceTrafficDirection=nullptr; }
    if (j.contains("transmissionInterval")) { p.transmissionInterval = vanetza::asn1::allocate<TransmissionInterval_t>(); j.at("transmissionInterval").get_to(*(p.transmissionInterval)); } 
    else { p.transmissionInterval=nullptr; }
    j.at("stationType").get_to((p.stationType));
    
}

/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const SituationContainer& p) {
    std::cout << "SituationContainer" << std::endl;
    j = json{{"informationQuality", (p.informationQuality)}, {"eventType", (p.eventType)}};
    if (p.linkedCause != 0) j["linkedCause"] = *(p.linkedCause);
    if (p.eventHistory != 0) j["eventHistory"] = *(p.eventHistory);
}

void from_json(const json& j, SituationContainer& p) {
    std::cout << "SituationContainer" << std::endl;
    j.at("informationQuality").get_to((p.informationQuality));
    j.at("eventType").get_to((p.eventType));
    if (j.contains("linkedCause")) { p.linkedCause = vanetza::asn1::allocate<CauseCode_t>(); j.at("linkedCause").get_to(*(p.linkedCause)); } 
    else { p.linkedCause=nullptr; }
    if (j.contains("eventHistory")) { p.eventHistory = vanetza::asn1::allocate<EventHistory_t>(); j.at("eventHistory").get_to(*(p.eventHistory)); } 
    else { p.eventHistory=nullptr; }
    
}

/*
*   RoadWorksContainerExtended - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const RoadWorksContainerExtended& p) {
    std::cout << "RoadWorksContainerExtended" << std::endl;
    j = json{};
    if (p.lightBarSirenInUse != 0) j["lightBarSirenInUse"] = to_json_LightBarSirenInUse(*(p.lightBarSirenInUse));
    if (p.closedLanes != 0) j["closedLanes"] = *(p.closedLanes);
    if (p.restriction != 0) j["restriction"] = *(p.restriction);
    if (p.speedLimit != 0) j["speedLimit"] = *(p.speedLimit);
    if (p.incidentIndication != 0) j["incidentIndication"] = *(p.incidentIndication);
    if (p.recommendedPath != 0) j["recommendedPath"] = *(p.recommendedPath);
    if (p.startingPointSpeedLimit != 0) j["startingPointSpeedLimit"] = *(p.startingPointSpeedLimit);
    if (p.trafficFlowRule != 0) j["trafficFlowRule"] = *(p.trafficFlowRule);
    if (p.referenceDenms != 0) j["referenceDenms"] = *(p.referenceDenms);
}

void from_json(const json& j, RoadWorksContainerExtended& p) {
    std::cout << "RoadWorksContainerExtended" << std::endl;
    if (j.contains("closedLanes")) { p.closedLanes = vanetza::asn1::allocate<ClosedLanes_t>(); j.at("closedLanes").get_to(*(p.closedLanes)); } 
    else { p.closedLanes=nullptr; }
    if (j.contains("restriction")) { p.restriction = vanetza::asn1::allocate<RestrictedTypes_t>(); j.at("restriction").get_to(*(p.restriction)); } 
    else { p.restriction=nullptr; }
    if (j.contains("speedLimit")) { p.speedLimit = vanetza::asn1::allocate<SpeedLimit_t>(); j.at("speedLimit").get_to(*(p.speedLimit)); } 
    else { p.speedLimit=nullptr; }
    if (j.contains("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); j.at("incidentIndication").get_to(*(p.incidentIndication)); } 
    else { p.incidentIndication=nullptr; }
    if (j.contains("recommendedPath")) { p.recommendedPath = vanetza::asn1::allocate<ItineraryPath_t>(); j.at("recommendedPath").get_to(*(p.recommendedPath)); } 
    else { p.recommendedPath=nullptr; }
    if (j.contains("startingPointSpeedLimit")) { p.startingPointSpeedLimit = vanetza::asn1::allocate<DeltaReferencePosition_t>(); j.at("startingPointSpeedLimit").get_to(*(p.startingPointSpeedLimit)); } 
    else { p.startingPointSpeedLimit=nullptr; }
    if (j.contains("trafficFlowRule")) { p.trafficFlowRule = vanetza::asn1::allocate<TrafficRule_t>(); j.at("trafficFlowRule").get_to(*(p.trafficFlowRule)); } 
    else { p.trafficFlowRule=nullptr; }
    if (j.contains("referenceDenms")) { p.referenceDenms = vanetza::asn1::allocate<ReferenceDenms_t>(); j.at("referenceDenms").get_to(*(p.referenceDenms)); } 
    else { p.referenceDenms=nullptr; }
    if (j.contains("lightBarSirenInUse")) { p.lightBarSirenInUse = vanetza::asn1::allocate<LightBarSirenInUse_t>(); from_json_LightBarSirenInUse(j["lightBarSirenInUse"],*(p.lightBarSirenInUse)); } 
    else { p.lightBarSirenInUse=nullptr; }
}

/*
*   AlacarteContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const AlacarteContainer& p) {
    std::cout << "AlacarteContainer" << std::endl;
    j = json{};
    if (p.lanePosition != 0) j["lanePosition"] = *(p.lanePosition);
    if (p.impactReduction != 0) j["impactReduction"] = *(p.impactReduction);
    if (p.externalTemperature != 0) j["externalTemperature"] = *(p.externalTemperature);
    if (p.roadWorks != 0) j["roadWorks"] = *(p.roadWorks);
    if (p.positioningSolution != 0) j["positioningSolution"] = *(p.positioningSolution);
    if (p.stationaryVehicle != 0) j["stationaryVehicle"] = *(p.stationaryVehicle);
}

void from_json(const json& j, AlacarteContainer& p) {
    std::cout << "AlacarteContainer" << std::endl;
    if (j.contains("lanePosition")) { p.lanePosition = vanetza::asn1::allocate<LanePosition_t>(); j.at("lanePosition").get_to(*(p.lanePosition)); } 
    else { p.lanePosition=nullptr; }
    if (j.contains("impactReduction")) { p.impactReduction = vanetza::asn1::allocate<ImpactReductionContainer_t>(); j.at("impactReduction").get_to(*(p.impactReduction)); } 
    else { p.impactReduction=nullptr; }
    if (j.contains("externalTemperature")) { p.externalTemperature = vanetza::asn1::allocate<Temperature_t>(); j.at("externalTemperature").get_to(*(p.externalTemperature)); } 
    else { p.externalTemperature=nullptr; }
    if (j.contains("roadWorks")) { p.roadWorks = vanetza::asn1::allocate<RoadWorksContainerExtended_t>(); j.at("roadWorks").get_to(*(p.roadWorks)); } 
    else { p.roadWorks=nullptr; }
    if (j.contains("positioningSolution")) { p.positioningSolution = vanetza::asn1::allocate<PositioningSolutionType_t>(); j.at("positioningSolution").get_to(*(p.positioningSolution)); } 
    else { p.positioningSolution=nullptr; }
    if (j.contains("stationaryVehicle")) { p.stationaryVehicle = vanetza::asn1::allocate<StationaryVehicleContainer_t>(); j.at("stationaryVehicle").get_to(*(p.stationaryVehicle)); } 
    else { p.stationaryVehicle=nullptr; }
    
}

/*
*   ConnectingLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectingLane& p) {
    std::cout << "ConnectingLane" << std::endl;
    j = json{{"lane", (p.lane)}};
    if (p.maneuver != 0) j["maneuver"] = to_json_AllowedManeuvers(*(p.maneuver));
}

void from_json(const json& j, ConnectingLane& p) {
    std::cout << "ConnectingLane" << std::endl;
    j.at("lane").get_to((p.lane));
    if (j.contains("maneuver")) { p.maneuver = vanetza::asn1::allocate<AllowedManeuvers_t>(); from_json_AllowedManeuvers(j["maneuver"],*(p.maneuver)); } 
    else { p.maneuver=nullptr; }
}

/*
*   Connection - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Connection& p) {
    std::cout << "Connection" << std::endl;
    j = json{{"connectingLane", (p.connectingLane)}};
    if (p.remoteIntersection != 0) j["remoteIntersection"] = *(p.remoteIntersection);
    if (p.signalGroup != 0) j["signalGroup"] = *(p.signalGroup);
    if (p.userClass != 0) j["userClass"] = *(p.userClass);
    if (p.connectionID != 0) j["connectionID"] = *(p.connectionID);
}

void from_json(const json& j, Connection& p) {
    std::cout << "Connection" << std::endl;
    j.at("connectingLane").get_to((p.connectingLane));
    if (j.contains("remoteIntersection")) { p.remoteIntersection = vanetza::asn1::allocate<IntersectionReferenceID_t>(); j.at("remoteIntersection").get_to(*(p.remoteIntersection)); } 
    else { p.remoteIntersection=nullptr; }
    if (j.contains("signalGroup")) { p.signalGroup = vanetza::asn1::allocate<SignalGroupID_t>(); j.at("signalGroup").get_to(*(p.signalGroup)); } 
    else { p.signalGroup=nullptr; }
    if (j.contains("userClass")) { p.userClass = vanetza::asn1::allocate<RestrictionClassID_t>(); j.at("userClass").get_to(*(p.userClass)); } 
    else { p.userClass=nullptr; }
    if (j.contains("connectionID")) { p.connectionID = vanetza::asn1::allocate<LaneConnectionID_t>(); j.at("connectionID").get_to(*(p.connectionID)); } 
    else { p.connectionID=nullptr; }
    
}

/*
*   LaneTypeAttributes - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneTypeAttributes& p) {
    std::cout << "LaneTypeAttributes" << std::endl;
    j = json{};
    if (p.present == LaneTypeAttributes_PR_vehicle) {
        j["vehicle"] = to_json_LaneAttributes_Vehicle(p.choice.vehicle);
    } else if (p.present == LaneTypeAttributes_PR_crosswalk) {
        j["crosswalk"] = to_json_LaneAttributes_Crosswalk(p.choice.crosswalk);
    } else if (p.present == LaneTypeAttributes_PR_bikeLane) {
        j["bikeLane"] = to_json_LaneAttributes_Bike(p.choice.bikeLane);
    } else if (p.present == LaneTypeAttributes_PR_sidewalk) {
        j["sidewalk"] = to_json_LaneAttributes_Sidewalk(p.choice.sidewalk);
    } else if (p.present == LaneTypeAttributes_PR_median) {
        j["median"] = to_json_LaneAttributes_Barrier(p.choice.median);
    } else if (p.present == LaneTypeAttributes_PR_striping) {
        j["striping"] = to_json_LaneAttributes_Striping(p.choice.striping);
    } else if (p.present == LaneTypeAttributes_PR_trackedVehicle) {
        j["trackedVehicle"] = to_json_LaneAttributes_TrackedVehicle(p.choice.trackedVehicle);
    } else if (p.present == LaneTypeAttributes_PR_parking) {
        j["parking"] = to_json_LaneAttributes_Parking(p.choice.parking);
    }
}

void from_json(const json& j, LaneTypeAttributes& p) {
    std::cout << "LaneTypeAttributes" << std::endl;
    if (j.contains("vehicle")) {
        p.present = LaneTypeAttributes_PR_vehicle;
        from_json_LaneAttributes_Vehicle(j["vehicle"], p.choice.vehicle);
    } else if (j.contains("crosswalk")) {
        p.present = LaneTypeAttributes_PR_crosswalk;
        from_json_LaneAttributes_Crosswalk(j["crosswalk"], p.choice.crosswalk);
    } else if (j.contains("bikeLane")) {
        p.present = LaneTypeAttributes_PR_bikeLane;
        from_json_LaneAttributes_Bike(j["bikeLane"], p.choice.bikeLane);
    } else if (j.contains("sidewalk")) {
        p.present = LaneTypeAttributes_PR_sidewalk;
        from_json_LaneAttributes_Sidewalk(j["sidewalk"], p.choice.sidewalk);
    } else if (j.contains("median")) {
        p.present = LaneTypeAttributes_PR_median;
        from_json_LaneAttributes_Barrier(j["median"], p.choice.median);
    } else if (j.contains("striping")) {
        p.present = LaneTypeAttributes_PR_striping;
        from_json_LaneAttributes_Striping(j["striping"], p.choice.striping);
    } else if (j.contains("trackedVehicle")) {
        p.present = LaneTypeAttributes_PR_trackedVehicle;
        from_json_LaneAttributes_TrackedVehicle(j["trackedVehicle"], p.choice.trackedVehicle);
    } else if (j.contains("parking")) {
        p.present = LaneTypeAttributes_PR_parking;
        from_json_LaneAttributes_Parking(j["parking"], p.choice.parking);
    } else {
        p.present = LaneTypeAttributes_PR_NOTHING;
    }
}

/*
*   MovementEvent - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementEvent& p) {
    std::cout << "MovementEvent" << std::endl;
    j = json{{"eventState", (p.eventState)}};
    if (p.timing != 0) j["timing"] = *(p.timing);
    if (p.speeds != 0) j["speeds"] = *(p.speeds);
}

void from_json(const json& j, MovementEvent& p) {
    std::cout << "MovementEvent" << std::endl;
    j.at("eventState").get_to((p.eventState));
    if (j.contains("timing")) { p.timing = vanetza::asn1::allocate<TimeChangeDetails_t>(); j.at("timing").get_to(*(p.timing)); } 
    else { p.timing=nullptr; }
    if (j.contains("speeds")) { p.speeds = vanetza::asn1::allocate<AdvisorySpeedList_t>(); j.at("speeds").get_to(*(p.speeds)); } 
    else { p.speeds=nullptr; }
    
}

/*
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionUserTypeList& p) {
    std::cout << "RestrictionUserTypeList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const RestrictionUserType_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, RestrictionUserTypeList& p) {
    RestrictionUserTypeList* p_tmp = vanetza::asn1::allocate<RestrictionUserTypeList>();
    for (const auto& item : j.items())
    {
        RestrictionUserType_t *element = vanetza::asn1::allocate<RestrictionUserType_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   LaneDataAttribute - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const LaneDataAttribute& p) {
    std::cout << "LaneDataAttribute" << std::endl;
    j = json{};
    if (p.present == LaneDataAttribute_PR_pathEndPointAngle) {
        j["pathEndPointAngle"] = p.choice.pathEndPointAngle;
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointCenter) {
        j["laneCrownPointCenter"] = p.choice.laneCrownPointCenter;
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointLeft) {
        j["laneCrownPointLeft"] = p.choice.laneCrownPointLeft;
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointRight) {
        j["laneCrownPointRight"] = p.choice.laneCrownPointRight;
    } else if (p.present == LaneDataAttribute_PR_laneAngle) {
        j["laneAngle"] = p.choice.laneAngle;
    } else if (p.present == LaneDataAttribute_PR_speedLimits) {
        j["speedLimits"] = p.choice.speedLimits;
    }
}

void from_json(const json& j, LaneDataAttribute& p) {
    std::cout << "LaneDataAttribute" << std::endl;
    if (j.contains("pathEndPointAngle")) {
        p.present = LaneDataAttribute_PR_pathEndPointAngle;
        j.at("pathEndPointAngle").get_to(p.choice.pathEndPointAngle);
    } else if (j.contains("laneCrownPointCenter")) {
        p.present = LaneDataAttribute_PR_laneCrownPointCenter;
        j.at("laneCrownPointCenter").get_to(p.choice.laneCrownPointCenter);
    } else if (j.contains("laneCrownPointLeft")) {
        p.present = LaneDataAttribute_PR_laneCrownPointLeft;
        j.at("laneCrownPointLeft").get_to(p.choice.laneCrownPointLeft);
    } else if (j.contains("laneCrownPointRight")) {
        p.present = LaneDataAttribute_PR_laneCrownPointRight;
        j.at("laneCrownPointRight").get_to(p.choice.laneCrownPointRight);
    } else if (j.contains("laneAngle")) {
        p.present = LaneDataAttribute_PR_laneAngle;
        j.at("laneAngle").get_to(p.choice.laneAngle);
    } else if (j.contains("speedLimits")) {
        p.present = LaneDataAttribute_PR_speedLimits;
        j.at("speedLimits").get_to(p.choice.speedLimits);
    } else {
        p.present = LaneDataAttribute_PR_NOTHING;
    }
}

/*
*   LaneDataAttributeList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const LaneDataAttributeList& p) {
    std::cout << "LaneDataAttributeList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const LaneDataAttribute_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, LaneDataAttributeList& p) {
    LaneDataAttributeList* p_tmp = vanetza::asn1::allocate<LaneDataAttributeList>();
    for (const auto& item : j.items())
    {
        LaneDataAttribute_t *element = vanetza::asn1::allocate<LaneDataAttribute_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeOffsetPointXY& p) {
    std::cout << "NodeOffsetPointXY" << std::endl;
    j = json{};
    if (p.present == NodeOffsetPointXY_PR_node_XY1) {
        j["node-XY1"] = p.choice.node_XY1;
    } else if (p.present == NodeOffsetPointXY_PR_node_XY2) {
        j["node-XY2"] = p.choice.node_XY2;
    } else if (p.present == NodeOffsetPointXY_PR_node_XY3) {
        j["node-XY3"] = p.choice.node_XY3;
    } else if (p.present == NodeOffsetPointXY_PR_node_XY4) {
        j["node-XY4"] = p.choice.node_XY4;
    } else if (p.present == NodeOffsetPointXY_PR_node_XY5) {
        j["node-XY5"] = p.choice.node_XY5;
    } else if (p.present == NodeOffsetPointXY_PR_node_XY6) {
        j["node-XY6"] = p.choice.node_XY6;
    } else if (p.present == NodeOffsetPointXY_PR_node_LatLon) {
        j["node-LatLon"] = p.choice.node_LatLon;
    }
}

void from_json(const json& j, NodeOffsetPointXY& p) {
    std::cout << "NodeOffsetPointXY" << std::endl;
    if (j.contains("node-XY1")) {
        p.present = NodeOffsetPointXY_PR_node_XY1;
        j.at("node-XY1").get_to(p.choice.node_XY1);
    } else if (j.contains("node-XY2")) {
        p.present = NodeOffsetPointXY_PR_node_XY2;
        j.at("node-XY2").get_to(p.choice.node_XY2);
    } else if (j.contains("node-XY3")) {
        p.present = NodeOffsetPointXY_PR_node_XY3;
        j.at("node-XY3").get_to(p.choice.node_XY3);
    } else if (j.contains("node-XY4")) {
        p.present = NodeOffsetPointXY_PR_node_XY4;
        j.at("node-XY4").get_to(p.choice.node_XY4);
    } else if (j.contains("node-XY5")) {
        p.present = NodeOffsetPointXY_PR_node_XY5;
        j.at("node-XY5").get_to(p.choice.node_XY5);
    } else if (j.contains("node-XY6")) {
        p.present = NodeOffsetPointXY_PR_node_XY6;
        j.at("node-XY6").get_to(p.choice.node_XY6);
    } else if (j.contains("node-LatLon")) {
        p.present = NodeOffsetPointXY_PR_node_LatLon;
        j.at("node-LatLon").get_to(p.choice.node_LatLon);
    } else {
        p.present = NodeOffsetPointXY_PR_NOTHING;
    }
}

/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeAttributeSetXY_t& p) {
    std::cout << "NodeAttributeSetXY" << std::endl;
    j = json{};
    if (p.localNode != 0) j["localNode"] = *(p.localNode);
    if (p.disabled != 0) j["disabled"] = *(p.disabled);
    if (p.enabled != 0) j["enabled"] = *(p.enabled);
    if (p.data != 0) j["data"] = *(p.data);
    if (p.dWidth != 0) j["dWidth"] = *(p.dWidth);
    if (p.dElevation != 0) j["dElevation"] = *(p.dElevation);
}

void from_json(const json& j, NodeAttributeSetXY_t& p) {
    std::cout << "NodeAttributeSetXY" << std::endl;
    if (j.contains("localNode")) { p.localNode = vanetza::asn1::allocate<NodeAttributeXYList_t>(); j.at("localNode").get_to(*(p.localNode)); } 
    else { p.localNode=nullptr; }
    if (j.contains("disabled")) { p.disabled = vanetza::asn1::allocate<SegmentAttributeXYList_t>(); j.at("disabled").get_to(*(p.disabled)); } 
    else { p.disabled=nullptr; }
    if (j.contains("enabled")) { p.enabled = vanetza::asn1::allocate<SegmentAttributeXYList_t>(); j.at("enabled").get_to(*(p.enabled)); } 
    else { p.enabled=nullptr; }
    if (j.contains("data")) { p.data = vanetza::asn1::allocate<LaneDataAttributeList_t>(); j.at("data").get_to(*(p.data)); } 
    else { p.data=nullptr; }
    if (j.contains("dWidth")) { p.dWidth = vanetza::asn1::allocate<Offset_B10_t>(); j.at("dWidth").get_to(*(p.dWidth)); } 
    else { p.dWidth=nullptr; }
    if (j.contains("dElevation")) { p.dElevation = vanetza::asn1::allocate<Offset_B10_t>(); j.at("dElevation").get_to(*(p.dElevation)); } 
    else { p.dElevation=nullptr; }
    
}

/*
*   CpmManagementContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CpmManagementContainer& p) {
    std::cout << "CpmManagementContainer" << std::endl;
    j = json{{"stationType", (p.stationType)}, {"referencePosition", (p.referencePosition)}};
    if (p.perceivedObjectContainerSegmentInfo != 0) j["perceivedObjectContainerSegmentInfo"] = *(p.perceivedObjectContainerSegmentInfo);
}

void from_json(const json& j, CpmManagementContainer& p) {
    std::cout << "CpmManagementContainer" << std::endl;
    j.at("stationType").get_to((p.stationType));
    if (j.contains("perceivedObjectContainerSegmentInfo")) { p.perceivedObjectContainerSegmentInfo = vanetza::asn1::allocate<PerceivedObjectContainerSegmentInfo_t>(); j.at("perceivedObjectContainerSegmentInfo").get_to(*(p.perceivedObjectContainerSegmentInfo)); } 
    else { p.perceivedObjectContainerSegmentInfo=nullptr; }
    j.at("referencePosition").get_to((p.referencePosition));
    
}

/*
*   VehicleSensorPropertyList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensorPropertyList& p) {
    std::cout << "VehicleSensorPropertyList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const VehicleSensorProperties_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, VehicleSensorPropertyList& p) {
    VehicleSensorPropertyList* p_tmp = vanetza::asn1::allocate<VehicleSensorPropertyList>();
    for (const auto& item : j.items())
    {
        VehicleSensorProperties_t *element = vanetza::asn1::allocate<VehicleSensorProperties_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   TrailerDataContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const TrailerDataContainer& p) {
    std::cout << "TrailerDataContainer" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const TrailerData_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, TrailerDataContainer& p) {
    TrailerDataContainer* p_tmp = vanetza::asn1::allocate<TrailerDataContainer>();
    for (const auto& item : j.items())
    {
        TrailerData_t *element = vanetza::asn1::allocate<TrailerData_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClass::ObjectClass__class& p) {
    std::cout << "ObjectClass::ObjectClass__class" << std::endl;
    j = json{};
    if (p.present == ObjectClass__class_PR_vehicle) {
        j["vehicle"] = p.choice.vehicle;
    } else if (p.present == ObjectClass__class_PR_person) {
        j["person"] = p.choice.person;
    } else if (p.present == ObjectClass__class_PR_animal) {
        j["animal"] = p.choice.animal;
    } else if (p.present == ObjectClass__class_PR_other) {
        j["other"] = p.choice.other;
    }
}

void from_json(const json& j, ObjectClass::ObjectClass__class& p) {
    std::cout << "ObjectClass::ObjectClass__class" << std::endl;
    if (j.contains("vehicle")) {
        p.present = ObjectClass__class_PR_vehicle;
        j.at("vehicle").get_to(p.choice.vehicle);
    } else if (j.contains("person")) {
        p.present = ObjectClass__class_PR_person;
        j.at("person").get_to(p.choice.person);
    } else if (j.contains("animal")) {
        p.present = ObjectClass__class_PR_animal;
        j.at("animal").get_to(p.choice.animal);
    } else if (j.contains("other")) {
        p.present = ObjectClass__class_PR_other;
        j.at("other").get_to(p.choice.other);
    } else {
        p.present = ObjectClass__class_PR_NOTHING;
    }
}

/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClass_t& p) {
    std::cout << "ObjectClass" << std::endl;
    j = json{{"confidence", (p.confidence)}, {"class", (p.Class)}};
    
}

void from_json(const json& j, ObjectClass_t& p) {
    std::cout << "ObjectClass" << std::endl;
    j.at("confidence").get_to((p.confidence));
    j.at("class").get_to((p.Class));
    
}

/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OffsetPoint& p) {
    std::cout << "OffsetPoint" << std::endl;
    j = json{{"nodeOffsetPointxy", (p.nodeOffsetPointxy)}};
    if (p.nodeOffsetPointZ != 0) j["nodeOffsetPointZ"] = *(p.nodeOffsetPointZ);
}

void from_json(const json& j, OffsetPoint& p) {
    std::cout << "OffsetPoint" << std::endl;
    j.at("nodeOffsetPointxy").get_to((p.nodeOffsetPointxy));
    if (j.contains("nodeOffsetPointZ")) { p.nodeOffsetPointZ = vanetza::asn1::allocate<NodeOffsetPointZ_t>(); j.at("nodeOffsetPointZ").get_to(*(p.nodeOffsetPointZ)); } 
    else { p.nodeOffsetPointZ=nullptr; }
    
}

/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SpecialVehicleContainer& p) {
    std::cout << "SpecialVehicleContainer" << std::endl;
    j = json{};
    if (p.present == SpecialVehicleContainer_PR_publicTransportContainer) {
        j["publicTransportContainer"] = p.choice.publicTransportContainer;
    } else if (p.present == SpecialVehicleContainer_PR_specialTransportContainer) {
        j["specialTransportContainer"] = p.choice.specialTransportContainer;
    } else if (p.present == SpecialVehicleContainer_PR_dangerousGoodsContainer) {
        j["dangerousGoodsContainer"] = p.choice.dangerousGoodsContainer;
    } else if (p.present == SpecialVehicleContainer_PR_roadWorksContainerBasic) {
        j["roadWorksContainerBasic"] = p.choice.roadWorksContainerBasic;
    } else if (p.present == SpecialVehicleContainer_PR_rescueContainer) {
        j["rescueContainer"] = p.choice.rescueContainer;
    } else if (p.present == SpecialVehicleContainer_PR_emergencyContainer) {
        j["emergencyContainer"] = p.choice.emergencyContainer;
    } else if (p.present == SpecialVehicleContainer_PR_safetyCarContainer) {
        j["safetyCarContainer"] = p.choice.safetyCarContainer;
    }
}

void from_json(const json& j, SpecialVehicleContainer& p) {
    std::cout << "SpecialVehicleContainer" << std::endl;
    if (j.contains("publicTransportContainer")) {
        p.present = SpecialVehicleContainer_PR_publicTransportContainer;
        j.at("publicTransportContainer").get_to(p.choice.publicTransportContainer);
    } else if (j.contains("specialTransportContainer")) {
        p.present = SpecialVehicleContainer_PR_specialTransportContainer;
        j.at("specialTransportContainer").get_to(p.choice.specialTransportContainer);
    } else if (j.contains("dangerousGoodsContainer")) {
        p.present = SpecialVehicleContainer_PR_dangerousGoodsContainer;
        j.at("dangerousGoodsContainer").get_to(p.choice.dangerousGoodsContainer);
    } else if (j.contains("roadWorksContainerBasic")) {
        p.present = SpecialVehicleContainer_PR_roadWorksContainerBasic;
        j.at("roadWorksContainerBasic").get_to(p.choice.roadWorksContainerBasic);
    } else if (j.contains("rescueContainer")) {
        p.present = SpecialVehicleContainer_PR_rescueContainer;
        j.at("rescueContainer").get_to(p.choice.rescueContainer);
    } else if (j.contains("emergencyContainer")) {
        p.present = SpecialVehicleContainer_PR_emergencyContainer;
        j.at("emergencyContainer").get_to(p.choice.emergencyContainer);
    } else if (j.contains("safetyCarContainer")) {
        p.present = SpecialVehicleContainer_PR_safetyCarContainer;
        j.at("safetyCarContainer").get_to(p.choice.safetyCarContainer);
    } else {
        p.present = SpecialVehicleContainer_PR_NOTHING;
    }
}

/*
*   DecentralizedEnvironmentalNotificationMessage - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const DecentralizedEnvironmentalNotificationMessage& p) {
    std::cout << "DecentralizedEnvironmentalNotificationMessage" << std::endl;
    j = json{{"management", (p.management)}};
    if (p.situation != 0) j["situation"] = *(p.situation);
    if (p.location != 0) j["location"] = *(p.location);
    if (p.alacarte != 0) j["alacarte"] = *(p.alacarte);
}

void from_json(const json& j, DecentralizedEnvironmentalNotificationMessage& p) {
    std::cout << "DecentralizedEnvironmentalNotificationMessage" << std::endl;
    j.at("management").get_to((p.management));
    if (j.contains("situation")) { p.situation = vanetza::asn1::allocate<SituationContainer_t>(); j.at("situation").get_to(*(p.situation)); } 
    else { p.situation=nullptr; }
    if (j.contains("location")) { p.location = vanetza::asn1::allocate<LocationContainer_t>(); j.at("location").get_to(*(p.location)); } 
    else { p.location=nullptr; }
    if (j.contains("alacarte")) { p.alacarte = vanetza::asn1::allocate<AlacarteContainer_t>(); j.at("alacarte").get_to(*(p.alacarte)); } 
    else { p.alacarte=nullptr; }
    
}

/*
*   ConnectsToList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectsToList& p) {
    std::cout << "ConnectsToList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const Connection_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ConnectsToList& p) {
    ConnectsToList* p_tmp = vanetza::asn1::allocate<ConnectsToList>();
    for (const auto& item : j.items())
    {
        Connection_t *element = vanetza::asn1::allocate<Connection_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   LaneAttributes - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneAttributes& p) {
    std::cout << "LaneAttributes" << std::endl;
    j = json{{"directionalUse", to_json_LaneDirection((p.directionalUse))}, {"sharedWith", to_json_LaneSharing((p.sharedWith))}, {"laneType", (p.laneType)}};
    
}

void from_json(const json& j, LaneAttributes& p) {
    std::cout << "LaneAttributes" << std::endl;
    j.at("laneType").get_to((p.laneType));
    from_json_LaneDirection(j["directionalUse"],(p.directionalUse));
    from_json_LaneSharing(j["sharedWith"],(p.sharedWith));
}

/*
*   MovementEventList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementEventList& p) {
    std::cout << "MovementEventList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const MovementEvent_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, MovementEventList& p) {
    MovementEventList* p_tmp = vanetza::asn1::allocate<MovementEventList>();
    for (const auto& item : j.items())
    {
        MovementEvent_t *element = vanetza::asn1::allocate<MovementEvent_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   MovementState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementState& p) {
    std::cout << "MovementState" << std::endl;
    j = json{{"signalGroup", (p.signalGroup)}, {"state-time-speed", (p.state_time_speed)}};
    if (p.maneuverAssistList != 0) j["maneuverAssistList"] = *(p.maneuverAssistList);
}

void from_json(const json& j, MovementState& p) {
    std::cout << "MovementState" << std::endl;
    j.at("signalGroup").get_to((p.signalGroup));
    j.at("state-time-speed").get_to((p.state_time_speed));
    if (j.contains("maneuverAssistList")) { p.maneuverAssistList = vanetza::asn1::allocate<ManeuverAssistList_t>(); j.at("maneuverAssistList").get_to(*(p.maneuverAssistList)); } 
    else { p.maneuverAssistList=nullptr; }
    
}

/*
*   RestrictionClassAssignment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionClassAssignment& p) {
    std::cout << "RestrictionClassAssignment" << std::endl;
    j = json{{"id", (p.id)}, {"users", (p.users)}};
    
}

void from_json(const json& j, RestrictionClassAssignment& p) {
    std::cout << "RestrictionClassAssignment" << std::endl;
    j.at("id").get_to((p.id));
    j.at("users").get_to((p.users));
    
}

/*
*   RestrictionClassList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionClassList& p) {
    std::cout << "RestrictionClassList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const RestrictionClassAssignment_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, RestrictionClassList& p) {
    RestrictionClassList* p_tmp = vanetza::asn1::allocate<RestrictionClassList>();
    for (const auto& item : j.items())
    {
        RestrictionClassAssignment_t *element = vanetza::asn1::allocate<RestrictionClassAssignment_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   NodeXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeXY_t& p) {
    std::cout << "NodeXY" << std::endl;
    j = json{{"delta", (p.delta)}};
    if (p.attributes != 0) j["attributes"] = *(p.attributes);
}

void from_json(const json& j, NodeXY_t& p) {
    std::cout << "NodeXY" << std::endl;
    j.at("delta").get_to((p.delta));
    if (j.contains("attributes")) { p.attributes = vanetza::asn1::allocate<NodeAttributeSetXY_t>(); j.at("attributes").get_to(*(p.attributes)); } 
    else { p.attributes=nullptr; }
    
}

/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OriginatingVehicleContainer& p) {
    std::cout << "OriginatingVehicleContainer" << std::endl;
    j = json{{"heading", (p.heading)}, {"speed", (p.speed)}, {"driveDirection", (p.driveDirection)}};
    if (p.vehicleOrientationAngle != 0) j["vehicleOrientationAngle"] = *(p.vehicleOrientationAngle);
    if (p.longitudinalAcceleration != 0) j["longitudinalAcceleration"] = *(p.longitudinalAcceleration);
    if (p.lateralAcceleration != 0) j["lateralAcceleration"] = *(p.lateralAcceleration);
    if (p.verticalAcceleration != 0) j["verticalAcceleration"] = *(p.verticalAcceleration);
    if (p.yawRate != 0) j["yawRate"] = *(p.yawRate);
    if (p.pitchAngle != 0) j["pitchAngle"] = *(p.pitchAngle);
    if (p.rollAngle != 0) j["rollAngle"] = *(p.rollAngle);
    if (p.vehicleLength != 0) j["vehicleLength"] = *(p.vehicleLength);
    if (p.vehicleWidth != 0) j["vehicleWidth"] = *(p.vehicleWidth);
    if (p.vehicleHeight != 0) j["vehicleHeight"] = *(p.vehicleHeight);
    if (p.trailerDataContainer != 0) j["trailerDataContainer"] = *(p.trailerDataContainer);
}

void from_json(const json& j, OriginatingVehicleContainer& p) {
    std::cout << "OriginatingVehicleContainer" << std::endl;
    j.at("heading").get_to((p.heading));
    j.at("speed").get_to((p.speed));
    if (j.contains("vehicleOrientationAngle")) { p.vehicleOrientationAngle = vanetza::asn1::allocate<WGS84Angle_t>(); j.at("vehicleOrientationAngle").get_to(*(p.vehicleOrientationAngle)); } 
    else { p.vehicleOrientationAngle=nullptr; }
    j.at("driveDirection").get_to((p.driveDirection));
    if (j.contains("longitudinalAcceleration")) { p.longitudinalAcceleration = vanetza::asn1::allocate<LongitudinalAcceleration_t>(); j.at("longitudinalAcceleration").get_to(*(p.longitudinalAcceleration)); } 
    else { p.longitudinalAcceleration=nullptr; }
    if (j.contains("lateralAcceleration")) { p.lateralAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); j.at("lateralAcceleration").get_to(*(p.lateralAcceleration)); } 
    else { p.lateralAcceleration=nullptr; }
    if (j.contains("verticalAcceleration")) { p.verticalAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); j.at("verticalAcceleration").get_to(*(p.verticalAcceleration)); } 
    else { p.verticalAcceleration=nullptr; }
    if (j.contains("yawRate")) { p.yawRate = vanetza::asn1::allocate<YawRate_t>(); j.at("yawRate").get_to(*(p.yawRate)); } 
    else { p.yawRate=nullptr; }
    if (j.contains("pitchAngle")) { p.pitchAngle = vanetza::asn1::allocate<CartesianAngle_t>(); j.at("pitchAngle").get_to(*(p.pitchAngle)); } 
    else { p.pitchAngle=nullptr; }
    if (j.contains("rollAngle")) { p.rollAngle = vanetza::asn1::allocate<CartesianAngle_t>(); j.at("rollAngle").get_to(*(p.rollAngle)); } 
    else { p.rollAngle=nullptr; }
    if (j.contains("vehicleLength")) { p.vehicleLength = vanetza::asn1::allocate<VehicleLength_t>(); j.at("vehicleLength").get_to(*(p.vehicleLength)); } 
    else { p.vehicleLength=nullptr; }
    if (j.contains("vehicleWidth")) { p.vehicleWidth = vanetza::asn1::allocate<VehicleWidth_t>(); j.at("vehicleWidth").get_to(*(p.vehicleWidth)); } 
    else { p.vehicleWidth=nullptr; }
    if (j.contains("vehicleHeight")) { p.vehicleHeight = vanetza::asn1::allocate<VehicleHeight_t>(); j.at("vehicleHeight").get_to(*(p.vehicleHeight)); } 
    else { p.vehicleHeight=nullptr; }
    if (j.contains("trailerDataContainer")) { p.trailerDataContainer = vanetza::asn1::allocate<TrailerDataContainer_t>(); j.at("trailerDataContainer").get_to(*(p.trailerDataContainer)); } 
    else { p.trailerDataContainer=nullptr; }
    
}

/*
*   VehicleSensor - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensor& p) {
    std::cout << "VehicleSensor" << std::endl;
    j = json{{"refPointId", (p.refPointId)}, {"xSensorOffset", (p.xSensorOffset)}, {"ySensorOffset", (p.ySensorOffset)}, {"vehicleSensorPropertyList", (p.vehicleSensorPropertyList)}};
    if (p.zSensorOffset != 0) j["zSensorOffset"] = *(p.zSensorOffset);
}

void from_json(const json& j, VehicleSensor& p) {
    std::cout << "VehicleSensor" << std::endl;
    j.at("refPointId").get_to((p.refPointId));
    j.at("xSensorOffset").get_to((p.xSensorOffset));
    j.at("ySensorOffset").get_to((p.ySensorOffset));
    if (j.contains("zSensorOffset")) { p.zSensorOffset = vanetza::asn1::allocate<ZSensorOffset_t>(); j.at("zSensorOffset").get_to(*(p.zSensorOffset)); } 
    else { p.zSensorOffset=nullptr; }
    j.at("vehicleSensorPropertyList").get_to((p.vehicleSensorPropertyList));
    
}

/*
*   AreaCircular - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaCircular& p) {
    std::cout << "AreaCircular" << std::endl;
    j = json{{"radius", (p.radius)}};
    if (p.nodeCenterPoint != 0) j["nodeCenterPoint"] = *(p.nodeCenterPoint);
}

void from_json(const json& j, AreaCircular& p) {
    std::cout << "AreaCircular" << std::endl;
    if (j.contains("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); j.at("nodeCenterPoint").get_to(*(p.nodeCenterPoint)); } 
    else { p.nodeCenterPoint=nullptr; }
    j.at("radius").get_to((p.radius));
    
}

/*
*   AreaEllipse - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaEllipse& p) {
    std::cout << "AreaEllipse" << std::endl;
    j = json{{"semiMinorRangeLength", (p.semiMinorRangeLength)}, {"semiMajorRangeLength", (p.semiMajorRangeLength)}, {"semiMajorRangeOrientation", (p.semiMajorRangeOrientation)}};
    if (p.nodeCenterPoint != 0) j["nodeCenterPoint"] = *(p.nodeCenterPoint);
    if (p.semiHeight != 0) j["semiHeight"] = *(p.semiHeight);
}

void from_json(const json& j, AreaEllipse& p) {
    std::cout << "AreaEllipse" << std::endl;
    if (j.contains("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); j.at("nodeCenterPoint").get_to(*(p.nodeCenterPoint)); } 
    else { p.nodeCenterPoint=nullptr; }
    j.at("semiMinorRangeLength").get_to((p.semiMinorRangeLength));
    j.at("semiMajorRangeLength").get_to((p.semiMajorRangeLength));
    j.at("semiMajorRangeOrientation").get_to((p.semiMajorRangeOrientation));
    if (j.contains("semiHeight")) { p.semiHeight = vanetza::asn1::allocate<SemiRangeLength_t>(); j.at("semiHeight").get_to(*(p.semiHeight)); } 
    else { p.semiHeight=nullptr; }
    
}

/*
*   AreaRectangle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaRectangle& p) {
    std::cout << "AreaRectangle" << std::endl;
    j = json{{"semiMajorRangeLength", (p.semiMajorRangeLength)}, {"semiMinorRangeLength", (p.semiMinorRangeLength)}, {"semiMajorRangeOrientation", (p.semiMajorRangeOrientation)}};
    if (p.nodeCenterPoint != 0) j["nodeCenterPoint"] = *(p.nodeCenterPoint);
    if (p.semiHeight != 0) j["semiHeight"] = *(p.semiHeight);
}

void from_json(const json& j, AreaRectangle& p) {
    std::cout << "AreaRectangle" << std::endl;
    if (j.contains("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); j.at("nodeCenterPoint").get_to(*(p.nodeCenterPoint)); } 
    else { p.nodeCenterPoint=nullptr; }
    j.at("semiMajorRangeLength").get_to((p.semiMajorRangeLength));
    j.at("semiMinorRangeLength").get_to((p.semiMinorRangeLength));
    j.at("semiMajorRangeOrientation").get_to((p.semiMajorRangeOrientation));
    if (j.contains("semiHeight")) { p.semiHeight = vanetza::asn1::allocate<SemiRangeLength_t>(); j.at("semiHeight").get_to(*(p.semiHeight)); } 
    else { p.semiHeight=nullptr; }
    
}

/*
*   PolyPointList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PolyPointList& p) {
    std::cout << "PolyPointList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const OffsetPoint_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, PolyPointList& p) {
    PolyPointList* p_tmp = vanetza::asn1::allocate<PolyPointList>();
    for (const auto& item : j.items())
    {
        OffsetPoint_t *element = vanetza::asn1::allocate<OffsetPoint_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   AreaRadial - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaRadial& p) {
    std::cout << "AreaRadial" << std::endl;
    j = json{{"range", (p.range)}, {"stationaryHorizontalOpeningAngleStart", (p.stationaryHorizontalOpeningAngleStart)}, {"stationaryHorizontalOpeningAngleEnd", (p.stationaryHorizontalOpeningAngleEnd)}};
    if (p.verticalOpeningAngleStart != 0) j["verticalOpeningAngleStart"] = *(p.verticalOpeningAngleStart);
    if (p.verticalOpeningAngleEnd != 0) j["verticalOpeningAngleEnd"] = *(p.verticalOpeningAngleEnd);
    if (p.sensorPositionOffset != 0) j["sensorPositionOffset"] = *(p.sensorPositionOffset);
    if (p.sensorHeight != 0) j["sensorHeight"] = *(p.sensorHeight);
}

void from_json(const json& j, AreaRadial& p) {
    std::cout << "AreaRadial" << std::endl;
    j.at("range").get_to((p.range));
    j.at("stationaryHorizontalOpeningAngleStart").get_to((p.stationaryHorizontalOpeningAngleStart));
    j.at("stationaryHorizontalOpeningAngleEnd").get_to((p.stationaryHorizontalOpeningAngleEnd));
    if (j.contains("verticalOpeningAngleStart")) { p.verticalOpeningAngleStart = vanetza::asn1::allocate<CartesianAngleValue_t>(); j.at("verticalOpeningAngleStart").get_to(*(p.verticalOpeningAngleStart)); } 
    else { p.verticalOpeningAngleStart=nullptr; }
    if (j.contains("verticalOpeningAngleEnd")) { p.verticalOpeningAngleEnd = vanetza::asn1::allocate<CartesianAngleValue_t>(); j.at("verticalOpeningAngleEnd").get_to(*(p.verticalOpeningAngleEnd)); } 
    else { p.verticalOpeningAngleEnd=nullptr; }
    if (j.contains("sensorPositionOffset")) { p.sensorPositionOffset = vanetza::asn1::allocate<OffsetPoint_t>(); j.at("sensorPositionOffset").get_to(*(p.sensorPositionOffset)); } 
    else { p.sensorPositionOffset=nullptr; }
    if (j.contains("sensorHeight")) { p.sensorHeight = vanetza::asn1::allocate<SensorHeight_t>(); j.at("sensorHeight").get_to(*(p.sensorHeight)); } 
    else { p.sensorHeight=nullptr; }
    
}

/*
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClassDescription& p) {
    std::cout << "ObjectClassDescription" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const ObjectClass_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, ObjectClassDescription& p) {
    ObjectClassDescription* p_tmp = vanetza::asn1::allocate<ObjectClassDescription>();
    for (const auto& item : j.items())
    {
        ObjectClass_t *element = vanetza::asn1::allocate<ObjectClass_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   CamParameters - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CamParameters& p) {
    std::cout << "CamParameters" << std::endl;
    j = json{{"basicContainer", (p.basicContainer)}, {"highFrequencyContainer", (p.highFrequencyContainer)}};
    if (p.lowFrequencyContainer != 0) j["lowFrequencyContainer"] = *(p.lowFrequencyContainer);
    if (p.specialVehicleContainer != 0) j["specialVehicleContainer"] = *(p.specialVehicleContainer);
}

void from_json(const json& j, CamParameters& p) {
    std::cout << "CamParameters" << std::endl;
    j.at("basicContainer").get_to((p.basicContainer));
    j.at("highFrequencyContainer").get_to((p.highFrequencyContainer));
    if (j.contains("lowFrequencyContainer")) { p.lowFrequencyContainer = vanetza::asn1::allocate<LowFrequencyContainer_t>(); j.at("lowFrequencyContainer").get_to(*(p.lowFrequencyContainer)); } 
    else { p.lowFrequencyContainer=nullptr; }
    if (j.contains("specialVehicleContainer")) { p.specialVehicleContainer = vanetza::asn1::allocate<SpecialVehicleContainer_t>(); j.at("specialVehicleContainer").get_to(*(p.specialVehicleContainer)); } 
    else { p.specialVehicleContainer=nullptr; }
    
}

/*
*   DENM - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const DENM& p) {
    std::cout << "DENM" << std::endl;
    j = json{{"header", (p.header)}, {"denm", (p.denm)}};
    
}

void from_json(const json& j, DENM& p) {
    std::cout << "DENM" << std::endl;
    j.at("header").get_to((p.header));
    j.at("denm").get_to((p.denm));
    
}

/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementList& p) {
    std::cout << "MovementList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const MovementState_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, MovementList& p) {
    MovementList* p_tmp = vanetza::asn1::allocate<MovementList>();
    for (const auto& item : j.items())
    {
        MovementState_t *element = vanetza::asn1::allocate<MovementState_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeSetXY& p) {
    std::cout << "NodeSetXY" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const NodeXY_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, NodeSetXY& p) {
    NodeSetXY* p_tmp = vanetza::asn1::allocate<NodeSetXY>();
    for (const auto& item : j.items())
    {
        NodeXY_t *element = vanetza::asn1::allocate<NodeXY_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const StationDataContainer& p) {
    std::cout << "StationDataContainer" << std::endl;
    j = json{};
    if (p.present == StationDataContainer_PR_originatingVehicleContainer) {
        j["originatingVehicleContainer"] = p.choice.originatingVehicleContainer;
    } else if (p.present == StationDataContainer_PR_originatingRSUContainer) {
        j["originatingRSUContainer"] = p.choice.originatingRSUContainer;
    }
}

void from_json(const json& j, StationDataContainer& p) {
    std::cout << "StationDataContainer" << std::endl;
    if (j.contains("originatingVehicleContainer")) {
        p.present = StationDataContainer_PR_originatingVehicleContainer;
        j.at("originatingVehicleContainer").get_to(p.choice.originatingVehicleContainer);
    } else if (j.contains("originatingRSUContainer")) {
        p.present = StationDataContainer_PR_originatingRSUContainer;
        j.at("originatingRSUContainer").get_to(p.choice.originatingRSUContainer);
    } else {
        p.present = StationDataContainer_PR_NOTHING;
    }
}

/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObject& p) {
    std::cout << "PerceivedObject" << std::endl;
    j = json{{"objectID", (p.objectID)}, {"timeOfMeasurement", (p.timeOfMeasurement)}, {"objectConfidence", (p.objectConfidence)}, {"xDistance", (p.xDistance)}, {"yDistance", (p.yDistance)}, {"xSpeed", (p.xSpeed)}, {"ySpeed", (p.ySpeed)}, {"objectRefPoint", (p.objectRefPoint)}};
    if (p.sensorIDList != 0) j["sensorIDList"] = *(p.sensorIDList);
    if (p.objectAge != 0) j["objectAge"] = *(p.objectAge);
    if (p.zDistance != 0) j["zDistance"] = *(p.zDistance);
    if (p.zSpeed != 0) j["zSpeed"] = *(p.zSpeed);
    if (p.xAcceleration != 0) j["xAcceleration"] = *(p.xAcceleration);
    if (p.yAcceleration != 0) j["yAcceleration"] = *(p.yAcceleration);
    if (p.zAcceleration != 0) j["zAcceleration"] = *(p.zAcceleration);
    if (p.yawAngle != 0) j["yawAngle"] = *(p.yawAngle);
    if (p.planarObjectDimension1 != 0) j["planarObjectDimension1"] = *(p.planarObjectDimension1);
    if (p.planarObjectDimension2 != 0) j["planarObjectDimension2"] = *(p.planarObjectDimension2);
    if (p.verticalObjectDimension != 0) j["verticalObjectDimension"] = *(p.verticalObjectDimension);
    if (p.dynamicStatus != 0) j["dynamicStatus"] = *(p.dynamicStatus);
    if (p.classification != 0) j["classification"] = *(p.classification);
    if (p.matchedPosition != 0) j["matchedPosition"] = *(p.matchedPosition);
}

void from_json(const json& j, PerceivedObject& p) {
    std::cout << "PerceivedObject" << std::endl;
    j.at("objectID").get_to((p.objectID));
    if (j.contains("sensorIDList")) { p.sensorIDList = vanetza::asn1::allocate<SensorIdList_t>(); j.at("sensorIDList").get_to(*(p.sensorIDList)); } 
    else { p.sensorIDList=nullptr; }
    j.at("timeOfMeasurement").get_to((p.timeOfMeasurement));
    if (j.contains("objectAge")) { p.objectAge = vanetza::asn1::allocate<ObjectAge_t>(); j.at("objectAge").get_to(*(p.objectAge)); } 
    else { p.objectAge=nullptr; }
    j.at("objectConfidence").get_to((p.objectConfidence));
    j.at("xDistance").get_to((p.xDistance));
    j.at("yDistance").get_to((p.yDistance));
    if (j.contains("zDistance")) { p.zDistance = vanetza::asn1::allocate<ObjectDistanceWithConfidence_t>(); j.at("zDistance").get_to(*(p.zDistance)); } 
    else { p.zDistance=nullptr; }
    j.at("xSpeed").get_to((p.xSpeed));
    j.at("ySpeed").get_to((p.ySpeed));
    if (j.contains("zSpeed")) { p.zSpeed = vanetza::asn1::allocate<SpeedExtended_t>(); j.at("zSpeed").get_to(*(p.zSpeed)); } 
    else { p.zSpeed=nullptr; }
    if (j.contains("xAcceleration")) { p.xAcceleration = vanetza::asn1::allocate<LongitudinalAcceleration_t>(); j.at("xAcceleration").get_to(*(p.xAcceleration)); } 
    else { p.xAcceleration=nullptr; }
    if (j.contains("yAcceleration")) { p.yAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); j.at("yAcceleration").get_to(*(p.yAcceleration)); } 
    else { p.yAcceleration=nullptr; }
    if (j.contains("zAcceleration")) { p.zAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); j.at("zAcceleration").get_to(*(p.zAcceleration)); } 
    else { p.zAcceleration=nullptr; }
    if (j.contains("yawAngle")) { p.yawAngle = vanetza::asn1::allocate<CartesianAngle_t>(); j.at("yawAngle").get_to(*(p.yawAngle)); } 
    else { p.yawAngle=nullptr; }
    if (j.contains("planarObjectDimension1")) { p.planarObjectDimension1 = vanetza::asn1::allocate<ObjectDimension_t>(); j.at("planarObjectDimension1").get_to(*(p.planarObjectDimension1)); } 
    else { p.planarObjectDimension1=nullptr; }
    if (j.contains("planarObjectDimension2")) { p.planarObjectDimension2 = vanetza::asn1::allocate<ObjectDimension_t>(); j.at("planarObjectDimension2").get_to(*(p.planarObjectDimension2)); } 
    else { p.planarObjectDimension2=nullptr; }
    if (j.contains("verticalObjectDimension")) { p.verticalObjectDimension = vanetza::asn1::allocate<ObjectDimension_t>(); j.at("verticalObjectDimension").get_to(*(p.verticalObjectDimension)); } 
    else { p.verticalObjectDimension=nullptr; }
    j.at("objectRefPoint").get_to((p.objectRefPoint));
    if (j.contains("dynamicStatus")) { p.dynamicStatus = vanetza::asn1::allocate<DynamicStatus_t>(); j.at("dynamicStatus").get_to(*(p.dynamicStatus)); } 
    else { p.dynamicStatus=nullptr; }
    if (j.contains("classification")) { p.classification = vanetza::asn1::allocate<ObjectClassDescription_t>(); j.at("classification").get_to(*(p.classification)); } 
    else { p.classification=nullptr; }
    if (j.contains("matchedPosition")) { p.matchedPosition = vanetza::asn1::allocate<MatchedPosition_t>(); j.at("matchedPosition").get_to(*(p.matchedPosition)); } 
    else { p.matchedPosition=nullptr; }
    
}

/*
*   AreaPolygon - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaPolygon& p) {
    std::cout << "AreaPolygon" << std::endl;
    j = json{{"polyPointList", (p.polyPointList)}};
    
}

void from_json(const json& j, AreaPolygon& p) {
    std::cout << "AreaPolygon" << std::endl;
    j.at("polyPointList").get_to((p.polyPointList));
    
}

/*
*   FreeSpaceArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceArea& p) {
    std::cout << "FreeSpaceArea" << std::endl;
    j = json{};
    if (p.present == FreeSpaceArea_PR_freeSpacePolygon) {
        j["freeSpacePolygon"] = p.choice.freeSpacePolygon;
    } else if (p.present == FreeSpaceArea_PR_freeSpaceCircular) {
        j["freeSpaceCircular"] = p.choice.freeSpaceCircular;
    } else if (p.present == FreeSpaceArea_PR_freeSpaceEllipse) {
        j["freeSpaceEllipse"] = p.choice.freeSpaceEllipse;
    } else if (p.present == FreeSpaceArea_PR_freeSpaceRectangle) {
        j["freeSpaceRectangle"] = p.choice.freeSpaceRectangle;
    }
}

void from_json(const json& j, FreeSpaceArea& p) {
    std::cout << "FreeSpaceArea" << std::endl;
    if (j.contains("freeSpacePolygon")) {
        p.present = FreeSpaceArea_PR_freeSpacePolygon;
        j.at("freeSpacePolygon").get_to(p.choice.freeSpacePolygon);
    } else if (j.contains("freeSpaceCircular")) {
        p.present = FreeSpaceArea_PR_freeSpaceCircular;
        j.at("freeSpaceCircular").get_to(p.choice.freeSpaceCircular);
    } else if (j.contains("freeSpaceEllipse")) {
        p.present = FreeSpaceArea_PR_freeSpaceEllipse;
        j.at("freeSpaceEllipse").get_to(p.choice.freeSpaceEllipse);
    } else if (j.contains("freeSpaceRectangle")) {
        p.present = FreeSpaceArea_PR_freeSpaceRectangle;
        j.at("freeSpaceRectangle").get_to(p.choice.freeSpaceRectangle);
    } else {
        p.present = FreeSpaceArea_PR_NOTHING;
    }
}

/*
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CoopAwareness& p) {
    std::cout << "CoopAwareness" << std::endl;
    j = json{{"generationDeltaTime", (p.generationDeltaTime)}, {"camParameters", (p.camParameters)}};
    
}

void from_json(const json& j, CoopAwareness& p) {
    std::cout << "CoopAwareness" << std::endl;
    j.at("generationDeltaTime").get_to((p.generationDeltaTime));
    j.at("camParameters").get_to((p.camParameters));
    
}

/*
*   IntersectionState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionState& p) {
    std::cout << "IntersectionState" << std::endl;
    j = json{{"id", (p.id)}, {"revision", (p.revision)}, {"status", to_json_IntersectionStatusObject((p.status))}, {"states", (p.states)}};
    if (p.moy != 0) j["moy"] = *(p.moy);
    if (p.timeStamp != 0) j["timeStamp"] = *(p.timeStamp);
    if (p.enabledLanes != 0) j["enabledLanes"] = *(p.enabledLanes);
    if (p.maneuverAssistList != 0) j["maneuverAssistList"] = *(p.maneuverAssistList);
}

void from_json(const json& j, IntersectionState& p) {
    std::cout << "IntersectionState" << std::endl;
    j.at("id").get_to((p.id));
    j.at("revision").get_to((p.revision));
    if (j.contains("moy")) { p.moy = vanetza::asn1::allocate<MinuteOfTheYear_t>(); j.at("moy").get_to(*(p.moy)); } 
    else { p.moy=nullptr; }
    if (j.contains("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<DSecond_t>(); j.at("timeStamp").get_to(*(p.timeStamp)); } 
    else { p.timeStamp=nullptr; }
    if (j.contains("enabledLanes")) { p.enabledLanes = vanetza::asn1::allocate<EnabledLaneList_t>(); j.at("enabledLanes").get_to(*(p.enabledLanes)); } 
    else { p.enabledLanes=nullptr; }
    j.at("states").get_to((p.states));
    if (j.contains("maneuverAssistList")) { p.maneuverAssistList = vanetza::asn1::allocate<ManeuverAssistList_t>(); j.at("maneuverAssistList").get_to(*(p.maneuverAssistList)); } 
    else { p.maneuverAssistList=nullptr; }
    from_json_IntersectionStatusObject(j["status"],(p.status));
}

/*
*   IntersectionStateList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionStateList& p) {
    std::cout << "IntersectionStateList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const IntersectionState_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, IntersectionStateList& p) {
    IntersectionStateList* p_tmp = vanetza::asn1::allocate<IntersectionStateList>();
    for (const auto& item : j.items())
    {
        IntersectionState_t *element = vanetza::asn1::allocate<IntersectionState_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const NodeListXY& p) {
    std::cout << "NodeListXY" << std::endl;
    j = json{};
    if (p.present == NodeListXY_PR_nodes) {
        j["nodes"] = p.choice.nodes;
    } else if (p.present == NodeListXY_PR_computed) {
        j["computed"] = p.choice.computed;
    }
}

void from_json(const json& j, NodeListXY& p) {
    std::cout << "NodeListXY" << std::endl;
    if (j.contains("nodes")) {
        p.present = NodeListXY_PR_nodes;
        j.at("nodes").get_to(p.choice.nodes);
    } else if (j.contains("computed")) {
        p.present = NodeListXY_PR_computed;
        j.at("computed").get_to(p.choice.computed);
    } else {
        p.present = NodeListXY_PR_NOTHING;
    }
}

/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObjectContainer& p) {
    std::cout << "PerceivedObjectContainer" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const PerceivedObject_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, PerceivedObjectContainer& p) {
    //PerceivedObjectContainer* p_tmp = vanetza::asn1::allocate<PerceivedObjectContainer>();
    for (const auto& item : j.items())
    {
        PerceivedObject_t *element = vanetza::asn1::allocate<PerceivedObject_t>();
        item.value().get_to(*element);
        asn_set_add(&p, element);
    }
    //p = *p_tmp;
}

/*
*   DetectionArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const DetectionArea& p) {
    std::cout << "DetectionArea" << std::endl;
    j = json{};
    if (p.present == DetectionArea_PR_vehicleSensor) {
        j["vehicleSensor"] = p.choice.vehicleSensor;
    } else if (p.present == DetectionArea_PR_stationarySensorRadial) {
        j["stationarySensorRadial"] = p.choice.stationarySensorRadial;
    } else if (p.present == DetectionArea_PR_stationarySensorPolygon) {
        j["stationarySensorPolygon"] = p.choice.stationarySensorPolygon;
    } else if (p.present == DetectionArea_PR_stationarySensorCircular) {
        j["stationarySensorCircular"] = p.choice.stationarySensorCircular;
    } else if (p.present == DetectionArea_PR_stationarySensorEllipse) {
        j["stationarySensorEllipse"] = p.choice.stationarySensorEllipse;
    } else if (p.present == DetectionArea_PR_stationarySensorRectangle) {
        j["stationarySensorRectangle"] = p.choice.stationarySensorRectangle;
    }
}

void from_json(const json& j, DetectionArea& p) {
    std::cout << "DetectionArea" << std::endl;
    if (j.contains("vehicleSensor")) {
        p.present = DetectionArea_PR_vehicleSensor;
        j.at("vehicleSensor").get_to(p.choice.vehicleSensor);
    } else if (j.contains("stationarySensorRadial")) {
        p.present = DetectionArea_PR_stationarySensorRadial;
        j.at("stationarySensorRadial").get_to(p.choice.stationarySensorRadial);
    } else if (j.contains("stationarySensorPolygon")) {
        p.present = DetectionArea_PR_stationarySensorPolygon;
        j.at("stationarySensorPolygon").get_to(p.choice.stationarySensorPolygon);
    } else if (j.contains("stationarySensorCircular")) {
        p.present = DetectionArea_PR_stationarySensorCircular;
        j.at("stationarySensorCircular").get_to(p.choice.stationarySensorCircular);
    } else if (j.contains("stationarySensorEllipse")) {
        p.present = DetectionArea_PR_stationarySensorEllipse;
        j.at("stationarySensorEllipse").get_to(p.choice.stationarySensorEllipse);
    } else if (j.contains("stationarySensorRectangle")) {
        p.present = DetectionArea_PR_stationarySensorRectangle;
        j.at("stationarySensorRectangle").get_to(p.choice.stationarySensorRectangle);
    } else {
        p.present = DetectionArea_PR_NOTHING;
    }
}

/*
*   FreeSpaceAddendum - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceAddendum& p) {
    std::cout << "FreeSpaceAddendum" << std::endl;
    j = json{{"freeSpaceConfidence", (p.freeSpaceConfidence)}, {"freeSpaceArea", (p.freeSpaceArea)}};
    if (p.sensorIDList != 0) j["sensorIDList"] = *(p.sensorIDList);
}

void from_json(const json& j, FreeSpaceAddendum& p) {
    std::cout << "FreeSpaceAddendum" << std::endl;
    j.at("freeSpaceConfidence").get_to((p.freeSpaceConfidence));
    j.at("freeSpaceArea").get_to((p.freeSpaceArea));
    if (j.contains("sensorIDList")) { p.sensorIDList = vanetza::asn1::allocate<SensorIdList_t>(); j.at("sensorIDList").get_to(*(p.sensorIDList)); } 
    else { p.sensorIDList=nullptr; }
    
}

/*
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CAM& p) {
    std::cout << "CAM" << std::endl;
    j = json{{"header", (p.header)}, {"cam", (p.cam)}};
    
}

void from_json(const json& j, CAM& p) {
    std::cout << "CAM" << std::endl;
    j.at("header").get_to((p.header));
    j.at("cam").get_to((p.cam));
    
}

/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const SPAT& p) {
    std::cout << "SPAT" << std::endl;
    j = json{{"intersections", (p.intersections)}};
    if (p.timeStamp != 0) j["timeStamp"] = *(p.timeStamp);
}

void from_json(const json& j, SPAT& p) {
    std::cout << "SPAT" << std::endl;
    if (j.contains("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); j.at("timeStamp").get_to(*(p.timeStamp)); } 
    else { p.timeStamp=nullptr; }
    j.at("intersections").get_to((p.intersections));
    
}

/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const GenericLane& p) {
    std::cout << "GenericLane" << std::endl;
    j = json{{"laneID", (p.laneID)}, {"laneAttributes", (p.laneAttributes)}, {"nodeList", (p.nodeList)}};
    if (p.ingressApproach != 0) j["ingressApproach"] = *(p.ingressApproach);
    if (p.egressApproach != 0) j["egressApproach"] = *(p.egressApproach);
    if (p.maneuvers != 0) j["maneuvers"] = to_json_AllowedManeuvers(*(p.maneuvers));
    if (p.connectsTo != 0) j["connectsTo"] = *(p.connectsTo);
    if (p.overlays != 0) j["overlays"] = *(p.overlays);
}

void from_json(const json& j, GenericLane& p) {
    std::cout << "GenericLane" << std::endl;
    j.at("laneID").get_to((p.laneID));
    if (j.contains("ingressApproach")) { p.ingressApproach = vanetza::asn1::allocate<ApproachID_t>(); j.at("ingressApproach").get_to(*(p.ingressApproach)); } 
    else { p.ingressApproach=nullptr; }
    if (j.contains("egressApproach")) { p.egressApproach = vanetza::asn1::allocate<ApproachID_t>(); j.at("egressApproach").get_to(*(p.egressApproach)); } 
    else { p.egressApproach=nullptr; }
    j.at("laneAttributes").get_to((p.laneAttributes));
    j.at("nodeList").get_to((p.nodeList));
    if (j.contains("connectsTo")) { p.connectsTo = vanetza::asn1::allocate<ConnectsToList_t>(); j.at("connectsTo").get_to(*(p.connectsTo)); } 
    else { p.connectsTo=nullptr; }
    if (j.contains("overlays")) { p.overlays = vanetza::asn1::allocate<OverlayLaneList_t>(); j.at("overlays").get_to(*(p.overlays)); } 
    else { p.overlays=nullptr; }
    if (j.contains("maneuvers")) { p.maneuvers = vanetza::asn1::allocate<AllowedManeuvers_t>(); from_json_AllowedManeuvers(j["maneuvers"],*(p.maneuvers)); } 
    else { p.maneuvers=nullptr; }
}

/*
*   LaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneList& p) {
    std::cout << "LaneList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const GenericLane_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, LaneList& p) {
    LaneList* p_tmp = vanetza::asn1::allocate<LaneList>();
    for (const auto& item : j.items())
    {
        GenericLane_t *element = vanetza::asn1::allocate<GenericLane_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   RoadLaneSetList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadLaneSetList& p) {
    std::cout << "RoadLaneSetList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const GenericLane_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, RoadLaneSetList& p) {
    RoadLaneSetList* p_tmp = vanetza::asn1::allocate<RoadLaneSetList>();
    for (const auto& item : j.items())
    {
        GenericLane_t *element = vanetza::asn1::allocate<GenericLane_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   RoadSegment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegment& p) {
    std::cout << "RoadSegment" << std::endl;
    j = json{{"id", (p.id)}, {"revision", (p.revision)}, {"refPoint", (p.refPoint)}, {"roadLaneSet", (p.roadLaneSet)}};
    if (p.laneWidth != 0) j["laneWidth"] = *(p.laneWidth);
    if (p.speedLimits != 0) j["speedLimits"] = *(p.speedLimits);
}

void from_json(const json& j, RoadSegment& p) {
    std::cout << "RoadSegment" << std::endl;
    j.at("id").get_to((p.id));
    j.at("revision").get_to((p.revision));
    j.at("refPoint").get_to((p.refPoint));
    if (j.contains("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<LaneWidth_t>(); j.at("laneWidth").get_to(*(p.laneWidth)); } 
    else { p.laneWidth=nullptr; }
    if (j.contains("speedLimits")) { p.speedLimits = vanetza::asn1::allocate<SpeedLimitList_t>(); j.at("speedLimits").get_to(*(p.speedLimits)); } 
    else { p.speedLimits=nullptr; }
    j.at("roadLaneSet").get_to((p.roadLaneSet));
    
}

/*
*   RoadSegmentList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegmentList& p) {
    std::cout << "RoadSegmentList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const RoadSegment_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, RoadSegmentList& p) {
    RoadSegmentList* p_tmp = vanetza::asn1::allocate<RoadSegmentList>();
    for (const auto& item : j.items())
    {
        RoadSegment_t *element = vanetza::asn1::allocate<RoadSegment_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   SensorInformation - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorInformation& p) {
    std::cout << "SensorInformation" << std::endl;
    j = json{{"sensorID", (p.sensorID)}, {"type", (p.type)}, {"detectionArea", (p.detectionArea)}};
    if (p.freeSpaceConfidence != 0) j["freeSpaceConfidence"] = *(p.freeSpaceConfidence);
}

void from_json(const json& j, SensorInformation& p) {
    std::cout << "SensorInformation" << std::endl;
    j.at("sensorID").get_to((p.sensorID));
    j.at("type").get_to((p.type));
    j.at("detectionArea").get_to((p.detectionArea));
    if (j.contains("freeSpaceConfidence")) { p.freeSpaceConfidence = vanetza::asn1::allocate<FreeSpaceConfidence_t>(); j.at("freeSpaceConfidence").get_to(*(p.freeSpaceConfidence)); } 
    else { p.freeSpaceConfidence=nullptr; }
    
}

/*
*   FreeSpaceAddendumContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceAddendumContainer& p) {
    std::cout << "FreeSpaceAddendumContainer" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const FreeSpaceAddendum_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, FreeSpaceAddendumContainer& p) {
    FreeSpaceAddendumContainer* p_tmp = vanetza::asn1::allocate<FreeSpaceAddendumContainer>();
    for (const auto& item : j.items())
    {
        FreeSpaceAddendum_t *element = vanetza::asn1::allocate<FreeSpaceAddendum_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

void to_json(json& j, const SPATEM& p) {
    std::cout << "SPATEM" << std::endl;
    j = json{{"header", (p.header)}, {"spat", (p.spat)}};
    
}

void from_json(const json& j, SPATEM& p) {
    std::cout << "SPATEM" << std::endl;
    j.at("header").get_to((p.header));
    j.at("spat").get_to((p.spat));
    
}

/*
*   IntersectionGeometry - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionGeometry& p) {
    std::cout << "IntersectionGeometry" << std::endl;
    j = json{{"id", (p.id)}, {"revision", (p.revision)}, {"refPoint", (p.refPoint)}, {"laneSet", (p.laneSet)}};
    if (p.laneWidth != 0) j["laneWidth"] = *(p.laneWidth);
    if (p.speedLimits != 0) j["speedLimits"] = *(p.speedLimits);
}

void from_json(const json& j, IntersectionGeometry& p) {
    std::cout << "IntersectionGeometry" << std::endl;
    j.at("id").get_to((p.id));
    j.at("revision").get_to((p.revision));
    j.at("refPoint").get_to((p.refPoint));
    if (j.contains("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<LaneWidth_t>(); j.at("laneWidth").get_to(*(p.laneWidth)); } 
    else { p.laneWidth=nullptr; }
    if (j.contains("speedLimits")) { p.speedLimits = vanetza::asn1::allocate<SpeedLimitList_t>(); j.at("speedLimits").get_to(*(p.speedLimits)); } 
    else { p.speedLimits=nullptr; }
    j.at("laneSet").get_to((p.laneSet));
    
}

/*
*   IntersectionGeometryList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionGeometryList& p) {
    std::cout << "IntersectionGeometryList" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const IntersectionGeometry_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, IntersectionGeometryList& p) {
    IntersectionGeometryList* p_tmp = vanetza::asn1::allocate<IntersectionGeometryList>();
    for (const auto& item : j.items())
    {
        IntersectionGeometry_t *element = vanetza::asn1::allocate<IntersectionGeometry_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorInformationContainer& p) {
    std::cout << "SensorInformationContainer" << std::endl;
    for(int i = 0; i < p.list.count; i++) {
        json obj;
        const SensorInformation_t po = *(p.list.array[i]);
        to_json(obj, po);
        j.push_back(obj);
    }
}

void from_json(const json& j, SensorInformationContainer& p) {
    SensorInformationContainer* p_tmp = vanetza::asn1::allocate<SensorInformationContainer>();
    for (const auto& item : j.items())
    {
        SensorInformation_t *element = vanetza::asn1::allocate<SensorInformation_t>();
        item.value().get_to(*element);
        asn_set_add(p_tmp, element);
    }
    p = *p_tmp;
}

/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MapData_t& p) {
    std::cout << "MapData" << std::endl;
    j = json{{"msgIssueRevision", (p.msgIssueRevision)}};
    if (p.timeStamp != 0) j["timeStamp"] = *(p.timeStamp);
    if (p.layerType != 0) j["layerType"] = *(p.layerType);
    if (p.layerID != 0) j["layerID"] = *(p.layerID);
    if (p.intersections != 0) j["intersections"] = *(p.intersections);
    if (p.roadSegments != 0) j["roadSegments"] = *(p.roadSegments);
    if (p.dataParameters != 0) j["dataParameters"] = *(p.dataParameters);
    if (p.restrictionList != 0) j["restrictionList"] = *(p.restrictionList);
}

void from_json(const json& j, MapData_t& p) {
    std::cout << "MapData" << std::endl;
    if (j.contains("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); j.at("timeStamp").get_to(*(p.timeStamp)); } 
    else { p.timeStamp=nullptr; }
    j.at("msgIssueRevision").get_to((p.msgIssueRevision));
    if (j.contains("layerType")) { p.layerType = vanetza::asn1::allocate<LayerType_t>(); j.at("layerType").get_to(*(p.layerType)); } 
    else { p.layerType=nullptr; }
    if (j.contains("layerID")) { p.layerID = vanetza::asn1::allocate<LayerID_t>(); j.at("layerID").get_to(*(p.layerID)); } 
    else { p.layerID=nullptr; }
    if (j.contains("intersections")) { p.intersections = vanetza::asn1::allocate<IntersectionGeometryList_t>(); j.at("intersections").get_to(*(p.intersections)); } 
    else { p.intersections=nullptr; }
    if (j.contains("roadSegments")) { p.roadSegments = vanetza::asn1::allocate<RoadSegmentList_t>(); j.at("roadSegments").get_to(*(p.roadSegments)); } 
    else { p.roadSegments=nullptr; }
    if (j.contains("dataParameters")) { p.dataParameters = vanetza::asn1::allocate<DataParameters_t>(); j.at("dataParameters").get_to(*(p.dataParameters)); } 
    else { p.dataParameters=nullptr; }
    if (j.contains("restrictionList")) { p.restrictionList = vanetza::asn1::allocate<RestrictionClassList_t>(); j.at("restrictionList").get_to(*(p.restrictionList)); } 
    else { p.restrictionList=nullptr; }
    
}

/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CpmParameters& p) {
    std::cout << "CpmParameters" << std::endl;
    j = json{{"managementContainer", (p.managementContainer)}, {"numberOfPerceivedObjects", (p.numberOfPerceivedObjects)}};
    if (p.stationDataContainer != 0) j["stationDataContainer"] = *(p.stationDataContainer);
    if (p.sensorInformationContainer != 0) j["sensorInformationContainer"] = *(p.sensorInformationContainer);
    if (p.perceivedObjectContainer != 0) j["perceivedObjectContainer"] = *(p.perceivedObjectContainer);
    if (p.freeSpaceAddendumContainer != 0) j["freeSpaceAddendumContainer"] = *(p.freeSpaceAddendumContainer);
}

void from_json(const json& j, CpmParameters& p) {
    std::cout << "CpmParameters" << std::endl;
    j.at("managementContainer").get_to((p.managementContainer));
    if (j.contains("stationDataContainer")) { p.stationDataContainer = vanetza::asn1::allocate<StationDataContainer_t>(); j.at("stationDataContainer").get_to(*(p.stationDataContainer)); } 
    else { p.stationDataContainer=nullptr; }
    if (j.contains("sensorInformationContainer")) { p.sensorInformationContainer = vanetza::asn1::allocate<SensorInformationContainer_t>(); j.at("sensorInformationContainer").get_to(*(p.sensorInformationContainer)); } 
    else { p.sensorInformationContainer=nullptr; }
    if (j.contains("perceivedObjectContainer")) { p.perceivedObjectContainer = vanetza::asn1::allocate<PerceivedObjectContainer_t>(); j.at("perceivedObjectContainer").get_to(*(p.perceivedObjectContainer)); } 
    else { p.perceivedObjectContainer=nullptr; }
    if (j.contains("freeSpaceAddendumContainer")) { p.freeSpaceAddendumContainer = vanetza::asn1::allocate<FreeSpaceAddendumContainer_t>(); j.at("freeSpaceAddendumContainer").get_to(*(p.freeSpaceAddendumContainer)); } 
    else { p.freeSpaceAddendumContainer=nullptr; }
    j.at("numberOfPerceivedObjects").get_to((p.numberOfPerceivedObjects));
    
}

/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

void to_json(json& j, const MAPEM& p) {
    std::cout << "MAPEM" << std::endl;
    j = json{{"header", (p.header)}, {"map", (p.map)}};
    
}

void from_json(const json& j, MAPEM& p) {
    std::cout << "MAPEM" << std::endl;
    j.at("header").get_to((p.header));
    j.at("map").get_to((p.map));
    
}

/*
*   CollectivePerceptionMessage - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CollectivePerceptionMessage& p) {
    std::cout << "CollectivePerceptionMessage" << std::endl;
    j = json{{"generationDeltaTime", (p.generationDeltaTime)}, {"cpmParameters", (p.cpmParameters)}};
    
}

void from_json(const json& j, CollectivePerceptionMessage& p) {
    std::cout << "CollectivePerceptionMessage" << std::endl;
    j.at("generationDeltaTime").get_to((p.generationDeltaTime));
    j.at("cpmParameters").get_to((p.cpmParameters));
    
}

/*
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CPM& p) {
    std::cout << "CPM" << std::endl;
    j = json{{"header", (p.header)}, {"cpm", (p.cpm)}};
    
}

void from_json(const json& j, CPM& p) {
    std::cout << "CPM" << std::endl;
    j.at("header").get_to((p.header));
    j.at("cpm").get_to((p.cpm));
    
}
