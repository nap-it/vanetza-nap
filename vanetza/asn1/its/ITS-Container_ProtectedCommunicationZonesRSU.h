/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_ProtectedCommunicationZonesRSU_H_
#define	_ITS_Container_ProtectedCommunicationZonesRSU_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ITS_Container_ProtectedCommunicationZone;

/* ITS-Container_ProtectedCommunicationZonesRSU */
typedef struct ITS_Container_ProtectedCommunicationZonesRSU {
	A_SEQUENCE_OF(struct ITS_Container_ProtectedCommunicationZone) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ITS_Container_ProtectedCommunicationZonesRSU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_ProtectedCommunicationZonesRSU;
extern asn_SET_OF_specifics_t asn_SPC_ITS_Container_ProtectedCommunicationZonesRSU_specs_1;
extern asn_TYPE_member_t asn_MBR_ITS_Container_ProtectedCommunicationZonesRSU_1[1];
extern asn_per_constraints_t asn_PER_type_ITS_Container_ProtectedCommunicationZonesRSU_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ITS-Container_ProtectedCommunicationZone.h"

#endif	/* _ITS_Container_ProtectedCommunicationZonesRSU_H_ */
#include "asn_internal.h"
