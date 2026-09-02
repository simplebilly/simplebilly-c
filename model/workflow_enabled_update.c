#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "workflow_enabled_update.h"



static workflow_enabled_update_t *workflow_enabled_update_create_internal(
    int *enabled
    ) {
    workflow_enabled_update_t *workflow_enabled_update_local_var = malloc(sizeof(workflow_enabled_update_t));
    if (!workflow_enabled_update_local_var) {
        return NULL;
    }
    memset(workflow_enabled_update_local_var, 0, sizeof(workflow_enabled_update_t));
    workflow_enabled_update_local_var->_library_owned = 1;
    workflow_enabled_update_local_var->enabled = enabled;
    return workflow_enabled_update_local_var;
}

__attribute__((deprecated)) workflow_enabled_update_t *workflow_enabled_update_create(
    int *enabled
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    workflow_enabled_update_t *result = workflow_enabled_update_create_internal (
        enabled_copy
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void workflow_enabled_update_free(workflow_enabled_update_t *workflow_enabled_update) {
    if(NULL == workflow_enabled_update){
        return ;
    }
    if(workflow_enabled_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "workflow_enabled_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (workflow_enabled_update->enabled) {
        free(workflow_enabled_update->enabled);
        workflow_enabled_update->enabled = NULL;
    }
    free(workflow_enabled_update);
}

cJSON *workflow_enabled_update_convertToJSON(workflow_enabled_update_t *workflow_enabled_update) {
    cJSON *item = cJSON_CreateObject();

    // workflow_enabled_update->enabled
    if (!workflow_enabled_update->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", *workflow_enabled_update->enabled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

workflow_enabled_update_t *workflow_enabled_update_parseFromJSON(cJSON *workflow_enabled_updateJSON){

    workflow_enabled_update_t *workflow_enabled_update_local_var = NULL;

    // define the local variable for workflow_enabled_update->enabled
    int *enabled_local_var = NULL;

    // workflow_enabled_update->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(workflow_enabled_updateJSON, "enabled");
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



    workflow_enabled_update_local_var = workflow_enabled_update_create_internal (
        enabled_local_var
        );

    if (!workflow_enabled_update_local_var) {
        goto end;
    }

    return workflow_enabled_update_local_var;
end:
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    return NULL;

}
