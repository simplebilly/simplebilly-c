/*
 * warehouse_stock.h
 *
 * 
 */

#ifndef _warehouse_stock_H_
#define _warehouse_stock_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct warehouse_stock_t warehouse_stock_t;

#include "any_type.h"



typedef struct warehouse_stock_t {
    char *batch_number; // string
    char *bin_location; // string
    char *expiry_date; //date
    char *product_id; // string
    long *quantity; //numeric
    any_type_t *serial_numbers; // custom
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} warehouse_stock_t;

__attribute__((deprecated)) warehouse_stock_t *warehouse_stock_create(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    any_type_t *serial_numbers,
    char *warehouse_id
);

void warehouse_stock_free(warehouse_stock_t *warehouse_stock);

warehouse_stock_t *warehouse_stock_parseFromJSON(cJSON *warehouse_stockJSON);

cJSON *warehouse_stock_convertToJSON(warehouse_stock_t *warehouse_stock);

#endif /* _warehouse_stock_H_ */

