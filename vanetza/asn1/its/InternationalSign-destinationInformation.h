/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_InternationalSign_destinationInformation_H_
#define	_InternationalSign_destinationInformation_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DDD_IO_LIST;

/* InternationalSign-destinationInformation */
typedef struct InternationalSign_destinationInformation {
	long	*junctionDirection;	/* OPTIONAL */
	long	*roundaboutCwDirection;	/* OPTIONAL */
	long	*roundaboutCcwDirection;	/* OPTIONAL */
	struct DDD_IO_LIST	*ioList;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InternationalSign_destinationInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InternationalSign_destinationInformation;
extern asn_SEQUENCE_specifics_t asn_SPC_InternationalSign_destinationInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_InternationalSign_destinationInformation_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DDD-IO-LIST.h"

#endif	/* _InternationalSign_destinationInformation_H_ */
#include "asn_internal.h"
