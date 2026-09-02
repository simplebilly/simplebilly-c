/*
 * ai_suggestion.h
 *
 * 
 */

#ifndef _ai_suggestion_H_
#define _ai_suggestion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_suggestion_t ai_suggestion_t;




typedef struct ai_suggestion_t {
    double *confidence; //numeric
    char *reasoning; // string
    char *suggested_priority; // string
    char *suggested_reply; // string
    char *suggested_status; // string
    list_t *tool_calls; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ai_suggestion_t;

__attribute__((deprecated)) ai_suggestion_t *ai_suggestion_create(
    double *confidence,
    char *reasoning,
    char *suggested_priority,
    char *suggested_reply,
    char *suggested_status,
    list_t *tool_calls
);

void ai_suggestion_free(ai_suggestion_t *ai_suggestion);

ai_suggestion_t *ai_suggestion_parseFromJSON(cJSON *ai_suggestionJSON);

cJSON *ai_suggestion_convertToJSON(ai_suggestion_t *ai_suggestion);

#endif /* _ai_suggestion_H_ */

