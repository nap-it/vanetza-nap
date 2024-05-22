/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_LaneCharacteristics_H_
#define	_LaneCharacteristics_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DefinitionAccuracy.h"
#include "LaneMarkingStatus.h"
#include "MarkingColour.h"
#include "LaneDelimitation.h"
#include "Zid.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LaneCharacteristics */
typedef struct LaneCharacteristics {
	DefinitionAccuracy_t	 zoneDefinitionAccuracy;
	LaneMarkingStatus_t	 existinglaneMarkingStatus;
	MarkingColour_t	 newlaneMarkingColour;
	LaneDelimitation_t	 laneDelimitationLeft;
	LaneDelimitation_t	 laneDelimitationRight;
	Zid_t	 mergingWith;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LaneCharacteristics_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LaneCharacteristics;
extern asn_SEQUENCE_specifics_t asn_SPC_LaneCharacteristics_specs_1;
extern asn_TYPE_member_t asn_MBR_LaneCharacteristics_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _LaneCharacteristics_H_ */
#include "asn_internal.h"
