#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_delivery_appointment_request.h"



static public_delivery_appointment_request_t *public_delivery_appointment_request_create_internal(
    char *email,
    char *notes,
    char *requested_date,
    char *supplier_name,
    char *time_slot,
    char *warehouse_code
    ) {
    public_delivery_appointment_request_t *public_delivery_appointment_request_local_var = malloc(sizeof(public_delivery_appointment_request_t));
    if (!public_delivery_appointment_request_local_var) {
        return NULL;
    }
    memset(public_delivery_appointment_request_local_var, 0, sizeof(public_delivery_appointment_request_t));
    public_delivery_appointment_request_local_var->_library_owned = 1;
    public_delivery_appointment_request_local_var->email = email;
    public_delivery_appointment_request_local_var->notes = notes;
    public_delivery_appointment_request_local_var->requested_date = requested_date;
    public_delivery_appointment_request_local_var->supplier_name = supplier_name;
    public_delivery_appointment_request_local_var->time_slot = time_slot;
    public_delivery_appointment_request_local_var->warehouse_code = warehouse_code;
    return public_delivery_appointment_request_local_var;
}

__attribute__((deprecated)) public_delivery_appointment_request_t *public_delivery_appointment_request_create(
    char *email,
    char *notes,
    char *requested_date,
    char *supplier_name,
    char *time_slot,
    char *warehouse_code
    ) {
    public_delivery_appointment_request_t *result = public_delivery_appointment_request_create_internal (
        email,
        notes,
        requested_date,
        supplier_name,
        time_slot,
        warehouse_code
        );
    if (!result) {
    }
    return result;
}

void public_delivery_appointment_request_free(public_delivery_appointment_request_t *public_delivery_appointment_request) {
    if(NULL == public_delivery_appointment_request){
        return ;
    }
    if(public_delivery_appointment_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_delivery_appointment_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_delivery_appointment_request->email) {
        free(public_delivery_appointment_request->email);
        public_delivery_appointment_request->email = NULL;
    }
    if (public_delivery_appointment_request->notes) {
        free(public_delivery_appointment_request->notes);
        public_delivery_appointment_request->notes = NULL;
    }
    if (public_delivery_appointment_request->requested_date) {
        free(public_delivery_appointment_request->requested_date);
        public_delivery_appointment_request->requested_date = NULL;
    }
    if (public_delivery_appointment_request->supplier_name) {
        free(public_delivery_appointment_request->supplier_name);
        public_delivery_appointment_request->supplier_name = NULL;
    }
    if (public_delivery_appointment_request->time_slot) {
        free(public_delivery_appointment_request->time_slot);
        public_delivery_appointment_request->time_slot = NULL;
    }
    if (public_delivery_appointment_request->warehouse_code) {
        free(public_delivery_appointment_request->warehouse_code);
        public_delivery_appointment_request->warehouse_code = NULL;
    }
    free(public_delivery_appointment_request);
}

cJSON *public_delivery_appointment_request_convertToJSON(public_delivery_appointment_request_t *public_delivery_appointment_request) {
    cJSON *item = cJSON_CreateObject();

    // public_delivery_appointment_request->email
    if (!public_delivery_appointment_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", public_delivery_appointment_request->email) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_request->notes
    if(public_delivery_appointment_request->notes) {
    if(cJSON_AddStringToObject(item, "notes", public_delivery_appointment_request->notes) == NULL) {
    goto fail; //String
    }
    }


    // public_delivery_appointment_request->requested_date
    if (!public_delivery_appointment_request->requested_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "requestedDate", public_delivery_appointment_request->requested_date) == NULL) {
    goto fail; //Date
    }


    // public_delivery_appointment_request->supplier_name
    if (!public_delivery_appointment_request->supplier_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supplierName", public_delivery_appointment_request->supplier_name) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_request->time_slot
    if(public_delivery_appointment_request->time_slot) {
    if(cJSON_AddStringToObject(item, "timeSlot", public_delivery_appointment_request->time_slot) == NULL) {
    goto fail; //String
    }
    }


    // public_delivery_appointment_request->warehouse_code
    if (!public_delivery_appointment_request->warehouse_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warehouseCode", public_delivery_appointment_request->warehouse_code) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_delivery_appointment_request_t *public_delivery_appointment_request_parseFromJSON(cJSON *public_delivery_appointment_requestJSON){

    public_delivery_appointment_request_t *public_delivery_appointment_request_local_var = NULL;

    char *email_local_str = NULL;

    char *notes_local_str = NULL;

    char *requested_date_local_str = NULL;

    char *supplier_name_local_str = NULL;

    char *time_slot_local_str = NULL;

    char *warehouse_code_local_str = NULL;

    // public_delivery_appointment_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "email");
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

    // public_delivery_appointment_request->notes
    cJSON *notes = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "notes");
    if (cJSON_IsNull(notes)) {
        notes = NULL;
    }
    if (notes) { 
    if(!cJSON_IsString(notes) && !cJSON_IsNull(notes))
    {
    goto end; //String
    }
    }

    // public_delivery_appointment_request->requested_date
    cJSON *requested_date = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "requestedDate");
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

    // public_delivery_appointment_request->supplier_name
    cJSON *supplier_name = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "supplierName");
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

    // public_delivery_appointment_request->time_slot
    cJSON *time_slot = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "timeSlot");
    if (cJSON_IsNull(time_slot)) {
        time_slot = NULL;
    }
    if (time_slot) { 
    if(!cJSON_IsString(time_slot) && !cJSON_IsNull(time_slot))
    {
    goto end; //String
    }
    }

    // public_delivery_appointment_request->warehouse_code
    cJSON *warehouse_code = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_requestJSON, "warehouseCode");
    if (cJSON_IsNull(warehouse_code)) {
        warehouse_code = NULL;
    }
    if (!warehouse_code) {
        goto end;
    }

    
    if(!cJSON_IsString(warehouse_code))
    {
    goto end; //String
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (notes && !cJSON_IsNull(notes)) notes_local_str = strdup(notes->valuestring);
    if (requested_date) requested_date_local_str = strdup(requested_date->valuestring);
    if (supplier_name && !cJSON_IsNull(supplier_name)) supplier_name_local_str = strdup(supplier_name->valuestring);
    if (time_slot && !cJSON_IsNull(time_slot)) time_slot_local_str = strdup(time_slot->valuestring);
    if (warehouse_code && !cJSON_IsNull(warehouse_code)) warehouse_code_local_str = strdup(warehouse_code->valuestring);

    public_delivery_appointment_request_local_var = public_delivery_appointment_request_create_internal (
        email_local_str,
        notes_local_str,
        requested_date_local_str,
        supplier_name_local_str,
        time_slot_local_str,
        warehouse_code_local_str
        );

    if (!public_delivery_appointment_request_local_var) {
        goto end;
    }

    return public_delivery_appointment_request_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (notes_local_str) {
        free(notes_local_str);
        notes_local_str = NULL;
    }
    if (requested_date_local_str) {
        free(requested_date_local_str);
        requested_date_local_str = NULL;
    }
    if (supplier_name_local_str) {
        free(supplier_name_local_str);
        supplier_name_local_str = NULL;
    }
    if (time_slot_local_str) {
        free(time_slot_local_str);
        time_slot_local_str = NULL;
    }
    if (warehouse_code_local_str) {
        free(warehouse_code_local_str);
        warehouse_code_local_str = NULL;
    }
    return NULL;

}
