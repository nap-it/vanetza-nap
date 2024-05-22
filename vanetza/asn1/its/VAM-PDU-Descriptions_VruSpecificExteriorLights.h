/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VAM_PDU_Descriptions_VruSpecificExteriorLights_H_
#define	_VAM_PDU_Descriptions_VruSpecificExteriorLights_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VAM_PDU_Descriptions_VruSpecificExteriorLights {
	VAM_PDU_Descriptions_VruSpecificExteriorLights_unavailable	= 0,
	VAM_PDU_Descriptions_VruSpecificExteriorLights_backFlashLight	= 1,
	VAM_PDU_Descriptions_VruSpecificExteriorLights_helmetLight	= 2,
	VAM_PDU_Descriptions_VruSpecificExteriorLights_armLight	= 3,
	VAM_PDU_Descriptions_VruSpecificExteriorLights_legLight	= 4,
	VAM_PDU_Descriptions_VruSpecificExteriorLights_wheelLight	= 5
} e_VAM_PDU_Descriptions_VruSpecificExteriorLights;

/* VAM-PDU-Descriptions_VruSpecificExteriorLights */
typedef BIT_STRING_t	 VAM_PDU_Descriptions_VruSpecificExteriorLights_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VAM_PDU_Descriptions_VruSpecificExteriorLights_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VAM_PDU_Descriptions_VruSpecificExteriorLights;
asn_struct_free_f VAM_PDU_Descriptions_VruSpecificExteriorLights_free;
asn_struct_print_f VAM_PDU_Descriptions_VruSpecificExteriorLights_print;
asn_constr_check_f VAM_PDU_Descriptions_VruSpecificExteriorLights_constraint;
ber_type_decoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_decode_ber;
der_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_der;
xer_type_decoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_decode_xer;
xer_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_xer;
jer_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_jer;
oer_type_decoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_decode_oer;
oer_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_oer;
per_type_decoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_decode_uper;
per_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_uper;
per_type_decoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_decode_aper;
per_type_encoder_f VAM_PDU_Descriptions_VruSpecificExteriorLights_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _VAM_PDU_Descriptions_VruSpecificExteriorLights_H_ */
#include "asn_internal.h"
