/*
 * return_warehouse_summary.h
 *
 * Aggregation for a single warehouse.
 */

#ifndef _return_warehouse_summary_H_
#define _return_warehouse_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct return_warehouse_summary_t return_warehouse_summary_t;




typedef struct return_warehouse_summary_t {
    long *items_restocked; //numeric
    long *items_scrapped; //numeric
    long *returns; //numeric
    char *warehouse_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} return_warehouse_summary_t;

__attribute__((deprecated)) return_warehouse_summary_t *return_warehouse_summary_create(
    long *items_restocked,
    long *items_scrapped,
    long *returns,
    char *warehouse_id
);

void return_warehouse_summary_free(return_warehouse_summary_t *return_warehouse_summary);

return_warehouse_summary_t *return_warehouse_summary_parseFromJSON(cJSON *return_warehouse_summaryJSON);

cJSON *return_warehouse_summary_convertToJSON(return_warehouse_summary_t *return_warehouse_summary);

#endif /* _return_warehouse_summary_H_ */

