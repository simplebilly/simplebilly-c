/*
 * emission_target.h
 *
 * 
 */

#ifndef _emission_target_H_
#define _emission_target_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emission_target_t emission_target_t;

#include "emission_target_scope.h"



typedef struct emission_target_t {
    char *base_value; // string
    int *base_year; //numeric
    char *description; // string
    emission_target_scope_t *scope; // custom
    char *target_value; // string
    int *target_year; //numeric
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} emission_target_t;

__attribute__((deprecated)) emission_target_t *emission_target_create(
    char *base_value,
    int *base_year,
    char *description,
    emission_target_scope_t *scope,
    char *target_value,
    int *target_year,
    char *updated_at
);

void emission_target_free(emission_target_t *emission_target);

emission_target_t *emission_target_parseFromJSON(cJSON *emission_targetJSON);

cJSON *emission_target_convertToJSON(emission_target_t *emission_target);

#endif /* _emission_target_H_ */

