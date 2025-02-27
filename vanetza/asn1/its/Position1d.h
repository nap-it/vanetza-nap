/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Position1d_H_
#define	_Position1d_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Position1d {
	Position1d_outOfRange	= 8190,
	Position1d_unavailable	= 8191
} e_Position1d;

/* Position1d */
typedef long	 Position1d_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Position1d_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Position1d;
asn_struct_free_f Position1d_free;
asn_struct_print_f Position1d_print;
asn_constr_check_f Position1d_constraint;
ber_type_decoder_f Position1d_decode_ber;
der_type_encoder_f Position1d_encode_der;
xer_type_decoder_f Position1d_decode_xer;
xer_type_encoder_f Position1d_encode_xer;
jer_type_encoder_f Position1d_encode_jer;
oer_type_decoder_f Position1d_decode_oer;
oer_type_encoder_f Position1d_encode_oer;
per_type_decoder_f Position1d_decode_uper;
per_type_encoder_f Position1d_encode_uper;
per_type_decoder_f Position1d_decode_aper;
per_type_encoder_f Position1d_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Position1d_H_ */
#include "asn_internal.h"
