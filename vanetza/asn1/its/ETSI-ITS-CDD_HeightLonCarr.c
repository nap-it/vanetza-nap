/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ETSI-ITS-CDD_HeightLonCarr.h"

int
ETSI_ITS_CDD_HeightLonCarr_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1L && value <= 100L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using NativeInteger,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ETSI_ITS_CDD_HeightLonCarr_constr_1 CC_NOTUSED = {
	{ 1, 1 }	/* (1..100) */,
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_ETSI_ITS_CDD_HeightLonCarr_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  1,  100 }	/* (1..100) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const ber_tlv_tag_t asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_HeightLonCarr = {
	"HeightLonCarr",
	"HeightLonCarr",
	&asn_OP_NativeInteger,
	asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1,
	sizeof(asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1[0]), /* 1 */
	asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1,	/* Same as above */
	sizeof(asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1)
		/sizeof(asn_DEF_ETSI_ITS_CDD_HeightLonCarr_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ETSI_ITS_CDD_HeightLonCarr_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ETSI_ITS_CDD_HeightLonCarr_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		ETSI_ITS_CDD_HeightLonCarr_constraint
	},
	0, 0,	/* Defined elsewhere */
	0	/* No specifics */
};

