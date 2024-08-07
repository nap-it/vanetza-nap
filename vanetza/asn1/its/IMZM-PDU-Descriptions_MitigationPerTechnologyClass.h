/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IMZM-PDU-Descriptions"
 * 	found in "asn1/IMZM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IMZM_PDU_Descriptions_MitigationPerTechnologyClass_H_
#define	_IMZM_PDU_Descriptions_MitigationPerTechnologyClass_H_


#include "asn_application.h"

/* Including external dependencies */
#include "IMZM-PDU-Descriptions_AccessTechnologyClass.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IMZM-PDU-Descriptions_MitigationPerTechnologyClass */
typedef struct IMZM_PDU_Descriptions_MitigationPerTechnologyClass {
	IMZM_PDU_Descriptions_AccessTechnologyClass_t	 accessTechnologyClass;
	long	*lowDutyCycle;	/* OPTIONAL */
	long	*powerReduction;	/* OPTIONAL */
	long	*dmcToffLimit;	/* OPTIONAL */
	long	*dmcTonLimit;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IMZM_PDU_Descriptions_MitigationPerTechnologyClass_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IMZM_PDU_Descriptions_MitigationPerTechnologyClass;
extern asn_SEQUENCE_specifics_t asn_SPC_IMZM_PDU_Descriptions_MitigationPerTechnologyClass_specs_1;
extern asn_TYPE_member_t asn_MBR_IMZM_PDU_Descriptions_MitigationPerTechnologyClass_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _IMZM_PDU_Descriptions_MitigationPerTechnologyClass_H_ */
#include "asn_internal.h"
