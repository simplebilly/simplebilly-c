/*
 * income_statement.h
 *
 * 
 */

#ifndef _income_statement_H_
#define _income_statement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct income_statement_t income_statement_t;

#include "pn_l_item.h"



typedef struct income_statement_t {
    list_t *expense_items; //nonprimitive container
    char *net_income; // string
    list_t *revenue_items; //nonprimitive container
    char *total_expenses; // string
    char *total_revenue; // string

    int _library_owned; // Is the library responsible for freeing this object?
} income_statement_t;

__attribute__((deprecated)) income_statement_t *income_statement_create(
    list_t *expense_items,
    char *net_income,
    list_t *revenue_items,
    char *total_expenses,
    char *total_revenue
);

void income_statement_free(income_statement_t *income_statement);

income_statement_t *income_statement_parseFromJSON(cJSON *income_statementJSON);

cJSON *income_statement_convertToJSON(income_statement_t *income_statement);

#endif /* _income_statement_H_ */

