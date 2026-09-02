/*
 * product_variant.h
 *
 * 
 */

#ifndef _product_variant_H_
#define _product_variant_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_variant_t product_variant_t;

#include "any_type.h"



typedef struct product_variant_t {
    char *barcode; // string
    char *image_link; // string
    int *is_active; //boolean
    char *name; // string
    any_type_t *option_values; // custom
    char *price; // string
    char *price_delta; // string
    char *product_id; // string
    char *sku; // string
    long *stock_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} product_variant_t;

__attribute__((deprecated)) product_variant_t *product_variant_create(
    char *barcode,
    char *image_link,
    int *is_active,
    char *name,
    any_type_t *option_values,
    char *price,
    char *price_delta,
    char *product_id,
    char *sku,
    long *stock_quantity
);

void product_variant_free(product_variant_t *product_variant);

product_variant_t *product_variant_parseFromJSON(cJSON *product_variantJSON);

cJSON *product_variant_convertToJSON(product_variant_t *product_variant);

#endif /* _product_variant_H_ */

