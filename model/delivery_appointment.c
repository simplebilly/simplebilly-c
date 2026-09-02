#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_appointment.h"



static delivery_appointment_t *delivery_appointment_create_internal(
    char *email,
    char *notes,
    char *phone,
    char *requested_date,
    delivery_appointment_status_t *status,
    char *supplier_name,
    char *time_slot,
    char *warehouse_id
    ) {
    delivery_appointment_t *delivery_appointment_local_var = malloc(sizeof(delivery_appointment_t));
    if (!delivery_appointment_local_var) {
        return NULL;
    }
    memset(delivery_appointment_local_var, 0, sizeof(delivery_appointment_t));
    delivery_appointment_local_var->_library_owned = 1;
    delivery_appointment_local_var->email = email;
    delivery_appointment_local_var->notes = notes;
    delivery_appointment_local_var->phone = phone;
    delivery_appointment_local_var->requested_date = requested_date;
    delivery_appointment_local_var->status = status;
    delivery_appointment_local_var->supplier_name = supplier_name;
    delivery_appointment_local_var->time_slot = time_slot;
    delivery_appointment_local_var->warehouse_id = warehouse_id;
    return delivery_appointment_local_var;
}

__attribute__((deprecated)) delivery_appointment_t *delivery_appointment_create(
    char *email,
    char *notes,
    char *phone,
    char *requested_date,
    delivery_appointment_status_t *status,
    char *supplier_name,
    char *time_slot,
    char *warehouse_id
    ) {
    delivery_appointment_t *result = delivery_appointment_create_internal (
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

void delivery_appointment_free(delivery_appointment_t *delivery_appointment) {
    if(NULL == delivery_appointment){
        return ;
    }
    if(delivery_appointment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_appointment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_appointment->email) {
        free(delivery_appointment->email);
        delivery_appointment->email = NULL;
    }
    if (delivery_appointment->notes) {
        free(delivery_appointment->notes);
        delivery_appointment->notes = NULL;
    }
    if (delivery_appointment->phone) {
        free(delivery_appointment->phone);
        delivery_appointment->phone = NULL;
    }
    if (delivery_appointment->requested_date) {
        free(delivery_appointment->requested_date);
        delivery_appointment->requested_date = NULL;
    }
    if (delivery_appointment->status) {
        delivery_appointment_status_free(delivery_appointment->status);
        delivery_appointment->status = NULL;
    }
    if (delivery_appointment->supplier_name) {
        free(delivery_appointment->supplier_name);
        delivery_appointment->supplier_name = NULL;
    }
    if (delivery_appointment->time_slot) {
        free(delivery_appointment->time_slot);
        delivery_appointment->time_slot = NULL;
    }
    if (delivery_appointment->warehouse_id) {
        free(delivery_appointment->warehouse_id);
        delivery_appointment->warehouse_id = NULL;
    }
    free(delivery_appointment);
}

cJSON *delivery_appointment_convertToJSON(delivery_appointment_t *delivery_appointment) {
    cJSON *item = cJSON_CreateObject();

    // delivery_appointment->email
    if (!delivery_appointment->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", delivery_appointment->email) == NULL) {
    goto fail; //String
    }


    // delivery_appointment->notes
    if(delivery_appointment->notes) {
    if(cJSON_AddStringToObject(item, "notes", delivery_appointment->notes) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment->phone
    if(delivery_appointment->phone) {
    if(cJSON_AddStringToObject(item, "phone", delivery_appointment->phone) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment->requested_date
    if (!delivery_appointment->requested_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestedDate", delivery_appointment->requested_date) == NULL) {
    goto fail; //Date
    }


    // delivery_appointment->status
    if (!delivery_appointment->status) {
        goto fail;
    }
    cJSON *status_local_JSON = delivery_appointment_status_convertToJSON(delivery_appointment->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // delivery_appointment->supplier_name
    if (!delivery_appointment->supplier_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supplierName", delivery_appointment->supplier_name) == NULL) {
    goto fail; //String
    }


    // delivery_appointment->time_slot
    if(delivery_appointment->time_slot) {
    if(cJSON_AddStringToObject(item, "timeSlot", delivery_appointment->time_slot) == NULL) {
    goto fail; //String
    }
    }


    // delivery_appointment->warehouse_id
    if (!delivery_appointment->warehouse_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseId", delivery_appointment->warehouse_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delivery_appointment_t *delivery_appointment_parseFromJSON(cJSON *delivery_appointmentJSON){

    delivery_appointment_t *delivery_appointment_local_var = NULL;

    char *email_local_str = NULL;

    char *notes_local_str = NULL;

    char *phone_local_str = NULL;

    char *requested_date_local_str = NULL;

    // define the local variable for delivery_appointment->status
    delivery_appointment_status_t *status_local_nonprim = NULL;

    char *supplier_name_local_str = NULL;

    char *time_slot_local_str = NULL;

    char *warehouse_id_local_str = NULL;

    // delivery_appointment->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "email");
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

    // delivery_appointment->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // delivery_appointment->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // delivery_appointment->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "requestedDate");
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

    // delivery_appointment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = delivery_appointment_status_parseFromJSON(status); //custom

    // delivery_appointment->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "supplierName");
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

    // delivery_appointment->time_slot
    cJSON *time_slot = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "timeSlot");
    if (cJSON_IsNull(time_slot)) {
        time_slot = NULL;
    }
    if (time_slot) { 
    if(!cJSON_IsString(time_slot) && !cJSON_IsNull(time_slot))
    {
    goto end; //String
    }
    }

    // delivery_appointment->warehouse_id
    cJSON *warehouse_id = cJSON_GetObjectItemCaseSensitive(delivery_appointmentJSON, "warehouseId");
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

    delivery_appointment_local_var = delivery_appointment_create_internal (
        email_local_str,
        notes_local_str,
        phone_local_str,
        requested_date_local_str,
        status_local_nonprim,
        supplier_name_local_str,
        time_slot_local_str,
        warehouse_id_local_str
        );

    if (!delivery_appointment_local_var) {
        goto end;
    }

    return delivery_appointment_local_var;
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
