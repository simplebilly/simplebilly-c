/*
 * order_create.h
 *
 * 
 */

#ifndef _order_create_H_
#define _order_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_create_t order_create_t;

#include "any_type.h"
#include "language_code.h"
#include "order_status.h"
#include "payment_method.h"



typedef struct order_create_t {
    any_type_t *audit_log; // custom
    char *currency; // string
    char *customer_id; // string
    char *external_reference; // string
    any_type_t *invoice_address; // custom
    any_type_t *items; // custom
    simplebilly_api_language_code__e language; //referenced enum
    simplebilly_api_order_status__e order_status; //referenced enum
    simplebilly_api_payment_method__e payment_method; //referenced enum
    any_type_t *shipping_address; // custom
    char *shipping_cost; // string
    char *shipping_method; // string
    char *shipping_weight; // string
    list_t *tags; //primitive container
    char *total_cost; // string

    int _library_owned; // Is the library responsible for freeing this object?
} order_create_t;

__attribute__((deprecated)) order_create_t *order_create_create(
    any_type_t *audit_log,
    char *currency,
    char *customer_id,
    char *external_reference,
    any_type_t *invoice_address,
    any_type_t *items,
    simplebilly_api_language_code__e language,
    simplebilly_api_order_status__e order_status,
    simplebilly_api_payment_method__e payment_method,
    any_type_t *shipping_address,
    char *shipping_cost,
    char *shipping_method,
    char *shipping_weight,
    list_t *tags,
    char *total_cost
);

void order_create_free(order_create_t *order_create);

order_create_t *order_create_parseFromJSON(cJSON *order_createJSON);

cJSON *order_create_convertToJSON(order_create_t *order_create);

#endif /* _order_create_H_ */

