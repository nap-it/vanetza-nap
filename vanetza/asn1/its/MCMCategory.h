/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_MCMCategory_H_
#define	_MCMCategory_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MCMCategory {
	MCMCategory_request	= 0,
	MCMCategory_offer	= 1,
	MCMCategory_response	= 2,
	MCMCategory_progress	= 3,
	MCMCategory_cancelation	= 4,
	MCMCategory_termination	= 5
} e_MCMCategory;

/* MCMCategory */
typedef long	 MCMCategory_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_MCMCategory_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_MCMCategory;
extern const asn_INTEGER_specifics_t asn_SPC_MCMCategory_specs_1;
asn_struct_free_f MCMCategory_free;
asn_struct_print_f MCMCategory_print;
asn_constr_check_f MCMCategory_constraint;
ber_type_decoder_f MCMCategory_decode_ber;
der_type_encoder_f MCMCategory_encode_der;
xer_type_decoder_f MCMCategory_decode_xer;
xer_type_encoder_f MCMCategory_encode_xer;
oer_type_decoder_f MCMCategory_decode_oer;
oer_type_encoder_f MCMCategory_encode_oer;
per_type_decoder_f MCMCategory_decode_uper;
per_type_encoder_f MCMCategory_encode_uper;
per_type_decoder_f MCMCategory_decode_aper;
per_type_encoder_f MCMCategory_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _MCMCategory_H_ */
#include "asn_internal.h"
