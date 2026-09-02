#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "x_rechnung_response.h"



static x_rechnung_response_t *x_rechnung_response_create_internal(
    char *content,
    char *content_type,
    char *filename
    ) {
    x_rechnung_response_t *x_rechnung_response_local_var = malloc(sizeof(x_rechnung_response_t));
    if (!x_rechnung_response_local_var) {
        return NULL;
    }
    memset(x_rechnung_response_local_var, 0, sizeof(x_rechnung_response_t));
    x_rechnung_response_local_var->_library_owned = 1;
    x_rechnung_response_local_var->content = content;
    x_rechnung_response_local_var->content_type = content_type;
    x_rechnung_response_local_var->filename = filename;
    return x_rechnung_response_local_var;
}

__attribute__((deprecated)) x_rechnung_response_t *x_rechnung_response_create(
    char *content,
    char *content_type,
    char *filename
    ) {
    x_rechnung_response_t *result = x_rechnung_response_create_internal (
        content,
        content_type,
        filename
        );
    if (!result) {
    }
    return result;
}

void x_rechnung_response_free(x_rechnung_response_t *x_rechnung_response) {
    if(NULL == x_rechnung_response){
        return ;
    }
    if(x_rechnung_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "x_rechnung_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (x_rechnung_response->content) {
        free(x_rechnung_response->content);
        x_rechnung_response->content = NULL;
    }
    if (x_rechnung_response->content_type) {
        free(x_rechnung_response->content_type);
        x_rechnung_response->content_type = NULL;
    }
    if (x_rechnung_response->filename) {
        free(x_rechnung_response->filename);
        x_rechnung_response->filename = NULL;
    }
    free(x_rechnung_response);
}

cJSON *x_rechnung_response_convertToJSON(x_rechnung_response_t *x_rechnung_response) {
    cJSON *item = cJSON_CreateObject();

    // x_rechnung_response->content
    if (!x_rechnung_response->content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content", x_rechnung_response->content) == NULL) {
    goto fail; //String
    }


    // x_rechnung_response->content_type
    if (!x_rechnung_response->content_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content_type", x_rechnung_response->content_type) == NULL) {
    goto fail; //String
    }


    // x_rechnung_response->filename
    if (!x_rechnung_response->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", x_rechnung_response->filename) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

x_rechnung_response_t *x_rechnung_response_parseFromJSON(cJSON *x_rechnung_responseJSON){

    x_rechnung_response_t *x_rechnung_response_local_var = NULL;

    char *content_local_str = NULL;

    char *content_type_local_str = NULL;

    char *filename_local_str = NULL;

    // x_rechnung_response->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(x_rechnung_responseJSON, "content");
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

    // x_rechnung_response->content_type
    cJSON *content_type = cJSON_GetObjectItemCaseSensitive(x_rechnung_responseJSON, "content_type");
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

    // x_rechnung_response->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(x_rechnung_responseJSON, "filename");
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

    x_rechnung_response_local_var = x_rechnung_response_create_internal (
        content_local_str,
        content_type_local_str,
        filename_local_str
        );

    if (!x_rechnung_response_local_var) {
        goto end;
    }

    return x_rechnung_response_local_var;
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
