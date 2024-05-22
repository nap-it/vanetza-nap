/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ETSI-ITS-CDD_ActionID.h"

static asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_ActionID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ETSI_ITS_CDD_ActionID, originatingStationId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_StationID,
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
		"originatingStationId"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ETSI_ITS_CDD_ActionID, sequenceNumber),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_SequenceNumber,
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
		"sequenceNumber"
		},
};
static const ber_tlv_tag_t asn_DEF_ETSI_ITS_CDD_ActionID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ETSI_ITS_CDD_ActionID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* originatingStationId */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* sequenceNumber */
};
static asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_ActionID_specs_1 = {
	sizeof(struct ETSI_ITS_CDD_ActionID),
	offsetof(struct ETSI_ITS_CDD_ActionID, _asn_ctx),
	asn_MAP_ETSI_ITS_CDD_ActionID_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_ActionID = {
	"ActionID",
	"ActionID",
	&asn_OP_SEQUENCE,
	asn_DEF_ETSI_ITS_CDD_ActionID_tags_1,
	sizeof(asn_DEF_ETSI_ITS_CDD_ActionID_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_ActionID_tags_1[0]), /* 1 */
	asn_DEF_ETSI_ITS_CDD_ActionID_tags_1,	/* Same as above */
	sizeof(asn_DEF_ETSI_ITS_CDD_ActionID_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_ActionID_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_ETSI_ITS_CDD_ActionID_1,
	2,	/* Elements count */
	&asn_SPC_ETSI_ITS_CDD_ActionID_specs_1	/* Additional specs */
};

