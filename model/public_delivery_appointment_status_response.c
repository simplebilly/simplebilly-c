#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_delivery_appointment_status_response.h"



static public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_create_internal(
    char *appointment_id,
    char *requested_date,
    char *status,
    char *time_slot,
    char *warehouse_name
    ) {
    public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_local_var = malloc(sizeof(public_delivery_appointment_status_response_t));
    if (!public_delivery_appointment_status_response_local_var) {
        return NULL;
    }
    memset(public_delivery_appointment_status_response_local_var, 0, sizeof(public_delivery_appointment_status_response_t));
    public_delivery_appointment_status_response_local_var->_library_owned = 1;
    public_delivery_appointment_status_response_local_var->appointment_id = appointment_id;
    public_delivery_appointment_status_response_local_var->requested_date = requested_date;
    public_delivery_appointment_status_response_local_var->status = status;
    public_delivery_appointment_status_response_local_var->time_slot = time_slot;
    public_delivery_appointment_status_response_local_var->warehouse_name = warehouse_name;
    return public_delivery_appointment_status_response_local_var;
}

__attribute__((deprecated)) public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_create(
    char *appointment_id,
    char *requested_date,
    char *status,
    char *time_slot,
    char *warehouse_name
    ) {
    public_delivery_appointment_status_response_t *result = public_delivery_appointment_status_response_create_internal (
        appointment_id,
        requested_date,
        status,
        time_slot,
        warehouse_name
        );
    if (!result) {
    }
    return result;
}

void public_delivery_appointment_status_response_free(public_delivery_appointment_status_response_t *public_delivery_appointment_status_response) {
    if(NULL == public_delivery_appointment_status_response){
        return ;
    }
    if(public_delivery_appointment_status_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_delivery_appointment_status_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_delivery_appointment_status_response->appointment_id) {
        free(public_delivery_appointment_status_response->appointment_id);
        public_delivery_appointment_status_response->appointment_id = NULL;
    }
    if (public_delivery_appointment_status_response->requested_date) {
        free(public_delivery_appointment_status_response->requested_date);
        public_delivery_appointment_status_response->requested_date = NULL;
    }
    if (public_delivery_appointment_status_response->status) {
        free(public_delivery_appointment_status_response->status);
        public_delivery_appointment_status_response->status = NULL;
    }
    if (public_delivery_appointment_status_response->time_slot) {
        free(public_delivery_appointment_status_response->time_slot);
        public_delivery_appointment_status_response->time_slot = NULL;
    }
    if (public_delivery_appointment_status_response->warehouse_name) {
        free(public_delivery_appointment_status_response->warehouse_name);
        public_delivery_appointment_status_response->warehouse_name = NULL;
    }
    free(public_delivery_appointment_status_response);
}

cJSON *public_delivery_appointment_status_response_convertToJSON(public_delivery_appointment_status_response_t *public_delivery_appointment_status_response) {
    cJSON *item = cJSON_CreateObject();

    // public_delivery_appointment_status_response->appointment_id
    if (!public_delivery_appointment_status_response->appointment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "appointmentId", public_delivery_appointment_status_response->appointment_id) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_status_response->requested_date
    if (!public_delivery_appointment_status_response->requested_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestedDate", public_delivery_appointment_status_response->requested_date) == NULL) {
    goto fail; //Date
    }


    // public_delivery_appointment_status_response->status
    if (!public_delivery_appointment_status_response->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", public_delivery_appointment_status_response->status) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_status_response->time_slot
    if(public_delivery_appointment_status_response->time_slot) {
    if(cJSON_AddStringToObject(item, "timeSlot", public_delivery_appointment_status_response->time_slot) == NULL) {
    goto fail; //String
    }
    }


    // public_delivery_appointment_status_response->warehouse_name
    if (!public_delivery_appointment_status_response->warehouse_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseName", public_delivery_appointment_status_response->warehouse_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_parseFromJSON(cJSON *public_delivery_appointment_status_responseJSON){

    public_delivery_appointment_status_response_t *public_delivery_appointment_status_response_local_var = NULL;

    char *appointment_id_local_str = NULL;

    char *requested_date_local_str = NULL;

    char *status_local_str = NULL;

    char *time_slot_local_str = NULL;

    char *warehouse_name_local_str = NULL;

    // public_delivery_appointment_status_response->appointment_id
    cJSON *appointment_id = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_status_responseJSON, "appointmentId");
    if (cJSON_IsNull(appointment_id)) {
        appointment_id = NULL;
    }
    if (!appointment_id) {
        goto end;
    }

    
    if(!cJSON_IsString(appointment_id))
    {
    goto end; //String
    }

    // public_delivery_appointment_status_response->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_status_responseJSON, "requestedDate");
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

    // public_delivery_appointment_status_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_status_responseJSON, "status");
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

    // public_delivery_appointment_status_response->time_slot
    cJSON *time_slot = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_status_responseJSON, "timeSlot");
    if (cJSON_IsNull(time_slot)) {
        time_slot = NULL;
    }
    if (time_slot) { 
    if(!cJSON_IsString(time_slot) && !cJSON_IsNull(time_slot))
    {
    goto end; //String
    }
    }

    // public_delivery_appointment_status_response->warehouse_name
    cJSON *warehouse_name = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_status_responseJSON, "warehouseName");
    if (cJSON_IsNull(warehouse_name)) {
        warehouse_name = NULL;
    }
    if (!warehouse_name) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_name))
    {
    goto end; //String
    }


    if (appointment_id && !cJSON_IsNull(appointment_id)) appointment_id_local_str = strdup(appointment_id->valuestring);
    if (requested_date) requested_date_local_str = strdup(requested_date->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (time_slot && !cJSON_IsNull(time_slot)) time_slot_local_str = strdup(time_slot->valuestring);
    if (warehouse_name && !cJSON_IsNull(warehouse_name)) warehouse_name_local_str = strdup(warehouse_name->valuestring);

    public_delivery_appointment_status_response_local_var = public_delivery_appointment_status_response_create_internal (
        appointment_id_local_str,
        requested_date_local_str,
        status_local_str,
        time_slot_local_str,
        warehouse_name_local_str
        );

    if (!public_delivery_appointment_status_response_local_var) {
        goto end;
    }

    return public_delivery_appointment_status_response_local_var;
end:
    if (appointment_id_local_str) {
        free(appointment_id_local_str);
        appointment_id_local_str = NULL;
    }
    if (requested_date_local_str) {
        free(requested_date_local_str);
        requested_date_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (time_slot_local_str) {
        free(time_slot_local_str);
        time_slot_local_str = NULL;
    }
    if (warehouse_name_local_str) {
        free(warehouse_name_local_str);
        warehouse_name_local_str = NULL;
    }
    return NULL;

}
