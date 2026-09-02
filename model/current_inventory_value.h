/*
 * current_inventory_value.h
 *
 * 
 */

#ifndef _current_inventory_value_H_
#define _current_inventory_value_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct current_inventory_value_t current_inventory_value_t;

#include "inventory_value_point.h"



typedef struct current_inventory_value_t {
    list_t *history; //nonprimitive container
    long *product_count; //numeric
    char *total_purchase_value; // string
    char *total_sales_value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} current_inventory_value_t;

__attribute__((deprecated)) current_inventory_value_t *current_inventory_value_create(
    list_t *history,
    long *product_count,
    char *total_purchase_value,
    char *total_sales_value
);

void current_inventory_value_free(current_inventory_value_t *current_inventory_value);

current_inventory_value_t *current_inventory_value_parseFromJSON(cJSON *current_inventory_valueJSON);

cJSON *current_inventory_value_convertToJSON(current_inventory_value_t *current_inventory_value);

#endif /* _current_inventory_value_H_ */

