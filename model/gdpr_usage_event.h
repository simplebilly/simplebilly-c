/*
 * gdpr_usage_event.h
 *
 * 
 */

#ifndef _gdpr_usage_event_H_
#define _gdpr_usage_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gdpr_usage_event_t gdpr_usage_event_t;




typedef struct gdpr_usage_event_t {
    char *created_at; //date time
    char *event_type; // string
    char *id; // string
    int *quantity; //numeric
    char *tenant_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gdpr_usage_event_t;

__attribute__((deprecated)) gdpr_usage_event_t *gdpr_usage_event_create(
    char *created_at,
    char *event_type,
    char *id,
    int *quantity,
    char *tenant_id
);

void gdpr_usage_event_free(gdpr_usage_event_t *gdpr_usage_event);

gdpr_usage_event_t *gdpr_usage_event_parseFromJSON(cJSON *gdpr_usage_eventJSON);

cJSON *gdpr_usage_event_convertToJSON(gdpr_usage_event_t *gdpr_usage_event);

#endif /* _gdpr_usage_event_H_ */

