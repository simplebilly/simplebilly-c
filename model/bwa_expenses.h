/*
 * bwa_expenses.h
 *
 * 
 */

#ifndef _bwa_expenses_H_
#define _bwa_expenses_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bwa_expenses_t bwa_expenses_t;

#include "expense_item.h"



typedef struct bwa_expenses_t {
    list_t *expense_breakdown; //nonprimitive container
    char *total_expenses; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bwa_expenses_t;

__attribute__((deprecated)) bwa_expenses_t *bwa_expenses_create(
    list_t *expense_breakdown,
    char *total_expenses
);

void bwa_expenses_free(bwa_expenses_t *bwa_expenses);

bwa_expenses_t *bwa_expenses_parseFromJSON(cJSON *bwa_expensesJSON);

cJSON *bwa_expenses_convertToJSON(bwa_expenses_t *bwa_expenses);

#endif /* _bwa_expenses_H_ */

