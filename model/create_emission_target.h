/*
 * create_emission_target.h
 *
 * 
 */

#ifndef _create_emission_target_H_
#define _create_emission_target_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_emission_target_t create_emission_target_t;




typedef struct create_emission_target_t {
    char *base_value; // string
    int *base_year; //numeric
    char *description; // string
    char *scope; // string
    char *target_value; // string
    int *target_year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} create_emission_target_t;

__attribute__((deprecated)) create_emission_target_t *create_emission_target_create(
    char *base_value,
    int *base_year,
    char *description,
    char *scope,
    char *target_value,
    int *target_year
);

void create_emission_target_free(create_emission_target_t *create_emission_target);

create_emission_target_t *create_emission_target_parseFromJSON(cJSON *create_emission_targetJSON);

cJSON *create_emission_target_convertToJSON(create_emission_target_t *create_emission_target);

#endif /* _create_emission_target_H_ */

