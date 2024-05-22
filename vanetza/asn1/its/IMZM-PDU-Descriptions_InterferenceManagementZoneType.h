/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IMZM-PDU-Descriptions"
 * 	found in "asn1/IMZM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IMZM_PDU_Descriptions_InterferenceManagementZoneType_H_
#define	_IMZM_PDU_Descriptions_InterferenceManagementZoneType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IMZM_PDU_Descriptions_InterferenceManagementZoneType {
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_permanentCenDsrcTolling	= 0,
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_temporaryCenDsrcTolling	= 1,
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_unavailable	= 2,
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_urbanRail	= 3,
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_satelliteStation	= 4,
	IMZM_PDU_Descriptions_InterferenceManagementZoneType_fixedLinks	= 5
	/*
	 * Enumeration is extensible
	 */
} e_IMZM_PDU_Descriptions_InterferenceManagementZoneType;

/* IMZM-PDU-Descriptions_InterferenceManagementZoneType */
typedef long	 IMZM_PDU_Descriptions_InterferenceManagementZoneType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IMZM_PDU_Descriptions_InterferenceManagementZoneType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IMZM_PDU_Descriptions_InterferenceManagementZoneType;
extern const asn_INTEGER_specifics_t asn_SPC_IMZM_PDU_Descriptions_InterferenceManagementZoneType_specs_1;
asn_struct_free_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_free;
asn_struct_print_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_print;
asn_constr_check_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_constraint;
ber_type_decoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_decode_ber;
der_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_der;
xer_type_decoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_decode_xer;
xer_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_xer;
jer_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_jer;
oer_type_decoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_decode_oer;
oer_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_oer;
per_type_decoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_decode_uper;
per_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_uper;
per_type_decoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_decode_aper;
per_type_encoder_f IMZM_PDU_Descriptions_InterferenceManagementZoneType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _IMZM_PDU_Descriptions_InterferenceManagementZoneType_H_ */
#include "asn_internal.h"
