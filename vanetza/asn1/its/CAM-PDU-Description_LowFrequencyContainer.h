/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Description"
 * 	found in "asn1/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CAM_PDU_Description_LowFrequencyContainer_H_
#define	_CAM_PDU_Description_LowFrequencyContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "CAM-PDU-Description_BasicVehicleContainerLowFrequency.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CAM_PDU_Description_LowFrequencyContainer_PR {
	CAM_PDU_Description_LowFrequencyContainer_PR_NOTHING,	/* No components present */
	CAM_PDU_Description_LowFrequencyContainer_PR_basicVehicleContainerLowFrequency
	/* Extensions may appear below */
	
} CAM_PDU_Description_LowFrequencyContainer_PR;

/* CAM-PDU-Description_LowFrequencyContainer */
typedef struct CAM_PDU_Description_LowFrequencyContainer {
	CAM_PDU_Description_LowFrequencyContainer_PR present;
	union CAM_PDU_Description_LowFrequencyContainer_u {
		CAM_PDU_Description_BasicVehicleContainerLowFrequency_t	 basicVehicleContainerLowFrequency;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CAM_PDU_Description_LowFrequencyContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CAM_PDU_Description_LowFrequencyContainer;
extern asn_CHOICE_specifics_t asn_SPC_CAM_PDU_Description_LowFrequencyContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_CAM_PDU_Description_LowFrequencyContainer_1[1];
extern asn_per_constraints_t asn_PER_type_CAM_PDU_Description_LowFrequencyContainer_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _CAM_PDU_Description_LowFrequencyContainer_H_ */
#include "asn_internal.h"
