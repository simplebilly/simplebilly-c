/*
 * anlage_s_ergebnis.h
 *
 * 
 */

#ifndef _anlage_s_ergebnis_H_
#define _anlage_s_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct anlage_s_ergebnis_t anlage_s_ergebnis_t;

#include "anlage_s_kfz_hinweis.h"



typedef struct anlage_s_ergebnis_t {
    char *gewinn_verlust; // string
    int *jahr; //numeric
    list_t *kfz_hinweise; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} anlage_s_ergebnis_t;

__attribute__((deprecated)) anlage_s_ergebnis_t *anlage_s_ergebnis_create(
    char *gewinn_verlust,
    int *jahr,
    list_t *kfz_hinweise
);

void anlage_s_ergebnis_free(anlage_s_ergebnis_t *anlage_s_ergebnis);

anlage_s_ergebnis_t *anlage_s_ergebnis_parseFromJSON(cJSON *anlage_s_ergebnisJSON);

cJSON *anlage_s_ergebnis_convertToJSON(anlage_s_ergebnis_t *anlage_s_ergebnis);

#endif /* _anlage_s_ergebnis_H_ */

