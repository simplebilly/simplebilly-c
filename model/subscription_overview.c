#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_overview.h"



static subscription_overview_t *subscription_overview_create_internal(
    char *current_period_end,
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    char *manage_url,
    char *plan,
    char *plan_name,
    double *price_eur,
    int *quantity,
    char *status,
    char *subscription_id,
    char *trial_ends_at,
    usage_snapshot_t *usage
    ) {
    subscription_overview_t *subscription_overview_local_var = malloc(sizeof(subscription_overview_t));
    if (!subscription_overview_local_var) {
        return NULL;
    }
    memset(subscription_overview_local_var, 0, sizeof(subscription_overview_t));
    subscription_overview_local_var->_library_owned = 1;
    subscription_overview_local_var->current_period_end = current_period_end;
    subscription_overview_local_var->features = features;
    subscription_overview_local_var->is_trialing = is_trialing;
    subscription_overview_local_var->limits = limits;
    subscription_overview_local_var->manage_url = manage_url;
    subscription_overview_local_var->plan = plan;
    subscription_overview_local_var->plan_name = plan_name;
    subscription_overview_local_var->price_eur = price_eur;
    subscription_overview_local_var->quantity = quantity;
    subscription_overview_local_var->status = status;
    subscription_overview_local_var->subscription_id = subscription_id;
    subscription_overview_local_var->trial_ends_at = trial_ends_at;
    subscription_overview_local_var->usage = usage;
    return subscription_overview_local_var;
}

__attribute__((deprecated)) subscription_overview_t *subscription_overview_create(
    char *current_period_end,
    plan_features_t *features,
    int *is_trialing,
    plan_limits_t *limits,
    char *manage_url,
    char *plan,
    char *plan_name,
    double *price_eur,
    int *quantity,
    char *status,
    char *subscription_id,
    char *trial_ends_at,
    usage_snapshot_t *usage
    ) {
    int *is_trialing_copy = NULL;
    if (is_trialing) {
        is_trialing_copy = malloc(sizeof(int));
        if (is_trialing_copy) *is_trialing_copy = *is_trialing;
    }
    double *price_eur_copy = NULL;
    if (price_eur) {
        price_eur_copy = malloc(sizeof(double));
        if (price_eur_copy) *price_eur_copy = *price_eur;
    }
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    subscription_overview_t *result = subscription_overview_create_internal (
        current_period_end,
        features,
        is_trialing_copy,
        limits,
        manage_url,
        plan,
        plan_name,
        price_eur_copy,
        quantity_copy,
        status,
        subscription_id,
        trial_ends_at,
        usage
        );
    if (!result) {
        free(is_trialing_copy);
        free(price_eur_copy);
        free(quantity_copy);
    }
    return result;
}

void subscription_overview_free(subscription_overview_t *subscription_overview) {
    if(NULL == subscription_overview){
        return ;
    }
    if(subscription_overview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "subscription_overview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (subscription_overview->current_period_end) {
        free(subscription_overview->current_period_end);
        subscription_overview->current_period_end = NULL;
    }
    if (subscription_overview->features) {
        plan_features_free(subscription_overview->features);
        subscription_overview->features = NULL;
    }
    if (subscription_overview->is_trialing) {
        free(subscription_overview->is_trialing);
        subscription_overview->is_trialing = NULL;
    }
    if (subscription_overview->limits) {
        plan_limits_free(subscription_overview->limits);
        subscription_overview->limits = NULL;
    }
    if (subscription_overview->manage_url) {
        free(subscription_overview->manage_url);
        subscription_overview->manage_url = NULL;
    }
    if (subscription_overview->plan) {
        free(subscription_overview->plan);
        subscription_overview->plan = NULL;
    }
    if (subscription_overview->plan_name) {
        free(subscription_overview->plan_name);
        subscription_overview->plan_name = NULL;
    }
    if (subscription_overview->price_eur) {
        free(subscription_overview->price_eur);
        subscription_overview->price_eur = NULL;
    }
    if (subscription_overview->quantity) {
        free(subscription_overview->quantity);
        subscription_overview->quantity = NULL;
    }
    if (subscription_overview->status) {
        free(subscription_overview->status);
        subscription_overview->status = NULL;
    }
    if (subscription_overview->subscription_id) {
        free(subscription_overview->subscription_id);
        subscription_overview->subscription_id = NULL;
    }
    if (subscription_overview->trial_ends_at) {
        free(subscription_overview->trial_ends_at);
        subscription_overview->trial_ends_at = NULL;
    }
    if (subscription_overview->usage) {
        usage_snapshot_free(subscription_overview->usage);
        subscription_overview->usage = NULL;
    }
    free(subscription_overview);
}

cJSON *subscription_overview_convertToJSON(subscription_overview_t *subscription_overview) {
    cJSON *item = cJSON_CreateObject();

    // subscription_overview->current_period_end
    if(subscription_overview->current_period_end) {
    if(cJSON_AddStringToObject(item, "currentPeriodEnd", subscription_overview->current_period_end) == NULL) {
    goto fail; //Date-Time
    }
    }


    // subscription_overview->features
    if (!subscription_overview->features) {
        goto fail;
    }
    cJSON *features_local_JSON = plan_features_convertToJSON(subscription_overview->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // subscription_overview->is_trialing
    if (!subscription_overview->is_trialing) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isTrialing", *subscription_overview->is_trialing) == NULL) {
    goto fail; //Bool
    }


    // subscription_overview->limits
    if (!subscription_overview->limits) {
        goto fail;
    }
    cJSON *limits_local_JSON = plan_limits_convertToJSON(subscription_overview->limits);
    if(limits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limits", limits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // subscription_overview->manage_url
    if(subscription_overview->manage_url) {
    if(cJSON_AddStringToObject(item, "manageUrl", subscription_overview->manage_url) == NULL) {
    goto fail; //String
    }
    }


    // subscription_overview->plan
    if (!subscription_overview->plan) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "plan", subscription_overview->plan) == NULL) {
    goto fail; //String
    }


    // subscription_overview->plan_name
    if (!subscription_overview->plan_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "planName", subscription_overview->plan_name) == NULL) {
    goto fail; //String
    }


    // subscription_overview->price_eur
    if (!subscription_overview->price_eur) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priceEur", *subscription_overview->price_eur) == NULL) {
    goto fail; //Numeric
    }


    // subscription_overview->quantity
    if(subscription_overview->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *subscription_overview->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // subscription_overview->status
    if(subscription_overview->status) {
    if(cJSON_AddStringToObject(item, "status", subscription_overview->status) == NULL) {
    goto fail; //String
    }
    }


    // subscription_overview->subscription_id
    if(subscription_overview->subscription_id) {
    if(cJSON_AddStringToObject(item, "subscriptionId", subscription_overview->subscription_id) == NULL) {
    goto fail; //String
    }
    }


    // subscription_overview->trial_ends_at
    if(subscription_overview->trial_ends_at) {
    if(cJSON_AddStringToObject(item, "trialEndsAt", subscription_overview->trial_ends_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // subscription_overview->usage
    if (!subscription_overview->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = usage_snapshot_convertToJSON(subscription_overview->usage);
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

subscription_overview_t *subscription_overview_parseFromJSON(cJSON *subscription_overviewJSON){

    subscription_overview_t *subscription_overview_local_var = NULL;

    char *current_period_end_local_str = NULL;

    // define the local variable for subscription_overview->features
    plan_features_t *features_local_nonprim = NULL;

    // define the local variable for subscription_overview->is_trialing
    int *is_trialing_local_var = NULL;

    // define the local variable for subscription_overview->limits
    plan_limits_t *limits_local_nonprim = NULL;

    char *manage_url_local_str = NULL;

    char *plan_local_str = NULL;

    char *plan_name_local_str = NULL;

    // define the local variable for subscription_overview->price_eur
    double *price_eur_local_var = NULL;

    // define the local variable for subscription_overview->quantity
    int *quantity_local_var = NULL;

    char *status_local_str = NULL;

    char *subscription_id_local_str = NULL;

    char *trial_ends_at_local_str = NULL;

    // define the local variable for subscription_overview->usage
    usage_snapshot_t *usage_local_nonprim = NULL;

    // subscription_overview->current_period_end
    cJSON *current_period_end = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "currentPeriodEnd");
    if (cJSON_IsNull(current_period_end)) {
        current_period_end = NULL;
    }
    if (current_period_end) { 
    if(!cJSON_IsString(current_period_end) && !cJSON_IsNull(current_period_end))
    {
    goto end; //DateTime
    }
    }

    // subscription_overview->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = plan_features_parseFromJSON(features); //nonprimitive

    // subscription_overview->is_trialing
    cJSON *is_trialing = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "isTrialing");
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

    // subscription_overview->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    limits_local_nonprim = plan_limits_parseFromJSON(limits); //nonprimitive

    // subscription_overview->manage_url
    cJSON *manage_url = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "manageUrl");
    if (cJSON_IsNull(manage_url)) {
        manage_url = NULL;
    }
    if (manage_url) { 
    if(!cJSON_IsString(manage_url) && !cJSON_IsNull(manage_url))
    {
    goto end; //String
    }
    }

    // subscription_overview->plan
    cJSON *plan = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "plan");
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

    // subscription_overview->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "planName");
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

    // subscription_overview->price_eur
    cJSON *price_eur = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "priceEur");
    if (cJSON_IsNull(price_eur)) {
        price_eur = NULL;
    }
    if (!price_eur) {
        goto end;
    }

    
    if(!cJSON_IsNumber(price_eur))
    {
    goto end; //Numeric
    }
    price_eur_local_var = malloc(sizeof(double));
    if(!price_eur_local_var)
    {
        goto end;
    }
    *price_eur_local_var = price_eur->valuedouble;

    // subscription_overview->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // subscription_overview->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // subscription_overview->subscription_id
    cJSON *subscription_id = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "subscriptionId");
    if (cJSON_IsNull(subscription_id)) {
        subscription_id = NULL;
    }
    if (subscription_id) { 
    if(!cJSON_IsString(subscription_id) && !cJSON_IsNull(subscription_id))
    {
    goto end; //String
    }
    }

    // subscription_overview->trial_ends_at
    cJSON *trial_ends_at = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "trialEndsAt");
    if (cJSON_IsNull(trial_ends_at)) {
        trial_ends_at = NULL;
    }
    if (trial_ends_at) { 
    if(!cJSON_IsString(trial_ends_at) && !cJSON_IsNull(trial_ends_at))
    {
    goto end; //DateTime
    }
    }

    // subscription_overview->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(subscription_overviewJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = usage_snapshot_parseFromJSON(usage); //nonprimitive


    if (current_period_end && !cJSON_IsNull(current_period_end)) current_period_end_local_str = strdup(current_period_end->valuestring);
    if (manage_url && !cJSON_IsNull(manage_url)) manage_url_local_str = strdup(manage_url->valuestring);
    if (plan && !cJSON_IsNull(plan)) plan_local_str = strdup(plan->valuestring);
    if (plan_name && !cJSON_IsNull(plan_name)) plan_name_local_str = strdup(plan_name->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (subscription_id && !cJSON_IsNull(subscription_id)) subscription_id_local_str = strdup(subscription_id->valuestring);
    if (trial_ends_at && !cJSON_IsNull(trial_ends_at)) trial_ends_at_local_str = strdup(trial_ends_at->valuestring);

    subscription_overview_local_var = subscription_overview_create_internal (
        current_period_end_local_str,
        features_local_nonprim,
        is_trialing_local_var,
        limits_local_nonprim,
        manage_url_local_str,
        plan_local_str,
        plan_name_local_str,
        price_eur_local_var,
        quantity_local_var,
        status_local_str,
        subscription_id_local_str,
        trial_ends_at_local_str,
        usage_local_nonprim
        );

    if (!subscription_overview_local_var) {
        goto end;
    }

    return subscription_overview_local_var;
end:
    if (current_period_end_local_str) {
        free(current_period_end_local_str);
        current_period_end_local_str = NULL;
    }
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
    if (manage_url_local_str) {
        free(manage_url_local_str);
        manage_url_local_str = NULL;
    }
    if (plan_local_str) {
        free(plan_local_str);
        plan_local_str = NULL;
    }
    if (plan_name_local_str) {
        free(plan_name_local_str);
        plan_name_local_str = NULL;
    }
    if (price_eur_local_var) {
        free(price_eur_local_var);
        price_eur_local_var = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (subscription_id_local_str) {
        free(subscription_id_local_str);
        subscription_id_local_str = NULL;
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
