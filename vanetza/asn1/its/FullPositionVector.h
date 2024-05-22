/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "iso/ISO19091.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_FullPositionVector_H_
#define	_FullPositionVector_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_Longitude.h"
#include "ITS-Container_Latitude.h"
#include "Elevation.h"
#include "HeadingIso.h"
#include "TimeConfidence.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DDateTime;
struct TransmissionAndSpeed;
struct PositionalAccuracy;
struct PositionConfidenceSet;
struct SpeedandHeadingIsoandThrottleConfidence;

/* FullPositionVector */
typedef struct FullPositionVector {
	struct DDateTime	*utcTime;	/* OPTIONAL */
	ITS_Container_Longitude_t	 Long;
	ITS_Container_Latitude_t	 lat;
	Elevation_t	*elevation;	/* OPTIONAL */
	HeadingIso_t	*heading;	/* OPTIONAL */
	struct TransmissionAndSpeed	*speed;	/* OPTIONAL */
	struct PositionalAccuracy	*posAccuracy;	/* OPTIONAL */
	TimeConfidence_t	*timeConfidence;	/* OPTIONAL */
	struct PositionConfidenceSet	*posConfidence;	/* OPTIONAL */
	struct SpeedandHeadingIsoandThrottleConfidence	*speedConfidence;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FullPositionVector_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FullPositionVector;
extern asn_SEQUENCE_specifics_t asn_SPC_FullPositionVector_specs_1;
extern asn_TYPE_member_t asn_MBR_FullPositionVector_1[10];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DDateTime.h"
#include "TransmissionAndSpeed.h"
#include "PositionalAccuracy.h"
#include "PositionConfidenceSet.h"
#include "SpeedandHeadingIsoandThrottleConfidence.h"

#endif	/* _FullPositionVector_H_ */
#include "asn_internal.h"
