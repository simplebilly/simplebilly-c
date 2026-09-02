/*
 * product_stock.h
 *
 * 
 */

#ifndef _product_stock_H_
#define _product_stock_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct product_stock_t product_stock_t;




typedef struct product_stock_t {
    char *name; // string
    char *product_id; // string
    char *sku; // string
    long *stock_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} product_stock_t;

__attribute__((deprecated)) product_stock_t *product_stock_create(
    char *name,
    char *product_id,
    char *sku,
    long *stock_quantity
);

void product_stock_free(product_stock_t *product_stock);

product_stock_t *product_stock_parseFromJSON(cJSON *product_stockJSON);

cJSON *product_stock_convertToJSON(product_stock_t *product_stock);

#endif /* _product_stock_H_ */

