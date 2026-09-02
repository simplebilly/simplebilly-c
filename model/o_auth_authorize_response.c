#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "o_auth_authorize_response.h"



static o_auth_authorize_response_t *o_auth_authorize_response_create_internal(
    char *authorization_url,
    char *state
    ) {
    o_auth_authorize_response_t *o_auth_authorize_response_local_var = malloc(sizeof(o_auth_authorize_response_t));
    if (!o_auth_authorize_response_local_var) {
        return NULL;
    }
    memset(o_auth_authorize_response_local_var, 0, sizeof(o_auth_authorize_response_t));
    o_auth_authorize_response_local_var->_library_owned = 1;
    o_auth_authorize_response_local_var->authorization_url = authorization_url;
    o_auth_authorize_response_local_var->state = state;
    return o_auth_authorize_response_local_var;
}

__attribute__((deprecated)) o_auth_authorize_response_t *o_auth_authorize_response_create(
    char *authorization_url,
    char *state
    ) {
    o_auth_authorize_response_t *result = o_auth_authorize_response_create_internal (
        authorization_url,
        state
        );
    if (!result) {
    }
    return result;
}

void o_auth_authorize_response_free(o_auth_authorize_response_t *o_auth_authorize_response) {
    if(NULL == o_auth_authorize_response){
        return ;
    }
    if(o_auth_authorize_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "o_auth_authorize_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (o_auth_authorize_response->authorization_url) {
        free(o_auth_authorize_response->authorization_url);
        o_auth_authorize_response->authorization_url = NULL;
    }
    if (o_auth_authorize_response->state) {
        free(o_auth_authorize_response->state);
        o_auth_authorize_response->state = NULL;
    }
    free(o_auth_authorize_response);
}

cJSON *o_auth_authorize_response_convertToJSON(o_auth_authorize_response_t *o_auth_authorize_response) {
    cJSON *item = cJSON_CreateObject();

    // o_auth_authorize_response->authorization_url
    if (!o_auth_authorize_response->authorization_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "authorization_url", o_auth_authorize_response->authorization_url) == NULL) {
    goto fail; //String
    }


    // o_auth_authorize_response->state
    if (!o_auth_authorize_response->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", o_auth_authorize_response->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

o_auth_authorize_response_t *o_auth_authorize_response_parseFromJSON(cJSON *o_auth_authorize_responseJSON){

    o_auth_authorize_response_t *o_auth_authorize_response_local_var = NULL;

    char *authorization_url_local_str = NULL;

    char *state_local_str = NULL;

    // o_auth_authorize_response->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(o_auth_authorize_responseJSON, "authorization_url");
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

    // o_auth_authorize_response->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(o_auth_authorize_responseJSON, "state");
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

    o_auth_authorize_response_local_var = o_auth_authorize_response_create_internal (
        authorization_url_local_str,
        state_local_str
        );

    if (!o_auth_authorize_response_local_var) {
        goto end;
    }

    return o_auth_authorize_response_local_var;
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
