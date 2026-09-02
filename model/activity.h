/*
 * activity.h
 *
 * 
 */

#ifndef _activity_H_
#define _activity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_t activity_t;

#include "activity_status.h"
#include "activity_type.h"



typedef struct activity_t {
    activity_type_t *activity_type; // custom
    char *assigned_to; // string
    char *contact_id; // string
    char *description; // string
    char *due_date; //date
    char *reminder_date; //date
    activity_status_t *status; // custom
    char *subject; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_t;

__attribute__((deprecated)) activity_t *activity_create(
    activity_type_t *activity_type,
    char *assigned_to,
    char *contact_id,
    char *description,
    char *due_date,
    char *reminder_date,
    activity_status_t *status,
    char *subject
);

void activity_free(activity_t *activity);

activity_t *activity_parseFromJSON(cJSON *activityJSON);

cJSON *activity_convertToJSON(activity_t *activity);

#endif /* _activity_H_ */

