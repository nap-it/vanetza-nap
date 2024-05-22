/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_MitigationPerTechnologyClass_H_
#define	_ETSI_ITS_CDD_MitigationPerTechnologyClass_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_AccessTechnologyClass.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_MitigationPerTechnologyClass */
typedef struct ETSI_ITS_CDD_MitigationPerTechnologyClass {
	ETSI_ITS_CDD_AccessTechnologyClass_t	 accessTechnologyClass;
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
} ETSI_ITS_CDD_MitigationPerTechnologyClass_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_MitigationPerTechnologyClass;
extern asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_MitigationPerTechnologyClass_specs_1;
extern asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_MitigationPerTechnologyClass_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_MitigationPerTechnologyClass_H_ */
#include "asn_internal.h"
