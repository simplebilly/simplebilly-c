/*
 * emit_event_request.h
 *
 * 
 */

#ifndef _emit_event_request_H_
#define _emit_event_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emit_event_request_t emit_event_request_t;

#include "any_type.h"



typedef struct emit_event_request_t {
    char *event_type; // string
    any_type_t *payload; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} emit_event_request_t;

__attribute__((deprecated)) emit_event_request_t *emit_event_request_create(
    char *event_type,
    any_type_t *payload
);

void emit_event_request_free(emit_event_request_t *emit_event_request);

emit_event_request_t *emit_event_request_parseFromJSON(cJSON *emit_event_requestJSON);

cJSON *emit_event_request_convertToJSON(emit_event_request_t *emit_event_request);

#endif /* _emit_event_request_H_ */

