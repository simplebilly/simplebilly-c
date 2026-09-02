/*
 * create_ticket_request.h
 *
 * Request body for creating a support ticket. Wraps the generated &#x60;SupportTicketCreateDto&#x60; fields plus &#x60;message_body&#x60; which is not a Model field (used to create the initial &#x60;ticket_message&#x60;).
 */

#ifndef _create_ticket_request_H_
#define _create_ticket_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_ticket_request_t create_ticket_request_t;




typedef struct create_ticket_request_t {
    char *channel_id; // string
    char *channel_type; // string
    char *customer_email; // string
    char *customer_id; // string
    char *customer_name; // string
    char *external_id; // string
    char *message_body; // string
    char *order_ref; // string
    char *subject; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_ticket_request_t;

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
);

void create_ticket_request_free(create_ticket_request_t *create_ticket_request);

create_ticket_request_t *create_ticket_request_parseFromJSON(cJSON *create_ticket_requestJSON);

cJSON *create_ticket_request_convertToJSON(create_ticket_request_t *create_ticket_request);

#endif /* _create_ticket_request_H_ */

