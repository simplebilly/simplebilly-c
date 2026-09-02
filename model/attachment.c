#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "attachment.h"



static attachment_t *attachment_create_internal(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *ocr_text,
    char *original_name,
    char *pdfa_path,
    char *sha256_hash,
    char *uploaded_by
    ) {
    attachment_t *attachment_local_var = malloc(sizeof(attachment_t));
    if (!attachment_local_var) {
        return NULL;
    }
    memset(attachment_local_var, 0, sizeof(attachment_t));
    attachment_local_var->_library_owned = 1;
    attachment_local_var->contact_id = contact_id;
    attachment_local_var->file_name = file_name;
    attachment_local_var->file_size = file_size;
    attachment_local_var->mime_type = mime_type;
    attachment_local_var->ocr_text = ocr_text;
    attachment_local_var->original_name = original_name;
    attachment_local_var->pdfa_path = pdfa_path;
    attachment_local_var->sha256_hash = sha256_hash;
    attachment_local_var->uploaded_by = uploaded_by;
    return attachment_local_var;
}

__attribute__((deprecated)) attachment_t *attachment_create(
    char *contact_id,
    char *file_name,
    long *file_size,
    char *mime_type,
    char *ocr_text,
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
    attachment_t *result = attachment_create_internal (
        contact_id,
        file_name,
        file_size_copy,
        mime_type,
        ocr_text,
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

void attachment_free(attachment_t *attachment) {
    if(NULL == attachment){
        return ;
    }
    if(attachment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "attachment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (attachment->contact_id) {
        free(attachment->contact_id);
        attachment->contact_id = NULL;
    }
    if (attachment->file_name) {
        free(attachment->file_name);
        attachment->file_name = NULL;
    }
    if (attachment->file_size) {
        free(attachment->file_size);
        attachment->file_size = NULL;
    }
    if (attachment->mime_type) {
        free(attachment->mime_type);
        attachment->mime_type = NULL;
    }
    if (attachment->ocr_text) {
        free(attachment->ocr_text);
        attachment->ocr_text = NULL;
    }
    if (attachment->original_name) {
        free(attachment->original_name);
        attachment->original_name = NULL;
    }
    if (attachment->pdfa_path) {
        free(attachment->pdfa_path);
        attachment->pdfa_path = NULL;
    }
    if (attachment->sha256_hash) {
        free(attachment->sha256_hash);
        attachment->sha256_hash = NULL;
    }
    if (attachment->uploaded_by) {
        free(attachment->uploaded_by);
        attachment->uploaded_by = NULL;
    }
    free(attachment);
}

cJSON *attachment_convertToJSON(attachment_t *attachment) {
    cJSON *item = cJSON_CreateObject();

    // attachment->contact_id
    if(attachment->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", attachment->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // attachment->file_name
    if (!attachment->file_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fileName", attachment->file_name) == NULL) {
    goto fail; //String
    }


    // attachment->file_size
    if(attachment->file_size) {
    if(cJSON_AddNumberToObject(item, "fileSize", *attachment->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // attachment->mime_type
    if(attachment->mime_type) {
    if(cJSON_AddStringToObject(item, "mimeType", attachment->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // attachment->ocr_text
    if(attachment->ocr_text) {
    if(cJSON_AddStringToObject(item, "ocrText", attachment->ocr_text) == NULL) {
    goto fail; //String
    }
    }


    // attachment->original_name
    if (!attachment->original_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "originalName", attachment->original_name) == NULL) {
    goto fail; //String
    }


    // attachment->pdfa_path
    if(attachment->pdfa_path) {
    if(cJSON_AddStringToObject(item, "pdfaPath", attachment->pdfa_path) == NULL) {
    goto fail; //String
    }
    }


    // attachment->sha256_hash
    if(attachment->sha256_hash) {
    if(cJSON_AddStringToObject(item, "sha256Hash", attachment->sha256_hash) == NULL) {
    goto fail; //String
    }
    }


    // attachment->uploaded_by
    if(attachment->uploaded_by) {
    if(cJSON_AddStringToObject(item, "uploadedBy", attachment->uploaded_by) == NULL) {
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

attachment_t *attachment_parseFromJSON(cJSON *attachmentJSON){

    attachment_t *attachment_local_var = NULL;

    char *contact_id_local_str = NULL;

    char *file_name_local_str = NULL;

    // define the local variable for attachment->file_size
    long *file_size_local_var = NULL;

    char *mime_type_local_str = NULL;

    char *ocr_text_local_str = NULL;

    char *original_name_local_str = NULL;

    char *pdfa_path_local_str = NULL;

    char *sha256_hash_local_str = NULL;

    char *uploaded_by_local_str = NULL;

    // attachment->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // attachment->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "fileName");
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

    // attachment->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "fileSize");
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

    // attachment->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "mimeType");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // attachment->ocr_text
    cJSON *ocr_text = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "ocrText");
    if (cJSON_IsNull(ocr_text)) {
        ocr_text = NULL;
    }
    if (ocr_text) { 
    if(!cJSON_IsString(ocr_text) && !cJSON_IsNull(ocr_text))
    {
    goto end; //String
    }
    }

    // attachment->original_name
    cJSON *original_name = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "originalName");
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

    // attachment->pdfa_path
    cJSON *pdfa_path = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "pdfaPath");
    if (cJSON_IsNull(pdfa_path)) {
        pdfa_path = NULL;
    }
    if (pdfa_path) { 
    if(!cJSON_IsString(pdfa_path) && !cJSON_IsNull(pdfa_path))
    {
    goto end; //String
    }
    }

    // attachment->sha256_hash
    cJSON *sha256_hash = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "sha256Hash");
    if (cJSON_IsNull(sha256_hash)) {
        sha256_hash = NULL;
    }
    if (sha256_hash) { 
    if(!cJSON_IsString(sha256_hash) && !cJSON_IsNull(sha256_hash))
    {
    goto end; //String
    }
    }

    // attachment->uploaded_by
    cJSON *uploaded_by = cJSON_GetObjectItemCaseSensitive(attachmentJSON, "uploadedBy");
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
    if (ocr_text && !cJSON_IsNull(ocr_text)) ocr_text_local_str = strdup(ocr_text->valuestring);
    if (original_name && !cJSON_IsNull(original_name)) original_name_local_str = strdup(original_name->valuestring);
    if (pdfa_path && !cJSON_IsNull(pdfa_path)) pdfa_path_local_str = strdup(pdfa_path->valuestring);
    if (sha256_hash && !cJSON_IsNull(sha256_hash)) sha256_hash_local_str = strdup(sha256_hash->valuestring);
    if (uploaded_by && !cJSON_IsNull(uploaded_by)) uploaded_by_local_str = strdup(uploaded_by->valuestring);

    attachment_local_var = attachment_create_internal (
        contact_id_local_str,
        file_name_local_str,
        file_size_local_var,
        mime_type_local_str,
        ocr_text_local_str,
        original_name_local_str,
        pdfa_path_local_str,
        sha256_hash_local_str,
        uploaded_by_local_str
        );

    if (!attachment_local_var) {
        goto end;
    }

    return attachment_local_var;
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
    if (ocr_text_local_str) {
        free(ocr_text_local_str);
        ocr_text_local_str = NULL;
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
