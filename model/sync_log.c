#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_log.h"



static sync_log_t *sync_log_create_internal(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *log_id,
    char *platform,
    char *started_at,
    char *status,
    char *sync_type
    ) {
    sync_log_t *sync_log_local_var = malloc(sizeof(sync_log_t));
    if (!sync_log_local_var) {
        return NULL;
    }
    memset(sync_log_local_var, 0, sizeof(sync_log_t));
    sync_log_local_var->_library_owned = 1;
    sync_log_local_var->completed_at = completed_at;
    sync_log_local_var->connection_id = connection_id;
    sync_log_local_var->error_message = error_message;
    sync_log_local_var->items_failed = items_failed;
    sync_log_local_var->items_synced = items_synced;
    sync_log_local_var->log_id = log_id;
    sync_log_local_var->platform = platform;
    sync_log_local_var->started_at = started_at;
    sync_log_local_var->status = status;
    sync_log_local_var->sync_type = sync_type;
    return sync_log_local_var;
}

__attribute__((deprecated)) sync_log_t *sync_log_create(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *log_id,
    char *platform,
    char *started_at,
    char *status,
    char *sync_type
    ) {
    int *items_failed_copy = NULL;
    if (items_failed) {
        items_failed_copy = malloc(sizeof(int));
        if (items_failed_copy) *items_failed_copy = *items_failed;
    }
    int *items_synced_copy = NULL;
    if (items_synced) {
        items_synced_copy = malloc(sizeof(int));
        if (items_synced_copy) *items_synced_copy = *items_synced;
    }
    sync_log_t *result = sync_log_create_internal (
        completed_at,
        connection_id,
        error_message,
        items_failed_copy,
        items_synced_copy,
        log_id,
        platform,
        started_at,
        status,
        sync_type
        );
    if (!result) {
        free(items_failed_copy);
        free(items_synced_copy);
    }
    return result;
}

void sync_log_free(sync_log_t *sync_log) {
    if(NULL == sync_log){
        return ;
    }
    if(sync_log->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sync_log_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sync_log->completed_at) {
        free(sync_log->completed_at);
        sync_log->completed_at = NULL;
    }
    if (sync_log->connection_id) {
        free(sync_log->connection_id);
        sync_log->connection_id = NULL;
    }
    if (sync_log->error_message) {
        free(sync_log->error_message);
        sync_log->error_message = NULL;
    }
    if (sync_log->items_failed) {
        free(sync_log->items_failed);
        sync_log->items_failed = NULL;
    }
    if (sync_log->items_synced) {
        free(sync_log->items_synced);
        sync_log->items_synced = NULL;
    }
    if (sync_log->log_id) {
        free(sync_log->log_id);
        sync_log->log_id = NULL;
    }
    if (sync_log->platform) {
        free(sync_log->platform);
        sync_log->platform = NULL;
    }
    if (sync_log->started_at) {
        free(sync_log->started_at);
        sync_log->started_at = NULL;
    }
    if (sync_log->status) {
        free(sync_log->status);
        sync_log->status = NULL;
    }
    if (sync_log->sync_type) {
        free(sync_log->sync_type);
        sync_log->sync_type = NULL;
    }
    free(sync_log);
}

cJSON *sync_log_convertToJSON(sync_log_t *sync_log) {
    cJSON *item = cJSON_CreateObject();

    // sync_log->completed_at
    if(sync_log->completed_at) {
    if(cJSON_AddStringToObject(item, "completed_at", sync_log->completed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // sync_log->connection_id
    if (!sync_log->connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "connection_id", sync_log->connection_id) == NULL) {
    goto fail; //String
    }


    // sync_log->error_message
    if(sync_log->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", sync_log->error_message) == NULL) {
    goto fail; //String
    }
    }


    // sync_log->items_failed
    if (!sync_log->items_failed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "items_failed", *sync_log->items_failed) == NULL) {
    goto fail; //Numeric
    }


    // sync_log->items_synced
    if (!sync_log->items_synced) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "items_synced", *sync_log->items_synced) == NULL) {
    goto fail; //Numeric
    }


    // sync_log->log_id
    if (!sync_log->log_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "log_id", sync_log->log_id) == NULL) {
    goto fail; //String
    }


    // sync_log->platform
    if (!sync_log->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", sync_log->platform) == NULL) {
    goto fail; //String
    }


    // sync_log->started_at
    if (!sync_log->started_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "started_at", sync_log->started_at) == NULL) {
    goto fail; //Date-Time
    }


    // sync_log->status
    if (!sync_log->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", sync_log->status) == NULL) {
    goto fail; //String
    }


    // sync_log->sync_type
    if (!sync_log->sync_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sync_type", sync_log->sync_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sync_log_t *sync_log_parseFromJSON(cJSON *sync_logJSON){

    sync_log_t *sync_log_local_var = NULL;

    char *completed_at_local_str = NULL;

    char *connection_id_local_str = NULL;

    char *error_message_local_str = NULL;

    // define the local variable for sync_log->items_failed
    int *items_failed_local_var = NULL;

    // define the local variable for sync_log->items_synced
    int *items_synced_local_var = NULL;

    char *log_id_local_str = NULL;

    char *platform_local_str = NULL;

    char *started_at_local_str = NULL;

    char *status_local_str = NULL;

    char *sync_type_local_str = NULL;

    // sync_log->completed_at
    cJSON *completed_at = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "completed_at");
    if (cJSON_IsNull(completed_at)) {
        completed_at = NULL;
    }
    if (completed_at) { 
    if(!cJSON_IsString(completed_at) && !cJSON_IsNull(completed_at))
    {
    goto end; //DateTime
    }
    }

    // sync_log->connection_id
    cJSON *connection_id = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "connection_id");
    if (cJSON_IsNull(connection_id)) {
        connection_id = NULL;
    }
    if (!connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(connection_id))
    {
    goto end; //String
    }

    // sync_log->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }

    // sync_log->items_failed
    cJSON *items_failed = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "items_failed");
    if (cJSON_IsNull(items_failed)) {
        items_failed = NULL;
    }
    if (!items_failed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_failed))
    {
    goto end; //Numeric
    }
    items_failed_local_var = malloc(sizeof(int));
    if(!items_failed_local_var)
    {
        goto end;
    }
    *items_failed_local_var = items_failed->valuedouble;

    // sync_log->items_synced
    cJSON *items_synced = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "items_synced");
    if (cJSON_IsNull(items_synced)) {
        items_synced = NULL;
    }
    if (!items_synced) {
        goto end;
    }

    
    if(!cJSON_IsNumber(items_synced))
    {
    goto end; //Numeric
    }
    items_synced_local_var = malloc(sizeof(int));
    if(!items_synced_local_var)
    {
        goto end;
    }
    *items_synced_local_var = items_synced->valuedouble;

    // sync_log->log_id
    cJSON *log_id = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "log_id");
    if (cJSON_IsNull(log_id)) {
        log_id = NULL;
    }
    if (!log_id) {
        goto end;
    }

    
    if(!cJSON_IsString(log_id))
    {
    goto end; //String
    }

    // sync_log->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }

    // sync_log->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "started_at");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (!started_at) {
        goto end;
    }

    
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }

    // sync_log->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // sync_log->sync_type
    cJSON *sync_type = cJSON_GetObjectItemCaseSensitive(sync_logJSON, "sync_type");
    if (cJSON_IsNull(sync_type)) {
        sync_type = NULL;
    }
    if (!sync_type) {
        goto end;
    }

    
    if(!cJSON_IsString(sync_type))
    {
    goto end; //String
    }


    if (completed_at && !cJSON_IsNull(completed_at)) completed_at_local_str = strdup(completed_at->valuestring);
    if (connection_id && !cJSON_IsNull(connection_id)) connection_id_local_str = strdup(connection_id->valuestring);
    if (error_message && !cJSON_IsNull(error_message)) error_message_local_str = strdup(error_message->valuestring);
    if (log_id && !cJSON_IsNull(log_id)) log_id_local_str = strdup(log_id->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (started_at && !cJSON_IsNull(started_at)) started_at_local_str = strdup(started_at->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (sync_type && !cJSON_IsNull(sync_type)) sync_type_local_str = strdup(sync_type->valuestring);

    sync_log_local_var = sync_log_create_internal (
        completed_at_local_str,
        connection_id_local_str,
        error_message_local_str,
        items_failed_local_var,
        items_synced_local_var,
        log_id_local_str,
        platform_local_str,
        started_at_local_str,
        status_local_str,
        sync_type_local_str
        );

    if (!sync_log_local_var) {
        goto end;
    }

    return sync_log_local_var;
end:
    if (completed_at_local_str) {
        free(completed_at_local_str);
        completed_at_local_str = NULL;
    }
    if (connection_id_local_str) {
        free(connection_id_local_str);
        connection_id_local_str = NULL;
    }
    if (error_message_local_str) {
        free(error_message_local_str);
        error_message_local_str = NULL;
    }
    if (items_failed_local_var) {
        free(items_failed_local_var);
        items_failed_local_var = NULL;
    }
    if (items_synced_local_var) {
        free(items_synced_local_var);
        items_synced_local_var = NULL;
    }
    if (log_id_local_str) {
        free(log_id_local_str);
        log_id_local_str = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (started_at_local_str) {
        free(started_at_local_str);
        started_at_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (sync_type_local_str) {
        free(sync_type_local_str);
        sync_type_local_str = NULL;
    }
    return NULL;

}
