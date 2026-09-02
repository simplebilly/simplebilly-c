/*
 * delivery_date_status_update.h
 *
 * 
 */

#ifndef _delivery_date_status_update_H_
#define _delivery_date_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_date_status_update_t delivery_date_status_update_t;




typedef struct delivery_date_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} delivery_date_status_update_t;

__attribute__((deprecated)) delivery_date_status_update_t *delivery_date_status_update_create(
    char *status
);

void delivery_date_status_update_free(delivery_date_status_update_t *delivery_date_status_update);

delivery_date_status_update_t *delivery_date_status_update_parseFromJSON(cJSON *delivery_date_status_updateJSON);

cJSON *delivery_date_status_update_convertToJSON(delivery_date_status_update_t *delivery_date_status_update);

#endif /* _delivery_date_status_update_H_ */

