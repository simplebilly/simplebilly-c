#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_order.h"



static return_order_t *return_order_create_internal(
    char *customer_contact_id,
    char *customer_name,
    any_type_t *line_items,
    char *notes,
    char *order_id,
    char *order_number,
    char *return_number,
    char *return_reason,
    return_order_status_t *status,
    char *warehouse_id
    ) {
    return_order_t *return_order_local_var = malloc(sizeof(return_order_t));
    if (!return_order_local_var) {
        return NULL;
    }
    memset(return_order_local_var, 0, sizeof(return_order_t));
    return_order_local_var->_library_owned = 1;
    return_order_local_var->customer_contact_id = customer_contact_id;
    return_order_local_var->customer_name = customer_name;
    return_order_local_var->line_items = line_items;
    return_order_local_var->notes = notes;
    return_order_local_var->order_id = order_id;
    return_order_local_var->order_number = order_number;
    return_order_local_var->return_number = return_number;
    return_order_local_var->return_reason = return_reason;
    return_order_local_var->status = status;
    return_order_local_var->warehouse_id = warehouse_id;
    return return_order_local_var;
}

__attribute__((deprecated)) return_order_t *return_order_create(
    char *customer_contact_id,
    char *customer_name,
    any_type_t *line_items,
    char *notes,
    char *order_id,
    char *order_number,
    char *return_number,
    char *return_reason,
    return_order_status_t *status,
    char *warehouse_id
    ) {
    return_order_t *result = return_order_create_internal (
        customer_contact_id,
        customer_name,
        line_items,
        notes,
        order_id,
        order_number,
        return_number,
        return_reason,
        status,
        warehouse_id
        );
    if (!result) {
    }
    return result;
}

void return_order_free(return_order_t *return_order) {
    if(NULL == return_order){
        return ;
    }
    if(return_order->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "return_order_free");
        return ;
    }
    listEntry_t *listEntry;
    if (return_order->customer_contact_id) {
        free(return_order->customer_contact_id);
        return_order->customer_contact_id = NULL;
    }
    if (return_order->customer_name) {
        free(return_order->customer_name);
        return_order->customer_name = NULL;
    }
    if (return_order->line_items) {
        _free(return_order->line_items);
        return_order->line_items = NULL;
    }
    if (return_order->notes) {
        free(return_order->notes);
        return_order->notes = NULL;
    }
    if (return_order->order_id) {
        free(return_order->order_id);
        return_order->order_id = NULL;
    }
    if (return_order->order_number) {
        free(return_order->order_number);
        return_order->order_number = NULL;
    }
    if (return_order->return_number) {
        free(return_order->return_number);
        return_order->return_number = NULL;
    }
    if (return_order->return_reason) {
        free(return_order->return_reason);
        return_order->return_reason = NULL;
    }
    if (return_order->status) {
        return_order_status_free(return_order->status);
        return_order->status = NULL;
    }
    if (return_order->warehouse_id) {
        free(return_order->warehouse_id);
        return_order->warehouse_id = NULL;
    }
    free(return_order);
}

cJSON *return_order_convertToJSON(return_order_t *return_order) {
    cJSON *item = cJSON_CreateObject();

    // return_order->customer_contact_id
    if(return_order->customer_contact_id) {
    if(cJSON_AddStringToObject(item, "customerContactId", return_order->customer_contact_id) == NULL) {
    goto fail; //String
    }
    }


    // return_order->customer_name
    if(return_order->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", return_order->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // return_order->line_items
    if(return_order->line_items) {
    cJSON *line_items_local_JSON = _convertToJSON(return_order->line_items);
    if(line_items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lineItems", line_items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // return_order->notes
    if(return_order->notes) {
    if(cJSON_AddStringToObject(item, "notes", return_order->notes) == NULL) {
    goto fail; //String
    }
    }


    // return_order->order_id
    if(return_order->order_id) {
    if(cJSON_AddStringToObject(item, "orderId", return_order->order_id) == NULL) {
    goto fail; //String
    }
    }


    // return_order->order_number
    if(return_order->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", return_order->order_number) == NULL) {
    goto fail; //String
    }
    }


    // return_order->return_number
    if (!return_order->return_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "returnNumber", return_order->return_number) == NULL) {
    goto fail; //String
    }


    // return_order->return_reason
    if(return_order->return_reason) {
    if(cJSON_AddStringToObject(item, "returnReason", return_order->return_reason) == NULL) {
    goto fail; //String
    }
    }


    // return_order->status
    if (!return_order->status) {
        goto fail;
    }
    cJSON *status_local_JSON = return_order_status_convertToJSON(return_order->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // return_order->warehouse_id
    if(return_order->warehouse_id) {
    if(cJSON_AddStringToObject(item, "warehouseId", return_order->warehouse_id) == NULL) {
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

return_order_t *return_order_parseFromJSON(cJSON *return_orderJSON){

    return_order_t *return_order_local_var = NULL;

    char *customer_contact_id_local_str = NULL;

    char *customer_name_local_str = NULL;

    // define the local variable for return_order->line_items
    _t *line_items_local_nonprim = NULL;

    char *notes_local_str = NULL;

    char *order_id_local_str = NULL;

    char *order_number_local_str = NULL;

    char *return_number_local_str = NULL;

    char *return_reason_local_str = NULL;

    // define the local variable for return_order->status
    return_order_status_t *status_local_nonprim = NULL;

    char *warehouse_id_local_str = NULL;

    // return_order->customer_contact_id
    cJSON *customer_contact_id = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "customerContactId");
    if (cJSON_IsNull(customer_contact_id)) {
        customer_contact_id = NULL;
    }
    if (customer_contact_id) { 
    if(!cJSON_IsString(customer_contact_id) && !cJSON_IsNull(customer_contact_id))
    {
    goto end; //String
    }
    }

    // return_order->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // return_order->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (line_items) { 
    line_items_local_nonprim = _parseFromJSON(line_items); //custom
    }

    // return_order->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // return_order->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "orderId");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // return_order->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // return_order->return_number
    cJSON *return_number = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "returnNumber");
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

    // return_order->return_reason
    cJSON *return_reason = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "returnReason");
    if (cJSON_IsNull(return_reason)) {
        return_reason = NULL;
    }
    if (return_reason) { 
    if(!cJSON_IsString(return_reason) && !cJSON_IsNull(return_reason))
    {
    goto end; //String
    }
    }

    // return_order->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = return_order_status_parseFromJSON(status); //custom

    // return_order->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(return_orderJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (warehouse_id) { 
    if(!cJSON_IsString(warehouse_id) && !cJSON_IsNull(warehouse_id))
    {
    goto end; //String
    }
    }


    if (customer_contact_id && !cJSON_IsNull(customer_contact_id)) customer_contact_id_local_str = strdup(customer_contact_id->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (return_number && !cJSON_IsNull(return_number)) return_number_local_str = strdup(return_number->valuestring);
    if (return_reason && !cJSON_IsNull(return_reason)) return_reason_local_str = strdup(return_reason->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    return_order_local_var = return_order_create_internal (
        customer_contact_id_local_str,
        customer_name_local_str,
        line_items ? line_items_local_nonprim : NULL,
        notes_local_str,
        order_id_local_str,
        order_number_local_str,
        return_number_local_str,
        return_reason_local_str,
        status_local_nonprim,
        warehouse_id_local_str
        );

    if (!return_order_local_var) {
        goto end;
    }

    return return_order_local_var;
end:
    if (customer_contact_id_local_str) {
        free(customer_contact_id_local_str);
        customer_contact_id_local_str = NULL;
    }
    if (customer_name_local_str) {
        free(customer_name_local_str);
        customer_name_local_str = NULL;
    }
    if (line_items_local_nonprim) {
        _free(line_items_local_nonprim);
        line_items_local_nonprim = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (return_number_local_str) {
        free(return_number_local_str);
        return_number_local_str = NULL;
    }
    if (return_reason_local_str) {
        free(return_reason_local_str);
        return_reason_local_str = NULL;
    }
    if (status_local_nonprim) {
        return_order_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
