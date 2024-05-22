/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_StationTypeIso_H_
#define	_StationTypeIso_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum StationTypeIso {
	StationTypeIso_unspecified	= 0,
	StationTypeIso_closedEntryWithPayment	= 1,
	StationTypeIso_closedEntryWithoutPayment	= 2,
	StationTypeIso_closedTransit	= 3,
	StationTypeIso_closedExit	= 4,
	StationTypeIso_closedCredit	= 5,
	StationTypeIso_mixed	= 6,
	StationTypeIso_passage	= 7,
	StationTypeIso_checkpoint	= 8,
	StationTypeIso_reload	= 9,
	StationTypeIso_reservedForFutureCENUse1	= 10,
	StationTypeIso_reservedForFutureCENUse2	= 11,
	StationTypeIso_reservedForFutureCENUse3	= 12,
	StationTypeIso_reservedForFutureCENUse4	= 13,
	StationTypeIso_privateUse5	= 14,
	StationTypeIso_privateUse6	= 15
} e_StationTypeIso;

/* StationTypeIso */
typedef long	 StationTypeIso_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_StationTypeIso_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_StationTypeIso;
extern const asn_INTEGER_specifics_t asn_SPC_StationTypeIso_specs_1;
asn_struct_free_f StationTypeIso_free;
asn_struct_print_f StationTypeIso_print;
asn_constr_check_f StationTypeIso_constraint;
ber_type_decoder_f StationTypeIso_decode_ber;
der_type_encoder_f StationTypeIso_encode_der;
xer_type_decoder_f StationTypeIso_decode_xer;
xer_type_encoder_f StationTypeIso_encode_xer;
jer_type_encoder_f StationTypeIso_encode_jer;
oer_type_decoder_f StationTypeIso_decode_oer;
oer_type_encoder_f StationTypeIso_encode_oer;
per_type_decoder_f StationTypeIso_decode_uper;
per_type_encoder_f StationTypeIso_encode_uper;
per_type_decoder_f StationTypeIso_decode_aper;
per_type_encoder_f StationTypeIso_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _StationTypeIso_H_ */
#include "asn_internal.h"
