/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_TrafficConditionSubCauseCode_H_
#define	_ITS_Container_TrafficConditionSubCauseCode_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ITS_Container_TrafficConditionSubCauseCode {
	ITS_Container_TrafficConditionSubCauseCode_unavailable	= 0,
	ITS_Container_TrafficConditionSubCauseCode_increasedVolumeOfTraffic	= 1,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamSlowlyIncreasing	= 2,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamIncreasing	= 3,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamStronglyIncreasing	= 4,
	ITS_Container_TrafficConditionSubCauseCode_trafficStationary	= 5,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamSlightlyDecreasing	= 6,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamDecreasing	= 7,
	ITS_Container_TrafficConditionSubCauseCode_trafficJamStronglyDecreasing	= 8
} e_ITS_Container_TrafficConditionSubCauseCode;

/* ITS-Container_TrafficConditionSubCauseCode */
typedef long	 ITS_Container_TrafficConditionSubCauseCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_TrafficConditionSubCauseCode;
asn_struct_free_f ITS_Container_TrafficConditionSubCauseCode_free;
asn_struct_print_f ITS_Container_TrafficConditionSubCauseCode_print;
asn_constr_check_f ITS_Container_TrafficConditionSubCauseCode_constraint;
ber_type_decoder_f ITS_Container_TrafficConditionSubCauseCode_decode_ber;
der_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_der;
xer_type_decoder_f ITS_Container_TrafficConditionSubCauseCode_decode_xer;
xer_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_xer;
jer_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_jer;
oer_type_decoder_f ITS_Container_TrafficConditionSubCauseCode_decode_oer;
oer_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_oer;
per_type_decoder_f ITS_Container_TrafficConditionSubCauseCode_decode_uper;
per_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_uper;
per_type_decoder_f ITS_Container_TrafficConditionSubCauseCode_decode_aper;
per_type_encoder_f ITS_Container_TrafficConditionSubCauseCode_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_TrafficConditionSubCauseCode_H_ */
#include "asn_internal.h"
