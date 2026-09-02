/*
 * product_category_update.h
 *
 * 
 */

#ifndef _product_category_update_H_
#define _product_category_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_category_update_t product_category_update_t;




typedef struct product_category_update_t {
    char *description; // string
    char *name; // string
    char *parent_category_id; // string
    int *sort_order; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} product_category_update_t;

__attribute__((deprecated)) product_category_update_t *product_category_update_create(
    char *description,
    char *name,
    char *parent_category_id,
    int *sort_order
);

void product_category_update_free(product_category_update_t *product_category_update);

product_category_update_t *product_category_update_parseFromJSON(cJSON *product_category_updateJSON);

cJSON *product_category_update_convertToJSON(product_category_update_t *product_category_update);

#endif /* _product_category_update_H_ */

