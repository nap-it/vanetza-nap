/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EVCSN-PDU-Descriptions"
 * 	found in "/home/rrosmaninho/vanetza/asn1/EVCSN-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R -D /home/rrosmaninho/vanetza/vanetza/asn1/its`
 */

#include "ChargingSpotType.h"

/*
 * This type is implemented using BIT_STRING,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_ChargingSpotType_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (3 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ChargingSpotType = {
	"ChargingSpotType",
	"ChargingSpotType",
	&asn_OP_BIT_STRING,
	asn_DEF_ChargingSpotType_tags_1,
	sizeof(asn_DEF_ChargingSpotType_tags_1)
		/sizeof(asn_DEF_ChargingSpotType_tags_1[0]), /* 1 */
	asn_DEF_ChargingSpotType_tags_1,	/* Same as above */
	sizeof(asn_DEF_ChargingSpotType_tags_1)
		/sizeof(asn_DEF_ChargingSpotType_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		BIT_STRING_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_BIT_STRING_specs	/* Additional specs */
};

