/*
 * pn_l_item.h
 *
 * 
 */

#ifndef _pn_l_item_H_
#define _pn_l_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pn_l_item_t pn_l_item_t;




typedef struct pn_l_item_t {
    char *account; // string
    char *account_name; // string
    char *amount; // string

    int _library_owned; // Is the library responsible for freeing this object?
} pn_l_item_t;

__attribute__((deprecated)) pn_l_item_t *pn_l_item_create(
    char *account,
    char *account_name,
    char *amount
);

void pn_l_item_free(pn_l_item_t *pn_l_item);

pn_l_item_t *pn_l_item_parseFromJSON(cJSON *pn_l_itemJSON);

cJSON *pn_l_item_convertToJSON(pn_l_item_t *pn_l_item);

#endif /* _pn_l_item_H_ */

