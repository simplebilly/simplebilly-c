/*
 * vat_item.h
 *
 * 
 */

#ifndef _vat_item_H_
#define _vat_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vat_item_t vat_item_t;




typedef struct vat_item_t {
    char *net_amount; // string
    char *tax_amount; // string
    char *tax_rate; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vat_item_t;

__attribute__((deprecated)) vat_item_t *vat_item_create(
    char *net_amount,
    char *tax_amount,
    char *tax_rate
);

void vat_item_free(vat_item_t *vat_item);

vat_item_t *vat_item_parseFromJSON(cJSON *vat_itemJSON);

cJSON *vat_item_convertToJSON(vat_item_t *vat_item);

#endif /* _vat_item_H_ */

