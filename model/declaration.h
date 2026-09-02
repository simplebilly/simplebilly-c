/*
 * declaration.h
 *
 * 
 */

#ifndef _declaration_H_
#define _declaration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct declaration_t declaration_t;

#include "declaration_type.h"



typedef struct declaration_t {
    declaration_type_t *declaration_type; // custom
    int *is_current; //boolean
    char *text; // string
    char *valid_from; //date
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} declaration_t;

__attribute__((deprecated)) declaration_t *declaration_create(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
);

void declaration_free(declaration_t *declaration);

declaration_t *declaration_parseFromJSON(cJSON *declarationJSON);

cJSON *declaration_convertToJSON(declaration_t *declaration);

#endif /* _declaration_H_ */

