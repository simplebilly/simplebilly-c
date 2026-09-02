/*
 * emission_entry.h
 *
 * 
 */

#ifndef _emission_entry_H_
#define _emission_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct emission_entry_t emission_entry_t;

#include "emission_method.h"
#include "ghg_scope.h"



typedef struct emission_entry_t {
    char *activity_value; // string
    char *category_id; // string
    char *description; // string
    char *ef_source; // string
    char *ef_version; // string
    emission_method_t *method; // custom
    ghg_scope_t *scope; // custom
    char *tco2e; // string
    char *unit; // string
    char *updated_at; //date time
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} emission_entry_t;

__attribute__((deprecated)) emission_entry_t *emission_entry_create(
    char *activity_value,
    char *category_id,
    char *description,
    char *ef_source,
    char *ef_version,
    emission_method_t *method,
    ghg_scope_t *scope,
    char *tco2e,
    char *unit,
    char *updated_at,
    int *year
);

void emission_entry_free(emission_entry_t *emission_entry);

emission_entry_t *emission_entry_parseFromJSON(cJSON *emission_entryJSON);

cJSON *emission_entry_convertToJSON(emission_entry_t *emission_entry);

#endif /* _emission_entry_H_ */

