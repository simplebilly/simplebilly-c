#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "purchase_order_status_update.h"



static purchase_order_status_update_t *purchase_order_status_update_create_internal(
    char *status
    ) {
    purchase_order_status_update_t *purchase_order_status_update_local_var = malloc(sizeof(purchase_order_status_update_t));
    if (!purchase_order_status_update_local_var) {
        return NULL;
    }
    memset(purchase_order_status_update_local_var, 0, sizeof(purchase_order_status_update_t));
    purchase_order_status_update_local_var->_library_owned = 1;
    purchase_order_status_update_local_var->status = status;
    return purchase_order_status_update_local_var;
}

__attribute__((deprecated)) purchase_order_status_update_t *purchase_order_status_update_create(
    char *status
    ) {
    purchase_order_status_update_t *result = purchase_order_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void purchase_order_status_update_free(purchase_order_status_update_t *purchase_order_status_update) {
    if(NULL == purchase_order_status_update){
        return ;
    }
    if(purchase_order_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "purchase_order_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (purchase_order_status_update->status) {
        free(purchase_order_status_update->status);
        purchase_order_status_update->status = NULL;
    }
    free(purchase_order_status_update);
}

cJSON *purchase_order_status_update_convertToJSON(purchase_order_status_update_t *purchase_order_status_update) {
    cJSON *item = cJSON_CreateObject();

    // purchase_order_status_update->status
    if (!purchase_order_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", purchase_order_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

purchase_order_status_update_t *purchase_order_status_update_parseFromJSON(cJSON *purchase_order_status_updateJSON){

    purchase_order_status_update_t *purchase_order_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // purchase_order_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(purchase_order_status_updateJSON, "status");
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

    purchase_order_status_update_local_var = purchase_order_status_update_create_internal (
        status_local_str
        );

    if (!purchase_order_status_update_local_var) {
        goto end;
    }

    return purchase_order_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
