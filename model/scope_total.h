/*
 * scope_total.h
 *
 * 
 */

#ifndef _scope_total_H_
#define _scope_total_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct scope_total_t scope_total_t;




typedef struct scope_total_t {
    char *scope; // string
    char *tco2e; // string

    int _library_owned; // Is the library responsible for freeing this object?
} scope_total_t;

__attribute__((deprecated)) scope_total_t *scope_total_create(
    char *scope,
    char *tco2e
);

void scope_total_free(scope_total_t *scope_total);

scope_total_t *scope_total_parseFromJSON(cJSON *scope_totalJSON);

cJSON *scope_total_convertToJSON(scope_total_t *scope_total);

#endif /* _scope_total_H_ */

