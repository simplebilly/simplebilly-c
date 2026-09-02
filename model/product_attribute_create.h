/*
 * product_attribute_create.h
 *
 * 
 */

#ifndef _product_attribute_create_H_
#define _product_attribute_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_attribute_create_t product_attribute_create_t;




typedef struct product_attribute_create_t {
    int *is_filterable; //boolean
    char *name; // string
    int *position; //numeric
    char *product_id; // string
    char *unit; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} product_attribute_create_t;

__attribute__((deprecated)) product_attribute_create_t *product_attribute_create_create(
    int *is_filterable,
    char *name,
    int *position,
    char *product_id,
    char *unit,
    char *value
);

void product_attribute_create_free(product_attribute_create_t *product_attribute_create);

product_attribute_create_t *product_attribute_create_parseFromJSON(cJSON *product_attribute_createJSON);

cJSON *product_attribute_create_convertToJSON(product_attribute_create_t *product_attribute_create);

#endif /* _product_attribute_create_H_ */

