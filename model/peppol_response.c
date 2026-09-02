#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "peppol_response.h"



static peppol_response_t *peppol_response_create_internal(
    char *content,
    char *content_type,
    char *filename
    ) {
    peppol_response_t *peppol_response_local_var = malloc(sizeof(peppol_response_t));
    if (!peppol_response_local_var) {
        return NULL;
    }
    memset(peppol_response_local_var, 0, sizeof(peppol_response_t));
    peppol_response_local_var->_library_owned = 1;
    peppol_response_local_var->content = content;
    peppol_response_local_var->content_type = content_type;
    peppol_response_local_var->filename = filename;
    return peppol_response_local_var;
}

__attribute__((deprecated)) peppol_response_t *peppol_response_create(
    char *content,
    char *content_type,
    char *filename
    ) {
    peppol_response_t *result = peppol_response_create_internal (
        content,
        content_type,
        filename
        );
    if (!result) {
    }
    return result;
}

void peppol_response_free(peppol_response_t *peppol_response) {
    if(NULL == peppol_response){
        return ;
    }
    if(peppol_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "peppol_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (peppol_response->content) {
        free(peppol_response->content);
        peppol_response->content = NULL;
    }
    if (peppol_response->content_type) {
        free(peppol_response->content_type);
        peppol_response->content_type = NULL;
    }
    if (peppol_response->filename) {
        free(peppol_response->filename);
        peppol_response->filename = NULL;
    }
    free(peppol_response);
}

cJSON *peppol_response_convertToJSON(peppol_response_t *peppol_response) {
    cJSON *item = cJSON_CreateObject();

    // peppol_response->content
    if (!peppol_response->content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content", peppol_response->content) == NULL) {
    goto fail; //String
    }


    // peppol_response->content_type
    if (!peppol_response->content_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content_type", peppol_response->content_type) == NULL) {
    goto fail; //String
    }


    // peppol_response->filename
    if (!peppol_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", peppol_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

peppol_response_t *peppol_response_parseFromJSON(cJSON *peppol_responseJSON){

    peppol_response_t *peppol_response_local_var = NULL;

    char *content_local_str = NULL;

    char *content_type_local_str = NULL;

    char *filename_local_str = NULL;

    // peppol_response->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(peppol_responseJSON, "content");
    if (cJSON_IsNull(content)) {
        content = NULL;
    }
    if (!content) {
        goto end;
    }

    
    if(!cJSON_IsString(content))
    {
    goto end; //String
    }

    // peppol_response->content_type
    cJSON *content_type = cJSON_GetObjectItemCaseSensitive(peppol_responseJSON, "content_type");
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

    // peppol_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(peppol_responseJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (!filename) {
        goto end;
    }

    
    if(!cJSON_IsString(filename))
    {
    goto end; //String
    }


    if (content && !cJSON_IsNull(content)) content_local_str = strdup(content->valuestring);
    if (content_type && !cJSON_IsNull(content_type)) content_type_local_str = strdup(content_type->valuestring);
    if (filename && !cJSON_IsNull(filename)) filename_local_str = strdup(filename->valuestring);

    peppol_response_local_var = peppol_response_create_internal (
        content_local_str,
        content_type_local_str,
        filename_local_str
        );

    if (!peppol_response_local_var) {
        goto end;
    }

    return peppol_response_local_var;
end:
    if (content_local_str) {
        free(content_local_str);
        content_local_str = NULL;
    }
    if (content_type_local_str) {
        free(content_type_local_str);
        content_type_local_str = NULL;
    }
    if (filename_local_str) {
        free(filename_local_str);
        filename_local_str = NULL;
    }
    return NULL;

}
