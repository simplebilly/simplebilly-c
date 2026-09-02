/*
 * purchase_order_update.h
 *
 * 
 */

#ifndef _purchase_order_update_H_
#define _purchase_order_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct purchase_order_update_t purchase_order_update_t;

#include "any_type.h"
#include "purchase_order_status.h"



typedef struct purchase_order_update_t {
    char *currency; // string
    any_type_t *delivery_address; // custom
    char *expected_delivery_date; //date
    any_type_t *line_items; // custom
    char *notes; // string
    char *order_date; //date
    char *po_number; // string
    purchase_order_status_t *status; // custom
    char *supplier_contact_id; // string
    char *supplier_name; // string
    char *total_gross_amount; // string
    char *total_net_amount; // string

    int _library_owned; // Is the library responsible for freeing this object?
} purchase_order_update_t;

__attribute__((deprecated)) purchase_order_update_t *purchase_order_update_create(
    char *currency,
    any_type_t *delivery_address,
    char *expected_delivery_date,
    any_type_t *line_items,
    char *notes,
    char *order_date,
    char *po_number,
    purchase_order_status_t *status,
    char *supplier_contact_id,
    char *supplier_name,
    char *total_gross_amount,
    char *total_net_amount
);

void purchase_order_update_free(purchase_order_update_t *purchase_order_update);

purchase_order_update_t *purchase_order_update_parseFromJSON(cJSON *purchase_order_updateJSON);

cJSON *purchase_order_update_convertToJSON(purchase_order_update_t *purchase_order_update);

#endif /* _purchase_order_update_H_ */

