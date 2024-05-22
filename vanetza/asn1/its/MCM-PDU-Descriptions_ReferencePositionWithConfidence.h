/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_MCM_PDU_Descriptions_ReferencePositionWithConfidence_H_
#define	_MCM_PDU_Descriptions_ReferencePositionWithConfidence_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_Latitude.h"
#include "ITS-Container_Longitude.h"
#include "MCM-PDU-Descriptions_PositionConfidenceEllipse.h"
#include "ITS-Container_Altitude.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* MCM-PDU-Descriptions_ReferencePositionWithConfidence */
typedef struct MCM_PDU_Descriptions_ReferencePositionWithConfidence {
	ITS_Container_Latitude_t	 latitude;
	ITS_Container_Longitude_t	 longitude;
	MCM_PDU_Descriptions_PositionConfidenceEllipse_t	 positionConfidenceEllipse;
	ITS_Container_Altitude_t	 altitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MCM_PDU_Descriptions_ReferencePositionWithConfidence_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MCM_PDU_Descriptions_ReferencePositionWithConfidence;
extern asn_SEQUENCE_specifics_t asn_SPC_MCM_PDU_Descriptions_ReferencePositionWithConfidence_specs_1;
extern asn_TYPE_member_t asn_MBR_MCM_PDU_Descriptions_ReferencePositionWithConfidence_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _MCM_PDU_Descriptions_ReferencePositionWithConfidence_H_ */
#include "asn_internal.h"
