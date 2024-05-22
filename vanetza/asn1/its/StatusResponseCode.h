/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_StatusResponseCode_H_
#define	_StatusResponseCode_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StatusResponseCode {
	StatusResponseCode_charging_Spot_Occupied	= 0,
	StatusResponseCode_charging_Spot_Unoccupied	= 1,
	StatusResponseCode_charging_Ongoing	= 2,
	StatusResponseCode_reservation_Limit_Exceeded	= 3,
	StatusResponseCode_reservation_Cancelled	= 4,
	StatusResponseCode_unknown_Reservation_ID	= 5,
	StatusResponseCode_expired_Reservation_ID	= 6
} e_StatusResponseCode;

/* StatusResponseCode */
typedef long	 StatusResponseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_StatusResponseCode;
asn_struct_free_f StatusResponseCode_free;
asn_struct_print_f StatusResponseCode_print;
asn_constr_check_f StatusResponseCode_constraint;
ber_type_decoder_f StatusResponseCode_decode_ber;
der_type_encoder_f StatusResponseCode_encode_der;
xer_type_decoder_f StatusResponseCode_decode_xer;
xer_type_encoder_f StatusResponseCode_encode_xer;
jer_type_encoder_f StatusResponseCode_encode_jer;
oer_type_decoder_f StatusResponseCode_decode_oer;
oer_type_encoder_f StatusResponseCode_encode_oer;
per_type_decoder_f StatusResponseCode_decode_uper;
per_type_encoder_f StatusResponseCode_encode_uper;
per_type_decoder_f StatusResponseCode_decode_aper;
per_type_encoder_f StatusResponseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _StatusResponseCode_H_ */
#include "asn_internal.h"
