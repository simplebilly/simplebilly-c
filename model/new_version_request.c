#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "new_version_request.h"



static new_version_request_t *new_version_request_create_internal(
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash
    ) {
    new_version_request_t *new_version_request_local_var = malloc(sizeof(new_version_request_t));
    if (!new_version_request_local_var) {
        return NULL;
    }
    memset(new_version_request_local_var, 0, sizeof(new_version_request_t));
    new_version_request_local_var->_library_owned = 1;
    new_version_request_local_var->file_name = file_name;
    new_version_request_local_var->file_size = file_size;
    new_version_request_local_var->mime_type = mime_type;
    new_version_request_local_var->original_name = original_name;
    new_version_request_local_var->sha256_hash = sha256_hash;
    return new_version_request_local_var;
}

__attribute__((deprecated)) new_version_request_t *new_version_request_create(
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash
    ) {
    long *file_size_copy = NULL;
    if (file_size) {
        file_size_copy = malloc(sizeof(long));
        if (file_size_copy) *file_size_copy = *file_size;
    }
    new_version_request_t *result = new_version_request_create_internal (
        file_name,
        file_size_copy,
        mime_type,
        original_name,
        sha256_hash
        );
    if (!result) {
        free(file_size_copy);
    }
    return result;
}

void new_version_request_free(new_version_request_t *new_version_request) {
    if(NULL == new_version_request){
        return ;
    }
    if(new_version_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "new_version_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (new_version_request->file_name) {
        free(new_version_request->file_name);
        new_version_request->file_name = NULL;
    }
    if (new_version_request->file_size) {
        free(new_version_request->file_size);
        new_version_request->file_size = NULL;
    }
    if (new_version_request->mime_type) {
        free(new_version_request->mime_type);
        new_version_request->mime_type = NULL;
    }
    if (new_version_request->original_name) {
        free(new_version_request->original_name);
        new_version_request->original_name = NULL;
    }
    if (new_version_request->sha256_hash) {
        free(new_version_request->sha256_hash);
        new_version_request->sha256_hash = NULL;
    }
    free(new_version_request);
}

cJSON *new_version_request_convertToJSON(new_version_request_t *new_version_request) {
    cJSON *item = cJSON_CreateObject();

    // new_version_request->file_name
    if (!new_version_request->file_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fileName", new_version_request->file_name) == NULL) {
    goto fail; //String
    }


    // new_version_request->file_size
    if(new_version_request->file_size) {
    if(cJSON_AddNumberToObject(item, "fileSize", *new_version_request->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // new_version_request->mime_type
    if(new_version_request->mime_type) {
    if(cJSON_AddStringToObject(item, "mimeType", new_version_request->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // new_version_request->original_name
    if(new_version_request->original_name) {
    if(cJSON_AddStringToObject(item, "originalName", new_version_request->original_name) == NULL) {
    goto fail; //String
    }
    }


    // new_version_request->sha256_hash
    if(new_version_request->sha256_hash) {
    if(cJSON_AddStringToObject(item, "sha256Hash", new_version_request->sha256_hash) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

new_version_request_t *new_version_request_parseFromJSON(cJSON *new_version_requestJSON){

    new_version_request_t *new_version_request_local_var = NULL;

    char *file_name_local_str = NULL;

    // define the local variable for new_version_request->file_size
    long *file_size_local_var = NULL;

    char *mime_type_local_str = NULL;

    char *original_name_local_str = NULL;

    char *sha256_hash_local_str = NULL;

    // new_version_request->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(new_version_requestJSON, "fileName");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (!file_name) {
        goto end;
    }

    
    if(!cJSON_IsString(file_name))
    {
    goto end; //String
    }

    // new_version_request->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(new_version_requestJSON, "fileSize");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    file_size_local_var = malloc(sizeof(long));
    if(!file_size_local_var)
    {
        goto end;
    }
    *file_size_local_var = file_size->valuedouble;
    }

    // new_version_request->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(new_version_requestJSON, "mimeType");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // new_version_request->original_name
    cJSON *original_name = cJSON_GetObjectItemCaseSensitive(new_version_requestJSON, "originalName");
    if (cJSON_IsNull(original_name)) {
        original_name = NULL;
    }
    if (original_name) { 
    if(!cJSON_IsString(original_name) && !cJSON_IsNull(original_name))
    {
    goto end; //String
    }
    }

    // new_version_request->sha256_hash
    cJSON *sha256_hash = cJSON_GetObjectItemCaseSensitive(new_version_requestJSON, "sha256Hash");
    if (cJSON_IsNull(sha256_hash)) {
        sha256_hash = NULL;
    }
    if (sha256_hash) { 
    if(!cJSON_IsString(sha256_hash) && !cJSON_IsNull(sha256_hash))
    {
    goto end; //String
    }
    }


    if (file_name && !cJSON_IsNull(file_name)) file_name_local_str = strdup(file_name->valuestring);
    if (mime_type && !cJSON_IsNull(mime_type)) mime_type_local_str = strdup(mime_type->valuestring);
    if (original_name && !cJSON_IsNull(original_name)) original_name_local_str = strdup(original_name->valuestring);
    if (sha256_hash && !cJSON_IsNull(sha256_hash)) sha256_hash_local_str = strdup(sha256_hash->valuestring);

    new_version_request_local_var = new_version_request_create_internal (
        file_name_local_str,
        file_size_local_var,
        mime_type_local_str,
        original_name_local_str,
        sha256_hash_local_str
        );

    if (!new_version_request_local_var) {
        goto end;
    }

    return new_version_request_local_var;
end:
    if (file_name_local_str) {
        free(file_name_local_str);
        file_name_local_str = NULL;
    }
    if (file_size_local_var) {
        free(file_size_local_var);
        file_size_local_var = NULL;
    }
    if (mime_type_local_str) {
        free(mime_type_local_str);
        mime_type_local_str = NULL;
    }
    if (original_name_local_str) {
        free(original_name_local_str);
        original_name_local_str = NULL;
    }
    if (sha256_hash_local_str) {
        free(sha256_hash_local_str);
        sha256_hash_local_str = NULL;
    }
    return NULL;

}
