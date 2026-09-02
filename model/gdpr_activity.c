#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_activity.h"



static gdpr_activity_t *gdpr_activity_create_internal(
    char *action,
    char *created_at,
    char *description,
    char *id,
    char *tenant_id
    ) {
    gdpr_activity_t *gdpr_activity_local_var = malloc(sizeof(gdpr_activity_t));
    if (!gdpr_activity_local_var) {
        return NULL;
    }
    memset(gdpr_activity_local_var, 0, sizeof(gdpr_activity_t));
    gdpr_activity_local_var->_library_owned = 1;
    gdpr_activity_local_var->action = action;
    gdpr_activity_local_var->created_at = created_at;
    gdpr_activity_local_var->description = description;
    gdpr_activity_local_var->id = id;
    gdpr_activity_local_var->tenant_id = tenant_id;
    return gdpr_activity_local_var;
}

__attribute__((deprecated)) gdpr_activity_t *gdpr_activity_create(
    char *action,
    char *created_at,
    char *description,
    char *id,
    char *tenant_id
    ) {
    gdpr_activity_t *result = gdpr_activity_create_internal (
        action,
        created_at,
        description,
        id,
        tenant_id
        );
    if (!result) {
    }
    return result;
}

void gdpr_activity_free(gdpr_activity_t *gdpr_activity) {
    if(NULL == gdpr_activity){
        return ;
    }
    if(gdpr_activity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_activity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_activity->action) {
        free(gdpr_activity->action);
        gdpr_activity->action = NULL;
    }
    if (gdpr_activity->created_at) {
        free(gdpr_activity->created_at);
        gdpr_activity->created_at = NULL;
    }
    if (gdpr_activity->description) {
        free(gdpr_activity->description);
        gdpr_activity->description = NULL;
    }
    if (gdpr_activity->id) {
        free(gdpr_activity->id);
        gdpr_activity->id = NULL;
    }
    if (gdpr_activity->tenant_id) {
        free(gdpr_activity->tenant_id);
        gdpr_activity->tenant_id = NULL;
    }
    free(gdpr_activity);
}

cJSON *gdpr_activity_convertToJSON(gdpr_activity_t *gdpr_activity) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_activity->action
    if (!gdpr_activity->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", gdpr_activity->action) == NULL) {
    goto fail; //String
    }


    // gdpr_activity->created_at
    if (!gdpr_activity->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_activity->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_activity->description
    if(gdpr_activity->description) {
    if(cJSON_AddStringToObject(item, "description", gdpr_activity->description) == NULL) {
    goto fail; //String
    }
    }


    // gdpr_activity->id
    if (!gdpr_activity->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_activity->id) == NULL) {
    goto fail; //String
    }


    // gdpr_activity->tenant_id
    if (!gdpr_activity->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_activity->tenant_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_activity_t *gdpr_activity_parseFromJSON(cJSON *gdpr_activityJSON){

    gdpr_activity_t *gdpr_activity_local_var = NULL;

    char *action_local_str = NULL;

    char *created_at_local_str = NULL;

    char *description_local_str = NULL;

    char *id_local_str = NULL;

    char *tenant_id_local_str = NULL;

    // gdpr_activity->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(gdpr_activityJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }

    // gdpr_activity->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_activityJSON, "createdAt");
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

    // gdpr_activity->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(gdpr_activityJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // gdpr_activity->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_activityJSON, "id");
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

    // gdpr_activity->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_activityJSON, "tenantId");
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


    if (action && !cJSON_IsNull(action)) action_local_str = strdup(action->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);

    gdpr_activity_local_var = gdpr_activity_create_internal (
        action_local_str,
        created_at_local_str,
        description_local_str,
        id_local_str,
        tenant_id_local_str
        );

    if (!gdpr_activity_local_var) {
        goto end;
    }

    return gdpr_activity_local_var;
end:
    if (action_local_str) {
        free(action_local_str);
        action_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    return NULL;

}
