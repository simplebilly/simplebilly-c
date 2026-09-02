/*
 * budget.h
 *
 * 
 */

#ifndef _budget_H_
#define _budget_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct budget_t budget_t;




typedef struct budget_t {
    char *category; // string
    char *monthly_goal; // string
    char *updated_at; //date time
    int *year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} budget_t;

__attribute__((deprecated)) budget_t *budget_create(
    char *category,
    char *monthly_goal,
    char *updated_at,
    int *year
);

void budget_free(budget_t *budget);

budget_t *budget_parseFromJSON(cJSON *budgetJSON);

cJSON *budget_convertToJSON(budget_t *budget);

#endif /* _budget_H_ */

