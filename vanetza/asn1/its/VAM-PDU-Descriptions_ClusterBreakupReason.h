/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VAM_PDU_Descriptions_ClusterBreakupReason_H_
#define	_VAM_PDU_Descriptions_ClusterBreakupReason_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VAM_PDU_Descriptions_ClusterBreakupReason {
	VAM_PDU_Descriptions_ClusterBreakupReason_notProvided	= 0,
	VAM_PDU_Descriptions_ClusterBreakupReason_clusteringPurposeCompleted	= 1,
	VAM_PDU_Descriptions_ClusterBreakupReason_leaderMovedOutOfClusterBoundingBox	= 2,
	VAM_PDU_Descriptions_ClusterBreakupReason_joiningAnotherCluster	= 3,
	VAM_PDU_Descriptions_ClusterBreakupReason_enteringLowRiskAreaBasedOnMaps	= 4,
	VAM_PDU_Descriptions_ClusterBreakupReason_receptionOfCpmContainingCluster	= 5,
	VAM_PDU_Descriptions_ClusterBreakupReason_max	= 15
} e_VAM_PDU_Descriptions_ClusterBreakupReason;

/* VAM-PDU-Descriptions_ClusterBreakupReason */
typedef long	 VAM_PDU_Descriptions_ClusterBreakupReason_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_VAM_PDU_Descriptions_ClusterBreakupReason_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_VAM_PDU_Descriptions_ClusterBreakupReason;
extern const asn_INTEGER_specifics_t asn_SPC_VAM_PDU_Descriptions_ClusterBreakupReason_specs_1;
asn_struct_free_f VAM_PDU_Descriptions_ClusterBreakupReason_free;
asn_struct_print_f VAM_PDU_Descriptions_ClusterBreakupReason_print;
asn_constr_check_f VAM_PDU_Descriptions_ClusterBreakupReason_constraint;
ber_type_decoder_f VAM_PDU_Descriptions_ClusterBreakupReason_decode_ber;
der_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_der;
xer_type_decoder_f VAM_PDU_Descriptions_ClusterBreakupReason_decode_xer;
xer_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_xer;
jer_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_jer;
oer_type_decoder_f VAM_PDU_Descriptions_ClusterBreakupReason_decode_oer;
oer_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_oer;
per_type_decoder_f VAM_PDU_Descriptions_ClusterBreakupReason_decode_uper;
per_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_uper;
per_type_decoder_f VAM_PDU_Descriptions_ClusterBreakupReason_decode_aper;
per_type_encoder_f VAM_PDU_Descriptions_ClusterBreakupReason_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _VAM_PDU_Descriptions_ClusterBreakupReason_H_ */
#include "asn_internal.h"
