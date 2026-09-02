#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_response_vec_team.h"



static api_response_vec_team_t *api_response_vec_team_create_internal(
    list_t *data,
    char *error,
    char *message,
    int *success
    ) {
    api_response_vec_team_t *api_response_vec_team_local_var = malloc(sizeof(api_response_vec_team_t));
    if (!api_response_vec_team_local_var) {
        return NULL;
    }
    memset(api_response_vec_team_local_var, 0, sizeof(api_response_vec_team_t));
    api_response_vec_team_local_var->_library_owned = 1;
    api_response_vec_team_local_var->data = data;
    api_response_vec_team_local_var->error = error;
    api_response_vec_team_local_var->message = message;
    api_response_vec_team_local_var->success = success;
    return api_response_vec_team_local_var;
}

__attribute__((deprecated)) api_response_vec_team_t *api_response_vec_team_create(
    list_t *data,
    char *error,
    char *message,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    api_response_vec_team_t *result = api_response_vec_team_create_internal (
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

void api_response_vec_team_free(api_response_vec_team_t *api_response_vec_team) {
    if(NULL == api_response_vec_team){
        return ;
    }
    if(api_response_vec_team->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_response_vec_team_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_response_vec_team->data) {
        list_ForEach(listEntry, api_response_vec_team->data) {
            api_response_team_data_free(listEntry->data);
        }
        list_freeList(api_response_vec_team->data);
        api_response_vec_team->data = NULL;
    }
    if (api_response_vec_team->error) {
        free(api_response_vec_team->error);
        api_response_vec_team->error = NULL;
    }
    if (api_response_vec_team->message) {
        free(api_response_vec_team->message);
        api_response_vec_team->message = NULL;
    }
    if (api_response_vec_team->success) {
        free(api_response_vec_team->success);
        api_response_vec_team->success = NULL;
    }
    free(api_response_vec_team);
}

cJSON *api_response_vec_team_convertToJSON(api_response_vec_team_t *api_response_vec_team) {
    cJSON *item = cJSON_CreateObject();

    // api_response_vec_team->data
    if(api_response_vec_team->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (api_response_vec_team->data) {
    list_ForEach(dataListEntry, api_response_vec_team->data) {
    cJSON *itemLocal = api_response_team_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // api_response_vec_team->error
    if(api_response_vec_team->error) {
    if(cJSON_AddStringToObject(item, "error", api_response_vec_team->error) == NULL) {
    goto fail; //String
    }
    }


    // api_response_vec_team->message
    if(api_response_vec_team->message) {
    if(cJSON_AddStringToObject(item, "message", api_response_vec_team->message) == NULL) {
    goto fail; //String
    }
    }


    // api_response_vec_team->success
    if (!api_response_vec_team->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *api_response_vec_team->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_response_vec_team_t *api_response_vec_team_parseFromJSON(cJSON *api_response_vec_teamJSON){

    api_response_vec_team_t *api_response_vec_team_local_var = NULL;

    // define the local list for api_response_vec_team->data
    list_t *dataList = NULL;

    char *error_local_str = NULL;

    char *message_local_str = NULL;

    // define the local variable for api_response_vec_team->success
    int *success_local_var = NULL;

    // api_response_vec_team->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(api_response_vec_teamJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_createList();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        api_response_team_data_t *dataItem = api_response_team_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // api_response_vec_team->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_response_vec_teamJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // api_response_vec_team->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(api_response_vec_teamJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // api_response_vec_team->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(api_response_vec_teamJSON, "success");
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

    api_response_vec_team_local_var = api_response_vec_team_create_internal (
        data ? dataList : NULL,
        error_local_str,
        message_local_str,
        success_local_var
        );

    if (!api_response_vec_team_local_var) {
        goto end;
    }

    return api_response_vec_team_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            api_response_team_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
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
