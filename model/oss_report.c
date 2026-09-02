#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "oss_report.h"



static oss_report_t *oss_report_create_internal(
    list_t *dependencies,
    int *total_count
    ) {
    oss_report_t *oss_report_local_var = malloc(sizeof(oss_report_t));
    if (!oss_report_local_var) {
        return NULL;
    }
    memset(oss_report_local_var, 0, sizeof(oss_report_t));
    oss_report_local_var->_library_owned = 1;
    oss_report_local_var->dependencies = dependencies;
    oss_report_local_var->total_count = total_count;
    return oss_report_local_var;
}

__attribute__((deprecated)) oss_report_t *oss_report_create(
    list_t *dependencies,
    int *total_count
    ) {
    int *total_count_copy = NULL;
    if (total_count) {
        total_count_copy = malloc(sizeof(int));
        if (total_count_copy) *total_count_copy = *total_count;
    }
    oss_report_t *result = oss_report_create_internal (
        dependencies,
        total_count_copy
        );
    if (!result) {
        free(total_count_copy);
    }
    return result;
}

void oss_report_free(oss_report_t *oss_report) {
    if(NULL == oss_report){
        return ;
    }
    if(oss_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "oss_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (oss_report->dependencies) {
        list_ForEach(listEntry, oss_report->dependencies) {
            oss_dependency_free(listEntry->data);
        }
        list_freeList(oss_report->dependencies);
        oss_report->dependencies = NULL;
    }
    if (oss_report->total_count) {
        free(oss_report->total_count);
        oss_report->total_count = NULL;
    }
    free(oss_report);
}

cJSON *oss_report_convertToJSON(oss_report_t *oss_report) {
    cJSON *item = cJSON_CreateObject();

    // oss_report->dependencies
    if (!oss_report->dependencies) {
        goto fail;
    }
    cJSON *dependencies = cJSON_AddArrayToObject(item, "dependencies");
    if(dependencies == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dependenciesListEntry;
    if (oss_report->dependencies) {
    list_ForEach(dependenciesListEntry, oss_report->dependencies) {
    cJSON *itemLocal = oss_dependency_convertToJSON(dependenciesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(dependencies, itemLocal);
    }
    }


    // oss_report->total_count
    if (!oss_report->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", *oss_report->total_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

oss_report_t *oss_report_parseFromJSON(cJSON *oss_reportJSON){

    oss_report_t *oss_report_local_var = NULL;

    // define the local list for oss_report->dependencies
    list_t *dependenciesList = NULL;

    // define the local variable for oss_report->total_count
    int *total_count_local_var = NULL;

    // oss_report->dependencies
    cJSON *dependencies = cJSON_GetObjectItemCaseSensitive(oss_reportJSON, "dependencies");
    if (cJSON_IsNull(dependencies)) {
        dependencies = NULL;
    }
    if (!dependencies) {
        goto end;
    }

    
    cJSON *dependencies_local_nonprimitive = NULL;
    if(!cJSON_IsArray(dependencies)){
        goto end; //nonprimitive container
    }

    dependenciesList = list_createList();

    cJSON_ArrayForEach(dependencies_local_nonprimitive,dependencies )
    {
        if(!cJSON_IsObject(dependencies_local_nonprimitive)){
            goto end;
        }
        oss_dependency_t *dependenciesItem = oss_dependency_parseFromJSON(dependencies_local_nonprimitive);

        list_addElement(dependenciesList, dependenciesItem);
    }

    // oss_report->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(oss_reportJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (!total_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }
    total_count_local_var = malloc(sizeof(int));
    if(!total_count_local_var)
    {
        goto end;
    }
    *total_count_local_var = total_count->valuedouble;



    oss_report_local_var = oss_report_create_internal (
        dependenciesList,
        total_count_local_var
        );

    if (!oss_report_local_var) {
        goto end;
    }

    return oss_report_local_var;
end:
    if (dependenciesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dependenciesList) {
            oss_dependency_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dependenciesList);
        dependenciesList = NULL;
    }
    if (total_count_local_var) {
        free(total_count_local_var);
        total_count_local_var = NULL;
    }
    return NULL;

}
