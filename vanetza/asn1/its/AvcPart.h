/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AvcPart_H_
#define	_AvcPart_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ZoneIds.h"
#include "IVI_Direction.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ZoneIds;
struct LanePositions;
struct VehicleCharacteristicsList;
struct AutomatedVehicleRules;
struct PlatooningRules;

/* AvcPart */
typedef struct AvcPart {
	struct ZoneIds	*detectionZoneIds;	/* OPTIONAL */
	ZoneIds_t	 relevanceZoneIds;
	IVI_Direction_t	*direction;	/* OPTIONAL */
	struct LanePositions	*applicableLanes;	/* OPTIONAL */
	struct VehicleCharacteristicsList	*vehicleCharacteristics;	/* OPTIONAL */
	struct AutomatedVehicleRules	*automatedVehicleRules;	/* OPTIONAL */
	struct PlatooningRules	*platooningRules;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AvcPart_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AvcPart;
extern asn_SEQUENCE_specifics_t asn_SPC_AvcPart_specs_1;
extern asn_TYPE_member_t asn_MBR_AvcPart_1[7];
extern asn_per_constraints_t asn_PER_type_AvcPart_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ZoneIds.h"
#include "LanePositions.h"
#include "VehicleCharacteristicsList.h"
#include "AutomatedVehicleRules.h"
#include "PlatooningRules.h"

#endif	/* _AvcPart_H_ */
#include "asn_internal.h"
