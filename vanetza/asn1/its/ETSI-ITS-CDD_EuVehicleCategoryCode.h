/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_EuVehicleCategoryCode_H_
#define	_ETSI_ITS_CDD_EuVehicleCategoryCode_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_EuVehicleCategoryL.h"
#include "ETSI-ITS-CDD_EuVehicleCategoryM.h"
#include "ETSI-ITS-CDD_EuVehicleCategoryN.h"
#include "ETSI-ITS-CDD_EuVehicleCategoryO.h"
#include "NULL.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_EuVehicleCategoryCode_PR {
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_NOTHING,	/* No components present */
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryL,
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryM,
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryN,
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryO,
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryT,
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR_euVehicleCategoryG
} ETSI_ITS_CDD_EuVehicleCategoryCode_PR;

/* ETSI-ITS-CDD_EuVehicleCategoryCode */
typedef struct ETSI_ITS_CDD_EuVehicleCategoryCode {
	ETSI_ITS_CDD_EuVehicleCategoryCode_PR present;
	union ETSI_ITS_CDD_EuVehicleCategoryCode_u {
		ETSI_ITS_CDD_EuVehicleCategoryL_t	 euVehicleCategoryL;
		ETSI_ITS_CDD_EuVehicleCategoryM_t	 euVehicleCategoryM;
		ETSI_ITS_CDD_EuVehicleCategoryN_t	 euVehicleCategoryN;
		ETSI_ITS_CDD_EuVehicleCategoryO_t	 euVehicleCategoryO;
		NULL_t	 euVehicleCategoryT;
		NULL_t	 euVehicleCategoryG;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_EuVehicleCategoryCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_EuVehicleCategoryCode;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_EuVehicleCategoryCode_H_ */
#include "asn_internal.h"
