#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "support_channel.h"



static support_channel_t *support_channel_create_internal(
    simplebilly_api_support_channel_type__e channel_type,
    any_type_t *config,
    char *created_at,
    int *is_active,
    char *name,
    char *tenant_id,
    char *updated_at
    ) {
    support_channel_t *support_channel_local_var = malloc(sizeof(support_channel_t));
    if (!support_channel_local_var) {
        return NULL;
    }
    memset(support_channel_local_var, 0, sizeof(support_channel_t));
    support_channel_local_var->_library_owned = 1;
    support_channel_local_var->channel_type = channel_type;
    support_channel_local_var->config = config;
    support_channel_local_var->created_at = created_at;
    support_channel_local_var->is_active = is_active;
    support_channel_local_var->name = name;
    support_channel_local_var->tenant_id = tenant_id;
    support_channel_local_var->updated_at = updated_at;
    return support_channel_local_var;
}

__attribute__((deprecated)) support_channel_t *support_channel_create(
    simplebilly_api_support_channel_type__e channel_type,
    any_type_t *config,
    char *created_at,
    int *is_active,
    char *name,
    char *tenant_id,
    char *updated_at
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    support_channel_t *result = support_channel_create_internal (
        channel_type,
        config,
        created_at,
        is_active_copy,
        name,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void support_channel_free(support_channel_t *support_channel) {
    if(NULL == support_channel){
        return ;
    }
    if(support_channel->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "support_channel_free");
        return ;
    }
    listEntry_t *listEntry;
    if (support_channel->config) {
        _free(support_channel->config);
        support_channel->config = NULL;
    }
    if (support_channel->created_at) {
        free(support_channel->created_at);
        support_channel->created_at = NULL;
    }
    if (support_channel->is_active) {
        free(support_channel->is_active);
        support_channel->is_active = NULL;
    }
    if (support_channel->name) {
        free(support_channel->name);
        support_channel->name = NULL;
    }
    if (support_channel->tenant_id) {
        free(support_channel->tenant_id);
        support_channel->tenant_id = NULL;
    }
    if (support_channel->updated_at) {
        free(support_channel->updated_at);
        support_channel->updated_at = NULL;
    }
    free(support_channel);
}

cJSON *support_channel_convertToJSON(support_channel_t *support_channel) {
    cJSON *item = cJSON_CreateObject();

    // support_channel->channel_type
    if (simplebilly_api_support_channel_type__NULL == support_channel->channel_type) {
        goto fail;
    }
    cJSON *channel_type_local_JSON = support_channel_type_convertToJSON(support_channel->channel_type);
    if(channel_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "channelType", channel_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // support_channel->config
    if (!support_channel->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(support_channel->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // support_channel->created_at
    if (!support_channel->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", support_channel->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // support_channel->is_active
    if (!support_channel->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isActive", *support_channel->is_active) == NULL) {
    goto fail; //Bool
    }


    // support_channel->name
    if (!support_channel->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", support_channel->name) == NULL) {
    goto fail; //String
    }


    // support_channel->tenant_id
    if (!support_channel->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", support_channel->tenant_id) == NULL) {
    goto fail; //String
    }


    // support_channel->updated_at
    if(support_channel->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", support_channel->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

support_channel_t *support_channel_parseFromJSON(cJSON *support_channelJSON){

    support_channel_t *support_channel_local_var = NULL;

    // define the local variable for support_channel->channel_type
    simplebilly_api_support_channel_type__e channel_type_local_nonprim = 0;

    // define the local variable for support_channel->config
    _t *config_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    // define the local variable for support_channel->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // support_channel->channel_type
    cJSON *channel_type = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "channelType");
    if (cJSON_IsNull(channel_type)) {
        channel_type = NULL;
    }
    if (!channel_type) {
        goto end;
    }

    
    channel_type_local_nonprim = support_channel_type_parseFromJSON(channel_type); //custom

    // support_channel->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // support_channel->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // support_channel->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "isActive");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (!is_active) {
        goto end;
    }

    
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

    // support_channel->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "name");
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

    // support_channel->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // support_channel->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(support_channelJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    support_channel_local_var = support_channel_create_internal (
        channel_type_local_nonprim,
        config_local_nonprim,
        created_at_local_str,
        is_active_local_var,
        name_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!support_channel_local_var) {
        goto end;
    }

    return support_channel_local_var;
end:
    if (channel_type_local_nonprim) {
        channel_type_local_nonprim = 0;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
