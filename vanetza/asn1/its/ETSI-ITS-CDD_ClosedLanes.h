/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_ClosedLanes_H_
#define	_ETSI_ITS_CDD_ClosedLanes_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_HardShoulderStatus.h"
#include "ETSI-ITS-CDD_DrivingLaneStatus.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_ClosedLanes */
typedef struct ETSI_ITS_CDD_ClosedLanes {
	ETSI_ITS_CDD_HardShoulderStatus_t	*innerhardShoulderStatus;	/* OPTIONAL */
	ETSI_ITS_CDD_HardShoulderStatus_t	*outerhardShoulderStatus;	/* OPTIONAL */
	ETSI_ITS_CDD_DrivingLaneStatus_t	*drivingLaneStatus;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_ClosedLanes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_ClosedLanes;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_ClosedLanes_H_ */
#include "asn_internal.h"