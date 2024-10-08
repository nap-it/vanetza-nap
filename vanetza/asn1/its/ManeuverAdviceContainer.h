/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ManeuverAdviceContainer_H_
#define	_ManeuverAdviceContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "Maneuvers.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ManeuverAdviceContainer */
typedef struct ManeuverAdviceContainer {
	long	 numberOfExecutants;
	Maneuvers_t	 maneuver;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ManeuverAdviceContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ManeuverAdviceContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_ManeuverAdviceContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_ManeuverAdviceContainer_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _ManeuverAdviceContainer_H_ */
#include "asn_internal.h"
