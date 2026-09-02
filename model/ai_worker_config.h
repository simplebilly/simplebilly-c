/*
 * ai_worker_config.h
 *
 * 
 */

#ifndef _ai_worker_config_H_
#define _ai_worker_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_worker_config_t ai_worker_config_t;




typedef struct ai_worker_config_t {
    int *auto_reply; //boolean
    char *created_at; //date time
    char *id; // string
    int *is_active; //boolean
    int *max_tool_calls; //numeric
    char *model; // string
    char *name; // string
    char *provider; // string
    char *system_prompt; // string
    char *tenant_id; // string
    list_t *trigger_on; //primitive container
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ai_worker_config_t;

__attribute__((deprecated)) ai_worker_config_t *ai_worker_config_create(
    int *auto_reply,
    char *created_at,
    char *id,
    int *is_active,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    char *tenant_id,
    list_t *trigger_on,
    char *updated_at
);

void ai_worker_config_free(ai_worker_config_t *ai_worker_config);

ai_worker_config_t *ai_worker_config_parseFromJSON(cJSON *ai_worker_configJSON);

cJSON *ai_worker_config_convertToJSON(ai_worker_config_t *ai_worker_config);

#endif /* _ai_worker_config_H_ */

