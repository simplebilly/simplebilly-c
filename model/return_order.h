/*
 * return_order.h
 *
 * 
 */

#ifndef _return_order_H_
#define _return_order_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_order_t return_order_t;

#include "any_type.h"
#include "return_order_status.h"



typedef struct return_order_t {
    char *customer_contact_id; // string
    char *customer_name; // string
    any_type_t *line_items; // custom
    char *notes; // string
    char *order_id; // string
    char *order_number; // string
    char *return_number; // string
    char *return_reason; // string
    return_order_status_t *status; // custom
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} return_order_t;

__attribute__((deprecated)) return_order_t *return_order_create(
    char *customer_contact_id,
    char *customer_name,
    any_type_t *line_items,
    char *notes,
    char *order_id,
    char *order_number,
    char *return_number,
    char *return_reason,
    return_order_status_t *status,
    char *warehouse_id
);

void return_order_free(return_order_t *return_order);

return_order_t *return_order_parseFromJSON(cJSON *return_orderJSON);

cJSON *return_order_convertToJSON(return_order_t *return_order);

#endif /* _return_order_H_ */

