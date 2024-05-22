/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IMZM-PDU-Descriptions"
 * 	found in "asn1/IMZM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ImzmParameters_H_
#define	_ImzmParameters_H_


#include "asn_application.h"

/* Including external dependencies */
#include "CAM-PDU-Descriptions_BasicContainer.h"
#include "ImzmContainer.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ImzmParameters */
typedef struct ImzmParameters {
	CAM_PDU_Descriptions_BasicContainer_t	 basicContainer;
	ImzmContainer_t	 imzmContainer;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ImzmParameters_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ImzmParameters;
extern asn_SEQUENCE_specifics_t asn_SPC_ImzmParameters_specs_1;
extern asn_TYPE_member_t asn_MBR_ImzmParameters_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _ImzmParameters_H_ */
#include "asn_internal.h"
