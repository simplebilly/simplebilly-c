#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accept_invite_request.h"



static accept_invite_request_t *accept_invite_request_create_internal(
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted,
    char *token
    ) {
    accept_invite_request_t *accept_invite_request_local_var = malloc(sizeof(accept_invite_request_t));
    if (!accept_invite_request_local_var) {
        return NULL;
    }
    memset(accept_invite_request_local_var, 0, sizeof(accept_invite_request_t));
    accept_invite_request_local_var->_library_owned = 1;
    accept_invite_request_local_var->first_name = first_name;
    accept_invite_request_local_var->last_name = last_name;
    accept_invite_request_local_var->password = password;
    accept_invite_request_local_var->privacy_accepted = privacy_accepted;
    accept_invite_request_local_var->token = token;
    return accept_invite_request_local_var;
}

__attribute__((deprecated)) accept_invite_request_t *accept_invite_request_create(
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted,
    char *token
    ) {
    int *privacy_accepted_copy = NULL;
    if (privacy_accepted) {
        privacy_accepted_copy = malloc(sizeof(int));
        if (privacy_accepted_copy) *privacy_accepted_copy = *privacy_accepted;
    }
    accept_invite_request_t *result = accept_invite_request_create_internal (
        first_name,
        last_name,
        password,
        privacy_accepted_copy,
        token
        );
    if (!result) {
        free(privacy_accepted_copy);
    }
    return result;
}

void accept_invite_request_free(accept_invite_request_t *accept_invite_request) {
    if(NULL == accept_invite_request){
        return ;
    }
    if(accept_invite_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "accept_invite_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (accept_invite_request->first_name) {
        free(accept_invite_request->first_name);
        accept_invite_request->first_name = NULL;
    }
    if (accept_invite_request->last_name) {
        free(accept_invite_request->last_name);
        accept_invite_request->last_name = NULL;
    }
    if (accept_invite_request->password) {
        free(accept_invite_request->password);
        accept_invite_request->password = NULL;
    }
    if (accept_invite_request->privacy_accepted) {
        free(accept_invite_request->privacy_accepted);
        accept_invite_request->privacy_accepted = NULL;
    }
    if (accept_invite_request->token) {
        free(accept_invite_request->token);
        accept_invite_request->token = NULL;
    }
    free(accept_invite_request);
}

cJSON *accept_invite_request_convertToJSON(accept_invite_request_t *accept_invite_request) {
    cJSON *item = cJSON_CreateObject();

    // accept_invite_request->first_name
    if (!accept_invite_request->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", accept_invite_request->first_name) == NULL) {
    goto fail; //String
    }


    // accept_invite_request->last_name
    if (!accept_invite_request->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "last_name", accept_invite_request->last_name) == NULL) {
    goto fail; //String
    }


    // accept_invite_request->password
    if (!accept_invite_request->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", accept_invite_request->password) == NULL) {
    goto fail; //String
    }


    // accept_invite_request->privacy_accepted
    if (!accept_invite_request->privacy_accepted) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "privacy_accepted", *accept_invite_request->privacy_accepted) == NULL) {
    goto fail; //Bool
    }


    // accept_invite_request->token
    if (!accept_invite_request->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", accept_invite_request->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

accept_invite_request_t *accept_invite_request_parseFromJSON(cJSON *accept_invite_requestJSON){

    accept_invite_request_t *accept_invite_request_local_var = NULL;

    char *first_name_local_str = NULL;

    char *last_name_local_str = NULL;

    char *password_local_str = NULL;

    // define the local variable for accept_invite_request->privacy_accepted
    int *privacy_accepted_local_var = NULL;

    char *token_local_str = NULL;

    // accept_invite_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(accept_invite_requestJSON, "first_name");
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

    // accept_invite_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(accept_invite_requestJSON, "last_name");
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

    // accept_invite_request->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(accept_invite_requestJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (!password) {
        goto end;
    }

    
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }

    // accept_invite_request->privacy_accepted
    cJSON *privacy_accepted = cJSON_GetObjectItemCaseSensitive(accept_invite_requestJSON, "privacy_accepted");
    if (cJSON_IsNull(privacy_accepted)) {
        privacy_accepted = NULL;
    }
    if (!privacy_accepted) {
        goto end;
    }

    
    if(!cJSON_IsBool(privacy_accepted))
    {
    goto end; //Bool
    }
    privacy_accepted_local_var = malloc(sizeof(int));
    if(!privacy_accepted_local_var)
    {
        goto end;
    }
    *privacy_accepted_local_var = privacy_accepted->valueint;

    // accept_invite_request->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(accept_invite_requestJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    if (first_name && !cJSON_IsNull(first_name)) first_name_local_str = strdup(first_name->valuestring);
    if (last_name && !cJSON_IsNull(last_name)) last_name_local_str = strdup(last_name->valuestring);
    if (password && !cJSON_IsNull(password)) password_local_str = strdup(password->valuestring);
    if (token && !cJSON_IsNull(token)) token_local_str = strdup(token->valuestring);

    accept_invite_request_local_var = accept_invite_request_create_internal (
        first_name_local_str,
        last_name_local_str,
        password_local_str,
        privacy_accepted_local_var,
        token_local_str
        );

    if (!accept_invite_request_local_var) {
        goto end;
    }

    return accept_invite_request_local_var;
end:
    if (first_name_local_str) {
        free(first_name_local_str);
        first_name_local_str = NULL;
    }
    if (last_name_local_str) {
        free(last_name_local_str);
        last_name_local_str = NULL;
    }
    if (password_local_str) {
        free(password_local_str);
        password_local_str = NULL;
    }
    if (privacy_accepted_local_var) {
        free(privacy_accepted_local_var);
        privacy_accepted_local_var = NULL;
    }
    if (token_local_str) {
        free(token_local_str);
        token_local_str = NULL;
    }
    return NULL;

}
