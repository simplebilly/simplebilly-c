#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_channel_dto.h"



static create_channel_dto_t *create_channel_dto_create_internal(
    char *channel_type,
    any_type_t *config,
    char *name
    ) {
    create_channel_dto_t *create_channel_dto_local_var = malloc(sizeof(create_channel_dto_t));
    if (!create_channel_dto_local_var) {
        return NULL;
    }
    memset(create_channel_dto_local_var, 0, sizeof(create_channel_dto_t));
    create_channel_dto_local_var->_library_owned = 1;
    create_channel_dto_local_var->channel_type = channel_type;
    create_channel_dto_local_var->config = config;
    create_channel_dto_local_var->name = name;
    return create_channel_dto_local_var;
}

__attribute__((deprecated)) create_channel_dto_t *create_channel_dto_create(
    char *channel_type,
    any_type_t *config,
    char *name
    ) {
    create_channel_dto_t *result = create_channel_dto_create_internal (
        channel_type,
        config,
        name
        );
    if (!result) {
    }
    return result;
}

void create_channel_dto_free(create_channel_dto_t *create_channel_dto) {
    if(NULL == create_channel_dto){
        return ;
    }
    if(create_channel_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_channel_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_channel_dto->channel_type) {
        free(create_channel_dto->channel_type);
        create_channel_dto->channel_type = NULL;
    }
    if (create_channel_dto->config) {
        _free(create_channel_dto->config);
        create_channel_dto->config = NULL;
    }
    if (create_channel_dto->name) {
        free(create_channel_dto->name);
        create_channel_dto->name = NULL;
    }
    free(create_channel_dto);
}

cJSON *create_channel_dto_convertToJSON(create_channel_dto_t *create_channel_dto) {
    cJSON *item = cJSON_CreateObject();

    // create_channel_dto->channel_type
    if (!create_channel_dto->channel_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "channel_type", create_channel_dto->channel_type) == NULL) {
    goto fail; //String
    }


    // create_channel_dto->config
    if (!create_channel_dto->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(create_channel_dto->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // create_channel_dto->name
    if (!create_channel_dto->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_channel_dto->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_channel_dto_t *create_channel_dto_parseFromJSON(cJSON *create_channel_dtoJSON){

    create_channel_dto_t *create_channel_dto_local_var = NULL;

    char *channel_type_local_str = NULL;

    // define the local variable for create_channel_dto->config
    _t *config_local_nonprim = NULL;

    char *name_local_str = NULL;

    // create_channel_dto->channel_type
    cJSON *channel_type = cJSON_GetObjectItemCaseSensitive(create_channel_dtoJSON, "channel_type");
    if (cJSON_IsNull(channel_type)) {
        channel_type = NULL;
    }
    if (!channel_type) {
        goto end;
    }

    
    if(!cJSON_IsString(channel_type))
    {
    goto end; //String
    }

    // create_channel_dto->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_channel_dtoJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // create_channel_dto->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_channel_dtoJSON, "name");
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


    if (channel_type && !cJSON_IsNull(channel_type)) channel_type_local_str = strdup(channel_type->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    create_channel_dto_local_var = create_channel_dto_create_internal (
        channel_type_local_str,
        config_local_nonprim,
        name_local_str
        );

    if (!create_channel_dto_local_var) {
        goto end;
    }

    return create_channel_dto_local_var;
end:
    if (channel_type_local_str) {
        free(channel_type_local_str);
        channel_type_local_str = NULL;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
