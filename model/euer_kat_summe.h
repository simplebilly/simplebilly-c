/*
 * euer_kat_summe.h
 *
 * 
 */

#ifndef _euer_kat_summe_H_
#define _euer_kat_summe_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct euer_kat_summe_t euer_kat_summe_t;




typedef struct euer_kat_summe_t {
    char *betrag; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} euer_kat_summe_t;

__attribute__((deprecated)) euer_kat_summe_t *euer_kat_summe_create(
    char *betrag,
    char *name
);

void euer_kat_summe_free(euer_kat_summe_t *euer_kat_summe);

euer_kat_summe_t *euer_kat_summe_parseFromJSON(cJSON *euer_kat_summeJSON);

cJSON *euer_kat_summe_convertToJSON(euer_kat_summe_t *euer_kat_summe);

#endif /* _euer_kat_summe_H_ */

