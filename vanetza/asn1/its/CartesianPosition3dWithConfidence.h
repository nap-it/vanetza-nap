/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CartesianPosition3dWithConfidence_H_
#define	_CartesianPosition3dWithConfidence_H_


#include "asn_application.h"

/* Including external dependencies */
#include "CartesianCoordinateWithConfidence.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CartesianCoordinateWithConfidence;

/* CartesianPosition3dWithConfidence */
typedef struct CartesianPosition3dWithConfidence {
	CartesianCoordinateWithConfidence_t	 xCoordinate;
	CartesianCoordinateWithConfidence_t	 yCoordinate;
	struct CartesianCoordinateWithConfidence	*zCoordinate;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CartesianPosition3dWithConfidence_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CartesianPosition3dWithConfidence;
extern asn_SEQUENCE_specifics_t asn_SPC_CartesianPosition3dWithConfidence_specs_1;
extern asn_TYPE_member_t asn_MBR_CartesianPosition3dWithConfidence_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CartesianCoordinateWithConfidence.h"

#endif	/* _CartesianPosition3dWithConfidence_H_ */
#include "asn_internal.h"
