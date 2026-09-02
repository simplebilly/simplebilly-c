#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qr_code_response.h"



static qr_code_response_t *qr_code_response_create_internal(
    char *content_type,
    char *qr_code_base64
    ) {
    qr_code_response_t *qr_code_response_local_var = malloc(sizeof(qr_code_response_t));
    if (!qr_code_response_local_var) {
        return NULL;
    }
    memset(qr_code_response_local_var, 0, sizeof(qr_code_response_t));
    qr_code_response_local_var->_library_owned = 1;
    qr_code_response_local_var->content_type = content_type;
    qr_code_response_local_var->qr_code_base64 = qr_code_base64;
    return qr_code_response_local_var;
}

__attribute__((deprecated)) qr_code_response_t *qr_code_response_create(
    char *content_type,
    char *qr_code_base64
    ) {
    qr_code_response_t *result = qr_code_response_create_internal (
        content_type,
        qr_code_base64
        );
    if (!result) {
    }
    return result;
}

void qr_code_response_free(qr_code_response_t *qr_code_response) {
    if(NULL == qr_code_response){
        return ;
    }
    if(qr_code_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "qr_code_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (qr_code_response->content_type) {
        free(qr_code_response->content_type);
        qr_code_response->content_type = NULL;
    }
    if (qr_code_response->qr_code_base64) {
        free(qr_code_response->qr_code_base64);
        qr_code_response->qr_code_base64 = NULL;
    }
    free(qr_code_response);
}

cJSON *qr_code_response_convertToJSON(qr_code_response_t *qr_code_response) {
    cJSON *item = cJSON_CreateObject();

    // qr_code_response->content_type
    if (!qr_code_response->content_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content_type", qr_code_response->content_type) == NULL) {
    goto fail; //String
    }


    // qr_code_response->qr_code_base64
    if (!qr_code_response->qr_code_base64) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "qr_code_base64", qr_code_response->qr_code_base64) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

qr_code_response_t *qr_code_response_parseFromJSON(cJSON *qr_code_responseJSON){

    qr_code_response_t *qr_code_response_local_var = NULL;

    char *content_type_local_str = NULL;

    char *qr_code_base64_local_str = NULL;

    // qr_code_response->content_type
    cJSON *content_type = cJSON_GetObjectItemCaseSensitive(qr_code_responseJSON, "content_type");
    if (cJSON_IsNull(content_type)) {
        content_type = NULL;
    }
    if (!content_type) {
        goto end;
    }

    
    if(!cJSON_IsString(content_type))
    {
    goto end; //String
    }

    // qr_code_response->qr_code_base64
    cJSON *qr_code_base64 = cJSON_GetObjectItemCaseSensitive(qr_code_responseJSON, "qr_code_base64");
    if (cJSON_IsNull(qr_code_base64)) {
        qr_code_base64 = NULL;
    }
    if (!qr_code_base64) {
        goto end;
    }

    
    if(!cJSON_IsString(qr_code_base64))
    {
    goto end; //String
    }


    if (content_type && !cJSON_IsNull(content_type)) content_type_local_str = strdup(content_type->valuestring);
    if (qr_code_base64 && !cJSON_IsNull(qr_code_base64)) qr_code_base64_local_str = strdup(qr_code_base64->valuestring);

    qr_code_response_local_var = qr_code_response_create_internal (
        content_type_local_str,
        qr_code_base64_local_str
        );

    if (!qr_code_response_local_var) {
        goto end;
    }

    return qr_code_response_local_var;
end:
    if (content_type_local_str) {
        free(content_type_local_str);
        content_type_local_str = NULL;
    }
    if (qr_code_base64_local_str) {
        free(qr_code_base64_local_str);
        qr_code_base64_local_str = NULL;
    }
    return NULL;

}
