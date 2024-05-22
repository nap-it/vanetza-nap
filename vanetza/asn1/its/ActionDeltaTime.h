/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ActionDeltaTime_H_
#define	_ActionDeltaTime_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ActionDeltaTime {
	ActionDeltaTime_zero	= 0,
	ActionDeltaTime_hundredMs	= 1,
	ActionDeltaTime_twoHundredMs	= 2,
	ActionDeltaTime_unavailable	= 127
} e_ActionDeltaTime;

/* ActionDeltaTime */
typedef long	 ActionDeltaTime_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ActionDeltaTime_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ActionDeltaTime;
asn_struct_free_f ActionDeltaTime_free;
asn_struct_print_f ActionDeltaTime_print;
asn_constr_check_f ActionDeltaTime_constraint;
ber_type_decoder_f ActionDeltaTime_decode_ber;
der_type_encoder_f ActionDeltaTime_encode_der;
xer_type_decoder_f ActionDeltaTime_decode_xer;
xer_type_encoder_f ActionDeltaTime_encode_xer;
jer_type_encoder_f ActionDeltaTime_encode_jer;
oer_type_decoder_f ActionDeltaTime_decode_oer;
oer_type_encoder_f ActionDeltaTime_encode_oer;
per_type_decoder_f ActionDeltaTime_decode_uper;
per_type_encoder_f ActionDeltaTime_encode_uper;
per_type_decoder_f ActionDeltaTime_decode_aper;
per_type_encoder_f ActionDeltaTime_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ActionDeltaTime_H_ */
#include "asn_internal.h"
