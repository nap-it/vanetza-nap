/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_TrafficRule_H_
#define	_ETSI_ITS_CDD_TrafficRule_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_TrafficRule {
	ETSI_ITS_CDD_TrafficRule_noPassing	= 0,
	ETSI_ITS_CDD_TrafficRule_noPassingForTrucks	= 1,
	ETSI_ITS_CDD_TrafficRule_passToRight	= 2,
	ETSI_ITS_CDD_TrafficRule_passToLeft	= 3,
	/*
	 * Enumeration is extensible
	 */
	ETSI_ITS_CDD_TrafficRule_passToLeftOrRight	= 4
} e_ETSI_ITS_CDD_TrafficRule;

/* ETSI-ITS-CDD_TrafficRule */
typedef long	 ETSI_ITS_CDD_TrafficRule_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_TrafficRule;
asn_struct_free_f ETSI_ITS_CDD_TrafficRule_free;
asn_struct_print_f ETSI_ITS_CDD_TrafficRule_print;
asn_constr_check_f ETSI_ITS_CDD_TrafficRule_constraint;
ber_type_decoder_f ETSI_ITS_CDD_TrafficRule_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_TrafficRule_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_TrafficRule_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_TrafficRule_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_TrafficRule_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_TrafficRule_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_TrafficRule_H_ */
#include "asn_internal.h"
