/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PayUnit_H_
#define	_PayUnit_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PayUnit */
typedef OCTET_STRING_t	 PayUnit_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PayUnit_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PayUnit;
asn_struct_free_f PayUnit_free;
asn_struct_print_f PayUnit_print;
asn_constr_check_f PayUnit_constraint;
ber_type_decoder_f PayUnit_decode_ber;
der_type_encoder_f PayUnit_encode_der;
xer_type_decoder_f PayUnit_decode_xer;
xer_type_encoder_f PayUnit_encode_xer;
jer_type_encoder_f PayUnit_encode_jer;
oer_type_decoder_f PayUnit_decode_oer;
oer_type_encoder_f PayUnit_encode_oer;
per_type_decoder_f PayUnit_decode_uper;
per_type_encoder_f PayUnit_encode_uper;
per_type_decoder_f PayUnit_decode_aper;
per_type_encoder_f PayUnit_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PayUnit_H_ */
#include "asn_internal.h"
