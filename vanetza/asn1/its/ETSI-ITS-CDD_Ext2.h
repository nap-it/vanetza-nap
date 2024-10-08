/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_Ext2_H_
#define	_ETSI_ITS_CDD_Ext2_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "ETSI-ITS-CDD_Ext3.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_Ext2_PR {
	ETSI_ITS_CDD_Ext2_PR_NOTHING,	/* No components present */
	ETSI_ITS_CDD_Ext2_PR_content,
	ETSI_ITS_CDD_Ext2_PR_extension
} ETSI_ITS_CDD_Ext2_PR;

/* ETSI-ITS-CDD_Ext2 */
typedef struct ETSI_ITS_CDD_Ext2 {
	ETSI_ITS_CDD_Ext2_PR present;
	union ETSI_ITS_CDD_Ext2_u {
		long	 content;
		ETSI_ITS_CDD_Ext3_t	 extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_Ext2_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_Ext2;
extern asn_CHOICE_specifics_t asn_SPC_ETSI_ITS_CDD_Ext2_specs_1;
extern asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_Ext2_1[2];
extern asn_per_constraints_t asn_PER_type_ETSI_ITS_CDD_Ext2_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_Ext2_H_ */
#include "asn_internal.h"
