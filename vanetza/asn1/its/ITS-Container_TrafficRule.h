/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_TrafficRule_H_
#define	_ITS_Container_TrafficRule_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITS_Container_TrafficRule {
	ITS_Container_TrafficRule_noPassing	= 0,
	ITS_Container_TrafficRule_noPassingForTrucks	= 1,
	ITS_Container_TrafficRule_passToRight	= 2,
	ITS_Container_TrafficRule_passToLeft	= 3
	/*
	 * Enumeration is extensible
	 */
} e_ITS_Container_TrafficRule;

/* ITS-Container_TrafficRule */
typedef long	 ITS_Container_TrafficRule_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ITS_Container_TrafficRule_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_TrafficRule;
extern const asn_INTEGER_specifics_t asn_SPC_ITS_Container_TrafficRule_specs_1;
asn_struct_free_f ITS_Container_TrafficRule_free;
asn_struct_print_f ITS_Container_TrafficRule_print;
asn_constr_check_f ITS_Container_TrafficRule_constraint;
ber_type_decoder_f ITS_Container_TrafficRule_decode_ber;
der_type_encoder_f ITS_Container_TrafficRule_encode_der;
xer_type_decoder_f ITS_Container_TrafficRule_decode_xer;
xer_type_encoder_f ITS_Container_TrafficRule_encode_xer;
jer_type_encoder_f ITS_Container_TrafficRule_encode_jer;
oer_type_decoder_f ITS_Container_TrafficRule_decode_oer;
oer_type_encoder_f ITS_Container_TrafficRule_encode_oer;
per_type_decoder_f ITS_Container_TrafficRule_decode_uper;
per_type_encoder_f ITS_Container_TrafficRule_encode_uper;
per_type_decoder_f ITS_Container_TrafficRule_decode_aper;
per_type_encoder_f ITS_Container_TrafficRule_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_TrafficRule_H_ */
#include "asn_internal.h"
