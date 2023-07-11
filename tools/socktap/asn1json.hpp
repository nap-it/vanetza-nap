/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2023-07-10 22:54:49.895345
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

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
void from_json(const Value& j, TimestampIts_t& p);
Value to_json(const long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long& p);
Value to_json(const unsigned long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned long& p);
Value to_json(const unsigned& p, Document::AllocatorType& allocator);
void from_json(const Value& j, unsigned& p);
Value to_json(const double& p, Document::AllocatorType& allocator);
void from_json(const Value& j, double& p);
Value to_json(const bool& p, Document::AllocatorType& allocator);
void from_json(const Value& j, bool& p);
Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, OCTET_STRING_t& p);


/*
*   ItsPduHeader - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItsPduHeader_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsPduHeader_t& p);


/*
*   DeltaReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DeltaReferencePosition_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaReferencePosition_t& p);


/*
*   Altitude - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Altitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Altitude& p);


/*
*   PosConfidenceEllipse - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PosConfidenceEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PosConfidenceEllipse& p);


/*
*   PathPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PathPoint& p);


/*
*   AccelerationControl - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_AccelerationControl(const AccelerationControl_t p, Document::AllocatorType& allocator);

void from_json_AccelerationControl(const Value& j, AccelerationControl_t& p);


/*
*   CauseCode - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CauseCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CauseCode& p);


/*
*   Curvature - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Curvature& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Curvature& p);


/*
*   Heading - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Heading& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Heading& p);


/*
*   DrivingLaneStatus - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_DrivingLaneStatus(const DrivingLaneStatus_t p, Document::AllocatorType& allocator);

void from_json_DrivingLaneStatus(const Value& j, DrivingLaneStatus_t& p);


/*
*   Speed - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Speed& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Speed& p);


/*
*   LongitudinalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LongitudinalAcceleration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LongitudinalAcceleration& p);


/*
*   LateralAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const LateralAcceleration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LateralAcceleration& p);


/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VerticalAcceleration_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VerticalAcceleration_t& p);


/*
*   ExteriorLights - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_ExteriorLights(const ExteriorLights_t p, Document::AllocatorType& allocator);

void from_json_ExteriorLights(const Value& j, ExteriorLights_t& p);


/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DangerousGoodsExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DangerousGoodsExtended& p);


/*
*   SpecialTransportType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_SpecialTransportType(const SpecialTransportType_t p, Document::AllocatorType& allocator);

void from_json_SpecialTransportType(const Value& j, SpecialTransportType_t& p);


/*
*   LightBarSirenInUse - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_LightBarSirenInUse(const LightBarSirenInUse_t p, Document::AllocatorType& allocator);

void from_json_LightBarSirenInUse(const Value& j, LightBarSirenInUse_t& p);


/*
*   PositionOfOccupants - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_PositionOfOccupants(const PositionOfOccupants_t p, Document::AllocatorType& allocator);

void from_json_PositionOfOccupants(const Value& j, PositionOfOccupants_t& p);


/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleIdentification& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleIdentification& p);


/*
*   EnergyStorageType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EnergyStorageType(const EnergyStorageType_t p, Document::AllocatorType& allocator);

void from_json_EnergyStorageType(const Value& j, EnergyStorageType_t& p);


/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const VehicleLength_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleLength_t& p);


/*
*   PathHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PathHistory& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PathHistory& p);


/*
*   EmergencyPriority - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json_EmergencyPriority(const EmergencyPriority_t p, Document::AllocatorType& allocator);

void from_json_EmergencyPriority(const Value& j, EmergencyPriority_t& p);


/*
*   SteeringWheelAngle - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const SteeringWheelAngle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SteeringWheelAngle& p);


/*
*   YawRate - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const YawRate& p, Document::AllocatorType& allocator);

void from_json(const Value& j, YawRate& p);


/*
*   ActionID - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ActionID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ActionID& p);


/*
*   ProtectedCommunicationZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ProtectedCommunicationZone& p);


/*
*   Traces - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const Traces& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Traces& p);


/*
*   PositionOfPillars - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PositionOfPillars& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionOfPillars& p);


/*
*   RestrictedTypes - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const RestrictedTypes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictedTypes& p);


/*
*   EventPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EventPoint& p);


/*
*   ProtectedCommunicationZonesRSU - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ProtectedCommunicationZonesRSU& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ProtectedCommunicationZonesRSU& p);


/*
*   CenDsrcTollingZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const CenDsrcTollingZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CenDsrcTollingZone& p);


/*
*   LaneAttributes-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const LaneAttributes_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneAttributes_addGrpC& p);


/*
*   MovementEvent-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MovementEvent_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEvent_addGrpC& p);


/*
*   Position3D-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Position3D_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Position3D_addGrpC& p);


/*
*   RestrictionUserType-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RestrictionUserType_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserType_addGrpC& p);


/*
*   RequestorDescription-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const RequestorDescription_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorDescription_addGrpC& p);


/*
*   SignalStatusPackage-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackage_addGrpC& p);


/*
*   Node - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const Node& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node& p);


/*
*   NodeLink - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeLink& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeLink& p);


/*
*   PrioritizationResponse - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PrioritizationResponse& p);


/*
*   PrioritizationResponseList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const PrioritizationResponseList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PrioritizationResponseList& p);


/*
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeed& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AdvisorySpeed& p);


/*
*   AdvisorySpeedList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const AdvisorySpeedList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AdvisorySpeedList_t& p);


/*
*   AntennaOffsetSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const AntennaOffsetSet& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AntennaOffsetSet& p);


/*
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetXaxis& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane::ComputedLane__offsetXaxis& p);


/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane::ComputedLane__offsetYaxis& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane::ComputedLane__offsetYaxis& p);


/*
*   ComputedLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ComputedLane_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedLane_t& p);


/*
*   ConnectionManeuverAssist - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionManeuverAssist_t& p);


/*
*   DataParameters - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DataParameters_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DataParameters_t& p);


/*
*   DDateTime - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const DDateTime& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDateTime& p);


/*
*   EnabledLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const EnabledLaneList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EnabledLaneList_t& p);


/*
*   IntersectionAccessPoint - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionAccessPoint_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionAccessPoint_t& p);


/*
*   IntersectionReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionReferenceID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionReferenceID& p);


/*
*   LaneSharing - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneSharing(const LaneSharing_t p, Document::AllocatorType& allocator);

void from_json_LaneSharing(const Value& j, LaneSharing_t& p);


/*
*   ManeuverAssistList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ManeuverAssistList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManeuverAssistList& p);


/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeXYList& p);


/*
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_LLmD_64b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_LLmD_64b& p);


/*
*   Node-XY-20b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_20b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_20b& p);


/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_22b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_22b& p);


/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_24b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_24b& p);


/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_26b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_26b& p);


/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_28b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_28b& p);


/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_XY_32b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_32b& p);


/*
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeOffsetPointXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeOffsetPointXY& p);


/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const OverlayLaneList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OverlayLaneList& p);


/*
*   PositionalAccuracy - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionalAccuracy& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionalAccuracy& p);


/*
*   PositionConfidenceSet - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const PositionConfidenceSet& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PositionConfidenceSet& p);


/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Position3D_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Position3D_t& p);


/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RegulatorySpeedLimit& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RegulatorySpeedLimit& p);


/*
*   RequestorType - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorType& p);


/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserType& p);


/*
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserTypeList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserTypeList& p);


/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentReferenceID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegmentReferenceID& p);


/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SegmentAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SegmentAttributeXYList& p);


/*
*   SignalControlZone - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalControlZone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalControlZone& p);


/*
*   SignalRequest - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequest& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequest& p);


/*
*   SignalRequestPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestPackage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestPackage& p);


/*
*   SpeedandHeadingIsoandThrottleConfidence - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedandHeadingIsoandThrottleConfidence& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedandHeadingIsoandThrottleConfidence& p);


/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SpeedLimitList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedLimitList& p);


/*
*   TimeChangeDetails - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TimeChangeDetails& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TimeChangeDetails& p);


/*
*   TransmissionAndSpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const TransmissionAndSpeed_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TransmissionAndSpeed_t& p);


/*
*   VehicleID - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const VehicleID_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleID_t& p);


/*
*   AllowedManeuvers - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_AllowedManeuvers(const AllowedManeuvers_t p, Document::AllocatorType& allocator);

void from_json_AllowedManeuvers(const Value& j, AllowedManeuvers_t& p);


/*
*   GNSSstatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_GNSSstatus(const GNSSstatus_t p, Document::AllocatorType& allocator);

void from_json_GNSSstatus(const Value& j, GNSSstatus_t& p);


/*
*   IntersectionStatusObject - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_IntersectionStatusObject(const IntersectionStatusObject_t p, Document::AllocatorType& allocator);

void from_json_IntersectionStatusObject(const Value& j, IntersectionStatusObject_t& p);


/*
*   LaneAttributes-Barrier - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Barrier(const LaneAttributes_Barrier_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Barrier(const Value& j, LaneAttributes_Barrier_t& p);


/*
*   LaneAttributes-Bike - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Bike(const LaneAttributes_Bike_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Bike(const Value& j, LaneAttributes_Bike_t& p);


/*
*   LaneAttributes-Crosswalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Crosswalk(const LaneAttributes_Crosswalk_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Crosswalk(const Value& j, LaneAttributes_Crosswalk_t& p);


/*
*   LaneAttributes-Parking - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Parking(const LaneAttributes_Parking_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Parking(const Value& j, LaneAttributes_Parking_t& p);


/*
*   LaneAttributes-Sidewalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Sidewalk(const LaneAttributes_Sidewalk_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Sidewalk(const Value& j, LaneAttributes_Sidewalk_t& p);


/*
*   LaneAttributes-Striping - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Striping(const LaneAttributes_Striping_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Striping(const Value& j, LaneAttributes_Striping_t& p);


/*
*   LaneAttributes-TrackedVehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_TrackedVehicle(const LaneAttributes_TrackedVehicle_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_TrackedVehicle(const Value& j, LaneAttributes_TrackedVehicle_t& p);


/*
*   LaneAttributes-Vehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneAttributes_Vehicle(const LaneAttributes_Vehicle_t p, Document::AllocatorType& allocator);

void from_json_LaneAttributes_Vehicle(const Value& j, LaneAttributes_Vehicle_t& p);


/*
*   LaneDirection - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_LaneDirection(const LaneDirection_t p, Document::AllocatorType& allocator);

void from_json_LaneDirection(const Value& j, LaneDirection_t& p);


/*
*   TransitVehicleStatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

Value to_json_TransitVehicleStatus(const TransitVehicleStatus_t p, Document::AllocatorType& allocator);

void from_json_TransitVehicleStatus(const Value& j, TransitVehicleStatus_t& p);


/*
*   CS5 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS5& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS5& p);


/*
*   FreightContainerData - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const FreightContainerData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreightContainerData_t& p);


/*
*   CountryCode - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_CountryCode(const CountryCode_t p, Document::AllocatorType& allocator);

void from_json_CountryCode(const Value& j, CountryCode_t& p);


/*
*   ServiceNumber - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceNumber(const ServiceNumber_t p, Document::AllocatorType& allocator);

void from_json_ServiceNumber(const Value& j, ServiceNumber_t& p);


/*
*   GeoGraphicalLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_GeoGraphicalLimit(const GeoGraphicalLimit_t p, Document::AllocatorType& allocator);

void from_json_GeoGraphicalLimit(const Value& j, GeoGraphicalLimit_t& p);


/*
*   ServiceApplicationLimit - Type BIT STRING
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json_ServiceApplicationLimit(const ServiceApplicationLimit_t p, Document::AllocatorType& allocator);

void from_json_ServiceApplicationLimit(const Value& j, ServiceApplicationLimit_t& p);


/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__serviceCategoryCode& p);


/*
*   GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode::GddStructure__pictogramCode__pictogramCategoryCode& p);


/*
*   GddStructure::GddStructure__pictogramCode - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure::GddStructure__pictogramCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure::GddStructure__pictogramCode& p);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__year - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__year& p);


/*
*   InternationalSign-speedLimits - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_speedLimits& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_speedLimits& p);


/*
*   DayOfWeek - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_DayOfWeek(const DayOfWeek_t p, Document::AllocatorType& allocator);

void from_json_DayOfWeek(const Value& j, DayOfWeek_t& p);


/*
*   DestinationPlace - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlace& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationPlace& p);


/*
*   DestinationPlaces - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationPlaces& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationPlaces& p);


/*
*   DestinationRoad - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoad& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationRoad& p);


/*
*   DestinationRoads - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DestinationRoads& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DestinationRoads& p);


/*
*   Distance - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Distance& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Distance& p);


/*
*   DistanceOrDuration - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DistanceOrDuration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DistanceOrDuration& p);


/*
*   HoursMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const HoursMinutes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HoursMinutes& p);


/*
*   MonthDay - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const MonthDay& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MonthDay& p);


/*
*   RepeatingPeriodDayTypes - Type BIT STRING
*   From GDD - File ISO14823.asn
*/

Value to_json_RepeatingPeriodDayTypes(const RepeatingPeriodDayTypes_t p, Document::AllocatorType& allocator);

void from_json_RepeatingPeriodDayTypes(const Value& j, RepeatingPeriodDayTypes_t& p);


/*
*   Weight - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const Weight& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Weight& p);


/*
*   AxleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AxleWeightLimits_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AxleWeightLimits_t& p);


/*
*   AddRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const AddRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AddRq_t& p);


/*
*   ChannelRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ChannelRq_t& p);


/*
*   ChannelRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ChannelRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ChannelRs_t& p);


/*
*   SubRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SubRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SubRq_t& p);


/*
*   DateCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateCompact_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateCompact_t& p);


/*
*   DieselEmissionValues::DieselEmissionValues__particulate - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues::DieselEmissionValues__particulate& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DieselEmissionValues::DieselEmissionValues__particulate& p);


/*
*   DieselEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DieselEmissionValues_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DieselEmissionValues_t& p);


/*
*   EnvironmentalCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EnvironmentalCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EnvironmentalCharacteristics_t& p);


/*
*   Engine - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Engine_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Engine_t& p);


/*
*   EquipmentStatus - Type BIT STRING
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json_EquipmentStatus(const EquipmentStatus_t p, Document::AllocatorType& allocator);

void from_json_EquipmentStatus(const Value& j, EquipmentStatus_t& p);


/*
*   ExhaustEmissionValues - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ExhaustEmissionValues_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ExhaustEmissionValues_t& p);


/*
*   LPN - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const LPN_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LPN_t& p);


/*
*   PassengerCapacity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PassengerCapacity_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PassengerCapacity_t& p);


/*
*   SignedValue - Type CHOICE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SignedValue_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignedValue_t& p);


/*
*   Provider - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const Provider_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Provider_t& p);


/*
*   PurseBalance - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PurseBalance_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PurseBalance_t& p);


/*
*   ReceiptContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptContract_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptContract_t& p);


/*
*   SessionClass - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionClass_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SessionClass_t& p);


/*
*   SessionLocation - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SessionLocation_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SessionLocation_t& p);


/*
*   DateAndTime::DateAndTime__timeCompact - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime::DateAndTime__timeCompact& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateAndTime::DateAndTime__timeCompact& p);


/*
*   DateAndTime - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DateAndTime_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DateAndTime_t& p);


/*
*   SoundLevel - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SoundLevel_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SoundLevel_t& p);


/*
*   TrailerDetails - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const TrailerDetails_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerDetails_t& p);


/*
*   ValidityOfContract - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ValidityOfContract_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ValidityOfContract_t& p);


/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber::VehicleAxles__vehicleAxlesNumber__numberOfAxles& p);


/*
*   VehicleAxles::VehicleAxles__vehicleAxlesNumber - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles::VehicleAxles__vehicleAxlesNumber& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles::VehicleAxles__vehicleAxlesNumber& p);


/*
*   VehicleAxles - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleAxles_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleAxles_t& p);


/*
*   VehicleDimensions - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleDimensions_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleDimensions_t& p);


/*
*   VehicleSpecificCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleSpecificCharacteristics_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSpecificCharacteristics_t& p);


/*
*   VehicleWeightLimits - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const VehicleWeightLimits_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleWeightLimits_t& p);


/*
*   AttributeIdList - Type SEQUENCE OF
*   From EfcDsrcGeneric - File ISO14906-1-7.asn
*/

Value to_json(const AttributeIdList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AttributeIdList_t& p);


/*
*   Attributes - Type SEQUENCE
*   From EfcDsrcGeneric - File ISO14906-1-7.asn
*/

Value to_json(const Attributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Attributes_t& p);


/*
*   Ext2 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Ext2& p);


/*
*   EuVehicleCategoryCode - Type CHOICE
*   From ElectronicRegistrationIdentificationVehicleDataModule - File ISO24534-3.asn
*/

Value to_json(const EuVehicleCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EuVehicleCategoryCode& p);


/*
*   ConnectedDenms - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConnectedDenms& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectedDenms& p);


/*
*   DeltaReferencePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaReferencePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaReferencePositions& p);


/*
*   IviIdentificationNumbers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviIdentificationNumbers& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviIdentificationNumbers& p);


/*
*   LaneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneIds& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneIds& p);


/*
*   LanePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LanePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LanePositions& p);


/*
*   SaeAutomationLevels - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const SaeAutomationLevels& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SaeAutomationLevels& p);


/*
*   ZoneIds - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ZoneIds& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ZoneIds& p);


/*
*   AbsolutePosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePosition& p);


/*
*   AbsolutePositionWAltitude - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionWAltitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositionWAltitude& p);


/*
*   ComputedSegment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ComputedSegment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ComputedSegment& p);


/*
*   DeltaPosition - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaPosition& p);


/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__serviceCategoryCode& p);


/*
*   ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode::ISO14823Code__pictogramCode__pictogramCategoryCode& p);


/*
*   ISO14823Code::ISO14823Code__pictogramCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code::ISO14823Code__pictogramCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code::ISO14823Code__pictogramCode& p);


/*
*   LaneCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneCharacteristics& p);


/*
*   LayoutComponent - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponent& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutComponent& p);


/*
*   LoadType - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LoadType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LoadType& p);


/*
*   MapReference - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapReference& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapReference& p);


/*
*   RoadSurfaceDynamicCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceDynamicCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceDynamicCharacteristics& p);


/*
*   RoadSurfaceStaticCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceStaticCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceStaticCharacteristics& p);


/*
*   RSCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSCode& p);


/*
*   Text - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Text& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Text& p);


/*
*   VehicleCharacteristicsFixValues - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValues& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsFixValues& p);


/*
*   VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRanges::VehicleCharacteristicsRanges__limits& p);


/*
*   VehicleCharacteristicsRanges - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRanges& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRanges& p);


/*
*   BasicVehicleContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerHighFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicVehicleContainerHighFrequency& p);


/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicVehicleContainerLowFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicVehicleContainerLowFrequency& p);


/*
*   SpecialTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialTransportContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpecialTransportContainer& p);


/*
*   DangerousGoodsContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const DangerousGoodsContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DangerousGoodsContainer& p);


/*
*   RescueContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RescueContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RescueContainer& p);


/*
*   EmergencyContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const EmergencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EmergencyContainer& p);


/*
*   SafetyCarContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SafetyCarContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SafetyCarContainer& p);


/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RSUContainerHighFrequency& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSUContainerHighFrequency& p);


/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const LocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LocationContainer& p);


/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ImpactReductionContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ImpactReductionContainer& p);


/*
*   StationaryVehicleContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const StationaryVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StationaryVehicleContainer& p);


/*
*   ReferenceDenms - Type SEQUENCE OF
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ReferenceDenms& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReferenceDenms& p);


/*
*   MapPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const MapPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapPosition& p);


/*
*   VruProfileAndSubprofile - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruProfileAndSubprofile& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruProfileAndSubprofile& p);


/*
*   VruSpecificExteriorLights - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_VruSpecificExteriorLights(const VruSpecificExteriorLights_t p, Document::AllocatorType& allocator);

void from_json_VruSpecificExteriorLights(const Value& j, VruSpecificExteriorLights_t& p);


/*
*   ClusterProfiles - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json_ClusterProfiles(const ClusterProfiles_t p, Document::AllocatorType& allocator);

void from_json_ClusterProfiles(const Value& j, ClusterProfiles_t& p);


/*
*   ClusterJoinInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterJoinInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterJoinInfo& p);


/*
*   ClusterLeaveInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterLeaveInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterLeaveInfo& p);


/*
*   ClusterBreakupInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBreakupInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterBreakupInfo& p);


/*
*   VruSafeDistanceIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruSafeDistanceIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruSafeDistanceIndication& p);


/*
*   TrajectoryInterceptionIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrajectoryInterceptionIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrajectoryInterceptionIndication& p);


/*
*   HeadingChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const HeadingChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HeadingChangeIndication& p);


/*
*   AccelerationChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const AccelerationChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AccelerationChangeIndication& p);


/*
*   StabilityChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const StabilityChangeIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StabilityChangeIndication& p);


/*
*   LaneDataAttribute - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneDataAttribute& p);


/*
*   LaneDataAttributeList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const LaneDataAttributeList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneDataAttributeList& p);


/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeAttributeSetXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeSetXY_t& p);


/*
*   OriginatingRSUContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingRSUContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OriginatingRSUContainer& p);


/*
*   VehicleSensorProperties - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorProperties& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensorProperties& p);


/*
*   ObjectDistanceWithConfidence - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDistanceWithConfidence& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectDistanceWithConfidence& p);


/*
*   ObjectDimension - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectDimension& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectDimension& p);


/*
*   CartesianAngle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CartesianAngle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CartesianAngle& p);


/*
*   WGS84Angle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const WGS84Angle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, WGS84Angle& p);


/*
*   SpeedExtended - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SpeedExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedExtended& p);


/*
*   SensorIdList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorIdList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorIdList& p);


/*
*   TrailerData - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerData& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerData& p);


/*
*   LongitudinalLanePosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const LongitudinalLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LongitudinalLanePosition& p);


/*
*   MatchedPosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const MatchedPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MatchedPosition& p);


/*
*   PerceivedObjectContainerSegmentInfo - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainerSegmentInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObjectContainerSegmentInfo& p);


/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass_t& p);


/*
*   VehicleSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSubclass& p);


/*
*   PersonSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PersonSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PersonSubclass& p);


/*
*   AnimalSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AnimalSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AnimalSubclass& p);


/*
*   OtherSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OtherSubclass& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OtherSubclass& p);


/*
*   NodeOffsetPointZ - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const NodeOffsetPointZ& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeOffsetPointZ& p);


/*
*   ReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ReferencePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReferencePosition& p);


/*
*   PtActivation - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PtActivation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PtActivation& p);


/*
*   ClosedLanes - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ClosedLanes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClosedLanes& p);


/*
*   ItineraryPath - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const ItineraryPath& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItineraryPath& p);


/*
*   EventHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const EventHistory& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EventHistory& p);


/*
*   DigitalMap - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const DigitalMap_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DigitalMap_t& p);


/*
*   IntersectionState-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const IntersectionState_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionState_addGrpC& p);


/*
*   NodeAttributeSet-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const NodeAttributeSet_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeSet_addGrpC& p);


/*
*   ItsStationPosition - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsStationPosition& p);


/*
*   ItsStationPositionList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ItsStationPositionList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ItsStationPositionList& p);


/*
*   SignalHeadLocation - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalHeadLocation& p);


/*
*   SignalHeadLocationList - Type SEQUENCE OF
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const SignalHeadLocationList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalHeadLocationList& p);


/*
*   ConnectingLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectingLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectingLane& p);


/*
*   Connection - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Connection& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Connection& p);


/*
*   FullPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const FullPositionVector& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FullPositionVector& p);


/*
*   LaneTypeAttributes - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneTypeAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneTypeAttributes& p);


/*
*   MovementEvent - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementEvent& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEvent& p);


/*
*   MovementEventList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementEventList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementEventList& p);


/*
*   MovementState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementState& p);


/*
*   NodeXY - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeXY_t& p);


/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeSetXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeSetXY& p);


/*
*   RequestorPositionVector - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorPositionVector& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorPositionVector& p);


/*
*   RestrictionClassAssignment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassAssignment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionClassAssignment& p);


/*
*   RestrictionClassList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionClassList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionClassList& p);


/*
*   RTCMheader - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMheader& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMheader& p);


/*
*   RTCMmessageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMmessageList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMmessageList& p);


/*
*   SignalRequesterInfo - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequesterInfo& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequesterInfo& p);


/*
*   SignalRequestList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestList& p);


/*
*   SignalStatusPackage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackage& p);


/*
*   CS1 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS1& p);


/*
*   CS2 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS2& p);


/*
*   CS3 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS3& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS3& p);


/*
*   CS4 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS4& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS4& p);


/*
*   CS8 - Type SEQUENCE
*   From AVIAEINumberingAndDataStructures - File ISO14816.asn
*/

Value to_json(const CS8& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CS8& p);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__month-day - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__month_day& p);


/*
*   InternationalSign-applicablePeriod::InternationalSign-applicablePeriod__hourMinutes - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod::InternationalSign_applicablePeriod__hourMinutes& p);


/*
*   InternationalSign-applicablePeriod - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicablePeriod& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicablePeriod& p);


/*
*   InternationalSign-applicableVehicleDimensions - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_applicableVehicleDimensions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_applicableVehicleDimensions& p);


/*
*   InternationalSign-section - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_section& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_section& p);


/*
*   DDD-IO - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDD_IO& p);


/*
*   CopyRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CopyRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CopyRq_t& p);


/*
*   CreditRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CreditRs_t& p);


/*
*   DebitRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DebitRs_t& p);


/*
*   GetInstanceRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const GetInstanceRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GetInstanceRq_t& p);


/*
*   GetStampedRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const GetStampedRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GetStampedRq_t& p);


/*
*   SetInstanceRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SetInstanceRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SetInstanceRq_t& p);


/*
*   ContractValidity - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ContractValidity_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ContractValidity_t& p);


/*
*   EFC-ContextMark - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const EFC_ContextMark_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, EFC_ContextMark_t& p);


/*
*   PaymentFee - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentFee_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PaymentFee_t& p);


/*
*   PaymentMeans - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const PaymentMeans_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PaymentMeans_t& p);


/*
*   ReceiptData - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptData_t& p);


/*
*   ReceiptFinancialPart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptFinancialPart_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptFinancialPart_t& p);


/*
*   ReceiptServicePart - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const ReceiptServicePart_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ReceiptServicePart_t& p);


/*
*   TrailerCharacteristics - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const TrailerCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristics& p);


/*
*   AttributeList - Type SEQUENCE OF
*   From EfcDsrcGeneric - File ISO14906-1-7.asn
*/

Value to_json(const AttributeList_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AttributeList_t& p);


/*
*   Ext1 - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const Ext1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Ext1& p);


/*
*   IviManagementContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviManagementContainer& p);


/*
*   RscPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RscPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RscPart& p);


/*
*   MlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MlcPart& p);


/*
*   AbsolutePositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositions& p);


/*
*   AbsolutePositionsWAltitude - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AbsolutePositionsWAltitude& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AbsolutePositionsWAltitude& p);


/*
*   DeltaPositions - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const DeltaPositions& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DeltaPositions& p);


/*
*   ConstraintTextLines1 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines1& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConstraintTextLines1& p);


/*
*   ConstraintTextLines2 - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ConstraintTextLines2& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConstraintTextLines2& p);


/*
*   LayoutComponents - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutComponents& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutComponents& p);


/*
*   RoadSignCodes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSignCodes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSignCodes& p);


/*
*   TextLines - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextLines& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TextLines& p);


/*
*   TrailerCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsList& p);


/*
*   TrailerCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsFixValuesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsFixValuesList& p);


/*
*   TrailerCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TrailerCharacteristicsRangesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerCharacteristicsRangesList& p);


/*
*   VehicleCharacteristicsFixValuesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsFixValuesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsFixValuesList& p);


/*
*   VehicleCharacteristicsRangesList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsRangesList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsRangesList& p);


/*
*   ValidityPeriods - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ValidityPeriods& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ValidityPeriods& p);


/*
*   AutomatedVehicleRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRule& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleRule& p);


/*
*   PlatooningRule - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRule& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PlatooningRule& p);


/*
*   PolygonalLine - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PolygonalLine& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PolygonalLine& p);


/*
*   Segment - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Segment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Segment& p);


/*
*   TractorCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TractorCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TractorCharacteristics& p);


/*
*   VcCode - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VcCode& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VcCode& p);


/*
*   Zone - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const Zone& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Zone& p);


/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const HighFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, HighFrequencyContainer& p);


/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const LowFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LowFrequencyContainer& p);


/*
*   BasicContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const BasicContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, BasicContainer& p);


/*
*   PublicTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const PublicTransportContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PublicTransportContainer& p);


/*
*   RoadWorksContainerBasic - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const RoadWorksContainerBasic& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadWorksContainerBasic& p);


/*
*   ManagementContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const ManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ManagementContainer& p);


/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const SituationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SituationContainer& p);


/*
*   RoadWorksContainerExtended - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const RoadWorksContainerExtended& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadWorksContainerExtended& p);


/*
*   AlacarteContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const AlacarteContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AlacarteContainer& p);


/*
*   NonIslandLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const NonIslandLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NonIslandLanePosition& p);


/*
*   VruExteriorLights - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruExteriorLights& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruExteriorLights& p);


/*
*   VruClusterOperationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterOperationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruClusterOperationContainer& p);


/*
*   VruPathPoint - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruPathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruPathPoint& p);


/*
*   SequenceOfVruSafeDistanceIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruSafeDistanceIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfVruSafeDistanceIndication& p);


/*
*   SequenceOfTrajectoryInterceptionIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfTrajectoryInterceptionIndication& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfTrajectoryInterceptionIndication& p);


/*
*   CpmManagementContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmManagementContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CpmManagementContainer& p);


/*
*   VehicleSensorPropertyList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensorPropertyList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensorPropertyList& p);


/*
*   TrailerDataContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const TrailerDataContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrailerDataContainer& p);


/*
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClassDescription& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClassDescription& p);


/*
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass::ObjectClass__class& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass::ObjectClass__class& p);


/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OffsetPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OffsetPoint& p);


/*
*   ConnectionManeuverAssist-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionManeuverAssist_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionManeuverAssist_addGrpC& p);


/*
*   ConnectionTrajectory-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const ConnectionTrajectory_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectionTrajectory_addGrpC& p);


/*
*   MapData-addGrpC - Type SEQUENCE
*   From AddGrpC - File DSRC.asn
*/

Value to_json(const MapData_addGrpC& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapData_addGrpC& p);


/*
*   RTCMcorrections - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RTCMcorrections& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RTCMcorrections& p);


/*
*   ConnectsToList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const ConnectsToList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ConnectsToList& p);


/*
*   LaneAttributes - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneAttributes& p);


/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementList& p);


/*
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeListXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeListXY& p);


/*
*   RequestorDescription - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RequestorDescription& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RequestorDescription& p);


/*
*   SignalStatusPackageList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusPackageList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusPackageList& p);


/*
*   DDD-IO-LIST - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const DDD_IO_LIST& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DDD_IO_LIST& p);


/*
*   CreditRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const CreditRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CreditRq_t& p);


/*
*   DebitRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const DebitRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DebitRq_t& p);


/*
*   GetStampedRs - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const GetStampedRs_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GetStampedRs_t& p);


/*
*   SetStampedRq - Type SEQUENCE
*   From EfcDsrcApplication - File ISO14906-0-6.asn
*/

Value to_json(const SetStampedRq_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SetStampedRq_t& p);


/*
*   VarLengthNumber - Type CHOICE
*   From CITSapplMgmtIDs - File ISO17419.asn
*/

Value to_json(const VarLengthNumber& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VarLengthNumber& p);


/*
*   GlcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GlcPart& p);


/*
*   RoadSurfaceContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadSurfaceContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSurfaceContainer& p);


/*
*   LayoutContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LayoutContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LayoutContainer& p);


/*
*   MlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MlcParts& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MlcParts& p);


/*
*   AutomatedVehicleRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleRules& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleRules& p);


/*
*   PlatooningRules - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const PlatooningRules& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PlatooningRules& p);


/*
*   CompleteVehicleCharacteristics - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const CompleteVehicleCharacteristics& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CompleteVehicleCharacteristics& p);


/*
*   LaneInformation - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneInformation& p);


/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const SpecialVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpecialVehicleContainer& p);


/*
*   DecentralizedEnvironmentalNotificationMessage - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DecentralizedEnvironmentalNotificationMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DecentralizedEnvironmentalNotificationMessage& p);


/*
*   TrafficIslandPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrafficIslandPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrafficIslandPosition& p);


/*
*   VruLowFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLowFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruLowFrequencyContainer& p);


/*
*   SequenceOfVruPathPoint - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const SequenceOfVruPathPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SequenceOfVruPathPoint& p);


/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OriginatingVehicleContainer& p);


/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObject& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObject& p);


/*
*   VehicleSensor - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const VehicleSensor& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleSensor& p);


/*
*   AreaCircular - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaCircular& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaCircular& p);


/*
*   AreaEllipse - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaEllipse& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaEllipse& p);


/*
*   AreaRectangle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRectangle& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaRectangle& p);


/*
*   PolyPointList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PolyPointList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PolyPointList& p);


/*
*   AreaRadial - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaRadial& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaRadial& p);


/*
*   SignalRequestMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalRequestMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalRequestMessage& p);


/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const GenericLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GenericLane& p);


/*
*   IntersectionState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionState& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionState& p);


/*
*   IntersectionStateList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionStateList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionStateList& p);


/*
*   LaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const LaneList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneList& p);


/*
*   RoadLaneSetList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadLaneSetList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadLaneSetList& p);


/*
*   RoadSegment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegment& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegment& p);


/*
*   RoadSegmentList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegmentList& p);


/*
*   SignalStatus - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatus& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatus& p);


/*
*   SignalStatusList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusList& p);


/*
*   InternationalSign-destinationInformation - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const InternationalSign_destinationInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, InternationalSign_destinationInformation& p);


/*
*   GlcParts - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GlcParts& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GlcParts& p);


/*
*   MapLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const MapLocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapLocationContainer& p);


/*
*   LaneConfiguration - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const LaneConfiguration& p, Document::AllocatorType& allocator);

void from_json(const Value& j, LaneConfiguration& p);


/*
*   VehicleCharacteristicsList - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const VehicleCharacteristicsList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VehicleCharacteristicsList& p);


/*
*   ISO14823Attribute - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Attribute& p);


/*
*   CamParameters - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CamParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CamParameters& p);


/*
*   DENM - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

Value to_json(const DENM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DENM& p);


/*
*   VruLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruLanePosition& p);


/*
*   VruMotionPredictionContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruMotionPredictionContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruMotionPredictionContainer& p);


/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const StationDataContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StationDataContainer& p);


/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainer_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObjectContainer_t& p);


/*
*   AreaPolygon - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const AreaPolygon& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AreaPolygon& p);


/*
*   FreeSpaceArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceArea& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceArea& p);


/*
*   SREM - Type SEQUENCE
*   From SREM-PDU-Descriptions - File TS103301v211-SREM.asn
*/

Value to_json(const SREM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SREM& p);


/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SPAT& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPAT& p);


/*
*   SignalStatusMessage - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SignalStatusMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SignalStatusMessage& p);


/*
*   IntersectionGeometry - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometry& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionGeometry& p);


/*
*   IntersectionGeometryList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const IntersectionGeometryList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IntersectionGeometryList& p);


/*
*   GddAttribute - Type CHOICE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttribute& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddAttribute& p);


/*
*   GeographicLocationContainer - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeographicLocationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GeographicLocationContainer& p);


/*
*   GicPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GicPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GicPart& p);


/*
*   RccPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RccPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RccPart& p);


/*
*   TcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TcPart& p);


/*
*   AvcPart - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AvcPart& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AvcPart& p);


/*
*   ISO14823Attributes - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Attributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Attributes& p);


/*
*   AnyCatalogue - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AnyCatalogue& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AnyCatalogue& p);


/*
*   ISO14823Code - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const ISO14823Code& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ISO14823Code& p);


/*
*   RSCode::RSCode__code - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RSCode::RSCode__code& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RSCode::RSCode__code& p);


/*
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CoopAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CoopAwareness& p);


/*
*   VruHighFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruHighFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruHighFrequencyContainer& p);


/*
*   ClusterBoundingBoxShape - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBoundingBoxShape& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterBoundingBoxShape& p);


/*
*   DetectionArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const DetectionArea& p, Document::AllocatorType& allocator);

void from_json(const Value& j, DetectionArea& p);


/*
*   FreeSpaceAddendum - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendum& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceAddendum& p);


/*
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

Value to_json(const SPATEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPATEM& p);


/*
*   SSEM - Type SEQUENCE
*   From SSEM-PDU-Descriptions - File TS103301v211-SSEM.asn
*/

Value to_json(const SSEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SSEM& p);


/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MapData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapData_t& p);


/*
*   GddAttributes - Type SEQUENCE OF
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddAttributes& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddAttributes& p);


/*
*   GeneralIviContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const GeneralIviContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GeneralIviContainer& p);


/*
*   RoadConfigurationContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const RoadConfigurationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadConfigurationContainer& p);


/*
*   TextContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const TextContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TextContainer& p);


/*
*   AutomatedVehicleContainer - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const AutomatedVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, AutomatedVehicleContainer& p);


/*
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CAM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CAM& p);


/*
*   VruClusterInformationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruClusterInformationContainer& p);


/*
*   SensorInformation - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformation& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorInformation& p);


/*
*   FreeSpaceAddendumContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const FreeSpaceAddendumContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, FreeSpaceAddendumContainer& p);


/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

Value to_json(const MAPEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MAPEM& p);


/*
*   GddStructure - Type SEQUENCE
*   From GDD - File ISO14823.asn
*/

Value to_json(const GddStructure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GddStructure& p);


/*
*   IviContainer - Type CHOICE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviContainer& p);


/*
*   VamParameters - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VamParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VamParameters& p);


/*
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorInformationContainer& p);


/*
*   IviContainers - Type SEQUENCE OF
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviContainers& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviContainers& p);


/*
*   VruAwareness - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruAwareness& p);


/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CpmParameters& p);


/*
*   IviStructure - Type SEQUENCE
*   From IVI - File ISO19321IVIv2.asn
*/

Value to_json(const IviStructure& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IviStructure& p);


/*
*   VAM - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VAM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VAM& p);


/*
*   CollectivePerceptionMessage - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CollectivePerceptionMessage& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CollectivePerceptionMessage& p);


/*
*   IVIM - Type SEQUENCE
*   From IVIM-PDU-Descriptions - File TS103301v211-IVIM.asn
*/

Value to_json(const IVIM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, IVIM& p);


/*
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CPM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CPM& p);


#endif
