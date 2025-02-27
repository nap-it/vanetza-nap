/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "asn1/EN302637-3v131-DENM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DENM_PDU_Descriptions_Termination_H_
#define	_DENM_PDU_Descriptions_Termination_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DENM_PDU_Descriptions_Termination {
	DENM_PDU_Descriptions_Termination_isCancellation	= 0,
	DENM_PDU_Descriptions_Termination_isNegation	= 1
} e_DENM_PDU_Descriptions_Termination;

/* DENM-PDU-Descriptions_Termination */
typedef long	 DENM_PDU_Descriptions_Termination_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_DENM_PDU_Descriptions_Termination_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_DENM_PDU_Descriptions_Termination;
extern const asn_INTEGER_specifics_t asn_SPC_DENM_PDU_Descriptions_Termination_specs_1;
asn_struct_free_f DENM_PDU_Descriptions_Termination_free;
asn_struct_print_f DENM_PDU_Descriptions_Termination_print;
asn_constr_check_f DENM_PDU_Descriptions_Termination_constraint;
ber_type_decoder_f DENM_PDU_Descriptions_Termination_decode_ber;
der_type_encoder_f DENM_PDU_Descriptions_Termination_encode_der;
xer_type_decoder_f DENM_PDU_Descriptions_Termination_decode_xer;
xer_type_encoder_f DENM_PDU_Descriptions_Termination_encode_xer;
jer_type_encoder_f DENM_PDU_Descriptions_Termination_encode_jer;
oer_type_decoder_f DENM_PDU_Descriptions_Termination_decode_oer;
oer_type_encoder_f DENM_PDU_Descriptions_Termination_encode_oer;
per_type_decoder_f DENM_PDU_Descriptions_Termination_decode_uper;
per_type_encoder_f DENM_PDU_Descriptions_Termination_encode_uper;
per_type_decoder_f DENM_PDU_Descriptions_Termination_decode_aper;
per_type_encoder_f DENM_PDU_Descriptions_Termination_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _DENM_PDU_Descriptions_Termination_H_ */
#include "asn_internal.h"
