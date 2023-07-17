/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2023-07-17 20:40:53.604128
*/

#include "asn1json.hpp"
#include <boost/optional.hpp>

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator) {
    long tmp;
    asn_INTEGER2long(&p, &tmp);
    return Value(tmp);
}

void from_json(const Value& j, TimestampIts_t& p) {
    p.buf = nullptr;
    asn_long2INTEGER(&p, j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64());
}

Value to_json(const long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, long& p) {
    p = j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64();
}

Value to_json(const unsigned long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned long& p) {
    p = j.GetUint64();
}

Value to_json(const unsigned& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned& p) {
    if (j.IsBool()) p = j.GetBool();
    else p = j.GetUint();
}

Value to_json(const double& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, double& p) {
    p = j.GetDouble();
}

Value to_json(const bool& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, bool& p) {
    p = j.GetBool();
}

Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, OCTET_STRING_t& p) {
    // TODO
}



/*
*   ItsPduHeader - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItsPduHeader_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("protocolVersion", to_json((p.protocolVersion), allocator), allocator);
    json.AddMember("messageID", to_json((p.messageID), allocator), allocator);
    json.AddMember("stationID", to_json((p.stationID), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ItsPduHeader_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["protocolVersion"], (p.protocolVersion));
    from_json(j["messageID"], (p.messageID));
    from_json(j["stationID"], (p.stationID));
}



/*
*   DeltaReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DeltaReferencePosition_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("deltaLatitude", to_json((p.deltaLatitude), allocator), allocator);
    json.AddMember("deltaLongitude", to_json((p.deltaLongitude), allocator), allocator);
    json.AddMember("deltaAltitude", to_json((p.deltaAltitude), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DeltaReferencePosition_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["deltaLatitude"], (p.deltaLatitude));
    from_json(j["deltaLongitude"], (p.deltaLongitude));
    from_json(j["deltaAltitude"], (p.deltaAltitude));
}



/*
*   Altitude - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Altitude& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("altitudeValue", to_json(((p.altitudeValue) == 800001) ? (p.altitudeValue) : (double)(p.altitudeValue) / 100.0, allocator), allocator);
    json.AddMember("altitudeConfidence", to_json((p.altitudeConfidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Altitude& p) {
    p._asn_ctx.ptr = nullptr;
    double altitudeValue; from_json(j["altitudeValue"], (altitudeValue)); (p.altitudeValue) = ((altitudeValue) != 800001) ? altitudeValue * 100 : altitudeValue;
    from_json(j["altitudeConfidence"], (p.altitudeConfidence));
}



/*
*   PosConfidenceEllipse - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PosConfidenceEllipse& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("semiMajorConfidence", to_json((p.semiMajorConfidence), allocator), allocator);
    json.AddMember("semiMinorConfidence", to_json((p.semiMinorConfidence), allocator), allocator);
    json.AddMember("semiMajorOrientation", to_json(((p.semiMajorOrientation) == 3601) ? (p.semiMajorOrientation) : (double)(p.semiMajorOrientation) / 10.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PosConfidenceEllipse& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["semiMajorConfidence"], (p.semiMajorConfidence));
    from_json(j["semiMinorConfidence"], (p.semiMinorConfidence));
    double semiMajorOrientation; from_json(j["semiMajorOrientation"], (semiMajorOrientation)); (p.semiMajorOrientation) = ((semiMajorOrientation) != 3601) ? semiMajorOrientation * 10 : semiMajorOrientation;
}



/*
*   PathPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathPoint& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pathPosition", to_json((p.pathPosition), allocator), allocator);
    if (p.pathDeltaTime != 0) json.AddMember("pathDeltaTime", to_json(*(p.pathDeltaTime), allocator), allocator);
    return json;
}

void from_json(const Value& j, PathPoint& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["pathPosition"], (p.pathPosition));
    if (j.HasMember("pathDeltaTime")) { p.pathDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>(); from_json(j["pathDeltaTime"], *(p.pathDeltaTime)); }
    else { p.pathDeltaTime=nullptr; }
}



/*
*   AccelerationControl - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_AccelerationControl(const AccelerationControl_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("brakePedalEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("gasPedalEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("emergencyBrakeEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("collisionWarningEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("accEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("cruiseControlEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("speedLimiterEngaged", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    return json;
}

void from_json_AccelerationControl(const Value& j, AccelerationControl_t& p) {
    AccelerationControl_t* p_tmp = vanetza::asn1::allocate<AccelerationControl_t>();
    bool brakePedalEngaged;
    bool gasPedalEngaged;
    bool emergencyBrakeEngaged;
    bool collisionWarningEngaged;
    bool accEngaged;
    bool cruiseControlEngaged;
    bool speedLimiterEngaged;
    if (j.HasMember("brakePedalEngaged")) from_json(j["brakePedalEngaged"], (brakePedalEngaged));
    if (j.HasMember("gasPedalEngaged")) from_json(j["gasPedalEngaged"], (gasPedalEngaged));
    if (j.HasMember("emergencyBrakeEngaged")) from_json(j["emergencyBrakeEngaged"], (emergencyBrakeEngaged));
    if (j.HasMember("collisionWarningEngaged")) from_json(j["collisionWarningEngaged"], (collisionWarningEngaged));
    if (j.HasMember("accEngaged")) from_json(j["accEngaged"], (accEngaged));
    if (j.HasMember("cruiseControlEngaged")) from_json(j["cruiseControlEngaged"], (cruiseControlEngaged));
    if (j.HasMember("speedLimiterEngaged")) from_json(j["speedLimiterEngaged"], (speedLimiterEngaged));
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
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CauseCode - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CauseCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("causeCode", to_json((p.causeCode), allocator), allocator);
    json.AddMember("subCauseCode", to_json((p.subCauseCode), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CauseCode& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["causeCode"], (p.causeCode));
    from_json(j["subCauseCode"], (p.subCauseCode));
}



/*
*   Curvature - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Curvature& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("curvatureValue", to_json((p.curvatureValue), allocator), allocator);
    json.AddMember("curvatureConfidence", to_json((p.curvatureConfidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Curvature& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["curvatureValue"], (p.curvatureValue));
    from_json(j["curvatureConfidence"], (p.curvatureConfidence));
}



/*
*   Heading - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Heading& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("headingValue", to_json(((p.headingValue) == 3601) ? (p.headingValue) : (double)(p.headingValue) / 10.0, allocator), allocator);
    json.AddMember("headingConfidence", to_json(((p.headingConfidence) == 126 || (p.headingConfidence) == 127) ? (p.headingConfidence) : (double)(p.headingConfidence) / 10.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Heading& p) {
    p._asn_ctx.ptr = nullptr;
    double headingValue; from_json(j["headingValue"], (headingValue)); (p.headingValue) = ((headingValue) != 3601) ? headingValue * 10 : headingValue;
    double headingConfidence; from_json(j["headingConfidence"], (headingConfidence)); (p.headingConfidence) = ((headingConfidence) != 126 && (headingConfidence) != 127) ? headingConfidence * 10 : headingConfidence;
}



/*
*   DrivingLaneStatus - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_DrivingLaneStatus(const DrivingLaneStatus_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    return json;
}

void from_json_DrivingLaneStatus(const Value& j, DrivingLaneStatus_t& p) {
    DrivingLaneStatus_t* p_tmp = vanetza::asn1::allocate<DrivingLaneStatus_t>();
    
    
    p_tmp->size = (0 / 8) + 1;
    p_tmp->bits_unused = (0 % 8) != 0 ? 8 - (0 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
    p = *p_tmp;
    delete p_tmp;
}

/*
*   Speed - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Speed& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("speedValue", to_json(((p.speedValue) == 16383) ? (p.speedValue) : (double)(p.speedValue) / 100.0, allocator), allocator);
    json.AddMember("speedConfidence", to_json(((p.speedConfidence) == 126 || (p.speedConfidence) == 127) ? (p.speedConfidence) : (double)(p.speedConfidence) / 100.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Speed& p) {
    p._asn_ctx.ptr = nullptr;
    double speedValue; from_json(j["speedValue"], (speedValue)); (p.speedValue) = ((speedValue) != 16383) ? speedValue * 100 : speedValue;
    double speedConfidence; from_json(j["speedConfidence"], (speedConfidence)); (p.speedConfidence) = ((speedConfidence) != 126 && (speedConfidence) != 127) ? speedConfidence * 100 : speedConfidence;
}



/*
*   LongitudinalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LongitudinalAcceleration& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("longitudinalAccelerationValue", to_json(((p.longitudinalAccelerationValue) == 161) ? (p.longitudinalAccelerationValue) : (double)(p.longitudinalAccelerationValue) / 10.0, allocator), allocator);
    json.AddMember("longitudinalAccelerationConfidence", to_json(((p.longitudinalAccelerationConfidence) == 102) ? (p.longitudinalAccelerationConfidence) : (double)(p.longitudinalAccelerationConfidence) / 10.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LongitudinalAcceleration& p) {
    p._asn_ctx.ptr = nullptr;
    double longitudinalAccelerationValue; from_json(j["longitudinalAccelerationValue"], (longitudinalAccelerationValue)); (p.longitudinalAccelerationValue) = ((longitudinalAccelerationValue) != 161) ? longitudinalAccelerationValue * 10 : longitudinalAccelerationValue;
    double longitudinalAccelerationConfidence; from_json(j["longitudinalAccelerationConfidence"], (longitudinalAccelerationConfidence)); (p.longitudinalAccelerationConfidence) = ((longitudinalAccelerationConfidence) != 102) ? longitudinalAccelerationConfidence * 10 : longitudinalAccelerationConfidence;
}



/*
*   LateralAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LateralAcceleration& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lateralAccelerationValue", to_json(((p.lateralAccelerationValue) == 161) ? (p.lateralAccelerationValue) : (double)(p.lateralAccelerationValue) / 10.0, allocator), allocator);
    json.AddMember("lateralAccelerationConfidence", to_json(((p.lateralAccelerationConfidence) == 102) ? (p.lateralAccelerationConfidence) : (double)(p.lateralAccelerationConfidence) / 10.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LateralAcceleration& p) {
    p._asn_ctx.ptr = nullptr;
    double lateralAccelerationValue; from_json(j["lateralAccelerationValue"], (lateralAccelerationValue)); (p.lateralAccelerationValue) = ((lateralAccelerationValue) != 161) ? lateralAccelerationValue * 10 : lateralAccelerationValue;
    double lateralAccelerationConfidence; from_json(j["lateralAccelerationConfidence"], (lateralAccelerationConfidence)); (p.lateralAccelerationConfidence) = ((lateralAccelerationConfidence) != 102) ? lateralAccelerationConfidence * 10 : lateralAccelerationConfidence;
}



/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VerticalAcceleration_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("verticalAccelerationValue", to_json(((p.verticalAccelerationValue) == 161) ? (p.verticalAccelerationValue) : (double)(p.verticalAccelerationValue) / 10.0, allocator), allocator);
    json.AddMember("verticalAccelerationConfidence", to_json(((p.verticalAccelerationConfidence) == 102) ? (p.verticalAccelerationConfidence) : (double)(p.verticalAccelerationConfidence) / 10.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VerticalAcceleration_t& p) {
    p._asn_ctx.ptr = nullptr;
    double verticalAccelerationValue; from_json(j["verticalAccelerationValue"], (verticalAccelerationValue)); (p.verticalAccelerationValue) = ((verticalAccelerationValue) != 161) ? verticalAccelerationValue * 10 : verticalAccelerationValue;
    double verticalAccelerationConfidence; from_json(j["verticalAccelerationConfidence"], (verticalAccelerationConfidence)); (p.verticalAccelerationConfidence) = ((verticalAccelerationConfidence) != 102) ? verticalAccelerationConfidence * 10 : verticalAccelerationConfidence;
}



/*
*   ExteriorLights - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_ExteriorLights(const ExteriorLights_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lowBeamHeadlightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("highBeamHeadlightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("leftTurnSignalOn", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("rightTurnSignalOn", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("daytimeRunningLightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("reverseLightOn", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("fogLightOn", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("parkingLightsOn", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_ExteriorLights(const Value& j, ExteriorLights_t& p) {
    ExteriorLights_t* p_tmp = vanetza::asn1::allocate<ExteriorLights_t>();
    bool lowBeamHeadlightsOn;
    bool highBeamHeadlightsOn;
    bool leftTurnSignalOn;
    bool rightTurnSignalOn;
    bool daytimeRunningLightsOn;
    bool reverseLightOn;
    bool fogLightOn;
    bool parkingLightsOn;
    if (j.HasMember("lowBeamHeadlightsOn")) from_json(j["lowBeamHeadlightsOn"], (lowBeamHeadlightsOn));
    if (j.HasMember("highBeamHeadlightsOn")) from_json(j["highBeamHeadlightsOn"], (highBeamHeadlightsOn));
    if (j.HasMember("leftTurnSignalOn")) from_json(j["leftTurnSignalOn"], (leftTurnSignalOn));
    if (j.HasMember("rightTurnSignalOn")) from_json(j["rightTurnSignalOn"], (rightTurnSignalOn));
    if (j.HasMember("daytimeRunningLightsOn")) from_json(j["daytimeRunningLightsOn"], (daytimeRunningLightsOn));
    if (j.HasMember("reverseLightOn")) from_json(j["reverseLightOn"], (reverseLightOn));
    if (j.HasMember("fogLightOn")) from_json(j["fogLightOn"], (fogLightOn));
    if (j.HasMember("parkingLightsOn")) from_json(j["parkingLightsOn"], (parkingLightsOn));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (lowBeamHeadlightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (highBeamHeadlightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (leftTurnSignalOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (rightTurnSignalOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (daytimeRunningLightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (reverseLightOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (fogLightOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (parkingLightsOn) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DangerousGoodsExtended& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("dangerousGoodsType", to_json((p.dangerousGoodsType), allocator), allocator);
    json.AddMember("unNumber", to_json((p.unNumber), allocator), allocator);
    json.AddMember("elevatedTemperature", to_json((p.elevatedTemperature), allocator), allocator);
    json.AddMember("tunnelsRestricted", to_json((p.tunnelsRestricted), allocator), allocator);
    json.AddMember("limitedQuantity", to_json((p.limitedQuantity), allocator), allocator);
    if (p.emergencyActionCode != 0) json.AddMember("emergencyActionCode", to_json(*(p.emergencyActionCode), allocator), allocator);
    if (p.companyName != 0) json.AddMember("companyName", to_json(*(p.companyName), allocator), allocator);
    return json;
}

void from_json(const Value& j, DangerousGoodsExtended& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["dangerousGoodsType"], (p.dangerousGoodsType));
    from_json(j["unNumber"], (p.unNumber));
    from_json(j["elevatedTemperature"], (p.elevatedTemperature));
    from_json(j["tunnelsRestricted"], (p.tunnelsRestricted));
    from_json(j["limitedQuantity"], (p.limitedQuantity));
    if (j.HasMember("emergencyActionCode")) { p.emergencyActionCode = vanetza::asn1::allocate<IA5String_t>(); from_json(j["emergencyActionCode"], *(p.emergencyActionCode)); }
    else { p.emergencyActionCode=nullptr; }
    if (j.HasMember("companyName")) { p.companyName = vanetza::asn1::allocate<UTF8String_t>(); from_json(j["companyName"], *(p.companyName)); }
    else { p.companyName=nullptr; }
    p.phoneNumber=nullptr;
}



/*
*   SpecialTransportType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_SpecialTransportType(const SpecialTransportType_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heavyLoad", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("excessWidth", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("excessLength", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("excessHeight", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    return json;
}

void from_json_SpecialTransportType(const Value& j, SpecialTransportType_t& p) {
    SpecialTransportType_t* p_tmp = vanetza::asn1::allocate<SpecialTransportType_t>();
    bool heavyLoad;
    bool excessWidth;
    bool excessLength;
    bool excessHeight;
    if (j.HasMember("heavyLoad")) from_json(j["heavyLoad"], (heavyLoad));
    if (j.HasMember("excessWidth")) from_json(j["excessWidth"], (excessWidth));
    if (j.HasMember("excessLength")) from_json(j["excessLength"], (excessLength));
    if (j.HasMember("excessHeight")) from_json(j["excessHeight"], (excessHeight));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = (4 % 8) != 0 ? 8 - (4 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (heavyLoad) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (excessWidth) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (excessLength) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (excessHeight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LightBarSirenInUse - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_LightBarSirenInUse(const LightBarSirenInUse_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lightBarActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("sirenActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    return json;
}

void from_json_LightBarSirenInUse(const Value& j, LightBarSirenInUse_t& p) {
    LightBarSirenInUse_t* p_tmp = vanetza::asn1::allocate<LightBarSirenInUse_t>();
    bool lightBarActivated;
    bool sirenActivated;
    if (j.HasMember("lightBarActivated")) from_json(j["lightBarActivated"], (lightBarActivated));
    if (j.HasMember("sirenActivated")) from_json(j["sirenActivated"], (sirenActivated));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = (2 % 8) != 0 ? 8 - (2 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (lightBarActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (sirenActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PositionOfOccupants - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_PositionOfOccupants(const PositionOfOccupants_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("row1LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("row1RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("row1MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("row1NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("row1NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("row2LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("row2RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("row2MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("row2NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    json.AddMember("row2NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8)))), allocator);
    json.AddMember("row3LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8)))), allocator);
    json.AddMember("row3RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8)))), allocator);
    json.AddMember("row3MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (12 / 8))) & (1 << ((7 * ((12 / 8) + 1))-(12 % 8)))), allocator);
    json.AddMember("row3NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (13 / 8))) & (1 << ((7 * ((13 / 8) + 1))-(13 % 8)))), allocator);
    json.AddMember("row3NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (14 / 8))) & (1 << ((7 * ((14 / 8) + 1))-(14 % 8)))), allocator);
    json.AddMember("row4LeftOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (15 / 8))) & (1 << ((7 * ((15 / 8) + 1))-(15 % 8)))), allocator);
    json.AddMember("row4RightOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (16 / 8))) & (1 << ((7 * ((16 / 8) + 1))-(16 % 8)))), allocator);
    json.AddMember("row4MidOccupied", (bool) (*(p.buf + (sizeof(uint8_t) * (17 / 8))) & (1 << ((7 * ((17 / 8) + 1))-(17 % 8)))), allocator);
    json.AddMember("row4NotDetectable", (bool) (*(p.buf + (sizeof(uint8_t) * (18 / 8))) & (1 << ((7 * ((18 / 8) + 1))-(18 % 8)))), allocator);
    json.AddMember("row4NotPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (19 / 8))) & (1 << ((7 * ((19 / 8) + 1))-(19 % 8)))), allocator);
    return json;
}

void from_json_PositionOfOccupants(const Value& j, PositionOfOccupants_t& p) {
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
    if (j.HasMember("row1LeftOccupied")) from_json(j["row1LeftOccupied"], (row1LeftOccupied));
    if (j.HasMember("row1RightOccupied")) from_json(j["row1RightOccupied"], (row1RightOccupied));
    if (j.HasMember("row1MidOccupied")) from_json(j["row1MidOccupied"], (row1MidOccupied));
    if (j.HasMember("row1NotDetectable")) from_json(j["row1NotDetectable"], (row1NotDetectable));
    if (j.HasMember("row1NotPresent")) from_json(j["row1NotPresent"], (row1NotPresent));
    if (j.HasMember("row2LeftOccupied")) from_json(j["row2LeftOccupied"], (row2LeftOccupied));
    if (j.HasMember("row2RightOccupied")) from_json(j["row2RightOccupied"], (row2RightOccupied));
    if (j.HasMember("row2MidOccupied")) from_json(j["row2MidOccupied"], (row2MidOccupied));
    if (j.HasMember("row2NotDetectable")) from_json(j["row2NotDetectable"], (row2NotDetectable));
    if (j.HasMember("row2NotPresent")) from_json(j["row2NotPresent"], (row2NotPresent));
    if (j.HasMember("row3LeftOccupied")) from_json(j["row3LeftOccupied"], (row3LeftOccupied));
    if (j.HasMember("row3RightOccupied")) from_json(j["row3RightOccupied"], (row3RightOccupied));
    if (j.HasMember("row3MidOccupied")) from_json(j["row3MidOccupied"], (row3MidOccupied));
    if (j.HasMember("row3NotDetectable")) from_json(j["row3NotDetectable"], (row3NotDetectable));
    if (j.HasMember("row3NotPresent")) from_json(j["row3NotPresent"], (row3NotPresent));
    if (j.HasMember("row4LeftOccupied")) from_json(j["row4LeftOccupied"], (row4LeftOccupied));
    if (j.HasMember("row4RightOccupied")) from_json(j["row4RightOccupied"], (row4RightOccupied));
    if (j.HasMember("row4MidOccupied")) from_json(j["row4MidOccupied"], (row4MidOccupied));
    if (j.HasMember("row4NotDetectable")) from_json(j["row4NotDetectable"], (row4NotDetectable));
    if (j.HasMember("row4NotPresent")) from_json(j["row4NotPresent"], (row4NotPresent));
    p_tmp->size = (20 / 8) + 1;
    p_tmp->bits_unused = (20 % 8) != 0 ? 8 - (20 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 2)) = (uint8_t) 0;
    if (row1LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (row1RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (row1MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (row1NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (row1NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (row2LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (row2RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (row2MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (row2NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (row2NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    if (row3LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    if (row3RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    if (row3MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    if (row3NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    if (row3NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 1);
    if (row4LeftOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 0);
    if (row4RightOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 7);
    if (row4MidOccupied) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 6);
    if (row4NotDetectable) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 5);
    if (row4NotPresent) *(p_tmp->buf + (sizeof(uint8_t) * 2)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleIdentification& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    
    return json;
}

void from_json(const Value& j, VehicleIdentification& p) {
    p._asn_ctx.ptr = nullptr;
    p.wMInumber=nullptr;
    p.vDS=nullptr;
}



/*
*   EnergyStorageType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EnergyStorageType(const EnergyStorageType_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("hydrogenStorage", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("electricEnergyStorage", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("liquidPropaneGas", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("compressedNaturalGas", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("diesel", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("gasoline", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("ammonia", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    return json;
}

void from_json_EnergyStorageType(const Value& j, EnergyStorageType_t& p) {
    EnergyStorageType_t* p_tmp = vanetza::asn1::allocate<EnergyStorageType_t>();
    bool hydrogenStorage;
    bool electricEnergyStorage;
    bool liquidPropaneGas;
    bool compressedNaturalGas;
    bool diesel;
    bool gasoline;
    bool ammonia;
    if (j.HasMember("hydrogenStorage")) from_json(j["hydrogenStorage"], (hydrogenStorage));
    if (j.HasMember("electricEnergyStorage")) from_json(j["electricEnergyStorage"], (electricEnergyStorage));
    if (j.HasMember("liquidPropaneGas")) from_json(j["liquidPropaneGas"], (liquidPropaneGas));
    if (j.HasMember("compressedNaturalGas")) from_json(j["compressedNaturalGas"], (compressedNaturalGas));
    if (j.HasMember("diesel")) from_json(j["diesel"], (diesel));
    if (j.HasMember("gasoline")) from_json(j["gasoline"], (gasoline));
    if (j.HasMember("ammonia")) from_json(j["ammonia"], (ammonia));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = (7 % 8) != 0 ? 8 - (7 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (hydrogenStorage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (electricEnergyStorage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (liquidPropaneGas) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (compressedNaturalGas) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (diesel) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (gasoline) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (ammonia) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleLength_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vehicleLengthValue", to_json(((p.vehicleLengthValue) == 1023) ? (p.vehicleLengthValue) : (double)(p.vehicleLengthValue) / 10.0, allocator), allocator);
    json.AddMember("vehicleLengthConfidenceIndication", to_json((p.vehicleLengthConfidenceIndication), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleLength_t& p) {
    p._asn_ctx.ptr = nullptr;
    double vehicleLengthValue; from_json(j["vehicleLengthValue"], (vehicleLengthValue)); (p.vehicleLengthValue) = ((vehicleLengthValue) != 1023) ? vehicleLengthValue * 10 : vehicleLengthValue;
    from_json(j["vehicleLengthConfidenceIndication"], (p.vehicleLengthConfidenceIndication));
}



/*
*   PathHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathHistory& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PathPoint_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, PathHistory& p) {
    PathHistory* p_tmp = vanetza::asn1::allocate<PathHistory>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PathPoint_t *element = vanetza::asn1::allocate<PathPoint_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   EmergencyPriority - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EmergencyPriority(const EmergencyPriority_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("requestForRightOfWay", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("requestForFreeCrossingAtATrafficLight", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    return json;
}

void from_json_EmergencyPriority(const Value& j, EmergencyPriority_t& p) {
    EmergencyPriority_t* p_tmp = vanetza::asn1::allocate<EmergencyPriority_t>();
    bool requestForRightOfWay;
    bool requestForFreeCrossingAtATrafficLight;
    if (j.HasMember("requestForRightOfWay")) from_json(j["requestForRightOfWay"], (requestForRightOfWay));
    if (j.HasMember("requestForFreeCrossingAtATrafficLight")) from_json(j["requestForFreeCrossingAtATrafficLight"], (requestForFreeCrossingAtATrafficLight));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = (2 % 8) != 0 ? 8 - (2 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (requestForRightOfWay) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (requestForFreeCrossingAtATrafficLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SteeringWheelAngle - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const SteeringWheelAngle& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("steeringWheelAngleValue", to_json((p.steeringWheelAngleValue), allocator), allocator);
    json.AddMember("steeringWheelAngleConfidence", to_json((p.steeringWheelAngleConfidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SteeringWheelAngle& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["steeringWheelAngleValue"], (p.steeringWheelAngleValue));
    from_json(j["steeringWheelAngleConfidence"], (p.steeringWheelAngleConfidence));
}



/*
*   YawRate - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const YawRate& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("yawRateValue", to_json(((p.yawRateValue) == 32767) ? (p.yawRateValue) : (double)(p.yawRateValue) / 100.0, allocator), allocator);
    json.AddMember("yawRateConfidence", to_json((p.yawRateConfidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, YawRate& p) {
    p._asn_ctx.ptr = nullptr;
    double yawRateValue; from_json(j["yawRateValue"], (yawRateValue)); (p.yawRateValue) = ((yawRateValue) != 32767) ? yawRateValue * 100 : yawRateValue;
    from_json(j["yawRateConfidence"], (p.yawRateConfidence));
}



/*
*   ActionID - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ActionID& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("originatingStationID", to_json((p.originatingStationID), allocator), allocator);
    json.AddMember("sequenceNumber", to_json((p.sequenceNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ActionID& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["originatingStationID"], (p.originatingStationID));
    from_json(j["sequenceNumber"], (p.sequenceNumber));
}



/*
*   ProtectedCommunicationZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZone& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("protectedZoneType", to_json((p.protectedZoneType), allocator), allocator);
    json.AddMember("protectedZoneLatitude", to_json(((p.protectedZoneLatitude) == 900000001) ? (p.protectedZoneLatitude) : (double)(p.protectedZoneLatitude) / 10000000.0, allocator), allocator);
    json.AddMember("protectedZoneLongitude", to_json(((p.protectedZoneLongitude) == 1800000001) ? (p.protectedZoneLongitude) : (double)(p.protectedZoneLongitude) / 10000000.0, allocator), allocator);
    if (p.protectedZoneRadius != 0) json.AddMember("protectedZoneRadius", to_json(*(p.protectedZoneRadius), allocator), allocator);
    if (p.protectedZoneID != 0) json.AddMember("protectedZoneID", to_json(*(p.protectedZoneID), allocator), allocator);
    return json;
}

void from_json(const Value& j, ProtectedCommunicationZone& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["protectedZoneType"], (p.protectedZoneType));
    double protectedZoneLatitude; from_json(j["protectedZoneLatitude"], (protectedZoneLatitude)); (p.protectedZoneLatitude) = ((protectedZoneLatitude) != 900000001) ? protectedZoneLatitude * 10000000 : protectedZoneLatitude;
    double protectedZoneLongitude; from_json(j["protectedZoneLongitude"], (protectedZoneLongitude)); (p.protectedZoneLongitude) = ((protectedZoneLongitude) != 1800000001) ? protectedZoneLongitude * 10000000 : protectedZoneLongitude;
    if (j.HasMember("protectedZoneRadius")) { p.protectedZoneRadius = vanetza::asn1::allocate<ProtectedZoneRadius_t>(); from_json(j["protectedZoneRadius"], *(p.protectedZoneRadius)); }
    else { p.protectedZoneRadius=nullptr; }
    if (j.HasMember("protectedZoneID")) { p.protectedZoneID = vanetza::asn1::allocate<ProtectedZoneID_t>(); from_json(j["protectedZoneID"], *(p.protectedZoneID)); }
    else { p.protectedZoneID=nullptr; }
    p.expiryTime=nullptr;
}



/*
*   Traces - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Traces& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PathHistory_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, Traces& p) {
    Traces* p_tmp = vanetza::asn1::allocate<Traces>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PathHistory_t *element = vanetza::asn1::allocate<PathHistory_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PositionOfPillars - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PositionOfPillars& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PosPillar_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, PositionOfPillars& p) {
    PositionOfPillars* p_tmp = vanetza::asn1::allocate<PositionOfPillars>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PosPillar_t *element = vanetza::asn1::allocate<PosPillar_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RestrictedTypes - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const RestrictedTypes& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const StationType_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, RestrictedTypes& p) {
    RestrictedTypes* p_tmp = vanetza::asn1::allocate<RestrictedTypes>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        StationType_t *element = vanetza::asn1::allocate<StationType_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   EventPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventPoint& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("eventPosition", to_json((p.eventPosition), allocator), allocator);
    json.AddMember("informationQuality", to_json((p.informationQuality), allocator), allocator);
    if (p.eventDeltaTime != 0) json.AddMember("eventDeltaTime", to_json(*(p.eventDeltaTime), allocator), allocator);
    return json;
}

void from_json(const Value& j, EventPoint& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["eventPosition"], (p.eventPosition));
    if (j.HasMember("eventDeltaTime")) { p.eventDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>(); from_json(j["eventDeltaTime"], *(p.eventDeltaTime)); }
    else { p.eventDeltaTime=nullptr; }
    from_json(j["informationQuality"], (p.informationQuality));
}



/*
*   ProtectedCommunicationZonesRSU - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZonesRSU& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ProtectedCommunicationZone_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ProtectedCommunicationZonesRSU& p) {
    ProtectedCommunicationZonesRSU* p_tmp = vanetza::asn1::allocate<ProtectedCommunicationZonesRSU>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ProtectedCommunicationZone_t *element = vanetza::asn1::allocate<ProtectedCommunicationZone_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CenDsrcTollingZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CenDsrcTollingZone& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("protectedZoneLatitude", to_json(((p.protectedZoneLatitude) == 900000001) ? (p.protectedZoneLatitude) : (double)(p.protectedZoneLatitude) / 10000000.0, allocator), allocator);
    json.AddMember("protectedZoneLongitude", to_json(((p.protectedZoneLongitude) == 1800000001) ? (p.protectedZoneLongitude) : (double)(p.protectedZoneLongitude) / 10000000.0, allocator), allocator);
    if (p.cenDsrcTollingZoneID != 0) json.AddMember("cenDsrcTollingZoneID", to_json(*(p.cenDsrcTollingZoneID), allocator), allocator);
    return json;
}

void from_json(const Value& j, CenDsrcTollingZone& p) {
    p._asn_ctx.ptr = nullptr;
    double protectedZoneLatitude; from_json(j["protectedZoneLatitude"], (protectedZoneLatitude)); (p.protectedZoneLatitude) = ((protectedZoneLatitude) != 900000001) ? protectedZoneLatitude * 10000000 : protectedZoneLatitude;
    double protectedZoneLongitude; from_json(j["protectedZoneLongitude"], (protectedZoneLongitude)); (p.protectedZoneLongitude) = ((protectedZoneLongitude) != 1800000001) ? protectedZoneLongitude * 10000000 : protectedZoneLongitude;
    if (j.HasMember("cenDsrcTollingZoneID")) { p.cenDsrcTollingZoneID = vanetza::asn1::allocate<CenDsrcTollingZoneID_t>(); from_json(j["cenDsrcTollingZoneID"], *(p.cenDsrcTollingZoneID)); }
    else { p.cenDsrcTollingZoneID=nullptr; }
}



/*
*   LaneAttributes-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const LaneAttributes_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.maxVehicleHeight != 0) json.AddMember("maxVehicleHeight", to_json(*(p.maxVehicleHeight), allocator), allocator);
    if (p.maxVehicleWeight != 0) json.AddMember("maxVehicleWeight", to_json(*(p.maxVehicleWeight), allocator), allocator);
    return json;
}

void from_json(const Value& j, LaneAttributes_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("maxVehicleHeight")) { p.maxVehicleHeight = vanetza::asn1::allocate<VehicleHeight_t>(); from_json(j["maxVehicleHeight"], *(p.maxVehicleHeight)); }
    else { p.maxVehicleHeight=nullptr; }
    if (j.HasMember("maxVehicleWeight")) { p.maxVehicleWeight = vanetza::asn1::allocate<VehicleMass_t>(); from_json(j["maxVehicleWeight"], *(p.maxVehicleWeight)); }
    else { p.maxVehicleWeight=nullptr; }
}



/*
*   MovementEvent-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MovementEvent_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.stateChangeReason != 0) json.AddMember("stateChangeReason", to_json(*(p.stateChangeReason), allocator), allocator);
    return json;
}

void from_json(const Value& j, MovementEvent_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("stateChangeReason")) { p.stateChangeReason = vanetza::asn1::allocate<ExceptionalCondition_t>(); from_json(j["stateChangeReason"], *(p.stateChangeReason)); }
    else { p.stateChangeReason=nullptr; }
}



/*
*   Position3D-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Position3D_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("altitude", to_json((p.altitude), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Position3D_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["altitude"], (p.altitude));
}



/*
*   RestrictionUserType-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RestrictionUserType_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.emission != 0) json.AddMember("emission", to_json(*(p.emission), allocator), allocator);
    if (p.fuel != 0) json.AddMember("fuel", to_json(*(p.fuel), allocator), allocator);
    return json;
}

void from_json(const Value& j, RestrictionUserType_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("emission")) { p.emission = vanetza::asn1::allocate<EmissionType_t>(); from_json(j["emission"], *(p.emission)); }
    else { p.emission=nullptr; }
    if (j.HasMember("fuel")) { p.fuel = vanetza::asn1::allocate<FuelType_t>(); from_json(j["fuel"], *(p.fuel)); }
    else { p.fuel=nullptr; }
}



/*
*   RequestorDescription-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RequestorDescription_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.fuel != 0) json.AddMember("fuel", to_json(*(p.fuel), allocator), allocator);
    if (p.batteryStatus != 0) json.AddMember("batteryStatus", to_json(*(p.batteryStatus), allocator), allocator);
    return json;
}

void from_json(const Value& j, RequestorDescription_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("fuel")) { p.fuel = vanetza::asn1::allocate<FuelType_t>(); from_json(j["fuel"], *(p.fuel)); }
    else { p.fuel=nullptr; }
    if (j.HasMember("batteryStatus")) { p.batteryStatus = vanetza::asn1::allocate<BatteryStatus_t>(); from_json(j["batteryStatus"], *(p.batteryStatus)); }
    else { p.batteryStatus=nullptr; }
}



/*
*   SignalStatusPackage-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.synchToSchedule != 0) json.AddMember("synchToSchedule", to_json(*(p.synchToSchedule), allocator), allocator);
    if (p.rejectedReason != 0) json.AddMember("rejectedReason", to_json(*(p.rejectedReason), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalStatusPackage_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("synchToSchedule")) { p.synchToSchedule = vanetza::asn1::allocate<DeltaTime_t>(); from_json(j["synchToSchedule"], *(p.synchToSchedule)); }
    else { p.synchToSchedule=nullptr; }
    if (j.HasMember("rejectedReason")) { p.rejectedReason = vanetza::asn1::allocate<RejectedReason_t>(); from_json(j["rejectedReason"], *(p.rejectedReason)); }
    else { p.rejectedReason=nullptr; }
}



/*
*   Node - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Node& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    if (p.lane != 0) json.AddMember("lane", to_json(*(p.lane), allocator), allocator);
    if (p.connectionID != 0) json.AddMember("connectionID", to_json(*(p.connectionID), allocator), allocator);
    if (p.intersectionID != 0) json.AddMember("intersectionID", to_json(*(p.intersectionID), allocator), allocator);
    return json;
}

void from_json(const Value& j, Node& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    if (j.HasMember("lane")) { p.lane = vanetza::asn1::allocate<LaneID_t>(); from_json(j["lane"], *(p.lane)); }
    else { p.lane=nullptr; }
    if (j.HasMember("connectionID")) { p.connectionID = vanetza::asn1::allocate<LaneConnectionID_t>(); from_json(j["connectionID"], *(p.connectionID)); }
    else { p.connectionID=nullptr; }
    if (j.HasMember("intersectionID")) { p.intersectionID = vanetza::asn1::allocate<IntersectionID_t>(); from_json(j["intersectionID"], *(p.intersectionID)); }
    else { p.intersectionID=nullptr; }
}



/*
*   NodeLink - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeLink& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Node_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, NodeLink& p) {
    NodeLink* p_tmp = vanetza::asn1::allocate<NodeLink>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Node_t *element = vanetza::asn1::allocate<Node_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PrioritizationResponse - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponse& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stationID", to_json((p.stationID), allocator), allocator);
    json.AddMember("priorState", to_json((p.priorState), allocator), allocator);
    json.AddMember("signalGroup", to_json((p.signalGroup), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PrioritizationResponse& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["stationID"], (p.stationID));
    from_json(j["priorState"], (p.priorState));
    from_json(j["signalGroup"], (p.signalGroup));
}



/*
*   PrioritizationResponseList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponseList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PrioritizationResponse_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, PrioritizationResponseList& p) {
    PrioritizationResponseList* p_tmp = vanetza::asn1::allocate<PrioritizationResponseList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PrioritizationResponse_t *element = vanetza::asn1::allocate<PrioritizationResponse_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeed& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    if (p.speed != 0) json.AddMember("speed", to_json(*(p.speed), allocator), allocator);
    if (p.confidence != 0) json.AddMember("confidence", to_json(*(p.confidence), allocator), allocator);
    if (p.distance != 0) json.AddMember("distance", to_json(*(p.distance), allocator), allocator);
    if (p.Class != 0) json.AddMember("class", to_json(*(p.Class), allocator), allocator);
    return json;
}

void from_json(const Value& j, AdvisorySpeed& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    if (j.HasMember("speed")) { p.speed = vanetza::asn1::allocate<SpeedAdvice_t>(); from_json(j["speed"], *(p.speed)); }
    else { p.speed=nullptr; }
    if (j.HasMember("confidence")) { p.confidence = vanetza::asn1::allocate<SpeedConfidenceIso_t>(); from_json(j["confidence"], *(p.confidence)); }
    else { p.confidence=nullptr; }
    if (j.HasMember("distance")) { p.distance = vanetza::asn1::allocate<ZoneLength_t>(); from_json(j["distance"], *(p.distance)); }
    else { p.distance=nullptr; }
    if (j.HasMember("class")) { p.Class = vanetza::asn1::allocate<RestrictionClassID_t>(); from_json(j["class"], *(p.Class)); }
    else { p.Class=nullptr; }
    p.regional=nullptr;
}



/*
*   AdvisorySpeedList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeedList_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const AdvisorySpeed_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, AdvisorySpeedList_t& p) {
    AdvisorySpeedList_t* p_tmp = vanetza::asn1::allocate<AdvisorySpeedList_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        AdvisorySpeed_t *element = vanetza::asn1::allocate<AdvisorySpeed_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AntennaOffsetSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AntennaOffsetSet& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("antOffsetX", to_json((p.antOffsetX), allocator), allocator);
    json.AddMember("antOffsetY", to_json((p.antOffsetY), allocator), allocator);
    json.AddMember("antOffsetZ", to_json((p.antOffsetZ), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AntennaOffsetSet& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["antOffsetX"], (p.antOffsetX));
    from_json(j["antOffsetY"], (p.antOffsetY));
    from_json(j["antOffsetZ"], (p.antOffsetZ));
}



/*
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetXaxis& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ComputedLane__offsetXaxis_PR::ComputedLane__offsetXaxis_PR_small) {
        json.AddMember("small", to_json(p.choice.small, allocator), allocator);
    } else if (p.present == ComputedLane__offsetXaxis_PR::ComputedLane__offsetXaxis_PR_large) {
        json.AddMember("large", to_json(p.choice.large, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ComputedLane::ComputedLane__offsetXaxis& p) {
    if (j.HasMember("small")) {
        p.present = ComputedLane__offsetXaxis_PR::ComputedLane__offsetXaxis_PR_small;
        from_json(j["small"], p.choice.small);
    } else if (j.HasMember("large")) {
        p.present = ComputedLane__offsetXaxis_PR::ComputedLane__offsetXaxis_PR_large;
        from_json(j["large"], p.choice.large);
    } else {
        p.present = ComputedLane__offsetXaxis_PR::ComputedLane__offsetXaxis_PR_NOTHING;
    }
}

/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetYaxis& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ComputedLane__offsetYaxis_PR::ComputedLane__offsetYaxis_PR_small) {
        json.AddMember("small", to_json(p.choice.small, allocator), allocator);
    } else if (p.present == ComputedLane__offsetYaxis_PR::ComputedLane__offsetYaxis_PR_large) {
        json.AddMember("large", to_json(p.choice.large, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ComputedLane::ComputedLane__offsetYaxis& p) {
    if (j.HasMember("small")) {
        p.present = ComputedLane__offsetYaxis_PR::ComputedLane__offsetYaxis_PR_small;
        from_json(j["small"], p.choice.small);
    } else if (j.HasMember("large")) {
        p.present = ComputedLane__offsetYaxis_PR::ComputedLane__offsetYaxis_PR_large;
        from_json(j["large"], p.choice.large);
    } else {
        p.present = ComputedLane__offsetYaxis_PR::ComputedLane__offsetYaxis_PR_NOTHING;
    }
}

/*
*   ComputedLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("referenceLaneId", to_json((p.referenceLaneId), allocator), allocator);
    json.AddMember("offsetXaxis", to_json((p.offsetXaxis), allocator), allocator);
    json.AddMember("offsetYaxis", to_json((p.offsetYaxis), allocator), allocator);
    if (p.rotateXY != 0) json.AddMember("rotateXY", to_json(*(p.rotateXY), allocator), allocator);
    if (p.scaleXaxis != 0) json.AddMember("scaleXaxis", to_json(*(p.scaleXaxis), allocator), allocator);
    if (p.scaleYaxis != 0) json.AddMember("scaleYaxis", to_json(*(p.scaleYaxis), allocator), allocator);
    return json;
}

void from_json(const Value& j, ComputedLane_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["referenceLaneId"], (p.referenceLaneId));
    from_json(j["offsetXaxis"], (p.offsetXaxis));
    from_json(j["offsetYaxis"], (p.offsetYaxis));
    if (j.HasMember("rotateXY")) { p.rotateXY = vanetza::asn1::allocate<Angle_t>(); from_json(j["rotateXY"], *(p.rotateXY)); }
    else { p.rotateXY=nullptr; }
    if (j.HasMember("scaleXaxis")) { p.scaleXaxis = vanetza::asn1::allocate<Scale_B12_t>(); from_json(j["scaleXaxis"], *(p.scaleXaxis)); }
    else { p.scaleXaxis=nullptr; }
    if (j.HasMember("scaleYaxis")) { p.scaleYaxis = vanetza::asn1::allocate<Scale_B12_t>(); from_json(j["scaleYaxis"], *(p.scaleYaxis)); }
    else { p.scaleYaxis=nullptr; }
    p.regional=nullptr;
}



/*
*   ConnectionManeuverAssist - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("connectionID", to_json((p.connectionID), allocator), allocator);
    if (p.queueLength != 0) json.AddMember("queueLength", to_json(*(p.queueLength), allocator), allocator);
    if (p.availableStorageLength != 0) json.AddMember("availableStorageLength", to_json(*(p.availableStorageLength), allocator), allocator);
    if (p.waitOnStop != 0) json.AddMember("waitOnStop", to_json(*(p.waitOnStop), allocator), allocator);
    if (p.pedBicycleDetect != 0) json.AddMember("pedBicycleDetect", to_json(*(p.pedBicycleDetect), allocator), allocator);
    return json;
}

void from_json(const Value& j, ConnectionManeuverAssist_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["connectionID"], (p.connectionID));
    if (j.HasMember("queueLength")) { p.queueLength = vanetza::asn1::allocate<ZoneLength_t>(); from_json(j["queueLength"], *(p.queueLength)); }
    else { p.queueLength=nullptr; }
    if (j.HasMember("availableStorageLength")) { p.availableStorageLength = vanetza::asn1::allocate<ZoneLength_t>(); from_json(j["availableStorageLength"], *(p.availableStorageLength)); }
    else { p.availableStorageLength=nullptr; }
    if (j.HasMember("waitOnStop")) { p.waitOnStop = vanetza::asn1::allocate<WaitOnStopline_t>(); from_json(j["waitOnStop"], *(p.waitOnStop)); }
    else { p.waitOnStop=nullptr; }
    if (j.HasMember("pedBicycleDetect")) { p.pedBicycleDetect = vanetza::asn1::allocate<PedestrianBicycleDetect_t>(); from_json(j["pedBicycleDetect"], *(p.pedBicycleDetect)); }
    else { p.pedBicycleDetect=nullptr; }
    p.regional=nullptr;
}



/*
*   DataParameters - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DataParameters_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.processMethod != 0) json.AddMember("processMethod", to_json(*(p.processMethod), allocator), allocator);
    if (p.processAgency != 0) json.AddMember("processAgency", to_json(*(p.processAgency), allocator), allocator);
    if (p.lastCheckedDate != 0) json.AddMember("lastCheckedDate", to_json(*(p.lastCheckedDate), allocator), allocator);
    if (p.geoidUsed != 0) json.AddMember("geoidUsed", to_json(*(p.geoidUsed), allocator), allocator);
    return json;
}

void from_json(const Value& j, DataParameters_t& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("processMethod")) { p.processMethod = vanetza::asn1::allocate<IA5String_t>(); from_json(j["processMethod"], *(p.processMethod)); }
    else { p.processMethod=nullptr; }
    if (j.HasMember("processAgency")) { p.processAgency = vanetza::asn1::allocate<IA5String_t>(); from_json(j["processAgency"], *(p.processAgency)); }
    else { p.processAgency=nullptr; }
    if (j.HasMember("lastCheckedDate")) { p.lastCheckedDate = vanetza::asn1::allocate<IA5String_t>(); from_json(j["lastCheckedDate"], *(p.lastCheckedDate)); }
    else { p.lastCheckedDate=nullptr; }
    if (j.HasMember("geoidUsed")) { p.geoidUsed = vanetza::asn1::allocate<IA5String_t>(); from_json(j["geoidUsed"], *(p.geoidUsed)); }
    else { p.geoidUsed=nullptr; }
}



/*
*   DDateTime - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DDateTime& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.year != 0) json.AddMember("year", to_json(*(p.year), allocator), allocator);
    if (p.month != 0) json.AddMember("month", to_json(*(p.month), allocator), allocator);
    if (p.day != 0) json.AddMember("day", to_json(*(p.day), allocator), allocator);
    if (p.hour != 0) json.AddMember("hour", to_json(*(p.hour), allocator), allocator);
    if (p.minute != 0) json.AddMember("minute", to_json(*(p.minute), allocator), allocator);
    if (p.second != 0) json.AddMember("second", to_json(*(p.second), allocator), allocator);
    if (p.offset != 0) json.AddMember("offset", to_json(*(p.offset), allocator), allocator);
    return json;
}

void from_json(const Value& j, DDateTime& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("year")) { p.year = vanetza::asn1::allocate<DYear_t>(); from_json(j["year"], *(p.year)); }
    else { p.year=nullptr; }
    if (j.HasMember("month")) { p.month = vanetza::asn1::allocate<DMonth_t>(); from_json(j["month"], *(p.month)); }
    else { p.month=nullptr; }
    if (j.HasMember("day")) { p.day = vanetza::asn1::allocate<DDay_t>(); from_json(j["day"], *(p.day)); }
    else { p.day=nullptr; }
    if (j.HasMember("hour")) { p.hour = vanetza::asn1::allocate<DHour_t>(); from_json(j["hour"], *(p.hour)); }
    else { p.hour=nullptr; }
    if (j.HasMember("minute")) { p.minute = vanetza::asn1::allocate<DMinute_t>(); from_json(j["minute"], *(p.minute)); }
    else { p.minute=nullptr; }
    if (j.HasMember("second")) { p.second = vanetza::asn1::allocate<DSecond_t>(); from_json(j["second"], *(p.second)); }
    else { p.second=nullptr; }
    if (j.HasMember("offset")) { p.offset = vanetza::asn1::allocate<DOffset_t>(); from_json(j["offset"], *(p.offset)); }
    else { p.offset=nullptr; }
}



/*
*   EnabledLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const EnabledLaneList_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LaneID_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, EnabledLaneList_t& p) {
    EnabledLaneList_t* p_tmp = vanetza::asn1::allocate<EnabledLaneList_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LaneID_t *element = vanetza::asn1::allocate<LaneID_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   IntersectionAccessPoint - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionAccessPoint_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == IntersectionAccessPoint_PR_lane) {
        json.AddMember("lane", to_json(p.choice.lane, allocator), allocator);
    } else if (p.present == IntersectionAccessPoint_PR_approach) {
        json.AddMember("approach", to_json(p.choice.approach, allocator), allocator);
    } else if (p.present == IntersectionAccessPoint_PR_connection) {
        json.AddMember("connection", to_json(p.choice.connection, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, IntersectionAccessPoint_t& p) {
    if (j.HasMember("lane")) {
        p.present = IntersectionAccessPoint_PR_lane;
        from_json(j["lane"], p.choice.lane);
    } else if (j.HasMember("approach")) {
        p.present = IntersectionAccessPoint_PR_approach;
        from_json(j["approach"], p.choice.approach);
    } else if (j.HasMember("connection")) {
        p.present = IntersectionAccessPoint_PR_connection;
        from_json(j["connection"], p.choice.connection);
    } else {
        p.present = IntersectionAccessPoint_PR_NOTHING;
    }
}

/*
*   IntersectionReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionReferenceID& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    if (p.region != 0) json.AddMember("region", to_json(*(p.region), allocator), allocator);
    return json;
}

void from_json(const Value& j, IntersectionReferenceID& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("region")) { p.region = vanetza::asn1::allocate<RoadRegulatorID_t>(); from_json(j["region"], *(p.region)); }
    else { p.region=nullptr; }
    from_json(j["id"], (p.id));
}



/*
*   LaneSharing - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneSharing(const LaneSharing_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("overlappingLaneDescriptionProvided", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("multipleLanesTreatedAsOneLane", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("otherNonMotorizedTrafficTypes", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("individualMotorizedVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("busVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("taxiVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("pedestriansTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("cyclistVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("trackedVehicleTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    json.AddMember("pedestrianTraffic", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8)))), allocator);
    return json;
}

void from_json_LaneSharing(const Value& j, LaneSharing_t& p) {
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
    if (j.HasMember("overlappingLaneDescriptionProvided")) from_json(j["overlappingLaneDescriptionProvided"], (overlappingLaneDescriptionProvided));
    if (j.HasMember("multipleLanesTreatedAsOneLane")) from_json(j["multipleLanesTreatedAsOneLane"], (multipleLanesTreatedAsOneLane));
    if (j.HasMember("otherNonMotorizedTrafficTypes")) from_json(j["otherNonMotorizedTrafficTypes"], (otherNonMotorizedTrafficTypes));
    if (j.HasMember("individualMotorizedVehicleTraffic")) from_json(j["individualMotorizedVehicleTraffic"], (individualMotorizedVehicleTraffic));
    if (j.HasMember("busVehicleTraffic")) from_json(j["busVehicleTraffic"], (busVehicleTraffic));
    if (j.HasMember("taxiVehicleTraffic")) from_json(j["taxiVehicleTraffic"], (taxiVehicleTraffic));
    if (j.HasMember("pedestriansTraffic")) from_json(j["pedestriansTraffic"], (pedestriansTraffic));
    if (j.HasMember("cyclistVehicleTraffic")) from_json(j["cyclistVehicleTraffic"], (cyclistVehicleTraffic));
    if (j.HasMember("trackedVehicleTraffic")) from_json(j["trackedVehicleTraffic"], (trackedVehicleTraffic));
    if (j.HasMember("pedestrianTraffic")) from_json(j["pedestrianTraffic"], (pedestrianTraffic));
    p_tmp->size = (10 / 8) + 1;
    p_tmp->bits_unused = (10 % 8) != 0 ? 8 - (10 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (overlappingLaneDescriptionProvided) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (multipleLanesTreatedAsOneLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (otherNonMotorizedTrafficTypes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (individualMotorizedVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (busVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (taxiVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (pedestriansTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (cyclistVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (trackedVehicleTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (pedestrianTraffic) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ManeuverAssistList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ManeuverAssistList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ConnectionManeuverAssist_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ManeuverAssistList& p) {
    ManeuverAssistList* p_tmp = vanetza::asn1::allocate<ManeuverAssistList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ConnectionManeuverAssist_t *element = vanetza::asn1::allocate<ConnectionManeuverAssist_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeAttributeXYList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const NodeAttributeXY_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, NodeAttributeXYList& p) {
    NodeAttributeXYList* p_tmp = vanetza::asn1::allocate<NodeAttributeXYList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        NodeAttributeXY_t *element = vanetza::asn1::allocate<NodeAttributeXY_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_LLmD_64b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lon", to_json(((p.lon) == 1800000001) ? (p.lon) : (double)(p.lon) / 10000000.0, allocator), allocator);
    json.AddMember("lat", to_json(((p.lat) == 900000001) ? (p.lat) : (double)(p.lat) / 10000000.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_LLmD_64b& p) {
    p._asn_ctx.ptr = nullptr;
    double lon; from_json(j["lon"], (lon)); (p.lon) = ((lon) != 1800000001) ? lon * 10000000 : lon;
    double lat; from_json(j["lat"], (lat)); (p.lat) = ((lat) != 900000001) ? lat * 10000000 : lat;
}



/*
*   Node-XY-20b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_20b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_20b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_22b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_22b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_24b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_24b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_26b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_26b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_28b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_28b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_32b& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Node_XY_32b& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
}



/*
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeOffsetPointXY& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == NodeOffsetPointXY_PR_node_XY1) {
        json.AddMember("node-XY1", to_json(p.choice.node_XY1, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_XY2) {
        json.AddMember("node-XY2", to_json(p.choice.node_XY2, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_XY3) {
        json.AddMember("node-XY3", to_json(p.choice.node_XY3, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_XY4) {
        json.AddMember("node-XY4", to_json(p.choice.node_XY4, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_XY5) {
        json.AddMember("node-XY5", to_json(p.choice.node_XY5, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_XY6) {
        json.AddMember("node-XY6", to_json(p.choice.node_XY6, allocator), allocator);
    } else if (p.present == NodeOffsetPointXY_PR_node_LatLon) {
        json.AddMember("node-LatLon", to_json(p.choice.node_LatLon, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, NodeOffsetPointXY& p) {
    if (j.HasMember("node-XY1")) {
        p.present = NodeOffsetPointXY_PR_node_XY1;
        from_json(j["node-XY1"], p.choice.node_XY1);
    } else if (j.HasMember("node-XY2")) {
        p.present = NodeOffsetPointXY_PR_node_XY2;
        from_json(j["node-XY2"], p.choice.node_XY2);
    } else if (j.HasMember("node-XY3")) {
        p.present = NodeOffsetPointXY_PR_node_XY3;
        from_json(j["node-XY3"], p.choice.node_XY3);
    } else if (j.HasMember("node-XY4")) {
        p.present = NodeOffsetPointXY_PR_node_XY4;
        from_json(j["node-XY4"], p.choice.node_XY4);
    } else if (j.HasMember("node-XY5")) {
        p.present = NodeOffsetPointXY_PR_node_XY5;
        from_json(j["node-XY5"], p.choice.node_XY5);
    } else if (j.HasMember("node-XY6")) {
        p.present = NodeOffsetPointXY_PR_node_XY6;
        from_json(j["node-XY6"], p.choice.node_XY6);
    } else if (j.HasMember("node-LatLon")) {
        p.present = NodeOffsetPointXY_PR_node_LatLon;
        from_json(j["node-LatLon"], p.choice.node_LatLon);
    } else {
        p.present = NodeOffsetPointXY_PR_NOTHING;
    }
}

/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const OverlayLaneList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LaneID_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, OverlayLaneList& p) {
    OverlayLaneList* p_tmp = vanetza::asn1::allocate<OverlayLaneList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LaneID_t *element = vanetza::asn1::allocate<LaneID_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PositionalAccuracy - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionalAccuracy& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("semiMajor", to_json((p.semiMajor), allocator), allocator);
    json.AddMember("semiMinor", to_json((p.semiMinor), allocator), allocator);
    json.AddMember("orientation", to_json((p.orientation), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PositionalAccuracy& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["semiMajor"], (p.semiMajor));
    from_json(j["semiMinor"], (p.semiMinor));
    from_json(j["orientation"], (p.orientation));
}



/*
*   PositionConfidenceSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionConfidenceSet& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pos", to_json((p.pos), allocator), allocator);
    json.AddMember("elevation", to_json((p.elevation), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PositionConfidenceSet& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["pos"], (p.pos));
    from_json(j["elevation"], (p.elevation));
}



/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Position3D_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lat", to_json(((p.lat) == 900000001) ? (p.lat) : (double)(p.lat) / 10000000.0, allocator), allocator);
    json.AddMember("long", to_json(((p.Long) == 1800000001) ? (p.Long) : (double)(p.Long) / 10000000.0, allocator), allocator);
    if (p.elevation != 0) json.AddMember("elevation", to_json(*(p.elevation), allocator), allocator);
    return json;
}

void from_json(const Value& j, Position3D_t& p) {
    p._asn_ctx.ptr = nullptr;
    double lat; from_json(j["lat"], (lat)); (p.lat) = ((lat) != 900000001) ? lat * 10000000 : lat;
    double Long; from_json(j["long"], (Long)); (p.Long) = ((Long) != 1800000001) ? Long * 10000000 : Long;
    if (j.HasMember("elevation")) { p.elevation = vanetza::asn1::allocate<Elevation_t>(); from_json(j["elevation"], *(p.elevation)); }
    else { p.elevation=nullptr; }
    p.regional=nullptr;
}



/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RegulatorySpeedLimit& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RegulatorySpeedLimit& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    from_json(j["speed"], (p.speed));
}



/*
*   RequestorType - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorType& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("role", to_json((p.role), allocator), allocator);
    if (p.subrole != 0) json.AddMember("subrole", to_json(*(p.subrole), allocator), allocator);
    if (p.request != 0) json.AddMember("request", to_json(*(p.request), allocator), allocator);
    if (p.hpmsType != 0) json.AddMember("hpmsType", to_json(*(p.hpmsType), allocator), allocator);
    return json;
}

void from_json(const Value& j, RequestorType& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["role"], (p.role));
    if (j.HasMember("subrole")) { p.subrole = vanetza::asn1::allocate<RequestSubRole_t>(); from_json(j["subrole"], *(p.subrole)); }
    else { p.subrole=nullptr; }
    if (j.HasMember("request")) { p.request = vanetza::asn1::allocate<RequestImportanceLevel_t>(); from_json(j["request"], *(p.request)); }
    else { p.request=nullptr; }
    if (j.HasMember("hpmsType")) { p.hpmsType = vanetza::asn1::allocate<VehicleType_t>(); from_json(j["hpmsType"], *(p.hpmsType)); }
    else { p.hpmsType=nullptr; }
    p.iso3883=nullptr;
    p.regional=nullptr;
}



/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserType& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == RestrictionUserType_PR_basicType) {
        json.AddMember("basicType", to_json(p.choice.basicType, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, RestrictionUserType& p) {
    if (j.HasMember("basicType")) {
        p.present = RestrictionUserType_PR_basicType;
        from_json(j["basicType"], p.choice.basicType);
    } else {
        p.present = RestrictionUserType_PR_NOTHING;
    }
}

/*
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserTypeList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RestrictionUserType_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RestrictionUserTypeList& p) {
    RestrictionUserTypeList* p_tmp = vanetza::asn1::allocate<RestrictionUserTypeList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RestrictionUserType_t *element = vanetza::asn1::allocate<RestrictionUserType_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentReferenceID& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    if (p.region != 0) json.AddMember("region", to_json(*(p.region), allocator), allocator);
    return json;
}

void from_json(const Value& j, RoadSegmentReferenceID& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("region")) { p.region = vanetza::asn1::allocate<RoadRegulatorID_t>(); from_json(j["region"], *(p.region)); }
    else { p.region=nullptr; }
    from_json(j["id"], (p.id));
}



/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SegmentAttributeXYList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SegmentAttributeXY_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, SegmentAttributeXYList& p) {
    SegmentAttributeXYList* p_tmp = vanetza::asn1::allocate<SegmentAttributeXYList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SegmentAttributeXY_t *element = vanetza::asn1::allocate<SegmentAttributeXY_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalControlZone - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalControlZone& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    
    return json;
}

void from_json(const Value& j, SignalControlZone& p) {
    p._asn_ctx.ptr = nullptr;
    
}



/*
*   SignalRequest - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequest& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("requestID", to_json((p.requestID), allocator), allocator);
    json.AddMember("requestType", to_json((p.requestType), allocator), allocator);
    json.AddMember("inBoundLane", to_json((p.inBoundLane), allocator), allocator);
    if (p.outBoundLane != 0) json.AddMember("outBoundLane", to_json(*(p.outBoundLane), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalRequest& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["requestID"], (p.requestID));
    from_json(j["requestType"], (p.requestType));
    from_json(j["inBoundLane"], (p.inBoundLane));
    if (j.HasMember("outBoundLane")) { p.outBoundLane = vanetza::asn1::allocate<IntersectionAccessPoint_t>(); from_json(j["outBoundLane"], *(p.outBoundLane)); }
    else { p.outBoundLane=nullptr; }
    p.regional=nullptr;
}



/*
*   SignalRequestPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestPackage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("request", to_json((p.request), allocator), allocator);
    if (p.minute != 0) json.AddMember("minute", to_json(*(p.minute), allocator), allocator);
    if (p.second != 0) json.AddMember("second", to_json(*(p.second), allocator), allocator);
    if (p.duration != 0) json.AddMember("duration", to_json(*(p.duration), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalRequestPackage& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["request"], (p.request));
    if (j.HasMember("minute")) { p.minute = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["minute"], *(p.minute)); }
    else { p.minute=nullptr; }
    if (j.HasMember("second")) { p.second = vanetza::asn1::allocate<DSecond_t>(); from_json(j["second"], *(p.second)); }
    else { p.second=nullptr; }
    if (j.HasMember("duration")) { p.duration = vanetza::asn1::allocate<DSecond_t>(); from_json(j["duration"], *(p.duration)); }
    else { p.duration=nullptr; }
    p.regional=nullptr;
}



/*
*   SpeedandHeadingIsoandThrottleConfidence - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedandHeadingIsoandThrottleConfidence& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heading", to_json((p.heading), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    json.AddMember("throttle", to_json((p.throttle), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SpeedandHeadingIsoandThrottleConfidence& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["heading"], (p.heading));
    from_json(j["speed"], (p.speed));
    from_json(j["throttle"], (p.throttle));
}



/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedLimitList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RegulatorySpeedLimit_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SpeedLimitList& p) {
    SpeedLimitList* p_tmp = vanetza::asn1::allocate<SpeedLimitList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RegulatorySpeedLimit_t *element = vanetza::asn1::allocate<RegulatorySpeedLimit_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TimeChangeDetails - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TimeChangeDetails& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("minEndTime", to_json((p.minEndTime), allocator), allocator);
    if (p.startTime != 0) json.AddMember("startTime", to_json(*(p.startTime), allocator), allocator);
    if (p.maxEndTime != 0) json.AddMember("maxEndTime", to_json(*(p.maxEndTime), allocator), allocator);
    if (p.likelyTime != 0) json.AddMember("likelyTime", to_json(*(p.likelyTime), allocator), allocator);
    if (p.confidence != 0) json.AddMember("confidence", to_json(*(p.confidence), allocator), allocator);
    if (p.nextTime != 0) json.AddMember("nextTime", to_json(*(p.nextTime), allocator), allocator);
    return json;
}

void from_json(const Value& j, TimeChangeDetails& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("startTime")) { p.startTime = vanetza::asn1::allocate<TimeMark_t>(); from_json(j["startTime"], *(p.startTime)); }
    else { p.startTime=nullptr; }
    from_json(j["minEndTime"], (p.minEndTime));
    if (j.HasMember("maxEndTime")) { p.maxEndTime = vanetza::asn1::allocate<TimeMark_t>(); from_json(j["maxEndTime"], *(p.maxEndTime)); }
    else { p.maxEndTime=nullptr; }
    if (j.HasMember("likelyTime")) { p.likelyTime = vanetza::asn1::allocate<TimeMark_t>(); from_json(j["likelyTime"], *(p.likelyTime)); }
    else { p.likelyTime=nullptr; }
    if (j.HasMember("confidence")) { p.confidence = vanetza::asn1::allocate<TimeIntervalConfidence_t>(); from_json(j["confidence"], *(p.confidence)); }
    else { p.confidence=nullptr; }
    if (j.HasMember("nextTime")) { p.nextTime = vanetza::asn1::allocate<TimeMark_t>(); from_json(j["nextTime"], *(p.nextTime)); }
    else { p.nextTime=nullptr; }
}



/*
*   TransmissionAndSpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TransmissionAndSpeed_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("transmisson", to_json((p.transmisson), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, TransmissionAndSpeed_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["transmisson"], (p.transmisson));
    from_json(j["speed"], (p.speed));
}



/*
*   VehicleID - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const VehicleID_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VehicleID_PR_stationID) {
        json.AddMember("stationID", to_json(p.choice.stationID, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleID_t& p) {
    if (j.HasMember("stationID")) {
        p.present = VehicleID_PR_stationID;
        from_json(j["stationID"], p.choice.stationID);
    } else {
        p.present = VehicleID_PR_NOTHING;
    }
}

/*
*   AllowedManeuvers - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_AllowedManeuvers(const AllowedManeuvers_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("maneuverStraightAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("maneuverLeftAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("maneuverRightAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("maneuverUTurnAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("maneuverLeftTurnOnRedAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("maneuverRightTurnOnRedAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("maneuverLaneChangeAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("maneuverNoStoppingAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("yieldAllwaysRequired", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    json.AddMember("goWithHalt", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8)))), allocator);
    json.AddMember("caution", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8)))), allocator);
    json.AddMember("reserved1", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8)))), allocator);
    return json;
}

void from_json_AllowedManeuvers(const Value& j, AllowedManeuvers_t& p) {
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
    if (j.HasMember("maneuverStraightAllowed")) from_json(j["maneuverStraightAllowed"], (maneuverStraightAllowed));
    if (j.HasMember("maneuverLeftAllowed")) from_json(j["maneuverLeftAllowed"], (maneuverLeftAllowed));
    if (j.HasMember("maneuverRightAllowed")) from_json(j["maneuverRightAllowed"], (maneuverRightAllowed));
    if (j.HasMember("maneuverUTurnAllowed")) from_json(j["maneuverUTurnAllowed"], (maneuverUTurnAllowed));
    if (j.HasMember("maneuverLeftTurnOnRedAllowed")) from_json(j["maneuverLeftTurnOnRedAllowed"], (maneuverLeftTurnOnRedAllowed));
    if (j.HasMember("maneuverRightTurnOnRedAllowed")) from_json(j["maneuverRightTurnOnRedAllowed"], (maneuverRightTurnOnRedAllowed));
    if (j.HasMember("maneuverLaneChangeAllowed")) from_json(j["maneuverLaneChangeAllowed"], (maneuverLaneChangeAllowed));
    if (j.HasMember("maneuverNoStoppingAllowed")) from_json(j["maneuverNoStoppingAllowed"], (maneuverNoStoppingAllowed));
    if (j.HasMember("yieldAllwaysRequired")) from_json(j["yieldAllwaysRequired"], (yieldAllwaysRequired));
    if (j.HasMember("goWithHalt")) from_json(j["goWithHalt"], (goWithHalt));
    if (j.HasMember("caution")) from_json(j["caution"], (caution));
    if (j.HasMember("reserved1")) from_json(j["reserved1"], (reserved1));
    p_tmp->size = (12 / 8) + 1;
    p_tmp->bits_unused = (12 % 8) != 0 ? 8 - (12 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (maneuverStraightAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (maneuverLeftAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (maneuverRightAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (maneuverUTurnAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (maneuverLeftTurnOnRedAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (maneuverRightTurnOnRedAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (maneuverLaneChangeAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (maneuverNoStoppingAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (yieldAllwaysRequired) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (goWithHalt) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    if (caution) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    if (reserved1) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   GNSSstatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_GNSSstatus(const GNSSstatus_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unavailable", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("isHealthy", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("isMonitored", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("baseStationType", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("aPDOPofUnder5", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("inViewOfUnder5", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("localCorrectionsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("networkCorrectionsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_GNSSstatus(const Value& j, GNSSstatus_t& p) {
    GNSSstatus_t* p_tmp = vanetza::asn1::allocate<GNSSstatus_t>();
    bool unavailable;
    bool isHealthy;
    bool isMonitored;
    bool baseStationType;
    bool aPDOPofUnder5;
    bool inViewOfUnder5;
    bool localCorrectionsPresent;
    bool networkCorrectionsPresent;
    if (j.HasMember("unavailable")) from_json(j["unavailable"], (unavailable));
    if (j.HasMember("isHealthy")) from_json(j["isHealthy"], (isHealthy));
    if (j.HasMember("isMonitored")) from_json(j["isMonitored"], (isMonitored));
    if (j.HasMember("baseStationType")) from_json(j["baseStationType"], (baseStationType));
    if (j.HasMember("aPDOPofUnder5")) from_json(j["aPDOPofUnder5"], (aPDOPofUnder5));
    if (j.HasMember("inViewOfUnder5")) from_json(j["inViewOfUnder5"], (inViewOfUnder5));
    if (j.HasMember("localCorrectionsPresent")) from_json(j["localCorrectionsPresent"], (localCorrectionsPresent));
    if (j.HasMember("networkCorrectionsPresent")) from_json(j["networkCorrectionsPresent"], (networkCorrectionsPresent));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (unavailable) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (isHealthy) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (isMonitored) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (baseStationType) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (aPDOPofUnder5) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (inViewOfUnder5) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (localCorrectionsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (networkCorrectionsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   IntersectionStatusObject - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_IntersectionStatusObject(const IntersectionStatusObject_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("manualControlIsEnabled", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("stopTimeIsActivated", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("failureFlash", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("preemptIsActive", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("signalPriorityIsActive", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("fixedTimeOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("trafficDependentOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("standbyOperation", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("failureMode", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    json.AddMember("off", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8)))), allocator);
    json.AddMember("recentMAPmessageUpdate", (bool) (*(p.buf + (sizeof(uint8_t) * (10 / 8))) & (1 << ((7 * ((10 / 8) + 1))-(10 % 8)))), allocator);
    json.AddMember("recentChangeInMAPassignedLanesIDsUsed", (bool) (*(p.buf + (sizeof(uint8_t) * (11 / 8))) & (1 << ((7 * ((11 / 8) + 1))-(11 % 8)))), allocator);
    json.AddMember("noValidMAPisAvailableAtThisTime", (bool) (*(p.buf + (sizeof(uint8_t) * (12 / 8))) & (1 << ((7 * ((12 / 8) + 1))-(12 % 8)))), allocator);
    json.AddMember("noValidSPATisAvailableAtThisTime", (bool) (*(p.buf + (sizeof(uint8_t) * (13 / 8))) & (1 << ((7 * ((13 / 8) + 1))-(13 % 8)))), allocator);
    return json;
}

void from_json_IntersectionStatusObject(const Value& j, IntersectionStatusObject_t& p) {
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
    if (j.HasMember("manualControlIsEnabled")) from_json(j["manualControlIsEnabled"], (manualControlIsEnabled));
    if (j.HasMember("stopTimeIsActivated")) from_json(j["stopTimeIsActivated"], (stopTimeIsActivated));
    if (j.HasMember("failureFlash")) from_json(j["failureFlash"], (failureFlash));
    if (j.HasMember("preemptIsActive")) from_json(j["preemptIsActive"], (preemptIsActive));
    if (j.HasMember("signalPriorityIsActive")) from_json(j["signalPriorityIsActive"], (signalPriorityIsActive));
    if (j.HasMember("fixedTimeOperation")) from_json(j["fixedTimeOperation"], (fixedTimeOperation));
    if (j.HasMember("trafficDependentOperation")) from_json(j["trafficDependentOperation"], (trafficDependentOperation));
    if (j.HasMember("standbyOperation")) from_json(j["standbyOperation"], (standbyOperation));
    if (j.HasMember("failureMode")) from_json(j["failureMode"], (failureMode));
    if (j.HasMember("off")) from_json(j["off"], (off));
    if (j.HasMember("recentMAPmessageUpdate")) from_json(j["recentMAPmessageUpdate"], (recentMAPmessageUpdate));
    if (j.HasMember("recentChangeInMAPassignedLanesIDsUsed")) from_json(j["recentChangeInMAPassignedLanesIDsUsed"], (recentChangeInMAPassignedLanesIDsUsed));
    if (j.HasMember("noValidMAPisAvailableAtThisTime")) from_json(j["noValidMAPisAvailableAtThisTime"], (noValidMAPisAvailableAtThisTime));
    if (j.HasMember("noValidSPATisAvailableAtThisTime")) from_json(j["noValidSPATisAvailableAtThisTime"], (noValidSPATisAvailableAtThisTime));
    p_tmp->size = (14 / 8) + 1;
    p_tmp->bits_unused = (14 % 8) != 0 ? 8 - (14 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (manualControlIsEnabled) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (stopTimeIsActivated) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (failureFlash) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (preemptIsActive) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (signalPriorityIsActive) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (fixedTimeOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (trafficDependentOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (standbyOperation) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (failureMode) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (off) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    if (recentMAPmessageUpdate) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 5);
    if (recentChangeInMAPassignedLanesIDsUsed) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 4);
    if (noValidMAPisAvailableAtThisTime) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 3);
    if (noValidSPATisAvailableAtThisTime) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 2);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Barrier - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Barrier(const LaneAttributes_Barrier_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("median-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("median", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("whiteLineHashing", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("stripedLines", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("doubleStripedLines", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("trafficCones", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("constructionBarrier", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("trafficChannels", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("lowCurbs", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    json.AddMember("highCurbs", (bool) (*(p.buf + (sizeof(uint8_t) * (9 / 8))) & (1 << ((7 * ((9 / 8) + 1))-(9 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Barrier(const Value& j, LaneAttributes_Barrier_t& p) {
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
    if (j.HasMember("median-RevocableLane")) from_json(j["median-RevocableLane"], (median_RevocableLane));
    if (j.HasMember("median")) from_json(j["median"], (median));
    if (j.HasMember("whiteLineHashing")) from_json(j["whiteLineHashing"], (whiteLineHashing));
    if (j.HasMember("stripedLines")) from_json(j["stripedLines"], (stripedLines));
    if (j.HasMember("doubleStripedLines")) from_json(j["doubleStripedLines"], (doubleStripedLines));
    if (j.HasMember("trafficCones")) from_json(j["trafficCones"], (trafficCones));
    if (j.HasMember("constructionBarrier")) from_json(j["constructionBarrier"], (constructionBarrier));
    if (j.HasMember("trafficChannels")) from_json(j["trafficChannels"], (trafficChannels));
    if (j.HasMember("lowCurbs")) from_json(j["lowCurbs"], (lowCurbs));
    if (j.HasMember("highCurbs")) from_json(j["highCurbs"], (highCurbs));
    p_tmp->size = (10 / 8) + 1;
    p_tmp->bits_unused = (10 % 8) != 0 ? 8 - (10 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (median_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (median) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (whiteLineHashing) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (stripedLines) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (doubleStripedLines) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (trafficCones) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (constructionBarrier) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (trafficChannels) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (lowCurbs) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    if (highCurbs) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 6);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Bike - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Bike(const LaneAttributes_Bike_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("bikeRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("pedestrianUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("isBikeFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("fixedCycleTime", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("biDirectionalCycleTimes", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("isolatedByBarrier", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("unsignalizedSegmentsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Bike(const Value& j, LaneAttributes_Bike_t& p) {
    LaneAttributes_Bike_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Bike_t>();
    bool bikeRevocableLane;
    bool pedestrianUseAllowed;
    bool isBikeFlyOverLane;
    bool fixedCycleTime;
    bool biDirectionalCycleTimes;
    bool isolatedByBarrier;
    bool unsignalizedSegmentsPresent;
    if (j.HasMember("bikeRevocableLane")) from_json(j["bikeRevocableLane"], (bikeRevocableLane));
    if (j.HasMember("pedestrianUseAllowed")) from_json(j["pedestrianUseAllowed"], (pedestrianUseAllowed));
    if (j.HasMember("isBikeFlyOverLane")) from_json(j["isBikeFlyOverLane"], (isBikeFlyOverLane));
    if (j.HasMember("fixedCycleTime")) from_json(j["fixedCycleTime"], (fixedCycleTime));
    if (j.HasMember("biDirectionalCycleTimes")) from_json(j["biDirectionalCycleTimes"], (biDirectionalCycleTimes));
    if (j.HasMember("isolatedByBarrier")) from_json(j["isolatedByBarrier"], (isolatedByBarrier));
    if (j.HasMember("unsignalizedSegmentsPresent")) from_json(j["unsignalizedSegmentsPresent"], (unsignalizedSegmentsPresent));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = (7 % 8) != 0 ? 8 - (7 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (bikeRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (pedestrianUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (isBikeFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (fixedCycleTime) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (biDirectionalCycleTimes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (isolatedByBarrier) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (unsignalizedSegmentsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Crosswalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Crosswalk(const LaneAttributes_Crosswalk_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("crosswalkRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("bicyleUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("isXwalkFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("fixedCycleTime", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("biDirectionalCycleTimes", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("hasPushToWalkButton", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("audioSupport", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("rfSignalRequestPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    json.AddMember("unsignalizedSegmentsPresent", (bool) (*(p.buf + (sizeof(uint8_t) * (8 / 8))) & (1 << ((7 * ((8 / 8) + 1))-(8 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Crosswalk(const Value& j, LaneAttributes_Crosswalk_t& p) {
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
    if (j.HasMember("crosswalkRevocableLane")) from_json(j["crosswalkRevocableLane"], (crosswalkRevocableLane));
    if (j.HasMember("bicyleUseAllowed")) from_json(j["bicyleUseAllowed"], (bicyleUseAllowed));
    if (j.HasMember("isXwalkFlyOverLane")) from_json(j["isXwalkFlyOverLane"], (isXwalkFlyOverLane));
    if (j.HasMember("fixedCycleTime")) from_json(j["fixedCycleTime"], (fixedCycleTime));
    if (j.HasMember("biDirectionalCycleTimes")) from_json(j["biDirectionalCycleTimes"], (biDirectionalCycleTimes));
    if (j.HasMember("hasPushToWalkButton")) from_json(j["hasPushToWalkButton"], (hasPushToWalkButton));
    if (j.HasMember("audioSupport")) from_json(j["audioSupport"], (audioSupport));
    if (j.HasMember("rfSignalRequestPresent")) from_json(j["rfSignalRequestPresent"], (rfSignalRequestPresent));
    if (j.HasMember("unsignalizedSegmentsPresent")) from_json(j["unsignalizedSegmentsPresent"], (unsignalizedSegmentsPresent));
    p_tmp->size = (9 / 8) + 1;
    p_tmp->bits_unused = (9 % 8) != 0 ? 8 - (9 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (crosswalkRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (bicyleUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (isXwalkFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (fixedCycleTime) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (biDirectionalCycleTimes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (hasPushToWalkButton) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (audioSupport) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (rfSignalRequestPresent) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    if (unsignalizedSegmentsPresent) *(p_tmp->buf + (sizeof(uint8_t) * 1)) |= (1 << 7);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Parking - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Parking(const LaneAttributes_Parking_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("parkingRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("parallelParkingInUse", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("headInParkingInUse", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("doNotParkZone", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("parkingForBusUse", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("parkingForTaxiUse", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("noPublicParkingUse", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Parking(const Value& j, LaneAttributes_Parking_t& p) {
    LaneAttributes_Parking_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Parking_t>();
    bool parkingRevocableLane;
    bool parallelParkingInUse;
    bool headInParkingInUse;
    bool doNotParkZone;
    bool parkingForBusUse;
    bool parkingForTaxiUse;
    bool noPublicParkingUse;
    if (j.HasMember("parkingRevocableLane")) from_json(j["parkingRevocableLane"], (parkingRevocableLane));
    if (j.HasMember("parallelParkingInUse")) from_json(j["parallelParkingInUse"], (parallelParkingInUse));
    if (j.HasMember("headInParkingInUse")) from_json(j["headInParkingInUse"], (headInParkingInUse));
    if (j.HasMember("doNotParkZone")) from_json(j["doNotParkZone"], (doNotParkZone));
    if (j.HasMember("parkingForBusUse")) from_json(j["parkingForBusUse"], (parkingForBusUse));
    if (j.HasMember("parkingForTaxiUse")) from_json(j["parkingForTaxiUse"], (parkingForTaxiUse));
    if (j.HasMember("noPublicParkingUse")) from_json(j["noPublicParkingUse"], (noPublicParkingUse));
    p_tmp->size = (7 / 8) + 1;
    p_tmp->bits_unused = (7 % 8) != 0 ? 8 - (7 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (parkingRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (parallelParkingInUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (headInParkingInUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (doNotParkZone) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (parkingForBusUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (parkingForTaxiUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (noPublicParkingUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Sidewalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Sidewalk(const LaneAttributes_Sidewalk_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sidewalk-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("bicyleUseAllowed", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("isSidewalkFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("walkBikes", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Sidewalk(const Value& j, LaneAttributes_Sidewalk_t& p) {
    LaneAttributes_Sidewalk_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Sidewalk_t>();
    bool sidewalk_RevocableLane;
    bool bicyleUseAllowed;
    bool isSidewalkFlyOverLane;
    bool walkBikes;
    if (j.HasMember("sidewalk-RevocableLane")) from_json(j["sidewalk-RevocableLane"], (sidewalk_RevocableLane));
    if (j.HasMember("bicyleUseAllowed")) from_json(j["bicyleUseAllowed"], (bicyleUseAllowed));
    if (j.HasMember("isSidewalkFlyOverLane")) from_json(j["isSidewalkFlyOverLane"], (isSidewalkFlyOverLane));
    if (j.HasMember("walkBikes")) from_json(j["walkBikes"], (walkBikes));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = (4 % 8) != 0 ? 8 - (4 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (sidewalk_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (bicyleUseAllowed) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (isSidewalkFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (walkBikes) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Striping - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Striping(const LaneAttributes_Striping_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stripeToConnectingLanesRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("stripeDrawOnLeft", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("stripeDrawOnRight", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("stripeToConnectingLanesLeft", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("stripeToConnectingLanesRight", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("stripeToConnectingLanesAhead", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Striping(const Value& j, LaneAttributes_Striping_t& p) {
    LaneAttributes_Striping_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Striping_t>();
    bool stripeToConnectingLanesRevocableLane;
    bool stripeDrawOnLeft;
    bool stripeDrawOnRight;
    bool stripeToConnectingLanesLeft;
    bool stripeToConnectingLanesRight;
    bool stripeToConnectingLanesAhead;
    if (j.HasMember("stripeToConnectingLanesRevocableLane")) from_json(j["stripeToConnectingLanesRevocableLane"], (stripeToConnectingLanesRevocableLane));
    if (j.HasMember("stripeDrawOnLeft")) from_json(j["stripeDrawOnLeft"], (stripeDrawOnLeft));
    if (j.HasMember("stripeDrawOnRight")) from_json(j["stripeDrawOnRight"], (stripeDrawOnRight));
    if (j.HasMember("stripeToConnectingLanesLeft")) from_json(j["stripeToConnectingLanesLeft"], (stripeToConnectingLanesLeft));
    if (j.HasMember("stripeToConnectingLanesRight")) from_json(j["stripeToConnectingLanesRight"], (stripeToConnectingLanesRight));
    if (j.HasMember("stripeToConnectingLanesAhead")) from_json(j["stripeToConnectingLanesAhead"], (stripeToConnectingLanesAhead));
    p_tmp->size = (6 / 8) + 1;
    p_tmp->bits_unused = (6 % 8) != 0 ? 8 - (6 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (stripeToConnectingLanesRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (stripeDrawOnLeft) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (stripeDrawOnRight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (stripeToConnectingLanesLeft) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (stripeToConnectingLanesRight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (stripeToConnectingLanesAhead) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-TrackedVehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_TrackedVehicle(const LaneAttributes_TrackedVehicle_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("spec-RevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("spec-commuterRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("spec-lightRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("spec-heavyRailRoadTrack", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("spec-otherRailType", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_TrackedVehicle(const Value& j, LaneAttributes_TrackedVehicle_t& p) {
    LaneAttributes_TrackedVehicle_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_TrackedVehicle_t>();
    bool spec_RevocableLane;
    bool spec_commuterRailRoadTrack;
    bool spec_lightRailRoadTrack;
    bool spec_heavyRailRoadTrack;
    bool spec_otherRailType;
    if (j.HasMember("spec-RevocableLane")) from_json(j["spec-RevocableLane"], (spec_RevocableLane));
    if (j.HasMember("spec-commuterRailRoadTrack")) from_json(j["spec-commuterRailRoadTrack"], (spec_commuterRailRoadTrack));
    if (j.HasMember("spec-lightRailRoadTrack")) from_json(j["spec-lightRailRoadTrack"], (spec_lightRailRoadTrack));
    if (j.HasMember("spec-heavyRailRoadTrack")) from_json(j["spec-heavyRailRoadTrack"], (spec_heavyRailRoadTrack));
    if (j.HasMember("spec-otherRailType")) from_json(j["spec-otherRailType"], (spec_otherRailType));
    p_tmp->size = (5 / 8) + 1;
    p_tmp->bits_unused = (5 % 8) != 0 ? 8 - (5 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (spec_RevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (spec_commuterRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (spec_lightRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (spec_heavyRailRoadTrack) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (spec_otherRailType) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes-Vehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Vehicle(const LaneAttributes_Vehicle_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("isVehicleRevocableLane", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("isVehicleFlyOverLane", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("hovLaneUseOnly", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("restrictedToBusUse", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("restrictedToTaxiUse", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("restrictedFromPublicUse", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("hasIRbeaconCoverage", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("permissionOnRequest", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_LaneAttributes_Vehicle(const Value& j, LaneAttributes_Vehicle_t& p) {
    LaneAttributes_Vehicle_t* p_tmp = vanetza::asn1::allocate<LaneAttributes_Vehicle_t>();
    bool isVehicleRevocableLane;
    bool isVehicleFlyOverLane;
    bool hovLaneUseOnly;
    bool restrictedToBusUse;
    bool restrictedToTaxiUse;
    bool restrictedFromPublicUse;
    bool hasIRbeaconCoverage;
    bool permissionOnRequest;
    if (j.HasMember("isVehicleRevocableLane")) from_json(j["isVehicleRevocableLane"], (isVehicleRevocableLane));
    if (j.HasMember("isVehicleFlyOverLane")) from_json(j["isVehicleFlyOverLane"], (isVehicleFlyOverLane));
    if (j.HasMember("hovLaneUseOnly")) from_json(j["hovLaneUseOnly"], (hovLaneUseOnly));
    if (j.HasMember("restrictedToBusUse")) from_json(j["restrictedToBusUse"], (restrictedToBusUse));
    if (j.HasMember("restrictedToTaxiUse")) from_json(j["restrictedToTaxiUse"], (restrictedToTaxiUse));
    if (j.HasMember("restrictedFromPublicUse")) from_json(j["restrictedFromPublicUse"], (restrictedFromPublicUse));
    if (j.HasMember("hasIRbeaconCoverage")) from_json(j["hasIRbeaconCoverage"], (hasIRbeaconCoverage));
    if (j.HasMember("permissionOnRequest")) from_json(j["permissionOnRequest"], (permissionOnRequest));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (isVehicleRevocableLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (isVehicleFlyOverLane) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (hovLaneUseOnly) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (restrictedToBusUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (restrictedToTaxiUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (restrictedFromPublicUse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (hasIRbeaconCoverage) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (permissionOnRequest) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneDirection - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneDirection(const LaneDirection_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("ingressPath", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("egressPath", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    return json;
}

void from_json_LaneDirection(const Value& j, LaneDirection_t& p) {
    LaneDirection_t* p_tmp = vanetza::asn1::allocate<LaneDirection_t>();
    bool ingressPath;
    bool egressPath;
    if (j.HasMember("ingressPath")) from_json(j["ingressPath"], (ingressPath));
    if (j.HasMember("egressPath")) from_json(j["egressPath"], (egressPath));
    p_tmp->size = (2 / 8) + 1;
    p_tmp->bits_unused = (2 % 8) != 0 ? 8 - (2 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (ingressPath) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (egressPath) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TransitVehicleStatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_TransitVehicleStatus(const TransitVehicleStatus_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("loading", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("anADAuse", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("aBikeLoad", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("doorOpen", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("charging", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("atStopLine", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    return json;
}

void from_json_TransitVehicleStatus(const Value& j, TransitVehicleStatus_t& p) {
    TransitVehicleStatus_t* p_tmp = vanetza::asn1::allocate<TransitVehicleStatus_t>();
    bool loading;
    bool anADAuse;
    bool aBikeLoad;
    bool doorOpen;
    bool charging;
    bool atStopLine;
    if (j.HasMember("loading")) from_json(j["loading"], (loading));
    if (j.HasMember("anADAuse")) from_json(j["anADAuse"], (anADAuse));
    if (j.HasMember("aBikeLoad")) from_json(j["aBikeLoad"], (aBikeLoad));
    if (j.HasMember("doorOpen")) from_json(j["doorOpen"], (doorOpen));
    if (j.HasMember("charging")) from_json(j["charging"], (charging));
    if (j.HasMember("atStopLine")) from_json(j["atStopLine"], (atStopLine));
    p_tmp->size = (6 / 8) + 1;
    p_tmp->bits_unused = (6 % 8) != 0 ? 8 - (6 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (loading) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (anADAuse) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (aBikeLoad) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (doorOpen) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (charging) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (atStopLine) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CS5 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS5& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vin", to_json((p.vin), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS5& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["vin"], (p.vin));
    
}



/*
*   FreightContainerData - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const FreightContainerData_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("serialNumber", to_json((p.serialNumber), allocator), allocator);
    json.AddMember("checkDigit", to_json((p.checkDigit), allocator), allocator);
    json.AddMember("length", to_json((p.length), allocator), allocator);
    json.AddMember("height", to_json((p.height), allocator), allocator);
    json.AddMember("width", to_json((p.width), allocator), allocator);
    json.AddMember("containerTypeCode", to_json((p.containerTypeCode), allocator), allocator);
    json.AddMember("maximumGrossMass", to_json((p.maximumGrossMass), allocator), allocator);
    json.AddMember("tareMass", to_json((p.tareMass), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, FreightContainerData_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["serialNumber"], (p.serialNumber));
    from_json(j["checkDigit"], (p.checkDigit));
    from_json(j["length"], (p.length));
    from_json(j["height"], (p.height));
    from_json(j["width"], (p.width));
    from_json(j["containerTypeCode"], (p.containerTypeCode));
    from_json(j["maximumGrossMass"], (p.maximumGrossMass));
    from_json(j["tareMass"], (p.tareMass));
    
    
}



/*
*   CountryCode - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_CountryCode(const CountryCode_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    return json;
}

void from_json_CountryCode(const Value& j, CountryCode_t& p) {
    CountryCode_t* p_tmp = vanetza::asn1::allocate<CountryCode_t>();
    
    
    p_tmp->size = (0 / 8) + 1;
    p_tmp->bits_unused = (0 % 8) != 0 ? 8 - (0 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ServiceNumber - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceNumber(const ServiceNumber_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    return json;
}

void from_json_ServiceNumber(const Value& j, ServiceNumber_t& p) {
    ServiceNumber_t* p_tmp = vanetza::asn1::allocate<ServiceNumber_t>();
    
    
    p_tmp->size = (0 / 8) + 1;
    p_tmp->bits_unused = (0 % 8) != 0 ? 8 - (0 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
    p = *p_tmp;
    delete p_tmp;
}

/*
*   GeoGraphicalLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_GeoGraphicalLimit(const GeoGraphicalLimit_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("globalRestriction", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("regionalRestriction", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("nationalRestriction", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("district", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("issuerCoverageRestriction", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("reservedForCEN1", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("reservedForCEN2", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("issuerSpecificRestriction", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_GeoGraphicalLimit(const Value& j, GeoGraphicalLimit_t& p) {
    GeoGraphicalLimit_t* p_tmp = vanetza::asn1::allocate<GeoGraphicalLimit_t>();
    bool globalRestriction;
    bool regionalRestriction;
    bool nationalRestriction;
    bool district;
    bool issuerCoverageRestriction;
    bool reservedForCEN1;
    bool reservedForCEN2;
    bool issuerSpecificRestriction;
    if (j.HasMember("globalRestriction")) from_json(j["globalRestriction"], (globalRestriction));
    if (j.HasMember("regionalRestriction")) from_json(j["regionalRestriction"], (regionalRestriction));
    if (j.HasMember("nationalRestriction")) from_json(j["nationalRestriction"], (nationalRestriction));
    if (j.HasMember("district")) from_json(j["district"], (district));
    if (j.HasMember("issuerCoverageRestriction")) from_json(j["issuerCoverageRestriction"], (issuerCoverageRestriction));
    if (j.HasMember("reservedForCEN1")) from_json(j["reservedForCEN1"], (reservedForCEN1));
    if (j.HasMember("reservedForCEN2")) from_json(j["reservedForCEN2"], (reservedForCEN2));
    if (j.HasMember("issuerSpecificRestriction")) from_json(j["issuerSpecificRestriction"], (issuerSpecificRestriction));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (globalRestriction) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (regionalRestriction) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (nationalRestriction) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (district) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (issuerCoverageRestriction) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (reservedForCEN1) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (reservedForCEN2) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (issuerSpecificRestriction) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ServiceApplicationLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceApplicationLimit(const ServiceApplicationLimit_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("notForPostpayment", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("notForPrepayment", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("notForVehicleaccess", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("notForFleetcontrol", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("issuerSpecificRestriction1", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("issuerSpecificRestriction2", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("issuerSpecificRestriction3", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("issuerSpecificRestriction4", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_ServiceApplicationLimit(const Value& j, ServiceApplicationLimit_t& p) {
    ServiceApplicationLimit_t* p_tmp = vanetza::asn1::allocate<ServiceApplicationLimit_t>();
    bool notForPostpayment;
    bool notForPrepayment;
    bool notForVehicleaccess;
    bool notForFleetcontrol;
    bool issuerSpecificRestriction1;
    bool issuerSpecificRestriction2;
    bool issuerSpecificRestriction3;
    bool issuerSpecificRestriction4;
    if (j.HasMember("notForPostpayment")) from_json(j["notForPostpayment"], (notForPostpayment));
    if (j.HasMember("notForPrepayment")) from_json(j["notForPrepayment"], (notForPrepayment));
    if (j.HasMember("notForVehicleaccess")) from_json(j["notForVehicleaccess"], (notForVehicleaccess));
    if (j.HasMember("notForFleetcontrol")) from_json(j["notForFleetcontrol"], (notForFleetcontrol));
    if (j.HasMember("issuerSpecificRestriction1")) from_json(j["issuerSpecificRestriction1"], (issuerSpecificRestriction1));
    if (j.HasMember("issuerSpecificRestriction2")) from_json(j["issuerSpecificRestriction2"], (issuerSpecificRestriction2));
    if (j.HasMember("issuerSpecificRestriction3")) from_json(j["issuerSpecificRestriction3"], (issuerSpecificRestriction3));
    if (j.HasMember("issuerSpecificRestriction4")) from_json(j["issuerSpecificRestriction4"], (issuerSpecificRestriction4));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (notForPostpayment) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (notForPrepayment) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (notForVehicleaccess) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (notForFleetcontrol) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (issuerSpecificRestriction1) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (issuerSpecificRestriction2) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (issuerSpecificRestriction3) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (issuerSpecificRestriction4) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram) {
        json.AddMember("trafficSignPictogram", to_json(p.choice.trafficSignPictogram, allocator), allocator);
    } else if (p.present == GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram) {
        json.AddMember("publicFacilitiesPictogram", to_json(p.choice.publicFacilitiesPictogram, allocator), allocator);
    } else if (p.present == GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram) {
        json.AddMember("ambientOrRoadConditionPictogram", to_json(p.choice.ambientOrRoadConditionPictogram, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p) {
    if (j.HasMember("trafficSignPictogram")) {
        p.present = GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram;
        from_json(j["trafficSignPictogram"], p.choice.trafficSignPictogram);
    } else if (j.HasMember("publicFacilitiesPictogram")) {
        p.present = GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram;
        from_json(j["publicFacilitiesPictogram"], p.choice.publicFacilitiesPictogram);
    } else if (j.HasMember("ambientOrRoadConditionPictogram")) {
        p.present = GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram;
        from_json(j["ambientOrRoadConditionPictogram"], p.choice.ambientOrRoadConditionPictogram);
    } else {
        p.present = GddStructure__pictogramCode__serviceCategoryCode_PR::GddStructure__pictogramCode__serviceCategoryCode_PR_NOTHING;
    }
}

/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("nature", to_json((p.nature), allocator), allocator);
    json.AddMember("serialNumber", to_json((p.serialNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["nature"], (p.nature));
    from_json(j["serialNumber"], (p.serialNumber));
}



/*
*   GddStructure::GddStructure__pictogramCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("serviceCategoryCode", to_json((p.serviceCategoryCode), allocator), allocator);
    json.AddMember("pictogramCategoryCode", to_json((p.pictogramCategoryCode), allocator), allocator);
    if (p.countryCode != 0) json.AddMember("countryCode", to_json(*(p.countryCode), allocator), allocator);
    return json;
}

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("countryCode")) { p.countryCode = vanetza::asn1::allocate<OCTET_STRING_t>(); from_json(j["countryCode"], *(p.countryCode)); }
    else { p.countryCode=nullptr; }
    from_json(j["serviceCategoryCode"], (p.serviceCategoryCode));
    from_json(j["pictogramCategoryCode"], (p.pictogramCategoryCode));
}



/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__year - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("yearRangeStartYear", to_json((p.yearRangeStartYear), allocator), allocator);
    json.AddMember("yearRangeEndYear", to_json((p.yearRangeEndYear), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["yearRangeStartYear"], (p.yearRangeStartYear));
    from_json(j["yearRangeEndYear"], (p.yearRangeEndYear));
}



/*
*   InternationalSign-speedLimits - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_speedLimits& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unit", to_json((p.unit), allocator), allocator);
    if (p.speedLimitMax != 0) json.AddMember("speedLimitMax", to_json(*(p.speedLimitMax), allocator), allocator);
    if (p.speedLimitMin != 0) json.AddMember("speedLimitMin", to_json(*(p.speedLimitMin), allocator), allocator);
    return json;
}

void from_json(const Value& j, InternationalSign_speedLimits& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("speedLimitMax")) { p.speedLimitMax = vanetza::asn1::allocate<long>(); from_json(j["speedLimitMax"], *(p.speedLimitMax)); }
    else { p.speedLimitMax=nullptr; }
    if (j.HasMember("speedLimitMin")) { p.speedLimitMin = vanetza::asn1::allocate<long>(); from_json(j["speedLimitMin"], *(p.speedLimitMin)); }
    else { p.speedLimitMin=nullptr; }
    from_json(j["unit"], (p.unit));
}



/*
*   DayOfWeek - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_DayOfWeek(const DayOfWeek_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unused", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("monday", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("tuesday", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("wednesday", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("thursday", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("friday", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    json.AddMember("saturday", (bool) (*(p.buf + (sizeof(uint8_t) * (6 / 8))) & (1 << ((7 * ((6 / 8) + 1))-(6 % 8)))), allocator);
    json.AddMember("sunday", (bool) (*(p.buf + (sizeof(uint8_t) * (7 / 8))) & (1 << ((7 * ((7 / 8) + 1))-(7 % 8)))), allocator);
    return json;
}

void from_json_DayOfWeek(const Value& j, DayOfWeek_t& p) {
    DayOfWeek_t* p_tmp = vanetza::asn1::allocate<DayOfWeek_t>();
    bool unused;
    bool monday;
    bool tuesday;
    bool wednesday;
    bool thursday;
    bool friday;
    bool saturday;
    bool sunday;
    if (j.HasMember("unused")) from_json(j["unused"], (unused));
    if (j.HasMember("monday")) from_json(j["monday"], (monday));
    if (j.HasMember("tuesday")) from_json(j["tuesday"], (tuesday));
    if (j.HasMember("wednesday")) from_json(j["wednesday"], (wednesday));
    if (j.HasMember("thursday")) from_json(j["thursday"], (thursday));
    if (j.HasMember("friday")) from_json(j["friday"], (friday));
    if (j.HasMember("saturday")) from_json(j["saturday"], (saturday));
    if (j.HasMember("sunday")) from_json(j["sunday"], (sunday));
    p_tmp->size = (8 / 8) + 1;
    p_tmp->bits_unused = (8 % 8) != 0 ? 8 - (8 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    *(p_tmp->buf + (sizeof(uint8_t) * 1)) = (uint8_t) 0;
    if (unused) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (monday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (tuesday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (wednesday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (thursday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (friday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    if (saturday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 1);
    if (sunday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 0);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DestinationPlace - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlace& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("destType", to_json((p.destType), allocator), allocator);
    if (p.destBlob != 0) json.AddMember("destBlob", to_json(*(p.destBlob), allocator), allocator);
    if (p.placeNameIdentification != 0) json.AddMember("placeNameIdentification", to_json(*(p.placeNameIdentification), allocator), allocator);
    if (p.placeNameText != 0) json.AddMember("placeNameText", to_json(*(p.placeNameText), allocator), allocator);
    return json;
}

void from_json(const Value& j, DestinationPlace& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["destType"], (p.destType));
    if (j.HasMember("destBlob")) { p.destBlob = vanetza::asn1::allocate<OCTET_STRING_t>(); from_json(j["destBlob"], *(p.destBlob)); }
    else { p.destBlob=nullptr; }
    if (j.HasMember("placeNameIdentification")) { p.placeNameIdentification = vanetza::asn1::allocate<long>(); from_json(j["placeNameIdentification"], *(p.placeNameIdentification)); }
    else { p.placeNameIdentification=nullptr; }
    if (j.HasMember("placeNameText")) { p.placeNameText = vanetza::asn1::allocate<UTF8String_t>(); from_json(j["placeNameText"], *(p.placeNameText)); }
    else { p.placeNameText=nullptr; }
}



/*
*   DestinationPlaces - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlaces& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const DestinationPlace_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DestinationPlaces& p) {
    DestinationPlaces* p_tmp = vanetza::asn1::allocate<DestinationPlaces>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        DestinationPlace_t *element = vanetza::asn1::allocate<DestinationPlace_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DestinationRoad - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoad& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("derType", to_json((p.derType), allocator), allocator);
    if (p.roadNumberIdentifier != 0) json.AddMember("roadNumberIdentifier", to_json(*(p.roadNumberIdentifier), allocator), allocator);
    if (p.roadNumberText != 0) json.AddMember("roadNumberText", to_json(*(p.roadNumberText), allocator), allocator);
    return json;
}

void from_json(const Value& j, DestinationRoad& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["derType"], (p.derType));
    if (j.HasMember("roadNumberIdentifier")) { p.roadNumberIdentifier = vanetza::asn1::allocate<long>(); from_json(j["roadNumberIdentifier"], *(p.roadNumberIdentifier)); }
    else { p.roadNumberIdentifier=nullptr; }
    if (j.HasMember("roadNumberText")) { p.roadNumberText = vanetza::asn1::allocate<UTF8String_t>(); from_json(j["roadNumberText"], *(p.roadNumberText)); }
    else { p.roadNumberText=nullptr; }
}



/*
*   DestinationRoads - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoads& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const DestinationRoad_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DestinationRoads& p) {
    DestinationRoads* p_tmp = vanetza::asn1::allocate<DestinationRoads>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        DestinationRoad_t *element = vanetza::asn1::allocate<DestinationRoad_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   Distance - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Distance& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    json.AddMember("unit", to_json((p.unit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Distance& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["value"], (p.value));
    from_json(j["unit"], (p.unit));
}



/*
*   DistanceOrDuration - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DistanceOrDuration& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    json.AddMember("unit", to_json((p.unit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DistanceOrDuration& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["value"], (p.value));
    from_json(j["unit"], (p.unit));
}



/*
*   HoursMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const HoursMinutes& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("hours", to_json((p.hours), allocator), allocator);
    json.AddMember("mins", to_json((p.mins), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, HoursMinutes& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["hours"], (p.hours));
    from_json(j["mins"], (p.mins));
}



/*
*   MonthDay - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const MonthDay& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("month", to_json((p.month), allocator), allocator);
    json.AddMember("day", to_json((p.day), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, MonthDay& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["month"], (p.month));
    from_json(j["day"], (p.day));
}



/*
*   RepeatingPeriodDayTypes - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_RepeatingPeriodDayTypes(const RepeatingPeriodDayTypes_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("national-holiday", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("even-days", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("odd-days", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("market-day", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    return json;
}

void from_json_RepeatingPeriodDayTypes(const Value& j, RepeatingPeriodDayTypes_t& p) {
    RepeatingPeriodDayTypes_t* p_tmp = vanetza::asn1::allocate<RepeatingPeriodDayTypes_t>();
    bool national_holiday;
    bool even_days;
    bool odd_days;
    bool market_day;
    if (j.HasMember("national-holiday")) from_json(j["national-holiday"], (national_holiday));
    if (j.HasMember("even-days")) from_json(j["even-days"], (even_days));
    if (j.HasMember("odd-days")) from_json(j["odd-days"], (odd_days));
    if (j.HasMember("market-day")) from_json(j["market-day"], (market_day));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = (4 % 8) != 0 ? 8 - (4 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (national_holiday) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (even_days) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (odd_days) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (market_day) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   Weight - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Weight& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    json.AddMember("unit", to_json((p.unit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Weight& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["value"], (p.value));
    from_json(j["unit"], (p.unit));
}



/*
*   AxleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AxleWeightLimits_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("maxLadenweightOnAxle1", to_json((p.maxLadenweightOnAxle1), allocator), allocator);
    json.AddMember("maxLadenweightOnAxle2", to_json((p.maxLadenweightOnAxle2), allocator), allocator);
    json.AddMember("maxLadenweightOnAxle3", to_json((p.maxLadenweightOnAxle3), allocator), allocator);
    json.AddMember("maxLadenweightOnAxle4", to_json((p.maxLadenweightOnAxle4), allocator), allocator);
    json.AddMember("maxLadenweightOnAxle5", to_json((p.maxLadenweightOnAxle5), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AxleWeightLimits_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["maxLadenweightOnAxle1"], (p.maxLadenweightOnAxle1));
    from_json(j["maxLadenweightOnAxle2"], (p.maxLadenweightOnAxle2));
    from_json(j["maxLadenweightOnAxle3"], (p.maxLadenweightOnAxle3));
    from_json(j["maxLadenweightOnAxle4"], (p.maxLadenweightOnAxle4));
    from_json(j["maxLadenweightOnAxle5"], (p.maxLadenweightOnAxle5));
}



/*
*   AddRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AddRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("attributeId", to_json((p.attributeId), allocator), allocator);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AddRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["attributeId"], (p.attributeId));
    from_json(j["value"], (p.value));
}



/*
*   ChannelRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("channelId", to_json((p.channelId), allocator), allocator);
    json.AddMember("apdu", to_json((p.apdu), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ChannelRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["channelId"], (p.channelId));
    from_json(j["apdu"], (p.apdu));
}



/*
*   ChannelRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRs_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("channelId", to_json((p.channelId), allocator), allocator);
    json.AddMember("apdu", to_json((p.apdu), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ChannelRs_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["channelId"], (p.channelId));
    from_json(j["apdu"], (p.apdu));
}



/*
*   CopyRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CopyRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("destinationEID", to_json((p.destinationEID), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CopyRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["destinationEID"], (p.destinationEID));
    
}



/*
*   GetInstanceRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const GetInstanceRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("posOfFirstInstance", to_json((p.posOfFirstInstance), allocator), allocator);
    json.AddMember("posOfLastInstance", to_json((p.posOfLastInstance), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, GetInstanceRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["posOfFirstInstance"], (p.posOfFirstInstance));
    from_json(j["posOfLastInstance"], (p.posOfLastInstance));
    
}



/*
*   SubRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SubRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("attributeId", to_json((p.attributeId), allocator), allocator);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SubRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["attributeId"], (p.attributeId));
    from_json(j["value"], (p.value));
}



/*
*   DateCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateCompact_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("year", to_json((p.year), allocator), allocator);
    json.AddMember("month", to_json((p.month), allocator), allocator);
    json.AddMember("day", to_json((p.day), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DateCompact_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["year"], (p.year));
    from_json(j["month"], (p.month));
    from_json(j["day"], (p.day));
}



/*
*   DieselEmissionValues::DieselEmissionValues__particulate - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues::DieselEmissionValues__particulate& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unitType", to_json((p.unitType), allocator), allocator);
    json.AddMember("value", to_json((p.value), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DieselEmissionValues::DieselEmissionValues__particulate& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["unitType"], (p.unitType));
    from_json(j["value"], (p.value));
}



/*
*   DieselEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("particulate", to_json((p.particulate), allocator), allocator);
    json.AddMember("absorptionCoeff", to_json((p.absorptionCoeff), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DieselEmissionValues_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["particulate"], (p.particulate));
    from_json(j["absorptionCoeff"], (p.absorptionCoeff));
}



/*
*   EfcDsrcApplication_DriverCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EfcDsrcApplication_DriverCharacteristics_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("driverClass", to_json((p.driverClass), allocator), allocator);
    json.AddMember("tripPurpose", to_json((p.tripPurpose), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, EfcDsrcApplication_DriverCharacteristics_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["driverClass"], (p.driverClass));
    from_json(j["tripPurpose"], (p.tripPurpose));
}



/*
*   EnvironmentalCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EnvironmentalCharacteristics_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("euroValue", to_json((p.euroValue), allocator), allocator);
    json.AddMember("copValue", to_json((p.copValue), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, EnvironmentalCharacteristics_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["euroValue"], (p.euroValue));
    from_json(j["copValue"], (p.copValue));
}



/*
*   Engine - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Engine_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("engineCapacity", to_json((p.engineCapacity), allocator), allocator);
    json.AddMember("enginePower", to_json((p.enginePower), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Engine_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["engineCapacity"], (p.engineCapacity));
    from_json(j["enginePower"], (p.enginePower));
}



/*
*   EquipmentStatus - Type BIT STRING
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json_EquipmentStatus(const EquipmentStatus_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    return json;
}

void from_json_EquipmentStatus(const Value& j, EquipmentStatus_t& p) {
    EquipmentStatus_t* p_tmp = vanetza::asn1::allocate<EquipmentStatus_t>();
    
    
    p_tmp->size = (0 / 8) + 1;
    p_tmp->bits_unused = (0 % 8) != 0 ? 8 - (0 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ExhaustEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ExhaustEmissionValues_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unitType", to_json((p.unitType), allocator), allocator);
    json.AddMember("emissionCO", to_json((p.emissionCO), allocator), allocator);
    json.AddMember("emissionHC", to_json((p.emissionHC), allocator), allocator);
    json.AddMember("emissionNOX", to_json((p.emissionNOX), allocator), allocator);
    json.AddMember("emissionHCNOX", to_json((p.emissionHCNOX), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ExhaustEmissionValues_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["unitType"], (p.unitType));
    from_json(j["emissionCO"], (p.emissionCO));
    from_json(j["emissionHC"], (p.emissionHC));
    from_json(j["emissionNOX"], (p.emissionNOX));
    from_json(j["emissionHCNOX"], (p.emissionHCNOX));
}



/*
*   LPN - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const LPN_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("countryCode", to_json_CountryCode((p.countryCode), allocator), allocator);
    json.AddMember("alphabetIndicator", to_json((p.alphabetIndicator), allocator), allocator);
    json.AddMember("licencePlateNumber", to_json((p.licencePlateNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LPN_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_CountryCode(j["countryCode"],(p.countryCode));
    from_json(j["alphabetIndicator"], (p.alphabetIndicator));
    from_json(j["licencePlateNumber"], (p.licencePlateNumber));
}



/*
*   PassengerCapacity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PassengerCapacity_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("numberOfSeats", to_json((p.numberOfSeats), allocator), allocator);
    json.AddMember("numberOfStandingPlaces", to_json((p.numberOfStandingPlaces), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PassengerCapacity_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["numberOfSeats"], (p.numberOfSeats));
    from_json(j["numberOfStandingPlaces"], (p.numberOfStandingPlaces));
}



/*
*   SignedValue - Type CHOICE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SignedValue_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == SignedValue_PR_positive) {
        json.AddMember("positive", to_json(p.choice.positive, allocator), allocator);
    } else if (p.present == SignedValue_PR_negative) {
        json.AddMember("negative", to_json(p.choice.negative, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, SignedValue_t& p) {
    if (j.HasMember("positive")) {
        p.present = SignedValue_PR_positive;
        from_json(j["positive"], p.choice.positive);
    } else if (j.HasMember("negative")) {
        p.present = SignedValue_PR_negative;
        from_json(j["negative"], p.choice.negative);
    } else {
        p.present = SignedValue_PR_NOTHING;
    }
}

/*
*   Provider - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Provider_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("countryCode", to_json_CountryCode((p.countryCode), allocator), allocator);
    json.AddMember("providerIdentifier", to_json((p.providerIdentifier), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, Provider_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_CountryCode(j["countryCode"],(p.countryCode));
    from_json(j["providerIdentifier"], (p.providerIdentifier));
}



/*
*   PurseBalance - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PurseBalance_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("purseValue", to_json((p.purseValue), allocator), allocator);
    json.AddMember("purseUnit", to_json((p.purseUnit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PurseBalance_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["purseValue"], (p.purseValue));
    from_json(j["purseUnit"], (p.purseUnit));
}



/*
*   ReceiptContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptContract_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sessionContractProvider", to_json((p.sessionContractProvider), allocator), allocator);
    json.AddMember("sessionTypeOfContract", to_json((p.sessionTypeOfContract), allocator), allocator);
    json.AddMember("sessionContractSerialNumber", to_json((p.sessionContractSerialNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ReceiptContract_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sessionContractProvider"], (p.sessionContractProvider));
    from_json(j["sessionTypeOfContract"], (p.sessionTypeOfContract));
    from_json(j["sessionContractSerialNumber"], (p.sessionContractSerialNumber));
}



/*
*   SessionClass - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionClass_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sessionTariffClass", to_json((p.sessionTariffClass), allocator), allocator);
    json.AddMember("sessionClaimedClass", to_json((p.sessionClaimedClass), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SessionClass_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sessionTariffClass"], (p.sessionTariffClass));
    from_json(j["sessionClaimedClass"], (p.sessionClaimedClass));
}



/*
*   SessionLocation - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionLocation_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("ascendingKilometrage", to_json((p.ascendingKilometrage), allocator), allocator);
    json.AddMember("laneCodeNumber", to_json((p.laneCodeNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SessionLocation_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["ascendingKilometrage"], (p.ascendingKilometrage));
    from_json(j["laneCodeNumber"], (p.laneCodeNumber));
}



/*
*   DateAndTime::DateAndTime__timeCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime::DateAndTime__timeCompact& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("hours", to_json((p.hours), allocator), allocator);
    json.AddMember("mins", to_json((p.mins), allocator), allocator);
    json.AddMember("double-secs", to_json((p.double_secs), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DateAndTime::DateAndTime__timeCompact& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["hours"], (p.hours));
    from_json(j["mins"], (p.mins));
    from_json(j["double-secs"], (p.double_secs));
}



/*
*   DateAndTime - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("timeDate", to_json((p.timeDate), allocator), allocator);
    json.AddMember("timeCompact", to_json((p.timeCompact), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DateAndTime_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["timeDate"], (p.timeDate));
    from_json(j["timeCompact"], (p.timeCompact));
}



/*
*   SoundLevel - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SoundLevel_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("soundstationary", to_json((p.soundstationary), allocator), allocator);
    json.AddMember("sounddriveby", to_json((p.sounddriveby), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SoundLevel_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["soundstationary"], (p.soundstationary));
    from_json(j["sounddriveby"], (p.sounddriveby));
}



/*
*   TrailerDetails - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const TrailerDetails_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("trailerType", to_json((p.trailerType), allocator), allocator);
    json.AddMember("trailerAxles", to_json((p.trailerAxles), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, TrailerDetails_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["trailerType"], (p.trailerType));
    from_json(j["trailerAxles"], (p.trailerAxles));
}



/*
*   ValidityOfContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ValidityOfContract_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("issuerRestrictions", to_json((p.issuerRestrictions), allocator), allocator);
    json.AddMember("contractExpiryDate", to_json((p.contractExpiryDate), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ValidityOfContract_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["issuerRestrictions"], (p.issuerRestrictions));
    from_json(j["contractExpiryDate"], (p.contractExpiryDate));
}



/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("trailerAxles", to_json((p.trailerAxles), allocator), allocator);
    json.AddMember("tractorAxles", to_json((p.tractorAxles), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["trailerAxles"], (p.trailerAxles));
    from_json(j["tractorAxles"], (p.tractorAxles));
}



/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("tyreType", to_json((p.tyreType), allocator), allocator);
    json.AddMember("numberOfAxles", to_json((p.numberOfAxles), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["tyreType"], (p.tyreType));
    from_json(j["numberOfAxles"], (p.numberOfAxles));
}



/*
*   VehicleAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vehicleFirstAxleHeight", to_json((p.vehicleFirstAxleHeight), allocator), allocator);
    json.AddMember("vehicleAxlesNumber", to_json((p.vehicleAxlesNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleAxles_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["vehicleFirstAxleHeight"], (p.vehicleFirstAxleHeight));
    from_json(j["vehicleAxlesNumber"], (p.vehicleAxlesNumber));
}



/*
*   VehicleDimensions - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleDimensions_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vehicleLengthOverall", to_json((p.vehicleLengthOverall), allocator), allocator);
    json.AddMember("vehicleHeigthOverall", to_json((p.vehicleHeigthOverall), allocator), allocator);
    json.AddMember("vehicleWidthOverall", to_json((p.vehicleWidthOverall), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleDimensions_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["vehicleLengthOverall"], (p.vehicleLengthOverall));
    from_json(j["vehicleHeigthOverall"], (p.vehicleHeigthOverall));
    from_json(j["vehicleWidthOverall"], (p.vehicleWidthOverall));
}



/*
*   VehicleSpecificCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleSpecificCharacteristics_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("environmentalCharacteristics", to_json((p.environmentalCharacteristics), allocator), allocator);
    json.AddMember("engineCharacteristics", to_json((p.engineCharacteristics), allocator), allocator);
    json.AddMember("descriptiveCharacteristics", to_json((p.descriptiveCharacteristics), allocator), allocator);
    json.AddMember("futureCharacteristics", to_json((p.futureCharacteristics), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleSpecificCharacteristics_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["environmentalCharacteristics"], (p.environmentalCharacteristics));
    from_json(j["engineCharacteristics"], (p.engineCharacteristics));
    from_json(j["descriptiveCharacteristics"], (p.descriptiveCharacteristics));
    from_json(j["futureCharacteristics"], (p.futureCharacteristics));
}



/*
*   VehicleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleWeightLimits_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vehicleMaxLadenWeight", to_json((p.vehicleMaxLadenWeight), allocator), allocator);
    json.AddMember("vehicleTrainMaximumWeight", to_json((p.vehicleTrainMaximumWeight), allocator), allocator);
    json.AddMember("vehicleWeightUnladen", to_json((p.vehicleWeightUnladen), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleWeightLimits_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["vehicleMaxLadenWeight"], (p.vehicleMaxLadenWeight));
    from_json(j["vehicleTrainMaximumWeight"], (p.vehicleTrainMaximumWeight));
    from_json(j["vehicleWeightUnladen"], (p.vehicleWeightUnladen));
}



/*
*   Ext2 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext2& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == Ext2_PR_content) {
        json.AddMember("content", to_json(p.choice.content, allocator), allocator);
    } else if (p.present == Ext2_PR_extension) {
        json.AddMember("extension", to_json(p.choice.extension, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, Ext2& p) {
    if (j.HasMember("content")) {
        p.present = Ext2_PR_content;
        from_json(j["content"], p.choice.content);
    } else if (j.HasMember("extension")) {
        p.present = Ext2_PR_extension;
        from_json(j["extension"], p.choice.extension);
    } else {
        p.present = Ext2_PR_NOTHING;
    }
}

/*
*   EuVehicleCategoryCode - Type CHOICE
*   From ElectronicRegistrationIdentificationVehicleDataModule - File ISO24534-3.asn
*/

Value to_json(const EuVehicleCategoryCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == EuVehicleCategoryCode_PR_euVehicleCategoryL) {
        json.AddMember("euVehicleCategoryL", to_json(p.choice.euVehicleCategoryL, allocator), allocator);
    } else if (p.present == EuVehicleCategoryCode_PR_euVehicleCategoryM) {
        json.AddMember("euVehicleCategoryM", to_json(p.choice.euVehicleCategoryM, allocator), allocator);
    } else if (p.present == EuVehicleCategoryCode_PR_euVehicleCategoryN) {
        json.AddMember("euVehicleCategoryN", to_json(p.choice.euVehicleCategoryN, allocator), allocator);
    } else if (p.present == EuVehicleCategoryCode_PR_euVehicleCategoryO) {
        json.AddMember("euVehicleCategoryO", to_json(p.choice.euVehicleCategoryO, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, EuVehicleCategoryCode& p) {
    if (j.HasMember("euVehicleCategoryL")) {
        p.present = EuVehicleCategoryCode_PR_euVehicleCategoryL;
        from_json(j["euVehicleCategoryL"], p.choice.euVehicleCategoryL);
    } else if (j.HasMember("euVehicleCategoryM")) {
        p.present = EuVehicleCategoryCode_PR_euVehicleCategoryM;
        from_json(j["euVehicleCategoryM"], p.choice.euVehicleCategoryM);
    } else if (j.HasMember("euVehicleCategoryN")) {
        p.present = EuVehicleCategoryCode_PR_euVehicleCategoryN;
        from_json(j["euVehicleCategoryN"], p.choice.euVehicleCategoryN);
    } else if (j.HasMember("euVehicleCategoryO")) {
        p.present = EuVehicleCategoryCode_PR_euVehicleCategoryO;
        from_json(j["euVehicleCategoryO"], p.choice.euVehicleCategoryO);
    } else {
        p.present = EuVehicleCategoryCode_PR_NOTHING;
    }
}

/*
*   ConnectedDenms - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConnectedDenms& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ActionID_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ConnectedDenms& p) {
    ConnectedDenms* p_tmp = vanetza::asn1::allocate<ConnectedDenms>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ActionID_t *element = vanetza::asn1::allocate<ActionID_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DeltaReferencePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaReferencePositions& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const DeltaReferencePosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DeltaReferencePositions& p) {
    DeltaReferencePositions* p_tmp = vanetza::asn1::allocate<DeltaReferencePositions>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        DeltaReferencePosition_t *element = vanetza::asn1::allocate<DeltaReferencePosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   IviIdentificationNumbers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviIdentificationNumbers& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const IviIdentificationNumber_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, IviIdentificationNumbers& p) {
    IviIdentificationNumbers* p_tmp = vanetza::asn1::allocate<IviIdentificationNumbers>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        IviIdentificationNumber_t *element = vanetza::asn1::allocate<IviIdentificationNumber_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneIds& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LaneID_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, LaneIds& p) {
    LaneIds* p_tmp = vanetza::asn1::allocate<LaneIds>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LaneID_t *element = vanetza::asn1::allocate<LaneID_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LanePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LanePositions& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LanePosition_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, LanePositions& p) {
    LanePositions* p_tmp = vanetza::asn1::allocate<LanePositions>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LanePosition_t *element = vanetza::asn1::allocate<LanePosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SaeAutomationLevels - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const SaeAutomationLevels& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SaeAutomationLevel_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, SaeAutomationLevels& p) {
    SaeAutomationLevels* p_tmp = vanetza::asn1::allocate<SaeAutomationLevels>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SaeAutomationLevel_t *element = vanetza::asn1::allocate<SaeAutomationLevel_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ZoneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ZoneIds& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Zid_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, ZoneIds& p) {
    ZoneIds* p_tmp = vanetza::asn1::allocate<ZoneIds>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Zid_t *element = vanetza::asn1::allocate<Zid_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AbsolutePosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("latitude", to_json(((p.latitude) == 900000001) ? (p.latitude) : (double)(p.latitude) / 10000000.0, allocator), allocator);
    json.AddMember("longitude", to_json(((p.longitude) == 1800000001) ? (p.longitude) : (double)(p.longitude) / 10000000.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AbsolutePosition& p) {
    p._asn_ctx.ptr = nullptr;
    double latitude; from_json(j["latitude"], (latitude)); (p.latitude) = ((latitude) != 900000001) ? latitude * 10000000 : latitude;
    double longitude; from_json(j["longitude"], (longitude)); (p.longitude) = ((longitude) != 1800000001) ? longitude * 10000000 : longitude;
}



/*
*   AbsolutePositionWAltitude - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionWAltitude& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("latitude", to_json(((p.latitude) == 900000001) ? (p.latitude) : (double)(p.latitude) / 10000000.0, allocator), allocator);
    json.AddMember("longitude", to_json(((p.longitude) == 1800000001) ? (p.longitude) : (double)(p.longitude) / 10000000.0, allocator), allocator);
    json.AddMember("altitude", to_json((p.altitude), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AbsolutePositionWAltitude& p) {
    p._asn_ctx.ptr = nullptr;
    double latitude; from_json(j["latitude"], (latitude)); (p.latitude) = ((latitude) != 900000001) ? latitude * 10000000 : latitude;
    double longitude; from_json(j["longitude"], (longitude)); (p.longitude) = ((longitude) != 1800000001) ? longitude * 10000000 : longitude;
    from_json(j["altitude"], (p.altitude));
}



/*
*   ComputedSegment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ComputedSegment& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("zoneId", to_json((p.zoneId), allocator), allocator);
    json.AddMember("laneNumber", to_json((p.laneNumber), allocator), allocator);
    json.AddMember("laneWidth", to_json((p.laneWidth), allocator), allocator);
    if (p.offsetDistance != 0) json.AddMember("offsetDistance", to_json(*(p.offsetDistance), allocator), allocator);
    if (p.offsetPosition != 0) json.AddMember("offsetPosition", to_json(*(p.offsetPosition), allocator), allocator);
    return json;
}

void from_json(const Value& j, ComputedSegment& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["zoneId"], (p.zoneId));
    from_json(j["laneNumber"], (p.laneNumber));
    from_json(j["laneWidth"], (p.laneWidth));
    if (j.HasMember("offsetDistance")) { p.offsetDistance = vanetza::asn1::allocate<long>(); from_json(j["offsetDistance"], *(p.offsetDistance)); }
    else { p.offsetDistance=nullptr; }
    if (j.HasMember("offsetPosition")) { p.offsetPosition = vanetza::asn1::allocate<DeltaReferencePosition_t>(); from_json(j["offsetPosition"], *(p.offsetPosition)); }
    else { p.offsetPosition=nullptr; }
}



/*
*   DeltaPosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("deltaLatitude", to_json((p.deltaLatitude), allocator), allocator);
    json.AddMember("deltaLongitude", to_json((p.deltaLongitude), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DeltaPosition& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["deltaLatitude"], (p.deltaLatitude));
    from_json(j["deltaLongitude"], (p.deltaLongitude));
}



/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram) {
        json.AddMember("trafficSignPictogram", to_json(p.choice.trafficSignPictogram, allocator), allocator);
    } else if (p.present == ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram) {
        json.AddMember("publicFacilitiesPictogram", to_json(p.choice.publicFacilitiesPictogram, allocator), allocator);
    } else if (p.present == ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram) {
        json.AddMember("ambientOrRoadConditionPictogram", to_json(p.choice.ambientOrRoadConditionPictogram, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p) {
    if (j.HasMember("trafficSignPictogram")) {
        p.present = ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram;
        from_json(j["trafficSignPictogram"], p.choice.trafficSignPictogram);
    } else if (j.HasMember("publicFacilitiesPictogram")) {
        p.present = ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram;
        from_json(j["publicFacilitiesPictogram"], p.choice.publicFacilitiesPictogram);
    } else if (j.HasMember("ambientOrRoadConditionPictogram")) {
        p.present = ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram;
        from_json(j["ambientOrRoadConditionPictogram"], p.choice.ambientOrRoadConditionPictogram);
    } else {
        p.present = ISO14823Code__pictogramCode__serviceCategoryCode_PR::ISO14823Code__pictogramCode__serviceCategoryCode_PR_NOTHING;
    }
}

/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("nature", to_json((p.nature), allocator), allocator);
    json.AddMember("serialNumber", to_json((p.serialNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["nature"], (p.nature));
    from_json(j["serialNumber"], (p.serialNumber));
}



/*
*   ISO14823Code::ISO14823Code__pictogramCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("serviceCategoryCode", to_json((p.serviceCategoryCode), allocator), allocator);
    json.AddMember("pictogramCategoryCode", to_json((p.pictogramCategoryCode), allocator), allocator);
    if (p.countryCode != 0) json.AddMember("countryCode", to_json(*(p.countryCode), allocator), allocator);
    return json;
}

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("countryCode")) { p.countryCode = vanetza::asn1::allocate<OCTET_STRING_t>(); from_json(j["countryCode"], *(p.countryCode)); }
    else { p.countryCode=nullptr; }
    from_json(j["serviceCategoryCode"], (p.serviceCategoryCode));
    from_json(j["pictogramCategoryCode"], (p.pictogramCategoryCode));
}



/*
*   LaneCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("zoneDefinitionAccuracy", to_json((p.zoneDefinitionAccuracy), allocator), allocator);
    json.AddMember("existinglaneMarkingStatus", to_json((p.existinglaneMarkingStatus), allocator), allocator);
    json.AddMember("newlaneMarkingColour", to_json((p.newlaneMarkingColour), allocator), allocator);
    json.AddMember("laneDelimitationLeft", to_json((p.laneDelimitationLeft), allocator), allocator);
    json.AddMember("laneDelimitationRight", to_json((p.laneDelimitationRight), allocator), allocator);
    json.AddMember("mergingWith", to_json((p.mergingWith), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LaneCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["zoneDefinitionAccuracy"], (p.zoneDefinitionAccuracy));
    from_json(j["existinglaneMarkingStatus"], (p.existinglaneMarkingStatus));
    from_json(j["newlaneMarkingColour"], (p.newlaneMarkingColour));
    from_json(j["laneDelimitationLeft"], (p.laneDelimitationLeft));
    from_json(j["laneDelimitationRight"], (p.laneDelimitationRight));
    from_json(j["mergingWith"], (p.mergingWith));
}



/*
*   LayoutComponent - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponent& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("layoutComponentId", to_json((p.layoutComponentId), allocator), allocator);
    json.AddMember("height", to_json((p.height), allocator), allocator);
    json.AddMember("width", to_json((p.width), allocator), allocator);
    json.AddMember("x", to_json((p.x), allocator), allocator);
    json.AddMember("y", to_json((p.y), allocator), allocator);
    json.AddMember("textScripting", to_json((p.textScripting), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LayoutComponent& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["layoutComponentId"], (p.layoutComponentId));
    from_json(j["height"], (p.height));
    from_json(j["width"], (p.width));
    from_json(j["x"], (p.x));
    from_json(j["y"], (p.y));
    from_json(j["textScripting"], (p.textScripting));
}



/*
*   LoadType - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LoadType& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("goodsType", to_json((p.goodsType), allocator), allocator);
    json.AddMember("dangerousGoodsType", to_json((p.dangerousGoodsType), allocator), allocator);
    json.AddMember("specialTransportType", to_json_SpecialTransportType((p.specialTransportType), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LoadType& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["goodsType"], (p.goodsType));
    from_json(j["dangerousGoodsType"], (p.dangerousGoodsType));
    from_json_SpecialTransportType(j["specialTransportType"],(p.specialTransportType));
}



/*
*   MapReference - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapReference& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == MapReference_PR_roadsegment) {
        json.AddMember("roadsegment", to_json(p.choice.roadsegment, allocator), allocator);
    } else if (p.present == MapReference_PR_intersection) {
        json.AddMember("intersection", to_json(p.choice.intersection, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, MapReference& p) {
    if (j.HasMember("roadsegment")) {
        p.present = MapReference_PR_roadsegment;
        from_json(j["roadsegment"], p.choice.roadsegment);
    } else if (j.HasMember("intersection")) {
        p.present = MapReference_PR_intersection;
        from_json(j["intersection"], p.choice.intersection);
    } else {
        p.present = MapReference_PR_NOTHING;
    }
}

/*
*   RoadSurfaceDynamicCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceDynamicCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("condition", to_json((p.condition), allocator), allocator);
    json.AddMember("temperature", to_json((p.temperature), allocator), allocator);
    json.AddMember("iceOrWaterDepth", to_json((p.iceOrWaterDepth), allocator), allocator);
    json.AddMember("treatment", to_json((p.treatment), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RoadSurfaceDynamicCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["condition"], (p.condition));
    from_json(j["temperature"], (p.temperature));
    from_json(j["iceOrWaterDepth"], (p.iceOrWaterDepth));
    from_json(j["treatment"], (p.treatment));
}



/*
*   RoadSurfaceStaticCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceStaticCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("frictionCoefficient", to_json((p.frictionCoefficient), allocator), allocator);
    json.AddMember("material", to_json((p.material), allocator), allocator);
    json.AddMember("wear", to_json((p.wear), allocator), allocator);
    json.AddMember("avBankingAngle", to_json((p.avBankingAngle), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RoadSurfaceStaticCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["frictionCoefficient"], (p.frictionCoefficient));
    from_json(j["material"], (p.material));
    from_json(j["wear"], (p.wear));
    from_json(j["avBankingAngle"], (p.avBankingAngle));
}



/*
*   Text - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Text& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("textContent", to_json((p.textContent), allocator), allocator);
    if (p.layoutComponentId != 0) json.AddMember("layoutComponentId", to_json(*(p.layoutComponentId), allocator), allocator);
    return json;
}

void from_json(const Value& j, Text& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("layoutComponentId")) { p.layoutComponentId = vanetza::asn1::allocate<long>(); from_json(j["layoutComponentId"], *(p.layoutComponentId)); }
    else { p.layoutComponentId=nullptr; }
    from_json(j["textContent"], (p.textContent));
    
}



/*
*   VehicleCharacteristicsFixValues - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValues& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VehicleCharacteristicsFixValues_PR_simpleVehicleType) {
        json.AddMember("simpleVehicleType", to_json(p.choice.simpleVehicleType, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsFixValues_PR_euVehicleCategoryCode) {
        json.AddMember("euVehicleCategoryCode", to_json(p.choice.euVehicleCategoryCode, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsFixValues_PR_euroAndCo2value) {
        json.AddMember("euroAndCo2value", to_json(p.choice.euroAndCo2value, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsFixValues_PR_engineCharacteristics) {
        json.AddMember("engineCharacteristics", to_json(p.choice.engineCharacteristics, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsFixValues_PR_loadType) {
        json.AddMember("loadType", to_json(p.choice.loadType, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsFixValues_PR_usage) {
        json.AddMember("usage", to_json(p.choice.usage, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsFixValues& p) {
    if (j.HasMember("simpleVehicleType")) {
        p.present = VehicleCharacteristicsFixValues_PR_simpleVehicleType;
        from_json(j["simpleVehicleType"], p.choice.simpleVehicleType);
    } else if (j.HasMember("euVehicleCategoryCode")) {
        p.present = VehicleCharacteristicsFixValues_PR_euVehicleCategoryCode;
        from_json(j["euVehicleCategoryCode"], p.choice.euVehicleCategoryCode);
    } else if (j.HasMember("euroAndCo2value")) {
        p.present = VehicleCharacteristicsFixValues_PR_euroAndCo2value;
        from_json(j["euroAndCo2value"], p.choice.euroAndCo2value);
    } else if (j.HasMember("engineCharacteristics")) {
        p.present = VehicleCharacteristicsFixValues_PR_engineCharacteristics;
        from_json(j["engineCharacteristics"], p.choice.engineCharacteristics);
    } else if (j.HasMember("loadType")) {
        p.present = VehicleCharacteristicsFixValues_PR_loadType;
        from_json(j["loadType"], p.choice.loadType);
    } else if (j.HasMember("usage")) {
        p.present = VehicleCharacteristicsFixValues_PR_usage;
        from_json(j["usage"], p.choice.usage);
    } else {
        p.present = VehicleCharacteristicsFixValues_PR_NOTHING;
    }
}

/*
*   VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_numberOfAxles) {
        json.AddMember("numberOfAxles", to_json(p.choice.numberOfAxles, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_vehicleDimensions) {
        json.AddMember("vehicleDimensions", to_json(p.choice.vehicleDimensions, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_vehicleWeightLimits) {
        json.AddMember("vehicleWeightLimits", to_json(p.choice.vehicleWeightLimits, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_axleWeightLimits) {
        json.AddMember("axleWeightLimits", to_json(p.choice.axleWeightLimits, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_passengerCapacity) {
        json.AddMember("passengerCapacity", to_json(p.choice.passengerCapacity, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_exhaustEmissionValues) {
        json.AddMember("exhaustEmissionValues", to_json(p.choice.exhaustEmissionValues, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_dieselEmissionValues) {
        json.AddMember("dieselEmissionValues", to_json(p.choice.dieselEmissionValues, allocator), allocator);
    } else if (p.present == VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_soundLevel) {
        json.AddMember("soundLevel", to_json(p.choice.soundLevel, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p) {
    if (j.HasMember("numberOfAxles")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_numberOfAxles;
        from_json(j["numberOfAxles"], p.choice.numberOfAxles);
    } else if (j.HasMember("vehicleDimensions")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_vehicleDimensions;
        from_json(j["vehicleDimensions"], p.choice.vehicleDimensions);
    } else if (j.HasMember("vehicleWeightLimits")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_vehicleWeightLimits;
        from_json(j["vehicleWeightLimits"], p.choice.vehicleWeightLimits);
    } else if (j.HasMember("axleWeightLimits")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_axleWeightLimits;
        from_json(j["axleWeightLimits"], p.choice.axleWeightLimits);
    } else if (j.HasMember("passengerCapacity")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_passengerCapacity;
        from_json(j["passengerCapacity"], p.choice.passengerCapacity);
    } else if (j.HasMember("exhaustEmissionValues")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_exhaustEmissionValues;
        from_json(j["exhaustEmissionValues"], p.choice.exhaustEmissionValues);
    } else if (j.HasMember("dieselEmissionValues")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_dieselEmissionValues;
        from_json(j["dieselEmissionValues"], p.choice.dieselEmissionValues);
    } else if (j.HasMember("soundLevel")) {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_soundLevel;
        from_json(j["soundLevel"], p.choice.soundLevel);
    } else {
        p.present = VehicleCharacteristicsRanges__limits_PR::VehicleCharacteristicsRanges__limits_PR_NOTHING;
    }
}

/*
*   VehicleCharacteristicsRanges - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("comparisonOperator", to_json((p.comparisonOperator), allocator), allocator);
    json.AddMember("limits", to_json((p.limits), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsRanges& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["comparisonOperator"], (p.comparisonOperator));
    from_json(j["limits"], (p.limits));
}



/*
*   BasicVehicleContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerHighFrequency& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heading", to_json((p.heading), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    json.AddMember("driveDirection", to_json((p.driveDirection), allocator), allocator);
    json.AddMember("vehicleLength", to_json((p.vehicleLength), allocator), allocator);
    json.AddMember("vehicleWidth", to_json(((p.vehicleWidth) == 61 || (p.vehicleWidth) == 62) ? (p.vehicleWidth) : (double)(p.vehicleWidth) / 10.0, allocator), allocator);
    json.AddMember("longitudinalAcceleration", to_json((p.longitudinalAcceleration), allocator), allocator);
    json.AddMember("curvature", to_json((p.curvature), allocator), allocator);
    json.AddMember("curvatureCalculationMode", to_json((p.curvatureCalculationMode), allocator), allocator);
    json.AddMember("yawRate", to_json((p.yawRate), allocator), allocator);
    if (p.accelerationControl != 0) json.AddMember("accelerationControl", to_json_AccelerationControl(*(p.accelerationControl), allocator), allocator);
    if (p.lanePosition != 0) json.AddMember("lanePosition", to_json(*(p.lanePosition), allocator), allocator);
    if (p.steeringWheelAngle != 0) json.AddMember("steeringWheelAngle", to_json(*(p.steeringWheelAngle), allocator), allocator);
    if (p.lateralAcceleration != 0) json.AddMember("lateralAcceleration", to_json(*(p.lateralAcceleration), allocator), allocator);
    if (p.verticalAcceleration != 0) json.AddMember("verticalAcceleration", to_json(*(p.verticalAcceleration), allocator), allocator);
    if (p.performanceClass != 0) json.AddMember("performanceClass", to_json(*(p.performanceClass), allocator), allocator);
    if (p.cenDsrcTollingZone != 0) json.AddMember("cenDsrcTollingZone", to_json(*(p.cenDsrcTollingZone), allocator), allocator);
    return json;
}

void from_json(const Value& j, BasicVehicleContainerHighFrequency& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["heading"], (p.heading));
    from_json(j["speed"], (p.speed));
    from_json(j["driveDirection"], (p.driveDirection));
    from_json(j["vehicleLength"], (p.vehicleLength));
    double vehicleWidth; from_json(j["vehicleWidth"], (vehicleWidth)); (p.vehicleWidth) = ((vehicleWidth) != 61 && (vehicleWidth) != 62) ? vehicleWidth * 10 : vehicleWidth;
    from_json(j["longitudinalAcceleration"], (p.longitudinalAcceleration));
    from_json(j["curvature"], (p.curvature));
    from_json(j["curvatureCalculationMode"], (p.curvatureCalculationMode));
    from_json(j["yawRate"], (p.yawRate));
    if (j.HasMember("accelerationControl")) { p.accelerationControl = vanetza::asn1::allocate<AccelerationControl_t>(); from_json_AccelerationControl(j["accelerationControl"],*(p.accelerationControl)); }
    else { p.accelerationControl=nullptr; }
    if (j.HasMember("lanePosition")) { p.lanePosition = vanetza::asn1::allocate<LanePosition_t>(); from_json(j["lanePosition"], *(p.lanePosition)); }
    else { p.lanePosition=nullptr; }
    if (j.HasMember("steeringWheelAngle")) { p.steeringWheelAngle = vanetza::asn1::allocate<SteeringWheelAngle_t>(); from_json(j["steeringWheelAngle"], *(p.steeringWheelAngle)); }
    else { p.steeringWheelAngle=nullptr; }
    if (j.HasMember("lateralAcceleration")) { p.lateralAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); from_json(j["lateralAcceleration"], *(p.lateralAcceleration)); }
    else { p.lateralAcceleration=nullptr; }
    if (j.HasMember("verticalAcceleration")) { p.verticalAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); from_json(j["verticalAcceleration"], *(p.verticalAcceleration)); }
    else { p.verticalAcceleration=nullptr; }
    if (j.HasMember("performanceClass")) { p.performanceClass = vanetza::asn1::allocate<PerformanceClass_t>(); from_json(j["performanceClass"], *(p.performanceClass)); }
    else { p.performanceClass=nullptr; }
    if (j.HasMember("cenDsrcTollingZone")) { p.cenDsrcTollingZone = vanetza::asn1::allocate<CenDsrcTollingZone_t>(); from_json(j["cenDsrcTollingZone"], *(p.cenDsrcTollingZone)); }
    else { p.cenDsrcTollingZone=nullptr; }
}



/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerLowFrequency& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vehicleRole", to_json((p.vehicleRole), allocator), allocator);
    json.AddMember("exteriorLights", to_json_ExteriorLights((p.exteriorLights), allocator), allocator);
    json.AddMember("pathHistory", to_json((p.pathHistory), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, BasicVehicleContainerLowFrequency& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["vehicleRole"], (p.vehicleRole));
    from_json_ExteriorLights(j["exteriorLights"],(p.exteriorLights));
    from_json(j["pathHistory"], (p.pathHistory));
}



/*
*   SpecialTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialTransportContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("specialTransportType", to_json_SpecialTransportType((p.specialTransportType), allocator), allocator);
    json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SpecialTransportContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_SpecialTransportType(j["specialTransportType"],(p.specialTransportType));
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}



/*
*   DangerousGoodsContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const DangerousGoodsContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("dangerousGoodsBasic", to_json((p.dangerousGoodsBasic), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DangerousGoodsContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["dangerousGoodsBasic"], (p.dangerousGoodsBasic));
}



/*
*   RescueContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RescueContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RescueContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
}



/*
*   EmergencyContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const EmergencyContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse), allocator), allocator);
    if (p.incidentIndication != 0) json.AddMember("incidentIndication", to_json(*(p.incidentIndication), allocator), allocator);
    if (p.emergencyPriority != 0) json.AddMember("emergencyPriority", to_json_EmergencyPriority(*(p.emergencyPriority), allocator), allocator);
    return json;
}

void from_json(const Value& j, EmergencyContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
    if (j.HasMember("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); from_json(j["incidentIndication"], *(p.incidentIndication)); }
    else { p.incidentIndication=nullptr; }
    if (j.HasMember("emergencyPriority")) { p.emergencyPriority = vanetza::asn1::allocate<EmergencyPriority_t>(); from_json_EmergencyPriority(j["emergencyPriority"],*(p.emergencyPriority)); }
    else { p.emergencyPriority=nullptr; }
}



/*
*   SafetyCarContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SafetyCarContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse), allocator), allocator);
    if (p.incidentIndication != 0) json.AddMember("incidentIndication", to_json(*(p.incidentIndication), allocator), allocator);
    if (p.trafficRule != 0) json.AddMember("trafficRule", to_json(*(p.trafficRule), allocator), allocator);
    if (p.speedLimit != 0) json.AddMember("speedLimit", to_json(*(p.speedLimit), allocator), allocator);
    return json;
}

void from_json(const Value& j, SafetyCarContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
    if (j.HasMember("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); from_json(j["incidentIndication"], *(p.incidentIndication)); }
    else { p.incidentIndication=nullptr; }
    if (j.HasMember("trafficRule")) { p.trafficRule = vanetza::asn1::allocate<TrafficRule_t>(); from_json(j["trafficRule"], *(p.trafficRule)); }
    else { p.trafficRule=nullptr; }
    if (j.HasMember("speedLimit")) { p.speedLimit = vanetza::asn1::allocate<SpeedLimit_t>(); from_json(j["speedLimit"], *(p.speedLimit)); }
    else { p.speedLimit=nullptr; }
}



/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RSUContainerHighFrequency& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.protectedCommunicationZonesRSU != 0) json.AddMember("protectedCommunicationZonesRSU", to_json(*(p.protectedCommunicationZonesRSU), allocator), allocator);
    return json;
}

void from_json(const Value& j, RSUContainerHighFrequency& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("protectedCommunicationZonesRSU")) { p.protectedCommunicationZonesRSU = vanetza::asn1::allocate<ProtectedCommunicationZonesRSU_t>(); from_json(j["protectedCommunicationZonesRSU"], *(p.protectedCommunicationZonesRSU)); }
    else { p.protectedCommunicationZonesRSU=nullptr; }
}



/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const LocationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("traces", to_json((p.traces), allocator), allocator);
    if (p.eventSpeed != 0) json.AddMember("eventSpeed", to_json(*(p.eventSpeed), allocator), allocator);
    if (p.eventPositionHeading != 0) json.AddMember("eventPositionHeading", to_json(*(p.eventPositionHeading), allocator), allocator);
    if (p.roadType != 0) json.AddMember("roadType", to_json(*(p.roadType), allocator), allocator);
    return json;
}

void from_json(const Value& j, LocationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("eventSpeed")) { p.eventSpeed = vanetza::asn1::allocate<Speed_t>(); from_json(j["eventSpeed"], *(p.eventSpeed)); }
    else { p.eventSpeed=nullptr; }
    if (j.HasMember("eventPositionHeading")) { p.eventPositionHeading = vanetza::asn1::allocate<Heading_t>(); from_json(j["eventPositionHeading"], *(p.eventPositionHeading)); }
    else { p.eventPositionHeading=nullptr; }
    from_json(j["traces"], (p.traces));
    if (j.HasMember("roadType")) { p.roadType = vanetza::asn1::allocate<RoadType_t>(); from_json(j["roadType"], *(p.roadType)); }
    else { p.roadType=nullptr; }
}



/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ImpactReductionContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heightLonCarrLeft", to_json((p.heightLonCarrLeft), allocator), allocator);
    json.AddMember("heightLonCarrRight", to_json((p.heightLonCarrRight), allocator), allocator);
    json.AddMember("posLonCarrLeft", to_json((p.posLonCarrLeft), allocator), allocator);
    json.AddMember("posLonCarrRight", to_json((p.posLonCarrRight), allocator), allocator);
    json.AddMember("positionOfPillars", to_json((p.positionOfPillars), allocator), allocator);
    json.AddMember("posCentMass", to_json((p.posCentMass), allocator), allocator);
    json.AddMember("wheelBaseVehicle", to_json((p.wheelBaseVehicle), allocator), allocator);
    json.AddMember("turningRadius", to_json((p.turningRadius), allocator), allocator);
    json.AddMember("posFrontAx", to_json((p.posFrontAx), allocator), allocator);
    json.AddMember("positionOfOccupants", to_json_PositionOfOccupants((p.positionOfOccupants), allocator), allocator);
    json.AddMember("vehicleMass", to_json((p.vehicleMass), allocator), allocator);
    json.AddMember("requestResponseIndication", to_json((p.requestResponseIndication), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ImpactReductionContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["heightLonCarrLeft"], (p.heightLonCarrLeft));
    from_json(j["heightLonCarrRight"], (p.heightLonCarrRight));
    from_json(j["posLonCarrLeft"], (p.posLonCarrLeft));
    from_json(j["posLonCarrRight"], (p.posLonCarrRight));
    from_json(j["positionOfPillars"], (p.positionOfPillars));
    from_json(j["posCentMass"], (p.posCentMass));
    from_json(j["wheelBaseVehicle"], (p.wheelBaseVehicle));
    from_json(j["turningRadius"], (p.turningRadius));
    from_json(j["posFrontAx"], (p.posFrontAx));
    from_json_PositionOfOccupants(j["positionOfOccupants"],(p.positionOfOccupants));
    from_json(j["vehicleMass"], (p.vehicleMass));
    from_json(j["requestResponseIndication"], (p.requestResponseIndication));
}



/*
*   StationaryVehicleContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const StationaryVehicleContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.stationarySince != 0) json.AddMember("stationarySince", to_json(*(p.stationarySince), allocator), allocator);
    if (p.stationaryCause != 0) json.AddMember("stationaryCause", to_json(*(p.stationaryCause), allocator), allocator);
    if (p.carryingDangerousGoods != 0) json.AddMember("carryingDangerousGoods", to_json(*(p.carryingDangerousGoods), allocator), allocator);
    if (p.numberOfOccupants != 0) json.AddMember("numberOfOccupants", to_json(*(p.numberOfOccupants), allocator), allocator);
    if (p.vehicleIdentification != 0) json.AddMember("vehicleIdentification", to_json(*(p.vehicleIdentification), allocator), allocator);
    if (p.energyStorageType != 0) json.AddMember("energyStorageType", to_json_EnergyStorageType(*(p.energyStorageType), allocator), allocator);
    return json;
}

void from_json(const Value& j, StationaryVehicleContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("stationarySince")) { p.stationarySince = vanetza::asn1::allocate<StationarySince_t>(); from_json(j["stationarySince"], *(p.stationarySince)); }
    else { p.stationarySince=nullptr; }
    if (j.HasMember("stationaryCause")) { p.stationaryCause = vanetza::asn1::allocate<CauseCode_t>(); from_json(j["stationaryCause"], *(p.stationaryCause)); }
    else { p.stationaryCause=nullptr; }
    if (j.HasMember("carryingDangerousGoods")) { p.carryingDangerousGoods = vanetza::asn1::allocate<DangerousGoodsExtended_t>(); from_json(j["carryingDangerousGoods"], *(p.carryingDangerousGoods)); }
    else { p.carryingDangerousGoods=nullptr; }
    if (j.HasMember("numberOfOccupants")) { p.numberOfOccupants = vanetza::asn1::allocate<NumberOfOccupants_t>(); from_json(j["numberOfOccupants"], *(p.numberOfOccupants)); }
    else { p.numberOfOccupants=nullptr; }
    if (j.HasMember("vehicleIdentification")) { p.vehicleIdentification = vanetza::asn1::allocate<VehicleIdentification_t>(); from_json(j["vehicleIdentification"], *(p.vehicleIdentification)); }
    else { p.vehicleIdentification=nullptr; }
    if (j.HasMember("energyStorageType")) { p.energyStorageType = vanetza::asn1::allocate<EnergyStorageType_t>(); from_json_EnergyStorageType(j["energyStorageType"],*(p.energyStorageType)); }
    else { p.energyStorageType=nullptr; }
}



/*
*   ReferenceDenms - Type SEQUENCE OF
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ReferenceDenms& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ActionID_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ReferenceDenms& p) {
    ReferenceDenms* p_tmp = vanetza::asn1::allocate<ReferenceDenms>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ActionID_t *element = vanetza::asn1::allocate<ActionID_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   MapPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const MapPosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("intersectionId", to_json((p.intersectionId), allocator), allocator);
    json.AddMember("lane", to_json((p.lane), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, MapPosition& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["intersectionId"], (p.intersectionId));
    from_json(j["lane"], (p.lane));
}



/*
*   VruProfileAndSubprofile - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruProfileAndSubprofile& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VruProfileAndSubprofile_PR_pedestrian) {
        json.AddMember("pedestrian", to_json(p.choice.pedestrian, allocator), allocator);
    } else if (p.present == VruProfileAndSubprofile_PR_bicyclist) {
        json.AddMember("bicyclist", to_json(p.choice.bicyclist, allocator), allocator);
    } else if (p.present == VruProfileAndSubprofile_PR_motorcylist) {
        json.AddMember("motorcylist", to_json(p.choice.motorcylist, allocator), allocator);
    } else if (p.present == VruProfileAndSubprofile_PR_animal) {
        json.AddMember("animal", to_json(p.choice.animal, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VruProfileAndSubprofile& p) {
    if (j.HasMember("pedestrian")) {
        p.present = VruProfileAndSubprofile_PR_pedestrian;
        from_json(j["pedestrian"], p.choice.pedestrian);
    } else if (j.HasMember("bicyclist")) {
        p.present = VruProfileAndSubprofile_PR_bicyclist;
        from_json(j["bicyclist"], p.choice.bicyclist);
    } else if (j.HasMember("motorcylist")) {
        p.present = VruProfileAndSubprofile_PR_motorcylist;
        from_json(j["motorcylist"], p.choice.motorcylist);
    } else if (j.HasMember("animal")) {
        p.present = VruProfileAndSubprofile_PR_animal;
        from_json(j["animal"], p.choice.animal);
    } else {
        p.present = VruProfileAndSubprofile_PR_NOTHING;
    }
}

/*
*   VruSpecificExteriorLights - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_VruSpecificExteriorLights(const VruSpecificExteriorLights_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("unavailable", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("backFlashLight", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("helmetLight", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("armLight", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    json.AddMember("legLight", (bool) (*(p.buf + (sizeof(uint8_t) * (4 / 8))) & (1 << ((7 * ((4 / 8) + 1))-(4 % 8)))), allocator);
    json.AddMember("wheelLight", (bool) (*(p.buf + (sizeof(uint8_t) * (5 / 8))) & (1 << ((7 * ((5 / 8) + 1))-(5 % 8)))), allocator);
    return json;
}

void from_json_VruSpecificExteriorLights(const Value& j, VruSpecificExteriorLights_t& p) {
    VruSpecificExteriorLights_t* p_tmp = vanetza::asn1::allocate<VruSpecificExteriorLights_t>();
    bool unavailable;
    bool backFlashLight;
    bool helmetLight;
    bool armLight;
    bool legLight;
    bool wheelLight;
    if (j.HasMember("unavailable")) from_json(j["unavailable"], (unavailable));
    if (j.HasMember("backFlashLight")) from_json(j["backFlashLight"], (backFlashLight));
    if (j.HasMember("helmetLight")) from_json(j["helmetLight"], (helmetLight));
    if (j.HasMember("armLight")) from_json(j["armLight"], (armLight));
    if (j.HasMember("legLight")) from_json(j["legLight"], (legLight));
    if (j.HasMember("wheelLight")) from_json(j["wheelLight"], (wheelLight));
    p_tmp->size = (6 / 8) + 1;
    p_tmp->bits_unused = (6 % 8) != 0 ? 8 - (6 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (unavailable) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (backFlashLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (helmetLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (armLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    if (legLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 3);
    if (wheelLight) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 2);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ClusterProfiles - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_ClusterProfiles(const ClusterProfiles_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pedestrian", (bool) (*(p.buf + (sizeof(uint8_t) * (0 / 8))) & (1 << ((7 * ((0 / 8) + 1))-(0 % 8)))), allocator);
    json.AddMember("bicyclist", (bool) (*(p.buf + (sizeof(uint8_t) * (1 / 8))) & (1 << ((7 * ((1 / 8) + 1))-(1 % 8)))), allocator);
    json.AddMember("motorcyclist", (bool) (*(p.buf + (sizeof(uint8_t) * (2 / 8))) & (1 << ((7 * ((2 / 8) + 1))-(2 % 8)))), allocator);
    json.AddMember("animal", (bool) (*(p.buf + (sizeof(uint8_t) * (3 / 8))) & (1 << ((7 * ((3 / 8) + 1))-(3 % 8)))), allocator);
    return json;
}

void from_json_ClusterProfiles(const Value& j, ClusterProfiles_t& p) {
    ClusterProfiles_t* p_tmp = vanetza::asn1::allocate<ClusterProfiles_t>();
    bool pedestrian;
    bool bicyclist;
    bool motorcyclist;
    bool animal;
    if (j.HasMember("pedestrian")) from_json(j["pedestrian"], (pedestrian));
    if (j.HasMember("bicyclist")) from_json(j["bicyclist"], (bicyclist));
    if (j.HasMember("motorcyclist")) from_json(j["motorcyclist"], (motorcyclist));
    if (j.HasMember("animal")) from_json(j["animal"], (animal));
    p_tmp->size = (4 / 8) + 1;
    p_tmp->bits_unused = (4 % 8) != 0 ? 8 - (4 % 8) : 0;
    p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
    *(p_tmp->buf + (sizeof(uint8_t) * 0)) = (uint8_t) 0;
    if (pedestrian) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 7);
    if (bicyclist) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 6);
    if (motorcyclist) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 5);
    if (animal) *(p_tmp->buf + (sizeof(uint8_t) * 0)) |= (1 << 4);
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ClusterJoinInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterJoinInfo& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("clusterId", to_json((p.clusterId), allocator), allocator);
    json.AddMember("joinTime", to_json((p.joinTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ClusterJoinInfo& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["clusterId"], (p.clusterId));
    from_json(j["joinTime"], (p.joinTime));
}



/*
*   ClusterLeaveInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterLeaveInfo& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("clusterId", to_json((p.clusterId), allocator), allocator);
    json.AddMember("clusterLeaveReason", to_json((p.clusterLeaveReason), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ClusterLeaveInfo& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["clusterId"], (p.clusterId));
    from_json(j["clusterLeaveReason"], (p.clusterLeaveReason));
}



/*
*   ClusterBreakupInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBreakupInfo& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("clusterBreakupReason", to_json((p.clusterBreakupReason), allocator), allocator);
    json.AddMember("breakupTime", to_json((p.breakupTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ClusterBreakupInfo& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["clusterBreakupReason"], (p.clusterBreakupReason));
    from_json(j["breakupTime"], (p.breakupTime));
}



/*
*   VruSafeDistanceIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruSafeDistanceIndication& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stationSafeDistanceIndication", to_json((p.stationSafeDistanceIndication), allocator), allocator);
    if (p.subjectStation != 0) json.AddMember("subjectStation", to_json(*(p.subjectStation), allocator), allocator);
    if (p.timeToCollision != 0) json.AddMember("timeToCollision", to_json(*(p.timeToCollision), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruSafeDistanceIndication& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("subjectStation")) { p.subjectStation = vanetza::asn1::allocate<StationID_t>(); from_json(j["subjectStation"], *(p.subjectStation)); }
    else { p.subjectStation=nullptr; }
    from_json(j["stationSafeDistanceIndication"], (p.stationSafeDistanceIndication));
    if (j.HasMember("timeToCollision")) { p.timeToCollision = vanetza::asn1::allocate<ActionDeltaTime_t>(); from_json(j["timeToCollision"], *(p.timeToCollision)); }
    else { p.timeToCollision=nullptr; }
}



/*
*   TrajectoryInterceptionIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrajectoryInterceptionIndication& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("trajectoryInterceptionProbability", to_json((p.trajectoryInterceptionProbability), allocator), allocator);
    if (p.subjectStation != 0) json.AddMember("subjectStation", to_json(*(p.subjectStation), allocator), allocator);
    if (p.trajectoryInterceptionConfidence != 0) json.AddMember("trajectoryInterceptionConfidence", to_json(*(p.trajectoryInterceptionConfidence), allocator), allocator);
    return json;
}

void from_json(const Value& j, TrajectoryInterceptionIndication& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("subjectStation")) { p.subjectStation = vanetza::asn1::allocate<StationID_t>(); from_json(j["subjectStation"], *(p.subjectStation)); }
    else { p.subjectStation=nullptr; }
    from_json(j["trajectoryInterceptionProbability"], (p.trajectoryInterceptionProbability));
    if (j.HasMember("trajectoryInterceptionConfidence")) { p.trajectoryInterceptionConfidence = vanetza::asn1::allocate<TrajectoryInterceptionConfidence_t>(); from_json(j["trajectoryInterceptionConfidence"], *(p.trajectoryInterceptionConfidence)); }
    else { p.trajectoryInterceptionConfidence=nullptr; }
}



/*
*   HeadingChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const HeadingChangeIndication& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("direction", to_json((p.direction), allocator), allocator);
    json.AddMember("actionDeltaTime", to_json((p.actionDeltaTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, HeadingChangeIndication& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["direction"], (p.direction));
    from_json(j["actionDeltaTime"], (p.actionDeltaTime));
}



/*
*   AccelerationChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const AccelerationChangeIndication& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("accelOrDecel", to_json((p.accelOrDecel), allocator), allocator);
    json.AddMember("actionDeltaTime", to_json((p.actionDeltaTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AccelerationChangeIndication& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["accelOrDecel"], (p.accelOrDecel));
    from_json(j["actionDeltaTime"], (p.actionDeltaTime));
}



/*
*   StabilityChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const StabilityChangeIndication& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lossProbability", to_json((p.lossProbability), allocator), allocator);
    json.AddMember("actionDeltaTime", to_json((p.actionDeltaTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, StabilityChangeIndication& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["lossProbability"], (p.lossProbability));
    from_json(j["actionDeltaTime"], (p.actionDeltaTime));
}



/*
*   LaneDataAttribute - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttribute& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == LaneDataAttribute_PR_pathEndPointAngle) {
        json.AddMember("pathEndPointAngle", to_json(p.choice.pathEndPointAngle, allocator), allocator);
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointCenter) {
        json.AddMember("laneCrownPointCenter", to_json(p.choice.laneCrownPointCenter, allocator), allocator);
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointLeft) {
        json.AddMember("laneCrownPointLeft", to_json(p.choice.laneCrownPointLeft, allocator), allocator);
    } else if (p.present == LaneDataAttribute_PR_laneCrownPointRight) {
        json.AddMember("laneCrownPointRight", to_json(p.choice.laneCrownPointRight, allocator), allocator);
    } else if (p.present == LaneDataAttribute_PR_laneAngle) {
        json.AddMember("laneAngle", to_json(p.choice.laneAngle, allocator), allocator);
    } else if (p.present == LaneDataAttribute_PR_speedLimits) {
        json.AddMember("speedLimits", to_json(p.choice.speedLimits, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, LaneDataAttribute& p) {
    if (j.HasMember("pathEndPointAngle")) {
        p.present = LaneDataAttribute_PR_pathEndPointAngle;
        from_json(j["pathEndPointAngle"], p.choice.pathEndPointAngle);
    } else if (j.HasMember("laneCrownPointCenter")) {
        p.present = LaneDataAttribute_PR_laneCrownPointCenter;
        from_json(j["laneCrownPointCenter"], p.choice.laneCrownPointCenter);
    } else if (j.HasMember("laneCrownPointLeft")) {
        p.present = LaneDataAttribute_PR_laneCrownPointLeft;
        from_json(j["laneCrownPointLeft"], p.choice.laneCrownPointLeft);
    } else if (j.HasMember("laneCrownPointRight")) {
        p.present = LaneDataAttribute_PR_laneCrownPointRight;
        from_json(j["laneCrownPointRight"], p.choice.laneCrownPointRight);
    } else if (j.HasMember("laneAngle")) {
        p.present = LaneDataAttribute_PR_laneAngle;
        from_json(j["laneAngle"], p.choice.laneAngle);
    } else if (j.HasMember("speedLimits")) {
        p.present = LaneDataAttribute_PR_speedLimits;
        from_json(j["speedLimits"], p.choice.speedLimits);
    } else {
        p.present = LaneDataAttribute_PR_NOTHING;
    }
}

/*
*   LaneDataAttributeList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttributeList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LaneDataAttribute_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, LaneDataAttributeList& p) {
    LaneDataAttributeList* p_tmp = vanetza::asn1::allocate<LaneDataAttributeList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LaneDataAttribute_t *element = vanetza::asn1::allocate<LaneDataAttribute_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeAttributeSetXY_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.localNode != 0) json.AddMember("localNode", to_json(*(p.localNode), allocator), allocator);
    if (p.disabled != 0) json.AddMember("disabled", to_json(*(p.disabled), allocator), allocator);
    if (p.enabled != 0) json.AddMember("enabled", to_json(*(p.enabled), allocator), allocator);
    if (p.data != 0) json.AddMember("data", to_json(*(p.data), allocator), allocator);
    if (p.dWidth != 0) json.AddMember("dWidth", to_json(*(p.dWidth), allocator), allocator);
    if (p.dElevation != 0) json.AddMember("dElevation", to_json(*(p.dElevation), allocator), allocator);
    return json;
}

void from_json(const Value& j, NodeAttributeSetXY_t& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("localNode")) { p.localNode = vanetza::asn1::allocate<NodeAttributeXYList_t>(); from_json(j["localNode"], *(p.localNode)); }
    else { p.localNode=nullptr; }
    if (j.HasMember("disabled")) { p.disabled = vanetza::asn1::allocate<SegmentAttributeXYList_t>(); from_json(j["disabled"], *(p.disabled)); }
    else { p.disabled=nullptr; }
    if (j.HasMember("enabled")) { p.enabled = vanetza::asn1::allocate<SegmentAttributeXYList_t>(); from_json(j["enabled"], *(p.enabled)); }
    else { p.enabled=nullptr; }
    if (j.HasMember("data")) { p.data = vanetza::asn1::allocate<LaneDataAttributeList_t>(); from_json(j["data"], *(p.data)); }
    else { p.data=nullptr; }
    if (j.HasMember("dWidth")) { p.dWidth = vanetza::asn1::allocate<Offset_B10_t>(); from_json(j["dWidth"], *(p.dWidth)); }
    else { p.dWidth=nullptr; }
    if (j.HasMember("dElevation")) { p.dElevation = vanetza::asn1::allocate<Offset_B10_t>(); from_json(j["dElevation"], *(p.dElevation)); }
    else { p.dElevation=nullptr; }
    p.regional=nullptr;
}



/*
*   OriginatingRSUContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingRSUContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == OriginatingRSUContainer_PR_intersectionReferenceId) {
        json.AddMember("intersectionReferenceId", to_json(p.choice.intersectionReferenceId, allocator), allocator);
    } else if (p.present == OriginatingRSUContainer_PR_roadSegmentReferenceId) {
        json.AddMember("roadSegmentReferenceId", to_json(p.choice.roadSegmentReferenceId, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, OriginatingRSUContainer& p) {
    if (j.HasMember("intersectionReferenceId")) {
        p.present = OriginatingRSUContainer_PR_intersectionReferenceId;
        from_json(j["intersectionReferenceId"], p.choice.intersectionReferenceId);
    } else if (j.HasMember("roadSegmentReferenceId")) {
        p.present = OriginatingRSUContainer_PR_roadSegmentReferenceId;
        from_json(j["roadSegmentReferenceId"], p.choice.roadSegmentReferenceId);
    } else {
        p.present = OriginatingRSUContainer_PR_NOTHING;
    }
}

/*
*   VehicleSensorProperties - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorProperties& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("range", to_json((p.range), allocator), allocator);
    json.AddMember("horizontalOpeningAngleStart", to_json(((p.horizontalOpeningAngleStart) == 3601) ? (p.horizontalOpeningAngleStart) : (double)(p.horizontalOpeningAngleStart) / 10.0, allocator), allocator);
    json.AddMember("horizontalOpeningAngleEnd", to_json(((p.horizontalOpeningAngleEnd) == 3601) ? (p.horizontalOpeningAngleEnd) : (double)(p.horizontalOpeningAngleEnd) / 10.0, allocator), allocator);
    if (p.verticalOpeningAngleStart != 0) json.AddMember("verticalOpeningAngleStart", to_json((*(p.verticalOpeningAngleStart) != 3601) ? (double) *(p.verticalOpeningAngleStart) / 10.0 : *(p.verticalOpeningAngleStart), allocator), allocator);
    if (p.verticalOpeningAngleEnd != 0) json.AddMember("verticalOpeningAngleEnd", to_json((*(p.verticalOpeningAngleEnd) != 3601) ? (double) *(p.verticalOpeningAngleEnd) / 10.0 : *(p.verticalOpeningAngleEnd), allocator), allocator);
    return json;
}

void from_json(const Value& j, VehicleSensorProperties& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["range"], (p.range));
    double horizontalOpeningAngleStart; from_json(j["horizontalOpeningAngleStart"], (horizontalOpeningAngleStart)); (p.horizontalOpeningAngleStart) = ((horizontalOpeningAngleStart) != 3601) ? horizontalOpeningAngleStart * 10 : horizontalOpeningAngleStart;
    double horizontalOpeningAngleEnd; from_json(j["horizontalOpeningAngleEnd"], (horizontalOpeningAngleEnd)); (p.horizontalOpeningAngleEnd) = ((horizontalOpeningAngleEnd) != 3601) ? horizontalOpeningAngleEnd * 10 : horizontalOpeningAngleEnd;
    double verticalOpeningAngleStart; if (j.HasMember("verticalOpeningAngleStart")) { p.verticalOpeningAngleStart = vanetza::asn1::allocate<CartesianAngleValue_t>(); from_json(j["verticalOpeningAngleStart"], (verticalOpeningAngleStart)); *(p.verticalOpeningAngleStart) = ((verticalOpeningAngleStart) != 3601) ? verticalOpeningAngleStart * 10 : verticalOpeningAngleStart; }
    else { p.verticalOpeningAngleStart=nullptr; }
    double verticalOpeningAngleEnd; if (j.HasMember("verticalOpeningAngleEnd")) { p.verticalOpeningAngleEnd = vanetza::asn1::allocate<CartesianAngleValue_t>(); from_json(j["verticalOpeningAngleEnd"], (verticalOpeningAngleEnd)); *(p.verticalOpeningAngleEnd) = ((verticalOpeningAngleEnd) != 3601) ? verticalOpeningAngleEnd * 10 : verticalOpeningAngleEnd; }
    else { p.verticalOpeningAngleEnd=nullptr; }
}



/*
*   ObjectDistanceWithConfidence - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDistanceWithConfidence& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json((double)(p.value) / 100.0, allocator), allocator);
    json.AddMember("confidence", to_json(((p.confidence) == 101 || (p.confidence) == 102) ? (p.confidence) : (double)(p.confidence) / 100.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ObjectDistanceWithConfidence& p) {
    p._asn_ctx.ptr = nullptr;
    double value; from_json(j["value"], (value)); (p.value) =value * 100;
    double confidence; from_json(j["confidence"], (confidence)); (p.confidence) = ((confidence) != 101 && (confidence) != 102) ? confidence * 100 : confidence;
}



/*
*   ObjectDimension - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDimension& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json((double)(p.value) / 10.0, allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ObjectDimension& p) {
    p._asn_ctx.ptr = nullptr;
    double value; from_json(j["value"], (value)); (p.value) =value * 10;
    from_json(j["confidence"], (p.confidence));
}



/*
*   CartesianAngle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CartesianAngle& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json(((p.value) == 3601) ? (p.value) : (double)(p.value) / 10.0, allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CartesianAngle& p) {
    p._asn_ctx.ptr = nullptr;
    double value; from_json(j["value"], (value)); (p.value) = ((value) != 3601) ? value * 10 : value;
    from_json(j["confidence"], (p.confidence));
}



/*
*   WGS84Angle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const WGS84Angle& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json(((p.value) == 3601) ? (p.value) : (double)(p.value) / 10.0, allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, WGS84Angle& p) {
    p._asn_ctx.ptr = nullptr;
    double value; from_json(j["value"], (value)); (p.value) = ((value) != 3601) ? value * 10 : value;
    from_json(j["confidence"], (p.confidence));
}



/*
*   SpeedExtended - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SpeedExtended& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("value", to_json(((p.value) == 16383) ? (p.value) : (double)(p.value) / 100.0, allocator), allocator);
    json.AddMember("confidence", to_json(((p.confidence) == 126 || (p.confidence) == 127) ? (p.confidence) : (double)(p.confidence) / 100.0, allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SpeedExtended& p) {
    p._asn_ctx.ptr = nullptr;
    double value; from_json(j["value"], (value)); (p.value) = ((value) != 16383) ? value * 100 : value;
    double confidence; from_json(j["confidence"], (confidence)); (p.confidence) = ((confidence) != 126 && (confidence) != 127) ? confidence * 100 : confidence;
}



/*
*   SensorIdList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorIdList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Identifier_t po = *(p.list.array[i]);
        // Value obj = to_json(po, allocator);
        json.PushBack(po, allocator);
    }
    return json;
}

void from_json(const Value& j, SensorIdList& p) {
    SensorIdList* p_tmp = vanetza::asn1::allocate<SensorIdList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Identifier_t *element = vanetza::asn1::allocate<Identifier_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TrailerData - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerData& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("refPointId", to_json((p.refPointId), allocator), allocator);
    json.AddMember("hitchPointOffset", to_json((p.hitchPointOffset), allocator), allocator);
    json.AddMember("frontOverhang", to_json((p.frontOverhang), allocator), allocator);
    json.AddMember("rearOverhang", to_json((p.rearOverhang), allocator), allocator);
    if (p.trailerWidth != 0) json.AddMember("trailerWidth", to_json((*(p.trailerWidth) != 61 && *(p.trailerWidth) != 62) ? (double) *(p.trailerWidth) / 10.0 : *(p.trailerWidth), allocator), allocator);
    if (p.hitchAngle != 0) json.AddMember("hitchAngle", to_json(*(p.hitchAngle), allocator), allocator);
    return json;
}

void from_json(const Value& j, TrailerData& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["refPointId"], (p.refPointId));
    from_json(j["hitchPointOffset"], (p.hitchPointOffset));
    from_json(j["frontOverhang"], (p.frontOverhang));
    from_json(j["rearOverhang"], (p.rearOverhang));
    double trailerWidth; if (j.HasMember("trailerWidth")) { p.trailerWidth = vanetza::asn1::allocate<VehicleWidth_t>(); from_json(j["trailerWidth"], (trailerWidth)); *(p.trailerWidth) = ((trailerWidth) != 61 && (trailerWidth) != 62) ? trailerWidth * 10 : trailerWidth; }
    else { p.trailerWidth=nullptr; }
    if (j.HasMember("hitchAngle")) { p.hitchAngle = vanetza::asn1::allocate<CartesianAngle_t>(); from_json(j["hitchAngle"], *(p.hitchAngle)); }
    else { p.hitchAngle=nullptr; }
}



/*
*   LongitudinalLanePosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const LongitudinalLanePosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("longitudinalLanePositionValue", to_json((p.longitudinalLanePositionValue), allocator), allocator);
    json.AddMember("longitudinalLanePositionConfidence", to_json((p.longitudinalLanePositionConfidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LongitudinalLanePosition& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["longitudinalLanePositionValue"], (p.longitudinalLanePositionValue));
    from_json(j["longitudinalLanePositionConfidence"], (p.longitudinalLanePositionConfidence));
}



/*
*   MatchedPosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const MatchedPosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.laneID != 0) json.AddMember("laneID", to_json(*(p.laneID), allocator), allocator);
    if (p.longitudinalLanePosition != 0) json.AddMember("longitudinalLanePosition", to_json(*(p.longitudinalLanePosition), allocator), allocator);
    return json;
}

void from_json(const Value& j, MatchedPosition& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("laneID")) { p.laneID = vanetza::asn1::allocate<LaneID_t>(); from_json(j["laneID"], *(p.laneID)); }
    else { p.laneID=nullptr; }
    if (j.HasMember("longitudinalLanePosition")) { p.longitudinalLanePosition = vanetza::asn1::allocate<LongitudinalLanePosition_t>(); from_json(j["longitudinalLanePosition"], *(p.longitudinalLanePosition)); }
    else { p.longitudinalLanePosition=nullptr; }
}



/*
*   PerceivedObjectContainerSegmentInfo - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainerSegmentInfo& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("totalMsgSegments", to_json((p.totalMsgSegments), allocator), allocator);
    json.AddMember("thisSegmentNum", to_json((p.thisSegmentNum), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PerceivedObjectContainerSegmentInfo& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["totalMsgSegments"], (p.totalMsgSegments));
    from_json(j["thisSegmentNum"], (p.thisSegmentNum));
}



/*
*   VehicleSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSubclass& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VehicleSubclass& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    from_json(j["confidence"], (p.confidence));
}



/*
*   PersonSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PersonSubclass& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PersonSubclass& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    from_json(j["confidence"], (p.confidence));
}



/*
*   AnimalSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AnimalSubclass& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AnimalSubclass& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    from_json(j["confidence"], (p.confidence));
}



/*
*   OtherSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OtherSubclass& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, OtherSubclass& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    from_json(j["confidence"], (p.confidence));
}



/*
*   NodeOffsetPointZ - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const NodeOffsetPointZ& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == NodeOffsetPointZ_PR_node_Z1) {
        json.AddMember("node-Z1", to_json(p.choice.node_Z1, allocator), allocator);
    } else if (p.present == NodeOffsetPointZ_PR_node_Z2) {
        json.AddMember("node-Z2", to_json(p.choice.node_Z2, allocator), allocator);
    } else if (p.present == NodeOffsetPointZ_PR_node_Z3) {
        json.AddMember("node-Z3", to_json(p.choice.node_Z3, allocator), allocator);
    } else if (p.present == NodeOffsetPointZ_PR_node_Z4) {
        json.AddMember("node-Z4", to_json(p.choice.node_Z4, allocator), allocator);
    } else if (p.present == NodeOffsetPointZ_PR_node_Z5) {
        json.AddMember("node-Z5", to_json(p.choice.node_Z5, allocator), allocator);
    } else if (p.present == NodeOffsetPointZ_PR_node_Z6) {
        json.AddMember("node-Z6", to_json(p.choice.node_Z6, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, NodeOffsetPointZ& p) {
    if (j.HasMember("node-Z1")) {
        p.present = NodeOffsetPointZ_PR_node_Z1;
        from_json(j["node-Z1"], p.choice.node_Z1);
    } else if (j.HasMember("node-Z2")) {
        p.present = NodeOffsetPointZ_PR_node_Z2;
        from_json(j["node-Z2"], p.choice.node_Z2);
    } else if (j.HasMember("node-Z3")) {
        p.present = NodeOffsetPointZ_PR_node_Z3;
        from_json(j["node-Z3"], p.choice.node_Z3);
    } else if (j.HasMember("node-Z4")) {
        p.present = NodeOffsetPointZ_PR_node_Z4;
        from_json(j["node-Z4"], p.choice.node_Z4);
    } else if (j.HasMember("node-Z5")) {
        p.present = NodeOffsetPointZ_PR_node_Z5;
        from_json(j["node-Z5"], p.choice.node_Z5);
    } else if (j.HasMember("node-Z6")) {
        p.present = NodeOffsetPointZ_PR_node_Z6;
        from_json(j["node-Z6"], p.choice.node_Z6);
    } else {
        p.present = NodeOffsetPointZ_PR_NOTHING;
    }
}

/*
*   ReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ReferencePosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("latitude", to_json(((p.latitude) == 900000001) ? (p.latitude) : (double)(p.latitude) / 10000000.0, allocator), allocator);
    json.AddMember("longitude", to_json(((p.longitude) == 1800000001) ? (p.longitude) : (double)(p.longitude) / 10000000.0, allocator), allocator);
    json.AddMember("positionConfidenceEllipse", to_json((p.positionConfidenceEllipse), allocator), allocator);
    json.AddMember("altitude", to_json((p.altitude), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ReferencePosition& p) {
    p._asn_ctx.ptr = nullptr;
    double latitude; from_json(j["latitude"], (latitude)); (p.latitude) = ((latitude) != 900000001) ? latitude * 10000000 : latitude;
    double longitude; from_json(j["longitude"], (longitude)); (p.longitude) = ((longitude) != 1800000001) ? longitude * 10000000 : longitude;
    from_json(j["positionConfidenceEllipse"], (p.positionConfidenceEllipse));
    from_json(j["altitude"], (p.altitude));
}



/*
*   PtActivation - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PtActivation& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("ptActivationType", to_json((p.ptActivationType), allocator), allocator);
    json.AddMember("ptActivationData", to_json((p.ptActivationData), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PtActivation& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["ptActivationType"], (p.ptActivationType));
    from_json(j["ptActivationData"], (p.ptActivationData));
}



/*
*   ClosedLanes - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ClosedLanes& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.innerhardShoulderStatus != 0) json.AddMember("innerhardShoulderStatus", to_json(*(p.innerhardShoulderStatus), allocator), allocator);
    if (p.outerhardShoulderStatus != 0) json.AddMember("outerhardShoulderStatus", to_json(*(p.outerhardShoulderStatus), allocator), allocator);
    if (p.drivingLaneStatus != 0) json.AddMember("drivingLaneStatus", to_json_DrivingLaneStatus(*(p.drivingLaneStatus), allocator), allocator);
    return json;
}

void from_json(const Value& j, ClosedLanes& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("innerhardShoulderStatus")) { p.innerhardShoulderStatus = vanetza::asn1::allocate<HardShoulderStatus_t>(); from_json(j["innerhardShoulderStatus"], *(p.innerhardShoulderStatus)); }
    else { p.innerhardShoulderStatus=nullptr; }
    if (j.HasMember("outerhardShoulderStatus")) { p.outerhardShoulderStatus = vanetza::asn1::allocate<HardShoulderStatus_t>(); from_json(j["outerhardShoulderStatus"], *(p.outerhardShoulderStatus)); }
    else { p.outerhardShoulderStatus=nullptr; }
    if (j.HasMember("drivingLaneStatus")) { p.drivingLaneStatus = vanetza::asn1::allocate<DrivingLaneStatus_t>(); from_json_DrivingLaneStatus(j["drivingLaneStatus"],*(p.drivingLaneStatus)); }
    else { p.drivingLaneStatus=nullptr; }
}



/*
*   ItineraryPath - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItineraryPath& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ReferencePosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ItineraryPath& p) {
    ItineraryPath* p_tmp = vanetza::asn1::allocate<ItineraryPath>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ReferencePosition_t *element = vanetza::asn1::allocate<ReferencePosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   EventHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventHistory& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const EventPoint_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, EventHistory& p) {
    EventHistory* p_tmp = vanetza::asn1::allocate<EventHistory>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        EventPoint_t *element = vanetza::asn1::allocate<EventPoint_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DigitalMap - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DigitalMap_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ReferencePosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DigitalMap_t& p) {
    DigitalMap_t* p_tmp = vanetza::asn1::allocate<DigitalMap_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ReferencePosition_t *element = vanetza::asn1::allocate<ReferencePosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   IntersectionState-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const IntersectionState_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.activePrioritizations != 0) json.AddMember("activePrioritizations", to_json(*(p.activePrioritizations), allocator), allocator);
    return json;
}

void from_json(const Value& j, IntersectionState_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("activePrioritizations")) { p.activePrioritizations = vanetza::asn1::allocate<PrioritizationResponseList_t>(); from_json(j["activePrioritizations"], *(p.activePrioritizations)); }
    else { p.activePrioritizations=nullptr; }
}



/*
*   NodeAttributeSet-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeAttributeSet_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.ptvRequest != 0) json.AddMember("ptvRequest", to_json(*(p.ptvRequest), allocator), allocator);
    if (p.nodeLink != 0) json.AddMember("nodeLink", to_json(*(p.nodeLink), allocator), allocator);
    if (p.node != 0) json.AddMember("node", to_json(*(p.node), allocator), allocator);
    return json;
}

void from_json(const Value& j, NodeAttributeSet_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("ptvRequest")) { p.ptvRequest = vanetza::asn1::allocate<PtvRequestType_t>(); from_json(j["ptvRequest"], *(p.ptvRequest)); }
    else { p.ptvRequest=nullptr; }
    if (j.HasMember("nodeLink")) { p.nodeLink = vanetza::asn1::allocate<NodeLink_t>(); from_json(j["nodeLink"], *(p.nodeLink)); }
    else { p.nodeLink=nullptr; }
    if (j.HasMember("node")) { p.node = vanetza::asn1::allocate<Node_t>(); from_json(j["node"], *(p.node)); }
    else { p.node=nullptr; }
}



/*
*   ItsStationPosition - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPosition_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stationID", to_json((p.stationID), allocator), allocator);
    if (p.laneID != 0) json.AddMember("laneID", to_json(*(p.laneID), allocator), allocator);
    if (p.nodeXY != 0) json.AddMember("nodeXY", to_json(*(p.nodeXY), allocator), allocator);
    if (p.timeReference != 0) json.AddMember("timeReference", to_json(*(p.timeReference), allocator), allocator);
    return json;
}

void from_json(const Value& j, ItsStationPosition_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["stationID"], (p.stationID));
    if (j.HasMember("laneID")) { p.laneID = vanetza::asn1::allocate<LaneID_t>(); from_json(j["laneID"], *(p.laneID)); }
    else { p.laneID=nullptr; }
    if (j.HasMember("nodeXY")) { p.nodeXY = vanetza::asn1::allocate<NodeOffsetPointXY_t>(); from_json(j["nodeXY"], *(p.nodeXY)); }
    else { p.nodeXY=nullptr; }
    if (j.HasMember("timeReference")) { p.timeReference = vanetza::asn1::allocate<TimeReference_t>(); from_json(j["timeReference"], *(p.timeReference)); }
    else { p.timeReference=nullptr; }
}



/*
*   ItsStationPositionList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPositionList_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ItsStationPosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ItsStationPositionList_t& p) {
    ItsStationPositionList_t* p_tmp = vanetza::asn1::allocate<ItsStationPositionList_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ItsStationPosition_t *element = vanetza::asn1::allocate<ItsStationPosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalHeadLocation - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocation_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("nodeXY", to_json((p.nodeXY), allocator), allocator);
    json.AddMember("nodeZ", to_json((p.nodeZ), allocator), allocator);
    json.AddMember("signalGroupID", to_json((p.signalGroupID), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SignalHeadLocation_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["nodeXY"], (p.nodeXY));
    from_json(j["nodeZ"], (p.nodeZ));
    from_json(j["signalGroupID"], (p.signalGroupID));
}



/*
*   SignalHeadLocationList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocationList_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SignalHeadLocation_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SignalHeadLocationList_t& p) {
    SignalHeadLocationList_t* p_tmp = vanetza::asn1::allocate<SignalHeadLocationList_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SignalHeadLocation_t *element = vanetza::asn1::allocate<SignalHeadLocation_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ConnectingLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectingLane& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lane", to_json((p.lane), allocator), allocator);
    if (p.maneuver != 0) json.AddMember("maneuver", to_json_AllowedManeuvers(*(p.maneuver), allocator), allocator);
    return json;
}

void from_json(const Value& j, ConnectingLane& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["lane"], (p.lane));
    if (j.HasMember("maneuver")) { p.maneuver = vanetza::asn1::allocate<AllowedManeuvers_t>(); from_json_AllowedManeuvers(j["maneuver"],*(p.maneuver)); }
    else { p.maneuver=nullptr; }
}



/*
*   Connection - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Connection& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("connectingLane", to_json((p.connectingLane), allocator), allocator);
    if (p.remoteIntersection != 0) json.AddMember("remoteIntersection", to_json(*(p.remoteIntersection), allocator), allocator);
    if (p.signalGroup != 0) json.AddMember("signalGroup", to_json(*(p.signalGroup), allocator), allocator);
    if (p.userClass != 0) json.AddMember("userClass", to_json(*(p.userClass), allocator), allocator);
    if (p.connectionID != 0) json.AddMember("connectionID", to_json(*(p.connectionID), allocator), allocator);
    return json;
}

void from_json(const Value& j, Connection& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["connectingLane"], (p.connectingLane));
    if (j.HasMember("remoteIntersection")) { p.remoteIntersection = vanetza::asn1::allocate<IntersectionReferenceID_t>(); from_json(j["remoteIntersection"], *(p.remoteIntersection)); }
    else { p.remoteIntersection=nullptr; }
    if (j.HasMember("signalGroup")) { p.signalGroup = vanetza::asn1::allocate<SignalGroupID_t>(); from_json(j["signalGroup"], *(p.signalGroup)); }
    else { p.signalGroup=nullptr; }
    if (j.HasMember("userClass")) { p.userClass = vanetza::asn1::allocate<RestrictionClassID_t>(); from_json(j["userClass"], *(p.userClass)); }
    else { p.userClass=nullptr; }
    if (j.HasMember("connectionID")) { p.connectionID = vanetza::asn1::allocate<LaneConnectionID_t>(); from_json(j["connectionID"], *(p.connectionID)); }
    else { p.connectionID=nullptr; }
}



/*
*   FullPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const FullPositionVector& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("long", to_json(((p.Long) == 1800000001) ? (p.Long) : (double)(p.Long) / 10000000.0, allocator), allocator);
    json.AddMember("lat", to_json(((p.lat) == 900000001) ? (p.lat) : (double)(p.lat) / 10000000.0, allocator), allocator);
    if (p.utcTime != 0) json.AddMember("utcTime", to_json(*(p.utcTime), allocator), allocator);
    if (p.elevation != 0) json.AddMember("elevation", to_json(*(p.elevation), allocator), allocator);
    if (p.heading != 0) json.AddMember("heading", to_json(*(p.heading), allocator), allocator);
    if (p.speed != 0) json.AddMember("speed", to_json(*(p.speed), allocator), allocator);
    if (p.posAccuracy != 0) json.AddMember("posAccuracy", to_json(*(p.posAccuracy), allocator), allocator);
    if (p.timeConfidence != 0) json.AddMember("timeConfidence", to_json(*(p.timeConfidence), allocator), allocator);
    if (p.posConfidence != 0) json.AddMember("posConfidence", to_json(*(p.posConfidence), allocator), allocator);
    if (p.speedConfidence != 0) json.AddMember("speedConfidence", to_json(*(p.speedConfidence), allocator), allocator);
    return json;
}

void from_json(const Value& j, FullPositionVector& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("utcTime")) { p.utcTime = vanetza::asn1::allocate<DDateTime_t>(); from_json(j["utcTime"], *(p.utcTime)); }
    else { p.utcTime=nullptr; }
    double Long; from_json(j["long"], (Long)); (p.Long) = ((Long) != 1800000001) ? Long * 10000000 : Long;
    double lat; from_json(j["lat"], (lat)); (p.lat) = ((lat) != 900000001) ? lat * 10000000 : lat;
    if (j.HasMember("elevation")) { p.elevation = vanetza::asn1::allocate<Elevation_t>(); from_json(j["elevation"], *(p.elevation)); }
    else { p.elevation=nullptr; }
    if (j.HasMember("heading")) { p.heading = vanetza::asn1::allocate<HeadingIso_t>(); from_json(j["heading"], *(p.heading)); }
    else { p.heading=nullptr; }
    if (j.HasMember("speed")) { p.speed = vanetza::asn1::allocate<TransmissionAndSpeed_t>(); from_json(j["speed"], *(p.speed)); }
    else { p.speed=nullptr; }
    if (j.HasMember("posAccuracy")) { p.posAccuracy = vanetza::asn1::allocate<PositionalAccuracy_t>(); from_json(j["posAccuracy"], *(p.posAccuracy)); }
    else { p.posAccuracy=nullptr; }
    if (j.HasMember("timeConfidence")) { p.timeConfidence = vanetza::asn1::allocate<TimeConfidence_t>(); from_json(j["timeConfidence"], *(p.timeConfidence)); }
    else { p.timeConfidence=nullptr; }
    if (j.HasMember("posConfidence")) { p.posConfidence = vanetza::asn1::allocate<PositionConfidenceSet_t>(); from_json(j["posConfidence"], *(p.posConfidence)); }
    else { p.posConfidence=nullptr; }
    if (j.HasMember("speedConfidence")) { p.speedConfidence = vanetza::asn1::allocate<SpeedandHeadingIsoandThrottleConfidence_t>(); from_json(j["speedConfidence"], *(p.speedConfidence)); }
    else { p.speedConfidence=nullptr; }
}



/*
*   LaneTypeAttributes - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneTypeAttributes& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == LaneTypeAttributes_PR_vehicle) {
        json.AddMember("vehicle", to_json_LaneAttributes_Vehicle(p.choice.vehicle, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_crosswalk) {
        json.AddMember("crosswalk", to_json_LaneAttributes_Crosswalk(p.choice.crosswalk, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_bikeLane) {
        json.AddMember("bikeLane", to_json_LaneAttributes_Bike(p.choice.bikeLane, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_sidewalk) {
        json.AddMember("sidewalk", to_json_LaneAttributes_Sidewalk(p.choice.sidewalk, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_median) {
        json.AddMember("median", to_json_LaneAttributes_Barrier(p.choice.median, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_striping) {
        json.AddMember("striping", to_json_LaneAttributes_Striping(p.choice.striping, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_trackedVehicle) {
        json.AddMember("trackedVehicle", to_json_LaneAttributes_TrackedVehicle(p.choice.trackedVehicle, allocator), allocator);
    } else if (p.present == LaneTypeAttributes_PR_parking) {
        json.AddMember("parking", to_json_LaneAttributes_Parking(p.choice.parking, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, LaneTypeAttributes& p) {
    if (j.HasMember("vehicle")) {
        p.present = LaneTypeAttributes_PR_vehicle;
        from_json_LaneAttributes_Vehicle(j["vehicle"], p.choice.vehicle);
    } else if (j.HasMember("crosswalk")) {
        p.present = LaneTypeAttributes_PR_crosswalk;
        from_json_LaneAttributes_Crosswalk(j["crosswalk"], p.choice.crosswalk);
    } else if (j.HasMember("bikeLane")) {
        p.present = LaneTypeAttributes_PR_bikeLane;
        from_json_LaneAttributes_Bike(j["bikeLane"], p.choice.bikeLane);
    } else if (j.HasMember("sidewalk")) {
        p.present = LaneTypeAttributes_PR_sidewalk;
        from_json_LaneAttributes_Sidewalk(j["sidewalk"], p.choice.sidewalk);
    } else if (j.HasMember("median")) {
        p.present = LaneTypeAttributes_PR_median;
        from_json_LaneAttributes_Barrier(j["median"], p.choice.median);
    } else if (j.HasMember("striping")) {
        p.present = LaneTypeAttributes_PR_striping;
        from_json_LaneAttributes_Striping(j["striping"], p.choice.striping);
    } else if (j.HasMember("trackedVehicle")) {
        p.present = LaneTypeAttributes_PR_trackedVehicle;
        from_json_LaneAttributes_TrackedVehicle(j["trackedVehicle"], p.choice.trackedVehicle);
    } else if (j.HasMember("parking")) {
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

Value to_json(const MovementEvent& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("eventState", to_json((p.eventState), allocator), allocator);
    if (p.timing != 0) json.AddMember("timing", to_json(*(p.timing), allocator), allocator);
    if (p.speeds != 0) json.AddMember("speeds", to_json(*(p.speeds), allocator), allocator);
    return json;
}

void from_json(const Value& j, MovementEvent& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["eventState"], (p.eventState));
    if (j.HasMember("timing")) { p.timing = vanetza::asn1::allocate<TimeChangeDetails_t>(); from_json(j["timing"], *(p.timing)); }
    else { p.timing=nullptr; }
    if (j.HasMember("speeds")) { p.speeds = vanetza::asn1::allocate<AdvisorySpeedList_t>(); from_json(j["speeds"], *(p.speeds)); }
    else { p.speeds=nullptr; }
    p.regional=nullptr;
}



/*
*   MovementEventList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementEventList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const MovementEvent_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, MovementEventList& p) {
    MovementEventList* p_tmp = vanetza::asn1::allocate<MovementEventList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        MovementEvent_t *element = vanetza::asn1::allocate<MovementEvent_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   MovementState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementState& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("signalGroup", to_json((p.signalGroup), allocator), allocator);
    json.AddMember("state-time-speed", to_json((p.state_time_speed), allocator), allocator);
    if (p.maneuverAssistList != 0) json.AddMember("maneuverAssistList", to_json(*(p.maneuverAssistList), allocator), allocator);
    return json;
}

void from_json(const Value& j, MovementState& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["signalGroup"], (p.signalGroup));
    from_json(j["state-time-speed"], (p.state_time_speed));
    if (j.HasMember("maneuverAssistList")) { p.maneuverAssistList = vanetza::asn1::allocate<ManeuverAssistList_t>(); from_json(j["maneuverAssistList"], *(p.maneuverAssistList)); }
    else { p.maneuverAssistList=nullptr; }
    p.movementName=nullptr;
    p.regional=nullptr;
}



/*
*   NodeXY - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeXY_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("delta", to_json((p.delta), allocator), allocator);
    if (p.attributes != 0) json.AddMember("attributes", to_json(*(p.attributes), allocator), allocator);
    return json;
}

void from_json(const Value& j, NodeXY_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["delta"], (p.delta));
    if (j.HasMember("attributes")) { p.attributes = vanetza::asn1::allocate<NodeAttributeSetXY_t>(); from_json(j["attributes"], *(p.attributes)); }
    else { p.attributes=nullptr; }
}



/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeSetXY& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const NodeXY_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, NodeSetXY& p) {
    NodeSetXY* p_tmp = vanetza::asn1::allocate<NodeSetXY>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        NodeXY_t *element = vanetza::asn1::allocate<NodeXY_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RequestorPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorPositionVector& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("position", to_json((p.position), allocator), allocator);
    if (p.heading != 0) json.AddMember("heading", to_json(*(p.heading), allocator), allocator);
    if (p.speed != 0) json.AddMember("speed", to_json(*(p.speed), allocator), allocator);
    return json;
}

void from_json(const Value& j, RequestorPositionVector& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["position"], (p.position));
    if (j.HasMember("heading")) { p.heading = vanetza::asn1::allocate<Angle_t>(); from_json(j["heading"], *(p.heading)); }
    else { p.heading=nullptr; }
    if (j.HasMember("speed")) { p.speed = vanetza::asn1::allocate<TransmissionAndSpeed_t>(); from_json(j["speed"], *(p.speed)); }
    else { p.speed=nullptr; }
}



/*
*   RestrictionClassAssignment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassAssignment& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("users", to_json((p.users), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RestrictionClassAssignment& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["users"], (p.users));
}



/*
*   RestrictionClassList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RestrictionClassAssignment_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RestrictionClassList& p) {
    RestrictionClassList* p_tmp = vanetza::asn1::allocate<RestrictionClassList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RestrictionClassAssignment_t *element = vanetza::asn1::allocate<RestrictionClassAssignment_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RTCMheader - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMheader& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("status", to_json_GNSSstatus((p.status), allocator), allocator);
    json.AddMember("offsetSet", to_json((p.offsetSet), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RTCMheader& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_GNSSstatus(j["status"],(p.status));
    from_json(j["offsetSet"], (p.offsetSet));
}



/*
*   RTCMmessageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMmessageList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RTCMmessage_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RTCMmessageList& p) {
    RTCMmessageList* p_tmp = vanetza::asn1::allocate<RTCMmessageList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RTCMmessage_t *element = vanetza::asn1::allocate<RTCMmessage_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalRequesterInfo - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequesterInfo& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("request", to_json((p.request), allocator), allocator);
    json.AddMember("sequenceNumber", to_json((p.sequenceNumber), allocator), allocator);
    if (p.role != 0) json.AddMember("role", to_json(*(p.role), allocator), allocator);
    if (p.typeData != 0) json.AddMember("typeData", to_json(*(p.typeData), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalRequesterInfo& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["request"], (p.request));
    from_json(j["sequenceNumber"], (p.sequenceNumber));
    if (j.HasMember("role")) { p.role = vanetza::asn1::allocate<BasicVehicleRole_t>(); from_json(j["role"], *(p.role)); }
    else { p.role=nullptr; }
    if (j.HasMember("typeData")) { p.typeData = vanetza::asn1::allocate<RequestorType_t>(); from_json(j["typeData"], *(p.typeData)); }
    else { p.typeData=nullptr; }
}



/*
*   SignalRequestList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SignalRequestPackage_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SignalRequestList& p) {
    SignalRequestList* p_tmp = vanetza::asn1::allocate<SignalRequestList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SignalRequestPackage_t *element = vanetza::asn1::allocate<SignalRequestPackage_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalStatusPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("inboundOn", to_json((p.inboundOn), allocator), allocator);
    json.AddMember("status", to_json((p.status), allocator), allocator);
    if (p.requester != 0) json.AddMember("requester", to_json(*(p.requester), allocator), allocator);
    if (p.outboundOn != 0) json.AddMember("outboundOn", to_json(*(p.outboundOn), allocator), allocator);
    if (p.minute != 0) json.AddMember("minute", to_json(*(p.minute), allocator), allocator);
    if (p.second != 0) json.AddMember("second", to_json(*(p.second), allocator), allocator);
    if (p.duration != 0) json.AddMember("duration", to_json(*(p.duration), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalStatusPackage& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("requester")) { p.requester = vanetza::asn1::allocate<SignalRequesterInfo_t>(); from_json(j["requester"], *(p.requester)); }
    else { p.requester=nullptr; }
    from_json(j["inboundOn"], (p.inboundOn));
    if (j.HasMember("outboundOn")) { p.outboundOn = vanetza::asn1::allocate<IntersectionAccessPoint_t>(); from_json(j["outboundOn"], *(p.outboundOn)); }
    else { p.outboundOn=nullptr; }
    if (j.HasMember("minute")) { p.minute = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["minute"], *(p.minute)); }
    else { p.minute=nullptr; }
    if (j.HasMember("second")) { p.second = vanetza::asn1::allocate<DSecond_t>(); from_json(j["second"], *(p.second)); }
    else { p.second=nullptr; }
    if (j.HasMember("duration")) { p.duration = vanetza::asn1::allocate<DSecond_t>(); from_json(j["duration"], *(p.duration)); }
    else { p.duration=nullptr; }
    from_json(j["status"], (p.status));
    p.regional=nullptr;
}



/*
*   CS1 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS1& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("countryCode", to_json_CountryCode((p.countryCode), allocator), allocator);
    json.AddMember("issuerIdentifier", to_json((p.issuerIdentifier), allocator), allocator);
    json.AddMember("serviceNumber", to_json_ServiceNumber((p.serviceNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS1& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_CountryCode(j["countryCode"],(p.countryCode));
    from_json(j["issuerIdentifier"], (p.issuerIdentifier));
    from_json_ServiceNumber(j["serviceNumber"],(p.serviceNumber));
}



/*
*   CS2 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS2& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("manufacturerIdentifier", to_json((p.manufacturerIdentifier), allocator), allocator);
    json.AddMember("serviceNumber", to_json_ServiceNumber((p.serviceNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS2& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["manufacturerIdentifier"], (p.manufacturerIdentifier));
    from_json_ServiceNumber(j["serviceNumber"],(p.serviceNumber));
}



/*
*   CS3 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS3& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("startTime", to_json((p.startTime), allocator), allocator);
    json.AddMember("stopTime", to_json((p.stopTime), allocator), allocator);
    json.AddMember("geographLimit", to_json_GeoGraphicalLimit((p.geographLimit), allocator), allocator);
    json.AddMember("serviceAppLimit", to_json_ServiceApplicationLimit((p.serviceAppLimit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS3& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["startTime"], (p.startTime));
    from_json(j["stopTime"], (p.stopTime));
    from_json_GeoGraphicalLimit(j["geographLimit"],(p.geographLimit));
    from_json_ServiceApplicationLimit(j["serviceAppLimit"],(p.serviceAppLimit));
}



/*
*   CS4 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS4& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("countryCode", to_json_CountryCode((p.countryCode), allocator), allocator);
    json.AddMember("alphabetIndicator", to_json((p.alphabetIndicator), allocator), allocator);
    json.AddMember("licPlateNumber", to_json((p.licPlateNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS4& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_CountryCode(j["countryCode"],(p.countryCode));
    from_json(j["alphabetIndicator"], (p.alphabetIndicator));
    from_json(j["licPlateNumber"], (p.licPlateNumber));
}



/*
*   CS8 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS8& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("countryCode", to_json_CountryCode((p.countryCode), allocator), allocator);
    json.AddMember("taxCode", to_json((p.taxCode), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CS8& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_CountryCode(j["countryCode"],(p.countryCode));
    from_json(j["taxCode"], (p.taxCode));
    
}



/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__month-day - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("dateRangeStartMonthDay", to_json((p.dateRangeStartMonthDay), allocator), allocator);
    json.AddMember("dateRangeEndMonthDay", to_json((p.dateRangeEndMonthDay), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["dateRangeStartMonthDay"], (p.dateRangeStartMonthDay));
    from_json(j["dateRangeEndMonthDay"], (p.dateRangeEndMonthDay));
}



/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__hourMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("timeRangeStartTime", to_json((p.timeRangeStartTime), allocator), allocator);
    json.AddMember("timeRangeEndTime", to_json((p.timeRangeEndTime), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["timeRangeStartTime"], (p.timeRangeStartTime));
    from_json(j["timeRangeEndTime"], (p.timeRangeEndTime));
}



/*
*   InternationalSign-applicablePeriod - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.year != 0) json.AddMember("year", to_json(*(p.year), allocator), allocator);
    if (p.month_day != 0) json.AddMember("month-day", to_json(*(p.month_day), allocator), allocator);
    if (p.repeatingPeriodDayTypes != 0) json.AddMember("repeatingPeriodDayTypes", to_json_RepeatingPeriodDayTypes(*(p.repeatingPeriodDayTypes), allocator), allocator);
    if (p.hourMinutes != 0) json.AddMember("hourMinutes", to_json(*(p.hourMinutes), allocator), allocator);
    if (p.dateRangeOfWeek != 0) json.AddMember("dateRangeOfWeek", to_json_DayOfWeek(*(p.dateRangeOfWeek), allocator), allocator);
    if (p.durationHourMinute != 0) json.AddMember("durationHourMinute", to_json(*(p.durationHourMinute), allocator), allocator);
    return json;
}

void from_json(const Value& j, InternationalSign_applicablePeriod& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("year")) { p.year = vanetza::asn1::allocate<InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year>(); from_json(j["year"], *(p.year)); }
    else { p.year=nullptr; }
    if (j.HasMember("month-day")) { p.month_day = vanetza::asn1::allocate<InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day>(); from_json(j["month-day"], *(p.month_day)); }
    else { p.month_day=nullptr; }
    if (j.HasMember("repeatingPeriodDayTypes")) { p.repeatingPeriodDayTypes = vanetza::asn1::allocate<RepeatingPeriodDayTypes_t>(); from_json_RepeatingPeriodDayTypes(j["repeatingPeriodDayTypes"],*(p.repeatingPeriodDayTypes)); }
    else { p.repeatingPeriodDayTypes=nullptr; }
    if (j.HasMember("hourMinutes")) { p.hourMinutes = vanetza::asn1::allocate<InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes>(); from_json(j["hourMinutes"], *(p.hourMinutes)); }
    else { p.hourMinutes=nullptr; }
    if (j.HasMember("dateRangeOfWeek")) { p.dateRangeOfWeek = vanetza::asn1::allocate<DayOfWeek_t>(); from_json_DayOfWeek(j["dateRangeOfWeek"],*(p.dateRangeOfWeek)); }
    else { p.dateRangeOfWeek=nullptr; }
    if (j.HasMember("durationHourMinute")) { p.durationHourMinute = vanetza::asn1::allocate<HoursMinutes_t>(); from_json(j["durationHourMinute"], *(p.durationHourMinute)); }
    else { p.durationHourMinute=nullptr; }
}



/*
*   InternationalSign-applicableVehicleDimensions - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicableVehicleDimensions& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.vehicleHeight != 0) json.AddMember("vehicleHeight", to_json(*(p.vehicleHeight), allocator), allocator);
    if (p.vehicleWidth != 0) json.AddMember("vehicleWidth", to_json(*(p.vehicleWidth), allocator), allocator);
    if (p.vehicleLength != 0) json.AddMember("vehicleLength", to_json(*(p.vehicleLength), allocator), allocator);
    if (p.vehicleWeight != 0) json.AddMember("vehicleWeight", to_json(*(p.vehicleWeight), allocator), allocator);
    return json;
}

void from_json(const Value& j, InternationalSign_applicableVehicleDimensions& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("vehicleHeight")) { p.vehicleHeight = vanetza::asn1::allocate<Distance_t>(); from_json(j["vehicleHeight"], *(p.vehicleHeight)); }
    else { p.vehicleHeight=nullptr; }
    if (j.HasMember("vehicleWidth")) { p.vehicleWidth = vanetza::asn1::allocate<Distance_t>(); from_json(j["vehicleWidth"], *(p.vehicleWidth)); }
    else { p.vehicleWidth=nullptr; }
    if (j.HasMember("vehicleLength")) { p.vehicleLength = vanetza::asn1::allocate<Distance_t>(); from_json(j["vehicleLength"], *(p.vehicleLength)); }
    else { p.vehicleLength=nullptr; }
    if (j.HasMember("vehicleWeight")) { p.vehicleWeight = vanetza::asn1::allocate<Weight_t>(); from_json(j["vehicleWeight"], *(p.vehicleWeight)); }
    else { p.vehicleWeight=nullptr; }
}



/*
*   InternationalSign-section - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_section& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.startingPointLength != 0) json.AddMember("startingPointLength", to_json(*(p.startingPointLength), allocator), allocator);
    if (p.continuityLength != 0) json.AddMember("continuityLength", to_json(*(p.continuityLength), allocator), allocator);
    return json;
}

void from_json(const Value& j, InternationalSign_section& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("startingPointLength")) { p.startingPointLength = vanetza::asn1::allocate<Distance_t>(); from_json(j["startingPointLength"], *(p.startingPointLength)); }
    else { p.startingPointLength=nullptr; }
    if (j.HasMember("continuityLength")) { p.continuityLength = vanetza::asn1::allocate<Distance_t>(); from_json(j["continuityLength"], *(p.continuityLength)); }
    else { p.continuityLength=nullptr; }
}



/*
*   DDD-IO - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("arrowDirection", to_json((p.arrowDirection), allocator), allocator);
    if (p.destPlace != 0) json.AddMember("destPlace", to_json(*(p.destPlace), allocator), allocator);
    if (p.destRoad != 0) json.AddMember("destRoad", to_json(*(p.destRoad), allocator), allocator);
    if (p.roadNumberIdentifier != 0) json.AddMember("roadNumberIdentifier", to_json(*(p.roadNumberIdentifier), allocator), allocator);
    if (p.streetName != 0) json.AddMember("streetName", to_json(*(p.streetName), allocator), allocator);
    if (p.streetNameText != 0) json.AddMember("streetNameText", to_json(*(p.streetNameText), allocator), allocator);
    if (p.distanceToDivergingPoint != 0) json.AddMember("distanceToDivergingPoint", to_json(*(p.distanceToDivergingPoint), allocator), allocator);
    if (p.distanceToDestinationPlace != 0) json.AddMember("distanceToDestinationPlace", to_json(*(p.distanceToDestinationPlace), allocator), allocator);
    return json;
}

void from_json(const Value& j, DDD_IO& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["arrowDirection"], (p.arrowDirection));
    if (j.HasMember("destPlace")) { p.destPlace = vanetza::asn1::allocate<DestinationPlaces_t>(); from_json(j["destPlace"], *(p.destPlace)); }
    else { p.destPlace=nullptr; }
    if (j.HasMember("destRoad")) { p.destRoad = vanetza::asn1::allocate<DestinationRoads_t>(); from_json(j["destRoad"], *(p.destRoad)); }
    else { p.destRoad=nullptr; }
    if (j.HasMember("roadNumberIdentifier")) { p.roadNumberIdentifier = vanetza::asn1::allocate<long>(); from_json(j["roadNumberIdentifier"], *(p.roadNumberIdentifier)); }
    else { p.roadNumberIdentifier=nullptr; }
    if (j.HasMember("streetName")) { p.streetName = vanetza::asn1::allocate<long>(); from_json(j["streetName"], *(p.streetName)); }
    else { p.streetName=nullptr; }
    if (j.HasMember("streetNameText")) { p.streetNameText = vanetza::asn1::allocate<UTF8String_t>(); from_json(j["streetNameText"], *(p.streetNameText)); }
    else { p.streetNameText=nullptr; }
    if (j.HasMember("distanceToDivergingPoint")) { p.distanceToDivergingPoint = vanetza::asn1::allocate<DistanceOrDuration_t>(); from_json(j["distanceToDivergingPoint"], *(p.distanceToDivergingPoint)); }
    else { p.distanceToDivergingPoint=nullptr; }
    if (j.HasMember("distanceToDestinationPlace")) { p.distanceToDestinationPlace = vanetza::asn1::allocate<DistanceOrDuration_t>(); from_json(j["distanceToDestinationPlace"], *(p.distanceToDestinationPlace)); }
    else { p.distanceToDestinationPlace=nullptr; }
}



/*
*   CreditRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRs_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("creditResult", to_json((p.creditResult), allocator), allocator);
    json.AddMember("creditAuthenticator", to_json((p.creditAuthenticator), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CreditRs_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["creditResult"], (p.creditResult));
    from_json(j["creditAuthenticator"], (p.creditAuthenticator));
}



/*
*   DebitRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRs_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("debitResult", to_json((p.debitResult), allocator), allocator);
    json.AddMember("debitAuthenticator", to_json((p.debitAuthenticator), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DebitRs_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["debitResult"], (p.debitResult));
    from_json(j["debitAuthenticator"], (p.debitAuthenticator));
}



/*
*   ContractValidity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ContractValidity_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("contractRestrictions", to_json((p.contractRestrictions), allocator), allocator);
    json.AddMember("contractExpiryDate", to_json((p.contractExpiryDate), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ContractValidity_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["contractRestrictions"], (p.contractRestrictions));
    from_json(j["contractExpiryDate"], (p.contractExpiryDate));
}



/*
*   EFC-ContextMark - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EFC_ContextMark_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("contractProvider", to_json((p.contractProvider), allocator), allocator);
    json.AddMember("typeOfContract", to_json((p.typeOfContract), allocator), allocator);
    json.AddMember("contextVersion", to_json((p.contextVersion), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, EFC_ContextMark_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["contractProvider"], (p.contractProvider));
    from_json(j["typeOfContract"], (p.typeOfContract));
    from_json(j["contextVersion"], (p.contextVersion));
}



/*
*   PaymentFee - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentFee_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("paymentFeeAmount", to_json((p.paymentFeeAmount), allocator), allocator);
    json.AddMember("paymentFeeUnit", to_json((p.paymentFeeUnit), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PaymentFee_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["paymentFeeAmount"], (p.paymentFeeAmount));
    from_json(j["paymentFeeUnit"], (p.paymentFeeUnit));
}



/*
*   PaymentMeans - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentMeans_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("personalAccountNumber", to_json((p.personalAccountNumber), allocator), allocator);
    json.AddMember("paymentMeansExpiryDate", to_json((p.paymentMeansExpiryDate), allocator), allocator);
    json.AddMember("pamentMeansUsageControl", to_json((p.pamentMeansUsageControl), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, PaymentMeans_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["personalAccountNumber"], (p.personalAccountNumber));
    from_json(j["paymentMeansExpiryDate"], (p.paymentMeansExpiryDate));
    from_json(j["pamentMeansUsageControl"], (p.pamentMeansUsageControl));
}



/*
*   ReceiptData - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptData_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sessionTime", to_json((p.sessionTime), allocator), allocator);
    json.AddMember("sessionServiceProvider", to_json((p.sessionServiceProvider), allocator), allocator);
    json.AddMember("locationOfStation", to_json((p.locationOfStation), allocator), allocator);
    json.AddMember("sessionType", to_json((p.sessionType), allocator), allocator);
    json.AddMember("sessionResult", to_json((p.sessionResult), allocator), allocator);
    json.AddMember("sessionTariffClass", to_json((p.sessionTariffClass), allocator), allocator);
    json.AddMember("sessionClaimedClass", to_json((p.sessionClaimedClass), allocator), allocator);
    json.AddMember("sessionFee", to_json((p.sessionFee), allocator), allocator);
    json.AddMember("sessionContractProvider", to_json((p.sessionContractProvider), allocator), allocator);
    json.AddMember("sessionTypeOfContract", to_json((p.sessionTypeOfContract), allocator), allocator);
    json.AddMember("sessionContextVersion", to_json((p.sessionContextVersion), allocator), allocator);
    json.AddMember("receiptDataAuthenticator", to_json((p.receiptDataAuthenticator), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ReceiptData_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sessionTime"], (p.sessionTime));
    from_json(j["sessionServiceProvider"], (p.sessionServiceProvider));
    from_json(j["locationOfStation"], (p.locationOfStation));
    from_json(j["sessionType"], (p.sessionType));
    from_json(j["sessionResult"], (p.sessionResult));
    from_json(j["sessionTariffClass"], (p.sessionTariffClass));
    from_json(j["sessionClaimedClass"], (p.sessionClaimedClass));
    from_json(j["sessionFee"], (p.sessionFee));
    from_json(j["sessionContractProvider"], (p.sessionContractProvider));
    from_json(j["sessionTypeOfContract"], (p.sessionTypeOfContract));
    from_json(j["sessionContextVersion"], (p.sessionContextVersion));
    from_json(j["receiptDataAuthenticator"], (p.receiptDataAuthenticator));
    
}



/*
*   ReceiptFinancialPart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptFinancialPart_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("personalAccountNumber", to_json((p.personalAccountNumber), allocator), allocator);
    json.AddMember("sessionPaymentFee", to_json((p.sessionPaymentFee), allocator), allocator);
    json.AddMember("sessionCurrentBalance", to_json((p.sessionCurrentBalance), allocator), allocator);
    json.AddMember("receiptFinancialSerialNumber", to_json((p.receiptFinancialSerialNumber), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ReceiptFinancialPart_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["personalAccountNumber"], (p.personalAccountNumber));
    from_json(j["sessionPaymentFee"], (p.sessionPaymentFee));
    from_json(j["sessionCurrentBalance"], (p.sessionCurrentBalance));
    from_json(j["receiptFinancialSerialNumber"], (p.receiptFinancialSerialNumber));
}



/*
*   ReceiptServicePart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptServicePart_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sessionTime", to_json((p.sessionTime), allocator), allocator);
    json.AddMember("sessionServiceProvider", to_json((p.sessionServiceProvider), allocator), allocator);
    json.AddMember("stationLocation", to_json((p.stationLocation), allocator), allocator);
    json.AddMember("typeOfSession", to_json((p.typeOfSession), allocator), allocator);
    json.AddMember("sessionResultOperational", to_json((p.sessionResultOperational), allocator), allocator);
    json.AddMember("sessionResultFinancial", to_json((p.sessionResultFinancial), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ReceiptServicePart_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sessionTime"], (p.sessionTime));
    from_json(j["sessionServiceProvider"], (p.sessionServiceProvider));
    from_json(j["stationLocation"], (p.stationLocation));
    from_json(j["typeOfSession"], (p.typeOfSession));
    from_json(j["sessionResultOperational"], (p.sessionResultOperational));
    from_json(j["sessionResultFinancial"], (p.sessionResultFinancial));
    
}



/*
*   EfcDsrcApplication_TrailerCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EfcDsrcApplication_TrailerCharacteristics_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("trailerDetails", to_json((p.trailerDetails), allocator), allocator);
    json.AddMember("trailerMaxLadenWeight", to_json((p.trailerMaxLadenWeight), allocator), allocator);
    json.AddMember("trailerWeightUnladen", to_json((p.trailerWeightUnladen), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, EfcDsrcApplication_TrailerCharacteristics_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["trailerDetails"], (p.trailerDetails));
    from_json(j["trailerMaxLadenWeight"], (p.trailerMaxLadenWeight));
    from_json(j["trailerWeightUnladen"], (p.trailerWeightUnladen));
}



/*
*   Ext1 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext1& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == Ext1_PR_content) {
        json.AddMember("content", to_json(p.choice.content, allocator), allocator);
    } else if (p.present == Ext1_PR_extension) {
        json.AddMember("extension", to_json(p.choice.extension, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, Ext1& p) {
    if (j.HasMember("content")) {
        p.present = Ext1_PR_content;
        from_json(j["content"], p.choice.content);
    } else if (j.HasMember("extension")) {
        p.present = Ext1_PR_extension;
        from_json(j["extension"], p.choice.extension);
    } else {
        p.present = Ext1_PR_NOTHING;
    }
}

/*
*   IviManagementContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviManagementContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("serviceProviderId", to_json((p.serviceProviderId), allocator), allocator);
    json.AddMember("iviIdentificationNumber", to_json((p.iviIdentificationNumber), allocator), allocator);
    json.AddMember("iviStatus", to_json((p.iviStatus), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.validFrom != 0) json.AddMember("validFrom", to_json(*(p.validFrom), allocator), allocator);
    if (p.validTo != 0) json.AddMember("validTo", to_json(*(p.validTo), allocator), allocator);
    if (p.connectedIviStructures != 0) json.AddMember("connectedIviStructures", to_json(*(p.connectedIviStructures), allocator), allocator);
    if (p.connectedDenms != 0) json.AddMember("connectedDenms", to_json(*(p.connectedDenms), allocator), allocator);
    return json;
}

void from_json(const Value& j, IviManagementContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["serviceProviderId"], (p.serviceProviderId));
    from_json(j["iviIdentificationNumber"], (p.iviIdentificationNumber));
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<TimestampIts_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    if (j.HasMember("validFrom")) { p.validFrom = vanetza::asn1::allocate<TimestampIts_t>(); from_json(j["validFrom"], *(p.validFrom)); }
    else { p.validFrom=nullptr; }
    if (j.HasMember("validTo")) { p.validTo = vanetza::asn1::allocate<TimestampIts_t>(); from_json(j["validTo"], *(p.validTo)); }
    else { p.validTo=nullptr; }
    if (j.HasMember("connectedIviStructures")) { p.connectedIviStructures = vanetza::asn1::allocate<IviIdentificationNumbers_t>(); from_json(j["connectedIviStructures"], *(p.connectedIviStructures)); }
    else { p.connectedIviStructures=nullptr; }
    from_json(j["iviStatus"], (p.iviStatus));
    if (j.HasMember("connectedDenms")) { p.connectedDenms = vanetza::asn1::allocate<ConnectedDenms_t>(); from_json(j["connectedDenms"], *(p.connectedDenms)); }
    else { p.connectedDenms=nullptr; }
}



/*
*   RscPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RscPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("relevanceZoneIds", to_json((p.relevanceZoneIds), allocator), allocator);
    if (p.detectionZoneIds != 0) json.AddMember("detectionZoneIds", to_json(*(p.detectionZoneIds), allocator), allocator);
    if (p.direction != 0) json.AddMember("direction", to_json(*(p.direction), allocator), allocator);
    if (p.roadSurfaceStaticCharacteristics != 0) json.AddMember("roadSurfaceStaticCharacteristics", to_json(*(p.roadSurfaceStaticCharacteristics), allocator), allocator);
    if (p.roadSurfaceDynamicCharacteristics != 0) json.AddMember("roadSurfaceDynamicCharacteristics", to_json(*(p.roadSurfaceDynamicCharacteristics), allocator), allocator);
    return json;
}

void from_json(const Value& j, RscPart& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("detectionZoneIds")) { p.detectionZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["detectionZoneIds"], *(p.detectionZoneIds)); }
    else { p.detectionZoneIds=nullptr; }
    from_json(j["relevanceZoneIds"], (p.relevanceZoneIds));
    if (j.HasMember("direction")) { p.direction = vanetza::asn1::allocate<Direction_t>(); from_json(j["direction"], *(p.direction)); }
    else { p.direction=nullptr; }
    if (j.HasMember("roadSurfaceStaticCharacteristics")) { p.roadSurfaceStaticCharacteristics = vanetza::asn1::allocate<RoadSurfaceStaticCharacteristics_t>(); from_json(j["roadSurfaceStaticCharacteristics"], *(p.roadSurfaceStaticCharacteristics)); }
    else { p.roadSurfaceStaticCharacteristics=nullptr; }
    if (j.HasMember("roadSurfaceDynamicCharacteristics")) { p.roadSurfaceDynamicCharacteristics = vanetza::asn1::allocate<RoadSurfaceDynamicCharacteristics_t>(); from_json(j["roadSurfaceDynamicCharacteristics"], *(p.roadSurfaceDynamicCharacteristics)); }
    else { p.roadSurfaceDynamicCharacteristics=nullptr; }
}



/*
*   MlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("zoneId", to_json((p.zoneId), allocator), allocator);
    if (p.laneIds != 0) json.AddMember("laneIds", to_json(*(p.laneIds), allocator), allocator);
    return json;
}

void from_json(const Value& j, MlcPart& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["zoneId"], (p.zoneId));
    if (j.HasMember("laneIds")) { p.laneIds = vanetza::asn1::allocate<LaneIds_t>(); from_json(j["laneIds"], *(p.laneIds)); }
    else { p.laneIds=nullptr; }
}



/*
*   AbsolutePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositions& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const AbsolutePosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, AbsolutePositions& p) {
    AbsolutePositions* p_tmp = vanetza::asn1::allocate<AbsolutePositions>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        AbsolutePosition_t *element = vanetza::asn1::allocate<AbsolutePosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AbsolutePositionsWAltitude - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionsWAltitude& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const AbsolutePositionWAltitude_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, AbsolutePositionsWAltitude& p) {
    AbsolutePositionsWAltitude* p_tmp = vanetza::asn1::allocate<AbsolutePositionsWAltitude>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        AbsolutePositionWAltitude_t *element = vanetza::asn1::allocate<AbsolutePositionWAltitude_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DeltaPositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPositions& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const DeltaPosition_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DeltaPositions& p) {
    DeltaPositions* p_tmp = vanetza::asn1::allocate<DeltaPositions>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        DeltaPosition_t *element = vanetza::asn1::allocate<DeltaPosition_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ConstraintTextLines1 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines1& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Text_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ConstraintTextLines1& p) {
    ConstraintTextLines1* p_tmp = vanetza::asn1::allocate<ConstraintTextLines1>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Text_t *element = vanetza::asn1::allocate<Text_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ConstraintTextLines2 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines2& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Text_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ConstraintTextLines2& p) {
    ConstraintTextLines2* p_tmp = vanetza::asn1::allocate<ConstraintTextLines2>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Text_t *element = vanetza::asn1::allocate<Text_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LayoutComponents - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponents& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LayoutComponent_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, LayoutComponents& p) {
    LayoutComponents* p_tmp = vanetza::asn1::allocate<LayoutComponents>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LayoutComponent_t *element = vanetza::asn1::allocate<LayoutComponent_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TextLines - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextLines& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Text_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TextLines& p) {
    TextLines* p_tmp = vanetza::asn1::allocate<TextLines>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Text_t *element = vanetza::asn1::allocate<Text_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TrailerCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsFixValuesList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VehicleCharacteristicsFixValues_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TrailerCharacteristicsFixValuesList& p) {
    TrailerCharacteristicsFixValuesList* p_tmp = vanetza::asn1::allocate<TrailerCharacteristicsFixValuesList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VehicleCharacteristicsFixValues_t *element = vanetza::asn1::allocate<VehicleCharacteristicsFixValues_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TrailerCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsRangesList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VehicleCharacteristicsRanges_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TrailerCharacteristicsRangesList& p) {
    TrailerCharacteristicsRangesList* p_tmp = vanetza::asn1::allocate<TrailerCharacteristicsRangesList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VehicleCharacteristicsRanges_t *element = vanetza::asn1::allocate<VehicleCharacteristicsRanges_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VehicleCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValuesList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VehicleCharacteristicsFixValues_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsFixValuesList& p) {
    VehicleCharacteristicsFixValuesList* p_tmp = vanetza::asn1::allocate<VehicleCharacteristicsFixValuesList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VehicleCharacteristicsFixValues_t *element = vanetza::asn1::allocate<VehicleCharacteristicsFixValues_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VehicleCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRangesList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VehicleCharacteristicsRanges_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsRangesList& p) {
    VehicleCharacteristicsRangesList* p_tmp = vanetza::asn1::allocate<VehicleCharacteristicsRangesList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VehicleCharacteristicsRanges_t *element = vanetza::asn1::allocate<VehicleCharacteristicsRanges_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ValidityPeriods - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ValidityPeriods& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const InternationalSign_applicablePeriod_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ValidityPeriods& p) {
    ValidityPeriods* p_tmp = vanetza::asn1::allocate<ValidityPeriods>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        InternationalSign_applicablePeriod_t *element = vanetza::asn1::allocate<InternationalSign_applicablePeriod_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PolygonalLine - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PolygonalLine& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == PolygonalLine_PR_deltaPositions) {
        json.AddMember("deltaPositions", to_json(p.choice.deltaPositions, allocator), allocator);
    } else if (p.present == PolygonalLine_PR_deltaPositionsWithAltitude) {
        json.AddMember("deltaPositionsWithAltitude", to_json(p.choice.deltaPositionsWithAltitude, allocator), allocator);
    } else if (p.present == PolygonalLine_PR_absolutePositions) {
        json.AddMember("absolutePositions", to_json(p.choice.absolutePositions, allocator), allocator);
    } else if (p.present == PolygonalLine_PR_absolutePositionsWithAltitude) {
        json.AddMember("absolutePositionsWithAltitude", to_json(p.choice.absolutePositionsWithAltitude, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, PolygonalLine& p) {
    if (j.HasMember("deltaPositions")) {
        p.present = PolygonalLine_PR_deltaPositions;
        from_json(j["deltaPositions"], p.choice.deltaPositions);
    } else if (j.HasMember("deltaPositionsWithAltitude")) {
        p.present = PolygonalLine_PR_deltaPositionsWithAltitude;
        from_json(j["deltaPositionsWithAltitude"], p.choice.deltaPositionsWithAltitude);
    } else if (j.HasMember("absolutePositions")) {
        p.present = PolygonalLine_PR_absolutePositions;
        from_json(j["absolutePositions"], p.choice.absolutePositions);
    } else if (j.HasMember("absolutePositionsWithAltitude")) {
        p.present = PolygonalLine_PR_absolutePositionsWithAltitude;
        from_json(j["absolutePositionsWithAltitude"], p.choice.absolutePositionsWithAltitude);
    } else {
        p.present = PolygonalLine_PR_NOTHING;
    }
}

/*
*   Segment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Segment& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("line", to_json((p.line), allocator), allocator);
    if (p.laneWidth != 0) json.AddMember("laneWidth", to_json(*(p.laneWidth), allocator), allocator);
    return json;
}

void from_json(const Value& j, Segment& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["line"], (p.line));
    if (j.HasMember("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<IviLaneWidth_t>(); from_json(j["laneWidth"], *(p.laneWidth)); }
    else { p.laneWidth=nullptr; }
}



/*
*   TractorCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TractorCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.equalTo != 0) json.AddMember("equalTo", to_json(*(p.equalTo), allocator), allocator);
    if (p.notEqualTo != 0) json.AddMember("notEqualTo", to_json(*(p.notEqualTo), allocator), allocator);
    if (p.ranges != 0) json.AddMember("ranges", to_json(*(p.ranges), allocator), allocator);
    return json;
}

void from_json(const Value& j, TractorCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("equalTo")) { p.equalTo = vanetza::asn1::allocate<VehicleCharacteristicsFixValuesList_t>(); from_json(j["equalTo"], *(p.equalTo)); }
    else { p.equalTo=nullptr; }
    if (j.HasMember("notEqualTo")) { p.notEqualTo = vanetza::asn1::allocate<VehicleCharacteristicsFixValuesList_t>(); from_json(j["notEqualTo"], *(p.notEqualTo)); }
    else { p.notEqualTo=nullptr; }
    if (j.HasMember("ranges")) { p.ranges = vanetza::asn1::allocate<VehicleCharacteristicsRangesList_t>(); from_json(j["ranges"], *(p.ranges)); }
    else { p.ranges=nullptr; }
}



/*
*   IVI_TrailerCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IVI_TrailerCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.equalTo != 0) json.AddMember("equalTo", to_json(*(p.equalTo), allocator), allocator);
    if (p.notEqualTo != 0) json.AddMember("notEqualTo", to_json(*(p.notEqualTo), allocator), allocator);
    if (p.ranges != 0) json.AddMember("ranges", to_json(*(p.ranges), allocator), allocator);
    return json;
}

void from_json(const Value& j, IVI_TrailerCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("equalTo")) { p.equalTo = vanetza::asn1::allocate<TrailerCharacteristicsFixValuesList_t>(); from_json(j["equalTo"], *(p.equalTo)); }
    else { p.equalTo=nullptr; }
    if (j.HasMember("notEqualTo")) { p.notEqualTo = vanetza::asn1::allocate<TrailerCharacteristicsFixValuesList_t>(); from_json(j["notEqualTo"], *(p.notEqualTo)); }
    else { p.notEqualTo=nullptr; }
    if (j.HasMember("ranges")) { p.ranges = vanetza::asn1::allocate<TrailerCharacteristicsRangesList_t>(); from_json(j["ranges"], *(p.ranges)); }
    else { p.ranges=nullptr; }
}



/*
*   VcCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VcCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("roadSignClass", to_json((p.roadSignClass), allocator), allocator);
    json.AddMember("roadSignCode", to_json((p.roadSignCode), allocator), allocator);
    json.AddMember("vcOption", to_json((p.vcOption), allocator), allocator);
    if (p.validity != 0) json.AddMember("validity", to_json(*(p.validity), allocator), allocator);
    if (p.value != 0) json.AddMember("value", to_json(*(p.value), allocator), allocator);
    if (p.unit != 0) json.AddMember("unit", to_json(*(p.unit), allocator), allocator);
    return json;
}

void from_json(const Value& j, VcCode& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["roadSignClass"], (p.roadSignClass));
    from_json(j["roadSignCode"], (p.roadSignCode));
    from_json(j["vcOption"], (p.vcOption));
    if (j.HasMember("validity")) { p.validity = vanetza::asn1::allocate<ValidityPeriods_t>(); from_json(j["validity"], *(p.validity)); }
    else { p.validity=nullptr; }
    if (j.HasMember("value")) { p.value = vanetza::asn1::allocate<long>(); from_json(j["value"], *(p.value)); }
    else { p.value=nullptr; }
    if (j.HasMember("unit")) { p.unit = vanetza::asn1::allocate<RSCUnit_t>(); from_json(j["unit"], *(p.unit)); }
    else { p.unit=nullptr; }
}



/*
*   Zone - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Zone& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == Zone_PR_segment) {
        json.AddMember("segment", to_json(p.choice.segment, allocator), allocator);
    } else if (p.present == Zone_PR_area) {
        json.AddMember("area", to_json(p.choice.area, allocator), allocator);
    } else if (p.present == Zone_PR_computedSegment) {
        json.AddMember("computedSegment", to_json(p.choice.computedSegment, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, Zone& p) {
    if (j.HasMember("segment")) {
        p.present = Zone_PR_segment;
        from_json(j["segment"], p.choice.segment);
    } else if (j.HasMember("area")) {
        p.present = Zone_PR_area;
        from_json(j["area"], p.choice.area);
    } else if (j.HasMember("computedSegment")) {
        p.present = Zone_PR_computedSegment;
        from_json(j["computedSegment"], p.choice.computedSegment);
    } else {
        p.present = Zone_PR_NOTHING;
    }
}

/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const HighFrequencyContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == HighFrequencyContainer_PR_basicVehicleContainerHighFrequency) {
        json.AddMember("basicVehicleContainerHighFrequency", to_json(p.choice.basicVehicleContainerHighFrequency, allocator), allocator);
    } else if (p.present == HighFrequencyContainer_PR_rsuContainerHighFrequency) {
        json.AddMember("rsuContainerHighFrequency", to_json(p.choice.rsuContainerHighFrequency, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, HighFrequencyContainer& p) {
    if (j.HasMember("basicVehicleContainerHighFrequency")) {
        p.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
        from_json(j["basicVehicleContainerHighFrequency"], p.choice.basicVehicleContainerHighFrequency);
    } else if (j.HasMember("rsuContainerHighFrequency")) {
        p.present = HighFrequencyContainer_PR_rsuContainerHighFrequency;
        from_json(j["rsuContainerHighFrequency"], p.choice.rsuContainerHighFrequency);
    } else {
        p.present = HighFrequencyContainer_PR_NOTHING;
    }
}

/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const LowFrequencyContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == LowFrequencyContainer_PR_basicVehicleContainerLowFrequency) {
        json.AddMember("basicVehicleContainerLowFrequency", to_json(p.choice.basicVehicleContainerLowFrequency, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, LowFrequencyContainer& p) {
    if (j.HasMember("basicVehicleContainerLowFrequency")) {
        p.present = LowFrequencyContainer_PR_basicVehicleContainerLowFrequency;
        from_json(j["basicVehicleContainerLowFrequency"], p.choice.basicVehicleContainerLowFrequency);
    } else {
        p.present = LowFrequencyContainer_PR_NOTHING;
    }
}

/*
*   BasicContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stationType", to_json((p.stationType), allocator), allocator);
    json.AddMember("referencePosition", to_json((p.referencePosition), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, BasicContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["stationType"], (p.stationType));
    from_json(j["referencePosition"], (p.referencePosition));
}



/*
*   PublicTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const PublicTransportContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("embarkationStatus", to_json((p.embarkationStatus), allocator), allocator);
    if (p.ptActivation != 0) json.AddMember("ptActivation", to_json(*(p.ptActivation), allocator), allocator);
    return json;
}

void from_json(const Value& j, PublicTransportContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["embarkationStatus"], (p.embarkationStatus));
    if (j.HasMember("ptActivation")) { p.ptActivation = vanetza::asn1::allocate<PtActivation_t>(); from_json(j["ptActivation"], *(p.ptActivation)); }
    else { p.ptActivation=nullptr; }
}



/*
*   RoadWorksContainerBasic - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RoadWorksContainerBasic& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse((p.lightBarSirenInUse), allocator), allocator);
    if (p.roadworksSubCauseCode != 0) json.AddMember("roadworksSubCauseCode", to_json(*(p.roadworksSubCauseCode), allocator), allocator);
    if (p.closedLanes != 0) json.AddMember("closedLanes", to_json(*(p.closedLanes), allocator), allocator);
    return json;
}

void from_json(const Value& j, RoadWorksContainerBasic& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("roadworksSubCauseCode")) { p.roadworksSubCauseCode = vanetza::asn1::allocate<RoadworksSubCauseCode_t>(); from_json(j["roadworksSubCauseCode"], *(p.roadworksSubCauseCode)); }
    else { p.roadworksSubCauseCode=nullptr; }
    from_json_LightBarSirenInUse(j["lightBarSirenInUse"],(p.lightBarSirenInUse));
    if (j.HasMember("closedLanes")) { p.closedLanes = vanetza::asn1::allocate<ClosedLanes_t>(); from_json(j["closedLanes"], *(p.closedLanes)); }
    else { p.closedLanes=nullptr; }
}



/*
*   ManagementContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ManagementContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("actionID", to_json((p.actionID), allocator), allocator);
    json.AddMember("detectionTime", to_json((p.detectionTime), allocator), allocator);
    json.AddMember("referenceTime", to_json((p.referenceTime), allocator), allocator);
    json.AddMember("eventPosition", to_json((p.eventPosition), allocator), allocator);
    json.AddMember("stationType", to_json((p.stationType), allocator), allocator);
    if (p.termination != 0) json.AddMember("termination", to_json(*(p.termination), allocator), allocator);
    if (p.relevanceDistance != 0) json.AddMember("relevanceDistance", to_json(*(p.relevanceDistance), allocator), allocator);
    if (p.relevanceTrafficDirection != 0) json.AddMember("relevanceTrafficDirection", to_json(*(p.relevanceTrafficDirection), allocator), allocator);
    if (p.validityDuration != 0) json.AddMember("validityDuration", to_json(*(p.validityDuration), allocator), allocator);
    if (p.transmissionInterval != 0) json.AddMember("transmissionInterval", to_json(*(p.transmissionInterval), allocator), allocator);
    return json;
}

void from_json(const Value& j, ManagementContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["actionID"], (p.actionID));
    from_json(j["detectionTime"], (p.detectionTime));
    from_json(j["referenceTime"], (p.referenceTime));
    if (j.HasMember("termination")) { p.termination = vanetza::asn1::allocate<Termination_t>(); from_json(j["termination"], *(p.termination)); }
    else { p.termination=nullptr; }
    from_json(j["eventPosition"], (p.eventPosition));
    if (j.HasMember("relevanceDistance")) { p.relevanceDistance = vanetza::asn1::allocate<RelevanceDistance_t>(); from_json(j["relevanceDistance"], *(p.relevanceDistance)); }
    else { p.relevanceDistance=nullptr; }
    if (j.HasMember("relevanceTrafficDirection")) { p.relevanceTrafficDirection = vanetza::asn1::allocate<RelevanceTrafficDirection_t>(); from_json(j["relevanceTrafficDirection"], *(p.relevanceTrafficDirection)); }
    else { p.relevanceTrafficDirection=nullptr; }
    if (j.HasMember("validityDuration")) { p.validityDuration = vanetza::asn1::allocate<ValidityDuration_t>(); from_json(j["validityDuration"], *(p.validityDuration)); }
    else { p.validityDuration=nullptr; }
    if (j.HasMember("transmissionInterval")) { p.transmissionInterval = vanetza::asn1::allocate<TransmissionInterval_t>(); from_json(j["transmissionInterval"], *(p.transmissionInterval)); }
    else { p.transmissionInterval=nullptr; }
    from_json(j["stationType"], (p.stationType));
}



/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const SituationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("informationQuality", to_json((p.informationQuality), allocator), allocator);
    json.AddMember("eventType", to_json((p.eventType), allocator), allocator);
    if (p.linkedCause != 0) json.AddMember("linkedCause", to_json(*(p.linkedCause), allocator), allocator);
    if (p.eventHistory != 0) json.AddMember("eventHistory", to_json(*(p.eventHistory), allocator), allocator);
    return json;
}

void from_json(const Value& j, SituationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["informationQuality"], (p.informationQuality));
    from_json(j["eventType"], (p.eventType));
    if (j.HasMember("linkedCause")) { p.linkedCause = vanetza::asn1::allocate<CauseCode_t>(); from_json(j["linkedCause"], *(p.linkedCause)); }
    else { p.linkedCause=nullptr; }
    if (j.HasMember("eventHistory")) { p.eventHistory = vanetza::asn1::allocate<EventHistory_t>(); from_json(j["eventHistory"], *(p.eventHistory)); }
    else { p.eventHistory=nullptr; }
}



/*
*   RoadWorksContainerExtended - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const RoadWorksContainerExtended& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.lightBarSirenInUse != 0) json.AddMember("lightBarSirenInUse", to_json_LightBarSirenInUse(*(p.lightBarSirenInUse), allocator), allocator);
    if (p.closedLanes != 0) json.AddMember("closedLanes", to_json(*(p.closedLanes), allocator), allocator);
    if (p.restriction != 0) json.AddMember("restriction", to_json(*(p.restriction), allocator), allocator);
    if (p.speedLimit != 0) json.AddMember("speedLimit", to_json(*(p.speedLimit), allocator), allocator);
    if (p.incidentIndication != 0) json.AddMember("incidentIndication", to_json(*(p.incidentIndication), allocator), allocator);
    if (p.recommendedPath != 0) json.AddMember("recommendedPath", to_json(*(p.recommendedPath), allocator), allocator);
    if (p.startingPointSpeedLimit != 0) json.AddMember("startingPointSpeedLimit", to_json(*(p.startingPointSpeedLimit), allocator), allocator);
    if (p.trafficFlowRule != 0) json.AddMember("trafficFlowRule", to_json(*(p.trafficFlowRule), allocator), allocator);
    if (p.referenceDenms != 0) json.AddMember("referenceDenms", to_json(*(p.referenceDenms), allocator), allocator);
    return json;
}

void from_json(const Value& j, RoadWorksContainerExtended& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("lightBarSirenInUse")) { p.lightBarSirenInUse = vanetza::asn1::allocate<LightBarSirenInUse_t>(); from_json_LightBarSirenInUse(j["lightBarSirenInUse"],*(p.lightBarSirenInUse)); }
    else { p.lightBarSirenInUse=nullptr; }
    if (j.HasMember("closedLanes")) { p.closedLanes = vanetza::asn1::allocate<ClosedLanes_t>(); from_json(j["closedLanes"], *(p.closedLanes)); }
    else { p.closedLanes=nullptr; }
    if (j.HasMember("restriction")) { p.restriction = vanetza::asn1::allocate<RestrictedTypes_t>(); from_json(j["restriction"], *(p.restriction)); }
    else { p.restriction=nullptr; }
    if (j.HasMember("speedLimit")) { p.speedLimit = vanetza::asn1::allocate<SpeedLimit_t>(); from_json(j["speedLimit"], *(p.speedLimit)); }
    else { p.speedLimit=nullptr; }
    if (j.HasMember("incidentIndication")) { p.incidentIndication = vanetza::asn1::allocate<CauseCode_t>(); from_json(j["incidentIndication"], *(p.incidentIndication)); }
    else { p.incidentIndication=nullptr; }
    if (j.HasMember("recommendedPath")) { p.recommendedPath = vanetza::asn1::allocate<ItineraryPath_t>(); from_json(j["recommendedPath"], *(p.recommendedPath)); }
    else { p.recommendedPath=nullptr; }
    if (j.HasMember("startingPointSpeedLimit")) { p.startingPointSpeedLimit = vanetza::asn1::allocate<DeltaReferencePosition_t>(); from_json(j["startingPointSpeedLimit"], *(p.startingPointSpeedLimit)); }
    else { p.startingPointSpeedLimit=nullptr; }
    if (j.HasMember("trafficFlowRule")) { p.trafficFlowRule = vanetza::asn1::allocate<TrafficRule_t>(); from_json(j["trafficFlowRule"], *(p.trafficFlowRule)); }
    else { p.trafficFlowRule=nullptr; }
    if (j.HasMember("referenceDenms")) { p.referenceDenms = vanetza::asn1::allocate<ReferenceDenms_t>(); from_json(j["referenceDenms"], *(p.referenceDenms)); }
    else { p.referenceDenms=nullptr; }
}



/*
*   AlacarteContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const AlacarteContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.lanePosition != 0) json.AddMember("lanePosition", to_json(*(p.lanePosition), allocator), allocator);
    if (p.impactReduction != 0) json.AddMember("impactReduction", to_json(*(p.impactReduction), allocator), allocator);
    if (p.externalTemperature != 0) json.AddMember("externalTemperature", to_json(*(p.externalTemperature), allocator), allocator);
    if (p.roadWorks != 0) json.AddMember("roadWorks", to_json(*(p.roadWorks), allocator), allocator);
    if (p.positioningSolution != 0) json.AddMember("positioningSolution", to_json(*(p.positioningSolution), allocator), allocator);
    if (p.stationaryVehicle != 0) json.AddMember("stationaryVehicle", to_json(*(p.stationaryVehicle), allocator), allocator);
    return json;
}

void from_json(const Value& j, AlacarteContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("lanePosition")) { p.lanePosition = vanetza::asn1::allocate<LanePosition_t>(); from_json(j["lanePosition"], *(p.lanePosition)); }
    else { p.lanePosition=nullptr; }
    if (j.HasMember("impactReduction")) { p.impactReduction = vanetza::asn1::allocate<ImpactReductionContainer_t>(); from_json(j["impactReduction"], *(p.impactReduction)); }
    else { p.impactReduction=nullptr; }
    if (j.HasMember("externalTemperature")) { p.externalTemperature = vanetza::asn1::allocate<ITS_Container_Temperature_t>(); from_json(j["externalTemperature"], *(p.externalTemperature)); }
    else { p.externalTemperature=nullptr; }
    if (j.HasMember("roadWorks")) { p.roadWorks = vanetza::asn1::allocate<RoadWorksContainerExtended_t>(); from_json(j["roadWorks"], *(p.roadWorks)); }
    else { p.roadWorks=nullptr; }
    if (j.HasMember("positioningSolution")) { p.positioningSolution = vanetza::asn1::allocate<PositioningSolutionType_t>(); from_json(j["positioningSolution"], *(p.positioningSolution)); }
    else { p.positioningSolution=nullptr; }
    if (j.HasMember("stationaryVehicle")) { p.stationaryVehicle = vanetza::asn1::allocate<StationaryVehicleContainer_t>(); from_json(j["stationaryVehicle"], *(p.stationaryVehicle)); }
    else { p.stationaryVehicle=nullptr; }
}



/*
*   NonIslandLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const NonIslandLanePosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == NonIslandLanePosition_PR_offRoadLanePosition) {
        json.AddMember("offRoadLanePosition", to_json(p.choice.offRoadLanePosition, allocator), allocator);
    } else if (p.present == NonIslandLanePosition_PR_vehicularLanePosition) {
        json.AddMember("vehicularLanePosition", to_json(p.choice.vehicularLanePosition, allocator), allocator);
    } else if (p.present == NonIslandLanePosition_PR_mapPosition) {
        json.AddMember("mapPosition", to_json(p.choice.mapPosition, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, NonIslandLanePosition& p) {
    if (j.HasMember("offRoadLanePosition")) {
        p.present = NonIslandLanePosition_PR_offRoadLanePosition;
        from_json(j["offRoadLanePosition"], p.choice.offRoadLanePosition);
    } else if (j.HasMember("vehicularLanePosition")) {
        p.present = NonIslandLanePosition_PR_vehicularLanePosition;
        from_json(j["vehicularLanePosition"], p.choice.vehicularLanePosition);
    } else if (j.HasMember("mapPosition")) {
        p.present = NonIslandLanePosition_PR_mapPosition;
        from_json(j["mapPosition"], p.choice.mapPosition);
    } else {
        p.present = NonIslandLanePosition_PR_NOTHING;
    }
}

/*
*   VruExteriorLights - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruExteriorLights& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("vruSpecific", to_json_VruSpecificExteriorLights((p.vruSpecific), allocator), allocator);
    json.AddMember("vehicular", to_json_ExteriorLights((p.vehicular), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VruExteriorLights& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_VruSpecificExteriorLights(j["vruSpecific"],(p.vruSpecific));
    from_json_ExteriorLights(j["vehicular"],(p.vehicular));
}



/*
*   VruClusterOperationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterOperationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.clusterJoinInfo != 0) json.AddMember("clusterJoinInfo", to_json(*(p.clusterJoinInfo), allocator), allocator);
    if (p.clusterLeaveInfo != 0) json.AddMember("clusterLeaveInfo", to_json(*(p.clusterLeaveInfo), allocator), allocator);
    if (p.clusterBreakupInfo != 0) json.AddMember("clusterBreakupInfo", to_json(*(p.clusterBreakupInfo), allocator), allocator);
    if (p.clusterIdChangeTimeInfo != 0) json.AddMember("clusterIdChangeTimeInfo", to_json(*(p.clusterIdChangeTimeInfo), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruClusterOperationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("clusterJoinInfo")) { p.clusterJoinInfo = vanetza::asn1::allocate<ClusterJoinInfo_t>(); from_json(j["clusterJoinInfo"], *(p.clusterJoinInfo)); }
    else { p.clusterJoinInfo=nullptr; }
    if (j.HasMember("clusterLeaveInfo")) { p.clusterLeaveInfo = vanetza::asn1::allocate<ClusterLeaveInfo_t>(); from_json(j["clusterLeaveInfo"], *(p.clusterLeaveInfo)); }
    else { p.clusterLeaveInfo=nullptr; }
    if (j.HasMember("clusterBreakupInfo")) { p.clusterBreakupInfo = vanetza::asn1::allocate<ClusterBreakupInfo_t>(); from_json(j["clusterBreakupInfo"], *(p.clusterBreakupInfo)); }
    else { p.clusterBreakupInfo=nullptr; }
    if (j.HasMember("clusterIdChangeTimeInfo")) { p.clusterIdChangeTimeInfo = vanetza::asn1::allocate<VruClusterOpTimestamp_t>(); from_json(j["clusterIdChangeTimeInfo"], *(p.clusterIdChangeTimeInfo)); }
    else { p.clusterIdChangeTimeInfo=nullptr; }
}



/*
*   VruPathPoint - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruPathPoint& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pathPosition", to_json((p.pathPosition), allocator), allocator);
    if (p.pathDeltaTime != 0) json.AddMember("pathDeltaTime", to_json(*(p.pathDeltaTime), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruPathPoint& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["pathPosition"], (p.pathPosition));
    if (j.HasMember("pathDeltaTime")) { p.pathDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>(); from_json(j["pathDeltaTime"], *(p.pathDeltaTime)); }
    else { p.pathDeltaTime=nullptr; }
}



/*
*   SequenceOfVruSafeDistanceIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruSafeDistanceIndication& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VruSafeDistanceIndication_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SequenceOfVruSafeDistanceIndication& p) {
    SequenceOfVruSafeDistanceIndication* p_tmp = vanetza::asn1::allocate<SequenceOfVruSafeDistanceIndication>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VruSafeDistanceIndication_t *element = vanetza::asn1::allocate<VruSafeDistanceIndication_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SequenceOfTrajectoryInterceptionIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfTrajectoryInterceptionIndication& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const TrajectoryInterceptionIndication_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SequenceOfTrajectoryInterceptionIndication& p) {
    SequenceOfTrajectoryInterceptionIndication* p_tmp = vanetza::asn1::allocate<SequenceOfTrajectoryInterceptionIndication>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        TrajectoryInterceptionIndication_t *element = vanetza::asn1::allocate<TrajectoryInterceptionIndication_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CpmManagementContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmManagementContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("stationType", to_json((p.stationType), allocator), allocator);
    json.AddMember("referencePosition", to_json((p.referencePosition), allocator), allocator);
    if (p.perceivedObjectContainerSegmentInfo != 0) json.AddMember("perceivedObjectContainerSegmentInfo", to_json(*(p.perceivedObjectContainerSegmentInfo), allocator), allocator);
    return json;
}

void from_json(const Value& j, CpmManagementContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["stationType"], (p.stationType));
    if (j.HasMember("perceivedObjectContainerSegmentInfo")) { p.perceivedObjectContainerSegmentInfo = vanetza::asn1::allocate<PerceivedObjectContainerSegmentInfo_t>(); from_json(j["perceivedObjectContainerSegmentInfo"], *(p.perceivedObjectContainerSegmentInfo)); }
    else { p.perceivedObjectContainerSegmentInfo=nullptr; }
    from_json(j["referencePosition"], (p.referencePosition));
}



/*
*   VehicleSensorPropertyList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorPropertyList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VehicleSensorProperties_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleSensorPropertyList& p) {
    VehicleSensorPropertyList* p_tmp = vanetza::asn1::allocate<VehicleSensorPropertyList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VehicleSensorProperties_t *element = vanetza::asn1::allocate<VehicleSensorProperties_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TrailerDataContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerDataContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const TrailerData_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TrailerDataContainer& p) {
    TrailerDataContainer* p_tmp = vanetza::asn1::allocate<TrailerDataContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        TrailerData_t *element = vanetza::asn1::allocate<TrailerData_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass::ObjectClass__class& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ObjectClass__class_PR::ObjectClass__class_PR_vehicle) {
        json.AddMember("vehicle", to_json(p.choice.vehicle, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR::ObjectClass__class_PR_person) {
        json.AddMember("person", to_json(p.choice.person, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR::ObjectClass__class_PR_animal) {
        json.AddMember("animal", to_json(p.choice.animal, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR::ObjectClass__class_PR_other) {
        json.AddMember("other", to_json(p.choice.other, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ObjectClass::ObjectClass__class& p) {
    if (j.HasMember("vehicle")) {
        p.present = ObjectClass__class_PR::ObjectClass__class_PR_vehicle;
        from_json(j["vehicle"], p.choice.vehicle);
    } else if (j.HasMember("person")) {
        p.present = ObjectClass__class_PR::ObjectClass__class_PR_person;
        from_json(j["person"], p.choice.person);
    } else if (j.HasMember("animal")) {
        p.present = ObjectClass__class_PR::ObjectClass__class_PR_animal;
        from_json(j["animal"], p.choice.animal);
    } else if (j.HasMember("other")) {
        p.present = ObjectClass__class_PR::ObjectClass__class_PR_other;
        from_json(j["other"], p.choice.other);
    } else {
        p.present = ObjectClass__class_PR::ObjectClass__class_PR_NOTHING;
    }
}

/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("confidence", to_json((p.confidence), allocator), allocator);
    json.AddMember("class", to_json((p.Class), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ObjectClass_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["confidence"], (p.confidence));
    from_json(j["class"], (p.Class));
}



/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OffsetPoint& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("nodeOffsetPointxy", to_json((p.nodeOffsetPointxy), allocator), allocator);
    if (p.nodeOffsetPointZ != 0) json.AddMember("nodeOffsetPointZ", to_json(*(p.nodeOffsetPointZ), allocator), allocator);
    return json;
}

void from_json(const Value& j, OffsetPoint& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["nodeOffsetPointxy"], (p.nodeOffsetPointxy));
    if (j.HasMember("nodeOffsetPointZ")) { p.nodeOffsetPointZ = vanetza::asn1::allocate<NodeOffsetPointZ_t>(); from_json(j["nodeOffsetPointZ"], *(p.nodeOffsetPointZ)); }
    else { p.nodeOffsetPointZ=nullptr; }
}



/*
*   ConnectionManeuverAssist-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.itsStationPosition != 0) json.AddMember("itsStationPosition", to_json(*(p.itsStationPosition), allocator), allocator);
    return json;
}

void from_json(const Value& j, ConnectionManeuverAssist_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("itsStationPosition")) { p.itsStationPosition = vanetza::asn1::allocate<ItsStationPositionList_t>(); from_json(j["itsStationPosition"], *(p.itsStationPosition)); }
    else { p.itsStationPosition=nullptr; }
}



/*
*   ConnectionTrajectory-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionTrajectory_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("nodes", to_json((p.nodes), allocator), allocator);
    json.AddMember("connectionID", to_json((p.connectionID), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, ConnectionTrajectory_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["nodes"], (p.nodes));
    from_json(j["connectionID"], (p.connectionID));
}



/*
*   MapData-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MapData_addGrpC& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.signalHeadLocations != 0) json.AddMember("signalHeadLocations", to_json(*(p.signalHeadLocations), allocator), allocator);
    return json;
}

void from_json(const Value& j, MapData_addGrpC& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("signalHeadLocations")) { p.signalHeadLocations = vanetza::asn1::allocate<SignalHeadLocationList_t>(); from_json(j["signalHeadLocations"], *(p.signalHeadLocations)); }
    else { p.signalHeadLocations=nullptr; }
}



/*
*   RTCMcorrections - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMcorrections& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("msgCnt", to_json((p.msgCnt), allocator), allocator);
    json.AddMember("rev", to_json((p.rev), allocator), allocator);
    json.AddMember("msgs", to_json((p.msgs), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.anchorPoint != 0) json.AddMember("anchorPoint", to_json(*(p.anchorPoint), allocator), allocator);
    if (p.rtcmHeader != 0) json.AddMember("rtcmHeader", to_json(*(p.rtcmHeader), allocator), allocator);
    return json;
}

void from_json(const Value& j, RTCMcorrections& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["msgCnt"], (p.msgCnt));
    from_json(j["rev"], (p.rev));
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    if (j.HasMember("anchorPoint")) { p.anchorPoint = vanetza::asn1::allocate<FullPositionVector_t>(); from_json(j["anchorPoint"], *(p.anchorPoint)); }
    else { p.anchorPoint=nullptr; }
    if (j.HasMember("rtcmHeader")) { p.rtcmHeader = vanetza::asn1::allocate<RTCMheader_t>(); from_json(j["rtcmHeader"], *(p.rtcmHeader)); }
    else { p.rtcmHeader=nullptr; }
    from_json(j["msgs"], (p.msgs));
    p.regional=nullptr;
}



/*
*   ConnectsToList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectsToList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const Connection_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ConnectsToList& p) {
    ConnectsToList* p_tmp = vanetza::asn1::allocate<ConnectsToList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        Connection_t *element = vanetza::asn1::allocate<Connection_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneAttributes - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneAttributes& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("directionalUse", to_json_LaneDirection((p.directionalUse), allocator), allocator);
    json.AddMember("sharedWith", to_json_LaneSharing((p.sharedWith), allocator), allocator);
    json.AddMember("laneType", to_json((p.laneType), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, LaneAttributes& p) {
    p._asn_ctx.ptr = nullptr;
    from_json_LaneDirection(j["directionalUse"],(p.directionalUse));
    from_json_LaneSharing(j["sharedWith"],(p.sharedWith));
    from_json(j["laneType"], (p.laneType));
    p.regional=nullptr;
}



/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const MovementState_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, MovementList& p) {
    MovementList* p_tmp = vanetza::asn1::allocate<MovementList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        MovementState_t *element = vanetza::asn1::allocate<MovementState_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeListXY& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == NodeListXY_PR_nodes) {
        json.AddMember("nodes", to_json(p.choice.nodes, allocator), allocator);
    } else if (p.present == NodeListXY_PR_computed) {
        json.AddMember("computed", to_json(p.choice.computed, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, NodeListXY& p) {
    if (j.HasMember("nodes")) {
        p.present = NodeListXY_PR_nodes;
        from_json(j["nodes"], p.choice.nodes);
    } else if (j.HasMember("computed")) {
        p.present = NodeListXY_PR_computed;
        from_json(j["computed"], p.choice.computed);
    } else {
        p.present = NodeListXY_PR_NOTHING;
    }
}

/*
*   RequestorDescription - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorDescription& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    if (p.type != 0) json.AddMember("type", to_json(*(p.type), allocator), allocator);
    if (p.position != 0) json.AddMember("position", to_json(*(p.position), allocator), allocator);
    if (p.transitStatus != 0) json.AddMember("transitStatus", to_json_TransitVehicleStatus(*(p.transitStatus), allocator), allocator);
    if (p.transitOccupancy != 0) json.AddMember("transitOccupancy", to_json(*(p.transitOccupancy), allocator), allocator);
    if (p.transitSchedule != 0) json.AddMember("transitSchedule", to_json(*(p.transitSchedule), allocator), allocator);
    return json;
}

void from_json(const Value& j, RequestorDescription& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    if (j.HasMember("type")) { p.type = vanetza::asn1::allocate<RequestorType_t>(); from_json(j["type"], *(p.type)); }
    else { p.type=nullptr; }
    if (j.HasMember("position")) { p.position = vanetza::asn1::allocate<RequestorPositionVector_t>(); from_json(j["position"], *(p.position)); }
    else { p.position=nullptr; }
    if (j.HasMember("transitStatus")) { p.transitStatus = vanetza::asn1::allocate<TransitVehicleStatus_t>(); from_json_TransitVehicleStatus(j["transitStatus"],*(p.transitStatus)); }
    else { p.transitStatus=nullptr; }
    if (j.HasMember("transitOccupancy")) { p.transitOccupancy = vanetza::asn1::allocate<TransitVehicleOccupancy_t>(); from_json(j["transitOccupancy"], *(p.transitOccupancy)); }
    else { p.transitOccupancy=nullptr; }
    if (j.HasMember("transitSchedule")) { p.transitSchedule = vanetza::asn1::allocate<DeltaTime_t>(); from_json(j["transitSchedule"], *(p.transitSchedule)); }
    else { p.transitSchedule=nullptr; }
    p.name=nullptr;
    p.routeName=nullptr;
    p.regional=nullptr;
}



/*
*   SignalStatusPackageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackageList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SignalStatusPackage_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SignalStatusPackageList& p) {
    SignalStatusPackageList* p_tmp = vanetza::asn1::allocate<SignalStatusPackageList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SignalStatusPackage_t *element = vanetza::asn1::allocate<SignalStatusPackage_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DDD-IO-LIST - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO_LIST& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const DDD_IO_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, DDD_IO_LIST& p) {
    DDD_IO_LIST* p_tmp = vanetza::asn1::allocate<DDD_IO_LIST>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        DDD_IO_t *element = vanetza::asn1::allocate<DDD_IO_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CreditRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("refund", to_json((p.refund), allocator), allocator);
    json.AddMember("nonce", to_json((p.nonce), allocator), allocator);
    json.AddMember("key", to_json((p.key), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CreditRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["refund"], (p.refund));
    from_json(j["nonce"], (p.nonce));
    from_json(j["key"], (p.key));
}



/*
*   DebitRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRq_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("debitPaymentFee", to_json((p.debitPaymentFee), allocator), allocator);
    json.AddMember("nonce", to_json((p.nonce), allocator), allocator);
    json.AddMember("keyRef", to_json((p.keyRef), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DebitRq_t& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["debitPaymentFee"], (p.debitPaymentFee));
    from_json(j["nonce"], (p.nonce));
    from_json(j["keyRef"], (p.keyRef));
}



/*
*   VarLengthNumber - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const VarLengthNumber& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VarLengthNumber_PR_content) {
        json.AddMember("content", to_json(p.choice.content, allocator), allocator);
    } else if (p.present == VarLengthNumber_PR_extension) {
        json.AddMember("extension", to_json(p.choice.extension, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VarLengthNumber& p) {
    if (j.HasMember("content")) {
        p.present = VarLengthNumber_PR_content;
        from_json(j["content"], p.choice.content);
    } else if (j.HasMember("extension")) {
        p.present = VarLengthNumber_PR_extension;
        from_json(j["extension"], p.choice.extension);
    } else {
        p.present = VarLengthNumber_PR_NOTHING;
    }
}

/*
*   GlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("zoneId", to_json((p.zoneId), allocator), allocator);
    if (p.laneNumber != 0) json.AddMember("laneNumber", to_json(*(p.laneNumber), allocator), allocator);
    if (p.zoneExtension != 0) json.AddMember("zoneExtension", to_json(*(p.zoneExtension), allocator), allocator);
    if (p.zoneHeading != 0) json.AddMember("zoneHeading", to_json((*(p.zoneHeading) != 3601) ? (double) *(p.zoneHeading) / 10.0 : *(p.zoneHeading), allocator), allocator);
    if (p.zone != 0) json.AddMember("zone", to_json(*(p.zone), allocator), allocator);
    return json;
}

void from_json(const Value& j, GlcPart& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["zoneId"], (p.zoneId));
    if (j.HasMember("laneNumber")) { p.laneNumber = vanetza::asn1::allocate<LanePosition_t>(); from_json(j["laneNumber"], *(p.laneNumber)); }
    else { p.laneNumber=nullptr; }
    if (j.HasMember("zoneExtension")) { p.zoneExtension = vanetza::asn1::allocate<long>(); from_json(j["zoneExtension"], *(p.zoneExtension)); }
    else { p.zoneExtension=nullptr; }
    double zoneHeading; if (j.HasMember("zoneHeading")) { p.zoneHeading = vanetza::asn1::allocate<HeadingValue_t>(); from_json(j["zoneHeading"], (zoneHeading)); *(p.zoneHeading) = ((zoneHeading) != 3601) ? zoneHeading * 10 : zoneHeading; }
    else { p.zoneHeading=nullptr; }
    if (j.HasMember("zone")) { p.zone = vanetza::asn1::allocate<Zone_t>(); from_json(j["zone"], *(p.zone)); }
    else { p.zone=nullptr; }
}



/*
*   RoadSurfaceContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RscPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RoadSurfaceContainer& p) {
    RoadSurfaceContainer* p_tmp = vanetza::asn1::allocate<RoadSurfaceContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RscPart_t *element = vanetza::asn1::allocate<RscPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LayoutContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("layoutId", to_json((p.layoutId), allocator), allocator);
    json.AddMember("layoutComponents", to_json((p.layoutComponents), allocator), allocator);
    if (p.height != 0) json.AddMember("height", to_json(*(p.height), allocator), allocator);
    if (p.width != 0) json.AddMember("width", to_json(*(p.width), allocator), allocator);
    return json;
}

void from_json(const Value& j, LayoutContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["layoutId"], (p.layoutId));
    if (j.HasMember("height")) { p.height = vanetza::asn1::allocate<long>(); from_json(j["height"], *(p.height)); }
    else { p.height=nullptr; }
    if (j.HasMember("width")) { p.width = vanetza::asn1::allocate<long>(); from_json(j["width"], *(p.width)); }
    else { p.width=nullptr; }
    from_json(j["layoutComponents"], (p.layoutComponents));
}



/*
*   MlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcParts& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const MlcPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, MlcParts& p) {
    MlcParts* p_tmp = vanetza::asn1::allocate<MlcParts>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        MlcPart_t *element = vanetza::asn1::allocate<MlcPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TrailerCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const IVI_TrailerCharacteristics_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TrailerCharacteristicsList& p) {
    TrailerCharacteristicsList* p_tmp = vanetza::asn1::allocate<TrailerCharacteristicsList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        IVI_TrailerCharacteristics_t *element = vanetza::asn1::allocate<IVI_TrailerCharacteristics_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CompleteVehicleCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const CompleteVehicleCharacteristics& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.tractor != 0) json.AddMember("tractor", to_json(*(p.tractor), allocator), allocator);
    if (p.trailer != 0) json.AddMember("trailer", to_json(*(p.trailer), allocator), allocator);
    if (p.train != 0) json.AddMember("train", to_json(*(p.train), allocator), allocator);
    return json;
}

void from_json(const Value& j, CompleteVehicleCharacteristics& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("tractor")) { p.tractor = vanetza::asn1::allocate<TractorCharacteristics_t>(); from_json(j["tractor"], *(p.tractor)); }
    else { p.tractor=nullptr; }
    if (j.HasMember("trailer")) { p.trailer = vanetza::asn1::allocate<TrailerCharacteristicsList_t>(); from_json(j["trailer"], *(p.trailer)); }
    else { p.trailer=nullptr; }
    if (j.HasMember("train")) { p.train = vanetza::asn1::allocate<TractorCharacteristics_t>(); from_json(j["train"], *(p.train)); }
    else { p.train=nullptr; }
}



/*
*   LaneInformation - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneInformation& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("laneNumber", to_json((p.laneNumber), allocator), allocator);
    json.AddMember("direction", to_json((p.direction), allocator), allocator);
    json.AddMember("laneType", to_json((p.laneType), allocator), allocator);
    json.AddMember("laneStatus", to_json((p.laneStatus), allocator), allocator);
    if (p.validity != 0) json.AddMember("validity", to_json(*(p.validity), allocator), allocator);
    if (p.laneTypeQualifier != 0) json.AddMember("laneTypeQualifier", to_json(*(p.laneTypeQualifier), allocator), allocator);
    if (p.laneWidth != 0) json.AddMember("laneWidth", to_json(*(p.laneWidth), allocator), allocator);
    if (p.ext1->detectionZoneIds != 0) json.AddMember("detectionZoneIds", to_json(*(p.ext1->detectionZoneIds), allocator), allocator);
    if (p.ext1->relevanceZoneIds != 0) json.AddMember("relevanceZoneIds", to_json(*(p.ext1->relevanceZoneIds), allocator), allocator);
    if (p.ext1->laneCharacteristics != 0) json.AddMember("laneCharacteristics", to_json(*(p.ext1->laneCharacteristics), allocator), allocator);
    if (p.ext1->laneSurfaceStaticCharacteristics != 0) json.AddMember("laneSurfaceStaticCharacteristics", to_json(*(p.ext1->laneSurfaceStaticCharacteristics), allocator), allocator);
    if (p.ext1->laneSurfaceDynamicCharacteristics != 0) json.AddMember("laneSurfaceDynamicCharacteristics", to_json(*(p.ext1->laneSurfaceDynamicCharacteristics), allocator), allocator);
    return json;
}

void from_json(const Value& j, LaneInformation& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["laneNumber"], (p.laneNumber));
    from_json(j["direction"], (p.direction));
    if (j.HasMember("validity")) { p.validity = vanetza::asn1::allocate<InternationalSign_applicablePeriod_t>(); from_json(j["validity"], *(p.validity)); }
    else { p.validity=nullptr; }
    from_json(j["laneType"], (p.laneType));
    if (j.HasMember("laneTypeQualifier")) { p.laneTypeQualifier = vanetza::asn1::allocate<CompleteVehicleCharacteristics_t>(); from_json(j["laneTypeQualifier"], *(p.laneTypeQualifier)); }
    else { p.laneTypeQualifier=nullptr; }
    from_json(j["laneStatus"], (p.laneStatus));
    if (j.HasMember("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<IviLaneWidth_t>(); from_json(j["laneWidth"], *(p.laneWidth)); }
    else { p.laneWidth=nullptr; }
    if (j.HasMember("detectionZoneIds")) { p.ext1->detectionZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["detectionZoneIds"], *(p.ext1->detectionZoneIds)); }
    else { p.ext1->detectionZoneIds=nullptr; }
    if (j.HasMember("relevanceZoneIds")) { p.ext1->relevanceZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["relevanceZoneIds"], *(p.ext1->relevanceZoneIds)); }
    else { p.ext1->relevanceZoneIds=nullptr; }
    if (j.HasMember("laneCharacteristics")) { p.ext1->laneCharacteristics = vanetza::asn1::allocate<LaneCharacteristics_t>(); from_json(j["laneCharacteristics"], *(p.ext1->laneCharacteristics)); }
    else { p.ext1->laneCharacteristics=nullptr; }
    if (j.HasMember("laneSurfaceStaticCharacteristics")) { p.ext1->laneSurfaceStaticCharacteristics = vanetza::asn1::allocate<RoadSurfaceStaticCharacteristics_t>(); from_json(j["laneSurfaceStaticCharacteristics"], *(p.ext1->laneSurfaceStaticCharacteristics)); }
    else { p.ext1->laneSurfaceStaticCharacteristics=nullptr; }
    if (j.HasMember("laneSurfaceDynamicCharacteristics")) { p.ext1->laneSurfaceDynamicCharacteristics = vanetza::asn1::allocate<RoadSurfaceDynamicCharacteristics_t>(); from_json(j["laneSurfaceDynamicCharacteristics"], *(p.ext1->laneSurfaceDynamicCharacteristics)); }
    else { p.ext1->laneSurfaceDynamicCharacteristics=nullptr; }
}



/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialVehicleContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == SpecialVehicleContainer_PR_publicTransportContainer) {
        json.AddMember("publicTransportContainer", to_json(p.choice.publicTransportContainer, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_specialTransportContainer) {
        json.AddMember("specialTransportContainer", to_json(p.choice.specialTransportContainer, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_dangerousGoodsContainer) {
        json.AddMember("dangerousGoodsContainer", to_json(p.choice.dangerousGoodsContainer, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_roadWorksContainerBasic) {
        json.AddMember("roadWorksContainerBasic", to_json(p.choice.roadWorksContainerBasic, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_rescueContainer) {
        json.AddMember("rescueContainer", to_json(p.choice.rescueContainer, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_emergencyContainer) {
        json.AddMember("emergencyContainer", to_json(p.choice.emergencyContainer, allocator), allocator);
    } else if (p.present == SpecialVehicleContainer_PR_safetyCarContainer) {
        json.AddMember("safetyCarContainer", to_json(p.choice.safetyCarContainer, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, SpecialVehicleContainer& p) {
    if (j.HasMember("publicTransportContainer")) {
        p.present = SpecialVehicleContainer_PR_publicTransportContainer;
        from_json(j["publicTransportContainer"], p.choice.publicTransportContainer);
    } else if (j.HasMember("specialTransportContainer")) {
        p.present = SpecialVehicleContainer_PR_specialTransportContainer;
        from_json(j["specialTransportContainer"], p.choice.specialTransportContainer);
    } else if (j.HasMember("dangerousGoodsContainer")) {
        p.present = SpecialVehicleContainer_PR_dangerousGoodsContainer;
        from_json(j["dangerousGoodsContainer"], p.choice.dangerousGoodsContainer);
    } else if (j.HasMember("roadWorksContainerBasic")) {
        p.present = SpecialVehicleContainer_PR_roadWorksContainerBasic;
        from_json(j["roadWorksContainerBasic"], p.choice.roadWorksContainerBasic);
    } else if (j.HasMember("rescueContainer")) {
        p.present = SpecialVehicleContainer_PR_rescueContainer;
        from_json(j["rescueContainer"], p.choice.rescueContainer);
    } else if (j.HasMember("emergencyContainer")) {
        p.present = SpecialVehicleContainer_PR_emergencyContainer;
        from_json(j["emergencyContainer"], p.choice.emergencyContainer);
    } else if (j.HasMember("safetyCarContainer")) {
        p.present = SpecialVehicleContainer_PR_safetyCarContainer;
        from_json(j["safetyCarContainer"], p.choice.safetyCarContainer);
    } else {
        p.present = SpecialVehicleContainer_PR_NOTHING;
    }
}

/*
*   DecentralizedEnvironmentalNotificationMessage - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DecentralizedEnvironmentalNotificationMessage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("management", to_json((p.management), allocator), allocator);
    if (p.situation != 0) json.AddMember("situation", to_json(*(p.situation), allocator), allocator);
    if (p.location != 0) json.AddMember("location", to_json(*(p.location), allocator), allocator);
    if (p.alacarte != 0) json.AddMember("alacarte", to_json(*(p.alacarte), allocator), allocator);
    return json;
}

void from_json(const Value& j, DecentralizedEnvironmentalNotificationMessage& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["management"], (p.management));
    if (j.HasMember("situation")) { p.situation = vanetza::asn1::allocate<SituationContainer_t>(); from_json(j["situation"], *(p.situation)); }
    else { p.situation=nullptr; }
    if (j.HasMember("location")) { p.location = vanetza::asn1::allocate<LocationContainer_t>(); from_json(j["location"], *(p.location)); }
    else { p.location=nullptr; }
    if (j.HasMember("alacarte")) { p.alacarte = vanetza::asn1::allocate<AlacarteContainer_t>(); from_json(j["alacarte"], *(p.alacarte)); }
    else { p.alacarte=nullptr; }
}



/*
*   TrafficIslandPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrafficIslandPosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("oneSide", to_json((p.oneSide), allocator), allocator);
    json.AddMember("otherSide", to_json((p.otherSide), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, TrafficIslandPosition& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["oneSide"], (p.oneSide));
    from_json(j["otherSide"], (p.otherSide));
}



/*
*   VruLowFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLowFrequencyContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.profileAndSubprofile != 0) json.AddMember("profileAndSubprofile", to_json(*(p.profileAndSubprofile), allocator), allocator);
    if (p.exteriorLights != 0) json.AddMember("exteriorLights", to_json(*(p.exteriorLights), allocator), allocator);
    if (p.sizeClass != 0) json.AddMember("sizeClass", to_json(*(p.sizeClass), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruLowFrequencyContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("profileAndSubprofile")) { p.profileAndSubprofile = vanetza::asn1::allocate<VruProfileAndSubprofile_t>(); from_json(j["profileAndSubprofile"], *(p.profileAndSubprofile)); }
    else { p.profileAndSubprofile=nullptr; }
    if (j.HasMember("exteriorLights")) { p.exteriorLights = vanetza::asn1::allocate<VruExteriorLights_t>(); from_json(j["exteriorLights"], *(p.exteriorLights)); }
    else { p.exteriorLights=nullptr; }
    if (j.HasMember("sizeClass")) { p.sizeClass = vanetza::asn1::allocate<VruSizeClass_t>(); from_json(j["sizeClass"], *(p.sizeClass)); }
    else { p.sizeClass=nullptr; }
}



/*
*   SequenceOfVruPathPoint - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruPathPoint& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const VruPathPoint_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SequenceOfVruPathPoint& p) {
    SequenceOfVruPathPoint* p_tmp = vanetza::asn1::allocate<SequenceOfVruPathPoint>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        VruPathPoint_t *element = vanetza::asn1::allocate<VruPathPoint_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingVehicleContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heading", to_json((p.heading), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    json.AddMember("driveDirection", to_json((p.driveDirection), allocator), allocator);
    if (p.vehicleOrientationAngle != 0) json.AddMember("vehicleOrientationAngle", to_json(*(p.vehicleOrientationAngle), allocator), allocator);
    if (p.longitudinalAcceleration != 0) json.AddMember("longitudinalAcceleration", to_json(*(p.longitudinalAcceleration), allocator), allocator);
    if (p.lateralAcceleration != 0) json.AddMember("lateralAcceleration", to_json(*(p.lateralAcceleration), allocator), allocator);
    if (p.verticalAcceleration != 0) json.AddMember("verticalAcceleration", to_json(*(p.verticalAcceleration), allocator), allocator);
    if (p.yawRate != 0) json.AddMember("yawRate", to_json(*(p.yawRate), allocator), allocator);
    if (p.pitchAngle != 0) json.AddMember("pitchAngle", to_json(*(p.pitchAngle), allocator), allocator);
    if (p.rollAngle != 0) json.AddMember("rollAngle", to_json(*(p.rollAngle), allocator), allocator);
    if (p.vehicleLength != 0) json.AddMember("vehicleLength", to_json(*(p.vehicleLength), allocator), allocator);
    if (p.vehicleWidth != 0) json.AddMember("vehicleWidth", to_json((*(p.vehicleWidth) != 61 && *(p.vehicleWidth) != 62) ? (double) *(p.vehicleWidth) / 10.0 : *(p.vehicleWidth), allocator), allocator);
    if (p.vehicleHeight != 0) json.AddMember("vehicleHeight", to_json(*(p.vehicleHeight), allocator), allocator);
    if (p.trailerDataContainer != 0) json.AddMember("trailerDataContainer", to_json(*(p.trailerDataContainer), allocator), allocator);
    return json;
}

void from_json(const Value& j, OriginatingVehicleContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["heading"], (p.heading));
    from_json(j["speed"], (p.speed));
    if (j.HasMember("vehicleOrientationAngle")) { p.vehicleOrientationAngle = vanetza::asn1::allocate<WGS84Angle_t>(); from_json(j["vehicleOrientationAngle"], *(p.vehicleOrientationAngle)); }
    else { p.vehicleOrientationAngle=nullptr; }
    from_json(j["driveDirection"], (p.driveDirection));
    if (j.HasMember("longitudinalAcceleration")) { p.longitudinalAcceleration = vanetza::asn1::allocate<LongitudinalAcceleration_t>(); from_json(j["longitudinalAcceleration"], *(p.longitudinalAcceleration)); }
    else { p.longitudinalAcceleration=nullptr; }
    if (j.HasMember("lateralAcceleration")) { p.lateralAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); from_json(j["lateralAcceleration"], *(p.lateralAcceleration)); }
    else { p.lateralAcceleration=nullptr; }
    if (j.HasMember("verticalAcceleration")) { p.verticalAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); from_json(j["verticalAcceleration"], *(p.verticalAcceleration)); }
    else { p.verticalAcceleration=nullptr; }
    if (j.HasMember("yawRate")) { p.yawRate = vanetza::asn1::allocate<YawRate_t>(); from_json(j["yawRate"], *(p.yawRate)); }
    else { p.yawRate=nullptr; }
    if (j.HasMember("pitchAngle")) { p.pitchAngle = vanetza::asn1::allocate<CartesianAngle_t>(); from_json(j["pitchAngle"], *(p.pitchAngle)); }
    else { p.pitchAngle=nullptr; }
    if (j.HasMember("rollAngle")) { p.rollAngle = vanetza::asn1::allocate<CartesianAngle_t>(); from_json(j["rollAngle"], *(p.rollAngle)); }
    else { p.rollAngle=nullptr; }
    if (j.HasMember("vehicleLength")) { p.vehicleLength = vanetza::asn1::allocate<VehicleLength_t>(); from_json(j["vehicleLength"], *(p.vehicleLength)); }
    else { p.vehicleLength=nullptr; }
    double vehicleWidth; if (j.HasMember("vehicleWidth")) { p.vehicleWidth = vanetza::asn1::allocate<VehicleWidth_t>(); from_json(j["vehicleWidth"], (vehicleWidth)); *(p.vehicleWidth) = ((vehicleWidth) != 61 && (vehicleWidth) != 62) ? vehicleWidth * 10 : vehicleWidth; }
    else { p.vehicleWidth=nullptr; }
    if (j.HasMember("vehicleHeight")) { p.vehicleHeight = vanetza::asn1::allocate<VehicleHeight_t>(); from_json(j["vehicleHeight"], *(p.vehicleHeight)); }
    else { p.vehicleHeight=nullptr; }
    if (j.HasMember("trailerDataContainer")) { p.trailerDataContainer = vanetza::asn1::allocate<TrailerDataContainer_t>(); from_json(j["trailerDataContainer"], *(p.trailerDataContainer)); }
    else { p.trailerDataContainer=nullptr; }
}



/*
*   VehicleSensor - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensor& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("refPointId", to_json((p.refPointId), allocator), allocator);
    json.AddMember("xSensorOffset", to_json((p.xSensorOffset), allocator), allocator);
    json.AddMember("ySensorOffset", to_json((p.ySensorOffset), allocator), allocator);
    json.AddMember("vehicleSensorPropertyList", to_json((p.vehicleSensorPropertyList), allocator), allocator);
    if (p.zSensorOffset != 0) json.AddMember("zSensorOffset", to_json(*(p.zSensorOffset), allocator), allocator);
    return json;
}

void from_json(const Value& j, VehicleSensor& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["refPointId"], (p.refPointId));
    from_json(j["xSensorOffset"], (p.xSensorOffset));
    from_json(j["ySensorOffset"], (p.ySensorOffset));
    if (j.HasMember("zSensorOffset")) { p.zSensorOffset = vanetza::asn1::allocate<ZSensorOffset_t>(); from_json(j["zSensorOffset"], *(p.zSensorOffset)); }
    else { p.zSensorOffset=nullptr; }
    from_json(j["vehicleSensorPropertyList"], (p.vehicleSensorPropertyList));
}



/*
*   AreaCircular - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaCircular& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("radius", to_json((double)(p.radius) / 10.0, allocator), allocator);
    if (p.nodeCenterPoint != 0) json.AddMember("nodeCenterPoint", to_json(*(p.nodeCenterPoint), allocator), allocator);
    return json;
}

void from_json(const Value& j, AreaCircular& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); from_json(j["nodeCenterPoint"], *(p.nodeCenterPoint)); }
    else { p.nodeCenterPoint=nullptr; }
    double radius; from_json(j["radius"], (radius)); (p.radius) =radius * 10;
}



/*
*   AreaEllipse - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaEllipse& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("semiMinorRangeLength", to_json((double)(p.semiMinorRangeLength) / 10.0, allocator), allocator);
    json.AddMember("semiMajorRangeLength", to_json((double)(p.semiMajorRangeLength) / 10.0, allocator), allocator);
    json.AddMember("semiMajorRangeOrientation", to_json(((p.semiMajorRangeOrientation) == 3601) ? (p.semiMajorRangeOrientation) : (double)(p.semiMajorRangeOrientation) / 10.0, allocator), allocator);
    if (p.nodeCenterPoint != 0) json.AddMember("nodeCenterPoint", to_json(*(p.nodeCenterPoint), allocator), allocator);
    if (p.semiHeight != 0) json.AddMember("semiHeight", to_json((double) *(p.semiHeight) / 10.0, allocator), allocator);
    return json;
}

void from_json(const Value& j, AreaEllipse& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); from_json(j["nodeCenterPoint"], *(p.nodeCenterPoint)); }
    else { p.nodeCenterPoint=nullptr; }
    double semiMinorRangeLength; from_json(j["semiMinorRangeLength"], (semiMinorRangeLength)); (p.semiMinorRangeLength) =semiMinorRangeLength * 10;
    double semiMajorRangeLength; from_json(j["semiMajorRangeLength"], (semiMajorRangeLength)); (p.semiMajorRangeLength) =semiMajorRangeLength * 10;
    double semiMajorRangeOrientation; from_json(j["semiMajorRangeOrientation"], (semiMajorRangeOrientation)); (p.semiMajorRangeOrientation) = ((semiMajorRangeOrientation) != 3601) ? semiMajorRangeOrientation * 10 : semiMajorRangeOrientation;
    double semiHeight; if (j.HasMember("semiHeight")) { p.semiHeight = vanetza::asn1::allocate<SemiRangeLength_t>(); from_json(j["semiHeight"], (semiHeight)); *(p.semiHeight) =semiHeight * 10; }
    else { p.semiHeight=nullptr; }
}



/*
*   AreaRectangle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRectangle& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("semiMajorRangeLength", to_json((double)(p.semiMajorRangeLength) / 10.0, allocator), allocator);
    json.AddMember("semiMinorRangeLength", to_json((double)(p.semiMinorRangeLength) / 10.0, allocator), allocator);
    json.AddMember("semiMajorRangeOrientation", to_json(((p.semiMajorRangeOrientation) == 3601) ? (p.semiMajorRangeOrientation) : (double)(p.semiMajorRangeOrientation) / 10.0, allocator), allocator);
    if (p.nodeCenterPoint != 0) json.AddMember("nodeCenterPoint", to_json(*(p.nodeCenterPoint), allocator), allocator);
    if (p.semiHeight != 0) json.AddMember("semiHeight", to_json((double) *(p.semiHeight) / 10.0, allocator), allocator);
    return json;
}

void from_json(const Value& j, AreaRectangle& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("nodeCenterPoint")) { p.nodeCenterPoint = vanetza::asn1::allocate<OffsetPoint_t>(); from_json(j["nodeCenterPoint"], *(p.nodeCenterPoint)); }
    else { p.nodeCenterPoint=nullptr; }
    double semiMajorRangeLength; from_json(j["semiMajorRangeLength"], (semiMajorRangeLength)); (p.semiMajorRangeLength) =semiMajorRangeLength * 10;
    double semiMinorRangeLength; from_json(j["semiMinorRangeLength"], (semiMinorRangeLength)); (p.semiMinorRangeLength) =semiMinorRangeLength * 10;
    double semiMajorRangeOrientation; from_json(j["semiMajorRangeOrientation"], (semiMajorRangeOrientation)); (p.semiMajorRangeOrientation) = ((semiMajorRangeOrientation) != 3601) ? semiMajorRangeOrientation * 10 : semiMajorRangeOrientation;
    double semiHeight; if (j.HasMember("semiHeight")) { p.semiHeight = vanetza::asn1::allocate<SemiRangeLength_t>(); from_json(j["semiHeight"], (semiHeight)); *(p.semiHeight) =semiHeight * 10; }
    else { p.semiHeight=nullptr; }
}



/*
*   PolyPointList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PolyPointList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const OffsetPoint_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, PolyPointList& p) {
    PolyPointList* p_tmp = vanetza::asn1::allocate<PolyPointList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        OffsetPoint_t *element = vanetza::asn1::allocate<OffsetPoint_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AreaRadial - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRadial& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("range", to_json((p.range), allocator), allocator);
    json.AddMember("stationaryHorizontalOpeningAngleStart", to_json(((p.stationaryHorizontalOpeningAngleStart) == 3601) ? (p.stationaryHorizontalOpeningAngleStart) : (double)(p.stationaryHorizontalOpeningAngleStart) / 10.0, allocator), allocator);
    json.AddMember("stationaryHorizontalOpeningAngleEnd", to_json(((p.stationaryHorizontalOpeningAngleEnd) == 3601) ? (p.stationaryHorizontalOpeningAngleEnd) : (double)(p.stationaryHorizontalOpeningAngleEnd) / 10.0, allocator), allocator);
    if (p.verticalOpeningAngleStart != 0) json.AddMember("verticalOpeningAngleStart", to_json((*(p.verticalOpeningAngleStart) != 3601) ? (double) *(p.verticalOpeningAngleStart) / 10.0 : *(p.verticalOpeningAngleStart), allocator), allocator);
    if (p.verticalOpeningAngleEnd != 0) json.AddMember("verticalOpeningAngleEnd", to_json((*(p.verticalOpeningAngleEnd) != 3601) ? (double) *(p.verticalOpeningAngleEnd) / 10.0 : *(p.verticalOpeningAngleEnd), allocator), allocator);
    if (p.sensorPositionOffset != 0) json.AddMember("sensorPositionOffset", to_json(*(p.sensorPositionOffset), allocator), allocator);
    if (p.sensorHeight != 0) json.AddMember("sensorHeight", to_json((double) *(p.sensorHeight) / 100.0, allocator), allocator);
    return json;
}

void from_json(const Value& j, AreaRadial& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["range"], (p.range));
    double stationaryHorizontalOpeningAngleStart; from_json(j["stationaryHorizontalOpeningAngleStart"], (stationaryHorizontalOpeningAngleStart)); (p.stationaryHorizontalOpeningAngleStart) = ((stationaryHorizontalOpeningAngleStart) != 3601) ? stationaryHorizontalOpeningAngleStart * 10 : stationaryHorizontalOpeningAngleStart;
    double stationaryHorizontalOpeningAngleEnd; from_json(j["stationaryHorizontalOpeningAngleEnd"], (stationaryHorizontalOpeningAngleEnd)); (p.stationaryHorizontalOpeningAngleEnd) = ((stationaryHorizontalOpeningAngleEnd) != 3601) ? stationaryHorizontalOpeningAngleEnd * 10 : stationaryHorizontalOpeningAngleEnd;
    double verticalOpeningAngleStart; if (j.HasMember("verticalOpeningAngleStart")) { p.verticalOpeningAngleStart = vanetza::asn1::allocate<CartesianAngleValue_t>(); from_json(j["verticalOpeningAngleStart"], (verticalOpeningAngleStart)); *(p.verticalOpeningAngleStart) = ((verticalOpeningAngleStart) != 3601) ? verticalOpeningAngleStart * 10 : verticalOpeningAngleStart; }
    else { p.verticalOpeningAngleStart=nullptr; }
    double verticalOpeningAngleEnd; if (j.HasMember("verticalOpeningAngleEnd")) { p.verticalOpeningAngleEnd = vanetza::asn1::allocate<CartesianAngleValue_t>(); from_json(j["verticalOpeningAngleEnd"], (verticalOpeningAngleEnd)); *(p.verticalOpeningAngleEnd) = ((verticalOpeningAngleEnd) != 3601) ? verticalOpeningAngleEnd * 10 : verticalOpeningAngleEnd; }
    else { p.verticalOpeningAngleEnd=nullptr; }
    if (j.HasMember("sensorPositionOffset")) { p.sensorPositionOffset = vanetza::asn1::allocate<OffsetPoint_t>(); from_json(j["sensorPositionOffset"], *(p.sensorPositionOffset)); }
    else { p.sensorPositionOffset=nullptr; }
    double sensorHeight; if (j.HasMember("sensorHeight")) { p.sensorHeight = vanetza::asn1::allocate<SensorHeight_t>(); from_json(j["sensorHeight"], (sensorHeight)); *(p.sensorHeight) =sensorHeight * 100; }
    else { p.sensorHeight=nullptr; }
}



/*
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClassDescription& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ObjectClass_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ObjectClassDescription& p) {
    ObjectClassDescription* p_tmp = vanetza::asn1::allocate<ObjectClassDescription>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ObjectClass_t *element = vanetza::asn1::allocate<ObjectClass_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalRequestMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestMessage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("second", to_json((p.second), allocator), allocator);
    json.AddMember("requestor", to_json((p.requestor), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.sequenceNumber != 0) json.AddMember("sequenceNumber", to_json(*(p.sequenceNumber), allocator), allocator);
    if (p.requests != 0) json.AddMember("requests", to_json(*(p.requests), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalRequestMessage& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    from_json(j["second"], (p.second));
    if (j.HasMember("sequenceNumber")) { p.sequenceNumber = vanetza::asn1::allocate<MsgCount_t>(); from_json(j["sequenceNumber"], *(p.sequenceNumber)); }
    else { p.sequenceNumber=nullptr; }
    if (j.HasMember("requests")) { p.requests = vanetza::asn1::allocate<SignalRequestList_t>(); from_json(j["requests"], *(p.requests)); }
    else { p.requests=nullptr; }
    from_json(j["requestor"], (p.requestor));
    p.regional=nullptr;
}



/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const GenericLane& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("laneID", to_json((p.laneID), allocator), allocator);
    json.AddMember("laneAttributes", to_json((p.laneAttributes), allocator), allocator);
    json.AddMember("nodeList", to_json((p.nodeList), allocator), allocator);
    if (p.ingressApproach != 0) json.AddMember("ingressApproach", to_json(*(p.ingressApproach), allocator), allocator);
    if (p.egressApproach != 0) json.AddMember("egressApproach", to_json(*(p.egressApproach), allocator), allocator);
    if (p.maneuvers != 0) json.AddMember("maneuvers", to_json_AllowedManeuvers(*(p.maneuvers), allocator), allocator);
    if (p.connectsTo != 0) json.AddMember("connectsTo", to_json(*(p.connectsTo), allocator), allocator);
    if (p.overlays != 0) json.AddMember("overlays", to_json(*(p.overlays), allocator), allocator);
    return json;
}

void from_json(const Value& j, GenericLane& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["laneID"], (p.laneID));
    if (j.HasMember("ingressApproach")) { p.ingressApproach = vanetza::asn1::allocate<ApproachID_t>(); from_json(j["ingressApproach"], *(p.ingressApproach)); }
    else { p.ingressApproach=nullptr; }
    if (j.HasMember("egressApproach")) { p.egressApproach = vanetza::asn1::allocate<ApproachID_t>(); from_json(j["egressApproach"], *(p.egressApproach)); }
    else { p.egressApproach=nullptr; }
    from_json(j["laneAttributes"], (p.laneAttributes));
    if (j.HasMember("maneuvers")) { p.maneuvers = vanetza::asn1::allocate<AllowedManeuvers_t>(); from_json_AllowedManeuvers(j["maneuvers"],*(p.maneuvers)); }
    else { p.maneuvers=nullptr; }
    from_json(j["nodeList"], (p.nodeList));
    if (j.HasMember("connectsTo")) { p.connectsTo = vanetza::asn1::allocate<ConnectsToList_t>(); from_json(j["connectsTo"], *(p.connectsTo)); }
    else { p.connectsTo=nullptr; }
    if (j.HasMember("overlays")) { p.overlays = vanetza::asn1::allocate<OverlayLaneList_t>(); from_json(j["overlays"], *(p.overlays)); }
    else { p.overlays=nullptr; }
    p.name=nullptr;
    p.regional=nullptr;
}



/*
*   IntersectionState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionState& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("revision", to_json((p.revision), allocator), allocator);
    json.AddMember("status", to_json_IntersectionStatusObject((p.status), allocator), allocator);
    json.AddMember("states", to_json((p.states), allocator), allocator);
    if (p.moy != 0) json.AddMember("moy", to_json(*(p.moy), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.enabledLanes != 0) json.AddMember("enabledLanes", to_json(*(p.enabledLanes), allocator), allocator);
    if (p.maneuverAssistList != 0) json.AddMember("maneuverAssistList", to_json(*(p.maneuverAssistList), allocator), allocator);
    return json;
}

void from_json(const Value& j, IntersectionState& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["revision"], (p.revision));
    from_json_IntersectionStatusObject(j["status"],(p.status));
    if (j.HasMember("moy")) { p.moy = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["moy"], *(p.moy)); }
    else { p.moy=nullptr; }
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<DSecond_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    if (j.HasMember("enabledLanes")) { p.enabledLanes = vanetza::asn1::allocate<EnabledLaneList_t>(); from_json(j["enabledLanes"], *(p.enabledLanes)); }
    else { p.enabledLanes=nullptr; }
    from_json(j["states"], (p.states));
    if (j.HasMember("maneuverAssistList")) { p.maneuverAssistList = vanetza::asn1::allocate<ManeuverAssistList_t>(); from_json(j["maneuverAssistList"], *(p.maneuverAssistList)); }
    else { p.maneuverAssistList=nullptr; }
    p.name=nullptr;
    p.regional=nullptr;
}



/*
*   IntersectionStateList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionStateList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const IntersectionState_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, IntersectionStateList& p) {
    IntersectionStateList* p_tmp = vanetza::asn1::allocate<IntersectionStateList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        IntersectionState_t *element = vanetza::asn1::allocate<IntersectionState_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   LaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const GenericLane_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, LaneList& p) {
    LaneList* p_tmp = vanetza::asn1::allocate<LaneList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        GenericLane_t *element = vanetza::asn1::allocate<GenericLane_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RoadLaneSetList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadLaneSetList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const GenericLane_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RoadLaneSetList& p) {
    RoadLaneSetList* p_tmp = vanetza::asn1::allocate<RoadLaneSetList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        GenericLane_t *element = vanetza::asn1::allocate<GenericLane_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RoadSegment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegment& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("revision", to_json((p.revision), allocator), allocator);
    json.AddMember("refPoint", to_json((p.refPoint), allocator), allocator);
    json.AddMember("roadLaneSet", to_json((p.roadLaneSet), allocator), allocator);
    if (p.laneWidth != 0) json.AddMember("laneWidth", to_json(*(p.laneWidth), allocator), allocator);
    if (p.speedLimits != 0) json.AddMember("speedLimits", to_json(*(p.speedLimits), allocator), allocator);
    return json;
}

void from_json(const Value& j, RoadSegment& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["revision"], (p.revision));
    from_json(j["refPoint"], (p.refPoint));
    if (j.HasMember("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<LaneWidth_t>(); from_json(j["laneWidth"], *(p.laneWidth)); }
    else { p.laneWidth=nullptr; }
    if (j.HasMember("speedLimits")) { p.speedLimits = vanetza::asn1::allocate<SpeedLimitList_t>(); from_json(j["speedLimits"], *(p.speedLimits)); }
    else { p.speedLimits=nullptr; }
    from_json(j["roadLaneSet"], (p.roadLaneSet));
    p.name=nullptr;
    p.regional=nullptr;
}



/*
*   RoadSegmentList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RoadSegment_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RoadSegmentList& p) {
    RoadSegmentList* p_tmp = vanetza::asn1::allocate<RoadSegmentList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RoadSegment_t *element = vanetza::asn1::allocate<RoadSegment_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   SignalStatus - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatus& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sequenceNumber", to_json((p.sequenceNumber), allocator), allocator);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("sigStatus", to_json((p.sigStatus), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SignalStatus& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sequenceNumber"], (p.sequenceNumber));
    from_json(j["id"], (p.id));
    from_json(j["sigStatus"], (p.sigStatus));
    p.regional=nullptr;
}



/*
*   SignalStatusList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SignalStatus_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SignalStatusList& p) {
    SignalStatusList* p_tmp = vanetza::asn1::allocate<SignalStatusList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SignalStatus_t *element = vanetza::asn1::allocate<SignalStatus_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   InternationalSign-destinationInformation - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_destinationInformation& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.junctionDirection != 0) json.AddMember("junctionDirection", to_json(*(p.junctionDirection), allocator), allocator);
    if (p.roundaboutCwDirection != 0) json.AddMember("roundaboutCwDirection", to_json(*(p.roundaboutCwDirection), allocator), allocator);
    if (p.roundaboutCcwDirection != 0) json.AddMember("roundaboutCcwDirection", to_json(*(p.roundaboutCcwDirection), allocator), allocator);
    if (p.ioList != 0) json.AddMember("ioList", to_json(*(p.ioList), allocator), allocator);
    return json;
}

void from_json(const Value& j, InternationalSign_destinationInformation& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("junctionDirection")) { p.junctionDirection = vanetza::asn1::allocate<long>(); from_json(j["junctionDirection"], *(p.junctionDirection)); }
    else { p.junctionDirection=nullptr; }
    if (j.HasMember("roundaboutCwDirection")) { p.roundaboutCwDirection = vanetza::asn1::allocate<long>(); from_json(j["roundaboutCwDirection"], *(p.roundaboutCwDirection)); }
    else { p.roundaboutCwDirection=nullptr; }
    if (j.HasMember("roundaboutCcwDirection")) { p.roundaboutCcwDirection = vanetza::asn1::allocate<long>(); from_json(j["roundaboutCcwDirection"], *(p.roundaboutCcwDirection)); }
    else { p.roundaboutCcwDirection=nullptr; }
    if (j.HasMember("ioList")) { p.ioList = vanetza::asn1::allocate<DDD_IO_LIST_t>(); from_json(j["ioList"], *(p.ioList)); }
    else { p.ioList=nullptr; }
}



/*
*   GlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcParts& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const GlcPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, GlcParts& p) {
    GlcParts* p_tmp = vanetza::asn1::allocate<GlcParts>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        GlcPart_t *element = vanetza::asn1::allocate<GlcPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   MapLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapLocationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("reference", to_json((p.reference), allocator), allocator);
    json.AddMember("parts", to_json((p.parts), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, MapLocationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["reference"], (p.reference));
    from_json(j["parts"], (p.parts));
}



/*
*   LaneConfiguration - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneConfiguration& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const LaneInformation_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, LaneConfiguration& p) {
    LaneConfiguration* p_tmp = vanetza::asn1::allocate<LaneConfiguration>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        LaneInformation_t *element = vanetza::asn1::allocate<LaneInformation_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VehicleCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const CompleteVehicleCharacteristics_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, VehicleCharacteristicsList& p) {
    VehicleCharacteristicsList* p_tmp = vanetza::asn1::allocate<VehicleCharacteristicsList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        CompleteVehicleCharacteristics_t *element = vanetza::asn1::allocate<CompleteVehicleCharacteristics_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   ISO14823Attribute - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attribute& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ISO14823Attribute_PR_dtm) {
        json.AddMember("dtm", to_json(p.choice.dtm, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_edt) {
        json.AddMember("edt", to_json(p.choice.edt, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_dfl) {
        json.AddMember("dfl", to_json(p.choice.dfl, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_ved) {
        json.AddMember("ved", to_json(p.choice.ved, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_spe) {
        json.AddMember("spe", to_json(p.choice.spe, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_roi) {
        json.AddMember("roi", to_json(p.choice.roi, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_dbv) {
        json.AddMember("dbv", to_json(p.choice.dbv, allocator), allocator);
    } else if (p.present == ISO14823Attribute_PR_ddd) {
        json.AddMember("ddd", to_json(p.choice.ddd, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ISO14823Attribute& p) {
    if (j.HasMember("dtm")) {
        p.present = ISO14823Attribute_PR_dtm;
        from_json(j["dtm"], p.choice.dtm);
    } else if (j.HasMember("edt")) {
        p.present = ISO14823Attribute_PR_edt;
        from_json(j["edt"], p.choice.edt);
    } else if (j.HasMember("dfl")) {
        p.present = ISO14823Attribute_PR_dfl;
        from_json(j["dfl"], p.choice.dfl);
    } else if (j.HasMember("ved")) {
        p.present = ISO14823Attribute_PR_ved;
        from_json(j["ved"], p.choice.ved);
    } else if (j.HasMember("spe")) {
        p.present = ISO14823Attribute_PR_spe;
        from_json(j["spe"], p.choice.spe);
    } else if (j.HasMember("roi")) {
        p.present = ISO14823Attribute_PR_roi;
        from_json(j["roi"], p.choice.roi);
    } else if (j.HasMember("dbv")) {
        p.present = ISO14823Attribute_PR_dbv;
        from_json(j["dbv"], p.choice.dbv);
    } else if (j.HasMember("ddd")) {
        p.present = ISO14823Attribute_PR_ddd;
        from_json(j["ddd"], p.choice.ddd);
    } else {
        p.present = ISO14823Attribute_PR_NOTHING;
    }
}

/*
*   CamParameters - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CamParameters& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("basicContainer", to_json((p.basicContainer), allocator), allocator);
    json.AddMember("highFrequencyContainer", to_json((p.highFrequencyContainer), allocator), allocator);
    if (p.lowFrequencyContainer != 0) json.AddMember("lowFrequencyContainer", to_json(*(p.lowFrequencyContainer), allocator), allocator);
    if (p.specialVehicleContainer != 0) json.AddMember("specialVehicleContainer", to_json(*(p.specialVehicleContainer), allocator), allocator);
    return json;
}

void from_json(const Value& j, CamParameters& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["basicContainer"], (p.basicContainer));
    from_json(j["highFrequencyContainer"], (p.highFrequencyContainer));
    if (j.HasMember("lowFrequencyContainer")) { p.lowFrequencyContainer = vanetza::asn1::allocate<LowFrequencyContainer_t>(); from_json(j["lowFrequencyContainer"], *(p.lowFrequencyContainer)); }
    else { p.lowFrequencyContainer=nullptr; }
    if (j.HasMember("specialVehicleContainer")) { p.specialVehicleContainer = vanetza::asn1::allocate<SpecialVehicleContainer_t>(); from_json(j["specialVehicleContainer"], *(p.specialVehicleContainer)); }
    else { p.specialVehicleContainer=nullptr; }
}



/*
*   DENM - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DENM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("denm", to_json((p.denm), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, DENM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["denm"], (p.denm));
}



/*
*   VruLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLanePosition& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == VruLanePosition_PR_offRoadLanePosition) {
        json.AddMember("offRoadLanePosition", to_json(p.choice.offRoadLanePosition, allocator), allocator);
    } else if (p.present == VruLanePosition_PR_vehicularLanePosition) {
        json.AddMember("vehicularLanePosition", to_json(p.choice.vehicularLanePosition, allocator), allocator);
    } else if (p.present == VruLanePosition_PR_trafficIslandPosition) {
        json.AddMember("trafficIslandPosition", to_json(p.choice.trafficIslandPosition, allocator), allocator);
    } else if (p.present == VruLanePosition_PR_mapPosition) {
        json.AddMember("mapPosition", to_json(p.choice.mapPosition, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, VruLanePosition& p) {
    if (j.HasMember("offRoadLanePosition")) {
        p.present = VruLanePosition_PR_offRoadLanePosition;
        from_json(j["offRoadLanePosition"], p.choice.offRoadLanePosition);
    } else if (j.HasMember("vehicularLanePosition")) {
        p.present = VruLanePosition_PR_vehicularLanePosition;
        from_json(j["vehicularLanePosition"], p.choice.vehicularLanePosition);
    } else if (j.HasMember("trafficIslandPosition")) {
        p.present = VruLanePosition_PR_trafficIslandPosition;
        from_json(j["trafficIslandPosition"], p.choice.trafficIslandPosition);
    } else if (j.HasMember("mapPosition")) {
        p.present = VruLanePosition_PR_mapPosition;
        from_json(j["mapPosition"], p.choice.mapPosition);
    } else {
        p.present = VruLanePosition_PR_NOTHING;
    }
}

/*
*   VruMotionPredictionContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruMotionPredictionContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    
    if (p.pathHistory != 0) json.AddMember("pathHistory", to_json(*(p.pathHistory), allocator), allocator);
    if (p.pathPrediction != 0) json.AddMember("pathPrediction", to_json(*(p.pathPrediction), allocator), allocator);
    if (p.safeDistance != 0) json.AddMember("safeDistance", to_json(*(p.safeDistance), allocator), allocator);
    if (p.trajectoryInterceptionIndication != 0) json.AddMember("trajectoryInterceptionIndication", to_json(*(p.trajectoryInterceptionIndication), allocator), allocator);
    if (p.accelerationChangeIndication != 0) json.AddMember("accelerationChangeIndication", to_json(*(p.accelerationChangeIndication), allocator), allocator);
    if (p.headingChangeIndication != 0) json.AddMember("headingChangeIndication", to_json(*(p.headingChangeIndication), allocator), allocator);
    if (p.stabilityChangeIndication != 0) json.AddMember("stabilityChangeIndication", to_json(*(p.stabilityChangeIndication), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruMotionPredictionContainer& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("pathHistory")) { p.pathHistory = vanetza::asn1::allocate<PathHistory_t>(); from_json(j["pathHistory"], *(p.pathHistory)); }
    else { p.pathHistory=nullptr; }
    if (j.HasMember("pathPrediction")) { p.pathPrediction = vanetza::asn1::allocate<SequenceOfVruPathPoint_t>(); from_json(j["pathPrediction"], *(p.pathPrediction)); }
    else { p.pathPrediction=nullptr; }
    if (j.HasMember("safeDistance")) { p.safeDistance = vanetza::asn1::allocate<SequenceOfVruSafeDistanceIndication_t>(); from_json(j["safeDistance"], *(p.safeDistance)); }
    else { p.safeDistance=nullptr; }
    if (j.HasMember("trajectoryInterceptionIndication")) { p.trajectoryInterceptionIndication = vanetza::asn1::allocate<SequenceOfTrajectoryInterceptionIndication_t>(); from_json(j["trajectoryInterceptionIndication"], *(p.trajectoryInterceptionIndication)); }
    else { p.trajectoryInterceptionIndication=nullptr; }
    if (j.HasMember("accelerationChangeIndication")) { p.accelerationChangeIndication = vanetza::asn1::allocate<AccelerationChangeIndication_t>(); from_json(j["accelerationChangeIndication"], *(p.accelerationChangeIndication)); }
    else { p.accelerationChangeIndication=nullptr; }
    if (j.HasMember("headingChangeIndication")) { p.headingChangeIndication = vanetza::asn1::allocate<HeadingChangeIndication_t>(); from_json(j["headingChangeIndication"], *(p.headingChangeIndication)); }
    else { p.headingChangeIndication=nullptr; }
    if (j.HasMember("stabilityChangeIndication")) { p.stabilityChangeIndication = vanetza::asn1::allocate<StabilityChangeIndication_t>(); from_json(j["stabilityChangeIndication"], *(p.stabilityChangeIndication)); }
    else { p.stabilityChangeIndication=nullptr; }
}



/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const StationDataContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == StationDataContainer_PR_originatingVehicleContainer) {
        json.AddMember("originatingVehicleContainer", to_json(p.choice.originatingVehicleContainer, allocator), allocator);
    } else if (p.present == StationDataContainer_PR_originatingRSUContainer) {
        json.AddMember("originatingRSUContainer", to_json(p.choice.originatingRSUContainer, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, StationDataContainer& p) {
    if (j.HasMember("originatingVehicleContainer")) {
        p.present = StationDataContainer_PR_originatingVehicleContainer;
        from_json(j["originatingVehicleContainer"], p.choice.originatingVehicleContainer);
    } else if (j.HasMember("originatingRSUContainer")) {
        p.present = StationDataContainer_PR_originatingRSUContainer;
        from_json(j["originatingRSUContainer"], p.choice.originatingRSUContainer);
    } else {
        p.present = StationDataContainer_PR_NOTHING;
    }
}

/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObject& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("objectID", to_json((p.objectID), allocator), allocator);
    json.AddMember("timeOfMeasurement", to_json((p.timeOfMeasurement), allocator), allocator);
    json.AddMember("objectConfidence", to_json((p.objectConfidence), allocator), allocator);
    json.AddMember("xDistance", to_json((p.xDistance), allocator), allocator);
    json.AddMember("yDistance", to_json((p.yDistance), allocator), allocator);
    json.AddMember("xSpeed", to_json((p.xSpeed), allocator), allocator);
    json.AddMember("ySpeed", to_json((p.ySpeed), allocator), allocator);
    json.AddMember("objectRefPoint", to_json((p.objectRefPoint), allocator), allocator);
    if (p.sensorIDList != 0) json.AddMember("sensorIDList", to_json(*(p.sensorIDList), allocator), allocator);
    if (p.objectAge != 0) json.AddMember("objectAge", to_json(*(p.objectAge), allocator), allocator);
    if (p.zDistance != 0) json.AddMember("zDistance", to_json(*(p.zDistance), allocator), allocator);
    if (p.zSpeed != 0) json.AddMember("zSpeed", to_json(*(p.zSpeed), allocator), allocator);
    if (p.xAcceleration != 0) json.AddMember("xAcceleration", to_json(*(p.xAcceleration), allocator), allocator);
    if (p.yAcceleration != 0) json.AddMember("yAcceleration", to_json(*(p.yAcceleration), allocator), allocator);
    if (p.zAcceleration != 0) json.AddMember("zAcceleration", to_json(*(p.zAcceleration), allocator), allocator);
    if (p.yawAngle != 0) json.AddMember("yawAngle", to_json(*(p.yawAngle), allocator), allocator);
    if (p.planarObjectDimension1 != 0) json.AddMember("planarObjectDimension1", to_json(*(p.planarObjectDimension1), allocator), allocator);
    if (p.planarObjectDimension2 != 0) json.AddMember("planarObjectDimension2", to_json(*(p.planarObjectDimension2), allocator), allocator);
    if (p.verticalObjectDimension != 0) json.AddMember("verticalObjectDimension", to_json(*(p.verticalObjectDimension), allocator), allocator);
    if (p.dynamicStatus != 0) json.AddMember("dynamicStatus", to_json(*(p.dynamicStatus), allocator), allocator);
    if (p.classification != 0) json.AddMember("classification", to_json(*(p.classification), allocator), allocator);
    if (p.matchedPosition != 0) json.AddMember("matchedPosition", to_json(*(p.matchedPosition), allocator), allocator);
    return json;
}

void from_json(const Value& j, PerceivedObject& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["objectID"], (p.objectID));
    if (j.HasMember("sensorIDList")) { p.sensorIDList = vanetza::asn1::allocate<SensorIdList_t>(); from_json(j["sensorIDList"], *(p.sensorIDList)); }
    else { p.sensorIDList=nullptr; }
    from_json(j["timeOfMeasurement"], (p.timeOfMeasurement));
    if (j.HasMember("objectAge")) { p.objectAge = vanetza::asn1::allocate<ObjectAge_t>(); from_json(j["objectAge"], *(p.objectAge)); }
    else { p.objectAge=nullptr; }
    from_json(j["objectConfidence"], (p.objectConfidence));
    from_json(j["xDistance"], (p.xDistance));
    from_json(j["yDistance"], (p.yDistance));
    if (j.HasMember("zDistance")) { p.zDistance = vanetza::asn1::allocate<ObjectDistanceWithConfidence_t>(); from_json(j["zDistance"], *(p.zDistance)); }
    else { p.zDistance=nullptr; }
    from_json(j["xSpeed"], (p.xSpeed));
    from_json(j["ySpeed"], (p.ySpeed));
    if (j.HasMember("zSpeed")) { p.zSpeed = vanetza::asn1::allocate<SpeedExtended_t>(); from_json(j["zSpeed"], *(p.zSpeed)); }
    else { p.zSpeed=nullptr; }
    if (j.HasMember("xAcceleration")) { p.xAcceleration = vanetza::asn1::allocate<LongitudinalAcceleration_t>(); from_json(j["xAcceleration"], *(p.xAcceleration)); }
    else { p.xAcceleration=nullptr; }
    if (j.HasMember("yAcceleration")) { p.yAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); from_json(j["yAcceleration"], *(p.yAcceleration)); }
    else { p.yAcceleration=nullptr; }
    if (j.HasMember("zAcceleration")) { p.zAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); from_json(j["zAcceleration"], *(p.zAcceleration)); }
    else { p.zAcceleration=nullptr; }
    if (j.HasMember("yawAngle")) { p.yawAngle = vanetza::asn1::allocate<CartesianAngle_t>(); from_json(j["yawAngle"], *(p.yawAngle)); }
    else { p.yawAngle=nullptr; }
    if (j.HasMember("planarObjectDimension1")) { p.planarObjectDimension1 = vanetza::asn1::allocate<ObjectDimension_t>(); from_json(j["planarObjectDimension1"], *(p.planarObjectDimension1)); }
    else { p.planarObjectDimension1=nullptr; }
    if (j.HasMember("planarObjectDimension2")) { p.planarObjectDimension2 = vanetza::asn1::allocate<ObjectDimension_t>(); from_json(j["planarObjectDimension2"], *(p.planarObjectDimension2)); }
    else { p.planarObjectDimension2=nullptr; }
    if (j.HasMember("verticalObjectDimension")) { p.verticalObjectDimension = vanetza::asn1::allocate<ObjectDimension_t>(); from_json(j["verticalObjectDimension"], *(p.verticalObjectDimension)); }
    else { p.verticalObjectDimension=nullptr; }
    from_json(j["objectRefPoint"], (p.objectRefPoint));
    if (j.HasMember("dynamicStatus")) { p.dynamicStatus = vanetza::asn1::allocate<DynamicStatus_t>(); from_json(j["dynamicStatus"], *(p.dynamicStatus)); }
    else { p.dynamicStatus=nullptr; }
    if (j.HasMember("classification")) { p.classification = vanetza::asn1::allocate<ObjectClassDescription_t>(); from_json(j["classification"], *(p.classification)); }
    else { p.classification=nullptr; }
    if (j.HasMember("matchedPosition")) { p.matchedPosition = vanetza::asn1::allocate<MatchedPosition_t>(); from_json(j["matchedPosition"], *(p.matchedPosition)); }
    else { p.matchedPosition=nullptr; }
}



/*
*   AreaPolygon - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaPolygon& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("polyPointList", to_json((p.polyPointList), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, AreaPolygon& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["polyPointList"], (p.polyPointList));
}



/*
*   FreeSpaceArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceArea& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == FreeSpaceArea_PR_freeSpacePolygon) {
        json.AddMember("freeSpacePolygon", to_json(p.choice.freeSpacePolygon, allocator), allocator);
    } else if (p.present == FreeSpaceArea_PR_freeSpaceCircular) {
        json.AddMember("freeSpaceCircular", to_json(p.choice.freeSpaceCircular, allocator), allocator);
    } else if (p.present == FreeSpaceArea_PR_freeSpaceEllipse) {
        json.AddMember("freeSpaceEllipse", to_json(p.choice.freeSpaceEllipse, allocator), allocator);
    } else if (p.present == FreeSpaceArea_PR_freeSpaceRectangle) {
        json.AddMember("freeSpaceRectangle", to_json(p.choice.freeSpaceRectangle, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, FreeSpaceArea& p) {
    if (j.HasMember("freeSpacePolygon")) {
        p.present = FreeSpaceArea_PR_freeSpacePolygon;
        from_json(j["freeSpacePolygon"], p.choice.freeSpacePolygon);
    } else if (j.HasMember("freeSpaceCircular")) {
        p.present = FreeSpaceArea_PR_freeSpaceCircular;
        from_json(j["freeSpaceCircular"], p.choice.freeSpaceCircular);
    } else if (j.HasMember("freeSpaceEllipse")) {
        p.present = FreeSpaceArea_PR_freeSpaceEllipse;
        from_json(j["freeSpaceEllipse"], p.choice.freeSpaceEllipse);
    } else if (j.HasMember("freeSpaceRectangle")) {
        p.present = FreeSpaceArea_PR_freeSpaceRectangle;
        from_json(j["freeSpaceRectangle"], p.choice.freeSpaceRectangle);
    } else {
        p.present = FreeSpaceArea_PR_NOTHING;
    }
}

/*
*   SREM - Type SEQUENCE
*   From SREM-PDU-Descriptions - File TS103301v211-SREM.asn
*/

Value to_json(const SREM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("srm", to_json((p.srm), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SREM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["srm"], (p.srm));
}



/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SPAT& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("intersections", to_json((p.intersections), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    return json;
}

void from_json(const Value& j, SPAT& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    from_json(j["intersections"], (p.intersections));
    p.name=nullptr;
    p.regional=nullptr;
}



/*
*   SignalStatusMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusMessage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("second", to_json((p.second), allocator), allocator);
    json.AddMember("status", to_json((p.status), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.sequenceNumber != 0) json.AddMember("sequenceNumber", to_json(*(p.sequenceNumber), allocator), allocator);
    return json;
}

void from_json(const Value& j, SignalStatusMessage& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    from_json(j["second"], (p.second));
    if (j.HasMember("sequenceNumber")) { p.sequenceNumber = vanetza::asn1::allocate<MsgCount_t>(); from_json(j["sequenceNumber"], *(p.sequenceNumber)); }
    else { p.sequenceNumber=nullptr; }
    from_json(j["status"], (p.status));
    p.regional=nullptr;
}



/*
*   IntersectionGeometry - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometry& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("id", to_json((p.id), allocator), allocator);
    json.AddMember("revision", to_json((p.revision), allocator), allocator);
    json.AddMember("refPoint", to_json((p.refPoint), allocator), allocator);
    json.AddMember("laneSet", to_json((p.laneSet), allocator), allocator);
    if (p.laneWidth != 0) json.AddMember("laneWidth", to_json(*(p.laneWidth), allocator), allocator);
    if (p.speedLimits != 0) json.AddMember("speedLimits", to_json(*(p.speedLimits), allocator), allocator);
    return json;
}

void from_json(const Value& j, IntersectionGeometry& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["id"], (p.id));
    from_json(j["revision"], (p.revision));
    from_json(j["refPoint"], (p.refPoint));
    if (j.HasMember("laneWidth")) { p.laneWidth = vanetza::asn1::allocate<LaneWidth_t>(); from_json(j["laneWidth"], *(p.laneWidth)); }
    else { p.laneWidth=nullptr; }
    if (j.HasMember("speedLimits")) { p.speedLimits = vanetza::asn1::allocate<SpeedLimitList_t>(); from_json(j["speedLimits"], *(p.speedLimits)); }
    else { p.speedLimits=nullptr; }
    from_json(j["laneSet"], (p.laneSet));
    p.name=nullptr;
    p.preemptPriorityData=nullptr;
    p.regional=nullptr;
}



/*
*   IntersectionGeometryList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometryList& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const IntersectionGeometry_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, IntersectionGeometryList& p) {
    IntersectionGeometryList* p_tmp = vanetza::asn1::allocate<IntersectionGeometryList>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        IntersectionGeometry_t *element = vanetza::asn1::allocate<IntersectionGeometry_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   GddAttribute - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttribute& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == GddAttribute_PR_dtm) {
        json.AddMember("dtm", to_json(p.choice.dtm, allocator), allocator);
    } else if (p.present == GddAttribute_PR_edt) {
        json.AddMember("edt", to_json(p.choice.edt, allocator), allocator);
    } else if (p.present == GddAttribute_PR_dfl) {
        json.AddMember("dfl", to_json(p.choice.dfl, allocator), allocator);
    } else if (p.present == GddAttribute_PR_ved) {
        json.AddMember("ved", to_json(p.choice.ved, allocator), allocator);
    } else if (p.present == GddAttribute_PR_spe) {
        json.AddMember("spe", to_json(p.choice.spe, allocator), allocator);
    } else if (p.present == GddAttribute_PR_roi) {
        json.AddMember("roi", to_json(p.choice.roi, allocator), allocator);
    } else if (p.present == GddAttribute_PR_dbv) {
        json.AddMember("dbv", to_json(p.choice.dbv, allocator), allocator);
    } else if (p.present == GddAttribute_PR_ddd) {
        json.AddMember("ddd", to_json(p.choice.ddd, allocator), allocator);
    } else if (p.present == GddAttribute_PR_set) {
        json.AddMember("set", to_json(p.choice.set, allocator), allocator);
    } else if (p.present == GddAttribute_PR_nol) {
        json.AddMember("nol", to_json(p.choice.nol, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, GddAttribute& p) {
    if (j.HasMember("dtm")) {
        p.present = GddAttribute_PR_dtm;
        from_json(j["dtm"], p.choice.dtm);
    } else if (j.HasMember("edt")) {
        p.present = GddAttribute_PR_edt;
        from_json(j["edt"], p.choice.edt);
    } else if (j.HasMember("dfl")) {
        p.present = GddAttribute_PR_dfl;
        from_json(j["dfl"], p.choice.dfl);
    } else if (j.HasMember("ved")) {
        p.present = GddAttribute_PR_ved;
        from_json(j["ved"], p.choice.ved);
    } else if (j.HasMember("spe")) {
        p.present = GddAttribute_PR_spe;
        from_json(j["spe"], p.choice.spe);
    } else if (j.HasMember("roi")) {
        p.present = GddAttribute_PR_roi;
        from_json(j["roi"], p.choice.roi);
    } else if (j.HasMember("dbv")) {
        p.present = GddAttribute_PR_dbv;
        from_json(j["dbv"], p.choice.dbv);
    } else if (j.HasMember("ddd")) {
        p.present = GddAttribute_PR_ddd;
        from_json(j["ddd"], *p.choice.ddd);
    } else if (j.HasMember("set")) {
        p.present = GddAttribute_PR_set;
        from_json(j["set"], p.choice.set);
    } else if (j.HasMember("nol")) {
        p.present = GddAttribute_PR_nol;
        from_json(j["nol"], p.choice.nol);
    } else {
        p.present = GddAttribute_PR_NOTHING;
    }
}

/*
*   GeographicLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeographicLocationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("referencePosition", to_json((p.referencePosition), allocator), allocator);
    json.AddMember("parts", to_json((p.parts), allocator), allocator);
    if (p.referencePositionTime != 0) json.AddMember("referencePositionTime", to_json(*(p.referencePositionTime), allocator), allocator);
    if (p.referencePositionHeading != 0) json.AddMember("referencePositionHeading", to_json(*(p.referencePositionHeading), allocator), allocator);
    if (p.referencePositionSpeed != 0) json.AddMember("referencePositionSpeed", to_json(*(p.referencePositionSpeed), allocator), allocator);
    return json;
}

void from_json(const Value& j, GeographicLocationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["referencePosition"], (p.referencePosition));
    if (j.HasMember("referencePositionTime")) { p.referencePositionTime = vanetza::asn1::allocate<TimestampIts_t>(); from_json(j["referencePositionTime"], *(p.referencePositionTime)); }
    else { p.referencePositionTime=nullptr; }
    if (j.HasMember("referencePositionHeading")) { p.referencePositionHeading = vanetza::asn1::allocate<Heading_t>(); from_json(j["referencePositionHeading"], *(p.referencePositionHeading)); }
    else { p.referencePositionHeading=nullptr; }
    if (j.HasMember("referencePositionSpeed")) { p.referencePositionSpeed = vanetza::asn1::allocate<Speed_t>(); from_json(j["referencePositionSpeed"], *(p.referencePositionSpeed)); }
    else { p.referencePositionSpeed=nullptr; }
    from_json(j["parts"], (p.parts));
}



/*
*   RccPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RccPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("relevanceZoneIds", to_json((p.relevanceZoneIds), allocator), allocator);
    json.AddMember("roadType", to_json((p.roadType), allocator), allocator);
    json.AddMember("laneConfiguration", to_json((p.laneConfiguration), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, RccPart& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["relevanceZoneIds"], (p.relevanceZoneIds));
    from_json(j["roadType"], (p.roadType));
    from_json(j["laneConfiguration"], (p.laneConfiguration));
}



/*
*   TcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TcPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("relevanceZoneIds", to_json((p.relevanceZoneIds), allocator), allocator);
    json.AddMember("data", to_json((p.data), allocator), allocator);
    json.AddMember("iviType", to_json((p.ext1->iviType), allocator), allocator);
    if (p.detectionZoneIds != 0) json.AddMember("detectionZoneIds", to_json(*(p.detectionZoneIds), allocator), allocator);
    if (p.direction != 0) json.AddMember("direction", to_json(*(p.direction), allocator), allocator);
    if (p.driverAwarenessZoneIds != 0) json.AddMember("driverAwarenessZoneIds", to_json(*(p.driverAwarenessZoneIds), allocator), allocator);
    if (p.minimumAwarenessTime != 0) json.AddMember("minimumAwarenessTime", to_json(*(p.minimumAwarenessTime), allocator), allocator);
    if (p.applicableLanes != 0) json.AddMember("applicableLanes", to_json(*(p.applicableLanes), allocator), allocator);
    if (p.layoutId != 0) json.AddMember("layoutId", to_json(*(p.layoutId), allocator), allocator);
    if (p.preStoredlayoutId != 0) json.AddMember("preStoredlayoutId", to_json(*(p.preStoredlayoutId), allocator), allocator);
    if (p.text != 0) json.AddMember("text", to_json(*(p.text), allocator), allocator);
    if (p.ext1->laneStatus != 0) json.AddMember("laneStatus", to_json(*(p.ext1->laneStatus), allocator), allocator);
    if (p.ext1->vehicleCharacteristics != 0) json.AddMember("vehicleCharacteristics", to_json(*(p.ext1->vehicleCharacteristics), allocator), allocator);
    return json;
}

void from_json(const Value& j, TcPart& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("detectionZoneIds")) { p.detectionZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["detectionZoneIds"], *(p.detectionZoneIds)); }
    else { p.detectionZoneIds=nullptr; }
    from_json(j["relevanceZoneIds"], (p.relevanceZoneIds));
    if (j.HasMember("direction")) { p.direction = vanetza::asn1::allocate<Direction_t>(); from_json(j["direction"], *(p.direction)); }
    else { p.direction=nullptr; }
    if (j.HasMember("driverAwarenessZoneIds")) { p.driverAwarenessZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["driverAwarenessZoneIds"], *(p.driverAwarenessZoneIds)); }
    else { p.driverAwarenessZoneIds=nullptr; }
    if (j.HasMember("minimumAwarenessTime")) { p.minimumAwarenessTime = vanetza::asn1::allocate<long>(); from_json(j["minimumAwarenessTime"], *(p.minimumAwarenessTime)); }
    else { p.minimumAwarenessTime=nullptr; }
    if (j.HasMember("applicableLanes")) { p.applicableLanes = vanetza::asn1::allocate<LanePositions_t>(); from_json(j["applicableLanes"], *(p.applicableLanes)); }
    else { p.applicableLanes=nullptr; }
    if (j.HasMember("layoutId")) { p.layoutId = vanetza::asn1::allocate<long>(); from_json(j["layoutId"], *(p.layoutId)); }
    else { p.layoutId=nullptr; }
    if (j.HasMember("preStoredlayoutId")) { p.preStoredlayoutId = vanetza::asn1::allocate<long>(); from_json(j["preStoredlayoutId"], *(p.preStoredlayoutId)); }
    else { p.preStoredlayoutId=nullptr; }
    if (j.HasMember("text")) { p.text = vanetza::asn1::allocate<TextLines_t>(); from_json(j["text"], *(p.text)); }
    else { p.text=nullptr; }
    from_json(j["data"], (p.data));
    from_json(j["iviType"], (p.ext1->iviType));
    if (j.HasMember("laneStatus")) { p.ext1->laneStatus = vanetza::asn1::allocate<LaneStatus_t>(); from_json(j["laneStatus"], *(p.ext1->laneStatus)); }
    else { p.ext1->laneStatus=nullptr; }
    if (j.HasMember("vehicleCharacteristics")) { p.ext1->vehicleCharacteristics = vanetza::asn1::allocate<VehicleCharacteristicsList_t>(); from_json(j["vehicleCharacteristics"], *(p.ext1->vehicleCharacteristics)); }
    else { p.ext1->vehicleCharacteristics=nullptr; }
}



/*
*   ISO14823Attributes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attributes& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const ISO14823Attribute_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, ISO14823Attributes& p) {
    ISO14823Attributes* p_tmp = vanetza::asn1::allocate<ISO14823Attributes>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        ISO14823Attribute_t *element = vanetza::asn1::allocate<ISO14823Attribute_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AnyCatalogue - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AnyCatalogue& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("owner", to_json((p.owner), allocator), allocator);
    json.AddMember("version", to_json((p.version), allocator), allocator);
    json.AddMember("pictogramCode", to_json((p.pictogramCode), allocator), allocator);
    if (p.value != 0) json.AddMember("value", to_json(*(p.value), allocator), allocator);
    if (p.unit != 0) json.AddMember("unit", to_json(*(p.unit), allocator), allocator);
    if (p.attributes != 0) json.AddMember("attributes", to_json(*(p.attributes), allocator), allocator);
    return json;
}

void from_json(const Value& j, AnyCatalogue& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["owner"], (p.owner));
    from_json(j["version"], (p.version));
    from_json(j["pictogramCode"], (p.pictogramCode));
    if (j.HasMember("value")) { p.value = vanetza::asn1::allocate<long>(); from_json(j["value"], *(p.value)); }
    else { p.value=nullptr; }
    if (j.HasMember("unit")) { p.unit = vanetza::asn1::allocate<RSCUnit_t>(); from_json(j["unit"], *(p.unit)); }
    else { p.unit=nullptr; }
    if (j.HasMember("attributes")) { p.attributes = vanetza::asn1::allocate<ISO14823Attributes_t>(); from_json(j["attributes"], *(p.attributes)); }
    else { p.attributes=nullptr; }
}



/*
*   ISO14823Code - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pictogramCode", to_json((p.pictogramCode), allocator), allocator);
    if (p.attributes != 0) json.AddMember("attributes", to_json(*(p.attributes), allocator), allocator);
    return json;
}

void from_json(const Value& j, ISO14823Code& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["pictogramCode"], (p.pictogramCode));
    if (j.HasMember("attributes")) { p.attributes = vanetza::asn1::allocate<ISO14823Attributes_t>(); from_json(j["attributes"], *(p.attributes)); }
    else { p.attributes=nullptr; }
}



/*
*   RSCode::RSCode__code - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode::RSCode__code& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == RSCode__code_PR::RSCode__code_PR_viennaConvention) {
        json.AddMember("viennaConvention", to_json(p.choice.viennaConvention, allocator), allocator);
    } else if (p.present == RSCode__code_PR::RSCode__code_PR_iso14823) {
        json.AddMember("iso14823", to_json(p.choice.iso14823, allocator), allocator);
    } else if (p.present == RSCode__code_PR::RSCode__code_PR_itisCodes) {
        json.AddMember("itisCodes", to_json(p.choice.itisCodes, allocator), allocator);
    } else if (p.present == RSCode__code_PR::RSCode__code_PR_anyCatalogue) {
        json.AddMember("anyCatalogue", to_json(p.choice.anyCatalogue, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, RSCode::RSCode__code& p) {
    if (j.HasMember("viennaConvention")) {
        p.present = RSCode__code_PR::RSCode__code_PR_viennaConvention;
        from_json(j["viennaConvention"], p.choice.viennaConvention);
    } else if (j.HasMember("iso14823")) {
        p.present = RSCode__code_PR::RSCode__code_PR_iso14823;
        from_json(j["iso14823"], p.choice.iso14823);
    } else if (j.HasMember("itisCodes")) {
        p.present = RSCode__code_PR::RSCode__code_PR_itisCodes;
        from_json(j["itisCodes"], p.choice.itisCodes);
    } else if (j.HasMember("anyCatalogue")) {
        p.present = RSCode__code_PR::RSCode__code_PR_anyCatalogue;
        from_json(j["anyCatalogue"], p.choice.anyCatalogue);
    } else {
        p.present = RSCode__code_PR::RSCode__code_PR_NOTHING;
    }
}

/*
*   RSCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("code", to_json((p.code), allocator), allocator);
    if (p.layoutComponentId != 0) json.AddMember("layoutComponentId", to_json(*(p.layoutComponentId), allocator), allocator);
    return json;
}

void from_json(const Value& j, RSCode& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("layoutComponentId")) { p.layoutComponentId = vanetza::asn1::allocate<long>(); from_json(j["layoutComponentId"], *(p.layoutComponentId)); }
    else { p.layoutComponentId=nullptr; }
    from_json(j["code"], (p.code));
}



/*
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CoopAwareness& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("generationDeltaTime", to_json((p.generationDeltaTime), allocator), allocator);
    json.AddMember("camParameters", to_json((p.camParameters), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CoopAwareness& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["generationDeltaTime"], (p.generationDeltaTime));
    from_json(j["camParameters"], (p.camParameters));
}



/*
*   VruHighFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruHighFrequencyContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("heading", to_json((p.heading), allocator), allocator);
    json.AddMember("speed", to_json((p.speed), allocator), allocator);
    json.AddMember("longitudinalAcceleration", to_json((p.longitudinalAcceleration), allocator), allocator);
    if (p.curvature != 0) json.AddMember("curvature", to_json(*(p.curvature), allocator), allocator);
    if (p.curvatureCalculationMode != 0) json.AddMember("curvatureCalculationMode", to_json(*(p.curvatureCalculationMode), allocator), allocator);
    if (p.yawRate != 0) json.AddMember("yawRate", to_json(*(p.yawRate), allocator), allocator);
    if (p.lateralAcceleration != 0) json.AddMember("lateralAcceleration", to_json(*(p.lateralAcceleration), allocator), allocator);
    if (p.verticalAcceleration != 0) json.AddMember("verticalAcceleration", to_json(*(p.verticalAcceleration), allocator), allocator);
    if (p.vruLanePosition != 0) json.AddMember("vruLanePosition", to_json(*(p.vruLanePosition), allocator), allocator);
    if (p.environment != 0) json.AddMember("environment", to_json(*(p.environment), allocator), allocator);
    if (p.movementControl != 0) json.AddMember("movementControl", to_json(*(p.movementControl), allocator), allocator);
    if (p.orientation != 0) json.AddMember("orientation", to_json(*(p.orientation), allocator), allocator);
    if (p.rollAngle != 0) json.AddMember("rollAngle", to_json(*(p.rollAngle), allocator), allocator);
    if (p.deviceUsage != 0) json.AddMember("deviceUsage", to_json(*(p.deviceUsage), allocator), allocator);
    return json;
}

void from_json(const Value& j, VruHighFrequencyContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["heading"], (p.heading));
    from_json(j["speed"], (p.speed));
    from_json(j["longitudinalAcceleration"], (p.longitudinalAcceleration));
    if (j.HasMember("curvature")) { p.curvature = vanetza::asn1::allocate<Curvature_t>(); from_json(j["curvature"], *(p.curvature)); }
    else { p.curvature=nullptr; }
    if (j.HasMember("curvatureCalculationMode")) { p.curvatureCalculationMode = vanetza::asn1::allocate<CurvatureCalculationMode_t>(); from_json(j["curvatureCalculationMode"], *(p.curvatureCalculationMode)); }
    else { p.curvatureCalculationMode=nullptr; }
    if (j.HasMember("yawRate")) { p.yawRate = vanetza::asn1::allocate<YawRate_t>(); from_json(j["yawRate"], *(p.yawRate)); }
    else { p.yawRate=nullptr; }
    if (j.HasMember("lateralAcceleration")) { p.lateralAcceleration = vanetza::asn1::allocate<LateralAcceleration_t>(); from_json(j["lateralAcceleration"], *(p.lateralAcceleration)); }
    else { p.lateralAcceleration=nullptr; }
    if (j.HasMember("verticalAcceleration")) { p.verticalAcceleration = vanetza::asn1::allocate<VerticalAcceleration_t>(); from_json(j["verticalAcceleration"], *(p.verticalAcceleration)); }
    else { p.verticalAcceleration=nullptr; }
    if (j.HasMember("vruLanePosition")) { p.vruLanePosition = vanetza::asn1::allocate<VruLanePosition_t>(); from_json(j["vruLanePosition"], *(p.vruLanePosition)); }
    else { p.vruLanePosition=nullptr; }
    if (j.HasMember("environment")) { p.environment = vanetza::asn1::allocate<VruEnvironment_t>(); from_json(j["environment"], *(p.environment)); }
    else { p.environment=nullptr; }
    if (j.HasMember("movementControl")) { p.movementControl = vanetza::asn1::allocate<VruMovementControl_t>(); from_json(j["movementControl"], *(p.movementControl)); }
    else { p.movementControl=nullptr; }
    if (j.HasMember("orientation")) { p.orientation = vanetza::asn1::allocate<VruOrientation_t>(); from_json(j["orientation"], *(p.orientation)); }
    else { p.orientation=nullptr; }
    if (j.HasMember("rollAngle")) { p.rollAngle = vanetza::asn1::allocate<VruRollAngle_t>(); from_json(j["rollAngle"], *(p.rollAngle)); }
    else { p.rollAngle=nullptr; }
    if (j.HasMember("deviceUsage")) { p.deviceUsage = vanetza::asn1::allocate<VruDeviceUsage_t>(); from_json(j["deviceUsage"], *(p.deviceUsage)); }
    else { p.deviceUsage=nullptr; }
}



/*
*   ClusterBoundingBoxShape - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBoundingBoxShape& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ClusterBoundingBoxShape_PR_clusterRectangle) {
        json.AddMember("clusterRectangle", to_json(p.choice.clusterRectangle, allocator), allocator);
    } else if (p.present == ClusterBoundingBoxShape_PR_clusterCircle) {
        json.AddMember("clusterCircle", to_json(p.choice.clusterCircle, allocator), allocator);
    } else if (p.present == ClusterBoundingBoxShape_PR_clusterPolygon) {
        json.AddMember("clusterPolygon", to_json(p.choice.clusterPolygon, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ClusterBoundingBoxShape& p) {
    if (j.HasMember("clusterRectangle")) {
        p.present = ClusterBoundingBoxShape_PR_clusterRectangle;
        from_json(j["clusterRectangle"], p.choice.clusterRectangle);
    } else if (j.HasMember("clusterCircle")) {
        p.present = ClusterBoundingBoxShape_PR_clusterCircle;
        from_json(j["clusterCircle"], p.choice.clusterCircle);
    } else if (j.HasMember("clusterPolygon")) {
        p.present = ClusterBoundingBoxShape_PR_clusterPolygon;
        from_json(j["clusterPolygon"], p.choice.clusterPolygon);
    } else {
        p.present = ClusterBoundingBoxShape_PR_NOTHING;
    }
}

/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainer_t& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PerceivedObject_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, PerceivedObjectContainer_t& p) {
    PerceivedObjectContainer_t* p_tmp = vanetza::asn1::allocate<PerceivedObjectContainer_t>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PerceivedObject_t *element = vanetza::asn1::allocate<PerceivedObject_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   DetectionArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const DetectionArea& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == DetectionArea_PR_vehicleSensor) {
        json.AddMember("vehicleSensor", to_json(p.choice.vehicleSensor, allocator), allocator);
    } else if (p.present == DetectionArea_PR_stationarySensorRadial) {
        json.AddMember("stationarySensorRadial", to_json(p.choice.stationarySensorRadial, allocator), allocator);
    } else if (p.present == DetectionArea_PR_stationarySensorPolygon) {
        json.AddMember("stationarySensorPolygon", to_json(p.choice.stationarySensorPolygon, allocator), allocator);
    } else if (p.present == DetectionArea_PR_stationarySensorCircular) {
        json.AddMember("stationarySensorCircular", to_json(p.choice.stationarySensorCircular, allocator), allocator);
    } else if (p.present == DetectionArea_PR_stationarySensorEllipse) {
        json.AddMember("stationarySensorEllipse", to_json(p.choice.stationarySensorEllipse, allocator), allocator);
    } else if (p.present == DetectionArea_PR_stationarySensorRectangle) {
        json.AddMember("stationarySensorRectangle", to_json(p.choice.stationarySensorRectangle, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, DetectionArea& p) {
    if (j.HasMember("vehicleSensor")) {
        p.present = DetectionArea_PR_vehicleSensor;
        from_json(j["vehicleSensor"], p.choice.vehicleSensor);
    } else if (j.HasMember("stationarySensorRadial")) {
        p.present = DetectionArea_PR_stationarySensorRadial;
        from_json(j["stationarySensorRadial"], p.choice.stationarySensorRadial);
    } else if (j.HasMember("stationarySensorPolygon")) {
        p.present = DetectionArea_PR_stationarySensorPolygon;
        from_json(j["stationarySensorPolygon"], p.choice.stationarySensorPolygon);
    } else if (j.HasMember("stationarySensorCircular")) {
        p.present = DetectionArea_PR_stationarySensorCircular;
        from_json(j["stationarySensorCircular"], p.choice.stationarySensorCircular);
    } else if (j.HasMember("stationarySensorEllipse")) {
        p.present = DetectionArea_PR_stationarySensorEllipse;
        from_json(j["stationarySensorEllipse"], p.choice.stationarySensorEllipse);
    } else if (j.HasMember("stationarySensorRectangle")) {
        p.present = DetectionArea_PR_stationarySensorRectangle;
        from_json(j["stationarySensorRectangle"], p.choice.stationarySensorRectangle);
    } else {
        p.present = DetectionArea_PR_NOTHING;
    }
}

/*
*   FreeSpaceAddendum - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendum& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("freeSpaceConfidence", to_json((p.freeSpaceConfidence), allocator), allocator);
    json.AddMember("freeSpaceArea", to_json((p.freeSpaceArea), allocator), allocator);
    if (p.sensorIDList != 0) json.AddMember("sensorIDList", to_json(*(p.sensorIDList), allocator), allocator);
    return json;
}

void from_json(const Value& j, FreeSpaceAddendum& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["freeSpaceConfidence"], (p.freeSpaceConfidence));
    from_json(j["freeSpaceArea"], (p.freeSpaceArea));
    if (j.HasMember("sensorIDList")) { p.sensorIDList = vanetza::asn1::allocate<SensorIdList_t>(); from_json(j["sensorIDList"], *(p.sensorIDList)); }
    else { p.sensorIDList=nullptr; }
    
}



/*
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

Value to_json(const SPATEM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("spat", to_json((p.spat), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SPATEM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["spat"], (p.spat));
}



/*
*   SSEM - Type SEQUENCE
*   From SSEM-PDU-Descriptions - File TS103301v211-SSEM.asn
*/

Value to_json(const SSEM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("ssm", to_json((p.ssm), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, SSEM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["ssm"], (p.ssm));
}



/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MapData_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("msgIssueRevision", to_json((p.msgIssueRevision), allocator), allocator);
    if (p.timeStamp != 0) json.AddMember("timeStamp", to_json(*(p.timeStamp), allocator), allocator);
    if (p.layerType != 0) json.AddMember("layerType", to_json(*(p.layerType), allocator), allocator);
    if (p.layerID != 0) json.AddMember("layerID", to_json(*(p.layerID), allocator), allocator);
    if (p.intersections != 0) json.AddMember("intersections", to_json(*(p.intersections), allocator), allocator);
    if (p.roadSegments != 0) json.AddMember("roadSegments", to_json(*(p.roadSegments), allocator), allocator);
    if (p.dataParameters != 0) json.AddMember("dataParameters", to_json(*(p.dataParameters), allocator), allocator);
    if (p.restrictionList != 0) json.AddMember("restrictionList", to_json(*(p.restrictionList), allocator), allocator);
    return json;
}

void from_json(const Value& j, MapData_t& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("timeStamp")) { p.timeStamp = vanetza::asn1::allocate<MinuteOfTheYear_t>(); from_json(j["timeStamp"], *(p.timeStamp)); }
    else { p.timeStamp=nullptr; }
    from_json(j["msgIssueRevision"], (p.msgIssueRevision));
    if (j.HasMember("layerType")) { p.layerType = vanetza::asn1::allocate<LayerType_t>(); from_json(j["layerType"], *(p.layerType)); }
    else { p.layerType=nullptr; }
    if (j.HasMember("layerID")) { p.layerID = vanetza::asn1::allocate<LayerID_t>(); from_json(j["layerID"], *(p.layerID)); }
    else { p.layerID=nullptr; }
    if (j.HasMember("intersections")) { p.intersections = vanetza::asn1::allocate<IntersectionGeometryList_t>(); from_json(j["intersections"], *(p.intersections)); }
    else { p.intersections=nullptr; }
    if (j.HasMember("roadSegments")) { p.roadSegments = vanetza::asn1::allocate<RoadSegmentList_t>(); from_json(j["roadSegments"], *(p.roadSegments)); }
    else { p.roadSegments=nullptr; }
    if (j.HasMember("dataParameters")) { p.dataParameters = vanetza::asn1::allocate<DataParameters_t>(); from_json(j["dataParameters"], *(p.dataParameters)); }
    else { p.dataParameters=nullptr; }
    if (j.HasMember("restrictionList")) { p.restrictionList = vanetza::asn1::allocate<RestrictionClassList_t>(); from_json(j["restrictionList"], *(p.restrictionList)); }
    else { p.restrictionList=nullptr; }
    p.regional=nullptr;
}



/*
*   GddAttributes - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttributes& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const GddAttribute_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, GddAttributes& p) {
    GddAttributes* p_tmp = vanetza::asn1::allocate<GddAttributes>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        GddAttribute_t *element = vanetza::asn1::allocate<GddAttribute_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RoadConfigurationContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadConfigurationContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RccPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RoadConfigurationContainer& p) {
    RoadConfigurationContainer* p_tmp = vanetza::asn1::allocate<RoadConfigurationContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RccPart_t *element = vanetza::asn1::allocate<RccPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   TextContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const TcPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, TextContainer& p) {
    TextContainer* p_tmp = vanetza::asn1::allocate<TextContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        TcPart_t *element = vanetza::asn1::allocate<TcPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   RoadSignCodes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSignCodes& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const RSCode_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, RoadSignCodes& p) {
    RoadSignCodes* p_tmp = vanetza::asn1::allocate<RoadSignCodes>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        RSCode_t *element = vanetza::asn1::allocate<RSCode_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AutomatedVehicleRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRule& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("priority", to_json((p.priority), allocator), allocator);
    json.AddMember("allowedSaeAutomationLevels", to_json((p.allowedSaeAutomationLevels), allocator), allocator);
    if (p.minGapBetweenVehicles != 0) json.AddMember("minGapBetweenVehicles", to_json(*(p.minGapBetweenVehicles), allocator), allocator);
    if (p.recGapBetweenVehicles != 0) json.AddMember("recGapBetweenVehicles", to_json(*(p.recGapBetweenVehicles), allocator), allocator);
    if (p.automatedVehicleMaxSpeedLimit != 0) json.AddMember("automatedVehicleMaxSpeedLimit", to_json((*(p.automatedVehicleMaxSpeedLimit) != 16383) ? (double) *(p.automatedVehicleMaxSpeedLimit) / 100.0 : *(p.automatedVehicleMaxSpeedLimit), allocator), allocator);
    if (p.automatedVehicleMinSpeedLimit != 0) json.AddMember("automatedVehicleMinSpeedLimit", to_json((*(p.automatedVehicleMinSpeedLimit) != 16383) ? (double) *(p.automatedVehicleMinSpeedLimit) / 100.0 : *(p.automatedVehicleMinSpeedLimit), allocator), allocator);
    if (p.automatedVehicleSpeedRecommendation != 0) json.AddMember("automatedVehicleSpeedRecommendation", to_json((*(p.automatedVehicleSpeedRecommendation) != 16383) ? (double) *(p.automatedVehicleSpeedRecommendation) / 100.0 : *(p.automatedVehicleSpeedRecommendation), allocator), allocator);
    if (p.roadSignCodes != 0) json.AddMember("roadSignCodes", to_json(*(p.roadSignCodes), allocator), allocator);
    if (p.extraText != 0) json.AddMember("extraText", to_json(*(p.extraText), allocator), allocator);
    return json;
}

void from_json(const Value& j, AutomatedVehicleRule& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["priority"], (p.priority));
    from_json(j["allowedSaeAutomationLevels"], (p.allowedSaeAutomationLevels));
    if (j.HasMember("minGapBetweenVehicles")) { p.minGapBetweenVehicles = vanetza::asn1::allocate<GapBetweenVehicles_t>(); from_json(j["minGapBetweenVehicles"], *(p.minGapBetweenVehicles)); }
    else { p.minGapBetweenVehicles=nullptr; }
    if (j.HasMember("recGapBetweenVehicles")) { p.recGapBetweenVehicles = vanetza::asn1::allocate<GapBetweenVehicles_t>(); from_json(j["recGapBetweenVehicles"], *(p.recGapBetweenVehicles)); }
    else { p.recGapBetweenVehicles=nullptr; }
    double automatedVehicleMaxSpeedLimit; if (j.HasMember("automatedVehicleMaxSpeedLimit")) { p.automatedVehicleMaxSpeedLimit = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["automatedVehicleMaxSpeedLimit"], (automatedVehicleMaxSpeedLimit)); *(p.automatedVehicleMaxSpeedLimit) = ((automatedVehicleMaxSpeedLimit) != 16383) ? automatedVehicleMaxSpeedLimit * 100 : automatedVehicleMaxSpeedLimit; }
    else { p.automatedVehicleMaxSpeedLimit=nullptr; }
    double automatedVehicleMinSpeedLimit; if (j.HasMember("automatedVehicleMinSpeedLimit")) { p.automatedVehicleMinSpeedLimit = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["automatedVehicleMinSpeedLimit"], (automatedVehicleMinSpeedLimit)); *(p.automatedVehicleMinSpeedLimit) = ((automatedVehicleMinSpeedLimit) != 16383) ? automatedVehicleMinSpeedLimit * 100 : automatedVehicleMinSpeedLimit; }
    else { p.automatedVehicleMinSpeedLimit=nullptr; }
    double automatedVehicleSpeedRecommendation; if (j.HasMember("automatedVehicleSpeedRecommendation")) { p.automatedVehicleSpeedRecommendation = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["automatedVehicleSpeedRecommendation"], (automatedVehicleSpeedRecommendation)); *(p.automatedVehicleSpeedRecommendation) = ((automatedVehicleSpeedRecommendation) != 16383) ? automatedVehicleSpeedRecommendation * 100 : automatedVehicleSpeedRecommendation; }
    else { p.automatedVehicleSpeedRecommendation=nullptr; }
    if (j.HasMember("roadSignCodes")) { p.roadSignCodes = vanetza::asn1::allocate<RoadSignCodes_t>(); from_json(j["roadSignCodes"], *(p.roadSignCodes)); }
    else { p.roadSignCodes=nullptr; }
    if (j.HasMember("extraText")) { p.extraText = vanetza::asn1::allocate<ConstraintTextLines2_t>(); from_json(j["extraText"], *(p.extraText)); }
    else { p.extraText=nullptr; }
}



/*
*   PlatooningRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRule& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("priority", to_json((p.priority), allocator), allocator);
    json.AddMember("allowedSaeAutomationLevels", to_json((p.allowedSaeAutomationLevels), allocator), allocator);
    if (p.maxNoOfVehicles != 0) json.AddMember("maxNoOfVehicles", to_json(*(p.maxNoOfVehicles), allocator), allocator);
    if (p.maxLenghtOfPlatoon != 0) json.AddMember("maxLenghtOfPlatoon", to_json(*(p.maxLenghtOfPlatoon), allocator), allocator);
    if (p.minGapBetweenVehicles != 0) json.AddMember("minGapBetweenVehicles", to_json(*(p.minGapBetweenVehicles), allocator), allocator);
    if (p.platoonMaxSpeedLimit != 0) json.AddMember("platoonMaxSpeedLimit", to_json((*(p.platoonMaxSpeedLimit) != 16383) ? (double) *(p.platoonMaxSpeedLimit) / 100.0 : *(p.platoonMaxSpeedLimit), allocator), allocator);
    if (p.platoonMinSpeedLimit != 0) json.AddMember("platoonMinSpeedLimit", to_json((*(p.platoonMinSpeedLimit) != 16383) ? (double) *(p.platoonMinSpeedLimit) / 100.0 : *(p.platoonMinSpeedLimit), allocator), allocator);
    if (p.platoonSpeedRecommendation != 0) json.AddMember("platoonSpeedRecommendation", to_json((*(p.platoonSpeedRecommendation) != 16383) ? (double) *(p.platoonSpeedRecommendation) / 100.0 : *(p.platoonSpeedRecommendation), allocator), allocator);
    if (p.roadSignCodes != 0) json.AddMember("roadSignCodes", to_json(*(p.roadSignCodes), allocator), allocator);
    if (p.extraText != 0) json.AddMember("extraText", to_json(*(p.extraText), allocator), allocator);
    return json;
}

void from_json(const Value& j, PlatooningRule& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["priority"], (p.priority));
    from_json(j["allowedSaeAutomationLevels"], (p.allowedSaeAutomationLevels));
    if (j.HasMember("maxNoOfVehicles")) { p.maxNoOfVehicles = vanetza::asn1::allocate<MaxNoOfVehicles_t>(); from_json(j["maxNoOfVehicles"], *(p.maxNoOfVehicles)); }
    else { p.maxNoOfVehicles=nullptr; }
    if (j.HasMember("maxLenghtOfPlatoon")) { p.maxLenghtOfPlatoon = vanetza::asn1::allocate<MaxLenghtOfPlatoon_t>(); from_json(j["maxLenghtOfPlatoon"], *(p.maxLenghtOfPlatoon)); }
    else { p.maxLenghtOfPlatoon=nullptr; }
    if (j.HasMember("minGapBetweenVehicles")) { p.minGapBetweenVehicles = vanetza::asn1::allocate<GapBetweenVehicles_t>(); from_json(j["minGapBetweenVehicles"], *(p.minGapBetweenVehicles)); }
    else { p.minGapBetweenVehicles=nullptr; }
    double platoonMaxSpeedLimit; if (j.HasMember("platoonMaxSpeedLimit")) { p.platoonMaxSpeedLimit = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["platoonMaxSpeedLimit"], (platoonMaxSpeedLimit)); *(p.platoonMaxSpeedLimit) = ((platoonMaxSpeedLimit) != 16383) ? platoonMaxSpeedLimit * 100 : platoonMaxSpeedLimit; }
    else { p.platoonMaxSpeedLimit=nullptr; }
    double platoonMinSpeedLimit; if (j.HasMember("platoonMinSpeedLimit")) { p.platoonMinSpeedLimit = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["platoonMinSpeedLimit"], (platoonMinSpeedLimit)); *(p.platoonMinSpeedLimit) = ((platoonMinSpeedLimit) != 16383) ? platoonMinSpeedLimit * 100 : platoonMinSpeedLimit; }
    else { p.platoonMinSpeedLimit=nullptr; }
    double platoonSpeedRecommendation; if (j.HasMember("platoonSpeedRecommendation")) { p.platoonSpeedRecommendation = vanetza::asn1::allocate<SpeedValue_t>(); from_json(j["platoonSpeedRecommendation"], (platoonSpeedRecommendation)); *(p.platoonSpeedRecommendation) = ((platoonSpeedRecommendation) != 16383) ? platoonSpeedRecommendation * 100 : platoonSpeedRecommendation; }
    else { p.platoonSpeedRecommendation=nullptr; }
    if (j.HasMember("roadSignCodes")) { p.roadSignCodes = vanetza::asn1::allocate<RoadSignCodes_t>(); from_json(j["roadSignCodes"], *(p.roadSignCodes)); }
    else { p.roadSignCodes=nullptr; }
    if (j.HasMember("extraText")) { p.extraText = vanetza::asn1::allocate<ConstraintTextLines2_t>(); from_json(j["extraText"], *(p.extraText)); }
    else { p.extraText=nullptr; }
}



/*
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CAM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("cam", to_json((p.cam), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CAM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["cam"], (p.cam));
}



/*
*   VruClusterInformationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterInformationContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("clusterId", to_json((p.clusterId), allocator), allocator);
    json.AddMember("clusterBoundingBoxShape", to_json((p.clusterBoundingBoxShape), allocator), allocator);
    json.AddMember("clusterCardinalitySize", to_json((p.clusterCardinalitySize), allocator), allocator);
    json.AddMember("clusterProfiles", to_json_ClusterProfiles((p.clusterProfiles), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VruClusterInformationContainer& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["clusterId"], (p.clusterId));
    from_json(j["clusterBoundingBoxShape"], (p.clusterBoundingBoxShape));
    from_json(j["clusterCardinalitySize"], (p.clusterCardinalitySize));
    from_json_ClusterProfiles(j["clusterProfiles"],(p.clusterProfiles));
}



/*
*   SensorInformation - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformation& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("sensorID", to_json((p.sensorID), allocator), allocator);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    json.AddMember("detectionArea", to_json((p.detectionArea), allocator), allocator);
    if (p.freeSpaceConfidence != 0) json.AddMember("freeSpaceConfidence", to_json(*(p.freeSpaceConfidence), allocator), allocator);
    return json;
}

void from_json(const Value& j, SensorInformation& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["sensorID"], (p.sensorID));
    from_json(j["type"], (p.type));
    from_json(j["detectionArea"], (p.detectionArea));
    if (j.HasMember("freeSpaceConfidence")) { p.freeSpaceConfidence = vanetza::asn1::allocate<FreeSpaceConfidence_t>(); from_json(j["freeSpaceConfidence"], *(p.freeSpaceConfidence)); }
    else { p.freeSpaceConfidence=nullptr; }
}



/*
*   FreeSpaceAddendumContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendumContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const FreeSpaceAddendum_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, FreeSpaceAddendumContainer& p) {
    FreeSpaceAddendumContainer* p_tmp = vanetza::asn1::allocate<FreeSpaceAddendumContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        FreeSpaceAddendum_t *element = vanetza::asn1::allocate<FreeSpaceAddendum_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

Value to_json(const MAPEM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("map", to_json((p.map), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, MAPEM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["map"], (p.map));
}



/*
*   GddStructure - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("pictogramCode", to_json((p.pictogramCode), allocator), allocator);
    if (p.attributes != 0) json.AddMember("attributes", to_json(*(p.attributes), allocator), allocator);
    return json;
}

void from_json(const Value& j, GddStructure& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["pictogramCode"], (p.pictogramCode));
    if (j.HasMember("attributes")) { p.attributes = vanetza::asn1::allocate<GddAttributes_t>(); from_json(j["attributes"], *(p.attributes)); }
    else { p.attributes=nullptr; }
}



/*
*   GicPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GicPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("iviType", to_json((p.iviType), allocator), allocator);
    json.AddMember("roadSignCodes", to_json((p.roadSignCodes), allocator), allocator);
    if (p.detectionZoneIds != 0) json.AddMember("detectionZoneIds", to_json(*(p.detectionZoneIds), allocator), allocator);
    if (p.its_Rrid != 0) json.AddMember("its-Rrid", to_json(*(p.its_Rrid), allocator), allocator);
    if (p.relevanceZoneIds != 0) json.AddMember("relevanceZoneIds", to_json(*(p.relevanceZoneIds), allocator), allocator);
    if (p.direction != 0) json.AddMember("direction", to_json(*(p.direction), allocator), allocator);
    if (p.driverAwarenessZoneIds != 0) json.AddMember("driverAwarenessZoneIds", to_json(*(p.driverAwarenessZoneIds), allocator), allocator);
    if (p.minimumAwarenessTime != 0) json.AddMember("minimumAwarenessTime", to_json(*(p.minimumAwarenessTime), allocator), allocator);
    if (p.applicableLanes != 0) json.AddMember("applicableLanes", to_json(*(p.applicableLanes), allocator), allocator);
    if (p.iviPurpose != 0) json.AddMember("iviPurpose", to_json(*(p.iviPurpose), allocator), allocator);
    if (p.laneStatus != 0) json.AddMember("laneStatus", to_json(*(p.laneStatus), allocator), allocator);
    if (p.vehicleCharacteristics != 0) json.AddMember("vehicleCharacteristics", to_json(*(p.vehicleCharacteristics), allocator), allocator);
    if (p.driverCharacteristics != 0) json.AddMember("driverCharacteristics", to_json(*(p.driverCharacteristics), allocator), allocator);
    if (p.layoutId != 0) json.AddMember("layoutId", to_json(*(p.layoutId), allocator), allocator);
    if (p.preStoredlayoutId != 0) json.AddMember("preStoredlayoutId", to_json(*(p.preStoredlayoutId), allocator), allocator);
    if (p.extraText != 0) json.AddMember("extraText", to_json(*(p.extraText), allocator), allocator);
    return json;
}

void from_json(const Value& j, GicPart& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("detectionZoneIds")) { p.detectionZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["detectionZoneIds"], *(p.detectionZoneIds)); }
    else { p.detectionZoneIds=nullptr; }
    if (j.HasMember("its-Rrid")) { p.its_Rrid = vanetza::asn1::allocate<VarLengthNumber_t>(); from_json(j["its-Rrid"], *(p.its_Rrid)); }
    else { p.its_Rrid=nullptr; }
    if (j.HasMember("relevanceZoneIds")) { p.relevanceZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["relevanceZoneIds"], *(p.relevanceZoneIds)); }
    else { p.relevanceZoneIds=nullptr; }
    if (j.HasMember("direction")) { p.direction = vanetza::asn1::allocate<Direction_t>(); from_json(j["direction"], *(p.direction)); }
    else { p.direction=nullptr; }
    if (j.HasMember("driverAwarenessZoneIds")) { p.driverAwarenessZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["driverAwarenessZoneIds"], *(p.driverAwarenessZoneIds)); }
    else { p.driverAwarenessZoneIds=nullptr; }
    if (j.HasMember("minimumAwarenessTime")) { p.minimumAwarenessTime = vanetza::asn1::allocate<long>(); from_json(j["minimumAwarenessTime"], *(p.minimumAwarenessTime)); }
    else { p.minimumAwarenessTime=nullptr; }
    if (j.HasMember("applicableLanes")) { p.applicableLanes = vanetza::asn1::allocate<LanePositions_t>(); from_json(j["applicableLanes"], *(p.applicableLanes)); }
    else { p.applicableLanes=nullptr; }
    from_json(j["iviType"], (p.iviType));
    if (j.HasMember("iviPurpose")) { p.iviPurpose = vanetza::asn1::allocate<IviPurpose_t>(); from_json(j["iviPurpose"], *(p.iviPurpose)); }
    else { p.iviPurpose=nullptr; }
    if (j.HasMember("laneStatus")) { p.laneStatus = vanetza::asn1::allocate<LaneStatus_t>(); from_json(j["laneStatus"], *(p.laneStatus)); }
    else { p.laneStatus=nullptr; }
    if (j.HasMember("vehicleCharacteristics")) { p.vehicleCharacteristics = vanetza::asn1::allocate<VehicleCharacteristicsList_t>(); from_json(j["vehicleCharacteristics"], *(p.vehicleCharacteristics)); }
    else { p.vehicleCharacteristics=nullptr; }
    if (j.HasMember("driverCharacteristics")) { p.driverCharacteristics = vanetza::asn1::allocate<IVI_DriverCharacteristics_t>(); from_json(j["driverCharacteristics"], *(p.driverCharacteristics)); }
    else { p.driverCharacteristics=nullptr; }
    if (j.HasMember("layoutId")) { p.layoutId = vanetza::asn1::allocate<long>(); from_json(j["layoutId"], *(p.layoutId)); }
    else { p.layoutId=nullptr; }
    if (j.HasMember("preStoredlayoutId")) { p.preStoredlayoutId = vanetza::asn1::allocate<long>(); from_json(j["preStoredlayoutId"], *(p.preStoredlayoutId)); }
    else { p.preStoredlayoutId=nullptr; }
    from_json(j["roadSignCodes"], (p.roadSignCodes));
    if (j.HasMember("extraText")) { p.extraText = vanetza::asn1::allocate<ConstraintTextLines1_t>(); from_json(j["extraText"], *(p.extraText)); }
    else { p.extraText=nullptr; }
}



/*
*   AutomatedVehicleRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRules& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const AutomatedVehicleRule_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, AutomatedVehicleRules& p) {
    AutomatedVehicleRules* p_tmp = vanetza::asn1::allocate<AutomatedVehicleRules>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        AutomatedVehicleRule_t *element = vanetza::asn1::allocate<AutomatedVehicleRule_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   PlatooningRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRules& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const PlatooningRule_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, PlatooningRules& p) {
    PlatooningRules* p_tmp = vanetza::asn1::allocate<PlatooningRules>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        PlatooningRule_t *element = vanetza::asn1::allocate<PlatooningRule_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VamParameters - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VamParameters& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("basicContainer", to_json((p.basicContainer), allocator), allocator);
    if (p.vruHighFrequencyContainer != 0) json.AddMember("vruHighFrequencyContainer", to_json(*(p.vruHighFrequencyContainer), allocator), allocator);
    if (p.vruLowFrequencyContainer != 0) json.AddMember("vruLowFrequencyContainer", to_json(*(p.vruLowFrequencyContainer), allocator), allocator);
    if (p.vruClusterInformationContainer != 0) json.AddMember("vruClusterInformationContainer", to_json(*(p.vruClusterInformationContainer), allocator), allocator);
    if (p.vruClusterOperationContainer != 0) json.AddMember("vruClusterOperationContainer", to_json(*(p.vruClusterOperationContainer), allocator), allocator);
    if (p.vruMotionPredictionContainer != 0) json.AddMember("vruMotionPredictionContainer", to_json(*(p.vruMotionPredictionContainer), allocator), allocator);
    return json;
}

void from_json(const Value& j, VamParameters& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["basicContainer"], (p.basicContainer));
    if (j.HasMember("vruHighFrequencyContainer")) { p.vruHighFrequencyContainer = vanetza::asn1::allocate<VruHighFrequencyContainer_t>(); from_json(j["vruHighFrequencyContainer"], *(p.vruHighFrequencyContainer)); }
    else { p.vruHighFrequencyContainer=nullptr; }
    if (j.HasMember("vruLowFrequencyContainer")) { p.vruLowFrequencyContainer = vanetza::asn1::allocate<VruLowFrequencyContainer_t>(); from_json(j["vruLowFrequencyContainer"], *(p.vruLowFrequencyContainer)); }
    else { p.vruLowFrequencyContainer=nullptr; }
    if (j.HasMember("vruClusterInformationContainer")) { p.vruClusterInformationContainer = vanetza::asn1::allocate<VruClusterInformationContainer_t>(); from_json(j["vruClusterInformationContainer"], *(p.vruClusterInformationContainer)); }
    else { p.vruClusterInformationContainer=nullptr; }
    if (j.HasMember("vruClusterOperationContainer")) { p.vruClusterOperationContainer = vanetza::asn1::allocate<VruClusterOperationContainer_t>(); from_json(j["vruClusterOperationContainer"], *(p.vruClusterOperationContainer)); }
    else { p.vruClusterOperationContainer=nullptr; }
    if (j.HasMember("vruMotionPredictionContainer")) { p.vruMotionPredictionContainer = vanetza::asn1::allocate<VruMotionPredictionContainer_t>(); from_json(j["vruMotionPredictionContainer"], *(p.vruMotionPredictionContainer)); }
    else { p.vruMotionPredictionContainer=nullptr; }
}



/*
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformationContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const SensorInformation_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, SensorInformationContainer& p) {
    SensorInformationContainer* p_tmp = vanetza::asn1::allocate<SensorInformationContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        SensorInformation_t *element = vanetza::asn1::allocate<SensorInformation_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   GeneralIviContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeneralIviContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const GicPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, GeneralIviContainer& p) {
    GeneralIviContainer* p_tmp = vanetza::asn1::allocate<GeneralIviContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        GicPart_t *element = vanetza::asn1::allocate<GicPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   AvcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AvcPart& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("relevanceZoneIds", to_json((p.relevanceZoneIds), allocator), allocator);
    if (p.detectionZoneIds != 0) json.AddMember("detectionZoneIds", to_json(*(p.detectionZoneIds), allocator), allocator);
    if (p.direction != 0) json.AddMember("direction", to_json(*(p.direction), allocator), allocator);
    if (p.applicableLanes != 0) json.AddMember("applicableLanes", to_json(*(p.applicableLanes), allocator), allocator);
    if (p.vehicleCharacteristics != 0) json.AddMember("vehicleCharacteristics", to_json(*(p.vehicleCharacteristics), allocator), allocator);
    if (p.automatedVehicleRules != 0) json.AddMember("automatedVehicleRules", to_json(*(p.automatedVehicleRules), allocator), allocator);
    if (p.platooningRules != 0) json.AddMember("platooningRules", to_json(*(p.platooningRules), allocator), allocator);
    return json;
}

void from_json(const Value& j, AvcPart& p) {
    p._asn_ctx.ptr = nullptr;
    if (j.HasMember("detectionZoneIds")) { p.detectionZoneIds = vanetza::asn1::allocate<ZoneIds_t>(); from_json(j["detectionZoneIds"], *(p.detectionZoneIds)); }
    else { p.detectionZoneIds=nullptr; }
    from_json(j["relevanceZoneIds"], (p.relevanceZoneIds));
    if (j.HasMember("direction")) { p.direction = vanetza::asn1::allocate<Direction_t>(); from_json(j["direction"], *(p.direction)); }
    else { p.direction=nullptr; }
    if (j.HasMember("applicableLanes")) { p.applicableLanes = vanetza::asn1::allocate<LanePositions_t>(); from_json(j["applicableLanes"], *(p.applicableLanes)); }
    else { p.applicableLanes=nullptr; }
    if (j.HasMember("vehicleCharacteristics")) { p.vehicleCharacteristics = vanetza::asn1::allocate<VehicleCharacteristicsList_t>(); from_json(j["vehicleCharacteristics"], *(p.vehicleCharacteristics)); }
    else { p.vehicleCharacteristics=nullptr; }
    if (j.HasMember("automatedVehicleRules")) { p.automatedVehicleRules = vanetza::asn1::allocate<AutomatedVehicleRules_t>(); from_json(j["automatedVehicleRules"], *(p.automatedVehicleRules)); }
    else { p.automatedVehicleRules=nullptr; }
    if (j.HasMember("platooningRules")) { p.platooningRules = vanetza::asn1::allocate<PlatooningRules_t>(); from_json(j["platooningRules"], *(p.platooningRules)); }
    else { p.platooningRules=nullptr; }
}



/*
*   VruAwareness - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruAwareness& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("generationDeltaTime", to_json((p.generationDeltaTime), allocator), allocator);
    json.AddMember("vamParameters", to_json((p.vamParameters), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VruAwareness& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["generationDeltaTime"], (p.generationDeltaTime));
    from_json(j["vamParameters"], (p.vamParameters));
}



/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmParameters& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("managementContainer", to_json((p.managementContainer), allocator), allocator);
    json.AddMember("numberOfPerceivedObjects", to_json((p.numberOfPerceivedObjects), allocator), allocator);
    if (p.stationDataContainer != 0) json.AddMember("stationDataContainer", to_json(*(p.stationDataContainer), allocator), allocator);
    if (p.sensorInformationContainer != 0) json.AddMember("sensorInformationContainer", to_json(*(p.sensorInformationContainer), allocator), allocator);
    if (p.perceivedObjectContainer != 0) json.AddMember("perceivedObjectContainer", to_json(*(p.perceivedObjectContainer), allocator), allocator);
    if (p.freeSpaceAddendumContainer != 0) json.AddMember("freeSpaceAddendumContainer", to_json(*(p.freeSpaceAddendumContainer), allocator), allocator);
    return json;
}

void from_json(const Value& j, CpmParameters& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["managementContainer"], (p.managementContainer));
    if (j.HasMember("stationDataContainer")) { p.stationDataContainer = vanetza::asn1::allocate<StationDataContainer_t>(); from_json(j["stationDataContainer"], *(p.stationDataContainer)); }
    else { p.stationDataContainer=nullptr; }
    if (j.HasMember("sensorInformationContainer")) { p.sensorInformationContainer = vanetza::asn1::allocate<SensorInformationContainer_t>(); from_json(j["sensorInformationContainer"], *(p.sensorInformationContainer)); }
    else { p.sensorInformationContainer=nullptr; }
    if (j.HasMember("perceivedObjectContainer")) { p.perceivedObjectContainer = vanetza::asn1::allocate<PerceivedObjectContainer_t>(); from_json(j["perceivedObjectContainer"], *(p.perceivedObjectContainer)); }
    else { p.perceivedObjectContainer=nullptr; }
    if (j.HasMember("freeSpaceAddendumContainer")) { p.freeSpaceAddendumContainer = vanetza::asn1::allocate<FreeSpaceAddendumContainer_t>(); from_json(j["freeSpaceAddendumContainer"], *(p.freeSpaceAddendumContainer)); }
    else { p.freeSpaceAddendumContainer=nullptr; }
    from_json(j["numberOfPerceivedObjects"], (p.numberOfPerceivedObjects));
}



/*
*   IviContainer - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainer& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == IviContainer_PR_glc) {
        json.AddMember("glc", to_json(p.choice.glc, allocator), allocator);
    } else if (p.present == IviContainer_PR_giv) {
        json.AddMember("giv", to_json(p.choice.giv, allocator), allocator);
    } else if (p.present == IviContainer_PR_rcc) {
        json.AddMember("rcc", to_json(p.choice.rcc, allocator), allocator);
    } else if (p.present == IviContainer_PR_tc) {
        json.AddMember("tc", to_json(p.choice.tc, allocator), allocator);
    } else if (p.present == IviContainer_PR_lac) {
        json.AddMember("lac", to_json(p.choice.lac, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, IviContainer& p) {
    if (j.HasMember("glc")) {
        p.present = IviContainer_PR_glc;
        from_json(j["glc"], p.choice.glc);
    } else if (j.HasMember("giv")) {
        p.present = IviContainer_PR_giv;
        from_json(j["giv"], p.choice.giv);
    } else if (j.HasMember("rcc")) {
        p.present = IviContainer_PR_rcc;
        from_json(j["rcc"], p.choice.rcc);
    } else if (j.HasMember("tc")) {
        p.present = IviContainer_PR_tc;
        from_json(j["tc"], p.choice.tc);
    } else if (j.HasMember("lac")) {
        p.present = IviContainer_PR_lac;
        from_json(j["lac"], p.choice.lac);
    } else {
        p.present = IviContainer_PR_NOTHING;
    }
}

/*
*   AutomatedVehicleContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleContainer& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const AvcPart_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, AutomatedVehicleContainer& p) {
    AutomatedVehicleContainer* p_tmp = vanetza::asn1::allocate<AutomatedVehicleContainer>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        AvcPart_t *element = vanetza::asn1::allocate<AvcPart_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   VAM - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VAM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("vam", to_json((p.vam), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, VAM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["vam"], (p.vam));
}



/*
*   CollectivePerceptionMessage - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CollectivePerceptionMessage& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("generationDeltaTime", to_json((p.generationDeltaTime), allocator), allocator);
    json.AddMember("cpmParameters", to_json((p.cpmParameters), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CollectivePerceptionMessage& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["generationDeltaTime"], (p.generationDeltaTime));
    from_json(j["cpmParameters"], (p.cpmParameters));
}



/*
*   IviContainers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainers& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        const IviContainer_t po = *(p.list.array[i]);
        Value obj = to_json(po, allocator);
        json.PushBack(obj, allocator);
    }
    return json;
}

void from_json(const Value& j, IviContainers& p) {
    IviContainers* p_tmp = vanetza::asn1::allocate<IviContainers>();
    for (SizeType i = 0; i < j.Size(); i++)
    {
        const Value& item = j[i];
        IviContainer_t *element = vanetza::asn1::allocate<IviContainer_t>();
        from_json(item, *element);
        asn_set_add(&(p_tmp->list), element);
    }
    p = *p_tmp;
    delete p_tmp;
}

/*
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CPM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("cpm", to_json((p.cpm), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, CPM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["cpm"], (p.cpm));
}



/*
*   IviStructure - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviStructure& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("mandatory", to_json((p.mandatory), allocator), allocator);
    if (p.optional != 0) json.AddMember("optional", to_json(*(p.optional), allocator), allocator);
    return json;
}

void from_json(const Value& j, IviStructure& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["mandatory"], (p.mandatory));
    if (j.HasMember("optional")) { p.optional = vanetza::asn1::allocate<IviContainers_t>(); from_json(j["optional"], *(p.optional)); }
    else { p.optional=nullptr; }
}



/*
*   IVIM - Type SEQUENCE
*   From IVIM-PDU-Descriptions - File TS103301v211-IVIM.asn
*/

Value to_json(const IVIM& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("header", to_json((p.header), allocator), allocator);
    json.AddMember("ivi", to_json((p.ivi), allocator), allocator);
    
    return json;
}

void from_json(const Value& j, IVIM& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["header"], (p.header));
    from_json(j["ivi"], (p.ivi));
}


