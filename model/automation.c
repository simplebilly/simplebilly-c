#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "automation.h"



static automation_t *automation_create_internal(
    char *automation_key,
    any_type_t *config,
    char *created_at,
    int *enabled,
    char *last_run_at,
    char *next_run_at,
    char *tenant_id,
    char *updated_at
    ) {
    automation_t *automation_local_var = malloc(sizeof(automation_t));
    if (!automation_local_var) {
        return NULL;
    }
    memset(automation_local_var, 0, sizeof(automation_t));
    automation_local_var->_library_owned = 1;
    automation_local_var->automation_key = automation_key;
    automation_local_var->config = config;
    automation_local_var->created_at = created_at;
    automation_local_var->enabled = enabled;
    automation_local_var->last_run_at = last_run_at;
    automation_local_var->next_run_at = next_run_at;
    automation_local_var->tenant_id = tenant_id;
    automation_local_var->updated_at = updated_at;
    return automation_local_var;
}

__attribute__((deprecated)) automation_t *automation_create(
    char *automation_key,
    any_type_t *config,
    char *created_at,
    int *enabled,
    char *last_run_at,
    char *next_run_at,
    char *tenant_id,
    char *updated_at
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    automation_t *result = automation_create_internal (
        automation_key,
        config,
        created_at,
        enabled_copy,
        last_run_at,
        next_run_at,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void automation_free(automation_t *automation) {
    if(NULL == automation){
        return ;
    }
    if(automation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "automation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (automation->automation_key) {
        free(automation->automation_key);
        automation->automation_key = NULL;
    }
    if (automation->config) {
        _free(automation->config);
        automation->config = NULL;
    }
    if (automation->created_at) {
        free(automation->created_at);
        automation->created_at = NULL;
    }
    if (automation->enabled) {
        free(automation->enabled);
        automation->enabled = NULL;
    }
    if (automation->last_run_at) {
        free(automation->last_run_at);
        automation->last_run_at = NULL;
    }
    if (automation->next_run_at) {
        free(automation->next_run_at);
        automation->next_run_at = NULL;
    }
    if (automation->tenant_id) {
        free(automation->tenant_id);
        automation->tenant_id = NULL;
    }
    if (automation->updated_at) {
        free(automation->updated_at);
        automation->updated_at = NULL;
    }
    free(automation);
}

cJSON *automation_convertToJSON(automation_t *automation) {
    cJSON *item = cJSON_CreateObject();

    // automation->automation_key
    if (!automation->automation_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "automationKey", automation->automation_key) == NULL) {
    goto fail; //String
    }


    // automation->config
    if (!automation->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(automation->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // automation->created_at
    if (!automation->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", automation->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // automation->enabled
    if (!automation->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", *automation->enabled) == NULL) {
    goto fail; //Bool
    }


    // automation->last_run_at
    if(automation->last_run_at) {
    if(cJSON_AddStringToObject(item, "lastRunAt", automation->last_run_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // automation->next_run_at
    if(automation->next_run_at) {
    if(cJSON_AddStringToObject(item, "nextRunAt", automation->next_run_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // automation->tenant_id
    if (!automation->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", automation->tenant_id) == NULL) {
    goto fail; //String
    }


    // automation->updated_at
    if (!automation->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", automation->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

automation_t *automation_parseFromJSON(cJSON *automationJSON){

    automation_t *automation_local_var = NULL;

    char *automation_key_local_str = NULL;

    // define the local variable for automation->config
    _t *config_local_nonprim = NULL;

    char *created_at_local_str = NULL;

    // define the local variable for automation->enabled
    int *enabled_local_var = NULL;

    char *last_run_at_local_str = NULL;

    char *next_run_at_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // automation->automation_key
    cJSON *automation_key = cJSON_GetObjectItemCaseSensitive(automationJSON, "automationKey");
    if (cJSON_IsNull(automation_key)) {
        automation_key = NULL;
    }
    if (!automation_key) {
        goto end;
    }

    
    if(!cJSON_IsString(automation_key))
    {
    goto end; //String
    }

    // automation->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(automationJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // automation->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(automationJSON, "createdAt");
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

    // automation->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(automationJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    enabled_local_var = malloc(sizeof(int));
    if(!enabled_local_var)
    {
        goto end;
    }
    *enabled_local_var = enabled->valueint;

    // automation->last_run_at
    cJSON *last_run_at = cJSON_GetObjectItemCaseSensitive(automationJSON, "lastRunAt");
    if (cJSON_IsNull(last_run_at)) {
        last_run_at = NULL;
    }
    if (last_run_at) { 
    if(!cJSON_IsString(last_run_at) && !cJSON_IsNull(last_run_at))
    {
    goto end; //DateTime
    }
    }

    // automation->next_run_at
    cJSON *next_run_at = cJSON_GetObjectItemCaseSensitive(automationJSON, "nextRunAt");
    if (cJSON_IsNull(next_run_at)) {
        next_run_at = NULL;
    }
    if (next_run_at) { 
    if(!cJSON_IsString(next_run_at) && !cJSON_IsNull(next_run_at))
    {
    goto end; //DateTime
    }
    }

    // automation->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(automationJSON, "tenantId");
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

    // automation->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(automationJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    if (automation_key && !cJSON_IsNull(automation_key)) automation_key_local_str = strdup(automation_key->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (last_run_at && !cJSON_IsNull(last_run_at)) last_run_at_local_str = strdup(last_run_at->valuestring);
    if (next_run_at && !cJSON_IsNull(next_run_at)) next_run_at_local_str = strdup(next_run_at->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    automation_local_var = automation_create_internal (
        automation_key_local_str,
        config_local_nonprim,
        created_at_local_str,
        enabled_local_var,
        last_run_at_local_str,
        next_run_at_local_str,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!automation_local_var) {
        goto end;
    }

    return automation_local_var;
end:
    if (automation_key_local_str) {
        free(automation_key_local_str);
        automation_key_local_str = NULL;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    if (last_run_at_local_str) {
        free(last_run_at_local_str);
        last_run_at_local_str = NULL;
    }
    if (next_run_at_local_str) {
        free(next_run_at_local_str);
        next_run_at_local_str = NULL;
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
