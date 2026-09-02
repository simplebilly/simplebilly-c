/*
 * bom.h
 *
 * 
 */

#ifndef _bom_H_
#define _bom_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bom_t bom_t;

#include "any_type.h"
#include "bom_status.h"



typedef struct bom_t {
    any_type_t *components; // custom
    char *description; // string
    char *name; // string
    long *output_quantity; //numeric
    char *product_id; // string
    bom_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} bom_t;

__attribute__((deprecated)) bom_t *bom_create(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
);

void bom_free(bom_t *bom);

bom_t *bom_parseFromJSON(cJSON *bomJSON);

cJSON *bom_convertToJSON(bom_t *bom);

#endif /* _bom_H_ */

