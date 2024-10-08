/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TyreAirTemperature_H_
#define	_TyreAirTemperature_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TyreAirTemperature {
	TyreAirTemperature_invalid	= 0,
	TyreAirTemperature_lessThanMinus50Celsius	= 1,
	TyreAirTemperature_minus50Celsius	= 2,
	TyreAirTemperature_minus49Celsius	= 3,
	TyreAirTemperature_zeroCelsius	= 52,
	TyreAirTemperature_overflowThreshold1	= 240,
	TyreAirTemperature_overflowThreshold2	= 241,
	TyreAirTemperature_overflowThreshold3	= 242,
	TyreAirTemperature_overflowThreshold4	= 243,
	TyreAirTemperature_overflowThreshold5	= 244,
	TyreAirTemperature_overflowThreshold6	= 245,
	TyreAirTemperature_overflowThreshold7	= 246,
	TyreAirTemperature_overflowThreshold8	= 247,
	TyreAirTemperature_overflowThreshold9	= 248,
	TyreAirTemperature_overflowThreshold10	= 249,
	TyreAirTemperature_overflowThreshold11	= 250,
	TyreAirTemperature_overflowThreshold12	= 251,
	TyreAirTemperature_overflowThreshold13	= 252,
	TyreAirTemperature_overflowThreshold14	= 253,
	TyreAirTemperature_overflowThreshold15	= 254,
	TyreAirTemperature_overflowThreshold16	= 255
} e_TyreAirTemperature;

/* TyreAirTemperature */
typedef long	 TyreAirTemperature_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TyreAirTemperature_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TyreAirTemperature;
asn_struct_free_f TyreAirTemperature_free;
asn_struct_print_f TyreAirTemperature_print;
asn_constr_check_f TyreAirTemperature_constraint;
ber_type_decoder_f TyreAirTemperature_decode_ber;
der_type_encoder_f TyreAirTemperature_encode_der;
xer_type_decoder_f TyreAirTemperature_decode_xer;
xer_type_encoder_f TyreAirTemperature_encode_xer;
jer_type_encoder_f TyreAirTemperature_encode_jer;
oer_type_decoder_f TyreAirTemperature_decode_oer;
oer_type_encoder_f TyreAirTemperature_encode_oer;
per_type_decoder_f TyreAirTemperature_decode_uper;
per_type_encoder_f TyreAirTemperature_encode_uper;
per_type_decoder_f TyreAirTemperature_decode_aper;
per_type_encoder_f TyreAirTemperature_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TyreAirTemperature_H_ */
#include "asn_internal.h"
