/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_YawRateConfidence_H_
#define	_ETSI_ITS_CDD_YawRateConfidence_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_YawRateConfidence {
	ETSI_ITS_CDD_YawRateConfidence_degSec_000_01	= 0,
	ETSI_ITS_CDD_YawRateConfidence_degSec_000_05	= 1,
	ETSI_ITS_CDD_YawRateConfidence_degSec_000_10	= 2,
	ETSI_ITS_CDD_YawRateConfidence_degSec_001_00	= 3,
	ETSI_ITS_CDD_YawRateConfidence_degSec_005_00	= 4,
	ETSI_ITS_CDD_YawRateConfidence_degSec_010_00	= 5,
	ETSI_ITS_CDD_YawRateConfidence_degSec_100_00	= 6,
	ETSI_ITS_CDD_YawRateConfidence_outOfRange	= 7,
	ETSI_ITS_CDD_YawRateConfidence_unavailable	= 8
} e_ETSI_ITS_CDD_YawRateConfidence;

/* ETSI-ITS-CDD_YawRateConfidence */
typedef long	 ETSI_ITS_CDD_YawRateConfidence_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ETSI_ITS_CDD_YawRateConfidence_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_YawRateConfidence;
extern const asn_INTEGER_specifics_t asn_SPC_ETSI_ITS_CDD_YawRateConfidence_specs_1;
asn_struct_free_f ETSI_ITS_CDD_YawRateConfidence_free;
asn_struct_print_f ETSI_ITS_CDD_YawRateConfidence_print;
asn_constr_check_f ETSI_ITS_CDD_YawRateConfidence_constraint;
ber_type_decoder_f ETSI_ITS_CDD_YawRateConfidence_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_YawRateConfidence_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_YawRateConfidence_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_YawRateConfidence_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_YawRateConfidence_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_YawRateConfidence_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_YawRateConfidence_H_ */
#include "asn_internal.h"
