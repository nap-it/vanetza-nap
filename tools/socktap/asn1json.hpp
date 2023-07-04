/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2023-07-03 23:29:50.795055
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
*   PtActivationData - Type OCTET STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

Value to_json(const PtActivationData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PtActivationData_t& p);


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
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Node_LLmD_64b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_LLmD_64b& p);


/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const OverlayLaneList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OverlayLaneList& p);


/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const Position3D_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Position3D_t& p);


/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserType& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserType& p);


/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const RoadSegmentReferenceID& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RoadSegmentReferenceID& p);


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
*   Node-XY-20b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_20b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_20b& p);


/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_22b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_22b& p);


/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_24b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_24b& p);


/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_26b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_26b& p);


/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_28b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_28b& p);


/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const Node_XY_32b& p, Document::AllocatorType& allocator);

void from_json(const Value& j, Node_XY_32b& p);


/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeXYList& p);


/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const RegulatorySpeedLimit& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RegulatorySpeedLimit& p);


/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const SegmentAttributeXYList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SegmentAttributeXYList& p);


/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const SpeedLimitList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SpeedLimitList& p);


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
*   MapPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const MapPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapPosition& p);


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
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const RestrictionUserTypeList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, RestrictionUserTypeList& p);


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
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeOffsetPointXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeOffsetPointXY& p);


/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeAttributeSetXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeAttributeSetXY_t& p);


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
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass::ObjectClass__class& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass::ObjectClass__class& p);


/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClass_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClass_t& p);


/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OffsetPoint& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OffsetPoint& p);


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
*   NonIslandLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const NonIslandLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NonIslandLanePosition& p);


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
*   NodeXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeXY_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeXY_t& p);


/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const OriginatingVehicleContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, OriginatingVehicleContainer& p);


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
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const ObjectClassDescription& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ObjectClassDescription& p);


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
*   TrafficIslandPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const TrafficIslandPosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, TrafficIslandPosition& p);


/*
*   VruMotionPredictionContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruMotionPredictionContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruMotionPredictionContainer& p);


/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

Value to_json(const MovementList& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MovementList& p);


/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

Value to_json(const NodeSetXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeSetXY& p);


/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const StationDataContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, StationDataContainer& p);


/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObject& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObject& p);


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
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CoopAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CoopAwareness& p);


/*
*   VruLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruLanePosition& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruLanePosition& p);


/*
*   ClusterBoundingBoxShape - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const ClusterBoundingBoxShape& p, Document::AllocatorType& allocator);

void from_json(const Value& j, ClusterBoundingBoxShape& p);


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
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

Value to_json(const NodeListXY& p, Document::AllocatorType& allocator);

void from_json(const Value& j, NodeListXY& p);


/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const PerceivedObjectContainer_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, PerceivedObjectContainer_t& p);


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
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

Value to_json(const CAM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CAM& p);


/*
*   VruHighFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruHighFrequencyContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruHighFrequencyContainer& p);


/*
*   VruClusterInformationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruClusterInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruClusterInformationContainer& p);


/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const SPAT& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPAT& p);


/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const GenericLane& p, Document::AllocatorType& allocator);

void from_json(const Value& j, GenericLane& p);


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
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

Value to_json(const SPATEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SPATEM& p);


/*
*   VamParameters - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VamParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VamParameters& p);


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
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const SensorInformationContainer& p, Document::AllocatorType& allocator);

void from_json(const Value& j, SensorInformationContainer& p);


/*
*   VruAwareness - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

Value to_json(const VruAwareness& p, Document::AllocatorType& allocator);

void from_json(const Value& j, VruAwareness& p);


/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

Value to_json(const MapData_t& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MapData_t& p);


/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CpmParameters& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CpmParameters& p);


/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

Value to_json(const MAPEM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, MAPEM& p);


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
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

Value to_json(const CPM& p, Document::AllocatorType& allocator);

void from_json(const Value& j, CPM& p);


#endif
