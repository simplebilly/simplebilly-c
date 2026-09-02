#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "return_order_status_update.h"



static return_order_status_update_t *return_order_status_update_create_internal(
    char *status
    ) {
    return_order_status_update_t *return_order_status_update_local_var = malloc(sizeof(return_order_status_update_t));
    if (!return_order_status_update_local_var) {
        return NULL;
    }
    memset(return_order_status_update_local_var, 0, sizeof(return_order_status_update_t));
    return_order_status_update_local_var->_library_owned = 1;
    return_order_status_update_local_var->status = status;
    return return_order_status_update_local_var;
}

__attribute__((deprecated)) return_order_status_update_t *return_order_status_update_create(
    char *status
    ) {
    return_order_status_update_t *result = return_order_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void return_order_status_update_free(return_order_status_update_t *return_order_status_update) {
    if(NULL == return_order_status_update){
        return ;
    }
    if(return_order_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "return_order_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (return_order_status_update->status) {
        free(return_order_status_update->status);
        return_order_status_update->status = NULL;
    }
    free(return_order_status_update);
}

cJSON *return_order_status_update_convertToJSON(return_order_status_update_t *return_order_status_update) {
    cJSON *item = cJSON_CreateObject();

    // return_order_status_update->status
    if (!return_order_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", return_order_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

return_order_status_update_t *return_order_status_update_parseFromJSON(cJSON *return_order_status_updateJSON){

    return_order_status_update_t *return_order_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // return_order_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(return_order_status_updateJSON, "status");
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

    return_order_status_update_local_var = return_order_status_update_create_internal (
        status_local_str
        );

    if (!return_order_status_update_local_var) {
        goto end;
    }

    return return_order_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
