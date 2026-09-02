#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "appointment_status_update.h"



static appointment_status_update_t *appointment_status_update_create_internal(
    char *status
    ) {
    appointment_status_update_t *appointment_status_update_local_var = malloc(sizeof(appointment_status_update_t));
    if (!appointment_status_update_local_var) {
        return NULL;
    }
    memset(appointment_status_update_local_var, 0, sizeof(appointment_status_update_t));
    appointment_status_update_local_var->_library_owned = 1;
    appointment_status_update_local_var->status = status;
    return appointment_status_update_local_var;
}

__attribute__((deprecated)) appointment_status_update_t *appointment_status_update_create(
    char *status
    ) {
    appointment_status_update_t *result = appointment_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void appointment_status_update_free(appointment_status_update_t *appointment_status_update) {
    if(NULL == appointment_status_update){
        return ;
    }
    if(appointment_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "appointment_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (appointment_status_update->status) {
        free(appointment_status_update->status);
        appointment_status_update->status = NULL;
    }
    free(appointment_status_update);
}

cJSON *appointment_status_update_convertToJSON(appointment_status_update_t *appointment_status_update) {
    cJSON *item = cJSON_CreateObject();

    // appointment_status_update->status
    if (!appointment_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", appointment_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

appointment_status_update_t *appointment_status_update_parseFromJSON(cJSON *appointment_status_updateJSON){

    appointment_status_update_t *appointment_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // appointment_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(appointment_status_updateJSON, "status");
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


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    appointment_status_update_local_var = appointment_status_update_create_internal (
        status_local_str
        );

    if (!appointment_status_update_local_var) {
        goto end;
    }

    return appointment_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
