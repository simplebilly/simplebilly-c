#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "import_test_response.h"



static import_test_response_t *import_test_response_create_internal(
    char *error,
    int *ok
    ) {
    import_test_response_t *import_test_response_local_var = malloc(sizeof(import_test_response_t));
    if (!import_test_response_local_var) {
        return NULL;
    }
    memset(import_test_response_local_var, 0, sizeof(import_test_response_t));
    import_test_response_local_var->_library_owned = 1;
    import_test_response_local_var->error = error;
    import_test_response_local_var->ok = ok;
    return import_test_response_local_var;
}

__attribute__((deprecated)) import_test_response_t *import_test_response_create(
    char *error,
    int *ok
    ) {
    int *ok_copy = NULL;
    if (ok) {
        ok_copy = malloc(sizeof(int));
        if (ok_copy) *ok_copy = *ok;
    }
    import_test_response_t *result = import_test_response_create_internal (
        error,
        ok_copy
        );
    if (!result) {
        free(ok_copy);
    }
    return result;
}

void import_test_response_free(import_test_response_t *import_test_response) {
    if(NULL == import_test_response){
        return ;
    }
    if(import_test_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "import_test_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (import_test_response->error) {
        free(import_test_response->error);
        import_test_response->error = NULL;
    }
    if (import_test_response->ok) {
        free(import_test_response->ok);
        import_test_response->ok = NULL;
    }
    free(import_test_response);
}

cJSON *import_test_response_convertToJSON(import_test_response_t *import_test_response) {
    cJSON *item = cJSON_CreateObject();

    // import_test_response->error
    if(import_test_response->error) {
    if(cJSON_AddStringToObject(item, "error", import_test_response->error) == NULL) {
    goto fail; //String
    }
    }


    // import_test_response->ok
    if (!import_test_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", *import_test_response->ok) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

import_test_response_t *import_test_response_parseFromJSON(cJSON *import_test_responseJSON){

    import_test_response_t *import_test_response_local_var = NULL;

    char *error_local_str = NULL;

    // define the local variable for import_test_response->ok
    int *ok_local_var = NULL;

    // import_test_response->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(import_test_responseJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // import_test_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(import_test_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }
    ok_local_var = malloc(sizeof(int));
    if(!ok_local_var)
    {
        goto end;
    }
    *ok_local_var = ok->valueint;


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);

    import_test_response_local_var = import_test_response_create_internal (
        error_local_str,
        ok_local_var
        );

    if (!import_test_response_local_var) {
        goto end;
    }

    return import_test_response_local_var;
end:
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
    }
    if (ok_local_var) {
        free(ok_local_var);
        ok_local_var = NULL;
    }
    return NULL;

}
