/*
 * update_automation.h
 *
 * 
 */

#ifndef _update_automation_H_
#define _update_automation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_automation_t update_automation_t;

#include "any_type.h"



typedef struct update_automation_t {
    any_type_t *config; // custom
    int *enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_automation_t;

__attribute__((deprecated)) update_automation_t *update_automation_create(
    any_type_t *config,
    int *enabled
);

void update_automation_free(update_automation_t *update_automation);

update_automation_t *update_automation_parseFromJSON(cJSON *update_automationJSON);

cJSON *update_automation_convertToJSON(update_automation_t *update_automation);

#endif /* _update_automation_H_ */

