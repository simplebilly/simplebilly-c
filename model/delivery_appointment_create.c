#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_appointment_create.h"



static delivery_appointment_create_t *delivery_appointment_create_create_internal(
    char *email,
    char *notes,
    char *phone,
    char *requested_date,
    delivery_appointment_status_t *status,
    char *supplier_name,
    char *time_slot,
    char *warehouse_id
    ) {
    delivery_appointment_create_t *delivery_appointment_create_local_var = malloc(sizeof(delivery_appointment_create_t));
    if (!delivery_appointment_create_local_var) {
        return NULL;
    }
    memset(delivery_appointment_create_local_var, 0, sizeof(delivery_appointment_create_t));
    delivery_appointment_create_local_var->_library_owned = 1;
    delivery_appointment_create_local_var->email = email;
    delivery_appointment_create_local_var->notes = notes;
    delivery_appointment_create_local_var->phone = phone;
    delivery_appointment_create_local_var->requested_date = requested_date;
    delivery_appointment_create_local_var->status = status;
    delivery_appointment_create_local_var->supplier_name = supplier_name;
    delivery_appointment_create_local_var->time_slot = time_slot;
    delivery_appointment_create_local_var->warehouse_id = warehouse_id;
    return delivery_appointment_create_local_var;
}

__attribute__((deprecated)) delivery_appointment_create_t *delivery_appointment_create_create(
    char *email,
    char *notes,
    char *phone,
    char *requested_date,
    delivery_appointment_status_t *status,
    char *supplier_name,
    char *time_slot,
    char *warehouse_id
    ) {
    delivery_appointment_create_t *result = delivery_appointment_create_create_internal (
        email,
        notes,
        phone,
        requested_date,
        status,
        supplier_name,
        time_slot,
        warehouse_id
        );
    if (!result) {
    }
    return result;
}

void delivery_appointment_create_free(delivery_appointment_create_t *delivery_appointment_create) {
    if(NULL == delivery_appointment_create){
        return ;
    }
    if(delivery_appointment_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_appointment_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_appointment_create->email) {
        free(delivery_appointment_create->email);
        delivery_appointment_create->email = NULL;
    }
    if (delivery_appointment_create->notes) {
        free(delivery_appointment_create->notes);
        delivery_appointment_create->notes = NULL;
    }
    if (delivery_appointment_create->phone) {
        free(delivery_appointment_create->phone);
        delivery_appointment_create->phone = NULL;
    }
    if (delivery_appointment_create->requested_date) {
        free(delivery_appointment_create->requested_date);
        delivery_appointment_create->requested_date = NULL;
    }
    if (delivery_appointment_create->status) {
        delivery_appointment_status_free(delivery_appointment_create->status);
        delivery_appointment_create->status = NULL;
    }
    if (delivery_appointment_create->supplier_name) {
        free(delivery_appointment_create->supplier_name);
        delivery_appointment_create->supplier_name = NULL;
    }
    if (delivery_appointment_create->time_slot) {
        free(delivery_appointment_create->time_slot);
        delivery_appointment_create->time_slot = NULL;
    }
    if (delivery_appointment_create->warehouse_id) {
        free(delivery_appointment_create->warehouse_id);
        delivery_appointment_create->warehouse_id = NULL;
    }
    free(delivery_appointment_create);
}

cJSON *delivery_appointment_create_convertToJSON(delivery_appointment_create_t *delivery_appointment_create) {
    cJSON *item = cJSON_CreateObject();

    // delivery_appointment_create->email
    if (!delivery_appointment_create->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", delivery_appointment_create->email) == NULL) {
    goto fail; //String
    }


    // delivery_appointment_create->notes
    if(delivery_appointment_create->notes) {
    if(cJSON_AddStringToObject(item, "notes", delivery_appointment_create->notes) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment_create->phone
    if(delivery_appointment_create->phone) {
    if(cJSON_AddStringToObject(item, "phone", delivery_appointment_create->phone) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment_create->requested_date
    if (!delivery_appointment_create->requested_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestedDate", delivery_appointment_create->requested_date) == NULL) {
    goto fail; //Date
    }


    // delivery_appointment_create->status
    if (!delivery_appointment_create->status) {
        goto fail;
    }
    cJSON *status_local_JSON = delivery_appointment_status_convertToJSON(delivery_appointment_create->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // delivery_appointment_create->supplier_name
    if (!delivery_appointment_create->supplier_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supplierName", delivery_appointment_create->supplier_name) == NULL) {
    goto fail; //String
    }


    // delivery_appointment_create->time_slot
    if(delivery_appointment_create->time_slot) {
    if(cJSON_AddStringToObject(item, "timeSlot", delivery_appointment_create->time_slot) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment_create->warehouse_id
    if (!delivery_appointment_create->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", delivery_appointment_create->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delivery_appointment_create_t *delivery_appointment_create_parseFromJSON(cJSON *delivery_appointment_createJSON){

    delivery_appointment_create_t *delivery_appointment_create_local_var = NULL;

    char *email_local_str = NULL;

    char *notes_local_str = NULL;

    char *phone_local_str = NULL;

    char *requested_date_local_str = NULL;

    // define the local variable for delivery_appointment_create->status
    delivery_appointment_status_t *status_local_nonprim = NULL;

    char *supplier_name_local_str = NULL;

    char *time_slot_local_str = NULL;

    char *warehouse_id_local_str = NULL;

    // delivery_appointment_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // delivery_appointment_create->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // delivery_appointment_create->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // delivery_appointment_create->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "requestedDate");
    if (cJSON_IsNull(requested_date)) {
        requested_date = NULL;
    }
    if (!requested_date) {
        goto end;
    }

    
    if(!cJSON_IsString(requested_date))
    {
    goto end; //Date
    }

    // delivery_appointment_create->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = delivery_appointment_status_parseFromJSON(status); //custom

    // delivery_appointment_create->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "supplierName");
    if (cJSON_IsNull(supplier_name)) {
        supplier_name = NULL;
    }
    if (!supplier_name) {
        goto end;
    }

    
    if(!cJSON_IsString(supplier_name))
    {
    goto end; //String
    }

    // delivery_appointment_create->time_slot
    cJSON *time_slot = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "timeSlot");
    if (cJSON_IsNull(time_slot)) {
        time_slot = NULL;
    }
    if (time_slot) { 
    if(!cJSON_IsString(time_slot) && !cJSON_IsNull(time_slot))
    {
    goto end; //String
    }
    }

    // delivery_appointment_create->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(delivery_appointment_createJSON, "warehouseId");
    if (cJSON_IsNull(warehouse_id)) {
        warehouse_id = NULL;
    }
    if (!warehouse_id) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_id))
    {
    goto end; //String
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (phone && !cJSON_IsNull(phone)) phone_local_str = strdup(phone->valuestring);
    if (requested_date) requested_date_local_str = strdup(requested_date->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);
    if (time_slot && !cJSON_IsNull(time_slot)) time_slot_local_str = strdup(time_slot->valuestring);
    if (warehouse_id && !cJSON_IsNull(warehouse_id)) warehouse_id_local_str = strdup(warehouse_id->valuestring);

    delivery_appointment_create_local_var = delivery_appointment_create_create_internal (
        email_local_str,
        notes_local_str,
        phone_local_str,
        requested_date_local_str,
        status_local_nonprim,
        supplier_name_local_str,
        time_slot_local_str,
        warehouse_id_local_str
        );

    if (!delivery_appointment_create_local_var) {
        goto end;
    }

    return delivery_appointment_create_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (phone_local_str) {
        free(phone_local_str);
        phone_local_str = NULL;
    }
    if (requested_date_local_str) {
        free(requested_date_local_str);
        requested_date_local_str = NULL;
    }
    if (status_local_nonprim) {
        delivery_appointment_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (supplier_name_local_str) {
        free(supplier_name_local_str);
        supplier_name_local_str = NULL;
    }
    if (time_slot_local_str) {
        free(time_slot_local_str);
        time_slot_local_str = NULL;
    }
    if (warehouse_id_local_str) {
        free(warehouse_id_local_str);
        warehouse_id_local_str = NULL;
    }
    return NULL;

}
