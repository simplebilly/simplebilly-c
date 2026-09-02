/*
 * ai_config_dto.h
 *
 * 
 */

#ifndef _ai_config_dto_H_
#define _ai_config_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ai_config_dto_t ai_config_dto_t;




typedef struct ai_config_dto_t {
    int *auto_reply; //boolean
    int *max_tool_calls; //numeric
    char *model; // string
    char *name; // string
    char *provider; // string
    char *system_prompt; // string
    list_t *trigger_on; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ai_config_dto_t;

__attribute__((deprecated)) ai_config_dto_t *ai_config_dto_create(
    int *auto_reply,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    list_t *trigger_on
);

void ai_config_dto_free(ai_config_dto_t *ai_config_dto);

ai_config_dto_t *ai_config_dto_parseFromJSON(cJSON *ai_config_dtoJSON);

cJSON *ai_config_dto_convertToJSON(ai_config_dto_t *ai_config_dto);

#endif /* _ai_config_dto_H_ */

