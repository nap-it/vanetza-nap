/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PathPointPredicted_H_
#define	_PathPointPredicted_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_DeltaLatitude.h"
#include "ETSI-ITS-CDD_DeltaLongitude.h"
#include "ETSI-ITS-CDD_DeltaAltitude.h"
#include "ETSI-ITS-CDD_AltitudeConfidence.h"
#include "StandardLength9b.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ETSI_ITS_CDD_PosConfidenceEllipse;
struct PathDeltaTimeChoice;

/* PathPointPredicted */
typedef struct PathPointPredicted {
	ETSI_ITS_CDD_DeltaLatitude_t	 deltaLatitude;
	ETSI_ITS_CDD_DeltaLongitude_t	 deltaLongitude;
	struct ETSI_ITS_CDD_PosConfidenceEllipse	*horizontalPositionConfidence;	/* OPTIONAL */
	ETSI_ITS_CDD_DeltaAltitude_t	*deltaAltitude;	/* DEFAULT 12800 */
	ETSI_ITS_CDD_AltitudeConfidence_t	*altitudeConfidence;	/* DEFAULT 15 */
	struct PathDeltaTimeChoice	*pathDeltaTime;	/* OPTIONAL */
	StandardLength9b_t	*symmetricAreaOffset;	/* OPTIONAL */
	StandardLength9b_t	*asymmetricAreaOffset;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PathPointPredicted_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PathPointPredicted;
extern asn_SEQUENCE_specifics_t asn_SPC_PathPointPredicted_specs_1;
extern asn_TYPE_member_t asn_MBR_PathPointPredicted_1[8];
extern asn_per_constraints_t asn_PER_type_PathPointPredicted_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ETSI-ITS-CDD_PosConfidenceEllipse.h"
#include "PathDeltaTimeChoice.h"

#endif	/* _PathPointPredicted_H_ */
#include "asn_internal.h"