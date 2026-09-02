/*
 * costing_line.h
 *
 * A single costing line: material cost for one BOM component.
 */

#ifndef _costing_line_H_
#define _costing_line_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct costing_line_t costing_line_t;




typedef struct costing_line_t {
    char *line_cost; // string
    char *name; // string
    char *product_id; // string
    long *quantity_per_unit; //numeric
    char *sku; // string
    long *total_quantity; //numeric
    char *unit_purchase_price; // string

    int _library_owned; // Is the library responsible for freeing this object?
} costing_line_t;

__attribute__((deprecated)) costing_line_t *costing_line_create(
    char *line_cost,
    char *name,
    char *product_id,
    long *quantity_per_unit,
    char *sku,
    long *total_quantity,
    char *unit_purchase_price
);

void costing_line_free(costing_line_t *costing_line);

costing_line_t *costing_line_parseFromJSON(cJSON *costing_lineJSON);

cJSON *costing_line_convertToJSON(costing_line_t *costing_line);

#endif /* _costing_line_H_ */

