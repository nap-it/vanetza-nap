/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AddRq_H_
#define	_AddRq_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AddRq */
typedef struct AddRq {
	long	 attributeId;
	long	 value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AddRq_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AddRq;

#ifdef __cplusplus
}
#endif

#endif	/* _AddRq_H_ */
#include "asn_internal.h"
