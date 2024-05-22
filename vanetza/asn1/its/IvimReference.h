/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IvimReference_H_
#define	_IvimReference_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_Provider.h"
#include "ETSI-ITS-CDD_IviIdentificationNumber.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IvimReference */
typedef struct IvimReference {
	ETSI_ITS_CDD_Provider_t	 serviceProviderId;
	ETSI_ITS_CDD_IviIdentificationNumber_t	 iviIdentificationNumber;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IvimReference_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IvimReference;
extern asn_SEQUENCE_specifics_t asn_SPC_IvimReference_specs_1;
extern asn_TYPE_member_t asn_MBR_IvimReference_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _IvimReference_H_ */
#include "asn_internal.h"
