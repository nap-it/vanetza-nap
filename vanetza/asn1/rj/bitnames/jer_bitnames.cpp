// jer_bitnames.cpp - Bit names lookup for BIT STRING types
// This maps type names to their named bits for human-readable JSON output
//
// HOW TO ADD A NEW BITSTRING TYPE:
// 1. Add a BITNAMES(...) entry to the list below
// 2. Format: BITNAMES(TypeName, "bit0name", "bit1name", "bit2name", ...)
// 3. Bits are numbered 0, 1, 2, ... in order listed
// 4. Rebuild - no gperf regeneration needed
//
#include "jer_bitnames.hpp"
#include <cstring>

namespace vanetza {
namespace asn1 {
namespace rj {

// Macro to simplify bitname definitions - bits are sequential starting from 0
#define BITNAMES(type, ...) \
    static const char* const names_##type[] = { __VA_ARGS__ }; \
    static constexpr uint8_t count_##type = sizeof(names_##type) / sizeof(names_##type[0])

// ============================================================================
// BIT STRING TYPE DEFINITIONS
// Add new types here - format: BITNAMES(TypeName, "bit0", "bit1", "bit2", ...)
// ============================================================================

BITNAMES(AccelerationControl,
    "brakePedalEngaged", "gasPedalEngaged", "emergencyBrakeEngaged",
    "collisionWarningEngaged", "accEngaged", "cruiseControlEngaged", "speedLimiterEngaged");

BITNAMES(ExteriorLights,
    "lowBeamHeadlightsOn", "highBeamHeadlightsOn", "leftTurnSignalOn", "rightTurnSignalOn",
    "daytimeRunningLightsOn", "reverseLightOn", "fogLightOn", "parkingLightsOn");

BITNAMES(LightBarSirenInUse, "lightBarActivated", "sirenActivated");

BITNAMES(EmergencyPriority, "requestForRightOfWay", "requestForFreeCrossingAtATrafficLight");

BITNAMES(EnergyStorageType,
    "hydrogenStorage", "electricEnergyStorage", "liquidPropaneGas",
    "compressedNaturalGas", "diesel", "gasoline", "ammonia");

BITNAMES(SpecialTransportType, "heavyLoad", "excessWidth", "excessLength", "excessHeight");

BITNAMES(DayOfWeek,
    "unused", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday");

BITNAMES(GNSSstatus,
    "unavailable", "isHealthy", "isMonitored", "baseStationType",
    "aPDOPofUnder5", "inViewOfUnder5", "localCorrectionsPresent", "networkCorrectionsPresent");

BITNAMES(LaneDirection, "ingressPath", "egressPath");

BITNAMES(TransitVehicleStatus, "loading", "anADAuse", "aBikeLoad", "doorOpen", "charging", "atStopLine");

BITNAMES(AllowedManeuvers,
    "maneuverStraightAllowed", "maneuverLeftAllowed", "maneuverRightAllowed",
    "maneuverUTurnAllowed", "maneuverLeftTurnOnRedAllowed", "maneuverRightTurnOnRedAllowed",
    "maneuverLaneChangeAllowed", "maneuverNoStoppingAllowed", "yieldAllwaysRequired",
    "goWithHalt", "caution", "reserved1");

BITNAMES(IntersectionStatusObject,
    "manualControlIsEnabled", "stopTimeIsActivated", "failureFlash", "preemptIsActive",
    "signalPriorityIsActive", "fixedTimeOperation", "trafficDependentOperation",
    "standbyOperation", "failureMode", "off", "recentMAPmessageUpdate",
    "recentChangeInMAPassignedLanesIDsUsed", "noValidMAPisAvailableAtThisTime",
    "noValidSPATisAvailableAtThisTime");

BITNAMES(LaneSharing,
    "overlappingLaneDescriptionProvided", "multipleLanesTreatedAsOneLane",
    "otherNonMotorizedTrafficTypes", "individualMotorizedVehicleTraffic",
    "busVehicleTraffic", "taxiVehicleTraffic", "pedestriansTraffic",
    "cyclistVehicleTraffic", "trackedVehicleTraffic", "pedestrianTraffic");

BITNAMES(PositionOfOccupants,
    "row1LeftOccupied", "row1RightOccupied", "row1MidOccupied", "row1NotDetectable", "row1NotPresent",
    "row2LeftOccupied", "row2RightOccupied", "row2MidOccupied", "row2NotDetectable", "row2NotPresent",
    "row3LeftOccupied", "row3RightOccupied", "row3MidOccupied", "row3NotDetectable", "row3NotPresent",
    "row4LeftOccupied", "row4RightOccupied", "row4MidOccupied", "row4NotDetectable", "row4NotPresent");

BITNAMES(VruClusterProfiles, "pedestrian", "bicyclist", "motorcyclist", "animal");

BITNAMES(VruSpecificExteriorLights,
    "unavailable", "backFlashLight", "helmetLight", "armLight", "legLight", "wheelLight");

BITNAMES(MatrixIncludedComponents,
    "xPosition", "yPosition", "zPosition",
    "xVelocityOrVelocityMagnitude", "yVelocityOrVelocityDirection", "zSpeed",
    "xAccelOrAccelMagnitude", "yAccelOrAccelDirection", "zAcceleration",
    "zAngle", "yAngle", "xAngle", "zAngularVelocity");

BITNAMES(SensorTypes,
    "undefined", "radar", "lidar", "monovideo", "stereovision", "nightvision",
    "ultrasonic", "pmd", "inductionLoop", "sphericalCamera", "uwb", "acoustic",
    "localAggregation", "itsAggregation");

BITNAMES(StoredInformationType,
    "undefined", "staticDb", "dynamicDb", "realTimeDb", "map");

// MAPEM/SPATEM Lane Attributes (R1 only)
BITNAMES(GeoGraphicalLimit,
    "globalRestriction", "regionalRestriction", "nationalRestriction", "district",
    "issuerCoverageRestriction", "reservedForCEN1", "reservedForCEN2", "issuerSpecificRestriction");

BITNAMES(RepeatingPeriodDayTypes,
    "national_holiday", "even_days", "odd_days", "market_day");

// Note: LaneAttributes types use hyphenated names in ASN.1, stored without hyphen for lookup
BITNAMES(LaneAttributes_Vehicle,
    "isVehicleRevocableLane", "isVehicleFlyOverLane", "hovLaneUseOnly", "restrictedToBusUse",
    "restrictedToTaxiUse", "restrictedFromPublicUse", "hasIRbeaconCoverage", "permissionOnRequest");

BITNAMES(LaneAttributes_Sidewalk,
    "sidewalk_RevocableLane", "bicyleUseAllowed", "isSidewalkFlyOverLane", "walkBikes");

BITNAMES(LaneAttributes_Striping,
    "stripeToConnectingLanesRevocableLane", "stripeDrawOnLeft", "stripeDrawOnRight",
    "stripeToConnectingLanesLeft", "stripeToConnectingLanesRight", "stripeToConnectingLanesAhead");

BITNAMES(LaneAttributes_TrackedVehicle,
    "spec_RevocableLane", "spec_commuterRailRoadTrack", "spec_lightRailRoadTrack",
    "spec_heavyRailRoadTrack", "spec_otherRailType");

BITNAMES(LaneAttributes_Bike,
    "bikeRevocableLane", "pedestrianUseAllowed", "isBikeFlyOverLane", "fixedCycleTime",
    "biDirectionalCycleTimes", "isolatedByBarrier", "unsignalizedSegmentsPresent");

BITNAMES(LaneAttributes_Crosswalk,
    "crosswalkRevocableLane", "bicyleUseAllowed", "isXwalkFlyOverLane", "fixedCycleTime",
    "biDirectionalCycleTimes", "hasPushToWalkButton", "audioSupport", "rfSignalRequestPresent",
    "unsignalizedSegmentsPresent");

BITNAMES(LaneAttributes_Parking,
    "parkingRevocableLane", "parallelParkingInUse", "headInParkingInUse", "doNotParkZone",
    "parkingForBusUse", "parkingForTaxiUse", "noPublicParkingUse");

BITNAMES(LaneAttributes_Barrier,
    "median_RevocableLane", "median", "whiteLineHashing", "stripedLines", "doubleStripedLines",
    "trafficCones", "constructionBarrier", "trafficChannels", "lowCurbs", "highCurbs");

// ============================================================================
// LOOKUP TABLE - Add entry for each BITNAMES above
// Format: ENTRY(TypeName)
// ============================================================================

#define ENTRY(type) { #type, names_##type, count_##type }
#define ENTRY_HYPHEN(name_with_hyphen, type_with_underscore) { name_with_hyphen, names_##type_with_underscore, count_##type_with_underscore }

static const jer_bitnames_entry bitnames_table[] = {
    ENTRY(AccelerationControl),
    ENTRY(AllowedManeuvers),
    ENTRY(DayOfWeek),
    ENTRY(EmergencyPriority),
    ENTRY(EnergyStorageType),
    ENTRY(ExteriorLights),
    ENTRY(GeoGraphicalLimit),
    ENTRY(GNSSstatus),
    ENTRY(IntersectionStatusObject),
    // LaneAttributes types with both underscore and hyphen versions
    ENTRY(LaneAttributes_Barrier),
    ENTRY_HYPHEN("LaneAttributes-Barrier", LaneAttributes_Barrier),
    ENTRY(LaneAttributes_Bike),
    ENTRY_HYPHEN("LaneAttributes-Bike", LaneAttributes_Bike),
    ENTRY(LaneAttributes_Crosswalk),
    ENTRY_HYPHEN("LaneAttributes-Crosswalk", LaneAttributes_Crosswalk),
    ENTRY(LaneAttributes_Parking),
    ENTRY_HYPHEN("LaneAttributes-Parking", LaneAttributes_Parking),
    ENTRY(LaneAttributes_Sidewalk),
    ENTRY_HYPHEN("LaneAttributes-Sidewalk", LaneAttributes_Sidewalk),
    ENTRY(LaneAttributes_Striping),
    ENTRY_HYPHEN("LaneAttributes-Striping", LaneAttributes_Striping),
    ENTRY(LaneAttributes_TrackedVehicle),
    ENTRY_HYPHEN("LaneAttributes-TrackedVehicle", LaneAttributes_TrackedVehicle),
    ENTRY(LaneAttributes_Vehicle),
    ENTRY_HYPHEN("LaneAttributes-Vehicle", LaneAttributes_Vehicle),
    ENTRY(LaneDirection),
    ENTRY(LaneSharing),
    ENTRY(LightBarSirenInUse),
    ENTRY(MatrixIncludedComponents),
    ENTRY(PositionOfOccupants),
    ENTRY(RepeatingPeriodDayTypes),
    ENTRY(SensorTypes),
    ENTRY(SpecialTransportType),
    ENTRY(StoredInformationType),
    ENTRY(TransitVehicleStatus),
    ENTRY(VruClusterProfiles),
    ENTRY(VruSpecificExteriorLights),
};

#undef ENTRY
#undef BITNAMES

static constexpr size_t bitnames_table_size = sizeof(bitnames_table) / sizeof(bitnames_table[0]);

const jer_bitnames_entry* jer_find_bitnames(const char* type_name) {
    for (size_t i = 0; i < bitnames_table_size; ++i) {
        if (std::strcmp(type_name, bitnames_table[i].type_name) == 0) {
            return &bitnames_table[i];
        }
    }
    return nullptr;  // Not found - caller should fall back to hex encoding
}

} // namespace rj
} // namespace asn1
} // namespace vanetza
