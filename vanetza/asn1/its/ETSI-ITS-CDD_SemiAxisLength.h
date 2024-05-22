/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_SemiAxisLength_H_
#define	_ETSI_ITS_CDD_SemiAxisLength_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_SemiAxisLength {
	ETSI_ITS_CDD_SemiAxisLength_doNotUse	= 0,
	ETSI_ITS_CDD_SemiAxisLength_outOfRange	= 4094,
	ETSI_ITS_CDD_SemiAxisLength_unavailable	= 4095
} e_ETSI_ITS_CDD_SemiAxisLength;

/* ETSI-ITS-CDD_SemiAxisLength */
typedef long	 ETSI_ITS_CDD_SemiAxisLength_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ETSI_ITS_CDD_SemiAxisLength_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_SemiAxisLength;
asn_struct_free_f ETSI_ITS_CDD_SemiAxisLength_free;
asn_struct_print_f ETSI_ITS_CDD_SemiAxisLength_print;
asn_constr_check_f ETSI_ITS_CDD_SemiAxisLength_constraint;
ber_type_decoder_f ETSI_ITS_CDD_SemiAxisLength_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_SemiAxisLength_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_SemiAxisLength_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_SemiAxisLength_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_SemiAxisLength_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_SemiAxisLength_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_SemiAxisLength_H_ */
#include "asn_internal.h"
