/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Response_H_
#define	_Response_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Response {
	Response_denied	= 0,
	Response_accepted	= 1
} e_Response;

/* Response */
typedef long	 Response_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Response_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Response;
extern const asn_INTEGER_specifics_t asn_SPC_Response_specs_1;
asn_struct_free_f Response_free;
asn_struct_print_f Response_print;
asn_constr_check_f Response_constraint;
ber_type_decoder_f Response_decode_ber;
der_type_encoder_f Response_encode_der;
xer_type_decoder_f Response_decode_xer;
xer_type_encoder_f Response_encode_xer;
jer_type_encoder_f Response_encode_jer;
oer_type_decoder_f Response_decode_oer;
oer_type_encoder_f Response_encode_oer;
per_type_decoder_f Response_decode_uper;
per_type_encoder_f Response_encode_uper;
per_type_decoder_f Response_decode_aper;
per_type_encoder_f Response_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Response_H_ */
#include "asn_internal.h"
