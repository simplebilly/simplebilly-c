#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gateway_o_auth_authorize_request.h"



static gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_create_internal(
    char *gateway_type,
    char *redirect_uri
    ) {
    gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_local_var = malloc(sizeof(gateway_o_auth_authorize_request_t));
    if (!gateway_o_auth_authorize_request_local_var) {
        return NULL;
    }
    memset(gateway_o_auth_authorize_request_local_var, 0, sizeof(gateway_o_auth_authorize_request_t));
    gateway_o_auth_authorize_request_local_var->_library_owned = 1;
    gateway_o_auth_authorize_request_local_var->gateway_type = gateway_type;
    gateway_o_auth_authorize_request_local_var->redirect_uri = redirect_uri;
    return gateway_o_auth_authorize_request_local_var;
}

__attribute__((deprecated)) gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_create(
    char *gateway_type,
    char *redirect_uri
    ) {
    gateway_o_auth_authorize_request_t *result = gateway_o_auth_authorize_request_create_internal (
        gateway_type,
        redirect_uri
        );
    if (!result) {
    }
    return result;
}

void gateway_o_auth_authorize_request_free(gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request) {
    if(NULL == gateway_o_auth_authorize_request){
        return ;
    }
    if(gateway_o_auth_authorize_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gateway_o_auth_authorize_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gateway_o_auth_authorize_request->gateway_type) {
        free(gateway_o_auth_authorize_request->gateway_type);
        gateway_o_auth_authorize_request->gateway_type = NULL;
    }
    if (gateway_o_auth_authorize_request->redirect_uri) {
        free(gateway_o_auth_authorize_request->redirect_uri);
        gateway_o_auth_authorize_request->redirect_uri = NULL;
    }
    free(gateway_o_auth_authorize_request);
}

cJSON *gateway_o_auth_authorize_request_convertToJSON(gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request) {
    cJSON *item = cJSON_CreateObject();

    // gateway_o_auth_authorize_request->gateway_type
    if (!gateway_o_auth_authorize_request->gateway_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gateway_type", gateway_o_auth_authorize_request->gateway_type) == NULL) {
    goto fail; //String
    }


    // gateway_o_auth_authorize_request->redirect_uri
    if (!gateway_o_auth_authorize_request->redirect_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "redirect_uri", gateway_o_auth_authorize_request->redirect_uri) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_parseFromJSON(cJSON *gateway_o_auth_authorize_requestJSON){

    gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_local_var = NULL;

    char *gateway_type_local_str = NULL;

    char *redirect_uri_local_str = NULL;

    // gateway_o_auth_authorize_request->gateway_type
    cJSON *gateway_type = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_authorize_requestJSON, "gateway_type");
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

    // gateway_o_auth_authorize_request->redirect_uri
    cJSON *redirect_uri = cJSON_GetObjectItemCaseSensitive(gateway_o_auth_authorize_requestJSON, "redirect_uri");
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


    if (gateway_type && !cJSON_IsNull(gateway_type)) gateway_type_local_str = strdup(gateway_type->valuestring);
    if (redirect_uri && !cJSON_IsNull(redirect_uri)) redirect_uri_local_str = strdup(redirect_uri->valuestring);

    gateway_o_auth_authorize_request_local_var = gateway_o_auth_authorize_request_create_internal (
        gateway_type_local_str,
        redirect_uri_local_str
        );

    if (!gateway_o_auth_authorize_request_local_var) {
        goto end;
    }

    return gateway_o_auth_authorize_request_local_var;
end:
    if (gateway_type_local_str) {
        free(gateway_type_local_str);
        gateway_type_local_str = NULL;
    }
    if (redirect_uri_local_str) {
        free(redirect_uri_local_str);
        redirect_uri_local_str = NULL;
    }
    return NULL;

}
