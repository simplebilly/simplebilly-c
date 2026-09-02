#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "provider_info.h"



static provider_info_t *provider_info_create_internal(
    char *display_name,
    char *name,
    int *requires_api_key,
    list_t *services,
    int *supports_label_creation,
    int *supports_rate_estimation,
    int *supports_tracking
    ) {
    provider_info_t *provider_info_local_var = malloc(sizeof(provider_info_t));
    if (!provider_info_local_var) {
        return NULL;
    }
    memset(provider_info_local_var, 0, sizeof(provider_info_t));
    provider_info_local_var->_library_owned = 1;
    provider_info_local_var->display_name = display_name;
    provider_info_local_var->name = name;
    provider_info_local_var->requires_api_key = requires_api_key;
    provider_info_local_var->services = services;
    provider_info_local_var->supports_label_creation = supports_label_creation;
    provider_info_local_var->supports_rate_estimation = supports_rate_estimation;
    provider_info_local_var->supports_tracking = supports_tracking;
    return provider_info_local_var;
}

__attribute__((deprecated)) provider_info_t *provider_info_create(
    char *display_name,
    char *name,
    int *requires_api_key,
    list_t *services,
    int *supports_label_creation,
    int *supports_rate_estimation,
    int *supports_tracking
    ) {
    int *requires_api_key_copy = NULL;
    if (requires_api_key) {
        requires_api_key_copy = malloc(sizeof(int));
        if (requires_api_key_copy) *requires_api_key_copy = *requires_api_key;
    }
    int *supports_label_creation_copy = NULL;
    if (supports_label_creation) {
        supports_label_creation_copy = malloc(sizeof(int));
        if (supports_label_creation_copy) *supports_label_creation_copy = *supports_label_creation;
    }
    int *supports_rate_estimation_copy = NULL;
    if (supports_rate_estimation) {
        supports_rate_estimation_copy = malloc(sizeof(int));
        if (supports_rate_estimation_copy) *supports_rate_estimation_copy = *supports_rate_estimation;
    }
    int *supports_tracking_copy = NULL;
    if (supports_tracking) {
        supports_tracking_copy = malloc(sizeof(int));
        if (supports_tracking_copy) *supports_tracking_copy = *supports_tracking;
    }
    provider_info_t *result = provider_info_create_internal (
        display_name,
        name,
        requires_api_key_copy,
        services,
        supports_label_creation_copy,
        supports_rate_estimation_copy,
        supports_tracking_copy
        );
    if (!result) {
        free(requires_api_key_copy);
        free(supports_label_creation_copy);
        free(supports_rate_estimation_copy);
        free(supports_tracking_copy);
    }
    return result;
}

void provider_info_free(provider_info_t *provider_info) {
    if(NULL == provider_info){
        return ;
    }
    if(provider_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "provider_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (provider_info->display_name) {
        free(provider_info->display_name);
        provider_info->display_name = NULL;
    }
    if (provider_info->name) {
        free(provider_info->name);
        provider_info->name = NULL;
    }
    if (provider_info->requires_api_key) {
        free(provider_info->requires_api_key);
        provider_info->requires_api_key = NULL;
    }
    if (provider_info->services) {
        list_ForEach(listEntry, provider_info->services) {
            free(listEntry->data);
        }
        list_freeList(provider_info->services);
        provider_info->services = NULL;
    }
    if (provider_info->supports_label_creation) {
        free(provider_info->supports_label_creation);
        provider_info->supports_label_creation = NULL;
    }
    if (provider_info->supports_rate_estimation) {
        free(provider_info->supports_rate_estimation);
        provider_info->supports_rate_estimation = NULL;
    }
    if (provider_info->supports_tracking) {
        free(provider_info->supports_tracking);
        provider_info->supports_tracking = NULL;
    }
    free(provider_info);
}

cJSON *provider_info_convertToJSON(provider_info_t *provider_info) {
    cJSON *item = cJSON_CreateObject();

    // provider_info->display_name
    if (!provider_info->display_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "display_name", provider_info->display_name) == NULL) {
    goto fail; //String
    }


    // provider_info->name
    if (!provider_info->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", provider_info->name) == NULL) {
    goto fail; //String
    }


    // provider_info->requires_api_key
    if (!provider_info->requires_api_key) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "requires_api_key", *provider_info->requires_api_key) == NULL) {
    goto fail; //Bool
    }


    // provider_info->services
    if (!provider_info->services) {
        goto fail;
    }
    cJSON *services = cJSON_AddArrayToObject(item, "services");
    if(services == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *servicesListEntry;
    list_ForEach(servicesListEntry, provider_info->services) {
    if(cJSON_AddStringToObject(services, "", servicesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // provider_info->supports_label_creation
    if (!provider_info->supports_label_creation) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_label_creation", *provider_info->supports_label_creation) == NULL) {
    goto fail; //Bool
    }


    // provider_info->supports_rate_estimation
    if (!provider_info->supports_rate_estimation) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_rate_estimation", *provider_info->supports_rate_estimation) == NULL) {
    goto fail; //Bool
    }


    // provider_info->supports_tracking
    if (!provider_info->supports_tracking) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supports_tracking", *provider_info->supports_tracking) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

provider_info_t *provider_info_parseFromJSON(cJSON *provider_infoJSON){

    provider_info_t *provider_info_local_var = NULL;

    char *display_name_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for provider_info->requires_api_key
    int *requires_api_key_local_var = NULL;

    // define the local list for provider_info->services
    list_t *servicesList = NULL;

    // define the local variable for provider_info->supports_label_creation
    int *supports_label_creation_local_var = NULL;

    // define the local variable for provider_info->supports_rate_estimation
    int *supports_rate_estimation_local_var = NULL;

    // define the local variable for provider_info->supports_tracking
    int *supports_tracking_local_var = NULL;

    // provider_info->display_name
    cJSON *display_name = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "display_name");
    if (cJSON_IsNull(display_name)) {
        display_name = NULL;
    }
    if (!display_name) {
        goto end;
    }

    
    if(!cJSON_IsString(display_name))
    {
    goto end; //String
    }

    // provider_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "name");
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

    // provider_info->requires_api_key
    cJSON *requires_api_key = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "requires_api_key");
    if (cJSON_IsNull(requires_api_key)) {
        requires_api_key = NULL;
    }
    if (!requires_api_key) {
        goto end;
    }

    
    if(!cJSON_IsBool(requires_api_key))
    {
    goto end; //Bool
    }
    requires_api_key_local_var = malloc(sizeof(int));
    if(!requires_api_key_local_var)
    {
        goto end;
    }
    *requires_api_key_local_var = requires_api_key->valueint;

    // provider_info->services
    cJSON *services = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "services");
    if (cJSON_IsNull(services)) {
        services = NULL;
    }
    if (!services) {
        goto end;
    }

    
    cJSON *services_local = NULL;
    if(!cJSON_IsArray(services)) {
        goto end;//primitive container
    }
    servicesList = list_createList();

    cJSON_ArrayForEach(services_local, services)
    {
        if(!cJSON_IsString(services_local))
        {
            goto end;
        }
        list_addElement(servicesList , strdup(services_local->valuestring));
    }

    // provider_info->supports_label_creation
    cJSON *supports_label_creation = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "supports_label_creation");
    if (cJSON_IsNull(supports_label_creation)) {
        supports_label_creation = NULL;
    }
    if (!supports_label_creation) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_label_creation))
    {
    goto end; //Bool
    }
    supports_label_creation_local_var = malloc(sizeof(int));
    if(!supports_label_creation_local_var)
    {
        goto end;
    }
    *supports_label_creation_local_var = supports_label_creation->valueint;

    // provider_info->supports_rate_estimation
    cJSON *supports_rate_estimation = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "supports_rate_estimation");
    if (cJSON_IsNull(supports_rate_estimation)) {
        supports_rate_estimation = NULL;
    }
    if (!supports_rate_estimation) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_rate_estimation))
    {
    goto end; //Bool
    }
    supports_rate_estimation_local_var = malloc(sizeof(int));
    if(!supports_rate_estimation_local_var)
    {
        goto end;
    }
    *supports_rate_estimation_local_var = supports_rate_estimation->valueint;

    // provider_info->supports_tracking
    cJSON *supports_tracking = cJSON_GetObjectItemCaseSensitive(provider_infoJSON, "supports_tracking");
    if (cJSON_IsNull(supports_tracking)) {
        supports_tracking = NULL;
    }
    if (!supports_tracking) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_tracking))
    {
    goto end; //Bool
    }
    supports_tracking_local_var = malloc(sizeof(int));
    if(!supports_tracking_local_var)
    {
        goto end;
    }
    *supports_tracking_local_var = supports_tracking->valueint;


    if (display_name && !cJSON_IsNull(display_name)) display_name_local_str = strdup(display_name->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    provider_info_local_var = provider_info_create_internal (
        display_name_local_str,
        name_local_str,
        requires_api_key_local_var,
        servicesList,
        supports_label_creation_local_var,
        supports_rate_estimation_local_var,
        supports_tracking_local_var
        );

    if (!provider_info_local_var) {
        goto end;
    }

    return provider_info_local_var;
end:
    if (display_name_local_str) {
        free(display_name_local_str);
        display_name_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (requires_api_key_local_var) {
        free(requires_api_key_local_var);
        requires_api_key_local_var = NULL;
    }
    if (servicesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, servicesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(servicesList);
        servicesList = NULL;
    }
    if (supports_label_creation_local_var) {
        free(supports_label_creation_local_var);
        supports_label_creation_local_var = NULL;
    }
    if (supports_rate_estimation_local_var) {
        free(supports_rate_estimation_local_var);
        supports_rate_estimation_local_var = NULL;
    }
    if (supports_tracking_local_var) {
        free(supports_tracking_local_var);
        supports_tracking_local_var = NULL;
    }
    return NULL;

}
