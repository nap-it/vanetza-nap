/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ReservationResponseMessage_H_
#define	_ReservationResponseMessage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ReservationResponseCode.h"
#include "Reservation-ID.h"
#include "Reservation-Password.h"
#include "StationDetails.h"
#include "ChargingSpotLabel.h"
#include "TimestampUTC.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ReservationResponseMessage */
typedef struct ReservationResponseMessage {
	ReservationResponseCode_t	 reservationResponseCode;
	Reservation_ID_t	*reservation_ID;	/* OPTIONAL */
	Reservation_Password_t	*reservation_Password;	/* OPTIONAL */
	StationDetails_t	*stationDetails;	/* OPTIONAL */
	ChargingSpotLabel_t	*chargingSpotLabel;	/* OPTIONAL */
	TimestampUTC_t	 expirationTime;
	TimestampUTC_t	*freeCancelTimeLimit;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReservationResponseMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReservationResponseMessage;
extern asn_SEQUENCE_specifics_t asn_SPC_ReservationResponseMessage_specs_1;
extern asn_TYPE_member_t asn_MBR_ReservationResponseMessage_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _ReservationResponseMessage_H_ */
#include "asn_internal.h"
