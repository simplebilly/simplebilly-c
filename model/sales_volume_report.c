#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sales_volume_report.h"



static sales_volume_report_t *sales_volume_report_create_internal(
    char *grand_total,
    list_t *items,
    long *total_count
    ) {
    sales_volume_report_t *sales_volume_report_local_var = malloc(sizeof(sales_volume_report_t));
    if (!sales_volume_report_local_var) {
        return NULL;
    }
    memset(sales_volume_report_local_var, 0, sizeof(sales_volume_report_t));
    sales_volume_report_local_var->_library_owned = 1;
    sales_volume_report_local_var->grand_total = grand_total;
    sales_volume_report_local_var->items = items;
    sales_volume_report_local_var->total_count = total_count;
    return sales_volume_report_local_var;
}

__attribute__((deprecated)) sales_volume_report_t *sales_volume_report_create(
    char *grand_total,
    list_t *items,
    long *total_count
    ) {
    long *total_count_copy = NULL;
    if (total_count) {
        total_count_copy = malloc(sizeof(long));
        if (total_count_copy) *total_count_copy = *total_count;
    }
    sales_volume_report_t *result = sales_volume_report_create_internal (
        grand_total,
        items,
        total_count_copy
        );
    if (!result) {
        free(total_count_copy);
    }
    return result;
}

void sales_volume_report_free(sales_volume_report_t *sales_volume_report) {
    if(NULL == sales_volume_report){
        return ;
    }
    if(sales_volume_report->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sales_volume_report_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sales_volume_report->grand_total) {
        free(sales_volume_report->grand_total);
        sales_volume_report->grand_total = NULL;
    }
    if (sales_volume_report->items) {
        list_ForEach(listEntry, sales_volume_report->items) {
            sales_volume_item_free(listEntry->data);
        }
        list_freeList(sales_volume_report->items);
        sales_volume_report->items = NULL;
    }
    if (sales_volume_report->total_count) {
        free(sales_volume_report->total_count);
        sales_volume_report->total_count = NULL;
    }
    free(sales_volume_report);
}

cJSON *sales_volume_report_convertToJSON(sales_volume_report_t *sales_volume_report) {
    cJSON *item = cJSON_CreateObject();

    // sales_volume_report->grand_total
    if (!sales_volume_report->grand_total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "grand_total", sales_volume_report->grand_total) == NULL) {
    goto fail; //String
    }


    // sales_volume_report->items
    if (!sales_volume_report->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (sales_volume_report->items) {
    list_ForEach(itemsListEntry, sales_volume_report->items) {
    cJSON *itemLocal = sales_volume_item_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // sales_volume_report->total_count
    if (!sales_volume_report->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", *sales_volume_report->total_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sales_volume_report_t *sales_volume_report_parseFromJSON(cJSON *sales_volume_reportJSON){

    sales_volume_report_t *sales_volume_report_local_var = NULL;

    char *grand_total_local_str = NULL;

    // define the local list for sales_volume_report->items
    list_t *itemsList = NULL;

    // define the local variable for sales_volume_report->total_count
    long *total_count_local_var = NULL;

    // sales_volume_report->grand_total
    cJSON *grand_total = cJSON_GetObjectItemCaseSensitive(sales_volume_reportJSON, "grand_total");
    if (cJSON_IsNull(grand_total)) {
        grand_total = NULL;
    }
    if (!grand_total) {
        goto end;
    }

    
    if(!cJSON_IsString(grand_total))
    {
    goto end; //String
    }

    // sales_volume_report->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(sales_volume_reportJSON, "items");
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
        sales_volume_item_t *itemsItem = sales_volume_item_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // sales_volume_report->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(sales_volume_reportJSON, "total_count");
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
    total_count_local_var = malloc(sizeof(long));
    if(!total_count_local_var)
    {
        goto end;
    }
    *total_count_local_var = total_count->valuedouble;


    if (grand_total && !cJSON_IsNull(grand_total)) grand_total_local_str = strdup(grand_total->valuestring);

    sales_volume_report_local_var = sales_volume_report_create_internal (
        grand_total_local_str,
        itemsList,
        total_count_local_var
        );

    if (!sales_volume_report_local_var) {
        goto end;
    }

    return sales_volume_report_local_var;
end:
    if (grand_total_local_str) {
        free(grand_total_local_str);
        grand_total_local_str = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            sales_volume_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (total_count_local_var) {
        free(total_count_local_var);
        total_count_local_var = NULL;
    }
    return NULL;

}
