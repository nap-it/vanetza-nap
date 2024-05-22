/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AnyCatalogue_H_
#define	_AnyCatalogue_H_


#include "asn_application.h"

/* Including external dependencies */
#include "EfcDsrcApplication_Provider.h"
#include "NativeInteger.h"
#include "RSCUnit.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ISO14823Attributes;

/* AnyCatalogue */
typedef struct AnyCatalogue {
	EfcDsrcApplication_Provider_t	 owner;
	long	 version;
	long	 pictogramCode;
	long	*value;	/* OPTIONAL */
	RSCUnit_t	*unit;	/* OPTIONAL */
	struct ISO14823Attributes	*attributes;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AnyCatalogue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AnyCatalogue;
extern asn_SEQUENCE_specifics_t asn_SPC_AnyCatalogue_specs_1;
extern asn_TYPE_member_t asn_MBR_AnyCatalogue_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ISO14823Attributes.h"

#endif	/* _AnyCatalogue_H_ */
#include "asn_internal.h"
