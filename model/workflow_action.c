#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "workflow_action.h"



static workflow_action_t *workflow_action_create_internal(
    char *action_type,
    char *body,
    char *subject
    ) {
    workflow_action_t *workflow_action_local_var = malloc(sizeof(workflow_action_t));
    if (!workflow_action_local_var) {
        return NULL;
    }
    memset(workflow_action_local_var, 0, sizeof(workflow_action_t));
    workflow_action_local_var->_library_owned = 1;
    workflow_action_local_var->action_type = action_type;
    workflow_action_local_var->body = body;
    workflow_action_local_var->subject = subject;
    return workflow_action_local_var;
}

__attribute__((deprecated)) workflow_action_t *workflow_action_create(
    char *action_type,
    char *body,
    char *subject
    ) {
    workflow_action_t *result = workflow_action_create_internal (
        action_type,
        body,
        subject
        );
    if (!result) {
    }
    return result;
}

void workflow_action_free(workflow_action_t *workflow_action) {
    if(NULL == workflow_action){
        return ;
    }
    if(workflow_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "workflow_action_free");
        return ;
    }
    listEntry_t *listEntry;
    if (workflow_action->action_type) {
        free(workflow_action->action_type);
        workflow_action->action_type = NULL;
    }
    if (workflow_action->body) {
        free(workflow_action->body);
        workflow_action->body = NULL;
    }
    if (workflow_action->subject) {
        free(workflow_action->subject);
        workflow_action->subject = NULL;
    }
    free(workflow_action);
}

cJSON *workflow_action_convertToJSON(workflow_action_t *workflow_action) {
    cJSON *item = cJSON_CreateObject();

    // workflow_action->action_type
    if (!workflow_action->action_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action_type", workflow_action->action_type) == NULL) {
    goto fail; //String
    }


    // workflow_action->body
    if(workflow_action->body) {
    if(cJSON_AddStringToObject(item, "body", workflow_action->body) == NULL) {
    goto fail; //String
    }
    }


    // workflow_action->subject
    if(workflow_action->subject) {
    if(cJSON_AddStringToObject(item, "subject", workflow_action->subject) == NULL) {
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

workflow_action_t *workflow_action_parseFromJSON(cJSON *workflow_actionJSON){

    workflow_action_t *workflow_action_local_var = NULL;

    char *action_type_local_str = NULL;

    char *body_local_str = NULL;

    char *subject_local_str = NULL;

    // workflow_action->action_type
    cJSON *action_type = cJSON_GetObjectItemCaseSensitive(workflow_actionJSON, "action_type");
    if (cJSON_IsNull(action_type)) {
        action_type = NULL;
    }
    if (!action_type) {
        goto end;
    }

    
    if(!cJSON_IsString(action_type))
    {
    goto end; //String
    }

    // workflow_action->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(workflow_actionJSON, "body");
    if (cJSON_IsNull(body)) {
        body = NULL;
    }
    if (body) { 
    if(!cJSON_IsString(body) && !cJSON_IsNull(body))
    {
    goto end; //String
    }
    }

    // workflow_action->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(workflow_actionJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }


    if (action_type && !cJSON_IsNull(action_type)) action_type_local_str = strdup(action_type->valuestring);
    if (body && !cJSON_IsNull(body)) body_local_str = strdup(body->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    workflow_action_local_var = workflow_action_create_internal (
        action_type_local_str,
        body_local_str,
        subject_local_str
        );

    if (!workflow_action_local_var) {
        goto end;
    }

    return workflow_action_local_var;
end:
    if (action_type_local_str) {
        free(action_type_local_str);
        action_type_local_str = NULL;
    }
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    return NULL;

}
