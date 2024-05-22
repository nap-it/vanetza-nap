/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "OccupiedLanesWithConfidence.h"

static int
memb_lanePositionBased_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1UL && size <= 4UL)) {
		/* Perform validation of the inner elements */
		return SEQUENCE_OF_constraint(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_mapBased_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1UL && size <= 4UL)) {
		/* Perform validation of the inner elements */
		return SEQUENCE_OF_constraint(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_lanePositionBased_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_lanePositionBased_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_mapBased_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_mapBased_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_lanePositionBased_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_lanePositionBased_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_mapBased_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_mapBased_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static asn_TYPE_member_t asn_MBR_lanePositionBased_2[] = {
	{ ATF_POINTER, 0, 0,
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_LanePositionOptions,
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
		""
		},
};
static const ber_tlv_tag_t asn_DEF_lanePositionBased_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_lanePositionBased_specs_2 = {
	sizeof(struct OccupiedLanesWithConfidence__lanePositionBased),
	offsetof(struct OccupiedLanesWithConfidence__lanePositionBased, _asn_ctx),
	2,	/* XER encoding is XMLValueList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_lanePositionBased_2 = {
	"lanePositionBased",
	"lanePositionBased",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_lanePositionBased_tags_2,
	sizeof(asn_DEF_lanePositionBased_tags_2)
		/sizeof(asn_DEF_lanePositionBased_tags_2[0]) - 1, /* 1 */
	asn_DEF_lanePositionBased_tags_2,	/* Same as above */
	sizeof(asn_DEF_lanePositionBased_tags_2)
		/sizeof(asn_DEF_lanePositionBased_tags_2[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_lanePositionBased_constr_2,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_lanePositionBased_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_lanePositionBased_2,
	1,	/* Single element */
	&asn_SPC_lanePositionBased_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_mapBased_4[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ETSI_ITS_CDD_MapPosition,
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
		""
		},
};
static const ber_tlv_tag_t asn_DEF_mapBased_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_mapBased_specs_4 = {
	sizeof(struct OccupiedLanesWithConfidence__mapBased),
	offsetof(struct OccupiedLanesWithConfidence__mapBased, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mapBased_4 = {
	"mapBased",
	"mapBased",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_mapBased_tags_4,
	sizeof(asn_DEF_mapBased_tags_4)
		/sizeof(asn_DEF_mapBased_tags_4[0]) - 1, /* 1 */
	asn_DEF_mapBased_tags_4,	/* Same as above */
	sizeof(asn_DEF_mapBased_tags_4)
		/sizeof(asn_DEF_mapBased_tags_4[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_mapBased_constr_4,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_mapBased_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_mapBased_4,
	1,	/* Single element */
	&asn_SPC_mapBased_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_OccupiedLanesWithConfidence_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct OccupiedLanesWithConfidence, lanePositionBased),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_lanePositionBased_2,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_lanePositionBased_constr_2,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_lanePositionBased_constr_2,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_lanePositionBased_constraint_1
		},
		0, 0, /* No default value */
		"lanePositionBased"
		},
	{ ATF_POINTER, 1, offsetof(struct OccupiedLanesWithConfidence, mapBased),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_mapBased_4,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_mapBased_constr_4,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_mapBased_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_mapBased_constraint_1
		},
		0, 0, /* No default value */
		"mapBased"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct OccupiedLanesWithConfidence, confidence),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MetaInformation,
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
		"confidence"
		},
};
static const int asn_MAP_OccupiedLanesWithConfidence_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_OccupiedLanesWithConfidence_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_OccupiedLanesWithConfidence_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lanePositionBased */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mapBased */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* confidence */
};
static asn_SEQUENCE_specifics_t asn_SPC_OccupiedLanesWithConfidence_specs_1 = {
	sizeof(struct OccupiedLanesWithConfidence),
	offsetof(struct OccupiedLanesWithConfidence, _asn_ctx),
	asn_MAP_OccupiedLanesWithConfidence_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_OccupiedLanesWithConfidence_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_OccupiedLanesWithConfidence = {
	"OccupiedLanesWithConfidence",
	"OccupiedLanesWithConfidence",
	&asn_OP_SEQUENCE,
	asn_DEF_OccupiedLanesWithConfidence_tags_1,
	sizeof(asn_DEF_OccupiedLanesWithConfidence_tags_1)
		/sizeof(asn_DEF_OccupiedLanesWithConfidence_tags_1[0]), /* 1 */
	asn_DEF_OccupiedLanesWithConfidence_tags_1,	/* Same as above */
	sizeof(asn_DEF_OccupiedLanesWithConfidence_tags_1)
		/sizeof(asn_DEF_OccupiedLanesWithConfidence_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_OccupiedLanesWithConfidence_1,
	3,	/* Elements count */
	&asn_SPC_OccupiedLanesWithConfidence_specs_1	/* Additional specs */
};

