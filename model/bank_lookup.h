/*
 * bank_lookup.h
 *
 * 
 */

#ifndef _bank_lookup_H_
#define _bank_lookup_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bank_lookup_t bank_lookup_t;




typedef struct bank_lookup_t {
    char *bank_name; // string
    char *bic; // string
    char *iban; // string
    char *nextgenpsd2_url; // string
    int *psd2_supported; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} bank_lookup_t;

__attribute__((deprecated)) bank_lookup_t *bank_lookup_create(
    char *bank_name,
    char *bic,
    char *iban,
    char *nextgenpsd2_url,
    int *psd2_supported
);

void bank_lookup_free(bank_lookup_t *bank_lookup);

bank_lookup_t *bank_lookup_parseFromJSON(cJSON *bank_lookupJSON);

cJSON *bank_lookup_convertToJSON(bank_lookup_t *bank_lookup);

#endif /* _bank_lookup_H_ */

