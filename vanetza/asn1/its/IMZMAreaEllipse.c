/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IMZM-PDU-Descriptions"
 * 	found in "asn1/IMZM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "IMZMAreaEllipse.h"

asn_TYPE_member_t asn_MBR_IMZMAreaEllipse_1[] = {
	{ ATF_POINTER, 1, offsetof(struct IMZMAreaEllipse, nodeCenterPoint),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OffsetPoint,
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
		"nodeCenterPoint"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IMZMAreaEllipse, semiMajorRangeLength),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SemiRangeLength,
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
		"semiMajorRangeLength"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IMZMAreaEllipse, semiMinorRangeLength),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SemiRangeLength,
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
		"semiMinorRangeLength"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IMZMAreaEllipse, semiMajorRangeOrientation),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_WGS84AngleValue,
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
		"semiMajorRangeOrientation"
		},
};
static const int asn_MAP_IMZMAreaEllipse_oms_1[] = { 0 };
static const ber_tlv_tag_t asn_DEF_IMZMAreaEllipse_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_IMZMAreaEllipse_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nodeCenterPoint */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* semiMajorRangeLength */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* semiMinorRangeLength */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* semiMajorRangeOrientation */
};
asn_SEQUENCE_specifics_t asn_SPC_IMZMAreaEllipse_specs_1 = {
	sizeof(struct IMZMAreaEllipse),
	offsetof(struct IMZMAreaEllipse, _asn_ctx),
	asn_MAP_IMZMAreaEllipse_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_IMZMAreaEllipse_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_IMZMAreaEllipse = {
	"IMZMAreaEllipse",
	"IMZMAreaEllipse",
	&asn_OP_SEQUENCE,
	asn_DEF_IMZMAreaEllipse_tags_1,
	sizeof(asn_DEF_IMZMAreaEllipse_tags_1)
		/sizeof(asn_DEF_IMZMAreaEllipse_tags_1[0]), /* 1 */
	asn_DEF_IMZMAreaEllipse_tags_1,	/* Same as above */
	sizeof(asn_DEF_IMZMAreaEllipse_tags_1)
		/sizeof(asn_DEF_IMZMAreaEllipse_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_IMZMAreaEllipse_1,
	4,	/* Elements count */
	&asn_SPC_IMZMAreaEllipse_specs_1	/* Additional specs */
};

