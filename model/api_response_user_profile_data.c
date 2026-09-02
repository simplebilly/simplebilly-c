#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_user_profile_data.h"



static api_response_user_profile_data_t *api_response_user_profile_data_create_internal(
    char *created_at,
    char *email,
    int *email_verified,
    char *first_name,
    char *full_name,
    char *id,
    char *last_name
    ) {
    api_response_user_profile_data_t *api_response_user_profile_data_local_var = malloc(sizeof(api_response_user_profile_data_t));
    if (!api_response_user_profile_data_local_var) {
        return NULL;
    }
    memset(api_response_user_profile_data_local_var, 0, sizeof(api_response_user_profile_data_t));
    api_response_user_profile_data_local_var->_library_owned = 1;
    api_response_user_profile_data_local_var->created_at = created_at;
    api_response_user_profile_data_local_var->email = email;
    api_response_user_profile_data_local_var->email_verified = email_verified;
    api_response_user_profile_data_local_var->first_name = first_name;
    api_response_user_profile_data_local_var->full_name = full_name;
    api_response_user_profile_data_local_var->id = id;
    api_response_user_profile_data_local_var->last_name = last_name;
    return api_response_user_profile_data_local_var;
}

__attribute__((deprecated)) api_response_user_profile_data_t *api_response_user_profile_data_create(
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
    api_response_user_profile_data_t *result = api_response_user_profile_data_create_internal (
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

void api_response_user_profile_data_free(api_response_user_profile_data_t *api_response_user_profile_data) {
    if(NULL == api_response_user_profile_data){
        return ;
    }
    if(api_response_user_profile_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_user_profile_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_user_profile_data->created_at) {
        free(api_response_user_profile_data->created_at);
        api_response_user_profile_data->created_at = NULL;
    }
    if (api_response_user_profile_data->email) {
        free(api_response_user_profile_data->email);
        api_response_user_profile_data->email = NULL;
    }
    if (api_response_user_profile_data->email_verified) {
        free(api_response_user_profile_data->email_verified);
        api_response_user_profile_data->email_verified = NULL;
    }
    if (api_response_user_profile_data->first_name) {
        free(api_response_user_profile_data->first_name);
        api_response_user_profile_data->first_name = NULL;
    }
    if (api_response_user_profile_data->full_name) {
        free(api_response_user_profile_data->full_name);
        api_response_user_profile_data->full_name = NULL;
    }
    if (api_response_user_profile_data->id) {
        free(api_response_user_profile_data->id);
        api_response_user_profile_data->id = NULL;
    }
    if (api_response_user_profile_data->last_name) {
        free(api_response_user_profile_data->last_name);
        api_response_user_profile_data->last_name = NULL;
    }
    free(api_response_user_profile_data);
}

cJSON *api_response_user_profile_data_convertToJSON(api_response_user_profile_data_t *api_response_user_profile_data) {
    cJSON *item = cJSON_CreateObject();

    // api_response_user_profile_data->created_at
    if (!api_response_user_profile_data->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", api_response_user_profile_data->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // api_response_user_profile_data->email
    if (!api_response_user_profile_data->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", api_response_user_profile_data->email) == NULL) {
    goto fail; //String
    }


    // api_response_user_profile_data->email_verified
    if (!api_response_user_profile_data->email_verified) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "email_verified", *api_response_user_profile_data->email_verified) == NULL) {
    goto fail; //Bool
    }


    // api_response_user_profile_data->first_name
    if (!api_response_user_profile_data->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", api_response_user_profile_data->first_name) == NULL) {
    goto fail; //String
    }


    // api_response_user_profile_data->full_name
    if (!api_response_user_profile_data->full_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "full_name", api_response_user_profile_data->full_name) == NULL) {
    goto fail; //String
    }


    // api_response_user_profile_data->id
    if (!api_response_user_profile_data->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", api_response_user_profile_data->id) == NULL) {
    goto fail; //String
    }


    // api_response_user_profile_data->last_name
    if (!api_response_user_profile_data->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "last_name", api_response_user_profile_data->last_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_user_profile_data_t *api_response_user_profile_data_parseFromJSON(cJSON *api_response_user_profile_dataJSON){

    api_response_user_profile_data_t *api_response_user_profile_data_local_var = NULL;

    char *created_at_local_str = NULL;

    char *email_local_str = NULL;

    // define the local variable for api_response_user_profile_data->email_verified
    int *email_verified_local_var = NULL;

    char *first_name_local_str = NULL;

    char *full_name_local_str = NULL;

    char *id_local_str = NULL;

    char *last_name_local_str = NULL;

    // api_response_user_profile_data->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "created_at");
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

    // api_response_user_profile_data->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "email");
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

    // api_response_user_profile_data->email_verified
    cJSON *email_verified = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "email_verified");
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

    // api_response_user_profile_data->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "first_name");
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

    // api_response_user_profile_data->full_name
    cJSON *full_name = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "full_name");
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

    // api_response_user_profile_data->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "id");
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

    // api_response_user_profile_data->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(api_response_user_profile_dataJSON, "last_name");
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

    api_response_user_profile_data_local_var = api_response_user_profile_data_create_internal (
        created_at_local_str,
        email_local_str,
        email_verified_local_var,
        first_name_local_str,
        full_name_local_str,
        id_local_str,
        last_name_local_str
        );

    if (!api_response_user_profile_data_local_var) {
        goto end;
    }

    return api_response_user_profile_data_local_var;
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
