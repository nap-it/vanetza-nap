/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PurseBalance_H_
#define	_PurseBalance_H_


#include "asn_application.h"

/* Including external dependencies */
#include "SignedValue.h"
#include "PayUnit.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PurseBalance */
typedef struct PurseBalance {
	SignedValue_t	 purseValue;
	PayUnit_t	 purseUnit;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PurseBalance_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PurseBalance;
extern asn_SEQUENCE_specifics_t asn_SPC_PurseBalance_specs_1;
extern asn_TYPE_member_t asn_MBR_PurseBalance_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _PurseBalance_H_ */
#include "asn_internal.h"
