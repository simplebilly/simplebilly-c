#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_profile.h"



static user_profile_t *user_profile_create_internal(
    char *created_at,
    char *email,
    int *email_verified,
    char *first_name,
    char *full_name,
    char *id,
    char *last_name
    ) {
    user_profile_t *user_profile_local_var = malloc(sizeof(user_profile_t));
    if (!user_profile_local_var) {
        return NULL;
    }
    memset(user_profile_local_var, 0, sizeof(user_profile_t));
    user_profile_local_var->_library_owned = 1;
    user_profile_local_var->created_at = created_at;
    user_profile_local_var->email = email;
    user_profile_local_var->email_verified = email_verified;
    user_profile_local_var->first_name = first_name;
    user_profile_local_var->full_name = full_name;
    user_profile_local_var->id = id;
    user_profile_local_var->last_name = last_name;
    return user_profile_local_var;
}

__attribute__((deprecated)) user_profile_t *user_profile_create(
    char *created_at,
    char *email,
    int *email_verified,
    char *first_name,
    char *full_name,
    char *id,
    char *last_name
    ) {
    int *email_verified_copy = NULL;
    if (email_verified) {
        email_verified_copy = malloc(sizeof(int));
        if (email_verified_copy) *email_verified_copy = *email_verified;
    }
    user_profile_t *result = user_profile_create_internal (
        created_at,
        email,
        email_verified_copy,
        first_name,
        full_name,
        id,
        last_name
        );
    if (!result) {
        free(email_verified_copy);
    }
    return result;
}

void user_profile_free(user_profile_t *user_profile) {
    if(NULL == user_profile){
        return ;
    }
    if(user_profile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_profile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_profile->created_at) {
        free(user_profile->created_at);
        user_profile->created_at = NULL;
    }
    if (user_profile->email) {
        free(user_profile->email);
        user_profile->email = NULL;
    }
    if (user_profile->email_verified) {
        free(user_profile->email_verified);
        user_profile->email_verified = NULL;
    }
    if (user_profile->first_name) {
        free(user_profile->first_name);
        user_profile->first_name = NULL;
    }
    if (user_profile->full_name) {
        free(user_profile->full_name);
        user_profile->full_name = NULL;
    }
    if (user_profile->id) {
        free(user_profile->id);
        user_profile->id = NULL;
    }
    if (user_profile->last_name) {
        free(user_profile->last_name);
        user_profile->last_name = NULL;
    }
    free(user_profile);
}

cJSON *user_profile_convertToJSON(user_profile_t *user_profile) {
    cJSON *item = cJSON_CreateObject();

    // user_profile->created_at
    if (!user_profile->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", user_profile->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // user_profile->email
    if (!user_profile->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", user_profile->email) == NULL) {
    goto fail; //String
    }


    // user_profile->email_verified
    if (!user_profile->email_verified) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "email_verified", *user_profile->email_verified) == NULL) {
    goto fail; //Bool
    }


    // user_profile->first_name
    if (!user_profile->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", user_profile->first_name) == NULL) {
    goto fail; //String
    }


    // user_profile->full_name
    if (!user_profile->full_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "full_name", user_profile->full_name) == NULL) {
    goto fail; //String
    }


    // user_profile->id
    if (!user_profile->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", user_profile->id) == NULL) {
    goto fail; //String
    }


    // user_profile->last_name
    if (!user_profile->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "last_name", user_profile->last_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_profile_t *user_profile_parseFromJSON(cJSON *user_profileJSON){

    user_profile_t *user_profile_local_var = NULL;

    char *created_at_local_str = NULL;

    char *email_local_str = NULL;

    // define the local variable for user_profile->email_verified
    int *email_verified_local_var = NULL;

    char *first_name_local_str = NULL;

    char *full_name_local_str = NULL;

    char *id_local_str = NULL;

    char *last_name_local_str = NULL;

    // user_profile->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "created_at");
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

    // user_profile->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "email");
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

    // user_profile->email_verified
    cJSON *email_verified = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "email_verified");
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

    // user_profile->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // user_profile->full_name
    cJSON *full_name = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "full_name");
    if (cJSON_IsNull(full_name)) {
        full_name = NULL;
    }
    if (!full_name) {
        goto end;
    }

    
    if(!cJSON_IsString(full_name))
    {
    goto end; //String
    }

    // user_profile->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "id");
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

    // user_profile->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(user_profileJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (!last_name) {
        goto end;
    }

    
    if(!cJSON_IsString(last_name))
    {
    goto end; //String
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (full_name && !cJSON_IsNull(full_name)) full_name_local_str = strdup(full_name->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);

    user_profile_local_var = user_profile_create_internal (
        created_at_local_str,
        email_local_str,
        email_verified_local_var,
        first_name_local_str,
        full_name_local_str,
        id_local_str,
        last_name_local_str
        );

    if (!user_profile_local_var) {
        goto end;
    }

    return user_profile_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (email_verified_local_var) {
        free(email_verified_local_var);
        email_verified_local_var = NULL;
    }
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (full_name_local_str) {
        free(full_name_local_str);
        full_name_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    return NULL;

}
