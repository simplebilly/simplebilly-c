#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "packing_video_response.h"



static packing_video_response_t *packing_video_response_create_internal(
    char *message,
    char *recording_url,
    int *success
    ) {
    packing_video_response_t *packing_video_response_local_var = malloc(sizeof(packing_video_response_t));
    if (!packing_video_response_local_var) {
        return NULL;
    }
    memset(packing_video_response_local_var, 0, sizeof(packing_video_response_t));
    packing_video_response_local_var->_library_owned = 1;
    packing_video_response_local_var->message = message;
    packing_video_response_local_var->recording_url = recording_url;
    packing_video_response_local_var->success = success;
    return packing_video_response_local_var;
}

__attribute__((deprecated)) packing_video_response_t *packing_video_response_create(
    char *message,
    char *recording_url,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    packing_video_response_t *result = packing_video_response_create_internal (
        message,
        recording_url,
        success_copy
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void packing_video_response_free(packing_video_response_t *packing_video_response) {
    if(NULL == packing_video_response){
        return ;
    }
    if(packing_video_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "packing_video_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (packing_video_response->message) {
        free(packing_video_response->message);
        packing_video_response->message = NULL;
    }
    if (packing_video_response->recording_url) {
        free(packing_video_response->recording_url);
        packing_video_response->recording_url = NULL;
    }
    if (packing_video_response->success) {
        free(packing_video_response->success);
        packing_video_response->success = NULL;
    }
    free(packing_video_response);
}

cJSON *packing_video_response_convertToJSON(packing_video_response_t *packing_video_response) {
    cJSON *item = cJSON_CreateObject();

    // packing_video_response->message
    if (!packing_video_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", packing_video_response->message) == NULL) {
    goto fail; //String
    }


    // packing_video_response->recording_url
    if(packing_video_response->recording_url) {
    if(cJSON_AddStringToObject(item, "recording_url", packing_video_response->recording_url) == NULL) {
    goto fail; //String
    }
    }


    // packing_video_response->success
    if (!packing_video_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *packing_video_response->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

packing_video_response_t *packing_video_response_parseFromJSON(cJSON *packing_video_responseJSON){

    packing_video_response_t *packing_video_response_local_var = NULL;

    char *message_local_str = NULL;

    char *recording_url_local_str = NULL;

    // define the local variable for packing_video_response->success
    int *success_local_var = NULL;

    // packing_video_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(packing_video_responseJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // packing_video_response->recording_url
    cJSON *recording_url = cJSON_GetObjectItemCaseSensitive(packing_video_responseJSON, "recording_url");
    if (cJSON_IsNull(recording_url)) {
        recording_url = NULL;
    }
    if (recording_url) { 
    if(!cJSON_IsString(recording_url) && !cJSON_IsNull(recording_url))
    {
    goto end; //String
    }
    }

    // packing_video_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(packing_video_responseJSON, "success");
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


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (recording_url && !cJSON_IsNull(recording_url)) recording_url_local_str = strdup(recording_url->valuestring);

    packing_video_response_local_var = packing_video_response_create_internal (
        message_local_str,
        recording_url_local_str,
        success_local_var
        );

    if (!packing_video_response_local_var) {
        goto end;
    }

    return packing_video_response_local_var;
end:
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (recording_url_local_str) {
        free(recording_url_local_str);
        recording_url_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    return NULL;

}
