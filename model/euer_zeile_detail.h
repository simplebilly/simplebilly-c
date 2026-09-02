/*
 * euer_zeile_detail.h
 *
 * 
 */

#ifndef _euer_zeile_detail_H_
#define _euer_zeile_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct euer_zeile_detail_t euer_zeile_detail_t;

#include "euer_kat_summe.h"



typedef struct euer_zeile_detail_t {
    char *abschnitt; // string
    char *betrag_gesamt; // string
    char *bezeichnung; // string
    list_t *kategorien; //nonprimitive container
    int *zeile; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} euer_zeile_detail_t;

__attribute__((deprecated)) euer_zeile_detail_t *euer_zeile_detail_create(
    char *abschnitt,
    char *betrag_gesamt,
    char *bezeichnung,
    list_t *kategorien,
    int *zeile
);

void euer_zeile_detail_free(euer_zeile_detail_t *euer_zeile_detail);

euer_zeile_detail_t *euer_zeile_detail_parseFromJSON(cJSON *euer_zeile_detailJSON);

cJSON *euer_zeile_detail_convertToJSON(euer_zeile_detail_t *euer_zeile_detail);

#endif /* _euer_zeile_detail_H_ */

