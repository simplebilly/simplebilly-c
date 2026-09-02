#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "attachment_create.h"



static attachment_create_t *attachment_create_create_internal(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *pdfa_path,
    char *sha256_hash,
    char *uploaded_by
    ) {
    attachment_create_t *attachment_create_local_var = malloc(sizeof(attachment_create_t));
    if (!attachment_create_local_var) {
        return NULL;
    }
    memset(attachment_create_local_var, 0, sizeof(attachment_create_t));
    attachment_create_local_var->_library_owned = 1;
    attachment_create_local_var->contact_id = contact_id;
    attachment_create_local_var->file_name = file_name;
    attachment_create_local_var->file_size = file_size;
    attachment_create_local_var->mime_type = mime_type;
    attachment_create_local_var->original_name = original_name;
    attachment_create_local_var->pdfa_path = pdfa_path;
    attachment_create_local_var->sha256_hash = sha256_hash;
    attachment_create_local_var->uploaded_by = uploaded_by;
    return attachment_create_local_var;
}

__attribute__((deprecated)) attachment_create_t *attachment_create_create(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *original_name,
    char *pdfa_path,
    char *sha256_hash,
    char *uploaded_by
    ) {
    long *file_size_copy = NULL;
    if (file_size) {
        file_size_copy = malloc(sizeof(long));
        if (file_size_copy) *file_size_copy = *file_size;
    }
    attachment_create_t *result = attachment_create_create_internal (
        contact_id,
        file_name,
        file_size_copy,
        mime_type,
        original_name,
        pdfa_path,
        sha256_hash,
        uploaded_by
        );
    if (!result) {
        free(file_size_copy);
    }
    return result;
}

void attachment_create_free(attachment_create_t *attachment_create) {
    if(NULL == attachment_create){
        return ;
    }
    if(attachment_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "attachment_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (attachment_create->contact_id) {
        free(attachment_create->contact_id);
        attachment_create->contact_id = NULL;
    }
    if (attachment_create->file_name) {
        free(attachment_create->file_name);
        attachment_create->file_name = NULL;
    }
    if (attachment_create->file_size) {
        free(attachment_create->file_size);
        attachment_create->file_size = NULL;
    }
    if (attachment_create->mime_type) {
        free(attachment_create->mime_type);
        attachment_create->mime_type = NULL;
    }
    if (attachment_create->original_name) {
        free(attachment_create->original_name);
        attachment_create->original_name = NULL;
    }
    if (attachment_create->pdfa_path) {
        free(attachment_create->pdfa_path);
        attachment_create->pdfa_path = NULL;
    }
    if (attachment_create->sha256_hash) {
        free(attachment_create->sha256_hash);
        attachment_create->sha256_hash = NULL;
    }
    if (attachment_create->uploaded_by) {
        free(attachment_create->uploaded_by);
        attachment_create->uploaded_by = NULL;
    }
    free(attachment_create);
}

cJSON *attachment_create_convertToJSON(attachment_create_t *attachment_create) {
    cJSON *item = cJSON_CreateObject();

    // attachment_create->contact_id
    if(attachment_create->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", attachment_create->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // attachment_create->file_name
    if (!attachment_create->file_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fileName", attachment_create->file_name) == NULL) {
    goto fail; //String
    }


    // attachment_create->file_size
    if(attachment_create->file_size) {
    if(cJSON_AddNumberToObject(item, "fileSize", *attachment_create->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // attachment_create->mime_type
    if(attachment_create->mime_type) {
    if(cJSON_AddStringToObject(item, "mimeType", attachment_create->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // attachment_create->original_name
    if (!attachment_create->original_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "originalName", attachment_create->original_name) == NULL) {
    goto fail; //String
    }


    // attachment_create->pdfa_path
    if(attachment_create->pdfa_path) {
    if(cJSON_AddStringToObject(item, "pdfaPath", attachment_create->pdfa_path) == NULL) {
    goto fail; //String
    }
    }


    // attachment_create->sha256_hash
    if(attachment_create->sha256_hash) {
    if(cJSON_AddStringToObject(item, "sha256Hash", attachment_create->sha256_hash) == NULL) {
    goto fail; //String
    }
    }


    // attachment_create->uploaded_by
    if(attachment_create->uploaded_by) {
    if(cJSON_AddStringToObject(item, "uploadedBy", attachment_create->uploaded_by) == NULL) {
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

attachment_create_t *attachment_create_parseFromJSON(cJSON *attachment_createJSON){

    attachment_create_t *attachment_create_local_var = NULL;

    char *contact_id_local_str = NULL;

    char *file_name_local_str = NULL;

    // define the local variable for attachment_create->file_size
    long *file_size_local_var = NULL;

    char *mime_type_local_str = NULL;

    char *original_name_local_str = NULL;

    char *pdfa_path_local_str = NULL;

    char *sha256_hash_local_str = NULL;

    char *uploaded_by_local_str = NULL;

    // attachment_create->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // attachment_create->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "fileName");
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

    // attachment_create->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "fileSize");
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

    // attachment_create->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "mimeType");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // attachment_create->original_name
    cJSON *original_name = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "originalName");
    if (cJSON_IsNull(original_name)) {
        original_name = NULL;
    }
    if (!original_name) {
        goto end;
    }

    
    if(!cJSON_IsString(original_name))
    {
    goto end; //String
    }

    // attachment_create->pdfa_path
    cJSON *pdfa_path = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "pdfaPath");
    if (cJSON_IsNull(pdfa_path)) {
        pdfa_path = NULL;
    }
    if (pdfa_path) { 
    if(!cJSON_IsString(pdfa_path) && !cJSON_IsNull(pdfa_path))
    {
    goto end; //String
    }
    }

    // attachment_create->sha256_hash
    cJSON *sha256_hash = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "sha256Hash");
    if (cJSON_IsNull(sha256_hash)) {
        sha256_hash = NULL;
    }
    if (sha256_hash) { 
    if(!cJSON_IsString(sha256_hash) && !cJSON_IsNull(sha256_hash))
    {
    goto end; //String
    }
    }

    // attachment_create->uploaded_by
    cJSON *uploaded_by = cJSON_GetObjectItemCaseSensitive(attachment_createJSON, "uploadedBy");
    if (cJSON_IsNull(uploaded_by)) {
        uploaded_by = NULL;
    }
    if (uploaded_by) { 
    if(!cJSON_IsString(uploaded_by) && !cJSON_IsNull(uploaded_by))
    {
    goto end; //String
    }
    }


    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (file_name && !cJSON_IsNull(file_name)) file_name_local_str = strdup(file_name->valuestring);
    if (mime_type && !cJSON_IsNull(mime_type)) mime_type_local_str = strdup(mime_type->valuestring);
    if (original_name && !cJSON_IsNull(original_name)) original_name_local_str = strdup(original_name->valuestring);
    if (pdfa_path && !cJSON_IsNull(pdfa_path)) pdfa_path_local_str = strdup(pdfa_path->valuestring);
    if (sha256_hash && !cJSON_IsNull(sha256_hash)) sha256_hash_local_str = strdup(sha256_hash->valuestring);
    if (uploaded_by && !cJSON_IsNull(uploaded_by)) uploaded_by_local_str = strdup(uploaded_by->valuestring);

    attachment_create_local_var = attachment_create_create_internal (
        contact_id_local_str,
        file_name_local_str,
        file_size_local_var,
        mime_type_local_str,
        original_name_local_str,
        pdfa_path_local_str,
        sha256_hash_local_str,
        uploaded_by_local_str
        );

    if (!attachment_create_local_var) {
        goto end;
    }

    return attachment_create_local_var;
end:
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
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
    if (pdfa_path_local_str) {
        free(pdfa_path_local_str);
        pdfa_path_local_str = NULL;
    }
    if (sha256_hash_local_str) {
        free(sha256_hash_local_str);
        sha256_hash_local_str = NULL;
    }
    if (uploaded_by_local_str) {
        free(uploaded_by_local_str);
        uploaded_by_local_str = NULL;
    }
    return NULL;

}
