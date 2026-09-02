#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_export.h"



static gdpr_export_t *gdpr_export_create_internal(
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
    gdpr_export_t *gdpr_export_local_var = malloc(sizeof(gdpr_export_t));
    if (!gdpr_export_local_var) {
        return NULL;
    }
    memset(gdpr_export_local_var, 0, sizeof(gdpr_export_t));
    gdpr_export_local_var->_library_owned = 1;
    gdpr_export_local_var->activity_log = activity_log;
    gdpr_export_local_var->api_keys = api_keys;
    gdpr_export_local_var->billing = billing;
    gdpr_export_local_var->exported_at = exported_at;
    gdpr_export_local_var->generated_by_ai = generated_by_ai;
    gdpr_export_local_var->notifications = notifications;
    gdpr_export_local_var->refresh_tokens = refresh_tokens;
    gdpr_export_local_var->tenants = tenants;
    gdpr_export_local_var->usage_events = usage_events;
    gdpr_export_local_var->user = user;
    return gdpr_export_local_var;
}

__attribute__((deprecated)) gdpr_export_t *gdpr_export_create(
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
    gdpr_export_t *result = gdpr_export_create_internal (
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

void gdpr_export_free(gdpr_export_t *gdpr_export) {
    if(NULL == gdpr_export){
        return ;
    }
    if(gdpr_export->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_export_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_export->activity_log) {
        list_ForEach(listEntry, gdpr_export->activity_log) {
            gdpr_activity_free(listEntry->data);
        }
        list_freeList(gdpr_export->activity_log);
        gdpr_export->activity_log = NULL;
    }
    if (gdpr_export->api_keys) {
        list_ForEach(listEntry, gdpr_export->api_keys) {
            gdpr_api_key_free(listEntry->data);
        }
        list_freeList(gdpr_export->api_keys);
        gdpr_export->api_keys = NULL;
    }
    if (gdpr_export->billing) {
        list_ForEach(listEntry, gdpr_export->billing) {
            gdpr_billing_info_free(listEntry->data);
        }
        list_freeList(gdpr_export->billing);
        gdpr_export->billing = NULL;
    }
    if (gdpr_export->exported_at) {
        free(gdpr_export->exported_at);
        gdpr_export->exported_at = NULL;
    }
    if (gdpr_export->generated_by_ai) {
        free(gdpr_export->generated_by_ai);
        gdpr_export->generated_by_ai = NULL;
    }
    if (gdpr_export->notifications) {
        list_ForEach(listEntry, gdpr_export->notifications) {
            gdpr_notification_free(listEntry->data);
        }
        list_freeList(gdpr_export->notifications);
        gdpr_export->notifications = NULL;
    }
    if (gdpr_export->refresh_tokens) {
        list_ForEach(listEntry, gdpr_export->refresh_tokens) {
            gdpr_refresh_token_free(listEntry->data);
        }
        list_freeList(gdpr_export->refresh_tokens);
        gdpr_export->refresh_tokens = NULL;
    }
    if (gdpr_export->tenants) {
        list_ForEach(listEntry, gdpr_export->tenants) {
            gdpr_tenant_free(listEntry->data);
        }
        list_freeList(gdpr_export->tenants);
        gdpr_export->tenants = NULL;
    }
    if (gdpr_export->usage_events) {
        list_ForEach(listEntry, gdpr_export->usage_events) {
            gdpr_usage_event_free(listEntry->data);
        }
        list_freeList(gdpr_export->usage_events);
        gdpr_export->usage_events = NULL;
    }
    if (gdpr_export->user) {
        gdpr_user_free(gdpr_export->user);
        gdpr_export->user = NULL;
    }
    free(gdpr_export);
}

cJSON *gdpr_export_convertToJSON(gdpr_export_t *gdpr_export) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_export->activity_log
    if (!gdpr_export->activity_log) {
        goto fail;
    }
    cJSON *activity_log = cJSON_AddArrayToObject(item, "activityLog");
    if(activity_log == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *activity_logListEntry;
    if (gdpr_export->activity_log) {
    list_ForEach(activity_logListEntry, gdpr_export->activity_log) {
    cJSON *itemLocal = gdpr_activity_convertToJSON(activity_logListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(activity_log, itemLocal);
    }
    }


    // gdpr_export->api_keys
    if (!gdpr_export->api_keys) {
        goto fail;
    }
    cJSON *api_keys = cJSON_AddArrayToObject(item, "apiKeys");
    if(api_keys == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *api_keysListEntry;
    if (gdpr_export->api_keys) {
    list_ForEach(api_keysListEntry, gdpr_export->api_keys) {
    cJSON *itemLocal = gdpr_api_key_convertToJSON(api_keysListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(api_keys, itemLocal);
    }
    }


    // gdpr_export->billing
    if (!gdpr_export->billing) {
        goto fail;
    }
    cJSON *billing = cJSON_AddArrayToObject(item, "billing");
    if(billing == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *billingListEntry;
    if (gdpr_export->billing) {
    list_ForEach(billingListEntry, gdpr_export->billing) {
    cJSON *itemLocal = gdpr_billing_info_convertToJSON(billingListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(billing, itemLocal);
    }
    }


    // gdpr_export->exported_at
    if (!gdpr_export->exported_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "exportedAt", gdpr_export->exported_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_export->generated_by_ai
    if (!gdpr_export->generated_by_ai) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "generatedByAi", *gdpr_export->generated_by_ai) == NULL) {
    goto fail; //Bool
    }


    // gdpr_export->notifications
    if (!gdpr_export->notifications) {
        goto fail;
    }
    cJSON *notifications = cJSON_AddArrayToObject(item, "notifications");
    if(notifications == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *notificationsListEntry;
    if (gdpr_export->notifications) {
    list_ForEach(notificationsListEntry, gdpr_export->notifications) {
    cJSON *itemLocal = gdpr_notification_convertToJSON(notificationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(notifications, itemLocal);
    }
    }


    // gdpr_export->refresh_tokens
    if (!gdpr_export->refresh_tokens) {
        goto fail;
    }
    cJSON *refresh_tokens = cJSON_AddArrayToObject(item, "refreshTokens");
    if(refresh_tokens == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *refresh_tokensListEntry;
    if (gdpr_export->refresh_tokens) {
    list_ForEach(refresh_tokensListEntry, gdpr_export->refresh_tokens) {
    cJSON *itemLocal = gdpr_refresh_token_convertToJSON(refresh_tokensListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(refresh_tokens, itemLocal);
    }
    }


    // gdpr_export->tenants
    if (!gdpr_export->tenants) {
        goto fail;
    }
    cJSON *tenants = cJSON_AddArrayToObject(item, "tenants");
    if(tenants == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tenantsListEntry;
    if (gdpr_export->tenants) {
    list_ForEach(tenantsListEntry, gdpr_export->tenants) {
    cJSON *itemLocal = gdpr_tenant_convertToJSON(tenantsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tenants, itemLocal);
    }
    }


    // gdpr_export->usage_events
    if (!gdpr_export->usage_events) {
        goto fail;
    }
    cJSON *usage_events = cJSON_AddArrayToObject(item, "usageEvents");
    if(usage_events == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *usage_eventsListEntry;
    if (gdpr_export->usage_events) {
    list_ForEach(usage_eventsListEntry, gdpr_export->usage_events) {
    cJSON *itemLocal = gdpr_usage_event_convertToJSON(usage_eventsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(usage_events, itemLocal);
    }
    }


    // gdpr_export->user
    if (!gdpr_export->user) {
        goto fail;
    }
    cJSON *user_local_JSON = gdpr_user_convertToJSON(gdpr_export->user);
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

gdpr_export_t *gdpr_export_parseFromJSON(cJSON *gdpr_exportJSON){

    gdpr_export_t *gdpr_export_local_var = NULL;

    // define the local list for gdpr_export->activity_log
    list_t *activity_logList = NULL;

    // define the local list for gdpr_export->api_keys
    list_t *api_keysList = NULL;

    // define the local list for gdpr_export->billing
    list_t *billingList = NULL;

    char *exported_at_local_str = NULL;

    // define the local variable for gdpr_export->generated_by_ai
    int *generated_by_ai_local_var = NULL;

    // define the local list for gdpr_export->notifications
    list_t *notificationsList = NULL;

    // define the local list for gdpr_export->refresh_tokens
    list_t *refresh_tokensList = NULL;

    // define the local list for gdpr_export->tenants
    list_t *tenantsList = NULL;

    // define the local list for gdpr_export->usage_events
    list_t *usage_eventsList = NULL;

    // define the local variable for gdpr_export->user
    gdpr_user_t *user_local_nonprim = NULL;

    // gdpr_export->activity_log
    cJSON *activity_log = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "activityLog");
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

    // gdpr_export->api_keys
    cJSON *api_keys = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "apiKeys");
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

    // gdpr_export->billing
    cJSON *billing = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "billing");
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

    // gdpr_export->exported_at
    cJSON *exported_at = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "exportedAt");
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

    // gdpr_export->generated_by_ai
    cJSON *generated_by_ai = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "generatedByAi");
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

    // gdpr_export->notifications
    cJSON *notifications = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "notifications");
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

    // gdpr_export->refresh_tokens
    cJSON *refresh_tokens = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "refreshTokens");
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

    // gdpr_export->tenants
    cJSON *tenants = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "tenants");
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

    // gdpr_export->usage_events
    cJSON *usage_events = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "usageEvents");
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

    // gdpr_export->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(gdpr_exportJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = gdpr_user_parseFromJSON(user); //nonprimitive


    if (exported_at && !cJSON_IsNull(exported_at)) exported_at_local_str = strdup(exported_at->valuestring);

    gdpr_export_local_var = gdpr_export_create_internal (
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

    if (!gdpr_export_local_var) {
        goto end;
    }

    return gdpr_export_local_var;
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
