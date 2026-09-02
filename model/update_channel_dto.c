#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_channel_dto.h"



static update_channel_dto_t *update_channel_dto_create_internal(
    any_type_t *config,
    int *is_active,
    char *name
    ) {
    update_channel_dto_t *update_channel_dto_local_var = malloc(sizeof(update_channel_dto_t));
    if (!update_channel_dto_local_var) {
        return NULL;
    }
    memset(update_channel_dto_local_var, 0, sizeof(update_channel_dto_t));
    update_channel_dto_local_var->_library_owned = 1;
    update_channel_dto_local_var->config = config;
    update_channel_dto_local_var->is_active = is_active;
    update_channel_dto_local_var->name = name;
    return update_channel_dto_local_var;
}

__attribute__((deprecated)) update_channel_dto_t *update_channel_dto_create(
    any_type_t *config,
    int *is_active,
    char *name
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    update_channel_dto_t *result = update_channel_dto_create_internal (
        config,
        is_active_copy,
        name
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void update_channel_dto_free(update_channel_dto_t *update_channel_dto) {
    if(NULL == update_channel_dto){
        return ;
    }
    if(update_channel_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_channel_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_channel_dto->config) {
        _free(update_channel_dto->config);
        update_channel_dto->config = NULL;
    }
    if (update_channel_dto->is_active) {
        free(update_channel_dto->is_active);
        update_channel_dto->is_active = NULL;
    }
    if (update_channel_dto->name) {
        free(update_channel_dto->name);
        update_channel_dto->name = NULL;
    }
    free(update_channel_dto);
}

cJSON *update_channel_dto_convertToJSON(update_channel_dto_t *update_channel_dto) {
    cJSON *item = cJSON_CreateObject();

    // update_channel_dto->config
    if(update_channel_dto->config) {
    cJSON *config_local_JSON = _convertToJSON(update_channel_dto->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // update_channel_dto->is_active
    if(update_channel_dto->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *update_channel_dto->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // update_channel_dto->name
    if(update_channel_dto->name) {
    if(cJSON_AddStringToObject(item, "name", update_channel_dto->name) == NULL) {
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

update_channel_dto_t *update_channel_dto_parseFromJSON(cJSON *update_channel_dtoJSON){

    update_channel_dto_t *update_channel_dto_local_var = NULL;

    // define the local variable for update_channel_dto->config
    _t *config_local_nonprim = NULL;

    // define the local variable for update_channel_dto->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    // update_channel_dto->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_channel_dtoJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // update_channel_dto->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(update_channel_dtoJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // update_channel_dto->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_channel_dtoJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    update_channel_dto_local_var = update_channel_dto_create_internal (
        config ? config_local_nonprim : NULL,
        is_active_local_var,
        name_local_str
        );

    if (!update_channel_dto_local_var) {
        goto end;
    }

    return update_channel_dto_local_var;
end:
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
