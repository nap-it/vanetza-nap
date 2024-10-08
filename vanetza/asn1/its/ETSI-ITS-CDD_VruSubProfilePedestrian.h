/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_VruSubProfilePedestrian_H_
#define	_ETSI_ITS_CDD_VruSubProfilePedestrian_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_VruSubProfilePedestrian {
	ETSI_ITS_CDD_VruSubProfilePedestrian_unavailable	= 0,
	ETSI_ITS_CDD_VruSubProfilePedestrian_ordinary_pedestrian	= 1,
	ETSI_ITS_CDD_VruSubProfilePedestrian_road_worker	= 2,
	ETSI_ITS_CDD_VruSubProfilePedestrian_first_responder	= 3
} e_ETSI_ITS_CDD_VruSubProfilePedestrian;

/* ETSI-ITS-CDD_VruSubProfilePedestrian */
typedef long	 ETSI_ITS_CDD_VruSubProfilePedestrian_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ETSI_ITS_CDD_VruSubProfilePedestrian_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_VruSubProfilePedestrian;
asn_struct_free_f ETSI_ITS_CDD_VruSubProfilePedestrian_free;
asn_struct_print_f ETSI_ITS_CDD_VruSubProfilePedestrian_print;
asn_constr_check_f ETSI_ITS_CDD_VruSubProfilePedestrian_constraint;
ber_type_decoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_VruSubProfilePedestrian_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_VruSubProfilePedestrian_H_ */
#include "asn_internal.h"
