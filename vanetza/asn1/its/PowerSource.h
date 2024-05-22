/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PowerSource_H_
#define	_PowerSource_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PowerSource {
	PowerSource_notApplicable	= 0,
	PowerSource_ac1Phase	= 1,
	PowerSource_ac2Phase	= 2,
	PowerSource_ac3Phase	= 3,
	PowerSource_dcc	= 4,
	PowerSource_chaDeMo	= 5
} e_PowerSource;

/* PowerSource */
typedef long	 PowerSource_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PowerSource_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PowerSource;
asn_struct_free_f PowerSource_free;
asn_struct_print_f PowerSource_print;
asn_constr_check_f PowerSource_constraint;
ber_type_decoder_f PowerSource_decode_ber;
der_type_encoder_f PowerSource_encode_der;
xer_type_decoder_f PowerSource_decode_xer;
xer_type_encoder_f PowerSource_encode_xer;
jer_type_encoder_f PowerSource_encode_jer;
oer_type_decoder_f PowerSource_decode_oer;
oer_type_encoder_f PowerSource_encode_oer;
per_type_decoder_f PowerSource_decode_uper;
per_type_encoder_f PowerSource_encode_uper;
per_type_decoder_f PowerSource_decode_aper;
per_type_encoder_f PowerSource_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PowerSource_H_ */
#include "asn_internal.h"
