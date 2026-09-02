#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gateway_o_auth_callback_request.h"



static gateway_o_auth_callback_request_t *gateway_o_auth_callback_request_create_internal(
    char *code,
    char *gateway_type,
    char *redirect_uri,
    char *state
    ) {
    gateway_o_auth_callback_request_t *gateway_o_auth_callback_request_local_var = malloc(sizeof(gateway_o_auth_callback_request_t));
    if (!gateway_o_auth_callback_request_local_var) {
        return NULL;
    }
    memset(gateway_o_auth_callback_request_local_var, 0, sizeof(gateway_o_auth_callback_request_t));
    gateway_o_auth_callback_request_local_var->_library_owned = 1;
    gateway_o_auth_callback_request_local_var->code = code;
    gateway_o_auth_callback_request_local_var->gateway_type = gateway_type;
    gateway_o_auth_callback_request_local_var->redirect_uri = redirect_uri;
    gateway_o_auth_callback_request_local_var->state = state;
    return gateway_o_auth_callback_request_local_var;
}

__attribute__((deprecated)) gateway_o_auth_callback_request_t *gateway_o_auth_callback_request_create(
    char *code,
    char *gateway_type,
    char *redirect_uri,
    char *state
    ) {
    gateway_o_auth_callback_request_t *result = gateway_o_auth_callback_request_create_internal (
        code,
        gateway_type,
        redirect_uri,
        state
        );
    if (!result) {
    }
    return result;
}

void gateway_o_auth_callback_request_free(gateway_o_auth_callback_request_t *gateway_o_auth_callback_request) {
    if(NULL == gateway_o_auth_callback_request){
        return ;
    }
    if(gateway_o_auth_callback_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gateway_o_auth_callback_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gateway_o_auth_callback_request->code) {
        free(gateway_o_auth_callback_request->code);
        gateway_o_auth_callback_request->code = NULL;
    }
    if (gateway_o_auth_callback_request->gateway_type) {
        free(gateway_o_auth_callback_request->gateway_type);
        gateway_o_auth_callback_request->gateway_type = NULL;
    }
    if (gateway_o_auth_callback_request->redirect_uri) {
        free(gateway_o_auth_callback_request->redirect_uri);
        gateway_o_auth_callback_request->redirect_uri = NULL;
    }
    if (gateway_o_auth_callback_request->state) {
        free(gateway_o_auth_callback_request->state);
        gateway_o_auth_callback_request->state = NULL;
    }
    free(gateway_o_auth_callback_request);
}

cJSON *gateway_o_auth_callback_request_convertToJSON(gateway_o_auth_callback_request_t *gateway_o_auth_callback_request) {
    cJSON *item = cJSON_CreateObject();

    // gateway_o_auth_callback_request->code
    if (!gateway_o_auth_callback_request->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", gateway_o_auth_callback_request->code) == NULL) {
    goto fail; //String
    }


    // gateway_o_auth_callback_request->gateway_type
    if (!gateway_o_auth_callback_request->gateway_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gateway_type", gateway_o_auth_callback_request->gateway_type) == NULL) {
    goto fail; //String
    }


    // gateway_o_auth_callback_request->redirect_uri
    if (!gateway_o_auth_callback_request->redirect_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "redirect_uri", gateway_o_auth_callback_request->redirect_uri) == NULL) {
    goto fail; //String
    }


    // gateway_o_auth_callback_request->state
    if (!gateway_o_auth_callback_request->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", gateway_o_auth_callback_request->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gateway_o_auth_callback_request_t *gateway_o_auth_callback_request_parseFromJSON(cJSON *gateway_o_auth_callback_requestJSON){

    gateway_o_auth_callback_request_t *gateway_o_auth_callback_request_local_var = NULL;

    char *code_local_str = NULL;

    char *gateway_type_local_str = NULL;

    char *redirect_uri_local_str = NULL;

    char *state_local_str = NULL;

    // gateway_o_auth_callback_request->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_callback_requestJSON, "code");
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

    // gateway_o_auth_callback_request->gateway_type
    cJSON *gateway_type = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_callback_requestJSON, "gateway_type");
    if (cJSON_IsNull(gateway_type)) {
        gateway_type = NULL;
    }
    if (!gateway_type) {
        goto end;
    }

    
    if(!cJSON_IsString(gateway_type))
    {
    goto end; //String
    }

    // gateway_o_auth_callback_request->redirect_uri
    cJSON *redirect_uri = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_callback_requestJSON, "redirect_uri");
    if (cJSON_IsNull(redirect_uri)) {
        redirect_uri = NULL;
    }
    if (!redirect_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(redirect_uri))
    {
    goto end; //String
    }

    // gateway_o_auth_callback_request->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_callback_requestJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }


    if (code && !cJSON_IsNull(code)) code_local_str = strdup(code->valuestring);
    if (gateway_type && !cJSON_IsNull(gateway_type)) gateway_type_local_str = strdup(gateway_type->valuestring);
    if (redirect_uri && !cJSON_IsNull(redirect_uri)) redirect_uri_local_str = strdup(redirect_uri->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);

    gateway_o_auth_callback_request_local_var = gateway_o_auth_callback_request_create_internal (
        code_local_str,
        gateway_type_local_str,
        redirect_uri_local_str,
        state_local_str
        );

    if (!gateway_o_auth_callback_request_local_var) {
        goto end;
    }

    return gateway_o_auth_callback_request_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (gateway_type_local_str) {
        free(gateway_type_local_str);
        gateway_type_local_str = NULL;
    }
    if (redirect_uri_local_str) {
        free(redirect_uri_local_str);
        redirect_uri_local_str = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    return NULL;

}
