/*
 * workflow.h
 *
 * 
 */

#ifndef _workflow_H_
#define _workflow_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct workflow_t workflow_t;

#include "any_type.h"



typedef struct workflow_t {
    any_type_t *actions; // custom
    int *enabled; //boolean
    char *name; // string
    char *trigger_event; // string

    int _library_owned; // Is the library responsible for freeing this object?
} workflow_t;

__attribute__((deprecated)) workflow_t *workflow_create(
    any_type_t *actions,
    int *enabled,
    char *name,
    char *trigger_event
);

void workflow_free(workflow_t *workflow);

workflow_t *workflow_parseFromJSON(cJSON *workflowJSON);

cJSON *workflow_convertToJSON(workflow_t *workflow);

#endif /* _workflow_H_ */

