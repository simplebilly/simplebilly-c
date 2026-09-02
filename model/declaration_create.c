#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "declaration_create.h"



static declaration_create_t *declaration_create_create_internal(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
    ) {
    declaration_create_t *declaration_create_local_var = malloc(sizeof(declaration_create_t));
    if (!declaration_create_local_var) {
        return NULL;
    }
    memset(declaration_create_local_var, 0, sizeof(declaration_create_t));
    declaration_create_local_var->_library_owned = 1;
    declaration_create_local_var->declaration_type = declaration_type;
    declaration_create_local_var->is_current = is_current;
    declaration_create_local_var->text = text;
    declaration_create_local_var->valid_from = valid_from;
    declaration_create_local_var->version = version;
    return declaration_create_local_var;
}

__attribute__((deprecated)) declaration_create_t *declaration_create_create(
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
    declaration_create_t *result = declaration_create_create_internal (
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

void declaration_create_free(declaration_create_t *declaration_create) {
    if(NULL == declaration_create){
        return ;
    }
    if(declaration_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "declaration_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (declaration_create->declaration_type) {
        declaration_type_free(declaration_create->declaration_type);
        declaration_create->declaration_type = NULL;
    }
    if (declaration_create->is_current) {
        free(declaration_create->is_current);
        declaration_create->is_current = NULL;
    }
    if (declaration_create->text) {
        free(declaration_create->text);
        declaration_create->text = NULL;
    }
    if (declaration_create->valid_from) {
        free(declaration_create->valid_from);
        declaration_create->valid_from = NULL;
    }
    if (declaration_create->version) {
        free(declaration_create->version);
        declaration_create->version = NULL;
    }
    free(declaration_create);
}

cJSON *declaration_create_convertToJSON(declaration_create_t *declaration_create) {
    cJSON *item = cJSON_CreateObject();

    // declaration_create->declaration_type
    if(declaration_create->declaration_type) {
    cJSON *declaration_type_local_JSON = declaration_type_convertToJSON(declaration_create->declaration_type);
    if(declaration_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "declarationType", declaration_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // declaration_create->is_current
    if(declaration_create->is_current) {
    if(cJSON_AddBoolToObject(item, "isCurrent", *declaration_create->is_current) == NULL) {
    goto fail; //Bool
    }
    }


    // declaration_create->text
    if(declaration_create->text) {
    if(cJSON_AddStringToObject(item, "text", declaration_create->text) == NULL) {
    goto fail; //String
    }
    }


    // declaration_create->valid_from
    if(declaration_create->valid_from) {
    if(cJSON_AddStringToObject(item, "validFrom", declaration_create->valid_from) == NULL) {
    goto fail; //Date
    }
    }


    // declaration_create->version
    if(declaration_create->version) {
    if(cJSON_AddStringToObject(item, "version", declaration_create->version) == NULL) {
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

declaration_create_t *declaration_create_parseFromJSON(cJSON *declaration_createJSON){

    declaration_create_t *declaration_create_local_var = NULL;

    // define the local variable for declaration_create->declaration_type
    declaration_type_t *declaration_type_local_nonprim = NULL;

    // define the local variable for declaration_create->is_current
    int *is_current_local_var = NULL;

    char *text_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *version_local_str = NULL;

    // declaration_create->declaration_type
    cJSON *declaration_type = cJSON_GetObjectItemCaseSensitive(declaration_createJSON, "declarationType");
    if (cJSON_IsNull(declaration_type)) {
        declaration_type = NULL;
    }
    if (declaration_type) { 
    declaration_type_local_nonprim = declaration_type_parseFromJSON(declaration_type); //custom
    }

    // declaration_create->is_current
    cJSON *is_current = cJSON_GetObjectItemCaseSensitive(declaration_createJSON, "isCurrent");
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

    // declaration_create->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(declaration_createJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // declaration_create->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(declaration_createJSON, "validFrom");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (valid_from) { 
    if(!cJSON_IsString(valid_from))
    {
    goto end; //Date
    }
    }

    // declaration_create->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(declaration_createJSON, "version");
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

    declaration_create_local_var = declaration_create_create_internal (
        declaration_type ? declaration_type_local_nonprim : NULL,
        is_current_local_var,
        text_local_str,
        valid_from_local_str,
        version_local_str
        );

    if (!declaration_create_local_var) {
        goto end;
    }

    return declaration_create_local_var;
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
