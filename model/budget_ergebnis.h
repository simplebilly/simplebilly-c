/*
 * budget_ergebnis.h
 *
 * 
 */

#ifndef _budget_ergebnis_H_
#define _budget_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct budget_ergebnis_t budget_ergebnis_t;

#include "budget_kategorie.h"



typedef struct budget_ergebnis_t {
    int *jahr; //numeric
    int *monat; //numeric
    list_t *monats_budget; //nonprimitive container
    list_t *prognose_restjahr; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} budget_ergebnis_t;

__attribute__((deprecated)) budget_ergebnis_t *budget_ergebnis_create(
    int *jahr,
    int *monat,
    list_t *monats_budget,
    list_t *prognose_restjahr
);

void budget_ergebnis_free(budget_ergebnis_t *budget_ergebnis);

budget_ergebnis_t *budget_ergebnis_parseFromJSON(cJSON *budget_ergebnisJSON);

cJSON *budget_ergebnis_convertToJSON(budget_ergebnis_t *budget_ergebnis);

#endif /* _budget_ergebnis_H_ */

