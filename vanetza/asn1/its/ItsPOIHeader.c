/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EVCSN-PDU-Descriptions"
 * 	found in "asn1/EVCSN-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ItsPOIHeader.h"

asn_TYPE_member_t asn_MBR_ItsPOIHeader_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ItsPOIHeader, poiType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_POIType,
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
		"poiType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ItsPOIHeader, timeStamp),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
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
		"timeStamp"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ItsPOIHeader, relayCapable),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
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
		"relayCapable"
		},
};
static const ber_tlv_tag_t asn_DEF_ItsPOIHeader_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ItsPOIHeader_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* poiType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* timeStamp */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* relayCapable */
};
asn_SEQUENCE_specifics_t asn_SPC_ItsPOIHeader_specs_1 = {
	sizeof(struct ItsPOIHeader),
	offsetof(struct ItsPOIHeader, _asn_ctx),
	asn_MAP_ItsPOIHeader_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ItsPOIHeader = {
	"ItsPOIHeader",
	"ItsPOIHeader",
	&asn_OP_SEQUENCE,
	asn_DEF_ItsPOIHeader_tags_1,
	sizeof(asn_DEF_ItsPOIHeader_tags_1)
		/sizeof(asn_DEF_ItsPOIHeader_tags_1[0]), /* 1 */
	asn_DEF_ItsPOIHeader_tags_1,	/* Same as above */
	sizeof(asn_DEF_ItsPOIHeader_tags_1)
		/sizeof(asn_DEF_ItsPOIHeader_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_ItsPOIHeader_1,
	3,	/* Elements count */
	&asn_SPC_ItsPOIHeader_specs_1	/* Additional specs */
};

