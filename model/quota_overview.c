#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quota_overview.h"



static quota_overview_t *quota_overview_create_internal(
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    list_t *metered,
    char *plan,
    char *plan_name,
    char *trial_ends_at,
    usage_snapshot_t *usage
    ) {
    quota_overview_t *quota_overview_local_var = malloc(sizeof(quota_overview_t));
    if (!quota_overview_local_var) {
        return NULL;
    }
    memset(quota_overview_local_var, 0, sizeof(quota_overview_t));
    quota_overview_local_var->_library_owned = 1;
    quota_overview_local_var->features = features;
    quota_overview_local_var->is_trialing = is_trialing;
    quota_overview_local_var->limits = limits;
    quota_overview_local_var->metered = metered;
    quota_overview_local_var->plan = plan;
    quota_overview_local_var->plan_name = plan_name;
    quota_overview_local_var->trial_ends_at = trial_ends_at;
    quota_overview_local_var->usage = usage;
    return quota_overview_local_var;
}

__attribute__((deprecated)) quota_overview_t *quota_overview_create(
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    list_t *metered,
    char *plan,
    char *plan_name,
    char *trial_ends_at,
    usage_snapshot_t *usage
    ) {
    int *is_trialing_copy = NULL;
    if (is_trialing) {
        is_trialing_copy = malloc(sizeof(int));
        if (is_trialing_copy) *is_trialing_copy = *is_trialing;
    }
    quota_overview_t *result = quota_overview_create_internal (
        features,
        is_trialing_copy,
        limits,
        metered,
        plan,
        plan_name,
        trial_ends_at,
        usage
        );
    if (!result) {
        free(is_trialing_copy);
    }
    return result;
}

void quota_overview_free(quota_overview_t *quota_overview) {
    if(NULL == quota_overview){
        return ;
    }
    if(quota_overview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quota_overview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quota_overview->features) {
        plan_features_free(quota_overview->features);
        quota_overview->features = NULL;
    }
    if (quota_overview->is_trialing) {
        free(quota_overview->is_trialing);
        quota_overview->is_trialing = NULL;
    }
    if (quota_overview->limits) {
        plan_limits_free(quota_overview->limits);
        quota_overview->limits = NULL;
    }
    if (quota_overview->metered) {
        list_ForEach(listEntry, quota_overview->metered) {
            metered_usage_free(listEntry->data);
        }
        list_freeList(quota_overview->metered);
        quota_overview->metered = NULL;
    }
    if (quota_overview->plan) {
        free(quota_overview->plan);
        quota_overview->plan = NULL;
    }
    if (quota_overview->plan_name) {
        free(quota_overview->plan_name);
        quota_overview->plan_name = NULL;
    }
    if (quota_overview->trial_ends_at) {
        free(quota_overview->trial_ends_at);
        quota_overview->trial_ends_at = NULL;
    }
    if (quota_overview->usage) {
        usage_snapshot_free(quota_overview->usage);
        quota_overview->usage = NULL;
    }
    free(quota_overview);
}

cJSON *quota_overview_convertToJSON(quota_overview_t *quota_overview) {
    cJSON *item = cJSON_CreateObject();

    // quota_overview->features
    if (!quota_overview->features) {
        goto fail;
    }
    cJSON *features_local_JSON = plan_features_convertToJSON(quota_overview->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // quota_overview->is_trialing
    if (!quota_overview->is_trialing) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isTrialing", *quota_overview->is_trialing) == NULL) {
    goto fail; //Bool
    }


    // quota_overview->limits
    if (!quota_overview->limits) {
        goto fail;
    }
    cJSON *limits_local_JSON = plan_limits_convertToJSON(quota_overview->limits);
    if(limits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limits", limits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // quota_overview->metered
    if (!quota_overview->metered) {
        goto fail;
    }
    cJSON *metered = cJSON_AddArrayToObject(item, "metered");
    if(metered == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *meteredListEntry;
    if (quota_overview->metered) {
    list_ForEach(meteredListEntry, quota_overview->metered) {
    cJSON *itemLocal = metered_usage_convertToJSON(meteredListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(metered, itemLocal);
    }
    }


    // quota_overview->plan
    if (!quota_overview->plan) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "plan", quota_overview->plan) == NULL) {
    goto fail; //String
    }


    // quota_overview->plan_name
    if (!quota_overview->plan_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "planName", quota_overview->plan_name) == NULL) {
    goto fail; //String
    }


    // quota_overview->trial_ends_at
    if(quota_overview->trial_ends_at) {
    if(cJSON_AddStringToObject(item, "trialEndsAt", quota_overview->trial_ends_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // quota_overview->usage
    if (!quota_overview->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = usage_snapshot_convertToJSON(quota_overview->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
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

quota_overview_t *quota_overview_parseFromJSON(cJSON *quota_overviewJSON){

    quota_overview_t *quota_overview_local_var = NULL;

    // define the local variable for quota_overview->features
    plan_features_t *features_local_nonprim = NULL;

    // define the local variable for quota_overview->is_trialing
    int *is_trialing_local_var = NULL;

    // define the local variable for quota_overview->limits
    plan_limits_t *limits_local_nonprim = NULL;

    // define the local list for quota_overview->metered
    list_t *meteredList = NULL;

    char *plan_local_str = NULL;

    char *plan_name_local_str = NULL;

    char *trial_ends_at_local_str = NULL;

    // define the local variable for quota_overview->usage
    usage_snapshot_t *usage_local_nonprim = NULL;

    // quota_overview->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = plan_features_parseFromJSON(features); //nonprimitive

    // quota_overview->is_trialing
    cJSON *is_trialing = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "isTrialing");
    if (cJSON_IsNull(is_trialing)) {
        is_trialing = NULL;
    }
    if (!is_trialing) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_trialing))
    {
    goto end; //Bool
    }
    is_trialing_local_var = malloc(sizeof(int));
    if(!is_trialing_local_var)
    {
        goto end;
    }
    *is_trialing_local_var = is_trialing->valueint;

    // quota_overview->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    limits_local_nonprim = plan_limits_parseFromJSON(limits); //nonprimitive

    // quota_overview->metered
    cJSON *metered = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "metered");
    if (cJSON_IsNull(metered)) {
        metered = NULL;
    }
    if (!metered) {
        goto end;
    }

    
    cJSON *metered_local_nonprimitive = NULL;
    if(!cJSON_IsArray(metered)){
        goto end; //nonprimitive container
    }

    meteredList = list_createList();

    cJSON_ArrayForEach(metered_local_nonprimitive,metered )
    {
        if(!cJSON_IsObject(metered_local_nonprimitive)){
            goto end;
        }
        metered_usage_t *meteredItem = metered_usage_parseFromJSON(metered_local_nonprimitive);

        list_addElement(meteredList, meteredItem);
    }

    // quota_overview->plan
    cJSON *plan = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "plan");
    if (cJSON_IsNull(plan)) {
        plan = NULL;
    }
    if (!plan) {
        goto end;
    }

    
    if(!cJSON_IsString(plan))
    {
    goto end; //String
    }

    // quota_overview->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "planName");
    if (cJSON_IsNull(plan_name)) {
        plan_name = NULL;
    }
    if (!plan_name) {
        goto end;
    }

    
    if(!cJSON_IsString(plan_name))
    {
    goto end; //String
    }

    // quota_overview->trial_ends_at
    cJSON *trial_ends_at = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "trialEndsAt");
    if (cJSON_IsNull(trial_ends_at)) {
        trial_ends_at = NULL;
    }
    if (trial_ends_at) { 
    if(!cJSON_IsString(trial_ends_at) && !cJSON_IsNull(trial_ends_at))
    {
    goto end; //DateTime
    }
    }

    // quota_overview->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(quota_overviewJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = usage_snapshot_parseFromJSON(usage); //nonprimitive


    if (plan && !cJSON_IsNull(plan)) plan_local_str = strdup(plan->valuestring);
    if (plan_name && !cJSON_IsNull(plan_name)) plan_name_local_str = strdup(plan_name->valuestring);
    if (trial_ends_at && !cJSON_IsNull(trial_ends_at)) trial_ends_at_local_str = strdup(trial_ends_at->valuestring);

    quota_overview_local_var = quota_overview_create_internal (
        features_local_nonprim,
        is_trialing_local_var,
        limits_local_nonprim,
        meteredList,
        plan_local_str,
        plan_name_local_str,
        trial_ends_at_local_str,
        usage_local_nonprim
        );

    if (!quota_overview_local_var) {
        goto end;
    }

    return quota_overview_local_var;
end:
    if (features_local_nonprim) {
        plan_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    if (is_trialing_local_var) {
        free(is_trialing_local_var);
        is_trialing_local_var = NULL;
    }
    if (limits_local_nonprim) {
        plan_limits_free(limits_local_nonprim);
        limits_local_nonprim = NULL;
    }
    if (meteredList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, meteredList) {
            metered_usage_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(meteredList);
        meteredList = NULL;
    }
    if (plan_local_str) {
        free(plan_local_str);
        plan_local_str = NULL;
    }
    if (plan_name_local_str) {
        free(plan_name_local_str);
        plan_name_local_str = NULL;
    }
    if (trial_ends_at_local_str) {
        free(trial_ends_at_local_str);
        trial_ends_at_local_str = NULL;
    }
    if (usage_local_nonprim) {
        usage_snapshot_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    return NULL;

}
