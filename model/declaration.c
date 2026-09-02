#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "declaration.h"



static declaration_t *declaration_create_internal(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
    ) {
    declaration_t *declaration_local_var = malloc(sizeof(declaration_t));
    if (!declaration_local_var) {
        return NULL;
    }
    memset(declaration_local_var, 0, sizeof(declaration_t));
    declaration_local_var->_library_owned = 1;
    declaration_local_var->declaration_type = declaration_type;
    declaration_local_var->is_current = is_current;
    declaration_local_var->text = text;
    declaration_local_var->valid_from = valid_from;
    declaration_local_var->version = version;
    return declaration_local_var;
}

__attribute__((deprecated)) declaration_t *declaration_create(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
    ) {
    int *is_current_copy = NULL;
    if (is_current) {
        is_current_copy = malloc(sizeof(int));
        if (is_current_copy) *is_current_copy = *is_current;
    }
    declaration_t *result = declaration_create_internal (
        declaration_type,
        is_current_copy,
        text,
        valid_from,
        version
        );
    if (!result) {
        free(is_current_copy);
    }
    return result;
}

void declaration_free(declaration_t *declaration) {
    if(NULL == declaration){
        return ;
    }
    if(declaration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "declaration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (declaration->declaration_type) {
        declaration_type_free(declaration->declaration_type);
        declaration->declaration_type = NULL;
    }
    if (declaration->is_current) {
        free(declaration->is_current);
        declaration->is_current = NULL;
    }
    if (declaration->text) {
        free(declaration->text);
        declaration->text = NULL;
    }
    if (declaration->valid_from) {
        free(declaration->valid_from);
        declaration->valid_from = NULL;
    }
    if (declaration->version) {
        free(declaration->version);
        declaration->version = NULL;
    }
    free(declaration);
}

cJSON *declaration_convertToJSON(declaration_t *declaration) {
    cJSON *item = cJSON_CreateObject();

    // declaration->declaration_type
    if(declaration->declaration_type) {
    cJSON *declaration_type_local_JSON = declaration_type_convertToJSON(declaration->declaration_type);
    if(declaration_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "declarationType", declaration_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // declaration->is_current
    if(declaration->is_current) {
    if(cJSON_AddBoolToObject(item, "isCurrent", *declaration->is_current) == NULL) {
    goto fail; //Bool
    }
    }


    // declaration->text
    if(declaration->text) {
    if(cJSON_AddStringToObject(item, "text", declaration->text) == NULL) {
    goto fail; //String
    }
    }


    // declaration->valid_from
    if(declaration->valid_from) {
    if(cJSON_AddStringToObject(item, "validFrom", declaration->valid_from) == NULL) {
    goto fail; //Date
    }
    }


    // declaration->version
    if(declaration->version) {
    if(cJSON_AddStringToObject(item, "version", declaration->version) == NULL) {
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

declaration_t *declaration_parseFromJSON(cJSON *declarationJSON){

    declaration_t *declaration_local_var = NULL;

    // define the local variable for declaration->declaration_type
    declaration_type_t *declaration_type_local_nonprim = NULL;

    // define the local variable for declaration->is_current
    int *is_current_local_var = NULL;

    char *text_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *version_local_str = NULL;

    // declaration->declaration_type
    cJSON *declaration_type = cJSON_GetObjectItemCaseSensitive(declarationJSON, "declarationType");
    if (cJSON_IsNull(declaration_type)) {
        declaration_type = NULL;
    }
    if (declaration_type) { 
    declaration_type_local_nonprim = declaration_type_parseFromJSON(declaration_type); //custom
    }

    // declaration->is_current
    cJSON *is_current = cJSON_GetObjectItemCaseSensitive(declarationJSON, "isCurrent");
    if (cJSON_IsNull(is_current)) {
        is_current = NULL;
    }
    if (is_current) { 
    if(!cJSON_IsBool(is_current))
    {
    goto end; //Bool
    }
    is_current_local_var = malloc(sizeof(int));
    if(!is_current_local_var)
    {
        goto end;
    }
    *is_current_local_var = is_current->valueint;
    }

    // declaration->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(declarationJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // declaration->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(declarationJSON, "validFrom");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (valid_from) { 
    if(!cJSON_IsString(valid_from))
    {
    goto end; //Date
    }
    }

    // declaration->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(declarationJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    if (text && !cJSON_IsNull(text)) text_local_str = strdup(text->valuestring);
    if (valid_from) valid_from_local_str = strdup(valid_from->valuestring);
    if (version && !cJSON_IsNull(version)) version_local_str = strdup(version->valuestring);

    declaration_local_var = declaration_create_internal (
        declaration_type ? declaration_type_local_nonprim : NULL,
        is_current_local_var,
        text_local_str,
        valid_from_local_str,
        version_local_str
        );

    if (!declaration_local_var) {
        goto end;
    }

    return declaration_local_var;
end:
    if (declaration_type_local_nonprim) {
        declaration_type_free(declaration_type_local_nonprim);
        declaration_type_local_nonprim = NULL;
    }
    if (is_current_local_var) {
        free(is_current_local_var);
        is_current_local_var = NULL;
    }
    if (text_local_str) {
        free(text_local_str);
        text_local_str = NULL;
    }
    if (valid_from_local_str) {
        free(valid_from_local_str);
        valid_from_local_str = NULL;
    }
    if (version_local_str) {
        free(version_local_str);
        version_local_str = NULL;
    }
    return NULL;

}
