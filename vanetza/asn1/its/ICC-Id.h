/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "iso/ISO14906-0-6.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ICC_Id_H_
#define	_ICC_Id_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ICC-Id */
typedef OCTET_STRING_t	 ICC_Id_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ICC_Id;
asn_struct_free_f ICC_Id_free;
asn_struct_print_f ICC_Id_print;
asn_constr_check_f ICC_Id_constraint;
ber_type_decoder_f ICC_Id_decode_ber;
der_type_encoder_f ICC_Id_encode_der;
xer_type_decoder_f ICC_Id_decode_xer;
xer_type_encoder_f ICC_Id_encode_xer;
jer_type_encoder_f ICC_Id_encode_jer;
oer_type_decoder_f ICC_Id_decode_oer;
oer_type_encoder_f ICC_Id_encode_oer;
per_type_decoder_f ICC_Id_decode_uper;
per_type_encoder_f ICC_Id_encode_uper;
per_type_decoder_f ICC_Id_decode_aper;
per_type_encoder_f ICC_Id_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ICC_Id_H_ */
#include "asn_internal.h"
