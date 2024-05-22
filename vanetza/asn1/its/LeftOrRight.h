/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_LeftOrRight_H_
#define	_LeftOrRight_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LeftOrRight {
	LeftOrRight_left	= 0,
	LeftOrRight_right	= 1
} e_LeftOrRight;

/* LeftOrRight */
typedef long	 LeftOrRight_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_LeftOrRight_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_LeftOrRight;
extern const asn_INTEGER_specifics_t asn_SPC_LeftOrRight_specs_1;
asn_struct_free_f LeftOrRight_free;
asn_struct_print_f LeftOrRight_print;
asn_constr_check_f LeftOrRight_constraint;
ber_type_decoder_f LeftOrRight_decode_ber;
der_type_encoder_f LeftOrRight_encode_der;
xer_type_decoder_f LeftOrRight_decode_xer;
xer_type_encoder_f LeftOrRight_encode_xer;
jer_type_encoder_f LeftOrRight_encode_jer;
oer_type_decoder_f LeftOrRight_decode_oer;
oer_type_encoder_f LeftOrRight_encode_oer;
per_type_decoder_f LeftOrRight_decode_uper;
per_type_encoder_f LeftOrRight_encode_uper;
per_type_decoder_f LeftOrRight_decode_aper;
per_type_encoder_f LeftOrRight_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _LeftOrRight_H_ */
#include "asn_internal.h"
