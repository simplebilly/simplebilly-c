#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_refresh_token.h"



static gdpr_refresh_token_t *gdpr_refresh_token_create_internal(
    char *created_at,
    char *expires_at,
    char *id,
    char *revoked_at,
    char *tenant_id
    ) {
    gdpr_refresh_token_t *gdpr_refresh_token_local_var = malloc(sizeof(gdpr_refresh_token_t));
    if (!gdpr_refresh_token_local_var) {
        return NULL;
    }
    memset(gdpr_refresh_token_local_var, 0, sizeof(gdpr_refresh_token_t));
    gdpr_refresh_token_local_var->_library_owned = 1;
    gdpr_refresh_token_local_var->created_at = created_at;
    gdpr_refresh_token_local_var->expires_at = expires_at;
    gdpr_refresh_token_local_var->id = id;
    gdpr_refresh_token_local_var->revoked_at = revoked_at;
    gdpr_refresh_token_local_var->tenant_id = tenant_id;
    return gdpr_refresh_token_local_var;
}

__attribute__((deprecated)) gdpr_refresh_token_t *gdpr_refresh_token_create(
    char *created_at,
    char *expires_at,
    char *id,
    char *revoked_at,
    char *tenant_id
    ) {
    gdpr_refresh_token_t *result = gdpr_refresh_token_create_internal (
        created_at,
        expires_at,
        id,
        revoked_at,
        tenant_id
        );
    if (!result) {
    }
    return result;
}

void gdpr_refresh_token_free(gdpr_refresh_token_t *gdpr_refresh_token) {
    if(NULL == gdpr_refresh_token){
        return ;
    }
    if(gdpr_refresh_token->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_refresh_token_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_refresh_token->created_at) {
        free(gdpr_refresh_token->created_at);
        gdpr_refresh_token->created_at = NULL;
    }
    if (gdpr_refresh_token->expires_at) {
        free(gdpr_refresh_token->expires_at);
        gdpr_refresh_token->expires_at = NULL;
    }
    if (gdpr_refresh_token->id) {
        free(gdpr_refresh_token->id);
        gdpr_refresh_token->id = NULL;
    }
    if (gdpr_refresh_token->revoked_at) {
        free(gdpr_refresh_token->revoked_at);
        gdpr_refresh_token->revoked_at = NULL;
    }
    if (gdpr_refresh_token->tenant_id) {
        free(gdpr_refresh_token->tenant_id);
        gdpr_refresh_token->tenant_id = NULL;
    }
    free(gdpr_refresh_token);
}

cJSON *gdpr_refresh_token_convertToJSON(gdpr_refresh_token_t *gdpr_refresh_token) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_refresh_token->created_at
    if (!gdpr_refresh_token->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_refresh_token->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_refresh_token->expires_at
    if (!gdpr_refresh_token->expires_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expiresAt", gdpr_refresh_token->expires_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_refresh_token->id
    if (!gdpr_refresh_token->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_refresh_token->id) == NULL) {
    goto fail; //String
    }


    // gdpr_refresh_token->revoked_at
    if(gdpr_refresh_token->revoked_at) {
    if(cJSON_AddStringToObject(item, "revokedAt", gdpr_refresh_token->revoked_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // gdpr_refresh_token->tenant_id
    if (!gdpr_refresh_token->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_refresh_token->tenant_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_refresh_token_t *gdpr_refresh_token_parseFromJSON(cJSON *gdpr_refresh_tokenJSON){

    gdpr_refresh_token_t *gdpr_refresh_token_local_var = NULL;

    char *created_at_local_str = NULL;

    char *expires_at_local_str = NULL;

    char *id_local_str = NULL;

    char *revoked_at_local_str = NULL;

    char *tenant_id_local_str = NULL;

    // gdpr_refresh_token->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_refresh_tokenJSON, "createdAt");
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

    // gdpr_refresh_token->expires_at
    cJSON *expires_at = cJSON_GetObjectItemCaseSensitive(gdpr_refresh_tokenJSON, "expiresAt");
    if (cJSON_IsNull(expires_at)) {
        expires_at = NULL;
    }
    if (!expires_at) {
        goto end;
    }

    
    if(!cJSON_IsString(expires_at) && !cJSON_IsNull(expires_at))
    {
    goto end; //DateTime
    }

    // gdpr_refresh_token->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_refresh_tokenJSON, "id");
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

    // gdpr_refresh_token->revoked_at
    cJSON *revoked_at = cJSON_GetObjectItemCaseSensitive(gdpr_refresh_tokenJSON, "revokedAt");
    if (cJSON_IsNull(revoked_at)) {
        revoked_at = NULL;
    }
    if (revoked_at) { 
    if(!cJSON_IsString(revoked_at) && !cJSON_IsNull(revoked_at))
    {
    goto end; //DateTime
    }
    }

    // gdpr_refresh_token->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_refresh_tokenJSON, "tenantId");
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


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (expires_at && !cJSON_IsNull(expires_at)) expires_at_local_str = strdup(expires_at->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (revoked_at && !cJSON_IsNull(revoked_at)) revoked_at_local_str = strdup(revoked_at->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);

    gdpr_refresh_token_local_var = gdpr_refresh_token_create_internal (
        created_at_local_str,
        expires_at_local_str,
        id_local_str,
        revoked_at_local_str,
        tenant_id_local_str
        );

    if (!gdpr_refresh_token_local_var) {
        goto end;
    }

    return gdpr_refresh_token_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (expires_at_local_str) {
        free(expires_at_local_str);
        expires_at_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (revoked_at_local_str) {
        free(revoked_at_local_str);
        revoked_at_local_str = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    return NULL;

}
