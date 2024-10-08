/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ETSI_ITS_CDD_VruDeviceUsage_H_
#define	_ETSI_ITS_CDD_VruDeviceUsage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ETSI_ITS_CDD_VruDeviceUsage {
	ETSI_ITS_CDD_VruDeviceUsage_unavailable	= 0,
	ETSI_ITS_CDD_VruDeviceUsage_other	= 1,
	ETSI_ITS_CDD_VruDeviceUsage_idle	= 2,
	ETSI_ITS_CDD_VruDeviceUsage_listeningToAudio	= 3,
	ETSI_ITS_CDD_VruDeviceUsage_typing	= 4,
	ETSI_ITS_CDD_VruDeviceUsage_calling	= 5,
	ETSI_ITS_CDD_VruDeviceUsage_playingGames	= 6,
	ETSI_ITS_CDD_VruDeviceUsage_reading	= 7,
	ETSI_ITS_CDD_VruDeviceUsage_viewing	= 8
} e_ETSI_ITS_CDD_VruDeviceUsage;

/* ETSI-ITS-CDD_VruDeviceUsage */
typedef long	 ETSI_ITS_CDD_VruDeviceUsage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ETSI_ITS_CDD_VruDeviceUsage;
asn_struct_free_f ETSI_ITS_CDD_VruDeviceUsage_free;
asn_struct_print_f ETSI_ITS_CDD_VruDeviceUsage_print;
asn_constr_check_f ETSI_ITS_CDD_VruDeviceUsage_constraint;
ber_type_decoder_f ETSI_ITS_CDD_VruDeviceUsage_decode_ber;
der_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_der;
xer_type_decoder_f ETSI_ITS_CDD_VruDeviceUsage_decode_xer;
xer_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_xer;
jer_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_jer;
oer_type_decoder_f ETSI_ITS_CDD_VruDeviceUsage_decode_oer;
oer_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_oer;
per_type_decoder_f ETSI_ITS_CDD_VruDeviceUsage_decode_uper;
per_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_uper;
per_type_decoder_f ETSI_ITS_CDD_VruDeviceUsage_decode_aper;
per_type_encoder_f ETSI_ITS_CDD_VruDeviceUsage_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ETSI_ITS_CDD_VruDeviceUsage_H_ */
#include "asn_internal.h"
