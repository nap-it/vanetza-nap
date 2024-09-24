/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CITSapplMgmtIDs"
 * 	found in "iso/ISO17419.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_CITSapplMgmtIDs_VarLengthNumber_H_
#define	_CITSapplMgmtIDs_VarLengthNumber_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "CITSapplMgmtIDs_Ext1.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CITSapplMgmtIDs_VarLengthNumber_PR {
	CITSapplMgmtIDs_VarLengthNumber_PR_NOTHING,	/* No components present */
	CITSapplMgmtIDs_VarLengthNumber_PR_content,
	CITSapplMgmtIDs_VarLengthNumber_PR_extension
} CITSapplMgmtIDs_VarLengthNumber_PR;

/* CITSapplMgmtIDs_VarLengthNumber */
typedef struct CITSapplMgmtIDs_VarLengthNumber {
	CITSapplMgmtIDs_VarLengthNumber_PR present;
	union CITSapplMgmtIDs_VarLengthNumber_u {
		long	 content;
		CITSapplMgmtIDs_Ext1_t	 extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CITSapplMgmtIDs_VarLengthNumber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CITSapplMgmtIDs_VarLengthNumber;
extern asn_CHOICE_specifics_t asn_SPC_CITSapplMgmtIDs_VarLengthNumber_specs_1;
extern asn_TYPE_member_t asn_MBR_CITSapplMgmtIDs_VarLengthNumber_1[2];
extern asn_per_constraints_t asn_PER_type_CITSapplMgmtIDs_VarLengthNumber_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _CITSapplMgmtIDs_VarLengthNumber_H_ */
#include "asn_internal.h"