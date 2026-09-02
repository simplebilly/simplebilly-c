#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "quota_override.h"



static quota_override_t *quota_override_create_internal(
    quota_override_features_t *features,
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    char *plan
    ) {
    quota_override_t *quota_override_local_var = malloc(sizeof(quota_override_t));
    if (!quota_override_local_var) {
        return NULL;
    }
    memset(quota_override_local_var, 0, sizeof(quota_override_t));
    quota_override_local_var->_library_owned = 1;
    quota_override_local_var->features = features;
    quota_override_local_var->max_connectors = max_connectors;
    quota_override_local_var->max_invoices_per_month = max_invoices_per_month;
    quota_override_local_var->max_users = max_users;
    quota_override_local_var->metered = metered;
    quota_override_local_var->plan = plan;
    return quota_override_local_var;
}

__attribute__((deprecated)) quota_override_t *quota_override_create(
    quota_override_features_t *features,
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    char *plan
    ) {
    int *max_connectors_copy = NULL;
    if (max_connectors) {
        max_connectors_copy = malloc(sizeof(int));
        if (max_connectors_copy) *max_connectors_copy = *max_connectors;
    }
    long *max_invoices_per_month_copy = NULL;
    if (max_invoices_per_month) {
        max_invoices_per_month_copy = malloc(sizeof(long));
        if (max_invoices_per_month_copy) *max_invoices_per_month_copy = *max_invoices_per_month;
    }
    int *max_users_copy = NULL;
    if (max_users) {
        max_users_copy = malloc(sizeof(int));
        if (max_users_copy) *max_users_copy = *max_users;
    }
    quota_override_t *result = quota_override_create_internal (
        features,
        max_connectors_copy,
        max_invoices_per_month_copy,
        max_users_copy,
        metered,
        plan
        );
    if (!result) {
        free(max_connectors_copy);
        free(max_invoices_per_month_copy);
        free(max_users_copy);
    }
    return result;
}

void quota_override_free(quota_override_t *quota_override) {
    if(NULL == quota_override){
        return ;
    }
    if(quota_override->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "quota_override_free");
        return ;
    }
    listEntry_t *listEntry;
    if (quota_override->features) {
        quota_override_features_free(quota_override->features);
        quota_override->features = NULL;
    }
    if (quota_override->max_connectors) {
        free(quota_override->max_connectors);
        quota_override->max_connectors = NULL;
    }
    if (quota_override->max_invoices_per_month) {
        free(quota_override->max_invoices_per_month);
        quota_override->max_invoices_per_month = NULL;
    }
    if (quota_override->max_users) {
        free(quota_override->max_users);
        quota_override->max_users = NULL;
    }
    if (quota_override->metered) {
        list_ForEach(listEntry, quota_override->metered) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(quota_override->metered);
        quota_override->metered = NULL;
    }
    if (quota_override->plan) {
        free(quota_override->plan);
        quota_override->plan = NULL;
    }
    free(quota_override);
}

cJSON *quota_override_convertToJSON(quota_override_t *quota_override) {
    cJSON *item = cJSON_CreateObject();

    // quota_override->features
    if(quota_override->features) {
    cJSON *features_local_JSON = quota_override_features_convertToJSON(quota_override->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // quota_override->max_connectors
    if(quota_override->max_connectors) {
    if(cJSON_AddNumberToObject(item, "max_connectors", *quota_override->max_connectors) == NULL) {
    goto fail; //Numeric
    }
    }


    // quota_override->max_invoices_per_month
    if(quota_override->max_invoices_per_month) {
    if(cJSON_AddNumberToObject(item, "max_invoices_per_month", *quota_override->max_invoices_per_month) == NULL) {
    goto fail; //Numeric
    }
    }


    // quota_override->max_users
    if(quota_override->max_users) {
    if(cJSON_AddNumberToObject(item, "max_users", *quota_override->max_users) == NULL) {
    goto fail; //Numeric
    }
    }


    // quota_override->metered
    if(quota_override->metered) {
    cJSON *metered = cJSON_AddObjectToObject(item, "metered");
    if(metered == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = metered;
    listEntry_t *meteredListEntry;
    if (quota_override->metered) {
    list_ForEach(meteredListEntry, quota_override->metered) {
        keyValuePair_t *localKeyValue = meteredListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // quota_override->plan
    if(quota_override->plan) {
    if(cJSON_AddStringToObject(item, "plan", quota_override->plan) == NULL) {
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

quota_override_t *quota_override_parseFromJSON(cJSON *quota_overrideJSON){

    quota_override_t *quota_override_local_var = NULL;

    // define the local variable for quota_override->features
    quota_override_features_t *features_local_nonprim = NULL;

    // define the local variable for quota_override->max_connectors
    int *max_connectors_local_var = NULL;

    // define the local variable for quota_override->max_invoices_per_month
    long *max_invoices_per_month_local_var = NULL;

    // define the local variable for quota_override->max_users
    int *max_users_local_var = NULL;

    // define the local map for quota_override->metered
    list_t *meteredList = NULL;

    char *plan_local_str = NULL;

    // quota_override->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (features) { 
    features_local_nonprim = quota_override_features_parseFromJSON(features); //nonprimitive
    }

    // quota_override->max_connectors
    cJSON *max_connectors = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "max_connectors");
    if (cJSON_IsNull(max_connectors)) {
        max_connectors = NULL;
    }
    if (max_connectors) { 
    if(!cJSON_IsNumber(max_connectors))
    {
    goto end; //Numeric
    }
    max_connectors_local_var = malloc(sizeof(int));
    if(!max_connectors_local_var)
    {
        goto end;
    }
    *max_connectors_local_var = max_connectors->valuedouble;
    }

    // quota_override->max_invoices_per_month
    cJSON *max_invoices_per_month = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "max_invoices_per_month");
    if (cJSON_IsNull(max_invoices_per_month)) {
        max_invoices_per_month = NULL;
    }
    if (max_invoices_per_month) { 
    if(!cJSON_IsNumber(max_invoices_per_month))
    {
    goto end; //Numeric
    }
    max_invoices_per_month_local_var = malloc(sizeof(long));
    if(!max_invoices_per_month_local_var)
    {
        goto end;
    }
    *max_invoices_per_month_local_var = max_invoices_per_month->valuedouble;
    }

    // quota_override->max_users
    cJSON *max_users = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "max_users");
    if (cJSON_IsNull(max_users)) {
        max_users = NULL;
    }
    if (max_users) { 
    if(!cJSON_IsNumber(max_users))
    {
    goto end; //Numeric
    }
    max_users_local_var = malloc(sizeof(int));
    if(!max_users_local_var)
    {
        goto end;
    }
    *max_users_local_var = max_users->valuedouble;
    }

    // quota_override->metered
    cJSON *metered = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "metered");
    if (cJSON_IsNull(metered)) {
        metered = NULL;
    }
    if (metered) { 
    cJSON *metered_local_map = NULL;
    if(!cJSON_IsObject(metered) && !cJSON_IsNull(metered))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(metered))
    {
        meteredList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(metered_local_map, metered)
        {
            cJSON *localMapObject = metered_local_map;
            if(!cJSON_IsNumber(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),&localMapObject->valuedouble );
            list_addElement(meteredList , localMapKeyPair);
        }
    }
    }

    // quota_override->plan
    cJSON *plan = cJSON_GetObjectItemCaseSensitive(quota_overrideJSON, "plan");
    if (cJSON_IsNull(plan)) {
        plan = NULL;
    }
    if (plan) { 
    if(!cJSON_IsString(plan) && !cJSON_IsNull(plan))
    {
    goto end; //String
    }
    }


    if (plan && !cJSON_IsNull(plan)) plan_local_str = strdup(plan->valuestring);

    quota_override_local_var = quota_override_create_internal (
        features ? features_local_nonprim : NULL,
        max_connectors_local_var,
        max_invoices_per_month_local_var,
        max_users_local_var,
        metered ? meteredList : NULL,
        plan_local_str
        );

    if (!quota_override_local_var) {
        goto end;
    }

    return quota_override_local_var;
end:
    if (features_local_nonprim) {
        quota_override_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    if (max_connectors_local_var) {
        free(max_connectors_local_var);
        max_connectors_local_var = NULL;
    }
    if (max_invoices_per_month_local_var) {
        free(max_invoices_per_month_local_var);
        max_invoices_per_month_local_var = NULL;
    }
    if (max_users_local_var) {
        free(max_users_local_var);
        max_users_local_var = NULL;
    }
    if (meteredList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, meteredList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(meteredList);
        meteredList = NULL;
    }
    if (plan_local_str) {
        free(plan_local_str);
        plan_local_str = NULL;
    }
    return NULL;

}
