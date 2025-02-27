/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Description"
 * 	found in "asn1/CAM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ExtensionContainerId_H_
#define	_ExtensionContainerId_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ExtensionContainerId */
typedef long	 ExtensionContainerId_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ExtensionContainerId_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ExtensionContainerId;
asn_struct_free_f ExtensionContainerId_free;
asn_struct_print_f ExtensionContainerId_print;
asn_constr_check_f ExtensionContainerId_constraint;
ber_type_decoder_f ExtensionContainerId_decode_ber;
der_type_encoder_f ExtensionContainerId_encode_der;
xer_type_decoder_f ExtensionContainerId_decode_xer;
xer_type_encoder_f ExtensionContainerId_encode_xer;
jer_type_encoder_f ExtensionContainerId_encode_jer;
oer_type_decoder_f ExtensionContainerId_decode_oer;
oer_type_encoder_f ExtensionContainerId_encode_oer;
per_type_decoder_f ExtensionContainerId_decode_uper;
per_type_encoder_f ExtensionContainerId_encode_uper;
per_type_decoder_f ExtensionContainerId_decode_aper;
per_type_encoder_f ExtensionContainerId_encode_aper;
#define ExtensionContainerId_twoWheelerContainer	((ExtensionContainerId_t)1)
#define ExtensionContainerId_eHorizonLocationSharingContainer	((ExtensionContainerId_t)2)
#define ExtensionContainerId_veryLowFrequencyContainer	((ExtensionContainerId_t)3)
#define ExtensionContainerId_pathPredictionContainer	((ExtensionContainerId_t)4)
#define ExtensionContainerId_generalizedLanePositionsContainer	((ExtensionContainerId_t)5)
#define ExtensionContainerId_vehicleMovementControlContainer	((ExtensionContainerId_t)6)

#ifdef __cplusplus
}
#endif

#endif	/* _ExtensionContainerId_H_ */
#include "asn_internal.h"
