/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ChannelRs_H_
#define	_ChannelRs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ChannelId.h"
#include "OCTET_STRING.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ChannelRs */
typedef struct ChannelRs {
	ChannelId_t	 channelId;
	OCTET_STRING_t	 apdu;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ChannelRs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChannelRs;

#ifdef __cplusplus
}
#endif

#endif	/* _ChannelRs_H_ */
#include "asn_internal.h"
