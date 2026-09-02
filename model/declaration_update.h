/*
 * declaration_update.h
 *
 * 
 */

#ifndef _declaration_update_H_
#define _declaration_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct declaration_update_t declaration_update_t;

#include "declaration_type.h"



typedef struct declaration_update_t {
    declaration_type_t *declaration_type; // custom
    int *is_current; //boolean
    char *text; // string
    char *valid_from; //date
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} declaration_update_t;

__attribute__((deprecated)) declaration_update_t *declaration_update_create(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
);

void declaration_update_free(declaration_update_t *declaration_update);

declaration_update_t *declaration_update_parseFromJSON(cJSON *declaration_updateJSON);

cJSON *declaration_update_convertToJSON(declaration_update_t *declaration_update);

#endif /* _declaration_update_H_ */

