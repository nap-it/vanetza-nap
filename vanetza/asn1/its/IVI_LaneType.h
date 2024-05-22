/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "iso/ISO19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IVI_LaneType_H_
#define	_IVI_LaneType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IVI_LaneType {
	IVI_LaneType_traffic	= 0,
	IVI_LaneType_through	= 1,
	IVI_LaneType_reversible	= 2,
	IVI_LaneType_acceleration	= 3,
	IVI_LaneType_deceleration	= 4,
	IVI_LaneType_leftHandTurning	= 5,
	IVI_LaneType_rightHandTurning	= 6,
	IVI_LaneType_dedicatedVehicle	= 7,
	IVI_LaneType_bus	= 8,
	IVI_LaneType_taxi	= 9,
	IVI_LaneType_hov	= 10,
	IVI_LaneType_hot	= 11,
	IVI_LaneType_pedestrian	= 12,
	IVI_LaneType_bikeLane	= 13,
	IVI_LaneType_median	= 14,
	IVI_LaneType_striping	= 15,
	IVI_LaneType_trackedVehicle	= 16,
	IVI_LaneType_parking	= 17,
	IVI_LaneType_emergency	= 18,
	IVI_LaneType_verge	= 19,
	IVI_LaneType_minimumRiskManoeuvre	= 20
} e_IVI_LaneType;

/* IVI_LaneType */
typedef long	 IVI_LaneType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IVI_LaneType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IVI_LaneType;
asn_struct_free_f IVI_LaneType_free;
asn_struct_print_f IVI_LaneType_print;
asn_constr_check_f IVI_LaneType_constraint;
ber_type_decoder_f IVI_LaneType_decode_ber;
der_type_encoder_f IVI_LaneType_encode_der;
xer_type_decoder_f IVI_LaneType_decode_xer;
xer_type_encoder_f IVI_LaneType_encode_xer;
jer_type_encoder_f IVI_LaneType_encode_jer;
oer_type_decoder_f IVI_LaneType_decode_oer;
oer_type_encoder_f IVI_LaneType_encode_oer;
per_type_decoder_f IVI_LaneType_decode_uper;
per_type_encoder_f IVI_LaneType_encode_uper;
per_type_decoder_f IVI_LaneType_decode_aper;
per_type_encoder_f IVI_LaneType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _IVI_LaneType_H_ */
#include "asn_internal.h"
