/*
 * balance_item.h
 *
 * 
 */

#ifndef _balance_item_H_
#define _balance_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct balance_item_t balance_item_t;




typedef struct balance_item_t {
    char *account; // string
    char *account_name; // string
    char *amount; // string

    int _library_owned; // Is the library responsible for freeing this object?
} balance_item_t;

__attribute__((deprecated)) balance_item_t *balance_item_create(
    char *account,
    char *account_name,
    char *amount
);

void balance_item_free(balance_item_t *balance_item);

balance_item_t *balance_item_parseFromJSON(cJSON *balance_itemJSON);

cJSON *balance_item_convertToJSON(balance_item_t *balance_item);

#endif /* _balance_item_H_ */

