/*
 * gewerbesteuer_ergebnis.h
 *
 * 
 */

#ifndef _gewerbesteuer_ergebnis_H_
#define _gewerbesteuer_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gewerbesteuer_ergebnis_t gewerbesteuer_ergebnis_t;




typedef struct gewerbesteuer_ergebnis_t {
    char *freibetrag; // string
    char *gesamtbelastung; // string
    char *gewerbeertrag; // string
    char *hebesatz; // string
    int *jahr; //numeric
    char *koerperschaftsteuer; // string
    char *land; // string
    char *messbetrag; // string
    char *steuer; // string
    char *steuer_art; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gewerbesteuer_ergebnis_t;

__attribute__((deprecated)) gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_create(
    char *freibetrag,
    char *gesamtbelastung,
    char *gewerbeertrag,
    char *hebesatz,
    int *jahr,
    char *koerperschaftsteuer,
    char *land,
    char *messbetrag,
    char *steuer,
    char *steuer_art
);

void gewerbesteuer_ergebnis_free(gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis);

gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis_parseFromJSON(cJSON *gewerbesteuer_ergebnisJSON);

cJSON *gewerbesteuer_ergebnis_convertToJSON(gewerbesteuer_ergebnis_t *gewerbesteuer_ergebnis);

#endif /* _gewerbesteuer_ergebnis_H_ */

