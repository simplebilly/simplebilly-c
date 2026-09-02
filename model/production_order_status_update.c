#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "production_order_status_update.h"



static production_order_status_update_t *production_order_status_update_create_internal(
    char *status
    ) {
    production_order_status_update_t *production_order_status_update_local_var = malloc(sizeof(production_order_status_update_t));
    if (!production_order_status_update_local_var) {
        return NULL;
    }
    memset(production_order_status_update_local_var, 0, sizeof(production_order_status_update_t));
    production_order_status_update_local_var->_library_owned = 1;
    production_order_status_update_local_var->status = status;
    return production_order_status_update_local_var;
}

__attribute__((deprecated)) production_order_status_update_t *production_order_status_update_create(
    char *status
    ) {
    production_order_status_update_t *result = production_order_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void production_order_status_update_free(production_order_status_update_t *production_order_status_update) {
    if(NULL == production_order_status_update){
        return ;
    }
    if(production_order_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "production_order_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (production_order_status_update->status) {
        free(production_order_status_update->status);
        production_order_status_update->status = NULL;
    }
    free(production_order_status_update);
}

cJSON *production_order_status_update_convertToJSON(production_order_status_update_t *production_order_status_update) {
    cJSON *item = cJSON_CreateObject();

    // production_order_status_update->status
    if (!production_order_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", production_order_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

production_order_status_update_t *production_order_status_update_parseFromJSON(cJSON *production_order_status_updateJSON){

    production_order_status_update_t *production_order_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // production_order_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(production_order_status_updateJSON, "status");
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

    production_order_status_update_local_var = production_order_status_update_create_internal (
        status_local_str
        );

    if (!production_order_status_update_local_var) {
        goto end;
    }

    return production_order_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
