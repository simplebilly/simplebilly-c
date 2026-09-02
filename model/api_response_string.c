#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_string.h"



static api_response_string_t *api_response_string_create_internal(
    char *data,
    char *error,
    char *message,
    int *success
    ) {
    api_response_string_t *api_response_string_local_var = malloc(sizeof(api_response_string_t));
    if (!api_response_string_local_var) {
        return NULL;
    }
    memset(api_response_string_local_var, 0, sizeof(api_response_string_t));
    api_response_string_local_var->_library_owned = 1;
    api_response_string_local_var->data = data;
    api_response_string_local_var->error = error;
    api_response_string_local_var->message = message;
    api_response_string_local_var->success = success;
    return api_response_string_local_var;
}

__attribute__((deprecated)) api_response_string_t *api_response_string_create(
    char *data,
    char *error,
    char *message,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    api_response_string_t *result = api_response_string_create_internal (
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

void api_response_string_free(api_response_string_t *api_response_string) {
    if(NULL == api_response_string){
        return ;
    }
    if(api_response_string->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_string_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_string->data) {
        free(api_response_string->data);
        api_response_string->data = NULL;
    }
    if (api_response_string->error) {
        free(api_response_string->error);
        api_response_string->error = NULL;
    }
    if (api_response_string->message) {
        free(api_response_string->message);
        api_response_string->message = NULL;
    }
    if (api_response_string->success) {
        free(api_response_string->success);
        api_response_string->success = NULL;
    }
    free(api_response_string);
}

cJSON *api_response_string_convertToJSON(api_response_string_t *api_response_string) {
    cJSON *item = cJSON_CreateObject();

    // api_response_string->data
    if(api_response_string->data) {
    if(cJSON_AddStringToObject(item, "data", api_response_string->data) == NULL) {
    goto fail; //String
    }
    }


    // api_response_string->error
    if(api_response_string->error) {
    if(cJSON_AddStringToObject(item, "error", api_response_string->error) == NULL) {
    goto fail; //String
    }
    }


    // api_response_string->message
    if(api_response_string->message) {
    if(cJSON_AddStringToObject(item, "message", api_response_string->message) == NULL) {
    goto fail; //String
    }
    }


    // api_response_string->success
    if (!api_response_string->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *api_response_string->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_string_t *api_response_string_parseFromJSON(cJSON *api_response_stringJSON){

    api_response_string_t *api_response_string_local_var = NULL;

    char *data_local_str = NULL;

    char *error_local_str = NULL;

    char *message_local_str = NULL;

    // define the local variable for api_response_string->success
    int *success_local_var = NULL;

    // api_response_string->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(api_response_stringJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    if(!cJSON_IsString(data) && !cJSON_IsNull(data))
    {
    goto end; //String
    }
    }

    // api_response_string->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_response_stringJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // api_response_string->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(api_response_stringJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // api_response_string->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(api_response_stringJSON, "success");
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


    if (data && !cJSON_IsNull(data)) data_local_str = strdup(data->valuestring);
    if (error && !cJSON_IsNull(error)) error_local_str = strdup(error->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);

    api_response_string_local_var = api_response_string_create_internal (
        data_local_str,
        error_local_str,
        message_local_str,
        success_local_var
        );

    if (!api_response_string_local_var) {
        goto end;
    }

    return api_response_string_local_var;
end:
    if (data_local_str) {
        free(data_local_str);
        data_local_str = NULL;
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
