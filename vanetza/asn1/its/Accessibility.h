/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Accessibility_H_
#define	_Accessibility_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UTF8String.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Accessibility */
typedef UTF8String_t	 Accessibility_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Accessibility_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Accessibility;
asn_struct_free_f Accessibility_free;
asn_struct_print_f Accessibility_print;
asn_constr_check_f Accessibility_constraint;
ber_type_decoder_f Accessibility_decode_ber;
der_type_encoder_f Accessibility_encode_der;
xer_type_decoder_f Accessibility_decode_xer;
xer_type_encoder_f Accessibility_encode_xer;
oer_type_decoder_f Accessibility_decode_oer;
oer_type_encoder_f Accessibility_encode_oer;
per_type_decoder_f Accessibility_decode_uper;
per_type_encoder_f Accessibility_encode_uper;
per_type_decoder_f Accessibility_decode_aper;
per_type_encoder_f Accessibility_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Accessibility_H_ */
#include "asn_internal.h"