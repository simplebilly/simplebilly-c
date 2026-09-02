#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_subscription_overview_data.h"



static api_response_subscription_overview_data_t *api_response_subscription_overview_data_create_internal(
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
    api_response_subscription_overview_data_t *api_response_subscription_overview_data_local_var = malloc(sizeof(api_response_subscription_overview_data_t));
    if (!api_response_subscription_overview_data_local_var) {
        return NULL;
    }
    memset(api_response_subscription_overview_data_local_var, 0, sizeof(api_response_subscription_overview_data_t));
    api_response_subscription_overview_data_local_var->_library_owned = 1;
    api_response_subscription_overview_data_local_var->current_period_end = current_period_end;
    api_response_subscription_overview_data_local_var->features = features;
    api_response_subscription_overview_data_local_var->is_trialing = is_trialing;
    api_response_subscription_overview_data_local_var->limits = limits;
    api_response_subscription_overview_data_local_var->manage_url = manage_url;
    api_response_subscription_overview_data_local_var->plan = plan;
    api_response_subscription_overview_data_local_var->plan_name = plan_name;
    api_response_subscription_overview_data_local_var->price_eur = price_eur;
    api_response_subscription_overview_data_local_var->quantity = quantity;
    api_response_subscription_overview_data_local_var->status = status;
    api_response_subscription_overview_data_local_var->subscription_id = subscription_id;
    api_response_subscription_overview_data_local_var->trial_ends_at = trial_ends_at;
    api_response_subscription_overview_data_local_var->usage = usage;
    return api_response_subscription_overview_data_local_var;
}

__attribute__((deprecated)) api_response_subscription_overview_data_t *api_response_subscription_overview_data_create(
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
    api_response_subscription_overview_data_t *result = api_response_subscription_overview_data_create_internal (
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

void api_response_subscription_overview_data_free(api_response_subscription_overview_data_t *api_response_subscription_overview_data) {
    if(NULL == api_response_subscription_overview_data){
        return ;
    }
    if(api_response_subscription_overview_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_subscription_overview_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_subscription_overview_data->current_period_end) {
        free(api_response_subscription_overview_data->current_period_end);
        api_response_subscription_overview_data->current_period_end = NULL;
    }
    if (api_response_subscription_overview_data->features) {
        plan_features_free(api_response_subscription_overview_data->features);
        api_response_subscription_overview_data->features = NULL;
    }
    if (api_response_subscription_overview_data->is_trialing) {
        free(api_response_subscription_overview_data->is_trialing);
        api_response_subscription_overview_data->is_trialing = NULL;
    }
    if (api_response_subscription_overview_data->limits) {
        plan_limits_free(api_response_subscription_overview_data->limits);
        api_response_subscription_overview_data->limits = NULL;
    }
    if (api_response_subscription_overview_data->manage_url) {
        free(api_response_subscription_overview_data->manage_url);
        api_response_subscription_overview_data->manage_url = NULL;
    }
    if (api_response_subscription_overview_data->plan) {
        free(api_response_subscription_overview_data->plan);
        api_response_subscription_overview_data->plan = NULL;
    }
    if (api_response_subscription_overview_data->plan_name) {
        free(api_response_subscription_overview_data->plan_name);
        api_response_subscription_overview_data->plan_name = NULL;
    }
    if (api_response_subscription_overview_data->price_eur) {
        free(api_response_subscription_overview_data->price_eur);
        api_response_subscription_overview_data->price_eur = NULL;
    }
    if (api_response_subscription_overview_data->quantity) {
        free(api_response_subscription_overview_data->quantity);
        api_response_subscription_overview_data->quantity = NULL;
    }
    if (api_response_subscription_overview_data->status) {
        free(api_response_subscription_overview_data->status);
        api_response_subscription_overview_data->status = NULL;
    }
    if (api_response_subscription_overview_data->subscription_id) {
        free(api_response_subscription_overview_data->subscription_id);
        api_response_subscription_overview_data->subscription_id = NULL;
    }
    if (api_response_subscription_overview_data->trial_ends_at) {
        free(api_response_subscription_overview_data->trial_ends_at);
        api_response_subscription_overview_data->trial_ends_at = NULL;
    }
    if (api_response_subscription_overview_data->usage) {
        usage_snapshot_free(api_response_subscription_overview_data->usage);
        api_response_subscription_overview_data->usage = NULL;
    }
    free(api_response_subscription_overview_data);
}

cJSON *api_response_subscription_overview_data_convertToJSON(api_response_subscription_overview_data_t *api_response_subscription_overview_data) {
    cJSON *item = cJSON_CreateObject();

    // api_response_subscription_overview_data->current_period_end
    if(api_response_subscription_overview_data->current_period_end) {
    if(cJSON_AddStringToObject(item, "currentPeriodEnd", api_response_subscription_overview_data->current_period_end) == NULL) {
    goto fail; //Date-Time
    }
    }


    // api_response_subscription_overview_data->features
    if (!api_response_subscription_overview_data->features) {
        goto fail;
    }
    cJSON *features_local_JSON = plan_features_convertToJSON(api_response_subscription_overview_data->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // api_response_subscription_overview_data->is_trialing
    if (!api_response_subscription_overview_data->is_trialing) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isTrialing", *api_response_subscription_overview_data->is_trialing) == NULL) {
    goto fail; //Bool
    }


    // api_response_subscription_overview_data->limits
    if (!api_response_subscription_overview_data->limits) {
        goto fail;
    }
    cJSON *limits_local_JSON = plan_limits_convertToJSON(api_response_subscription_overview_data->limits);
    if(limits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "limits", limits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // api_response_subscription_overview_data->manage_url
    if(api_response_subscription_overview_data->manage_url) {
    if(cJSON_AddStringToObject(item, "manageUrl", api_response_subscription_overview_data->manage_url) == NULL) {
    goto fail; //String
    }
    }


    // api_response_subscription_overview_data->plan
    if (!api_response_subscription_overview_data->plan) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "plan", api_response_subscription_overview_data->plan) == NULL) {
    goto fail; //String
    }


    // api_response_subscription_overview_data->plan_name
    if (!api_response_subscription_overview_data->plan_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "planName", api_response_subscription_overview_data->plan_name) == NULL) {
    goto fail; //String
    }


    // api_response_subscription_overview_data->price_eur
    if (!api_response_subscription_overview_data->price_eur) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "priceEur", *api_response_subscription_overview_data->price_eur) == NULL) {
    goto fail; //Numeric
    }


    // api_response_subscription_overview_data->quantity
    if(api_response_subscription_overview_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *api_response_subscription_overview_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // api_response_subscription_overview_data->status
    if(api_response_subscription_overview_data->status) {
    if(cJSON_AddStringToObject(item, "status", api_response_subscription_overview_data->status) == NULL) {
    goto fail; //String
    }
    }


    // api_response_subscription_overview_data->subscription_id
    if(api_response_subscription_overview_data->subscription_id) {
    if(cJSON_AddStringToObject(item, "subscriptionId", api_response_subscription_overview_data->subscription_id) == NULL) {
    goto fail; //String
    }
    }


    // api_response_subscription_overview_data->trial_ends_at
    if(api_response_subscription_overview_data->trial_ends_at) {
    if(cJSON_AddStringToObject(item, "trialEndsAt", api_response_subscription_overview_data->trial_ends_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // api_response_subscription_overview_data->usage
    if (!api_response_subscription_overview_data->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = usage_snapshot_convertToJSON(api_response_subscription_overview_data->usage);
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

api_response_subscription_overview_data_t *api_response_subscription_overview_data_parseFromJSON(cJSON *api_response_subscription_overview_dataJSON){

    api_response_subscription_overview_data_t *api_response_subscription_overview_data_local_var = NULL;

    char *current_period_end_local_str = NULL;

    // define the local variable for api_response_subscription_overview_data->features
    plan_features_t *features_local_nonprim = NULL;

    // define the local variable for api_response_subscription_overview_data->is_trialing
    int *is_trialing_local_var = NULL;

    // define the local variable for api_response_subscription_overview_data->limits
    plan_limits_t *limits_local_nonprim = NULL;

    char *manage_url_local_str = NULL;

    char *plan_local_str = NULL;

    char *plan_name_local_str = NULL;

    // define the local variable for api_response_subscription_overview_data->price_eur
    double *price_eur_local_var = NULL;

    // define the local variable for api_response_subscription_overview_data->quantity
    int *quantity_local_var = NULL;

    char *status_local_str = NULL;

    char *subscription_id_local_str = NULL;

    char *trial_ends_at_local_str = NULL;

    // define the local variable for api_response_subscription_overview_data->usage
    usage_snapshot_t *usage_local_nonprim = NULL;

    // api_response_subscription_overview_data->current_period_end
    cJSON *current_period_end = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "currentPeriodEnd");
    if (cJSON_IsNull(current_period_end)) {
        current_period_end = NULL;
    }
    if (current_period_end) { 
    if(!cJSON_IsString(current_period_end) && !cJSON_IsNull(current_period_end))
    {
    goto end; //DateTime
    }
    }

    // api_response_subscription_overview_data->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = plan_features_parseFromJSON(features); //nonprimitive

    // api_response_subscription_overview_data->is_trialing
    cJSON *is_trialing = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "isTrialing");
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

    // api_response_subscription_overview_data->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (!limits) {
        goto end;
    }

    
    limits_local_nonprim = plan_limits_parseFromJSON(limits); //nonprimitive

    // api_response_subscription_overview_data->manage_url
    cJSON *manage_url = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "manageUrl");
    if (cJSON_IsNull(manage_url)) {
        manage_url = NULL;
    }
    if (manage_url) { 
    if(!cJSON_IsString(manage_url) && !cJSON_IsNull(manage_url))
    {
    goto end; //String
    }
    }

    // api_response_subscription_overview_data->plan
    cJSON *plan = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "plan");
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

    // api_response_subscription_overview_data->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "planName");
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

    // api_response_subscription_overview_data->price_eur
    cJSON *price_eur = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "priceEur");
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

    // api_response_subscription_overview_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "quantity");
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

    // api_response_subscription_overview_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // api_response_subscription_overview_data->subscription_id
    cJSON *subscription_id = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "subscriptionId");
    if (cJSON_IsNull(subscription_id)) {
        subscription_id = NULL;
    }
    if (subscription_id) { 
    if(!cJSON_IsString(subscription_id) && !cJSON_IsNull(subscription_id))
    {
    goto end; //String
    }
    }

    // api_response_subscription_overview_data->trial_ends_at
    cJSON *trial_ends_at = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "trialEndsAt");
    if (cJSON_IsNull(trial_ends_at)) {
        trial_ends_at = NULL;
    }
    if (trial_ends_at) { 
    if(!cJSON_IsString(trial_ends_at) && !cJSON_IsNull(trial_ends_at))
    {
    goto end; //DateTime
    }
    }

    // api_response_subscription_overview_data->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overview_dataJSON, "usage");
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

    api_response_subscription_overview_data_local_var = api_response_subscription_overview_data_create_internal (
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

    if (!api_response_subscription_overview_data_local_var) {
        goto end;
    }

    return api_response_subscription_overview_data_local_var;
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
