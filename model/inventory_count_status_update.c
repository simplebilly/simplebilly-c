#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inventory_count_status_update.h"



static inventory_count_status_update_t *inventory_count_status_update_create_internal(
    char *status
    ) {
    inventory_count_status_update_t *inventory_count_status_update_local_var = malloc(sizeof(inventory_count_status_update_t));
    if (!inventory_count_status_update_local_var) {
        return NULL;
    }
    memset(inventory_count_status_update_local_var, 0, sizeof(inventory_count_status_update_t));
    inventory_count_status_update_local_var->_library_owned = 1;
    inventory_count_status_update_local_var->status = status;
    return inventory_count_status_update_local_var;
}

__attribute__((deprecated)) inventory_count_status_update_t *inventory_count_status_update_create(
    char *status
    ) {
    inventory_count_status_update_t *result = inventory_count_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void inventory_count_status_update_free(inventory_count_status_update_t *inventory_count_status_update) {
    if(NULL == inventory_count_status_update){
        return ;
    }
    if(inventory_count_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inventory_count_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inventory_count_status_update->status) {
        free(inventory_count_status_update->status);
        inventory_count_status_update->status = NULL;
    }
    free(inventory_count_status_update);
}

cJSON *inventory_count_status_update_convertToJSON(inventory_count_status_update_t *inventory_count_status_update) {
    cJSON *item = cJSON_CreateObject();

    // inventory_count_status_update->status
    if (!inventory_count_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", inventory_count_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inventory_count_status_update_t *inventory_count_status_update_parseFromJSON(cJSON *inventory_count_status_updateJSON){

    inventory_count_status_update_t *inventory_count_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // inventory_count_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(inventory_count_status_updateJSON, "status");
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

    inventory_count_status_update_local_var = inventory_count_status_update_create_internal (
        status_local_str
        );

    if (!inventory_count_status_update_local_var) {
        goto end;
    }

    return inventory_count_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
