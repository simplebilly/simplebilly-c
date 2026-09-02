#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_response.h"



static auth_response_t *auth_response_create_internal(
    char *access_token,
    char *message,
    char *refresh_token,
    int *success,
    model_t *user
    ) {
    auth_response_t *auth_response_local_var = malloc(sizeof(auth_response_t));
    if (!auth_response_local_var) {
        return NULL;
    }
    memset(auth_response_local_var, 0, sizeof(auth_response_t));
    auth_response_local_var->_library_owned = 1;
    auth_response_local_var->access_token = access_token;
    auth_response_local_var->message = message;
    auth_response_local_var->refresh_token = refresh_token;
    auth_response_local_var->success = success;
    auth_response_local_var->user = user;
    return auth_response_local_var;
}

__attribute__((deprecated)) auth_response_t *auth_response_create(
    char *access_token,
    char *message,
    char *refresh_token,
    int *success,
    model_t *user
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    auth_response_t *result = auth_response_create_internal (
        access_token,
        message,
        refresh_token,
        success_copy,
        user
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void auth_response_free(auth_response_t *auth_response) {
    if(NULL == auth_response){
        return ;
    }
    if(auth_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "auth_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (auth_response->access_token) {
        free(auth_response->access_token);
        auth_response->access_token = NULL;
    }
    if (auth_response->message) {
        free(auth_response->message);
        auth_response->message = NULL;
    }
    if (auth_response->refresh_token) {
        free(auth_response->refresh_token);
        auth_response->refresh_token = NULL;
    }
    if (auth_response->success) {
        free(auth_response->success);
        auth_response->success = NULL;
    }
    if (auth_response->user) {
        model_free(auth_response->user);
        auth_response->user = NULL;
    }
    free(auth_response);
}

cJSON *auth_response_convertToJSON(auth_response_t *auth_response) {
    cJSON *item = cJSON_CreateObject();

    // auth_response->access_token
    if(auth_response->access_token) {
    if(cJSON_AddStringToObject(item, "access_token", auth_response->access_token) == NULL) {
    goto fail; //String
    }
    }


    // auth_response->message
    if(auth_response->message) {
    if(cJSON_AddStringToObject(item, "message", auth_response->message) == NULL) {
    goto fail; //String
    }
    }


    // auth_response->refresh_token
    if(auth_response->refresh_token) {
    if(cJSON_AddStringToObject(item, "refresh_token", auth_response->refresh_token) == NULL) {
    goto fail; //String
    }
    }


    // auth_response->success
    if (!auth_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *auth_response->success) == NULL) {
    goto fail; //Bool
    }


    // auth_response->user
    if(auth_response->user) {
    cJSON *user_local_JSON = model_convertToJSON(auth_response->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
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

auth_response_t *auth_response_parseFromJSON(cJSON *auth_responseJSON){

    auth_response_t *auth_response_local_var = NULL;

    char *access_token_local_str = NULL;

    char *message_local_str = NULL;

    char *refresh_token_local_str = NULL;

    // define the local variable for auth_response->success
    int *success_local_var = NULL;

    // define the local variable for auth_response->user
    model_t *user_local_nonprim = NULL;

    // auth_response->access_token
    cJSON *access_token = cJSON_GetObjectItemCaseSensitive(auth_responseJSON, "access_token");
    if (cJSON_IsNull(access_token)) {
        access_token = NULL;
    }
    if (access_token) { 
    if(!cJSON_IsString(access_token) && !cJSON_IsNull(access_token))
    {
    goto end; //String
    }
    }

    // auth_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(auth_responseJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // auth_response->refresh_token
    cJSON *refresh_token = cJSON_GetObjectItemCaseSensitive(auth_responseJSON, "refresh_token");
    if (cJSON_IsNull(refresh_token)) {
        refresh_token = NULL;
    }
    if (refresh_token) { 
    if(!cJSON_IsString(refresh_token) && !cJSON_IsNull(refresh_token))
    {
    goto end; //String
    }
    }

    // auth_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(auth_responseJSON, "success");
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

    // auth_response->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(auth_responseJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = model_parseFromJSON(user); //nonprimitive
    }


    if (access_token && !cJSON_IsNull(access_token)) access_token_local_str = strdup(access_token->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (refresh_token && !cJSON_IsNull(refresh_token)) refresh_token_local_str = strdup(refresh_token->valuestring);

    auth_response_local_var = auth_response_create_internal (
        access_token_local_str,
        message_local_str,
        refresh_token_local_str,
        success_local_var,
        user ? user_local_nonprim : NULL
        );

    if (!auth_response_local_var) {
        goto end;
    }

    return auth_response_local_var;
end:
    if (access_token_local_str) {
        free(access_token_local_str);
        access_token_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (refresh_token_local_str) {
        free(refresh_token_local_str);
        refresh_token_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    if (user_local_nonprim) {
        model_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
