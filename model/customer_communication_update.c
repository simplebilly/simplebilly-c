#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_communication_update.h"



static customer_communication_update_t *customer_communication_update_create_internal(
    char *body,
    communication_channel_t *channel,
    char *contact_id,
    char *counterparty,
    communication_direction_t *direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
    ) {
    customer_communication_update_t *customer_communication_update_local_var = malloc(sizeof(customer_communication_update_t));
    if (!customer_communication_update_local_var) {
        return NULL;
    }
    memset(customer_communication_update_local_var, 0, sizeof(customer_communication_update_t));
    customer_communication_update_local_var->_library_owned = 1;
    customer_communication_update_local_var->body = body;
    customer_communication_update_local_var->channel = channel;
    customer_communication_update_local_var->contact_id = contact_id;
    customer_communication_update_local_var->counterparty = counterparty;
    customer_communication_update_local_var->direction = direction;
    customer_communication_update_local_var->occurred_at = occurred_at;
    customer_communication_update_local_var->subject = subject;
    customer_communication_update_local_var->tags = tags;
    return customer_communication_update_local_var;
}

__attribute__((deprecated)) customer_communication_update_t *customer_communication_update_create(
    char *body,
    communication_channel_t *channel,
    char *contact_id,
    char *counterparty,
    communication_direction_t *direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
    ) {
    customer_communication_update_t *result = customer_communication_update_create_internal (
        body,
        channel,
        contact_id,
        counterparty,
        direction,
        occurred_at,
        subject,
        tags
        );
    if (!result) {
    }
    return result;
}

void customer_communication_update_free(customer_communication_update_t *customer_communication_update) {
    if(NULL == customer_communication_update){
        return ;
    }
    if(customer_communication_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_communication_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_communication_update->body) {
        free(customer_communication_update->body);
        customer_communication_update->body = NULL;
    }
    if (customer_communication_update->channel) {
        communication_channel_free(customer_communication_update->channel);
        customer_communication_update->channel = NULL;
    }
    if (customer_communication_update->contact_id) {
        free(customer_communication_update->contact_id);
        customer_communication_update->contact_id = NULL;
    }
    if (customer_communication_update->counterparty) {
        free(customer_communication_update->counterparty);
        customer_communication_update->counterparty = NULL;
    }
    if (customer_communication_update->direction) {
        communication_direction_free(customer_communication_update->direction);
        customer_communication_update->direction = NULL;
    }
    if (customer_communication_update->occurred_at) {
        free(customer_communication_update->occurred_at);
        customer_communication_update->occurred_at = NULL;
    }
    if (customer_communication_update->subject) {
        free(customer_communication_update->subject);
        customer_communication_update->subject = NULL;
    }
    if (customer_communication_update->tags) {
        _free(customer_communication_update->tags);
        customer_communication_update->tags = NULL;
    }
    free(customer_communication_update);
}

cJSON *customer_communication_update_convertToJSON(customer_communication_update_t *customer_communication_update) {
    cJSON *item = cJSON_CreateObject();

    // customer_communication_update->body
    if(customer_communication_update->body) {
    if(cJSON_AddStringToObject(item, "body", customer_communication_update->body) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication_update->channel
    if(customer_communication_update->channel) {
    cJSON *channel_local_JSON = communication_channel_convertToJSON(customer_communication_update->channel);
    if(channel_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "channel", channel_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // customer_communication_update->contact_id
    if(customer_communication_update->contact_id) {
    if(cJSON_AddStringToObject(item, "contactId", customer_communication_update->contact_id) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication_update->counterparty
    if(customer_communication_update->counterparty) {
    if(cJSON_AddStringToObject(item, "counterparty", customer_communication_update->counterparty) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication_update->direction
    if(customer_communication_update->direction) {
    cJSON *direction_local_JSON = communication_direction_convertToJSON(customer_communication_update->direction);
    if(direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "direction", direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // customer_communication_update->occurred_at
    if(customer_communication_update->occurred_at) {
    if(cJSON_AddStringToObject(item, "occurredAt", customer_communication_update->occurred_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // customer_communication_update->subject
    if(customer_communication_update->subject) {
    if(cJSON_AddStringToObject(item, "subject", customer_communication_update->subject) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication_update->tags
    if(customer_communication_update->tags) {
    cJSON *tags_local_JSON = _convertToJSON(customer_communication_update->tags);
    if(tags_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "tags", tags_local_JSON);
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

customer_communication_update_t *customer_communication_update_parseFromJSON(cJSON *customer_communication_updateJSON){

    customer_communication_update_t *customer_communication_update_local_var = NULL;

    char *body_local_str = NULL;

    // define the local variable for customer_communication_update->channel
    communication_channel_t *channel_local_nonprim = NULL;

    char *contact_id_local_str = NULL;

    char *counterparty_local_str = NULL;

    // define the local variable for customer_communication_update->direction
    communication_direction_t *direction_local_nonprim = NULL;

    char *occurred_at_local_str = NULL;

    char *subject_local_str = NULL;

    // define the local variable for customer_communication_update->tags
    _t *tags_local_nonprim = NULL;

    // customer_communication_update->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "body");
    if (cJSON_IsNull(body)) {
        body = NULL;
    }
    if (body) { 
    if(!cJSON_IsString(body) && !cJSON_IsNull(body))
    {
    goto end; //String
    }
    }

    // customer_communication_update->channel
    cJSON *channel = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "channel");
    if (cJSON_IsNull(channel)) {
        channel = NULL;
    }
    if (channel) { 
    channel_local_nonprim = communication_channel_parseFromJSON(channel); //custom
    }

    // customer_communication_update->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (contact_id) { 
    if(!cJSON_IsString(contact_id) && !cJSON_IsNull(contact_id))
    {
    goto end; //String
    }
    }

    // customer_communication_update->counterparty
    cJSON *counterparty = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "counterparty");
    if (cJSON_IsNull(counterparty)) {
        counterparty = NULL;
    }
    if (counterparty) { 
    if(!cJSON_IsString(counterparty) && !cJSON_IsNull(counterparty))
    {
    goto end; //String
    }
    }

    // customer_communication_update->direction
    cJSON *direction = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "direction");
    if (cJSON_IsNull(direction)) {
        direction = NULL;
    }
    if (direction) { 
    direction_local_nonprim = communication_direction_parseFromJSON(direction); //custom
    }

    // customer_communication_update->occurred_at
    cJSON *occurred_at = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "occurredAt");
    if (cJSON_IsNull(occurred_at)) {
        occurred_at = NULL;
    }
    if (occurred_at) { 
    if(!cJSON_IsString(occurred_at) && !cJSON_IsNull(occurred_at))
    {
    goto end; //DateTime
    }
    }

    // customer_communication_update->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }

    // customer_communication_update->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(customer_communication_updateJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    tags_local_nonprim = _parseFromJSON(tags); //custom
    }


    if (body && !cJSON_IsNull(body)) body_local_str = strdup(body->valuestring);
    if (contact_id && !cJSON_IsNull(contact_id)) contact_id_local_str = strdup(contact_id->valuestring);
    if (counterparty && !cJSON_IsNull(counterparty)) counterparty_local_str = strdup(counterparty->valuestring);
    if (occurred_at && !cJSON_IsNull(occurred_at)) occurred_at_local_str = strdup(occurred_at->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    customer_communication_update_local_var = customer_communication_update_create_internal (
        body_local_str,
        channel ? channel_local_nonprim : NULL,
        contact_id_local_str,
        counterparty_local_str,
        direction ? direction_local_nonprim : NULL,
        occurred_at_local_str,
        subject_local_str,
        tags ? tags_local_nonprim : NULL
        );

    if (!customer_communication_update_local_var) {
        goto end;
    }

    return customer_communication_update_local_var;
end:
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (channel_local_nonprim) {
        communication_channel_free(channel_local_nonprim);
        channel_local_nonprim = NULL;
    }
    if (contact_id_local_str) {
        free(contact_id_local_str);
        contact_id_local_str = NULL;
    }
    if (counterparty_local_str) {
        free(counterparty_local_str);
        counterparty_local_str = NULL;
    }
    if (direction_local_nonprim) {
        communication_direction_free(direction_local_nonprim);
        direction_local_nonprim = NULL;
    }
    if (occurred_at_local_str) {
        free(occurred_at_local_str);
        occurred_at_local_str = NULL;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    if (tags_local_nonprim) {
        _free(tags_local_nonprim);
        tags_local_nonprim = NULL;
    }
    return NULL;

}
