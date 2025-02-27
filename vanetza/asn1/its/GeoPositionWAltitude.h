/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ETSI-ITS-CDD"
 * 	found in "iso/CDD-Release2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_GeoPositionWAltitude_H_
#define	_GeoPositionWAltitude_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ETSI-ITS-CDD_Latitude.h"
#include "ETSI-ITS-CDD_Longitude.h"
#include "ETSI-ITS-CDD_Altitude.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* GeoPositionWAltitude */
typedef struct GeoPositionWAltitude {
	ETSI_ITS_CDD_Latitude_t	 latitude;
	ETSI_ITS_CDD_Longitude_t	 longitude;
	ETSI_ITS_CDD_Altitude_t	 altitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GeoPositionWAltitude_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GeoPositionWAltitude;
extern asn_SEQUENCE_specifics_t asn_SPC_GeoPositionWAltitude_specs_1;
extern asn_TYPE_member_t asn_MBR_GeoPositionWAltitude_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _GeoPositionWAltitude_H_ */
#include "asn_internal.h"
