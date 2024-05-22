/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_RepeatingPeriodDayTypes_H_
#define	_RepeatingPeriodDayTypes_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RepeatingPeriodDayTypes {
	RepeatingPeriodDayTypes_national_holiday	= 0,
	RepeatingPeriodDayTypes_even_days	= 1,
	RepeatingPeriodDayTypes_odd_days	= 2,
	RepeatingPeriodDayTypes_market_day	= 3
} e_RepeatingPeriodDayTypes;

/* RepeatingPeriodDayTypes */
typedef BIT_STRING_t	 RepeatingPeriodDayTypes_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RepeatingPeriodDayTypes_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RepeatingPeriodDayTypes;
asn_struct_free_f RepeatingPeriodDayTypes_free;
asn_struct_print_f RepeatingPeriodDayTypes_print;
asn_constr_check_f RepeatingPeriodDayTypes_constraint;
ber_type_decoder_f RepeatingPeriodDayTypes_decode_ber;
der_type_encoder_f RepeatingPeriodDayTypes_encode_der;
xer_type_decoder_f RepeatingPeriodDayTypes_decode_xer;
xer_type_encoder_f RepeatingPeriodDayTypes_encode_xer;
jer_type_encoder_f RepeatingPeriodDayTypes_encode_jer;
oer_type_decoder_f RepeatingPeriodDayTypes_decode_oer;
oer_type_encoder_f RepeatingPeriodDayTypes_encode_oer;
per_type_decoder_f RepeatingPeriodDayTypes_decode_uper;
per_type_encoder_f RepeatingPeriodDayTypes_encode_uper;
per_type_decoder_f RepeatingPeriodDayTypes_decode_aper;
per_type_encoder_f RepeatingPeriodDayTypes_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RepeatingPeriodDayTypes_H_ */
#include "asn_internal.h"
