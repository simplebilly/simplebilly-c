#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_response.h"



static convert_response_t *convert_response_create_internal(
    char *invoice_id,
    char *invoice_number,
    char *proforma_id,
    char *proforma_number
    ) {
    convert_response_t *convert_response_local_var = malloc(sizeof(convert_response_t));
    if (!convert_response_local_var) {
        return NULL;
    }
    memset(convert_response_local_var, 0, sizeof(convert_response_t));
    convert_response_local_var->_library_owned = 1;
    convert_response_local_var->invoice_id = invoice_id;
    convert_response_local_var->invoice_number = invoice_number;
    convert_response_local_var->proforma_id = proforma_id;
    convert_response_local_var->proforma_number = proforma_number;
    return convert_response_local_var;
}

__attribute__((deprecated)) convert_response_t *convert_response_create(
    char *invoice_id,
    char *invoice_number,
    char *proforma_id,
    char *proforma_number
    ) {
    convert_response_t *result = convert_response_create_internal (
        invoice_id,
        invoice_number,
        proforma_id,
        proforma_number
        );
    if (!result) {
    }
    return result;
}

void convert_response_free(convert_response_t *convert_response) {
    if(NULL == convert_response){
        return ;
    }
    if(convert_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (convert_response->invoice_id) {
        free(convert_response->invoice_id);
        convert_response->invoice_id = NULL;
    }
    if (convert_response->invoice_number) {
        free(convert_response->invoice_number);
        convert_response->invoice_number = NULL;
    }
    if (convert_response->proforma_id) {
        free(convert_response->proforma_id);
        convert_response->proforma_id = NULL;
    }
    if (convert_response->proforma_number) {
        free(convert_response->proforma_number);
        convert_response->proforma_number = NULL;
    }
    free(convert_response);
}

cJSON *convert_response_convertToJSON(convert_response_t *convert_response) {
    cJSON *item = cJSON_CreateObject();

    // convert_response->invoice_id
    if (!convert_response->invoice_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoiceId", convert_response->invoice_id) == NULL) {
    goto fail; //String
    }


    // convert_response->invoice_number
    if (!convert_response->invoice_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invoiceNumber", convert_response->invoice_number) == NULL) {
    goto fail; //String
    }


    // convert_response->proforma_id
    if (!convert_response->proforma_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "proformaId", convert_response->proforma_id) == NULL) {
    goto fail; //String
    }


    // convert_response->proforma_number
    if (!convert_response->proforma_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "proformaNumber", convert_response->proforma_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

convert_response_t *convert_response_parseFromJSON(cJSON *convert_responseJSON){

    convert_response_t *convert_response_local_var = NULL;

    char *invoice_id_local_str = NULL;

    char *invoice_number_local_str = NULL;

    char *proforma_id_local_str = NULL;

    char *proforma_number_local_str = NULL;

    // convert_response->invoice_id
    cJSON *invoice_id = cJSON_GetObjectItemCaseSensitive(convert_responseJSON, "invoiceId");
    if (cJSON_IsNull(invoice_id)) {
        invoice_id = NULL;
    }
    if (!invoice_id) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_id))
    {
    goto end; //String
    }

    // convert_response->invoice_number
    cJSON *invoice_number = cJSON_GetObjectItemCaseSensitive(convert_responseJSON, "invoiceNumber");
    if (cJSON_IsNull(invoice_number)) {
        invoice_number = NULL;
    }
    if (!invoice_number) {
        goto end;
    }

    
    if(!cJSON_IsString(invoice_number))
    {
    goto end; //String
    }

    // convert_response->proforma_id
    cJSON *proforma_id = cJSON_GetObjectItemCaseSensitive(convert_responseJSON, "proformaId");
    if (cJSON_IsNull(proforma_id)) {
        proforma_id = NULL;
    }
    if (!proforma_id) {
        goto end;
    }

    
    if(!cJSON_IsString(proforma_id))
    {
    goto end; //String
    }

    // convert_response->proforma_number
    cJSON *proforma_number = cJSON_GetObjectItemCaseSensitive(convert_responseJSON, "proformaNumber");
    if (cJSON_IsNull(proforma_number)) {
        proforma_number = NULL;
    }
    if (!proforma_number) {
        goto end;
    }

    
    if(!cJSON_IsString(proforma_number))
    {
    goto end; //String
    }


    if (invoice_id && !cJSON_IsNull(invoice_id)) invoice_id_local_str = strdup(invoice_id->valuestring);
    if (invoice_number && !cJSON_IsNull(invoice_number)) invoice_number_local_str = strdup(invoice_number->valuestring);
    if (proforma_id && !cJSON_IsNull(proforma_id)) proforma_id_local_str = strdup(proforma_id->valuestring);
    if (proforma_number && !cJSON_IsNull(proforma_number)) proforma_number_local_str = strdup(proforma_number->valuestring);

    convert_response_local_var = convert_response_create_internal (
        invoice_id_local_str,
        invoice_number_local_str,
        proforma_id_local_str,
        proforma_number_local_str
        );

    if (!convert_response_local_var) {
        goto end;
    }

    return convert_response_local_var;
end:
    if (invoice_id_local_str) {
        free(invoice_id_local_str);
        invoice_id_local_str = NULL;
    }
    if (invoice_number_local_str) {
        free(invoice_number_local_str);
        invoice_number_local_str = NULL;
    }
    if (proforma_id_local_str) {
        free(proforma_id_local_str);
        proforma_id_local_str = NULL;
    }
    if (proforma_number_local_str) {
        free(proforma_number_local_str);
        proforma_number_local_str = NULL;
    }
    return NULL;

}
