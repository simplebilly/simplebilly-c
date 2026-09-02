/*
 * create_emission_entry.h
 *
 * 
 */

#ifndef _create_emission_entry_H_
#define _create_emission_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_emission_entry_t create_emission_entry_t;




typedef struct create_emission_entry_t {
    char *activity_value; // string
    char *category_id; // string
    char *description; // string
    char *method; // string
    char *scope; // string
    char *unit; // string
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} create_emission_entry_t;

__attribute__((deprecated)) create_emission_entry_t *create_emission_entry_create(
    char *activity_value,
    char *category_id,
    char *description,
    char *method,
    char *scope,
    char *unit,
    int *year
);

void create_emission_entry_free(create_emission_entry_t *create_emission_entry);

create_emission_entry_t *create_emission_entry_parseFromJSON(cJSON *create_emission_entryJSON);

cJSON *create_emission_entry_convertToJSON(create_emission_entry_t *create_emission_entry);

#endif /* _create_emission_entry_H_ */

