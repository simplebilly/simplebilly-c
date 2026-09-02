#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_api_key.h"



static gdpr_api_key_t *gdpr_api_key_create_internal(
    char *created_at,
    char *expires_at,
    char *id,
    char *key_id,
    char *name,
    int *revoked
    ) {
    gdpr_api_key_t *gdpr_api_key_local_var = malloc(sizeof(gdpr_api_key_t));
    if (!gdpr_api_key_local_var) {
        return NULL;
    }
    memset(gdpr_api_key_local_var, 0, sizeof(gdpr_api_key_t));
    gdpr_api_key_local_var->_library_owned = 1;
    gdpr_api_key_local_var->created_at = created_at;
    gdpr_api_key_local_var->expires_at = expires_at;
    gdpr_api_key_local_var->id = id;
    gdpr_api_key_local_var->key_id = key_id;
    gdpr_api_key_local_var->name = name;
    gdpr_api_key_local_var->revoked = revoked;
    return gdpr_api_key_local_var;
}

__attribute__((deprecated)) gdpr_api_key_t *gdpr_api_key_create(
    char *created_at,
    char *expires_at,
    char *id,
    char *key_id,
    char *name,
    int *revoked
    ) {
    int *revoked_copy = NULL;
    if (revoked) {
        revoked_copy = malloc(sizeof(int));
        if (revoked_copy) *revoked_copy = *revoked;
    }
    gdpr_api_key_t *result = gdpr_api_key_create_internal (
        created_at,
        expires_at,
        id,
        key_id,
        name,
        revoked_copy
        );
    if (!result) {
        free(revoked_copy);
    }
    return result;
}

void gdpr_api_key_free(gdpr_api_key_t *gdpr_api_key) {
    if(NULL == gdpr_api_key){
        return ;
    }
    if(gdpr_api_key->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_api_key_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_api_key->created_at) {
        free(gdpr_api_key->created_at);
        gdpr_api_key->created_at = NULL;
    }
    if (gdpr_api_key->expires_at) {
        free(gdpr_api_key->expires_at);
        gdpr_api_key->expires_at = NULL;
    }
    if (gdpr_api_key->id) {
        free(gdpr_api_key->id);
        gdpr_api_key->id = NULL;
    }
    if (gdpr_api_key->key_id) {
        free(gdpr_api_key->key_id);
        gdpr_api_key->key_id = NULL;
    }
    if (gdpr_api_key->name) {
        free(gdpr_api_key->name);
        gdpr_api_key->name = NULL;
    }
    if (gdpr_api_key->revoked) {
        free(gdpr_api_key->revoked);
        gdpr_api_key->revoked = NULL;
    }
    free(gdpr_api_key);
}

cJSON *gdpr_api_key_convertToJSON(gdpr_api_key_t *gdpr_api_key) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_api_key->created_at
    if (!gdpr_api_key->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_api_key->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_api_key->expires_at
    if(gdpr_api_key->expires_at) {
    if(cJSON_AddStringToObject(item, "expiresAt", gdpr_api_key->expires_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // gdpr_api_key->id
    if (!gdpr_api_key->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_api_key->id) == NULL) {
    goto fail; //String
    }


    // gdpr_api_key->key_id
    if (!gdpr_api_key->key_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "keyId", gdpr_api_key->key_id) == NULL) {
    goto fail; //String
    }


    // gdpr_api_key->name
    if (!gdpr_api_key->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", gdpr_api_key->name) == NULL) {
    goto fail; //String
    }


    // gdpr_api_key->revoked
    if (!gdpr_api_key->revoked) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "revoked", *gdpr_api_key->revoked) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_api_key_t *gdpr_api_key_parseFromJSON(cJSON *gdpr_api_keyJSON){

    gdpr_api_key_t *gdpr_api_key_local_var = NULL;

    char *created_at_local_str = NULL;

    char *expires_at_local_str = NULL;

    char *id_local_str = NULL;

    char *key_id_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for gdpr_api_key->revoked
    int *revoked_local_var = NULL;

    // gdpr_api_key->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "createdAt");
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

    // gdpr_api_key->expires_at
    cJSON *expires_at = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "expiresAt");
    if (cJSON_IsNull(expires_at)) {
        expires_at = NULL;
    }
    if (expires_at) { 
    if(!cJSON_IsString(expires_at) && !cJSON_IsNull(expires_at))
    {
    goto end; //DateTime
    }
    }

    // gdpr_api_key->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "id");
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

    // gdpr_api_key->key_id
    cJSON *key_id = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "keyId");
    if (cJSON_IsNull(key_id)) {
        key_id = NULL;
    }
    if (!key_id) {
        goto end;
    }

    
    if(!cJSON_IsString(key_id))
    {
    goto end; //String
    }

    // gdpr_api_key->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "name");
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

    // gdpr_api_key->revoked
    cJSON *revoked = cJSON_GetObjectItemCaseSensitive(gdpr_api_keyJSON, "revoked");
    if (cJSON_IsNull(revoked)) {
        revoked = NULL;
    }
    if (!revoked) {
        goto end;
    }

    
    if(!cJSON_IsBool(revoked))
    {
    goto end; //Bool
    }
    revoked_local_var = malloc(sizeof(int));
    if(!revoked_local_var)
    {
        goto end;
    }
    *revoked_local_var = revoked->valueint;


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (expires_at && !cJSON_IsNull(expires_at)) expires_at_local_str = strdup(expires_at->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (key_id && !cJSON_IsNull(key_id)) key_id_local_str = strdup(key_id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    gdpr_api_key_local_var = gdpr_api_key_create_internal (
        created_at_local_str,
        expires_at_local_str,
        id_local_str,
        key_id_local_str,
        name_local_str,
        revoked_local_var
        );

    if (!gdpr_api_key_local_var) {
        goto end;
    }

    return gdpr_api_key_local_var;
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
    if (key_id_local_str) {
        free(key_id_local_str);
        key_id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (revoked_local_var) {
        free(revoked_local_var);
        revoked_local_var = NULL;
    }
    return NULL;

}
