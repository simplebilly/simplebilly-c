/*
 * labor_cost_row.h
 *
 * 
 */

#ifndef _labor_cost_row_H_
#define _labor_cost_row_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct labor_cost_row_t labor_cost_row_t;




typedef struct labor_cost_row_t {
    char *cost; // string
    char *employee_id; // string
    char *group_key; // string
    char *hours; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} labor_cost_row_t;

__attribute__((deprecated)) labor_cost_row_t *labor_cost_row_create(
    char *cost,
    char *employee_id,
    char *group_key,
    char *hours,
    char *name
);

void labor_cost_row_free(labor_cost_row_t *labor_cost_row);

labor_cost_row_t *labor_cost_row_parseFromJSON(cJSON *labor_cost_rowJSON);

cJSON *labor_cost_row_convertToJSON(labor_cost_row_t *labor_cost_row);

#endif /* _labor_cost_row_H_ */

