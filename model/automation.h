/*
 * automation.h
 *
 * 
 */

#ifndef _automation_H_
#define _automation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct automation_t automation_t;

#include "any_type.h"



typedef struct automation_t {
    char *automation_key; // string
    any_type_t *config; // custom
    char *created_at; //date time
    int *enabled; //boolean
    char *last_run_at; //date time
    char *next_run_at; //date time
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} automation_t;

__attribute__((deprecated)) automation_t *automation_create(
    char *automation_key,
    any_type_t *config,
    char *created_at,
    int *enabled,
    char *last_run_at,
    char *next_run_at,
    char *tenant_id,
    char *updated_at
);

void automation_free(automation_t *automation);

automation_t *automation_parseFromJSON(cJSON *automationJSON);

cJSON *automation_convertToJSON(automation_t *automation);

#endif /* _automation_H_ */

