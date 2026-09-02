/*
 * euer_ergebnis.h
 *
 * 
 */

#ifndef _euer_ergebnis_H_
#define _euer_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct euer_ergebnis_t euer_ergebnis_t;

#include "euer_zeile.h"



typedef struct euer_ergebnis_t {
    char *anlage_zugaenge; // string
    char *gewinn_verlust; // string
    int *jahr; //numeric
    char *summe_ausgaben; // string
    char *summe_einnahmen; // string
    list_t *zeilen; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} euer_ergebnis_t;

__attribute__((deprecated)) euer_ergebnis_t *euer_ergebnis_create(
    char *anlage_zugaenge,
    char *gewinn_verlust,
    int *jahr,
    char *summe_ausgaben,
    char *summe_einnahmen,
    list_t *zeilen
);

void euer_ergebnis_free(euer_ergebnis_t *euer_ergebnis);

euer_ergebnis_t *euer_ergebnis_parseFromJSON(cJSON *euer_ergebnisJSON);

cJSON *euer_ergebnis_convertToJSON(euer_ergebnis_t *euer_ergebnis);

#endif /* _euer_ergebnis_H_ */

