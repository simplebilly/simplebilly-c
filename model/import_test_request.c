#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "import_test_request.h"



static import_test_request_t *import_test_request_create_internal(
    char *api_key,
    char *provider
    ) {
    import_test_request_t *import_test_request_local_var = malloc(sizeof(import_test_request_t));
    if (!import_test_request_local_var) {
        return NULL;
    }
    memset(import_test_request_local_var, 0, sizeof(import_test_request_t));
    import_test_request_local_var->_library_owned = 1;
    import_test_request_local_var->api_key = api_key;
    import_test_request_local_var->provider = provider;
    return import_test_request_local_var;
}

__attribute__((deprecated)) import_test_request_t *import_test_request_create(
    char *api_key,
    char *provider
    ) {
    import_test_request_t *result = import_test_request_create_internal (
        api_key,
        provider
        );
    if (!result) {
    }
    return result;
}

void import_test_request_free(import_test_request_t *import_test_request) {
    if(NULL == import_test_request){
        return ;
    }
    if(import_test_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "import_test_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (import_test_request->api_key) {
        free(import_test_request->api_key);
        import_test_request->api_key = NULL;
    }
    if (import_test_request->provider) {
        free(import_test_request->provider);
        import_test_request->provider = NULL;
    }
    free(import_test_request);
}

cJSON *import_test_request_convertToJSON(import_test_request_t *import_test_request) {
    cJSON *item = cJSON_CreateObject();

    // import_test_request->api_key
    if (!import_test_request->api_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "apiKey", import_test_request->api_key) == NULL) {
    goto fail; //String
    }


    // import_test_request->provider
    if (!import_test_request->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", import_test_request->provider) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

import_test_request_t *import_test_request_parseFromJSON(cJSON *import_test_requestJSON){

    import_test_request_t *import_test_request_local_var = NULL;

    char *api_key_local_str = NULL;

    char *provider_local_str = NULL;

    // import_test_request->api_key
    cJSON *api_key = cJSON_GetObjectItemCaseSensitive(import_test_requestJSON, "apiKey");
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

    // import_test_request->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(import_test_requestJSON, "provider");
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


    if (api_key && !cJSON_IsNull(api_key)) api_key_local_str = strdup(api_key->valuestring);
    if (provider && !cJSON_IsNull(provider)) provider_local_str = strdup(provider->valuestring);

    import_test_request_local_var = import_test_request_create_internal (
        api_key_local_str,
        provider_local_str
        );

    if (!import_test_request_local_var) {
        goto end;
    }

    return import_test_request_local_var;
end:
    if (api_key_local_str) {
        free(api_key_local_str);
        api_key_local_str = NULL;
    }
    if (provider_local_str) {
        free(provider_local_str);
        provider_local_str = NULL;
    }
    return NULL;

}
