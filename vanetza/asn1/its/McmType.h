/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_McmType_H_
#define	_McmType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum McmType {
	McmType_intent	= 0,
	McmType_request	= 1,
	McmType_response	= 2,
	McmType_reservation	= 3,
	McmType_termination	= 4,
	McmType_cancellationRequest	= 5,
	McmType_emergencymaneuverReservation	= 6,
	McmType_executionStatus	= 7,
	McmType_offer	= 8,
	McmType_ack	= 9
} e_McmType;

/* McmType */
typedef long	 McmType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_McmType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_McmType;
extern const asn_INTEGER_specifics_t asn_SPC_McmType_specs_1;
asn_struct_free_f McmType_free;
asn_struct_print_f McmType_print;
asn_constr_check_f McmType_constraint;
ber_type_decoder_f McmType_decode_ber;
der_type_encoder_f McmType_encode_der;
xer_type_decoder_f McmType_decode_xer;
xer_type_encoder_f McmType_encode_xer;
jer_type_encoder_f McmType_encode_jer;
oer_type_decoder_f McmType_decode_oer;
oer_type_encoder_f McmType_encode_oer;
per_type_decoder_f McmType_decode_uper;
per_type_encoder_f McmType_encode_uper;
per_type_decoder_f McmType_decode_aper;
per_type_encoder_f McmType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _McmType_H_ */
#include "asn_internal.h"
