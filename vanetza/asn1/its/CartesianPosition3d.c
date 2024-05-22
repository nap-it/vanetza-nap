/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "CartesianPosition3d.h"

asn_TYPE_member_t asn_MBR_CartesianPosition3d_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CartesianPosition3d, xCoordinate),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CartesianCoordinate,
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
		"xCoordinate"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CartesianPosition3d, yCoordinate),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CartesianCoordinate,
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
		"yCoordinate"
		},
	{ ATF_POINTER, 1, offsetof(struct CartesianPosition3d, zCoordinate),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CartesianCoordinate,
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
		"zCoordinate"
		},
};
static const int asn_MAP_CartesianPosition3d_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_CartesianPosition3d_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CartesianPosition3d_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* xCoordinate */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* yCoordinate */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* zCoordinate */
};
asn_SEQUENCE_specifics_t asn_SPC_CartesianPosition3d_specs_1 = {
	sizeof(struct CartesianPosition3d),
	offsetof(struct CartesianPosition3d, _asn_ctx),
	asn_MAP_CartesianPosition3d_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_CartesianPosition3d_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_CartesianPosition3d = {
	"CartesianPosition3d",
	"CartesianPosition3d",
	&asn_OP_SEQUENCE,
	asn_DEF_CartesianPosition3d_tags_1,
	sizeof(asn_DEF_CartesianPosition3d_tags_1)
		/sizeof(asn_DEF_CartesianPosition3d_tags_1[0]), /* 1 */
	asn_DEF_CartesianPosition3d_tags_1,	/* Same as above */
	sizeof(asn_DEF_CartesianPosition3d_tags_1)
		/sizeof(asn_DEF_CartesianPosition3d_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_CartesianPosition3d_1,
	3,	/* Elements count */
	&asn_SPC_CartesianPosition3d_specs_1	/* Additional specs */
};

