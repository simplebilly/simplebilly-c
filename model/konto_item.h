/*
 * konto_item.h
 *
 * 
 */

#ifndef _konto_item_H_
#define _konto_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct konto_item_t konto_item_t;




typedef struct konto_item_t {
    char *anfangsbestand; // string
    char *haben_umsatz; // string
    char *konto; // string
    char *name; // string
    char *saldo; // string
    char *soll_umsatz; // string

    int _library_owned; // Is the library responsible for freeing this object?
} konto_item_t;

__attribute__((deprecated)) konto_item_t *konto_item_create(
    char *anfangsbestand,
    char *haben_umsatz,
    char *konto,
    char *name,
    char *saldo,
    char *soll_umsatz
);

void konto_item_free(konto_item_t *konto_item);

konto_item_t *konto_item_parseFromJSON(cJSON *konto_itemJSON);

cJSON *konto_item_convertToJSON(konto_item_t *konto_item);

#endif /* _konto_item_H_ */

