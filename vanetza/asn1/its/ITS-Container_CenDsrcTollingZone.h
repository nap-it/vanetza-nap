/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "asn1/TS102894-2v131-CDD.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ITS_Container_CenDsrcTollingZone_H_
#define	_ITS_Container_CenDsrcTollingZone_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_Latitude.h"
#include "ITS-Container_Longitude.h"
#include "ITS-Container_CenDsrcTollingZoneID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ITS-Container_CenDsrcTollingZone */
typedef struct ITS_Container_CenDsrcTollingZone {
	ITS_Container_Latitude_t	 protectedZoneLatitude;
	ITS_Container_Longitude_t	 protectedZoneLongitude;
	ITS_Container_CenDsrcTollingZoneID_t	*cenDsrcTollingZoneID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ITS_Container_CenDsrcTollingZone_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ITS_Container_CenDsrcTollingZone;
extern asn_SEQUENCE_specifics_t asn_SPC_ITS_Container_CenDsrcTollingZone_specs_1;
extern asn_TYPE_member_t asn_MBR_ITS_Container_CenDsrcTollingZone_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _ITS_Container_CenDsrcTollingZone_H_ */
#include "asn_internal.h"
