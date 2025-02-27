/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Description"
 * 	found in "asn1/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "CAM-PDU-Description_HighFrequencyContainer.h"

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_CAM_PDU_Description_HighFrequencyContainer_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_CAM_PDU_Description_HighFrequencyContainer_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_CAM_PDU_Description_HighFrequencyContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CAM_PDU_Description_HighFrequencyContainer, choice.basicVehicleContainerHighFrequency),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CAM_PDU_Description_BasicVehicleContainerHighFrequency,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"basicVehicleContainerHighFrequency"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CAM_PDU_Description_HighFrequencyContainer, choice.rsuContainerHighFrequency),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CAM_PDU_Description_RSUContainerHighFrequency,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"rsuContainerHighFrequency"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_CAM_PDU_Description_HighFrequencyContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* basicVehicleContainerHighFrequency */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* rsuContainerHighFrequency */
};
asn_CHOICE_specifics_t asn_SPC_CAM_PDU_Description_HighFrequencyContainer_specs_1 = {
	sizeof(struct CAM_PDU_Description_HighFrequencyContainer),
	offsetof(struct CAM_PDU_Description_HighFrequencyContainer, _asn_ctx),
	offsetof(struct CAM_PDU_Description_HighFrequencyContainer, present),
	sizeof(((struct CAM_PDU_Description_HighFrequencyContainer *)0)->present),
	asn_MAP_CAM_PDU_Description_HighFrequencyContainer_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_CAM_PDU_Description_HighFrequencyContainer = {
	"HighFrequencyContainer",
	"HighFrequencyContainer",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_CAM_PDU_Description_HighFrequencyContainer_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_CAM_PDU_Description_HighFrequencyContainer_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_CAM_PDU_Description_HighFrequencyContainer_1,
	2,	/* Elements count */
	&asn_SPC_CAM_PDU_Description_HighFrequencyContainer_specs_1	/* Additional specs */
};

