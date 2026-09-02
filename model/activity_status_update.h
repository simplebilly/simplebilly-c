/*
 * activity_status_update.h
 *
 * 
 */

#ifndef _activity_status_update_H_
#define _activity_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_status_update_t activity_status_update_t;




typedef struct activity_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_status_update_t;

__attribute__((deprecated)) activity_status_update_t *activity_status_update_create(
    char *status
);

void activity_status_update_free(activity_status_update_t *activity_status_update);

activity_status_update_t *activity_status_update_parseFromJSON(cJSON *activity_status_updateJSON);

cJSON *activity_status_update_convertToJSON(activity_status_update_t *activity_status_update);

#endif /* _activity_status_update_H_ */

