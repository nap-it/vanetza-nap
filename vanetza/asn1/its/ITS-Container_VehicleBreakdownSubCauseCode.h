/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_VehicleBreakdownSubCauseCode_H_
#define	_ITS_Container_VehicleBreakdownSubCauseCode_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITS_Container_VehicleBreakdownSubCauseCode {
	ITS_Container_VehicleBreakdownSubCauseCode_unavailable	= 0,
	ITS_Container_VehicleBreakdownSubCauseCode_lackOfFuel	= 1,
	ITS_Container_VehicleBreakdownSubCauseCode_lackOfBatteryPower	= 2,
	ITS_Container_VehicleBreakdownSubCauseCode_engineProblem	= 3,
	ITS_Container_VehicleBreakdownSubCauseCode_transmissionProblem	= 4,
	ITS_Container_VehicleBreakdownSubCauseCode_engineCoolingProblem	= 5,
	ITS_Container_VehicleBreakdownSubCauseCode_brakingSystemProblem	= 6,
	ITS_Container_VehicleBreakdownSubCauseCode_steeringProblem	= 7,
	ITS_Container_VehicleBreakdownSubCauseCode_tyrePuncture	= 8,
	ITS_Container_VehicleBreakdownSubCauseCode_tyrePressureProblem	= 9
} e_ITS_Container_VehicleBreakdownSubCauseCode;

/* ITS-Container_VehicleBreakdownSubCauseCode */
typedef long	 ITS_Container_VehicleBreakdownSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_VehicleBreakdownSubCauseCode;
asn_struct_free_f ITS_Container_VehicleBreakdownSubCauseCode_free;
asn_struct_print_f ITS_Container_VehicleBreakdownSubCauseCode_print;
asn_constr_check_f ITS_Container_VehicleBreakdownSubCauseCode_constraint;
ber_type_decoder_f ITS_Container_VehicleBreakdownSubCauseCode_decode_ber;
der_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_der;
xer_type_decoder_f ITS_Container_VehicleBreakdownSubCauseCode_decode_xer;
xer_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_xer;
jer_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_jer;
oer_type_decoder_f ITS_Container_VehicleBreakdownSubCauseCode_decode_oer;
oer_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_oer;
per_type_decoder_f ITS_Container_VehicleBreakdownSubCauseCode_decode_uper;
per_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_uper;
per_type_decoder_f ITS_Container_VehicleBreakdownSubCauseCode_decode_aper;
per_type_encoder_f ITS_Container_VehicleBreakdownSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_VehicleBreakdownSubCauseCode_H_ */
#include "asn_internal.h"
