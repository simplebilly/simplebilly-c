/*
 * customer_update.h
 *
 * 
 */

#ifndef _customer_update_H_
#define _customer_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_update_t customer_update_t;

#include "any_type.h"



typedef struct customer_update_t {
    any_type_t *address; // custom
    char *contact_person; // string
    char *email; // string
    char *external_order_number; // string
    char *name; // string
    int *payment_grace_period_days; //numeric
    char *phone; // string
    char *vat_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} customer_update_t;

__attribute__((deprecated)) customer_update_t *customer_update_create(
    any_type_t *address,
    char *contact_person,
    char *email,
    char *external_order_number,
    char *name,
    int *payment_grace_period_days,
    char *phone,
    char *vat_id
);

void customer_update_free(customer_update_t *customer_update);

customer_update_t *customer_update_parseFromJSON(cJSON *customer_updateJSON);

cJSON *customer_update_convertToJSON(customer_update_t *customer_update);

#endif /* _customer_update_H_ */

