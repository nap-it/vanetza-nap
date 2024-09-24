/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_EfcDsrcApplication_Provider_H_
#define	_EfcDsrcApplication_Provider_H_


#include "asn_application.h"

/* Including external dependencies */
#include "AVIAEINumberingAndDataStructures_CountryCode.h"
#include "IssuerIdentifierIso.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EfcDsrcApplication_Provider */
typedef struct EfcDsrcApplication_Provider {
	AVIAEINumberingAndDataStructures_CountryCode_t	 countryCode;
	IssuerIdentifierIso_t	 providerIdentifier;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EfcDsrcApplication_Provider_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EfcDsrcApplication_Provider;
extern asn_SEQUENCE_specifics_t asn_SPC_EfcDsrcApplication_Provider_specs_1;
extern asn_TYPE_member_t asn_MBR_EfcDsrcApplication_Provider_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _EfcDsrcApplication_Provider_H_ */
#include "asn_internal.h"