#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_subscription.h"



static event_subscription_t *event_subscription_create_internal(
    char *callback_url,
    char *event_type,
    int *is_active,
    char *subscription_id
    ) {
    event_subscription_t *event_subscription_local_var = malloc(sizeof(event_subscription_t));
    if (!event_subscription_local_var) {
        return NULL;
    }
    memset(event_subscription_local_var, 0, sizeof(event_subscription_t));
    event_subscription_local_var->_library_owned = 1;
    event_subscription_local_var->callback_url = callback_url;
    event_subscription_local_var->event_type = event_type;
    event_subscription_local_var->is_active = is_active;
    event_subscription_local_var->subscription_id = subscription_id;
    return event_subscription_local_var;
}

__attribute__((deprecated)) event_subscription_t *event_subscription_create(
    char *callback_url,
    char *event_type,
    int *is_active,
    char *subscription_id
    ) {
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    event_subscription_t *result = event_subscription_create_internal (
        callback_url,
        event_type,
        is_active_copy,
        subscription_id
        );
    if (!result) {
        free(is_active_copy);
    }
    return result;
}

void event_subscription_free(event_subscription_t *event_subscription) {
    if(NULL == event_subscription){
        return ;
    }
    if(event_subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "event_subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (event_subscription->callback_url) {
        free(event_subscription->callback_url);
        event_subscription->callback_url = NULL;
    }
    if (event_subscription->event_type) {
        free(event_subscription->event_type);
        event_subscription->event_type = NULL;
    }
    if (event_subscription->is_active) {
        free(event_subscription->is_active);
        event_subscription->is_active = NULL;
    }
    if (event_subscription->subscription_id) {
        free(event_subscription->subscription_id);
        event_subscription->subscription_id = NULL;
    }
    free(event_subscription);
}

cJSON *event_subscription_convertToJSON(event_subscription_t *event_subscription) {
    cJSON *item = cJSON_CreateObject();

    // event_subscription->callback_url
    if (!event_subscription->callback_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "callback_url", event_subscription->callback_url) == NULL) {
    goto fail; //String
    }


    // event_subscription->event_type
    if (!event_subscription->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "event_type", event_subscription->event_type) == NULL) {
    goto fail; //String
    }


    // event_subscription->is_active
    if (!event_subscription->is_active) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_active", *event_subscription->is_active) == NULL) {
    goto fail; //Bool
    }


    // event_subscription->subscription_id
    if (!event_subscription->subscription_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subscription_id", event_subscription->subscription_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

event_subscription_t *event_subscription_parseFromJSON(cJSON *event_subscriptionJSON){

    event_subscription_t *event_subscription_local_var = NULL;

    char *callback_url_local_str = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for event_subscription->is_active
    int *is_active_local_var = NULL;

    char *subscription_id_local_str = NULL;

    // event_subscription->callback_url
    cJSON *callback_url = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON, "callback_url");
    if (cJSON_IsNull(callback_url)) {
        callback_url = NULL;
    }
    if (!callback_url) {
        goto end;
    }

    
    if(!cJSON_IsString(callback_url))
    {
    goto end; //String
    }

    // event_subscription->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON, "event_type");
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

    // event_subscription->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (!is_active) {
        goto end;
    }

    
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

    // event_subscription->subscription_id
    cJSON *subscription_id = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON, "subscription_id");
    if (cJSON_IsNull(subscription_id)) {
        subscription_id = NULL;
    }
    if (!subscription_id) {
        goto end;
    }

    
    if(!cJSON_IsString(subscription_id))
    {
    goto end; //String
    }


    if (callback_url && !cJSON_IsNull(callback_url)) callback_url_local_str = strdup(callback_url->valuestring);
    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (subscription_id && !cJSON_IsNull(subscription_id)) subscription_id_local_str = strdup(subscription_id->valuestring);

    event_subscription_local_var = event_subscription_create_internal (
        callback_url_local_str,
        event_type_local_str,
        is_active_local_var,
        subscription_id_local_str
        );

    if (!event_subscription_local_var) {
        goto end;
    }

    return event_subscription_local_var;
end:
    if (callback_url_local_str) {
        free(callback_url_local_str);
        callback_url_local_str = NULL;
    }
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (subscription_id_local_str) {
        free(subscription_id_local_str);
        subscription_id_local_str = NULL;
    }
    return NULL;

}
