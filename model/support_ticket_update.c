#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "support_ticket_update.h"



static support_ticket_update_t *support_ticket_update_create_internal(
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
    ticket_priority_t *priority,
    char *resolution,
    support_ticket_status_t *status,
    char *subject,
    any_type_t *tags,
    char *tenant_id,
    char *updated_at
    ) {
    support_ticket_update_t *support_ticket_update_local_var = malloc(sizeof(support_ticket_update_t));
    if (!support_ticket_update_local_var) {
        return NULL;
    }
    memset(support_ticket_update_local_var, 0, sizeof(support_ticket_update_t));
    support_ticket_update_local_var->_library_owned = 1;
    support_ticket_update_local_var->assigned_to = assigned_to;
    support_ticket_update_local_var->channel_id = channel_id;
    support_ticket_update_local_var->channel_type = channel_type;
    support_ticket_update_local_var->closed_at = closed_at;
    support_ticket_update_local_var->created_at = created_at;
    support_ticket_update_local_var->customer_email = customer_email;
    support_ticket_update_local_var->customer_id = customer_id;
    support_ticket_update_local_var->customer_name = customer_name;
    support_ticket_update_local_var->external_id = external_id;
    support_ticket_update_local_var->first_message_at = first_message_at;
    support_ticket_update_local_var->last_message_at = last_message_at;
    support_ticket_update_local_var->lead_id = lead_id;
    support_ticket_update_local_var->message_count = message_count;
    support_ticket_update_local_var->order_ref = order_ref;
    support_ticket_update_local_var->priority = priority;
    support_ticket_update_local_var->resolution = resolution;
    support_ticket_update_local_var->status = status;
    support_ticket_update_local_var->subject = subject;
    support_ticket_update_local_var->tags = tags;
    support_ticket_update_local_var->tenant_id = tenant_id;
    support_ticket_update_local_var->updated_at = updated_at;
    return support_ticket_update_local_var;
}

__attribute__((deprecated)) support_ticket_update_t *support_ticket_update_create(
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
    ticket_priority_t *priority,
    char *resolution,
    support_ticket_status_t *status,
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
    support_ticket_update_t *result = support_ticket_update_create_internal (
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

void support_ticket_update_free(support_ticket_update_t *support_ticket_update) {
    if(NULL == support_ticket_update){
        return ;
    }
    if(support_ticket_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "support_ticket_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (support_ticket_update->assigned_to) {
        free(support_ticket_update->assigned_to);
        support_ticket_update->assigned_to = NULL;
    }
    if (support_ticket_update->channel_id) {
        free(support_ticket_update->channel_id);
        support_ticket_update->channel_id = NULL;
    }
    if (support_ticket_update->channel_type) {
        support_channel_type_free(support_ticket_update->channel_type);
        support_ticket_update->channel_type = NULL;
    }
    if (support_ticket_update->closed_at) {
        free(support_ticket_update->closed_at);
        support_ticket_update->closed_at = NULL;
    }
    if (support_ticket_update->created_at) {
        free(support_ticket_update->created_at);
        support_ticket_update->created_at = NULL;
    }
    if (support_ticket_update->customer_email) {
        free(support_ticket_update->customer_email);
        support_ticket_update->customer_email = NULL;
    }
    if (support_ticket_update->customer_id) {
        free(support_ticket_update->customer_id);
        support_ticket_update->customer_id = NULL;
    }
    if (support_ticket_update->customer_name) {
        free(support_ticket_update->customer_name);
        support_ticket_update->customer_name = NULL;
    }
    if (support_ticket_update->external_id) {
        free(support_ticket_update->external_id);
        support_ticket_update->external_id = NULL;
    }
    if (support_ticket_update->first_message_at) {
        free(support_ticket_update->first_message_at);
        support_ticket_update->first_message_at = NULL;
    }
    if (support_ticket_update->last_message_at) {
        free(support_ticket_update->last_message_at);
        support_ticket_update->last_message_at = NULL;
    }
    if (support_ticket_update->lead_id) {
        free(support_ticket_update->lead_id);
        support_ticket_update->lead_id = NULL;
    }
    if (support_ticket_update->message_count) {
        free(support_ticket_update->message_count);
        support_ticket_update->message_count = NULL;
    }
    if (support_ticket_update->order_ref) {
        free(support_ticket_update->order_ref);
        support_ticket_update->order_ref = NULL;
    }
    if (support_ticket_update->priority) {
        ticket_priority_free(support_ticket_update->priority);
        support_ticket_update->priority = NULL;
    }
    if (support_ticket_update->resolution) {
        free(support_ticket_update->resolution);
        support_ticket_update->resolution = NULL;
    }
    if (support_ticket_update->status) {
        support_ticket_status_free(support_ticket_update->status);
        support_ticket_update->status = NULL;
    }
    if (support_ticket_update->subject) {
        free(support_ticket_update->subject);
        support_ticket_update->subject = NULL;
    }
    if (support_ticket_update->tags) {
        _free(support_ticket_update->tags);
        support_ticket_update->tags = NULL;
    }
    if (support_ticket_update->tenant_id) {
        free(support_ticket_update->tenant_id);
        support_ticket_update->tenant_id = NULL;
    }
    if (support_ticket_update->updated_at) {
        free(support_ticket_update->updated_at);
        support_ticket_update->updated_at = NULL;
    }
    free(support_ticket_update);
}

cJSON *support_ticket_update_convertToJSON(support_ticket_update_t *support_ticket_update) {
    cJSON *item = cJSON_CreateObject();

    // support_ticket_update->assigned_to
    if(support_ticket_update->assigned_to) {
    if(cJSON_AddStringToObject(item, "assignedTo", support_ticket_update->assigned_to) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->channel_id
    if(support_ticket_update->channel_id) {
    if(cJSON_AddStringToObject(item, "channelId", support_ticket_update->channel_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->channel_type
    if(support_ticket_update->channel_type) {
    cJSON *channel_type_local_JSON = support_channel_type_convertToJSON(support_ticket_update->channel_type);
    if(channel_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "channelType", channel_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // support_ticket_update->closed_at
    if(support_ticket_update->closed_at) {
    if(cJSON_AddStringToObject(item, "closedAt", support_ticket_update->closed_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // support_ticket_update->created_at
    if(support_ticket_update->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", support_ticket_update->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // support_ticket_update->customer_email
    if(support_ticket_update->customer_email) {
    if(cJSON_AddStringToObject(item, "customerEmail", support_ticket_update->customer_email) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->customer_id
    if(support_ticket_update->customer_id) {
    if(cJSON_AddStringToObject(item, "customerId", support_ticket_update->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->customer_name
    if(support_ticket_update->customer_name) {
    if(cJSON_AddStringToObject(item, "customerName", support_ticket_update->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->external_id
    if(support_ticket_update->external_id) {
    if(cJSON_AddStringToObject(item, "externalId", support_ticket_update->external_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->first_message_at
    if(support_ticket_update->first_message_at) {
    if(cJSON_AddStringToObject(item, "firstMessageAt", support_ticket_update->first_message_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // support_ticket_update->last_message_at
    if(support_ticket_update->last_message_at) {
    if(cJSON_AddStringToObject(item, "lastMessageAt", support_ticket_update->last_message_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // support_ticket_update->lead_id
    if(support_ticket_update->lead_id) {
    if(cJSON_AddStringToObject(item, "leadId", support_ticket_update->lead_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->message_count
    if(support_ticket_update->message_count) {
    if(cJSON_AddNumberToObject(item, "messageCount", *support_ticket_update->message_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // support_ticket_update->order_ref
    if(support_ticket_update->order_ref) {
    if(cJSON_AddStringToObject(item, "orderRef", support_ticket_update->order_ref) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->priority
    if(support_ticket_update->priority) {
    cJSON *priority_local_JSON = ticket_priority_convertToJSON(support_ticket_update->priority);
    if(priority_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "priority", priority_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // support_ticket_update->resolution
    if(support_ticket_update->resolution) {
    if(cJSON_AddStringToObject(item, "resolution", support_ticket_update->resolution) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->status
    if(support_ticket_update->status) {
    cJSON *status_local_JSON = support_ticket_status_convertToJSON(support_ticket_update->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // support_ticket_update->subject
    if(support_ticket_update->subject) {
    if(cJSON_AddStringToObject(item, "subject", support_ticket_update->subject) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->tags
    if(support_ticket_update->tags) {
    cJSON *tags_local_JSON = _convertToJSON(support_ticket_update->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // support_ticket_update->tenant_id
    if(support_ticket_update->tenant_id) {
    if(cJSON_AddStringToObject(item, "tenantId", support_ticket_update->tenant_id) == NULL) {
    goto fail; //String
    }
    }


    // support_ticket_update->updated_at
    if(support_ticket_update->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", support_ticket_update->updated_at) == NULL) {
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

support_ticket_update_t *support_ticket_update_parseFromJSON(cJSON *support_ticket_updateJSON){

    support_ticket_update_t *support_ticket_update_local_var = NULL;

    char *assigned_to_local_str = NULL;

    char *channel_id_local_str = NULL;

    // define the local variable for support_ticket_update->channel_type
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

    // define the local variable for support_ticket_update->message_count
    int *message_count_local_var = NULL;

    char *order_ref_local_str = NULL;

    // define the local variable for support_ticket_update->priority
    ticket_priority_t *priority_local_nonprim = NULL;

    char *resolution_local_str = NULL;

    // define the local variable for support_ticket_update->status
    support_ticket_status_t *status_local_nonprim = NULL;

    char *subject_local_str = NULL;

    // define the local variable for support_ticket_update->tags
    _t *tags_local_nonprim = NULL;

    char *tenant_id_local_str = NULL;

    char *updated_at_local_str = NULL;

    // support_ticket_update->assigned_to
    cJSON *assigned_to = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "assignedTo");
    if (cJSON_IsNull(assigned_to)) {
        assigned_to = NULL;
    }
    if (assigned_to) { 
    if(!cJSON_IsString(assigned_to) && !cJSON_IsNull(assigned_to))
    {
    goto end; //String
    }
    }

    // support_ticket_update->channel_id
    cJSON *channel_id = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "channelId");
    if (cJSON_IsNull(channel_id)) {
        channel_id = NULL;
    }
    if (channel_id) { 
    if(!cJSON_IsString(channel_id) && !cJSON_IsNull(channel_id))
    {
    goto end; //String
    }
    }

    // support_ticket_update->channel_type
    cJSON *channel_type = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "channelType");
    if (cJSON_IsNull(channel_type)) {
        channel_type = NULL;
    }
    if (channel_type) { 
    channel_type_local_nonprim = support_channel_type_parseFromJSON(channel_type); //custom
    }

    // support_ticket_update->closed_at
    cJSON *closed_at = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "closedAt");
    if (cJSON_IsNull(closed_at)) {
        closed_at = NULL;
    }
    if (closed_at) { 
    if(!cJSON_IsString(closed_at) && !cJSON_IsNull(closed_at))
    {
    goto end; //DateTime
    }
    }

    // support_ticket_update->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // support_ticket_update->customer_email
    cJSON *customer_email = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "customerEmail");
    if (cJSON_IsNull(customer_email)) {
        customer_email = NULL;
    }
    if (customer_email) { 
    if(!cJSON_IsString(customer_email) && !cJSON_IsNull(customer_email))
    {
    goto end; //String
    }
    }

    // support_ticket_update->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "customerId");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // support_ticket_update->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "customerName");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // support_ticket_update->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "externalId");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // support_ticket_update->first_message_at
    cJSON *first_message_at = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "firstMessageAt");
    if (cJSON_IsNull(first_message_at)) {
        first_message_at = NULL;
    }
    if (first_message_at) { 
    if(!cJSON_IsString(first_message_at) && !cJSON_IsNull(first_message_at))
    {
    goto end; //DateTime
    }
    }

    // support_ticket_update->last_message_at
    cJSON *last_message_at = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "lastMessageAt");
    if (cJSON_IsNull(last_message_at)) {
        last_message_at = NULL;
    }
    if (last_message_at) { 
    if(!cJSON_IsString(last_message_at) && !cJSON_IsNull(last_message_at))
    {
    goto end; //DateTime
    }
    }

    // support_ticket_update->lead_id
    cJSON *lead_id = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "leadId");
    if (cJSON_IsNull(lead_id)) {
        lead_id = NULL;
    }
    if (lead_id) { 
    if(!cJSON_IsString(lead_id) && !cJSON_IsNull(lead_id))
    {
    goto end; //String
    }
    }

    // support_ticket_update->message_count
    cJSON *message_count = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "messageCount");
    if (cJSON_IsNull(message_count)) {
        message_count = NULL;
    }
    if (message_count) { 
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
    }

    // support_ticket_update->order_ref
    cJSON *order_ref = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "orderRef");
    if (cJSON_IsNull(order_ref)) {
        order_ref = NULL;
    }
    if (order_ref) { 
    if(!cJSON_IsString(order_ref) && !cJSON_IsNull(order_ref))
    {
    goto end; //String
    }
    }

    // support_ticket_update->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    priority_local_nonprim = ticket_priority_parseFromJSON(priority); //custom
    }

    // support_ticket_update->resolution
    cJSON *resolution = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "resolution");
    if (cJSON_IsNull(resolution)) {
        resolution = NULL;
    }
    if (resolution) { 
    if(!cJSON_IsString(resolution) && !cJSON_IsNull(resolution))
    {
    goto end; //String
    }
    }

    // support_ticket_update->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = support_ticket_status_parseFromJSON(status); //custom
    }

    // support_ticket_update->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }

    // support_ticket_update->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    tags_local_nonprim = _parseFromJSON(tags); //custom
    }

    // support_ticket_update->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "tenantId");
    if (cJSON_IsNull(tenant_id)) {
        tenant_id = NULL;
    }
    if (tenant_id) { 
    if(!cJSON_IsString(tenant_id) && !cJSON_IsNull(tenant_id))
    {
    goto end; //String
    }
    }

    // support_ticket_update->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(support_ticket_updateJSON, "updatedAt");
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

    support_ticket_update_local_var = support_ticket_update_create_internal (
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
        priority ? priority_local_nonprim : NULL,
        resolution_local_str,
        status ? status_local_nonprim : NULL,
        subject_local_str,
        tags ? tags_local_nonprim : NULL,
        tenant_id_local_str,
        updated_at_local_str
        );

    if (!support_ticket_update_local_var) {
        goto end;
    }

    return support_ticket_update_local_var;
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
        ticket_priority_free(priority_local_nonprim);
        priority_local_nonprim = NULL;
    }
    if (resolution_local_str) {
        free(resolution_local_str);
        resolution_local_str = NULL;
    }
    if (status_local_nonprim) {
        support_ticket_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
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
