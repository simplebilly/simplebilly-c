/*
 * kst_ergebnis.h
 *
 * 
 */

#ifndef _kst_ergebnis_H_
#define _kst_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kst_ergebnis_t kst_ergebnis_t;




typedef struct kst_ergebnis_t {
    char *gesamt; // string
    char *gesamtbelastung; // string
    char *gewerbesteuer; // string
    char *gewinn; // string
    int *ist_kapitalgesellschaft; //boolean
    int *jahr; //numeric
    char *koerperschaftsteuer; // string
    char *solidaritaetszuschlag; // string

    int _library_owned; // Is the library responsible for freeing this object?
} kst_ergebnis_t;

__attribute__((deprecated)) kst_ergebnis_t *kst_ergebnis_create(
    char *gesamt,
    char *gesamtbelastung,
    char *gewerbesteuer,
    char *gewinn,
    int *ist_kapitalgesellschaft,
    int *jahr,
    char *koerperschaftsteuer,
    char *solidaritaetszuschlag
);

void kst_ergebnis_free(kst_ergebnis_t *kst_ergebnis);

kst_ergebnis_t *kst_ergebnis_parseFromJSON(cJSON *kst_ergebnisJSON);

cJSON *kst_ergebnis_convertToJSON(kst_ergebnis_t *kst_ergebnis);

#endif /* _kst_ergebnis_H_ */

