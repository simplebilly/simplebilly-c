#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "konto_report.h"



static konto_report_t *konto_report_create_internal(
    char *generated_at,
    list_t *konten,
    char *period
    ) {
    konto_report_t *konto_report_local_var = malloc(sizeof(konto_report_t));
    if (!konto_report_local_var) {
        return NULL;
    }
    memset(konto_report_local_var, 0, sizeof(konto_report_t));
    konto_report_local_var->_library_owned = 1;
    konto_report_local_var->generated_at = generated_at;
    konto_report_local_var->konten = konten;
    konto_report_local_var->period = period;
    return konto_report_local_var;
}

__attribute__((deprecated)) konto_report_t *konto_report_create(
    char *generated_at,
    list_t *konten,
    char *period
    ) {
    konto_report_t *result = konto_report_create_internal (
        generated_at,
        konten,
        period
        );
    if (!result) {
    }
    return result;
}

void konto_report_free(konto_report_t *konto_report) {
    if(NULL == konto_report){
        return ;
    }
    if(konto_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "konto_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (konto_report->generated_at) {
        free(konto_report->generated_at);
        konto_report->generated_at = NULL;
    }
    if (konto_report->konten) {
        list_ForEach(listEntry, konto_report->konten) {
            konto_item_free(listEntry->data);
        }
        list_freeList(konto_report->konten);
        konto_report->konten = NULL;
    }
    if (konto_report->period) {
        free(konto_report->period);
        konto_report->period = NULL;
    }
    free(konto_report);
}

cJSON *konto_report_convertToJSON(konto_report_t *konto_report) {
    cJSON *item = cJSON_CreateObject();

    // konto_report->generated_at
    if (!konto_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", konto_report->generated_at) == NULL) {
    goto fail; //String
    }


    // konto_report->konten
    if (!konto_report->konten) {
        goto fail;
    }
    cJSON *konten = cJSON_AddArrayToObject(item, "konten");
    if(konten == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *kontenListEntry;
    if (konto_report->konten) {
    list_ForEach(kontenListEntry, konto_report->konten) {
    cJSON *itemLocal = konto_item_convertToJSON(kontenListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(konten, itemLocal);
    }
    }


    // konto_report->period
    if (!konto_report->period) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "period", konto_report->period) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

konto_report_t *konto_report_parseFromJSON(cJSON *konto_reportJSON){

    konto_report_t *konto_report_local_var = NULL;

    char *generated_at_local_str = NULL;

    // define the local list for konto_report->konten
    list_t *kontenList = NULL;

    char *period_local_str = NULL;

    // konto_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(konto_reportJSON, "generated_at");
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

    // konto_report->konten
    cJSON *konten = cJSON_GetObjectItemCaseSensitive(konto_reportJSON, "konten");
    if (cJSON_IsNull(konten)) {
        konten = NULL;
    }
    if (!konten) {
        goto end;
    }

    
    cJSON *konten_local_nonprimitive = NULL;
    if(!cJSON_IsArray(konten)){
        goto end; //nonprimitive container
    }

    kontenList = list_createList();

    cJSON_ArrayForEach(konten_local_nonprimitive,konten )
    {
        if(!cJSON_IsObject(konten_local_nonprimitive)){
            goto end;
        }
        konto_item_t *kontenItem = konto_item_parseFromJSON(konten_local_nonprimitive);

        list_addElement(kontenList, kontenItem);
    }

    // konto_report->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(konto_reportJSON, "period");
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


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);
    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);

    konto_report_local_var = konto_report_create_internal (
        generated_at_local_str,
        kontenList,
        period_local_str
        );

    if (!konto_report_local_var) {
        goto end;
    }

    return konto_report_local_var;
end:
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (kontenList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, kontenList) {
            konto_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(kontenList);
        kontenList = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    return NULL;

}
