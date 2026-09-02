#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "marketplace_webhook_event.h"



static marketplace_webhook_event_t *marketplace_webhook_event_create_internal(
    char *connection_id,
    any_type_t *event_body,
    char *event_type,
    any_type_t *headers,
    char *platform,
    int *processed,
    char *processing_error
    ) {
    marketplace_webhook_event_t *marketplace_webhook_event_local_var = malloc(sizeof(marketplace_webhook_event_t));
    if (!marketplace_webhook_event_local_var) {
        return NULL;
    }
    memset(marketplace_webhook_event_local_var, 0, sizeof(marketplace_webhook_event_t));
    marketplace_webhook_event_local_var->_library_owned = 1;
    marketplace_webhook_event_local_var->connection_id = connection_id;
    marketplace_webhook_event_local_var->event_body = event_body;
    marketplace_webhook_event_local_var->event_type = event_type;
    marketplace_webhook_event_local_var->headers = headers;
    marketplace_webhook_event_local_var->platform = platform;
    marketplace_webhook_event_local_var->processed = processed;
    marketplace_webhook_event_local_var->processing_error = processing_error;
    return marketplace_webhook_event_local_var;
}

__attribute__((deprecated)) marketplace_webhook_event_t *marketplace_webhook_event_create(
    char *connection_id,
    any_type_t *event_body,
    char *event_type,
    any_type_t *headers,
    char *platform,
    int *processed,
    char *processing_error
    ) {
    int *processed_copy = NULL;
    if (processed) {
        processed_copy = malloc(sizeof(int));
        if (processed_copy) *processed_copy = *processed;
    }
    marketplace_webhook_event_t *result = marketplace_webhook_event_create_internal (
        connection_id,
        event_body,
        event_type,
        headers,
        platform,
        processed_copy,
        processing_error
        );
    if (!result) {
        free(processed_copy);
    }
    return result;
}

void marketplace_webhook_event_free(marketplace_webhook_event_t *marketplace_webhook_event) {
    if(NULL == marketplace_webhook_event){
        return ;
    }
    if(marketplace_webhook_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "marketplace_webhook_event_free");
        return ;
    }
    listEntry_t *listEntry;
    if (marketplace_webhook_event->connection_id) {
        free(marketplace_webhook_event->connection_id);
        marketplace_webhook_event->connection_id = NULL;
    }
    if (marketplace_webhook_event->event_body) {
        _free(marketplace_webhook_event->event_body);
        marketplace_webhook_event->event_body = NULL;
    }
    if (marketplace_webhook_event->event_type) {
        free(marketplace_webhook_event->event_type);
        marketplace_webhook_event->event_type = NULL;
    }
    if (marketplace_webhook_event->headers) {
        _free(marketplace_webhook_event->headers);
        marketplace_webhook_event->headers = NULL;
    }
    if (marketplace_webhook_event->platform) {
        free(marketplace_webhook_event->platform);
        marketplace_webhook_event->platform = NULL;
    }
    if (marketplace_webhook_event->processed) {
        free(marketplace_webhook_event->processed);
        marketplace_webhook_event->processed = NULL;
    }
    if (marketplace_webhook_event->processing_error) {
        free(marketplace_webhook_event->processing_error);
        marketplace_webhook_event->processing_error = NULL;
    }
    free(marketplace_webhook_event);
}

cJSON *marketplace_webhook_event_convertToJSON(marketplace_webhook_event_t *marketplace_webhook_event) {
    cJSON *item = cJSON_CreateObject();

    // marketplace_webhook_event->connection_id
    if (!marketplace_webhook_event->connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "connectionId", marketplace_webhook_event->connection_id) == NULL) {
    goto fail; //String
    }


    // marketplace_webhook_event->event_body
    if(marketplace_webhook_event->event_body) {
    cJSON *event_body_local_JSON = _convertToJSON(marketplace_webhook_event->event_body);
    if(event_body_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "eventBody", event_body_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // marketplace_webhook_event->event_type
    if (!marketplace_webhook_event->event_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eventType", marketplace_webhook_event->event_type) == NULL) {
    goto fail; //String
    }


    // marketplace_webhook_event->headers
    if(marketplace_webhook_event->headers) {
    cJSON *headers_local_JSON = _convertToJSON(marketplace_webhook_event->headers);
    if(headers_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "headers", headers_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // marketplace_webhook_event->platform
    if (!marketplace_webhook_event->platform) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "platform", marketplace_webhook_event->platform) == NULL) {
    goto fail; //String
    }


    // marketplace_webhook_event->processed
    if(marketplace_webhook_event->processed) {
    if(cJSON_AddBoolToObject(item, "processed", *marketplace_webhook_event->processed) == NULL) {
    goto fail; //Bool
    }
    }


    // marketplace_webhook_event->processing_error
    if(marketplace_webhook_event->processing_error) {
    if(cJSON_AddStringToObject(item, "processingError", marketplace_webhook_event->processing_error) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

marketplace_webhook_event_t *marketplace_webhook_event_parseFromJSON(cJSON *marketplace_webhook_eventJSON){

    marketplace_webhook_event_t *marketplace_webhook_event_local_var = NULL;

    char *connection_id_local_str = NULL;

    // define the local variable for marketplace_webhook_event->event_body
    _t *event_body_local_nonprim = NULL;

    char *event_type_local_str = NULL;

    // define the local variable for marketplace_webhook_event->headers
    _t *headers_local_nonprim = NULL;

    char *platform_local_str = NULL;

    // define the local variable for marketplace_webhook_event->processed
    int *processed_local_var = NULL;

    char *processing_error_local_str = NULL;

    // marketplace_webhook_event->connection_id
    cJSON *connection_id = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "connectionId");
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

    // marketplace_webhook_event->event_body
    cJSON *event_body = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "eventBody");
    if (cJSON_IsNull(event_body)) {
        event_body = NULL;
    }
    if (event_body) { 
    event_body_local_nonprim = _parseFromJSON(event_body); //custom
    }

    // marketplace_webhook_event->event_type
    cJSON *event_type = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "eventType");
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

    // marketplace_webhook_event->headers
    cJSON *headers = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "headers");
    if (cJSON_IsNull(headers)) {
        headers = NULL;
    }
    if (headers) { 
    headers_local_nonprim = _parseFromJSON(headers); //custom
    }

    // marketplace_webhook_event->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "platform");
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

    // marketplace_webhook_event->processed
    cJSON *processed = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "processed");
    if (cJSON_IsNull(processed)) {
        processed = NULL;
    }
    if (processed) { 
    if(!cJSON_IsBool(processed))
    {
    goto end; //Bool
    }
    processed_local_var = malloc(sizeof(int));
    if(!processed_local_var)
    {
        goto end;
    }
    *processed_local_var = processed->valueint;
    }

    // marketplace_webhook_event->processing_error
    cJSON *processing_error = cJSON_GetObjectItemCaseSensitive(marketplace_webhook_eventJSON, "processingError");
    if (cJSON_IsNull(processing_error)) {
        processing_error = NULL;
    }
    if (processing_error) { 
    if(!cJSON_IsString(processing_error) && !cJSON_IsNull(processing_error))
    {
    goto end; //String
    }
    }


    if (connection_id && !cJSON_IsNull(connection_id)) connection_id_local_str = strdup(connection_id->valuestring);
    if (event_type && !cJSON_IsNull(event_type)) event_type_local_str = strdup(event_type->valuestring);
    if (platform && !cJSON_IsNull(platform)) platform_local_str = strdup(platform->valuestring);
    if (processing_error && !cJSON_IsNull(processing_error)) processing_error_local_str = strdup(processing_error->valuestring);

    marketplace_webhook_event_local_var = marketplace_webhook_event_create_internal (
        connection_id_local_str,
        event_body ? event_body_local_nonprim : NULL,
        event_type_local_str,
        headers ? headers_local_nonprim : NULL,
        platform_local_str,
        processed_local_var,
        processing_error_local_str
        );

    if (!marketplace_webhook_event_local_var) {
        goto end;
    }

    return marketplace_webhook_event_local_var;
end:
    if (connection_id_local_str) {
        free(connection_id_local_str);
        connection_id_local_str = NULL;
    }
    if (event_body_local_nonprim) {
        _free(event_body_local_nonprim);
        event_body_local_nonprim = NULL;
    }
    if (event_type_local_str) {
        free(event_type_local_str);
        event_type_local_str = NULL;
    }
    if (headers_local_nonprim) {
        _free(headers_local_nonprim);
        headers_local_nonprim = NULL;
    }
    if (platform_local_str) {
        free(platform_local_str);
        platform_local_str = NULL;
    }
    if (processed_local_var) {
        free(processed_local_var);
        processed_local_var = NULL;
    }
    if (processing_error_local_str) {
        free(processing_error_local_str);
        processing_error_local_str = NULL;
    }
    return NULL;

}
