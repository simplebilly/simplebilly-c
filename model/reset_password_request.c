#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reset_password_request.h"



static reset_password_request_t *reset_password_request_create_internal(
    char *new_password,
    char *token
    ) {
    reset_password_request_t *reset_password_request_local_var = malloc(sizeof(reset_password_request_t));
    if (!reset_password_request_local_var) {
        return NULL;
    }
    memset(reset_password_request_local_var, 0, sizeof(reset_password_request_t));
    reset_password_request_local_var->_library_owned = 1;
    reset_password_request_local_var->new_password = new_password;
    reset_password_request_local_var->token = token;
    return reset_password_request_local_var;
}

__attribute__((deprecated)) reset_password_request_t *reset_password_request_create(
    char *new_password,
    char *token
    ) {
    reset_password_request_t *result = reset_password_request_create_internal (
        new_password,
        token
        );
    if (!result) {
    }
    return result;
}

void reset_password_request_free(reset_password_request_t *reset_password_request) {
    if(NULL == reset_password_request){
        return ;
    }
    if(reset_password_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reset_password_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reset_password_request->new_password) {
        free(reset_password_request->new_password);
        reset_password_request->new_password = NULL;
    }
    if (reset_password_request->token) {
        free(reset_password_request->token);
        reset_password_request->token = NULL;
    }
    free(reset_password_request);
}

cJSON *reset_password_request_convertToJSON(reset_password_request_t *reset_password_request) {
    cJSON *item = cJSON_CreateObject();

    // reset_password_request->new_password
    if (!reset_password_request->new_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "new_password", reset_password_request->new_password) == NULL) {
    goto fail; //String
    }


    // reset_password_request->token
    if (!reset_password_request->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", reset_password_request->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reset_password_request_t *reset_password_request_parseFromJSON(cJSON *reset_password_requestJSON){

    reset_password_request_t *reset_password_request_local_var = NULL;

    char *new_password_local_str = NULL;

    char *token_local_str = NULL;

    // reset_password_request->new_password
    cJSON *new_password = cJSON_GetObjectItemCaseSensitive(reset_password_requestJSON, "new_password");
    if (cJSON_IsNull(new_password)) {
        new_password = NULL;
    }
    if (!new_password) {
        goto end;
    }

    
    if(!cJSON_IsString(new_password))
    {
    goto end; //String
    }

    // reset_password_request->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(reset_password_requestJSON, "token");
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


    if (new_password && !cJSON_IsNull(new_password)) new_password_local_str = strdup(new_password->valuestring);
    if (token && !cJSON_IsNull(token)) token_local_str = strdup(token->valuestring);

    reset_password_request_local_var = reset_password_request_create_internal (
        new_password_local_str,
        token_local_str
        );

    if (!reset_password_request_local_var) {
        goto end;
    }

    return reset_password_request_local_var;
end:
    if (new_password_local_str) {
        free(new_password_local_str);
        new_password_local_str = NULL;
    }
    if (token_local_str) {
        free(token_local_str);
        token_local_str = NULL;
    }
    return NULL;

}
