/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_EFC_ContextMark_H_
#define	_EFC_ContextMark_H_


#include "asn_application.h"

/* Including external dependencies */
#include "EfcDsrcApplication_Provider.h"
#include "OCTET_STRING.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EFC-ContextMark */
typedef struct EFC_ContextMark {
	EfcDsrcApplication_Provider_t	 contractProvider;
	OCTET_STRING_t	 typeOfContract;
	long	 contextVersion;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} EFC_ContextMark_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EFC_ContextMark;

#ifdef __cplusplus
}
#endif

#endif	/* _EFC_ContextMark_H_ */
#include "asn_internal.h"
