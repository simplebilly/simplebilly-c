/*
 * gdpr_activity.h
 *
 * 
 */

#ifndef _gdpr_activity_H_
#define _gdpr_activity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_activity_t gdpr_activity_t;




typedef struct gdpr_activity_t {
    char *action; // string
    char *created_at; //date time
    char *description; // string
    char *id; // string
    char *tenant_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_activity_t;

__attribute__((deprecated)) gdpr_activity_t *gdpr_activity_create(
    char *action,
    char *created_at,
    char *description,
    char *id,
    char *tenant_id
);

void gdpr_activity_free(gdpr_activity_t *gdpr_activity);

gdpr_activity_t *gdpr_activity_parseFromJSON(cJSON *gdpr_activityJSON);

cJSON *gdpr_activity_convertToJSON(gdpr_activity_t *gdpr_activity);

#endif /* _gdpr_activity_H_ */

