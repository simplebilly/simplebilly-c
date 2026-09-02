#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stock_transfer_status_update.h"



static stock_transfer_status_update_t *stock_transfer_status_update_create_internal(
    char *status
    ) {
    stock_transfer_status_update_t *stock_transfer_status_update_local_var = malloc(sizeof(stock_transfer_status_update_t));
    if (!stock_transfer_status_update_local_var) {
        return NULL;
    }
    memset(stock_transfer_status_update_local_var, 0, sizeof(stock_transfer_status_update_t));
    stock_transfer_status_update_local_var->_library_owned = 1;
    stock_transfer_status_update_local_var->status = status;
    return stock_transfer_status_update_local_var;
}

__attribute__((deprecated)) stock_transfer_status_update_t *stock_transfer_status_update_create(
    char *status
    ) {
    stock_transfer_status_update_t *result = stock_transfer_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void stock_transfer_status_update_free(stock_transfer_status_update_t *stock_transfer_status_update) {
    if(NULL == stock_transfer_status_update){
        return ;
    }
    if(stock_transfer_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stock_transfer_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stock_transfer_status_update->status) {
        free(stock_transfer_status_update->status);
        stock_transfer_status_update->status = NULL;
    }
    free(stock_transfer_status_update);
}

cJSON *stock_transfer_status_update_convertToJSON(stock_transfer_status_update_t *stock_transfer_status_update) {
    cJSON *item = cJSON_CreateObject();

    // stock_transfer_status_update->status
    if (!stock_transfer_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", stock_transfer_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stock_transfer_status_update_t *stock_transfer_status_update_parseFromJSON(cJSON *stock_transfer_status_updateJSON){

    stock_transfer_status_update_t *stock_transfer_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // stock_transfer_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(stock_transfer_status_updateJSON, "status");
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

    stock_transfer_status_update_local_var = stock_transfer_status_update_create_internal (
        status_local_str
        );

    if (!stock_transfer_status_update_local_var) {
        goto end;
    }

    return stock_transfer_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
