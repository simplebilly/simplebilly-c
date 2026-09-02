#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plausibility_report.h"



static plausibility_report_t *plausibility_report_create_internal(
    list_t *checks,
    char *generated_at,
    plausibility_summary_t *summary
    ) {
    plausibility_report_t *plausibility_report_local_var = malloc(sizeof(plausibility_report_t));
    if (!plausibility_report_local_var) {
        return NULL;
    }
    memset(plausibility_report_local_var, 0, sizeof(plausibility_report_t));
    plausibility_report_local_var->_library_owned = 1;
    plausibility_report_local_var->checks = checks;
    plausibility_report_local_var->generated_at = generated_at;
    plausibility_report_local_var->summary = summary;
    return plausibility_report_local_var;
}

__attribute__((deprecated)) plausibility_report_t *plausibility_report_create(
    list_t *checks,
    char *generated_at,
    plausibility_summary_t *summary
    ) {
    plausibility_report_t *result = plausibility_report_create_internal (
        checks,
        generated_at,
        summary
        );
    if (!result) {
    }
    return result;
}

void plausibility_report_free(plausibility_report_t *plausibility_report) {
    if(NULL == plausibility_report){
        return ;
    }
    if(plausibility_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plausibility_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plausibility_report->checks) {
        list_ForEach(listEntry, plausibility_report->checks) {
            plausibility_check_free(listEntry->data);
        }
        list_freeList(plausibility_report->checks);
        plausibility_report->checks = NULL;
    }
    if (plausibility_report->generated_at) {
        free(plausibility_report->generated_at);
        plausibility_report->generated_at = NULL;
    }
    if (plausibility_report->summary) {
        plausibility_summary_free(plausibility_report->summary);
        plausibility_report->summary = NULL;
    }
    free(plausibility_report);
}

cJSON *plausibility_report_convertToJSON(plausibility_report_t *plausibility_report) {
    cJSON *item = cJSON_CreateObject();

    // plausibility_report->checks
    if (!plausibility_report->checks) {
        goto fail;
    }
    cJSON *checks = cJSON_AddArrayToObject(item, "checks");
    if(checks == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *checksListEntry;
    if (plausibility_report->checks) {
    list_ForEach(checksListEntry, plausibility_report->checks) {
    cJSON *itemLocal = plausibility_check_convertToJSON(checksListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(checks, itemLocal);
    }
    }


    // plausibility_report->generated_at
    if (!plausibility_report->generated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "generated_at", plausibility_report->generated_at) == NULL) {
    goto fail; //String
    }


    // plausibility_report->summary
    if (!plausibility_report->summary) {
        goto fail;
    }
    cJSON *summary_local_JSON = plausibility_summary_convertToJSON(plausibility_report->summary);
    if(summary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "summary", summary_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plausibility_report_t *plausibility_report_parseFromJSON(cJSON *plausibility_reportJSON){

    plausibility_report_t *plausibility_report_local_var = NULL;

    // define the local list for plausibility_report->checks
    list_t *checksList = NULL;

    char *generated_at_local_str = NULL;

    // define the local variable for plausibility_report->summary
    plausibility_summary_t *summary_local_nonprim = NULL;

    // plausibility_report->checks
    cJSON *checks = cJSON_GetObjectItemCaseSensitive(plausibility_reportJSON, "checks");
    if (cJSON_IsNull(checks)) {
        checks = NULL;
    }
    if (!checks) {
        goto end;
    }

    
    cJSON *checks_local_nonprimitive = NULL;
    if(!cJSON_IsArray(checks)){
        goto end; //nonprimitive container
    }

    checksList = list_createList();

    cJSON_ArrayForEach(checks_local_nonprimitive,checks )
    {
        if(!cJSON_IsObject(checks_local_nonprimitive)){
            goto end;
        }
        plausibility_check_t *checksItem = plausibility_check_parseFromJSON(checks_local_nonprimitive);

        list_addElement(checksList, checksItem);
    }

    // plausibility_report->generated_at
    cJSON *generated_at = cJSON_GetObjectItemCaseSensitive(plausibility_reportJSON, "generated_at");
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

    // plausibility_report->summary
    cJSON *summary = cJSON_GetObjectItemCaseSensitive(plausibility_reportJSON, "summary");
    if (cJSON_IsNull(summary)) {
        summary = NULL;
    }
    if (!summary) {
        goto end;
    }

    
    summary_local_nonprim = plausibility_summary_parseFromJSON(summary); //nonprimitive


    if (generated_at && !cJSON_IsNull(generated_at)) generated_at_local_str = strdup(generated_at->valuestring);

    plausibility_report_local_var = plausibility_report_create_internal (
        checksList,
        generated_at_local_str,
        summary_local_nonprim
        );

    if (!plausibility_report_local_var) {
        goto end;
    }

    return plausibility_report_local_var;
end:
    if (checksList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, checksList) {
            plausibility_check_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(checksList);
        checksList = NULL;
    }
    if (generated_at_local_str) {
        free(generated_at_local_str);
        generated_at_local_str = NULL;
    }
    if (summary_local_nonprim) {
        plausibility_summary_free(summary_local_nonprim);
        summary_local_nonprim = NULL;
    }
    return NULL;

}
