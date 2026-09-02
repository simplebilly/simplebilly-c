/*
 * appointment_status_update.h
 *
 * 
 */

#ifndef _appointment_status_update_H_
#define _appointment_status_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct appointment_status_update_t appointment_status_update_t;




typedef struct appointment_status_update_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} appointment_status_update_t;

__attribute__((deprecated)) appointment_status_update_t *appointment_status_update_create(
    char *status
);

void appointment_status_update_free(appointment_status_update_t *appointment_status_update);

appointment_status_update_t *appointment_status_update_parseFromJSON(cJSON *appointment_status_updateJSON);

cJSON *appointment_status_update_convertToJSON(appointment_status_update_t *appointment_status_update);

#endif /* _appointment_status_update_H_ */

