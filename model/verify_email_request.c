#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verify_email_request.h"



static verify_email_request_t *verify_email_request_create_internal(
    char *token
    ) {
    verify_email_request_t *verify_email_request_local_var = malloc(sizeof(verify_email_request_t));
    if (!verify_email_request_local_var) {
        return NULL;
    }
    memset(verify_email_request_local_var, 0, sizeof(verify_email_request_t));
    verify_email_request_local_var->_library_owned = 1;
    verify_email_request_local_var->token = token;
    return verify_email_request_local_var;
}

__attribute__((deprecated)) verify_email_request_t *verify_email_request_create(
    char *token
    ) {
    verify_email_request_t *result = verify_email_request_create_internal (
        token
        );
    if (!result) {
    }
    return result;
}

void verify_email_request_free(verify_email_request_t *verify_email_request) {
    if(NULL == verify_email_request){
        return ;
    }
    if(verify_email_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "verify_email_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (verify_email_request->token) {
        free(verify_email_request->token);
        verify_email_request->token = NULL;
    }
    free(verify_email_request);
}

cJSON *verify_email_request_convertToJSON(verify_email_request_t *verify_email_request) {
    cJSON *item = cJSON_CreateObject();

    // verify_email_request->token
    if (!verify_email_request->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", verify_email_request->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

verify_email_request_t *verify_email_request_parseFromJSON(cJSON *verify_email_requestJSON){

    verify_email_request_t *verify_email_request_local_var = NULL;

    char *token_local_str = NULL;

    // verify_email_request->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(verify_email_requestJSON, "token");
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

    verify_email_request_local_var = verify_email_request_create_internal (
        token_local_str
        );

    if (!verify_email_request_local_var) {
        goto end;
    }

    return verify_email_request_local_var;
end:
    if (token_local_str) {
        free(token_local_str);
        token_local_str = NULL;
    }
    return NULL;

}
