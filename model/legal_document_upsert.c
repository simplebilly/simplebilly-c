#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "legal_document_upsert.h"



static legal_document_upsert_t *legal_document_upsert_create_internal(
    char *content,
    char *doc_type,
    char *lang,
    char *title
    ) {
    legal_document_upsert_t *legal_document_upsert_local_var = malloc(sizeof(legal_document_upsert_t));
    if (!legal_document_upsert_local_var) {
        return NULL;
    }
    memset(legal_document_upsert_local_var, 0, sizeof(legal_document_upsert_t));
    legal_document_upsert_local_var->_library_owned = 1;
    legal_document_upsert_local_var->content = content;
    legal_document_upsert_local_var->doc_type = doc_type;
    legal_document_upsert_local_var->lang = lang;
    legal_document_upsert_local_var->title = title;
    return legal_document_upsert_local_var;
}

__attribute__((deprecated)) legal_document_upsert_t *legal_document_upsert_create(
    char *content,
    char *doc_type,
    char *lang,
    char *title
    ) {
    legal_document_upsert_t *result = legal_document_upsert_create_internal (
        content,
        doc_type,
        lang,
        title
        );
    if (!result) {
    }
    return result;
}

void legal_document_upsert_free(legal_document_upsert_t *legal_document_upsert) {
    if(NULL == legal_document_upsert){
        return ;
    }
    if(legal_document_upsert->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "legal_document_upsert_free");
        return ;
    }
    listEntry_t *listEntry;
    if (legal_document_upsert->content) {
        free(legal_document_upsert->content);
        legal_document_upsert->content = NULL;
    }
    if (legal_document_upsert->doc_type) {
        free(legal_document_upsert->doc_type);
        legal_document_upsert->doc_type = NULL;
    }
    if (legal_document_upsert->lang) {
        free(legal_document_upsert->lang);
        legal_document_upsert->lang = NULL;
    }
    if (legal_document_upsert->title) {
        free(legal_document_upsert->title);
        legal_document_upsert->title = NULL;
    }
    free(legal_document_upsert);
}

cJSON *legal_document_upsert_convertToJSON(legal_document_upsert_t *legal_document_upsert) {
    cJSON *item = cJSON_CreateObject();

    // legal_document_upsert->content
    if (!legal_document_upsert->content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content", legal_document_upsert->content) == NULL) {
    goto fail; //String
    }


    // legal_document_upsert->doc_type
    if (!legal_document_upsert->doc_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "docType", legal_document_upsert->doc_type) == NULL) {
    goto fail; //String
    }


    // legal_document_upsert->lang
    if (!legal_document_upsert->lang) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lang", legal_document_upsert->lang) == NULL) {
    goto fail; //String
    }


    // legal_document_upsert->title
    if (!legal_document_upsert->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", legal_document_upsert->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

legal_document_upsert_t *legal_document_upsert_parseFromJSON(cJSON *legal_document_upsertJSON){

    legal_document_upsert_t *legal_document_upsert_local_var = NULL;

    char *content_local_str = NULL;

    char *doc_type_local_str = NULL;

    char *lang_local_str = NULL;

    char *title_local_str = NULL;

    // legal_document_upsert->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(legal_document_upsertJSON, "content");
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

    // legal_document_upsert->doc_type
    cJSON *doc_type = cJSON_GetObjectItemCaseSensitive(legal_document_upsertJSON, "docType");
    if (cJSON_IsNull(doc_type)) {
        doc_type = NULL;
    }
    if (!doc_type) {
        goto end;
    }

    
    if(!cJSON_IsString(doc_type))
    {
    goto end; //String
    }

    // legal_document_upsert->lang
    cJSON *lang = cJSON_GetObjectItemCaseSensitive(legal_document_upsertJSON, "lang");
    if (cJSON_IsNull(lang)) {
        lang = NULL;
    }
    if (!lang) {
        goto end;
    }

    
    if(!cJSON_IsString(lang))
    {
    goto end; //String
    }

    // legal_document_upsert->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(legal_document_upsertJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }


    if (content && !cJSON_IsNull(content)) content_local_str = strdup(content->valuestring);
    if (doc_type && !cJSON_IsNull(doc_type)) doc_type_local_str = strdup(doc_type->valuestring);
    if (lang && !cJSON_IsNull(lang)) lang_local_str = strdup(lang->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    legal_document_upsert_local_var = legal_document_upsert_create_internal (
        content_local_str,
        doc_type_local_str,
        lang_local_str,
        title_local_str
        );

    if (!legal_document_upsert_local_var) {
        goto end;
    }

    return legal_document_upsert_local_var;
end:
    if (content_local_str) {
        free(content_local_str);
        content_local_str = NULL;
    }
    if (doc_type_local_str) {
        free(doc_type_local_str);
        doc_type_local_str = NULL;
    }
    if (lang_local_str) {
        free(lang_local_str);
        lang_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    return NULL;

}
