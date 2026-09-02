#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice_pdf_url_response.h"



static invoice_pdf_url_response_t *invoice_pdf_url_response_create_internal(
    char *url
    ) {
    invoice_pdf_url_response_t *invoice_pdf_url_response_local_var = malloc(sizeof(invoice_pdf_url_response_t));
    if (!invoice_pdf_url_response_local_var) {
        return NULL;
    }
    memset(invoice_pdf_url_response_local_var, 0, sizeof(invoice_pdf_url_response_t));
    invoice_pdf_url_response_local_var->_library_owned = 1;
    invoice_pdf_url_response_local_var->url = url;
    return invoice_pdf_url_response_local_var;
}

__attribute__((deprecated)) invoice_pdf_url_response_t *invoice_pdf_url_response_create(
    char *url
    ) {
    invoice_pdf_url_response_t *result = invoice_pdf_url_response_create_internal (
        url
        );
    if (!result) {
    }
    return result;
}

void invoice_pdf_url_response_free(invoice_pdf_url_response_t *invoice_pdf_url_response) {
    if(NULL == invoice_pdf_url_response){
        return ;
    }
    if(invoice_pdf_url_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invoice_pdf_url_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invoice_pdf_url_response->url) {
        free(invoice_pdf_url_response->url);
        invoice_pdf_url_response->url = NULL;
    }
    free(invoice_pdf_url_response);
}

cJSON *invoice_pdf_url_response_convertToJSON(invoice_pdf_url_response_t *invoice_pdf_url_response) {
    cJSON *item = cJSON_CreateObject();

    // invoice_pdf_url_response->url
    if (!invoice_pdf_url_response->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", invoice_pdf_url_response->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invoice_pdf_url_response_t *invoice_pdf_url_response_parseFromJSON(cJSON *invoice_pdf_url_responseJSON){

    invoice_pdf_url_response_t *invoice_pdf_url_response_local_var = NULL;

    char *url_local_str = NULL;

    // invoice_pdf_url_response->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(invoice_pdf_url_responseJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    if (url && !cJSON_IsNull(url)) url_local_str = strdup(url->valuestring);

    invoice_pdf_url_response_local_var = invoice_pdf_url_response_create_internal (
        url_local_str
        );

    if (!invoice_pdf_url_response_local_var) {
        goto end;
    }

    return invoice_pdf_url_response_local_var;
end:
    if (url_local_str) {
        free(url_local_str);
        url_local_str = NULL;
    }
    return NULL;

}
