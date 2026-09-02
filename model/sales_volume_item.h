/*
 * sales_volume_item.h
 *
 * 
 */

#ifndef _sales_volume_item_H_
#define _sales_volume_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sales_volume_item_t sales_volume_item_t;




typedef struct sales_volume_item_t {
    char *contact_id; // string
    char *contact_type; // string
    char *last_purchase_date; // string
    char *name; // string
    int *total_invoices; //numeric
    char *total_revenue; // string

    int _library_owned; // Is the library responsible for freeing this object?
} sales_volume_item_t;

__attribute__((deprecated)) sales_volume_item_t *sales_volume_item_create(
    char *contact_id,
    char *contact_type,
    char *last_purchase_date,
    char *name,
    int *total_invoices,
    char *total_revenue
);

void sales_volume_item_free(sales_volume_item_t *sales_volume_item);

sales_volume_item_t *sales_volume_item_parseFromJSON(cJSON *sales_volume_itemJSON);

cJSON *sales_volume_item_convertToJSON(sales_volume_item_t *sales_volume_item);

#endif /* _sales_volume_item_H_ */

