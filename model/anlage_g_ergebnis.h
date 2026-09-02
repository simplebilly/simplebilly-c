/*
 * anlage_g_ergebnis.h
 *
 * 
 */

#ifndef _anlage_g_ergebnis_H_
#define _anlage_g_ergebnis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct anlage_g_ergebnis_t anlage_g_ergebnis_t;

#include "anlage_g_kfz_hinweis.h"



typedef struct anlage_g_ergebnis_t {
    char *gewinn_verlust; // string
    char *gewst_gezahlt; // string
    char *gewst_messbetrag_approx; // string
    int *gewst_pflichtig; //boolean
    int *jahr; //numeric
    list_t *kfz_hinweise; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} anlage_g_ergebnis_t;

__attribute__((deprecated)) anlage_g_ergebnis_t *anlage_g_ergebnis_create(
    char *gewinn_verlust,
    char *gewst_gezahlt,
    char *gewst_messbetrag_approx,
    int *gewst_pflichtig,
    int *jahr,
    list_t *kfz_hinweise
);

void anlage_g_ergebnis_free(anlage_g_ergebnis_t *anlage_g_ergebnis);

anlage_g_ergebnis_t *anlage_g_ergebnis_parseFromJSON(cJSON *anlage_g_ergebnisJSON);

cJSON *anlage_g_ergebnis_convertToJSON(anlage_g_ergebnis_t *anlage_g_ergebnis);

#endif /* _anlage_g_ergebnis_H_ */

