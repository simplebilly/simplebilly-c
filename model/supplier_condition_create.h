/*
 * supplier_condition_create.h
 *
 * 
 */

#ifndef _supplier_condition_create_H_
#define _supplier_condition_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct supplier_condition_create_t supplier_condition_create_t;

#include "any_type.h"



typedef struct supplier_condition_create_t {
    char *currency; // string
    char *delivery_terms; // string
    char *early_payment_discount_percent; // string
    int *is_default; //boolean
    char *minimum_order_value; // string
    char *notes; // string
    int *payment_due_days; //numeric
    char *payment_terms; // string
    char *supplier_contact_id; // string
    char *supplier_name; // string
    any_type_t *volume_discount_tiers; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} supplier_condition_create_t;

__attribute__((deprecated)) supplier_condition_create_t *supplier_condition_create_create(
    char *currency,
    char *delivery_terms,
    char *early_payment_discount_percent,
    int *is_default,
    char *minimum_order_value,
    char *notes,
    int *payment_due_days,
    char *payment_terms,
    char *supplier_contact_id,
    char *supplier_name,
    any_type_t *volume_discount_tiers
);

void supplier_condition_create_free(supplier_condition_create_t *supplier_condition_create);

supplier_condition_create_t *supplier_condition_create_parseFromJSON(cJSON *supplier_condition_createJSON);

cJSON *supplier_condition_create_convertToJSON(supplier_condition_create_t *supplier_condition_create);

#endif /* _supplier_condition_create_H_ */

