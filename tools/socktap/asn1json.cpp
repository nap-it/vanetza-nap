/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2023-07-10 10:11:09.799125
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
*   PtActivationData - Type OCTET STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PtActivationData_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, PtActivationData_t& p) {
    // TODO
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
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeed& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    json.AddMember("type", to_json((p.type), allocator), allocator);
    if (p.speed != 0) json.AddMember("speed", to_json(*(p.speed), allocator), allocator);
    if (p.confidence != 0) json.AddMember("confidence", to_json((*(p.confidence) != 126 && *(p.confidence) != 127) ? (double) *(p.confidence) / 100.0 : *(p.confidence), allocator), allocator);
    if (p.distance != 0) json.AddMember("distance", to_json(*(p.distance), allocator), allocator);
    if (p.Class != 0) json.AddMember("class", to_json(*(p.Class), allocator), allocator);
    return json;
}

void from_json(const Value& j, AdvisorySpeed& p) {
    p._asn_ctx.ptr = nullptr;
    from_json(j["type"], (p.type));
    if (j.HasMember("speed")) { p.speed = vanetza::asn1::allocate<SpeedAdvice_t>(); from_json(j["speed"], *(p.speed)); }
    else { p.speed=nullptr; }
    double confidence; if (j.HasMember("confidence")) { p.confidence = vanetza::asn1::allocate<SpeedConfidence_t>(); from_json(j["confidence"], (confidence)); *(p.confidence) = ((confidence) != 126 && (confidence) != 127) ? confidence * 100 : confidence; }
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
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetXaxis& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ComputedLane__offsetXaxis_PR_small) {
        json.AddMember("small", to_json(p.choice.small, allocator), allocator);
    } else if (p.present == ComputedLane__offsetXaxis_PR_large) {
        json.AddMember("large", to_json(p.choice.large, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ComputedLane::ComputedLane__offsetXaxis& p) {
    if (j.HasMember("small")) {
        p.present = ComputedLane__offsetXaxis_PR_small;
        from_json(j["small"], p.choice.small);
    } else if (j.HasMember("large")) {
        p.present = ComputedLane__offsetXaxis_PR_large;
        from_json(j["large"], p.choice.large);
    } else {
        p.present = ComputedLane__offsetXaxis_PR_NOTHING;
    }
}

/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetYaxis& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if (p.present == ComputedLane__offsetYaxis_PR_small) {
        json.AddMember("small", to_json(p.choice.small, allocator), allocator);
    } else if (p.present == ComputedLane__offsetYaxis_PR_large) {
        json.AddMember("large", to_json(p.choice.large, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ComputedLane::ComputedLane__offsetYaxis& p) {
    if (j.HasMember("small")) {
        p.present = ComputedLane__offsetYaxis_PR_small;
        from_json(j["small"], p.choice.small);
    } else if (j.HasMember("large")) {
        p.present = ComputedLane__offsetYaxis_PR_large;
        from_json(j["large"], p.choice.large);
    } else {
        p.present = ComputedLane__offsetYaxis_PR_NOTHING;
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
*   Node-XY-20b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
    if (p.present == ObjectClass__class_PR_vehicle) {
        json.AddMember("vehicle", to_json(p.choice.vehicle, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR_person) {
        json.AddMember("person", to_json(p.choice.person, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR_animal) {
        json.AddMember("animal", to_json(p.choice.animal, allocator), allocator);
    } else if (p.present == ObjectClass__class_PR_other) {
        json.AddMember("other", to_json(p.choice.other, allocator), allocator);
    }
    return json;
}

void from_json(const Value& j, ObjectClass::ObjectClass__class& p) {
    if (j.HasMember("vehicle")) {
        p.present = ObjectClass__class_PR_vehicle;
        from_json(j["vehicle"], p.choice.vehicle);
    } else if (j.HasMember("person")) {
        p.present = ObjectClass__class_PR_person;
        from_json(j["person"], p.choice.person);
    } else if (j.HasMember("animal")) {
        p.present = ObjectClass__class_PR_animal;
        from_json(j["animal"], p.choice.animal);
    } else if (j.HasMember("other")) {
        p.present = ObjectClass__class_PR_other;
        from_json(j["other"], p.choice.other);
    } else {
        p.present = ObjectClass__class_PR_NOTHING;
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
*   NodeXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
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


