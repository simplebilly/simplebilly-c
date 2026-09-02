/*
 * euer_detail_ergebnis.h
 *
 * 
 */

#ifndef _euer_detail_ergebnis_H_
#define _euer_detail_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct euer_detail_ergebnis_t euer_detail_ergebnis_t;

#include "euer_zeile_detail.h"



typedef struct euer_detail_ergebnis_t {
    int *jahr; //numeric
    list_t *zeilen; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} euer_detail_ergebnis_t;

__attribute__((deprecated)) euer_detail_ergebnis_t *euer_detail_ergebnis_create(
    int *jahr,
    list_t *zeilen
);

void euer_detail_ergebnis_free(euer_detail_ergebnis_t *euer_detail_ergebnis);

euer_detail_ergebnis_t *euer_detail_ergebnis_parseFromJSON(cJSON *euer_detail_ergebnisJSON);

cJSON *euer_detail_ergebnis_convertToJSON(euer_detail_ergebnis_t *euer_detail_ergebnis);

#endif /* _euer_detail_ergebnis_H_ */

