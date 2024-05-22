/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_MessageSegmentationInfo_H_
#define	_MessageSegmentationInfo_H_


#include "asn_application.h"

/* Including external dependencies */
#include "CardinalNumber3b.h"
#include "OrdinalNumber3b.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* MessageSegmentationInfo */
typedef struct MessageSegmentationInfo {
	CardinalNumber3b_t	 totalMsgNo;
	OrdinalNumber3b_t	 thisMsgNo;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MessageSegmentationInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageSegmentationInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_MessageSegmentationInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_MessageSegmentationInfo_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _MessageSegmentationInfo_H_ */
#include "asn_internal.h"
