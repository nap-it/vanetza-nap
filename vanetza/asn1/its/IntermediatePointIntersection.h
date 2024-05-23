/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IntermediatePointIntersection_H_
#define	_IntermediatePointIntersection_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_Heading.h"
#include "TimeOfPos.h"
#include "ETSI-ITS-CDD_LanePosition.h"
#include "LaneCount.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IntermediatePointIntersection */
typedef struct IntermediatePointIntersection {
	struct IntermediatePointIntersection__exitLane {
		ETSI_ITS_CDD_LanePosition_t	 lanePosition;
		LaneCount_t	 laneCount;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} exitLane;
	ETSI_ITS_CDD_Heading_t	 exitHeading;
	TimeOfPos_t	 timeOfPosEntry;
	TimeOfPos_t	 timeOfPosExit;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IntermediatePointIntersection_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IntermediatePointIntersection;
extern asn_SEQUENCE_specifics_t asn_SPC_IntermediatePointIntersection_specs_1;
extern asn_TYPE_member_t asn_MBR_IntermediatePointIntersection_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _IntermediatePointIntersection_H_ */
#include "asn_internal.h"
