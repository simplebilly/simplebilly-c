#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "public_delivery_appointment_response.h"



static public_delivery_appointment_response_t *public_delivery_appointment_response_create_internal(
    char *appointment_id,
    char *confirmation_hint,
    char *message,
    char *status
    ) {
    public_delivery_appointment_response_t *public_delivery_appointment_response_local_var = malloc(sizeof(public_delivery_appointment_response_t));
    if (!public_delivery_appointment_response_local_var) {
        return NULL;
    }
    memset(public_delivery_appointment_response_local_var, 0, sizeof(public_delivery_appointment_response_t));
    public_delivery_appointment_response_local_var->_library_owned = 1;
    public_delivery_appointment_response_local_var->appointment_id = appointment_id;
    public_delivery_appointment_response_local_var->confirmation_hint = confirmation_hint;
    public_delivery_appointment_response_local_var->message = message;
    public_delivery_appointment_response_local_var->status = status;
    return public_delivery_appointment_response_local_var;
}

__attribute__((deprecated)) public_delivery_appointment_response_t *public_delivery_appointment_response_create(
    char *appointment_id,
    char *confirmation_hint,
    char *message,
    char *status
    ) {
    public_delivery_appointment_response_t *result = public_delivery_appointment_response_create_internal (
        appointment_id,
        confirmation_hint,
        message,
        status
        );
    if (!result) {
    }
    return result;
}

void public_delivery_appointment_response_free(public_delivery_appointment_response_t *public_delivery_appointment_response) {
    if(NULL == public_delivery_appointment_response){
        return ;
    }
    if(public_delivery_appointment_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "public_delivery_appointment_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (public_delivery_appointment_response->appointment_id) {
        free(public_delivery_appointment_response->appointment_id);
        public_delivery_appointment_response->appointment_id = NULL;
    }
    if (public_delivery_appointment_response->confirmation_hint) {
        free(public_delivery_appointment_response->confirmation_hint);
        public_delivery_appointment_response->confirmation_hint = NULL;
    }
    if (public_delivery_appointment_response->message) {
        free(public_delivery_appointment_response->message);
        public_delivery_appointment_response->message = NULL;
    }
    if (public_delivery_appointment_response->status) {
        free(public_delivery_appointment_response->status);
        public_delivery_appointment_response->status = NULL;
    }
    free(public_delivery_appointment_response);
}

cJSON *public_delivery_appointment_response_convertToJSON(public_delivery_appointment_response_t *public_delivery_appointment_response) {
    cJSON *item = cJSON_CreateObject();

    // public_delivery_appointment_response->appointment_id
    if (!public_delivery_appointment_response->appointment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "appointmentId", public_delivery_appointment_response->appointment_id) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_response->confirmation_hint
    if (!public_delivery_appointment_response->confirmation_hint) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "confirmationHint", public_delivery_appointment_response->confirmation_hint) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_response->message
    if (!public_delivery_appointment_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", public_delivery_appointment_response->message) == NULL) {
    goto fail; //String
    }


    // public_delivery_appointment_response->status
    if (!public_delivery_appointment_response->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", public_delivery_appointment_response->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

public_delivery_appointment_response_t *public_delivery_appointment_response_parseFromJSON(cJSON *public_delivery_appointment_responseJSON){

    public_delivery_appointment_response_t *public_delivery_appointment_response_local_var = NULL;

    char *appointment_id_local_str = NULL;

    char *confirmation_hint_local_str = NULL;

    char *message_local_str = NULL;

    char *status_local_str = NULL;

    // public_delivery_appointment_response->appointment_id
    cJSON *appointment_id = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_responseJSON, "appointmentId");
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

    // public_delivery_appointment_response->confirmation_hint
    cJSON *confirmation_hint = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_responseJSON, "confirmationHint");
    if (cJSON_IsNull(confirmation_hint)) {
        confirmation_hint = NULL;
    }
    if (!confirmation_hint) {
        goto end;
    }

    
    if(!cJSON_IsString(confirmation_hint))
    {
    goto end; //String
    }

    // public_delivery_appointment_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_responseJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // public_delivery_appointment_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(public_delivery_appointment_responseJSON, "status");
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


    if (appointment_id && !cJSON_IsNull(appointment_id)) appointment_id_local_str = strdup(appointment_id->valuestring);
    if (confirmation_hint && !cJSON_IsNull(confirmation_hint)) confirmation_hint_local_str = strdup(confirmation_hint->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    public_delivery_appointment_response_local_var = public_delivery_appointment_response_create_internal (
        appointment_id_local_str,
        confirmation_hint_local_str,
        message_local_str,
        status_local_str
        );

    if (!public_delivery_appointment_response_local_var) {
        goto end;
    }

    return public_delivery_appointment_response_local_var;
end:
    if (appointment_id_local_str) {
        free(appointment_id_local_str);
        appointment_id_local_str = NULL;
    }
    if (confirmation_hint_local_str) {
        free(confirmation_hint_local_str);
        confirmation_hint_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
