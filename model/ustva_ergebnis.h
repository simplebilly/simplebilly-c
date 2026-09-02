/*
 * ustva_ergebnis.h
 *
 * 
 */

#ifndef _ustva_ergebnis_H_
#define _ustva_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ustva_ergebnis_t ustva_ergebnis_t;




typedef struct ustva_ergebnis_t {
    char *bis; // string
    char *hinweis; // string
    int *ist_kleinunternehmer; //boolean
    char *kz_41; // string
    char *kz_43; // string
    char *kz_46; // string
    char *kz_47; // string
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
    char *von; // string
    char *zahllast; // string
    char *zeitraum; // string
    char *zeitraum_typ; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ustva_ergebnis_t;

__attribute__((deprecated)) ustva_ergebnis_t *ustva_ergebnis_create(
    char *bis,
    char *hinweis,
    int *ist_kleinunternehmer,
    char *kz_41,
    char *kz_43,
    char *kz_46,
    char *kz_47,
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
    char *von,
    char *zahllast,
    char *zeitraum,
    char *zeitraum_typ
);

void ustva_ergebnis_free(ustva_ergebnis_t *ustva_ergebnis);

ustva_ergebnis_t *ustva_ergebnis_parseFromJSON(cJSON *ustva_ergebnisJSON);

cJSON *ustva_ergebnis_convertToJSON(ustva_ergebnis_t *ustva_ergebnis);

#endif /* _ustva_ergebnis_H_ */

