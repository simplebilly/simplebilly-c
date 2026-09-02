#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "current_inventory_value.h"



static current_inventory_value_t *current_inventory_value_create_internal(
    list_t *history,
    long *product_count,
    char *total_purchase_value,
    char *total_sales_value
    ) {
    current_inventory_value_t *current_inventory_value_local_var = malloc(sizeof(current_inventory_value_t));
    if (!current_inventory_value_local_var) {
        return NULL;
    }
    memset(current_inventory_value_local_var, 0, sizeof(current_inventory_value_t));
    current_inventory_value_local_var->_library_owned = 1;
    current_inventory_value_local_var->history = history;
    current_inventory_value_local_var->product_count = product_count;
    current_inventory_value_local_var->total_purchase_value = total_purchase_value;
    current_inventory_value_local_var->total_sales_value = total_sales_value;
    return current_inventory_value_local_var;
}

__attribute__((deprecated)) current_inventory_value_t *current_inventory_value_create(
    list_t *history,
    long *product_count,
    char *total_purchase_value,
    char *total_sales_value
    ) {
    long *product_count_copy = NULL;
    if (product_count) {
        product_count_copy = malloc(sizeof(long));
        if (product_count_copy) *product_count_copy = *product_count;
    }
    current_inventory_value_t *result = current_inventory_value_create_internal (
        history,
        product_count_copy,
        total_purchase_value,
        total_sales_value
        );
    if (!result) {
        free(product_count_copy);
    }
    return result;
}

void current_inventory_value_free(current_inventory_value_t *current_inventory_value) {
    if(NULL == current_inventory_value){
        return ;
    }
    if(current_inventory_value->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "current_inventory_value_free");
        return ;
    }
    listEntry_t *listEntry;
    if (current_inventory_value->history) {
        list_ForEach(listEntry, current_inventory_value->history) {
            inventory_value_point_free(listEntry->data);
        }
        list_freeList(current_inventory_value->history);
        current_inventory_value->history = NULL;
    }
    if (current_inventory_value->product_count) {
        free(current_inventory_value->product_count);
        current_inventory_value->product_count = NULL;
    }
    if (current_inventory_value->total_purchase_value) {
        free(current_inventory_value->total_purchase_value);
        current_inventory_value->total_purchase_value = NULL;
    }
    if (current_inventory_value->total_sales_value) {
        free(current_inventory_value->total_sales_value);
        current_inventory_value->total_sales_value = NULL;
    }
    free(current_inventory_value);
}

cJSON *current_inventory_value_convertToJSON(current_inventory_value_t *current_inventory_value) {
    cJSON *item = cJSON_CreateObject();

    // current_inventory_value->history
    if (!current_inventory_value->history) {
        goto fail;
    }
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (current_inventory_value->history) {
    list_ForEach(historyListEntry, current_inventory_value->history) {
    cJSON *itemLocal = inventory_value_point_convertToJSON(historyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(history, itemLocal);
    }
    }


    // current_inventory_value->product_count
    if (!current_inventory_value->product_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "product_count", *current_inventory_value->product_count) == NULL) {
    goto fail; //Numeric
    }


    // current_inventory_value->total_purchase_value
    if (!current_inventory_value->total_purchase_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_purchase_value", current_inventory_value->total_purchase_value) == NULL) {
    goto fail; //String
    }


    // current_inventory_value->total_sales_value
    if (!current_inventory_value->total_sales_value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total_sales_value", current_inventory_value->total_sales_value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

current_inventory_value_t *current_inventory_value_parseFromJSON(cJSON *current_inventory_valueJSON){

    current_inventory_value_t *current_inventory_value_local_var = NULL;

    // define the local list for current_inventory_value->history
    list_t *historyList = NULL;

    // define the local variable for current_inventory_value->product_count
    long *product_count_local_var = NULL;

    char *total_purchase_value_local_str = NULL;

    char *total_sales_value_local_str = NULL;

    // current_inventory_value->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(current_inventory_valueJSON, "history");
    if (cJSON_IsNull(history)) {
        history = NULL;
    }
    if (!history) {
        goto end;
    }

    
    cJSON *history_local_nonprimitive = NULL;
    if(!cJSON_IsArray(history)){
        goto end; //nonprimitive container
    }

    historyList = list_createList();

    cJSON_ArrayForEach(history_local_nonprimitive,history )
    {
        if(!cJSON_IsObject(history_local_nonprimitive)){
            goto end;
        }
        inventory_value_point_t *historyItem = inventory_value_point_parseFromJSON(history_local_nonprimitive);

        list_addElement(historyList, historyItem);
    }

    // current_inventory_value->product_count
    cJSON *product_count = cJSON_GetObjectItemCaseSensitive(current_inventory_valueJSON, "product_count");
    if (cJSON_IsNull(product_count)) {
        product_count = NULL;
    }
    if (!product_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(product_count))
    {
    goto end; //Numeric
    }
    product_count_local_var = malloc(sizeof(long));
    if(!product_count_local_var)
    {
        goto end;
    }
    *product_count_local_var = product_count->valuedouble;

    // current_inventory_value->total_purchase_value
    cJSON *total_purchase_value = cJSON_GetObjectItemCaseSensitive(current_inventory_valueJSON, "total_purchase_value");
    if (cJSON_IsNull(total_purchase_value)) {
        total_purchase_value = NULL;
    }
    if (!total_purchase_value) {
        goto end;
    }

    
    if(!cJSON_IsString(total_purchase_value))
    {
    goto end; //String
    }

    // current_inventory_value->total_sales_value
    cJSON *total_sales_value = cJSON_GetObjectItemCaseSensitive(current_inventory_valueJSON, "total_sales_value");
    if (cJSON_IsNull(total_sales_value)) {
        total_sales_value = NULL;
    }
    if (!total_sales_value) {
        goto end;
    }

    
    if(!cJSON_IsString(total_sales_value))
    {
    goto end; //String
    }


    if (total_purchase_value && !cJSON_IsNull(total_purchase_value)) total_purchase_value_local_str = strdup(total_purchase_value->valuestring);
    if (total_sales_value && !cJSON_IsNull(total_sales_value)) total_sales_value_local_str = strdup(total_sales_value->valuestring);

    current_inventory_value_local_var = current_inventory_value_create_internal (
        historyList,
        product_count_local_var,
        total_purchase_value_local_str,
        total_sales_value_local_str
        );

    if (!current_inventory_value_local_var) {
        goto end;
    }

    return current_inventory_value_local_var;
end:
    if (historyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, historyList) {
            inventory_value_point_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(historyList);
        historyList = NULL;
    }
    if (product_count_local_var) {
        free(product_count_local_var);
        product_count_local_var = NULL;
    }
    if (total_purchase_value_local_str) {
        free(total_purchase_value_local_str);
        total_purchase_value_local_str = NULL;
    }
    if (total_sales_value_local_str) {
        free(total_sales_value_local_str);
        total_sales_value_local_str = NULL;
    }
    return NULL;

}
