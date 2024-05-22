/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IviStatus_H_
#define	_IviStatus_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IviStatus {
	IviStatus_new	= 0,
	IviStatus_update	= 1,
	IviStatus_cancellation	= 2,
	IviStatus_negation	= 3
} e_IviStatus;

/* IviStatus */
typedef long	 IviStatus_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IviStatus_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IviStatus;
asn_struct_free_f IviStatus_free;
asn_struct_print_f IviStatus_print;
asn_constr_check_f IviStatus_constraint;
ber_type_decoder_f IviStatus_decode_ber;
der_type_encoder_f IviStatus_encode_der;
xer_type_decoder_f IviStatus_decode_xer;
xer_type_encoder_f IviStatus_encode_xer;
jer_type_encoder_f IviStatus_encode_jer;
oer_type_decoder_f IviStatus_decode_oer;
oer_type_encoder_f IviStatus_encode_oer;
per_type_decoder_f IviStatus_decode_uper;
per_type_encoder_f IviStatus_encode_uper;
per_type_decoder_f IviStatus_decode_aper;
per_type_encoder_f IviStatus_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _IviStatus_H_ */
#include "asn_internal.h"
