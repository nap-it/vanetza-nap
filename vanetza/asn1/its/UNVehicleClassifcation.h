/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_UNVehicleClassifcation_H_
#define	_UNVehicleClassifcation_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UNVehicleClassifcation {
	UNVehicleClassifcation_reserved	= 0,
	UNVehicleClassifcation_categoryL1	= 1,
	UNVehicleClassifcation_categoryL2	= 2,
	UNVehicleClassifcation_categoryL3	= 3,
	UNVehicleClassifcation_categoryL4	= 4,
	UNVehicleClassifcation_categoryL5	= 5,
	UNVehicleClassifcation_categoryL6	= 6,
	UNVehicleClassifcation_categoryL7	= 7,
	UNVehicleClassifcation_categoryL8	= 8
} e_UNVehicleClassifcation;

/* UNVehicleClassifcation */
typedef long	 UNVehicleClassifcation_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_UNVehicleClassifcation_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_UNVehicleClassifcation;
asn_struct_free_f UNVehicleClassifcation_free;
asn_struct_print_f UNVehicleClassifcation_print;
asn_constr_check_f UNVehicleClassifcation_constraint;
ber_type_decoder_f UNVehicleClassifcation_decode_ber;
der_type_encoder_f UNVehicleClassifcation_encode_der;
xer_type_decoder_f UNVehicleClassifcation_decode_xer;
xer_type_encoder_f UNVehicleClassifcation_encode_xer;
oer_type_decoder_f UNVehicleClassifcation_decode_oer;
oer_type_encoder_f UNVehicleClassifcation_encode_oer;
per_type_decoder_f UNVehicleClassifcation_decode_uper;
per_type_encoder_f UNVehicleClassifcation_encode_uper;
per_type_decoder_f UNVehicleClassifcation_decode_aper;
per_type_encoder_f UNVehicleClassifcation_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _UNVehicleClassifcation_H_ */
#include "asn_internal.h"
