/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_TrajectoryInterceptionIndication_H_
#define	_ETSI_ITS_CDD_TrajectoryInterceptionIndication_H_


#include "asn_application.h"

/* Including external dependencies */
#include "StationId.h"
#include "ETSI-ITS-CDD_TrajectoryInterceptionProbability.h"
#include "ETSI-ITS-CDD_TrajectoryInterceptionConfidence.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_TrajectoryInterceptionIndication */
typedef struct ETSI_ITS_CDD_TrajectoryInterceptionIndication {
	StationId_t	*subjectStation;	/* OPTIONAL */
	ETSI_ITS_CDD_TrajectoryInterceptionProbability_t	 trajectoryInterceptionProbability;
	ETSI_ITS_CDD_TrajectoryInterceptionConfidence_t	*trajectoryInterceptionConfidence;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_TrajectoryInterceptionIndication_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_TrajectoryInterceptionIndication;
extern asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_TrajectoryInterceptionIndication_specs_1;
extern asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_TrajectoryInterceptionIndication_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_TrajectoryInterceptionIndication_H_ */
#include "asn_internal.h"
