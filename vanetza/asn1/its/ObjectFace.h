/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ObjectFace_H_
#define	_ObjectFace_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ObjectFace {
	ObjectFace_front	= 0,
	ObjectFace_sideLeftFront	= 1,
	ObjectFace_sideLeftBack	= 2,
	ObjectFace_sideRightFront	= 3,
	ObjectFace_sideRightBack	= 4,
	ObjectFace_back	= 5
} e_ObjectFace;

/* ObjectFace */
typedef long	 ObjectFace_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ObjectFace_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ObjectFace;
extern const asn_INTEGER_specifics_t asn_SPC_ObjectFace_specs_1;
asn_struct_free_f ObjectFace_free;
asn_struct_print_f ObjectFace_print;
asn_constr_check_f ObjectFace_constraint;
ber_type_decoder_f ObjectFace_decode_ber;
der_type_encoder_f ObjectFace_encode_der;
xer_type_decoder_f ObjectFace_decode_xer;
xer_type_encoder_f ObjectFace_encode_xer;
jer_type_encoder_f ObjectFace_encode_jer;
oer_type_decoder_f ObjectFace_decode_oer;
oer_type_encoder_f ObjectFace_encode_oer;
per_type_decoder_f ObjectFace_decode_uper;
per_type_encoder_f ObjectFace_encode_uper;
per_type_decoder_f ObjectFace_decode_aper;
per_type_encoder_f ObjectFace_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ObjectFace_H_ */
#include "asn_internal.h"
