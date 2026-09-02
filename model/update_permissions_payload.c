#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_permissions_payload.h"



static update_permissions_payload_t *update_permissions_payload_create_internal(
    list_t *permissions
    ) {
    update_permissions_payload_t *update_permissions_payload_local_var = malloc(sizeof(update_permissions_payload_t));
    if (!update_permissions_payload_local_var) {
        return NULL;
    }
    memset(update_permissions_payload_local_var, 0, sizeof(update_permissions_payload_t));
    update_permissions_payload_local_var->_library_owned = 1;
    update_permissions_payload_local_var->permissions = permissions;
    return update_permissions_payload_local_var;
}

__attribute__((deprecated)) update_permissions_payload_t *update_permissions_payload_create(
    list_t *permissions
    ) {
    update_permissions_payload_t *result = update_permissions_payload_create_internal (
        permissions
        );
    if (!result) {
    }
    return result;
}

void update_permissions_payload_free(update_permissions_payload_t *update_permissions_payload) {
    if(NULL == update_permissions_payload){
        return ;
    }
    if(update_permissions_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_permissions_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_permissions_payload->permissions) {
        list_ForEach(listEntry, update_permissions_payload->permissions) {
            free(listEntry->data);
        }
        list_freeList(update_permissions_payload->permissions);
        update_permissions_payload->permissions = NULL;
    }
    free(update_permissions_payload);
}

cJSON *update_permissions_payload_convertToJSON(update_permissions_payload_t *update_permissions_payload) {
    cJSON *item = cJSON_CreateObject();

    // update_permissions_payload->permissions
    if (!update_permissions_payload->permissions) {
        goto fail;
    }
    cJSON *permissions = cJSON_AddArrayToObject(item, "permissions");
    if(permissions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *permissionsListEntry;
    list_ForEach(permissionsListEntry, update_permissions_payload->permissions) {
    if(cJSON_AddStringToObject(permissions, "", permissionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_permissions_payload_t *update_permissions_payload_parseFromJSON(cJSON *update_permissions_payloadJSON){

    update_permissions_payload_t *update_permissions_payload_local_var = NULL;

    // define the local list for update_permissions_payload->permissions
    list_t *permissionsList = NULL;

    // update_permissions_payload->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(update_permissions_payloadJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    cJSON *permissions_local = NULL;
    if(!cJSON_IsArray(permissions)) {
        goto end;//primitive container
    }
    permissionsList = list_createList();

    cJSON_ArrayForEach(permissions_local, permissions)
    {
        if(!cJSON_IsString(permissions_local))
        {
            goto end;
        }
        list_addElement(permissionsList , strdup(permissions_local->valuestring));
    }



    update_permissions_payload_local_var = update_permissions_payload_create_internal (
        permissionsList
        );

    if (!update_permissions_payload_local_var) {
        goto end;
    }

    return update_permissions_payload_local_var;
end:
    if (permissionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, permissionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(permissionsList);
        permissionsList = NULL;
    }
    return NULL;

}
