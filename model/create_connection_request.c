#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_connection_request.h"



static create_connection_request_t *create_connection_request_create_internal(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    char *label,
    char *platform,
    char *shop_domain
    ) {
    create_connection_request_t *create_connection_request_local_var = malloc(sizeof(create_connection_request_t));
    if (!create_connection_request_local_var) {
        return NULL;
    }
    memset(create_connection_request_local_var, 0, sizeof(create_connection_request_t));
    create_connection_request_local_var->_library_owned = 1;
    create_connection_request_local_var->api_key = api_key;
    create_connection_request_local_var->api_secret = api_secret;
    create_connection_request_local_var->config = config;
    create_connection_request_local_var->label = label;
    create_connection_request_local_var->platform = platform;
    create_connection_request_local_var->shop_domain = shop_domain;
    return create_connection_request_local_var;
}

__attribute__((deprecated)) create_connection_request_t *create_connection_request_create(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    char *label,
    char *platform,
    char *shop_domain
    ) {
    create_connection_request_t *result = create_connection_request_create_internal (
        api_key,
        api_secret,
        config,
        label,
        platform,
        shop_domain
        );
    if (!result) {
    }
    return result;
}

void create_connection_request_free(create_connection_request_t *create_connection_request) {
    if(NULL == create_connection_request){
        return ;
    }
    if(create_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_connection_request->api_key) {
        free(create_connection_request->api_key);
        create_connection_request->api_key = NULL;
    }
    if (create_connection_request->api_secret) {
        free(create_connection_request->api_secret);
        create_connection_request->api_secret = NULL;
    }
    if (create_connection_request->config) {
        _free(create_connection_request->config);
        create_connection_request->config = NULL;
    }
    if (create_connection_request->label) {
        free(create_connection_request->label);
        create_connection_request->label = NULL;
    }
    if (create_connection_request->platform) {
        free(create_connection_request->platform);
        create_connection_request->platform = NULL;
    }
    if (create_connection_request->shop_domain) {
        free(create_connection_request->shop_domain);
        create_connection_request->shop_domain = NULL;
    }
    free(create_connection_request);
}

cJSON *create_connection_request_convertToJSON(create_connection_request_t *create_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // create_connection_request->api_key
    if(create_connection_request->api_key) {
    if(cJSON_AddStringToObject(item, "api_key", create_connection_request->api_key) == NULL) {
    goto fail; //String
    }
    }


    // create_connection_request->api_secret
    if(create_connection_request->api_secret) {
    if(cJSON_AddStringToObject(item, "api_secret", create_connection_request->api_secret) == NULL) {
    goto fail; //String
    }
    }


    // create_connection_request->config
    if(create_connection_request->config) {
    cJSON *config_local_JSON = _convertToJSON(create_connection_request->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // create_connection_request->label
    if (!create_connection_request->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", create_connection_request->label) == NULL) {
    goto fail; //String
    }


    // create_connection_request->platform
    if (!create_connection_request->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", create_connection_request->platform) == NULL) {
    goto fail; //String
    }


    // create_connection_request->shop_domain
    if(create_connection_request->shop_domain) {
    if(cJSON_AddStringToObject(item, "shop_domain", create_connection_request->shop_domain) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_connection_request_t *create_connection_request_parseFromJSON(cJSON *create_connection_requestJSON){

    create_connection_request_t *create_connection_request_local_var = NULL;

    char *api_key_local_str = NULL;

    char *api_secret_local_str = NULL;

    // define the local variable for create_connection_request->config
    _t *config_local_nonprim = NULL;

    char *label_local_str = NULL;

    char *platform_local_str = NULL;

    char *shop_domain_local_str = NULL;

    // create_connection_request->api_key
    cJSON *api_key = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "api_key");
    if (cJSON_IsNull(api_key)) {
        api_key = NULL;
    }
    if (api_key) { 
    if(!cJSON_IsString(api_key) && !cJSON_IsNull(api_key))
    {
    goto end; //String
    }
    }

    // create_connection_request->api_secret
    cJSON *api_secret = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "api_secret");
    if (cJSON_IsNull(api_secret)) {
        api_secret = NULL;
    }
    if (api_secret) { 
    if(!cJSON_IsString(api_secret) && !cJSON_IsNull(api_secret))
    {
    goto end; //String
    }
    }

    // create_connection_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // create_connection_request->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // create_connection_request->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "platform");
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

    // create_connection_request->shop_domain
    cJSON *shop_domain = cJSON_GetObjectItemCaseSensitive(create_connection_requestJSON, "shop_domain");
    if (cJSON_IsNull(shop_domain)) {
        shop_domain = NULL;
    }
    if (shop_domain) { 
    if(!cJSON_IsString(shop_domain) && !cJSON_IsNull(shop_domain))
    {
    goto end; //String
    }
    }


    if (api_key && !cJSON_IsNull(api_key)) api_key_local_str = strdup(api_key->valuestring);
    if (api_secret && !cJSON_IsNull(api_secret)) api_secret_local_str = strdup(api_secret->valuestring);
    if (label && !cJSON_IsNull(label)) label_local_str = strdup(label->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (shop_domain && !cJSON_IsNull(shop_domain)) shop_domain_local_str = strdup(shop_domain->valuestring);

    create_connection_request_local_var = create_connection_request_create_internal (
        api_key_local_str,
        api_secret_local_str,
        config ? config_local_nonprim : NULL,
        label_local_str,
        platform_local_str,
        shop_domain_local_str
        );

    if (!create_connection_request_local_var) {
        goto end;
    }

    return create_connection_request_local_var;
end:
    if (api_key_local_str) {
        free(api_key_local_str);
        api_key_local_str = NULL;
    }
    if (api_secret_local_str) {
        free(api_secret_local_str);
        api_secret_local_str = NULL;
    }
    if (config_local_nonprim) {
        _free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (shop_domain_local_str) {
        free(shop_domain_local_str);
        shop_domain_local_str = NULL;
    }
    return NULL;

}
