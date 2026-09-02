#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "packing_queue_item.h"



static packing_queue_item_t *packing_queue_item_create_internal(
    char *created_at,
    char *customer_id,
    int *delivery_note_printed,
    any_type_t *items,
    int *items_count,
    int *label_printed,
    char *order_number,
    char *order_status,
    char *shipment_id,
    any_type_t *shipping_address,
    char *shipping_method,
    char *tracking_number,
    char *video_recording
    ) {
    packing_queue_item_t *packing_queue_item_local_var = malloc(sizeof(packing_queue_item_t));
    if (!packing_queue_item_local_var) {
        return NULL;
    }
    memset(packing_queue_item_local_var, 0, sizeof(packing_queue_item_t));
    packing_queue_item_local_var->_library_owned = 1;
    packing_queue_item_local_var->created_at = created_at;
    packing_queue_item_local_var->customer_id = customer_id;
    packing_queue_item_local_var->delivery_note_printed = delivery_note_printed;
    packing_queue_item_local_var->items = items;
    packing_queue_item_local_var->items_count = items_count;
    packing_queue_item_local_var->label_printed = label_printed;
    packing_queue_item_local_var->order_number = order_number;
    packing_queue_item_local_var->order_status = order_status;
    packing_queue_item_local_var->shipment_id = shipment_id;
    packing_queue_item_local_var->shipping_address = shipping_address;
    packing_queue_item_local_var->shipping_method = shipping_method;
    packing_queue_item_local_var->tracking_number = tracking_number;
    packing_queue_item_local_var->video_recording = video_recording;
    return packing_queue_item_local_var;
}

__attribute__((deprecated)) packing_queue_item_t *packing_queue_item_create(
    char *created_at,
    char *customer_id,
    int *delivery_note_printed,
    any_type_t *items,
    int *items_count,
    int *label_printed,
    char *order_number,
    char *order_status,
    char *shipment_id,
    any_type_t *shipping_address,
    char *shipping_method,
    char *tracking_number,
    char *video_recording
    ) {
    int *delivery_note_printed_copy = NULL;
    if (delivery_note_printed) {
        delivery_note_printed_copy = malloc(sizeof(int));
        if (delivery_note_printed_copy) *delivery_note_printed_copy = *delivery_note_printed;
    }
    int *items_count_copy = NULL;
    if (items_count) {
        items_count_copy = malloc(sizeof(int));
        if (items_count_copy) *items_count_copy = *items_count;
    }
    int *label_printed_copy = NULL;
    if (label_printed) {
        label_printed_copy = malloc(sizeof(int));
        if (label_printed_copy) *label_printed_copy = *label_printed;
    }
    packing_queue_item_t *result = packing_queue_item_create_internal (
        created_at,
        customer_id,
        delivery_note_printed_copy,
        items,
        items_count_copy,
        label_printed_copy,
        order_number,
        order_status,
        shipment_id,
        shipping_address,
        shipping_method,
        tracking_number,
        video_recording
        );
    if (!result) {
        free(delivery_note_printed_copy);
        free(items_count_copy);
        free(label_printed_copy);
    }
    return result;
}

void packing_queue_item_free(packing_queue_item_t *packing_queue_item) {
    if(NULL == packing_queue_item){
        return ;
    }
    if(packing_queue_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "packing_queue_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (packing_queue_item->created_at) {
        free(packing_queue_item->created_at);
        packing_queue_item->created_at = NULL;
    }
    if (packing_queue_item->customer_id) {
        free(packing_queue_item->customer_id);
        packing_queue_item->customer_id = NULL;
    }
    if (packing_queue_item->delivery_note_printed) {
        free(packing_queue_item->delivery_note_printed);
        packing_queue_item->delivery_note_printed = NULL;
    }
    if (packing_queue_item->items) {
        _free(packing_queue_item->items);
        packing_queue_item->items = NULL;
    }
    if (packing_queue_item->items_count) {
        free(packing_queue_item->items_count);
        packing_queue_item->items_count = NULL;
    }
    if (packing_queue_item->label_printed) {
        free(packing_queue_item->label_printed);
        packing_queue_item->label_printed = NULL;
    }
    if (packing_queue_item->order_number) {
        free(packing_queue_item->order_number);
        packing_queue_item->order_number = NULL;
    }
    if (packing_queue_item->order_status) {
        free(packing_queue_item->order_status);
        packing_queue_item->order_status = NULL;
    }
    if (packing_queue_item->shipment_id) {
        free(packing_queue_item->shipment_id);
        packing_queue_item->shipment_id = NULL;
    }
    if (packing_queue_item->shipping_address) {
        _free(packing_queue_item->shipping_address);
        packing_queue_item->shipping_address = NULL;
    }
    if (packing_queue_item->shipping_method) {
        free(packing_queue_item->shipping_method);
        packing_queue_item->shipping_method = NULL;
    }
    if (packing_queue_item->tracking_number) {
        free(packing_queue_item->tracking_number);
        packing_queue_item->tracking_number = NULL;
    }
    if (packing_queue_item->video_recording) {
        free(packing_queue_item->video_recording);
        packing_queue_item->video_recording = NULL;
    }
    free(packing_queue_item);
}

cJSON *packing_queue_item_convertToJSON(packing_queue_item_t *packing_queue_item) {
    cJSON *item = cJSON_CreateObject();

    // packing_queue_item->created_at
    if (!packing_queue_item->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", packing_queue_item->created_at) == NULL) {
    goto fail; //String
    }


    // packing_queue_item->customer_id
    if (!packing_queue_item->customer_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "customer_id", packing_queue_item->customer_id) == NULL) {
    goto fail; //String
    }


    // packing_queue_item->delivery_note_printed
    if (!packing_queue_item->delivery_note_printed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "delivery_note_printed", *packing_queue_item->delivery_note_printed) == NULL) {
    goto fail; //Bool
    }


    // packing_queue_item->items
    if (!packing_queue_item->items) {
        goto fail;
    }
    cJSON *items_local_JSON = _convertToJSON(packing_queue_item->items);
    if(items_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "items", items_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // packing_queue_item->items_count
    if (!packing_queue_item->items_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "items_count", *packing_queue_item->items_count) == NULL) {
    goto fail; //Numeric
    }


    // packing_queue_item->label_printed
    if (!packing_queue_item->label_printed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "label_printed", *packing_queue_item->label_printed) == NULL) {
    goto fail; //Bool
    }


    // packing_queue_item->order_number
    if (!packing_queue_item->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_number", packing_queue_item->order_number) == NULL) {
    goto fail; //String
    }


    // packing_queue_item->order_status
    if (!packing_queue_item->order_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_status", packing_queue_item->order_status) == NULL) {
    goto fail; //String
    }


    // packing_queue_item->shipment_id
    if(packing_queue_item->shipment_id) {
    if(cJSON_AddStringToObject(item, "shipment_id", packing_queue_item->shipment_id) == NULL) {
    goto fail; //String
    }
    }


    // packing_queue_item->shipping_address
    if(packing_queue_item->shipping_address) {
    cJSON *shipping_address_local_JSON = _convertToJSON(packing_queue_item->shipping_address);
    if(shipping_address_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "shipping_address", shipping_address_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // packing_queue_item->shipping_method
    if (!packing_queue_item->shipping_method) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shipping_method", packing_queue_item->shipping_method) == NULL) {
    goto fail; //String
    }


    // packing_queue_item->tracking_number
    if(packing_queue_item->tracking_number) {
    if(cJSON_AddStringToObject(item, "tracking_number", packing_queue_item->tracking_number) == NULL) {
    goto fail; //String
    }
    }


    // packing_queue_item->video_recording
    if(packing_queue_item->video_recording) {
    if(cJSON_AddStringToObject(item, "video_recording", packing_queue_item->video_recording) == NULL) {
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

packing_queue_item_t *packing_queue_item_parseFromJSON(cJSON *packing_queue_itemJSON){

    packing_queue_item_t *packing_queue_item_local_var = NULL;

    char *created_at_local_str = NULL;

    char *customer_id_local_str = NULL;

    // define the local variable for packing_queue_item->delivery_note_printed
    int *delivery_note_printed_local_var = NULL;

    // define the local variable for packing_queue_item->items
    _t *items_local_nonprim = NULL;

    // define the local variable for packing_queue_item->items_count
    int *items_count_local_var = NULL;

    // define the local variable for packing_queue_item->label_printed
    int *label_printed_local_var = NULL;

    char *order_number_local_str = NULL;

    char *order_status_local_str = NULL;

    char *shipment_id_local_str = NULL;

    // define the local variable for packing_queue_item->shipping_address
    _t *shipping_address_local_nonprim = NULL;

    char *shipping_method_local_str = NULL;

    char *tracking_number_local_str = NULL;

    char *video_recording_local_str = NULL;

    // packing_queue_item->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // packing_queue_item->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "customer_id");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (!customer_id) {
        goto end;
    }

    
    if(!cJSON_IsString(customer_id))
    {
    goto end; //String
    }

    // packing_queue_item->delivery_note_printed
    cJSON *delivery_note_printed = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "delivery_note_printed");
    if (cJSON_IsNull(delivery_note_printed)) {
        delivery_note_printed = NULL;
    }
    if (!delivery_note_printed) {
        goto end;
    }

    
    if(!cJSON_IsBool(delivery_note_printed))
    {
    goto end; //Bool
    }
    delivery_note_printed_local_var = malloc(sizeof(int));
    if(!delivery_note_printed_local_var)
    {
        goto end;
    }
    *delivery_note_printed_local_var = delivery_note_printed->valueint;

    // packing_queue_item->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    items_local_nonprim = _parseFromJSON(items); //custom

    // packing_queue_item->items_count
    cJSON *items_count = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "items_count");
    if (cJSON_IsNull(items_count)) {
        items_count = NULL;
    }
    if (!items_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_count))
    {
    goto end; //Numeric
    }
    items_count_local_var = malloc(sizeof(int));
    if(!items_count_local_var)
    {
        goto end;
    }
    *items_count_local_var = items_count->valuedouble;

    // packing_queue_item->label_printed
    cJSON *label_printed = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "label_printed");
    if (cJSON_IsNull(label_printed)) {
        label_printed = NULL;
    }
    if (!label_printed) {
        goto end;
    }

    
    if(!cJSON_IsBool(label_printed))
    {
    goto end; //Bool
    }
    label_printed_local_var = malloc(sizeof(int));
    if(!label_printed_local_var)
    {
        goto end;
    }
    *label_printed_local_var = label_printed->valueint;

    // packing_queue_item->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "order_number");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }

    // packing_queue_item->order_status
    cJSON *order_status = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "order_status");
    if (cJSON_IsNull(order_status)) {
        order_status = NULL;
    }
    if (!order_status) {
        goto end;
    }

    
    if(!cJSON_IsString(order_status))
    {
    goto end; //String
    }

    // packing_queue_item->shipment_id
    cJSON *shipment_id = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "shipment_id");
    if (cJSON_IsNull(shipment_id)) {
        shipment_id = NULL;
    }
    if (shipment_id) { 
    if(!cJSON_IsString(shipment_id) && !cJSON_IsNull(shipment_id))
    {
    goto end; //String
    }
    }

    // packing_queue_item->shipping_address
    cJSON *shipping_address = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "shipping_address");
    if (cJSON_IsNull(shipping_address)) {
        shipping_address = NULL;
    }
    if (shipping_address) { 
    shipping_address_local_nonprim = _parseFromJSON(shipping_address); //custom
    }

    // packing_queue_item->shipping_method
    cJSON *shipping_method = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "shipping_method");
    if (cJSON_IsNull(shipping_method)) {
        shipping_method = NULL;
    }
    if (!shipping_method) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_method))
    {
    goto end; //String
    }

    // packing_queue_item->tracking_number
    cJSON *tracking_number = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "tracking_number");
    if (cJSON_IsNull(tracking_number)) {
        tracking_number = NULL;
    }
    if (tracking_number) { 
    if(!cJSON_IsString(tracking_number) && !cJSON_IsNull(tracking_number))
    {
    goto end; //String
    }
    }

    // packing_queue_item->video_recording
    cJSON *video_recording = cJSON_GetObjectItemCaseSensitive(packing_queue_itemJSON, "video_recording");
    if (cJSON_IsNull(video_recording)) {
        video_recording = NULL;
    }
    if (video_recording) { 
    if(!cJSON_IsString(video_recording) && !cJSON_IsNull(video_recording))
    {
    goto end; //String
    }
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (order_status && !cJSON_IsNull(order_status)) order_status_local_str = strdup(order_status->valuestring);
    if (shipment_id && !cJSON_IsNull(shipment_id)) shipment_id_local_str = strdup(shipment_id->valuestring);
    if (shipping_method && !cJSON_IsNull(shipping_method)) shipping_method_local_str = strdup(shipping_method->valuestring);
    if (tracking_number && !cJSON_IsNull(tracking_number)) tracking_number_local_str = strdup(tracking_number->valuestring);
    if (video_recording && !cJSON_IsNull(video_recording)) video_recording_local_str = strdup(video_recording->valuestring);

    packing_queue_item_local_var = packing_queue_item_create_internal (
        created_at_local_str,
        customer_id_local_str,
        delivery_note_printed_local_var,
        items_local_nonprim,
        items_count_local_var,
        label_printed_local_var,
        order_number_local_str,
        order_status_local_str,
        shipment_id_local_str,
        shipping_address ? shipping_address_local_nonprim : NULL,
        shipping_method_local_str,
        tracking_number_local_str,
        video_recording_local_str
        );

    if (!packing_queue_item_local_var) {
        goto end;
    }

    return packing_queue_item_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (delivery_note_printed_local_var) {
        free(delivery_note_printed_local_var);
        delivery_note_printed_local_var = NULL;
    }
    if (items_local_nonprim) {
        _free(items_local_nonprim);
        items_local_nonprim = NULL;
    }
    if (items_count_local_var) {
        free(items_count_local_var);
        items_count_local_var = NULL;
    }
    if (label_printed_local_var) {
        free(label_printed_local_var);
        label_printed_local_var = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (order_status_local_str) {
        free(order_status_local_str);
        order_status_local_str = NULL;
    }
    if (shipment_id_local_str) {
        free(shipment_id_local_str);
        shipment_id_local_str = NULL;
    }
    if (shipping_address_local_nonprim) {
        _free(shipping_address_local_nonprim);
        shipping_address_local_nonprim = NULL;
    }
    if (shipping_method_local_str) {
        free(shipping_method_local_str);
        shipping_method_local_str = NULL;
    }
    if (tracking_number_local_str) {
        free(tracking_number_local_str);
        tracking_number_local_str = NULL;
    }
    if (video_recording_local_str) {
        free(video_recording_local_str);
        video_recording_local_str = NULL;
    }
    return NULL;

}
