/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "iso/ISO19091.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_NodeAttributeSet_addGrpC_H_
#define	_NodeAttributeSet_addGrpC_H_


#include "asn_application.h"

/* Including external dependencies */
#include "PtvRequestType.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NodeLink;
struct Node;

/* NodeAttributeSet-addGrpC */
typedef struct NodeAttributeSet_addGrpC {
	PtvRequestType_t	*ptvRequest;	/* OPTIONAL */
	struct NodeLink	*nodeLink;	/* OPTIONAL */
	struct Node	*node;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NodeAttributeSet_addGrpC_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NodeAttributeSet_addGrpC;
extern asn_SEQUENCE_specifics_t asn_SPC_NodeAttributeSet_addGrpC_specs_1;
extern asn_TYPE_member_t asn_MBR_NodeAttributeSet_addGrpC_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NodeLink.h"
#include "Node.h"

#endif	/* _NodeAttributeSet_addGrpC_H_ */
#include "asn_internal.h"
