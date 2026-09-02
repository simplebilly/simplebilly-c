/*
 * inventory_count_status_update.h
 *
 * 
 */

#ifndef _inventory_count_status_update_H_
#define _inventory_count_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inventory_count_status_update_t inventory_count_status_update_t;




typedef struct inventory_count_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} inventory_count_status_update_t;

__attribute__((deprecated)) inventory_count_status_update_t *inventory_count_status_update_create(
    char *status
);

void inventory_count_status_update_free(inventory_count_status_update_t *inventory_count_status_update);

inventory_count_status_update_t *inventory_count_status_update_parseFromJSON(cJSON *inventory_count_status_updateJSON);

cJSON *inventory_count_status_update_convertToJSON(inventory_count_status_update_t *inventory_count_status_update);

#endif /* _inventory_count_status_update_H_ */

