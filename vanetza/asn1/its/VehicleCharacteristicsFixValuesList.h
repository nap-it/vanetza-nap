/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_VehicleCharacteristicsFixValuesList_H_
#define	_VehicleCharacteristicsFixValuesList_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct VehicleCharacteristicsFixValues;

/* VehicleCharacteristicsFixValuesList */
typedef struct VehicleCharacteristicsFixValuesList {
	A_SEQUENCE_OF(struct VehicleCharacteristicsFixValues) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VehicleCharacteristicsFixValuesList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VehicleCharacteristicsFixValuesList;
extern asn_SET_OF_specifics_t asn_SPC_VehicleCharacteristicsFixValuesList_specs_1;
extern asn_TYPE_member_t asn_MBR_VehicleCharacteristicsFixValuesList_1[1];
extern asn_per_constraints_t asn_PER_type_VehicleCharacteristicsFixValuesList_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "VehicleCharacteristicsFixValues.h"

#endif	/* _VehicleCharacteristicsFixValuesList_H_ */
#include "asn_internal.h"
