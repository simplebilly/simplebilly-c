/*
 * replenishment_suggestion_line.h
 *
 * A single replenishment suggestion.
 */

#ifndef _replenishment_suggestion_line_H_
#define _replenishment_suggestion_line_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct replenishment_suggestion_line_t replenishment_suggestion_line_t;




typedef struct replenishment_suggestion_line_t {
    long *current_stock; //numeric
    long *max_stock; //numeric
    long *min_stock; //numeric
    char *product_id; // string
    char *product_name; // string
    char *sku; // string
    long *source_available; //numeric
    char *source_warehouse_id; // string
    long *suggested_quantity; //numeric
    char *target_warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} replenishment_suggestion_line_t;

__attribute__((deprecated)) replenishment_suggestion_line_t *replenishment_suggestion_line_create(
    long *current_stock,
    long *max_stock,
    long *min_stock,
    char *product_id,
    char *product_name,
    char *sku,
    long *source_available,
    char *source_warehouse_id,
    long *suggested_quantity,
    char *target_warehouse_id
);

void replenishment_suggestion_line_free(replenishment_suggestion_line_t *replenishment_suggestion_line);

replenishment_suggestion_line_t *replenishment_suggestion_line_parseFromJSON(cJSON *replenishment_suggestion_lineJSON);

cJSON *replenishment_suggestion_line_convertToJSON(replenishment_suggestion_line_t *replenishment_suggestion_line);

#endif /* _replenishment_suggestion_line_H_ */

