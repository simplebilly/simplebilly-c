#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gateway_o_auth_authorize_response.h"



static gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_create_internal(
    char *authorization_url,
    char *state
    ) {
    gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_local_var = malloc(sizeof(gateway_o_auth_authorize_response_t));
    if (!gateway_o_auth_authorize_response_local_var) {
        return NULL;
    }
    memset(gateway_o_auth_authorize_response_local_var, 0, sizeof(gateway_o_auth_authorize_response_t));
    gateway_o_auth_authorize_response_local_var->_library_owned = 1;
    gateway_o_auth_authorize_response_local_var->authorization_url = authorization_url;
    gateway_o_auth_authorize_response_local_var->state = state;
    return gateway_o_auth_authorize_response_local_var;
}

__attribute__((deprecated)) gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_create(
    char *authorization_url,
    char *state
    ) {
    gateway_o_auth_authorize_response_t *result = gateway_o_auth_authorize_response_create_internal (
        authorization_url,
        state
        );
    if (!result) {
    }
    return result;
}

void gateway_o_auth_authorize_response_free(gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response) {
    if(NULL == gateway_o_auth_authorize_response){
        return ;
    }
    if(gateway_o_auth_authorize_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gateway_o_auth_authorize_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gateway_o_auth_authorize_response->authorization_url) {
        free(gateway_o_auth_authorize_response->authorization_url);
        gateway_o_auth_authorize_response->authorization_url = NULL;
    }
    if (gateway_o_auth_authorize_response->state) {
        free(gateway_o_auth_authorize_response->state);
        gateway_o_auth_authorize_response->state = NULL;
    }
    free(gateway_o_auth_authorize_response);
}

cJSON *gateway_o_auth_authorize_response_convertToJSON(gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response) {
    cJSON *item = cJSON_CreateObject();

    // gateway_o_auth_authorize_response->authorization_url
    if (!gateway_o_auth_authorize_response->authorization_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "authorization_url", gateway_o_auth_authorize_response->authorization_url) == NULL) {
    goto fail; //String
    }


    // gateway_o_auth_authorize_response->state
    if (!gateway_o_auth_authorize_response->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", gateway_o_auth_authorize_response->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_parseFromJSON(cJSON *gateway_o_auth_authorize_responseJSON){

    gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_local_var = NULL;

    char *authorization_url_local_str = NULL;

    char *state_local_str = NULL;

    // gateway_o_auth_authorize_response->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_authorize_responseJSON, "authorization_url");
    if (cJSON_IsNull(authorization_url)) {
        authorization_url = NULL;
    }
    if (!authorization_url) {
        goto end;
    }

    
    if(!cJSON_IsString(authorization_url))
    {
    goto end; //String
    }

    // gateway_o_auth_authorize_response->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_authorize_responseJSON, "state");
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


    if (authorization_url && !cJSON_IsNull(authorization_url)) authorization_url_local_str = strdup(authorization_url->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);

    gateway_o_auth_authorize_response_local_var = gateway_o_auth_authorize_response_create_internal (
        authorization_url_local_str,
        state_local_str
        );

    if (!gateway_o_auth_authorize_response_local_var) {
        goto end;
    }

    return gateway_o_auth_authorize_response_local_var;
end:
    if (authorization_url_local_str) {
        free(authorization_url_local_str);
        authorization_url_local_str = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    return NULL;

}
