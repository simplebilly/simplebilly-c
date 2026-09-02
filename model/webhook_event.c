#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "webhook_event.h"



static webhook_event_t *webhook_event_create_internal(
    int *attempts,
    char *channel,
    webhook_direction_t *direction,
    char *event_type,
    char *last_error,
    any_type_t *payload,
    webhook_event_status_t *status
    ) {
    webhook_event_t *webhook_event_local_var = malloc(sizeof(webhook_event_t));
    if (!webhook_event_local_var) {
        return NULL;
    }
    memset(webhook_event_local_var, 0, sizeof(webhook_event_t));
    webhook_event_local_var->_library_owned = 1;
    webhook_event_local_var->attempts = attempts;
    webhook_event_local_var->channel = channel;
    webhook_event_local_var->direction = direction;
    webhook_event_local_var->event_type = event_type;
    webhook_event_local_var->last_error = last_error;
    webhook_event_local_var->payload = payload;
    webhook_event_local_var->status = status;
    return webhook_event_local_var;
}

__attribute__((deprecated)) webhook_event_t *webhook_event_create(
    int *attempts,
    char *channel,
    webhook_direction_t *direction,
    char *event_type,
    char *last_error,
    any_type_t *payload,
    webhook_event_status_t *status
    ) {
    int *attempts_copy = NULL;
    if (attempts) {
        attempts_copy = malloc(sizeof(int));
        if (attempts_copy) *attempts_copy = *attempts;
    }
    webhook_event_t *result = webhook_event_create_internal (
        attempts_copy,
        channel,
        direction,
        event_type,
        last_error,
        payload,
        status
        );
    if (!result) {
        free(attempts_copy);
    }
    return result;
}

void webhook_event_free(webhook_event_t *webhook_event) {
    if(NULL == webhook_event){
        return ;
    }
    if(webhook_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "webhook_event_free");
        return ;
    }
    listEntry_t *listEntry;
    if (webhook_event->attempts) {
        free(webhook_event->attempts);
        webhook_event->attempts = NULL;
    }
    if (webhook_event->channel) {
        free(webhook_event->channel);
        webhook_event->channel = NULL;
    }
    if (webhook_event->direction) {
        webhook_direction_free(webhook_event->direction);
        webhook_event->direction = NULL;
    }
    if (webhook_event->event_type) {
        free(webhook_event->event_type);
        webhook_event->event_type = NULL;
    }
    if (webhook_event->last_error) {
        free(webhook_event->last_error);
        webhook_event->last_error = NULL;
    }
    if (webhook_event->payload) {
        _free(webhook_event->payload);
        webhook_event->payload = NULL;
    }
    if (webhook_event->status) {
        webhook_event_status_free(webhook_event->status);
        webhook_event->status = NULL;
    }
    free(webhook_event);
}

cJSON *webhook_event_convertToJSON(webhook_event_t *webhook_event) {
    cJSON *item = cJSON_CreateObject();

    // webhook_event->attempts
    if(webhook_event->attempts) {
    if(cJSON_AddNumberToObject(item, "attempts", *webhook_event->attempts) == NULL) {
    goto fail; //Numeric
    }
    }


    // webhook_event->channel
    if(webhook_event->channel) {
    if(cJSON_AddStringToObject(item, "channel", webhook_event->channel) == NULL) {
    goto fail; //String
    }
    }


    // webhook_event->direction
    if (!webhook_event->direction) {
        goto fail;
    }
    cJSON *direction_local_JSON = webhook_direction_convertToJSON(webhook_event->direction);
    if(direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "direction", direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // webhook_event->event_type
    if (!webhook_event->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eventType", webhook_event->event_type) == NULL) {
    goto fail; //String
    }


    // webhook_event->last_error
    if(webhook_event->last_error) {
    if(cJSON_AddStringToObject(item, "lastError", webhook_event->last_error) == NULL) {
    goto fail; //String
    }
    }


    // webhook_event->payload
    if(webhook_event->payload) {
    cJSON *payload_local_JSON = _convertToJSON(webhook_event->payload);
    if(payload_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "payload", payload_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // webhook_event->status
    if(webhook_event->status) {
    cJSON *status_local_JSON = webhook_event_status_convertToJSON(webhook_event->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

webhook_event_t *webhook_event_parseFromJSON(cJSON *webhook_eventJSON){

    webhook_event_t *webhook_event_local_var = NULL;

    // define the local variable for webhook_event->attempts
    int *attempts_local_var = NULL;

    char *channel_local_str = NULL;

    // define the local variable for webhook_event->direction
    webhook_direction_t *direction_local_nonprim = NULL;

    char *event_type_local_str = NULL;

    char *last_error_local_str = NULL;

    // define the local variable for webhook_event->payload
    _t *payload_local_nonprim = NULL;

    // define the local variable for webhook_event->status
    webhook_event_status_t *status_local_nonprim = NULL;

    // webhook_event->attempts
    cJSON *attempts = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "attempts");
    if (cJSON_IsNull(attempts)) {
        attempts = NULL;
    }
    if (attempts) { 
    if(!cJSON_IsNumber(attempts))
    {
    goto end; //Numeric
    }
    attempts_local_var = malloc(sizeof(int));
    if(!attempts_local_var)
    {
        goto end;
    }
    *attempts_local_var = attempts->valuedouble;
    }

    // webhook_event->channel
    cJSON *channel = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "channel");
    if (cJSON_IsNull(channel)) {
        channel = NULL;
    }
    if (channel) { 
    if(!cJSON_IsString(channel) && !cJSON_IsNull(channel))
    {
    goto end; //String
    }
    }

    // webhook_event->direction
    cJSON *direction = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "direction");
    if (cJSON_IsNull(direction)) {
        direction = NULL;
    }
    if (!direction) {
        goto end;
    }

    
    direction_local_nonprim = webhook_direction_parseFromJSON(direction); //custom

    // webhook_event->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "eventType");
    if (cJSON_IsNull(event_type)) {
        event_type = NULL;
    }
    if (!event_type) {
        goto end;
    }

    
    if(!cJSON_IsString(event_type))
    {
    goto end; //String
    }

    // webhook_event->last_error
    cJSON *last_error = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "lastError");
    if (cJSON_IsNull(last_error)) {
        last_error = NULL;
    }
    if (last_error) { 
    if(!cJSON_IsString(last_error) && !cJSON_IsNull(last_error))
    {
    goto end; //String
    }
    }

    // webhook_event->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (payload) { 
    payload_local_nonprim = _parseFromJSON(payload); //custom
    }

    // webhook_event->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(webhook_eventJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = webhook_event_status_parseFromJSON(status); //custom
    }


    if (channel && !cJSON_IsNull(channel)) channel_local_str = strdup(channel->valuestring);
    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (last_error && !cJSON_IsNull(last_error)) last_error_local_str = strdup(last_error->valuestring);

    webhook_event_local_var = webhook_event_create_internal (
        attempts_local_var,
        channel_local_str,
        direction_local_nonprim,
        event_type_local_str,
        last_error_local_str,
        payload ? payload_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    if (!webhook_event_local_var) {
        goto end;
    }

    return webhook_event_local_var;
end:
    if (attempts_local_var) {
        free(attempts_local_var);
        attempts_local_var = NULL;
    }
    if (channel_local_str) {
        free(channel_local_str);
        channel_local_str = NULL;
    }
    if (direction_local_nonprim) {
        webhook_direction_free(direction_local_nonprim);
        direction_local_nonprim = NULL;
    }
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (last_error_local_str) {
        free(last_error_local_str);
        last_error_local_str = NULL;
    }
    if (payload_local_nonprim) {
        _free(payload_local_nonprim);
        payload_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        webhook_event_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
