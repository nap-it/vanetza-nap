/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgTCM_Location_H_
#define	_TisTpgTCM_Location_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UTF8String.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ReferencePosition;

/* TisTpgTCM-Location */
typedef struct TisTpgTCM_Location {
	struct ReferencePosition	*tpgLocation;	/* OPTIONAL */
	UTF8String_t	*address;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgTCM_Location_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgTCM_Location;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgTCM_Location_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgTCM_Location_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ReferencePosition.h"

#endif	/* _TisTpgTCM_Location_H_ */
#include "asn_internal.h"
