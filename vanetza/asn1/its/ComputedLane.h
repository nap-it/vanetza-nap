/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "iso/ISO19091.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ComputedLane_H_
#define	_ComputedLane_H_


#include "asn_application.h"

/* Including external dependencies */
#include "LaneID.h"
#include "Angle.h"
#include "Scale-B12.h"
#include "DrivenLineOffsetSm.h"
#include "DrivenLineOffsetLg.h"
#include "constr_CHOICE.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ComputedLane__offsetXaxis_PR {
	ComputedLane__offsetXaxis_PR_NOTHING,	/* No components present */
	ComputedLane__offsetXaxis_PR_small,
	ComputedLane__offsetXaxis_PR_large
} ComputedLane__offsetXaxis_PR;
typedef enum ComputedLane__offsetYaxis_PR {
	ComputedLane__offsetYaxis_PR_NOTHING,	/* No components present */
	ComputedLane__offsetYaxis_PR_small,
	ComputedLane__offsetYaxis_PR_large
} ComputedLane__offsetYaxis_PR;

/* Forward declarations */
struct Reg_ComputedLane;

/* ComputedLane */
typedef struct ComputedLane {
	LaneID_t	 referenceLaneId;
	struct ComputedLane__offsetXaxis {
		ComputedLane__offsetXaxis_PR present;
		union ComputedLane__offsetXaxis_u {
			DrivenLineOffsetSm_t	 small;
			DrivenLineOffsetLg_t	 large;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} offsetXaxis;
	struct ComputedLane__offsetYaxis {
		ComputedLane__offsetYaxis_PR present;
		union ComputedLane__offsetYaxis_u {
			DrivenLineOffsetSm_t	 small;
			DrivenLineOffsetLg_t	 large;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} offsetYaxis;
	Angle_t	*rotateXY;	/* OPTIONAL */
	Scale_B12_t	*scaleXaxis;	/* OPTIONAL */
	Scale_B12_t	*scaleYaxis;	/* OPTIONAL */
	struct ComputedLane__regional {
		A_SEQUENCE_OF(struct Reg_ComputedLane) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *regional;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ComputedLane_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ComputedLane;
extern asn_SEQUENCE_specifics_t asn_SPC_ComputedLane_specs_1;
extern asn_TYPE_member_t asn_MBR_ComputedLane_1[7];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RegionalExtension.h"

#endif	/* _ComputedLane_H_ */
#include "asn_internal.h"
