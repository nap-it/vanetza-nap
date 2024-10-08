/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_GetInstanceRq_H_
#define	_GetInstanceRq_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "AttributeIdList.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* GetInstanceRq */
typedef struct GetInstanceRq {
	long	 posOfFirstInstance;
	long	 posOfLastInstance;
	AttributeIdList_t	 attributeIdList;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetInstanceRq_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetInstanceRq;

#ifdef __cplusplus
}
#endif

#endif	/* _GetInstanceRq_H_ */
#include "asn_internal.h"
