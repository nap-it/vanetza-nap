/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Description"
 * 	found in "asn1/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CAM_PDU_Description_CAM_H_
#define	_CAM_PDU_Description_CAM_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_ItsPduHeader.h"
#include "CamPayload.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CAM-PDU-Description_CAM */
typedef struct CAM_PDU_Description_CAM {
	ETSI_ITS_CDD_ItsPduHeader_t	 header;
	CamPayload_t	 cam;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CAM_PDU_Description_CAM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CAM_PDU_Description_CAM;

#ifdef __cplusplus
}
#endif

#endif	/* _CAM_PDU_Description_CAM_H_ */
#include "asn_internal.h"
