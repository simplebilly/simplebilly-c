/*
 * workflow_action.h
 *
 * One action inside a workflow. Only &#x60;email&#x60; is supported for now.
 */

#ifndef _workflow_action_H_
#define _workflow_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct workflow_action_t workflow_action_t;




typedef struct workflow_action_t {
    char *action_type; // string
    char *body; // string
    char *subject; // string

    int _library_owned; // Is the library responsible for freeing this object?
} workflow_action_t;

__attribute__((deprecated)) workflow_action_t *workflow_action_create(
    char *action_type,
    char *body,
    char *subject
);

void workflow_action_free(workflow_action_t *workflow_action);

workflow_action_t *workflow_action_parseFromJSON(cJSON *workflow_actionJSON);

cJSON *workflow_action_convertToJSON(workflow_action_t *workflow_action);

#endif /* _workflow_action_H_ */

