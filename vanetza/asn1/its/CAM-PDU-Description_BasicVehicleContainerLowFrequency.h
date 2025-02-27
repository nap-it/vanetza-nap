/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Description"
 * 	found in "asn1/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CAM_PDU_Description_BasicVehicleContainerLowFrequency_H_
#define	_CAM_PDU_Description_BasicVehicleContainerLowFrequency_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_VehicleRole.h"
#include "ETSI-ITS-CDD_ExteriorLights.h"
#include "Path.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CAM-PDU-Description_BasicVehicleContainerLowFrequency */
typedef struct CAM_PDU_Description_BasicVehicleContainerLowFrequency {
	ETSI_ITS_CDD_VehicleRole_t	 vehicleRole;
	ETSI_ITS_CDD_ExteriorLights_t	 exteriorLights;
	Path_t	 pathHistory;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CAM_PDU_Description_BasicVehicleContainerLowFrequency_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CAM_PDU_Description_BasicVehicleContainerLowFrequency;
extern asn_SEQUENCE_specifics_t asn_SPC_CAM_PDU_Description_BasicVehicleContainerLowFrequency_specs_1;
extern asn_TYPE_member_t asn_MBR_CAM_PDU_Description_BasicVehicleContainerLowFrequency_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _CAM_PDU_Description_BasicVehicleContainerLowFrequency_H_ */
#include "asn_internal.h"
