/*
 * ticket_message.h
 *
 * 
 */

#ifndef _ticket_message_H_
#define _ticket_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ticket_message_t ticket_message_t;

#include "any_type.h"
#include "message_direction.h"
#include "message_type.h"



typedef struct ticket_message_t {
    char *author_email; // string
    char *author_name; // string
    char *body; // string
    char *body_html; // string
    char *channel_id; // string
    char *created_at; //date time
    simplebilly_api_message_direction__e direction; //referenced enum
    char *external_id; // string
    int *is_internal; //boolean
    simplebilly_api_message_type__e message_type; //referenced enum
    any_type_t *metadata; // custom
    char *tenant_id; // string
    char *ticket_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ticket_message_t;

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
);

void ticket_message_free(ticket_message_t *ticket_message);

ticket_message_t *ticket_message_parseFromJSON(cJSON *ticket_messageJSON);

cJSON *ticket_message_convertToJSON(ticket_message_t *ticket_message);

#endif /* _ticket_message_H_ */

