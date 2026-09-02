#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "euer_ergebnis.h"



static euer_ergebnis_t *euer_ergebnis_create_internal(
    char *anlage_zugaenge,
    char *gewinn_verlust,
    int *jahr,
    char *summe_ausgaben,
    char *summe_einnahmen,
    list_t *zeilen
    ) {
    euer_ergebnis_t *euer_ergebnis_local_var = malloc(sizeof(euer_ergebnis_t));
    if (!euer_ergebnis_local_var) {
        return NULL;
    }
    memset(euer_ergebnis_local_var, 0, sizeof(euer_ergebnis_t));
    euer_ergebnis_local_var->_library_owned = 1;
    euer_ergebnis_local_var->anlage_zugaenge = anlage_zugaenge;
    euer_ergebnis_local_var->gewinn_verlust = gewinn_verlust;
    euer_ergebnis_local_var->jahr = jahr;
    euer_ergebnis_local_var->summe_ausgaben = summe_ausgaben;
    euer_ergebnis_local_var->summe_einnahmen = summe_einnahmen;
    euer_ergebnis_local_var->zeilen = zeilen;
    return euer_ergebnis_local_var;
}

__attribute__((deprecated)) euer_ergebnis_t *euer_ergebnis_create(
    char *anlage_zugaenge,
    char *gewinn_verlust,
    int *jahr,
    char *summe_ausgaben,
    char *summe_einnahmen,
    list_t *zeilen
    ) {
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    euer_ergebnis_t *result = euer_ergebnis_create_internal (
        anlage_zugaenge,
        gewinn_verlust,
        jahr_copy,
        summe_ausgaben,
        summe_einnahmen,
        zeilen
        );
    if (!result) {
        free(jahr_copy);
    }
    return result;
}

void euer_ergebnis_free(euer_ergebnis_t *euer_ergebnis) {
    if(NULL == euer_ergebnis){
        return ;
    }
    if(euer_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "euer_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (euer_ergebnis->anlage_zugaenge) {
        free(euer_ergebnis->anlage_zugaenge);
        euer_ergebnis->anlage_zugaenge = NULL;
    }
    if (euer_ergebnis->gewinn_verlust) {
        free(euer_ergebnis->gewinn_verlust);
        euer_ergebnis->gewinn_verlust = NULL;
    }
    if (euer_ergebnis->jahr) {
        free(euer_ergebnis->jahr);
        euer_ergebnis->jahr = NULL;
    }
    if (euer_ergebnis->summe_ausgaben) {
        free(euer_ergebnis->summe_ausgaben);
        euer_ergebnis->summe_ausgaben = NULL;
    }
    if (euer_ergebnis->summe_einnahmen) {
        free(euer_ergebnis->summe_einnahmen);
        euer_ergebnis->summe_einnahmen = NULL;
    }
    if (euer_ergebnis->zeilen) {
        list_ForEach(listEntry, euer_ergebnis->zeilen) {
            euer_zeile_free(listEntry->data);
        }
        list_freeList(euer_ergebnis->zeilen);
        euer_ergebnis->zeilen = NULL;
    }
    free(euer_ergebnis);
}

cJSON *euer_ergebnis_convertToJSON(euer_ergebnis_t *euer_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // euer_ergebnis->anlage_zugaenge
    if (!euer_ergebnis->anlage_zugaenge) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "anlage_zugaenge", euer_ergebnis->anlage_zugaenge) == NULL) {
    goto fail; //String
    }


    // euer_ergebnis->gewinn_verlust
    if (!euer_ergebnis->gewinn_verlust) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinn_verlust", euer_ergebnis->gewinn_verlust) == NULL) {
    goto fail; //String
    }


    // euer_ergebnis->jahr
    if (!euer_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *euer_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // euer_ergebnis->summe_ausgaben
    if (!euer_ergebnis->summe_ausgaben) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "summe_ausgaben", euer_ergebnis->summe_ausgaben) == NULL) {
    goto fail; //String
    }


    // euer_ergebnis->summe_einnahmen
    if (!euer_ergebnis->summe_einnahmen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "summe_einnahmen", euer_ergebnis->summe_einnahmen) == NULL) {
    goto fail; //String
    }


    // euer_ergebnis->zeilen
    if (!euer_ergebnis->zeilen) {
        goto fail;
    }
    cJSON *zeilen = cJSON_AddArrayToObject(item, "zeilen");
    if(zeilen == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *zeilenListEntry;
    if (euer_ergebnis->zeilen) {
    list_ForEach(zeilenListEntry, euer_ergebnis->zeilen) {
    cJSON *itemLocal = euer_zeile_convertToJSON(zeilenListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(zeilen, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

euer_ergebnis_t *euer_ergebnis_parseFromJSON(cJSON *euer_ergebnisJSON){

    euer_ergebnis_t *euer_ergebnis_local_var = NULL;

    char *anlage_zugaenge_local_str = NULL;

    char *gewinn_verlust_local_str = NULL;

    // define the local variable for euer_ergebnis->jahr
    int *jahr_local_var = NULL;

    char *summe_ausgaben_local_str = NULL;

    char *summe_einnahmen_local_str = NULL;

    // define the local list for euer_ergebnis->zeilen
    list_t *zeilenList = NULL;

    // euer_ergebnis->anlage_zugaenge
    cJSON *anlage_zugaenge = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "anlage_zugaenge");
    if (cJSON_IsNull(anlage_zugaenge)) {
        anlage_zugaenge = NULL;
    }
    if (!anlage_zugaenge) {
        goto end;
    }

    
    if(!cJSON_IsString(anlage_zugaenge))
    {
    goto end; //String
    }

    // euer_ergebnis->gewinn_verlust
    cJSON *gewinn_verlust = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "gewinn_verlust");
    if (cJSON_IsNull(gewinn_verlust)) {
        gewinn_verlust = NULL;
    }
    if (!gewinn_verlust) {
        goto end;
    }

    
    if(!cJSON_IsString(gewinn_verlust))
    {
    goto end; //String
    }

    // euer_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "jahr");
    if (cJSON_IsNull(jahr)) {
        jahr = NULL;
    }
    if (!jahr) {
        goto end;
    }

    
    if(!cJSON_IsNumber(jahr))
    {
    goto end; //Numeric
    }
    jahr_local_var = malloc(sizeof(int));
    if(!jahr_local_var)
    {
        goto end;
    }
    *jahr_local_var = jahr->valuedouble;

    // euer_ergebnis->summe_ausgaben
    cJSON *summe_ausgaben = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "summe_ausgaben");
    if (cJSON_IsNull(summe_ausgaben)) {
        summe_ausgaben = NULL;
    }
    if (!summe_ausgaben) {
        goto end;
    }

    
    if(!cJSON_IsString(summe_ausgaben))
    {
    goto end; //String
    }

    // euer_ergebnis->summe_einnahmen
    cJSON *summe_einnahmen = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "summe_einnahmen");
    if (cJSON_IsNull(summe_einnahmen)) {
        summe_einnahmen = NULL;
    }
    if (!summe_einnahmen) {
        goto end;
    }

    
    if(!cJSON_IsString(summe_einnahmen))
    {
    goto end; //String
    }

    // euer_ergebnis->zeilen
    cJSON *zeilen = cJSON_GetObjectItemCaseSensitive(euer_ergebnisJSON, "zeilen");
    if (cJSON_IsNull(zeilen)) {
        zeilen = NULL;
    }
    if (!zeilen) {
        goto end;
    }

    
    cJSON *zeilen_local_nonprimitive = NULL;
    if(!cJSON_IsArray(zeilen)){
        goto end; //nonprimitive container
    }

    zeilenList = list_createList();

    cJSON_ArrayForEach(zeilen_local_nonprimitive,zeilen )
    {
        if(!cJSON_IsObject(zeilen_local_nonprimitive)){
            goto end;
        }
        euer_zeile_t *zeilenItem = euer_zeile_parseFromJSON(zeilen_local_nonprimitive);

        list_addElement(zeilenList, zeilenItem);
    }


    if (anlage_zugaenge && !cJSON_IsNull(anlage_zugaenge)) anlage_zugaenge_local_str = strdup(anlage_zugaenge->valuestring);
    if (gewinn_verlust && !cJSON_IsNull(gewinn_verlust)) gewinn_verlust_local_str = strdup(gewinn_verlust->valuestring);
    if (summe_ausgaben && !cJSON_IsNull(summe_ausgaben)) summe_ausgaben_local_str = strdup(summe_ausgaben->valuestring);
    if (summe_einnahmen && !cJSON_IsNull(summe_einnahmen)) summe_einnahmen_local_str = strdup(summe_einnahmen->valuestring);

    euer_ergebnis_local_var = euer_ergebnis_create_internal (
        anlage_zugaenge_local_str,
        gewinn_verlust_local_str,
        jahr_local_var,
        summe_ausgaben_local_str,
        summe_einnahmen_local_str,
        zeilenList
        );

    if (!euer_ergebnis_local_var) {
        goto end;
    }

    return euer_ergebnis_local_var;
end:
    if (anlage_zugaenge_local_str) {
        free(anlage_zugaenge_local_str);
        anlage_zugaenge_local_str = NULL;
    }
    if (gewinn_verlust_local_str) {
        free(gewinn_verlust_local_str);
        gewinn_verlust_local_str = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (summe_ausgaben_local_str) {
        free(summe_ausgaben_local_str);
        summe_ausgaben_local_str = NULL;
    }
    if (summe_einnahmen_local_str) {
        free(summe_einnahmen_local_str);
        summe_einnahmen_local_str = NULL;
    }
    if (zeilenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, zeilenList) {
            euer_zeile_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(zeilenList);
        zeilenList = NULL;
    }
    return NULL;

}
