#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_tenant_info.h"



static user_tenant_info_t *user_tenant_info_create_internal(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
    ) {
    user_tenant_info_t *user_tenant_info_local_var = malloc(sizeof(user_tenant_info_t));
    if (!user_tenant_info_local_var) {
        return NULL;
    }
    memset(user_tenant_info_local_var, 0, sizeof(user_tenant_info_t));
    user_tenant_info_local_var->_library_owned = 1;
    user_tenant_info_local_var->custom_domain = custom_domain;
    user_tenant_info_local_var->role = role;
    user_tenant_info_local_var->subdomain = subdomain;
    user_tenant_info_local_var->tenant_id = tenant_id;
    user_tenant_info_local_var->tenant_name = tenant_name;
    return user_tenant_info_local_var;
}

__attribute__((deprecated)) user_tenant_info_t *user_tenant_info_create(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
    ) {
    user_tenant_info_t *result = user_tenant_info_create_internal (
        custom_domain,
        role,
        subdomain,
        tenant_id,
        tenant_name
        );
    if (!result) {
    }
    return result;
}

void user_tenant_info_free(user_tenant_info_t *user_tenant_info) {
    if(NULL == user_tenant_info){
        return ;
    }
    if(user_tenant_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_tenant_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_tenant_info->custom_domain) {
        free(user_tenant_info->custom_domain);
        user_tenant_info->custom_domain = NULL;
    }
    if (user_tenant_info->role) {
        free(user_tenant_info->role);
        user_tenant_info->role = NULL;
    }
    if (user_tenant_info->subdomain) {
        free(user_tenant_info->subdomain);
        user_tenant_info->subdomain = NULL;
    }
    if (user_tenant_info->tenant_id) {
        free(user_tenant_info->tenant_id);
        user_tenant_info->tenant_id = NULL;
    }
    if (user_tenant_info->tenant_name) {
        free(user_tenant_info->tenant_name);
        user_tenant_info->tenant_name = NULL;
    }
    free(user_tenant_info);
}

cJSON *user_tenant_info_convertToJSON(user_tenant_info_t *user_tenant_info) {
    cJSON *item = cJSON_CreateObject();

    // user_tenant_info->custom_domain
    if(user_tenant_info->custom_domain) {
    if(cJSON_AddStringToObject(item, "custom_domain", user_tenant_info->custom_domain) == NULL) {
    goto fail; //String
    }
    }


    // user_tenant_info->role
    if (!user_tenant_info->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", user_tenant_info->role) == NULL) {
    goto fail; //String
    }


    // user_tenant_info->subdomain
    if(user_tenant_info->subdomain) {
    if(cJSON_AddStringToObject(item, "subdomain", user_tenant_info->subdomain) == NULL) {
    goto fail; //String
    }
    }


    // user_tenant_info->tenant_id
    if (!user_tenant_info->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", user_tenant_info->tenant_id) == NULL) {
    goto fail; //String
    }


    // user_tenant_info->tenant_name
    if (!user_tenant_info->tenant_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_name", user_tenant_info->tenant_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_tenant_info_t *user_tenant_info_parseFromJSON(cJSON *user_tenant_infoJSON){

    user_tenant_info_t *user_tenant_info_local_var = NULL;

    char *custom_domain_local_str = NULL;

    char *role_local_str = NULL;

    char *subdomain_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *tenant_name_local_str = NULL;

    // user_tenant_info->custom_domain
    cJSON *custom_domain = cJSON_GetObjectItemCaseSensitive(user_tenant_infoJSON, "custom_domain");
    if (cJSON_IsNull(custom_domain)) {
        custom_domain = NULL;
    }
    if (custom_domain) { 
    if(!cJSON_IsString(custom_domain) && !cJSON_IsNull(custom_domain))
    {
    goto end; //String
    }
    }

    // user_tenant_info->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(user_tenant_infoJSON, "role");
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

    // user_tenant_info->subdomain
    cJSON *subdomain = cJSON_GetObjectItemCaseSensitive(user_tenant_infoJSON, "subdomain");
    if (cJSON_IsNull(subdomain)) {
        subdomain = NULL;
    }
    if (subdomain) { 
    if(!cJSON_IsString(subdomain) && !cJSON_IsNull(subdomain))
    {
    goto end; //String
    }
    }

    // user_tenant_info->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(user_tenant_infoJSON, "tenant_id");
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

    // user_tenant_info->tenant_name
    cJSON *tenant_name = cJSON_GetObjectItemCaseSensitive(user_tenant_infoJSON, "tenant_name");
    if (cJSON_IsNull(tenant_name)) {
        tenant_name = NULL;
    }
    if (!tenant_name) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_name))
    {
    goto end; //String
    }


    if (custom_domain && !cJSON_IsNull(custom_domain)) custom_domain_local_str = strdup(custom_domain->valuestring);
    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);
    if (subdomain && !cJSON_IsNull(subdomain)) subdomain_local_str = strdup(subdomain->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (tenant_name && !cJSON_IsNull(tenant_name)) tenant_name_local_str = strdup(tenant_name->valuestring);

    user_tenant_info_local_var = user_tenant_info_create_internal (
        custom_domain_local_str,
        role_local_str,
        subdomain_local_str,
        tenant_id_local_str,
        tenant_name_local_str
        );

    if (!user_tenant_info_local_var) {
        goto end;
    }

    return user_tenant_info_local_var;
end:
    if (custom_domain_local_str) {
        free(custom_domain_local_str);
        custom_domain_local_str = NULL;
    }
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (subdomain_local_str) {
        free(subdomain_local_str);
        subdomain_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (tenant_name_local_str) {
        free(tenant_name_local_str);
        tenant_name_local_str = NULL;
    }
    return NULL;

}
