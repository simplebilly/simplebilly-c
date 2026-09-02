#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "anlage_s_ergebnis.h"



static anlage_s_ergebnis_t *anlage_s_ergebnis_create_internal(
    char *gewinn_verlust,
    int *jahr,
    list_t *kfz_hinweise
    ) {
    anlage_s_ergebnis_t *anlage_s_ergebnis_local_var = malloc(sizeof(anlage_s_ergebnis_t));
    if (!anlage_s_ergebnis_local_var) {
        return NULL;
    }
    memset(anlage_s_ergebnis_local_var, 0, sizeof(anlage_s_ergebnis_t));
    anlage_s_ergebnis_local_var->_library_owned = 1;
    anlage_s_ergebnis_local_var->gewinn_verlust = gewinn_verlust;
    anlage_s_ergebnis_local_var->jahr = jahr;
    anlage_s_ergebnis_local_var->kfz_hinweise = kfz_hinweise;
    return anlage_s_ergebnis_local_var;
}

__attribute__((deprecated)) anlage_s_ergebnis_t *anlage_s_ergebnis_create(
    char *gewinn_verlust,
    int *jahr,
    list_t *kfz_hinweise
    ) {
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    anlage_s_ergebnis_t *result = anlage_s_ergebnis_create_internal (
        gewinn_verlust,
        jahr_copy,
        kfz_hinweise
        );
    if (!result) {
        free(jahr_copy);
    }
    return result;
}

void anlage_s_ergebnis_free(anlage_s_ergebnis_t *anlage_s_ergebnis) {
    if(NULL == anlage_s_ergebnis){
        return ;
    }
    if(anlage_s_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "anlage_s_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (anlage_s_ergebnis->gewinn_verlust) {
        free(anlage_s_ergebnis->gewinn_verlust);
        anlage_s_ergebnis->gewinn_verlust = NULL;
    }
    if (anlage_s_ergebnis->jahr) {
        free(anlage_s_ergebnis->jahr);
        anlage_s_ergebnis->jahr = NULL;
    }
    if (anlage_s_ergebnis->kfz_hinweise) {
        list_ForEach(listEntry, anlage_s_ergebnis->kfz_hinweise) {
            anlage_s_kfz_hinweis_free(listEntry->data);
        }
        list_freeList(anlage_s_ergebnis->kfz_hinweise);
        anlage_s_ergebnis->kfz_hinweise = NULL;
    }
    free(anlage_s_ergebnis);
}

cJSON *anlage_s_ergebnis_convertToJSON(anlage_s_ergebnis_t *anlage_s_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // anlage_s_ergebnis->gewinn_verlust
    if (!anlage_s_ergebnis->gewinn_verlust) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinn_verlust", anlage_s_ergebnis->gewinn_verlust) == NULL) {
    goto fail; //String
    }


    // anlage_s_ergebnis->jahr
    if (!anlage_s_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *anlage_s_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // anlage_s_ergebnis->kfz_hinweise
    if (!anlage_s_ergebnis->kfz_hinweise) {
        goto fail;
    }
    cJSON *kfz_hinweise = cJSON_AddArrayToObject(item, "kfz_hinweise");
    if(kfz_hinweise == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *kfz_hinweiseListEntry;
    if (anlage_s_ergebnis->kfz_hinweise) {
    list_ForEach(kfz_hinweiseListEntry, anlage_s_ergebnis->kfz_hinweise) {
    cJSON *itemLocal = anlage_s_kfz_hinweis_convertToJSON(kfz_hinweiseListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(kfz_hinweise, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

anlage_s_ergebnis_t *anlage_s_ergebnis_parseFromJSON(cJSON *anlage_s_ergebnisJSON){

    anlage_s_ergebnis_t *anlage_s_ergebnis_local_var = NULL;

    char *gewinn_verlust_local_str = NULL;

    // define the local variable for anlage_s_ergebnis->jahr
    int *jahr_local_var = NULL;

    // define the local list for anlage_s_ergebnis->kfz_hinweise
    list_t *kfz_hinweiseList = NULL;

    // anlage_s_ergebnis->gewinn_verlust
    cJSON *gewinn_verlust = cJSON_GetObjectItemCaseSensitive(anlage_s_ergebnisJSON, "gewinn_verlust");
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

    // anlage_s_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(anlage_s_ergebnisJSON, "jahr");
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

    // anlage_s_ergebnis->kfz_hinweise
    cJSON *kfz_hinweise = cJSON_GetObjectItemCaseSensitive(anlage_s_ergebnisJSON, "kfz_hinweise");
    if (cJSON_IsNull(kfz_hinweise)) {
        kfz_hinweise = NULL;
    }
    if (!kfz_hinweise) {
        goto end;
    }

    
    cJSON *kfz_hinweise_local_nonprimitive = NULL;
    if(!cJSON_IsArray(kfz_hinweise)){
        goto end; //nonprimitive container
    }

    kfz_hinweiseList = list_createList();

    cJSON_ArrayForEach(kfz_hinweise_local_nonprimitive,kfz_hinweise )
    {
        if(!cJSON_IsObject(kfz_hinweise_local_nonprimitive)){
            goto end;
        }
        anlage_s_kfz_hinweis_t *kfz_hinweiseItem = anlage_s_kfz_hinweis_parseFromJSON(kfz_hinweise_local_nonprimitive);

        list_addElement(kfz_hinweiseList, kfz_hinweiseItem);
    }


    if (gewinn_verlust && !cJSON_IsNull(gewinn_verlust)) gewinn_verlust_local_str = strdup(gewinn_verlust->valuestring);

    anlage_s_ergebnis_local_var = anlage_s_ergebnis_create_internal (
        gewinn_verlust_local_str,
        jahr_local_var,
        kfz_hinweiseList
        );

    if (!anlage_s_ergebnis_local_var) {
        goto end;
    }

    return anlage_s_ergebnis_local_var;
end:
    if (gewinn_verlust_local_str) {
        free(gewinn_verlust_local_str);
        gewinn_verlust_local_str = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (kfz_hinweiseList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, kfz_hinweiseList) {
            anlage_s_kfz_hinweis_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(kfz_hinweiseList);
        kfz_hinweiseList = NULL;
    }
    return NULL;

}
