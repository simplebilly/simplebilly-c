/*
 * production_order.h
 *
 * 
 */

#ifndef _production_order_H_
#define _production_order_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct production_order_t production_order_t;

#include "any_type.h"
#include "production_order_status.h"



typedef struct production_order_t {
    char *bom_id; // string
    any_type_t *components; // custom
    char *end_date; //date
    char *notes; // string
    char *order_number; // string
    char *product_id; // string
    long *quantity; //numeric
    char *source_warehouse_id; // string
    char *start_date; //date
    production_order_status_t *status; // custom
    char *target_warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} production_order_t;

__attribute__((deprecated)) production_order_t *production_order_create(
    char *bom_id,
    any_type_t *components,
    char *end_date,
    char *notes,
    char *order_number,
    char *product_id,
    long *quantity,
    char *source_warehouse_id,
    char *start_date,
    production_order_status_t *status,
    char *target_warehouse_id
);

void production_order_free(production_order_t *production_order);

production_order_t *production_order_parseFromJSON(cJSON *production_orderJSON);

cJSON *production_order_convertToJSON(production_order_t *production_order);

#endif /* _production_order_H_ */

