/*
 * account_overview.h
 *
 * 
 */

#ifndef _account_overview_H_
#define _account_overview_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct account_overview_t account_overview_t;




typedef struct account_overview_t {
    char *account; // string
    char *account_name; // string
    char *balance; // string
    char *credit_total; // string
    char *debit_total; // string

    int _library_owned; // Is the library responsible for freeing this object?
} account_overview_t;

__attribute__((deprecated)) account_overview_t *account_overview_create(
    char *account,
    char *account_name,
    char *balance,
    char *credit_total,
    char *debit_total
);

void account_overview_free(account_overview_t *account_overview);

account_overview_t *account_overview_parseFromJSON(cJSON *account_overviewJSON);

cJSON *account_overview_convertToJSON(account_overview_t *account_overview);

#endif /* _account_overview_H_ */

