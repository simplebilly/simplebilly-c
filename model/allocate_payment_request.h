/*
 * allocate_payment_request.h
 *
 * 
 */

#ifndef _allocate_payment_request_H_
#define _allocate_payment_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct allocate_payment_request_t allocate_payment_request_t;




typedef struct allocate_payment_request_t {
    double *amount; //numeric
    char *invoice_id; // string
    char *payment_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} allocate_payment_request_t;

__attribute__((deprecated)) allocate_payment_request_t *allocate_payment_request_create(
    double *amount,
    char *invoice_id,
    char *payment_id
);

void allocate_payment_request_free(allocate_payment_request_t *allocate_payment_request);

allocate_payment_request_t *allocate_payment_request_parseFromJSON(cJSON *allocate_payment_requestJSON);

cJSON *allocate_payment_request_convertToJSON(allocate_payment_request_t *allocate_payment_request);

#endif /* _allocate_payment_request_H_ */

