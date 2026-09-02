#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sync_summary.h"



static sync_summary_t *sync_summary_create_internal(
    char *error_message,
    int *items_failed,
    int *items_synced
    ) {
    sync_summary_t *sync_summary_local_var = malloc(sizeof(sync_summary_t));
    if (!sync_summary_local_var) {
        return NULL;
    }
    memset(sync_summary_local_var, 0, sizeof(sync_summary_t));
    sync_summary_local_var->_library_owned = 1;
    sync_summary_local_var->error_message = error_message;
    sync_summary_local_var->items_failed = items_failed;
    sync_summary_local_var->items_synced = items_synced;
    return sync_summary_local_var;
}

__attribute__((deprecated)) sync_summary_t *sync_summary_create(
    char *error_message,
    int *items_failed,
    int *items_synced
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
    sync_summary_t *result = sync_summary_create_internal (
        error_message,
        items_failed_copy,
        items_synced_copy
        );
    if (!result) {
        free(items_failed_copy);
        free(items_synced_copy);
    }
    return result;
}

void sync_summary_free(sync_summary_t *sync_summary) {
    if(NULL == sync_summary){
        return ;
    }
    if(sync_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sync_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sync_summary->error_message) {
        free(sync_summary->error_message);
        sync_summary->error_message = NULL;
    }
    if (sync_summary->items_failed) {
        free(sync_summary->items_failed);
        sync_summary->items_failed = NULL;
    }
    if (sync_summary->items_synced) {
        free(sync_summary->items_synced);
        sync_summary->items_synced = NULL;
    }
    free(sync_summary);
}

cJSON *sync_summary_convertToJSON(sync_summary_t *sync_summary) {
    cJSON *item = cJSON_CreateObject();

    // sync_summary->error_message
    if(sync_summary->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", sync_summary->error_message) == NULL) {
    goto fail; //String
    }
    }


    // sync_summary->items_failed
    if(sync_summary->items_failed) {
    if(cJSON_AddNumberToObject(item, "items_failed", *sync_summary->items_failed) == NULL) {
    goto fail; //Numeric
    }
    }


    // sync_summary->items_synced
    if(sync_summary->items_synced) {
    if(cJSON_AddNumberToObject(item, "items_synced", *sync_summary->items_synced) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sync_summary_t *sync_summary_parseFromJSON(cJSON *sync_summaryJSON){

    sync_summary_t *sync_summary_local_var = NULL;

    char *error_message_local_str = NULL;

    // define the local variable for sync_summary->items_failed
    int *items_failed_local_var = NULL;

    // define the local variable for sync_summary->items_synced
    int *items_synced_local_var = NULL;

    // sync_summary->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(sync_summaryJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }

    // sync_summary->items_failed
    cJSON *items_failed = cJSON_GetObjectItemCaseSensitive(sync_summaryJSON, "items_failed");
    if (cJSON_IsNull(items_failed)) {
        items_failed = NULL;
    }
    if (items_failed) { 
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
    }

    // sync_summary->items_synced
    cJSON *items_synced = cJSON_GetObjectItemCaseSensitive(sync_summaryJSON, "items_synced");
    if (cJSON_IsNull(items_synced)) {
        items_synced = NULL;
    }
    if (items_synced) { 
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
    }


    if (error_message && !cJSON_IsNull(error_message)) error_message_local_str = strdup(error_message->valuestring);

    sync_summary_local_var = sync_summary_create_internal (
        error_message_local_str,
        items_failed_local_var,
        items_synced_local_var
        );

    if (!sync_summary_local_var) {
        goto end;
    }

    return sync_summary_local_var;
end:
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
    return NULL;

}
