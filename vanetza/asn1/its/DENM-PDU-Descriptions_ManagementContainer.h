/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "asn1/EN302637-3v131-DENM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DENM_PDU_Descriptions_ManagementContainer_H_
#define	_DENM_PDU_Descriptions_ManagementContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_ActionID.h"
#include "ITS-Container_TimestampIts.h"
#include "Termination.h"
#include "ITS-Container_ReferencePosition.h"
#include "ITS-Container_RelevanceDistance.h"
#include "ITS-Container_RelevanceTrafficDirection.h"
#include "ITS-Container_ValidityDuration.h"
#include "ITS-Container_TransmissionInterval.h"
#include "ITS-Container_StationType.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* DENM-PDU-Descriptions_ManagementContainer */
typedef struct DENM_PDU_Descriptions_ManagementContainer {
	ITS_Container_ActionID_t	 actionID;
	ITS_Container_TimestampIts_t	 detectionTime;
	ITS_Container_TimestampIts_t	 referenceTime;
	Termination_t	*termination;	/* OPTIONAL */
	ITS_Container_ReferencePosition_t	 eventPosition;
	ITS_Container_RelevanceDistance_t	*relevanceDistance;	/* OPTIONAL */
	ITS_Container_RelevanceTrafficDirection_t	*relevanceTrafficDirection;	/* OPTIONAL */
	ITS_Container_ValidityDuration_t	*validityDuration;	/* DEFAULT 600 */
	ITS_Container_TransmissionInterval_t	*transmissionInterval;	/* OPTIONAL */
	ITS_Container_StationType_t	 stationType;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DENM_PDU_Descriptions_ManagementContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DENM_PDU_Descriptions_ManagementContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_DENM_PDU_Descriptions_ManagementContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_DENM_PDU_Descriptions_ManagementContainer_1[10];

#ifdef __cplusplus
}
#endif

#endif	/* _DENM_PDU_Descriptions_ManagementContainer_H_ */
#include "asn_internal.h"
