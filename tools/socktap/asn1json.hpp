/*
*   JSON marshalling and unmarshalling functions for use by RapidJSON
*   Auto-generated from the asn1 directory by asn1json.py on 2024-03-20 04:52:43.945633
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <vanetza/asn1/cam.hpp>
#include <vanetza/asn1/denm.hpp>
#include <vanetza/asn1/cpm.hpp>
#include <vanetza/asn1/vam.hpp>
#include <vanetza/asn1/spatem.hpp>
#include <vanetza/asn1/mapem.hpp>
#include <vanetza/asn1/srem.hpp>
#include <vanetza/asn1/ssem.hpp>
#include <vanetza/asn1/ivim.hpp>
#include <vanetza/asn1/rtcmem.hpp>
#include <vanetza/asn1/evcsnm.hpp>
#include <vanetza/asn1/evrsrm.hpp>
#include <vanetza/asn1/imzm.hpp>
#include <vanetza/asn1/tistpgm.hpp>
#include <vanetza/asn1/mcm.hpp>

#include <vanetza/asn1/its/NodeXY.h>
#include <vanetza/asn1/its/VehicleID.h>
#include <vanetza/asn1/its/TransitVehicleStatus.h>
#include <vanetza/asn1/its/TransmissionAndSpeed.h>
#include <vanetza/asn1/its/DigitalMap.h>
#include <vanetza/asn1/its/Position3D.h>
#include <vanetza/asn1/its/IntersectionAccessPoint.h>
#include <vanetza/asn1/its/ComputedLane.h>
#include <vanetza/asn1/its/AdvisorySpeedList.h>
#include <vanetza/asn1/its/ConnectionManeuverAssist.h>
#include <vanetza/asn1/its/DataParameters.h>
#include <vanetza/asn1/its/EnabledLaneList.h>
#include <vanetza/asn1/its/CS1.h>
#include <vanetza/asn1/its/CS2.h>
#include <vanetza/asn1/its/CS3.h>
#include <vanetza/asn1/its/CS4.h>
#include <vanetza/asn1/its/CS5.h>
#include <vanetza/asn1/its/CS7.h>
#include <vanetza/asn1/its/CS8.h>
#include <vanetza/asn1/its/ServiceNumber.h>
#include <vanetza/asn1/its/GeoGraphicalLimit.h>
#include <vanetza/asn1/its/LicPlateNumber.h>
#include <vanetza/asn1/its/TaxCode.h>
#include <vanetza/asn1/its/AviEriDateTime.h>
#include <vanetza/asn1/its/ServiceApplicationLimit.h>
#include <vanetza/asn1/its/FreightContainerData.h>
#include <vanetza/asn1/its/AddRq.h>
#include <vanetza/asn1/its/ChannelRq.h>
#include <vanetza/asn1/its/ChannelRs.h>
#include <vanetza/asn1/its/SubRq.h>
#include <vanetza/asn1/its/ContractAuthenticator.h>
#include <vanetza/asn1/its/DateCompact.h>
#include <vanetza/asn1/its/Engine.h>
#include <vanetza/asn1/its/EquipmentOBUId.h>
#include <vanetza/asn1/its/EquipmentStatus.h>
#include <vanetza/asn1/its/ICC-Id.h>
#include <vanetza/asn1/its/LPN.h>
#include <vanetza/asn1/its/SignedValue.h>
#include <vanetza/asn1/its/PaymentSecurityData.h>
#include <vanetza/asn1/its/PayUnit.h>
#include <vanetza/asn1/its/PersonalAccountNumber.h>
#include <vanetza/asn1/its/PurseBalance.h>
#include <vanetza/asn1/its/ReceiptOBUId.h>
#include <vanetza/asn1/its/ReceiptAuthenticator.h>
#include <vanetza/asn1/its/ReceiptText.h>
#include <vanetza/asn1/its/ResultFin.h>
#include <vanetza/asn1/its/SessionClass.h>
#include <vanetza/asn1/its/ReceiptContract.h>
#include <vanetza/asn1/its/SessionLocation.h>
#include <vanetza/asn1/its/DateAndTime.h>
#include <vanetza/asn1/its/ItsStationPosition.h>
#include <vanetza/asn1/its/SignalHeadLocation.h>
#include <vanetza/asn1/its/ItsStationPositionList.h>
#include <vanetza/asn1/its/SignalHeadLocationList.h>
#include <vanetza/asn1/its/CurrentVehicleConfiguration.h>
#include <vanetza/asn1/its/ManouevreResponse.h>
#include <vanetza/asn1/its/ActualNumberOfPassengers.h>
#include <vanetza/asn1/its/AxleWeightLimits.h>
#include <vanetza/asn1/its/AddRq.h>
#include <vanetza/asn1/its/ChannelId.h>
#include <vanetza/asn1/its/ChannelRq.h>
#include <vanetza/asn1/its/ChannelRs.h>
#include <vanetza/asn1/its/CopyRq.h>
#include <vanetza/asn1/its/CreditRq.h>
#include <vanetza/asn1/its/CreditRs.h>
#include <vanetza/asn1/its/DebitRq.h>
#include <vanetza/asn1/its/DebitRs.h>
#include <vanetza/asn1/its/GetInstanceRq.h>
#include <vanetza/asn1/its/GetStampedRq.h>
#include <vanetza/asn1/its/GetStampedRs.h>
#include <vanetza/asn1/its/SetInstanceRq.h>
#include <vanetza/asn1/its/SetMMIRq.h>
#include <vanetza/asn1/its/SetStampedRq.h>
#include <vanetza/asn1/its/SubRq.h>
#include <vanetza/asn1/its/CO2EmissionValue.h>
#include <vanetza/asn1/its/ContractSerialNumber.h>
#include <vanetza/asn1/its/ContractAuthenticator.h>
#include <vanetza/asn1/its/ContractValidity.h>
#include <vanetza/asn1/its/ContractVehicle.h>
#include <vanetza/asn1/its/DateCompact.h>
#include <vanetza/asn1/its/DescriptiveCharacteristics.h>
#include <vanetza/asn1/its/DieselEmissionValues.h>
#include <vanetza/asn1/its/EfcDsrcApplication_DriverCharacteristics.h>
#include <vanetza/asn1/its/EFC-ContextMark.h>
#include <vanetza/asn1/its/EnvironmentalCharacteristics.h>
#include <vanetza/asn1/its/EuroValue.h>
#include <vanetza/asn1/its/CopValue.h>
#include <vanetza/asn1/its/EngineCharacteristics.h>
#include <vanetza/asn1/its/Engine.h>
#include <vanetza/asn1/its/EquipmentOBUId.h>
#include <vanetza/asn1/its/EquipmentStatus.h>
#include <vanetza/asn1/its/ExhaustEmissionValues.h>
#include <vanetza/asn1/its/FutureCharacteristics.h>
#include <vanetza/asn1/its/ICC-Id.h>
#include <vanetza/asn1/its/Int1.h>
#include <vanetza/asn1/its/Int2.h>
#include <vanetza/asn1/its/Int3.h>
#include <vanetza/asn1/its/Int4.h>
#include <vanetza/asn1/its/LPN.h>
#include <vanetza/asn1/its/PassengerCapacity.h>
#include <vanetza/asn1/its/PaymentFee.h>
#include <vanetza/asn1/its/PaymentMeans.h>
#include <vanetza/asn1/its/PaymentMeansBalance.h>
#include <vanetza/asn1/its/SignedValue.h>
#include <vanetza/asn1/its/PaymentMeansUnit.h>
#include <vanetza/asn1/its/PaymentSecurityData.h>
#include <vanetza/asn1/its/PayUnit.h>
#include <vanetza/asn1/its/PersonalAccountNumber.h>
#include <vanetza/asn1/its/Provider.h>
#include <vanetza/asn1/its/PurseBalance.h>
#include <vanetza/asn1/its/ReceiptContract.h>
#include <vanetza/asn1/its/ReceiptData1.h>
#include <vanetza/asn1/its/ReceiptData2.h>
#include <vanetza/asn1/its/ReceiptData.h>
#include <vanetza/asn1/its/ReceiptDistance.h>
#include <vanetza/asn1/its/ReceiptFinancialPart.h>
#include <vanetza/asn1/its/ReceiptICC-Id.h>
#include <vanetza/asn1/its/ReceiptOBUId.h>
#include <vanetza/asn1/its/ReceiptServicePart.h>
#include <vanetza/asn1/its/ReceiptServiceSerialNumber.h>
#include <vanetza/asn1/its/ReceiptAuthenticator.h>
#include <vanetza/asn1/its/ReceiptText.h>
#include <vanetza/asn1/its/ResultFin.h>
#include <vanetza/asn1/its/ResultOp.h>
#include <vanetza/asn1/its/SessionClass.h>
#include <vanetza/asn1/its/SessionLocation.h>
#include <vanetza/asn1/its/StationTypeIso.h>
#include <vanetza/asn1/its/DateAndTime.h>
#include <vanetza/asn1/its/SoundLevel.h>
#include <vanetza/asn1/its/EfcDsrcApplication_TrailerCharacteristics.h>
#include <vanetza/asn1/its/TrailerDetails.h>
#include <vanetza/asn1/its/TrailerLicencePlateNumber.h>
#include <vanetza/asn1/its/UnitType.h>
#include <vanetza/asn1/its/ValidityOfContract.h>
#include <vanetza/asn1/its/VehicleAuthenticator.h>
#include <vanetza/asn1/its/VehicleAxles.h>
#include <vanetza/asn1/its/TrailerAxles.h>
#include <vanetza/asn1/its/TractorAxles.h>
#include <vanetza/asn1/its/VehicleClass.h>
#include <vanetza/asn1/its/VehicleDimensions.h>
#include <vanetza/asn1/its/VehicleLicencePlateNumber.h>
#include <vanetza/asn1/its/VehicleIdentificationNumber.h>
#include <vanetza/asn1/its/VehicleSpecificCharacteristics.h>
#include <vanetza/asn1/its/VehicleTotalDistance.h>
#include <vanetza/asn1/its/VehicleWeightLaden.h>
#include <vanetza/asn1/its/VehicleCurrentMaxTrainWeight.h>
#include <vanetza/asn1/its/VehicleWeightLimits.h>
#include <vanetza/asn1/its/AttributeIdList.h>
#include <vanetza/asn1/its/AttributeList.h>
#include <vanetza/asn1/its/Attributes.h>

using namespace rapidjson;

Value to_json(const TimestampIts_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, TimestampIts_t& p, std::string field);
Value to_json(const long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long& p, std::string field);
Value to_json(const unsigned long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned long& p, std::string field);
Value to_json(const unsigned& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned& p, std::string field);
Value to_json(const double& p, Document::AllocatorType& allocator);
void from_json(const Value& j, double& p, std::string field);
Value to_json(const bool& p, Document::AllocatorType& allocator);
void from_json(const Value& j, bool& p, std::string field);
Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, OCTET_STRING_t& p, std::string field);
Value to_json(const NULL_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, NULL_t& p, std::string field);


/*
*   ItsPduHeader - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItsPduHeader_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsPduHeader_t& p, std::string field);


/*
*   DeltaReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DeltaReferencePosition_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaReferencePosition_t& p, std::string field);


/*
*   Altitude - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Altitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Altitude& p, std::string field);


/*
*   PosConfidenceEllipse - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PosConfidenceEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PosConfidenceEllipse& p, std::string field);


/*
*   PathPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PathPoint& p, std::string field);


/*
*   AccelerationControl - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_AccelerationControl(const AccelerationControl_t p, Document::AllocatorType& allocator);

void from_json_AccelerationControl(const Value& j, AccelerationControl_t& p, std::string field);


/*
*   CauseCode - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CauseCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CauseCode& p, std::string field);


/*
*   Curvature - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Curvature& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Curvature& p, std::string field);


/*
*   Heading - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Heading& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Heading& p, std::string field);


/*
*   DrivingLaneStatus - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_DrivingLaneStatus(const DrivingLaneStatus_t p, Document::AllocatorType& allocator);

void from_json_DrivingLaneStatus(const Value& j, DrivingLaneStatus_t& p, std::string field);


/*
*   Speed - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Speed& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Speed& p, std::string field);


/*
*   LongitudinalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LongitudinalAcceleration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LongitudinalAcceleration& p, std::string field);


/*
*   LateralAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LateralAcceleration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LateralAcceleration& p, std::string field);


/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VerticalAcceleration_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VerticalAcceleration_t& p, std::string field);


/*
*   ExteriorLights - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_ExteriorLights(const ExteriorLights_t p, Document::AllocatorType& allocator);

void from_json_ExteriorLights(const Value& j, ExteriorLights_t& p, std::string field);


/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DangerousGoodsExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DangerousGoodsExtended& p, std::string field);


/*
*   SpecialTransportType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_SpecialTransportType(const SpecialTransportType_t p, Document::AllocatorType& allocator);

void from_json_SpecialTransportType(const Value& j, SpecialTransportType_t& p, std::string field);


/*
*   LightBarSirenInUse - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_LightBarSirenInUse(const LightBarSirenInUse_t p, Document::AllocatorType& allocator);

void from_json_LightBarSirenInUse(const Value& j, LightBarSirenInUse_t& p, std::string field);


/*
*   PositionOfOccupants - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_PositionOfOccupants(const PositionOfOccupants_t p, Document::AllocatorType& allocator);

void from_json_PositionOfOccupants(const Value& j, PositionOfOccupants_t& p, std::string field);


/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleIdentification& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleIdentification& p, std::string field);


/*
*   EnergyStorageType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EnergyStorageType(const EnergyStorageType_t p, Document::AllocatorType& allocator);

void from_json_EnergyStorageType(const Value& j, EnergyStorageType_t& p, std::string field);


/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleLength_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleLength_t& p, std::string field);


/*
*   PathHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathHistory& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PathHistory& p, std::string field);


/*
*   EmergencyPriority - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EmergencyPriority(const EmergencyPriority_t p, Document::AllocatorType& allocator);

void from_json_EmergencyPriority(const Value& j, EmergencyPriority_t& p, std::string field);


/*
*   SteeringWheelAngle - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const SteeringWheelAngle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SteeringWheelAngle& p, std::string field);


/*
*   YawRate - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const YawRate& p, Document::AllocatorType& allocator);

void from_json(const Value& j, YawRate& p, std::string field);


/*
*   ActionID - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ActionID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ActionID& p, std::string field);


/*
*   ProtectedCommunicationZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ProtectedCommunicationZone& p, std::string field);


/*
*   Traces - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Traces& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Traces& p, std::string field);


/*
*   PositionOfPillars - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PositionOfPillars& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionOfPillars& p, std::string field);


/*
*   RestrictedTypes - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const RestrictedTypes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictedTypes& p, std::string field);


/*
*   EventPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EventPoint& p, std::string field);


/*
*   ProtectedCommunicationZonesRSU - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZonesRSU& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ProtectedCommunicationZonesRSU& p, std::string field);


/*
*   CenDsrcTollingZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CenDsrcTollingZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CenDsrcTollingZone& p, std::string field);


/*
*   LaneAttributes-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const LaneAttributes_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneAttributes_addGrpC& p, std::string field);


/*
*   MovementEvent-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MovementEvent_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEvent_addGrpC& p, std::string field);


/*
*   Position3D-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Position3D_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Position3D_addGrpC& p, std::string field);


/*
*   RestrictionUserType-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RestrictionUserType_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserType_addGrpC& p, std::string field);


/*
*   RequestorDescription-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RequestorDescription_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorDescription_addGrpC& p, std::string field);


/*
*   SignalStatusPackage-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackage_addGrpC& p, std::string field);


/*
*   Node - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Node& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node& p, std::string field);


/*
*   NodeLink - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeLink& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeLink& p, std::string field);


/*
*   PrioritizationResponse - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PrioritizationResponse& p, std::string field);


/*
*   PrioritizationResponseList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponseList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PrioritizationResponseList& p, std::string field);


/*
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeed& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AdvisorySpeed& p, std::string field);


/*
*   AdvisorySpeedList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeedList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AdvisorySpeedList_t& p, std::string field);


/*
*   AntennaOffsetSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AntennaOffsetSet& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AntennaOffsetSet& p, std::string field);


/*
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetXaxis& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane::ComputedLane__offsetXaxis& p, std::string field);


/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetYaxis& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane::ComputedLane__offsetYaxis& p, std::string field);


/*
*   ComputedLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane_t& p, std::string field);


/*
*   ConnectionManeuverAssist - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionManeuverAssist_t& p, std::string field);


/*
*   DataParameters - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DataParameters_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DataParameters_t& p, std::string field);


/*
*   DDateTime - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DDateTime& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDateTime& p, std::string field);


/*
*   EnabledLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const EnabledLaneList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EnabledLaneList_t& p, std::string field);


/*
*   IntersectionAccessPoint - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionAccessPoint_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionAccessPoint_t& p, std::string field);


/*
*   IntersectionReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionReferenceID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionReferenceID& p, std::string field);


/*
*   LaneSharing - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneSharing(const LaneSharing_t p, Document::AllocatorType& allocator);

void from_json_LaneSharing(const Value& j, LaneSharing_t& p, std::string field);


/*
*   ManeuverAssistList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ManeuverAssistList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManeuverAssistList& p, std::string field);


/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeXYList& p, std::string field);


/*
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_LLmD_64b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_LLmD_64b& p, std::string field);


/*
*   Node-XY-20b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_20b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_20b& p, std::string field);


/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_22b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_22b& p, std::string field);


/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_24b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_24b& p, std::string field);


/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_26b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_26b& p, std::string field);


/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_28b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_28b& p, std::string field);


/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_32b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_32b& p, std::string field);


/*
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeOffsetPointXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeOffsetPointXY& p, std::string field);


/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const OverlayLaneList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OverlayLaneList& p, std::string field);


/*
*   PositionalAccuracy - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionalAccuracy& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionalAccuracy& p, std::string field);


/*
*   PositionConfidenceSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionConfidenceSet& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionConfidenceSet& p, std::string field);


/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Position3D_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Position3D_t& p, std::string field);


/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RegulatorySpeedLimit& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RegulatorySpeedLimit& p, std::string field);


/*
*   RequestorType - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorType& p, std::string field);


/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserType& p, std::string field);


/*
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserTypeList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserTypeList& p, std::string field);


/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentReferenceID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegmentReferenceID& p, std::string field);


/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SegmentAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SegmentAttributeXYList& p, std::string field);


/*
*   SignalControlZone - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalControlZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalControlZone& p, std::string field);


/*
*   SignalRequest - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequest& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequest& p, std::string field);


/*
*   SignalRequestPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestPackage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestPackage& p, std::string field);


/*
*   SpeedandHeadingIsoandThrottleConfidence - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedandHeadingIsoandThrottleConfidence& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedandHeadingIsoandThrottleConfidence& p, std::string field);


/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedLimitList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedLimitList& p, std::string field);


/*
*   TimeChangeDetails - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TimeChangeDetails& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TimeChangeDetails& p, std::string field);


/*
*   TransmissionAndSpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TransmissionAndSpeed_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TransmissionAndSpeed_t& p, std::string field);


/*
*   VehicleID - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const VehicleID_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleID_t& p, std::string field);


/*
*   AllowedManeuvers - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_AllowedManeuvers(const AllowedManeuvers_t p, Document::AllocatorType& allocator);

void from_json_AllowedManeuvers(const Value& j, AllowedManeuvers_t& p, std::string field);


/*
*   GNSSstatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_GNSSstatus(const GNSSstatus_t p, Document::AllocatorType& allocator);

void from_json_GNSSstatus(const Value& j, GNSSstatus_t& p, std::string field);


/*
*   IntersectionStatusObject - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_IntersectionStatusObject(const IntersectionStatusObject_t p, Document::AllocatorType& allocator);

void from_json_IntersectionStatusObject(const Value& j, IntersectionStatusObject_t& p, std::string field);


/*
*   LaneAttributes-Barrier - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Barrier(const LaneAttributes_Barrier_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Barrier(const Value& j, LaneAttributes_Barrier_t& p, std::string field);


/*
*   LaneAttributes-Bike - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Bike(const LaneAttributes_Bike_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Bike(const Value& j, LaneAttributes_Bike_t& p, std::string field);


/*
*   LaneAttributes-Crosswalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Crosswalk(const LaneAttributes_Crosswalk_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Crosswalk(const Value& j, LaneAttributes_Crosswalk_t& p, std::string field);


/*
*   LaneAttributes-Parking - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Parking(const LaneAttributes_Parking_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Parking(const Value& j, LaneAttributes_Parking_t& p, std::string field);


/*
*   LaneAttributes-Sidewalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Sidewalk(const LaneAttributes_Sidewalk_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Sidewalk(const Value& j, LaneAttributes_Sidewalk_t& p, std::string field);


/*
*   LaneAttributes-Striping - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Striping(const LaneAttributes_Striping_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Striping(const Value& j, LaneAttributes_Striping_t& p, std::string field);


/*
*   LaneAttributes-TrackedVehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_TrackedVehicle(const LaneAttributes_TrackedVehicle_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_TrackedVehicle(const Value& j, LaneAttributes_TrackedVehicle_t& p, std::string field);


/*
*   LaneAttributes-Vehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Vehicle(const LaneAttributes_Vehicle_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Vehicle(const Value& j, LaneAttributes_Vehicle_t& p, std::string field);


/*
*   LaneDirection - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneDirection(const LaneDirection_t p, Document::AllocatorType& allocator);

void from_json_LaneDirection(const Value& j, LaneDirection_t& p, std::string field);


/*
*   TransitVehicleStatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_TransitVehicleStatus(const TransitVehicleStatus_t p, Document::AllocatorType& allocator);

void from_json_TransitVehicleStatus(const Value& j, TransitVehicleStatus_t& p, std::string field);


/*
*   CS5 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS5& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS5& p, std::string field);


/*
*   FreightContainerData - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const FreightContainerData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreightContainerData_t& p, std::string field);


/*
*   CountryCode - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_CountryCode(const CountryCode_t p, Document::AllocatorType& allocator);

void from_json_CountryCode(const Value& j, CountryCode_t& p, std::string field);


/*
*   ServiceNumber - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceNumber(const ServiceNumber_t p, Document::AllocatorType& allocator);

void from_json_ServiceNumber(const Value& j, ServiceNumber_t& p, std::string field);


/*
*   GeoGraphicalLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_GeoGraphicalLimit(const GeoGraphicalLimit_t p, Document::AllocatorType& allocator);

void from_json_GeoGraphicalLimit(const Value& j, GeoGraphicalLimit_t& p, std::string field);


/*
*   ServiceApplicationLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceApplicationLimit(const ServiceApplicationLimit_t p, Document::AllocatorType& allocator);

void from_json_ServiceApplicationLimit(const Value& j, ServiceApplicationLimit_t& p, std::string field);


/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p, std::string field);


/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p, std::string field);


/*
*   GddStructure::GddStructure__pictogramCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode& p, std::string field);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__year - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p, std::string field);


/*
*   InternationalSign-speedLimits - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_speedLimits& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_speedLimits& p, std::string field);


/*
*   DayOfWeek - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_DayOfWeek(const DayOfWeek_t p, Document::AllocatorType& allocator);

void from_json_DayOfWeek(const Value& j, DayOfWeek_t& p, std::string field);


/*
*   DestinationPlace - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlace& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationPlace& p, std::string field);


/*
*   DestinationPlaces - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlaces& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationPlaces& p, std::string field);


/*
*   DestinationRoad - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoad& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationRoad& p, std::string field);


/*
*   DestinationRoads - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoads& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationRoads& p, std::string field);


/*
*   Distance - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Distance& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Distance& p, std::string field);


/*
*   DistanceOrDuration - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DistanceOrDuration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DistanceOrDuration& p, std::string field);


/*
*   HoursMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const HoursMinutes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HoursMinutes& p, std::string field);


/*
*   MonthDay - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const MonthDay& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MonthDay& p, std::string field);


/*
*   RepeatingPeriodDayTypes - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_RepeatingPeriodDayTypes(const RepeatingPeriodDayTypes_t p, Document::AllocatorType& allocator);

void from_json_RepeatingPeriodDayTypes(const Value& j, RepeatingPeriodDayTypes_t& p, std::string field);


/*
*   Weight - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Weight& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Weight& p, std::string field);


/*
*   AxleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AxleWeightLimits_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AxleWeightLimits_t& p, std::string field);


/*
*   AddRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AddRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AddRq_t& p, std::string field);


/*
*   ChannelRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ChannelRq_t& p, std::string field);


/*
*   ChannelRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ChannelRs_t& p, std::string field);


/*
*   CopyRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CopyRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CopyRq_t& p, std::string field);


/*
*   GetInstanceRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const GetInstanceRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GetInstanceRq_t& p, std::string field);


/*
*   SubRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SubRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SubRq_t& p, std::string field);


/*
*   DateCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateCompact_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateCompact_t& p, std::string field);


/*
*   DieselEmissionValues::DieselEmissionValues__particulate - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues::DieselEmissionValues__particulate& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DieselEmissionValues::DieselEmissionValues__particulate& p, std::string field);


/*
*   DieselEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DieselEmissionValues_t& p, std::string field);


/*
*   EfcDsrcApplication_DriverCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EfcDsrcApplication_DriverCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EfcDsrcApplication_DriverCharacteristics_t& p, std::string field);


/*
*   EnvironmentalCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EnvironmentalCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EnvironmentalCharacteristics_t& p, std::string field);


/*
*   Engine - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Engine_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Engine_t& p, std::string field);


/*
*   EquipmentStatus - Type BIT STRING
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json_EquipmentStatus(const EquipmentStatus_t p, Document::AllocatorType& allocator);

void from_json_EquipmentStatus(const Value& j, EquipmentStatus_t& p, std::string field);


/*
*   ExhaustEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ExhaustEmissionValues_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ExhaustEmissionValues_t& p, std::string field);


/*
*   LPN - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const LPN_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LPN_t& p, std::string field);


/*
*   PassengerCapacity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PassengerCapacity_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PassengerCapacity_t& p, std::string field);


/*
*   SignedValue - Type CHOICE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SignedValue_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignedValue_t& p, std::string field);


/*
*   Provider - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Provider_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Provider_t& p, std::string field);


/*
*   PurseBalance - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PurseBalance_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PurseBalance_t& p, std::string field);


/*
*   ReceiptContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptContract_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptContract_t& p, std::string field);


/*
*   SessionClass - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionClass_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SessionClass_t& p, std::string field);


/*
*   SessionLocation - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionLocation_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SessionLocation_t& p, std::string field);


/*
*   DateAndTime::DateAndTime__timeCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime::DateAndTime__timeCompact& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateAndTime::DateAndTime__timeCompact& p, std::string field);


/*
*   DateAndTime - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateAndTime_t& p, std::string field);


/*
*   SoundLevel - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SoundLevel_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SoundLevel_t& p, std::string field);


/*
*   TrailerDetails - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const TrailerDetails_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerDetails_t& p, std::string field);


/*
*   ValidityOfContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ValidityOfContract_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ValidityOfContract_t& p, std::string field);


/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p, std::string field);


/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber& p, std::string field);


/*
*   VehicleAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles_t& p, std::string field);


/*
*   VehicleDimensions - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleDimensions_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleDimensions_t& p, std::string field);


/*
*   VehicleSpecificCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleSpecificCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSpecificCharacteristics_t& p, std::string field);


/*
*   VehicleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleWeightLimits_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleWeightLimits_t& p, std::string field);


/*
*   Ext2 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Ext2& p, std::string field);


/*
*   EuVehicleCategoryCode - Type CHOICE
*   From ElectronicRegistrationIdentificationVehicleDataModule - File ISO24534-3.asn
*/

Value to_json(const EuVehicleCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EuVehicleCategoryCode& p, std::string field);


/*
*   ConnectedDenms - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConnectedDenms& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectedDenms& p, std::string field);


/*
*   DeltaReferencePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaReferencePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaReferencePositions& p, std::string field);


/*
*   IviIdentificationNumbers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviIdentificationNumbers& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviIdentificationNumbers& p, std::string field);


/*
*   LaneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneIds& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneIds& p, std::string field);


/*
*   LanePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LanePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LanePositions& p, std::string field);


/*
*   SaeAutomationLevels - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const SaeAutomationLevels& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SaeAutomationLevels& p, std::string field);


/*
*   ZoneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ZoneIds& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ZoneIds& p, std::string field);


/*
*   AbsolutePosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePosition& p, std::string field);


/*
*   AbsolutePositionWAltitude - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionWAltitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositionWAltitude& p, std::string field);


/*
*   ComputedSegment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ComputedSegment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedSegment& p, std::string field);


/*
*   DeltaPosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaPosition& p, std::string field);


/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p, std::string field);


/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p, std::string field);


/*
*   ISO14823Code::ISO14823Code__pictogramCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode& p, std::string field);


/*
*   LaneCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneCharacteristics& p, std::string field);


/*
*   LayoutComponent - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponent& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutComponent& p, std::string field);


/*
*   LoadType - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LoadType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LoadType& p, std::string field);


/*
*   MapReference - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapReference& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapReference& p, std::string field);


/*
*   RoadSurfaceDynamicCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceDynamicCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceDynamicCharacteristics& p, std::string field);


/*
*   RoadSurfaceStaticCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceStaticCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceStaticCharacteristics& p, std::string field);


/*
*   Text - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Text& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Text& p, std::string field);


/*
*   VehicleCharacteristicsFixValues - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValues& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsFixValues& p, std::string field);


/*
*   VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p, std::string field);


/*
*   VehicleCharacteristicsRanges - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRanges& p, std::string field);


/*
*   BasicVehicleContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerHighFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicVehicleContainerHighFrequency& p, std::string field);


/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerLowFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicVehicleContainerLowFrequency& p, std::string field);


/*
*   SpecialTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialTransportContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpecialTransportContainer& p, std::string field);


/*
*   DangerousGoodsContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const DangerousGoodsContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DangerousGoodsContainer& p, std::string field);


/*
*   RescueContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RescueContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RescueContainer& p, std::string field);


/*
*   EmergencyContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const EmergencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EmergencyContainer& p, std::string field);


/*
*   SafetyCarContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SafetyCarContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SafetyCarContainer& p, std::string field);


/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RSUContainerHighFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSUContainerHighFrequency& p, std::string field);


/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const LocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LocationContainer& p, std::string field);


/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ImpactReductionContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ImpactReductionContainer& p, std::string field);


/*
*   StationaryVehicleContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const StationaryVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StationaryVehicleContainer& p, std::string field);


/*
*   ReferenceDenms - Type SEQUENCE OF
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ReferenceDenms& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReferenceDenms& p, std::string field);


/*
*   MapPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const MapPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapPosition& p, std::string field);


/*
*   VruProfileAndSubprofile - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruProfileAndSubprofile& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruProfileAndSubprofile& p, std::string field);


/*
*   VruSpecificExteriorLights - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_VruSpecificExteriorLights(const VruSpecificExteriorLights_t p, Document::AllocatorType& allocator);

void from_json_VruSpecificExteriorLights(const Value& j, VruSpecificExteriorLights_t& p, std::string field);


/*
*   ClusterProfiles - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_ClusterProfiles(const ClusterProfiles_t p, Document::AllocatorType& allocator);

void from_json_ClusterProfiles(const Value& j, ClusterProfiles_t& p, std::string field);


/*
*   ClusterJoinInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterJoinInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterJoinInfo& p, std::string field);


/*
*   ClusterLeaveInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterLeaveInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterLeaveInfo& p, std::string field);


/*
*   ClusterBreakupInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBreakupInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterBreakupInfo& p, std::string field);


/*
*   VruSafeDistanceIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruSafeDistanceIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruSafeDistanceIndication& p, std::string field);


/*
*   TrajectoryInterceptionIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrajectoryInterceptionIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrajectoryInterceptionIndication& p, std::string field);


/*
*   HeadingChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const HeadingChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HeadingChangeIndication& p, std::string field);


/*
*   AccelerationChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const AccelerationChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AccelerationChangeIndication& p, std::string field);


/*
*   StabilityChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const StabilityChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StabilityChangeIndication& p, std::string field);


/*
*   LaneDataAttribute - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneDataAttribute& p, std::string field);


/*
*   LaneDataAttributeList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttributeList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneDataAttributeList& p, std::string field);


/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeAttributeSetXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeSetXY_t& p, std::string field);


/*
*   OriginatingRSUContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingRSUContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OriginatingRSUContainer& p, std::string field);


/*
*   VehicleSensorProperties - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorProperties& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensorProperties& p, std::string field);


/*
*   ObjectDistanceWithConfidence - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDistanceWithConfidence& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectDistanceWithConfidence& p, std::string field);


/*
*   ObjectDimension - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDimension& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectDimension& p, std::string field);


/*
*   CartesianAngle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CartesianAngle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CartesianAngle& p, std::string field);


/*
*   WGS84Angle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const WGS84Angle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, WGS84Angle& p, std::string field);


/*
*   SpeedExtended - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SpeedExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedExtended& p, std::string field);


/*
*   SensorIdList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorIdList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorIdList& p, std::string field);


/*
*   TrailerData - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerData& p, std::string field);


/*
*   LongitudinalLanePosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const LongitudinalLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LongitudinalLanePosition& p, std::string field);


/*
*   MatchedPosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const MatchedPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MatchedPosition& p, std::string field);


/*
*   PerceivedObjectContainerSegmentInfo - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainerSegmentInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObjectContainerSegmentInfo& p, std::string field);


/*
*   VehicleSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSubclass& p, std::string field);


/*
*   PersonSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PersonSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PersonSubclass& p, std::string field);


/*
*   AnimalSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AnimalSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AnimalSubclass& p, std::string field);


/*
*   OtherSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OtherSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OtherSubclass& p, std::string field);


/*
*   NodeOffsetPointZ - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const NodeOffsetPointZ& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeOffsetPointZ& p, std::string field);


/*
*   ItsPOIHeader - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsPOIHeader& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsPOIHeader& p, std::string field);


/*
*   ChargingSpotType - Type BIT STRING
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json_ChargingSpotType(const ChargingSpotType_t p, Document::AllocatorType& allocator);

void from_json_ChargingSpotType(const Value& j, ChargingSpotType_t& p, std::string field);


/*
*   TypeOfReceptacle - Type BIT STRING
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json_TypeOfReceptacle(const TypeOfReceptacle_t p, Document::AllocatorType& allocator);

void from_json_TypeOfReceptacle(const Value& j, TypeOfReceptacle_t& p, std::string field);


/*
*   SpotAvailability - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const SpotAvailability& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpotAvailability& p, std::string field);


/*
*   Payment-ID - Type CHOICE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const Payment_ID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Payment_ID& p, std::string field);


/*
*   RechargingType - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const RechargingType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RechargingType& p, std::string field);


/*
*   SupportedPaymentTypes - Type BIT STRING
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json_SupportedPaymentTypes(const SupportedPaymentTypes_t p, Document::AllocatorType& allocator);

void from_json_SupportedPaymentTypes(const Value& j, SupportedPaymentTypes_t& p, std::string field);


/*
*   InterferenceManagementChannel - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementChannel& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementChannel& p, std::string field);


/*
*   MitigationPerTechnologyClass - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const MitigationPerTechnologyClass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MitigationPerTechnologyClass& p, std::string field);


/*
*   TisTpgDRM-Situation - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgDRM_Situation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgDRM_Situation& p, std::string field);


/*
*   TisTpgSNM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgSNM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgSNM_Management& p, std::string field);


/*
*   TisTpgTRM-Situation - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTRM_Situation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTRM_Situation& p, std::string field);


/*
*   TyreData::TyreData__currentTyrePressure - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__currentTyrePressure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__currentTyrePressure& p, std::string field);


/*
*   TyreData::TyreData__currentInsideAirTemperature - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__currentInsideAirTemperature& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__currentInsideAirTemperature& p, std::string field);


/*
*   TyreData::TyreData__recommendedTyrePressure - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__recommendedTyrePressure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__recommendedTyrePressure& p, std::string field);


/*
*   TyreData::TyreData__sensorState - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__sensorState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__sensorState& p, std::string field);


/*
*   AppliedTyrePressure - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const AppliedTyrePressure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AppliedTyrePressure& p, std::string field);


/*
*   TyreSidewallInformation - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_TyreSidewallInformation(const TyreSidewallInformation_t p, Document::AllocatorType& allocator);

void from_json_TyreSidewallInformation(const Value& j, TyreSidewallInformation_t& p, std::string field);


/*
*   CurrentVehicleConfiguration - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_CurrentVehicleConfiguration(const CurrentVehicleConfiguration_t p, Document::AllocatorType& allocator);

void from_json_CurrentVehicleConfiguration(const Value& j, CurrentVehicleConfiguration_t& p, std::string field);


/*
*   TIN - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_TIN(const TIN_t p, Document::AllocatorType& allocator);

void from_json_TIN(const Value& j, TIN_t& p, std::string field);


/*
*   PressureConfiguration - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_PressureConfiguration(const PressureConfiguration_t p, Document::AllocatorType& allocator);

void from_json_PressureConfiguration(const Value& j, PressureConfiguration_t& p, std::string field);


/*
*   AppliedTyrePressures - Type SEQUENCE OF
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const AppliedTyrePressures& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AppliedTyrePressures& p, std::string field);


/*
*   TpgAutomation - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_TpgAutomation(const TpgAutomation_t p, Document::AllocatorType& allocator);

void from_json_TpgAutomation(const Value& j, TpgAutomation_t& p, std::string field);


/*
*   TisProfile - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_TisProfile(const TisProfile_t p, Document::AllocatorType& allocator);

void from_json_TisProfile(const Value& j, TisProfile_t& p, std::string field);


/*
*   Language - Type BIT STRING
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json_Language(const Language_t p, Document::AllocatorType& allocator);

void from_json_Language(const Value& j, Language_t& p, std::string field);


/*
*   PositionConfidenceEllipse - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const PositionConfidenceEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionConfidenceEllipse& p, std::string field);


/*
*   ManoeuvreCooperationCost - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManoeuvreCooperationCost& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManoeuvreCooperationCost& p, std::string field);


/*
*   VehicleAutomationState - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const VehicleAutomationState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAutomationState& p, std::string field);


/*
*   ManouevreResponse - Type CHOICE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManouevreResponse_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManouevreResponse_t& p, std::string field);


/*
*   Polynom::Polynom__coefficients - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Polynom::Polynom__coefficients& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Polynom::Polynom__coefficients& p, std::string field);


/*
*   Polynom - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Polynom& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Polynom& p, std::string field);


/*
*   IntermediatePointIntersection::IntermediatePointIntersection__exitLane - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePointIntersection::IntermediatePointIntersection__exitLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePointIntersection::IntermediatePointIntersection__exitLane& p, std::string field);


/*
*   IntermediatePointIntersection - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePointIntersection& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePointIntersection& p, std::string field);


/*
*   Lane - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Lane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Lane& p, std::string field);


/*
*   ReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ReferencePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReferencePosition& p, std::string field);


/*
*   PtActivation - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PtActivation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PtActivation& p, std::string field);


/*
*   ClosedLanes - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ClosedLanes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClosedLanes& p, std::string field);


/*
*   ItineraryPath - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItineraryPath& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItineraryPath& p, std::string field);


/*
*   EventHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventHistory& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EventHistory& p, std::string field);


/*
*   DigitalMap - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DigitalMap_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DigitalMap_t& p, std::string field);


/*
*   IntersectionState-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const IntersectionState_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionState_addGrpC& p, std::string field);


/*
*   NodeAttributeSet-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeAttributeSet_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeSet_addGrpC& p, std::string field);


/*
*   ItsStationPosition - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPosition_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsStationPosition_t& p, std::string field);


/*
*   ItsStationPositionList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPositionList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsStationPositionList_t& p, std::string field);


/*
*   SignalHeadLocation - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocation_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalHeadLocation_t& p, std::string field);


/*
*   SignalHeadLocationList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocationList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalHeadLocationList_t& p, std::string field);


/*
*   ConnectingLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectingLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectingLane& p, std::string field);


/*
*   Connection - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Connection& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Connection& p, std::string field);


/*
*   FullPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const FullPositionVector& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FullPositionVector& p, std::string field);


/*
*   LaneTypeAttributes - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneTypeAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneTypeAttributes& p, std::string field);


/*
*   MovementEvent - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementEvent& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEvent& p, std::string field);


/*
*   MovementEventList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementEventList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEventList& p, std::string field);


/*
*   MovementState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementState& p, std::string field);


/*
*   NodeXY - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeXY_t& p, std::string field);


/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeSetXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeSetXY& p, std::string field);


/*
*   RequestorPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorPositionVector& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorPositionVector& p, std::string field);


/*
*   RestrictionClassAssignment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassAssignment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionClassAssignment& p, std::string field);


/*
*   RestrictionClassList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionClassList& p, std::string field);


/*
*   RTCMheader - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMheader& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMheader& p, std::string field);


/*
*   RTCMmessageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMmessageList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMmessageList& p, std::string field);


/*
*   SignalRequesterInfo - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequesterInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequesterInfo& p, std::string field);


/*
*   SignalRequestList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestList& p, std::string field);


/*
*   SignalStatusPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackage& p, std::string field);


/*
*   CS1 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS1& p, std::string field);


/*
*   CS2 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS2& p, std::string field);


/*
*   CS3 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS3& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS3& p, std::string field);


/*
*   CS4 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS4& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS4& p, std::string field);


/*
*   CS8 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS8& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS8& p, std::string field);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__month-day - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p, std::string field);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__hourMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p, std::string field);


/*
*   InternationalSign-applicablePeriod - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod& p, std::string field);


/*
*   InternationalSign-applicableVehicleDimensions - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicableVehicleDimensions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicableVehicleDimensions& p, std::string field);


/*
*   InternationalSign-section - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_section& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_section& p, std::string field);


/*
*   DDD-IO - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDD_IO& p, std::string field);


/*
*   CreditRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CreditRs_t& p, std::string field);


/*
*   DebitRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DebitRs_t& p, std::string field);


/*
*   ContractValidity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ContractValidity_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ContractValidity_t& p, std::string field);


/*
*   EFC-ContextMark - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EFC_ContextMark_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EFC_ContextMark_t& p, std::string field);


/*
*   PaymentFee - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentFee_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PaymentFee_t& p, std::string field);


/*
*   PaymentMeans - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentMeans_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PaymentMeans_t& p, std::string field);


/*
*   ReceiptData - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptData_t& p, std::string field);


/*
*   ReceiptFinancialPart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptFinancialPart_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptFinancialPart_t& p, std::string field);


/*
*   ReceiptServicePart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptServicePart_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptServicePart_t& p, std::string field);


/*
*   EfcDsrcApplication_TrailerCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EfcDsrcApplication_TrailerCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EfcDsrcApplication_TrailerCharacteristics_t& p, std::string field);


/*
*   Ext1 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Ext1& p, std::string field);


/*
*   IviManagementContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviManagementContainer& p, std::string field);


/*
*   RscPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RscPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RscPart& p, std::string field);


/*
*   MlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MlcPart& p, std::string field);


/*
*   AbsolutePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositions& p, std::string field);


/*
*   AbsolutePositionsWAltitude - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionsWAltitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositionsWAltitude& p, std::string field);


/*
*   DeltaPositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaPositions& p, std::string field);


/*
*   ConstraintTextLines1 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConstraintTextLines1& p, std::string field);


/*
*   ConstraintTextLines2 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConstraintTextLines2& p, std::string field);


/*
*   LayoutComponents - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponents& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutComponents& p, std::string field);


/*
*   TextLines - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextLines& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TextLines& p, std::string field);


/*
*   TrailerCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsFixValuesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsFixValuesList& p, std::string field);


/*
*   TrailerCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsRangesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsRangesList& p, std::string field);


/*
*   VehicleCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValuesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsFixValuesList& p, std::string field);


/*
*   VehicleCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRangesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRangesList& p, std::string field);


/*
*   ValidityPeriods - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ValidityPeriods& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ValidityPeriods& p, std::string field);


/*
*   PolygonalLine - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PolygonalLine& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PolygonalLine& p, std::string field);


/*
*   Segment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Segment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Segment& p, std::string field);


/*
*   TractorCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TractorCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TractorCharacteristics& p, std::string field);


/*
*   IVI_TrailerCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IVI_TrailerCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IVI_TrailerCharacteristics& p, std::string field);


/*
*   VcCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VcCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VcCode& p, std::string field);


/*
*   Zone - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Zone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Zone& p, std::string field);


/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const HighFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HighFrequencyContainer& p, std::string field);


/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const LowFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LowFrequencyContainer& p, std::string field);


/*
*   BasicContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicContainer& p, std::string field);


/*
*   PublicTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const PublicTransportContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PublicTransportContainer& p, std::string field);


/*
*   RoadWorksContainerBasic - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RoadWorksContainerBasic& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadWorksContainerBasic& p, std::string field);


/*
*   ManagementContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManagementContainer& p, std::string field);


/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const SituationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SituationContainer& p, std::string field);


/*
*   RoadWorksContainerExtended - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const RoadWorksContainerExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadWorksContainerExtended& p, std::string field);


/*
*   AlacarteContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const AlacarteContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AlacarteContainer& p, std::string field);


/*
*   NonIslandLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const NonIslandLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NonIslandLanePosition& p, std::string field);


/*
*   VruExteriorLights - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruExteriorLights& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruExteriorLights& p, std::string field);


/*
*   VruClusterOperationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterOperationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruClusterOperationContainer& p, std::string field);


/*
*   VruPathPoint - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruPathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruPathPoint& p, std::string field);


/*
*   SequenceOfVruSafeDistanceIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruSafeDistanceIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfVruSafeDistanceIndication& p, std::string field);


/*
*   SequenceOfTrajectoryInterceptionIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfTrajectoryInterceptionIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfTrajectoryInterceptionIndication& p, std::string field);


/*
*   CpmManagementContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CpmManagementContainer& p, std::string field);


/*
*   VehicleSensorPropertyList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorPropertyList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensorPropertyList& p, std::string field);


/*
*   TrailerDataContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerDataContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerDataContainer& p, std::string field);


/*
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass::ObjectClass__class& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass::ObjectClass__class& p, std::string field);


/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass_t& p, std::string field);


/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OffsetPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OffsetPoint& p, std::string field);


/*
*   ParkingPlacesData - Type SEQUENCE OF
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ParkingPlacesData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ParkingPlacesData& p, std::string field);


/*
*   PreReservationRequestMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const PreReservationRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PreReservationRequestMessage& p, std::string field);


/*
*   PreReservationResponseMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const PreReservationResponseMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PreReservationResponseMessage& p, std::string field);


/*
*   ReservationRequestMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const ReservationRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReservationRequestMessage& p, std::string field);


/*
*   ReservationResponseMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const ReservationResponseMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReservationResponseMessage& p, std::string field);


/*
*   CancellationRequestMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const CancellationRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CancellationRequestMessage& p, std::string field);


/*
*   CancellationResponseMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const CancellationResponseMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CancellationResponseMessage& p, std::string field);


/*
*   UpdateRequestMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const UpdateRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, UpdateRequestMessage& p, std::string field);


/*
*   UpdateResponseMessage - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const UpdateResponseMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, UpdateResponseMessage& p, std::string field);


/*
*   MitigationForTechnologies - Type SEQUENCE OF
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const MitigationForTechnologies& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MitigationForTechnologies& p, std::string field);


/*
*   IMZMAreaEllipse - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const IMZMAreaEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IMZMAreaEllipse& p, std::string field);


/*
*   TisTpgDRM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgDRM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgDRM_Management& p, std::string field);


/*
*   TisTpgDRM-Location - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgDRM_Location& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgDRM_Location& p, std::string field);


/*
*   TisTpgTRM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTRM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTRM_Management& p, std::string field);


/*
*   TisTpgTRM-Location - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTRM_Location& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTRM_Location& p, std::string field);


/*
*   TisTpgTCM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTCM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTCM_Management& p, std::string field);


/*
*   TisTpgTCM-Situation - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTCM_Situation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTCM_Situation& p, std::string field);


/*
*   TisTpgTCM-Location - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTCM_Location& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTCM_Location& p, std::string field);


/*
*   TisTpgVDRM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgVDRM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgVDRM_Management& p, std::string field);


/*
*   TisTpgVDPM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgVDPM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgVDPM_Management& p, std::string field);


/*
*   TisTpgEOFM-Management - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgEOFM_Management& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgEOFM_Management& p, std::string field);


/*
*   PressureVariant - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const PressureVariant& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PressureVariant& p, std::string field);


/*
*   TyreData::TyreData__tyreSidewallInformation - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__tyreSidewallInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__tyreSidewallInformation& p, std::string field);


/*
*   TyreData::TyreData__tin - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData::TyreData__tin& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData::TyreData__tin& p, std::string field);


/*
*   TyreData - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreData& p, std::string field);


/*
*   TpgStationData - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TpgStationData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TpgStationData& p, std::string field);


/*
*   TpgNotifContainer - Type SEQUENCE OF
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TpgNotifContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TpgNotifContainer& p, std::string field);


/*
*   ReferencePositionWithConfidence - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ReferencePositionWithConfidence& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReferencePositionWithConfidence& p, std::string field);


/*
*   ManoeuvreCoordinationRational - Type CHOICE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManoeuvreCoordinationRational& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManoeuvreCoordinationRational& p, std::string field);


/*
*   Trajectory::Trajectory__longitudinalPositions - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory::Trajectory__longitudinalPositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory::Trajectory__longitudinalPositions& p, std::string field);


/*
*   Trajectory::Trajectory__lateralPositions - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory::Trajectory__lateralPositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory::Trajectory__lateralPositions& p, std::string field);


/*
*   Trajectory::Trajectory__elevationPositions - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory::Trajectory__elevationPositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory::Trajectory__elevationPositions& p, std::string field);


/*
*   Trajectory::Trajectory__headings - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory::Trajectory__headings& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory::Trajectory__headings& p, std::string field);


/*
*   IntermediatePointReference - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePointReference& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePointReference& p, std::string field);


/*
*   IntermediatePointLane - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePointLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePointLane& p, std::string field);


/*
*   IntermediatePointOffroad - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePointOffroad& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePointOffroad& p, std::string field);


/*
*   ConnectionManeuverAssist-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionManeuverAssist_addGrpC& p, std::string field);


/*
*   ConnectionTrajectory-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionTrajectory_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionTrajectory_addGrpC& p, std::string field);


/*
*   MapData-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MapData_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapData_addGrpC& p, std::string field);


/*
*   RTCMcorrections - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMcorrections& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMcorrections& p, std::string field);


/*
*   ConnectsToList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectsToList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectsToList& p, std::string field);


/*
*   LaneAttributes - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneAttributes& p, std::string field);


/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementList& p, std::string field);


/*
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeListXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeListXY& p, std::string field);


/*
*   RequestorDescription - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorDescription& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorDescription& p, std::string field);


/*
*   SignalStatusPackageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackageList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackageList& p, std::string field);


/*
*   DDD-IO-LIST - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO_LIST& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDD_IO_LIST& p, std::string field);


/*
*   CreditRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CreditRq_t& p, std::string field);


/*
*   DebitRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DebitRq_t& p, std::string field);


/*
*   VarLengthNumber - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const VarLengthNumber& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VarLengthNumber& p, std::string field);


/*
*   GlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GlcPart& p, std::string field);


/*
*   RoadSurfaceContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceContainer& p, std::string field);


/*
*   LayoutContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutContainer& p, std::string field);


/*
*   MlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcParts& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MlcParts& p, std::string field);


/*
*   TrailerCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsList& p, std::string field);


/*
*   CompleteVehicleCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const CompleteVehicleCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CompleteVehicleCharacteristics& p, std::string field);


/*
*   LaneInformation - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneInformation& p, std::string field);


/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpecialVehicleContainer& p, std::string field);


/*
*   DecentralizedEnvironmentalNotificationMessage - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DecentralizedEnvironmentalNotificationMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DecentralizedEnvironmentalNotificationMessage& p, std::string field);


/*
*   TrafficIslandPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrafficIslandPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrafficIslandPosition& p, std::string field);


/*
*   VruLowFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLowFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruLowFrequencyContainer& p, std::string field);


/*
*   SequenceOfVruPathPoint - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruPathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfVruPathPoint& p, std::string field);


/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OriginatingVehicleContainer& p, std::string field);


/*
*   VehicleSensor - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensor& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensor& p, std::string field);


/*
*   AreaCircular - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaCircular& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaCircular& p, std::string field);


/*
*   AreaEllipse - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaEllipse& p, std::string field);


/*
*   AreaRectangle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRectangle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaRectangle& p, std::string field);


/*
*   PolyPointList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PolyPointList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PolyPointList& p, std::string field);


/*
*   AreaRadial - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRadial& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaRadial& p, std::string field);


/*
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClassDescription& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClassDescription& p, std::string field);


/*
*   ItsChargingSpotDataElements - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsChargingSpotDataElements& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsChargingSpotDataElements& p, std::string field);


/*
*   EV-RSR-MessageBody - Type CHOICE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const EV_RSR_MessageBody& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EV_RSR_MessageBody& p, std::string field);


/*
*   InterferenceManagementMitigationType - Type CHOICE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementMitigationType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementMitigationType& p, std::string field);


/*
*   TisTpgDRM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgDRM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgDRM& p, std::string field);


/*
*   TisTpgSNM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgSNM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgSNM& p, std::string field);


/*
*   TisTpgTRM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTRM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTRM& p, std::string field);


/*
*   TisTpgTCM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTCM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTCM& p, std::string field);


/*
*   TisTpgVDRM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgVDRM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgVDRM& p, std::string field);


/*
*   VehicleSpecificData - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const VehicleSpecificData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSpecificData& p, std::string field);


/*
*   TisTpgEOFM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgEOFM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgEOFM& p, std::string field);


/*
*   PressureVariantsList - Type SEQUENCE OF
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const PressureVariantsList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PressureVariantsList& p, std::string field);


/*
*   RTCMEM - Type SEQUENCE
*   From RTCMEM-PDU-Descriptions - File TS103301v211-RTCMEM.asn
*/

Value to_json(const RTCMEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMEM& p, std::string field);


/*
*   McmBasicContainer - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const McmBasicContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, McmBasicContainer& p, std::string field);


/*
*   IntermediatePoint - Type CHOICE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const IntermediatePoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntermediatePoint& p, std::string field);


/*
*   SignalRequestMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestMessage& p, std::string field);


/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const GenericLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GenericLane& p, std::string field);


/*
*   IntersectionState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionState& p, std::string field);


/*
*   IntersectionStateList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionStateList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionStateList& p, std::string field);


/*
*   LaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneList& p, std::string field);


/*
*   RoadLaneSetList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadLaneSetList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadLaneSetList& p, std::string field);


/*
*   RoadSegment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegment& p, std::string field);


/*
*   RoadSegmentList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegmentList& p, std::string field);


/*
*   SignalStatus - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatus& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatus& p, std::string field);


/*
*   SignalStatusList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusList& p, std::string field);


/*
*   InternationalSign-destinationInformation - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_destinationInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_destinationInformation& p, std::string field);


/*
*   GlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcParts& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GlcParts& p, std::string field);


/*
*   MapLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapLocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapLocationContainer& p, std::string field);


/*
*   LaneConfiguration - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneConfiguration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneConfiguration& p, std::string field);


/*
*   VehicleCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsList& p, std::string field);


/*
*   ISO14823Attribute - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Attribute& p, std::string field);


/*
*   CamParameters - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CamParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CamParameters& p, std::string field);


/*
*   DENM - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DENM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DENM& p, std::string field);


/*
*   VruLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruLanePosition& p, std::string field);


/*
*   VruMotionPredictionContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruMotionPredictionContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruMotionPredictionContainer& p, std::string field);


/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const StationDataContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StationDataContainer& p, std::string field);


/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObject& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObject& p, std::string field);


/*
*   AreaPolygon - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaPolygon& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaPolygon& p, std::string field);


/*
*   FreeSpaceArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceArea& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceArea& p, std::string field);


/*
*   SREM - Type SEQUENCE
*   From SREM-PDU-Descriptions - File TS103301v211-SREM.asn
*/

Value to_json(const SREM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SREM& p, std::string field);


/*
*   ItsChargingSpots - Type SEQUENCE OF
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsChargingSpots& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsChargingSpots& p, std::string field);


/*
*   EV-RSR - Type SEQUENCE
*   From EV-RechargingSpotReservation-PDU-Descriptions - File EV-RSR-PDU-Descriptions.asn
*/

Value to_json(const EV_RSR& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EV_RSR& p, std::string field);


/*
*   InterferenceManagementInfoPerChannel - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementInfoPerChannel& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementInfoPerChannel& p, std::string field);


/*
*   InterferenceManagementZoneShape - Type CHOICE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementZoneShape& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementZoneShape& p, std::string field);


/*
*   TyreSetVariant - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TyreSetVariant& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TyreSetVariant& p, std::string field);


/*
*   Trajectory::Trajectory__intermediatePoints - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory::Trajectory__intermediatePoints& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory::Trajectory__intermediatePoints& p, std::string field);


/*
*   Trajectory - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const Trajectory& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Trajectory& p, std::string field);


/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SPAT& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPAT& p, std::string field);


/*
*   SignalStatusMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusMessage& p, std::string field);


/*
*   IntersectionGeometry - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometry& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionGeometry& p, std::string field);


/*
*   IntersectionGeometryList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometryList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionGeometryList& p, std::string field);


/*
*   GddAttribute - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddAttribute& p, std::string field);


/*
*   GeographicLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeographicLocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GeographicLocationContainer& p, std::string field);


/*
*   RccPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RccPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RccPart& p, std::string field);


/*
*   TcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TcPart& p, std::string field);


/*
*   ISO14823Attributes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Attributes& p, std::string field);


/*
*   AnyCatalogue - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AnyCatalogue& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AnyCatalogue& p, std::string field);


/*
*   ISO14823Code - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code& p, std::string field);


/*
*   RSCode::RSCode__code - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode::RSCode__code& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSCode::RSCode__code& p, std::string field);


/*
*   RSCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSCode& p, std::string field);


/*
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CoopAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CoopAwareness& p, std::string field);


/*
*   VruHighFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruHighFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruHighFrequencyContainer& p, std::string field);


/*
*   ClusterBoundingBoxShape - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBoundingBoxShape& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterBoundingBoxShape& p, std::string field);


/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainer_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObjectContainer_t& p, std::string field);


/*
*   DetectionArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const DetectionArea& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DetectionArea& p, std::string field);


/*
*   FreeSpaceAddendum - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendum& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceAddendum& p, std::string field);


/*
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

Value to_json(const SPATEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPATEM& p, std::string field);


/*
*   SSEM - Type SEQUENCE
*   From SSEM-PDU-Descriptions - File TS103301v211-SSEM.asn
*/

Value to_json(const SSEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SSEM& p, std::string field);


/*
*   ItsChargingStationData - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsChargingStationData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsChargingStationData& p, std::string field);


/*
*   ZoneDefinition - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const ZoneDefinition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ZoneDefinition& p, std::string field);


/*
*   InterferenceManagementInfo - Type SEQUENCE OF
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementInfo& p, std::string field);


/*
*   PlacardTable - Type SEQUENCE OF
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const PlacardTable& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PlacardTable& p, std::string field);


/*
*   ManoeuvreAdvice - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManoeuvreAdvice& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManoeuvreAdvice& p, std::string field);


/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MapData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapData_t& p, std::string field);


/*
*   GddAttributes - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddAttributes& p, std::string field);


/*
*   RoadConfigurationContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadConfigurationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadConfigurationContainer& p, std::string field);


/*
*   TextContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TextContainer& p, std::string field);


/*
*   RoadSignCodes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSignCodes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSignCodes& p, std::string field);


/*
*   AutomatedVehicleRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRule& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleRule& p, std::string field);


/*
*   PlatooningRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRule& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PlatooningRule& p, std::string field);


/*
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CAM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CAM& p, std::string field);


/*
*   VruClusterInformationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruClusterInformationContainer& p, std::string field);


/*
*   SensorInformation - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorInformation& p, std::string field);


/*
*   FreeSpaceAddendumContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendumContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceAddendumContainer& p, std::string field);


/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

Value to_json(const MAPEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MAPEM& p, std::string field);


/*
*   ItsEVCSNData::ItsEVCSNData__chargingStationsData - Type SEQUENCE OF
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsEVCSNData::ItsEVCSNData__chargingStationsData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsEVCSNData::ItsEVCSNData__chargingStationsData& p, std::string field);


/*
*   ItsEVCSNData - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const ItsEVCSNData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsEVCSNData& p, std::string field);


/*
*   InterferenceManagementZone - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementZone& p, std::string field);


/*
*   TisTpgVDPM - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgVDPM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgVDPM& p, std::string field);


/*
*   ExecutantData - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ExecutantData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ExecutantData& p, std::string field);


/*
*   GddStructure - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure& p, std::string field);


/*
*   GicPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GicPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GicPart& p, std::string field);


/*
*   AutomatedVehicleRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRules& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleRules& p, std::string field);


/*
*   PlatooningRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRules& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PlatooningRules& p, std::string field);


/*
*   VamParameters - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VamParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VamParameters& p, std::string field);


/*
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorInformationContainer& p, std::string field);


/*
*   EVChargingSpotNotificationPOIMessage - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const EVChargingSpotNotificationPOIMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EVChargingSpotNotificationPOIMessage& p, std::string field);


/*
*   InterferenceManagementZones - Type SEQUENCE OF
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementZones& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementZones& p, std::string field);


/*
*   TisTpgTransaction - Type CHOICE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTransaction& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTransaction& p, std::string field);


/*
*   ManoeuvreAdviceContainer::ManoeuvreAdviceContainer__executantData - Type SEQUENCE OF
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManoeuvreAdviceContainer::ManoeuvreAdviceContainer__executantData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManoeuvreAdviceContainer::ManoeuvreAdviceContainer__executantData& p, std::string field);


/*
*   ManoeuvreAdviceContainer - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const ManoeuvreAdviceContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManoeuvreAdviceContainer& p, std::string field);


/*
*   GeneralIviContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeneralIviContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GeneralIviContainer& p, std::string field);


/*
*   AvcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AvcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AvcPart& p, std::string field);


/*
*   VruAwareness - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruAwareness& p, std::string field);


/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CpmParameters& p, std::string field);


/*
*   EvcsnPdu - Type SEQUENCE
*   From EVCSN-PDU-Descriptions - File EVCSN-PDU-Descriptions.asn
*/

Value to_json(const EvcsnPdu& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EvcsnPdu& p, std::string field);


/*
*   ImzmContainer - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const ImzmContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ImzmContainer& p, std::string field);


/*
*   TisTpgTransactionsPdu - Type SEQUENCE
*   From TIS-TPG-Transactions-Descriptions - File TIS-TPG-Transactions-Descriptions.asn
*/

Value to_json(const TisTpgTransactionsPdu& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TisTpgTransactionsPdu& p, std::string field);


/*
*   VehicleManoeuvreContainer - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const VehicleManoeuvreContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleManoeuvreContainer& p, std::string field);


/*
*   IviContainer - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviContainer& p, std::string field);


/*
*   AutomatedVehicleContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleContainer& p, std::string field);


/*
*   VAM - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VAM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VAM& p, std::string field);


/*
*   CollectivePerceptionMessage - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CollectivePerceptionMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CollectivePerceptionMessage& p, std::string field);


/*
*   ImzmParameters - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const ImzmParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ImzmParameters& p, std::string field);


/*
*   McmContainer - Type CHOICE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const McmContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, McmContainer& p, std::string field);


/*
*   IviContainers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainers& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviContainers& p, std::string field);


/*
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CPM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CPM& p, std::string field);


/*
*   InterferenceManagementZoneMessage - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const InterferenceManagementZoneMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InterferenceManagementZoneMessage& p, std::string field);


/*
*   WrappedMcmInformationBlocks - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const WrappedMcmInformationBlocks& p, Document::AllocatorType& allocator);

void from_json(const Value& j, WrappedMcmInformationBlocks& p, std::string field);


/*
*   IviStructure - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviStructure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviStructure& p, std::string field);


/*
*   IVIM - Type SEQUENCE
*   From IVIM-PDU-Descriptions - File TS103301v211-IVIM.asn
*/

Value to_json(const IVIM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IVIM& p, std::string field);


/*
*   IMZM - Type SEQUENCE
*   From IMZM-PDU-Descriptions - File IMZM-PDU-Descriptions.asn
*/

Value to_json(const IMZM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IMZM& p, std::string field);


/*
*   MCM - Type SEQUENCE
*   From MCM-PDU-Descriptions - File MCM-PDU-Descriptions.asn
*/

Value to_json(const MCM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MCM& p, std::string field);


#endif
