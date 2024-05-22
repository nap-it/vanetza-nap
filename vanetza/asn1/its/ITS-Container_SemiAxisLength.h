/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_SemiAxisLength_H_
#define	_ITS_Container_SemiAxisLength_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITS_Container_SemiAxisLength {
	ITS_Container_SemiAxisLength_oneCentimeter	= 1,
	ITS_Container_SemiAxisLength_outOfRange	= 4094,
	ITS_Container_SemiAxisLength_unavailable	= 4095
} e_ITS_Container_SemiAxisLength;

/* ITS-Container_SemiAxisLength */
typedef long	 ITS_Container_SemiAxisLength_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ITS_Container_SemiAxisLength_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_SemiAxisLength;
asn_struct_free_f ITS_Container_SemiAxisLength_free;
asn_struct_print_f ITS_Container_SemiAxisLength_print;
asn_constr_check_f ITS_Container_SemiAxisLength_constraint;
ber_type_decoder_f ITS_Container_SemiAxisLength_decode_ber;
der_type_encoder_f ITS_Container_SemiAxisLength_encode_der;
xer_type_decoder_f ITS_Container_SemiAxisLength_decode_xer;
xer_type_encoder_f ITS_Container_SemiAxisLength_encode_xer;
jer_type_encoder_f ITS_Container_SemiAxisLength_encode_jer;
oer_type_decoder_f ITS_Container_SemiAxisLength_decode_oer;
oer_type_encoder_f ITS_Container_SemiAxisLength_encode_oer;
per_type_decoder_f ITS_Container_SemiAxisLength_decode_uper;
per_type_encoder_f ITS_Container_SemiAxisLength_encode_uper;
per_type_decoder_f ITS_Container_SemiAxisLength_decode_aper;
per_type_encoder_f ITS_Container_SemiAxisLength_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_SemiAxisLength_H_ */
#include "asn_internal.h"
