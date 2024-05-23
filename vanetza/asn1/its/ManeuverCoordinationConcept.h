/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ManeuverCoordinationConcept_H_
#define	_ManeuverCoordinationConcept_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ManeuverCoordinationConcept {
	ManeuverCoordinationConcept_agreementSeeking	= 0,
	ManeuverCoordinationConcept_prescriptive	= 1
} e_ManeuverCoordinationConcept;

/* ManeuverCoordinationConcept */
typedef long	 ManeuverCoordinationConcept_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ManeuverCoordinationConcept_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ManeuverCoordinationConcept;
extern const asn_INTEGER_specifics_t asn_SPC_ManeuverCoordinationConcept_specs_1;
asn_struct_free_f ManeuverCoordinationConcept_free;
asn_struct_print_f ManeuverCoordinationConcept_print;
asn_constr_check_f ManeuverCoordinationConcept_constraint;
ber_type_decoder_f ManeuverCoordinationConcept_decode_ber;
der_type_encoder_f ManeuverCoordinationConcept_encode_der;
xer_type_decoder_f ManeuverCoordinationConcept_decode_xer;
xer_type_encoder_f ManeuverCoordinationConcept_encode_xer;
jer_type_encoder_f ManeuverCoordinationConcept_encode_jer;
oer_type_decoder_f ManeuverCoordinationConcept_decode_oer;
oer_type_encoder_f ManeuverCoordinationConcept_encode_oer;
per_type_decoder_f ManeuverCoordinationConcept_decode_uper;
per_type_encoder_f ManeuverCoordinationConcept_encode_uper;
per_type_decoder_f ManeuverCoordinationConcept_decode_aper;
per_type_encoder_f ManeuverCoordinationConcept_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ManeuverCoordinationConcept_H_ */
#include "asn_internal.h"
