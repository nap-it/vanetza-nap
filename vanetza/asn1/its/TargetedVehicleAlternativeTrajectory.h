/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TargetedVehicleAlternativeTrajectory_H_
#define	_TargetedVehicleAlternativeTrajectory_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Trajectory.h"
#include "Lane.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TargetedVehicleAlternativeTrajectory */
typedef struct TargetedVehicleAlternativeTrajectory {
	Trajectory_t	 alternativeTrajectory;
	Lane_t	 lane;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TargetedVehicleAlternativeTrajectory_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TargetedVehicleAlternativeTrajectory;
extern asn_SEQUENCE_specifics_t asn_SPC_TargetedVehicleAlternativeTrajectory_specs_1;
extern asn_TYPE_member_t asn_MBR_TargetedVehicleAlternativeTrajectory_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _TargetedVehicleAlternativeTrajectory_H_ */
#include "asn_internal.h"
