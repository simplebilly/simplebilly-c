/*
 * production_order_status_update.h
 *
 * Status update request.
 */

#ifndef _production_order_status_update_H_
#define _production_order_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct production_order_status_update_t production_order_status_update_t;




typedef struct production_order_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} production_order_status_update_t;

__attribute__((deprecated)) production_order_status_update_t *production_order_status_update_create(
    char *status
);

void production_order_status_update_free(production_order_status_update_t *production_order_status_update);

production_order_status_update_t *production_order_status_update_parseFromJSON(cJSON *production_order_status_updateJSON);

cJSON *production_order_status_update_convertToJSON(production_order_status_update_t *production_order_status_update);

#endif /* _production_order_status_update_H_ */

