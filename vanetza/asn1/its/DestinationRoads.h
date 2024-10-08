/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DestinationRoads_H_
#define	_DestinationRoads_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DestinationRoad;

/* DestinationRoads */
typedef struct DestinationRoads {
	A_SEQUENCE_OF(struct DestinationRoad) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DestinationRoads_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DestinationRoads;
extern asn_SET_OF_specifics_t asn_SPC_DestinationRoads_specs_1;
extern asn_TYPE_member_t asn_MBR_DestinationRoads_1[1];
extern asn_per_constraints_t asn_PER_type_DestinationRoads_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DestinationRoad.h"

#endif	/* _DestinationRoads_H_ */
#include "asn_internal.h"
