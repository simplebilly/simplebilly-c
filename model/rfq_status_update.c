#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rfq_status_update.h"



static rfq_status_update_t *rfq_status_update_create_internal(
    char *status
    ) {
    rfq_status_update_t *rfq_status_update_local_var = malloc(sizeof(rfq_status_update_t));
    if (!rfq_status_update_local_var) {
        return NULL;
    }
    memset(rfq_status_update_local_var, 0, sizeof(rfq_status_update_t));
    rfq_status_update_local_var->_library_owned = 1;
    rfq_status_update_local_var->status = status;
    return rfq_status_update_local_var;
}

__attribute__((deprecated)) rfq_status_update_t *rfq_status_update_create(
    char *status
    ) {
    rfq_status_update_t *result = rfq_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void rfq_status_update_free(rfq_status_update_t *rfq_status_update) {
    if(NULL == rfq_status_update){
        return ;
    }
    if(rfq_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rfq_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rfq_status_update->status) {
        free(rfq_status_update->status);
        rfq_status_update->status = NULL;
    }
    free(rfq_status_update);
}

cJSON *rfq_status_update_convertToJSON(rfq_status_update_t *rfq_status_update) {
    cJSON *item = cJSON_CreateObject();

    // rfq_status_update->status
    if (!rfq_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", rfq_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

rfq_status_update_t *rfq_status_update_parseFromJSON(cJSON *rfq_status_updateJSON){

    rfq_status_update_t *rfq_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // rfq_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(rfq_status_updateJSON, "status");
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

    rfq_status_update_local_var = rfq_status_update_create_internal (
        status_local_str
        );

    if (!rfq_status_update_local_var) {
        goto end;
    }

    return rfq_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
