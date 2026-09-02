#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plan_limits.h"



static plan_limits_t *plan_limits_create_internal(
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    list_t *paid_connectors
    ) {
    plan_limits_t *plan_limits_local_var = malloc(sizeof(plan_limits_t));
    if (!plan_limits_local_var) {
        return NULL;
    }
    memset(plan_limits_local_var, 0, sizeof(plan_limits_t));
    plan_limits_local_var->_library_owned = 1;
    plan_limits_local_var->max_connectors = max_connectors;
    plan_limits_local_var->max_invoices_per_month = max_invoices_per_month;
    plan_limits_local_var->max_users = max_users;
    plan_limits_local_var->metered = metered;
    plan_limits_local_var->paid_connectors = paid_connectors;
    return plan_limits_local_var;
}

__attribute__((deprecated)) plan_limits_t *plan_limits_create(
    int *max_connectors,
    long *max_invoices_per_month,
    int *max_users,
    list_t* metered,
    list_t *paid_connectors
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
    plan_limits_t *result = plan_limits_create_internal (
        max_connectors_copy,
        max_invoices_per_month_copy,
        max_users_copy,
        metered,
        paid_connectors
        );
    if (!result) {
        free(max_connectors_copy);
        free(max_invoices_per_month_copy);
        free(max_users_copy);
    }
    return result;
}

void plan_limits_free(plan_limits_t *plan_limits) {
    if(NULL == plan_limits){
        return ;
    }
    if(plan_limits->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plan_limits_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plan_limits->max_connectors) {
        free(plan_limits->max_connectors);
        plan_limits->max_connectors = NULL;
    }
    if (plan_limits->max_invoices_per_month) {
        free(plan_limits->max_invoices_per_month);
        plan_limits->max_invoices_per_month = NULL;
    }
    if (plan_limits->max_users) {
        free(plan_limits->max_users);
        plan_limits->max_users = NULL;
    }
    if (plan_limits->metered) {
        list_ForEach(listEntry, plan_limits->metered) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(plan_limits->metered);
        plan_limits->metered = NULL;
    }
    if (plan_limits->paid_connectors) {
        list_ForEach(listEntry, plan_limits->paid_connectors) {
            free(listEntry->data);
        }
        list_freeList(plan_limits->paid_connectors);
        plan_limits->paid_connectors = NULL;
    }
    free(plan_limits);
}

cJSON *plan_limits_convertToJSON(plan_limits_t *plan_limits) {
    cJSON *item = cJSON_CreateObject();

    // plan_limits->max_connectors
    if (!plan_limits->max_connectors) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxConnectors", *plan_limits->max_connectors) == NULL) {
    goto fail; //Numeric
    }


    // plan_limits->max_invoices_per_month
    if (!plan_limits->max_invoices_per_month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxInvoicesPerMonth", *plan_limits->max_invoices_per_month) == NULL) {
    goto fail; //Numeric
    }


    // plan_limits->max_users
    if (!plan_limits->max_users) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxUsers", *plan_limits->max_users) == NULL) {
    goto fail; //Numeric
    }


    // plan_limits->metered
    if(plan_limits->metered) {
    cJSON *metered = cJSON_AddObjectToObject(item, "metered");
    if(metered == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = metered;
    listEntry_t *meteredListEntry;
    if (plan_limits->metered) {
    list_ForEach(meteredListEntry, plan_limits->metered) {
        keyValuePair_t *localKeyValue = meteredListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // plan_limits->paid_connectors
    if (!plan_limits->paid_connectors) {
        goto fail;
    }
    cJSON *paid_connectors = cJSON_AddArrayToObject(item, "paidConnectors");
    if(paid_connectors == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *paid_connectorsListEntry;
    list_ForEach(paid_connectorsListEntry, plan_limits->paid_connectors) {
    if(cJSON_AddStringToObject(paid_connectors, "", paid_connectorsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plan_limits_t *plan_limits_parseFromJSON(cJSON *plan_limitsJSON){

    plan_limits_t *plan_limits_local_var = NULL;

    // define the local variable for plan_limits->max_connectors
    int *max_connectors_local_var = NULL;

    // define the local variable for plan_limits->max_invoices_per_month
    long *max_invoices_per_month_local_var = NULL;

    // define the local variable for plan_limits->max_users
    int *max_users_local_var = NULL;

    // define the local map for plan_limits->metered
    list_t *meteredList = NULL;

    // define the local list for plan_limits->paid_connectors
    list_t *paid_connectorsList = NULL;

    // plan_limits->max_connectors
    cJSON *max_connectors = cJSON_GetObjectItemCaseSensitive(plan_limitsJSON, "maxConnectors");
    if (cJSON_IsNull(max_connectors)) {
        max_connectors = NULL;
    }
    if (!max_connectors) {
        goto end;
    }

    
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

    // plan_limits->max_invoices_per_month
    cJSON *max_invoices_per_month = cJSON_GetObjectItemCaseSensitive(plan_limitsJSON, "maxInvoicesPerMonth");
    if (cJSON_IsNull(max_invoices_per_month)) {
        max_invoices_per_month = NULL;
    }
    if (!max_invoices_per_month) {
        goto end;
    }

    
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

    // plan_limits->max_users
    cJSON *max_users = cJSON_GetObjectItemCaseSensitive(plan_limitsJSON, "maxUsers");
    if (cJSON_IsNull(max_users)) {
        max_users = NULL;
    }
    if (!max_users) {
        goto end;
    }

    
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

    // plan_limits->metered
    cJSON *metered = cJSON_GetObjectItemCaseSensitive(plan_limitsJSON, "metered");
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

    // plan_limits->paid_connectors
    cJSON *paid_connectors = cJSON_GetObjectItemCaseSensitive(plan_limitsJSON, "paidConnectors");
    if (cJSON_IsNull(paid_connectors)) {
        paid_connectors = NULL;
    }
    if (!paid_connectors) {
        goto end;
    }

    
    cJSON *paid_connectors_local = NULL;
    if(!cJSON_IsArray(paid_connectors)) {
        goto end;//primitive container
    }
    paid_connectorsList = list_createList();

    cJSON_ArrayForEach(paid_connectors_local, paid_connectors)
    {
        if(!cJSON_IsString(paid_connectors_local))
        {
            goto end;
        }
        list_addElement(paid_connectorsList , strdup(paid_connectors_local->valuestring));
    }



    plan_limits_local_var = plan_limits_create_internal (
        max_connectors_local_var,
        max_invoices_per_month_local_var,
        max_users_local_var,
        metered ? meteredList : NULL,
        paid_connectorsList
        );

    if (!plan_limits_local_var) {
        goto end;
    }

    return plan_limits_local_var;
end:
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
    if (paid_connectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, paid_connectorsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(paid_connectorsList);
        paid_connectorsList = NULL;
    }
    return NULL;

}
