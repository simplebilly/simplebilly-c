/*
 * activity_update.h
 *
 * 
 */

#ifndef _activity_update_H_
#define _activity_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_update_t activity_update_t;

#include "activity_status.h"
#include "activity_type.h"



typedef struct activity_update_t {
    activity_type_t *activity_type; // custom
    char *assigned_to; // string
    char *contact_id; // string
    char *description; // string
    char *due_date; //date
    char *reminder_date; //date
    activity_status_t *status; // custom
    char *subject; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_update_t;

__attribute__((deprecated)) activity_update_t *activity_update_create(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
);

void activity_update_free(activity_update_t *activity_update);

activity_update_t *activity_update_parseFromJSON(cJSON *activity_updateJSON);

cJSON *activity_update_convertToJSON(activity_update_t *activity_update);

#endif /* _activity_update_H_ */

