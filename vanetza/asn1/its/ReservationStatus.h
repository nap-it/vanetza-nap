/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ReservationStatus_H_
#define	_ReservationStatus_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ReservationStatus {
	ReservationStatus_reservationOK	= 0,
	ReservationStatus_noReservationService	= 1,
	ReservationStatus_noTpmsAvailable	= 2
	/*
	 * Enumeration is extensible
	 */
} e_ReservationStatus;

/* ReservationStatus */
typedef long	 ReservationStatus_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ReservationStatus_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ReservationStatus;
extern const asn_INTEGER_specifics_t asn_SPC_ReservationStatus_specs_1;
asn_struct_free_f ReservationStatus_free;
asn_struct_print_f ReservationStatus_print;
asn_constr_check_f ReservationStatus_constraint;
ber_type_decoder_f ReservationStatus_decode_ber;
der_type_encoder_f ReservationStatus_encode_der;
xer_type_decoder_f ReservationStatus_decode_xer;
xer_type_encoder_f ReservationStatus_encode_xer;
jer_type_encoder_f ReservationStatus_encode_jer;
oer_type_decoder_f ReservationStatus_decode_oer;
oer_type_encoder_f ReservationStatus_encode_oer;
per_type_decoder_f ReservationStatus_decode_uper;
per_type_encoder_f ReservationStatus_encode_uper;
per_type_decoder_f ReservationStatus_decode_aper;
per_type_encoder_f ReservationStatus_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ReservationStatus_H_ */
#include "asn_internal.h"
