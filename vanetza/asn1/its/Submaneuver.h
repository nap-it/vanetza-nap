/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Submaneuver_H_
#define	_Submaneuver_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "Wgs84TrajectoryPoint.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Submaneuver__trajectoryPoint_PR {
	Submaneuver__trajectoryPoint_PR_NOTHING,	/* No components present */
	Submaneuver__trajectoryPoint_PR_wgs84TrajectoryPoint
} Submaneuver__trajectoryPoint_PR;

/* Submaneuver */
typedef struct Submaneuver {
	long	 submaneuverId;
	struct Submaneuver__trajectoryPoint {
		Submaneuver__trajectoryPoint_PR present;
		union Submaneuver__trajectoryPoint_u {
			Wgs84TrajectoryPoint_t	 wgs84TrajectoryPoint;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} trajectoryPoint;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Submaneuver_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Submaneuver;
extern asn_SEQUENCE_specifics_t asn_SPC_Submaneuver_specs_1;
extern asn_TYPE_member_t asn_MBR_Submaneuver_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Submaneuver_H_ */
#include "asn_internal.h"
