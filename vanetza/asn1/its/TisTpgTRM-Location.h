/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgTRM_Location_H_
#define	_TisTpgTRM_Location_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_ReferencePosition.h"
#include "ITS-Container_Speed.h"
#include "ITS-Container_Heading.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgTRM-Location */
typedef struct TisTpgTRM_Location {
	ITS_Container_ReferencePosition_t	 vehiclePosition;
	ITS_Container_Speed_t	 vehicleSpeed;
	ITS_Container_Heading_t	 vehicleHeading;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgTRM_Location_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgTRM_Location;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgTRM_Location_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgTRM_Location_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgTRM_Location_H_ */
#include "asn_internal.h"
