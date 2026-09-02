/*
 * return_logistics_queue_item.h
 *
 * One open return awaiting warehouse processing (inbound queue).
 */

#ifndef _return_logistics_queue_item_H_
#define _return_logistics_queue_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_logistics_queue_item_t return_logistics_queue_item_t;

#include "any_type.h"



typedef struct return_logistics_queue_item_t {
    long *age_days; //numeric
    char *created_at; //date time
    char *customer_name; // string
    any_type_t *line_items; // custom
    char *order_number; // string
    char *return_number; // string
    char *return_order_id; // string
    char *status; // string
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} return_logistics_queue_item_t;

__attribute__((deprecated)) return_logistics_queue_item_t *return_logistics_queue_item_create(
    long *age_days,
    char *created_at,
    char *customer_name,
    any_type_t *line_items,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *warehouse_id
);

void return_logistics_queue_item_free(return_logistics_queue_item_t *return_logistics_queue_item);

return_logistics_queue_item_t *return_logistics_queue_item_parseFromJSON(cJSON *return_logistics_queue_itemJSON);

cJSON *return_logistics_queue_item_convertToJSON(return_logistics_queue_item_t *return_logistics_queue_item);

#endif /* _return_logistics_queue_item_H_ */

