/*
 * extra_payment.h
 *
 * 
 */

#ifndef _extra_payment_H_
#define _extra_payment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extra_payment_t extra_payment_t;




typedef struct extra_payment_t {
    char *amount; // string
    char *employee_id; // string
    char *reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} extra_payment_t;

__attribute__((deprecated)) extra_payment_t *extra_payment_create(
    char *amount,
    char *employee_id,
    char *reason
);

void extra_payment_free(extra_payment_t *extra_payment);

extra_payment_t *extra_payment_parseFromJSON(cJSON *extra_paymentJSON);

cJSON *extra_payment_convertToJSON(extra_payment_t *extra_payment);

#endif /* _extra_payment_H_ */

