/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "VAM-PDU-Descriptions"
 * 	found in "asn1/TS103300-3v211-VAM.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VruClusterOperationContainer_H_
#define	_VruClusterOperationContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "VruClusterOpTimestamp.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct VAM_PDU_Descriptions_ClusterJoinInfo;
struct VAM_PDU_Descriptions_ClusterLeaveInfo;
struct VAM_PDU_Descriptions_ClusterBreakupInfo;

/* VruClusterOperationContainer */
typedef struct VruClusterOperationContainer {
	struct VAM_PDU_Descriptions_ClusterJoinInfo	*clusterJoinInfo;	/* OPTIONAL */
	struct VAM_PDU_Descriptions_ClusterLeaveInfo	*clusterLeaveInfo;	/* OPTIONAL */
	struct VAM_PDU_Descriptions_ClusterBreakupInfo	*clusterBreakupInfo;	/* OPTIONAL */
	VruClusterOpTimestamp_t	*clusterIdChangeTimeInfo;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VruClusterOperationContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VruClusterOperationContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_VruClusterOperationContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_VruClusterOperationContainer_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "VAM-PDU-Descriptions_ClusterJoinInfo.h"
#include "VAM-PDU-Descriptions_ClusterLeaveInfo.h"
#include "VAM-PDU-Descriptions_ClusterBreakupInfo.h"

#endif	/* _VruClusterOperationContainer_H_ */
#include "asn_internal.h"
