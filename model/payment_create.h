/*
 * payment_create.h
 *
 * 
 */

#ifndef _payment_create_H_
#define _payment_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_create_t payment_create_t;

#include "any_type.h"
#include "payment_method.h"



typedef struct payment_create_t {
    char *amount; // string
    any_type_t *attachment; // custom
    char *currency; // string
    char *customer_id; // string
    char *description; // string
    any_type_t *metadata; // custom
    simplebilly_api_payment_method__e method; //referenced enum
    char *payment_date; //date time
    char *reference; // string

    int _library_owned; // Is the library responsible for freeing this object?
} payment_create_t;

__attribute__((deprecated)) payment_create_t *payment_create_create(
    char *amount,
    any_type_t *attachment,
    char *currency,
    char *customer_id,
    char *description,
    any_type_t *metadata,
    simplebilly_api_payment_method__e method,
    char *payment_date,
    char *reference
);

void payment_create_free(payment_create_t *payment_create);

payment_create_t *payment_create_parseFromJSON(cJSON *payment_createJSON);

cJSON *payment_create_convertToJSON(payment_create_t *payment_create);

#endif /* _payment_create_H_ */

