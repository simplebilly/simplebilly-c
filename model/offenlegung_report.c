#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "offenlegung_report.h"



static offenlegung_report_t *offenlegung_report_create_internal(
    char *deadline,
    int *deadline_months,
    list_t *items,
    int *kapitalmarktorientiert,
    char *note,
    int *year
    ) {
    offenlegung_report_t *offenlegung_report_local_var = malloc(sizeof(offenlegung_report_t));
    if (!offenlegung_report_local_var) {
        return NULL;
    }
    memset(offenlegung_report_local_var, 0, sizeof(offenlegung_report_t));
    offenlegung_report_local_var->_library_owned = 1;
    offenlegung_report_local_var->deadline = deadline;
    offenlegung_report_local_var->deadline_months = deadline_months;
    offenlegung_report_local_var->items = items;
    offenlegung_report_local_var->kapitalmarktorientiert = kapitalmarktorientiert;
    offenlegung_report_local_var->note = note;
    offenlegung_report_local_var->year = year;
    return offenlegung_report_local_var;
}

__attribute__((deprecated)) offenlegung_report_t *offenlegung_report_create(
    char *deadline,
    int *deadline_months,
    list_t *items,
    int *kapitalmarktorientiert,
    char *note,
    int *year
    ) {
    int *deadline_months_copy = NULL;
    if (deadline_months) {
        deadline_months_copy = malloc(sizeof(int));
        if (deadline_months_copy) *deadline_months_copy = *deadline_months;
    }
    int *kapitalmarktorientiert_copy = NULL;
    if (kapitalmarktorientiert) {
        kapitalmarktorientiert_copy = malloc(sizeof(int));
        if (kapitalmarktorientiert_copy) *kapitalmarktorientiert_copy = *kapitalmarktorientiert;
    }
    int *year_copy = NULL;
    if (year) {
        year_copy = malloc(sizeof(int));
        if (year_copy) *year_copy = *year;
    }
    offenlegung_report_t *result = offenlegung_report_create_internal (
        deadline,
        deadline_months_copy,
        items,
        kapitalmarktorientiert_copy,
        note,
        year_copy
        );
    if (!result) {
        free(deadline_months_copy);
        free(kapitalmarktorientiert_copy);
        free(year_copy);
    }
    return result;
}

void offenlegung_report_free(offenlegung_report_t *offenlegung_report) {
    if(NULL == offenlegung_report){
        return ;
    }
    if(offenlegung_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "offenlegung_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (offenlegung_report->deadline) {
        free(offenlegung_report->deadline);
        offenlegung_report->deadline = NULL;
    }
    if (offenlegung_report->deadline_months) {
        free(offenlegung_report->deadline_months);
        offenlegung_report->deadline_months = NULL;
    }
    if (offenlegung_report->items) {
        list_ForEach(listEntry, offenlegung_report->items) {
            offenlegung_item_free(listEntry->data);
        }
        list_freeList(offenlegung_report->items);
        offenlegung_report->items = NULL;
    }
    if (offenlegung_report->kapitalmarktorientiert) {
        free(offenlegung_report->kapitalmarktorientiert);
        offenlegung_report->kapitalmarktorientiert = NULL;
    }
    if (offenlegung_report->note) {
        free(offenlegung_report->note);
        offenlegung_report->note = NULL;
    }
    if (offenlegung_report->year) {
        free(offenlegung_report->year);
        offenlegung_report->year = NULL;
    }
    free(offenlegung_report);
}

cJSON *offenlegung_report_convertToJSON(offenlegung_report_t *offenlegung_report) {
    cJSON *item = cJSON_CreateObject();

    // offenlegung_report->deadline
    if (!offenlegung_report->deadline) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deadline", offenlegung_report->deadline) == NULL) {
    goto fail; //Date
    }


    // offenlegung_report->deadline_months
    if (!offenlegung_report->deadline_months) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "deadline_months", *offenlegung_report->deadline_months) == NULL) {
    goto fail; //Numeric
    }


    // offenlegung_report->items
    if (!offenlegung_report->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (offenlegung_report->items) {
    list_ForEach(itemsListEntry, offenlegung_report->items) {
    cJSON *itemLocal = offenlegung_item_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // offenlegung_report->kapitalmarktorientiert
    if (!offenlegung_report->kapitalmarktorientiert) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "kapitalmarktorientiert", *offenlegung_report->kapitalmarktorientiert) == NULL) {
    goto fail; //Bool
    }


    // offenlegung_report->note
    if (!offenlegung_report->note) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "note", offenlegung_report->note) == NULL) {
    goto fail; //String
    }


    // offenlegung_report->year
    if (!offenlegung_report->year) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "year", *offenlegung_report->year) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

offenlegung_report_t *offenlegung_report_parseFromJSON(cJSON *offenlegung_reportJSON){

    offenlegung_report_t *offenlegung_report_local_var = NULL;

    char *deadline_local_str = NULL;

    // define the local variable for offenlegung_report->deadline_months
    int *deadline_months_local_var = NULL;

    // define the local list for offenlegung_report->items
    list_t *itemsList = NULL;

    // define the local variable for offenlegung_report->kapitalmarktorientiert
    int *kapitalmarktorientiert_local_var = NULL;

    char *note_local_str = NULL;

    // define the local variable for offenlegung_report->year
    int *year_local_var = NULL;

    // offenlegung_report->deadline
    cJSON *deadline = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "deadline");
    if (cJSON_IsNull(deadline)) {
        deadline = NULL;
    }
    if (!deadline) {
        goto end;
    }

    
    if(!cJSON_IsString(deadline))
    {
    goto end; //Date
    }

    // offenlegung_report->deadline_months
    cJSON *deadline_months = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "deadline_months");
    if (cJSON_IsNull(deadline_months)) {
        deadline_months = NULL;
    }
    if (!deadline_months) {
        goto end;
    }

    
    if(!cJSON_IsNumber(deadline_months))
    {
    goto end; //Numeric
    }
    deadline_months_local_var = malloc(sizeof(int));
    if(!deadline_months_local_var)
    {
        goto end;
    }
    *deadline_months_local_var = deadline_months->valuedouble;

    // offenlegung_report->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        offenlegung_item_t *itemsItem = offenlegung_item_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // offenlegung_report->kapitalmarktorientiert
    cJSON *kapitalmarktorientiert = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "kapitalmarktorientiert");
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

    // offenlegung_report->note
    cJSON *note = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "note");
    if (cJSON_IsNull(note)) {
        note = NULL;
    }
    if (!note) {
        goto end;
    }

    
    if(!cJSON_IsString(note))
    {
    goto end; //String
    }

    // offenlegung_report->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(offenlegung_reportJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (!year) {
        goto end;
    }

    
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    year_local_var = malloc(sizeof(int));
    if(!year_local_var)
    {
        goto end;
    }
    *year_local_var = year->valuedouble;


    if (deadline) deadline_local_str = strdup(deadline->valuestring);
    if (note && !cJSON_IsNull(note)) note_local_str = strdup(note->valuestring);

    offenlegung_report_local_var = offenlegung_report_create_internal (
        deadline_local_str,
        deadline_months_local_var,
        itemsList,
        kapitalmarktorientiert_local_var,
        note_local_str,
        year_local_var
        );

    if (!offenlegung_report_local_var) {
        goto end;
    }

    return offenlegung_report_local_var;
end:
    if (deadline_local_str) {
        free(deadline_local_str);
        deadline_local_str = NULL;
    }
    if (deadline_months_local_var) {
        free(deadline_months_local_var);
        deadline_months_local_var = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            offenlegung_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (kapitalmarktorientiert_local_var) {
        free(kapitalmarktorientiert_local_var);
        kapitalmarktorientiert_local_var = NULL;
    }
    if (note_local_str) {
        free(note_local_str);
        note_local_str = NULL;
    }
    if (year_local_var) {
        free(year_local_var);
        year_local_var = NULL;
    }
    return NULL;

}
