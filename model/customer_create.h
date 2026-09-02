/*
 * customer_create.h
 *
 * 
 */

#ifndef _customer_create_H_
#define _customer_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_create_t customer_create_t;

#include "any_type.h"



typedef struct customer_create_t {
    any_type_t *address; // custom
    char *contact_person; // string
    char *email; // string
    char *external_order_number; // string
    char *name; // string
    int *payment_grace_period_days; //numeric
    char *phone; // string
    char *vat_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_create_t;

__attribute__((deprecated)) customer_create_t *customer_create_create(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
);

void customer_create_free(customer_create_t *customer_create);

customer_create_t *customer_create_parseFromJSON(cJSON *customer_createJSON);

cJSON *customer_create_convertToJSON(customer_create_t *customer_create);

#endif /* _customer_create_H_ */

