#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ticket_message.h"



static ticket_message_t *ticket_message_create_internal(
    char *author_email,
    char *author_name,
    char *body,
    char *body_html,
    char *channel_id,
    char *created_at,
    simplebilly_api_message_direction__e direction,
    char *external_id,
    int *is_internal,
    simplebilly_api_message_type__e message_type,
    any_type_t *metadata,
    char *tenant_id,
    char *ticket_id
    ) {
    ticket_message_t *ticket_message_local_var = malloc(sizeof(ticket_message_t));
    if (!ticket_message_local_var) {
        return NULL;
    }
    memset(ticket_message_local_var, 0, sizeof(ticket_message_t));
    ticket_message_local_var->_library_owned = 1;
    ticket_message_local_var->author_email = author_email;
    ticket_message_local_var->author_name = author_name;
    ticket_message_local_var->body = body;
    ticket_message_local_var->body_html = body_html;
    ticket_message_local_var->channel_id = channel_id;
    ticket_message_local_var->created_at = created_at;
    ticket_message_local_var->direction = direction;
    ticket_message_local_var->external_id = external_id;
    ticket_message_local_var->is_internal = is_internal;
    ticket_message_local_var->message_type = message_type;
    ticket_message_local_var->metadata = metadata;
    ticket_message_local_var->tenant_id = tenant_id;
    ticket_message_local_var->ticket_id = ticket_id;
    return ticket_message_local_var;
}

__attribute__((deprecated)) ticket_message_t *ticket_message_create(
    char *author_email,
    char *author_name,
    char *body,
    char *body_html,
    char *channel_id,
    char *created_at,
    simplebilly_api_message_direction__e direction,
    char *external_id,
    int *is_internal,
    simplebilly_api_message_type__e message_type,
    any_type_t *metadata,
    char *tenant_id,
    char *ticket_id
    ) {
    int *is_internal_copy = NULL;
    if (is_internal) {
        is_internal_copy = malloc(sizeof(int));
        if (is_internal_copy) *is_internal_copy = *is_internal;
    }
    ticket_message_t *result = ticket_message_create_internal (
        author_email,
        author_name,
        body,
        body_html,
        channel_id,
        created_at,
        direction,
        external_id,
        is_internal_copy,
        message_type,
        metadata,
        tenant_id,
        ticket_id
        );
    if (!result) {
        free(is_internal_copy);
    }
    return result;
}

void ticket_message_free(ticket_message_t *ticket_message) {
    if(NULL == ticket_message){
        return ;
    }
    if(ticket_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ticket_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ticket_message->author_email) {
        free(ticket_message->author_email);
        ticket_message->author_email = NULL;
    }
    if (ticket_message->author_name) {
        free(ticket_message->author_name);
        ticket_message->author_name = NULL;
    }
    if (ticket_message->body) {
        free(ticket_message->body);
        ticket_message->body = NULL;
    }
    if (ticket_message->body_html) {
        free(ticket_message->body_html);
        ticket_message->body_html = NULL;
    }
    if (ticket_message->channel_id) {
        free(ticket_message->channel_id);
        ticket_message->channel_id = NULL;
    }
    if (ticket_message->created_at) {
        free(ticket_message->created_at);
        ticket_message->created_at = NULL;
    }
    if (ticket_message->external_id) {
        free(ticket_message->external_id);
        ticket_message->external_id = NULL;
    }
    if (ticket_message->is_internal) {
        free(ticket_message->is_internal);
        ticket_message->is_internal = NULL;
    }
    if (ticket_message->metadata) {
        _free(ticket_message->metadata);
        ticket_message->metadata = NULL;
    }
    if (ticket_message->tenant_id) {
        free(ticket_message->tenant_id);
        ticket_message->tenant_id = NULL;
    }
    if (ticket_message->ticket_id) {
        free(ticket_message->ticket_id);
        ticket_message->ticket_id = NULL;
    }
    free(ticket_message);
}

cJSON *ticket_message_convertToJSON(ticket_message_t *ticket_message) {
    cJSON *item = cJSON_CreateObject();

    // ticket_message->author_email
    if(ticket_message->author_email) {
    if(cJSON_AddStringToObject(item, "authorEmail", ticket_message->author_email) == NULL) {
    goto fail; //String
    }
    }


    // ticket_message->author_name
    if(ticket_message->author_name) {
    if(cJSON_AddStringToObject(item, "authorName", ticket_message->author_name) == NULL) {
    goto fail; //String
    }
    }


    // ticket_message->body
    if (!ticket_message->body) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "body", ticket_message->body) == NULL) {
    goto fail; //String
    }


    // ticket_message->body_html
    if(ticket_message->body_html) {
    if(cJSON_AddStringToObject(item, "bodyHtml", ticket_message->body_html) == NULL) {
    goto fail; //String
    }
    }


    // ticket_message->channel_id
    if(ticket_message->channel_id) {
    if(cJSON_AddStringToObject(item, "channelId", ticket_message->channel_id) == NULL) {
    goto fail; //String
    }
    }


    // ticket_message->created_at
    if (!ticket_message->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", ticket_message->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // ticket_message->direction
    if (simplebilly_api_message_direction__NULL == ticket_message->direction) {
        goto fail;
    }
    cJSON *direction_local_JSON = message_direction_convertToJSON(ticket_message->direction);
    if(direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "direction", direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // ticket_message->external_id
    if(ticket_message->external_id) {
    if(cJSON_AddStringToObject(item, "externalId", ticket_message->external_id) == NULL) {
    goto fail; //String
    }
    }


    // ticket_message->is_internal
    if (!ticket_message->is_internal) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isInternal", *ticket_message->is_internal) == NULL) {
    goto fail; //Bool
    }


    // ticket_message->message_type
    if (simplebilly_api_message_type__NULL == ticket_message->message_type) {
        goto fail;
    }
    cJSON *message_type_local_JSON = message_type_convertToJSON(ticket_message->message_type);
    if(message_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "messageType", message_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // ticket_message->metadata
    if (!ticket_message->metadata) {
        goto fail;
    }
    cJSON *metadata_local_JSON = _convertToJSON(ticket_message->metadata);
    if(metadata_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // ticket_message->tenant_id
    if (!ticket_message->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", ticket_message->tenant_id) == NULL) {
    goto fail; //String
    }


    // ticket_message->ticket_id
    if (!ticket_message->ticket_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ticketId", ticket_message->ticket_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ticket_message_t *ticket_message_parseFromJSON(cJSON *ticket_messageJSON){

    ticket_message_t *ticket_message_local_var = NULL;

    char *author_email_local_str = NULL;

    char *author_name_local_str = NULL;

    char *body_local_str = NULL;

    char *body_html_local_str = NULL;

    char *channel_id_local_str = NULL;

    char *created_at_local_str = NULL;

    // define the local variable for ticket_message->direction
    simplebilly_api_message_direction__e direction_local_nonprim = 0;

    char *external_id_local_str = NULL;

    // define the local variable for ticket_message->is_internal
    int *is_internal_local_var = NULL;

    // define the local variable for ticket_message->message_type
    simplebilly_api_message_type__e message_type_local_nonprim = 0;

    // define the local variable for ticket_message->metadata
    _t *metadata_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *ticket_id_local_str = NULL;

    // ticket_message->author_email
    cJSON *author_email = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "authorEmail");
    if (cJSON_IsNull(author_email)) {
        author_email = NULL;
    }
    if (author_email) { 
    if(!cJSON_IsString(author_email) && !cJSON_IsNull(author_email))
    {
    goto end; //String
    }
    }

    // ticket_message->author_name
    cJSON *author_name = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "authorName");
    if (cJSON_IsNull(author_name)) {
        author_name = NULL;
    }
    if (author_name) { 
    if(!cJSON_IsString(author_name) && !cJSON_IsNull(author_name))
    {
    goto end; //String
    }
    }

    // ticket_message->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "body");
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

    // ticket_message->body_html
    cJSON *body_html = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "bodyHtml");
    if (cJSON_IsNull(body_html)) {
        body_html = NULL;
    }
    if (body_html) { 
    if(!cJSON_IsString(body_html) && !cJSON_IsNull(body_html))
    {
    goto end; //String
    }
    }

    // ticket_message->channel_id
    cJSON *channel_id = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "channelId");
    if (cJSON_IsNull(channel_id)) {
        channel_id = NULL;
    }
    if (channel_id) { 
    if(!cJSON_IsString(channel_id) && !cJSON_IsNull(channel_id))
    {
    goto end; //String
    }
    }

    // ticket_message->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "createdAt");
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

    // ticket_message->direction
    cJSON *direction = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "direction");
    if (cJSON_IsNull(direction)) {
        direction = NULL;
    }
    if (!direction) {
        goto end;
    }

    
    direction_local_nonprim = message_direction_parseFromJSON(direction); //custom

    // ticket_message->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "externalId");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // ticket_message->is_internal
    cJSON *is_internal = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "isInternal");
    if (cJSON_IsNull(is_internal)) {
        is_internal = NULL;
    }
    if (!is_internal) {
        goto end;
    }

    
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

    // ticket_message->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "messageType");
    if (cJSON_IsNull(message_type)) {
        message_type = NULL;
    }
    if (!message_type) {
        goto end;
    }

    
    message_type_local_nonprim = message_type_parseFromJSON(message_type); //custom

    // ticket_message->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (!metadata) {
        goto end;
    }

    
    metadata_local_nonprim = _parseFromJSON(metadata); //custom

    // ticket_message->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "tenantId");
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

    // ticket_message->ticket_id
    cJSON *ticket_id = cJSON_GetObjectItemCaseSensitive(ticket_messageJSON, "ticketId");
    if (cJSON_IsNull(ticket_id)) {
        ticket_id = NULL;
    }
    if (!ticket_id) {
        goto end;
    }

    
    if(!cJSON_IsString(ticket_id))
    {
    goto end; //String
    }


    if (author_email && !cJSON_IsNull(author_email)) author_email_local_str = strdup(author_email->valuestring);
    if (author_name && !cJSON_IsNull(author_name)) author_name_local_str = strdup(author_name->valuestring);
    if (body && !cJSON_IsNull(body)) body_local_str = strdup(body->valuestring);
    if (body_html && !cJSON_IsNull(body_html)) body_html_local_str = strdup(body_html->valuestring);
    if (channel_id && !cJSON_IsNull(channel_id)) channel_id_local_str = strdup(channel_id->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (external_id && !cJSON_IsNull(external_id)) external_id_local_str = strdup(external_id->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (ticket_id && !cJSON_IsNull(ticket_id)) ticket_id_local_str = strdup(ticket_id->valuestring);

    ticket_message_local_var = ticket_message_create_internal (
        author_email_local_str,
        author_name_local_str,
        body_local_str,
        body_html_local_str,
        channel_id_local_str,
        created_at_local_str,
        direction_local_nonprim,
        external_id_local_str,
        is_internal_local_var,
        message_type_local_nonprim,
        metadata_local_nonprim,
        tenant_id_local_str,
        ticket_id_local_str
        );

    if (!ticket_message_local_var) {
        goto end;
    }

    return ticket_message_local_var;
end:
    if (author_email_local_str) {
        free(author_email_local_str);
        author_email_local_str = NULL;
    }
    if (author_name_local_str) {
        free(author_name_local_str);
        author_name_local_str = NULL;
    }
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (body_html_local_str) {
        free(body_html_local_str);
        body_html_local_str = NULL;
    }
    if (channel_id_local_str) {
        free(channel_id_local_str);
        channel_id_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (direction_local_nonprim) {
        direction_local_nonprim = 0;
    }
    if (external_id_local_str) {
        free(external_id_local_str);
        external_id_local_str = NULL;
    }
    if (is_internal_local_var) {
        free(is_internal_local_var);
        is_internal_local_var = NULL;
    }
    if (message_type_local_nonprim) {
        message_type_local_nonprim = 0;
    }
    if (metadata_local_nonprim) {
        _free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (ticket_id_local_str) {
        free(ticket_id_local_str);
        ticket_id_local_str = NULL;
    }
    return NULL;

}
