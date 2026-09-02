/*
 * product.h
 *
 * 
 */

#ifndef _product_H_
#define _product_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_t product_t;

#include "any_type.h"



typedef struct product_t {
    char *availability; // string
    char *barcode; // string
    char *brand; // string
    char *category_id; // string
    char *condition; // string
    char *default_ledger_account; // string
    char *default_price; // string
    char *default_price_formula_id; // string
    char *default_tax_rate; // string
    char *description; // string
    char *gtin; // string
    char *height; // string
    char *image_link; // string
    any_type_t *images; // custom
    int *is_taxable; //boolean
    char *length; // string
    char *link; // string
    long *max_stock; //numeric
    long *min_stock; //numeric
    char *mpn; // string
    char *name; // string
    char *package_height; // string
    char *package_length; // string
    char *package_weight_unit; // string
    char *package_weight_value; // string
    char *package_width; // string
    char *product_code; // string
    char *product_type; // string
    char *purchase_price; // string
    long *reorder_quantity; //numeric
    char *sale_price; // string
    char *shipping_price; // string
    int *shipping_requires_insurance; //boolean
    char *sku; // string
    long *stock_quantity; //numeric
    any_type_t *tags; // custom
    char *tax_price; // string
    int *track_batch; //boolean
    int *track_serial; //boolean
    any_type_t *unit; // custom
    char *weight_unit; // string
    char *weight_value; // string
    char *width; // string

    int _library_owned; // Is the library responsible for freeing this object?
} product_t;

__attribute__((deprecated)) product_t *product_create(
    char *availability,
    char *barcode,
    char *brand,
    char *category_id,
    char *condition,
    char *default_ledger_account,
    char *default_price,
    char *default_price_formula_id,
    char *default_tax_rate,
    char *description,
    char *gtin,
    char *height,
    char *image_link,
    any_type_t *images,
    int *is_taxable,
    char *length,
    char *link,
    long *max_stock,
    long *min_stock,
    char *mpn,
    char *name,
    char *package_height,
    char *package_length,
    char *package_weight_unit,
    char *package_weight_value,
    char *package_width,
    char *product_code,
    char *product_type,
    char *purchase_price,
    long *reorder_quantity,
    char *sale_price,
    char *shipping_price,
    int *shipping_requires_insurance,
    char *sku,
    long *stock_quantity,
    any_type_t *tags,
    char *tax_price,
    int *track_batch,
    int *track_serial,
    any_type_t *unit,
    char *weight_unit,
    char *weight_value,
    char *width
);

void product_free(product_t *product);

product_t *product_parseFromJSON(cJSON *productJSON);

cJSON *product_convertToJSON(product_t *product);

#endif /* _product_H_ */

