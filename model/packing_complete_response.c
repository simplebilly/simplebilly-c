#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "packing_complete_response.h"



static packing_complete_response_t *packing_complete_response_create_internal(
    char *message,
    char *new_state,
    char *order_number,
    int *success
    ) {
    packing_complete_response_t *packing_complete_response_local_var = malloc(sizeof(packing_complete_response_t));
    if (!packing_complete_response_local_var) {
        return NULL;
    }
    memset(packing_complete_response_local_var, 0, sizeof(packing_complete_response_t));
    packing_complete_response_local_var->_library_owned = 1;
    packing_complete_response_local_var->message = message;
    packing_complete_response_local_var->new_state = new_state;
    packing_complete_response_local_var->order_number = order_number;
    packing_complete_response_local_var->success = success;
    return packing_complete_response_local_var;
}

__attribute__((deprecated)) packing_complete_response_t *packing_complete_response_create(
    char *message,
    char *new_state,
    char *order_number,
    int *success
    ) {
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    packing_complete_response_t *result = packing_complete_response_create_internal (
        message,
        new_state,
        order_number,
        success_copy
        );
    if (!result) {
        free(success_copy);
    }
    return result;
}

void packing_complete_response_free(packing_complete_response_t *packing_complete_response) {
    if(NULL == packing_complete_response){
        return ;
    }
    if(packing_complete_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "packing_complete_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (packing_complete_response->message) {
        free(packing_complete_response->message);
        packing_complete_response->message = NULL;
    }
    if (packing_complete_response->new_state) {
        free(packing_complete_response->new_state);
        packing_complete_response->new_state = NULL;
    }
    if (packing_complete_response->order_number) {
        free(packing_complete_response->order_number);
        packing_complete_response->order_number = NULL;
    }
    if (packing_complete_response->success) {
        free(packing_complete_response->success);
        packing_complete_response->success = NULL;
    }
    free(packing_complete_response);
}

cJSON *packing_complete_response_convertToJSON(packing_complete_response_t *packing_complete_response) {
    cJSON *item = cJSON_CreateObject();

    // packing_complete_response->message
    if (!packing_complete_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", packing_complete_response->message) == NULL) {
    goto fail; //String
    }


    // packing_complete_response->new_state
    if (!packing_complete_response->new_state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "new_state", packing_complete_response->new_state) == NULL) {
    goto fail; //String
    }


    // packing_complete_response->order_number
    if (!packing_complete_response->order_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_number", packing_complete_response->order_number) == NULL) {
    goto fail; //String
    }


    // packing_complete_response->success
    if (!packing_complete_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", *packing_complete_response->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

packing_complete_response_t *packing_complete_response_parseFromJSON(cJSON *packing_complete_responseJSON){

    packing_complete_response_t *packing_complete_response_local_var = NULL;

    char *message_local_str = NULL;

    char *new_state_local_str = NULL;

    char *order_number_local_str = NULL;

    // define the local variable for packing_complete_response->success
    int *success_local_var = NULL;

    // packing_complete_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(packing_complete_responseJSON, "message");
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

    // packing_complete_response->new_state
    cJSON *new_state = cJSON_GetObjectItemCaseSensitive(packing_complete_responseJSON, "new_state");
    if (cJSON_IsNull(new_state)) {
        new_state = NULL;
    }
    if (!new_state) {
        goto end;
    }

    
    if(!cJSON_IsString(new_state))
    {
    goto end; //String
    }

    // packing_complete_response->order_number
    cJSON *order_number = cJSON_GetObjectItemCaseSensitive(packing_complete_responseJSON, "order_number");
    if (cJSON_IsNull(order_number)) {
        order_number = NULL;
    }
    if (!order_number) {
        goto end;
    }

    
    if(!cJSON_IsString(order_number))
    {
    goto end; //String
    }

    // packing_complete_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(packing_complete_responseJSON, "success");
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
    if (new_state && !cJSON_IsNull(new_state)) new_state_local_str = strdup(new_state->valuestring);
    if (order_number && !cJSON_IsNull(order_number)) order_number_local_str = strdup(order_number->valuestring);

    packing_complete_response_local_var = packing_complete_response_create_internal (
        message_local_str,
        new_state_local_str,
        order_number_local_str,
        success_local_var
        );

    if (!packing_complete_response_local_var) {
        goto end;
    }

    return packing_complete_response_local_var;
end:
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (new_state_local_str) {
        free(new_state_local_str);
        new_state_local_str = NULL;
    }
    if (order_number_local_str) {
        free(order_number_local_str);
        order_number_local_str = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    return NULL;

}
