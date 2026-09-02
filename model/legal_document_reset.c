#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "legal_document_reset.h"



static legal_document_reset_t *legal_document_reset_create_internal(
    char *doc_type,
    char *lang
    ) {
    legal_document_reset_t *legal_document_reset_local_var = malloc(sizeof(legal_document_reset_t));
    if (!legal_document_reset_local_var) {
        return NULL;
    }
    memset(legal_document_reset_local_var, 0, sizeof(legal_document_reset_t));
    legal_document_reset_local_var->_library_owned = 1;
    legal_document_reset_local_var->doc_type = doc_type;
    legal_document_reset_local_var->lang = lang;
    return legal_document_reset_local_var;
}

__attribute__((deprecated)) legal_document_reset_t *legal_document_reset_create(
    char *doc_type,
    char *lang
    ) {
    legal_document_reset_t *result = legal_document_reset_create_internal (
        doc_type,
        lang
        );
    if (!result) {
    }
    return result;
}

void legal_document_reset_free(legal_document_reset_t *legal_document_reset) {
    if(NULL == legal_document_reset){
        return ;
    }
    if(legal_document_reset->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "legal_document_reset_free");
        return ;
    }
    listEntry_t *listEntry;
    if (legal_document_reset->doc_type) {
        free(legal_document_reset->doc_type);
        legal_document_reset->doc_type = NULL;
    }
    if (legal_document_reset->lang) {
        free(legal_document_reset->lang);
        legal_document_reset->lang = NULL;
    }
    free(legal_document_reset);
}

cJSON *legal_document_reset_convertToJSON(legal_document_reset_t *legal_document_reset) {
    cJSON *item = cJSON_CreateObject();

    // legal_document_reset->doc_type
    if(legal_document_reset->doc_type) {
    if(cJSON_AddStringToObject(item, "docType", legal_document_reset->doc_type) == NULL) {
    goto fail; //String
    }
    }


    // legal_document_reset->lang
    if(legal_document_reset->lang) {
    if(cJSON_AddStringToObject(item, "lang", legal_document_reset->lang) == NULL) {
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

legal_document_reset_t *legal_document_reset_parseFromJSON(cJSON *legal_document_resetJSON){

    legal_document_reset_t *legal_document_reset_local_var = NULL;

    char *doc_type_local_str = NULL;

    char *lang_local_str = NULL;

    // legal_document_reset->doc_type
    cJSON *doc_type = cJSON_GetObjectItemCaseSensitive(legal_document_resetJSON, "docType");
    if (cJSON_IsNull(doc_type)) {
        doc_type = NULL;
    }
    if (doc_type) { 
    if(!cJSON_IsString(doc_type) && !cJSON_IsNull(doc_type))
    {
    goto end; //String
    }
    }

    // legal_document_reset->lang
    cJSON *lang = cJSON_GetObjectItemCaseSensitive(legal_document_resetJSON, "lang");
    if (cJSON_IsNull(lang)) {
        lang = NULL;
    }
    if (lang) { 
    if(!cJSON_IsString(lang) && !cJSON_IsNull(lang))
    {
    goto end; //String
    }
    }


    if (doc_type && !cJSON_IsNull(doc_type)) doc_type_local_str = strdup(doc_type->valuestring);
    if (lang && !cJSON_IsNull(lang)) lang_local_str = strdup(lang->valuestring);

    legal_document_reset_local_var = legal_document_reset_create_internal (
        doc_type_local_str,
        lang_local_str
        );

    if (!legal_document_reset_local_var) {
        goto end;
    }

    return legal_document_reset_local_var;
end:
    if (doc_type_local_str) {
        free(doc_type_local_str);
        doc_type_local_str = NULL;
    }
    if (lang_local_str) {
        free(lang_local_str);
        lang_local_str = NULL;
    }
    return NULL;

}
