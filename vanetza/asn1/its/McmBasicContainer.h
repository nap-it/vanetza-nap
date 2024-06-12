/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_McmBasicContainer_H_
#define	_McmBasicContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_TimestampIts.h"
#include "ETSI-ITS-CDD_StationID.h"
#include "ETSI-ITS-CDD_StationType.h"
#include "ETSI-ITS-CDD_DeltaReferencePosition.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* McmBasicContainer */
typedef struct McmBasicContainer {
	ETSI_ITS_CDD_TimestampIts_t	 generationDeltaTime;
	ETSI_ITS_CDD_StationID_t	 stationID;
	ETSI_ITS_CDD_StationType_t	 stationType;
	ETSI_ITS_CDD_DeltaReferencePosition_t	 deltaReferencePosition;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} McmBasicContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_McmBasicContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_McmBasicContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_McmBasicContainer_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _McmBasicContainer_H_ */
#include "asn_internal.h"
