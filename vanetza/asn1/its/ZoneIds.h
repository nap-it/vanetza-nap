/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ZoneIds_H_
#define	_ZoneIds_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Zid.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ZoneIds */
typedef struct ZoneIds {
	A_SEQUENCE_OF(Zid_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ZoneIds_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ZoneIds;
extern asn_SET_OF_specifics_t asn_SPC_ZoneIds_specs_1;
extern asn_TYPE_member_t asn_MBR_ZoneIds_1[1];
extern asn_per_constraints_t asn_PER_type_ZoneIds_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ZoneIds_H_ */
#include "asn_internal.h"
