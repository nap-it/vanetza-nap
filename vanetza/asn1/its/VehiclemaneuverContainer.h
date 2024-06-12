/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VehiclemaneuverContainer_H_
#define	_VehiclemaneuverContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "McmType.h"
#include "ManeuverId.h"
#include "ManeuverCoordinationConcept.h"
#include "ManeuverCoordinationRational.h"
#include "VehicleCurrentState.h"
#include "ManeuverExecutionStatus.h"
#include "TrajectoryId.h"
#include "Wgs84Trajectory.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VehiclemaneuverContainer__vehicleTrajectory_PR {
	VehiclemaneuverContainer__vehicleTrajectory_PR_NOTHING,	/* No components present */
	VehiclemaneuverContainer__vehicleTrajectory_PR_wgs84Trajectory
} VehiclemaneuverContainer__vehicleTrajectory_PR;

/* Forward declarations */
struct ManeuverAdviceContainer;
struct ManeuverResponse;

/* VehiclemaneuverContainer */
typedef struct VehiclemaneuverContainer {
	McmType_t	 mcmType;
	ManeuverId_t	 maneuverId;
	ManeuverCoordinationConcept_t	 maneuverCoordinationConcept;
	ManeuverCoordinationRational_t	 maneuverCoordinationRational;
	VehicleCurrentState_t	 vehicleCurrentState;
	ManeuverExecutionStatus_t	*maneuverExecutionStatus;	/* OPTIONAL */
	TrajectoryId_t	 trajectoryId;
	struct VehiclemaneuverContainer__vehicleTrajectory {
		VehiclemaneuverContainer__vehicleTrajectory_PR present;
		union VehiclemaneuverContainer__vehicleTrajectory_u {
			Wgs84Trajectory_t	 wgs84Trajectory;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} vehicleTrajectory;
	struct ManeuverAdviceContainer	*maneuverAdviceContainer;	/* OPTIONAL */
	struct ManeuverResponse	*maneuverResponse;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VehiclemaneuverContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VehiclemaneuverContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_VehiclemaneuverContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_VehiclemaneuverContainer_1[10];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ManeuverAdviceContainer.h"
#include "ManeuverResponse.h"

#endif	/* _VehiclemaneuverContainer_H_ */
#include "asn_internal.h"
