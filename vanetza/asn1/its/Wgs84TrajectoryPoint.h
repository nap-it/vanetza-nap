/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_Wgs84TrajectoryPoint_H_
#define	_Wgs84TrajectoryPoint_H_


#include "asn_application.h"

/* Including external dependencies */
#include "IntermediatePoint.h"
#include "ETSI-ITS-CDD_Longitude.h"
#include "ETSI-ITS-CDD_Latitude.h"
#include "ETSI-ITS-CDD_Speed.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ETSI_ITS_CDD_Altitude;
struct ETSI_ITS_CDD_Heading;

/* Wgs84TrajectoryPoint */
typedef struct Wgs84TrajectoryPoint {
	IntermediatePoint_t	 intermediatePoint;
	ETSI_ITS_CDD_Longitude_t	 longitudePosition;
	ETSI_ITS_CDD_Latitude_t	 latitudePosition;
	struct ETSI_ITS_CDD_Altitude	*altitudePosition;	/* OPTIONAL */
	struct ETSI_ITS_CDD_Heading	*headings;	/* OPTIONAL */
	ETSI_ITS_CDD_Speed_t	 speed;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Wgs84TrajectoryPoint_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Wgs84TrajectoryPoint;
extern asn_SEQUENCE_specifics_t asn_SPC_Wgs84TrajectoryPoint_specs_1;
extern asn_TYPE_member_t asn_MBR_Wgs84TrajectoryPoint_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ETSI-ITS-CDD_Altitude.h"
#include "ETSI-ITS-CDD_Heading.h"

#endif	/* _Wgs84TrajectoryPoint_H_ */
#include "asn_internal.h"
