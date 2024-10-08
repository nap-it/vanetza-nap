/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ManeuverCoordinationRational_H_
#define	_ManeuverCoordinationRational_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ManeuverCooperationGoal.h"
#include "ManeuverCooperationCost.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ManeuverCoordinationRational_PR {
	ManeuverCoordinationRational_PR_NOTHING,	/* No components present */
	ManeuverCoordinationRational_PR_maneuverCooperationGoal,
	ManeuverCoordinationRational_PR_maneuverCooperationCost
} ManeuverCoordinationRational_PR;

/* ManeuverCoordinationRational */
typedef struct ManeuverCoordinationRational {
	ManeuverCoordinationRational_PR present;
	union ManeuverCoordinationRational_u {
		ManeuverCooperationGoal_t	 maneuverCooperationGoal;
		ManeuverCooperationCost_t	 maneuverCooperationCost;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ManeuverCoordinationRational_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ManeuverCoordinationRational;
extern asn_CHOICE_specifics_t asn_SPC_ManeuverCoordinationRational_specs_1;
extern asn_TYPE_member_t asn_MBR_ManeuverCoordinationRational_1[2];
extern asn_per_constraints_t asn_PER_type_ManeuverCoordinationRational_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ManeuverCoordinationRational_H_ */
#include "asn_internal.h"
