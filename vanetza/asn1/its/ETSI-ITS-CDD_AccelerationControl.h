/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_AccelerationControl_H_
#define	_ETSI_ITS_CDD_AccelerationControl_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_AccelerationControl {
	ETSI_ITS_CDD_AccelerationControl_brakePedalEngaged	= 0,
	ETSI_ITS_CDD_AccelerationControl_gasPedalEngaged	= 1,
	ETSI_ITS_CDD_AccelerationControl_emergencyBrakeEngaged	= 2,
	ETSI_ITS_CDD_AccelerationControl_collisionWarningEngaged	= 3,
	ETSI_ITS_CDD_AccelerationControl_accEngaged	= 4,
	ETSI_ITS_CDD_AccelerationControl_cruiseControlEngaged	= 5,
	ETSI_ITS_CDD_AccelerationControl_speedLimiterEngaged	= 6
} e_ETSI_ITS_CDD_AccelerationControl;

/* ETSI-ITS-CDD_AccelerationControl */
typedef BIT_STRING_t	 ETSI_ITS_CDD_AccelerationControl_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_AccelerationControl;
asn_struct_free_f ETSI_ITS_CDD_AccelerationControl_free;
asn_struct_print_f ETSI_ITS_CDD_AccelerationControl_print;
asn_constr_check_f ETSI_ITS_CDD_AccelerationControl_constraint;
ber_type_decoder_f ETSI_ITS_CDD_AccelerationControl_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_AccelerationControl_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_AccelerationControl_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_AccelerationControl_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_AccelerationControl_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_AccelerationControl_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_AccelerationControl_H_ */
#include "asn_internal.h"
