/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_NumberOfAppliedPressure_H_
#define	_NumberOfAppliedPressure_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NumberOfAppliedPressure {
	NumberOfAppliedPressure_oneAppliedPressure	= 1,
	NumberOfAppliedPressure_twoAppliedPressure	= 2
} e_NumberOfAppliedPressure;

/* NumberOfAppliedPressure */
typedef long	 NumberOfAppliedPressure_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NumberOfAppliedPressure_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NumberOfAppliedPressure;
asn_struct_free_f NumberOfAppliedPressure_free;
asn_struct_print_f NumberOfAppliedPressure_print;
asn_constr_check_f NumberOfAppliedPressure_constraint;
ber_type_decoder_f NumberOfAppliedPressure_decode_ber;
der_type_encoder_f NumberOfAppliedPressure_encode_der;
xer_type_decoder_f NumberOfAppliedPressure_decode_xer;
xer_type_encoder_f NumberOfAppliedPressure_encode_xer;
jer_type_encoder_f NumberOfAppliedPressure_encode_jer;
oer_type_decoder_f NumberOfAppliedPressure_decode_oer;
oer_type_encoder_f NumberOfAppliedPressure_encode_oer;
per_type_decoder_f NumberOfAppliedPressure_decode_uper;
per_type_encoder_f NumberOfAppliedPressure_encode_uper;
per_type_decoder_f NumberOfAppliedPressure_decode_aper;
per_type_encoder_f NumberOfAppliedPressure_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NumberOfAppliedPressure_H_ */
#include "asn_internal.h"
