/*
 * product_attribute_update.h
 *
 * 
 */

#ifndef _product_attribute_update_H_
#define _product_attribute_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_attribute_update_t product_attribute_update_t;




typedef struct product_attribute_update_t {
    int *is_filterable; //boolean
    char *name; // string
    int *position; //numeric
    char *product_id; // string
    char *unit; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} product_attribute_update_t;

__attribute__((deprecated)) product_attribute_update_t *product_attribute_update_create(
    int *is_filterable,
    char *name,
    int *position,
    char *product_id,
    char *unit,
    char *value
);

void product_attribute_update_free(product_attribute_update_t *product_attribute_update);

product_attribute_update_t *product_attribute_update_parseFromJSON(cJSON *product_attribute_updateJSON);

cJSON *product_attribute_update_convertToJSON(product_attribute_update_t *product_attribute_update);

#endif /* _product_attribute_update_H_ */

