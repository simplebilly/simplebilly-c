#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "declaration_update.h"



static declaration_update_t *declaration_update_create_internal(
    declaration_type_t *declaration_type,
    int *is_current,
    char *text,
    char *valid_from,
    char *version
    ) {
    declaration_update_t *declaration_update_local_var = malloc(sizeof(declaration_update_t));
    if (!declaration_update_local_var) {
        return NULL;
    }
    memset(declaration_update_local_var, 0, sizeof(declaration_update_t));
    declaration_update_local_var->_library_owned = 1;
    declaration_update_local_var->declaration_type = declaration_type;
    declaration_update_local_var->is_current = is_current;
    declaration_update_local_var->text = text;
    declaration_update_local_var->valid_from = valid_from;
    declaration_update_local_var->version = version;
    return declaration_update_local_var;
}

__attribute__((deprecated)) declaration_update_t *declaration_update_create(
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
    declaration_update_t *result = declaration_update_create_internal (
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

void declaration_update_free(declaration_update_t *declaration_update) {
    if(NULL == declaration_update){
        return ;
    }
    if(declaration_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "declaration_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (declaration_update->declaration_type) {
        declaration_type_free(declaration_update->declaration_type);
        declaration_update->declaration_type = NULL;
    }
    if (declaration_update->is_current) {
        free(declaration_update->is_current);
        declaration_update->is_current = NULL;
    }
    if (declaration_update->text) {
        free(declaration_update->text);
        declaration_update->text = NULL;
    }
    if (declaration_update->valid_from) {
        free(declaration_update->valid_from);
        declaration_update->valid_from = NULL;
    }
    if (declaration_update->version) {
        free(declaration_update->version);
        declaration_update->version = NULL;
    }
    free(declaration_update);
}

cJSON *declaration_update_convertToJSON(declaration_update_t *declaration_update) {
    cJSON *item = cJSON_CreateObject();

    // declaration_update->declaration_type
    if(declaration_update->declaration_type) {
    cJSON *declaration_type_local_JSON = declaration_type_convertToJSON(declaration_update->declaration_type);
    if(declaration_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "declarationType", declaration_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // declaration_update->is_current
    if(declaration_update->is_current) {
    if(cJSON_AddBoolToObject(item, "isCurrent", *declaration_update->is_current) == NULL) {
    goto fail; //Bool
    }
    }


    // declaration_update->text
    if(declaration_update->text) {
    if(cJSON_AddStringToObject(item, "text", declaration_update->text) == NULL) {
    goto fail; //String
    }
    }


    // declaration_update->valid_from
    if(declaration_update->valid_from) {
    if(cJSON_AddStringToObject(item, "validFrom", declaration_update->valid_from) == NULL) {
    goto fail; //Date
    }
    }


    // declaration_update->version
    if(declaration_update->version) {
    if(cJSON_AddStringToObject(item, "version", declaration_update->version) == NULL) {
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

declaration_update_t *declaration_update_parseFromJSON(cJSON *declaration_updateJSON){

    declaration_update_t *declaration_update_local_var = NULL;

    // define the local variable for declaration_update->declaration_type
    declaration_type_t *declaration_type_local_nonprim = NULL;

    // define the local variable for declaration_update->is_current
    int *is_current_local_var = NULL;

    char *text_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *version_local_str = NULL;

    // declaration_update->declaration_type
    cJSON *declaration_type = cJSON_GetObjectItemCaseSensitive(declaration_updateJSON, "declarationType");
    if (cJSON_IsNull(declaration_type)) {
        declaration_type = NULL;
    }
    if (declaration_type) { 
    declaration_type_local_nonprim = declaration_type_parseFromJSON(declaration_type); //custom
    }

    // declaration_update->is_current
    cJSON *is_current = cJSON_GetObjectItemCaseSensitive(declaration_updateJSON, "isCurrent");
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

    // declaration_update->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(declaration_updateJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // declaration_update->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(declaration_updateJSON, "validFrom");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (valid_from) { 
    if(!cJSON_IsString(valid_from))
    {
    goto end; //Date
    }
    }

    // declaration_update->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(declaration_updateJSON, "version");
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

    declaration_update_local_var = declaration_update_create_internal (
        declaration_type ? declaration_type_local_nonprim : NULL,
        is_current_local_var,
        text_local_str,
        valid_from_local_str,
        version_local_str
        );

    if (!declaration_update_local_var) {
        goto end;
    }

    return declaration_update_local_var;
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
