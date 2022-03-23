/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2022-01-06 04:54:50.616735
*/

#include <nlohmann/json.hpp>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>

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
    j.at("pathPosition").get_to((p.pathPosition));
    j.at("pathDeltaTime").get_to(*(p.pathDeltaTime));
    
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
    p.size = (7 / 8) + 1;
    p.bits_unused = 8 - (7 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (brakePedalEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (gasPedalEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (emergencyBrakeEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (collisionWarningEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (accEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (cruiseControlEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (speedLimiterEngaged) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
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
    
    
    p.size = (0 / 8) + 1;
    p.bits_unused = 8 - (0 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
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
    j.at("lateralAccelerationValue").get_to((p.lateralAccelerationValue));
    j.at("lateralAccelerationConfidence").get_to((p.lateralAccelerationConfidence));
    
}

/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VerticalAcceleration& p) {
    std::cout << "VerticalAcceleration" << std::endl;
    j = json{{"verticalAccelerationValue", (p.verticalAccelerationValue)}, {"verticalAccelerationConfidence", (p.verticalAccelerationConfidence)}};
    
}

void from_json(const json& j, VerticalAcceleration& p) {
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
    p.size = (8 / 8) + 1;
    p.bits_unused = 8 - (8 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p.buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (lowBeamHeadlightsOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (highBeamHeadlightsOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (leftTurnSignalOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (rightTurnSignalOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (daytimeRunningLightsOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (reverseLightOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (fogLightOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (parkingLightsOn) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
}

/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DangerousGoodsExtended& p) {
    std::cout << "DangerousGoodsExtended" << std::endl;
    j = json{{"dangerousGoodsType", (p.dangerousGoodsType)}, {"unNumber", (p.unNumber)}, {"elevatedTemperature", (p.elevatedTemperature)}, {"tunnelsRestricted", (p.tunnelsRestricted)}, {"limitedQuantity", (p.limitedQuantity)}};
    if (p.emergencyActionCode != 0) j["emergencyActionCode"] = *(p.emergencyActionCode);
    if (p.phoneNumber != 0) j["phoneNumber"] = *(p.phoneNumber);
    if (p.companyName != 0) j["companyName"] = *(p.companyName);
}

void from_json(const json& j, DangerousGoodsExtended& p) {
    j.at("dangerousGoodsType").get_to((p.dangerousGoodsType));
    j.at("unNumber").get_to((p.unNumber));
    j.at("elevatedTemperature").get_to((p.elevatedTemperature));
    j.at("tunnelsRestricted").get_to((p.tunnelsRestricted));
    j.at("limitedQuantity").get_to((p.limitedQuantity));
    j.at("emergencyActionCode").get_to(*(p.emergencyActionCode));
    j.at("phoneNumber").get_to(*(p.phoneNumber));
    j.at("companyName").get_to(*(p.companyName));
    
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
    bool heavyLoad;
    bool excessWidth;
    bool excessLength;
    bool excessHeight;
    j.at("heavyLoad").get_to((heavyLoad));
    j.at("excessWidth").get_to((excessWidth));
    j.at("excessLength").get_to((excessLength));
    j.at("excessHeight").get_to((excessHeight));
    p.size = (4 / 8) + 1;
    p.bits_unused = 8 - (4 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (heavyLoad) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (excessWidth) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (excessLength) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (excessHeight) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
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
    bool lightBarActivated;
    bool sirenActivated;
    j.at("lightBarActivated").get_to((lightBarActivated));
    j.at("sirenActivated").get_to((sirenActivated));
    p.size = (2 / 8) + 1;
    p.bits_unused = 8 - (2 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (lightBarActivated) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (sirenActivated) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
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
    p.size = (20 / 8) + 1;
    p.bits_unused = 8 - (20 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p.buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    *(p.buf + (sizeof(uint8_t) * 2)) = (uint8_t) 0;
    if (row1LeftOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (row1RightOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (row1MidOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (row1NotDetectable) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (row1NotPresent) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (row2LeftOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (row2RightOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (row2MidOccupied) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (row2NotDetectable) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (row2NotPresent) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    if (row3LeftOccupied) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    if (row3RightOccupied) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    if (row3MidOccupied) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    if (row3NotDetectable) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    if (row3NotPresent) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    if (row4LeftOccupied) *(p.buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (row4RightOccupied) *(p.buf + (sizeof(uint8_t) * 2)) |= (1 << 0);
    if (row4MidOccupied) *(p.buf + (sizeof(uint8_t) * 2)) |= (1 << 1);
    if (row4NotDetectable) *(p.buf + (sizeof(uint8_t) * 2)) |= (1 << 2);
    if (row4NotPresent) *(p.buf + (sizeof(uint8_t) * 2)) |= (1 << 3);
}

/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleIdentification& p) {
    std::cout << "VehicleIdentification" << std::endl;
    j = json{};
    if (p.wMInumber != 0) j["wMInumber"] = *(p.wMInumber);
    if (p.vDS != 0) j["vDS"] = *(p.vDS);
}

void from_json(const json& j, VehicleIdentification& p) {
    j.at("wMInumber").get_to(*(p.wMInumber));
    j.at("vDS").get_to(*(p.vDS));
    
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
    p.size = (7 / 8) + 1;
    p.bits_unused = 8 - (7 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (hydrogenStorage) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (electricEnergyStorage) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (liquidPropaneGas) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (compressedNaturalGas) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (diesel) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (gasoline) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (ammonia) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
}

/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleLength& p) {
    std::cout << "VehicleLength" << std::endl;
    j = json{{"vehicleLengthValue", (p.vehicleLengthValue)}, {"vehicleLengthConfidenceIndication", (p.vehicleLengthConfidenceIndication)}};
    
}

void from_json(const json& j, VehicleLength& p) {
    j.at("vehicleLengthValue").get_to((p.vehicleLengthValue));
    j.at("vehicleLengthConfidenceIndication").get_to((p.vehicleLengthConfidenceIndication));
    
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
    bool requestForRightOfWay;
    bool requestForFreeCrossingAtATrafficLight;
    j.at("requestForRightOfWay").get_to((requestForRightOfWay));
    j.at("requestForFreeCrossingAtATrafficLight").get_to((requestForFreeCrossingAtATrafficLight));
    p.size = (2 / 8) + 1;
    p.bits_unused = 8 - (2 % 8);
    p.buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p.size);
    *(p.buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (requestForRightOfWay) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (requestForFreeCrossingAtATrafficLight) *(p.buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
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
    //if (p.expiryTime != 0) j["expiryTime"] = *(p.expiryTime);
    if (p.protectedZoneRadius != 0) j["protectedZoneRadius"] = *(p.protectedZoneRadius);
    if (p.protectedZoneID != 0) j["protectedZoneID"] = *(p.protectedZoneID);
}

void from_json(const json& j, ProtectedCommunicationZone& p) {
    j.at("protectedZoneType").get_to((p.protectedZoneType));
    //j.at("expiryTime").get_to(*(p.expiryTime));
    j.at("protectedZoneLatitude").get_to((p.protectedZoneLatitude));
    j.at("protectedZoneLongitude").get_to((p.protectedZoneLongitude));
    j.at("protectedZoneRadius").get_to(*(p.protectedZoneRadius));
    j.at("protectedZoneID").get_to(*(p.protectedZoneID));
    
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
    j.at("eventPosition").get_to((p.eventPosition));
    j.at("eventDeltaTime").get_to(*(p.eventDeltaTime));
    j.at("informationQuality").get_to((p.informationQuality));
    
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
    j.at("protectedZoneLatitude").get_to((p.protectedZoneLatitude));
    j.at("protectedZoneLongitude").get_to((p.protectedZoneLongitude));
    j.at("cenDsrcTollingZoneID").get_to(*(p.cenDsrcTollingZoneID));
    
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
    j.at("heading").get_to((p.heading));
    j.at("speed").get_to((p.speed));
    j.at("driveDirection").get_to((p.driveDirection));
    j.at("vehicleLength").get_to((p.vehicleLength));
    j.at("vehicleWidth").get_to((p.vehicleWidth));
    j.at("longitudinalAcceleration").get_to((p.longitudinalAcceleration));
    j.at("curvature").get_to((p.curvature));
    j.at("curvatureCalculationMode").get_to((p.curvatureCalculationMode));
    j.at("yawRate").get_to((p.yawRate));
    j.at("lanePosition").get_to(*(p.lanePosition));
    j.at("steeringWheelAngle").get_to(*(p.steeringWheelAngle));
    j.at("lateralAcceleration").get_to(*(p.lateralAcceleration));
    j.at("verticalAcceleration").get_to(*(p.verticalAcceleration));
    j.at("performanceClass").get_to(*(p.performanceClass));
    j.at("cenDsrcTollingZone").get_to(*(p.cenDsrcTollingZone));
    from_json_AccelerationControl(j["accelerationControl"],*(p.accelerationControl));
}

/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicVehicleContainerLowFrequency& p) {
    std::cout << "BasicVehicleContainerLowFrequency" << std::endl;
    j = json{{"vehicleRole", (p.vehicleRole)}, {"exteriorLights", to_json_ExteriorLights((p.exteriorLights))}};
    
}

void from_json(const json& j, BasicVehicleContainerLowFrequency& p) {
    j.at("vehicleRole").get_to((p.vehicleRole));
    //j.at("pathHistory").get_to((p.pathHistory));
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
    j.at("incidentIndication").get_to(*(p.incidentIndication));
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
    from_json_EmergencyPriority(j["emergencyPriority"],*(p.emergencyPriority));
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
    j.at("incidentIndication").get_to(*(p.incidentIndication));
    j.at("trafficRule").get_to(*(p.trafficRule));
    j.at("speedLimit").get_to(*(p.speedLimit));
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}

/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RSUContainerHighFrequency& p) {
    std::cout << "RSUContainerHighFrequency" << std::endl;
    j = json{};
    //if (p.protectedCommunicationZonesRSU != 0) j["protectedCommunicationZonesRSU"] = *(p.protectedCommunicationZonesRSU);
}

void from_json(const json& j, RSUContainerHighFrequency& p) {
    //j.at("protectedCommunicationZonesRSU").get_to(*(p.protectedCommunicationZonesRSU));
    
}

/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const SituationContainer& p) {
    std::cout << "SituationContainer" << std::endl;
    j = json{{"informationQuality", (p.informationQuality)}, {"eventType", (p.eventType)}};
    if (p.linkedCause != 0) j["linkedCause"] = *(p.linkedCause);
    //if (p.eventHistory != 0) j["eventHistory"] = *(p.eventHistory);
}

void from_json(const json& j, SituationContainer& p) {
    j.at("informationQuality").get_to((p.informationQuality));
    j.at("eventType").get_to((p.eventType));
    j.at("linkedCause").get_to(*(p.linkedCause));
    //j.at("eventHistory").get_to(*(p.eventHistory));
    
}

/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const LocationContainer& p) {
    std::cout << "LocationContainer" << std::endl;
    j = json{};
    if (p.eventSpeed != 0) j["eventSpeed"] = *(p.eventSpeed);
    if (p.eventPositionHeading != 0) j["eventPositionHeading"] = *(p.eventPositionHeading);
    if (p.roadType != 0) j["roadType"] = *(p.roadType);
}

void from_json(const json& j, LocationContainer& p) {
    j.at("eventSpeed").get_to(*(p.eventSpeed));
    j.at("eventPositionHeading").get_to(*(p.eventPositionHeading));
    //j.at("traces").get_to((p.traces));
    j.at("roadType").get_to(*(p.roadType));
    
}

/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ImpactReductionContainer& p) {
    std::cout << "ImpactReductionContainer" << std::endl;
    j = json{{"heightLonCarrLeft", (p.heightLonCarrLeft)}, {"heightLonCarrRight", (p.heightLonCarrRight)}, {"posLonCarrLeft", (p.posLonCarrLeft)}, {"posLonCarrRight", (p.posLonCarrRight)}, {"posCentMass", (p.posCentMass)}, {"wheelBaseVehicle", (p.wheelBaseVehicle)}, {"turningRadius", (p.turningRadius)}, {"posFrontAx", (p.posFrontAx)}, {"positionOfOccupants", to_json_PositionOfOccupants((p.positionOfOccupants))}, {"vehicleMass", (p.vehicleMass)}, {"requestResponseIndication", (p.requestResponseIndication)}};
    
}

void from_json(const json& j, ImpactReductionContainer& p) {
    j.at("heightLonCarrLeft").get_to((p.heightLonCarrLeft));
    j.at("heightLonCarrRight").get_to((p.heightLonCarrRight));
    j.at("posLonCarrLeft").get_to((p.posLonCarrLeft));
    j.at("posLonCarrRight").get_to((p.posLonCarrRight));
    //j.at("positionOfPillars").get_to((p.positionOfPillars));
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
    j.at("stationarySince").get_to(*(p.stationarySince));
    j.at("stationaryCause").get_to(*(p.stationaryCause));
    j.at("carryingDangerousGoods").get_to(*(p.carryingDangerousGoods));
    j.at("numberOfOccupants").get_to(*(p.numberOfOccupants));
    j.at("vehicleIdentification").get_to(*(p.vehicleIdentification));
    from_json_EnergyStorageType(j["energyStorageType"],*(p.energyStorageType));
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
    j.at("innerhardShoulderStatus").get_to(*(p.innerhardShoulderStatus));
    j.at("outerhardShoulderStatus").get_to(*(p.outerhardShoulderStatus));
    from_json_DrivingLaneStatus(j["drivingLaneStatus"],*(p.drivingLaneStatus));
}

/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const HighFrequencyContainer& p) {
    std::cout << "HighFrequencyContainer" << std::endl;
    j = json{{"basicVehicleContainerHighFrequency", (p.choice.basicVehicleContainerHighFrequency)}, {"rsuContainerHighFrequency", (p.choice.rsuContainerHighFrequency)}};
    
}

void from_json(const json& j, HighFrequencyContainer& p) {
    j.at("basicVehicleContainerHighFrequency").get_to((p.choice.basicVehicleContainerHighFrequency));
    j.at("rsuContainerHighFrequency").get_to((p.choice.rsuContainerHighFrequency));
    
}

/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const LowFrequencyContainer& p) {
    std::cout << "LowFrequencyContainer" << std::endl;
    j = json{{"basicVehicleContainerLowFrequency", (p.choice.basicVehicleContainerLowFrequency)}};
    
}

void from_json(const json& j, LowFrequencyContainer& p) {
    j.at("basicVehicleContainerLowFrequency").get_to((p.choice.basicVehicleContainerLowFrequency));
    
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
    j.at("embarkationStatus").get_to((p.embarkationStatus));
    j.at("ptActivation").get_to(*(p.ptActivation));
    
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
    j.at("roadworksSubCauseCode").get_to(*(p.roadworksSubCauseCode));
    j.at("closedLanes").get_to(*(p.closedLanes));
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
    j.at("actionID").get_to((p.actionID));
    //j.at("detectionTime").get_to((p.detectionTime));
    //j.at("referenceTime").get_to((p.referenceTime));
    j.at("termination").get_to(*(p.termination));
    j.at("eventPosition").get_to((p.eventPosition));
    j.at("relevanceDistance").get_to(*(p.relevanceDistance));
    j.at("relevanceTrafficDirection").get_to(*(p.relevanceTrafficDirection));
    //j.at("validityDuration").get_to((p.validityDuration));
    j.at("transmissionInterval").get_to(*(p.transmissionInterval));
    j.at("stationType").get_to((p.stationType));
    
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
    //if (p.restriction != 0) j["restriction"] = *(p.restriction);
    if (p.speedLimit != 0) j["speedLimit"] = *(p.speedLimit);
    if (p.incidentIndication != 0) j["incidentIndication"] = *(p.incidentIndication);
    //if (p.recommendedPath != 0) j["recommendedPath"] = *(p.recommendedPath);
    if (p.startingPointSpeedLimit != 0) j["startingPointSpeedLimit"] = *(p.startingPointSpeedLimit);
    if (p.trafficFlowRule != 0) j["trafficFlowRule"] = *(p.trafficFlowRule);
    //if (p.referenceDenms != 0) j["referenceDenms"] = *(p.referenceDenms);
}

void from_json(const json& j, RoadWorksContainerExtended& p) {
    j.at("closedLanes").get_to(*(p.closedLanes));
    //j.at("restriction").get_to(*(p.restriction));
    j.at("speedLimit").get_to(*(p.speedLimit));
    j.at("incidentIndication").get_to(*(p.incidentIndication));
    //j.at("recommendedPath").get_to(*(p.recommendedPath));
    j.at("startingPointSpeedLimit").get_to(*(p.startingPointSpeedLimit));
    j.at("trafficFlowRule").get_to(*(p.trafficFlowRule));
    //j.at("referenceDenms").get_to(*(p.referenceDenms));
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],*(p.lightBarSirenInUse));
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
    j.at("lanePosition").get_to(*(p.lanePosition));
    j.at("impactReduction").get_to(*(p.impactReduction));
    j.at("externalTemperature").get_to(*(p.externalTemperature));
    j.at("roadWorks").get_to(*(p.roadWorks));
    j.at("positioningSolution").get_to(*(p.positioningSolution));
    j.at("stationaryVehicle").get_to(*(p.stationaryVehicle));
    
}

/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SpecialVehicleContainer& p) {
    std::cout << "SpecialVehicleContainer" << std::endl;
    j = json{{"publicTransportContainer", (p.choice.publicTransportContainer)}, {"specialTransportContainer", (p.choice.specialTransportContainer)}, {"dangerousGoodsContainer", (p.choice.dangerousGoodsContainer)}, {"roadWorksContainerBasic", (p.choice.roadWorksContainerBasic)}, {"rescueContainer", (p.choice.rescueContainer)}, {"emergencyContainer", (p.choice.emergencyContainer)}, {"safetyCarContainer", (p.choice.safetyCarContainer)}};
    
}

void from_json(const json& j, SpecialVehicleContainer& p) {
    j.at("publicTransportContainer").get_to((p.choice.publicTransportContainer));
    j.at("specialTransportContainer").get_to((p.choice.specialTransportContainer));
    j.at("dangerousGoodsContainer").get_to((p.choice.dangerousGoodsContainer));
    j.at("roadWorksContainerBasic").get_to((p.choice.roadWorksContainerBasic));
    j.at("rescueContainer").get_to((p.choice.rescueContainer));
    j.at("emergencyContainer").get_to((p.choice.emergencyContainer));
    j.at("safetyCarContainer").get_to((p.choice.safetyCarContainer));
    
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
    j.at("management").get_to((p.management));
    j.at("situation").get_to(*(p.situation));
    j.at("location").get_to(*(p.location));
    j.at("alacarte").get_to(*(p.alacarte));
    
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
    j.at("basicContainer").get_to((p.basicContainer));
    j.at("highFrequencyContainer").get_to((p.highFrequencyContainer));
    j.at("lowFrequencyContainer").get_to(*(p.lowFrequencyContainer));
    j.at("specialVehicleContainer").get_to(*(p.specialVehicleContainer));
    
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
    j.at("header").get_to((p.header));
    j.at("denm").get_to((p.denm));
    
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
    j.at("generationDeltaTime").get_to((p.generationDeltaTime));
    j.at("camParameters").get_to((p.camParameters));
    
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
    j.at("header").get_to((p.header));
    j.at("cam").get_to((p.cam));
    
}
