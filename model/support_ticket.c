#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "support_ticket.h"



static support_ticket_t *support_ticket_create_internal(
    char *assigned_to,
    char *channel_id,
    support_channel_type_t *channel_type,
    char *closed_at,
    char *created_at,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *external_id,
    char *first_message_at,
    char *last_message_at,
    char *lead_id,
    int *message_count,
    char *order_ref,
    simplebilly_api_ticket_priority__e priority,
    char *resolution,
    simplebilly_api_support_ticket_status__e status,
    char *subject,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    support_ticket_t *support_ticket_local_var = malloc(sizeof(support_ticket_t));
    if (!support_ticket_local_var) {
        return NULL;
    }
    memset(support_ticket_local_var, 0, sizeof(support_ticket_t));
    support_ticket_local_var->_library_owned = 1;
    support_ticket_local_var->assigned_to = assigned_to;
    support_ticket_local_var->channel_id = channel_id;
    support_ticket_local_var->channel_type = channel_type;
    support_ticket_local_var->closed_at = closed_at;
    support_ticket_local_var->created_at = created_at;
    support_ticket_local_var->customer_email = customer_email;
    support_ticket_local_var->customer_id = customer_id;
    support_ticket_local_var->customer_name = customer_name;
    support_ticket_local_var->external_id = external_id;
    support_ticket_local_var->first_message_at = first_message_at;
    support_ticket_local_var->last_message_at = last_message_at;
    support_ticket_local_var->lead_id = lead_id;
    support_ticket_local_var->message_count = message_count;
    support_ticket_local_var->order_ref = order_ref;
    support_ticket_local_var->priority = priority;
    support_ticket_local_var->resolution = resolution;
    support_ticket_local_var->status = status;
    support_ticket_local_var->subject = subject;
    support_ticket_local_var->tags = tags;
    support_ticket_local_var->tenant_id = tenant_id;
    support_ticket_local_var->updated_at = updated_at;
    return support_ticket_local_var;
}

__attribute__((deprecated)) support_ticket_t *support_ticket_create(
    char *assigned_to,
    char *channel_id,
    support_channel_type_t *channel_type,
    char *closed_at,
    char *created_at,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *external_id,
    char *first_message_at,
    char *last_message_at,
    char *lead_id,
    int *message_count,
    char *order_ref,
    simplebilly_api_ticket_priority__e priority,
    char *resolution,
    simplebilly_api_support_ticket_status__e status,
    char *subject,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    int *message_count_copy = NULL;
    if (message_count) {
        message_count_copy = malloc(sizeof(int));
        if (message_count_copy) *message_count_copy = *message_count;
    }
    support_ticket_t *result = support_ticket_create_internal (
        assigned_to,
        channel_id,
        channel_type,
        closed_at,
        created_at,
        customer_email,
        customer_id,
        customer_name,
        external_id,
        first_message_at,
        last_message_at,
        lead_id,
        message_count_copy,
        order_ref,
        priority,
        resolution,
        status,
        subject,
        tags,
        tenant_id,
        updated_at
        );
    if (!result) {
        free(message_count_copy);
    }
    return result;
}

void support_ticket_free(support_ticket_t *support_ticket) {
    if(NULL == support_ticket){
        return ;
    }
    if(support_ticket->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "support_ticket_free");
        return ;
    }
    listEntry_t *listEntry;
    if (support_ticket->assigned_to) {
        free(support_ticket->assigned_to);
        support_ticket->assigned_to = NULL;
    }
    if (support_ticket->channel_id) {
        free(support_ticket->channel_id);
        support_ticket->channel_id = NULL;
    }
    if (support_ticket->channel_type) {
        support_channel_type_free(support_ticket->channel_type);
        support_ticket->channel_type = NULL;
    }
    if (support_ticket->closed_at) {
        free(support_ticket->closed_at);
        support_ticket->closed_at = NULL;
    }
    if (support_ticket->created_at) {
        free(support_ticket->created_at);
        support_ticket->created_at = NULL;
    }
    if (support_ticket->customer_email) {
        free(support_ticket->customer_email);
        support_ticket->customer_email = NULL;
    }
    if (support_ticket->customer_id) {
        free(support_ticket->customer_id);
        support_ticket->customer_id = NULL;
    }
    if (support_ticket->customer_name) {
        free(support_ticket->customer_name);
        support_ticket->customer_name = NULL;
    }
    if (support_ticket->external_id) {
        free(support_ticket->external_id);
        support_ticket->external_id = NULL;
    }
    if (support_ticket->first_message_at) {
        free(support_ticket->first_message_at);
        support_ticket->first_message_at = NULL;
    }
    if (support_ticket->last_message_at) {
        free(support_ticket->last_message_at);
        support_ticket->last_message_at = NULL;
    }
    if (support_ticket->lead_id) {
        free(support_ticket->lead_id);
        support_ticket->lead_id = NULL;
    }
    if (support_ticket->message_count) {
        free(support_ticket->message_count);
        support_ticket->message_count = NULL;
    }
    if (support_ticket->order_ref) {
        free(support_ticket->order_ref);
        support_ticket->order_ref = NULL;
    }
    if (support_ticket->resolution) {
        free(support_ticket->resolution);
        support_ticket->resolution = NULL;
    }
    if (support_ticket->subject) {
        free(support_ticket->subject);
        support_ticket->subject = NULL;
    }
    if (support_ticket->tags) {
        _free(support_ticket->tags);
        support_ticket->tags = NULL;
    }
    if (support_ticket->tenant_id) {
        free(support_ticket->tenant_id);
        support_ticket->tenant_id = NULL;
    }
    if (support_ticket->updated_at) {
        free(support_ticket->updated_at);
        support_ticket->updated_at = NULL;
    }
    free(support_ticket);
}

cJSON *support_ticket_convertToJSON(support_ticket_t *support_ticket) {
    cJSON *item = cJSON_CreateObject();

    // support_ticket->assigned_to
    if(support_ticket->assigned_to) {
    if(cJSON_AddStringToObject(item, "assignedTo", support_ticket->assigned_to) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->channel_id
    if(support_ticket->channel_id) {
    if(cJSON_AddStringToObject(item, "channelId", support_ticket->channel_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->channel_type
    if(support_ticket->channel_type) {
    cJSON *channel_type_local_JSON = support_channel_type_convertToJSON(support_ticket->channel_type);
    if(channel_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "channelType", channel_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // support_ticket->closed_at
    if(support_ticket->closed_at) {
    if(cJSON_AddStringToObject(item, "closedAt", support_ticket->closed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // support_ticket->created_at
    if (!support_ticket->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", support_ticket->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // support_ticket->customer_email
    if(support_ticket->customer_email) {
    if(cJSON_AddStringToObject(item, "customerEmail", support_ticket->customer_email) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->customer_id
    if(support_ticket->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", support_ticket->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->customer_name
    if(support_ticket->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", support_ticket->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->external_id
    if(support_ticket->external_id) {
    if(cJSON_AddStringToObject(item, "externalId", support_ticket->external_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->first_message_at
    if (!support_ticket->first_message_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "firstMessageAt", support_ticket->first_message_at) == NULL) {
    goto fail; //Date-Time
    }


    // support_ticket->last_message_at
    if (!support_ticket->last_message_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lastMessageAt", support_ticket->last_message_at) == NULL) {
    goto fail; //Date-Time
    }


    // support_ticket->lead_id
    if(support_ticket->lead_id) {
    if(cJSON_AddStringToObject(item, "leadId", support_ticket->lead_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->message_count
    if (!support_ticket->message_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "messageCount", *support_ticket->message_count) == NULL) {
    goto fail; //Numeric
    }


    // support_ticket->order_ref
    if(support_ticket->order_ref) {
    if(cJSON_AddStringToObject(item, "orderRef", support_ticket->order_ref) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->priority
    if (simplebilly_api_ticket_priority__NULL == support_ticket->priority) {
        goto fail;
    }
    cJSON *priority_local_JSON = ticket_priority_convertToJSON(support_ticket->priority);
    if(priority_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "priority", priority_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // support_ticket->resolution
    if(support_ticket->resolution) {
    if(cJSON_AddStringToObject(item, "resolution", support_ticket->resolution) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket->status
    if (simplebilly_api_support_ticket_status__NULL == support_ticket->status) {
        goto fail;
    }
    cJSON *status_local_JSON = support_ticket_status_convertToJSON(support_ticket->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // support_ticket->subject
    if (!support_ticket->subject) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject", support_ticket->subject) == NULL) {
    goto fail; //String
    }


    // support_ticket->tags
    if (!support_ticket->tags) {
        goto fail;
    }
    cJSON *tags_local_JSON = _convertToJSON(support_ticket->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // support_ticket->tenant_id
    if (!support_ticket->tenant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tenantId", support_ticket->tenant_id) == NULL) {
    goto fail; //String
    }


    // support_ticket->updated_at
    if(support_ticket->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", support_ticket->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

support_ticket_t *support_ticket_parseFromJSON(cJSON *support_ticketJSON){

    support_ticket_t *support_ticket_local_var = NULL;

    char *assigned_to_local_str = NULL;

    char *channel_id_local_str = NULL;

    // define the local variable for support_ticket->channel_type
    support_channel_type_t *channel_type_local_nonprim = NULL;

    char *closed_at_local_str = NULL;

    char *created_at_local_str = NULL;

    char *customer_email_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *customer_name_local_str = NULL;

    char *external_id_local_str = NULL;

    char *first_message_at_local_str = NULL;

    char *last_message_at_local_str = NULL;

    char *lead_id_local_str = NULL;

    // define the local variable for support_ticket->message_count
    int *message_count_local_var = NULL;

    char *order_ref_local_str = NULL;

    // define the local variable for support_ticket->priority
    simplebilly_api_ticket_priority__e priority_local_nonprim = 0;

    char *resolution_local_str = NULL;

    // define the local variable for support_ticket->status
    simplebilly_api_support_ticket_status__e status_local_nonprim = 0;

    char *subject_local_str = NULL;

    // define the local variable for support_ticket->tags
    _t *tags_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // support_ticket->assigned_to
    cJSON *assigned_to = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "assignedTo");
    if (cJSON_IsNull(assigned_to)) {
        assigned_to = NULL;
    }
    if (assigned_to) { 
    if(!cJSON_IsString(assigned_to) && !cJSON_IsNull(assigned_to))
    {
    goto end; //String
    }
    }

    // support_ticket->channel_id
    cJSON *channel_id = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "channelId");
    if (cJSON_IsNull(channel_id)) {
        channel_id = NULL;
    }
    if (channel_id) { 
    if(!cJSON_IsString(channel_id) && !cJSON_IsNull(channel_id))
    {
    goto end; //String
    }
    }

    // support_ticket->channel_type
    cJSON *channel_type = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "channelType");
    if (cJSON_IsNull(channel_type)) {
        channel_type = NULL;
    }
    if (channel_type) { 
    channel_type_local_nonprim = support_channel_type_parseFromJSON(channel_type); //custom
    }

    // support_ticket->closed_at
    cJSON *closed_at = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "closedAt");
    if (cJSON_IsNull(closed_at)) {
        closed_at = NULL;
    }
    if (closed_at) { 
    if(!cJSON_IsString(closed_at) && !cJSON_IsNull(closed_at))
    {
    goto end; //DateTime
    }
    }

    // support_ticket->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "createdAt");
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

    // support_ticket->customer_email
    cJSON *customer_email = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "customerEmail");
    if (cJSON_IsNull(customer_email)) {
        customer_email = NULL;
    }
    if (customer_email) { 
    if(!cJSON_IsString(customer_email) && !cJSON_IsNull(customer_email))
    {
    goto end; //String
    }
    }

    // support_ticket->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // support_ticket->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // support_ticket->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "externalId");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // support_ticket->first_message_at
    cJSON *first_message_at = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "firstMessageAt");
    if (cJSON_IsNull(first_message_at)) {
        first_message_at = NULL;
    }
    if (!first_message_at) {
        goto end;
    }

    
    if(!cJSON_IsString(first_message_at) && !cJSON_IsNull(first_message_at))
    {
    goto end; //DateTime
    }

    // support_ticket->last_message_at
    cJSON *last_message_at = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "lastMessageAt");
    if (cJSON_IsNull(last_message_at)) {
        last_message_at = NULL;
    }
    if (!last_message_at) {
        goto end;
    }

    
    if(!cJSON_IsString(last_message_at) && !cJSON_IsNull(last_message_at))
    {
    goto end; //DateTime
    }

    // support_ticket->lead_id
    cJSON *lead_id = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "leadId");
    if (cJSON_IsNull(lead_id)) {
        lead_id = NULL;
    }
    if (lead_id) { 
    if(!cJSON_IsString(lead_id) && !cJSON_IsNull(lead_id))
    {
    goto end; //String
    }
    }

    // support_ticket->message_count
    cJSON *message_count = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "messageCount");
    if (cJSON_IsNull(message_count)) {
        message_count = NULL;
    }
    if (!message_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_count))
    {
    goto end; //Numeric
    }
    message_count_local_var = malloc(sizeof(int));
    if(!message_count_local_var)
    {
        goto end;
    }
    *message_count_local_var = message_count->valuedouble;

    // support_ticket->order_ref
    cJSON *order_ref = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "orderRef");
    if (cJSON_IsNull(order_ref)) {
        order_ref = NULL;
    }
    if (order_ref) { 
    if(!cJSON_IsString(order_ref) && !cJSON_IsNull(order_ref))
    {
    goto end; //String
    }
    }

    // support_ticket->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (!priority) {
        goto end;
    }

    
    priority_local_nonprim = ticket_priority_parseFromJSON(priority); //custom

    // support_ticket->resolution
    cJSON *resolution = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "resolution");
    if (cJSON_IsNull(resolution)) {
        resolution = NULL;
    }
    if (resolution) { 
    if(!cJSON_IsString(resolution) && !cJSON_IsNull(resolution))
    {
    goto end; //String
    }
    }

    // support_ticket->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = support_ticket_status_parseFromJSON(status); //custom

    // support_ticket->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (!subject) {
        goto end;
    }

    
    if(!cJSON_IsString(subject))
    {
    goto end; //String
    }

    // support_ticket->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (!tags) {
        goto end;
    }

    
    tags_local_nonprim = _parseFromJSON(tags); //custom

    // support_ticket->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "tenantId");
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

    // support_ticket->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(support_ticketJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    if (assigned_to && !cJSON_IsNull(assigned_to)) assigned_to_local_str = strdup(assigned_to->valuestring);
    if (channel_id && !cJSON_IsNull(channel_id)) channel_id_local_str = strdup(channel_id->valuestring);
    if (closed_at && !cJSON_IsNull(closed_at)) closed_at_local_str = strdup(closed_at->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (customer_email && !cJSON_IsNull(customer_email)) customer_email_local_str = strdup(customer_email->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (external_id && !cJSON_IsNull(external_id)) external_id_local_str = strdup(external_id->valuestring);
    if (first_message_at && !cJSON_IsNull(first_message_at)) first_message_at_local_str = strdup(first_message_at->valuestring);
    if (last_message_at && !cJSON_IsNull(last_message_at)) last_message_at_local_str = strdup(last_message_at->valuestring);
    if (lead_id && !cJSON_IsNull(lead_id)) lead_id_local_str = strdup(lead_id->valuestring);
    if (order_ref && !cJSON_IsNull(order_ref)) order_ref_local_str = strdup(order_ref->valuestring);
    if (resolution && !cJSON_IsNull(resolution)) resolution_local_str = strdup(resolution->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);
    if (tenant_id && !cJSON_IsNull(tenant_id)) tenant_id_local_str = strdup(tenant_id->valuestring);
    if (updated_at && !cJSON_IsNull(updated_at)) updated_at_local_str = strdup(updated_at->valuestring);

    support_ticket_local_var = support_ticket_create_internal (
        assigned_to_local_str,
        channel_id_local_str,
        channel_type ? channel_type_local_nonprim : NULL,
        closed_at_local_str,
        created_at_local_str,
        customer_email_local_str,
        customer_id_local_str,
        customer_name_local_str,
        external_id_local_str,
        first_message_at_local_str,
        last_message_at_local_str,
        lead_id_local_str,
        message_count_local_var,
        order_ref_local_str,
        priority_local_nonprim,
        resolution_local_str,
        status_local_nonprim,
        subject_local_str,
        tags_local_nonprim,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!support_ticket_local_var) {
        goto end;
    }

    return support_ticket_local_var;
end:
    if (assigned_to_local_str) {
        free(assigned_to_local_str);
        assigned_to_local_str = NULL;
    }
    if (channel_id_local_str) {
        free(channel_id_local_str);
        channel_id_local_str = NULL;
    }
    if (channel_type_local_nonprim) {
        support_channel_type_free(channel_type_local_nonprim);
        channel_type_local_nonprim = NULL;
    }
    if (closed_at_local_str) {
        free(closed_at_local_str);
        closed_at_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (customer_email_local_str) {
        free(customer_email_local_str);
        customer_email_local_str = NULL;
    }
    if (customer_id_local_str) {
        free(customer_id_local_str);
        customer_id_local_str = NULL;
    }
    if (customer_name_local_str) {
        free(customer_name_local_str);
        customer_name_local_str = NULL;
    }
    if (external_id_local_str) {
        free(external_id_local_str);
        external_id_local_str = NULL;
    }
    if (first_message_at_local_str) {
        free(first_message_at_local_str);
        first_message_at_local_str = NULL;
    }
    if (last_message_at_local_str) {
        free(last_message_at_local_str);
        last_message_at_local_str = NULL;
    }
    if (lead_id_local_str) {
        free(lead_id_local_str);
        lead_id_local_str = NULL;
    }
    if (message_count_local_var) {
        free(message_count_local_var);
        message_count_local_var = NULL;
    }
    if (order_ref_local_str) {
        free(order_ref_local_str);
        order_ref_local_str = NULL;
    }
    if (priority_local_nonprim) {
        priority_local_nonprim = 0;
    }
    if (resolution_local_str) {
        free(resolution_local_str);
        resolution_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    if (tags_local_nonprim) {
        _free(tags_local_nonprim);
        tags_local_nonprim = NULL;
    }
    if (tenant_id_local_str) {
        free(tenant_id_local_str);
        tenant_id_local_str = NULL;
    }
    if (updated_at_local_str) {
        free(updated_at_local_str);
        updated_at_local_str = NULL;
    }
    return NULL;

}
