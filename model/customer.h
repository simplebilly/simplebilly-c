/*
 * customer.h
 *
 * 
 */

#ifndef _customer_H_
#define _customer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_t customer_t;

#include "any_type.h"



typedef struct customer_t {
    any_type_t *address; // custom
    char *contact_person; // string
    char *email; // string
    char *external_order_number; // string
    char *name; // string
    int *payment_grace_period_days; //numeric
    char *phone; // string
    char *vat_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_t;

__attribute__((deprecated)) customer_t *customer_create(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
);

void customer_free(customer_t *customer);

customer_t *customer_parseFromJSON(cJSON *customerJSON);

cJSON *customer_convertToJSON(customer_t *customer);

#endif /* _customer_H_ */

