/*
 * bom_update.h
 *
 * 
 */

#ifndef _bom_update_H_
#define _bom_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bom_update_t bom_update_t;

#include "any_type.h"
#include "bom_status.h"



typedef struct bom_update_t {
    any_type_t *components; // custom
    char *description; // string
    char *name; // string
    long *output_quantity; //numeric
    char *product_id; // string
    bom_status_t *status; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} bom_update_t;

__attribute__((deprecated)) bom_update_t *bom_update_create(
    any_type_t *components,
    char *description,
    char *name,
    long *output_quantity,
    char *product_id,
    bom_status_t *status
);

void bom_update_free(bom_update_t *bom_update);

bom_update_t *bom_update_parseFromJSON(cJSON *bom_updateJSON);

cJSON *bom_update_convertToJSON(bom_update_t *bom_update);

#endif /* _bom_update_H_ */

