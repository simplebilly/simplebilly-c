/*
 * gu_v_item.h
 *
 * 
 */

#ifndef _gu_v_item_H_
#define _gu_v_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gu_v_item_t gu_v_item_t;




typedef struct gu_v_item_t {
    char *account; // string
    char *amount; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gu_v_item_t;

__attribute__((deprecated)) gu_v_item_t *gu_v_item_create(
    char *account,
    char *amount,
    char *name
);

void gu_v_item_free(gu_v_item_t *gu_v_item);

gu_v_item_t *gu_v_item_parseFromJSON(cJSON *gu_v_itemJSON);

cJSON *gu_v_item_convertToJSON(gu_v_item_t *gu_v_item);

#endif /* _gu_v_item_H_ */

