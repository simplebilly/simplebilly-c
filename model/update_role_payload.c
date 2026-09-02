#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_role_payload.h"



static update_role_payload_t *update_role_payload_create_internal(
    char *role,
    int *sync_permissions
    ) {
    update_role_payload_t *update_role_payload_local_var = malloc(sizeof(update_role_payload_t));
    if (!update_role_payload_local_var) {
        return NULL;
    }
    memset(update_role_payload_local_var, 0, sizeof(update_role_payload_t));
    update_role_payload_local_var->_library_owned = 1;
    update_role_payload_local_var->role = role;
    update_role_payload_local_var->sync_permissions = sync_permissions;
    return update_role_payload_local_var;
}

__attribute__((deprecated)) update_role_payload_t *update_role_payload_create(
    char *role,
    int *sync_permissions
    ) {
    int *sync_permissions_copy = NULL;
    if (sync_permissions) {
        sync_permissions_copy = malloc(sizeof(int));
        if (sync_permissions_copy) *sync_permissions_copy = *sync_permissions;
    }
    update_role_payload_t *result = update_role_payload_create_internal (
        role,
        sync_permissions_copy
        );
    if (!result) {
        free(sync_permissions_copy);
    }
    return result;
}

void update_role_payload_free(update_role_payload_t *update_role_payload) {
    if(NULL == update_role_payload){
        return ;
    }
    if(update_role_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_role_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_role_payload->role) {
        free(update_role_payload->role);
        update_role_payload->role = NULL;
    }
    if (update_role_payload->sync_permissions) {
        free(update_role_payload->sync_permissions);
        update_role_payload->sync_permissions = NULL;
    }
    free(update_role_payload);
}

cJSON *update_role_payload_convertToJSON(update_role_payload_t *update_role_payload) {
    cJSON *item = cJSON_CreateObject();

    // update_role_payload->role
    if (!update_role_payload->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", update_role_payload->role) == NULL) {
    goto fail; //String
    }


    // update_role_payload->sync_permissions
    if(update_role_payload->sync_permissions) {
    if(cJSON_AddBoolToObject(item, "sync_permissions", *update_role_payload->sync_permissions) == NULL) {
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

update_role_payload_t *update_role_payload_parseFromJSON(cJSON *update_role_payloadJSON){

    update_role_payload_t *update_role_payload_local_var = NULL;

    char *role_local_str = NULL;

    // define the local variable for update_role_payload->sync_permissions
    int *sync_permissions_local_var = NULL;

    // update_role_payload->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(update_role_payloadJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    if(!cJSON_IsString(role))
    {
    goto end; //String
    }

    // update_role_payload->sync_permissions
    cJSON *sync_permissions = cJSON_GetObjectItemCaseSensitive(update_role_payloadJSON, "sync_permissions");
    if (cJSON_IsNull(sync_permissions)) {
        sync_permissions = NULL;
    }
    if (sync_permissions) { 
    if(!cJSON_IsBool(sync_permissions))
    {
    goto end; //Bool
    }
    sync_permissions_local_var = malloc(sizeof(int));
    if(!sync_permissions_local_var)
    {
        goto end;
    }
    *sync_permissions_local_var = sync_permissions->valueint;
    }


    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);

    update_role_payload_local_var = update_role_payload_create_internal (
        role_local_str,
        sync_permissions_local_var
        );

    if (!update_role_payload_local_var) {
        goto end;
    }

    return update_role_payload_local_var;
end:
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (sync_permissions_local_var) {
        free(sync_permissions_local_var);
        sync_permissions_local_var = NULL;
    }
    return NULL;

}
