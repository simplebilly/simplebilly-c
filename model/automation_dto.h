/*
 * automation_dto.h
 *
 * 
 */

#ifndef _automation_dto_H_
#define _automation_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct automation_dto_t automation_dto_t;

#include "any_type.h"



typedef struct automation_dto_t {
    char *automation_key; // string
    any_type_t *config; // custom
    int *default_day; //numeric
    char *description; // string
    int *enabled; //boolean
    char *kind; // string
    char *last_run_at; //date time
    char *next_run_at; //date time
    char *schedule_kind; // string

    int _library_owned; // Is the library responsible for freeing this object?
} automation_dto_t;

__attribute__((deprecated)) automation_dto_t *automation_dto_create(
    char *automation_key,
    any_type_t *config,
    int *default_day,
    char *description,
    int *enabled,
    char *kind,
    char *last_run_at,
    char *next_run_at,
    char *schedule_kind
);

void automation_dto_free(automation_dto_t *automation_dto);

automation_dto_t *automation_dto_parseFromJSON(cJSON *automation_dtoJSON);

cJSON *automation_dto_convertToJSON(automation_dto_t *automation_dto);

#endif /* _automation_dto_H_ */

