/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DeclineReason_H_
#define	_DeclineReason_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DeclineReason {
	DeclineReason_agreementSeekingUnknown	= 0,
	DeclineReason_allUnableToConform	= 1,
	DeclineReason_agreementSeekingUnwanted	= 2,
	DeclineReason_allUnableToUnderstand	= 3,
	DeclineReason_allErroneousBehaviourDetected	= 4,
	DeclineReason_allMissbehaviourDetected	= 5,
	DeclineReason_agreementSeekingManoeuvreCancellationRequestIssued	= 6
} e_DeclineReason;

/* DeclineReason */
typedef long	 DeclineReason_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DeclineReason_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DeclineReason;
extern const asn_INTEGER_specifics_t asn_SPC_DeclineReason_specs_1;
asn_struct_free_f DeclineReason_free;
asn_struct_print_f DeclineReason_print;
asn_constr_check_f DeclineReason_constraint;
ber_type_decoder_f DeclineReason_decode_ber;
der_type_encoder_f DeclineReason_encode_der;
xer_type_decoder_f DeclineReason_decode_xer;
xer_type_encoder_f DeclineReason_encode_xer;
jer_type_encoder_f DeclineReason_encode_jer;
oer_type_decoder_f DeclineReason_decode_oer;
oer_type_encoder_f DeclineReason_encode_oer;
per_type_decoder_f DeclineReason_decode_uper;
per_type_encoder_f DeclineReason_encode_uper;
per_type_decoder_f DeclineReason_decode_aper;
per_type_encoder_f DeclineReason_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _DeclineReason_H_ */
#include "asn_internal.h"
