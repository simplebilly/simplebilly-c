#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_date_update.h"



static delivery_date_update_t *delivery_date_update_create_internal(
    char *customer_id,
    char *fulfilled_date,
    char *note,
    char *order_number,
    char *original_date,
    char *product_id,
    char *promised_date,
    delivery_date_status_t *status
    ) {
    delivery_date_update_t *delivery_date_update_local_var = malloc(sizeof(delivery_date_update_t));
    if (!delivery_date_update_local_var) {
        return NULL;
    }
    memset(delivery_date_update_local_var, 0, sizeof(delivery_date_update_t));
    delivery_date_update_local_var->_library_owned = 1;
    delivery_date_update_local_var->customer_id = customer_id;
    delivery_date_update_local_var->fulfilled_date = fulfilled_date;
    delivery_date_update_local_var->note = note;
    delivery_date_update_local_var->order_number = order_number;
    delivery_date_update_local_var->original_date = original_date;
    delivery_date_update_local_var->product_id = product_id;
    delivery_date_update_local_var->promised_date = promised_date;
    delivery_date_update_local_var->status = status;
    return delivery_date_update_local_var;
}

__attribute__((deprecated)) delivery_date_update_t *delivery_date_update_create(
    char *customer_id,
    char *fulfilled_date,
    char *note,
    char *order_number,
    char *original_date,
    char *product_id,
    char *promised_date,
    delivery_date_status_t *status
    ) {
    delivery_date_update_t *result = delivery_date_update_create_internal (
        customer_id,
        fulfilled_date,
        note,
        order_number,
        original_date,
        product_id,
        promised_date,
        status
        );
    if (!result) {
    }
    return result;
}

void delivery_date_update_free(delivery_date_update_t *delivery_date_update) {
    if(NULL == delivery_date_update){
        return ;
    }
    if(delivery_date_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_date_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_date_update->customer_id) {
        free(delivery_date_update->customer_id);
        delivery_date_update->customer_id = NULL;
    }
    if (delivery_date_update->fulfilled_date) {
        free(delivery_date_update->fulfilled_date);
        delivery_date_update->fulfilled_date = NULL;
    }
    if (delivery_date_update->note) {
        free(delivery_date_update->note);
        delivery_date_update->note = NULL;
    }
    if (delivery_date_update->order_number) {
        free(delivery_date_update->order_number);
        delivery_date_update->order_number = NULL;
    }
    if (delivery_date_update->original_date) {
        free(delivery_date_update->original_date);
        delivery_date_update->original_date = NULL;
    }
    if (delivery_date_update->product_id) {
        free(delivery_date_update->product_id);
        delivery_date_update->product_id = NULL;
    }
    if (delivery_date_update->promised_date) {
        free(delivery_date_update->promised_date);
        delivery_date_update->promised_date = NULL;
    }
    if (delivery_date_update->status) {
        delivery_date_status_free(delivery_date_update->status);
        delivery_date_update->status = NULL;
    }
    free(delivery_date_update);
}

cJSON *delivery_date_update_convertToJSON(delivery_date_update_t *delivery_date_update) {
    cJSON *item = cJSON_CreateObject();

    // delivery_date_update->customer_id
    if(delivery_date_update->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", delivery_date_update->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // delivery_date_update->fulfilled_date
    if(delivery_date_update->fulfilled_date) {
    if(cJSON_AddStringToObject(item, "fulfilledDate", delivery_date_update->fulfilled_date) == NULL) {
    goto fail; //Date
    }
    }


    // delivery_date_update->note
    if(delivery_date_update->note) {
    if(cJSON_AddStringToObject(item, "note", delivery_date_update->note) == NULL) {
    goto fail; //String
    }
    }


    // delivery_date_update->order_number
    if(delivery_date_update->order_number) {
    if(cJSON_AddStringToObject(item, "orderNumber", delivery_date_update->order_number) == NULL) {
    goto fail; //String
    }
    }


    // delivery_date_update->original_date
    if(delivery_date_update->original_date) {
    if(cJSON_AddStringToObject(item, "originalDate", delivery_date_update->original_date) == NULL) {
    goto fail; //Date
    }
    }


    // delivery_date_update->product_id
    if(delivery_date_update->product_id) {
    if(cJSON_AddStringToObject(item, "productId", delivery_date_update->product_id) == NULL) {
    goto fail; //String
    }
    }


    // delivery_date_update->promised_date
    if(delivery_date_update->promised_date) {
    if(cJSON_AddStringToObject(item, "promisedDate", delivery_date_update->promised_date) == NULL) {
    goto fail; //Date
    }
    }


    // delivery_date_update->status
    if(delivery_date_update->status) {
    cJSON *status_local_JSON = delivery_date_status_convertToJSON(delivery_date_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delivery_date_update_t *delivery_date_update_parseFromJSON(cJSON *delivery_date_updateJSON){

    delivery_date_update_t *delivery_date_update_local_var = NULL;

    char *customer_id_local_str = NULL;

    char *fulfilled_date_local_str = NULL;

    char *note_local_str = NULL;

    char *order_number_local_str = NULL;

    char *original_date_local_str = NULL;

    char *product_id_local_str = NULL;

    char *promised_date_local_str = NULL;

    // define the local variable for delivery_date_update->status
    delivery_date_status_t *status_local_nonprim = NULL;

    // delivery_date_update->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // delivery_date_update->fulfilled_date
    cJSON *fulfilled_date = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "fulfilledDate");
    if (cJSON_IsNull(fulfilled_date)) {
        fulfilled_date = NULL;
    }
    if (fulfilled_date) { 
    if(!cJSON_IsString(fulfilled_date))
    {
    goto end; //Date
    }
    }

    // delivery_date_update->note
    cJSON *note = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "note");
    if (cJSON_IsNull(note)) {
        note = NULL;
    }
    if (note) { 
    if(!cJSON_IsString(note) && !cJSON_IsNull(note))
    {
    goto end; //String
    }
    }

    // delivery_date_update->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "orderNumber");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (order_number) { 
    if(!cJSON_IsString(order_number) && !cJSON_IsNull(order_number))
    {
    goto end; //String
    }
    }

    // delivery_date_update->original_date
    cJSON *original_date = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "originalDate");
    if (cJSON_IsNull(original_date)) {
        original_date = NULL;
    }
    if (original_date) { 
    if(!cJSON_IsString(original_date))
    {
    goto end; //Date
    }
    }

    // delivery_date_update->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // delivery_date_update->promised_date
    cJSON *promised_date = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "promisedDate");
    if (cJSON_IsNull(promised_date)) {
        promised_date = NULL;
    }
    if (promised_date) { 
    if(!cJSON_IsString(promised_date))
    {
    goto end; //Date
    }
    }

    // delivery_date_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(delivery_date_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = delivery_date_status_parseFromJSON(status); //custom
    }


    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (fulfilled_date) fulfilled_date_local_str = strdup(fulfilled_date->valuestring);
    if (note && !cJSON_IsNull(note)) note_local_str = strdup(note->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);
    if (original_date) original_date_local_str = strdup(original_date->valuestring);
    if (product_id && !cJSON_IsNull(product_id)) product_id_local_str = strdup(product_id->valuestring);
    if (promised_date) promised_date_local_str = strdup(promised_date->valuestring);

    delivery_date_update_local_var = delivery_date_update_create_internal (
        customer_id_local_str,
        fulfilled_date_local_str,
        note_local_str,
        order_number_local_str,
        original_date_local_str,
        product_id_local_str,
        promised_date_local_str,
        status ? status_local_nonprim : NULL
        );

    if (!delivery_date_update_local_var) {
        goto end;
    }

    return delivery_date_update_local_var;
end:
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (fulfilled_date_local_str) {
        free(fulfilled_date_local_str);
        fulfilled_date_local_str = NULL;
    }
    if (note_local_str) {
        free(note_local_str);
        note_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (original_date_local_str) {
        free(original_date_local_str);
        original_date_local_str = NULL;
    }
    if (product_id_local_str) {
        free(product_id_local_str);
        product_id_local_str = NULL;
    }
    if (promised_date_local_str) {
        free(promised_date_local_str);
        promised_date_local_str = NULL;
    }
    if (status_local_nonprim) {
        delivery_date_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
