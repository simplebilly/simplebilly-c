#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_subscription_overview.h"



static api_response_subscription_overview_t *api_response_subscription_overview_create_internal(
    api_response_subscription_overview_data_t *data,
    char *error,
    char *message,
    int *success
    ) {
    api_response_subscription_overview_t *api_response_subscription_overview_local_var = malloc(sizeof(api_response_subscription_overview_t));
    if (!api_response_subscription_overview_local_var) {
        return NULL;
    }
    memset(api_response_subscription_overview_local_var, 0, sizeof(api_response_subscription_overview_t));
    api_response_subscription_overview_local_var->_library_owned = 1;
    api_response_subscription_overview_local_var->data = data;
    api_response_subscription_overview_local_var->error = error;
    api_response_subscription_overview_local_var->message = message;
    api_response_subscription_overview_local_var->success = success;
    return api_response_subscription_overview_local_var;
}

__attribute__((deprecated)) api_response_subscription_overview_t *api_response_subscription_overview_create(
    api_response_subscription_overview_data_t *data,
    char *error,
    char *message,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    api_response_subscription_overview_t *result = api_response_subscription_overview_create_internal (
        data,
        error,
        message,
        success_copy
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void api_response_subscription_overview_free(api_response_subscription_overview_t *api_response_subscription_overview) {
    if(NULL == api_response_subscription_overview){
        return ;
    }
    if(api_response_subscription_overview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_subscription_overview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_subscription_overview->data) {
        api_response_subscription_overview_data_free(api_response_subscription_overview->data);
        api_response_subscription_overview->data = NULL;
    }
    if (api_response_subscription_overview->error) {
        free(api_response_subscription_overview->error);
        api_response_subscription_overview->error = NULL;
    }
    if (api_response_subscription_overview->message) {
        free(api_response_subscription_overview->message);
        api_response_subscription_overview->message = NULL;
    }
    if (api_response_subscription_overview->success) {
        free(api_response_subscription_overview->success);
        api_response_subscription_overview->success = NULL;
    }
    free(api_response_subscription_overview);
}

cJSON *api_response_subscription_overview_convertToJSON(api_response_subscription_overview_t *api_response_subscription_overview) {
    cJSON *item = cJSON_CreateObject();

    // api_response_subscription_overview->data
    if(api_response_subscription_overview->data) {
    cJSON *data_local_JSON = api_response_subscription_overview_data_convertToJSON(api_response_subscription_overview->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // api_response_subscription_overview->error
    if(api_response_subscription_overview->error) {
    if(cJSON_AddStringToObject(item, "error", api_response_subscription_overview->error) == NULL) {
    goto fail; //String
    }
    }


    // api_response_subscription_overview->message
    if(api_response_subscription_overview->message) {
    if(cJSON_AddStringToObject(item, "message", api_response_subscription_overview->message) == NULL) {
    goto fail; //String
    }
    }


    // api_response_subscription_overview->success
    if (!api_response_subscription_overview->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *api_response_subscription_overview->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_subscription_overview_t *api_response_subscription_overview_parseFromJSON(cJSON *api_response_subscription_overviewJSON){

    api_response_subscription_overview_t *api_response_subscription_overview_local_var = NULL;

    // define the local variable for api_response_subscription_overview->data
    api_response_subscription_overview_data_t *data_local_nonprim = NULL;

    char *error_local_str = NULL;

    char *message_local_str = NULL;

    // define the local variable for api_response_subscription_overview->success
    int *success_local_var = NULL;

    // api_response_subscription_overview->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overviewJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = api_response_subscription_overview_data_parseFromJSON(data); //nonprimitive
    }

    // api_response_subscription_overview->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overviewJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // api_response_subscription_overview->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overviewJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // api_response_subscription_overview->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(api_response_subscription_overviewJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }
    success_local_var = malloc(sizeof(int));
    if(!success_local_var)
    {
        goto end;
    }
    *success_local_var = success->valueint;


    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);

    api_response_subscription_overview_local_var = api_response_subscription_overview_create_internal (
        data ? data_local_nonprim : NULL,
        error_local_str,
        message_local_str,
        success_local_var
        );

    if (!api_response_subscription_overview_local_var) {
        goto end;
    }

    return api_response_subscription_overview_local_var;
end:
    if (data_local_nonprim) {
        api_response_subscription_overview_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (error_local_str) {
        free(error_local_str);
        error_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    return NULL;

}
