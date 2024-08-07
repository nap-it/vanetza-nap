/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_FillingStatus_H_
#define	_FillingStatus_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum FillingStatus {
	FillingStatus_requestVehicleData	= 0,
	FillingStatus_sendVehicleData	= 1,
	FillingStatus_started	= 2,
	FillingStatus_fillingProcessFailed	= 3,
	FillingStatus_fillingProcessCompleted	= 4
} e_FillingStatus;

/* FillingStatus */
typedef long	 FillingStatus_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_FillingStatus_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_FillingStatus;
asn_struct_free_f FillingStatus_free;
asn_struct_print_f FillingStatus_print;
asn_constr_check_f FillingStatus_constraint;
ber_type_decoder_f FillingStatus_decode_ber;
der_type_encoder_f FillingStatus_encode_der;
xer_type_decoder_f FillingStatus_decode_xer;
xer_type_encoder_f FillingStatus_encode_xer;
jer_type_encoder_f FillingStatus_encode_jer;
oer_type_decoder_f FillingStatus_decode_oer;
oer_type_encoder_f FillingStatus_encode_oer;
per_type_decoder_f FillingStatus_decode_uper;
per_type_encoder_f FillingStatus_encode_uper;
per_type_decoder_f FillingStatus_decode_aper;
per_type_encoder_f FillingStatus_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _FillingStatus_H_ */
#include "asn_internal.h"
