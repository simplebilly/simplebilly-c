#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "customer_communication.h"



static customer_communication_t *customer_communication_create_internal(
    char *body,
    simplebilly_api_communication_channel__e channel,
    char *contact_id,
    char *counterparty,
    simplebilly_api_communication_direction__e direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
    ) {
    customer_communication_t *customer_communication_local_var = malloc(sizeof(customer_communication_t));
    if (!customer_communication_local_var) {
        return NULL;
    }
    memset(customer_communication_local_var, 0, sizeof(customer_communication_t));
    customer_communication_local_var->_library_owned = 1;
    customer_communication_local_var->body = body;
    customer_communication_local_var->channel = channel;
    customer_communication_local_var->contact_id = contact_id;
    customer_communication_local_var->counterparty = counterparty;
    customer_communication_local_var->direction = direction;
    customer_communication_local_var->occurred_at = occurred_at;
    customer_communication_local_var->subject = subject;
    customer_communication_local_var->tags = tags;
    return customer_communication_local_var;
}

__attribute__((deprecated)) customer_communication_t *customer_communication_create(
    char *body,
    simplebilly_api_communication_channel__e channel,
    char *contact_id,
    char *counterparty,
    simplebilly_api_communication_direction__e direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
    ) {
    customer_communication_t *result = customer_communication_create_internal (
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

void customer_communication_free(customer_communication_t *customer_communication) {
    if(NULL == customer_communication){
        return ;
    }
    if(customer_communication->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "customer_communication_free");
        return ;
    }
    listEntry_t *listEntry;
    if (customer_communication->body) {
        free(customer_communication->body);
        customer_communication->body = NULL;
    }
    if (customer_communication->contact_id) {
        free(customer_communication->contact_id);
        customer_communication->contact_id = NULL;
    }
    if (customer_communication->counterparty) {
        free(customer_communication->counterparty);
        customer_communication->counterparty = NULL;
    }
    if (customer_communication->occurred_at) {
        free(customer_communication->occurred_at);
        customer_communication->occurred_at = NULL;
    }
    if (customer_communication->subject) {
        free(customer_communication->subject);
        customer_communication->subject = NULL;
    }
    if (customer_communication->tags) {
        _free(customer_communication->tags);
        customer_communication->tags = NULL;
    }
    free(customer_communication);
}

cJSON *customer_communication_convertToJSON(customer_communication_t *customer_communication) {
    cJSON *item = cJSON_CreateObject();

    // customer_communication->body
    if(customer_communication->body) {
    if(cJSON_AddStringToObject(item, "body", customer_communication->body) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication->channel
    if (simplebilly_api_communication_channel__NULL == customer_communication->channel) {
        goto fail;
    }
    cJSON *channel_local_JSON = communication_channel_convertToJSON(customer_communication->channel);
    if(channel_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "channel", channel_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // customer_communication->contact_id
    if (!customer_communication->contact_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contactId", customer_communication->contact_id) == NULL) {
    goto fail; //String
    }


    // customer_communication->counterparty
    if(customer_communication->counterparty) {
    if(cJSON_AddStringToObject(item, "counterparty", customer_communication->counterparty) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication->direction
    if (simplebilly_api_communication_direction__NULL == customer_communication->direction) {
        goto fail;
    }
    cJSON *direction_local_JSON = communication_direction_convertToJSON(customer_communication->direction);
    if(direction_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "direction", direction_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // customer_communication->occurred_at
    if(customer_communication->occurred_at) {
    if(cJSON_AddStringToObject(item, "occurredAt", customer_communication->occurred_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // customer_communication->subject
    if(customer_communication->subject) {
    if(cJSON_AddStringToObject(item, "subject", customer_communication->subject) == NULL) {
    goto fail; //String
    }
    }


    // customer_communication->tags
    if(customer_communication->tags) {
    cJSON *tags_local_JSON = _convertToJSON(customer_communication->tags);
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

customer_communication_t *customer_communication_parseFromJSON(cJSON *customer_communicationJSON){

    customer_communication_t *customer_communication_local_var = NULL;

    char *body_local_str = NULL;

    // define the local variable for customer_communication->channel
    simplebilly_api_communication_channel__e channel_local_nonprim = 0;

    char *contact_id_local_str = NULL;

    char *counterparty_local_str = NULL;

    // define the local variable for customer_communication->direction
    simplebilly_api_communication_direction__e direction_local_nonprim = 0;

    char *occurred_at_local_str = NULL;

    char *subject_local_str = NULL;

    // define the local variable for customer_communication->tags
    _t *tags_local_nonprim = NULL;

    // customer_communication->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "body");
    if (cJSON_IsNull(body)) {
        body = NULL;
    }
    if (body) { 
    if(!cJSON_IsString(body) && !cJSON_IsNull(body))
    {
    goto end; //String
    }
    }

    // customer_communication->channel
    cJSON *channel = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "channel");
    if (cJSON_IsNull(channel)) {
        channel = NULL;
    }
    if (!channel) {
        goto end;
    }

    
    channel_local_nonprim = communication_channel_parseFromJSON(channel); //custom

    // customer_communication->contact_id
    cJSON *contact_id = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "contactId");
    if (cJSON_IsNull(contact_id)) {
        contact_id = NULL;
    }
    if (!contact_id) {
        goto end;
    }

    
    if(!cJSON_IsString(contact_id))
    {
    goto end; //String
    }

    // customer_communication->counterparty
    cJSON *counterparty = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "counterparty");
    if (cJSON_IsNull(counterparty)) {
        counterparty = NULL;
    }
    if (counterparty) { 
    if(!cJSON_IsString(counterparty) && !cJSON_IsNull(counterparty))
    {
    goto end; //String
    }
    }

    // customer_communication->direction
    cJSON *direction = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "direction");
    if (cJSON_IsNull(direction)) {
        direction = NULL;
    }
    if (!direction) {
        goto end;
    }

    
    direction_local_nonprim = communication_direction_parseFromJSON(direction); //custom

    // customer_communication->occurred_at
    cJSON *occurred_at = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "occurredAt");
    if (cJSON_IsNull(occurred_at)) {
        occurred_at = NULL;
    }
    if (occurred_at) { 
    if(!cJSON_IsString(occurred_at) && !cJSON_IsNull(occurred_at))
    {
    goto end; //DateTime
    }
    }

    // customer_communication->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "subject");
    if (cJSON_IsNull(subject)) {
        subject = NULL;
    }
    if (subject) { 
    if(!cJSON_IsString(subject) && !cJSON_IsNull(subject))
    {
    goto end; //String
    }
    }

    // customer_communication->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(customer_communicationJSON, "tags");
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

    customer_communication_local_var = customer_communication_create_internal (
        body_local_str,
        channel_local_nonprim,
        contact_id_local_str,
        counterparty_local_str,
        direction_local_nonprim,
        occurred_at_local_str,
        subject_local_str,
        tags ? tags_local_nonprim : NULL
        );

    if (!customer_communication_local_var) {
        goto end;
    }

    return customer_communication_local_var;
end:
    if (body_local_str) {
        free(body_local_str);
        body_local_str = NULL;
    }
    if (channel_local_nonprim) {
        channel_local_nonprim = 0;
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
        direction_local_nonprim = 0;
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
