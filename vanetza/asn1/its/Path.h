/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Path_H_
#define	_Path_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ETSI_ITS_CDD_PathPoint;

/* Path */
typedef struct Path {
	A_SEQUENCE_OF(struct ETSI_ITS_CDD_PathPoint) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Path_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Path;
extern asn_SET_OF_specifics_t asn_SPC_Path_specs_1;
extern asn_TYPE_member_t asn_MBR_Path_1[1];
extern asn_per_constraints_t asn_PER_type_Path_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ETSI-ITS-CDD_PathPoint.h"

#endif	/* _Path_H_ */
#include "asn_internal.h"
