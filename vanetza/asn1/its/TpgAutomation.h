/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TpgAutomation_H_
#define	_TpgAutomation_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TpgAutomation {
	TpgAutomation_fullAutomated	= 0,
	TpgAutomation_semiAutomated	= 1,
	TpgAutomation_manual	= 2,
	TpgAutomation_reserved	= 3
} e_TpgAutomation;

/* TpgAutomation */
typedef BIT_STRING_t	 TpgAutomation_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TpgAutomation_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TpgAutomation;
asn_struct_free_f TpgAutomation_free;
asn_struct_print_f TpgAutomation_print;
asn_constr_check_f TpgAutomation_constraint;
ber_type_decoder_f TpgAutomation_decode_ber;
der_type_encoder_f TpgAutomation_encode_der;
xer_type_decoder_f TpgAutomation_decode_xer;
xer_type_encoder_f TpgAutomation_encode_xer;
jer_type_encoder_f TpgAutomation_encode_jer;
oer_type_decoder_f TpgAutomation_decode_oer;
oer_type_encoder_f TpgAutomation_encode_oer;
per_type_decoder_f TpgAutomation_decode_uper;
per_type_encoder_f TpgAutomation_encode_uper;
per_type_decoder_f TpgAutomation_decode_aper;
per_type_encoder_f TpgAutomation_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TpgAutomation_H_ */
#include "asn_internal.h"
