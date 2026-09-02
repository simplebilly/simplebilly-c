#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_vec_user_tenant_info_data_inner.h"



static api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_create_internal(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
    ) {
    api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_local_var = malloc(sizeof(api_response_vec_user_tenant_info_data_inner_t));
    if (!api_response_vec_user_tenant_info_data_inner_local_var) {
        return NULL;
    }
    memset(api_response_vec_user_tenant_info_data_inner_local_var, 0, sizeof(api_response_vec_user_tenant_info_data_inner_t));
    api_response_vec_user_tenant_info_data_inner_local_var->_library_owned = 1;
    api_response_vec_user_tenant_info_data_inner_local_var->custom_domain = custom_domain;
    api_response_vec_user_tenant_info_data_inner_local_var->role = role;
    api_response_vec_user_tenant_info_data_inner_local_var->subdomain = subdomain;
    api_response_vec_user_tenant_info_data_inner_local_var->tenant_id = tenant_id;
    api_response_vec_user_tenant_info_data_inner_local_var->tenant_name = tenant_name;
    return api_response_vec_user_tenant_info_data_inner_local_var;
}

__attribute__((deprecated)) api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_create(
    char *custom_domain,
    char *role,
    char *subdomain,
    char *tenant_id,
    char *tenant_name
    ) {
    api_response_vec_user_tenant_info_data_inner_t *result = api_response_vec_user_tenant_info_data_inner_create_internal (
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

void api_response_vec_user_tenant_info_data_inner_free(api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner) {
    if(NULL == api_response_vec_user_tenant_info_data_inner){
        return ;
    }
    if(api_response_vec_user_tenant_info_data_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_vec_user_tenant_info_data_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_vec_user_tenant_info_data_inner->custom_domain) {
        free(api_response_vec_user_tenant_info_data_inner->custom_domain);
        api_response_vec_user_tenant_info_data_inner->custom_domain = NULL;
    }
    if (api_response_vec_user_tenant_info_data_inner->role) {
        free(api_response_vec_user_tenant_info_data_inner->role);
        api_response_vec_user_tenant_info_data_inner->role = NULL;
    }
    if (api_response_vec_user_tenant_info_data_inner->subdomain) {
        free(api_response_vec_user_tenant_info_data_inner->subdomain);
        api_response_vec_user_tenant_info_data_inner->subdomain = NULL;
    }
    if (api_response_vec_user_tenant_info_data_inner->tenant_id) {
        free(api_response_vec_user_tenant_info_data_inner->tenant_id);
        api_response_vec_user_tenant_info_data_inner->tenant_id = NULL;
    }
    if (api_response_vec_user_tenant_info_data_inner->tenant_name) {
        free(api_response_vec_user_tenant_info_data_inner->tenant_name);
        api_response_vec_user_tenant_info_data_inner->tenant_name = NULL;
    }
    free(api_response_vec_user_tenant_info_data_inner);
}

cJSON *api_response_vec_user_tenant_info_data_inner_convertToJSON(api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner) {
    cJSON *item = cJSON_CreateObject();

    // api_response_vec_user_tenant_info_data_inner->custom_domain
    if(api_response_vec_user_tenant_info_data_inner->custom_domain) {
    if(cJSON_AddStringToObject(item, "custom_domain", api_response_vec_user_tenant_info_data_inner->custom_domain) == NULL) {
    goto fail; //String
    }
    }


    // api_response_vec_user_tenant_info_data_inner->role
    if (!api_response_vec_user_tenant_info_data_inner->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", api_response_vec_user_tenant_info_data_inner->role) == NULL) {
    goto fail; //String
    }


    // api_response_vec_user_tenant_info_data_inner->subdomain
    if(api_response_vec_user_tenant_info_data_inner->subdomain) {
    if(cJSON_AddStringToObject(item, "subdomain", api_response_vec_user_tenant_info_data_inner->subdomain) == NULL) {
    goto fail; //String
    }
    }


    // api_response_vec_user_tenant_info_data_inner->tenant_id
    if (!api_response_vec_user_tenant_info_data_inner->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", api_response_vec_user_tenant_info_data_inner->tenant_id) == NULL) {
    goto fail; //String
    }


    // api_response_vec_user_tenant_info_data_inner->tenant_name
    if (!api_response_vec_user_tenant_info_data_inner->tenant_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_name", api_response_vec_user_tenant_info_data_inner->tenant_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_parseFromJSON(cJSON *api_response_vec_user_tenant_info_data_innerJSON){

    api_response_vec_user_tenant_info_data_inner_t *api_response_vec_user_tenant_info_data_inner_local_var = NULL;

    char *custom_domain_local_str = NULL;

    char *role_local_str = NULL;

    char *subdomain_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *tenant_name_local_str = NULL;

    // api_response_vec_user_tenant_info_data_inner->custom_domain
    cJSON *custom_domain = cJSON_GetObjectItemCaseSensitive(api_response_vec_user_tenant_info_data_innerJSON, "custom_domain");
    if (cJSON_IsNull(custom_domain)) {
        custom_domain = NULL;
    }
    if (custom_domain) { 
    if(!cJSON_IsString(custom_domain) && !cJSON_IsNull(custom_domain))
    {
    goto end; //String
    }
    }

    // api_response_vec_user_tenant_info_data_inner->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(api_response_vec_user_tenant_info_data_innerJSON, "role");
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

    // api_response_vec_user_tenant_info_data_inner->subdomain
    cJSON *subdomain = cJSON_GetObjectItemCaseSensitive(api_response_vec_user_tenant_info_data_innerJSON, "subdomain");
    if (cJSON_IsNull(subdomain)) {
        subdomain = NULL;
    }
    if (subdomain) { 
    if(!cJSON_IsString(subdomain) && !cJSON_IsNull(subdomain))
    {
    goto end; //String
    }
    }

    // api_response_vec_user_tenant_info_data_inner->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(api_response_vec_user_tenant_info_data_innerJSON, "tenant_id");
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

    // api_response_vec_user_tenant_info_data_inner->tenant_name
    cJSON *tenant_name = cJSON_GetObjectItemCaseSensitive(api_response_vec_user_tenant_info_data_innerJSON, "tenant_name");
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

    api_response_vec_user_tenant_info_data_inner_local_var = api_response_vec_user_tenant_info_data_inner_create_internal (
        custom_domain_local_str,
        role_local_str,
        subdomain_local_str,
        tenant_id_local_str,
        tenant_name_local_str
        );

    if (!api_response_vec_user_tenant_info_data_inner_local_var) {
        goto end;
    }

    return api_response_vec_user_tenant_info_data_inner_local_var;
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
