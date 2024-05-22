/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgTRM_Management_H_
#define	_TisTpgTRM_Management_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_TimestampIts.h"
#include "UNVehicleClassifcation.h"
#include "ITS-Container_StationID.h"
#include "ReservationStatus.h"
#include "CustomerContract.h"
#include "ReservationID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgTRM-Management */
typedef struct TisTpgTRM_Management {
	ITS_Container_TimestampIts_t	 generationTime;
	UNVehicleClassifcation_t	 vehicleType;
	ITS_Container_StationID_t	 tpgStationID;
	ReservationStatus_t	 reservationStatus;
	CustomerContract_t	*costumercontract;	/* OPTIONAL */
	ReservationID_t	*reservationID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgTRM_Management_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgTRM_Management;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgTRM_Management_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgTRM_Management_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgTRM_Management_H_ */
#include "asn_internal.h"
