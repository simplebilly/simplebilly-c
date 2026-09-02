#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "o_auth_callback_request.h"



static o_auth_callback_request_t *o_auth_callback_request_create_internal(
    char *code,
    any_type_t *config,
    char *connection_id,
    char *platform,
    char *shop_domain,
    char *state
    ) {
    o_auth_callback_request_t *o_auth_callback_request_local_var = malloc(sizeof(o_auth_callback_request_t));
    if (!o_auth_callback_request_local_var) {
        return NULL;
    }
    memset(o_auth_callback_request_local_var, 0, sizeof(o_auth_callback_request_t));
    o_auth_callback_request_local_var->_library_owned = 1;
    o_auth_callback_request_local_var->code = code;
    o_auth_callback_request_local_var->config = config;
    o_auth_callback_request_local_var->connection_id = connection_id;
    o_auth_callback_request_local_var->platform = platform;
    o_auth_callback_request_local_var->shop_domain = shop_domain;
    o_auth_callback_request_local_var->state = state;
    return o_auth_callback_request_local_var;
}

__attribute__((deprecated)) o_auth_callback_request_t *o_auth_callback_request_create(
    char *code,
    any_type_t *config,
    char *connection_id,
    char *platform,
    char *shop_domain,
    char *state
    ) {
    o_auth_callback_request_t *result = o_auth_callback_request_create_internal (
        code,
        config,
        connection_id,
        platform,
        shop_domain,
        state
        );
    if (!result) {
    }
    return result;
}

void o_auth_callback_request_free(o_auth_callback_request_t *o_auth_callback_request) {
    if(NULL == o_auth_callback_request){
        return ;
    }
    if(o_auth_callback_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "o_auth_callback_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (o_auth_callback_request->code) {
        free(o_auth_callback_request->code);
        o_auth_callback_request->code = NULL;
    }
    if (o_auth_callback_request->config) {
        _free(o_auth_callback_request->config);
        o_auth_callback_request->config = NULL;
    }
    if (o_auth_callback_request->connection_id) {
        free(o_auth_callback_request->connection_id);
        o_auth_callback_request->connection_id = NULL;
    }
    if (o_auth_callback_request->platform) {
        free(o_auth_callback_request->platform);
        o_auth_callback_request->platform = NULL;
    }
    if (o_auth_callback_request->shop_domain) {
        free(o_auth_callback_request->shop_domain);
        o_auth_callback_request->shop_domain = NULL;
    }
    if (o_auth_callback_request->state) {
        free(o_auth_callback_request->state);
        o_auth_callback_request->state = NULL;
    }
    free(o_auth_callback_request);
}

cJSON *o_auth_callback_request_convertToJSON(o_auth_callback_request_t *o_auth_callback_request) {
    cJSON *item = cJSON_CreateObject();

    // o_auth_callback_request->code
    if (!o_auth_callback_request->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", o_auth_callback_request->code) == NULL) {
    goto fail; //String
    }


    // o_auth_callback_request->config
    if(o_auth_callback_request->config) {
    cJSON *config_local_JSON = _convertToJSON(o_auth_callback_request->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // o_auth_callback_request->connection_id
    if(o_auth_callback_request->connection_id) {
    if(cJSON_AddStringToObject(item, "connection_id", o_auth_callback_request->connection_id) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_callback_request->platform
    if (!o_auth_callback_request->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", o_auth_callback_request->platform) == NULL) {
    goto fail; //String
    }


    // o_auth_callback_request->shop_domain
    if(o_auth_callback_request->shop_domain) {
    if(cJSON_AddStringToObject(item, "shop_domain", o_auth_callback_request->shop_domain) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_callback_request->state
    if (!o_auth_callback_request->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", o_auth_callback_request->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

o_auth_callback_request_t *o_auth_callback_request_parseFromJSON(cJSON *o_auth_callback_requestJSON){

    o_auth_callback_request_t *o_auth_callback_request_local_var = NULL;

    char *code_local_str = NULL;

    // define the local variable for o_auth_callback_request->config
    _t *config_local_nonprim = NULL;

    char *connection_id_local_str = NULL;

    char *platform_local_str = NULL;

    char *shop_domain_local_str = NULL;

    char *state_local_str = NULL;

    // o_auth_callback_request->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "code");
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

    // o_auth_callback_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // o_auth_callback_request->connection_id
    cJSON *connection_id = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "connection_id");
    if (cJSON_IsNull(connection_id)) {
        connection_id = NULL;
    }
    if (connection_id) { 
    if(!cJSON_IsString(connection_id) && !cJSON_IsNull(connection_id))
    {
    goto end; //String
    }
    }

    // o_auth_callback_request->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "platform");
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

    // o_auth_callback_request->shop_domain
    cJSON *shop_domain = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "shop_domain");
    if (cJSON_IsNull(shop_domain)) {
        shop_domain = NULL;
    }
    if (shop_domain) { 
    if(!cJSON_IsString(shop_domain) && !cJSON_IsNull(shop_domain))
    {
    goto end; //String
    }
    }

    // o_auth_callback_request->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(o_auth_callback_requestJSON, "state");
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
    if (connection_id && !cJSON_IsNull(connection_id)) connection_id_local_str = strdup(connection_id->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (shop_domain && !cJSON_IsNull(shop_domain)) shop_domain_local_str = strdup(shop_domain->valuestring);
    if (state && !cJSON_IsNull(state)) state_local_str = strdup(state->valuestring);

    o_auth_callback_request_local_var = o_auth_callback_request_create_internal (
        code_local_str,
        config ? config_local_nonprim : NULL,
        connection_id_local_str,
        platform_local_str,
        shop_domain_local_str,
        state_local_str
        );

    if (!o_auth_callback_request_local_var) {
        goto end;
    }

    return o_auth_callback_request_local_var;
end:
    if (code_local_str) {
        free(code_local_str);
        code_local_str = NULL;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (connection_id_local_str) {
        free(connection_id_local_str);
        connection_id_local_str = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (shop_domain_local_str) {
        free(shop_domain_local_str);
        shop_domain_local_str = NULL;
    }
    if (state_local_str) {
        free(state_local_str);
        state_local_str = NULL;
    }
    return NULL;

}
