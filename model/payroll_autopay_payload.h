/*
 * payroll_autopay_payload.h
 *
 * 
 */

#ifndef _payroll_autopay_payload_H_
#define _payroll_autopay_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_autopay_payload_t payroll_autopay_payload_t;




typedef struct payroll_autopay_payload_t {
    char *debtor_bic; // string
    char *debtor_iban; // string
    char *debtor_name; // string
    char *execution_date; //date

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_autopay_payload_t;

__attribute__((deprecated)) payroll_autopay_payload_t *payroll_autopay_payload_create(
    char *debtor_bic,
    char *debtor_iban,
    char *debtor_name,
    char *execution_date
);

void payroll_autopay_payload_free(payroll_autopay_payload_t *payroll_autopay_payload);

payroll_autopay_payload_t *payroll_autopay_payload_parseFromJSON(cJSON *payroll_autopay_payloadJSON);

cJSON *payroll_autopay_payload_convertToJSON(payroll_autopay_payload_t *payroll_autopay_payload);

#endif /* _payroll_autopay_payload_H_ */

