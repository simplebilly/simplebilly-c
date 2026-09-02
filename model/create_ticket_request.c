#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_ticket_request.h"



static create_ticket_request_t *create_ticket_request_create_internal(
    char *channel_id,
    char *channel_type,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *external_id,
    char *message_body,
    char *order_ref,
    char *subject
    ) {
    create_ticket_request_t *create_ticket_request_local_var = malloc(sizeof(create_ticket_request_t));
    if (!create_ticket_request_local_var) {
        return NULL;
    }
    memset(create_ticket_request_local_var, 0, sizeof(create_ticket_request_t));
    create_ticket_request_local_var->_library_owned = 1;
    create_ticket_request_local_var->channel_id = channel_id;
    create_ticket_request_local_var->channel_type = channel_type;
    create_ticket_request_local_var->customer_email = customer_email;
    create_ticket_request_local_var->customer_id = customer_id;
    create_ticket_request_local_var->customer_name = customer_name;
    create_ticket_request_local_var->external_id = external_id;
    create_ticket_request_local_var->message_body = message_body;
    create_ticket_request_local_var->order_ref = order_ref;
    create_ticket_request_local_var->subject = subject;
    return create_ticket_request_local_var;
}

__attribute__((deprecated)) create_ticket_request_t *create_ticket_request_create(
    char *channel_id,
    char *channel_type,
    char *customer_email,
    char *customer_id,
    char *customer_name,
    char *external_id,
    char *message_body,
    char *order_ref,
    char *subject
    ) {
    create_ticket_request_t *result = create_ticket_request_create_internal (
        channel_id,
        channel_type,
        customer_email,
        customer_id,
        customer_name,
        external_id,
        message_body,
        order_ref,
        subject
        );
    if (!result) {
    }
    return result;
}

void create_ticket_request_free(create_ticket_request_t *create_ticket_request) {
    if(NULL == create_ticket_request){
        return ;
    }
    if(create_ticket_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_ticket_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_ticket_request->channel_id) {
        free(create_ticket_request->channel_id);
        create_ticket_request->channel_id = NULL;
    }
    if (create_ticket_request->channel_type) {
        free(create_ticket_request->channel_type);
        create_ticket_request->channel_type = NULL;
    }
    if (create_ticket_request->customer_email) {
        free(create_ticket_request->customer_email);
        create_ticket_request->customer_email = NULL;
    }
    if (create_ticket_request->customer_id) {
        free(create_ticket_request->customer_id);
        create_ticket_request->customer_id = NULL;
    }
    if (create_ticket_request->customer_name) {
        free(create_ticket_request->customer_name);
        create_ticket_request->customer_name = NULL;
    }
    if (create_ticket_request->external_id) {
        free(create_ticket_request->external_id);
        create_ticket_request->external_id = NULL;
    }
    if (create_ticket_request->message_body) {
        free(create_ticket_request->message_body);
        create_ticket_request->message_body = NULL;
    }
    if (create_ticket_request->order_ref) {
        free(create_ticket_request->order_ref);
        create_ticket_request->order_ref = NULL;
    }
    if (create_ticket_request->subject) {
        free(create_ticket_request->subject);
        create_ticket_request->subject = NULL;
    }
    free(create_ticket_request);
}

cJSON *create_ticket_request_convertToJSON(create_ticket_request_t *create_ticket_request) {
    cJSON *item = cJSON_CreateObject();

    // create_ticket_request->channel_id
    if(create_ticket_request->channel_id) {
    if(cJSON_AddStringToObject(item, "channel_id", create_ticket_request->channel_id) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->channel_type
    if(create_ticket_request->channel_type) {
    if(cJSON_AddStringToObject(item, "channel_type", create_ticket_request->channel_type) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->customer_email
    if(create_ticket_request->customer_email) {
    if(cJSON_AddStringToObject(item, "customer_email", create_ticket_request->customer_email) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->customer_id
    if(create_ticket_request->customer_id) {
    if(cJSON_AddStringToObject(item, "customer_id", create_ticket_request->customer_id) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->customer_name
    if(create_ticket_request->customer_name) {
    if(cJSON_AddStringToObject(item, "customer_name", create_ticket_request->customer_name) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->external_id
    if(create_ticket_request->external_id) {
    if(cJSON_AddStringToObject(item, "external_id", create_ticket_request->external_id) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->message_body
    if (!create_ticket_request->message_body) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_body", create_ticket_request->message_body) == NULL) {
    goto fail; //String
    }


    // create_ticket_request->order_ref
    if(create_ticket_request->order_ref) {
    if(cJSON_AddStringToObject(item, "order_ref", create_ticket_request->order_ref) == NULL) {
    goto fail; //String
    }
    }


    // create_ticket_request->subject
    if (!create_ticket_request->subject) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject", create_ticket_request->subject) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_ticket_request_t *create_ticket_request_parseFromJSON(cJSON *create_ticket_requestJSON){

    create_ticket_request_t *create_ticket_request_local_var = NULL;

    char *channel_id_local_str = NULL;

    char *channel_type_local_str = NULL;

    char *customer_email_local_str = NULL;

    char *customer_id_local_str = NULL;

    char *customer_name_local_str = NULL;

    char *external_id_local_str = NULL;

    char *message_body_local_str = NULL;

    char *order_ref_local_str = NULL;

    char *subject_local_str = NULL;

    // create_ticket_request->channel_id
    cJSON *channel_id = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "channel_id");
    if (cJSON_IsNull(channel_id)) {
        channel_id = NULL;
    }
    if (channel_id) { 
    if(!cJSON_IsString(channel_id) && !cJSON_IsNull(channel_id))
    {
    goto end; //String
    }
    }

    // create_ticket_request->channel_type
    cJSON *channel_type = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "channel_type");
    if (cJSON_IsNull(channel_type)) {
        channel_type = NULL;
    }
    if (channel_type) { 
    if(!cJSON_IsString(channel_type) && !cJSON_IsNull(channel_type))
    {
    goto end; //String
    }
    }

    // create_ticket_request->customer_email
    cJSON *customer_email = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "customer_email");
    if (cJSON_IsNull(customer_email)) {
        customer_email = NULL;
    }
    if (customer_email) { 
    if(!cJSON_IsString(customer_email) && !cJSON_IsNull(customer_email))
    {
    goto end; //String
    }
    }

    // create_ticket_request->customer_id
    cJSON *customer_id = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "customer_id");
    if (cJSON_IsNull(customer_id)) {
        customer_id = NULL;
    }
    if (customer_id) { 
    if(!cJSON_IsString(customer_id) && !cJSON_IsNull(customer_id))
    {
    goto end; //String
    }
    }

    // create_ticket_request->customer_name
    cJSON *customer_name = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "customer_name");
    if (cJSON_IsNull(customer_name)) {
        customer_name = NULL;
    }
    if (customer_name) { 
    if(!cJSON_IsString(customer_name) && !cJSON_IsNull(customer_name))
    {
    goto end; //String
    }
    }

    // create_ticket_request->external_id
    cJSON *external_id = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "external_id");
    if (cJSON_IsNull(external_id)) {
        external_id = NULL;
    }
    if (external_id) { 
    if(!cJSON_IsString(external_id) && !cJSON_IsNull(external_id))
    {
    goto end; //String
    }
    }

    // create_ticket_request->message_body
    cJSON *message_body = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "message_body");
    if (cJSON_IsNull(message_body)) {
        message_body = NULL;
    }
    if (!message_body) {
        goto end;
    }

    
    if(!cJSON_IsString(message_body))
    {
    goto end; //String
    }

    // create_ticket_request->order_ref
    cJSON *order_ref = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "order_ref");
    if (cJSON_IsNull(order_ref)) {
        order_ref = NULL;
    }
    if (order_ref) { 
    if(!cJSON_IsString(order_ref) && !cJSON_IsNull(order_ref))
    {
    goto end; //String
    }
    }

    // create_ticket_request->subject
    cJSON *subject = cJSON_GetObjectItemCaseSensitive(create_ticket_requestJSON, "subject");
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


    if (channel_id && !cJSON_IsNull(channel_id)) channel_id_local_str = strdup(channel_id->valuestring);
    if (channel_type && !cJSON_IsNull(channel_type)) channel_type_local_str = strdup(channel_type->valuestring);
    if (customer_email && !cJSON_IsNull(customer_email)) customer_email_local_str = strdup(customer_email->valuestring);
    if (customer_id && !cJSON_IsNull(customer_id)) customer_id_local_str = strdup(customer_id->valuestring);
    if (customer_name && !cJSON_IsNull(customer_name)) customer_name_local_str = strdup(customer_name->valuestring);
    if (external_id && !cJSON_IsNull(external_id)) external_id_local_str = strdup(external_id->valuestring);
    if (message_body && !cJSON_IsNull(message_body)) message_body_local_str = strdup(message_body->valuestring);
    if (order_ref && !cJSON_IsNull(order_ref)) order_ref_local_str = strdup(order_ref->valuestring);
    if (subject && !cJSON_IsNull(subject)) subject_local_str = strdup(subject->valuestring);

    create_ticket_request_local_var = create_ticket_request_create_internal (
        channel_id_local_str,
        channel_type_local_str,
        customer_email_local_str,
        customer_id_local_str,
        customer_name_local_str,
        external_id_local_str,
        message_body_local_str,
        order_ref_local_str,
        subject_local_str
        );

    if (!create_ticket_request_local_var) {
        goto end;
    }

    return create_ticket_request_local_var;
end:
    if (channel_id_local_str) {
        free(channel_id_local_str);
        channel_id_local_str = NULL;
    }
    if (channel_type_local_str) {
        free(channel_type_local_str);
        channel_type_local_str = NULL;
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
    if (message_body_local_str) {
        free(message_body_local_str);
        message_body_local_str = NULL;
    }
    if (order_ref_local_str) {
        free(order_ref_local_str);
        order_ref_local_str = NULL;
    }
    if (subject_local_str) {
        free(subject_local_str);
        subject_local_str = NULL;
    }
    return NULL;

}
