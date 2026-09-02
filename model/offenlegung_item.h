/*
 * offenlegung_item.h
 *
 * 
 */

#ifndef _offenlegung_item_H_
#define _offenlegung_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct offenlegung_item_t offenlegung_item_t;




typedef struct offenlegung_item_t {
    int *exists; //boolean
    char *name; // string
    char *source; // string

    int _library_owned; // Is the library responsible for freeing this object?
} offenlegung_item_t;

__attribute__((deprecated)) offenlegung_item_t *offenlegung_item_create(
    int *exists,
    char *name,
    char *source
);

void offenlegung_item_free(offenlegung_item_t *offenlegung_item);

offenlegung_item_t *offenlegung_item_parseFromJSON(cJSON *offenlegung_itemJSON);

cJSON *offenlegung_item_convertToJSON(offenlegung_item_t *offenlegung_item);

#endif /* _offenlegung_item_H_ */

