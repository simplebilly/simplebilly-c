#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_config_dto.h"



static ai_config_dto_t *ai_config_dto_create_internal(
    int *auto_reply,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    list_t *trigger_on
    ) {
    ai_config_dto_t *ai_config_dto_local_var = malloc(sizeof(ai_config_dto_t));
    if (!ai_config_dto_local_var) {
        return NULL;
    }
    memset(ai_config_dto_local_var, 0, sizeof(ai_config_dto_t));
    ai_config_dto_local_var->_library_owned = 1;
    ai_config_dto_local_var->auto_reply = auto_reply;
    ai_config_dto_local_var->max_tool_calls = max_tool_calls;
    ai_config_dto_local_var->model = model;
    ai_config_dto_local_var->name = name;
    ai_config_dto_local_var->provider = provider;
    ai_config_dto_local_var->system_prompt = system_prompt;
    ai_config_dto_local_var->trigger_on = trigger_on;
    return ai_config_dto_local_var;
}

__attribute__((deprecated)) ai_config_dto_t *ai_config_dto_create(
    int *auto_reply,
    int *max_tool_calls,
    char *model,
    char *name,
    char *provider,
    char *system_prompt,
    list_t *trigger_on
    ) {
    int *auto_reply_copy = NULL;
    if (auto_reply) {
        auto_reply_copy = malloc(sizeof(int));
        if (auto_reply_copy) *auto_reply_copy = *auto_reply;
    }
    int *max_tool_calls_copy = NULL;
    if (max_tool_calls) {
        max_tool_calls_copy = malloc(sizeof(int));
        if (max_tool_calls_copy) *max_tool_calls_copy = *max_tool_calls;
    }
    ai_config_dto_t *result = ai_config_dto_create_internal (
        auto_reply_copy,
        max_tool_calls_copy,
        model,
        name,
        provider,
        system_prompt,
        trigger_on
        );
    if (!result) {
        free(auto_reply_copy);
        free(max_tool_calls_copy);
    }
    return result;
}

void ai_config_dto_free(ai_config_dto_t *ai_config_dto) {
    if(NULL == ai_config_dto){
        return ;
    }
    if(ai_config_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_config_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ai_config_dto->auto_reply) {
        free(ai_config_dto->auto_reply);
        ai_config_dto->auto_reply = NULL;
    }
    if (ai_config_dto->max_tool_calls) {
        free(ai_config_dto->max_tool_calls);
        ai_config_dto->max_tool_calls = NULL;
    }
    if (ai_config_dto->model) {
        free(ai_config_dto->model);
        ai_config_dto->model = NULL;
    }
    if (ai_config_dto->name) {
        free(ai_config_dto->name);
        ai_config_dto->name = NULL;
    }
    if (ai_config_dto->provider) {
        free(ai_config_dto->provider);
        ai_config_dto->provider = NULL;
    }
    if (ai_config_dto->system_prompt) {
        free(ai_config_dto->system_prompt);
        ai_config_dto->system_prompt = NULL;
    }
    if (ai_config_dto->trigger_on) {
        list_ForEach(listEntry, ai_config_dto->trigger_on) {
            free(listEntry->data);
        }
        list_freeList(ai_config_dto->trigger_on);
        ai_config_dto->trigger_on = NULL;
    }
    free(ai_config_dto);
}

cJSON *ai_config_dto_convertToJSON(ai_config_dto_t *ai_config_dto) {
    cJSON *item = cJSON_CreateObject();

    // ai_config_dto->auto_reply
    if(ai_config_dto->auto_reply) {
    if(cJSON_AddBoolToObject(item, "auto_reply", *ai_config_dto->auto_reply) == NULL) {
    goto fail; //Bool
    }
    }


    // ai_config_dto->max_tool_calls
    if(ai_config_dto->max_tool_calls) {
    if(cJSON_AddNumberToObject(item, "max_tool_calls", *ai_config_dto->max_tool_calls) == NULL) {
    goto fail; //Numeric
    }
    }


    // ai_config_dto->model
    if (!ai_config_dto->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", ai_config_dto->model) == NULL) {
    goto fail; //String
    }


    // ai_config_dto->name
    if (!ai_config_dto->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", ai_config_dto->name) == NULL) {
    goto fail; //String
    }


    // ai_config_dto->provider
    if (!ai_config_dto->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", ai_config_dto->provider) == NULL) {
    goto fail; //String
    }


    // ai_config_dto->system_prompt
    if(ai_config_dto->system_prompt) {
    if(cJSON_AddStringToObject(item, "system_prompt", ai_config_dto->system_prompt) == NULL) {
    goto fail; //String
    }
    }


    // ai_config_dto->trigger_on
    if(ai_config_dto->trigger_on) {
    cJSON *trigger_on = cJSON_AddArrayToObject(item, "trigger_on");
    if(trigger_on == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *trigger_onListEntry;
    list_ForEach(trigger_onListEntry, ai_config_dto->trigger_on) {
    if(cJSON_AddStringToObject(trigger_on, "", trigger_onListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ai_config_dto_t *ai_config_dto_parseFromJSON(cJSON *ai_config_dtoJSON){

    ai_config_dto_t *ai_config_dto_local_var = NULL;

    // define the local variable for ai_config_dto->auto_reply
    int *auto_reply_local_var = NULL;

    // define the local variable for ai_config_dto->max_tool_calls
    int *max_tool_calls_local_var = NULL;

    char *model_local_str = NULL;

    char *name_local_str = NULL;

    char *provider_local_str = NULL;

    char *system_prompt_local_str = NULL;

    // define the local list for ai_config_dto->trigger_on
    list_t *trigger_onList = NULL;

    // ai_config_dto->auto_reply
    cJSON *auto_reply = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "auto_reply");
    if (cJSON_IsNull(auto_reply)) {
        auto_reply = NULL;
    }
    if (auto_reply) { 
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
    }

    // ai_config_dto->max_tool_calls
    cJSON *max_tool_calls = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "max_tool_calls");
    if (cJSON_IsNull(max_tool_calls)) {
        max_tool_calls = NULL;
    }
    if (max_tool_calls) { 
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
    }

    // ai_config_dto->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "model");
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

    // ai_config_dto->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "name");
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

    // ai_config_dto->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "provider");
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

    // ai_config_dto->system_prompt
    cJSON *system_prompt = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "system_prompt");
    if (cJSON_IsNull(system_prompt)) {
        system_prompt = NULL;
    }
    if (system_prompt) { 
    if(!cJSON_IsString(system_prompt) && !cJSON_IsNull(system_prompt))
    {
    goto end; //String
    }
    }

    // ai_config_dto->trigger_on
    cJSON *trigger_on = cJSON_GetObjectItemCaseSensitive(ai_config_dtoJSON, "trigger_on");
    if (cJSON_IsNull(trigger_on)) {
        trigger_on = NULL;
    }
    if (trigger_on) { 
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
    }


    if (model && !cJSON_IsNull(model)) model_local_str = strdup(model->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (provider && !cJSON_IsNull(provider)) provider_local_str = strdup(provider->valuestring);
    if (system_prompt && !cJSON_IsNull(system_prompt)) system_prompt_local_str = strdup(system_prompt->valuestring);

    ai_config_dto_local_var = ai_config_dto_create_internal (
        auto_reply_local_var,
        max_tool_calls_local_var,
        model_local_str,
        name_local_str,
        provider_local_str,
        system_prompt_local_str,
        trigger_on ? trigger_onList : NULL
        );

    if (!ai_config_dto_local_var) {
        goto end;
    }

    return ai_config_dto_local_var;
end:
    if (auto_reply_local_var) {
        free(auto_reply_local_var);
        auto_reply_local_var = NULL;
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
    if (trigger_onList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, trigger_onList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(trigger_onList);
        trigger_onList = NULL;
    }
    return NULL;

}
