/*
 * support_ticket_update.h
 *
 * 
 */

#ifndef _support_ticket_update_H_
#define _support_ticket_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct support_ticket_update_t support_ticket_update_t;

#include "any_type.h"
#include "support_channel_type.h"
#include "support_ticket_status.h"
#include "ticket_priority.h"



typedef struct support_ticket_update_t {
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
    ticket_priority_t *priority; // custom
    char *resolution; // string
    support_ticket_status_t *status; // custom
    char *subject; // string
    any_type_t *tags; // custom
    char *tenant_id; // string
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} support_ticket_update_t;

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
);

void support_ticket_update_free(support_ticket_update_t *support_ticket_update);

support_ticket_update_t *support_ticket_update_parseFromJSON(cJSON *support_ticket_updateJSON);

cJSON *support_ticket_update_convertToJSON(support_ticket_update_t *support_ticket_update);

#endif /* _support_ticket_update_H_ */

