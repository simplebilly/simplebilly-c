#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_field_info.h"



static config_field_info_t *config_field_info_create_internal(
    config_field_kind_t *kind,
    char *label,
    char *name,
    char *placeholder,
    int *required
    ) {
    config_field_info_t *config_field_info_local_var = malloc(sizeof(config_field_info_t));
    if (!config_field_info_local_var) {
        return NULL;
    }
    memset(config_field_info_local_var, 0, sizeof(config_field_info_t));
    config_field_info_local_var->_library_owned = 1;
    config_field_info_local_var->kind = kind;
    config_field_info_local_var->label = label;
    config_field_info_local_var->name = name;
    config_field_info_local_var->placeholder = placeholder;
    config_field_info_local_var->required = required;
    return config_field_info_local_var;
}

__attribute__((deprecated)) config_field_info_t *config_field_info_create(
    config_field_kind_t *kind,
    char *label,
    char *name,
    char *placeholder,
    int *required
    ) {
    int *required_copy = NULL;
    if (required) {
        required_copy = malloc(sizeof(int));
        if (required_copy) *required_copy = *required;
    }
    config_field_info_t *result = config_field_info_create_internal (
        kind,
        label,
        name,
        placeholder,
        required_copy
        );
    if (!result) {
        free(required_copy);
    }
    return result;
}

void config_field_info_free(config_field_info_t *config_field_info) {
    if(NULL == config_field_info){
        return ;
    }
    if(config_field_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_field_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_field_info->kind) {
        config_field_kind_free(config_field_info->kind);
        config_field_info->kind = NULL;
    }
    if (config_field_info->label) {
        free(config_field_info->label);
        config_field_info->label = NULL;
    }
    if (config_field_info->name) {
        free(config_field_info->name);
        config_field_info->name = NULL;
    }
    if (config_field_info->placeholder) {
        free(config_field_info->placeholder);
        config_field_info->placeholder = NULL;
    }
    if (config_field_info->required) {
        free(config_field_info->required);
        config_field_info->required = NULL;
    }
    free(config_field_info);
}

cJSON *config_field_info_convertToJSON(config_field_info_t *config_field_info) {
    cJSON *item = cJSON_CreateObject();

    // config_field_info->kind
    if (!config_field_info->kind) {
        goto fail;
    }
    cJSON *kind_local_JSON = config_field_kind_convertToJSON(config_field_info->kind);
    if(kind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kind", kind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // config_field_info->label
    if (!config_field_info->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", config_field_info->label) == NULL) {
    goto fail; //String
    }


    // config_field_info->name
    if (!config_field_info->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", config_field_info->name) == NULL) {
    goto fail; //String
    }


    // config_field_info->placeholder
    if(config_field_info->placeholder) {
    if(cJSON_AddStringToObject(item, "placeholder", config_field_info->placeholder) == NULL) {
    goto fail; //String
    }
    }


    // config_field_info->required
    if (!config_field_info->required) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "required", *config_field_info->required) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

config_field_info_t *config_field_info_parseFromJSON(cJSON *config_field_infoJSON){

    config_field_info_t *config_field_info_local_var = NULL;

    // define the local variable for config_field_info->kind
    config_field_kind_t *kind_local_nonprim = NULL;

    char *label_local_str = NULL;

    char *name_local_str = NULL;

    char *placeholder_local_str = NULL;

    // define the local variable for config_field_info->required
    int *required_local_var = NULL;

    // config_field_info->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(config_field_infoJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    kind_local_nonprim = config_field_kind_parseFromJSON(kind); //nonprimitive

    // config_field_info->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(config_field_infoJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // config_field_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(config_field_infoJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // config_field_info->placeholder
    cJSON *placeholder = cJSON_GetObjectItemCaseSensitive(config_field_infoJSON, "placeholder");
    if (cJSON_IsNull(placeholder)) {
        placeholder = NULL;
    }
    if (placeholder) { 
    if(!cJSON_IsString(placeholder) && !cJSON_IsNull(placeholder))
    {
    goto end; //String
    }
    }

    // config_field_info->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(config_field_infoJSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (!required) {
        goto end;
    }

    
    if(!cJSON_IsBool(required))
    {
    goto end; //Bool
    }
    required_local_var = malloc(sizeof(int));
    if(!required_local_var)
    {
        goto end;
    }
    *required_local_var = required->valueint;


    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (placeholder && !cJSON_IsNull(placeholder)) placeholder_local_str = strdup(placeholder->valuestring);

    config_field_info_local_var = config_field_info_create_internal (
        kind_local_nonprim,
        label_local_str,
        name_local_str,
        placeholder_local_str,
        required_local_var
        );

    if (!config_field_info_local_var) {
        goto end;
    }

    return config_field_info_local_var;
end:
    if (kind_local_nonprim) {
        config_field_kind_free(kind_local_nonprim);
        kind_local_nonprim = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (placeholder_local_str) {
        free(placeholder_local_str);
        placeholder_local_str = NULL;
    }
    if (required_local_var) {
        free(required_local_var);
        required_local_var = NULL;
    }
    return NULL;

}
