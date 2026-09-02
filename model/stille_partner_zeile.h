/*
 * stille_partner_zeile.h
 *
 * 
 */

#ifndef _stille_partner_zeile_H_
#define _stille_partner_zeile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stille_partner_zeile_t stille_partner_zeile_t;




typedef struct stille_partner_zeile_t {
    char *auseinandersetzungsguthaben; // string
    char *gewinnanteil; // string
    char *gewinnvortrag; // string
    char *hinweis; // string
    char *instrument_type; // string
    char *kest; // string
    char *name; // string
    char *verlust_verrechnungskonto; // string
    char *verlustanteil; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stille_partner_zeile_t;

__attribute__((deprecated)) stille_partner_zeile_t *stille_partner_zeile_create(
    char *auseinandersetzungsguthaben,
    char *gewinnanteil,
    char *gewinnvortrag,
    char *hinweis,
    char *instrument_type,
    char *kest,
    char *name,
    char *verlust_verrechnungskonto,
    char *verlustanteil
);

void stille_partner_zeile_free(stille_partner_zeile_t *stille_partner_zeile);

stille_partner_zeile_t *stille_partner_zeile_parseFromJSON(cJSON *stille_partner_zeileJSON);

cJSON *stille_partner_zeile_convertToJSON(stille_partner_zeile_t *stille_partner_zeile);

#endif /* _stille_partner_zeile_H_ */

