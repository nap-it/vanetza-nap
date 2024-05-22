/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "VehicleLicencePlateNumber.h"

/*
 * This type is implemented using LPN,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_VehicleLicencePlateNumber_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_VehicleLicencePlateNumber = {
	"VehicleLicencePlateNumber",
	"VehicleLicencePlateNumber",
	&asn_OP_SEQUENCE,
	asn_DEF_VehicleLicencePlateNumber_tags_1,
	sizeof(asn_DEF_VehicleLicencePlateNumber_tags_1)
		/sizeof(asn_DEF_VehicleLicencePlateNumber_tags_1[0]), /* 1 */
	asn_DEF_VehicleLicencePlateNumber_tags_1,	/* Same as above */
	sizeof(asn_DEF_VehicleLicencePlateNumber_tags_1)
		/sizeof(asn_DEF_VehicleLicencePlateNumber_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_LPN_1,
	3,	/* Elements count */
	&asn_SPC_LPN_specs_1	/* Additional specs */
};

