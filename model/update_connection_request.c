#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_connection_request.h"



static update_connection_request_t *update_connection_request_create_internal(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    int *is_active,
    char *label,
    char *shop_domain
    ) {
    update_connection_request_t *update_connection_request_local_var = malloc(sizeof(update_connection_request_t));
    if (!update_connection_request_local_var) {
        return NULL;
    }
    memset(update_connection_request_local_var, 0, sizeof(update_connection_request_t));
    update_connection_request_local_var->_library_owned = 1;
    update_connection_request_local_var->api_key = api_key;
    update_connection_request_local_var->api_secret = api_secret;
    update_connection_request_local_var->config = config;
    update_connection_request_local_var->is_active = is_active;
    update_connection_request_local_var->label = label;
    update_connection_request_local_var->shop_domain = shop_domain;
    return update_connection_request_local_var;
}

__attribute__((deprecated)) update_connection_request_t *update_connection_request_create(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    int *is_active,
    char *label,
    char *shop_domain
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    update_connection_request_t *result = update_connection_request_create_internal (
        api_key,
        api_secret,
        config,
        is_active_copy,
        label,
        shop_domain
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void update_connection_request_free(update_connection_request_t *update_connection_request) {
    if(NULL == update_connection_request){
        return ;
    }
    if(update_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_connection_request->api_key) {
        free(update_connection_request->api_key);
        update_connection_request->api_key = NULL;
    }
    if (update_connection_request->api_secret) {
        free(update_connection_request->api_secret);
        update_connection_request->api_secret = NULL;
    }
    if (update_connection_request->config) {
        _free(update_connection_request->config);
        update_connection_request->config = NULL;
    }
    if (update_connection_request->is_active) {
        free(update_connection_request->is_active);
        update_connection_request->is_active = NULL;
    }
    if (update_connection_request->label) {
        free(update_connection_request->label);
        update_connection_request->label = NULL;
    }
    if (update_connection_request->shop_domain) {
        free(update_connection_request->shop_domain);
        update_connection_request->shop_domain = NULL;
    }
    free(update_connection_request);
}

cJSON *update_connection_request_convertToJSON(update_connection_request_t *update_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // update_connection_request->api_key
    if(update_connection_request->api_key) {
    if(cJSON_AddStringToObject(item, "api_key", update_connection_request->api_key) == NULL) {
    goto fail; //String
    }
    }


    // update_connection_request->api_secret
    if(update_connection_request->api_secret) {
    if(cJSON_AddStringToObject(item, "api_secret", update_connection_request->api_secret) == NULL) {
    goto fail; //String
    }
    }


    // update_connection_request->config
    if(update_connection_request->config) {
    cJSON *config_local_JSON = _convertToJSON(update_connection_request->config);
    if(config_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // update_connection_request->is_active
    if(update_connection_request->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *update_connection_request->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // update_connection_request->label
    if(update_connection_request->label) {
    if(cJSON_AddStringToObject(item, "label", update_connection_request->label) == NULL) {
    goto fail; //String
    }
    }


    // update_connection_request->shop_domain
    if(update_connection_request->shop_domain) {
    if(cJSON_AddStringToObject(item, "shop_domain", update_connection_request->shop_domain) == NULL) {
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

update_connection_request_t *update_connection_request_parseFromJSON(cJSON *update_connection_requestJSON){

    update_connection_request_t *update_connection_request_local_var = NULL;

    char *api_key_local_str = NULL;

    char *api_secret_local_str = NULL;

    // define the local variable for update_connection_request->config
    _t *config_local_nonprim = NULL;

    // define the local variable for update_connection_request->is_active
    int *is_active_local_var = NULL;

    char *label_local_str = NULL;

    char *shop_domain_local_str = NULL;

    // update_connection_request->api_key
    cJSON *api_key = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "api_key");
    if (cJSON_IsNull(api_key)) {
        api_key = NULL;
    }
    if (api_key) { 
    if(!cJSON_IsString(api_key) && !cJSON_IsNull(api_key))
    {
    goto end; //String
    }
    }

    // update_connection_request->api_secret
    cJSON *api_secret = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "api_secret");
    if (cJSON_IsNull(api_secret)) {
        api_secret = NULL;
    }
    if (api_secret) { 
    if(!cJSON_IsString(api_secret) && !cJSON_IsNull(api_secret))
    {
    goto end; //String
    }
    }

    // update_connection_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = _parseFromJSON(config); //custom
    }

    // update_connection_request->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // update_connection_request->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // update_connection_request->shop_domain
    cJSON *shop_domain = cJSON_GetObjectItemCaseSensitive(update_connection_requestJSON, "shop_domain");
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
    if (shop_domain && !cJSON_IsNull(shop_domain)) shop_domain_local_str = strdup(shop_domain->valuestring);

    update_connection_request_local_var = update_connection_request_create_internal (
        api_key_local_str,
        api_secret_local_str,
        config ? config_local_nonprim : NULL,
        is_active_local_var,
        label_local_str,
        shop_domain_local_str
        );

    if (!update_connection_request_local_var) {
        goto end;
    }

    return update_connection_request_local_var;
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
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (label_local_str) {
        free(label_local_str);
        label_local_str = NULL;
    }
    if (shop_domain_local_str) {
        free(shop_domain_local_str);
        shop_domain_local_str = NULL;
    }
    return NULL;

}
