/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ReservationResponseCode.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ReservationResponseCode_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_ReservationResponseCode_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  5 }	/* (0..5) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_ReservationResponseCode_value2enum_1[] = {
	{ 0,	2,	"ok" },
	{ 1,	15,	"invalid-EVSE-ID" },
	{ 2,	26,	"payment-type-not-supported" },
	{ 3,	13,	"payment-error" },
	{ 4,	20,	"authentication-error" },
	{ 5,	31,	"insufficient-power-availability" }
};
static const unsigned int asn_MAP_ReservationResponseCode_enum2value_1[] = {
	4,	/* authentication-error(4) */
	5,	/* insufficient-power-availability(5) */
	1,	/* invalid-EVSE-ID(1) */
	0,	/* ok(0) */
	3,	/* payment-error(3) */
	2	/* payment-type-not-supported(2) */
};
const asn_INTEGER_specifics_t asn_SPC_ReservationResponseCode_specs_1 = {
	asn_MAP_ReservationResponseCode_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_ReservationResponseCode_enum2value_1,	/* N => "tag"; sorted by N */
	6,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ReservationResponseCode_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ReservationResponseCode = {
	"ReservationResponseCode",
	"ReservationResponseCode",
	&asn_OP_NativeEnumerated,
	asn_DEF_ReservationResponseCode_tags_1,
	sizeof(asn_DEF_ReservationResponseCode_tags_1)
		/sizeof(asn_DEF_ReservationResponseCode_tags_1[0]), /* 1 */
	asn_DEF_ReservationResponseCode_tags_1,	/* Same as above */
	sizeof(asn_DEF_ReservationResponseCode_tags_1)
		/sizeof(asn_DEF_ReservationResponseCode_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ReservationResponseCode_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ReservationResponseCode_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ReservationResponseCode_specs_1	/* Additional specs */
};

