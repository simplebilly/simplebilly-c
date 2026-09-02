/*
 * ai_suggestion_request.h
 *
 * 
 */

#ifndef _ai_suggestion_request_H_
#define _ai_suggestion_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_suggestion_request_t ai_suggestion_request_t;




typedef struct ai_suggestion_request_t {
    char *instructions; // string
    char *message_body; // string
    char *ticket_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ai_suggestion_request_t;

__attribute__((deprecated)) ai_suggestion_request_t *ai_suggestion_request_create(
    char *instructions,
    char *message_body,
    char *ticket_id
);

void ai_suggestion_request_free(ai_suggestion_request_t *ai_suggestion_request);

ai_suggestion_request_t *ai_suggestion_request_parseFromJSON(cJSON *ai_suggestion_requestJSON);

cJSON *ai_suggestion_request_convertToJSON(ai_suggestion_request_t *ai_suggestion_request);

#endif /* _ai_suggestion_request_H_ */

