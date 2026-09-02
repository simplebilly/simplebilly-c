/*
 * balance_sheet.h
 *
 * 
 */

#ifndef _balance_sheet_H_
#define _balance_sheet_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct balance_sheet_t balance_sheet_t;

#include "balance_item.h"



typedef struct balance_sheet_t {
    list_t *assets; //nonprimitive container
    int *balanced; //boolean
    list_t *equity_liabilities; //nonprimitive container
    char *total_assets; // string
    char *total_equity_liabilities; // string

    int _library_owned; // Is the library responsible for freeing this object?
} balance_sheet_t;

__attribute__((deprecated)) balance_sheet_t *balance_sheet_create(
    list_t *assets,
    int *balanced,
    list_t *equity_liabilities,
    char *total_assets,
    char *total_equity_liabilities
);

void balance_sheet_free(balance_sheet_t *balance_sheet);

balance_sheet_t *balance_sheet_parseFromJSON(cJSON *balance_sheetJSON);

cJSON *balance_sheet_convertToJSON(balance_sheet_t *balance_sheet);

#endif /* _balance_sheet_H_ */

