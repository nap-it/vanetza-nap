/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_GddAttribute_H_
#define	_GddAttribute_H_


#include "asn_application.h"

/* Including external dependencies */
#include "InternationalSign-applicablePeriod.h"
#include "InternationalSign-exemptedApplicablePeriod.h"
#include "InternationalSign-directionalFlowOfLane.h"
#include "InternationalSign-applicableVehicleDimensions.h"
#include "InternationalSign-speedLimits.h"
#include "InternationalSign-rateOfIncline.h"
#include "InternationalSign-distanceBetweenVehicles.h"
#include "InternationalSign-section.h"
#include "InternationalSign-numberOfLane.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GddAttribute_PR {
	GddAttribute_PR_NOTHING,	/* No components present */
	GddAttribute_PR_dtm,
	GddAttribute_PR_edt,
	GddAttribute_PR_dfl,
	GddAttribute_PR_ved,
	GddAttribute_PR_spe,
	GddAttribute_PR_roi,
	GddAttribute_PR_dbv,
	GddAttribute_PR_ddd,
	GddAttribute_PR_set,
	GddAttribute_PR_nol
} GddAttribute_PR;

/* Forward declarations */
struct InternationalSign_destinationInformation;

/* GddAttribute */
typedef struct GddAttribute {
	GddAttribute_PR present;
	union GddAttribute_u {
		InternationalSign_applicablePeriod_t	 dtm;
		InternationalSign_exemptedApplicablePeriod_t	 edt;
		InternationalSign_directionalFlowOfLane_t	 dfl;
		InternationalSign_applicableVehicleDimensions_t	 ved;
		InternationalSign_speedLimits_t	 spe;
		InternationalSign_rateOfIncline_t	 roi;
		InternationalSign_distanceBetweenVehicles_t	 dbv;
		struct InternationalSign_destinationInformation	*ddd;
		InternationalSign_section_t	 set;
		InternationalSign_numberOfLane_t	 nol;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GddAttribute_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GddAttribute;
extern asn_CHOICE_specifics_t asn_SPC_GddAttribute_specs_1;
extern asn_TYPE_member_t asn_MBR_GddAttribute_1[10];
extern asn_per_constraints_t asn_PER_type_GddAttribute_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "InternationalSign-destinationInformation.h"

#endif	/* _GddAttribute_H_ */
#include "asn_internal.h"
