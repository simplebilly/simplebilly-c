/*
 * contact_timeline_response.h
 *
 * Aggregated per-contact timeline.
 */

#ifndef _contact_timeline_response_H_
#define _contact_timeline_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_timeline_response_t contact_timeline_response_t;

#include "timeline_event.h"



typedef struct contact_timeline_response_t {
    char *contact_id; // string
    list_t *events; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} contact_timeline_response_t;

__attribute__((deprecated)) contact_timeline_response_t *contact_timeline_response_create(
    char *contact_id,
    list_t *events
);

void contact_timeline_response_free(contact_timeline_response_t *contact_timeline_response);

contact_timeline_response_t *contact_timeline_response_parseFromJSON(cJSON *contact_timeline_responseJSON);

cJSON *contact_timeline_response_convertToJSON(contact_timeline_response_t *contact_timeline_response);

#endif /* _contact_timeline_response_H_ */

