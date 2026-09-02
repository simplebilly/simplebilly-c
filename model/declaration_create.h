/*
 * declaration_create.h
 *
 * 
 */

#ifndef _declaration_create_H_
#define _declaration_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct declaration_create_t declaration_create_t;

#include "declaration_type.h"



typedef struct declaration_create_t {
    declaration_type_t *declaration_type; // custom
    int *is_current; //boolean
    char *text; // string
    char *valid_from; //date
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} declaration_create_t;

__attribute__((deprecated)) declaration_create_t *declaration_create_create(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
);

void declaration_create_free(declaration_create_t *declaration_create);

declaration_create_t *declaration_create_parseFromJSON(cJSON *declaration_createJSON);

cJSON *declaration_create_convertToJSON(declaration_create_t *declaration_create);

#endif /* _declaration_create_H_ */

