#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_subscription_request.h"



static update_subscription_request_t *update_subscription_request_create_internal(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
    ) {
    update_subscription_request_t *update_subscription_request_local_var = malloc(sizeof(update_subscription_request_t));
    if (!update_subscription_request_local_var) {
        return NULL;
    }
    memset(update_subscription_request_local_var, 0, sizeof(update_subscription_request_t));
    update_subscription_request_local_var->_library_owned = 1;
    update_subscription_request_local_var->event_type = event_type;
    update_subscription_request_local_var->is_active = is_active;
    update_subscription_request_local_var->name = name;
    update_subscription_request_local_var->secret = secret;
    update_subscription_request_local_var->url = url;
    return update_subscription_request_local_var;
}

__attribute__((deprecated)) update_subscription_request_t *update_subscription_request_create(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    update_subscription_request_t *result = update_subscription_request_create_internal (
        event_type,
        is_active_copy,
        name,
        secret,
        url
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void update_subscription_request_free(update_subscription_request_t *update_subscription_request) {
    if(NULL == update_subscription_request){
        return ;
    }
    if(update_subscription_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_subscription_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_subscription_request->event_type) {
        free(update_subscription_request->event_type);
        update_subscription_request->event_type = NULL;
    }
    if (update_subscription_request->is_active) {
        free(update_subscription_request->is_active);
        update_subscription_request->is_active = NULL;
    }
    if (update_subscription_request->name) {
        free(update_subscription_request->name);
        update_subscription_request->name = NULL;
    }
    if (update_subscription_request->secret) {
        free(update_subscription_request->secret);
        update_subscription_request->secret = NULL;
    }
    if (update_subscription_request->url) {
        free(update_subscription_request->url);
        update_subscription_request->url = NULL;
    }
    free(update_subscription_request);
}

cJSON *update_subscription_request_convertToJSON(update_subscription_request_t *update_subscription_request) {
    cJSON *item = cJSON_CreateObject();

    // update_subscription_request->event_type
    if(update_subscription_request->event_type) {
    if(cJSON_AddStringToObject(item, "event_type", update_subscription_request->event_type) == NULL) {
    goto fail; //String
    }
    }


    // update_subscription_request->is_active
    if(update_subscription_request->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *update_subscription_request->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // update_subscription_request->name
    if(update_subscription_request->name) {
    if(cJSON_AddStringToObject(item, "name", update_subscription_request->name) == NULL) {
    goto fail; //String
    }
    }


    // update_subscription_request->secret
    if(update_subscription_request->secret) {
    if(cJSON_AddStringToObject(item, "secret", update_subscription_request->secret) == NULL) {
    goto fail; //String
    }
    }


    // update_subscription_request->url
    if(update_subscription_request->url) {
    if(cJSON_AddStringToObject(item, "url", update_subscription_request->url) == NULL) {
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

update_subscription_request_t *update_subscription_request_parseFromJSON(cJSON *update_subscription_requestJSON){

    update_subscription_request_t *update_subscription_request_local_var = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for update_subscription_request->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    char *secret_local_str = NULL;

    char *url_local_str = NULL;

    // update_subscription_request->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(update_subscription_requestJSON, "event_type");
    if (cJSON_IsNull(event_type)) {
        event_type = NULL;
    }
    if (event_type) { 
    if(!cJSON_IsString(event_type) && !cJSON_IsNull(event_type))
    {
    goto end; //String
    }
    }

    // update_subscription_request->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(update_subscription_requestJSON, "is_active");
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

    // update_subscription_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_subscription_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // update_subscription_request->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(update_subscription_requestJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (secret) { 
    if(!cJSON_IsString(secret) && !cJSON_IsNull(secret))
    {
    goto end; //String
    }
    }

    // update_subscription_request->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(update_subscription_requestJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (secret && !cJSON_IsNull(secret)) secret_local_str = strdup(secret->valuestring);
    if (url && !cJSON_IsNull(url)) url_local_str = strdup(url->valuestring);

    update_subscription_request_local_var = update_subscription_request_create_internal (
        event_type_local_str,
        is_active_local_var,
        name_local_str,
        secret_local_str,
        url_local_str
        );

    if (!update_subscription_request_local_var) {
        goto end;
    }

    return update_subscription_request_local_var;
end:
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (secret_local_str) {
        free(secret_local_str);
        secret_local_str = NULL;
    }
    if (url_local_str) {
        free(url_local_str);
        url_local_str = NULL;
    }
    return NULL;

}
