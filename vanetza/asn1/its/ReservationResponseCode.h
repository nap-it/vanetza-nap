/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ReservationResponseCode_H_
#define	_ReservationResponseCode_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ReservationResponseCode {
	ReservationResponseCode_ok	= 0,
	ReservationResponseCode_invalid_EVSE_ID	= 1,
	ReservationResponseCode_payment_type_not_supported	= 2,
	ReservationResponseCode_payment_error	= 3,
	ReservationResponseCode_authentication_error	= 4,
	ReservationResponseCode_insufficient_power_availability	= 5
} e_ReservationResponseCode;

/* ReservationResponseCode */
typedef long	 ReservationResponseCode_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ReservationResponseCode_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ReservationResponseCode;
extern const asn_INTEGER_specifics_t asn_SPC_ReservationResponseCode_specs_1;
asn_struct_free_f ReservationResponseCode_free;
asn_struct_print_f ReservationResponseCode_print;
asn_constr_check_f ReservationResponseCode_constraint;
ber_type_decoder_f ReservationResponseCode_decode_ber;
der_type_encoder_f ReservationResponseCode_encode_der;
xer_type_decoder_f ReservationResponseCode_decode_xer;
xer_type_encoder_f ReservationResponseCode_encode_xer;
jer_type_encoder_f ReservationResponseCode_encode_jer;
oer_type_decoder_f ReservationResponseCode_decode_oer;
oer_type_encoder_f ReservationResponseCode_encode_oer;
per_type_decoder_f ReservationResponseCode_decode_uper;
per_type_encoder_f ReservationResponseCode_encode_uper;
per_type_decoder_f ReservationResponseCode_decode_aper;
per_type_encoder_f ReservationResponseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ReservationResponseCode_H_ */
#include "asn_internal.h"
