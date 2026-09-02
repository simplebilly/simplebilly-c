/*
 * bilanz_item.h
 *
 * 
 */

#ifndef _bilanz_item_H_
#define _bilanz_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bilanz_item_t bilanz_item_t;




typedef struct bilanz_item_t {
    char *amount; // string
    char *konto; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bilanz_item_t;

__attribute__((deprecated)) bilanz_item_t *bilanz_item_create(
    char *amount,
    char *konto,
    char *name
);

void bilanz_item_free(bilanz_item_t *bilanz_item);

bilanz_item_t *bilanz_item_parseFromJSON(cJSON *bilanz_itemJSON);

cJSON *bilanz_item_convertToJSON(bilanz_item_t *bilanz_item);

#endif /* _bilanz_item_H_ */

