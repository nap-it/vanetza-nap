/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ReceiptContract_H_
#define	_ReceiptContract_H_


#include "asn_application.h"

/* Including external dependencies */
#include "EfcDsrcApplication_Provider.h"
#include "OCTET_STRING.h"
#include "Int4.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ReceiptContract */
typedef struct ReceiptContract {
	EfcDsrcApplication_Provider_t	 sessionContractProvider;
	OCTET_STRING_t	 sessionTypeOfContract;
	Int4_t	 sessionContractSerialNumber;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReceiptContract_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReceiptContract;

#ifdef __cplusplus
}
#endif

#endif	/* _ReceiptContract_H_ */
#include "asn_internal.h"
