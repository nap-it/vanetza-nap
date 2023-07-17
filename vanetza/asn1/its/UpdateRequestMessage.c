/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "/home/rrosmaninho/vanetza/asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R -D /home/rrosmaninho/vanetza/vanetza/asn1/its`
 */

#include "UpdateRequestMessage.h"

asn_TYPE_member_t asn_MBR_UpdateRequestMessage_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UpdateRequestMessage, reservation_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Reservation_ID,
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
		"reservation-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UpdateRequestMessage, reservation_Password),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Reservation_Password,
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
		"reservation-Password"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UpdateRequestMessage, updatedArrivalTime),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimestampUTC,
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
		"updatedArrivalTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UpdateRequestMessage, updatedDepartureTime),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimestampUTC,
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
		"updatedDepartureTime"
		},
};
static const ber_tlv_tag_t asn_DEF_UpdateRequestMessage_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_UpdateRequestMessage_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* reservation-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* reservation-Password */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* updatedArrivalTime */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* updatedDepartureTime */
};
asn_SEQUENCE_specifics_t asn_SPC_UpdateRequestMessage_specs_1 = {
	sizeof(struct UpdateRequestMessage),
	offsetof(struct UpdateRequestMessage, _asn_ctx),
	asn_MAP_UpdateRequestMessage_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_UpdateRequestMessage = {
	"UpdateRequestMessage",
	"UpdateRequestMessage",
	&asn_OP_SEQUENCE,
	asn_DEF_UpdateRequestMessage_tags_1,
	sizeof(asn_DEF_UpdateRequestMessage_tags_1)
		/sizeof(asn_DEF_UpdateRequestMessage_tags_1[0]), /* 1 */
	asn_DEF_UpdateRequestMessage_tags_1,	/* Same as above */
	sizeof(asn_DEF_UpdateRequestMessage_tags_1)
		/sizeof(asn_DEF_UpdateRequestMessage_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_UpdateRequestMessage_1,
	4,	/* Elements count */
	&asn_SPC_UpdateRequestMessage_specs_1	/* Additional specs */
};

