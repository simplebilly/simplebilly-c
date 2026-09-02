/*
 * revenue_item.h
 *
 * 
 */

#ifndef _revenue_item_H_
#define _revenue_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revenue_item_t revenue_item_t;




typedef struct revenue_item_t {
    char *amount; // string
    char *category; // string
    double *percentage; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} revenue_item_t;

__attribute__((deprecated)) revenue_item_t *revenue_item_create(
    char *amount,
    char *category,
    double *percentage
);

void revenue_item_free(revenue_item_t *revenue_item);

revenue_item_t *revenue_item_parseFromJSON(cJSON *revenue_itemJSON);

cJSON *revenue_item_convertToJSON(revenue_item_t *revenue_item);

#endif /* _revenue_item_H_ */

