/*
 * inventory_value_point.h
 *
 * 
 */

#ifndef _inventory_value_point_H_
#define _inventory_value_point_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inventory_value_point_t inventory_value_point_t;




typedef struct inventory_value_point_t {
    long *product_count; //numeric
    char *recorded_at; //date time
    char *total_purchase_value; // string
    char *total_sales_value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} inventory_value_point_t;

__attribute__((deprecated)) inventory_value_point_t *inventory_value_point_create(
    long *product_count,
    char *recorded_at,
    char *total_purchase_value,
    char *total_sales_value
);

void inventory_value_point_free(inventory_value_point_t *inventory_value_point);

inventory_value_point_t *inventory_value_point_parseFromJSON(cJSON *inventory_value_pointJSON);

cJSON *inventory_value_point_convertToJSON(inventory_value_point_t *inventory_value_point);

#endif /* _inventory_value_point_H_ */

