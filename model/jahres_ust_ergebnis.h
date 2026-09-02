/*
 * jahres_ust_ergebnis.h
 *
 * 
 */

#ifndef _jahres_ust_ergebnis_H_
#define _jahres_ust_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct jahres_ust_ergebnis_t jahres_ust_ergebnis_t;




typedef struct jahres_ust_ergebnis_t {
    char *bis; // string
    int *gespeicherte_perioden; //numeric
    int *hat_ig_transaktionen; //boolean
    int *ist_kleinunternehmer; //boolean
    int *jahr; //numeric
    char *kz_41; // string
    char *kz_43; // string
    char *kz_46; // string
    char *kz_47; // string
    char *kz_48; // string
    char *kz_61; // string
    char *kz_66; // string
    char *kz_67; // string
    char *kz_81; // string
    char *kz_83; // string
    char *kz_84; // string
    char *kz_85; // string
    char *kz_86; // string
    char *kz_88; // string
    char *kz_89; // string
    char *kz_93; // string
    char *restschuld; // string
    char *summe_vorauszahlungen; // string
    char *von; // string
    char *zahllast; // string

    int _library_owned; // Is the library responsible for freeing this object?
} jahres_ust_ergebnis_t;

__attribute__((deprecated)) jahres_ust_ergebnis_t *jahres_ust_ergebnis_create(
    char *bis,
    int *gespeicherte_perioden,
    int *hat_ig_transaktionen,
    int *ist_kleinunternehmer,
    int *jahr,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
    char *kz_48,
    char *kz_61,
    char *kz_66,
    char *kz_67,
    char *kz_81,
    char *kz_83,
    char *kz_84,
    char *kz_85,
    char *kz_86,
    char *kz_88,
    char *kz_89,
    char *kz_93,
    char *restschuld,
    char *summe_vorauszahlungen,
    char *von,
    char *zahllast
);

void jahres_ust_ergebnis_free(jahres_ust_ergebnis_t *jahres_ust_ergebnis);

jahres_ust_ergebnis_t *jahres_ust_ergebnis_parseFromJSON(cJSON *jahres_ust_ergebnisJSON);

cJSON *jahres_ust_ergebnis_convertToJSON(jahres_ust_ergebnis_t *jahres_ust_ergebnis);

#endif /* _jahres_ust_ergebnis_H_ */

