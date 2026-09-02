#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_enable_request.h"



static totp_enable_request_t *totp_enable_request_create_internal(
    char *code
    ) {
    totp_enable_request_t *totp_enable_request_local_var = malloc(sizeof(totp_enable_request_t));
    if (!totp_enable_request_local_var) {
        return NULL;
    }
    memset(totp_enable_request_local_var, 0, sizeof(totp_enable_request_t));
    totp_enable_request_local_var->_library_owned = 1;
    totp_enable_request_local_var->code = code;
    return totp_enable_request_local_var;
}

__attribute__((deprecated)) totp_enable_request_t *totp_enable_request_create(
    char *code
    ) {
    totp_enable_request_t *result = totp_enable_request_create_internal (
        code
        );
    if (!result) {
    }
    return result;
}

void totp_enable_request_free(totp_enable_request_t *totp_enable_request) {
    if(NULL == totp_enable_request){
        return ;
    }
    if(totp_enable_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_enable_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_enable_request->code) {
        free(totp_enable_request->code);
        totp_enable_request->code = NULL;
    }
    free(totp_enable_request);
}

cJSON *totp_enable_request_convertToJSON(totp_enable_request_t *totp_enable_request) {
    cJSON *item = cJSON_CreateObject();

    // totp_enable_request->code
    if (!totp_enable_request->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", totp_enable_request->code) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_enable_request_t *totp_enable_request_parseFromJSON(cJSON *totp_enable_requestJSON){

    totp_enable_request_t *totp_enable_request_local_var = NULL;

    char *code_local_str = NULL;

    // totp_enable_request->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(totp_enable_requestJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);

    totp_enable_request_local_var = totp_enable_request_create_internal (
        code_local_str
        );

    if (!totp_enable_request_local_var) {
        goto end;
    }

    return totp_enable_request_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    return NULL;

}
