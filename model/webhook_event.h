/*
 * webhook_event.h
 *
 * 
 */

#ifndef _webhook_event_H_
#define _webhook_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct webhook_event_t webhook_event_t;

#include "any_type.h"
#include "webhook_direction.h"
#include "webhook_event_status.h"



typedef struct webhook_event_t {
    int *attempts; //numeric
    char *channel; // string
    webhook_direction_t *direction; // custom
    char *event_type; // string
    char *last_error; // string
    any_type_t *payload; // custom
    webhook_event_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} webhook_event_t;

__attribute__((deprecated)) webhook_event_t *webhook_event_create(
    int *attempts,
    char *channel,
    webhook_direction_t *direction,
    char *event_type,
    char *last_error,
    any_type_t *payload,
    webhook_event_status_t *status
);

void webhook_event_free(webhook_event_t *webhook_event);

webhook_event_t *webhook_event_parseFromJSON(cJSON *webhook_eventJSON);

cJSON *webhook_event_convertToJSON(webhook_event_t *webhook_event);

#endif /* _webhook_event_H_ */

