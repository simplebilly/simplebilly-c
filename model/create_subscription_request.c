#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_subscription_request.h"



static create_subscription_request_t *create_subscription_request_create_internal(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
    ) {
    create_subscription_request_t *create_subscription_request_local_var = malloc(sizeof(create_subscription_request_t));
    if (!create_subscription_request_local_var) {
        return NULL;
    }
    memset(create_subscription_request_local_var, 0, sizeof(create_subscription_request_t));
    create_subscription_request_local_var->_library_owned = 1;
    create_subscription_request_local_var->event_type = event_type;
    create_subscription_request_local_var->is_active = is_active;
    create_subscription_request_local_var->name = name;
    create_subscription_request_local_var->secret = secret;
    create_subscription_request_local_var->url = url;
    return create_subscription_request_local_var;
}

__attribute__((deprecated)) create_subscription_request_t *create_subscription_request_create(
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
    create_subscription_request_t *result = create_subscription_request_create_internal (
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

void create_subscription_request_free(create_subscription_request_t *create_subscription_request) {
    if(NULL == create_subscription_request){
        return ;
    }
    if(create_subscription_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_subscription_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_subscription_request->event_type) {
        free(create_subscription_request->event_type);
        create_subscription_request->event_type = NULL;
    }
    if (create_subscription_request->is_active) {
        free(create_subscription_request->is_active);
        create_subscription_request->is_active = NULL;
    }
    if (create_subscription_request->name) {
        free(create_subscription_request->name);
        create_subscription_request->name = NULL;
    }
    if (create_subscription_request->secret) {
        free(create_subscription_request->secret);
        create_subscription_request->secret = NULL;
    }
    if (create_subscription_request->url) {
        free(create_subscription_request->url);
        create_subscription_request->url = NULL;
    }
    free(create_subscription_request);
}

cJSON *create_subscription_request_convertToJSON(create_subscription_request_t *create_subscription_request) {
    cJSON *item = cJSON_CreateObject();

    // create_subscription_request->event_type
    if (!create_subscription_request->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "event_type", create_subscription_request->event_type) == NULL) {
    goto fail; //String
    }


    // create_subscription_request->is_active
    if(create_subscription_request->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *create_subscription_request->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // create_subscription_request->name
    if (!create_subscription_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_subscription_request->name) == NULL) {
    goto fail; //String
    }


    // create_subscription_request->secret
    if(create_subscription_request->secret) {
    if(cJSON_AddStringToObject(item, "secret", create_subscription_request->secret) == NULL) {
    goto fail; //String
    }
    }


    // create_subscription_request->url
    if (!create_subscription_request->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", create_subscription_request->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_subscription_request_t *create_subscription_request_parseFromJSON(cJSON *create_subscription_requestJSON){

    create_subscription_request_t *create_subscription_request_local_var = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for create_subscription_request->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    char *secret_local_str = NULL;

    char *url_local_str = NULL;

    // create_subscription_request->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(create_subscription_requestJSON, "event_type");
    if (cJSON_IsNull(event_type)) {
        event_type = NULL;
    }
    if (!event_type) {
        goto end;
    }

    
    if(!cJSON_IsString(event_type))
    {
    goto end; //String
    }

    // create_subscription_request->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(create_subscription_requestJSON, "is_active");
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

    // create_subscription_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_subscription_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // create_subscription_request->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(create_subscription_requestJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (secret) { 
    if(!cJSON_IsString(secret) && !cJSON_IsNull(secret))
    {
    goto end; //String
    }
    }

    // create_subscription_request->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(create_subscription_requestJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (secret && !cJSON_IsNull(secret)) secret_local_str = strdup(secret->valuestring);
    if (url && !cJSON_IsNull(url)) url_local_str = strdup(url->valuestring);

    create_subscription_request_local_var = create_subscription_request_create_internal (
        event_type_local_str,
        is_active_local_var,
        name_local_str,
        secret_local_str,
        url_local_str
        );

    if (!create_subscription_request_local_var) {
        goto end;
    }

    return create_subscription_request_local_var;
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
