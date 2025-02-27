/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Description"
 * 	found in "asn1/DENM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "DENM-PDU-Description_AlacarteContainer.h"

static asn_TYPE_member_t asn_MBR_ext1_9[] = {
	{ ATF_POINTER, 2, offsetof(struct DENM_PDU_Description_AlacarteContainer__ext1, roadConfiguration),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DENM_PDU_Description_RoadConfigurationContainer,
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
		"roadConfiguration"
		},
	{ ATF_POINTER, 1, offsetof(struct DENM_PDU_Description_AlacarteContainer__ext1, preCrash),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PreCrashContainer,
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
		"preCrash"
		},
};
static const int asn_MAP_ext1_oms_9[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_ext1_tags_9[] = {
	(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ext1_tag2el_9[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* roadConfiguration */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* preCrash */
};
static asn_SEQUENCE_specifics_t asn_SPC_ext1_specs_9 = {
	sizeof(struct DENM_PDU_Description_AlacarteContainer__ext1),
	offsetof(struct DENM_PDU_Description_AlacarteContainer__ext1, _asn_ctx),
	asn_MAP_ext1_tag2el_9,
	2,	/* Count of tags in the map */
	asn_MAP_ext1_oms_9,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ext1_9 = {
	"ext1",
	"ext1",
	&asn_OP_SEQUENCE,
	asn_DEF_ext1_tags_9,
	sizeof(asn_DEF_ext1_tags_9)
		/sizeof(asn_DEF_ext1_tags_9[0]) - 1, /* 1 */
	asn_DEF_ext1_tags_9,	/* Same as above */
	sizeof(asn_DEF_ext1_tags_9)
		/sizeof(asn_DEF_ext1_tags_9[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_ext1_9,
	2,	/* Elements count */
	&asn_SPC_ext1_specs_9	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_DENM_PDU_Description_AlacarteContainer_1[] = {
	{ ATF_POINTER, 7, offsetof(struct DENM_PDU_Description_AlacarteContainer, lanePosition),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_LanePosition,
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
		"lanePosition"
		},
	{ ATF_POINTER, 6, offsetof(struct DENM_PDU_Description_AlacarteContainer, impactReduction),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DENM_PDU_Description_ImpactReductionContainer,
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
		"impactReduction"
		},
	{ ATF_POINTER, 5, offsetof(struct DENM_PDU_Description_AlacarteContainer, externalTemperature),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_Temperature,
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
		"externalTemperature"
		},
	{ ATF_POINTER, 4, offsetof(struct DENM_PDU_Description_AlacarteContainer, roadWorks),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DENM_PDU_Description_RoadWorksContainerExtended,
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
		"roadWorks"
		},
	{ ATF_POINTER, 3, offsetof(struct DENM_PDU_Description_AlacarteContainer, positioningSolution),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ETSI_ITS_CDD_PositioningSolutionType,
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
		"positioningSolution"
		},
	{ ATF_POINTER, 2, offsetof(struct DENM_PDU_Description_AlacarteContainer, stationaryVehicle),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DENM_PDU_Description_StationaryVehicleContainer,
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
		"stationaryVehicle"
		},
	{ ATF_POINTER, 1, offsetof(struct DENM_PDU_Description_AlacarteContainer, ext1),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		0,
		&asn_DEF_ext1_9,
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
		"ext1"
		},
};
static const int asn_MAP_DENM_PDU_Description_AlacarteContainer_oms_1[] = { 0, 1, 2, 3, 4, 5, 6 };
static const ber_tlv_tag_t asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DENM_PDU_Description_AlacarteContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lanePosition */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* impactReduction */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* externalTemperature */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* roadWorks */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* positioningSolution */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* stationaryVehicle */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* ext1 */
};
asn_SEQUENCE_specifics_t asn_SPC_DENM_PDU_Description_AlacarteContainer_specs_1 = {
	sizeof(struct DENM_PDU_Description_AlacarteContainer),
	offsetof(struct DENM_PDU_Description_AlacarteContainer, _asn_ctx),
	asn_MAP_DENM_PDU_Description_AlacarteContainer_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_DENM_PDU_Description_AlacarteContainer_oms_1,	/* Optional members */
	6, 1,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_DENM_PDU_Description_AlacarteContainer = {
	"AlacarteContainer",
	"AlacarteContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1,
	sizeof(asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1)
		/sizeof(asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1[0]), /* 1 */
	asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1,	/* Same as above */
	sizeof(asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1)
		/sizeof(asn_DEF_DENM_PDU_Description_AlacarteContainer_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_DENM_PDU_Description_AlacarteContainer_1,
	7,	/* Elements count */
	&asn_SPC_DENM_PDU_Description_AlacarteContainer_specs_1	/* Additional specs */
};

