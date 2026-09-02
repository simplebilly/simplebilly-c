#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_worker_config.h"



static ai_worker_config_t *ai_worker_config_create_internal(
    int *auto_reply,
    char *created_at,
    char *id,
    int *is_active,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    char *tenant_id,
    list_t *trigger_on,
    char *updated_at
    ) {
    ai_worker_config_t *ai_worker_config_local_var = malloc(sizeof(ai_worker_config_t));
    if (!ai_worker_config_local_var) {
        return NULL;
    }
    memset(ai_worker_config_local_var, 0, sizeof(ai_worker_config_t));
    ai_worker_config_local_var->_library_owned = 1;
    ai_worker_config_local_var->auto_reply = auto_reply;
    ai_worker_config_local_var->created_at = created_at;
    ai_worker_config_local_var->id = id;
    ai_worker_config_local_var->is_active = is_active;
    ai_worker_config_local_var->max_tool_calls = max_tool_calls;
    ai_worker_config_local_var->model = model;
    ai_worker_config_local_var->name = name;
    ai_worker_config_local_var->provider = provider;
    ai_worker_config_local_var->system_prompt = system_prompt;
    ai_worker_config_local_var->tenant_id = tenant_id;
    ai_worker_config_local_var->trigger_on = trigger_on;
    ai_worker_config_local_var->updated_at = updated_at;
    return ai_worker_config_local_var;
}

__attribute__((deprecated)) ai_worker_config_t *ai_worker_config_create(
    int *auto_reply,
    char *created_at,
    char *id,
    int *is_active,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    char *tenant_id,
    list_t *trigger_on,
    char *updated_at
    ) {
    int *auto_reply_copy = NULL;
    if (auto_reply) {
        auto_reply_copy = malloc(sizeof(int));
        if (auto_reply_copy) *auto_reply_copy = *auto_reply;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *max_tool_calls_copy = NULL;
    if (max_tool_calls) {
        max_tool_calls_copy = malloc(sizeof(int));
        if (max_tool_calls_copy) *max_tool_calls_copy = *max_tool_calls;
    }
    ai_worker_config_t *result = ai_worker_config_create_internal (
        auto_reply_copy,
        created_at,
        id,
        is_active_copy,
        max_tool_calls_copy,
        model,
        name,
        provider,
        system_prompt,
        tenant_id,
        trigger_on,
        updated_at
        );
    if (!result) {
        free(auto_reply_copy);
        free(is_active_copy);
        free(max_tool_calls_copy);
    }
    return result;
}

void ai_worker_config_free(ai_worker_config_t *ai_worker_config) {
    if(NULL == ai_worker_config){
        return ;
    }
    if(ai_worker_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_worker_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ai_worker_config->auto_reply) {
        free(ai_worker_config->auto_reply);
        ai_worker_config->auto_reply = NULL;
    }
    if (ai_worker_config->created_at) {
        free(ai_worker_config->created_at);
        ai_worker_config->created_at = NULL;
    }
    if (ai_worker_config->id) {
        free(ai_worker_config->id);
        ai_worker_config->id = NULL;
    }
    if (ai_worker_config->is_active) {
        free(ai_worker_config->is_active);
        ai_worker_config->is_active = NULL;
    }
    if (ai_worker_config->max_tool_calls) {
        free(ai_worker_config->max_tool_calls);
        ai_worker_config->max_tool_calls = NULL;
    }
    if (ai_worker_config->model) {
        free(ai_worker_config->model);
        ai_worker_config->model = NULL;
    }
    if (ai_worker_config->name) {
        free(ai_worker_config->name);
        ai_worker_config->name = NULL;
    }
    if (ai_worker_config->provider) {
        free(ai_worker_config->provider);
        ai_worker_config->provider = NULL;
    }
    if (ai_worker_config->system_prompt) {
        free(ai_worker_config->system_prompt);
        ai_worker_config->system_prompt = NULL;
    }
    if (ai_worker_config->tenant_id) {
        free(ai_worker_config->tenant_id);
        ai_worker_config->tenant_id = NULL;
    }
    if (ai_worker_config->trigger_on) {
        list_ForEach(listEntry, ai_worker_config->trigger_on) {
            free(listEntry->data);
        }
        list_freeList(ai_worker_config->trigger_on);
        ai_worker_config->trigger_on = NULL;
    }
    if (ai_worker_config->updated_at) {
        free(ai_worker_config->updated_at);
        ai_worker_config->updated_at = NULL;
    }
    free(ai_worker_config);
}

cJSON *ai_worker_config_convertToJSON(ai_worker_config_t *ai_worker_config) {
    cJSON *item = cJSON_CreateObject();

    // ai_worker_config->auto_reply
    if (!ai_worker_config->auto_reply) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "auto_reply", *ai_worker_config->auto_reply) == NULL) {
    goto fail; //Bool
    }


    // ai_worker_config->created_at
    if (!ai_worker_config->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", ai_worker_config->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // ai_worker_config->id
    if (!ai_worker_config->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ai_worker_config->id) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->is_active
    if (!ai_worker_config->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *ai_worker_config->is_active) == NULL) {
    goto fail; //Bool
    }


    // ai_worker_config->max_tool_calls
    if (!ai_worker_config->max_tool_calls) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "max_tool_calls", *ai_worker_config->max_tool_calls) == NULL) {
    goto fail; //Numeric
    }


    // ai_worker_config->model
    if (!ai_worker_config->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", ai_worker_config->model) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->name
    if (!ai_worker_config->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", ai_worker_config->name) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->provider
    if (!ai_worker_config->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", ai_worker_config->provider) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->system_prompt
    if (!ai_worker_config->system_prompt) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "system_prompt", ai_worker_config->system_prompt) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->tenant_id
    if (!ai_worker_config->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", ai_worker_config->tenant_id) == NULL) {
    goto fail; //String
    }


    // ai_worker_config->trigger_on
    if (!ai_worker_config->trigger_on) {
        goto fail;
    }
    cJSON *trigger_on = cJSON_AddArrayToObject(item, "trigger_on");
    if(trigger_on == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *trigger_onListEntry;
    list_ForEach(trigger_onListEntry, ai_worker_config->trigger_on) {
    if(cJSON_AddStringToObject(trigger_on, "", trigger_onListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // ai_worker_config->updated_at
    if(ai_worker_config->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", ai_worker_config->updated_at) == NULL) {
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

ai_worker_config_t *ai_worker_config_parseFromJSON(cJSON *ai_worker_configJSON){

    ai_worker_config_t *ai_worker_config_local_var = NULL;

    // define the local variable for ai_worker_config->auto_reply
    int *auto_reply_local_var = NULL;

    char *created_at_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for ai_worker_config->is_active
    int *is_active_local_var = NULL;

    // define the local variable for ai_worker_config->max_tool_calls
    int *max_tool_calls_local_var = NULL;

    char *model_local_str = NULL;

    char *name_local_str = NULL;

    char *provider_local_str = NULL;

    char *system_prompt_local_str = NULL;

    char *tenant_id_local_str = NULL;

    // define the local list for ai_worker_config->trigger_on
    list_t *trigger_onList = NULL;

    char *updated_at_local_str = NULL;

    // ai_worker_config->auto_reply
    cJSON *auto_reply = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "auto_reply");
    if (cJSON_IsNull(auto_reply)) {
        auto_reply = NULL;
    }
    if (!auto_reply) {
        goto end;
    }

    
    if(!cJSON_IsBool(auto_reply))
    {
    goto end; //Bool
    }
    auto_reply_local_var = malloc(sizeof(int));
    if(!auto_reply_local_var)
    {
        goto end;
    }
    *auto_reply_local_var = auto_reply->valueint;

    // ai_worker_config->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "created_at");
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

    // ai_worker_config->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // ai_worker_config->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "is_active");
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

    // ai_worker_config->max_tool_calls
    cJSON *max_tool_calls = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "max_tool_calls");
    if (cJSON_IsNull(max_tool_calls)) {
        max_tool_calls = NULL;
    }
    if (!max_tool_calls) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_tool_calls))
    {
    goto end; //Numeric
    }
    max_tool_calls_local_var = malloc(sizeof(int));
    if(!max_tool_calls_local_var)
    {
        goto end;
    }
    *max_tool_calls_local_var = max_tool_calls->valuedouble;

    // ai_worker_config->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }

    // ai_worker_config->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "name");
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

    // ai_worker_config->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    
    if(!cJSON_IsString(provider))
    {
    goto end; //String
    }

    // ai_worker_config->system_prompt
    cJSON *system_prompt = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "system_prompt");
    if (cJSON_IsNull(system_prompt)) {
        system_prompt = NULL;
    }
    if (!system_prompt) {
        goto end;
    }

    
    if(!cJSON_IsString(system_prompt))
    {
    goto end; //String
    }

    // ai_worker_config->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "tenant_id");
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

    // ai_worker_config->trigger_on
    cJSON *trigger_on = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "trigger_on");
    if (cJSON_IsNull(trigger_on)) {
        trigger_on = NULL;
    }
    if (!trigger_on) {
        goto end;
    }

    
    cJSON *trigger_on_local = NULL;
    if(!cJSON_IsArray(trigger_on)) {
        goto end;//primitive container
    }
    trigger_onList = list_createList();

    cJSON_ArrayForEach(trigger_on_local, trigger_on)
    {
        if(!cJSON_IsString(trigger_on_local))
        {
            goto end;
        }
        list_addElement(trigger_onList , strdup(trigger_on_local->valuestring));
    }

    // ai_worker_config->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(ai_worker_configJSON, "updated_at");
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
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (model && !cJSON_IsNull(model)) model_local_str = strdup(model->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (provider && !cJSON_IsNull(provider)) provider_local_str = strdup(provider->valuestring);
    if (system_prompt && !cJSON_IsNull(system_prompt)) system_prompt_local_str = strdup(system_prompt->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    ai_worker_config_local_var = ai_worker_config_create_internal (
        auto_reply_local_var,
        created_at_local_str,
        id_local_str,
        is_active_local_var,
        max_tool_calls_local_var,
        model_local_str,
        name_local_str,
        provider_local_str,
        system_prompt_local_str,
        tenant_id_local_str,
        trigger_onList,
        updated_at_local_str
        );

    if (!ai_worker_config_local_var) {
        goto end;
    }

    return ai_worker_config_local_var;
end:
    if (auto_reply_local_var) {
        free(auto_reply_local_var);
        auto_reply_local_var = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (max_tool_calls_local_var) {
        free(max_tool_calls_local_var);
        max_tool_calls_local_var = NULL;
    }
    if (model_local_str) {
        free(model_local_str);
        model_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (provider_local_str) {
        free(provider_local_str);
        provider_local_str = NULL;
    }
    if (system_prompt_local_str) {
        free(system_prompt_local_str);
        system_prompt_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (trigger_onList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, trigger_onList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(trigger_onList);
        trigger_onList = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
