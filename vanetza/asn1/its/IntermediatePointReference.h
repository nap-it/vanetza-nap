/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IntermediatePointReference_H_
#define	_IntermediatePointReference_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ReferenceStartingPosition.h"
#include "ETSI-ITS-CDD_Heading.h"
#include "Lane.h"
#include "TimeOfPos.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IntermediatePointReference */
typedef struct IntermediatePointReference {
	ReferenceStartingPosition_t	 referenceStartingPosition;
	ETSI_ITS_CDD_Heading_t	 referenceHeading;
	Lane_t	 lane;
	TimeOfPos_t	 timeOfPos;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IntermediatePointReference_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IntermediatePointReference;
extern asn_SEQUENCE_specifics_t asn_SPC_IntermediatePointReference_specs_1;
extern asn_TYPE_member_t asn_MBR_IntermediatePointReference_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _IntermediatePointReference_H_ */
#include "asn_internal.h"
