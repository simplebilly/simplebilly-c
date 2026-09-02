/*
 * inventory_count_update.h
 *
 * 
 */

#ifndef _inventory_count_update_H_
#define _inventory_count_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inventory_count_update_t inventory_count_update_t;

#include "any_type.h"
#include "inventory_count_status.h"



typedef struct inventory_count_update_t {
    char *count_date; //date
    char *count_number; // string
    any_type_t *line_items; // custom
    char *notes; // string
    inventory_count_status_t *status; // custom
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} inventory_count_update_t;

__attribute__((deprecated)) inventory_count_update_t *inventory_count_update_create(
    char *count_date,
    char *count_number,
    any_type_t *line_items,
    char *notes,
    inventory_count_status_t *status,
    char *warehouse_id
);

void inventory_count_update_free(inventory_count_update_t *inventory_count_update);

inventory_count_update_t *inventory_count_update_parseFromJSON(cJSON *inventory_count_updateJSON);

cJSON *inventory_count_update_convertToJSON(inventory_count_update_t *inventory_count_update);

#endif /* _inventory_count_update_H_ */

