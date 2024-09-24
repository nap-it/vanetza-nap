/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_VerticalAcceleration_H_
#define	_ETSI_ITS_CDD_VerticalAcceleration_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_VerticalAccelerationValue.h"
#include "ETSI-ITS-CDD_AccelerationConfidence.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_VerticalAcceleration */
typedef struct ETSI_ITS_CDD_VerticalAcceleration {
	ETSI_ITS_CDD_VerticalAccelerationValue_t	 verticalAccelerationValue;
	ETSI_ITS_CDD_AccelerationConfidence_t	 verticalAccelerationConfidence;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_VerticalAcceleration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_VerticalAcceleration;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_VerticalAcceleration_H_ */
#include "asn_internal.h"