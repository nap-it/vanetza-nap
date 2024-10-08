/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "TisTpgDRM-Management.h"

asn_TYPE_member_t asn_MBR_TisTpgDRM_Management_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TisTpgDRM_Management, generationTime),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ITS_Container_TimestampIts,
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
		"generationTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TisTpgDRM_Management, vehicleType),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UNVehicleClassifcation,
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
		"vehicleType"
		},
	{ ATF_POINTER, 1, offsetof(struct TisTpgDRM_Management, costumerContract),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CustomerContract,
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
		"costumerContract"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TisTpgDRM_Management, tisProfile),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TisProfile,
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
		"tisProfile"
		},
};
static const int asn_MAP_TisTpgDRM_Management_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_TisTpgDRM_Management_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TisTpgDRM_Management_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* generationTime */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* vehicleType */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* costumerContract */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* tisProfile */
};
asn_SEQUENCE_specifics_t asn_SPC_TisTpgDRM_Management_specs_1 = {
	sizeof(struct TisTpgDRM_Management),
	offsetof(struct TisTpgDRM_Management, _asn_ctx),
	asn_MAP_TisTpgDRM_Management_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_TisTpgDRM_Management_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_TisTpgDRM_Management = {
	"TisTpgDRM-Management",
	"TisTpgDRM-Management",
	&asn_OP_SEQUENCE,
	asn_DEF_TisTpgDRM_Management_tags_1,
	sizeof(asn_DEF_TisTpgDRM_Management_tags_1)
		/sizeof(asn_DEF_TisTpgDRM_Management_tags_1[0]), /* 1 */
	asn_DEF_TisTpgDRM_Management_tags_1,	/* Same as above */
	sizeof(asn_DEF_TisTpgDRM_Management_tags_1)
		/sizeof(asn_DEF_TisTpgDRM_Management_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_TisTpgDRM_Management_1,
	4,	/* Elements count */
	&asn_SPC_TisTpgDRM_Management_specs_1	/* Additional specs */
};

