/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_AltitudeValue_H_
#define	_ITS_Container_AltitudeValue_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITS_Container_AltitudeValue {
	ITS_Container_AltitudeValue_referenceEllipsoidSurface	= 0,
	ITS_Container_AltitudeValue_oneCentimeter	= 1,
	ITS_Container_AltitudeValue_unavailable	= 800001
} e_ITS_Container_AltitudeValue;

/* ITS-Container_AltitudeValue */
typedef long	 ITS_Container_AltitudeValue_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ITS_Container_AltitudeValue_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_AltitudeValue;
asn_struct_free_f ITS_Container_AltitudeValue_free;
asn_struct_print_f ITS_Container_AltitudeValue_print;
asn_constr_check_f ITS_Container_AltitudeValue_constraint;
ber_type_decoder_f ITS_Container_AltitudeValue_decode_ber;
der_type_encoder_f ITS_Container_AltitudeValue_encode_der;
xer_type_decoder_f ITS_Container_AltitudeValue_decode_xer;
xer_type_encoder_f ITS_Container_AltitudeValue_encode_xer;
jer_type_encoder_f ITS_Container_AltitudeValue_encode_jer;
oer_type_decoder_f ITS_Container_AltitudeValue_decode_oer;
oer_type_encoder_f ITS_Container_AltitudeValue_encode_oer;
per_type_decoder_f ITS_Container_AltitudeValue_decode_uper;
per_type_encoder_f ITS_Container_AltitudeValue_encode_uper;
per_type_decoder_f ITS_Container_AltitudeValue_decode_aper;
per_type_encoder_f ITS_Container_AltitudeValue_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_AltitudeValue_H_ */
#include "asn_internal.h"
