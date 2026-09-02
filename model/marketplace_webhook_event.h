/*
 * marketplace_webhook_event.h
 *
 * 
 */

#ifndef _marketplace_webhook_event_H_
#define _marketplace_webhook_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct marketplace_webhook_event_t marketplace_webhook_event_t;

#include "any_type.h"



typedef struct marketplace_webhook_event_t {
    char *connection_id; // string
    any_type_t *event_body; // custom
    char *event_type; // string
    any_type_t *headers; // custom
    char *platform; // string
    int *processed; //boolean
    char *processing_error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} marketplace_webhook_event_t;

__attribute__((deprecated)) marketplace_webhook_event_t *marketplace_webhook_event_create(
    char *connection_id,
    any_type_t *event_body,
    char *event_type,
    any_type_t *headers,
    char *platform,
    int *processed,
    char *processing_error
);

void marketplace_webhook_event_free(marketplace_webhook_event_t *marketplace_webhook_event);

marketplace_webhook_event_t *marketplace_webhook_event_parseFromJSON(cJSON *marketplace_webhook_eventJSON);

cJSON *marketplace_webhook_event_convertToJSON(marketplace_webhook_event_t *marketplace_webhook_event);

#endif /* _marketplace_webhook_event_H_ */

