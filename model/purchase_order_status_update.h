/*
 * purchase_order_status_update.h
 *
 * 
 */

#ifndef _purchase_order_status_update_H_
#define _purchase_order_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct purchase_order_status_update_t purchase_order_status_update_t;




typedef struct purchase_order_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} purchase_order_status_update_t;

__attribute__((deprecated)) purchase_order_status_update_t *purchase_order_status_update_create(
    char *status
);

void purchase_order_status_update_free(purchase_order_status_update_t *purchase_order_status_update);

purchase_order_status_update_t *purchase_order_status_update_parseFromJSON(cJSON *purchase_order_status_updateJSON);

cJSON *purchase_order_status_update_convertToJSON(purchase_order_status_update_t *purchase_order_status_update);

#endif /* _purchase_order_status_update_H_ */

