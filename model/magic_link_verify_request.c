#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "magic_link_verify_request.h"



static magic_link_verify_request_t *magic_link_verify_request_create_internal(
    char *token
    ) {
    magic_link_verify_request_t *magic_link_verify_request_local_var = malloc(sizeof(magic_link_verify_request_t));
    if (!magic_link_verify_request_local_var) {
        return NULL;
    }
    memset(magic_link_verify_request_local_var, 0, sizeof(magic_link_verify_request_t));
    magic_link_verify_request_local_var->_library_owned = 1;
    magic_link_verify_request_local_var->token = token;
    return magic_link_verify_request_local_var;
}

__attribute__((deprecated)) magic_link_verify_request_t *magic_link_verify_request_create(
    char *token
    ) {
    magic_link_verify_request_t *result = magic_link_verify_request_create_internal (
        token
        );
    if (!result) {
    }
    return result;
}

void magic_link_verify_request_free(magic_link_verify_request_t *magic_link_verify_request) {
    if(NULL == magic_link_verify_request){
        return ;
    }
    if(magic_link_verify_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "magic_link_verify_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (magic_link_verify_request->token) {
        free(magic_link_verify_request->token);
        magic_link_verify_request->token = NULL;
    }
    free(magic_link_verify_request);
}

cJSON *magic_link_verify_request_convertToJSON(magic_link_verify_request_t *magic_link_verify_request) {
    cJSON *item = cJSON_CreateObject();

    // magic_link_verify_request->token
    if (!magic_link_verify_request->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", magic_link_verify_request->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

magic_link_verify_request_t *magic_link_verify_request_parseFromJSON(cJSON *magic_link_verify_requestJSON){

    magic_link_verify_request_t *magic_link_verify_request_local_var = NULL;

    char *token_local_str = NULL;

    // magic_link_verify_request->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(magic_link_verify_requestJSON, "token");
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


    if (token && !cJSON_IsNull(token)) token_local_str = strdup(token->valuestring);

    magic_link_verify_request_local_var = magic_link_verify_request_create_internal (
        token_local_str
        );

    if (!magic_link_verify_request_local_var) {
        goto end;
    }

    return magic_link_verify_request_local_var;
end:
    if (token_local_str) {
        free(token_local_str);
        token_local_str = NULL;
    }
    return NULL;

}
