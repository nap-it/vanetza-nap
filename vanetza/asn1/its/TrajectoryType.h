/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TrajectoryType_H_
#define	_TrajectoryType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TrajectoryType {
	TrajectoryType_referenceFollowMe	= 0,
	TrajectoryType_referenceGroup	= 1,
	TrajectoryType_advised	= 2,
	TrajectoryType_requested	= 3
} e_TrajectoryType;

/* TrajectoryType */
typedef long	 TrajectoryType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TrajectoryType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TrajectoryType;
extern const asn_INTEGER_specifics_t asn_SPC_TrajectoryType_specs_1;
asn_struct_free_f TrajectoryType_free;
asn_struct_print_f TrajectoryType_print;
asn_constr_check_f TrajectoryType_constraint;
ber_type_decoder_f TrajectoryType_decode_ber;
der_type_encoder_f TrajectoryType_encode_der;
xer_type_decoder_f TrajectoryType_decode_xer;
xer_type_encoder_f TrajectoryType_encode_xer;
jer_type_encoder_f TrajectoryType_encode_jer;
oer_type_decoder_f TrajectoryType_decode_oer;
oer_type_encoder_f TrajectoryType_encode_oer;
per_type_decoder_f TrajectoryType_decode_uper;
per_type_encoder_f TrajectoryType_encode_uper;
per_type_decoder_f TrajectoryType_decode_aper;
per_type_encoder_f TrajectoryType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TrajectoryType_H_ */
#include "asn_internal.h"
