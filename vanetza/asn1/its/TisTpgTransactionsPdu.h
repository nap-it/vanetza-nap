/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgTransactionsPdu_H_
#define	_TisTpgTransactionsPdu_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ITS-Container_ItsPduHeader.h"
#include "TisTpgTransaction.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgTransactionsPdu */
typedef struct TisTpgTransactionsPdu {
	ITS_Container_ItsPduHeader_t	 header;
	TisTpgTransaction_t	 tisTpgTransaction;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgTransactionsPdu_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgTransactionsPdu;

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgTransactionsPdu_H_ */
#include "asn_internal.h"
