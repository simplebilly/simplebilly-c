#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "marketplace_sync_log.h"



static marketplace_sync_log_t *marketplace_sync_log_create_internal(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *platform,
    char *started_at,
    simplebilly_api_sync_log_status__e status,
    simplebilly_api_sync_type__e sync_type
    ) {
    marketplace_sync_log_t *marketplace_sync_log_local_var = malloc(sizeof(marketplace_sync_log_t));
    if (!marketplace_sync_log_local_var) {
        return NULL;
    }
    memset(marketplace_sync_log_local_var, 0, sizeof(marketplace_sync_log_t));
    marketplace_sync_log_local_var->_library_owned = 1;
    marketplace_sync_log_local_var->completed_at = completed_at;
    marketplace_sync_log_local_var->connection_id = connection_id;
    marketplace_sync_log_local_var->error_message = error_message;
    marketplace_sync_log_local_var->items_failed = items_failed;
    marketplace_sync_log_local_var->items_synced = items_synced;
    marketplace_sync_log_local_var->platform = platform;
    marketplace_sync_log_local_var->started_at = started_at;
    marketplace_sync_log_local_var->status = status;
    marketplace_sync_log_local_var->sync_type = sync_type;
    return marketplace_sync_log_local_var;
}

__attribute__((deprecated)) marketplace_sync_log_t *marketplace_sync_log_create(
    char *completed_at,
    char *connection_id,
    char *error_message,
    int *items_failed,
    int *items_synced,
    char *platform,
    char *started_at,
    simplebilly_api_sync_log_status__e status,
    simplebilly_api_sync_type__e sync_type
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
    marketplace_sync_log_t *result = marketplace_sync_log_create_internal (
        completed_at,
        connection_id,
        error_message,
        items_failed_copy,
        items_synced_copy,
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

void marketplace_sync_log_free(marketplace_sync_log_t *marketplace_sync_log) {
    if(NULL == marketplace_sync_log){
        return ;
    }
    if(marketplace_sync_log->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "marketplace_sync_log_free");
        return ;
    }
    listEntry_t *listEntry;
    if (marketplace_sync_log->completed_at) {
        free(marketplace_sync_log->completed_at);
        marketplace_sync_log->completed_at = NULL;
    }
    if (marketplace_sync_log->connection_id) {
        free(marketplace_sync_log->connection_id);
        marketplace_sync_log->connection_id = NULL;
    }
    if (marketplace_sync_log->error_message) {
        free(marketplace_sync_log->error_message);
        marketplace_sync_log->error_message = NULL;
    }
    if (marketplace_sync_log->items_failed) {
        free(marketplace_sync_log->items_failed);
        marketplace_sync_log->items_failed = NULL;
    }
    if (marketplace_sync_log->items_synced) {
        free(marketplace_sync_log->items_synced);
        marketplace_sync_log->items_synced = NULL;
    }
    if (marketplace_sync_log->platform) {
        free(marketplace_sync_log->platform);
        marketplace_sync_log->platform = NULL;
    }
    if (marketplace_sync_log->started_at) {
        free(marketplace_sync_log->started_at);
        marketplace_sync_log->started_at = NULL;
    }
    free(marketplace_sync_log);
}

cJSON *marketplace_sync_log_convertToJSON(marketplace_sync_log_t *marketplace_sync_log) {
    cJSON *item = cJSON_CreateObject();

    // marketplace_sync_log->completed_at
    if(marketplace_sync_log->completed_at) {
    if(cJSON_AddStringToObject(item, "completedAt", marketplace_sync_log->completed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // marketplace_sync_log->connection_id
    if (!marketplace_sync_log->connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "connectionId", marketplace_sync_log->connection_id) == NULL) {
    goto fail; //String
    }


    // marketplace_sync_log->error_message
    if(marketplace_sync_log->error_message) {
    if(cJSON_AddStringToObject(item, "errorMessage", marketplace_sync_log->error_message) == NULL) {
    goto fail; //String
    }
    }


    // marketplace_sync_log->items_failed
    if (!marketplace_sync_log->items_failed) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsFailed", *marketplace_sync_log->items_failed) == NULL) {
    goto fail; //Numeric
    }


    // marketplace_sync_log->items_synced
    if (!marketplace_sync_log->items_synced) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "itemsSynced", *marketplace_sync_log->items_synced) == NULL) {
    goto fail; //Numeric
    }


    // marketplace_sync_log->platform
    if (!marketplace_sync_log->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", marketplace_sync_log->platform) == NULL) {
    goto fail; //String
    }


    // marketplace_sync_log->started_at
    if (!marketplace_sync_log->started_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "startedAt", marketplace_sync_log->started_at) == NULL) {
    goto fail; //Date-Time
    }


    // marketplace_sync_log->status
    if (simplebilly_api_sync_log_status__NULL == marketplace_sync_log->status) {
        goto fail;
    }
    cJSON *status_local_JSON = sync_log_status_convertToJSON(marketplace_sync_log->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // marketplace_sync_log->sync_type
    if (simplebilly_api_sync_type__NULL == marketplace_sync_log->sync_type) {
        goto fail;
    }
    cJSON *sync_type_local_JSON = sync_type_convertToJSON(marketplace_sync_log->sync_type);
    if(sync_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "syncType", sync_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

marketplace_sync_log_t *marketplace_sync_log_parseFromJSON(cJSON *marketplace_sync_logJSON){

    marketplace_sync_log_t *marketplace_sync_log_local_var = NULL;

    char *completed_at_local_str = NULL;

    char *connection_id_local_str = NULL;

    char *error_message_local_str = NULL;

    // define the local variable for marketplace_sync_log->items_failed
    int *items_failed_local_var = NULL;

    // define the local variable for marketplace_sync_log->items_synced
    int *items_synced_local_var = NULL;

    char *platform_local_str = NULL;

    char *started_at_local_str = NULL;

    // define the local variable for marketplace_sync_log->status
    simplebilly_api_sync_log_status__e status_local_nonprim = 0;

    // define the local variable for marketplace_sync_log->sync_type
    simplebilly_api_sync_type__e sync_type_local_nonprim = 0;

    // marketplace_sync_log->completed_at
    cJSON *completed_at = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "completedAt");
    if (cJSON_IsNull(completed_at)) {
        completed_at = NULL;
    }
    if (completed_at) { 
    if(!cJSON_IsString(completed_at) && !cJSON_IsNull(completed_at))
    {
    goto end; //DateTime
    }
    }

    // marketplace_sync_log->connection_id
    cJSON *connection_id = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "connectionId");
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

    // marketplace_sync_log->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "errorMessage");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }

    // marketplace_sync_log->items_failed
    cJSON *items_failed = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "itemsFailed");
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

    // marketplace_sync_log->items_synced
    cJSON *items_synced = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "itemsSynced");
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

    // marketplace_sync_log->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "platform");
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

    // marketplace_sync_log->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "startedAt");
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

    // marketplace_sync_log->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = sync_log_status_parseFromJSON(status); //custom

    // marketplace_sync_log->sync_type
    cJSON *sync_type = cJSON_GetObjectItemCaseSensitive(marketplace_sync_logJSON, "syncType");
    if (cJSON_IsNull(sync_type)) {
        sync_type = NULL;
    }
    if (!sync_type) {
        goto end;
    }

    
    sync_type_local_nonprim = sync_type_parseFromJSON(sync_type); //custom


    if (completed_at && !cJSON_IsNull(completed_at)) completed_at_local_str = strdup(completed_at->valuestring);
    if (connection_id && !cJSON_IsNull(connection_id)) connection_id_local_str = strdup(connection_id->valuestring);
    if (error_message && !cJSON_IsNull(error_message)) error_message_local_str = strdup(error_message->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (started_at && !cJSON_IsNull(started_at)) started_at_local_str = strdup(started_at->valuestring);

    marketplace_sync_log_local_var = marketplace_sync_log_create_internal (
        completed_at_local_str,
        connection_id_local_str,
        error_message_local_str,
        items_failed_local_var,
        items_synced_local_var,
        platform_local_str,
        started_at_local_str,
        status_local_nonprim,
        sync_type_local_nonprim
        );

    if (!marketplace_sync_log_local_var) {
        goto end;
    }

    return marketplace_sync_log_local_var;
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
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (started_at_local_str) {
        free(started_at_local_str);
        started_at_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (sync_type_local_nonprim) {
        sync_type_local_nonprim = 0;
    }
    return NULL;

}
