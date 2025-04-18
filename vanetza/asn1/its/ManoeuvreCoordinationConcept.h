/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ManoeuvreCoordinationConcept_H_
#define	_ManoeuvreCoordinationConcept_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ManoeuvreCoordinationConcept {
	ManoeuvreCoordinationConcept_agreementSeeking	= 0,
	ManoeuvreCoordinationConcept_prescriptive	= 1
} e_ManoeuvreCoordinationConcept;

/* ManoeuvreCoordinationConcept */
typedef long	 ManoeuvreCoordinationConcept_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ManoeuvreCoordinationConcept_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ManoeuvreCoordinationConcept;
extern const asn_INTEGER_specifics_t asn_SPC_ManoeuvreCoordinationConcept_specs_1;
asn_struct_free_f ManoeuvreCoordinationConcept_free;
asn_struct_print_f ManoeuvreCoordinationConcept_print;
asn_constr_check_f ManoeuvreCoordinationConcept_constraint;
ber_type_decoder_f ManoeuvreCoordinationConcept_decode_ber;
der_type_encoder_f ManoeuvreCoordinationConcept_encode_der;
xer_type_decoder_f ManoeuvreCoordinationConcept_decode_xer;
xer_type_encoder_f ManoeuvreCoordinationConcept_encode_xer;
jer_type_encoder_f ManoeuvreCoordinationConcept_encode_jer;
oer_type_decoder_f ManoeuvreCoordinationConcept_decode_oer;
oer_type_encoder_f ManoeuvreCoordinationConcept_encode_oer;
per_type_decoder_f ManoeuvreCoordinationConcept_decode_uper;
per_type_encoder_f ManoeuvreCoordinationConcept_encode_uper;
per_type_decoder_f ManoeuvreCoordinationConcept_decode_aper;
per_type_encoder_f ManoeuvreCoordinationConcept_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ManoeuvreCoordinationConcept_H_ */
#include "asn_internal.h"
