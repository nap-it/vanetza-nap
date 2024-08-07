/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PDU-Descriptions"
 * 	found in "asn1/CPM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_MessageRateRange_H_
#define	_MessageRateRange_H_


#include "asn_application.h"

/* Including external dependencies */
#include "MessageRateHz.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* MessageRateRange */
typedef struct MessageRateRange {
	MessageRateHz_t	 messageRateMin;
	MessageRateHz_t	 messageRateMax;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MessageRateRange_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageRateRange;
extern asn_SEQUENCE_specifics_t asn_SPC_MessageRateRange_specs_1;
extern asn_TYPE_member_t asn_MBR_MessageRateRange_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _MessageRateRange_H_ */
#include "asn_internal.h"
