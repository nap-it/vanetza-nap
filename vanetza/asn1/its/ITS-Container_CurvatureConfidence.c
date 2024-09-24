/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ITS-Container_CurvatureConfidence.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ITS_Container_CurvatureConfidence_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_ITS_Container_CurvatureConfidence_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  7 }	/* (0..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_ITS_Container_CurvatureConfidence_value2enum_1[] = {
	{ 0,	19,	"onePerMeter-0-00002" },
	{ 1,	18,	"onePerMeter-0-0001" },
	{ 2,	18,	"onePerMeter-0-0005" },
	{ 3,	17,	"onePerMeter-0-002" },
	{ 4,	16,	"onePerMeter-0-01" },
	{ 5,	15,	"onePerMeter-0-1" },
	{ 6,	10,	"outOfRange" },
	{ 7,	11,	"unavailable" }
};
static const unsigned int asn_MAP_ITS_Container_CurvatureConfidence_enum2value_1[] = {
	0,	/* onePerMeter-0-00002(0) */
	1,	/* onePerMeter-0-0001(1) */
	2,	/* onePerMeter-0-0005(2) */
	3,	/* onePerMeter-0-002(3) */
	4,	/* onePerMeter-0-01(4) */
	5,	/* onePerMeter-0-1(5) */
	6,	/* outOfRange(6) */
	7	/* unavailable(7) */
};
const asn_INTEGER_specifics_t asn_SPC_ITS_Container_CurvatureConfidence_specs_1 = {
	asn_MAP_ITS_Container_CurvatureConfidence_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_ITS_Container_CurvatureConfidence_enum2value_1,	/* N => "tag"; sorted by N */
	8,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ITS_Container_CurvatureConfidence_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ITS_Container_CurvatureConfidence = {
	"CurvatureConfidence",
	"CurvatureConfidence",
	&asn_OP_NativeEnumerated,
	asn_DEF_ITS_Container_CurvatureConfidence_tags_1,
	sizeof(asn_DEF_ITS_Container_CurvatureConfidence_tags_1)
		/sizeof(asn_DEF_ITS_Container_CurvatureConfidence_tags_1[0]), /* 1 */
	asn_DEF_ITS_Container_CurvatureConfidence_tags_1,	/* Same as above */
	sizeof(asn_DEF_ITS_Container_CurvatureConfidence_tags_1)
		/sizeof(asn_DEF_ITS_Container_CurvatureConfidence_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ITS_Container_CurvatureConfidence_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ITS_Container_CurvatureConfidence_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ITS_Container_CurvatureConfidence_specs_1	/* Additional specs */
};
