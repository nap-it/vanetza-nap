/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ISO14823Code_H_
#define	_ISO14823Code_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"
#include "NativeEnumerated.h"
#include "constr_CHOICE.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ISO14823Code__pictogramCode__serviceCategoryCode_PR {
	ISO14823Code__pictogramCode__serviceCategoryCode_PR_NOTHING,	/* No components present */
	ISO14823Code__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram,
	ISO14823Code__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram,
	ISO14823Code__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram
	/* Extensions may appear below */
	
} ISO14823Code__pictogramCode__serviceCategoryCode_PR;
typedef enum ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram {
	ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram_dangerWarning	= 0,
	ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram_regulatory	= 1,
	ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram_informative	= 2
	/*
	 * Enumeration is extensible
	 */
} e_ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram;
typedef enum ISO14823Code__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram {
	ISO14823Code__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram_publicFacilities	= 0
	/*
	 * Enumeration is extensible
	 */
} e_ISO14823Code__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram;
typedef enum ISO14823Code__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram {
	ISO14823Code__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram_ambientCondition	= 0,
	ISO14823Code__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram_roadCondition	= 1
	/*
	 * Enumeration is extensible
	 */
} e_ISO14823Code__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram;

/* Forward declarations */
struct ISO14823Attributes;

/* ISO14823Code */
typedef struct ISO14823Code {
	struct ISO14823Code__pictogramCode {
		OCTET_STRING_t	*countryCode;	/* OPTIONAL */
		struct ISO14823Code__pictogramCode__serviceCategoryCode {
			ISO14823Code__pictogramCode__serviceCategoryCode_PR present;
			union ISO14823Code__pictogramCode__serviceCategoryCode_u {
				long	 trafficSignPictogram;
				long	 publicFacilitiesPictogram;
				long	 ambientOrRoadConditionPictogram;
				/*
				 * This type is extensible,
				 * possible extensions are below.
				 */
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} serviceCategoryCode;
		struct ISO14823Code__pictogramCode__pictogramCategoryCode {
			long	 nature;
			long	 serialNumber;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} pictogramCategoryCode;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} pictogramCode;
	struct ISO14823Attributes	*attributes;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ISO14823Code_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_trafficSignPictogram_5;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_publicFacilitiesPictogram_10;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ambientOrRoadConditionPictogram_13;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_ISO14823Code;
extern asn_SEQUENCE_specifics_t asn_SPC_ISO14823Code_specs_1;
extern asn_TYPE_member_t asn_MBR_ISO14823Code_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ISO14823Attributes.h"

#endif	/* _ISO14823Code_H_ */
#include "asn_internal.h"
