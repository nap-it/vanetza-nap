/*
*   JSON marshalling and unmarshalling functions for use by nlohmann::json
*   Auto-generated from the asn1 directory by asn1json.py on 2022-04-16 00:51:04.352719
*/

#ifndef ASN1_JSON_HPP
#define ASN1_JSON_HPP

#include <nlohmann/json.hpp>
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

using json = nlohmann::json;

void to_json(json& j, const TimestampIts_t& p);
void from_json(const json& j, TimestampIts_t& p);


/*
*   ItsPduHeader - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ItsPduHeader_t& p);

void from_json(const json& j, ItsPduHeader_t& p);


/*
*   DeltaReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DeltaReferencePosition_t& p);

void from_json(const json& j, DeltaReferencePosition_t& p);


/*
*   Altitude - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Altitude& p);

void from_json(const json& j, Altitude& p);


/*
*   PosConfidenceEllipse - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PosConfidenceEllipse& p);

void from_json(const json& j, PosConfidenceEllipse& p);


/*
*   PathPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PathPoint& p);

void from_json(const json& j, PathPoint& p);


/*
*   PtActivationData - Type OCTET STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PtActivationData_t& p);

void from_json(const json& j, PtActivationData_t& p);


/*
*   AccelerationControl - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_AccelerationControl(const AccelerationControl_t p);

void from_json_AccelerationControl(const json& j, AccelerationControl_t& p);


/*
*   CauseCode - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const CauseCode& p);

void from_json(const json& j, CauseCode& p);


/*
*   Curvature - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Curvature& p);

void from_json(const json& j, Curvature& p);


/*
*   Heading - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Heading& p);

void from_json(const json& j, Heading& p);


/*
*   DrivingLaneStatus - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_DrivingLaneStatus(const DrivingLaneStatus_t p);

void from_json_DrivingLaneStatus(const json& j, DrivingLaneStatus_t& p);


/*
*   Speed - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Speed& p);

void from_json(const json& j, Speed& p);


/*
*   LongitudinalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const LongitudinalAcceleration& p);

void from_json(const json& j, LongitudinalAcceleration& p);


/*
*   LateralAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const LateralAcceleration& p);

void from_json(const json& j, LateralAcceleration& p);


/*
*   VerticalAcceleration - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VerticalAcceleration_t& p);

void from_json(const json& j, VerticalAcceleration_t& p);


/*
*   ExteriorLights - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_ExteriorLights(const ExteriorLights_t p);

void from_json_ExteriorLights(const json& j, ExteriorLights_t& p);


/*
*   DangerousGoodsExtended - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DangerousGoodsExtended& p);

void from_json(const json& j, DangerousGoodsExtended& p);


/*
*   SpecialTransportType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_SpecialTransportType(const SpecialTransportType_t p);

void from_json_SpecialTransportType(const json& j, SpecialTransportType_t& p);


/*
*   LightBarSirenInUse - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_LightBarSirenInUse(const LightBarSirenInUse_t p);

void from_json_LightBarSirenInUse(const json& j, LightBarSirenInUse_t& p);


/*
*   PositionOfOccupants - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_PositionOfOccupants(const PositionOfOccupants_t p);

void from_json_PositionOfOccupants(const json& j, PositionOfOccupants_t& p);


/*
*   VehicleIdentification - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleIdentification& p);

void from_json(const json& j, VehicleIdentification& p);


/*
*   EnergyStorageType - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_EnergyStorageType(const EnergyStorageType_t p);

void from_json_EnergyStorageType(const json& j, EnergyStorageType_t& p);


/*
*   VehicleLength - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const VehicleLength_t& p);

void from_json(const json& j, VehicleLength_t& p);


/*
*   PathHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PathHistory& p);

void from_json(const json& j, PathHistory& p);


/*
*   EmergencyPriority - Type BIT STRING
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

json to_json_EmergencyPriority(const EmergencyPriority_t p);

void from_json_EmergencyPriority(const json& j, EmergencyPriority_t& p);


/*
*   SteeringWheelAngle - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const SteeringWheelAngle& p);

void from_json(const json& j, SteeringWheelAngle& p);


/*
*   YawRate - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const YawRate& p);

void from_json(const json& j, YawRate& p);


/*
*   ActionID - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ActionID& p);

void from_json(const json& j, ActionID& p);


/*
*   ProtectedCommunicationZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ProtectedCommunicationZone& p);

void from_json(const json& j, ProtectedCommunicationZone& p);


/*
*   Traces - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const Traces& p);

void from_json(const json& j, Traces& p);


/*
*   PositionOfPillars - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PositionOfPillars& p);

void from_json(const json& j, PositionOfPillars& p);


/*
*   RestrictedTypes - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const RestrictedTypes& p);

void from_json(const json& j, RestrictedTypes& p);


/*
*   EventPoint - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const EventPoint& p);

void from_json(const json& j, EventPoint& p);


/*
*   ProtectedCommunicationZonesRSU - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ProtectedCommunicationZonesRSU& p);

void from_json(const json& j, ProtectedCommunicationZonesRSU& p);


/*
*   CenDsrcTollingZone - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const CenDsrcTollingZone& p);

void from_json(const json& j, CenDsrcTollingZone& p);


/*
*   BasicVehicleContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicVehicleContainerHighFrequency& p);

void from_json(const json& j, BasicVehicleContainerHighFrequency& p);


/*
*   BasicVehicleContainerLowFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicVehicleContainerLowFrequency& p);

void from_json(const json& j, BasicVehicleContainerLowFrequency& p);


/*
*   SpecialTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SpecialTransportContainer& p);

void from_json(const json& j, SpecialTransportContainer& p);


/*
*   DangerousGoodsContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const DangerousGoodsContainer& p);

void from_json(const json& j, DangerousGoodsContainer& p);


/*
*   RescueContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RescueContainer& p);

void from_json(const json& j, RescueContainer& p);


/*
*   EmergencyContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const EmergencyContainer& p);

void from_json(const json& j, EmergencyContainer& p);


/*
*   SafetyCarContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SafetyCarContainer& p);

void from_json(const json& j, SafetyCarContainer& p);


/*
*   RSUContainerHighFrequency - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RSUContainerHighFrequency& p);

void from_json(const json& j, RSUContainerHighFrequency& p);


/*
*   LocationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const LocationContainer& p);

void from_json(const json& j, LocationContainer& p);


/*
*   ImpactReductionContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ImpactReductionContainer& p);

void from_json(const json& j, ImpactReductionContainer& p);


/*
*   StationaryVehicleContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const StationaryVehicleContainer& p);

void from_json(const json& j, StationaryVehicleContainer& p);


/*
*   ReferenceDenms - Type SEQUENCE OF
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ReferenceDenms& p);

void from_json(const json& j, ReferenceDenms& p);


/*
*   VruProfileAndSubprofile - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruProfileAndSubprofile& p);

void from_json(const json& j, VruProfileAndSubprofile& p);


/*
*   VruSpecificExteriorLights - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

json to_json_VruSpecificExteriorLights(const VruSpecificExteriorLights_t p);

void from_json_VruSpecificExteriorLights(const json& j, VruSpecificExteriorLights_t& p);


/*
*   ClusterProfiles - Type BIT STRING
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

json to_json_ClusterProfiles(const ClusterProfiles_t p);

void from_json_ClusterProfiles(const json& j, ClusterProfiles_t& p);


/*
*   ClusterJoinInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const ClusterJoinInfo& p);

void from_json(const json& j, ClusterJoinInfo& p);


/*
*   ClusterLeaveInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const ClusterLeaveInfo& p);

void from_json(const json& j, ClusterLeaveInfo& p);


/*
*   ClusterBreakupInfo - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const ClusterBreakupInfo& p);

void from_json(const json& j, ClusterBreakupInfo& p);


/*
*   VruSafeDistanceIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruSafeDistanceIndication& p);

void from_json(const json& j, VruSafeDistanceIndication& p);


/*
*   TrajectoryInterceptionIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const TrajectoryInterceptionIndication& p);

void from_json(const json& j, TrajectoryInterceptionIndication& p);


/*
*   HeadingChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const HeadingChangeIndication& p);

void from_json(const json& j, HeadingChangeIndication& p);


/*
*   AccelerationChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const AccelerationChangeIndication& p);

void from_json(const json& j, AccelerationChangeIndication& p);


/*
*   StabilityChangeIndication - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const StabilityChangeIndication& p);

void from_json(const json& j, StabilityChangeIndication& p);


/*
*   AdvisorySpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const AdvisorySpeed& p);

void from_json(const json& j, AdvisorySpeed& p);


/*
*   AdvisorySpeedList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const AdvisorySpeedList_t& p);

void from_json(const json& j, AdvisorySpeedList_t& p);


/*
*   ComputedLane::ComputedLane__offsetXaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane::ComputedLane__offsetXaxis& p);

void from_json(const json& j, ComputedLane::ComputedLane__offsetXaxis& p);


/*
*   ComputedLane::ComputedLane__offsetYaxis - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane::ComputedLane__offsetYaxis& p);

void from_json(const json& j, ComputedLane::ComputedLane__offsetYaxis& p);


/*
*   ComputedLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ComputedLane_t& p);

void from_json(const json& j, ComputedLane_t& p);


/*
*   ConnectionManeuverAssist - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectionManeuverAssist_t& p);

void from_json(const json& j, ConnectionManeuverAssist_t& p);


/*
*   DataParameters - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const DataParameters_t& p);

void from_json(const json& j, DataParameters_t& p);


/*
*   EnabledLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const EnabledLaneList_t& p);

void from_json(const json& j, EnabledLaneList_t& p);


/*
*   IntersectionAccessPoint - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionAccessPoint_t& p);

void from_json(const json& j, IntersectionAccessPoint_t& p);


/*
*   IntersectionReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionReferenceID& p);

void from_json(const json& j, IntersectionReferenceID& p);


/*
*   LaneSharing - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneSharing(const LaneSharing_t p);

void from_json_LaneSharing(const json& j, LaneSharing_t& p);


/*
*   ManeuverAssistList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ManeuverAssistList& p);

void from_json(const json& j, ManeuverAssistList& p);


/*
*   Node-LLmD-64b - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Node_LLmD_64b& p);

void from_json(const json& j, Node_LLmD_64b& p);


/*
*   OverlayLaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const OverlayLaneList& p);

void from_json(const json& j, OverlayLaneList& p);


/*
*   Position3D - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Position3D_t& p);

void from_json(const json& j, Position3D_t& p);


/*
*   RestrictionUserType - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionUserType& p);

void from_json(const json& j, RestrictionUserType& p);


/*
*   RoadSegmentReferenceID - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegmentReferenceID& p);

void from_json(const json& j, RoadSegmentReferenceID& p);


/*
*   TimeChangeDetails - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const TimeChangeDetails& p);

void from_json(const json& j, TimeChangeDetails& p);


/*
*   TransmissionAndSpeed - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const TransmissionAndSpeed_t& p);

void from_json(const json& j, TransmissionAndSpeed_t& p);


/*
*   VehicleID - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const VehicleID_t& p);

void from_json(const json& j, VehicleID_t& p);


/*
*   AllowedManeuvers - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_AllowedManeuvers(const AllowedManeuvers_t p);

void from_json_AllowedManeuvers(const json& j, AllowedManeuvers_t& p);


/*
*   IntersectionStatusObject - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_IntersectionStatusObject(const IntersectionStatusObject_t p);

void from_json_IntersectionStatusObject(const json& j, IntersectionStatusObject_t& p);


/*
*   LaneAttributes-Barrier - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Barrier(const LaneAttributes_Barrier_t p);

void from_json_LaneAttributes_Barrier(const json& j, LaneAttributes_Barrier_t& p);


/*
*   LaneAttributes-Bike - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Bike(const LaneAttributes_Bike_t p);

void from_json_LaneAttributes_Bike(const json& j, LaneAttributes_Bike_t& p);


/*
*   LaneAttributes-Crosswalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Crosswalk(const LaneAttributes_Crosswalk_t p);

void from_json_LaneAttributes_Crosswalk(const json& j, LaneAttributes_Crosswalk_t& p);


/*
*   LaneAttributes-Parking - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Parking(const LaneAttributes_Parking_t p);

void from_json_LaneAttributes_Parking(const json& j, LaneAttributes_Parking_t& p);


/*
*   LaneAttributes-Sidewalk - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Sidewalk(const LaneAttributes_Sidewalk_t p);

void from_json_LaneAttributes_Sidewalk(const json& j, LaneAttributes_Sidewalk_t& p);


/*
*   LaneAttributes-Striping - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Striping(const LaneAttributes_Striping_t p);

void from_json_LaneAttributes_Striping(const json& j, LaneAttributes_Striping_t& p);


/*
*   LaneAttributes-TrackedVehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_TrackedVehicle(const LaneAttributes_TrackedVehicle_t p);

void from_json_LaneAttributes_TrackedVehicle(const json& j, LaneAttributes_TrackedVehicle_t& p);


/*
*   LaneAttributes-Vehicle - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneAttributes_Vehicle(const LaneAttributes_Vehicle_t p);

void from_json_LaneAttributes_Vehicle(const json& j, LaneAttributes_Vehicle_t& p);


/*
*   LaneDirection - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_LaneDirection(const LaneDirection_t p);

void from_json_LaneDirection(const json& j, LaneDirection_t& p);


/*
*   TransitVehicleStatus - Type BIT STRING
*   From DSRC - File DSRC.asn
*/

json to_json_TransitVehicleStatus(const TransitVehicleStatus_t p);

void from_json_TransitVehicleStatus(const json& j, TransitVehicleStatus_t& p);


/*
*   Node-XY-20b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_20b& p);

void from_json(const json& j, Node_XY_20b& p);


/*
*   Node-XY-22b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_22b& p);

void from_json(const json& j, Node_XY_22b& p);


/*
*   Node-XY-24b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_24b& p);

void from_json(const json& j, Node_XY_24b& p);


/*
*   Node-XY-26b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_26b& p);

void from_json(const json& j, Node_XY_26b& p);


/*
*   Node-XY-28b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_28b& p);

void from_json(const json& j, Node_XY_28b& p);


/*
*   Node-XY-32b - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const Node_XY_32b& p);

void from_json(const json& j, Node_XY_32b& p);


/*
*   NodeAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeAttributeXYList& p);

void from_json(const json& j, NodeAttributeXYList& p);


/*
*   RegulatorySpeedLimit - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const RegulatorySpeedLimit& p);

void from_json(const json& j, RegulatorySpeedLimit& p);


/*
*   SegmentAttributeXYList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const SegmentAttributeXYList& p);

void from_json(const json& j, SegmentAttributeXYList& p);


/*
*   SpeedLimitList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const SpeedLimitList& p);

void from_json(const json& j, SpeedLimitList& p);


/*
*   OriginatingRSUContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OriginatingRSUContainer& p);

void from_json(const json& j, OriginatingRSUContainer& p);


/*
*   VehicleSensorProperties - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensorProperties& p);

void from_json(const json& j, VehicleSensorProperties& p);


/*
*   ObjectDistanceWithConfidence - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectDistanceWithConfidence& p);

void from_json(const json& j, ObjectDistanceWithConfidence& p);


/*
*   ObjectDimension - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectDimension& p);

void from_json(const json& j, ObjectDimension& p);


/*
*   CartesianAngle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CartesianAngle& p);

void from_json(const json& j, CartesianAngle& p);


/*
*   WGS84Angle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const WGS84Angle& p);

void from_json(const json& j, WGS84Angle& p);


/*
*   SpeedExtended - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SpeedExtended& p);

void from_json(const json& j, SpeedExtended& p);


/*
*   SensorIdList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorIdList& p);

void from_json(const json& j, SensorIdList& p);


/*
*   TrailerData - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const TrailerData& p);

void from_json(const json& j, TrailerData& p);


/*
*   LongitudinalLanePosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const LongitudinalLanePosition& p);

void from_json(const json& j, LongitudinalLanePosition& p);


/*
*   MatchedPosition - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const MatchedPosition& p);

void from_json(const json& j, MatchedPosition& p);


/*
*   PerceivedObjectContainerSegmentInfo - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObjectContainerSegmentInfo& p);

void from_json(const json& j, PerceivedObjectContainerSegmentInfo& p);


/*
*   VehicleSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSubclass& p);

void from_json(const json& j, VehicleSubclass& p);


/*
*   PersonSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PersonSubclass& p);

void from_json(const json& j, PersonSubclass& p);


/*
*   AnimalSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AnimalSubclass& p);

void from_json(const json& j, AnimalSubclass& p);


/*
*   OtherSubclass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OtherSubclass& p);

void from_json(const json& j, OtherSubclass& p);


/*
*   NodeOffsetPointZ - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const NodeOffsetPointZ& p);

void from_json(const json& j, NodeOffsetPointZ& p);


/*
*   ReferencePosition - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ReferencePosition& p);

void from_json(const json& j, ReferencePosition& p);


/*
*   PtActivation - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const PtActivation& p);

void from_json(const json& j, PtActivation& p);


/*
*   ClosedLanes - Type SEQUENCE
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ClosedLanes& p);

void from_json(const json& j, ClosedLanes& p);


/*
*   ItineraryPath - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const ItineraryPath& p);

void from_json(const json& j, ItineraryPath& p);


/*
*   EventHistory - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const EventHistory& p);

void from_json(const json& j, EventHistory& p);


/*
*   DigitalMap - Type SEQUENCE OF
*   From ITS-Container - File TS102894-2v131-CDD.asn
*/

void to_json(json& j, const DigitalMap_t& p);

void from_json(const json& j, DigitalMap_t& p);


/*
*   HighFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const HighFrequencyContainer& p);

void from_json(const json& j, HighFrequencyContainer& p);


/*
*   LowFrequencyContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const LowFrequencyContainer& p);

void from_json(const json& j, LowFrequencyContainer& p);


/*
*   BasicContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const BasicContainer& p);

void from_json(const json& j, BasicContainer& p);


/*
*   PublicTransportContainer - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const PublicTransportContainer& p);

void from_json(const json& j, PublicTransportContainer& p);


/*
*   RoadWorksContainerBasic - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const RoadWorksContainerBasic& p);

void from_json(const json& j, RoadWorksContainerBasic& p);


/*
*   ManagementContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const ManagementContainer& p);

void from_json(const json& j, ManagementContainer& p);


/*
*   SituationContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const SituationContainer& p);

void from_json(const json& j, SituationContainer& p);


/*
*   RoadWorksContainerExtended - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const RoadWorksContainerExtended& p);

void from_json(const json& j, RoadWorksContainerExtended& p);


/*
*   AlacarteContainer - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const AlacarteContainer& p);

void from_json(const json& j, AlacarteContainer& p);


/*
*   MapPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const MapPosition& p);

void from_json(const json& j, MapPosition& p);


/*
*   VruExteriorLights - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruExteriorLights& p);

void from_json(const json& j, VruExteriorLights& p);


/*
*   VruClusterOperationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruClusterOperationContainer& p);

void from_json(const json& j, VruClusterOperationContainer& p);


/*
*   VruPathPoint - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruPathPoint& p);

void from_json(const json& j, VruPathPoint& p);


/*
*   SequenceOfVruSafeDistanceIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const SequenceOfVruSafeDistanceIndication& p);

void from_json(const json& j, SequenceOfVruSafeDistanceIndication& p);


/*
*   SequenceOfTrajectoryInterceptionIndication - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const SequenceOfTrajectoryInterceptionIndication& p);

void from_json(const json& j, SequenceOfTrajectoryInterceptionIndication& p);


/*
*   ConnectingLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectingLane& p);

void from_json(const json& j, ConnectingLane& p);


/*
*   Connection - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const Connection& p);

void from_json(const json& j, Connection& p);


/*
*   LaneTypeAttributes - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneTypeAttributes& p);

void from_json(const json& j, LaneTypeAttributes& p);


/*
*   MovementEvent - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementEvent& p);

void from_json(const json& j, MovementEvent& p);


/*
*   RestrictionUserTypeList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionUserTypeList& p);

void from_json(const json& j, RestrictionUserTypeList& p);


/*
*   LaneDataAttribute - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const LaneDataAttribute& p);

void from_json(const json& j, LaneDataAttribute& p);


/*
*   LaneDataAttributeList - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const LaneDataAttributeList& p);

void from_json(const json& j, LaneDataAttributeList& p);


/*
*   NodeOffsetPointXY - Type CHOICE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeOffsetPointXY& p);

void from_json(const json& j, NodeOffsetPointXY& p);


/*
*   NodeAttributeSetXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeAttributeSetXY_t& p);

void from_json(const json& j, NodeAttributeSetXY_t& p);


/*
*   CpmManagementContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CpmManagementContainer& p);

void from_json(const json& j, CpmManagementContainer& p);


/*
*   VehicleSensorPropertyList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensorPropertyList& p);

void from_json(const json& j, VehicleSensorPropertyList& p);


/*
*   TrailerDataContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const TrailerDataContainer& p);

void from_json(const json& j, TrailerDataContainer& p);


/*
*   ObjectClass::ObjectClass__class - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClass::ObjectClass__class& p);

void from_json(const json& j, ObjectClass::ObjectClass__class& p);


/*
*   ObjectClass - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClass_t& p);

void from_json(const json& j, ObjectClass_t& p);


/*
*   OffsetPoint - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OffsetPoint& p);

void from_json(const json& j, OffsetPoint& p);


/*
*   SpecialVehicleContainer - Type CHOICE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const SpecialVehicleContainer& p);

void from_json(const json& j, SpecialVehicleContainer& p);


/*
*   DecentralizedEnvironmentalNotificationMessage - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const DecentralizedEnvironmentalNotificationMessage& p);

void from_json(const json& j, DecentralizedEnvironmentalNotificationMessage& p);


/*
*   NonIslandLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const NonIslandLanePosition& p);

void from_json(const json& j, NonIslandLanePosition& p);


/*
*   VruLowFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruLowFrequencyContainer& p);

void from_json(const json& j, VruLowFrequencyContainer& p);


/*
*   SequenceOfVruPathPoint - Type SEQUENCE OF
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const SequenceOfVruPathPoint& p);

void from_json(const json& j, SequenceOfVruPathPoint& p);


/*
*   ConnectsToList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const ConnectsToList& p);

void from_json(const json& j, ConnectsToList& p);


/*
*   LaneAttributes - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneAttributes& p);

void from_json(const json& j, LaneAttributes& p);


/*
*   MovementEventList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementEventList& p);

void from_json(const json& j, MovementEventList& p);


/*
*   MovementState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementState& p);

void from_json(const json& j, MovementState& p);


/*
*   RestrictionClassAssignment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionClassAssignment& p);

void from_json(const json& j, RestrictionClassAssignment& p);


/*
*   RestrictionClassList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RestrictionClassList& p);

void from_json(const json& j, RestrictionClassList& p);


/*
*   NodeXY - Type SEQUENCE
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeXY_t& p);

void from_json(const json& j, NodeXY_t& p);


/*
*   OriginatingVehicleContainer - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const OriginatingVehicleContainer& p);

void from_json(const json& j, OriginatingVehicleContainer& p);


/*
*   VehicleSensor - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const VehicleSensor& p);

void from_json(const json& j, VehicleSensor& p);


/*
*   AreaCircular - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaCircular& p);

void from_json(const json& j, AreaCircular& p);


/*
*   AreaEllipse - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaEllipse& p);

void from_json(const json& j, AreaEllipse& p);


/*
*   AreaRectangle - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaRectangle& p);

void from_json(const json& j, AreaRectangle& p);


/*
*   PolyPointList - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PolyPointList& p);

void from_json(const json& j, PolyPointList& p);


/*
*   AreaRadial - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaRadial& p);

void from_json(const json& j, AreaRadial& p);


/*
*   ObjectClassDescription - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const ObjectClassDescription& p);

void from_json(const json& j, ObjectClassDescription& p);


/*
*   CamParameters - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CamParameters& p);

void from_json(const json& j, CamParameters& p);


/*
*   DENM - Type SEQUENCE
*   From DENM-PDU-Descriptions - File EN302637-3v131-DENM.asn
*/

void to_json(json& j, const DENM& p);

void from_json(const json& j, DENM& p);


/*
*   TrafficIslandPosition - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const TrafficIslandPosition& p);

void from_json(const json& j, TrafficIslandPosition& p);


/*
*   VruMotionPredictionContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruMotionPredictionContainer& p);

void from_json(const json& j, VruMotionPredictionContainer& p);


/*
*   MovementList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MovementList& p);

void from_json(const json& j, MovementList& p);


/*
*   NodeSetXY - Type SEQUENCE OF
*   From DSRC-REGION-noCircular - File DSRC_REGION_noCircular.asn
*/

void to_json(json& j, const NodeSetXY& p);

void from_json(const json& j, NodeSetXY& p);


/*
*   StationDataContainer - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const StationDataContainer& p);

void from_json(const json& j, StationDataContainer& p);


/*
*   PerceivedObject - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObject& p);

void from_json(const json& j, PerceivedObject& p);


/*
*   AreaPolygon - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const AreaPolygon& p);

void from_json(const json& j, AreaPolygon& p);


/*
*   FreeSpaceArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceArea& p);

void from_json(const json& j, FreeSpaceArea& p);


/*
*   CoopAwareness - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CoopAwareness& p);

void from_json(const json& j, CoopAwareness& p);


/*
*   VruLanePosition - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruLanePosition& p);

void from_json(const json& j, VruLanePosition& p);


/*
*   ClusterBoundingBoxShape - Type CHOICE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const ClusterBoundingBoxShape& p);

void from_json(const json& j, ClusterBoundingBoxShape& p);


/*
*   IntersectionState - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionState& p);

void from_json(const json& j, IntersectionState& p);


/*
*   IntersectionStateList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionStateList& p);

void from_json(const json& j, IntersectionStateList& p);


/*
*   NodeListXY - Type CHOICE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const NodeListXY& p);

void from_json(const json& j, NodeListXY& p);


/*
*   PerceivedObjectContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const PerceivedObjectContainer_t& p);

void from_json(const json& j, PerceivedObjectContainer_t& p);


/*
*   DetectionArea - Type CHOICE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const DetectionArea& p);

void from_json(const json& j, DetectionArea& p);


/*
*   FreeSpaceAddendum - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceAddendum& p);

void from_json(const json& j, FreeSpaceAddendum& p);


/*
*   CAM - Type SEQUENCE
*   From CAM-PDU-Descriptions - File EN302637-2v141-CAM.asn
*/

void to_json(json& j, const CAM& p);

void from_json(const json& j, CAM& p);


/*
*   VruHighFrequencyContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruHighFrequencyContainer& p);

void from_json(const json& j, VruHighFrequencyContainer& p);


/*
*   VruClusterInformationContainer - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruClusterInformationContainer& p);

void from_json(const json& j, VruClusterInformationContainer& p);


/*
*   SPAT - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const SPAT& p);

void from_json(const json& j, SPAT& p);


/*
*   GenericLane - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const GenericLane& p);

void from_json(const json& j, GenericLane& p);


/*
*   LaneList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const LaneList& p);

void from_json(const json& j, LaneList& p);


/*
*   RoadLaneSetList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadLaneSetList& p);

void from_json(const json& j, RoadLaneSetList& p);


/*
*   RoadSegment - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegment& p);

void from_json(const json& j, RoadSegment& p);


/*
*   RoadSegmentList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const RoadSegmentList& p);

void from_json(const json& j, RoadSegmentList& p);


/*
*   SensorInformation - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorInformation& p);

void from_json(const json& j, SensorInformation& p);


/*
*   FreeSpaceAddendumContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const FreeSpaceAddendumContainer& p);

void from_json(const json& j, FreeSpaceAddendumContainer& p);


/*
*   SPATEM - Type SEQUENCE
*   From SPATEM-PDU-Descriptions - File TS103301v211-SPATEM.asn
*/

void to_json(json& j, const SPATEM& p);

void from_json(const json& j, SPATEM& p);


/*
*   VamParameters - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VamParameters& p);

void from_json(const json& j, VamParameters& p);


/*
*   IntersectionGeometry - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionGeometry& p);

void from_json(const json& j, IntersectionGeometry& p);


/*
*   IntersectionGeometryList - Type SEQUENCE OF
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const IntersectionGeometryList& p);

void from_json(const json& j, IntersectionGeometryList& p);


/*
*   SensorInformationContainer - Type SEQUENCE OF
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const SensorInformationContainer& p);

void from_json(const json& j, SensorInformationContainer& p);


/*
*   VruAwareness - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VruAwareness& p);

void from_json(const json& j, VruAwareness& p);


/*
*   MapData - Type SEQUENCE
*   From DSRC - File DSRC.asn
*/

void to_json(json& j, const MapData_t& p);

void from_json(const json& j, MapData_t& p);


/*
*   CpmParameters - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CpmParameters& p);

void from_json(const json& j, CpmParameters& p);


/*
*   MAPEM - Type SEQUENCE
*   From MAPEM-PDU-Descriptions - File TS103301v211-MAPEM.asn
*/

void to_json(json& j, const MAPEM& p);

void from_json(const json& j, MAPEM& p);


/*
*   VAM - Type SEQUENCE
*   From VAM-PDU-Descriptions - File TS103300-3v211-VAM.asn
*/

void to_json(json& j, const VAM& p);

void from_json(const json& j, VAM& p);


/*
*   CollectivePerceptionMessage - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CollectivePerceptionMessage& p);

void from_json(const json& j, CollectivePerceptionMessage& p);


/*
*   CPM - Type SEQUENCE
*   From CPM-PDU-Descriptions - File TR103562v211-CPM.asn
*/

void to_json(json& j, const CPM& p);

void from_json(const json& j, CPM& p);


#endif
