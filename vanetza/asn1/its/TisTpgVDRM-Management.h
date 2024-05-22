/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgVDRM_Management_H_
#define	_TisTpgVDRM_Management_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_TimestampIts.h"
#include "FillingStatus.h"
#include "TpgAutomation.h"
#include "PairingID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgVDRM-Management */
typedef struct TisTpgVDRM_Management {
	ITS_Container_TimestampIts_t	 generationTime;
	FillingStatus_t	 fillingStatus;
	TpgAutomation_t	 automationLevel;
	PairingID_t	*pairingID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgVDRM_Management_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgVDRM_Management;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgVDRM_Management_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgVDRM_Management_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgVDRM_Management_H_ */
#include "asn_internal.h"
