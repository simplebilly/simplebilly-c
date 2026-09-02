#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_gdpr_export_data.h"



static api_response_gdpr_export_data_t *api_response_gdpr_export_data_create_internal(
    list_t *activity_log,
    list_t *api_keys,
    list_t *billing,
    char *exported_at,
    int *generated_by_ai,
    list_t *notifications,
    list_t *refresh_tokens,
    list_t *tenants,
    list_t *usage_events,
    gdpr_user_t *user
    ) {
    api_response_gdpr_export_data_t *api_response_gdpr_export_data_local_var = malloc(sizeof(api_response_gdpr_export_data_t));
    if (!api_response_gdpr_export_data_local_var) {
        return NULL;
    }
    memset(api_response_gdpr_export_data_local_var, 0, sizeof(api_response_gdpr_export_data_t));
    api_response_gdpr_export_data_local_var->_library_owned = 1;
    api_response_gdpr_export_data_local_var->activity_log = activity_log;
    api_response_gdpr_export_data_local_var->api_keys = api_keys;
    api_response_gdpr_export_data_local_var->billing = billing;
    api_response_gdpr_export_data_local_var->exported_at = exported_at;
    api_response_gdpr_export_data_local_var->generated_by_ai = generated_by_ai;
    api_response_gdpr_export_data_local_var->notifications = notifications;
    api_response_gdpr_export_data_local_var->refresh_tokens = refresh_tokens;
    api_response_gdpr_export_data_local_var->tenants = tenants;
    api_response_gdpr_export_data_local_var->usage_events = usage_events;
    api_response_gdpr_export_data_local_var->user = user;
    return api_response_gdpr_export_data_local_var;
}

__attribute__((deprecated)) api_response_gdpr_export_data_t *api_response_gdpr_export_data_create(
    list_t *activity_log,
    list_t *api_keys,
    list_t *billing,
    char *exported_at,
    int *generated_by_ai,
    list_t *notifications,
    list_t *refresh_tokens,
    list_t *tenants,
    list_t *usage_events,
    gdpr_user_t *user
    ) {
    int *generated_by_ai_copy = NULL;
    if (generated_by_ai) {
        generated_by_ai_copy = malloc(sizeof(int));
        if (generated_by_ai_copy) *generated_by_ai_copy = *generated_by_ai;
    }
    api_response_gdpr_export_data_t *result = api_response_gdpr_export_data_create_internal (
        activity_log,
        api_keys,
        billing,
        exported_at,
        generated_by_ai_copy,
        notifications,
        refresh_tokens,
        tenants,
        usage_events,
        user
        );
    if (!result) {
        free(generated_by_ai_copy);
    }
    return result;
}

void api_response_gdpr_export_data_free(api_response_gdpr_export_data_t *api_response_gdpr_export_data) {
    if(NULL == api_response_gdpr_export_data){
        return ;
    }
    if(api_response_gdpr_export_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_gdpr_export_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_gdpr_export_data->activity_log) {
        list_ForEach(listEntry, api_response_gdpr_export_data->activity_log) {
            gdpr_activity_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->activity_log);
        api_response_gdpr_export_data->activity_log = NULL;
    }
    if (api_response_gdpr_export_data->api_keys) {
        list_ForEach(listEntry, api_response_gdpr_export_data->api_keys) {
            gdpr_api_key_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->api_keys);
        api_response_gdpr_export_data->api_keys = NULL;
    }
    if (api_response_gdpr_export_data->billing) {
        list_ForEach(listEntry, api_response_gdpr_export_data->billing) {
            gdpr_billing_info_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->billing);
        api_response_gdpr_export_data->billing = NULL;
    }
    if (api_response_gdpr_export_data->exported_at) {
        free(api_response_gdpr_export_data->exported_at);
        api_response_gdpr_export_data->exported_at = NULL;
    }
    if (api_response_gdpr_export_data->generated_by_ai) {
        free(api_response_gdpr_export_data->generated_by_ai);
        api_response_gdpr_export_data->generated_by_ai = NULL;
    }
    if (api_response_gdpr_export_data->notifications) {
        list_ForEach(listEntry, api_response_gdpr_export_data->notifications) {
            gdpr_notification_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->notifications);
        api_response_gdpr_export_data->notifications = NULL;
    }
    if (api_response_gdpr_export_data->refresh_tokens) {
        list_ForEach(listEntry, api_response_gdpr_export_data->refresh_tokens) {
            gdpr_refresh_token_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->refresh_tokens);
        api_response_gdpr_export_data->refresh_tokens = NULL;
    }
    if (api_response_gdpr_export_data->tenants) {
        list_ForEach(listEntry, api_response_gdpr_export_data->tenants) {
            gdpr_tenant_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->tenants);
        api_response_gdpr_export_data->tenants = NULL;
    }
    if (api_response_gdpr_export_data->usage_events) {
        list_ForEach(listEntry, api_response_gdpr_export_data->usage_events) {
            gdpr_usage_event_free(listEntry->data);
        }
        list_freeList(api_response_gdpr_export_data->usage_events);
        api_response_gdpr_export_data->usage_events = NULL;
    }
    if (api_response_gdpr_export_data->user) {
        gdpr_user_free(api_response_gdpr_export_data->user);
        api_response_gdpr_export_data->user = NULL;
    }
    free(api_response_gdpr_export_data);
}

cJSON *api_response_gdpr_export_data_convertToJSON(api_response_gdpr_export_data_t *api_response_gdpr_export_data) {
    cJSON *item = cJSON_CreateObject();

    // api_response_gdpr_export_data->activity_log
    if (!api_response_gdpr_export_data->activity_log) {
        goto fail;
    }
    cJSON *activity_log = cJSON_AddArrayToObject(item, "activityLog");
    if(activity_log == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *activity_logListEntry;
    if (api_response_gdpr_export_data->activity_log) {
    list_ForEach(activity_logListEntry, api_response_gdpr_export_data->activity_log) {
    cJSON *itemLocal = gdpr_activity_convertToJSON(activity_logListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(activity_log, itemLocal);
    }
    }


    // api_response_gdpr_export_data->api_keys
    if (!api_response_gdpr_export_data->api_keys) {
        goto fail;
    }
    cJSON *api_keys = cJSON_AddArrayToObject(item, "apiKeys");
    if(api_keys == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *api_keysListEntry;
    if (api_response_gdpr_export_data->api_keys) {
    list_ForEach(api_keysListEntry, api_response_gdpr_export_data->api_keys) {
    cJSON *itemLocal = gdpr_api_key_convertToJSON(api_keysListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(api_keys, itemLocal);
    }
    }


    // api_response_gdpr_export_data->billing
    if (!api_response_gdpr_export_data->billing) {
        goto fail;
    }
    cJSON *billing = cJSON_AddArrayToObject(item, "billing");
    if(billing == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *billingListEntry;
    if (api_response_gdpr_export_data->billing) {
    list_ForEach(billingListEntry, api_response_gdpr_export_data->billing) {
    cJSON *itemLocal = gdpr_billing_info_convertToJSON(billingListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(billing, itemLocal);
    }
    }


    // api_response_gdpr_export_data->exported_at
    if (!api_response_gdpr_export_data->exported_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "exportedAt", api_response_gdpr_export_data->exported_at) == NULL) {
    goto fail; //Date-Time
    }


    // api_response_gdpr_export_data->generated_by_ai
    if (!api_response_gdpr_export_data->generated_by_ai) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "generatedByAi", *api_response_gdpr_export_data->generated_by_ai) == NULL) {
    goto fail; //Bool
    }


    // api_response_gdpr_export_data->notifications
    if (!api_response_gdpr_export_data->notifications) {
        goto fail;
    }
    cJSON *notifications = cJSON_AddArrayToObject(item, "notifications");
    if(notifications == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *notificationsListEntry;
    if (api_response_gdpr_export_data->notifications) {
    list_ForEach(notificationsListEntry, api_response_gdpr_export_data->notifications) {
    cJSON *itemLocal = gdpr_notification_convertToJSON(notificationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(notifications, itemLocal);
    }
    }


    // api_response_gdpr_export_data->refresh_tokens
    if (!api_response_gdpr_export_data->refresh_tokens) {
        goto fail;
    }
    cJSON *refresh_tokens = cJSON_AddArrayToObject(item, "refreshTokens");
    if(refresh_tokens == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *refresh_tokensListEntry;
    if (api_response_gdpr_export_data->refresh_tokens) {
    list_ForEach(refresh_tokensListEntry, api_response_gdpr_export_data->refresh_tokens) {
    cJSON *itemLocal = gdpr_refresh_token_convertToJSON(refresh_tokensListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(refresh_tokens, itemLocal);
    }
    }


    // api_response_gdpr_export_data->tenants
    if (!api_response_gdpr_export_data->tenants) {
        goto fail;
    }
    cJSON *tenants = cJSON_AddArrayToObject(item, "tenants");
    if(tenants == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tenantsListEntry;
    if (api_response_gdpr_export_data->tenants) {
    list_ForEach(tenantsListEntry, api_response_gdpr_export_data->tenants) {
    cJSON *itemLocal = gdpr_tenant_convertToJSON(tenantsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tenants, itemLocal);
    }
    }


    // api_response_gdpr_export_data->usage_events
    if (!api_response_gdpr_export_data->usage_events) {
        goto fail;
    }
    cJSON *usage_events = cJSON_AddArrayToObject(item, "usageEvents");
    if(usage_events == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *usage_eventsListEntry;
    if (api_response_gdpr_export_data->usage_events) {
    list_ForEach(usage_eventsListEntry, api_response_gdpr_export_data->usage_events) {
    cJSON *itemLocal = gdpr_usage_event_convertToJSON(usage_eventsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(usage_events, itemLocal);
    }
    }


    // api_response_gdpr_export_data->user
    if (!api_response_gdpr_export_data->user) {
        goto fail;
    }
    cJSON *user_local_JSON = gdpr_user_convertToJSON(api_response_gdpr_export_data->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_gdpr_export_data_t *api_response_gdpr_export_data_parseFromJSON(cJSON *api_response_gdpr_export_dataJSON){

    api_response_gdpr_export_data_t *api_response_gdpr_export_data_local_var = NULL;

    // define the local list for api_response_gdpr_export_data->activity_log
    list_t *activity_logList = NULL;

    // define the local list for api_response_gdpr_export_data->api_keys
    list_t *api_keysList = NULL;

    // define the local list for api_response_gdpr_export_data->billing
    list_t *billingList = NULL;

    char *exported_at_local_str = NULL;

    // define the local variable for api_response_gdpr_export_data->generated_by_ai
    int *generated_by_ai_local_var = NULL;

    // define the local list for api_response_gdpr_export_data->notifications
    list_t *notificationsList = NULL;

    // define the local list for api_response_gdpr_export_data->refresh_tokens
    list_t *refresh_tokensList = NULL;

    // define the local list for api_response_gdpr_export_data->tenants
    list_t *tenantsList = NULL;

    // define the local list for api_response_gdpr_export_data->usage_events
    list_t *usage_eventsList = NULL;

    // define the local variable for api_response_gdpr_export_data->user
    gdpr_user_t *user_local_nonprim = NULL;

    // api_response_gdpr_export_data->activity_log
    cJSON *activity_log = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "activityLog");
    if (cJSON_IsNull(activity_log)) {
        activity_log = NULL;
    }
    if (!activity_log) {
        goto end;
    }

    
    cJSON *activity_log_local_nonprimitive = NULL;
    if(!cJSON_IsArray(activity_log)){
        goto end; //nonprimitive container
    }

    activity_logList = list_createList();

    cJSON_ArrayForEach(activity_log_local_nonprimitive,activity_log )
    {
        if(!cJSON_IsObject(activity_log_local_nonprimitive)){
            goto end;
        }
        gdpr_activity_t *activity_logItem = gdpr_activity_parseFromJSON(activity_log_local_nonprimitive);

        list_addElement(activity_logList, activity_logItem);
    }

    // api_response_gdpr_export_data->api_keys
    cJSON *api_keys = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "apiKeys");
    if (cJSON_IsNull(api_keys)) {
        api_keys = NULL;
    }
    if (!api_keys) {
        goto end;
    }

    
    cJSON *api_keys_local_nonprimitive = NULL;
    if(!cJSON_IsArray(api_keys)){
        goto end; //nonprimitive container
    }

    api_keysList = list_createList();

    cJSON_ArrayForEach(api_keys_local_nonprimitive,api_keys )
    {
        if(!cJSON_IsObject(api_keys_local_nonprimitive)){
            goto end;
        }
        gdpr_api_key_t *api_keysItem = gdpr_api_key_parseFromJSON(api_keys_local_nonprimitive);

        list_addElement(api_keysList, api_keysItem);
    }

    // api_response_gdpr_export_data->billing
    cJSON *billing = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "billing");
    if (cJSON_IsNull(billing)) {
        billing = NULL;
    }
    if (!billing) {
        goto end;
    }

    
    cJSON *billing_local_nonprimitive = NULL;
    if(!cJSON_IsArray(billing)){
        goto end; //nonprimitive container
    }

    billingList = list_createList();

    cJSON_ArrayForEach(billing_local_nonprimitive,billing )
    {
        if(!cJSON_IsObject(billing_local_nonprimitive)){
            goto end;
        }
        gdpr_billing_info_t *billingItem = gdpr_billing_info_parseFromJSON(billing_local_nonprimitive);

        list_addElement(billingList, billingItem);
    }

    // api_response_gdpr_export_data->exported_at
    cJSON *exported_at = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "exportedAt");
    if (cJSON_IsNull(exported_at)) {
        exported_at = NULL;
    }
    if (!exported_at) {
        goto end;
    }

    
    if(!cJSON_IsString(exported_at) && !cJSON_IsNull(exported_at))
    {
    goto end; //DateTime
    }

    // api_response_gdpr_export_data->generated_by_ai
    cJSON *generated_by_ai = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "generatedByAi");
    if (cJSON_IsNull(generated_by_ai)) {
        generated_by_ai = NULL;
    }
    if (!generated_by_ai) {
        goto end;
    }

    
    if(!cJSON_IsBool(generated_by_ai))
    {
    goto end; //Bool
    }
    generated_by_ai_local_var = malloc(sizeof(int));
    if(!generated_by_ai_local_var)
    {
        goto end;
    }
    *generated_by_ai_local_var = generated_by_ai->valueint;

    // api_response_gdpr_export_data->notifications
    cJSON *notifications = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "notifications");
    if (cJSON_IsNull(notifications)) {
        notifications = NULL;
    }
    if (!notifications) {
        goto end;
    }

    
    cJSON *notifications_local_nonprimitive = NULL;
    if(!cJSON_IsArray(notifications)){
        goto end; //nonprimitive container
    }

    notificationsList = list_createList();

    cJSON_ArrayForEach(notifications_local_nonprimitive,notifications )
    {
        if(!cJSON_IsObject(notifications_local_nonprimitive)){
            goto end;
        }
        gdpr_notification_t *notificationsItem = gdpr_notification_parseFromJSON(notifications_local_nonprimitive);

        list_addElement(notificationsList, notificationsItem);
    }

    // api_response_gdpr_export_data->refresh_tokens
    cJSON *refresh_tokens = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "refreshTokens");
    if (cJSON_IsNull(refresh_tokens)) {
        refresh_tokens = NULL;
    }
    if (!refresh_tokens) {
        goto end;
    }

    
    cJSON *refresh_tokens_local_nonprimitive = NULL;
    if(!cJSON_IsArray(refresh_tokens)){
        goto end; //nonprimitive container
    }

    refresh_tokensList = list_createList();

    cJSON_ArrayForEach(refresh_tokens_local_nonprimitive,refresh_tokens )
    {
        if(!cJSON_IsObject(refresh_tokens_local_nonprimitive)){
            goto end;
        }
        gdpr_refresh_token_t *refresh_tokensItem = gdpr_refresh_token_parseFromJSON(refresh_tokens_local_nonprimitive);

        list_addElement(refresh_tokensList, refresh_tokensItem);
    }

    // api_response_gdpr_export_data->tenants
    cJSON *tenants = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "tenants");
    if (cJSON_IsNull(tenants)) {
        tenants = NULL;
    }
    if (!tenants) {
        goto end;
    }

    
    cJSON *tenants_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tenants)){
        goto end; //nonprimitive container
    }

    tenantsList = list_createList();

    cJSON_ArrayForEach(tenants_local_nonprimitive,tenants )
    {
        if(!cJSON_IsObject(tenants_local_nonprimitive)){
            goto end;
        }
        gdpr_tenant_t *tenantsItem = gdpr_tenant_parseFromJSON(tenants_local_nonprimitive);

        list_addElement(tenantsList, tenantsItem);
    }

    // api_response_gdpr_export_data->usage_events
    cJSON *usage_events = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "usageEvents");
    if (cJSON_IsNull(usage_events)) {
        usage_events = NULL;
    }
    if (!usage_events) {
        goto end;
    }

    
    cJSON *usage_events_local_nonprimitive = NULL;
    if(!cJSON_IsArray(usage_events)){
        goto end; //nonprimitive container
    }

    usage_eventsList = list_createList();

    cJSON_ArrayForEach(usage_events_local_nonprimitive,usage_events )
    {
        if(!cJSON_IsObject(usage_events_local_nonprimitive)){
            goto end;
        }
        gdpr_usage_event_t *usage_eventsItem = gdpr_usage_event_parseFromJSON(usage_events_local_nonprimitive);

        list_addElement(usage_eventsList, usage_eventsItem);
    }

    // api_response_gdpr_export_data->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(api_response_gdpr_export_dataJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = gdpr_user_parseFromJSON(user); //nonprimitive


    if (exported_at && !cJSON_IsNull(exported_at)) exported_at_local_str = strdup(exported_at->valuestring);

    api_response_gdpr_export_data_local_var = api_response_gdpr_export_data_create_internal (
        activity_logList,
        api_keysList,
        billingList,
        exported_at_local_str,
        generated_by_ai_local_var,
        notificationsList,
        refresh_tokensList,
        tenantsList,
        usage_eventsList,
        user_local_nonprim
        );

    if (!api_response_gdpr_export_data_local_var) {
        goto end;
    }

    return api_response_gdpr_export_data_local_var;
end:
    if (activity_logList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, activity_logList) {
            gdpr_activity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(activity_logList);
        activity_logList = NULL;
    }
    if (api_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, api_keysList) {
            gdpr_api_key_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(api_keysList);
        api_keysList = NULL;
    }
    if (billingList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, billingList) {
            gdpr_billing_info_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(billingList);
        billingList = NULL;
    }
    if (exported_at_local_str) {
        free(exported_at_local_str);
        exported_at_local_str = NULL;
    }
    if (generated_by_ai_local_var) {
        free(generated_by_ai_local_var);
        generated_by_ai_local_var = NULL;
    }
    if (notificationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, notificationsList) {
            gdpr_notification_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(notificationsList);
        notificationsList = NULL;
    }
    if (refresh_tokensList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, refresh_tokensList) {
            gdpr_refresh_token_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(refresh_tokensList);
        refresh_tokensList = NULL;
    }
    if (tenantsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tenantsList) {
            gdpr_tenant_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tenantsList);
        tenantsList = NULL;
    }
    if (usage_eventsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usage_eventsList) {
            gdpr_usage_event_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(usage_eventsList);
        usage_eventsList = NULL;
    }
    if (user_local_nonprim) {
        gdpr_user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
