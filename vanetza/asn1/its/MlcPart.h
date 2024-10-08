/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_MlcPart_H_
#define	_MlcPart_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Zid.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct LaneIds;

/* MlcPart */
typedef struct MlcPart {
	Zid_t	 zoneId;
	struct LaneIds	*laneIds;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MlcPart_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MlcPart;
extern asn_SEQUENCE_specifics_t asn_SPC_MlcPart_specs_1;
extern asn_TYPE_member_t asn_MBR_MlcPart_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LaneIds.h"

#endif	/* _MlcPart_H_ */
#include "asn_internal.h"
