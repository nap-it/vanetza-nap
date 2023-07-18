/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "/home/rrosmaninho/vanetza/asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R -D /home/rrosmaninho/vanetza/vanetza/asn1/its`
 */

#ifndef	_SupportedPaymentTypes_H_
#define	_SupportedPaymentTypes_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SupportedPaymentTypes {
	SupportedPaymentTypes_contract	= 0,
	SupportedPaymentTypes_externalIdentification	= 1
} e_SupportedPaymentTypes;

/* SupportedPaymentTypes */
typedef BIT_STRING_t	 SupportedPaymentTypes_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SupportedPaymentTypes_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SupportedPaymentTypes;
asn_struct_free_f SupportedPaymentTypes_free;
asn_struct_print_f SupportedPaymentTypes_print;
asn_constr_check_f SupportedPaymentTypes_constraint;
ber_type_decoder_f SupportedPaymentTypes_decode_ber;
der_type_encoder_f SupportedPaymentTypes_encode_der;
xer_type_decoder_f SupportedPaymentTypes_decode_xer;
xer_type_encoder_f SupportedPaymentTypes_encode_xer;
oer_type_decoder_f SupportedPaymentTypes_decode_oer;
oer_type_encoder_f SupportedPaymentTypes_encode_oer;
per_type_decoder_f SupportedPaymentTypes_decode_uper;
per_type_encoder_f SupportedPaymentTypes_encode_uper;
per_type_decoder_f SupportedPaymentTypes_decode_aper;
per_type_encoder_f SupportedPaymentTypes_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedPaymentTypes_H_ */
#include "asn_internal.h"
