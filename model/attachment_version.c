#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "attachment_version.h"



static attachment_version_t *attachment_version_create_internal(
    char *attachment_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash,
    char *uploaded_by,
    int *version_number
    ) {
    attachment_version_t *attachment_version_local_var = malloc(sizeof(attachment_version_t));
    if (!attachment_version_local_var) {
        return NULL;
    }
    memset(attachment_version_local_var, 0, sizeof(attachment_version_t));
    attachment_version_local_var->_library_owned = 1;
    attachment_version_local_var->attachment_id = attachment_id;
    attachment_version_local_var->file_name = file_name;
    attachment_version_local_var->file_size = file_size;
    attachment_version_local_var->mime_type = mime_type;
    attachment_version_local_var->original_name = original_name;
    attachment_version_local_var->sha256_hash = sha256_hash;
    attachment_version_local_var->uploaded_by = uploaded_by;
    attachment_version_local_var->version_number = version_number;
    return attachment_version_local_var;
}

__attribute__((deprecated)) attachment_version_t *attachment_version_create(
    char *attachment_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *sha256_hash,
    char *uploaded_by,
    int *version_number
    ) {
    long *file_size_copy = NULL;
    if (file_size) {
        file_size_copy = malloc(sizeof(long));
        if (file_size_copy) *file_size_copy = *file_size;
    }
    int *version_number_copy = NULL;
    if (version_number) {
        version_number_copy = malloc(sizeof(int));
        if (version_number_copy) *version_number_copy = *version_number;
    }
    attachment_version_t *result = attachment_version_create_internal (
        attachment_id,
        file_name,
        file_size_copy,
        mime_type,
        original_name,
        sha256_hash,
        uploaded_by,
        version_number_copy
        );
    if (!result) {
        free(file_size_copy);
        free(version_number_copy);
    }
    return result;
}

void attachment_version_free(attachment_version_t *attachment_version) {
    if(NULL == attachment_version){
        return ;
    }
    if(attachment_version->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "attachment_version_free");
        return ;
    }
    listEntry_t *listEntry;
    if (attachment_version->attachment_id) {
        free(attachment_version->attachment_id);
        attachment_version->attachment_id = NULL;
    }
    if (attachment_version->file_name) {
        free(attachment_version->file_name);
        attachment_version->file_name = NULL;
    }
    if (attachment_version->file_size) {
        free(attachment_version->file_size);
        attachment_version->file_size = NULL;
    }
    if (attachment_version->mime_type) {
        free(attachment_version->mime_type);
        attachment_version->mime_type = NULL;
    }
    if (attachment_version->original_name) {
        free(attachment_version->original_name);
        attachment_version->original_name = NULL;
    }
    if (attachment_version->sha256_hash) {
        free(attachment_version->sha256_hash);
        attachment_version->sha256_hash = NULL;
    }
    if (attachment_version->uploaded_by) {
        free(attachment_version->uploaded_by);
        attachment_version->uploaded_by = NULL;
    }
    if (attachment_version->version_number) {
        free(attachment_version->version_number);
        attachment_version->version_number = NULL;
    }
    free(attachment_version);
}

cJSON *attachment_version_convertToJSON(attachment_version_t *attachment_version) {
    cJSON *item = cJSON_CreateObject();

    // attachment_version->attachment_id
    if (!attachment_version->attachment_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "attachmentId", attachment_version->attachment_id) == NULL) {
    goto fail; //String
    }


    // attachment_version->file_name
    if (!attachment_version->file_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fileName", attachment_version->file_name) == NULL) {
    goto fail; //String
    }


    // attachment_version->file_size
    if(attachment_version->file_size) {
    if(cJSON_AddNumberToObject(item, "fileSize", *attachment_version->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // attachment_version->mime_type
    if(attachment_version->mime_type) {
    if(cJSON_AddStringToObject(item, "mimeType", attachment_version->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // attachment_version->original_name
    if(attachment_version->original_name) {
    if(cJSON_AddStringToObject(item, "originalName", attachment_version->original_name) == NULL) {
    goto fail; //String
    }
    }


    // attachment_version->sha256_hash
    if(attachment_version->sha256_hash) {
    if(cJSON_AddStringToObject(item, "sha256Hash", attachment_version->sha256_hash) == NULL) {
    goto fail; //String
    }
    }


    // attachment_version->uploaded_by
    if(attachment_version->uploaded_by) {
    if(cJSON_AddStringToObject(item, "uploadedBy", attachment_version->uploaded_by) == NULL) {
    goto fail; //String
    }
    }


    // attachment_version->version_number
    if (!attachment_version->version_number) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "versionNumber", *attachment_version->version_number) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

attachment_version_t *attachment_version_parseFromJSON(cJSON *attachment_versionJSON){

    attachment_version_t *attachment_version_local_var = NULL;

    char *attachment_id_local_str = NULL;

    char *file_name_local_str = NULL;

    // define the local variable for attachment_version->file_size
    long *file_size_local_var = NULL;

    char *mime_type_local_str = NULL;

    char *original_name_local_str = NULL;

    char *sha256_hash_local_str = NULL;

    char *uploaded_by_local_str = NULL;

    // define the local variable for attachment_version->version_number
    int *version_number_local_var = NULL;

    // attachment_version->attachment_id
    cJSON *attachment_id = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "attachmentId");
    if (cJSON_IsNull(attachment_id)) {
        attachment_id = NULL;
    }
    if (!attachment_id) {
        goto end;
    }

    
    if(!cJSON_IsString(attachment_id))
    {
    goto end; //String
    }

    // attachment_version->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "fileName");
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

    // attachment_version->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "fileSize");
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

    // attachment_version->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "mimeType");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // attachment_version->original_name
    cJSON *original_name = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "originalName");
    if (cJSON_IsNull(original_name)) {
        original_name = NULL;
    }
    if (original_name) { 
    if(!cJSON_IsString(original_name) && !cJSON_IsNull(original_name))
    {
    goto end; //String
    }
    }

    // attachment_version->sha256_hash
    cJSON *sha256_hash = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "sha256Hash");
    if (cJSON_IsNull(sha256_hash)) {
        sha256_hash = NULL;
    }
    if (sha256_hash) { 
    if(!cJSON_IsString(sha256_hash) && !cJSON_IsNull(sha256_hash))
    {
    goto end; //String
    }
    }

    // attachment_version->uploaded_by
    cJSON *uploaded_by = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "uploadedBy");
    if (cJSON_IsNull(uploaded_by)) {
        uploaded_by = NULL;
    }
    if (uploaded_by) { 
    if(!cJSON_IsString(uploaded_by) && !cJSON_IsNull(uploaded_by))
    {
    goto end; //String
    }
    }

    // attachment_version->version_number
    cJSON *version_number = cJSON_GetObjectItemCaseSensitive(attachment_versionJSON, "versionNumber");
    if (cJSON_IsNull(version_number)) {
        version_number = NULL;
    }
    if (!version_number) {
        goto end;
    }

    
    if(!cJSON_IsNumber(version_number))
    {
    goto end; //Numeric
    }
    version_number_local_var = malloc(sizeof(int));
    if(!version_number_local_var)
    {
        goto end;
    }
    *version_number_local_var = version_number->valuedouble;


    if (attachment_id && !cJSON_IsNull(attachment_id)) attachment_id_local_str = strdup(attachment_id->valuestring);
    if (file_name && !cJSON_IsNull(file_name)) file_name_local_str = strdup(file_name->valuestring);
    if (mime_type && !cJSON_IsNull(mime_type)) mime_type_local_str = strdup(mime_type->valuestring);
    if (original_name && !cJSON_IsNull(original_name)) original_name_local_str = strdup(original_name->valuestring);
    if (sha256_hash && !cJSON_IsNull(sha256_hash)) sha256_hash_local_str = strdup(sha256_hash->valuestring);
    if (uploaded_by && !cJSON_IsNull(uploaded_by)) uploaded_by_local_str = strdup(uploaded_by->valuestring);

    attachment_version_local_var = attachment_version_create_internal (
        attachment_id_local_str,
        file_name_local_str,
        file_size_local_var,
        mime_type_local_str,
        original_name_local_str,
        sha256_hash_local_str,
        uploaded_by_local_str,
        version_number_local_var
        );

    if (!attachment_version_local_var) {
        goto end;
    }

    return attachment_version_local_var;
end:
    if (attachment_id_local_str) {
        free(attachment_id_local_str);
        attachment_id_local_str = NULL;
    }
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
    if (uploaded_by_local_str) {
        free(uploaded_by_local_str);
        uploaded_by_local_str = NULL;
    }
    if (version_number_local_var) {
        free(version_number_local_var);
        version_number_local_var = NULL;
    }
    return NULL;

}
