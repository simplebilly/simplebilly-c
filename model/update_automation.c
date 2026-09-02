#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_automation.h"



static update_automation_t *update_automation_create_internal(
    any_type_t *config,
    int *enabled
    ) {
    update_automation_t *update_automation_local_var = malloc(sizeof(update_automation_t));
    if (!update_automation_local_var) {
        return NULL;
    }
    memset(update_automation_local_var, 0, sizeof(update_automation_t));
    update_automation_local_var->_library_owned = 1;
    update_automation_local_var->config = config;
    update_automation_local_var->enabled = enabled;
    return update_automation_local_var;
}

__attribute__((deprecated)) update_automation_t *update_automation_create(
    any_type_t *config,
    int *enabled
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    update_automation_t *result = update_automation_create_internal (
        config,
        enabled_copy
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void update_automation_free(update_automation_t *update_automation) {
    if(NULL == update_automation){
        return ;
    }
    if(update_automation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_automation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_automation->config) {
        _free(update_automation->config);
        update_automation->config = NULL;
    }
    if (update_automation->enabled) {
        free(update_automation->enabled);
        update_automation->enabled = NULL;
    }
    free(update_automation);
}

cJSON *update_automation_convertToJSON(update_automation_t *update_automation) {
    cJSON *item = cJSON_CreateObject();

    // update_automation->config
    if(update_automation->config) {
    cJSON *config_local_JSON = _convertToJSON(update_automation->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // update_automation->enabled
    if(update_automation->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", *update_automation->enabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_automation_t *update_automation_parseFromJSON(cJSON *update_automationJSON){

    update_automation_t *update_automation_local_var = NULL;

    // define the local variable for update_automation->config
    _t *config_local_nonprim = NULL;

    // define the local variable for update_automation->enabled
    int *enabled_local_var = NULL;

    // update_automation->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_automationJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // update_automation->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(update_automationJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
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
    }



    update_automation_local_var = update_automation_create_internal (
        config ? config_local_nonprim : NULL,
        enabled_local_var
        );

    if (!update_automation_local_var) {
        goto end;
    }

    return update_automation_local_var;
end:
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    return NULL;

}
