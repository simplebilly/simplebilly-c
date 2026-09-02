/*
 * product_category.h
 *
 * 
 */

#ifndef _product_category_H_
#define _product_category_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_category_t product_category_t;




typedef struct product_category_t {
    char *description; // string
    char *name; // string
    char *parent_category_id; // string
    int *sort_order; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} product_category_t;

__attribute__((deprecated)) product_category_t *product_category_create(
    char *description,
    char *name,
    char *parent_category_id,
    int *sort_order
);

void product_category_free(product_category_t *product_category);

product_category_t *product_category_parseFromJSON(cJSON *product_categoryJSON);

cJSON *product_category_convertToJSON(product_category_t *product_category);

#endif /* _product_category_H_ */

