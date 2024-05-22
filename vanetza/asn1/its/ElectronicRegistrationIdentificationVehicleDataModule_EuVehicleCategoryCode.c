/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ElectronicRegistrationIdentificationVehicleDataModule"
 * 	found in "iso/ISO24534-3.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode.h"

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
asn_per_constraints_t asn_PER_type_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  5 }	/* (0..5) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehicleCategoryL),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryL,
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
		"euVehicleCategoryL"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehicleCategoryM),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryM,
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
		"euVehicleCategoryM"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehicleCategoryN),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryN,
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
		"euVehicleCategoryN"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehicleCategoryO),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryO,
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
		"euVehicleCategoryO"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehilcleCategoryT),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
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
		"euVehilcleCategoryT"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, choice.euVehilcleCategoryG),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
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
		"euVehilcleCategoryG"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* euVehicleCategoryL */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* euVehicleCategoryM */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* euVehicleCategoryN */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* euVehicleCategoryO */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* euVehilcleCategoryT */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* euVehilcleCategoryG */
};
asn_CHOICE_specifics_t asn_SPC_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_specs_1 = {
	sizeof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode),
	offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, _asn_ctx),
	offsetof(struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode, present),
	sizeof(((struct ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode *)0)->present),
	asn_MAP_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode = {
	"EuVehicleCategoryCode",
	"EuVehicleCategoryCode",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_1,
	6,	/* Elements count */
	&asn_SPC_ElectronicRegistrationIdentificationVehicleDataModule_EuVehicleCategoryCode_specs_1	/* Additional specs */
};

