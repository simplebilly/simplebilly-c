/*
 * expense_item.h
 *
 * 
 */

#ifndef _expense_item_H_
#define _expense_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct expense_item_t expense_item_t;




typedef struct expense_item_t {
    char *amount; // string
    char *category; // string
    double *percentage; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} expense_item_t;

__attribute__((deprecated)) expense_item_t *expense_item_create(
    char *amount,
    char *category,
    double *percentage
);

void expense_item_free(expense_item_t *expense_item);

expense_item_t *expense_item_parseFromJSON(cJSON *expense_itemJSON);

cJSON *expense_item_convertToJSON(expense_item_t *expense_item);

#endif /* _expense_item_H_ */

