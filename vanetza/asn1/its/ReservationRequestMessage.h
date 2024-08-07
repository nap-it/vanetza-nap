/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ReservationRequestMessage_H_
#define	_ReservationRequestMessage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "TimestampUTC.h"
#include "PreReservation-ID.h"
#include "EAmount.h"
#include "PaymentType.h"
#include "Payment-ID.h"
#include "Pairing-ID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Payment_ID;

/* ReservationRequestMessage */
typedef struct ReservationRequestMessage {
	TimestampUTC_t	 currentTime;
	PreReservation_ID_t	 preReservation_ID;
	TimestampUTC_t	 arrivalTime;
	TimestampUTC_t	*departureTime;	/* OPTIONAL */
	EAmount_t	 eAmount;
	EAmount_t	 eAmountMin;
	PaymentType_t	 paymentType;
	Payment_ID_t	 payment_ID;
	struct Payment_ID	*secondPayment_ID;	/* OPTIONAL */
	Pairing_ID_t	*pairing_ID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReservationRequestMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReservationRequestMessage;
extern asn_SEQUENCE_specifics_t asn_SPC_ReservationRequestMessage_specs_1;
extern asn_TYPE_member_t asn_MBR_ReservationRequestMessage_1[10];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Payment-ID.h"

#endif	/* _ReservationRequestMessage_H_ */
#include "asn_internal.h"
