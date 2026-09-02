/*
 * stock_adjustment.h
 *
 * 
 */

#ifndef _stock_adjustment_H_
#define _stock_adjustment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_adjustment_t stock_adjustment_t;




typedef struct stock_adjustment_t {
    char *batch_number; // string
    char *bin_location; // string
    char *expiry_date; //date
    char *product_id; // string
    long *quantity; //numeric
    list_t *serial_numbers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} stock_adjustment_t;

__attribute__((deprecated)) stock_adjustment_t *stock_adjustment_create(
    char *batch_number,
    char *bin_location,
    char *expiry_date,
    char *product_id,
    long *quantity,
    list_t *serial_numbers
);

void stock_adjustment_free(stock_adjustment_t *stock_adjustment);

stock_adjustment_t *stock_adjustment_parseFromJSON(cJSON *stock_adjustmentJSON);

cJSON *stock_adjustment_convertToJSON(stock_adjustment_t *stock_adjustment);

#endif /* _stock_adjustment_H_ */

