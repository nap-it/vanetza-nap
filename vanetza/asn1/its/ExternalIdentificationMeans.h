/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ExternalIdentificationMeans_H_
#define	_ExternalIdentificationMeans_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UTF8String.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ExternalIdentificationMeans */
typedef UTF8String_t	 ExternalIdentificationMeans_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ExternalIdentificationMeans_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ExternalIdentificationMeans;
asn_struct_free_f ExternalIdentificationMeans_free;
asn_struct_print_f ExternalIdentificationMeans_print;
asn_constr_check_f ExternalIdentificationMeans_constraint;
ber_type_decoder_f ExternalIdentificationMeans_decode_ber;
der_type_encoder_f ExternalIdentificationMeans_encode_der;
xer_type_decoder_f ExternalIdentificationMeans_decode_xer;
xer_type_encoder_f ExternalIdentificationMeans_encode_xer;
jer_type_encoder_f ExternalIdentificationMeans_encode_jer;
oer_type_decoder_f ExternalIdentificationMeans_decode_oer;
oer_type_encoder_f ExternalIdentificationMeans_encode_oer;
per_type_decoder_f ExternalIdentificationMeans_decode_uper;
per_type_encoder_f ExternalIdentificationMeans_encode_uper;
per_type_decoder_f ExternalIdentificationMeans_decode_aper;
per_type_encoder_f ExternalIdentificationMeans_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ExternalIdentificationMeans_H_ */
#include "asn_internal.h"
