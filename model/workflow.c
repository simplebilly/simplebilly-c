#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "workflow.h"



static workflow_t *workflow_create_internal(
    any_type_t *actions,
    int *enabled,
    char *name,
    char *trigger_event
    ) {
    workflow_t *workflow_local_var = malloc(sizeof(workflow_t));
    if (!workflow_local_var) {
        return NULL;
    }
    memset(workflow_local_var, 0, sizeof(workflow_t));
    workflow_local_var->_library_owned = 1;
    workflow_local_var->actions = actions;
    workflow_local_var->enabled = enabled;
    workflow_local_var->name = name;
    workflow_local_var->trigger_event = trigger_event;
    return workflow_local_var;
}

__attribute__((deprecated)) workflow_t *workflow_create(
    any_type_t *actions,
    int *enabled,
    char *name,
    char *trigger_event
    ) {
    int *enabled_copy = NULL;
    if (enabled) {
        enabled_copy = malloc(sizeof(int));
        if (enabled_copy) *enabled_copy = *enabled;
    }
    workflow_t *result = workflow_create_internal (
        actions,
        enabled_copy,
        name,
        trigger_event
        );
    if (!result) {
        free(enabled_copy);
    }
    return result;
}

void workflow_free(workflow_t *workflow) {
    if(NULL == workflow){
        return ;
    }
    if(workflow->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "workflow_free");
        return ;
    }
    listEntry_t *listEntry;
    if (workflow->actions) {
        _free(workflow->actions);
        workflow->actions = NULL;
    }
    if (workflow->enabled) {
        free(workflow->enabled);
        workflow->enabled = NULL;
    }
    if (workflow->name) {
        free(workflow->name);
        workflow->name = NULL;
    }
    if (workflow->trigger_event) {
        free(workflow->trigger_event);
        workflow->trigger_event = NULL;
    }
    free(workflow);
}

cJSON *workflow_convertToJSON(workflow_t *workflow) {
    cJSON *item = cJSON_CreateObject();

    // workflow->actions
    if(workflow->actions) {
    cJSON *actions_local_JSON = _convertToJSON(workflow->actions);
    if(actions_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "actions", actions_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // workflow->enabled
    if(workflow->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", *workflow->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // workflow->name
    if (!workflow->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", workflow->name) == NULL) {
    goto fail; //String
    }


    // workflow->trigger_event
    if (!workflow->trigger_event) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "triggerEvent", workflow->trigger_event) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

workflow_t *workflow_parseFromJSON(cJSON *workflowJSON){

    workflow_t *workflow_local_var = NULL;

    // define the local variable for workflow->actions
    _t *actions_local_nonprim = NULL;

    // define the local variable for workflow->enabled
    int *enabled_local_var = NULL;

    char *name_local_str = NULL;

    char *trigger_event_local_str = NULL;

    // workflow->actions
    cJSON *actions = cJSON_GetObjectItemCaseSensitive(workflowJSON, "actions");
    if (cJSON_IsNull(actions)) {
        actions = NULL;
    }
    if (actions) { 
    actions_local_nonprim = _parseFromJSON(actions); //custom
    }

    // workflow->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(workflowJSON, "enabled");
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

    // workflow->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(workflowJSON, "name");
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

    // workflow->trigger_event
    cJSON *trigger_event = cJSON_GetObjectItemCaseSensitive(workflowJSON, "triggerEvent");
    if (cJSON_IsNull(trigger_event)) {
        trigger_event = NULL;
    }
    if (!trigger_event) {
        goto end;
    }

    
    if(!cJSON_IsString(trigger_event))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (trigger_event && !cJSON_IsNull(trigger_event)) trigger_event_local_str = strdup(trigger_event->valuestring);

    workflow_local_var = workflow_create_internal (
        actions ? actions_local_nonprim : NULL,
        enabled_local_var,
        name_local_str,
        trigger_event_local_str
        );

    if (!workflow_local_var) {
        goto end;
    }

    return workflow_local_var;
end:
    if (actions_local_nonprim) {
        _free(actions_local_nonprim);
        actions_local_nonprim = NULL;
    }
    if (enabled_local_var) {
        free(enabled_local_var);
        enabled_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (trigger_event_local_str) {
        free(trigger_event_local_str);
        trigger_event_local_str = NULL;
    }
    return NULL;

}
