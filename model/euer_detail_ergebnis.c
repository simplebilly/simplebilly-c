#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "euer_detail_ergebnis.h"



static euer_detail_ergebnis_t *euer_detail_ergebnis_create_internal(
    int *jahr,
    list_t *zeilen
    ) {
    euer_detail_ergebnis_t *euer_detail_ergebnis_local_var = malloc(sizeof(euer_detail_ergebnis_t));
    if (!euer_detail_ergebnis_local_var) {
        return NULL;
    }
    memset(euer_detail_ergebnis_local_var, 0, sizeof(euer_detail_ergebnis_t));
    euer_detail_ergebnis_local_var->_library_owned = 1;
    euer_detail_ergebnis_local_var->jahr = jahr;
    euer_detail_ergebnis_local_var->zeilen = zeilen;
    return euer_detail_ergebnis_local_var;
}

__attribute__((deprecated)) euer_detail_ergebnis_t *euer_detail_ergebnis_create(
    int *jahr,
    list_t *zeilen
    ) {
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    euer_detail_ergebnis_t *result = euer_detail_ergebnis_create_internal (
        jahr_copy,
        zeilen
        );
    if (!result) {
        free(jahr_copy);
    }
    return result;
}

void euer_detail_ergebnis_free(euer_detail_ergebnis_t *euer_detail_ergebnis) {
    if(NULL == euer_detail_ergebnis){
        return ;
    }
    if(euer_detail_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "euer_detail_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (euer_detail_ergebnis->jahr) {
        free(euer_detail_ergebnis->jahr);
        euer_detail_ergebnis->jahr = NULL;
    }
    if (euer_detail_ergebnis->zeilen) {
        list_ForEach(listEntry, euer_detail_ergebnis->zeilen) {
            euer_zeile_detail_free(listEntry->data);
        }
        list_freeList(euer_detail_ergebnis->zeilen);
        euer_detail_ergebnis->zeilen = NULL;
    }
    free(euer_detail_ergebnis);
}

cJSON *euer_detail_ergebnis_convertToJSON(euer_detail_ergebnis_t *euer_detail_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // euer_detail_ergebnis->jahr
    if (!euer_detail_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *euer_detail_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // euer_detail_ergebnis->zeilen
    if (!euer_detail_ergebnis->zeilen) {
        goto fail;
    }
    cJSON *zeilen = cJSON_AddArrayToObject(item, "zeilen");
    if(zeilen == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *zeilenListEntry;
    if (euer_detail_ergebnis->zeilen) {
    list_ForEach(zeilenListEntry, euer_detail_ergebnis->zeilen) {
    cJSON *itemLocal = euer_zeile_detail_convertToJSON(zeilenListEntry->data);
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

euer_detail_ergebnis_t *euer_detail_ergebnis_parseFromJSON(cJSON *euer_detail_ergebnisJSON){

    euer_detail_ergebnis_t *euer_detail_ergebnis_local_var = NULL;

    // define the local variable for euer_detail_ergebnis->jahr
    int *jahr_local_var = NULL;

    // define the local list for euer_detail_ergebnis->zeilen
    list_t *zeilenList = NULL;

    // euer_detail_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(euer_detail_ergebnisJSON, "jahr");
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

    // euer_detail_ergebnis->zeilen
    cJSON *zeilen = cJSON_GetObjectItemCaseSensitive(euer_detail_ergebnisJSON, "zeilen");
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
        euer_zeile_detail_t *zeilenItem = euer_zeile_detail_parseFromJSON(zeilen_local_nonprimitive);

        list_addElement(zeilenList, zeilenItem);
    }



    euer_detail_ergebnis_local_var = euer_detail_ergebnis_create_internal (
        jahr_local_var,
        zeilenList
        );

    if (!euer_detail_ergebnis_local_var) {
        goto end;
    }

    return euer_detail_ergebnis_local_var;
end:
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (zeilenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, zeilenList) {
            euer_zeile_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(zeilenList);
        zeilenList = NULL;
    }
    return NULL;

}
