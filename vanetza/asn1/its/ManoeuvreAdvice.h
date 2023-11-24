/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MCM-PDU-Descriptions"
 * 	found in "asn1/MCM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_ManoeuvreAdvice_H_
#define	_ManoeuvreAdvice_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "ReferencePositionWithConfidence.h"
#include "Heading.h"
#include "TrajectoryType.h"
#include "Trajectory.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ManoeuvreAdvice */
typedef struct ManoeuvreAdvice {
	long	 manoeuvreID;
	long	 executantID;
	ReferencePositionWithConfidence_t	 executantPosition;
	Heading_t	 executantHeading;
	TrajectoryType_t	 trajectoryType;
	Trajectory_t	 trajectory;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ManoeuvreAdvice_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ManoeuvreAdvice;
extern asn_SEQUENCE_specifics_t asn_SPC_ManoeuvreAdvice_specs_1;
extern asn_TYPE_member_t asn_MBR_ManoeuvreAdvice_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _ManoeuvreAdvice_H_ */
#include "asn_internal.h"
