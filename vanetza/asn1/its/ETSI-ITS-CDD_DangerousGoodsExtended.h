/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_DangerousGoodsExtended_H_
#define	_ETSI_ITS_CDD_DangerousGoodsExtended_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_DangerousGoodsBasic.h"
#include "NativeInteger.h"
#include "BOOLEAN.h"
#include "IA5String.h"
#include "ETSI-ITS-CDD_PhoneNumber.h"
#include "UTF8String.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ETSI-ITS-CDD_DangerousGoodsExtended */
typedef struct ETSI_ITS_CDD_DangerousGoodsExtended {
	ETSI_ITS_CDD_DangerousGoodsBasic_t	 dangerousGoodsType;
	long	 unNumber;
	BOOLEAN_t	 elevatedTemperature;
	BOOLEAN_t	 tunnelsRestricted;
	BOOLEAN_t	 limitedQuantity;
	IA5String_t	*emergencyActionCode;	/* OPTIONAL */
	ETSI_ITS_CDD_PhoneNumber_t	*phoneNumber;	/* OPTIONAL */
	UTF8String_t	*companyName;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ETSI_ITS_CDD_DangerousGoodsExtended_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_DangerousGoodsExtended;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_DangerousGoodsExtended_H_ */
#include "asn_internal.h"