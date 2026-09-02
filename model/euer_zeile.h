/*
 * euer_zeile.h
 *
 * 
 */

#ifndef _euer_zeile_H_
#define _euer_zeile_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct euer_zeile_t euer_zeile_t;




typedef struct euer_zeile_t {
    char *abschnitt; // string
    char *betrag; // string
    char *bezeichnung; // string
    int *zeile; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} euer_zeile_t;

__attribute__((deprecated)) euer_zeile_t *euer_zeile_create(
    char *abschnitt,
    char *betrag,
    char *bezeichnung,
    int *zeile
);

void euer_zeile_free(euer_zeile_t *euer_zeile);

euer_zeile_t *euer_zeile_parseFromJSON(cJSON *euer_zeileJSON);

cJSON *euer_zeile_convertToJSON(euer_zeile_t *euer_zeile);

#endif /* _euer_zeile_H_ */

