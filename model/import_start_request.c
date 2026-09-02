#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "import_start_request.h"



static import_start_request_t *import_start_request_create_internal(
    char *api_key,
    char *provider,
    list_t *years
    ) {
    import_start_request_t *import_start_request_local_var = malloc(sizeof(import_start_request_t));
    if (!import_start_request_local_var) {
        return NULL;
    }
    memset(import_start_request_local_var, 0, sizeof(import_start_request_t));
    import_start_request_local_var->_library_owned = 1;
    import_start_request_local_var->api_key = api_key;
    import_start_request_local_var->provider = provider;
    import_start_request_local_var->years = years;
    return import_start_request_local_var;
}

__attribute__((deprecated)) import_start_request_t *import_start_request_create(
    char *api_key,
    char *provider,
    list_t *years
    ) {
    import_start_request_t *result = import_start_request_create_internal (
        api_key,
        provider,
        years
        );
    if (!result) {
    }
    return result;
}

void import_start_request_free(import_start_request_t *import_start_request) {
    if(NULL == import_start_request){
        return ;
    }
    if(import_start_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "import_start_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (import_start_request->api_key) {
        free(import_start_request->api_key);
        import_start_request->api_key = NULL;
    }
    if (import_start_request->provider) {
        free(import_start_request->provider);
        import_start_request->provider = NULL;
    }
    if (import_start_request->years) {
        list_ForEach(listEntry, import_start_request->years) {
            free(listEntry->data);
        }
        list_freeList(import_start_request->years);
        import_start_request->years = NULL;
    }
    free(import_start_request);
}

cJSON *import_start_request_convertToJSON(import_start_request_t *import_start_request) {
    cJSON *item = cJSON_CreateObject();

    // import_start_request->api_key
    if (!import_start_request->api_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "apiKey", import_start_request->api_key) == NULL) {
    goto fail; //String
    }


    // import_start_request->provider
    if (!import_start_request->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", import_start_request->provider) == NULL) {
    goto fail; //String
    }


    // import_start_request->years
    if (!import_start_request->years) {
        goto fail;
    }
    cJSON *years = cJSON_AddArrayToObject(item, "years");
    if(years == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *yearsListEntry;
    list_ForEach(yearsListEntry, import_start_request->years) {
    if(cJSON_AddNumberToObject(years, "", *(double *)yearsListEntry->data) == NULL)
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

import_start_request_t *import_start_request_parseFromJSON(cJSON *import_start_requestJSON){

    import_start_request_t *import_start_request_local_var = NULL;

    char *api_key_local_str = NULL;

    char *provider_local_str = NULL;

    // define the local list for import_start_request->years
    list_t *yearsList = NULL;

    // import_start_request->api_key
    cJSON *api_key = cJSON_GetObjectItemCaseSensitive(import_start_requestJSON, "apiKey");
    if (cJSON_IsNull(api_key)) {
        api_key = NULL;
    }
    if (!api_key) {
        goto end;
    }

    
    if(!cJSON_IsString(api_key))
    {
    goto end; //String
    }

    // import_start_request->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(import_start_requestJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    
    if(!cJSON_IsString(provider))
    {
    goto end; //String
    }

    // import_start_request->years
    cJSON *years = cJSON_GetObjectItemCaseSensitive(import_start_requestJSON, "years");
    if (cJSON_IsNull(years)) {
        years = NULL;
    }
    if (!years) {
        goto end;
    }

    
    cJSON *years_local = NULL;
    if(!cJSON_IsArray(years)) {
        goto end;//primitive container
    }
    yearsList = list_createList();

    cJSON_ArrayForEach(years_local, years)
    {
        if(!cJSON_IsNumber(years_local))
        {
            goto end;
        }
        double *years_local_value = calloc(1, sizeof(double));
        if(!years_local_value)
        {
            goto end;
        }
        *years_local_value = years_local->valuedouble;
        list_addElement(yearsList , years_local_value);
    }


    if (api_key && !cJSON_IsNull(api_key)) api_key_local_str = strdup(api_key->valuestring);
    if (provider && !cJSON_IsNull(provider)) provider_local_str = strdup(provider->valuestring);

    import_start_request_local_var = import_start_request_create_internal (
        api_key_local_str,
        provider_local_str,
        yearsList
        );

    if (!import_start_request_local_var) {
        goto end;
    }

    return import_start_request_local_var;
end:
    if (api_key_local_str) {
        free(api_key_local_str);
        api_key_local_str = NULL;
    }
    if (provider_local_str) {
        free(provider_local_str);
        provider_local_str = NULL;
    }
    if (yearsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, yearsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(yearsList);
        yearsList = NULL;
    }
    return NULL;

}
