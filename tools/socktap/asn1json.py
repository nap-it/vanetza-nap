# To run:
# python3 asn1json.py cpp > asn1json.cpp
# python3 asn1json.py hpp > asn1json.hpp

from email import header
import asn1tools
from datetime import datetime
import time, sys
from math import pow

######

base_dir = "../../asn1"
asn1_files = ["CDD-Release2.asn", "TS102894-2v131-CDD.asn", "DSRC.asn", "ISO14816.asn", "ISO14823.asn", "ISO14906-0-6.asn", "ISO14906-1-7.asn", "ISO17419.asn", 
              "ISO24534-3.asn", "ISO19321IVIv2.asn", "EN302637-2v141-CAM.asn", "EN302637-3v131-DENM.asn", "TS103300-3v211-VAM.asn", 
              "DSRC_REGION_noCircular.asn", "CPM-PDU-Descriptions.asn", "TS103301v211-MAPEM.asn", "TS103301v211-SPATEM.asn", 
              "TS103301v211-IVIM.asn", "TS103301v211-SREM.asn", "TS103301v211-SSEM.asn", "EVCSN-PDU-Descriptions.asn", 
              "EV-RSR-PDU-Descriptions.asn", "IMZM-PDU-Descriptions.asn", "TIS-TPG-Transactions-Descriptions.asn",
              "TS103301v211-RTCMEM.asn", "MCM-PDU-Descriptions.asn", "CAM-PDU-Descriptions.asn", "DENM-PDU-Descriptions.asn"]

default_types = ["INTEGER", "BOOLEAN", "ENUMERATED", "BIT STRING", "IA5String",
                 "SEQUENCE", "OCTET STRING", "SEQUENCE OF", "UTF8String", "NumericString", "CHOICE", "VisibleString"]

######

transformation = {
    "Latitude": (pow(10,7),[900000001]),
    "Longitude": (pow(10,7),[1800000001]),
    "CartesianCoordinateLarge": (pow(10,2),[]),
    "SteeringWheelAngleValue": ((2/3),[]),
    "AltitudeValue": (pow(10,2),[800001]),
#    "AltitudeConfidence": (pow(10,2),[14,15]),
    "HeadingValue": (pow(10,1),[3601]),
    "HeadingConfidence": (pow(10,1),[126,127]),
    "SpeedValue": (pow(10,2),[16383]),
    "VelocityComponentValue": (pow(10,2),[16383]),
    "SpeedConfidence": (pow(10,2),[126,127]),
    "AccelerationConfidence": (pow(10,1),[102]),
    "VehicleLengthValue": (pow(10,1),[1023]),
    "VehicleWidth": (pow(10,1),[61,62]),
    "LongitudinalAccelerationValue": (pow(10,1),[161]),
    "AccelerationValue": (pow(10,1),[161]),
    "YawRateValue": (pow(10,2),[32767]),
    "DistanceValue": (pow(10,2),[]),
    "DistanceConfidence": (pow(10,2),[101,102]),
    "SpeedValueExtended": (pow(10,2),[16383]),
    "LateralAccelerationValue": (pow(10,1),[161]),
    "LongitudinalAccelerationValue": (pow(10,1),[161]),
    "VerticalAccelerationValue": (pow(10,1),[161]),
    "ObjectDimensionValue": (pow(10,1),[]),
    "WGS84AngleValue": (pow(10,1),[3601]),
    "CartesianAngleValue": (pow(10,1),[3601]),
    "SensorHeight": (pow(10,2),[]),
    "SemiRangeLength": (pow(10,1),[]),
    "Radius": (pow(10,1),[]),
    "DeltaLatitude": (pow(10,7), [131072]),
    "DeltaLongitude": (pow(10,7), [131072]),
    "DeltaAltitude": (pow(10,2), [-12700, 12799, 12800]),
    "CoordinateConfidence": (pow(10,2), [4096]),
    "TimestampIts": (pow(10,3),[]),
    "AngleConfidence": (pow(10,1), [127]),
}

printed = ["PhoneNumber", "VehicleHeight", "PreemptPriorityList", "WMInumber", "VDS",
           "RegionalExtension", "TemporaryID", "DescriptiveName", "MessageFrame", "OpeningDaysHours",
           "Attributes", "GetStampedRq", "GetStampedRs", "SetInstanceRq", "SetStampedRq", "AttributeList",
           "AttributeIdList", "NULL", "CustomerContract"]

include = ["NodeXY", "VehicleID", "TransitVehicleStatus", "TransmissionAndSpeed", "ITS-Container_DigitalMap", "ETSI-ITS-CDD_DigitalMap",
           "Position3D", "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", 
           "DataParameters", "EnabledLaneList", "CS1", "CS2", "CS3", "CS4", "CS5", "CS7", "CS8", "ServiceNumber", 
           "GeoGraphicalLimit", "LicPlateNumber", "TaxCode", "AviEriDateTime", "ServiceApplicationLimit", 
           "FreightContainerData", "AddRq", "ChannelRq", "ChannelRs", "SubRq", "ContractAuthenticator", "DateCompact", 
           "Engine", "EquipmentOBUId", "EquipmentStatus", "ICC-Id", "LPN", "SignedValue", "PaymentSecurityData", 
           "PayUnit", "PersonalAccountNumber", "PurseBalance", "ReceiptOBUId", "ReceiptAuthenticator", "ReceiptText",
           "ResultFin", "SessionClass", "ReceiptContract", "SessionLocation", "DateAndTime", "ItsStationPosition", 
           "SignalHeadLocation", "ItsStationPositionList", "SignalHeadLocationList", "CurrentVehicleConfiguration",
           "ITS-Container_AccelerationControl", "ITS-Container_PtActivation", "ITS-Container_ClosedLanes",
           "ITS-Container_DrivingLaneStatus", "ITS-Container_DangerousGoodsExtended", "ITS-Container_LightBarSirenInUse", 
           "ITS-Container_PositionOfOccupants", "ITS-Container_VehicleIdentification", "ITS-Container_EnergyStorageType",
           "ITS-Container_VehicleLength", "ITS-Container_EmergencyPriority", "ITS-Container_SteeringWheelAngle", 
           "ITS-Container_ItineraryPath", "ITS-Container_ProtectedCommunicationZone", "ITS-Container_Traces", 
           "ITS-Container_PositionOfPillars", "ITS-Container_RestrictedTypes", "ITS-Container_EventHistory", "ITS-Container_EventPoint", 
           "ITS-Container_ProtectedCommunicationZonesRSU", "ITS-Container_CenDsrcTollingZone", 
           "CAM-PDU-Descriptions_BasicVehicleContainerHighFrequency", "CAM-PDU-Descriptions_BasicVehicleContainerLowFrequency", 
           "CAM-PDU-Descriptions_PublicTransportContainer", "CAM-PDU-Descriptions_SpecialTransportContainer", 
           "CAM-PDU-Descriptions_DangerousGoodsContainer", "CAM-PDU-Descriptions_RoadWorksContainerBasic", 
           "CAM-PDU-Descriptions_RescueContainer", "CAM-PDU-Descriptions_EmergencyContainer", "CAM-PDU-Descriptions_SafetyCarContainer", 
           "CAM-PDU-Descriptions_RSUContainerHighFrequency", "CAM-PDU-Descriptions_CamParameters", 
           "CAM-PDU-Descriptions_HighFrequencyContainer", "CAM-PDU-Descriptions_LowFrequencyContainer", 
           "CAM-PDU-Descriptions_SpecialVehicleContainer", "CAM-PDU-Descriptions_CAM", "DENM-PDU-Descriptions_RoadWorksContainerExtended", 
           "DENM-PDU-Descriptions_AlacarteContainer", "DENM-PDU-Descriptions_ManagementContainer", 
           "DENM-PDU-Descriptions_SituationContainer", "DENM-PDU-Descriptions_LocationContainer", "DENM-PDU-Descriptions_DENM",
           "RLLC", "RRLC", "McmGenericCurentStateContainer"]

add_t = ["ObjectClass", "VehicleID", "VehicleLength", "VerticalAcceleration", "DeltaReferencePosition", "ItsPduHeader", 
         "PtActivationData", "MapData","NodeAttributeSetXY", "NodeXY", "DigitalMap", "TransmissionAndSpeed", "Position3D",
         "IntersectionAccessPoint", "ComputedLane", "AdvisorySpeedList", "ConnectionManeuverAssist", "DataParameters", 
         "EnabledLaneList", "PerceivedObjectContainer", "RTCMmessage", "FreightContainerData", "LPN", "SignedValue",
         "PurseBalance", "ReceiptContract", "SessionClass", "SessionLocation", "DateAndTime", "ItsStationPosition", 
         "SignalHeadLocation", "ItsStationPositionList", "SignalHeadLocationList", "BatteryType", "ChargingSpotLabel",
         "ContractID", "ExternalIdentificationMeans", "Pairing-ID", "Reservation-ID", "Reservation-Password", 
         "StationDetails", "CustomerContract", "ManeuverResponse"]

pr_capitalize = ["originatingVehicleContainer", "originatingRsuContainer", "sensorInformationContainer", "perceptionRegionContainer", "perceivedObjectContainer"]

replace_types = {
    ("Temperature", "TS102894-2v131-CDD.asn"): "ITS_Container_Temperature",
    ("Temperature", "EN302637-3v131-DENM.asn"): "ITS_Container_Temperature",
    ("TrailerCharacteristics", "ISO14906-0-6.asn"): "EfcDsrcApplication_TrailerCharacteristics",
    ("DriverCharacteristics", "ISO14906-0-6.asn"): "EfcDsrcApplication_DriverCharacteristics",
    ("TrailerCharacteristics", "ISO19321IVIv2.asn"): "IVI_TrailerCharacteristics",
    ("DriverCharacteristics", "ISO19321IVIv2.asn"): "IVI_DriverCharacteristics",
    ("BasicContainer", "MCM-PDU-Descriptions.asn"): "BasicContainerMCM"
}

disambiguate_types = {
    ("DeltaReferencePosition", "ComputedSegment"): "ITS_Container_",
    ("DeltaReferencePosition", "DeltaReferencePositions", "IVI"): "ITS_Container_",
    ("DeltaReferencePosition", "DeltaReferencePositions"): "ETSI_ITS_CDD_",
    ("LanePosition", "LanePositions"): "ITS_Container_",
    ("IviIdentificationNumber", "IviIdentificationNumbers"): "IVI_",
    ("ActionID", "ConnectedDenms"): "ITS_Container_",
    ("CountryCode", "Provider"): "AVIAEINumberingAndDataStructures_",
    ("CountryCode", "CS1"): "AVIAEINumberingAndDataStructures_",
    ("CountryCode", "CS4"): "AVIAEINumberingAndDataStructures_",
    ("CountryCode", "CS8"): "AVIAEINumberingAndDataStructures_",
    ("LaneWidth", "BasicLaneInformation"): "ETSI_ITS_CDD_",
    ("LanePosition", "BasicLaneInformation"): "ETSI_ITS_CDD_",
    ("ProtectedZoneId", "CenDsrcTollingZone"): "",
    ("IA5String", "DangerousGoodsExtended"): "",
    ("UTF8String", "DangerousGoodsExtended"): "",
    ("ProtectedZoneId", "ProtectedCommunicationZone"): "",
    ("VehicleWidth", "TrailerData"): "ETSI_ITS_CDD_",
    ("StationId", "TrajectoryInterceptionIndication"): "",
    ("ProtectedZoneID", "ProtectedCommunicationZone"): "",
    ("VehicleHeight", "LaneAttributes-addGrpC"): "DSRC_",
    ("VehicleMass", "LaneAttributes-addGrpC"): "ITS_Container_",
    ("CountryCode", "LPN"): "AVIAEINumberingAndDataStructures_",
    ("SpecialTransportType", "LoadType"): "ITS_Container_",
    ("AccelerationControl", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("LanePosition", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("SteeringWheelAngle", "BasicVehicleContainerHighFrequency", "CAM-PDU-Descriptions"): "ITS_Container_",
    ("SteeringWheelAngle", "BasicVehicleContainerHighFrequency", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("AccelerationComponent", "BasicVehicleContainerHighFrequency"): "",
    ("CenDsrcTollingZone", "BasicVehicleContainerHighFrequency", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("PtActivation", "PublicTransportContainer", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("ClosedLanes", "RoadWorksContainerBasic", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("LateralAcceleration", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("VerticalAcceleration", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("PerformanceClass", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("CenDsrcTollingZone", "BasicVehicleContainerHighFrequency"): "ITS_Container_",
    ("ExteriorLights", "BasicVehicleContainerLowFrequency"): "ITS_Container_",
    ("PtActivation", "PublicTransportContainer"): "ITS_Container_",
    ("LightBarSirenInUse", "SpecialTransportContainer"): "ITS_Container_",
    ("SpecialTransportType", "SpecialTransportContainer"): "ITS_Container_",
    ("LightBarSirenInUse", "RoadWorksContainerBasic"): "ITS_Container_",
    ("RoadworksSubCauseCode", "RoadWorksContainerBasic"): "ITS_Container_",
    ("ClosedLanes", "RoadWorksContainerBasic"): "ITS_Container_",
    ("LightBarSirenInUse", "RescueContainer"): "ITS_Container_",
    ("LightBarSirenInUse", "EmergencyContainer"): "ITS_Container_",
    ("EmergencyPriority", "EmergencyContainer"): "ITS_Container_",
    ("CauseCode", "EmergencyContainer"): "ITS_Container_",
    ("LightBarSirenInUse", "SafetyCarContainer"): "ITS_Container_",
    ("CauseCode", "SafetyCarContainer"): "ITS_Container_",
    ("TrafficRule", "SafetyCarContainer"): "ITS_Container_",
    ("SpeedLimit", "SafetyCarContainer"): "ITS_Container_",
    ("ProtectedCommunicationZonesRSU", "RSUContainerHighFrequency"): "ITS_Container_",
    ("Termination", "ManagementContainer"): "",
    ("RelevanceDistance", "ManagementContainer"): "ITS_Container_",
    ("RelevanceTrafficDirection", "ManagementContainer"): "ITS_Container_",
    ("ValidityDuration", "ManagementContainer"): "ITS_Container_",
    ("TransmissionInterval", "ManagementContainer"): "ITS_Container_",
    ("Speed", "LocationContainer"): "ITS_Container_",
    ("Heading", "LocationContainer"): "ITS_Container_",
    ("RoadType", "LocationContainer"): "ITS_Container_",
    ("CauseCode", "SituationContainer"): "ITS_Container_",
    ("EventHistory", "SituationContainer"): "ITS_Container_",
    ("StationarySince", "StationaryVehicleContainer"): "ITS_Container_",
    ("CauseCode", "StationaryVehicleContainer"): "ITS_Container_",
    ("DangerousGoodsExtended", "StationaryVehicleContainer"): "ITS_Container_",
    ("NumberOfOccupants", "StationaryVehicleContainer"): "ITS_Container_",
    ("VehicleIdentification", "StationaryVehicleContainer"): "ITS_Container_",
    ("EnergyStorageType", "StationaryVehicleContainer"): "ITS_Container_",
    ("PositionOfOccupants", "ImpactReductionContainer"): "ITS_Container_",
    ("ActionID", "ReferenceDenms"): "ITS_Container_",
    ("VruProfileAndSubprofile", "VruLowFrequencyContainer"): "VAM_PDU_Descriptions_",
    ("VruExteriorLights", "VruLowFrequencyContainer"): "VAM_PDU_Descriptions_", 
    ("VruSizeClass", "VruLowFrequencyContainer"): "VAM_PDU_Descriptions_",
    ("ExteriorLights", "VruExteriorLights"): "ITS_Container_",
    ("ClusterJoinInfo", "VruClusterOperationContainer"): "VAM_PDU_Descriptions_",
    ("ClusterLeaveInfo", "VruClusterOperationContainer"): "VAM_PDU_Descriptions_",
    ("ClusterBreakupInfo", "VruClusterOperationContainer"): "VAM_PDU_Descriptions_",
    ("PathDeltaTime", "VruPathPoint"): "ITS_Container_",
    ("StationID", "VruSafeDistanceIndication"): "ITS_Container_",
    ("StationID", "TrajectoryInterceptionIndication"): "ITS_Container_",
    ("MapReference", "OriginatingRsuContainer"): "ETSI_ITS_CDD_",
    ("ReferencePosition", "TisTpgDRM-Location"): "ITS_Container_",
    ("ReferencePosition", "TisTpgTCM-Location"): "ITS_Container_",
    ("MapReference", "MapemElementReference"): "ETSI_ITS_CDD_",
    ("Identifier1B", "MapPosition"): "",
    ("LongitudinalLanePosition", "MapPosition"): "",
    ("MapReference", "MapReferences"): "ETSI_ITS_CDD_",
    ("MapPosition", "OccupiedLanesWithConfidence::OccupiedLanesWithConfidence__mapBased"): "ETSI_ITS_CDD_",
    ("PathPoint", "Path"): "ETSI_ITS_CDD_",
    ("PosConfidenceEllipse", "PathPointPredicted"): "ETSI_ITS_CDD_",
    ("Path", "Traces"): "",
    ("TimestampIts", "IviManagementContainer"): "ITS_Container_",
    ("Direction", "RscPart"): "IVI_",
    ("LightBarSirenInUse", "RoadWorksContainerExtended"): "ITS_Container_",
    ("ClosedLanes", "RoadWorksContainerExtended"): "ITS_Container_",
    ("RestrictedTypes", "RoadWorksContainerExtended"): "ITS_Container_",
    ("SpeedLimit", "RoadWorksContainerExtended"): "ITS_Container_",
    ("CauseCode", "RoadWorksContainerExtended"): "ITS_Container_",
    ("ItineraryPath", "RoadWorksContainerExtended"): "ITS_Container_",
    ("DeltaReferencePosition", "RoadWorksContainerExtended"): "ITS_Container_",
    ("TrafficRule", "RoadWorksContainerExtended"): "ITS_Container_",
    ("LanePosition", "AlacarteContainer"): "ITS_Container_",
    ("PositioningSolutionType", "AlacarteContainer"): "ITS_Container_",
    ("MessageSegmentationInfo", "ManagementContainer"): "",
    ("MessageRateRange", "ManagementContainer"): "",
    ("DigitalMap", "TpgStationData"): "ITS_Container_",
    ("MapPosition", "GeneralizedLanePosition"): "ETSI_ITS_CDD_",
    ("RoadType", "RoadConfigurationSection"): "ETSI_ITS_CDD_",
    ("Curvature", "VruHighFrequencyContainer"): "ITS_Container_",
    ("CurvatureCalculationMode", "VruHighFrequencyContainer"): "ITS_Container_",
    ("YawRate", "VruHighFrequencyContainer"): "ITS_Container_",
    ("LateralAcceleration", "VruHighFrequencyContainer"): "ITS_Container_",
    ("VerticalAcceleration", "VruHighFrequencyContainer"): "ITS_Container_",
    ("VruEnvironment", "VruHighFrequencyContainer"): "VAM_PDU_Descriptions_",
    ("VruMovementControl", "VruHighFrequencyContainer"): "VAM_PDU_Descriptions_",
    ("VruDeviceUsage", "VruHighFrequencyContainer"): "VAM_PDU_Descriptions_",
    ("PathHistory", "VruMotionPredictionContainer"): "ITS_Container_",
    ("SequenceOfTrajectoryInterceptionIndication", "VruMotionPredictionContainer"): "VAM_PDU_Descriptions_",
    ("AccelerationChangeIndication", "VruMotionPredictionContainer"): "VAM_PDU_Descriptions_",
    ("HeadingChangeIndication", "VruMotionPredictionContainer"): "VAM_PDU_Descriptions_",
    ("StabilityChangeIndication", "VruMotionPredictionContainer"): "VAM_PDU_Descriptions_",
    ("InterferenceManagementMitigationType", "InterferenceManagementInfoPerChannel"): "",
    ("LaneWidth", "RoadSegment"): "DSRC_",
    ("MapPosition", "PerceivedObject"): "ETSI_ITS_CDD_",
    ("LaneWidth", "IntersectionGeometry"): "DSRC_",
    ("TimestampIts", "GeographicLocationContainer"): "ITS_Container_",
    ("Heading", "GeographicLocationContainer"): "ITS_Container_",
    ("Speed", "GeographicLocationContainer"): "ITS_Container_",
    ("DigitalMap", "ItsChargingStationData"): "ITS_Container_",
    ("Direction", "TcPart"): "IVI_",
    ("ProtectedZoneRadius", "ZoneDefinition"): "ITS_Container_",
    ("SpeedValue", "AutomatedVehicleRule"): "ITS_Container_",
    ("SpeedValue", "PlatooningRule"): "ITS_Container_",
    ("VarLengthNumber", "GicPart"): "CITSapplMgmtIDs_",
    ("Direction", "GicPart"): "IVI_",
    ("Direction", "AvcPart"): "IVI_",
    ("LanePosition", "GlcPart"): "ITS_Container_",
    ("HeadingValue", "GlcPart"): "ITS_Container_",
    ("AltitudeValue", "GeoPosition"): "ETSI_ITS_CDD_",
    ("LaneType", "LanePositionAndType"): "ETSI_ITS_CDD_",
    ("Direction", "LanePositionAndType"): "ETSI_ITS_CDD_",
    ("Heading", "Wgs84TrajectoryPoint"): "ETSI_ITS_CDD_",
    ("Altitude", "Wgs84TrajectoryPoint"): "ETSI_ITS_CDD_",
    ("SaeAutomationLevel", "SaeAutomationLevels"): "ETSI_ITS_CDD_",
    ("SaeAutomationLevel", "VehicleMovementControl"): "ETSI_ITS_CDD_",
    ("AccelerationControl", "VehicleMovementControl"): "ETSI_ITS_CDD_",
    ("Termination", "ManagementContainer"): "DENM_PDU_Descriptions_",
    ("CauseCodeV2", "EmergencyContainer", "CAM-PDU-Description"): "",
    ("CauseCodeV2", "SafetyCarContainer", "CAM-PDU-Description"): "",
    ("EmergencyPriority", "EmergencyContainer", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("ProtectedCommunicationZonesRSU", "RSUContainerHighFrequency", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("EmergencyPriority", "EmergencyContainer", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("VruSubProfileBicyclist", "CyclistTypeSpecificInformation", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("VruMovementControl", "CyclistTypeSpecificInformation", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("StandardLength3b", "ManagementContainer", "DENM-PDU-Description"): "",
    ("TrafficDirection", "ManagementContainer", "DENM-PDU-Description"): "",
    ("DeltaTimeSecond", "ManagementContainer", "DENM-PDU-Description"): "",
    ("DeltaTimeMilliSecondPositive", "ManagementContainer", "DENM-PDU-Description"): "",
    ("CauseCodeV2", "SituationContainer", "DENM-PDU-Description"): "",
    ("EventZone", "SituationContainer", "DENM-PDU-Description"): "",
    ("ActionIdList", "SituationContainer", "DENM-PDU-Description"): "",
    ("Position1d", "SituationContainer", "DENM-PDU-Description"): "",
    ("ClosedLanes", "RoadWorksContainerExtended", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("RestrictedTypes", "RoadWorksContainerExtended", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("CauseCodeV2", "RoadWorksContainerExtended", "DENM-PDU-Description"): "",
    ("ItineraryPath", "RoadWorksContainerExtended", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("DeltaReferencePosition", "RoadWorksContainerExtended", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("ActionIdList", "RoadWorksContainerExtended", "DENM-PDU-Description"): "",
    ("CauseCodeV2", "StationaryVehicleContainer", "DENM-PDU-Description"): "",
    ("DangerousGoodsExtended", "StationaryVehicleContainer", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("VehicleIdentification", "StationaryVehicleContainer", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("DeltaReferencePosition", "ParkingSpaceBasic", "ETSI-ITS-CDD"): "ETSI_ITS_CDD_",
    ("DeltaReferencePosition", "ParkingSpaceDetailed", "ETSI-ITS-CDD"): "ETSI_ITS_CDD_",
    ("DeltaPositions", "ParkingSpaceDetailed", "ETSI-ITS-CDD"): "ETSI_ITS_CDD_",
    ("ReferenceDenms", "RoadWorksContainerExtended", "DENM-PDU-Descriptions"): "",
    ("ITS_Container_Temperature", "AlacarteContainer", "DENM-PDU-Descriptions"): "",
    ("SituationContainer", "DenmPayload", "DENM-PDU-Description"): "DENM_PDU_Description_",
    ("LocationContainer", "DenmPayload", "DENM-PDU-Description"): "DENM_PDU_Description_",
    ("AlacarteContainer", "DenmPayload", "DENM-PDU-Description"): "DENM_PDU_Description_",
    ("SituationContainer", "DecentralizedEnvironmentalNotificationMessage", "DENM-PDU-Descriptions"): "DENM_PDU_Descriptions_",
    ("LocationContainer", "DecentralizedEnvironmentalNotificationMessage", "DENM-PDU-Descriptions"): "DENM_PDU_Descriptions_",
    ("AlacarteContainer", "DecentralizedEnvironmentalNotificationMessage", "DENM-PDU-Descriptions"): "DENM_PDU_Descriptions_",
    ("StabilityChangeIndication", "TwoWheelerContainer", "CAM-PDU-Description"): "ETSI_ITS_CDD_",
    ("Speed", "LocationContainer", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("Wgs84Angle", "LocationContainer", "DENM-PDU-Description"): "",
    ("GeneralizedLanePositions", "LocationContainer", "DENM-PDU-Description"): "",
    ("OccupiedLanesWithConfidence", "LocationContainer", "DENM-PDU-Description"): "",
    ("IvimReferences", "LocationContainer", "DENM-PDU-Description"): "",
    ("MapReferences", "LocationContainer", "DENM-PDU-Description"): "",
    ("TracesExtended", "LocationContainer", "DENM-PDU-Description"): "",
    ("PathPredictedList", "LocationContainer", "DENM-PDU-Description"): "",
    ("Temperature", "AlacarteContainer", "DENM-PDU-Description"): "ETSI_ITS_CDD_",
    ("PreCrashContainer", "AlacarteContainer", "DENM-PDU-Description"): "",
    ("RccPart", "RoadConfigurationContainer", "IVI"): "",
    ("WrappedExtensionContainers", "CamParameters", "CAM-PDU-Description"): "",
    ("EventPoint", "EventZone", "ETSI-ITS-CDD"): "ETSI_ITS_CDD_",
    
    ("Latitude", "Trajectory::Trajectory__latitudePositions"): "ETSI_ITS_CDD_",
    ("Longitude", "Trajectory::Trajectory__longitudePositions"): "ETSI_ITS_CDD_",
    ("Altitude", "Trajectory::Trajectory__altitudePositions"): "ETSI_ITS_CDD_",
    ("Speed", "Trajectory::Trajectory__speed"): "ETSI_ITS_CDD_",
    ("SpecialTransportType", "VehicleSize"): "ETSI_ITS_CDD_",
    ("Iso3833VehicleType", "RequestorType"): "ElectronicRegistrationIdentificationVehicleDataModule_",
    ("DeltaAltitude", "PathPointPredicted"): "ETSI_ITS_CDD_",
    ("AltitudeConfidence", "PathPointPredicted"): "ETSI_ITS_CDD_",
}

ignore_member_names = ['regional', 'shadowingApplies', 'expiryTime', 'fill', 'ownerCode', 'language', 'sessionLocation', 'avc', 'mlc', 'rsc', 'train']
ignore_member_types = ["PhoneNumber", "OpeningDaysHours", "MessageFrame", "DescriptiveName", "RegionalExtension", "REG-EXT-ID-AND-TYPE.&id", 
                       "REG-EXT-ID-AND-TYPE.&Type", 'MESSAGE-ID-AND-TYPE.&id', 'MESSAGE-ID-AND-TYPE.&Type', 
                       'PreemptPriorityList', "WMInumber", "VDS", "TemporaryID", "Attributes", "GetStampedRq", "GetStampedRs", 
                       "SetInstanceRq", "SetStampedRq", "AttributeList", "AttributeIdList"] # "EventZone"]

treat_as_optional = [("validityDuration", "ManagementContainer"), ("deltaAltitude", "PathPointPredicted"), ("altitudeConfidence", "PathPointPredicted")]

capitalize_first_letter = ["class", "long"]

integer_types = ["TimestampIts"]

add_pointer = [
    ("GddAttribute", "ddd"),
    ("InternationalSign-destinationInformation", "ioList")
]

alias_pointer_types = {
    "EventZone": ("ETSI_ITS_CDD_EventHistory_t", "EventZone")
}

######

basic = []
asn1_types = []
bitstrings = {}

initial_len = len(printed)

def get_element_name(m, self, opt):
    return ('*' if "optional" in m and m["optional"] and opt else '') + \
            '(p.' + ('choice.' if self.definition["type"] == "CHOICE" else '') + \
            ((m["ext"] + '->') if m["ext"] != None else '') + \
            (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_")

def get_disambiguated_member_name(type, parent, root, print_name):
    if (type, parent, root) in disambiguate_types:
        return (disambiguate_types[(type, parent, root)] + type).replace("-", "_")
    elif (type, parent) in disambiguate_types:
        return (disambiguate_types[(type, parent)] + type).replace("-", "_")
    elif print_name != parent and type != "INTEGER":
        return (root + "_" + type).replace("-", "_")
    else:
        return type.replace("-", "_")


def strip_outer_parens(expr):
    expr = expr.strip()
    while expr.startswith('(') and expr.endswith(')'):
        expr = expr[1:-1].strip()
    if expr.startswith('('):
        expr = expr[1:].strip()
    if expr.endswith(')'):
        expr = expr[:-1].strip()
    return expr


class ASN1Sequence:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = []
        self.ignored_members = []
        ext = 0
        for i in range(len(definition["members"])):
            m = definition["members"][i]
            if m is None:
                if i != len(definition["members"]) - 2:
                    ext += 1
            elif m["type"] not in ignore_member_types and m['name'] not in ignore_member_names:
                m["ext"] = "ext" + str(ext) if ext > 0 else (m["ext"] if "ext" in m else None)
                self.members.append(m)
            else:
                m["ext"] = "ext" + str(ext) if ext > 0 else None
                self.ignored_members.append(m)
        self.dependencies = [
            m for m in self.members if m["type"] not in default_types]
        self.parent_name = parent_name
        self.parent_file = parent_file
        self.print_name = name

        for m in self.members:
            if (m["name"], self.name) in treat_as_optional:
                m["optional"] = True
            if "default" in m and m["name"] == "altitude":
                m["optional"] = True

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field);
"""

    def __str__(self):
        result = """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    """

        struct_name = self.print_name.replace("-", "_")

        member_strs = []
        for m in self.members:
            if m["type"] in integer_types and m["type"] in transformation:
                member_strs.append("long " + m["name"] + ";")
                member_strs.append("asn_INTEGER2long(" + ("&" if 'optional' not in m or not m['optional'] else "") + get_element_name(m, self, False) + "), &" + m['name'] + ");")

        for m in self.members:
            if "optional" in m and m["optional"]:
                continue
            if m["type"] in alias_pointer_types:
                ptr = get_element_name(m, self, False)
                ptr_no = strip_outer_parens(ptr)
                alias_type = alias_pointer_types[m["type"]][0]
                cast_expr = '*reinterpret_cast<' + alias_type + '*>(' + ptr_no + ')'
                member_str = 'json.AddMember("' + m["name"] + '", to_json(' + cast_expr + ', allocator), allocator);'
                member_strs.append(member_str)
                continue
            
            member_str = ('json.AddMember("' + m["name"] + '", ' + ('to_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(' if m["type"] in bitstrings else 'to_json('))
            
            if m["type"] in transformation:
                condition_str = " || ".join([(get_element_name(m, self, True) + \
                                            ") == " + str(n)) for n in transformation[m["type"]][1]])
                
                if len(transformation[m["type"]][1]) > 0:
                    member_str += "(" + condition_str + ") ? " + \
                                    get_element_name(m, self, True) + ') : '
                
                if m["type"] in integer_types:
                    member_str += '(double) (' + m["name"] + \
                                ') / ' + str(float(transformation[m["type"]][0]))
                else:
                    member_str += '(double)' + get_element_name(m, self, False) + \
                                ') / ' + str(float(transformation[m["type"]][0]))
            else:
                member_str += get_element_name(m, self, False) + ')'
            
            member_str += ', allocator), allocator);'
            if m.get("ext") is not None:
                member_str = 'if (p.' + m["ext"] + ' != 0) ' + member_str
            member_strs.append(member_str)
        
        result += '\n    '.join(member_strs) + """
"""
        
        member_strs = []
        for m in self.members:
            if "optional" in m and m["optional"]:
                if m["type"] in alias_pointer_types:
                    ptr = get_element_name(m, self, False)
                    ptr_no = strip_outer_parens(ptr)
                    alias_type = alias_pointer_types[m["type"]][0]
                    cast_expr = '*reinterpret_cast<' + alias_type + '*>(' + ptr_no + ')'
                    condition = ptr_no + ' != 0'
                    if m.get("ext") is not None:
                        condition = 'p.' + m["ext"] + ' != 0 && ' + ptr_no + ' != 0'
                    member_str = 'if (' + condition + ') json.AddMember("' + m["name"] + '", to_json(' + cast_expr + ', allocator), allocator);'
                    member_strs.append(member_str)
                    continue
                extendee= "ext" in m and m["ext"] != None
                member_str = ('if ' + ('(p.' + m["ext"] + ' != 0 && ' if extendee else '') + get_element_name(m, self, False) + ' != 0' + (')' if extendee else '') + ') ' + \
                                'json.AddMember("' + m["name"] + '", ' + ('to_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(' if m["type"] in bitstrings else 'to_json('))
                                
                if m["type"] in transformation:
                    condition_str = " && ".join([(get_element_name(m, self, True) + \
                                                ") != " + str(n)) for n in transformation[m["type"]][1]])

                    if len(transformation[m["type"]][1]) > 0:
                        member_str += "(" + condition_str + ") ? "
                    
                    if m["type"] in integer_types:
                        member_str += '(double) (' + m["name"] + \
                                    ') / ' + str(float(transformation[m["type"]][0]))
                    else: 
                        member_str += '(double) *' + get_element_name(m, self, False) + \
                                    ') / ' + str(float(transformation[m["type"]][0]))

                    if len(transformation[m["type"]][1]) > 0:
                        member_str += ' : *' + get_element_name(m, self, False) + ')'

                else:
                    member_str += get_element_name(m, self, True) + ')'
            
                member_str += ', allocator), allocator);'
                member_strs.append(member_str)
        
        result += '    ' + '\n    '.join(member_strs)
        
        result += """
    return json;
}

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field) {
    try {
        p._asn_ctx.ptr = nullptr;
"""
        ext_required = sorted({m["ext"] for m in self.members if m.get("ext") is not None and ("optional" not in m or not m["optional"])})
        for ext in ext_required:
            result += '        if (p.' + ext + " == 0) { p." + ext + " = vanetza::asn1::allocate<" + struct_name + "::" + struct_name + "__" + ext + ">(); }\n"
        member_strs = []
        for m in self.members:
            needs_closing = False
            member_str = ""

            alias_info = alias_pointer_types.get(m["type"])
            if alias_info is not None and "optional" in m and m["optional"]:
                ptr = get_element_name(m, self, False)
                ptr_no = strip_outer_parens(ptr)
                alias_type = alias_info[0]
                alias_struct = alias_info[1]
                member_str = 'if (j.HasMember("' + m["name"] + '")) { ' + alias_type + ' *tmp = vanetza::asn1::allocate<' + alias_type + '>(); from_json(j["' + m["name"] + '"], *tmp, "' + m["name"] + '"); ' + ptr_no + ' = reinterpret_cast<' + alias_struct + '*>(tmp); }\n        else { ' + ptr_no + ' = nullptr; }'
                member_strs.append(member_str)
                continue

            if m["type"] in transformation:
                member_str += 'double ' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '; '
            
            if "optional" in m and m["optional"]:
                needs_closing = True
                member_str += 'if (j.HasMember("' + m["name"] + '")) { '
                if m.get("ext") is not None:
                    member_str += 'if (p.' + m["ext"] + ' == 0) { p.' + m["ext"] + ' = vanetza::asn1::allocate<' + struct_name + '::' + struct_name + '__' + m["ext"] + '>(); } '
                member_str += get_element_name(m, self, False)[1:] + \
                                ' = vanetza::asn1::allocate<' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name).replace(" ", "_").replace("INTEGER", "long") +  \
                                    ('_t' if m["type"] not in ["INTEGER"] and "actual_type" not in m else '') + '>(); '
            
            if m["type"] not in bitstrings:
                member_str += 'from_json(j["' + m["name"] + '"], '
            else:
                member_str += 'from_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(j["' + m["name"] + '"],'
            
            if m["type"] not in transformation:
                member_str += get_element_name(m, self, True) + '), "' + m["name"] + '");'
            else:
                if m["type"] in integer_types:
                    member_str += '(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '), "' + m["name"] + '"); ' + \
                                m["name"] + \
                                ' = '
                else:
                    member_str += '(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + '), "' + m["name"] + '"); ' + \
                                get_element_name(m, self, True) + \
                                ') = '
                if len(transformation[m["type"]][1]) > 0:
                    member_str += '(' + ' && '.join([('(' + (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ') != ' + str(n)) for n in transformation[m["type"]][1]]) + ') ? ' + \
                                    (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ' * ' + str(int(transformation[m["type"]][0])) + ' : ' + \
                                    (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + ';'
                else:
                    member_str += (m["name"] if m['name'] not in capitalize_first_letter else m['name'].title()).replace("-", "_") + \
                                    ' * ' + str(int(transformation[m["type"]][0]) if (transformation[m["type"]][0]).is_integer() else float(transformation[m["type"]][0])) + ';'

                if m["type"] in integer_types:
                    member_str += " memset(&" + get_element_name(m, self, True) + "), 0, sizeof" + get_element_name(m, self, True) + ")); asn_long2INTEGER(&" + get_element_name(m, self, True) + "), static_cast<long>(" + m["name"] + "));"
                                    
            if needs_closing:
                else_prefix = 'if (p.' + m["ext"] + ' != 0) ' if m.get("ext") is not None else ''
                member_str += ' }\n        else { ' + else_prefix + \
                                 get_element_name(m, self, False)[1:] + '=nullptr; }'
            
            member_strs.append(member_str)

            if "Id" in m["name"] and "Wrapped" in self.name:
                extra_str = "p." + self.members[1]['name'] + ".present = static_cast<" + self.members[1]['type'].split('::')[1] + "_PR>(p." + m['name'] + ");"
                member_strs.append(extra_str)

        for m in self.ignored_members:
            member_str = ""
            if "optional" in m and m["optional"]:
                prefix = 'if (p.' + m["ext"] + ' != 0) ' if m.get("ext") is not None else ''
                member_str += prefix + get_element_name(m, self, False)[1:] + '=nullptr;'
            member_strs.append(member_str)

        if member_strs:
            result += '        ' + '\n        '.join(member_strs)

        result += """
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

"""
        
        return result



class ASN1Choice:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.actual_type = definition['actual_type'] if 'actual_type' in definition else None
        self.members = [m for m in definition["members"] if m is not None and m["type"] not in ignore_member_types and m['name'] not in ignore_member_names]
        self.dependencies = [
            m for m in self.members if m["type"] not in default_types]
        self.parent_name = parent_name
        self.parent_file = parent_file
        self.print_name = name

        for m in self.members:
            if m['name'] in capitalize_first_letter:
                m['name'] = m['name'].title()

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field);
"""

    def __str__(self):
        result =  """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    if """

        member_strs = []
        for m in self.members:
            member_str = '(p.present == ' + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.print_name.replace("-", "_")) + \
                        '_PR_' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ') {\n        '
            
            if "Wrapped" not in self.name:
                if m["type"] not in bitstrings:
                    member_str += 'json.AddMember("' + m["name"] + '", to_json(p.choice.' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ', allocator), allocator);'
                else:
                    member_str += 'json.AddMember("' + m["name"] + '", to_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(' + ('*' if "optional" in m and m["optional"] else '') + 'p.choice.' + m["name"].replace("-", "_") + ', allocator), allocator);'
            else:
                if m["type"] not in bitstrings:
                    member_str += 'json = to_json(p.choice.' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ', allocator);'
                else:
                    member_str += 'json = to_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(' + ('*' if "optional" in m and m["optional"] else '') + 'p.choice.' + m["name"].replace("-", "_") + ', allocator);'


            member_strs.append(member_str)

        result += '\n    } else if '.join(member_strs)
        result += """
    }
    return json;
}

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field) {
    try {
        if """ 

        member_strs = []
        for m in self.members:
            if "Wrapped" not in self.name:
                member_str = '(j.HasMember("' + m["name"] + '")) {\n            p.present = ' + \
                        (self.actual_type.replace("-", "_") if self.actual_type is not None else self.print_name.replace("-", "_")) + \
                        '_PR_' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ';\n        '
            else:
                member_str = '(p.present == ' + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.print_name.replace("-", "_")) + \
                        '_PR_' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ') {\n        '

            if "Wrapped" not in self.name:
                if m["type"] not in bitstrings:
                    member_str += '    from_json(j["' + m["name"] + '"], '
                else:
                    member_str += '    from_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(j["' + m["name"] + '"], '
            else:
                if m["type"] not in bitstrings:
                    member_str += '    from_json(j, '
                else:
                    member_str += '    from_json_' + get_disambiguated_member_name(m["type"], self.name, self.parent_name, self.print_name) + '(j, '


            member_str += ('*' if "optional" in m and m["optional"] else '') + 'p.choice.' + (m["name"].replace("-", "_") if m["name"] not in pr_capitalize else (m["name"][0].upper() + m["name"][1:]).replace("-", "_")) + ', "' + m["name"] + '");'

            member_strs.append(member_str)

        result += '\n        } else if '.join(member_strs)
        result += """\n        } else {
        p.present = """ + (self.actual_type.replace("-", "_") if self.actual_type is not None else self.print_name.replace("-", "_")) + """_PR_NOTHING;
        }
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}"""

        return result

class ASN1SequenceOf:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        # print(definition)
        self.element = definition["element"]["type"]
        self.members = [definition["element"]]
        self.dependencies = [self.element] if self.element not in default_types else []
        self.parent_name = parent_name
        self.parent_file = parent_file
        self.print_name = name

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kArrayType);
    for(int i = 0; i < p.list.count; i++) {
        """ + (("const " + get_disambiguated_member_name(self.element, self.name, self.parent_name, self.print_name) + "_t po = *(p.list.array[i]);") if "INTEGER" not in get_disambiguated_member_name(self.element, self.name, self.parent_name, self.print_name) else (get_disambiguated_member_name(self.element, self.name, self.parent_name, self.print_name) + "_t po;\n        asn_long2INTEGER(&po, *(p.list.array[i]));")) + """
        """ + ('// ' if self.element in basic else '') + """Value obj = to_json(po, allocator);
        json.PushBack(""" + ('po' if self.element in basic else 'obj') + """, allocator);
    }
    return json;
}

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field) {
    try {
        """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """* p_tmp = vanetza::asn1::allocate<""" + \
          (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """>();
        for (SizeType i = 0; i < j.Size(); i++) {
            const Value& item = j[i];
            """ + get_disambiguated_member_name(self.element, self.name, self.parent_name, self.print_name) + """_t *element = vanetza::asn1::allocate<""" + get_disambiguated_member_name(self.element, self.name, self.parent_name, self.print_name) + """_t>();
            from_json(item, *element, "index #" + std::to_string(i));
            asn_set_add(&(p_tmp->list), element);
        }
        p = *p_tmp;
        delete p_tmp;
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}"""


class ASN1BitString:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.members = [m for m in definition["named-bits"]
                        if m is not None] if "named-bits" in definition else []
        self.parent_name = parent_name
        self.parent_file = parent_file
        self.print_name = name

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json_""" + self.print_name.replace("-", "_") + """(const """ + self.print_name.replace("-", "_") + """_t p, Document::AllocatorType& allocator);

void from_json_""" + self.print_name.replace("-", "_") + """(const Value& j, """ + self.print_name.replace("-", "_") + """_t& p, std::string field);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json_""" + self.print_name.replace("-", "_") + """(const """ + self.print_name.replace("-", "_") + """_t p, Document::AllocatorType& allocator) {
    Value json(kObjectType);
    """ + '\n    '.join(['json.AddMember("' + m[0] + '", ' + '(bool) (*(p.buf + (sizeof(uint8_t) * (' + str(m[1]) + ' / 8))) & (1 << ((7 * ((' + str(int(m[1])) + ' / 8) + 1))-(' + \
                         str(m[1]) + ' % 8)))), allocator);' for m in self.members]) + """
    return json;
}

void from_json_""" + self.print_name.replace("-", "_") + """(const Value& j, """ + self.print_name.replace("-", "_") + """_t& p, std::string field) {
    try {
        """ + self.print_name.replace("-", "_") + """_t* p_tmp = vanetza::asn1::allocate<""" + self.print_name.replace("-", "_") + """_t>();
        """ + '\n        '.join(["bool " + m[0].replace("-", "_") + ";" for m in self.members]) + """
        """ + '\n        '.join(['if (j.HasMember("' + m[0] + '")) from_json(j["' + m[0] + '"], ' + '(' + m[0].replace("-", "_") + '), "' + m[0] + '");' for m in self.members]) + """
        p_tmp->size = (""" + str(len(self.members)) + """ / 8) + 1;
        p_tmp->bits_unused = (""" + str(len(self.members)) + """ % 8) != 0 ? 8 - (""" + str(len(self.members)) + """ % 8) : 0;
        p_tmp->buf = (uint8_t *) calloc(1, sizeof(uint8_t) * p_tmp->size);
        """ + '\n        '.join(['*(p_tmp->buf + (sizeof(uint8_t) * ' + str(i) + ')) = (uint8_t) 0;' for i in range(int(len(self.members) / 8) + 1)]) + """
        """ + '\n        '.join(['if (' + m[0].replace("-", "_") + ') *(p_tmp->buf + (sizeof(uint8_t) * ' + str(int(int(m[1])/8)) + ')) |= (1 << ' + str(7 - (int(m[1]) % 8)) + ');' for m in self.members]) + """
        p = *p_tmp;
        delete p_tmp;
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}"""


class ASN1TODO:
    def __init__(self, name, definition, parent_name, parent_file):
        self.name = name
        self.definition = definition
        self.parent_name = parent_name
        self.parent_file = parent_file
        self.print_name = name

    def header_str(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator);

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field);
"""

    def __str__(self):
        return """
/*
*   """ + self.name + """ - Type """ + self.definition["type"] + """
*   From """ + self.parent_name + """ - File """ + self.parent_file + """
*/

Value to_json(const """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, """ + (self.print_name.replace("-", "_") + "_t" if self.name in add_t else self.print_name.replace("-", "_")) + """& p, std::string field) {
    // TODO
}"""


def parse_type(type_name, top_level_key, asn1_file, asn1_type):
    type_name = type_name if (type_name, asn1_file) not in replace_types else replace_types[(type_name, asn1_file)]
    if "element" in asn1_type:
        asn1_type["element"]["type"] = asn1_type["element"]["type"] if (asn1_type["element"]["type"], asn1_file) not in replace_types else replace_types[(asn1_type["element"]["type"], asn1_file)]
    if "members" in asn1_type:
        members = []
        for m in asn1_type["members"]:
            if m is not None:
                if isinstance(m, list):
                    for n in m:
                        n["ext"] = "ext1"
                    members.extend(m)
                else:
                    members.append(m)
        for m in members:
            if m is not None:
                m["type"] = m["type"] if (m["type"], asn1_file) not in replace_types else replace_types[(m["type"], asn1_file)]
                if (type_name, m["name"]) in add_pointer:
                    m["optional"] = True
        asn1_type["members"] = members

    if "ISO14906" in asn1_file and "::" not in type_name:
        if type_name == "Provider":
            include.append("ETSI-ITS-CDD_Provider")
            include.append("EfcDsrcApplication_Provider")
        else:
            include.append(type_name)
        add_t.append(type_name)
    if "CDD-Release2" in asn1_file and "::" not in type_name:
        if type_name in ["AccelerationChangeIndication", "AccelerationConfidence", "AccelerationControl", "AccessTechnologyClass", "AccidentSubCauseCode", "ActionID", "AdverseWeatherCondition-AdhesionSubCauseCode", "AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode", "AdverseWeatherCondition-PrecipitationSubCauseCode", "AdverseWeatherCondition-VisibilitySubCauseCode", "Altitude", "AltitudeConfidence", "AltitudeValue", "BasicContainer", "CauseCode", "CauseCodeType", "CenDsrcTollingZone", "CenDsrcTollingZoneID", "ClosedLanes", "ClusterBreakupInfo", "ClusterBreakupReason", "ClusterJoinInfo", "ClusterLeaveInfo", "ClusterLeaveReason", "CollisionRiskSubCauseCode", "CountryCode", "Curvature", "CurvatureCalculationMode", "CurvatureConfidence", "CurvatureValue", "DangerousEndOfQueueSubCauseCode", "DangerousGoodsBasic", "DangerousGoodsExtended", "DangerousSituationSubCauseCode", "DeltaAltitude", "DeltaLatitude", "DeltaLongitude", "DeltaReferencePosition", "DigitalMap", "Direction", "DriveDirection", "DrivingLaneStatus", "EmbarkationStatus", "EmergencyPriority", "EmergencyVehicleApproachingSubCauseCode", "EnergyStorageType", "EuVehicleCategoryCode", "EuVehicleCategoryL", "EuVehicleCategoryM", "EuVehicleCategoryN", "EuVehicleCategoryO", "EventHistory", "EventPoint", "Ext1", "Ext2", "Ext3", "ExteriorLights", "GenerationDeltaTime", "HardShoulderStatus", "HazardousLocation-AnimalOnTheRoadSubCauseCode", "HazardousLocation-DangerousCurveSubCauseCode", "HazardousLocation-ObstacleOnTheRoadSubCauseCode", "HazardousLocation-SurfaceConditionSubCauseCode", "Heading", "HeadingChangeIndication", "HeadingConfidence", "HeadingValue", "HeightLonCarr", "HumanPresenceOnTheRoadSubCauseCode", "HumanProblemSubCauseCode", "InformationQuality", "InterferenceManagementChannel", "InterferenceManagementInfo", "InterferenceManagementInfoPerChannel", "InterferenceManagementZone", "InterferenceManagementZones", "InterferenceManagementZoneType", "Iso3833VehicleType", "ItineraryPath", "ItsPduHeader", "IviIdentificationNumber", "LanePosition", "LaneType", "LaneWidth", "LateralAcceleration", "LateralAccelerationValue", "Latitude", "LightBarSirenInUse", "Longitude", "LongitudinalAcceleration", "LongitudinalAccelerationValue", "MapPosition", "MapReference", "MitigationForTechnologies", "MitigationPerTechnologyClass", "NumberOfOccupants", "OpeningDaysHours", "PathDeltaTime", "PathHistory", "PathPoint", "PerformanceClass", "PhoneNumber", "PosCentMass", "PosConfidenceEllipse", "PosFrontAx", "PositioningSolutionType", "PositionOfOccupants", "PositionOfPillars", "PosLonCarr", "PosPillar", "PostCrashSubCauseCode", "ProtectedCommunicationZone", "ProtectedCommunicationZonesRSU", "ProtectedZoneRadius", "ProtectedZoneType", "Provider", "PtActivation", "PtActivationData", "PtActivationType", "ReferencePosition", "RelevanceDistance", "RelevanceTrafficDirection", "RequestResponseIndication", "RescueAndRecoveryWorkInProgressSubCauseCode", "RestrictedTypes", "RoadType", "RoadworksSubCauseCode", "SemiAxisLength", "SequenceNumber", "SequenceOfTrajectoryInterceptionIndication", "SignalViolationSubCauseCode", "SlowVehicleSubCauseCode", "SpecialTransportType", "Speed", "SpeedConfidence", "SpeedLimit", "SpeedValue", "StabilityChangeIndication", "StabilityLossProbability", "StationarySince", "StationaryVehicleSubCauseCode", "StationID", "StationType", "SteeringWheelAngle", "SteeringWheelAngleConfidence", "SteeringWheelAngleValue", "SubCauseCodeType", "Temperature", "TimestampIts", "Traces", "TrafficConditionSubCauseCode", "TrafficIslandPosition", "TrafficRule", "TrajectoryInterceptionConfidence", "TrajectoryInterceptionIndication", "TrajectoryInterceptionProbability", "TransmissionInterval", "TurningRadius", "ValidityDuration", "VarLengthNumber", "VDS", "VehicleBreakdownSubCauseCode", "VehicleHeight", "VehicleIdentification", "VehicleLength", "VehicleLengthConfidenceIndication", "VehicleLengthValue", "VehicleMass", "VehicleRole", "VehicleWidth", "VerticalAcceleration", "VerticalAccelerationValue", "VruDeviceUsage", "VruEnvironment", "VruExteriorLights", "VruMovementControl", "VruProfileAndSubprofile", "VruSizeClass", "VruSpecificExteriorLights", "VruSubProfileAnimal", "VruSubProfileBicyclist", "VruSubProfileMotorcyclist", "VruSubProfilePedestrian", "WheelBaseVehicle", "WMInumber", "WrongWayDrivingSubCauseCode", "YawRate", "YawRateConfidence", "YawRateValue", "SaeAutomationLevel", "DeltaPosition", "DeltaPositions", "DeltaReferencePositions", "PolygonalLine"]:
            include.append("ETSI-ITS-CDD_" + type_name)
        else:
            include.append(type_name)
        add_t.append(type_name)
#    if "CAM-PDU" in asn1_file and "::" not in type_name:
#        if type_name in ['CAM', 'CamParameters', 'HighFrequencyContainer', 'LowFrequencyContainer', 'SpecialVehicleContainer', 'BasicVehicleContainerHighFrequency', 'BasicVehicleContainerLowFrequency', 'PublicTransportContainer', 'SpecialTransportContainer', 'DangerousGoodsContainer', 'RoadWorksContainerBasic', 'RescueContainer', 'EmergencyContainer', 'SafetyCarContainer', 'RSUContainerHighFrequency']:
#            include.append("CAM_PDU_Descriptions_" + type_name)
#        else:
#            include.append(type_name)
#        add_t.append(type_name)
    if asn1_type["type"] in ["SEQUENCE"]:
        for m in asn1_type["members"]:
            if m is not None and m['name'] not in ignore_member_names and m['type'] in ["SEQUENCE", "CHOICE", "SEQUENCE OF"]:
                escaped_type_name = type_name
                if "::" in type_name:
                    escaped_type_name = type_name.split("::")[-1]
                m['actual_type'] = escaped_type_name + '__' + m['name'] + "_PR::" + escaped_type_name + '__' + m['name']

                if m['type'] in ["SEQUENCE", "CHOICE"]:
                    parse_type(type_name + "::" + escaped_type_name + '__' + m['name'], top_level_key, asn1_file, {'type': m['type'], 'members': m['members'], 'name': type_name + "::" + escaped_type_name + '__' + m['name'], 'actual_type': m['actual_type']})
                if m['type'] in ["SEQUENCE OF"]:
                    parse_type(type_name + "::" + escaped_type_name + '__' + m['name'], top_level_key, asn1_file, {'type': m['type'], 'element': m['element'], 'name': type_name + "::" + escaped_type_name + '__' + m['name'], 'actual_type': m['actual_type']})

                m['type'] = type_name + "::" + escaped_type_name + '__' + m['name']
        asn1_types.append(ASN1Sequence(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["CHOICE"]:
        asn1_types.append(ASN1Choice(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["SEQUENCE OF"]:
        asn1_types.append(ASN1SequenceOf(
            type_name, asn1_type, top_level_key, asn1_file))
    elif asn1_type["type"] in ["BIT STRING"]:
        asn1_types.append(ASN1BitString(
            type_name, asn1_type, top_level_key, asn1_file))
        bitstrings[type_name] = ASN1BitString(
            type_name, asn1_type, top_level_key, asn1_file)
    elif asn1_type["type"] in ["OCTET STRING", "NumericString", "UTF8String", "IA5String", "NodeOffsetPointXY", "NodeOffsetPointZ", "VisibleString"]:
        asn1_types.append(
            ASN1TODO(type_name, asn1_type, top_level_key, asn1_file))
        if asn1_type["type"] == "OCTET STRING":
            add_t.append(type_name)
    else:
        #print(type_name)
        if all(t not in type_name for t in ["WayPoint"]):
            basic.append(type_name)
        printed.append(type_name)


for asn1_file in asn1_files:
    #print(asn1_file)
    parsed_info = asn1tools.parse_files(base_dir + "/" + asn1_file)
    for top_level_key in list(parsed_info.keys()):
        for type_name in parsed_info[top_level_key]["types"]:
            asn1_type = parsed_info[top_level_key]["types"][type_name]
            parse_type(type_name, top_level_key, asn1_file, asn1_type)

intro = """/*
*   JSON marshalling and unmarshalling functions for use by RapidJSON
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
*/

#include "asn1json.hpp"
#include <boost/optional.hpp>

Value to_json(const ITS_Container_TimestampIts_t& p, Document::AllocatorType& allocator) {
    long tmp;
    asn_INTEGER2long(&p, &tmp);
    return Value(tmp);
}

void from_json(const Value& j, ITS_Container_TimestampIts_t& p, std::string field) {
    try {
        p.buf = nullptr;
        asn_long2INTEGER(&p, j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64());
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, long& p, std::string field) {
    try {  
        p = j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const unsigned long* p, Document::AllocatorType& allocator) {
    return Value(*p);
}

void from_json(const Value& j, long* p, std::string field) {
    try {  
        *p = j.IsDouble() ? static_cast<long>(j.GetDouble()) : j.GetInt64();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const unsigned long& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned long& p, std::string field) {
    try {
        p = j.GetUint64();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const unsigned& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, unsigned& p, std::string field) {
    try {
        if (j.IsBool()) p = j.GetBool();
        else p = j.GetUint();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const double& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, double& p, std::string field) {
    try {
        p = j.GetDouble();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const bool& p, Document::AllocatorType& allocator) {
    return Value(p);
}

void from_json(const Value& j, bool& p, std::string field) {
    try {
        p = j.GetBool();
    } catch(VanetzaJSONException& ex) {
        ex.addContext(field);
        ex.rethrow();
    }
}

Value to_json(const OCTET_STRING_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, OCTET_STRING_t& p, std::string field) {
    // TODO
}

Value to_json(const NULL_t& p, Document::AllocatorType& allocator) {
    Value json(kObjectType); 
    return json;
    // TODO
}

void from_json(const Value& j, NULL_t& p, std::string field) {
    // TODO
}

"""

header_intro = """/*
*   JSON marshalling and unmarshalling functions for use by RapidJSON
*   Auto-generated from the asn1 directory by asn1json.py on """ + str(datetime.now()) + """
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

""" + '\n'.join(['#include <vanetza/asn1/its/' + inc + '.h>' for inc in include]) + """

using namespace rapidjson;

Value to_json(const ETSI_ITS_CDD_TimestampIts_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, ETSI_ITS_CDD_TimestampIts_t& p, std::string field);
Value to_json(const ITS_Container_TimestampIts_t& p, Document::AllocatorType& allocator);
void from_json(const Value& j, ITS_Container_TimestampIts_t& p, std::string field);
Value to_json(const long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long& p, std::string field);
Value to_json(const unsigned long& p, Document::AllocatorType& allocator);
void from_json(const Value& j, long* p, std::string field);
Value to_json(const unsigned long* p, Document::AllocatorType& allocator);
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
"""

name_counts = {}
duplicate_printed = []

if sys.argv[1] == "hpp":
    print(header_intro)
else:
    print(intro)

b = len(printed)

# TODO: Replace with better algorithm when there's time
# for i in range(10):
#while len(printed) + initial_len != len(asn1_types) + b:
for t in asn1_types:
    if t.name in name_counts and t.name not in printed and t.parent_name not in ["DSRC-REGION-noCircular"] and t.name not in ["Acceleration3dWithConfidence"]:
        name_counts[t.name] += 1
    else:
        name_counts[t.name] = 1
for t in asn1_types:
    if name_counts[t.name] > 1:
        if "Steering" in t.name:
            pass
        t.print_name = t.parent_name.replace("-", "_") + "_" + t.name
while any([printed.count(t.name) < name_counts[t.name] for t in asn1_types]):
    for t in asn1_types:
        if printed.count(t.name) < name_counts[t.name] and t.print_name not in duplicate_printed and (t.definition["type"] in ["BIT STRING", "OCTET STRING", "NumericString", "UTF8String", "IA5String", 
                                                                "CLASS", "VisibleString"] 
            or all([d["type"] in printed + default_types for d in t.members])):
            if t.definition["type"] not in ["OCTET STRING", "UTF8String", "VisibleString"]:
                #pass
                print(t.header_str() if sys.argv[1] == "hpp" else t)
            printed.append(t.name)
            if t.print_name != t.name:
                duplicate_printed.append(t.print_name)
        #elif printed.count(t.name) < name_counts[t.name]:
            #print(t.name + " " + t.definition["type"])
            ##print(all([d["type"] in printed + default_types for d in t.members]))
            #print([d["type"] for d in t.members if d["type"] not in printed + default_types])
    #print('\n\n\n\n')
    ##print([(t.name, printed.count(t.name), name_counts[t.name]) for t in asn1_types if printed.count(t.name) < name_counts[t.name]])
    #time.sleep(1)

if sys.argv[1] == "hpp":
    print("\n#endif")
