/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ContractID_H_
#define	_ContractID_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UTF8String.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ContractID */
typedef UTF8String_t	 ContractID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ContractID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ContractID;
asn_struct_free_f ContractID_free;
asn_struct_print_f ContractID_print;
asn_constr_check_f ContractID_constraint;
ber_type_decoder_f ContractID_decode_ber;
der_type_encoder_f ContractID_encode_der;
xer_type_decoder_f ContractID_decode_xer;
xer_type_encoder_f ContractID_encode_xer;
jer_type_encoder_f ContractID_encode_jer;
oer_type_decoder_f ContractID_decode_oer;
oer_type_encoder_f ContractID_encode_oer;
per_type_decoder_f ContractID_decode_uper;
per_type_encoder_f ContractID_encode_uper;
per_type_decoder_f ContractID_decode_aper;
per_type_encoder_f ContractID_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ContractID_H_ */
#include "asn_internal.h"
