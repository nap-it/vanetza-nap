/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_UsageIndication_H_
#define	_UsageIndication_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UsageIndication {
	UsageIndication_noIndication	= 0,
	UsageIndication_specialUse	= 1,
	UsageIndication_rescueOperation	= 2
	/*
	 * Enumeration is extensible
	 */
} e_UsageIndication;

/* UsageIndication */
typedef long	 UsageIndication_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_UsageIndication_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_UsageIndication;
extern const asn_INTEGER_specifics_t asn_SPC_UsageIndication_specs_1;
asn_struct_free_f UsageIndication_free;
asn_struct_print_f UsageIndication_print;
asn_constr_check_f UsageIndication_constraint;
ber_type_decoder_f UsageIndication_decode_ber;
der_type_encoder_f UsageIndication_encode_der;
xer_type_decoder_f UsageIndication_decode_xer;
xer_type_encoder_f UsageIndication_encode_xer;
jer_type_encoder_f UsageIndication_encode_jer;
oer_type_decoder_f UsageIndication_decode_oer;
oer_type_encoder_f UsageIndication_encode_oer;
per_type_decoder_f UsageIndication_decode_uper;
per_type_encoder_f UsageIndication_encode_uper;
per_type_decoder_f UsageIndication_decode_aper;
per_type_encoder_f UsageIndication_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _UsageIndication_H_ */
#include "asn_internal.h"
