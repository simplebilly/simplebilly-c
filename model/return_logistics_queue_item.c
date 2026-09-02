#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_logistics_queue_item.h"



static return_logistics_queue_item_t *return_logistics_queue_item_create_internal(
    long *age_days,
    char *created_at,
    char *customer_name,
    any_type_t *line_items,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *warehouse_id
    ) {
    return_logistics_queue_item_t *return_logistics_queue_item_local_var = malloc(sizeof(return_logistics_queue_item_t));
    if (!return_logistics_queue_item_local_var) {
        return NULL;
    }
    memset(return_logistics_queue_item_local_var, 0, sizeof(return_logistics_queue_item_t));
    return_logistics_queue_item_local_var->_library_owned = 1;
    return_logistics_queue_item_local_var->age_days = age_days;
    return_logistics_queue_item_local_var->created_at = created_at;
    return_logistics_queue_item_local_var->customer_name = customer_name;
    return_logistics_queue_item_local_var->line_items = line_items;
    return_logistics_queue_item_local_var->order_number = order_number;
    return_logistics_queue_item_local_var->return_number = return_number;
    return_logistics_queue_item_local_var->return_order_id = return_order_id;
    return_logistics_queue_item_local_var->status = status;
    return_logistics_queue_item_local_var->warehouse_id = warehouse_id;
    return return_logistics_queue_item_local_var;
}

__attribute__((deprecated)) return_logistics_queue_item_t *return_logistics_queue_item_create(
    long *age_days,
    char *created_at,
    char *customer_name,
    any_type_t *line_items,
    char *order_number,
    char *return_number,
    char *return_order_id,
    char *status,
    char *warehouse_id
    ) {
    long *age_days_copy = NULL;
    if (age_days) {
        age_days_copy = malloc(sizeof(long));
        if (age_days_copy) *age_days_copy = *age_days;
    }
    return_logistics_queue_item_t *result = return_logistics_queue_item_create_internal (
        age_days_copy,
        created_at,
        customer_name,
        line_items,
        order_number,
        return_number,
        return_order_id,
        status,
        warehouse_id
        );
    if (!result) {
        free(age_days_copy);
    }
    return result;
}

void return_logistics_queue_item_free(return_logistics_queue_item_t *return_logistics_queue_item) {
    if(NULL == return_logistics_queue_item){
        return ;
    }
    if(return_logistics_queue_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "return_logistics_queue_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (return_logistics_queue_item->age_days) {
        free(return_logistics_queue_item->age_days);
        return_logistics_queue_item->age_days = NULL;
    }
    if (return_logistics_queue_item->created_at) {
        free(return_logistics_queue_item->created_at);
        return_logistics_queue_item->created_at = NULL;
    }
    if (return_logistics_queue_item->customer_name) {
        free(return_logistics_queue_item->customer_name);
        return_logistics_queue_item->customer_name = NULL;
    }
    if (return_logistics_queue_item->line_items) {
        _free(return_logistics_queue_item->line_items);
        return_logistics_queue_item->line_items = NULL;
    }
    if (return_logistics_queue_item->order_number) {
        free(return_logistics_queue_item->order_number);
        return_logistics_queue_item->order_number = NULL;
    }
    if (return_logistics_queue_item->return_number) {
        free(return_logistics_queue_item->return_number);
        return_logistics_queue_item->return_number = NULL;
    }
    if (return_logistics_queue_item->return_order_id) {
        free(return_logistics_queue_item->return_order_id);
        return_logistics_queue_item->return_order_id = NULL;
    }
    if (return_logistics_queue_item->status) {
        free(return_logistics_queue_item->status);
        return_logistics_queue_item->status = NULL;
    }
    if (return_logistics_queue_item->warehouse_id) {
        free(return_logistics_queue_item->warehouse_id);
        return_logistics_queue_item->warehouse_id = NULL;
    }
    free(return_logistics_queue_item);
}

cJSON *return_logistics_queue_item_convertToJSON(return_logistics_queue_item_t *return_logistics_queue_item) {
    cJSON *item = cJSON_CreateObject();

    // return_logistics_queue_item->age_days
    if (!return_logistics_queue_item->age_days) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ageDays", *return_logistics_queue_item->age_days) == NULL) {
    goto fail; //Numeric
    }


    // return_logistics_queue_item->created_at
    if (!return_logistics_queue_item->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", return_logistics_queue_item->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // return_logistics_queue_item->customer_name
    if(return_logistics_queue_item->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", return_logistics_queue_item->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // return_logistics_queue_item->line_items
    if (!return_logistics_queue_item->line_items) {
        goto fail;
    }
    cJSON *line_items_local_JSON = _convertToJSON(return_logistics_queue_item->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // return_logistics_queue_item->order_number
    if(return_logistics_queue_item->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", return_logistics_queue_item->order_number) == NULL) {
    goto fail; //String
    }
    }


    // return_logistics_queue_item->return_number
    if (!return_logistics_queue_item->return_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "returnNumber", return_logistics_queue_item->return_number) == NULL) {
    goto fail; //String
    }


    // return_logistics_queue_item->return_order_id
    if (!return_logistics_queue_item->return_order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "returnOrderId", return_logistics_queue_item->return_order_id) == NULL) {
    goto fail; //String
    }


    // return_logistics_queue_item->status
    if (!return_logistics_queue_item->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", return_logistics_queue_item->status) == NULL) {
    goto fail; //String
    }


    // return_logistics_queue_item->warehouse_id
    if(return_logistics_queue_item->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", return_logistics_queue_item->warehouse_id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

return_logistics_queue_item_t *return_logistics_queue_item_parseFromJSON(cJSON *return_logistics_queue_itemJSON){

    return_logistics_queue_item_t *return_logistics_queue_item_local_var = NULL;

    // define the local variable for return_logistics_queue_item->age_days
    long *age_days_local_var = NULL;

    char *created_at_local_str = NULL;

    char *customer_name_local_str = NULL;

    // define the local variable for return_logistics_queue_item->line_items
    _t *line_items_local_nonprim = NULL;

    char *order_number_local_str = NULL;

    char *return_number_local_str = NULL;

    char *return_order_id_local_str = NULL;

    char *status_local_str = NULL;

    char *warehouse_id_local_str = NULL;

    // return_logistics_queue_item->age_days
    cJSON *age_days = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "ageDays");
    if (cJSON_IsNull(age_days)) {
        age_days = NULL;
    }
    if (!age_days) {
        goto end;
    }

    
    if(!cJSON_IsNumber(age_days))
    {
    goto end; //Numeric
    }
    age_days_local_var = malloc(sizeof(long));
    if(!age_days_local_var)
    {
        goto end;
    }
    *age_days_local_var = age_days->valuedouble;

    // return_logistics_queue_item->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // return_logistics_queue_item->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // return_logistics_queue_item->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    line_items_local_nonprim = _parseFromJSON(line_items); //custom

    // return_logistics_queue_item->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // return_logistics_queue_item->return_number
    cJSON *return_number = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "returnNumber");
    if (cJSON_IsNull(return_number)) {
        return_number = NULL;
    }
    if (!return_number) {
        goto end;
    }

    
    if(!cJSON_IsString(return_number))
    {
    goto end; //String
    }

    // return_logistics_queue_item->return_order_id
    cJSON *return_order_id = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "returnOrderId");
    if (cJSON_IsNull(return_order_id)) {
        return_order_id = NULL;
    }
    if (!return_order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(return_order_id))
    {
    goto end; //String
    }

    // return_logistics_queue_item->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // return_logistics_queue_item->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(return_logistics_queue_itemJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (return_number && !cJSON_IsNull(return_number)) return_number_local_str = strdup(return_number->valuestring);
    if (return_order_id && !cJSON_IsNull(return_order_id)) return_order_id_local_str = strdup(return_order_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    return_logistics_queue_item_local_var = return_logistics_queue_item_create_internal (
        age_days_local_var,
        created_at_local_str,
        customer_name_local_str,
        line_items_local_nonprim,
        order_number_local_str,
        return_number_local_str,
        return_order_id_local_str,
        status_local_str,
        warehouse_id_local_str
        );

    if (!return_logistics_queue_item_local_var) {
        goto end;
    }

    return return_logistics_queue_item_local_var;
end:
    if (age_days_local_var) {
        free(age_days_local_var);
        age_days_local_var = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (customer_name_local_str) {
        free(customer_name_local_str);
        customer_name_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (return_number_local_str) {
        free(return_number_local_str);
        return_number_local_str = NULL;
    }
    if (return_order_id_local_str) {
        free(return_order_id_local_str);
        return_order_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
