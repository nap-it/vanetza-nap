/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_StandardLength3b_H_
#define	_StandardLength3b_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StandardLength3b {
	StandardLength3b_lessThan50m	= 0,
	StandardLength3b_lessThan100m	= 1,
	StandardLength3b_lessThan200m	= 2,
	StandardLength3b_lessThan500m	= 3,
	StandardLength3b_lessThan1000m	= 4,
	StandardLength3b_lessThan5km	= 5,
	StandardLength3b_lessThan10km	= 6,
	StandardLength3b_over10km	= 7
} e_StandardLength3b;

/* StandardLength3b */
typedef long	 StandardLength3b_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_StandardLength3b;
asn_struct_free_f StandardLength3b_free;
asn_struct_print_f StandardLength3b_print;
asn_constr_check_f StandardLength3b_constraint;
ber_type_decoder_f StandardLength3b_decode_ber;
der_type_encoder_f StandardLength3b_encode_der;
xer_type_decoder_f StandardLength3b_decode_xer;
xer_type_encoder_f StandardLength3b_encode_xer;
jer_type_encoder_f StandardLength3b_encode_jer;
oer_type_decoder_f StandardLength3b_decode_oer;
oer_type_encoder_f StandardLength3b_encode_oer;
per_type_decoder_f StandardLength3b_decode_uper;
per_type_encoder_f StandardLength3b_encode_uper;
per_type_decoder_f StandardLength3b_decode_aper;
per_type_encoder_f StandardLength3b_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _StandardLength3b_H_ */
#include "asn_internal.h"
