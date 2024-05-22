/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_PathPoint_H_
#define	_ETSI_ITS_CDD_PathPoint_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_DeltaReferencePosition.h"
#include "ETSI-ITS-CDD_PathDeltaTime.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_PathPoint */
typedef struct ETSI_ITS_CDD_PathPoint {
	ETSI_ITS_CDD_DeltaReferencePosition_t	 pathPosition;
	ETSI_ITS_CDD_PathDeltaTime_t	*pathDeltaTime;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_PathPoint_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_PathPoint;
extern asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_PathPoint_specs_1;
extern asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_PathPoint_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_PathPoint_H_ */
#include "asn_internal.h"
