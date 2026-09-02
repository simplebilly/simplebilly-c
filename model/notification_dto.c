#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "notification_dto.h"



static notification_dto_t *notification_dto_create_internal(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    int *sent_via_email,
    char *tenant_id,
    char *title,
    char *user_id
    ) {
    notification_dto_t *notification_dto_local_var = malloc(sizeof(notification_dto_t));
    if (!notification_dto_local_var) {
        return NULL;
    }
    memset(notification_dto_local_var, 0, sizeof(notification_dto_t));
    notification_dto_local_var->_library_owned = 1;
    notification_dto_local_var->created_at = created_at;
    notification_dto_local_var->id = id;
    notification_dto_local_var->is_read = is_read;
    notification_dto_local_var->message = message;
    notification_dto_local_var->sent_via_email = sent_via_email;
    notification_dto_local_var->tenant_id = tenant_id;
    notification_dto_local_var->title = title;
    notification_dto_local_var->user_id = user_id;
    return notification_dto_local_var;
}

__attribute__((deprecated)) notification_dto_t *notification_dto_create(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    int *sent_via_email,
    char *tenant_id,
    char *title,
    char *user_id
    ) {
    int *is_read_copy = NULL;
    if (is_read) {
        is_read_copy = malloc(sizeof(int));
        if (is_read_copy) *is_read_copy = *is_read;
    }
    int *sent_via_email_copy = NULL;
    if (sent_via_email) {
        sent_via_email_copy = malloc(sizeof(int));
        if (sent_via_email_copy) *sent_via_email_copy = *sent_via_email;
    }
    notification_dto_t *result = notification_dto_create_internal (
        created_at,
        id,
        is_read_copy,
        message,
        sent_via_email_copy,
        tenant_id,
        title,
        user_id
        );
    if (!result) {
        free(is_read_copy);
        free(sent_via_email_copy);
    }
    return result;
}

void notification_dto_free(notification_dto_t *notification_dto) {
    if(NULL == notification_dto){
        return ;
    }
    if(notification_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "notification_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (notification_dto->created_at) {
        free(notification_dto->created_at);
        notification_dto->created_at = NULL;
    }
    if (notification_dto->id) {
        free(notification_dto->id);
        notification_dto->id = NULL;
    }
    if (notification_dto->is_read) {
        free(notification_dto->is_read);
        notification_dto->is_read = NULL;
    }
    if (notification_dto->message) {
        free(notification_dto->message);
        notification_dto->message = NULL;
    }
    if (notification_dto->sent_via_email) {
        free(notification_dto->sent_via_email);
        notification_dto->sent_via_email = NULL;
    }
    if (notification_dto->tenant_id) {
        free(notification_dto->tenant_id);
        notification_dto->tenant_id = NULL;
    }
    if (notification_dto->title) {
        free(notification_dto->title);
        notification_dto->title = NULL;
    }
    if (notification_dto->user_id) {
        free(notification_dto->user_id);
        notification_dto->user_id = NULL;
    }
    free(notification_dto);
}

cJSON *notification_dto_convertToJSON(notification_dto_t *notification_dto) {
    cJSON *item = cJSON_CreateObject();

    // notification_dto->created_at
    if (!notification_dto->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created_at", notification_dto->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // notification_dto->id
    if (!notification_dto->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", notification_dto->id) == NULL) {
    goto fail; //String
    }


    // notification_dto->is_read
    if (!notification_dto->is_read) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_read", *notification_dto->is_read) == NULL) {
    goto fail; //Bool
    }


    // notification_dto->message
    if(notification_dto->message) {
    if(cJSON_AddStringToObject(item, "message", notification_dto->message) == NULL) {
    goto fail; //String
    }
    }


    // notification_dto->sent_via_email
    if (!notification_dto->sent_via_email) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "sent_via_email", *notification_dto->sent_via_email) == NULL) {
    goto fail; //Bool
    }


    // notification_dto->tenant_id
    if (!notification_dto->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenant_id", notification_dto->tenant_id) == NULL) {
    goto fail; //String
    }


    // notification_dto->title
    if (!notification_dto->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", notification_dto->title) == NULL) {
    goto fail; //String
    }


    // notification_dto->user_id
    if (!notification_dto->user_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "user_id", notification_dto->user_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

notification_dto_t *notification_dto_parseFromJSON(cJSON *notification_dtoJSON){

    notification_dto_t *notification_dto_local_var = NULL;

    char *created_at_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for notification_dto->is_read
    int *is_read_local_var = NULL;

    char *message_local_str = NULL;

    // define the local variable for notification_dto->sent_via_email
    int *sent_via_email_local_var = NULL;

    char *tenant_id_local_str = NULL;

    char *title_local_str = NULL;

    char *user_id_local_str = NULL;

    // notification_dto->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // notification_dto->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // notification_dto->is_read
    cJSON *is_read = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "is_read");
    if (cJSON_IsNull(is_read)) {
        is_read = NULL;
    }
    if (!is_read) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_read))
    {
    goto end; //Bool
    }
    is_read_local_var = malloc(sizeof(int));
    if(!is_read_local_var)
    {
        goto end;
    }
    *is_read_local_var = is_read->valueint;

    // notification_dto->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // notification_dto->sent_via_email
    cJSON *sent_via_email = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "sent_via_email");
    if (cJSON_IsNull(sent_via_email)) {
        sent_via_email = NULL;
    }
    if (!sent_via_email) {
        goto end;
    }

    
    if(!cJSON_IsBool(sent_via_email))
    {
    goto end; //Bool
    }
    sent_via_email_local_var = malloc(sizeof(int));
    if(!sent_via_email_local_var)
    {
        goto end;
    }
    *sent_via_email_local_var = sent_via_email->valueint;

    // notification_dto->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "tenant_id");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // notification_dto->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // notification_dto->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(notification_dtoJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);

    notification_dto_local_var = notification_dto_create_internal (
        created_at_local_str,
        id_local_str,
        is_read_local_var,
        message_local_str,
        sent_via_email_local_var,
        tenant_id_local_str,
        title_local_str,
        user_id_local_str
        );

    if (!notification_dto_local_var) {
        goto end;
    }

    return notification_dto_local_var;
end:
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (is_read_local_var) {
        free(is_read_local_var);
        is_read_local_var = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (sent_via_email_local_var) {
        free(sent_via_email_local_var);
        sent_via_email_local_var = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (user_id_local_str) {
        free(user_id_local_str);
        user_id_local_str = NULL;
    }
    return NULL;

}
