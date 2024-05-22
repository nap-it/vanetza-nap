/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_InterferenceManagementZones_H_
#define	_ETSI_ITS_CDD_InterferenceManagementZones_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ETSI_ITS_CDD_InterferenceManagementZone;

/* ETSI-ITS-CDD_InterferenceManagementZones */
typedef struct ETSI_ITS_CDD_InterferenceManagementZones {
	A_SEQUENCE_OF(struct ETSI_ITS_CDD_InterferenceManagementZone) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_InterferenceManagementZones_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_InterferenceManagementZones;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ETSI-ITS-CDD_InterferenceManagementZone.h"

#endif	/* _ETSI_ITS_CDD_InterferenceManagementZones_H_ */
#include "asn_internal.h"
