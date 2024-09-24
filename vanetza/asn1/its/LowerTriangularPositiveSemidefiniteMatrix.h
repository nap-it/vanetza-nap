/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_LowerTriangularPositiveSemidefiniteMatrix_H_
#define	_LowerTriangularPositiveSemidefiniteMatrix_H_


#include "asn_application.h"

/* Including external dependencies */
#include "MatrixIncludedComponents.h"
#include "LowerTriangularPositiveSemidefiniteMatrixColumns.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LowerTriangularPositiveSemidefiniteMatrix */
typedef struct LowerTriangularPositiveSemidefiniteMatrix {
	MatrixIncludedComponents_t	 componentsIncludedIntheMatrix;
	LowerTriangularPositiveSemidefiniteMatrixColumns_t	 matrix;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LowerTriangularPositiveSemidefiniteMatrix_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LowerTriangularPositiveSemidefiniteMatrix;
extern asn_SEQUENCE_specifics_t asn_SPC_LowerTriangularPositiveSemidefiniteMatrix_specs_1;
extern asn_TYPE_member_t asn_MBR_LowerTriangularPositiveSemidefiniteMatrix_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _LowerTriangularPositiveSemidefiniteMatrix_H_ */
#include "asn_internal.h"