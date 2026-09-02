/*
 * order_update.h
 *
 * 
 */

#ifndef _order_update_H_
#define _order_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_update_t order_update_t;

#include "any_type.h"
#include "language_code.h"
#include "order_status.h"
#include "payment_method.h"



typedef struct order_update_t {
    any_type_t *audit_log; // custom
    char *currency; // string
    char *customer_id; // string
    char *external_reference; // string
    any_type_t *invoice_address; // custom
    any_type_t *items; // custom
    language_code_t *language; // custom
    order_status_t *order_status; // custom
    payment_method_t *payment_method; // custom
    any_type_t *shipping_address; // custom
    char *shipping_cost; // string
    char *shipping_method; // string
    char *shipping_weight; // string
    list_t *tags; //primitive container
    char *total_cost; // string

    int _library_owned; // Is the library responsible for freeing this object?
} order_update_t;

__attribute__((deprecated)) order_update_t *order_update_create(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    language_code_t *language,
    order_status_t *order_status,
    payment_method_t *payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
);

void order_update_free(order_update_t *order_update);

order_update_t *order_update_parseFromJSON(cJSON *order_updateJSON);

cJSON *order_update_convertToJSON(order_update_t *order_update);

#endif /* _order_update_H_ */

