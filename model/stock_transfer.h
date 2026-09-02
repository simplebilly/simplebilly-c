/*
 * stock_transfer.h
 *
 * 
 */

#ifndef _stock_transfer_H_
#define _stock_transfer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stock_transfer_t stock_transfer_t;

#include "any_type.h"
#include "stock_transfer_status.h"



typedef struct stock_transfer_t {
    any_type_t *line_items; // custom
    char *notes; // string
    char *source_warehouse_id; // string
    stock_transfer_status_t *status; // custom
    char *target_warehouse_id; // string
    char *transfer_date; //date
    char *transfer_number; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stock_transfer_t;

__attribute__((deprecated)) stock_transfer_t *stock_transfer_create(
    any_type_t *line_items,
    char *notes,
    char *source_warehouse_id,
    stock_transfer_status_t *status,
    char *target_warehouse_id,
    char *transfer_date,
    char *transfer_number
);

void stock_transfer_free(stock_transfer_t *stock_transfer);

stock_transfer_t *stock_transfer_parseFromJSON(cJSON *stock_transferJSON);

cJSON *stock_transfer_convertToJSON(stock_transfer_t *stock_transfer);

#endif /* _stock_transfer_H_ */

