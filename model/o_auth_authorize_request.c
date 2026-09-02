#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "o_auth_authorize_request.h"



static o_auth_authorize_request_t *o_auth_authorize_request_create_internal(
    any_type_t *config,
    char *platform,
    char *redirect_uri
    ) {
    o_auth_authorize_request_t *o_auth_authorize_request_local_var = malloc(sizeof(o_auth_authorize_request_t));
    if (!o_auth_authorize_request_local_var) {
        return NULL;
    }
    memset(o_auth_authorize_request_local_var, 0, sizeof(o_auth_authorize_request_t));
    o_auth_authorize_request_local_var->_library_owned = 1;
    o_auth_authorize_request_local_var->config = config;
    o_auth_authorize_request_local_var->platform = platform;
    o_auth_authorize_request_local_var->redirect_uri = redirect_uri;
    return o_auth_authorize_request_local_var;
}

__attribute__((deprecated)) o_auth_authorize_request_t *o_auth_authorize_request_create(
    any_type_t *config,
    char *platform,
    char *redirect_uri
    ) {
    o_auth_authorize_request_t *result = o_auth_authorize_request_create_internal (
        config,
        platform,
        redirect_uri
        );
    if (!result) {
    }
    return result;
}

void o_auth_authorize_request_free(o_auth_authorize_request_t *o_auth_authorize_request) {
    if(NULL == o_auth_authorize_request){
        return ;
    }
    if(o_auth_authorize_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "o_auth_authorize_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (o_auth_authorize_request->config) {
        _free(o_auth_authorize_request->config);
        o_auth_authorize_request->config = NULL;
    }
    if (o_auth_authorize_request->platform) {
        free(o_auth_authorize_request->platform);
        o_auth_authorize_request->platform = NULL;
    }
    if (o_auth_authorize_request->redirect_uri) {
        free(o_auth_authorize_request->redirect_uri);
        o_auth_authorize_request->redirect_uri = NULL;
    }
    free(o_auth_authorize_request);
}

cJSON *o_auth_authorize_request_convertToJSON(o_auth_authorize_request_t *o_auth_authorize_request) {
    cJSON *item = cJSON_CreateObject();

    // o_auth_authorize_request->config
    if(o_auth_authorize_request->config) {
    cJSON *config_local_JSON = _convertToJSON(o_auth_authorize_request->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // o_auth_authorize_request->platform
    if (!o_auth_authorize_request->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", o_auth_authorize_request->platform) == NULL) {
    goto fail; //String
    }


    // o_auth_authorize_request->redirect_uri
    if (!o_auth_authorize_request->redirect_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "redirect_uri", o_auth_authorize_request->redirect_uri) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

o_auth_authorize_request_t *o_auth_authorize_request_parseFromJSON(cJSON *o_auth_authorize_requestJSON){

    o_auth_authorize_request_t *o_auth_authorize_request_local_var = NULL;

    // define the local variable for o_auth_authorize_request->config
    _t *config_local_nonprim = NULL;

    char *platform_local_str = NULL;

    char *redirect_uri_local_str = NULL;

    // o_auth_authorize_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(o_auth_authorize_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // o_auth_authorize_request->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(o_auth_authorize_requestJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }

    // o_auth_authorize_request->redirect_uri
    cJSON *redirect_uri = cJSON_GetObjectItemCaseSensitive(o_auth_authorize_requestJSON, "redirect_uri");
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


    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (redirect_uri && !cJSON_IsNull(redirect_uri)) redirect_uri_local_str = strdup(redirect_uri->valuestring);

    o_auth_authorize_request_local_var = o_auth_authorize_request_create_internal (
        config ? config_local_nonprim : NULL,
        platform_local_str,
        redirect_uri_local_str
        );

    if (!o_auth_authorize_request_local_var) {
        goto end;
    }

    return o_auth_authorize_request_local_var;
end:
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (redirect_uri_local_str) {
        free(redirect_uri_local_str);
        redirect_uri_local_str = NULL;
    }
    return NULL;

}
