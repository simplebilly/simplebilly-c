#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_user_profile.h"



static api_response_user_profile_t *api_response_user_profile_create_internal(
    api_response_user_profile_data_t *data,
    char *error,
    char *message,
    int *success
    ) {
    api_response_user_profile_t *api_response_user_profile_local_var = malloc(sizeof(api_response_user_profile_t));
    if (!api_response_user_profile_local_var) {
        return NULL;
    }
    memset(api_response_user_profile_local_var, 0, sizeof(api_response_user_profile_t));
    api_response_user_profile_local_var->_library_owned = 1;
    api_response_user_profile_local_var->data = data;
    api_response_user_profile_local_var->error = error;
    api_response_user_profile_local_var->message = message;
    api_response_user_profile_local_var->success = success;
    return api_response_user_profile_local_var;
}

__attribute__((deprecated)) api_response_user_profile_t *api_response_user_profile_create(
    api_response_user_profile_data_t *data,
    char *error,
    char *message,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    api_response_user_profile_t *result = api_response_user_profile_create_internal (
        data,
        error,
        message,
        success_copy
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void api_response_user_profile_free(api_response_user_profile_t *api_response_user_profile) {
    if(NULL == api_response_user_profile){
        return ;
    }
    if(api_response_user_profile->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_user_profile_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_user_profile->data) {
        api_response_user_profile_data_free(api_response_user_profile->data);
        api_response_user_profile->data = NULL;
    }
    if (api_response_user_profile->error) {
        free(api_response_user_profile->error);
        api_response_user_profile->error = NULL;
    }
    if (api_response_user_profile->message) {
        free(api_response_user_profile->message);
        api_response_user_profile->message = NULL;
    }
    if (api_response_user_profile->success) {
        free(api_response_user_profile->success);
        api_response_user_profile->success = NULL;
    }
    free(api_response_user_profile);
}

cJSON *api_response_user_profile_convertToJSON(api_response_user_profile_t *api_response_user_profile) {
    cJSON *item = cJSON_CreateObject();

    // api_response_user_profile->data
    if(api_response_user_profile->data) {
    cJSON *data_local_JSON = api_response_user_profile_data_convertToJSON(api_response_user_profile->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // api_response_user_profile->error
    if(api_response_user_profile->error) {
    if(cJSON_AddStringToObject(item, "error", api_response_user_profile->error) == NULL) {
    goto fail; //String
    }
    }


    // api_response_user_profile->message
    if(api_response_user_profile->message) {
    if(cJSON_AddStringToObject(item, "message", api_response_user_profile->message) == NULL) {
    goto fail; //String
    }
    }


    // api_response_user_profile->success
    if (!api_response_user_profile->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *api_response_user_profile->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_user_profile_t *api_response_user_profile_parseFromJSON(cJSON *api_response_user_profileJSON){

    api_response_user_profile_t *api_response_user_profile_local_var = NULL;

    // define the local variable for api_response_user_profile->data
    api_response_user_profile_data_t *data_local_nonprim = NULL;

    char *error_local_str = NULL;

    char *message_local_str = NULL;

    // define the local variable for api_response_user_profile->success
    int *success_local_var = NULL;

    // api_response_user_profile->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(api_response_user_profileJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = api_response_user_profile_data_parseFromJSON(data); //nonprimitive
    }

    // api_response_user_profile->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_response_user_profileJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // api_response_user_profile->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(api_response_user_profileJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // api_response_user_profile->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(api_response_user_profileJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }
    success_local_var = malloc(sizeof(int));
    if(!success_local_var)
    {
        goto end;
    }
    *success_local_var = success->valueint;


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);

    api_response_user_profile_local_var = api_response_user_profile_create_internal (
        data ? data_local_nonprim : NULL,
        error_local_str,
        message_local_str,
        success_local_var
        );

    if (!api_response_user_profile_local_var) {
        goto end;
    }

    return api_response_user_profile_local_var;
end:
    if (data_local_nonprim) {
        api_response_user_profile_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    return NULL;

}
