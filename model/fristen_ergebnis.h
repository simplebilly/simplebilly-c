/*
 * fristen_ergebnis.h
 *
 * 
 */

#ifndef _fristen_ergebnis_H_
#define _fristen_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fristen_ergebnis_t fristen_ergebnis_t;

#include "frist_eintrag.h"



typedef struct fristen_ergebnis_t {
    int *anzahl; //numeric
    list_t *fristen; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} fristen_ergebnis_t;

__attribute__((deprecated)) fristen_ergebnis_t *fristen_ergebnis_create(
    int *anzahl,
    list_t *fristen
);

void fristen_ergebnis_free(fristen_ergebnis_t *fristen_ergebnis);

fristen_ergebnis_t *fristen_ergebnis_parseFromJSON(cJSON *fristen_ergebnisJSON);

cJSON *fristen_ergebnis_convertToJSON(fristen_ergebnis_t *fristen_ergebnis);

#endif /* _fristen_ergebnis_H_ */

