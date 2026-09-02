/*
 * timeline_event.h
 *
 * Single timeline entry aggregated from the contact&#39;s activity across all related modules (communications, quotations, orders, invoices, documents).
 */

#ifndef _timeline_event_H_
#define _timeline_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct timeline_event_t timeline_event_t;




typedef struct timeline_event_t {
    char *date; // string
    char *detail; // string
    char *id; // string
    char *status; // string
    char *title; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} timeline_event_t;

__attribute__((deprecated)) timeline_event_t *timeline_event_create(
    char *date,
    char *detail,
    char *id,
    char *status,
    char *title,
    char *type
);

void timeline_event_free(timeline_event_t *timeline_event);

timeline_event_t *timeline_event_parseFromJSON(cJSON *timeline_eventJSON);

cJSON *timeline_event_convertToJSON(timeline_event_t *timeline_event);

#endif /* _timeline_event_H_ */

