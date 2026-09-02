/*
 * eks_ergebnis.h
 *
 * 
 */

#ifndef _eks_ergebnis_H_
#define _eks_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct eks_ergebnis_t eks_ergebnis_t;

#include "eks_monats_wert.h"



typedef struct eks_ergebnis_t {
    char *gesamtergebnis; // string
    list_t *monate; //nonprimitive container
    char *prognose_naechste_6_monate; // string
    char *summe_ausgaben; // string
    char *summe_einnahmen; // string
    char *zeitraum_bis; // string
    char *zeitraum_von; // string

    int _library_owned; // Is the library responsible for freeing this object?
} eks_ergebnis_t;

__attribute__((deprecated)) eks_ergebnis_t *eks_ergebnis_create(
    char *gesamtergebnis,
    list_t *monate,
    char *prognose_naechste_6_monate,
    char *summe_ausgaben,
    char *summe_einnahmen,
    char *zeitraum_bis,
    char *zeitraum_von
);

void eks_ergebnis_free(eks_ergebnis_t *eks_ergebnis);

eks_ergebnis_t *eks_ergebnis_parseFromJSON(cJSON *eks_ergebnisJSON);

cJSON *eks_ergebnis_convertToJSON(eks_ergebnis_t *eks_ergebnis);

#endif /* _eks_ergebnis_H_ */

