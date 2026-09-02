/*
 * bom_create.h
 *
 * 
 */

#ifndef _bom_create_H_
#define _bom_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bom_create_t bom_create_t;

#include "any_type.h"
#include "bom_status.h"



typedef struct bom_create_t {
    any_type_t *components; // custom
    char *description; // string
    char *name; // string
    long *output_quantity; //numeric
    char *product_id; // string
    bom_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} bom_create_t;

__attribute__((deprecated)) bom_create_t *bom_create_create(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
);

void bom_create_free(bom_create_t *bom_create);

bom_create_t *bom_create_parseFromJSON(cJSON *bom_createJSON);

cJSON *bom_create_convertToJSON(bom_create_t *bom_create);

#endif /* _bom_create_H_ */

