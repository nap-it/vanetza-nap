/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ETSI-ITS-CDD_VehicleLength.h"

static asn_TYPE_member_t asn_MBR_ETSI_ITS_CDD_VehicleLength_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ETSI_ITS_CDD_VehicleLength, vehicleLengthValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_VehicleLengthValue,
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
		"vehicleLengthValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ETSI_ITS_CDD_VehicleLength, vehicleLengthConfidenceIndication),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_VehicleLengthConfidenceIndication,
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
		"vehicleLengthConfidenceIndication"
		},
};
static const ber_tlv_tag_t asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ETSI_ITS_CDD_VehicleLength_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* vehicleLengthValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* vehicleLengthConfidenceIndication */
};
static asn_SEQUENCE_specifics_t asn_SPC_ETSI_ITS_CDD_VehicleLength_specs_1 = {
	sizeof(struct ETSI_ITS_CDD_VehicleLength),
	offsetof(struct ETSI_ITS_CDD_VehicleLength, _asn_ctx),
	asn_MAP_ETSI_ITS_CDD_VehicleLength_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_VehicleLength = {
	"VehicleLength",
	"VehicleLength",
	&asn_OP_SEQUENCE,
	asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1,
	sizeof(asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1[0]), /* 1 */
	asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1,	/* Same as above */
	sizeof(asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_VehicleLength_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_ETSI_ITS_CDD_VehicleLength_1,
	2,	/* Elements count */
	&asn_SPC_ETSI_ITS_CDD_VehicleLength_specs_1	/* Additional specs */
};

