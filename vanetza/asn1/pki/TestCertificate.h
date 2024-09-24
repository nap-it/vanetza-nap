/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IEEE1609dot2"
 * 	found in "asn1/IEEE1609dot2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TestCertificate_H_
#define	_TestCertificate_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Certificate.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TestCertificate */
typedef Certificate_t	 TestCertificate_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TestCertificate;
asn_struct_free_f TestCertificate_free;
asn_struct_print_f TestCertificate_print;
asn_constr_check_f TestCertificate_constraint;
ber_type_decoder_f TestCertificate_decode_ber;
der_type_encoder_f TestCertificate_encode_der;
xer_type_decoder_f TestCertificate_decode_xer;
xer_type_encoder_f TestCertificate_encode_xer;
jer_type_encoder_f TestCertificate_encode_jer;
oer_type_decoder_f TestCertificate_decode_oer;
oer_type_encoder_f TestCertificate_encode_oer;
per_type_decoder_f TestCertificate_decode_uper;
per_type_encoder_f TestCertificate_encode_uper;
per_type_decoder_f TestCertificate_decode_aper;
per_type_encoder_f TestCertificate_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TestCertificate_H_ */
#include "asn_internal.h"