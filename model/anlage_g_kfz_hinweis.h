/*
 * anlage_g_kfz_hinweis.h
 *
 * 
 */

#ifndef _anlage_g_kfz_hinweis_H_
#define _anlage_g_kfz_hinweis_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct anlage_g_kfz_hinweis_t anlage_g_kfz_hinweis_t;




typedef struct anlage_g_kfz_hinweis_t {
    char *bezeichnung; // string
    char *kennzeichen; // string
    char *privat_anteil_prozent; // string

    int _library_owned; // Is the library responsible for freeing this object?
} anlage_g_kfz_hinweis_t;

__attribute__((deprecated)) anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_create(
    char *bezeichnung,
    char *kennzeichen,
    char *privat_anteil_prozent
);

void anlage_g_kfz_hinweis_free(anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis);

anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis_parseFromJSON(cJSON *anlage_g_kfz_hinweisJSON);

cJSON *anlage_g_kfz_hinweis_convertToJSON(anlage_g_kfz_hinweis_t *anlage_g_kfz_hinweis);

#endif /* _anlage_g_kfz_hinweis_H_ */

