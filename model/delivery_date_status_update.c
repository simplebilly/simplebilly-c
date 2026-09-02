#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_date_status_update.h"



static delivery_date_status_update_t *delivery_date_status_update_create_internal(
    char *status
    ) {
    delivery_date_status_update_t *delivery_date_status_update_local_var = malloc(sizeof(delivery_date_status_update_t));
    if (!delivery_date_status_update_local_var) {
        return NULL;
    }
    memset(delivery_date_status_update_local_var, 0, sizeof(delivery_date_status_update_t));
    delivery_date_status_update_local_var->_library_owned = 1;
    delivery_date_status_update_local_var->status = status;
    return delivery_date_status_update_local_var;
}

__attribute__((deprecated)) delivery_date_status_update_t *delivery_date_status_update_create(
    char *status
    ) {
    delivery_date_status_update_t *result = delivery_date_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void delivery_date_status_update_free(delivery_date_status_update_t *delivery_date_status_update) {
    if(NULL == delivery_date_status_update){
        return ;
    }
    if(delivery_date_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_date_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_date_status_update->status) {
        free(delivery_date_status_update->status);
        delivery_date_status_update->status = NULL;
    }
    free(delivery_date_status_update);
}

cJSON *delivery_date_status_update_convertToJSON(delivery_date_status_update_t *delivery_date_status_update) {
    cJSON *item = cJSON_CreateObject();

    // delivery_date_status_update->status
    if (!delivery_date_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", delivery_date_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delivery_date_status_update_t *delivery_date_status_update_parseFromJSON(cJSON *delivery_date_status_updateJSON){

    delivery_date_status_update_t *delivery_date_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // delivery_date_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(delivery_date_status_updateJSON, "status");
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

    delivery_date_status_update_local_var = delivery_date_status_update_create_internal (
        status_local_str
        );

    if (!delivery_date_status_update_local_var) {
        goto end;
    }

    return delivery_date_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
