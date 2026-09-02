#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_logistics_summary.h"



static return_logistics_summary_t *return_logistics_summary_create_internal(
    any_type_t *by_status,
    list_t *by_warehouse,
    long *items_restocked,
    long *items_scrapped,
    long *total_items,
    long *total_returns
    ) {
    return_logistics_summary_t *return_logistics_summary_local_var = malloc(sizeof(return_logistics_summary_t));
    if (!return_logistics_summary_local_var) {
        return NULL;
    }
    memset(return_logistics_summary_local_var, 0, sizeof(return_logistics_summary_t));
    return_logistics_summary_local_var->_library_owned = 1;
    return_logistics_summary_local_var->by_status = by_status;
    return_logistics_summary_local_var->by_warehouse = by_warehouse;
    return_logistics_summary_local_var->items_restocked = items_restocked;
    return_logistics_summary_local_var->items_scrapped = items_scrapped;
    return_logistics_summary_local_var->total_items = total_items;
    return_logistics_summary_local_var->total_returns = total_returns;
    return return_logistics_summary_local_var;
}

__attribute__((deprecated)) return_logistics_summary_t *return_logistics_summary_create(
    any_type_t *by_status,
    list_t *by_warehouse,
    long *items_restocked,
    long *items_scrapped,
    long *total_items,
    long *total_returns
    ) {
    long *items_restocked_copy = NULL;
    if (items_restocked) {
        items_restocked_copy = malloc(sizeof(long));
        if (items_restocked_copy) *items_restocked_copy = *items_restocked;
    }
    long *items_scrapped_copy = NULL;
    if (items_scrapped) {
        items_scrapped_copy = malloc(sizeof(long));
        if (items_scrapped_copy) *items_scrapped_copy = *items_scrapped;
    }
    long *total_items_copy = NULL;
    if (total_items) {
        total_items_copy = malloc(sizeof(long));
        if (total_items_copy) *total_items_copy = *total_items;
    }
    long *total_returns_copy = NULL;
    if (total_returns) {
        total_returns_copy = malloc(sizeof(long));
        if (total_returns_copy) *total_returns_copy = *total_returns;
    }
    return_logistics_summary_t *result = return_logistics_summary_create_internal (
        by_status,
        by_warehouse,
        items_restocked_copy,
        items_scrapped_copy,
        total_items_copy,
        total_returns_copy
        );
    if (!result) {
        free(items_restocked_copy);
        free(items_scrapped_copy);
        free(total_items_copy);
        free(total_returns_copy);
    }
    return result;
}

void return_logistics_summary_free(return_logistics_summary_t *return_logistics_summary) {
    if(NULL == return_logistics_summary){
        return ;
    }
    if(return_logistics_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "return_logistics_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (return_logistics_summary->by_status) {
        _free(return_logistics_summary->by_status);
        return_logistics_summary->by_status = NULL;
    }
    if (return_logistics_summary->by_warehouse) {
        list_ForEach(listEntry, return_logistics_summary->by_warehouse) {
            return_warehouse_summary_free(listEntry->data);
        }
        list_freeList(return_logistics_summary->by_warehouse);
        return_logistics_summary->by_warehouse = NULL;
    }
    if (return_logistics_summary->items_restocked) {
        free(return_logistics_summary->items_restocked);
        return_logistics_summary->items_restocked = NULL;
    }
    if (return_logistics_summary->items_scrapped) {
        free(return_logistics_summary->items_scrapped);
        return_logistics_summary->items_scrapped = NULL;
    }
    if (return_logistics_summary->total_items) {
        free(return_logistics_summary->total_items);
        return_logistics_summary->total_items = NULL;
    }
    if (return_logistics_summary->total_returns) {
        free(return_logistics_summary->total_returns);
        return_logistics_summary->total_returns = NULL;
    }
    free(return_logistics_summary);
}

cJSON *return_logistics_summary_convertToJSON(return_logistics_summary_t *return_logistics_summary) {
    cJSON *item = cJSON_CreateObject();

    // return_logistics_summary->by_status
    if (!return_logistics_summary->by_status) {
        goto fail;
    }
    cJSON *by_status_local_JSON = _convertToJSON(return_logistics_summary->by_status);
    if(by_status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "byStatus", by_status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // return_logistics_summary->by_warehouse
    if (!return_logistics_summary->by_warehouse) {
        goto fail;
    }
    cJSON *by_warehouse = cJSON_AddArrayToObject(item, "byWarehouse");
    if(by_warehouse == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *by_warehouseListEntry;
    if (return_logistics_summary->by_warehouse) {
    list_ForEach(by_warehouseListEntry, return_logistics_summary->by_warehouse) {
    cJSON *itemLocal = return_warehouse_summary_convertToJSON(by_warehouseListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(by_warehouse, itemLocal);
    }
    }


    // return_logistics_summary->items_restocked
    if (!return_logistics_summary->items_restocked) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsRestocked", *return_logistics_summary->items_restocked) == NULL) {
    goto fail; //Numeric
    }


    // return_logistics_summary->items_scrapped
    if (!return_logistics_summary->items_scrapped) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsScrapped", *return_logistics_summary->items_scrapped) == NULL) {
    goto fail; //Numeric
    }


    // return_logistics_summary->total_items
    if (!return_logistics_summary->total_items) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalItems", *return_logistics_summary->total_items) == NULL) {
    goto fail; //Numeric
    }


    // return_logistics_summary->total_returns
    if (!return_logistics_summary->total_returns) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalReturns", *return_logistics_summary->total_returns) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

return_logistics_summary_t *return_logistics_summary_parseFromJSON(cJSON *return_logistics_summaryJSON){

    return_logistics_summary_t *return_logistics_summary_local_var = NULL;

    // define the local variable for return_logistics_summary->by_status
    _t *by_status_local_nonprim = NULL;

    // define the local list for return_logistics_summary->by_warehouse
    list_t *by_warehouseList = NULL;

    // define the local variable for return_logistics_summary->items_restocked
    long *items_restocked_local_var = NULL;

    // define the local variable for return_logistics_summary->items_scrapped
    long *items_scrapped_local_var = NULL;

    // define the local variable for return_logistics_summary->total_items
    long *total_items_local_var = NULL;

    // define the local variable for return_logistics_summary->total_returns
    long *total_returns_local_var = NULL;

    // return_logistics_summary->by_status
    cJSON *by_status = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "byStatus");
    if (cJSON_IsNull(by_status)) {
        by_status = NULL;
    }
    if (!by_status) {
        goto end;
    }

    
    by_status_local_nonprim = _parseFromJSON(by_status); //custom

    // return_logistics_summary->by_warehouse
    cJSON *by_warehouse = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "byWarehouse");
    if (cJSON_IsNull(by_warehouse)) {
        by_warehouse = NULL;
    }
    if (!by_warehouse) {
        goto end;
    }

    
    cJSON *by_warehouse_local_nonprimitive = NULL;
    if(!cJSON_IsArray(by_warehouse)){
        goto end; //nonprimitive container
    }

    by_warehouseList = list_createList();

    cJSON_ArrayForEach(by_warehouse_local_nonprimitive,by_warehouse )
    {
        if(!cJSON_IsObject(by_warehouse_local_nonprimitive)){
            goto end;
        }
        return_warehouse_summary_t *by_warehouseItem = return_warehouse_summary_parseFromJSON(by_warehouse_local_nonprimitive);

        list_addElement(by_warehouseList, by_warehouseItem);
    }

    // return_logistics_summary->items_restocked
    cJSON *items_restocked = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "itemsRestocked");
    if (cJSON_IsNull(items_restocked)) {
        items_restocked = NULL;
    }
    if (!items_restocked) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_restocked))
    {
    goto end; //Numeric
    }
    items_restocked_local_var = malloc(sizeof(long));
    if(!items_restocked_local_var)
    {
        goto end;
    }
    *items_restocked_local_var = items_restocked->valuedouble;

    // return_logistics_summary->items_scrapped
    cJSON *items_scrapped = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "itemsScrapped");
    if (cJSON_IsNull(items_scrapped)) {
        items_scrapped = NULL;
    }
    if (!items_scrapped) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_scrapped))
    {
    goto end; //Numeric
    }
    items_scrapped_local_var = malloc(sizeof(long));
    if(!items_scrapped_local_var)
    {
        goto end;
    }
    *items_scrapped_local_var = items_scrapped->valuedouble;

    // return_logistics_summary->total_items
    cJSON *total_items = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "totalItems");
    if (cJSON_IsNull(total_items)) {
        total_items = NULL;
    }
    if (!total_items) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_items))
    {
    goto end; //Numeric
    }
    total_items_local_var = malloc(sizeof(long));
    if(!total_items_local_var)
    {
        goto end;
    }
    *total_items_local_var = total_items->valuedouble;

    // return_logistics_summary->total_returns
    cJSON *total_returns = cJSON_GetObjectItemCaseSensitive(return_logistics_summaryJSON, "totalReturns");
    if (cJSON_IsNull(total_returns)) {
        total_returns = NULL;
    }
    if (!total_returns) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_returns))
    {
    goto end; //Numeric
    }
    total_returns_local_var = malloc(sizeof(long));
    if(!total_returns_local_var)
    {
        goto end;
    }
    *total_returns_local_var = total_returns->valuedouble;



    return_logistics_summary_local_var = return_logistics_summary_create_internal (
        by_status_local_nonprim,
        by_warehouseList,
        items_restocked_local_var,
        items_scrapped_local_var,
        total_items_local_var,
        total_returns_local_var
        );

    if (!return_logistics_summary_local_var) {
        goto end;
    }

    return return_logistics_summary_local_var;
end:
    if (by_status_local_nonprim) {
        _free(by_status_local_nonprim);
        by_status_local_nonprim = NULL;
    }
    if (by_warehouseList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, by_warehouseList) {
            return_warehouse_summary_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(by_warehouseList);
        by_warehouseList = NULL;
    }
    if (items_restocked_local_var) {
        free(items_restocked_local_var);
        items_restocked_local_var = NULL;
    }
    if (items_scrapped_local_var) {
        free(items_scrapped_local_var);
        items_scrapped_local_var = NULL;
    }
    if (total_items_local_var) {
        free(total_items_local_var);
        total_items_local_var = NULL;
    }
    if (total_returns_local_var) {
        free(total_returns_local_var);
        total_returns_local_var = NULL;
    }
    return NULL;

}
