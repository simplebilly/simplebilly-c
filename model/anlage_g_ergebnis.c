#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "anlage_g_ergebnis.h"



static anlage_g_ergebnis_t *anlage_g_ergebnis_create_internal(
    char *gewinn_verlust,
    char *gewst_gezahlt,
    char *gewst_messbetrag_approx,
    int *gewst_pflichtig,
    int *jahr,
    list_t *kfz_hinweise
    ) {
    anlage_g_ergebnis_t *anlage_g_ergebnis_local_var = malloc(sizeof(anlage_g_ergebnis_t));
    if (!anlage_g_ergebnis_local_var) {
        return NULL;
    }
    memset(anlage_g_ergebnis_local_var, 0, sizeof(anlage_g_ergebnis_t));
    anlage_g_ergebnis_local_var->_library_owned = 1;
    anlage_g_ergebnis_local_var->gewinn_verlust = gewinn_verlust;
    anlage_g_ergebnis_local_var->gewst_gezahlt = gewst_gezahlt;
    anlage_g_ergebnis_local_var->gewst_messbetrag_approx = gewst_messbetrag_approx;
    anlage_g_ergebnis_local_var->gewst_pflichtig = gewst_pflichtig;
    anlage_g_ergebnis_local_var->jahr = jahr;
    anlage_g_ergebnis_local_var->kfz_hinweise = kfz_hinweise;
    return anlage_g_ergebnis_local_var;
}

__attribute__((deprecated)) anlage_g_ergebnis_t *anlage_g_ergebnis_create(
    char *gewinn_verlust,
    char *gewst_gezahlt,
    char *gewst_messbetrag_approx,
    int *gewst_pflichtig,
    int *jahr,
    list_t *kfz_hinweise
    ) {
    int *gewst_pflichtig_copy = NULL;
    if (gewst_pflichtig) {
        gewst_pflichtig_copy = malloc(sizeof(int));
        if (gewst_pflichtig_copy) *gewst_pflichtig_copy = *gewst_pflichtig;
    }
    int *jahr_copy = NULL;
    if (jahr) {
        jahr_copy = malloc(sizeof(int));
        if (jahr_copy) *jahr_copy = *jahr;
    }
    anlage_g_ergebnis_t *result = anlage_g_ergebnis_create_internal (
        gewinn_verlust,
        gewst_gezahlt,
        gewst_messbetrag_approx,
        gewst_pflichtig_copy,
        jahr_copy,
        kfz_hinweise
        );
    if (!result) {
        free(gewst_pflichtig_copy);
        free(jahr_copy);
    }
    return result;
}

void anlage_g_ergebnis_free(anlage_g_ergebnis_t *anlage_g_ergebnis) {
    if(NULL == anlage_g_ergebnis){
        return ;
    }
    if(anlage_g_ergebnis->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "anlage_g_ergebnis_free");
        return ;
    }
    listEntry_t *listEntry;
    if (anlage_g_ergebnis->gewinn_verlust) {
        free(anlage_g_ergebnis->gewinn_verlust);
        anlage_g_ergebnis->gewinn_verlust = NULL;
    }
    if (anlage_g_ergebnis->gewst_gezahlt) {
        free(anlage_g_ergebnis->gewst_gezahlt);
        anlage_g_ergebnis->gewst_gezahlt = NULL;
    }
    if (anlage_g_ergebnis->gewst_messbetrag_approx) {
        free(anlage_g_ergebnis->gewst_messbetrag_approx);
        anlage_g_ergebnis->gewst_messbetrag_approx = NULL;
    }
    if (anlage_g_ergebnis->gewst_pflichtig) {
        free(anlage_g_ergebnis->gewst_pflichtig);
        anlage_g_ergebnis->gewst_pflichtig = NULL;
    }
    if (anlage_g_ergebnis->jahr) {
        free(anlage_g_ergebnis->jahr);
        anlage_g_ergebnis->jahr = NULL;
    }
    if (anlage_g_ergebnis->kfz_hinweise) {
        list_ForEach(listEntry, anlage_g_ergebnis->kfz_hinweise) {
            anlage_g_kfz_hinweis_free(listEntry->data);
        }
        list_freeList(anlage_g_ergebnis->kfz_hinweise);
        anlage_g_ergebnis->kfz_hinweise = NULL;
    }
    free(anlage_g_ergebnis);
}

cJSON *anlage_g_ergebnis_convertToJSON(anlage_g_ergebnis_t *anlage_g_ergebnis) {
    cJSON *item = cJSON_CreateObject();

    // anlage_g_ergebnis->gewinn_verlust
    if (!anlage_g_ergebnis->gewinn_verlust) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewinn_verlust", anlage_g_ergebnis->gewinn_verlust) == NULL) {
    goto fail; //String
    }


    // anlage_g_ergebnis->gewst_gezahlt
    if (!anlage_g_ergebnis->gewst_gezahlt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewst_gezahlt", anlage_g_ergebnis->gewst_gezahlt) == NULL) {
    goto fail; //String
    }


    // anlage_g_ergebnis->gewst_messbetrag_approx
    if (!anlage_g_ergebnis->gewst_messbetrag_approx) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gewst_messbetrag_approx", anlage_g_ergebnis->gewst_messbetrag_approx) == NULL) {
    goto fail; //String
    }


    // anlage_g_ergebnis->gewst_pflichtig
    if (!anlage_g_ergebnis->gewst_pflichtig) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "gewst_pflichtig", *anlage_g_ergebnis->gewst_pflichtig) == NULL) {
    goto fail; //Bool
    }


    // anlage_g_ergebnis->jahr
    if (!anlage_g_ergebnis->jahr) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "jahr", *anlage_g_ergebnis->jahr) == NULL) {
    goto fail; //Numeric
    }


    // anlage_g_ergebnis->kfz_hinweise
    if (!anlage_g_ergebnis->kfz_hinweise) {
        goto fail;
    }
    cJSON *kfz_hinweise = cJSON_AddArrayToObject(item, "kfz_hinweise");
    if(kfz_hinweise == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *kfz_hinweiseListEntry;
    if (anlage_g_ergebnis->kfz_hinweise) {
    list_ForEach(kfz_hinweiseListEntry, anlage_g_ergebnis->kfz_hinweise) {
    cJSON *itemLocal = anlage_g_kfz_hinweis_convertToJSON(kfz_hinweiseListEntry->data);
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

anlage_g_ergebnis_t *anlage_g_ergebnis_parseFromJSON(cJSON *anlage_g_ergebnisJSON){

    anlage_g_ergebnis_t *anlage_g_ergebnis_local_var = NULL;

    char *gewinn_verlust_local_str = NULL;

    char *gewst_gezahlt_local_str = NULL;

    char *gewst_messbetrag_approx_local_str = NULL;

    // define the local variable for anlage_g_ergebnis->gewst_pflichtig
    int *gewst_pflichtig_local_var = NULL;

    // define the local variable for anlage_g_ergebnis->jahr
    int *jahr_local_var = NULL;

    // define the local list for anlage_g_ergebnis->kfz_hinweise
    list_t *kfz_hinweiseList = NULL;

    // anlage_g_ergebnis->gewinn_verlust
    cJSON *gewinn_verlust = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "gewinn_verlust");
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

    // anlage_g_ergebnis->gewst_gezahlt
    cJSON *gewst_gezahlt = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "gewst_gezahlt");
    if (cJSON_IsNull(gewst_gezahlt)) {
        gewst_gezahlt = NULL;
    }
    if (!gewst_gezahlt) {
        goto end;
    }

    
    if(!cJSON_IsString(gewst_gezahlt))
    {
    goto end; //String
    }

    // anlage_g_ergebnis->gewst_messbetrag_approx
    cJSON *gewst_messbetrag_approx = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "gewst_messbetrag_approx");
    if (cJSON_IsNull(gewst_messbetrag_approx)) {
        gewst_messbetrag_approx = NULL;
    }
    if (!gewst_messbetrag_approx) {
        goto end;
    }

    
    if(!cJSON_IsString(gewst_messbetrag_approx))
    {
    goto end; //String
    }

    // anlage_g_ergebnis->gewst_pflichtig
    cJSON *gewst_pflichtig = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "gewst_pflichtig");
    if (cJSON_IsNull(gewst_pflichtig)) {
        gewst_pflichtig = NULL;
    }
    if (!gewst_pflichtig) {
        goto end;
    }

    
    if(!cJSON_IsBool(gewst_pflichtig))
    {
    goto end; //Bool
    }
    gewst_pflichtig_local_var = malloc(sizeof(int));
    if(!gewst_pflichtig_local_var)
    {
        goto end;
    }
    *gewst_pflichtig_local_var = gewst_pflichtig->valueint;

    // anlage_g_ergebnis->jahr
    cJSON *jahr = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "jahr");
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

    // anlage_g_ergebnis->kfz_hinweise
    cJSON *kfz_hinweise = cJSON_GetObjectItemCaseSensitive(anlage_g_ergebnisJSON, "kfz_hinweise");
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
        anlage_g_kfz_hinweis_t *kfz_hinweiseItem = anlage_g_kfz_hinweis_parseFromJSON(kfz_hinweise_local_nonprimitive);

        list_addElement(kfz_hinweiseList, kfz_hinweiseItem);
    }


    if (gewinn_verlust && !cJSON_IsNull(gewinn_verlust)) gewinn_verlust_local_str = strdup(gewinn_verlust->valuestring);
    if (gewst_gezahlt && !cJSON_IsNull(gewst_gezahlt)) gewst_gezahlt_local_str = strdup(gewst_gezahlt->valuestring);
    if (gewst_messbetrag_approx && !cJSON_IsNull(gewst_messbetrag_approx)) gewst_messbetrag_approx_local_str = strdup(gewst_messbetrag_approx->valuestring);

    anlage_g_ergebnis_local_var = anlage_g_ergebnis_create_internal (
        gewinn_verlust_local_str,
        gewst_gezahlt_local_str,
        gewst_messbetrag_approx_local_str,
        gewst_pflichtig_local_var,
        jahr_local_var,
        kfz_hinweiseList
        );

    if (!anlage_g_ergebnis_local_var) {
        goto end;
    }

    return anlage_g_ergebnis_local_var;
end:
    if (gewinn_verlust_local_str) {
        free(gewinn_verlust_local_str);
        gewinn_verlust_local_str = NULL;
    }
    if (gewst_gezahlt_local_str) {
        free(gewst_gezahlt_local_str);
        gewst_gezahlt_local_str = NULL;
    }
    if (gewst_messbetrag_approx_local_str) {
        free(gewst_messbetrag_approx_local_str);
        gewst_messbetrag_approx_local_str = NULL;
    }
    if (gewst_pflichtig_local_var) {
        free(gewst_pflichtig_local_var);
        gewst_pflichtig_local_var = NULL;
    }
    if (jahr_local_var) {
        free(jahr_local_var);
        jahr_local_var = NULL;
    }
    if (kfz_hinweiseList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, kfz_hinweiseList) {
            anlage_g_kfz_hinweis_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(kfz_hinweiseList);
        kfz_hinweiseList = NULL;
    }
    return NULL;

}
