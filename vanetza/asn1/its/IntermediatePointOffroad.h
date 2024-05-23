/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IntermediatePointOffroad_H_
#define	_IntermediatePointOffroad_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_ReferencePosition.h"
#include "ETSI-ITS-CDD_Heading.h"
#include "TimeOfPos.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IntermediatePointOffroad */
typedef struct IntermediatePointOffroad {
	ETSI_ITS_CDD_ReferencePosition_t	 referencePosition;
	ETSI_ITS_CDD_Heading_t	 referenceHeading;
	TimeOfPos_t	 timeOfPos;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IntermediatePointOffroad_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IntermediatePointOffroad;
extern asn_SEQUENCE_specifics_t asn_SPC_IntermediatePointOffroad_specs_1;
extern asn_TYPE_member_t asn_MBR_IntermediatePointOffroad_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _IntermediatePointOffroad_H_ */
#include "asn_internal.h"
