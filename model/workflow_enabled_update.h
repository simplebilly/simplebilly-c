/*
 * workflow_enabled_update.h
 *
 * 
 */

#ifndef _workflow_enabled_update_H_
#define _workflow_enabled_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct workflow_enabled_update_t workflow_enabled_update_t;




typedef struct workflow_enabled_update_t {
    int *enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} workflow_enabled_update_t;

__attribute__((deprecated)) workflow_enabled_update_t *workflow_enabled_update_create(
    int *enabled
);

void workflow_enabled_update_free(workflow_enabled_update_t *workflow_enabled_update);

workflow_enabled_update_t *workflow_enabled_update_parseFromJSON(cJSON *workflow_enabled_updateJSON);

cJSON *workflow_enabled_update_convertToJSON(workflow_enabled_update_t *workflow_enabled_update);

#endif /* _workflow_enabled_update_H_ */

