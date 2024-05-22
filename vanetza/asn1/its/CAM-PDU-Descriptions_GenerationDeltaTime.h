/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "asn1/EN302637-2v141-CAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CAM_PDU_Descriptions_GenerationDeltaTime_H_
#define	_CAM_PDU_Descriptions_GenerationDeltaTime_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CAM_PDU_Descriptions_GenerationDeltaTime {
	CAM_PDU_Descriptions_GenerationDeltaTime_oneMilliSec	= 1
} e_CAM_PDU_Descriptions_GenerationDeltaTime;

/* CAM-PDU-Descriptions_GenerationDeltaTime */
typedef long	 CAM_PDU_Descriptions_GenerationDeltaTime_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_CAM_PDU_Descriptions_GenerationDeltaTime_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_CAM_PDU_Descriptions_GenerationDeltaTime;
asn_struct_free_f CAM_PDU_Descriptions_GenerationDeltaTime_free;
asn_struct_print_f CAM_PDU_Descriptions_GenerationDeltaTime_print;
asn_constr_check_f CAM_PDU_Descriptions_GenerationDeltaTime_constraint;
ber_type_decoder_f CAM_PDU_Descriptions_GenerationDeltaTime_decode_ber;
der_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_der;
xer_type_decoder_f CAM_PDU_Descriptions_GenerationDeltaTime_decode_xer;
xer_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_xer;
jer_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_jer;
oer_type_decoder_f CAM_PDU_Descriptions_GenerationDeltaTime_decode_oer;
oer_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_oer;
per_type_decoder_f CAM_PDU_Descriptions_GenerationDeltaTime_decode_uper;
per_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_uper;
per_type_decoder_f CAM_PDU_Descriptions_GenerationDeltaTime_decode_aper;
per_type_encoder_f CAM_PDU_Descriptions_GenerationDeltaTime_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _CAM_PDU_Descriptions_GenerationDeltaTime_H_ */
#include "asn_internal.h"
