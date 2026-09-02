#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gdpr_notification.h"



static gdpr_notification_t *gdpr_notification_create_internal(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    char *tenant_id,
    char *title
    ) {
    gdpr_notification_t *gdpr_notification_local_var = malloc(sizeof(gdpr_notification_t));
    if (!gdpr_notification_local_var) {
        return NULL;
    }
    memset(gdpr_notification_local_var, 0, sizeof(gdpr_notification_t));
    gdpr_notification_local_var->_library_owned = 1;
    gdpr_notification_local_var->created_at = created_at;
    gdpr_notification_local_var->id = id;
    gdpr_notification_local_var->is_read = is_read;
    gdpr_notification_local_var->message = message;
    gdpr_notification_local_var->tenant_id = tenant_id;
    gdpr_notification_local_var->title = title;
    return gdpr_notification_local_var;
}

__attribute__((deprecated)) gdpr_notification_t *gdpr_notification_create(
    char *created_at,
    char *id,
    int *is_read,
    char *message,
    char *tenant_id,
    char *title
    ) {
    int *is_read_copy = NULL;
    if (is_read) {
        is_read_copy = malloc(sizeof(int));
        if (is_read_copy) *is_read_copy = *is_read;
    }
    gdpr_notification_t *result = gdpr_notification_create_internal (
        created_at,
        id,
        is_read_copy,
        message,
        tenant_id,
        title
        );
    if (!result) {
        free(is_read_copy);
    }
    return result;
}

void gdpr_notification_free(gdpr_notification_t *gdpr_notification) {
    if(NULL == gdpr_notification){
        return ;
    }
    if(gdpr_notification->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gdpr_notification_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gdpr_notification->created_at) {
        free(gdpr_notification->created_at);
        gdpr_notification->created_at = NULL;
    }
    if (gdpr_notification->id) {
        free(gdpr_notification->id);
        gdpr_notification->id = NULL;
    }
    if (gdpr_notification->is_read) {
        free(gdpr_notification->is_read);
        gdpr_notification->is_read = NULL;
    }
    if (gdpr_notification->message) {
        free(gdpr_notification->message);
        gdpr_notification->message = NULL;
    }
    if (gdpr_notification->tenant_id) {
        free(gdpr_notification->tenant_id);
        gdpr_notification->tenant_id = NULL;
    }
    if (gdpr_notification->title) {
        free(gdpr_notification->title);
        gdpr_notification->title = NULL;
    }
    free(gdpr_notification);
}

cJSON *gdpr_notification_convertToJSON(gdpr_notification_t *gdpr_notification) {
    cJSON *item = cJSON_CreateObject();

    // gdpr_notification->created_at
    if (!gdpr_notification->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", gdpr_notification->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // gdpr_notification->id
    if (!gdpr_notification->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gdpr_notification->id) == NULL) {
    goto fail; //String
    }


    // gdpr_notification->is_read
    if (!gdpr_notification->is_read) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isRead", *gdpr_notification->is_read) == NULL) {
    goto fail; //Bool
    }


    // gdpr_notification->message
    if(gdpr_notification->message) {
    if(cJSON_AddStringToObject(item, "message", gdpr_notification->message) == NULL) {
    goto fail; //String
    }
    }


    // gdpr_notification->tenant_id
    if (!gdpr_notification->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", gdpr_notification->tenant_id) == NULL) {
    goto fail; //String
    }


    // gdpr_notification->title
    if (!gdpr_notification->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", gdpr_notification->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gdpr_notification_t *gdpr_notification_parseFromJSON(cJSON *gdpr_notificationJSON){

    gdpr_notification_t *gdpr_notification_local_var = NULL;

    char *created_at_local_str = NULL;

    char *id_local_str = NULL;

    // define the local variable for gdpr_notification->is_read
    int *is_read_local_var = NULL;

    char *message_local_str = NULL;

    char *tenant_id_local_str = NULL;

    char *title_local_str = NULL;

    // gdpr_notification->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "createdAt");
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

    // gdpr_notification->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "id");
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

    // gdpr_notification->is_read
    cJSON *is_read = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "isRead");
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

    // gdpr_notification->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // gdpr_notification->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "tenantId");
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

    // gdpr_notification->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(gdpr_notificationJSON, "title");
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


    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);

    gdpr_notification_local_var = gdpr_notification_create_internal (
        created_at_local_str,
        id_local_str,
        is_read_local_var,
        message_local_str,
        tenant_id_local_str,
        title_local_str
        );

    if (!gdpr_notification_local_var) {
        goto end;
    }

    return gdpr_notification_local_var;
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
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    return NULL;

}
