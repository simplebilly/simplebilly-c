#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "webhook_subscription.h"



static webhook_subscription_t *webhook_subscription_create_internal(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
    ) {
    webhook_subscription_t *webhook_subscription_local_var = malloc(sizeof(webhook_subscription_t));
    if (!webhook_subscription_local_var) {
        return NULL;
    }
    memset(webhook_subscription_local_var, 0, sizeof(webhook_subscription_t));
    webhook_subscription_local_var->_library_owned = 1;
    webhook_subscription_local_var->event_type = event_type;
    webhook_subscription_local_var->is_active = is_active;
    webhook_subscription_local_var->name = name;
    webhook_subscription_local_var->secret = secret;
    webhook_subscription_local_var->url = url;
    return webhook_subscription_local_var;
}

__attribute__((deprecated)) webhook_subscription_t *webhook_subscription_create(
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
    webhook_subscription_t *result = webhook_subscription_create_internal (
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

void webhook_subscription_free(webhook_subscription_t *webhook_subscription) {
    if(NULL == webhook_subscription){
        return ;
    }
    if(webhook_subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "webhook_subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (webhook_subscription->event_type) {
        free(webhook_subscription->event_type);
        webhook_subscription->event_type = NULL;
    }
    if (webhook_subscription->is_active) {
        free(webhook_subscription->is_active);
        webhook_subscription->is_active = NULL;
    }
    if (webhook_subscription->name) {
        free(webhook_subscription->name);
        webhook_subscription->name = NULL;
    }
    if (webhook_subscription->secret) {
        free(webhook_subscription->secret);
        webhook_subscription->secret = NULL;
    }
    if (webhook_subscription->url) {
        free(webhook_subscription->url);
        webhook_subscription->url = NULL;
    }
    free(webhook_subscription);
}

cJSON *webhook_subscription_convertToJSON(webhook_subscription_t *webhook_subscription) {
    cJSON *item = cJSON_CreateObject();

    // webhook_subscription->event_type
    if (!webhook_subscription->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eventType", webhook_subscription->event_type) == NULL) {
    goto fail; //String
    }


    // webhook_subscription->is_active
    if(webhook_subscription->is_active) {
    if(cJSON_AddBoolToObject(item, "isActive", *webhook_subscription->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // webhook_subscription->name
    if (!webhook_subscription->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", webhook_subscription->name) == NULL) {
    goto fail; //String
    }


    // webhook_subscription->secret
    if (!webhook_subscription->secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secret", webhook_subscription->secret) == NULL) {
    goto fail; //String
    }


    // webhook_subscription->url
    if (!webhook_subscription->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", webhook_subscription->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

webhook_subscription_t *webhook_subscription_parseFromJSON(cJSON *webhook_subscriptionJSON){

    webhook_subscription_t *webhook_subscription_local_var = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for webhook_subscription->is_active
    int *is_active_local_var = NULL;

    char *name_local_str = NULL;

    char *secret_local_str = NULL;

    char *url_local_str = NULL;

    // webhook_subscription->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(webhook_subscriptionJSON, "eventType");
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

    // webhook_subscription->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(webhook_subscriptionJSON, "isActive");
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

    // webhook_subscription->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(webhook_subscriptionJSON, "name");
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

    // webhook_subscription->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(webhook_subscriptionJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (!secret) {
        goto end;
    }

    
    if(!cJSON_IsString(secret))
    {
    goto end; //String
    }

    // webhook_subscription->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(webhook_subscriptionJSON, "url");
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

    webhook_subscription_local_var = webhook_subscription_create_internal (
        event_type_local_str,
        is_active_local_var,
        name_local_str,
        secret_local_str,
        url_local_str
        );

    if (!webhook_subscription_local_var) {
        goto end;
    }

    return webhook_subscription_local_var;
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
