#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "euer_zeile_detail.h"



static euer_zeile_detail_t *euer_zeile_detail_create_internal(
    char *abschnitt,
    char *betrag_gesamt,
    char *bezeichnung,
    list_t *kategorien,
    int *zeile
    ) {
    euer_zeile_detail_t *euer_zeile_detail_local_var = malloc(sizeof(euer_zeile_detail_t));
    if (!euer_zeile_detail_local_var) {
        return NULL;
    }
    memset(euer_zeile_detail_local_var, 0, sizeof(euer_zeile_detail_t));
    euer_zeile_detail_local_var->_library_owned = 1;
    euer_zeile_detail_local_var->abschnitt = abschnitt;
    euer_zeile_detail_local_var->betrag_gesamt = betrag_gesamt;
    euer_zeile_detail_local_var->bezeichnung = bezeichnung;
    euer_zeile_detail_local_var->kategorien = kategorien;
    euer_zeile_detail_local_var->zeile = zeile;
    return euer_zeile_detail_local_var;
}

__attribute__((deprecated)) euer_zeile_detail_t *euer_zeile_detail_create(
    char *abschnitt,
    char *betrag_gesamt,
    char *bezeichnung,
    list_t *kategorien,
    int *zeile
    ) {
    int *zeile_copy = NULL;
    if (zeile) {
        zeile_copy = malloc(sizeof(int));
        if (zeile_copy) *zeile_copy = *zeile;
    }
    euer_zeile_detail_t *result = euer_zeile_detail_create_internal (
        abschnitt,
        betrag_gesamt,
        bezeichnung,
        kategorien,
        zeile_copy
        );
    if (!result) {
        free(zeile_copy);
    }
    return result;
}

void euer_zeile_detail_free(euer_zeile_detail_t *euer_zeile_detail) {
    if(NULL == euer_zeile_detail){
        return ;
    }
    if(euer_zeile_detail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "euer_zeile_detail_free");
        return ;
    }
    listEntry_t *listEntry;
    if (euer_zeile_detail->abschnitt) {
        free(euer_zeile_detail->abschnitt);
        euer_zeile_detail->abschnitt = NULL;
    }
    if (euer_zeile_detail->betrag_gesamt) {
        free(euer_zeile_detail->betrag_gesamt);
        euer_zeile_detail->betrag_gesamt = NULL;
    }
    if (euer_zeile_detail->bezeichnung) {
        free(euer_zeile_detail->bezeichnung);
        euer_zeile_detail->bezeichnung = NULL;
    }
    if (euer_zeile_detail->kategorien) {
        list_ForEach(listEntry, euer_zeile_detail->kategorien) {
            euer_kat_summe_free(listEntry->data);
        }
        list_freeList(euer_zeile_detail->kategorien);
        euer_zeile_detail->kategorien = NULL;
    }
    if (euer_zeile_detail->zeile) {
        free(euer_zeile_detail->zeile);
        euer_zeile_detail->zeile = NULL;
    }
    free(euer_zeile_detail);
}

cJSON *euer_zeile_detail_convertToJSON(euer_zeile_detail_t *euer_zeile_detail) {
    cJSON *item = cJSON_CreateObject();

    // euer_zeile_detail->abschnitt
    if (!euer_zeile_detail->abschnitt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "abschnitt", euer_zeile_detail->abschnitt) == NULL) {
    goto fail; //String
    }


    // euer_zeile_detail->betrag_gesamt
    if (!euer_zeile_detail->betrag_gesamt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "betrag_gesamt", euer_zeile_detail->betrag_gesamt) == NULL) {
    goto fail; //String
    }


    // euer_zeile_detail->bezeichnung
    if (!euer_zeile_detail->bezeichnung) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bezeichnung", euer_zeile_detail->bezeichnung) == NULL) {
    goto fail; //String
    }


    // euer_zeile_detail->kategorien
    if (!euer_zeile_detail->kategorien) {
        goto fail;
    }
    cJSON *kategorien = cJSON_AddArrayToObject(item, "kategorien");
    if(kategorien == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *kategorienListEntry;
    if (euer_zeile_detail->kategorien) {
    list_ForEach(kategorienListEntry, euer_zeile_detail->kategorien) {
    cJSON *itemLocal = euer_kat_summe_convertToJSON(kategorienListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(kategorien, itemLocal);
    }
    }


    // euer_zeile_detail->zeile
    if (!euer_zeile_detail->zeile) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "zeile", *euer_zeile_detail->zeile) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

euer_zeile_detail_t *euer_zeile_detail_parseFromJSON(cJSON *euer_zeile_detailJSON){

    euer_zeile_detail_t *euer_zeile_detail_local_var = NULL;

    char *abschnitt_local_str = NULL;

    char *betrag_gesamt_local_str = NULL;

    char *bezeichnung_local_str = NULL;

    // define the local list for euer_zeile_detail->kategorien
    list_t *kategorienList = NULL;

    // define the local variable for euer_zeile_detail->zeile
    int *zeile_local_var = NULL;

    // euer_zeile_detail->abschnitt
    cJSON *abschnitt = cJSON_GetObjectItemCaseSensitive(euer_zeile_detailJSON, "abschnitt");
    if (cJSON_IsNull(abschnitt)) {
        abschnitt = NULL;
    }
    if (!abschnitt) {
        goto end;
    }

    
    if(!cJSON_IsString(abschnitt))
    {
    goto end; //String
    }

    // euer_zeile_detail->betrag_gesamt
    cJSON *betrag_gesamt = cJSON_GetObjectItemCaseSensitive(euer_zeile_detailJSON, "betrag_gesamt");
    if (cJSON_IsNull(betrag_gesamt)) {
        betrag_gesamt = NULL;
    }
    if (!betrag_gesamt) {
        goto end;
    }

    
    if(!cJSON_IsString(betrag_gesamt))
    {
    goto end; //String
    }

    // euer_zeile_detail->bezeichnung
    cJSON *bezeichnung = cJSON_GetObjectItemCaseSensitive(euer_zeile_detailJSON, "bezeichnung");
    if (cJSON_IsNull(bezeichnung)) {
        bezeichnung = NULL;
    }
    if (!bezeichnung) {
        goto end;
    }

    
    if(!cJSON_IsString(bezeichnung))
    {
    goto end; //String
    }

    // euer_zeile_detail->kategorien
    cJSON *kategorien = cJSON_GetObjectItemCaseSensitive(euer_zeile_detailJSON, "kategorien");
    if (cJSON_IsNull(kategorien)) {
        kategorien = NULL;
    }
    if (!kategorien) {
        goto end;
    }

    
    cJSON *kategorien_local_nonprimitive = NULL;
    if(!cJSON_IsArray(kategorien)){
        goto end; //nonprimitive container
    }

    kategorienList = list_createList();

    cJSON_ArrayForEach(kategorien_local_nonprimitive,kategorien )
    {
        if(!cJSON_IsObject(kategorien_local_nonprimitive)){
            goto end;
        }
        euer_kat_summe_t *kategorienItem = euer_kat_summe_parseFromJSON(kategorien_local_nonprimitive);

        list_addElement(kategorienList, kategorienItem);
    }

    // euer_zeile_detail->zeile
    cJSON *zeile = cJSON_GetObjectItemCaseSensitive(euer_zeile_detailJSON, "zeile");
    if (cJSON_IsNull(zeile)) {
        zeile = NULL;
    }
    if (!zeile) {
        goto end;
    }

    
    if(!cJSON_IsNumber(zeile))
    {
    goto end; //Numeric
    }
    zeile_local_var = malloc(sizeof(int));
    if(!zeile_local_var)
    {
        goto end;
    }
    *zeile_local_var = zeile->valuedouble;


    if (abschnitt && !cJSON_IsNull(abschnitt)) abschnitt_local_str = strdup(abschnitt->valuestring);
    if (betrag_gesamt && !cJSON_IsNull(betrag_gesamt)) betrag_gesamt_local_str = strdup(betrag_gesamt->valuestring);
    if (bezeichnung && !cJSON_IsNull(bezeichnung)) bezeichnung_local_str = strdup(bezeichnung->valuestring);

    euer_zeile_detail_local_var = euer_zeile_detail_create_internal (
        abschnitt_local_str,
        betrag_gesamt_local_str,
        bezeichnung_local_str,
        kategorienList,
        zeile_local_var
        );

    if (!euer_zeile_detail_local_var) {
        goto end;
    }

    return euer_zeile_detail_local_var;
end:
    if (abschnitt_local_str) {
        free(abschnitt_local_str);
        abschnitt_local_str = NULL;
    }
    if (betrag_gesamt_local_str) {
        free(betrag_gesamt_local_str);
        betrag_gesamt_local_str = NULL;
    }
    if (bezeichnung_local_str) {
        free(bezeichnung_local_str);
        bezeichnung_local_str = NULL;
    }
    if (kategorienList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, kategorienList) {
            euer_kat_summe_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(kategorienList);
        kategorienList = NULL;
    }
    if (zeile_local_var) {
        free(zeile_local_var);
        zeile_local_var = NULL;
    }
    return NULL;

}
