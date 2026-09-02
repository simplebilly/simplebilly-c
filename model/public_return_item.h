/*
 * public_return_item.h
 *
 * 
 */

#ifndef _public_return_item_H_
#define _public_return_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct public_return_item_t public_return_item_t;




typedef struct public_return_item_t {
    char *name; // string
    char *product_id; // string
    long *quantity; //numeric
    char *reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} public_return_item_t;

__attribute__((deprecated)) public_return_item_t *public_return_item_create(
    char *name,
    char *product_id,
    long *quantity,
    char *reason
);

void public_return_item_free(public_return_item_t *public_return_item);

public_return_item_t *public_return_item_parseFromJSON(cJSON *public_return_itemJSON);

cJSON *public_return_item_convertToJSON(public_return_item_t *public_return_item);

#endif /* _public_return_item_H_ */

