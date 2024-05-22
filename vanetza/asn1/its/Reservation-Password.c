/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "Reservation-Password.h"

static int check_permitted_alphabet_1(const void *sptr) {
	/* The underlying type is VisibleString */
	const VisibleString_t *st = (const VisibleString_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!(cv >= 32UL && cv <= 126UL)) return -1;
	}
	return 0;
}

int
Reservation_Password_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const VisibleString_t *st = (const VisibleString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 8UL)
		 && !check_permitted_alphabet_1(st)) {
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
 * This type is implemented using VisibleString,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_Reservation_Password_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	8	/* (SIZE(8..8)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_Reservation_Password_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  32,  126 }	/* (32..126) */,
	{ APC_CONSTRAINED,	 0,  0,  8,  8 }	/* (SIZE(8..8)) */,
	0, 0	/* No PER character map necessary */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const ber_tlv_tag_t asn_DEF_Reservation_Password_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (26 << 2))
};
asn_TYPE_descriptor_t asn_DEF_Reservation_Password = {
	"Reservation-Password",
	"Reservation-Password",
	&asn_OP_VisibleString,
	asn_DEF_Reservation_Password_tags_1,
	sizeof(asn_DEF_Reservation_Password_tags_1)
		/sizeof(asn_DEF_Reservation_Password_tags_1[0]), /* 1 */
	asn_DEF_Reservation_Password_tags_1,	/* Same as above */
	sizeof(asn_DEF_Reservation_Password_tags_1)
		/sizeof(asn_DEF_Reservation_Password_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_Reservation_Password_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_Reservation_Password_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		Reservation_Password_constraint
	},
	0, 0,	/* No members */
	0	/* No specifics */
};

