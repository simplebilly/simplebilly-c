#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eks_ergebnis.h"



static eks_ergebnis_t *eks_ergebnis_create_internal(
    char *gesamtergebnis,
    list_t *monate,
    char *prognose_naechste_6_monate,
    char *summe_ausgaben,
    char *summe_einnahmen,
    char *zeitraum_bis,
    char *zeitraum_von
    ) {
    eks_ergebnis_t *eks_ergebnis_local_var = malloc(sizeof(eks_ergebnis_t));
    if (!eks_ergebnis_local_var) {
        return NULL;
    }
    memset(eks_ergebnis_local_var, 0, sizeof(eks_ergebnis_t));
    eks_ergebnis_local_var->_library_owned = 1;
    eks_ergebnis_local_var->gesamtergebnis = gesamtergebnis;
    eks_ergebnis_local_var->monate = monate;
    eks_ergebnis_local_var->prognose_naechste_6_monate = prognose_naechste_6_monate;
    eks_ergebnis_local_var->summe_ausgaben = summe_ausgaben;
    eks_ergebnis_local_var->summe_einnahmen = summe_einnahmen;
    eks_ergebnis_local_var->zeitraum_bis = zeitraum_bis;
    eks_ergebnis_local_var->zeitraum_von = zeitraum_von;
    return eks_ergebnis_local_var;
}

__attribute__((deprecated)) eks_ergebnis_t *eks_ergebnis_create(
    char *gesamtergebnis,
    list_t *monate,
    char *prognose_naechste_6_monate,
    char *summe_ausgaben,
    char *summe_einnahmen,
    char *zeitraum_bis,
    char *zeitraum_von
    ) {
    eks_ergebnis_t *result = eks_ergebnis_create_internal (
        gesamtergebnis,
        monate,
        prognose_naechste_6_monate,
        summe_ausgaben,
        summe_einnahmen,
        zeitraum_bis,
        zeitraum_von
        );
    if (!result) {
    }
    return result;
}

void eks_ergebnis_free(eks_ergebnis_t *eks_ergebnis) {
    if(NULL == eks_ergebnis){
        return ;
    }
    if(eks_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "eks_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (eks_ergebnis->gesamtergebnis) {
        free(eks_ergebnis->gesamtergebnis);
        eks_ergebnis->gesamtergebnis = NULL;
    }
    if (eks_ergebnis->monate) {
        list_ForEach(listEntry, eks_ergebnis->monate) {
            eks_monats_wert_free(listEntry->data);
        }
        list_freeList(eks_ergebnis->monate);
        eks_ergebnis->monate = NULL;
    }
    if (eks_ergebnis->prognose_naechste_6_monate) {
        free(eks_ergebnis->prognose_naechste_6_monate);
        eks_ergebnis->prognose_naechste_6_monate = NULL;
    }
    if (eks_ergebnis->summe_ausgaben) {
        free(eks_ergebnis->summe_ausgaben);
        eks_ergebnis->summe_ausgaben = NULL;
    }
    if (eks_ergebnis->summe_einnahmen) {
        free(eks_ergebnis->summe_einnahmen);
        eks_ergebnis->summe_einnahmen = NULL;
    }
    if (eks_ergebnis->zeitraum_bis) {
        free(eks_ergebnis->zeitraum_bis);
        eks_ergebnis->zeitraum_bis = NULL;
    }
    if (eks_ergebnis->zeitraum_von) {
        free(eks_ergebnis->zeitraum_von);
        eks_ergebnis->zeitraum_von = NULL;
    }
    free(eks_ergebnis);
}

cJSON *eks_ergebnis_convertToJSON(eks_ergebnis_t *eks_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // eks_ergebnis->gesamtergebnis
    if (!eks_ergebnis->gesamtergebnis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gesamtergebnis", eks_ergebnis->gesamtergebnis) == NULL) {
    goto fail; //String
    }


    // eks_ergebnis->monate
    if (!eks_ergebnis->monate) {
        goto fail;
    }
    cJSON *monate = cJSON_AddArrayToObject(item, "monate");
    if(monate == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *monateListEntry;
    if (eks_ergebnis->monate) {
    list_ForEach(monateListEntry, eks_ergebnis->monate) {
    cJSON *itemLocal = eks_monats_wert_convertToJSON(monateListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(monate, itemLocal);
    }
    }


    // eks_ergebnis->prognose_naechste_6_monate
    if (!eks_ergebnis->prognose_naechste_6_monate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "prognose_naechste_6_monate", eks_ergebnis->prognose_naechste_6_monate) == NULL) {
    goto fail; //String
    }


    // eks_ergebnis->summe_ausgaben
    if (!eks_ergebnis->summe_ausgaben) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "summe_ausgaben", eks_ergebnis->summe_ausgaben) == NULL) {
    goto fail; //String
    }


    // eks_ergebnis->summe_einnahmen
    if (!eks_ergebnis->summe_einnahmen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "summe_einnahmen", eks_ergebnis->summe_einnahmen) == NULL) {
    goto fail; //String
    }


    // eks_ergebnis->zeitraum_bis
    if (!eks_ergebnis->zeitraum_bis) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zeitraum_bis", eks_ergebnis->zeitraum_bis) == NULL) {
    goto fail; //String
    }


    // eks_ergebnis->zeitraum_von
    if (!eks_ergebnis->zeitraum_von) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "zeitraum_von", eks_ergebnis->zeitraum_von) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

eks_ergebnis_t *eks_ergebnis_parseFromJSON(cJSON *eks_ergebnisJSON){

    eks_ergebnis_t *eks_ergebnis_local_var = NULL;

    char *gesamtergebnis_local_str = NULL;

    // define the local list for eks_ergebnis->monate
    list_t *monateList = NULL;

    char *prognose_naechste_6_monate_local_str = NULL;

    char *summe_ausgaben_local_str = NULL;

    char *summe_einnahmen_local_str = NULL;

    char *zeitraum_bis_local_str = NULL;

    char *zeitraum_von_local_str = NULL;

    // eks_ergebnis->gesamtergebnis
    cJSON *gesamtergebnis = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "gesamtergebnis");
    if (cJSON_IsNull(gesamtergebnis)) {
        gesamtergebnis = NULL;
    }
    if (!gesamtergebnis) {
        goto end;
    }

    
    if(!cJSON_IsString(gesamtergebnis))
    {
    goto end; //String
    }

    // eks_ergebnis->monate
    cJSON *monate = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "monate");
    if (cJSON_IsNull(monate)) {
        monate = NULL;
    }
    if (!monate) {
        goto end;
    }

    
    cJSON *monate_local_nonprimitive = NULL;
    if(!cJSON_IsArray(monate)){
        goto end; //nonprimitive container
    }

    monateList = list_createList();

    cJSON_ArrayForEach(monate_local_nonprimitive,monate )
    {
        if(!cJSON_IsObject(monate_local_nonprimitive)){
            goto end;
        }
        eks_monats_wert_t *monateItem = eks_monats_wert_parseFromJSON(monate_local_nonprimitive);

        list_addElement(monateList, monateItem);
    }

    // eks_ergebnis->prognose_naechste_6_monate
    cJSON *prognose_naechste_6_monate = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "prognose_naechste_6_monate");
    if (cJSON_IsNull(prognose_naechste_6_monate)) {
        prognose_naechste_6_monate = NULL;
    }
    if (!prognose_naechste_6_monate) {
        goto end;
    }

    
    if(!cJSON_IsString(prognose_naechste_6_monate))
    {
    goto end; //String
    }

    // eks_ergebnis->summe_ausgaben
    cJSON *summe_ausgaben = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "summe_ausgaben");
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

    // eks_ergebnis->summe_einnahmen
    cJSON *summe_einnahmen = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "summe_einnahmen");
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

    // eks_ergebnis->zeitraum_bis
    cJSON *zeitraum_bis = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "zeitraum_bis");
    if (cJSON_IsNull(zeitraum_bis)) {
        zeitraum_bis = NULL;
    }
    if (!zeitraum_bis) {
        goto end;
    }

    
    if(!cJSON_IsString(zeitraum_bis))
    {
    goto end; //String
    }

    // eks_ergebnis->zeitraum_von
    cJSON *zeitraum_von = cJSON_GetObjectItemCaseSensitive(eks_ergebnisJSON, "zeitraum_von");
    if (cJSON_IsNull(zeitraum_von)) {
        zeitraum_von = NULL;
    }
    if (!zeitraum_von) {
        goto end;
    }

    
    if(!cJSON_IsString(zeitraum_von))
    {
    goto end; //String
    }


    if (gesamtergebnis && !cJSON_IsNull(gesamtergebnis)) gesamtergebnis_local_str = strdup(gesamtergebnis->valuestring);
    if (prognose_naechste_6_monate && !cJSON_IsNull(prognose_naechste_6_monate)) prognose_naechste_6_monate_local_str = strdup(prognose_naechste_6_monate->valuestring);
    if (summe_ausgaben && !cJSON_IsNull(summe_ausgaben)) summe_ausgaben_local_str = strdup(summe_ausgaben->valuestring);
    if (summe_einnahmen && !cJSON_IsNull(summe_einnahmen)) summe_einnahmen_local_str = strdup(summe_einnahmen->valuestring);
    if (zeitraum_bis && !cJSON_IsNull(zeitraum_bis)) zeitraum_bis_local_str = strdup(zeitraum_bis->valuestring);
    if (zeitraum_von && !cJSON_IsNull(zeitraum_von)) zeitraum_von_local_str = strdup(zeitraum_von->valuestring);

    eks_ergebnis_local_var = eks_ergebnis_create_internal (
        gesamtergebnis_local_str,
        monateList,
        prognose_naechste_6_monate_local_str,
        summe_ausgaben_local_str,
        summe_einnahmen_local_str,
        zeitraum_bis_local_str,
        zeitraum_von_local_str
        );

    if (!eks_ergebnis_local_var) {
        goto end;
    }

    return eks_ergebnis_local_var;
end:
    if (gesamtergebnis_local_str) {
        free(gesamtergebnis_local_str);
        gesamtergebnis_local_str = NULL;
    }
    if (monateList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, monateList) {
            eks_monats_wert_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(monateList);
        monateList = NULL;
    }
    if (prognose_naechste_6_monate_local_str) {
        free(prognose_naechste_6_monate_local_str);
        prognose_naechste_6_monate_local_str = NULL;
    }
    if (summe_ausgaben_local_str) {
        free(summe_ausgaben_local_str);
        summe_ausgaben_local_str = NULL;
    }
    if (summe_einnahmen_local_str) {
        free(summe_einnahmen_local_str);
        summe_einnahmen_local_str = NULL;
    }
    if (zeitraum_bis_local_str) {
        free(zeitraum_bis_local_str);
        zeitraum_bis_local_str = NULL;
    }
    if (zeitraum_von_local_str) {
        free(zeitraum_von_local_str);
        zeitraum_von_local_str = NULL;
    }
    return NULL;

}
