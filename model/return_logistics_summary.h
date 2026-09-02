/*
 * return_logistics_summary.h
 *
 * Warehouse-level aggregation for the returns logistics dashboard.
 */

#ifndef _return_logistics_summary_H_
#define _return_logistics_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_logistics_summary_t return_logistics_summary_t;

#include "any_type.h"
#include "return_warehouse_summary.h"



typedef struct return_logistics_summary_t {
    any_type_t *by_status; // custom
    list_t *by_warehouse; //nonprimitive container
    long *items_restocked; //numeric
    long *items_scrapped; //numeric
    long *total_items; //numeric
    long *total_returns; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} return_logistics_summary_t;

__attribute__((deprecated)) return_logistics_summary_t *return_logistics_summary_create(
    any_type_t *by_status,
    list_t *by_warehouse,
    long *items_restocked,
    long *items_scrapped,
    long *total_items,
    long *total_returns
);

void return_logistics_summary_free(return_logistics_summary_t *return_logistics_summary);

return_logistics_summary_t *return_logistics_summary_parseFromJSON(cJSON *return_logistics_summaryJSON);

cJSON *return_logistics_summary_convertToJSON(return_logistics_summary_t *return_logistics_summary);

#endif /* _return_logistics_summary_H_ */

