#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fristen_ergebnis.h"



static fristen_ergebnis_t *fristen_ergebnis_create_internal(
    int *anzahl,
    list_t *fristen
    ) {
    fristen_ergebnis_t *fristen_ergebnis_local_var = malloc(sizeof(fristen_ergebnis_t));
    if (!fristen_ergebnis_local_var) {
        return NULL;
    }
    memset(fristen_ergebnis_local_var, 0, sizeof(fristen_ergebnis_t));
    fristen_ergebnis_local_var->_library_owned = 1;
    fristen_ergebnis_local_var->anzahl = anzahl;
    fristen_ergebnis_local_var->fristen = fristen;
    return fristen_ergebnis_local_var;
}

__attribute__((deprecated)) fristen_ergebnis_t *fristen_ergebnis_create(
    int *anzahl,
    list_t *fristen
    ) {
    int *anzahl_copy = NULL;
    if (anzahl) {
        anzahl_copy = malloc(sizeof(int));
        if (anzahl_copy) *anzahl_copy = *anzahl;
    }
    fristen_ergebnis_t *result = fristen_ergebnis_create_internal (
        anzahl_copy,
        fristen
        );
    if (!result) {
        free(anzahl_copy);
    }
    return result;
}

void fristen_ergebnis_free(fristen_ergebnis_t *fristen_ergebnis) {
    if(NULL == fristen_ergebnis){
        return ;
    }
    if(fristen_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "fristen_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (fristen_ergebnis->anzahl) {
        free(fristen_ergebnis->anzahl);
        fristen_ergebnis->anzahl = NULL;
    }
    if (fristen_ergebnis->fristen) {
        list_ForEach(listEntry, fristen_ergebnis->fristen) {
            frist_eintrag_free(listEntry->data);
        }
        list_freeList(fristen_ergebnis->fristen);
        fristen_ergebnis->fristen = NULL;
    }
    free(fristen_ergebnis);
}

cJSON *fristen_ergebnis_convertToJSON(fristen_ergebnis_t *fristen_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // fristen_ergebnis->anzahl
    if (!fristen_ergebnis->anzahl) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "anzahl", *fristen_ergebnis->anzahl) == NULL) {
    goto fail; //Numeric
    }


    // fristen_ergebnis->fristen
    if (!fristen_ergebnis->fristen) {
        goto fail;
    }
    cJSON *fristen = cJSON_AddArrayToObject(item, "fristen");
    if(fristen == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *fristenListEntry;
    if (fristen_ergebnis->fristen) {
    list_ForEach(fristenListEntry, fristen_ergebnis->fristen) {
    cJSON *itemLocal = frist_eintrag_convertToJSON(fristenListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(fristen, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

fristen_ergebnis_t *fristen_ergebnis_parseFromJSON(cJSON *fristen_ergebnisJSON){

    fristen_ergebnis_t *fristen_ergebnis_local_var = NULL;

    // define the local variable for fristen_ergebnis->anzahl
    int *anzahl_local_var = NULL;

    // define the local list for fristen_ergebnis->fristen
    list_t *fristenList = NULL;

    // fristen_ergebnis->anzahl
    cJSON *anzahl = cJSON_GetObjectItemCaseSensitive(fristen_ergebnisJSON, "anzahl");
    if (cJSON_IsNull(anzahl)) {
        anzahl = NULL;
    }
    if (!anzahl) {
        goto end;
    }

    
    if(!cJSON_IsNumber(anzahl))
    {
    goto end; //Numeric
    }
    anzahl_local_var = malloc(sizeof(int));
    if(!anzahl_local_var)
    {
        goto end;
    }
    *anzahl_local_var = anzahl->valuedouble;

    // fristen_ergebnis->fristen
    cJSON *fristen = cJSON_GetObjectItemCaseSensitive(fristen_ergebnisJSON, "fristen");
    if (cJSON_IsNull(fristen)) {
        fristen = NULL;
    }
    if (!fristen) {
        goto end;
    }

    
    cJSON *fristen_local_nonprimitive = NULL;
    if(!cJSON_IsArray(fristen)){
        goto end; //nonprimitive container
    }

    fristenList = list_createList();

    cJSON_ArrayForEach(fristen_local_nonprimitive,fristen )
    {
        if(!cJSON_IsObject(fristen_local_nonprimitive)){
            goto end;
        }
        frist_eintrag_t *fristenItem = frist_eintrag_parseFromJSON(fristen_local_nonprimitive);

        list_addElement(fristenList, fristenItem);
    }



    fristen_ergebnis_local_var = fristen_ergebnis_create_internal (
        anzahl_local_var,
        fristenList
        );

    if (!fristen_ergebnis_local_var) {
        goto end;
    }

    return fristen_ergebnis_local_var;
end:
    if (anzahl_local_var) {
        free(anzahl_local_var);
        anzahl_local_var = NULL;
    }
    if (fristenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, fristenList) {
            frist_eintrag_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(fristenList);
        fristenList = NULL;
    }
    return NULL;

}
