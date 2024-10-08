/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ValidityPeriods_H_
#define	_ValidityPeriods_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct InternationalSign_applicablePeriod;

/* ValidityPeriods */
typedef struct ValidityPeriods {
	A_SEQUENCE_OF(struct InternationalSign_applicablePeriod) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ValidityPeriods_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ValidityPeriods;
extern asn_SET_OF_specifics_t asn_SPC_ValidityPeriods_specs_1;
extern asn_TYPE_member_t asn_MBR_ValidityPeriods_1[1];
extern asn_per_constraints_t asn_PER_type_ValidityPeriods_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "InternationalSign-applicablePeriod.h"

#endif	/* _ValidityPeriods_H_ */
#include "asn_internal.h"
