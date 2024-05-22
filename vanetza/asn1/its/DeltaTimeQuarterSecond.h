/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DeltaTimeQuarterSecond_H_
#define	_DeltaTimeQuarterSecond_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DeltaTimeQuarterSecond {
	DeltaTimeQuarterSecond_unavailable	= 255
} e_DeltaTimeQuarterSecond;

/* DeltaTimeQuarterSecond */
typedef long	 DeltaTimeQuarterSecond_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DeltaTimeQuarterSecond_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DeltaTimeQuarterSecond;
asn_struct_free_f DeltaTimeQuarterSecond_free;
asn_struct_print_f DeltaTimeQuarterSecond_print;
asn_constr_check_f DeltaTimeQuarterSecond_constraint;
ber_type_decoder_f DeltaTimeQuarterSecond_decode_ber;
der_type_encoder_f DeltaTimeQuarterSecond_encode_der;
xer_type_decoder_f DeltaTimeQuarterSecond_decode_xer;
xer_type_encoder_f DeltaTimeQuarterSecond_encode_xer;
jer_type_encoder_f DeltaTimeQuarterSecond_encode_jer;
oer_type_decoder_f DeltaTimeQuarterSecond_decode_oer;
oer_type_encoder_f DeltaTimeQuarterSecond_encode_oer;
per_type_decoder_f DeltaTimeQuarterSecond_decode_uper;
per_type_encoder_f DeltaTimeQuarterSecond_encode_uper;
per_type_decoder_f DeltaTimeQuarterSecond_decode_aper;
per_type_encoder_f DeltaTimeQuarterSecond_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _DeltaTimeQuarterSecond_H_ */
#include "asn_internal.h"
