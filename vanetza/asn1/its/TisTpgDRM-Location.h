/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgDRM_Location_H_
#define	_TisTpgDRM_Location_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ReferencePosition.h"
#include "Speed.h"
#include "Heading.h"
#include "SearchRange.h"
#include "SearchCondition.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ReferencePosition;

/* TisTpgDRM-Location */
typedef struct TisTpgDRM_Location {
	ReferencePosition_t	 vehiclePosition;
	Speed_t	 vehicleSpeed;
	Heading_t	 vehicleHeading;
	struct ReferencePosition	*requestedPosition;	/* OPTIONAL */
	SearchRange_t	*searchRange;	/* OPTIONAL */
	SearchCondition_t	*searchCondition;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgDRM_Location_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgDRM_Location;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgDRM_Location_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgDRM_Location_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ReferencePosition.h"

#endif	/* _TisTpgDRM_Location_H_ */
#include "asn_internal.h"
