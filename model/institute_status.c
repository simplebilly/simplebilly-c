#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "institute_status.h"



static institute_status_t *institute_status_create_internal(
    list_t *checklist,
    institute_deadlines_t *deadlines,
    char *institute_type,
    int *kapitalmarktorientiert
    ) {
    institute_status_t *institute_status_local_var = malloc(sizeof(institute_status_t));
    if (!institute_status_local_var) {
        return NULL;
    }
    memset(institute_status_local_var, 0, sizeof(institute_status_t));
    institute_status_local_var->_library_owned = 1;
    institute_status_local_var->checklist = checklist;
    institute_status_local_var->deadlines = deadlines;
    institute_status_local_var->institute_type = institute_type;
    institute_status_local_var->kapitalmarktorientiert = kapitalmarktorientiert;
    return institute_status_local_var;
}

__attribute__((deprecated)) institute_status_t *institute_status_create(
    list_t *checklist,
    institute_deadlines_t *deadlines,
    char *institute_type,
    int *kapitalmarktorientiert
    ) {
    int *kapitalmarktorientiert_copy = NULL;
    if (kapitalmarktorientiert) {
        kapitalmarktorientiert_copy = malloc(sizeof(int));
        if (kapitalmarktorientiert_copy) *kapitalmarktorientiert_copy = *kapitalmarktorientiert;
    }
    institute_status_t *result = institute_status_create_internal (
        checklist,
        deadlines,
        institute_type,
        kapitalmarktorientiert_copy
        );
    if (!result) {
        free(kapitalmarktorientiert_copy);
    }
    return result;
}

void institute_status_free(institute_status_t *institute_status) {
    if(NULL == institute_status){
        return ;
    }
    if(institute_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "institute_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (institute_status->checklist) {
        list_ForEach(listEntry, institute_status->checklist) {
            institute_check_item_free(listEntry->data);
        }
        list_freeList(institute_status->checklist);
        institute_status->checklist = NULL;
    }
    if (institute_status->deadlines) {
        institute_deadlines_free(institute_status->deadlines);
        institute_status->deadlines = NULL;
    }
    if (institute_status->institute_type) {
        free(institute_status->institute_type);
        institute_status->institute_type = NULL;
    }
    if (institute_status->kapitalmarktorientiert) {
        free(institute_status->kapitalmarktorientiert);
        institute_status->kapitalmarktorientiert = NULL;
    }
    free(institute_status);
}

cJSON *institute_status_convertToJSON(institute_status_t *institute_status) {
    cJSON *item = cJSON_CreateObject();

    // institute_status->checklist
    if (!institute_status->checklist) {
        goto fail;
    }
    cJSON *checklist = cJSON_AddArrayToObject(item, "checklist");
    if(checklist == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *checklistListEntry;
    if (institute_status->checklist) {
    list_ForEach(checklistListEntry, institute_status->checklist) {
    cJSON *itemLocal = institute_check_item_convertToJSON(checklistListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(checklist, itemLocal);
    }
    }


    // institute_status->deadlines
    if (!institute_status->deadlines) {
        goto fail;
    }
    cJSON *deadlines_local_JSON = institute_deadlines_convertToJSON(institute_status->deadlines);
    if(deadlines_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deadlines", deadlines_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // institute_status->institute_type
    if (!institute_status->institute_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instituteType", institute_status->institute_type) == NULL) {
    goto fail; //String
    }


    // institute_status->kapitalmarktorientiert
    if (!institute_status->kapitalmarktorientiert) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "kapitalmarktorientiert", *institute_status->kapitalmarktorientiert) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

institute_status_t *institute_status_parseFromJSON(cJSON *institute_statusJSON){

    institute_status_t *institute_status_local_var = NULL;

    // define the local list for institute_status->checklist
    list_t *checklistList = NULL;

    // define the local variable for institute_status->deadlines
    institute_deadlines_t *deadlines_local_nonprim = NULL;

    char *institute_type_local_str = NULL;

    // define the local variable for institute_status->kapitalmarktorientiert
    int *kapitalmarktorientiert_local_var = NULL;

    // institute_status->checklist
    cJSON *checklist = cJSON_GetObjectItemCaseSensitive(institute_statusJSON, "checklist");
    if (cJSON_IsNull(checklist)) {
        checklist = NULL;
    }
    if (!checklist) {
        goto end;
    }

    
    cJSON *checklist_local_nonprimitive = NULL;
    if(!cJSON_IsArray(checklist)){
        goto end; //nonprimitive container
    }

    checklistList = list_createList();

    cJSON_ArrayForEach(checklist_local_nonprimitive,checklist )
    {
        if(!cJSON_IsObject(checklist_local_nonprimitive)){
            goto end;
        }
        institute_check_item_t *checklistItem = institute_check_item_parseFromJSON(checklist_local_nonprimitive);

        list_addElement(checklistList, checklistItem);
    }

    // institute_status->deadlines
    cJSON *deadlines = cJSON_GetObjectItemCaseSensitive(institute_statusJSON, "deadlines");
    if (cJSON_IsNull(deadlines)) {
        deadlines = NULL;
    }
    if (!deadlines) {
        goto end;
    }

    
    deadlines_local_nonprim = institute_deadlines_parseFromJSON(deadlines); //nonprimitive

    // institute_status->institute_type
    cJSON *institute_type = cJSON_GetObjectItemCaseSensitive(institute_statusJSON, "instituteType");
    if (cJSON_IsNull(institute_type)) {
        institute_type = NULL;
    }
    if (!institute_type) {
        goto end;
    }

    
    if(!cJSON_IsString(institute_type))
    {
    goto end; //String
    }

    // institute_status->kapitalmarktorientiert
    cJSON *kapitalmarktorientiert = cJSON_GetObjectItemCaseSensitive(institute_statusJSON, "kapitalmarktorientiert");
    if (cJSON_IsNull(kapitalmarktorientiert)) {
        kapitalmarktorientiert = NULL;
    }
    if (!kapitalmarktorientiert) {
        goto end;
    }

    
    if(!cJSON_IsBool(kapitalmarktorientiert))
    {
    goto end; //Bool
    }
    kapitalmarktorientiert_local_var = malloc(sizeof(int));
    if(!kapitalmarktorientiert_local_var)
    {
        goto end;
    }
    *kapitalmarktorientiert_local_var = kapitalmarktorientiert->valueint;


    if (institute_type && !cJSON_IsNull(institute_type)) institute_type_local_str = strdup(institute_type->valuestring);

    institute_status_local_var = institute_status_create_internal (
        checklistList,
        deadlines_local_nonprim,
        institute_type_local_str,
        kapitalmarktorientiert_local_var
        );

    if (!institute_status_local_var) {
        goto end;
    }

    return institute_status_local_var;
end:
    if (checklistList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, checklistList) {
            institute_check_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(checklistList);
        checklistList = NULL;
    }
    if (deadlines_local_nonprim) {
        institute_deadlines_free(deadlines_local_nonprim);
        deadlines_local_nonprim = NULL;
    }
    if (institute_type_local_str) {
        free(institute_type_local_str);
        institute_type_local_str = NULL;
    }
    if (kapitalmarktorientiert_local_var) {
        free(kapitalmarktorientiert_local_var);
        kapitalmarktorientiert_local_var = NULL;
    }
    return NULL;

}
