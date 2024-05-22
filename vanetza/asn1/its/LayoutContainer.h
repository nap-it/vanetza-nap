/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_LayoutContainer_H_
#define	_LayoutContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "LayoutComponents.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LayoutContainer */
typedef struct LayoutContainer {
	long	 layoutId;
	long	*height;	/* OPTIONAL */
	long	*width;	/* OPTIONAL */
	LayoutComponents_t	 layoutComponents;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LayoutContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LayoutContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_LayoutContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_LayoutContainer_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _LayoutContainer_H_ */
#include "asn_internal.h"
