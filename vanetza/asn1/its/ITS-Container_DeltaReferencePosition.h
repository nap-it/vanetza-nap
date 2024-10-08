/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_DeltaReferencePosition_H_
#define	_ITS_Container_DeltaReferencePosition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_DeltaLatitude.h"
#include "ITS-Container_DeltaLongitude.h"
#include "ITS-Container_DeltaAltitude.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ITS-Container_DeltaReferencePosition */
typedef struct ITS_Container_DeltaReferencePosition {
	ITS_Container_DeltaLatitude_t	 deltaLatitude;
	ITS_Container_DeltaLongitude_t	 deltaLongitude;
	ITS_Container_DeltaAltitude_t	 deltaAltitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ITS_Container_DeltaReferencePosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_DeltaReferencePosition;
extern asn_SEQUENCE_specifics_t asn_SPC_ITS_Container_DeltaReferencePosition_specs_1;
extern asn_TYPE_member_t asn_MBR_ITS_Container_DeltaReferencePosition_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_DeltaReferencePosition_H_ */
#include "asn_internal.h"
