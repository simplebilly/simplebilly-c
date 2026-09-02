/*
 * support_ticket.h
 *
 * 
 */

#ifndef _support_ticket_H_
#define _support_ticket_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct support_ticket_t support_ticket_t;

#include "any_type.h"
#include "support_channel_type.h"
#include "support_ticket_status.h"
#include "ticket_priority.h"



typedef struct support_ticket_t {
    char *assigned_to; // string
    char *channel_id; // string
    support_channel_type_t *channel_type; // custom
    char *closed_at; //date time
    char *created_at; //date time
    char *customer_email; // string
    char *customer_id; // string
    char *customer_name; // string
    char *external_id; // string
    char *first_message_at; //date time
    char *last_message_at; //date time
    char *lead_id; // string
    int *message_count; //numeric
    char *order_ref; // string
    simplebilly_api_ticket_priority__e priority; //referenced enum
    char *resolution; // string
    simplebilly_api_support_ticket_status__e status; //referenced enum
    char *subject; // string
    any_type_t *tags; // custom
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} support_ticket_t;

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
);

void support_ticket_free(support_ticket_t *support_ticket);

support_ticket_t *support_ticket_parseFromJSON(cJSON *support_ticketJSON);

cJSON *support_ticket_convertToJSON(support_ticket_t *support_ticket);

#endif /* _support_ticket_H_ */

