/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_H_
#define	_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct VAM_PDU_Descriptions_TrajectoryInterceptionIndication;

/* VAM-PDU-Descriptions_SequenceOfTrajectoryInterceptionIndication */
typedef struct VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication {
	A_SEQUENCE_OF(struct VAM_PDU_Descriptions_TrajectoryInterceptionIndication) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication;
extern asn_SET_OF_specifics_t asn_SPC_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_specs_1;
extern asn_TYPE_member_t asn_MBR_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_1[1];
extern asn_per_constraints_t asn_PER_type_VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "VAM-PDU-Descriptions_TrajectoryInterceptionIndication.h"

#endif	/* _VAM_PDU_Descriptions_SequenceOfTrajectoryInterceptionIndication_H_ */
#include "asn_internal.h"