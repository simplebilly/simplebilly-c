#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tenant_user.h"



static tenant_user_t *tenant_user_create_internal(
    char *email,
    int *email_verified,
    int *is_active,
    char *joined_at,
    char *last_login,
    char *name,
    list_t *permissions,
    char *role,
    char *user_id
    ) {
    tenant_user_t *tenant_user_local_var = malloc(sizeof(tenant_user_t));
    if (!tenant_user_local_var) {
        return NULL;
    }
    memset(tenant_user_local_var, 0, sizeof(tenant_user_t));
    tenant_user_local_var->_library_owned = 1;
    tenant_user_local_var->email = email;
    tenant_user_local_var->email_verified = email_verified;
    tenant_user_local_var->is_active = is_active;
    tenant_user_local_var->joined_at = joined_at;
    tenant_user_local_var->last_login = last_login;
    tenant_user_local_var->name = name;
    tenant_user_local_var->permissions = permissions;
    tenant_user_local_var->role = role;
    tenant_user_local_var->user_id = user_id;
    return tenant_user_local_var;
}

__attribute__((deprecated)) tenant_user_t *tenant_user_create(
    char *email,
    int *email_verified,
    int *is_active,
    char *joined_at,
    char *last_login,
    char *name,
    list_t *permissions,
    char *role,
    char *user_id
    ) {
    int *email_verified_copy = NULL;
    if (email_verified) {
        email_verified_copy = malloc(sizeof(int));
        if (email_verified_copy) *email_verified_copy = *email_verified;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    tenant_user_t *result = tenant_user_create_internal (
        email,
        email_verified_copy,
        is_active_copy,
        joined_at,
        last_login,
        name,
        permissions,
        role,
        user_id
        );
    if (!result) {
        free(email_verified_copy);
        free(is_active_copy);
    }
    return result;
}

void tenant_user_free(tenant_user_t *tenant_user) {
    if(NULL == tenant_user){
        return ;
    }
    if(tenant_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tenant_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tenant_user->email) {
        free(tenant_user->email);
        tenant_user->email = NULL;
    }
    if (tenant_user->email_verified) {
        free(tenant_user->email_verified);
        tenant_user->email_verified = NULL;
    }
    if (tenant_user->is_active) {
        free(tenant_user->is_active);
        tenant_user->is_active = NULL;
    }
    if (tenant_user->joined_at) {
        free(tenant_user->joined_at);
        tenant_user->joined_at = NULL;
    }
    if (tenant_user->last_login) {
        free(tenant_user->last_login);
        tenant_user->last_login = NULL;
    }
    if (tenant_user->name) {
        free(tenant_user->name);
        tenant_user->name = NULL;
    }
    if (tenant_user->permissions) {
        list_ForEach(listEntry, tenant_user->permissions) {
            free(listEntry->data);
        }
        list_freeList(tenant_user->permissions);
        tenant_user->permissions = NULL;
    }
    if (tenant_user->role) {
        free(tenant_user->role);
        tenant_user->role = NULL;
    }
    if (tenant_user->user_id) {
        free(tenant_user->user_id);
        tenant_user->user_id = NULL;
    }
    free(tenant_user);
}

cJSON *tenant_user_convertToJSON(tenant_user_t *tenant_user) {
    cJSON *item = cJSON_CreateObject();

    // tenant_user->email
    if (!tenant_user->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", tenant_user->email) == NULL) {
    goto fail; //String
    }


    // tenant_user->email_verified
    if (!tenant_user->email_verified) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "email_verified", *tenant_user->email_verified) == NULL) {
    goto fail; //Bool
    }


    // tenant_user->is_active
    if (!tenant_user->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *tenant_user->is_active) == NULL) {
    goto fail; //Bool
    }


    // tenant_user->joined_at
    if (!tenant_user->joined_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "joined_at", tenant_user->joined_at) == NULL) {
    goto fail; //Date-Time
    }


    // tenant_user->last_login
    if(tenant_user->last_login) {
    if(cJSON_AddStringToObject(item, "last_login", tenant_user->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // tenant_user->name
    if (!tenant_user->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", tenant_user->name) == NULL) {
    goto fail; //String
    }


    // tenant_user->permissions
    if (!tenant_user->permissions) {
        goto fail;
    }
    cJSON *permissions = cJSON_AddArrayToObject(item, "permissions");
    if(permissions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *permissionsListEntry;
    list_ForEach(permissionsListEntry, tenant_user->permissions) {
    if(cJSON_AddStringToObject(permissions, "", permissionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // tenant_user->role
    if (!tenant_user->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", tenant_user->role) == NULL) {
    goto fail; //String
    }


    // tenant_user->user_id
    if (!tenant_user->user_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "user_id", tenant_user->user_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tenant_user_t *tenant_user_parseFromJSON(cJSON *tenant_userJSON){

    tenant_user_t *tenant_user_local_var = NULL;

    char *email_local_str = NULL;

    // define the local variable for tenant_user->email_verified
    int *email_verified_local_var = NULL;

    // define the local variable for tenant_user->is_active
    int *is_active_local_var = NULL;

    char *joined_at_local_str = NULL;

    char *last_login_local_str = NULL;

    char *name_local_str = NULL;

    // define the local list for tenant_user->permissions
    list_t *permissionsList = NULL;

    char *role_local_str = NULL;

    char *user_id_local_str = NULL;

    // tenant_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // tenant_user->email_verified
    cJSON *email_verified = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "email_verified");
    if (cJSON_IsNull(email_verified)) {
        email_verified = NULL;
    }
    if (!email_verified) {
        goto end;
    }

    
    if(!cJSON_IsBool(email_verified))
    {
    goto end; //Bool
    }
    email_verified_local_var = malloc(sizeof(int));
    if(!email_verified_local_var)
    {
        goto end;
    }
    *email_verified_local_var = email_verified->valueint;

    // tenant_user->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (!is_active) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;

    // tenant_user->joined_at
    cJSON *joined_at = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "joined_at");
    if (cJSON_IsNull(joined_at)) {
        joined_at = NULL;
    }
    if (!joined_at) {
        goto end;
    }

    
    if(!cJSON_IsString(joined_at) && !cJSON_IsNull(joined_at))
    {
    goto end; //DateTime
    }

    // tenant_user->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "last_login");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // tenant_user->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "name");
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

    // tenant_user->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "permissions");
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

    // tenant_user->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "role");
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

    // tenant_user->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(tenant_userJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (joined_at && !cJSON_IsNull(joined_at)) joined_at_local_str = strdup(joined_at->valuestring);
    if (last_login && !cJSON_IsNull(last_login)) last_login_local_str = strdup(last_login->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);

    tenant_user_local_var = tenant_user_create_internal (
        email_local_str,
        email_verified_local_var,
        is_active_local_var,
        joined_at_local_str,
        last_login_local_str,
        name_local_str,
        permissionsList,
        role_local_str,
        user_id_local_str
        );

    if (!tenant_user_local_var) {
        goto end;
    }

    return tenant_user_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (email_verified_local_var) {
        free(email_verified_local_var);
        email_verified_local_var = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (joined_at_local_str) {
        free(joined_at_local_str);
        joined_at_local_str = NULL;
    }
    if (last_login_local_str) {
        free(last_login_local_str);
        last_login_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (permissionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, permissionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(permissionsList);
        permissionsList = NULL;
    }
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (user_id_local_str) {
        free(user_id_local_str);
        user_id_local_str = NULL;
    }
    return NULL;

}
