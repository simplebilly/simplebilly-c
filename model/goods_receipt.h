/*
 * goods_receipt.h
 *
 * 
 */

#ifndef _goods_receipt_H_
#define _goods_receipt_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct goods_receipt_t goods_receipt_t;

#include "any_type.h"



typedef struct goods_receipt_t {
    char *gr_number; // string
    any_type_t *line_items; // custom
    char *notes; // string
    char *purchase_order_id; // string
    char *receipt_date; //date
    char *supplier_contact_id; // string
    char *supplier_name; // string
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} goods_receipt_t;

__attribute__((deprecated)) goods_receipt_t *goods_receipt_create(
    char *gr_number,
    any_type_t *line_items,
    char *notes,
    char *purchase_order_id,
    char *receipt_date,
    char *supplier_contact_id,
    char *supplier_name,
    char *warehouse_id
);

void goods_receipt_free(goods_receipt_t *goods_receipt);

goods_receipt_t *goods_receipt_parseFromJSON(cJSON *goods_receiptJSON);

cJSON *goods_receipt_convertToJSON(goods_receipt_t *goods_receipt);

#endif /* _goods_receipt_H_ */

