/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_H_
#define	_ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_InterferenceManagementChannel.h"
#include "ETSI-ITS-CDD_InterferenceManagementZoneType.h"
#include "ETSI-ITS-CDD_TimestampIts.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ETSI_ITS_CDD_MitigationForTechnologies;

/* ETSI-ITS-CDD_InterferenceManagementInfoPerChannel */
typedef struct ETSI_ITS_CDD_InterferenceManagementInfoPerChannel {
	ETSI_ITS_CDD_InterferenceManagementChannel_t	 interferenceManagementChannel;
	ETSI_ITS_CDD_InterferenceManagementZoneType_t	 interferenceManagementZoneType;
	struct ETSI_ITS_CDD_MitigationForTechnologies	*interferenceManagementMitigationType;	/* OPTIONAL */
	ETSI_ITS_CDD_TimestampIts_t	*expiryTime;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_InterferenceManagementInfoPerChannel;
extern asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_specs_1;
extern asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ETSI-ITS-CDD_MitigationForTechnologies.h"

#endif	/* _ETSI_ITS_CDD_InterferenceManagementInfoPerChannel_H_ */
#include "asn_internal.h"
