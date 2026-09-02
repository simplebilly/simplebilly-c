/*
 * return_order_status_update.h
 *
 * 
 */

#ifndef _return_order_status_update_H_
#define _return_order_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_order_status_update_t return_order_status_update_t;




typedef struct return_order_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} return_order_status_update_t;

__attribute__((deprecated)) return_order_status_update_t *return_order_status_update_create(
    char *status
);

void return_order_status_update_free(return_order_status_update_t *return_order_status_update);

return_order_status_update_t *return_order_status_update_parseFromJSON(cJSON *return_order_status_updateJSON);

cJSON *return_order_status_update_convertToJSON(return_order_status_update_t *return_order_status_update);

#endif /* _return_order_status_update_H_ */

