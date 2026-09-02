/*
 * production_order_costing.h
 *
 * Actual-costing (Nachkalkulation) report for a production order.
 */

#ifndef _production_order_costing_H_
#define _production_order_costing_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct production_order_costing_t production_order_costing_t;

#include "costing_line.h"



typedef struct production_order_costing_t {
    char *cost_per_unit; // string
    char *cost_source; // string
    list_t *lines; //nonprimitive container
    char *margin_per_unit; // string
    char *margin_percent; // string
    char *material_cost_total; // string
    char *order_number; // string
    char *production_order_id; // string
    long *quantity; //numeric
    char *sale_price; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} production_order_costing_t;

__attribute__((deprecated)) production_order_costing_t *production_order_costing_create(
    char *cost_per_unit,
    char *cost_source,
    list_t *lines,
    char *margin_per_unit,
    char *margin_percent,
    char *material_cost_total,
    char *order_number,
    char *production_order_id,
    long *quantity,
    char *sale_price,
    char *status
);

void production_order_costing_free(production_order_costing_t *production_order_costing);

production_order_costing_t *production_order_costing_parseFromJSON(cJSON *production_order_costingJSON);

cJSON *production_order_costing_convertToJSON(production_order_costing_t *production_order_costing);

#endif /* _production_order_costing_H_ */

