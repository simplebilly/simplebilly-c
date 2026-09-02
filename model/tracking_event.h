/*
 * tracking_event.h
 *
 * 
 */

#ifndef _tracking_event_H_
#define _tracking_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tracking_event_t tracking_event_t;




typedef struct tracking_event_t {
    char *date; // string
    char *description; // string
    char *location; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} tracking_event_t;

__attribute__((deprecated)) tracking_event_t *tracking_event_create(
    char *date,
    char *description,
    char *location,
    char *status
);

void tracking_event_free(tracking_event_t *tracking_event);

tracking_event_t *tracking_event_parseFromJSON(cJSON *tracking_eventJSON);

cJSON *tracking_event_convertToJSON(tracking_event_t *tracking_event);

#endif /* _tracking_event_H_ */

