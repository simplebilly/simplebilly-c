#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supplier_invoice_status_update.h"



static supplier_invoice_status_update_t *supplier_invoice_status_update_create_internal(
    char *status
    ) {
    supplier_invoice_status_update_t *supplier_invoice_status_update_local_var = malloc(sizeof(supplier_invoice_status_update_t));
    if (!supplier_invoice_status_update_local_var) {
        return NULL;
    }
    memset(supplier_invoice_status_update_local_var, 0, sizeof(supplier_invoice_status_update_t));
    supplier_invoice_status_update_local_var->_library_owned = 1;
    supplier_invoice_status_update_local_var->status = status;
    return supplier_invoice_status_update_local_var;
}

__attribute__((deprecated)) supplier_invoice_status_update_t *supplier_invoice_status_update_create(
    char *status
    ) {
    supplier_invoice_status_update_t *result = supplier_invoice_status_update_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void supplier_invoice_status_update_free(supplier_invoice_status_update_t *supplier_invoice_status_update) {
    if(NULL == supplier_invoice_status_update){
        return ;
    }
    if(supplier_invoice_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "supplier_invoice_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (supplier_invoice_status_update->status) {
        free(supplier_invoice_status_update->status);
        supplier_invoice_status_update->status = NULL;
    }
    free(supplier_invoice_status_update);
}

cJSON *supplier_invoice_status_update_convertToJSON(supplier_invoice_status_update_t *supplier_invoice_status_update) {
    cJSON *item = cJSON_CreateObject();

    // supplier_invoice_status_update->status
    if (!supplier_invoice_status_update->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", supplier_invoice_status_update->status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

supplier_invoice_status_update_t *supplier_invoice_status_update_parseFromJSON(cJSON *supplier_invoice_status_updateJSON){

    supplier_invoice_status_update_t *supplier_invoice_status_update_local_var = NULL;

    char *status_local_str = NULL;

    // supplier_invoice_status_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(supplier_invoice_status_updateJSON, "status");
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

    supplier_invoice_status_update_local_var = supplier_invoice_status_update_create_internal (
        status_local_str
        );

    if (!supplier_invoice_status_update_local_var) {
        goto end;
    }

    return supplier_invoice_status_update_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
