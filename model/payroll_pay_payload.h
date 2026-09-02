/*
 * payroll_pay_payload.h
 *
 * 
 */

#ifndef _payroll_pay_payload_H_
#define _payroll_pay_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_pay_payload_t payroll_pay_payload_t;




typedef struct payroll_pay_payload_t {
    char *payment_date; //date

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_pay_payload_t;

__attribute__((deprecated)) payroll_pay_payload_t *payroll_pay_payload_create(
    char *payment_date
);

void payroll_pay_payload_free(payroll_pay_payload_t *payroll_pay_payload);

payroll_pay_payload_t *payroll_pay_payload_parseFromJSON(cJSON *payroll_pay_payloadJSON);

cJSON *payroll_pay_payload_convertToJSON(payroll_pay_payload_t *payroll_pay_payload);

#endif /* _payroll_pay_payload_H_ */

