#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_tenant.h"



static gdpr_tenant_t *gdpr_tenant_create_internal(
    char *name,
    char *role,
    char *tenant_id
    ) {
    gdpr_tenant_t *gdpr_tenant_local_var = malloc(sizeof(gdpr_tenant_t));
    if (!gdpr_tenant_local_var) {
        return NULL;
    }
    memset(gdpr_tenant_local_var, 0, sizeof(gdpr_tenant_t));
    gdpr_tenant_local_var->_library_owned = 1;
    gdpr_tenant_local_var->name = name;
    gdpr_tenant_local_var->role = role;
    gdpr_tenant_local_var->tenant_id = tenant_id;
    return gdpr_tenant_local_var;
}

__attribute__((deprecated)) gdpr_tenant_t *gdpr_tenant_create(
    char *name,
    char *role,
    char *tenant_id
    ) {
    gdpr_tenant_t *result = gdpr_tenant_create_internal (
        name,
        role,
        tenant_id
        );
    if (!result) {
    }
    return result;
}

void gdpr_tenant_free(gdpr_tenant_t *gdpr_tenant) {
    if(NULL == gdpr_tenant){
        return ;
    }
    if(gdpr_tenant->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_tenant_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_tenant->name) {
        free(gdpr_tenant->name);
        gdpr_tenant->name = NULL;
    }
    if (gdpr_tenant->role) {
        free(gdpr_tenant->role);
        gdpr_tenant->role = NULL;
    }
    if (gdpr_tenant->tenant_id) {
        free(gdpr_tenant->tenant_id);
        gdpr_tenant->tenant_id = NULL;
    }
    free(gdpr_tenant);
}

cJSON *gdpr_tenant_convertToJSON(gdpr_tenant_t *gdpr_tenant) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_tenant->name
    if (!gdpr_tenant->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", gdpr_tenant->name) == NULL) {
    goto fail; //String
    }


    // gdpr_tenant->role
    if (!gdpr_tenant->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", gdpr_tenant->role) == NULL) {
    goto fail; //String
    }


    // gdpr_tenant->tenant_id
    if (!gdpr_tenant->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_tenant->tenant_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_tenant_t *gdpr_tenant_parseFromJSON(cJSON *gdpr_tenantJSON){

    gdpr_tenant_t *gdpr_tenant_local_var = NULL;

    char *name_local_str = NULL;

    char *role_local_str = NULL;

    char *tenant_id_local_str = NULL;

    // gdpr_tenant->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(gdpr_tenantJSON, "name");
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

    // gdpr_tenant->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(gdpr_tenantJSON, "role");
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

    // gdpr_tenant->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_tenantJSON, "tenantId");
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


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (role && !cJSON_IsNull(role)) role_local_str = strdup(role->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);

    gdpr_tenant_local_var = gdpr_tenant_create_internal (
        name_local_str,
        role_local_str,
        tenant_id_local_str
        );

    if (!gdpr_tenant_local_var) {
        goto end;
    }

    return gdpr_tenant_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (role_local_str) {
        free(role_local_str);
        role_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    return NULL;

}
