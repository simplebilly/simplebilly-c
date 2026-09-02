#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "legal_document.h"



static legal_document_t *legal_document_create_internal(
    char *content,
    simplebilly_api_legal_doc_type__e doc_type,
    simplebilly_api_language_code__e lang,
    char *title
    ) {
    legal_document_t *legal_document_local_var = malloc(sizeof(legal_document_t));
    if (!legal_document_local_var) {
        return NULL;
    }
    memset(legal_document_local_var, 0, sizeof(legal_document_t));
    legal_document_local_var->_library_owned = 1;
    legal_document_local_var->content = content;
    legal_document_local_var->doc_type = doc_type;
    legal_document_local_var->lang = lang;
    legal_document_local_var->title = title;
    return legal_document_local_var;
}

__attribute__((deprecated)) legal_document_t *legal_document_create(
    char *content,
    simplebilly_api_legal_doc_type__e doc_type,
    simplebilly_api_language_code__e lang,
    char *title
    ) {
    legal_document_t *result = legal_document_create_internal (
        content,
        doc_type,
        lang,
        title
        );
    if (!result) {
    }
    return result;
}

void legal_document_free(legal_document_t *legal_document) {
    if(NULL == legal_document){
        return ;
    }
    if(legal_document->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "legal_document_free");
        return ;
    }
    listEntry_t *listEntry;
    if (legal_document->content) {
        free(legal_document->content);
        legal_document->content = NULL;
    }
    if (legal_document->title) {
        free(legal_document->title);
        legal_document->title = NULL;
    }
    free(legal_document);
}

cJSON *legal_document_convertToJSON(legal_document_t *legal_document) {
    cJSON *item = cJSON_CreateObject();

    // legal_document->content
    if (!legal_document->content) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "content", legal_document->content) == NULL) {
    goto fail; //String
    }


    // legal_document->doc_type
    if (simplebilly_api_legal_doc_type__NULL == legal_document->doc_type) {
        goto fail;
    }
    cJSON *doc_type_local_JSON = legal_doc_type_convertToJSON(legal_document->doc_type);
    if(doc_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "docType", doc_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // legal_document->lang
    if (simplebilly_api_language_code__NULL == legal_document->lang) {
        goto fail;
    }
    cJSON *lang_local_JSON = language_code_convertToJSON(legal_document->lang);
    if(lang_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "lang", lang_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // legal_document->title
    if (!legal_document->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", legal_document->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

legal_document_t *legal_document_parseFromJSON(cJSON *legal_documentJSON){

    legal_document_t *legal_document_local_var = NULL;

    char *content_local_str = NULL;

    // define the local variable for legal_document->doc_type
    simplebilly_api_legal_doc_type__e doc_type_local_nonprim = 0;

    // define the local variable for legal_document->lang
    simplebilly_api_language_code__e lang_local_nonprim = 0;

    char *title_local_str = NULL;

    // legal_document->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(legal_documentJSON, "content");
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

    // legal_document->doc_type
    cJSON *doc_type = cJSON_GetObjectItemCaseSensitive(legal_documentJSON, "docType");
    if (cJSON_IsNull(doc_type)) {
        doc_type = NULL;
    }
    if (!doc_type) {
        goto end;
    }

    
    doc_type_local_nonprim = legal_doc_type_parseFromJSON(doc_type); //custom

    // legal_document->lang
    cJSON *lang = cJSON_GetObjectItemCaseSensitive(legal_documentJSON, "lang");
    if (cJSON_IsNull(lang)) {
        lang = NULL;
    }
    if (!lang) {
        goto end;
    }

    
    lang_local_nonprim = language_code_parseFromJSON(lang); //custom

    // legal_document->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(legal_documentJSON, "title");
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
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    legal_document_local_var = legal_document_create_internal (
        content_local_str,
        doc_type_local_nonprim,
        lang_local_nonprim,
        title_local_str
        );

    if (!legal_document_local_var) {
        goto end;
    }

    return legal_document_local_var;
end:
    if (content_local_str) {
        free(content_local_str);
        content_local_str = NULL;
    }
    if (doc_type_local_nonprim) {
        doc_type_local_nonprim = 0;
    }
    if (lang_local_nonprim) {
        lang_local_nonprim = 0;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    return NULL;

}
