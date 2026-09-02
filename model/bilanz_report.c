#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bilanz_report.h"



static bilanz_report_t *bilanz_report_create_internal(
    list_t *aktiva,
    int *balanced,
    char *generated_at,
    list_t *passiva,
    char *period,
    char *total_aktiva,
    char *total_passiva
    ) {
    bilanz_report_t *bilanz_report_local_var = malloc(sizeof(bilanz_report_t));
    if (!bilanz_report_local_var) {
        return NULL;
    }
    memset(bilanz_report_local_var, 0, sizeof(bilanz_report_t));
    bilanz_report_local_var->_library_owned = 1;
    bilanz_report_local_var->aktiva = aktiva;
    bilanz_report_local_var->balanced = balanced;
    bilanz_report_local_var->generated_at = generated_at;
    bilanz_report_local_var->passiva = passiva;
    bilanz_report_local_var->period = period;
    bilanz_report_local_var->total_aktiva = total_aktiva;
    bilanz_report_local_var->total_passiva = total_passiva;
    return bilanz_report_local_var;
}

__attribute__((deprecated)) bilanz_report_t *bilanz_report_create(
    list_t *aktiva,
    int *balanced,
    char *generated_at,
    list_t *passiva,
    char *period,
    char *total_aktiva,
    char *total_passiva
    ) {
    int *balanced_copy = NULL;
    if (balanced) {
        balanced_copy = malloc(sizeof(int));
        if (balanced_copy) *balanced_copy = *balanced;
    }
    bilanz_report_t *result = bilanz_report_create_internal (
        aktiva,
        balanced_copy,
        generated_at,
        passiva,
        period,
        total_aktiva,
        total_passiva
        );
    if (!result) {
        free(balanced_copy);
    }
    return result;
}

void bilanz_report_free(bilanz_report_t *bilanz_report) {
    if(NULL == bilanz_report){
        return ;
    }
    if(bilanz_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bilanz_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bilanz_report->aktiva) {
        list_ForEach(listEntry, bilanz_report->aktiva) {
            bilanz_item_free(listEntry->data);
        }
        list_freeList(bilanz_report->aktiva);
        bilanz_report->aktiva = NULL;
    }
    if (bilanz_report->balanced) {
        free(bilanz_report->balanced);
        bilanz_report->balanced = NULL;
    }
    if (bilanz_report->generated_at) {
        free(bilanz_report->generated_at);
        bilanz_report->generated_at = NULL;
    }
    if (bilanz_report->passiva) {
        list_ForEach(listEntry, bilanz_report->passiva) {
            bilanz_item_free(listEntry->data);
        }
        list_freeList(bilanz_report->passiva);
        bilanz_report->passiva = NULL;
    }
    if (bilanz_report->period) {
        free(bilanz_report->period);
        bilanz_report->period = NULL;
    }
    if (bilanz_report->total_aktiva) {
        free(bilanz_report->total_aktiva);
        bilanz_report->total_aktiva = NULL;
    }
    if (bilanz_report->total_passiva) {
        free(bilanz_report->total_passiva);
        bilanz_report->total_passiva = NULL;
    }
    free(bilanz_report);
}

cJSON *bilanz_report_convertToJSON(bilanz_report_t *bilanz_report) {
    cJSON *item = cJSON_CreateObject();

    // bilanz_report->aktiva
    if (!bilanz_report->aktiva) {
        goto fail;
    }
    cJSON *aktiva = cJSON_AddArrayToObject(item, "aktiva");
    if(aktiva == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *aktivaListEntry;
    if (bilanz_report->aktiva) {
    list_ForEach(aktivaListEntry, bilanz_report->aktiva) {
    cJSON *itemLocal = bilanz_item_convertToJSON(aktivaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(aktiva, itemLocal);
    }
    }


    // bilanz_report->balanced
    if (!bilanz_report->balanced) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "balanced", *bilanz_report->balanced) == NULL) {
    goto fail; //Bool
    }


    // bilanz_report->generated_at
    if (!bilanz_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", bilanz_report->generated_at) == NULL) {
    goto fail; //String
    }


    // bilanz_report->passiva
    if (!bilanz_report->passiva) {
        goto fail;
    }
    cJSON *passiva = cJSON_AddArrayToObject(item, "passiva");
    if(passiva == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *passivaListEntry;
    if (bilanz_report->passiva) {
    list_ForEach(passivaListEntry, bilanz_report->passiva) {
    cJSON *itemLocal = bilanz_item_convertToJSON(passivaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(passiva, itemLocal);
    }
    }


    // bilanz_report->period
    if (!bilanz_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", bilanz_report->period) == NULL) {
    goto fail; //String
    }


    // bilanz_report->total_aktiva
    if (!bilanz_report->total_aktiva) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_aktiva", bilanz_report->total_aktiva) == NULL) {
    goto fail; //String
    }


    // bilanz_report->total_passiva
    if (!bilanz_report->total_passiva) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_passiva", bilanz_report->total_passiva) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bilanz_report_t *bilanz_report_parseFromJSON(cJSON *bilanz_reportJSON){

    bilanz_report_t *bilanz_report_local_var = NULL;

    // define the local list for bilanz_report->aktiva
    list_t *aktivaList = NULL;

    // define the local variable for bilanz_report->balanced
    int *balanced_local_var = NULL;

    char *generated_at_local_str = NULL;

    // define the local list for bilanz_report->passiva
    list_t *passivaList = NULL;

    char *period_local_str = NULL;

    char *total_aktiva_local_str = NULL;

    char *total_passiva_local_str = NULL;

    // bilanz_report->aktiva
    cJSON *aktiva = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "aktiva");
    if (cJSON_IsNull(aktiva)) {
        aktiva = NULL;
    }
    if (!aktiva) {
        goto end;
    }

    
    cJSON *aktiva_local_nonprimitive = NULL;
    if(!cJSON_IsArray(aktiva)){
        goto end; //nonprimitive container
    }

    aktivaList = list_createList();

    cJSON_ArrayForEach(aktiva_local_nonprimitive,aktiva )
    {
        if(!cJSON_IsObject(aktiva_local_nonprimitive)){
            goto end;
        }
        bilanz_item_t *aktivaItem = bilanz_item_parseFromJSON(aktiva_local_nonprimitive);

        list_addElement(aktivaList, aktivaItem);
    }

    // bilanz_report->balanced
    cJSON *balanced = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "balanced");
    if (cJSON_IsNull(balanced)) {
        balanced = NULL;
    }
    if (!balanced) {
        goto end;
    }

    
    if(!cJSON_IsBool(balanced))
    {
    goto end; //Bool
    }
    balanced_local_var = malloc(sizeof(int));
    if(!balanced_local_var)
    {
        goto end;
    }
    *balanced_local_var = balanced->valueint;

    // bilanz_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "generated_at");
    if (cJSON_IsNull(generated_at)) {
        generated_at = NULL;
    }
    if (!generated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(generated_at))
    {
    goto end; //String
    }

    // bilanz_report->passiva
    cJSON *passiva = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "passiva");
    if (cJSON_IsNull(passiva)) {
        passiva = NULL;
    }
    if (!passiva) {
        goto end;
    }

    
    cJSON *passiva_local_nonprimitive = NULL;
    if(!cJSON_IsArray(passiva)){
        goto end; //nonprimitive container
    }

    passivaList = list_createList();

    cJSON_ArrayForEach(passiva_local_nonprimitive,passiva )
    {
        if(!cJSON_IsObject(passiva_local_nonprimitive)){
            goto end;
        }
        bilanz_item_t *passivaItem = bilanz_item_parseFromJSON(passiva_local_nonprimitive);

        list_addElement(passivaList, passivaItem);
    }

    // bilanz_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (!period) {
        goto end;
    }

    
    if(!cJSON_IsString(period))
    {
    goto end; //String
    }

    // bilanz_report->total_aktiva
    cJSON *total_aktiva = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "total_aktiva");
    if (cJSON_IsNull(total_aktiva)) {
        total_aktiva = NULL;
    }
    if (!total_aktiva) {
        goto end;
    }

    
    if(!cJSON_IsString(total_aktiva))
    {
    goto end; //String
    }

    // bilanz_report->total_passiva
    cJSON *total_passiva = cJSON_GetObjectItemCaseSensitive(bilanz_reportJSON, "total_passiva");
    if (cJSON_IsNull(total_passiva)) {
        total_passiva = NULL;
    }
    if (!total_passiva) {
        goto end;
    }

    
    if(!cJSON_IsString(total_passiva))
    {
    goto end; //String
    }


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);
    if (total_aktiva && !cJSON_IsNull(total_aktiva)) total_aktiva_local_str = strdup(total_aktiva->valuestring);
    if (total_passiva && !cJSON_IsNull(total_passiva)) total_passiva_local_str = strdup(total_passiva->valuestring);

    bilanz_report_local_var = bilanz_report_create_internal (
        aktivaList,
        balanced_local_var,
        generated_at_local_str,
        passivaList,
        period_local_str,
        total_aktiva_local_str,
        total_passiva_local_str
        );

    if (!bilanz_report_local_var) {
        goto end;
    }

    return bilanz_report_local_var;
end:
    if (aktivaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, aktivaList) {
            bilanz_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(aktivaList);
        aktivaList = NULL;
    }
    if (balanced_local_var) {
        free(balanced_local_var);
        balanced_local_var = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (passivaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, passivaList) {
            bilanz_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(passivaList);
        passivaList = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (total_aktiva_local_str) {
        free(total_aktiva_local_str);
        total_aktiva_local_str = NULL;
    }
    if (total_passiva_local_str) {
        free(total_passiva_local_str);
        total_passiva_local_str = NULL;
    }
    return NULL;

}
