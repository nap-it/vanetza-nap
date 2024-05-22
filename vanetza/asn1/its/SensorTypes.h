/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_SensorTypes_H_
#define	_SensorTypes_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SensorTypes {
	SensorTypes_undefined	= 0,
	SensorTypes_radar	= 1,
	SensorTypes_lidar	= 2,
	SensorTypes_monovideo	= 3,
	SensorTypes_stereovision	= 4,
	SensorTypes_nightvision	= 5,
	SensorTypes_ultrasonic	= 6,
	SensorTypes_pmd	= 7,
	SensorTypes_inductionLoop	= 8,
	SensorTypes_sphericalCamera	= 9,
	SensorTypes_uwb	= 10,
	SensorTypes_acoustic	= 11,
	SensorTypes_localAggregation	= 12,
	SensorTypes_itsAggregation	= 13
} e_SensorTypes;

/* SensorTypes */
typedef BIT_STRING_t	 SensorTypes_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SensorTypes_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SensorTypes;
asn_struct_free_f SensorTypes_free;
asn_struct_print_f SensorTypes_print;
asn_constr_check_f SensorTypes_constraint;
ber_type_decoder_f SensorTypes_decode_ber;
der_type_encoder_f SensorTypes_encode_der;
xer_type_decoder_f SensorTypes_decode_xer;
xer_type_encoder_f SensorTypes_encode_xer;
jer_type_encoder_f SensorTypes_encode_jer;
oer_type_decoder_f SensorTypes_decode_oer;
oer_type_encoder_f SensorTypes_encode_oer;
per_type_decoder_f SensorTypes_decode_uper;
per_type_encoder_f SensorTypes_encode_uper;
per_type_decoder_f SensorTypes_decode_aper;
per_type_encoder_f SensorTypes_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _SensorTypes_H_ */
#include "asn_internal.h"
