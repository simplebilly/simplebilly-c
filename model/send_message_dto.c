#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_message_dto.h"



static send_message_dto_t *send_message_dto_create_internal(
    char *body,
    int *is_internal
    ) {
    send_message_dto_t *send_message_dto_local_var = malloc(sizeof(send_message_dto_t));
    if (!send_message_dto_local_var) {
        return NULL;
    }
    memset(send_message_dto_local_var, 0, sizeof(send_message_dto_t));
    send_message_dto_local_var->_library_owned = 1;
    send_message_dto_local_var->body = body;
    send_message_dto_local_var->is_internal = is_internal;
    return send_message_dto_local_var;
}

__attribute__((deprecated)) send_message_dto_t *send_message_dto_create(
    char *body,
    int *is_internal
    ) {
    int *is_internal_copy = NULL;
    if (is_internal) {
        is_internal_copy = malloc(sizeof(int));
        if (is_internal_copy) *is_internal_copy = *is_internal;
    }
    send_message_dto_t *result = send_message_dto_create_internal (
        body,
        is_internal_copy
        );
    if (!result) {
        free(is_internal_copy);
    }
    return result;
}

void send_message_dto_free(send_message_dto_t *send_message_dto) {
    if(NULL == send_message_dto){
        return ;
    }
    if(send_message_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_message_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_message_dto->body) {
        free(send_message_dto->body);
        send_message_dto->body = NULL;
    }
    if (send_message_dto->is_internal) {
        free(send_message_dto->is_internal);
        send_message_dto->is_internal = NULL;
    }
    free(send_message_dto);
}

cJSON *send_message_dto_convertToJSON(send_message_dto_t *send_message_dto) {
    cJSON *item = cJSON_CreateObject();

    // send_message_dto->body
    if (!send_message_dto->body) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "body", send_message_dto->body) == NULL) {
    goto fail; //String
    }


    // send_message_dto->is_internal
    if(send_message_dto->is_internal) {
    if(cJSON_AddBoolToObject(item, "is_internal", *send_message_dto->is_internal) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_message_dto_t *send_message_dto_parseFromJSON(cJSON *send_message_dtoJSON){

    send_message_dto_t *send_message_dto_local_var = NULL;

    char *body_local_str = NULL;

    // define the local variable for send_message_dto->is_internal
    int *is_internal_local_var = NULL;

    // send_message_dto->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(send_message_dtoJSON, "body");
    if (cJSON_IsNull(body)) {
        body = NULL;
    }
    if (!body) {
        goto end;
    }

    
    if(!cJSON_IsString(body))
    {
    goto end; //String
    }

    // send_message_dto->is_internal
    cJSON *is_internal = cJSON_GetObjectItemCaseSensitive(send_message_dtoJSON, "is_internal");
    if (cJSON_IsNull(is_internal)) {
        is_internal = NULL;
    }
    if (is_internal) { 
    if(!cJSON_IsBool(is_internal))
    {
    goto end; //Bool
    }
    is_internal_local_var = malloc(sizeof(int));
    if(!is_internal_local_var)
    {
        goto end;
    }
    *is_internal_local_var = is_internal->valueint;
    }


    if (body && !cJSON_IsNull(body)) body_local_str = strdup(body->valuestring);

    send_message_dto_local_var = send_message_dto_create_internal (
        body_local_str,
        is_internal_local_var
        );

    if (!send_message_dto_local_var) {
        goto end;
    }

    return send_message_dto_local_var;
end:
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (is_internal_local_var) {
        free(is_internal_local_var);
        is_internal_local_var = NULL;
    }
    return NULL;

}
