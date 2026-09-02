#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "automation_dto.h"



static automation_dto_t *automation_dto_create_internal(
    char *automation_key,
    any_type_t *config,
    int *default_day,
    char *description,
    int *enabled,
    char *kind,
    char *last_run_at,
    char *next_run_at,
    char *schedule_kind
    ) {
    automation_dto_t *automation_dto_local_var = malloc(sizeof(automation_dto_t));
    if (!automation_dto_local_var) {
        return NULL;
    }
    memset(automation_dto_local_var, 0, sizeof(automation_dto_t));
    automation_dto_local_var->_library_owned = 1;
    automation_dto_local_var->automation_key = automation_key;
    automation_dto_local_var->config = config;
    automation_dto_local_var->default_day = default_day;
    automation_dto_local_var->description = description;
    automation_dto_local_var->enabled = enabled;
    automation_dto_local_var->kind = kind;
    automation_dto_local_var->last_run_at = last_run_at;
    automation_dto_local_var->next_run_at = next_run_at;
    automation_dto_local_var->schedule_kind = schedule_kind;
    return automation_dto_local_var;
}

__attribute__((deprecated)) automation_dto_t *automation_dto_create(
    char *automation_key,
    any_type_t *config,
    int *default_day,
    char *description,
    int *enabled,
    char *kind,
    char *last_run_at,
    char *next_run_at,
    char *schedule_kind
    ) {
    int *default_day_copy = NULL;
    if (default_day) {
        default_day_copy = malloc(sizeof(int));
        if (default_day_copy) *default_day_copy = *default_day;
    }
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    automation_dto_t *result = automation_dto_create_internal (
        automation_key,
        config,
        default_day_copy,
        description,
        enabled_copy,
        kind,
        last_run_at,
        next_run_at,
        schedule_kind
        );
    if (!result) {
        free(default_day_copy);
        free(enabled_copy);
    }
    return result;
}

void automation_dto_free(automation_dto_t *automation_dto) {
    if(NULL == automation_dto){
        return ;
    }
    if(automation_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "automation_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (automation_dto->automation_key) {
        free(automation_dto->automation_key);
        automation_dto->automation_key = NULL;
    }
    if (automation_dto->config) {
        _free(automation_dto->config);
        automation_dto->config = NULL;
    }
    if (automation_dto->default_day) {
        free(automation_dto->default_day);
        automation_dto->default_day = NULL;
    }
    if (automation_dto->description) {
        free(automation_dto->description);
        automation_dto->description = NULL;
    }
    if (automation_dto->enabled) {
        free(automation_dto->enabled);
        automation_dto->enabled = NULL;
    }
    if (automation_dto->kind) {
        free(automation_dto->kind);
        automation_dto->kind = NULL;
    }
    if (automation_dto->last_run_at) {
        free(automation_dto->last_run_at);
        automation_dto->last_run_at = NULL;
    }
    if (automation_dto->next_run_at) {
        free(automation_dto->next_run_at);
        automation_dto->next_run_at = NULL;
    }
    if (automation_dto->schedule_kind) {
        free(automation_dto->schedule_kind);
        automation_dto->schedule_kind = NULL;
    }
    free(automation_dto);
}

cJSON *automation_dto_convertToJSON(automation_dto_t *automation_dto) {
    cJSON *item = cJSON_CreateObject();

    // automation_dto->automation_key
    if (!automation_dto->automation_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "automationKey", automation_dto->automation_key) == NULL) {
    goto fail; //String
    }


    // automation_dto->config
    if (!automation_dto->config) {
        goto fail;
    }
    cJSON *config_local_JSON = _convertToJSON(automation_dto->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // automation_dto->default_day
    if(automation_dto->default_day) {
    if(cJSON_AddNumberToObject(item, "defaultDay", *automation_dto->default_day) == NULL) {
    goto fail; //Numeric
    }
    }


    // automation_dto->description
    if (!automation_dto->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", automation_dto->description) == NULL) {
    goto fail; //String
    }


    // automation_dto->enabled
    if (!automation_dto->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", *automation_dto->enabled) == NULL) {
    goto fail; //Bool
    }


    // automation_dto->kind
    if (!automation_dto->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", automation_dto->kind) == NULL) {
    goto fail; //String
    }


    // automation_dto->last_run_at
    if(automation_dto->last_run_at) {
    if(cJSON_AddStringToObject(item, "lastRunAt", automation_dto->last_run_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // automation_dto->next_run_at
    if(automation_dto->next_run_at) {
    if(cJSON_AddStringToObject(item, "nextRunAt", automation_dto->next_run_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // automation_dto->schedule_kind
    if (!automation_dto->schedule_kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scheduleKind", automation_dto->schedule_kind) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

automation_dto_t *automation_dto_parseFromJSON(cJSON *automation_dtoJSON){

    automation_dto_t *automation_dto_local_var = NULL;

    char *automation_key_local_str = NULL;

    // define the local variable for automation_dto->config
    _t *config_local_nonprim = NULL;

    // define the local variable for automation_dto->default_day
    int *default_day_local_var = NULL;

    char *description_local_str = NULL;

    // define the local variable for automation_dto->enabled
    int *enabled_local_var = NULL;

    char *kind_local_str = NULL;

    char *last_run_at_local_str = NULL;

    char *next_run_at_local_str = NULL;

    char *schedule_kind_local_str = NULL;

    // automation_dto->automation_key
    cJSON *automation_key = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "automationKey");
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

    // automation_dto->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = _parseFromJSON(config); //custom

    // automation_dto->default_day
    cJSON *default_day = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "defaultDay");
    if (cJSON_IsNull(default_day)) {
        default_day = NULL;
    }
    if (default_day) { 
    if(!cJSON_IsNumber(default_day))
    {
    goto end; //Numeric
    }
    default_day_local_var = malloc(sizeof(int));
    if(!default_day_local_var)
    {
        goto end;
    }
    *default_day_local_var = default_day->valuedouble;
    }

    // automation_dto->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // automation_dto->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "enabled");
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

    // automation_dto->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // automation_dto->last_run_at
    cJSON *last_run_at = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "lastRunAt");
    if (cJSON_IsNull(last_run_at)) {
        last_run_at = NULL;
    }
    if (last_run_at) { 
    if(!cJSON_IsString(last_run_at) && !cJSON_IsNull(last_run_at))
    {
    goto end; //DateTime
    }
    }

    // automation_dto->next_run_at
    cJSON *next_run_at = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "nextRunAt");
    if (cJSON_IsNull(next_run_at)) {
        next_run_at = NULL;
    }
    if (next_run_at) { 
    if(!cJSON_IsString(next_run_at) && !cJSON_IsNull(next_run_at))
    {
    goto end; //DateTime
    }
    }

    // automation_dto->schedule_kind
    cJSON *schedule_kind = cJSON_GetObjectItemCaseSensitive(automation_dtoJSON, "scheduleKind");
    if (cJSON_IsNull(schedule_kind)) {
        schedule_kind = NULL;
    }
    if (!schedule_kind) {
        goto end;
    }

    
    if(!cJSON_IsString(schedule_kind))
    {
    goto end; //String
    }


    if (automation_key && !cJSON_IsNull(automation_key)) automation_key_local_str = strdup(automation_key->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (last_run_at && !cJSON_IsNull(last_run_at)) last_run_at_local_str = strdup(last_run_at->valuestring);
    if (next_run_at && !cJSON_IsNull(next_run_at)) next_run_at_local_str = strdup(next_run_at->valuestring);
    if (schedule_kind && !cJSON_IsNull(schedule_kind)) schedule_kind_local_str = strdup(schedule_kind->valuestring);

    automation_dto_local_var = automation_dto_create_internal (
        automation_key_local_str,
        config_local_nonprim,
        default_day_local_var,
        description_local_str,
        enabled_local_var,
        kind_local_str,
        last_run_at_local_str,
        next_run_at_local_str,
        schedule_kind_local_str
        );

    if (!automation_dto_local_var) {
        goto end;
    }

    return automation_dto_local_var;
end:
    if (automation_key_local_str) {
        free(automation_key_local_str);
        automation_key_local_str = NULL;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (default_day_local_var) {
        free(default_day_local_var);
        default_day_local_var = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (last_run_at_local_str) {
        free(last_run_at_local_str);
        last_run_at_local_str = NULL;
    }
    if (next_run_at_local_str) {
        free(next_run_at_local_str);
        next_run_at_local_str = NULL;
    }
    if (schedule_kind_local_str) {
        free(schedule_kind_local_str);
        schedule_kind_local_str = NULL;
    }
    return NULL;

}
