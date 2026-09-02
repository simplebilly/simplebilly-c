/*
 * payroll_create_payload.h
 *
 * 
 */

#ifndef _payroll_create_payload_H_
#define _payroll_create_payload_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payroll_create_payload_t payroll_create_payload_t;

#include "extra_payment.h"



typedef struct payroll_create_payload_t {
    list_t *employee_ids; //primitive container
    list_t *extra_payments; //nonprimitive container
    int *month; //numeric
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} payroll_create_payload_t;

__attribute__((deprecated)) payroll_create_payload_t *payroll_create_payload_create(
    list_t *employee_ids,
    list_t *extra_payments,
    int *month,
    int *year
);

void payroll_create_payload_free(payroll_create_payload_t *payroll_create_payload);

payroll_create_payload_t *payroll_create_payload_parseFromJSON(cJSON *payroll_create_payloadJSON);

cJSON *payroll_create_payload_convertToJSON(payroll_create_payload_t *payroll_create_payload);

#endif /* _payroll_create_payload_H_ */

