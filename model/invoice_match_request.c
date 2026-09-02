#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_match_request.h"



static invoice_match_request_t *invoice_match_request_create_internal(
    char *supplier_invoice_id
    ) {
    invoice_match_request_t *invoice_match_request_local_var = malloc(sizeof(invoice_match_request_t));
    if (!invoice_match_request_local_var) {
        return NULL;
    }
    memset(invoice_match_request_local_var, 0, sizeof(invoice_match_request_t));
    invoice_match_request_local_var->_library_owned = 1;
    invoice_match_request_local_var->supplier_invoice_id = supplier_invoice_id;
    return invoice_match_request_local_var;
}

__attribute__((deprecated)) invoice_match_request_t *invoice_match_request_create(
    char *supplier_invoice_id
    ) {
    invoice_match_request_t *result = invoice_match_request_create_internal (
        supplier_invoice_id
        );
    if (!result) {
    }
    return result;
}

void invoice_match_request_free(invoice_match_request_t *invoice_match_request) {
    if(NULL == invoice_match_request){
        return ;
    }
    if(invoice_match_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invoice_match_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invoice_match_request->supplier_invoice_id) {
        free(invoice_match_request->supplier_invoice_id);
        invoice_match_request->supplier_invoice_id = NULL;
    }
    free(invoice_match_request);
}

cJSON *invoice_match_request_convertToJSON(invoice_match_request_t *invoice_match_request) {
    cJSON *item = cJSON_CreateObject();

    // invoice_match_request->supplier_invoice_id
    if (!invoice_match_request->supplier_invoice_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supplier_invoice_id", invoice_match_request->supplier_invoice_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invoice_match_request_t *invoice_match_request_parseFromJSON(cJSON *invoice_match_requestJSON){

    invoice_match_request_t *invoice_match_request_local_var = NULL;

    char *supplier_invoice_id_local_str = NULL;

    // invoice_match_request->supplier_invoice_id
    cJSON *supplier_invoice_id = cJSON_GetObjectItemCaseSensitive(invoice_match_requestJSON, "supplier_invoice_id");
    if (cJSON_IsNull(supplier_invoice_id)) {
        supplier_invoice_id = NULL;
    }
    if (!supplier_invoice_id) {
        goto end;
    }

    
    if(!cJSON_IsString(supplier_invoice_id))
    {
    goto end; //String
    }


    if (supplier_invoice_id && !cJSON_IsNull(supplier_invoice_id)) supplier_invoice_id_local_str = strdup(supplier_invoice_id->valuestring);

    invoice_match_request_local_var = invoice_match_request_create_internal (
        supplier_invoice_id_local_str
        );

    if (!invoice_match_request_local_var) {
        goto end;
    }

    return invoice_match_request_local_var;
end:
    if (supplier_invoice_id_local_str) {
        free(supplier_invoice_id_local_str);
        supplier_invoice_id_local_str = NULL;
    }
    return NULL;

}
