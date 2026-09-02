/*
 * customer_communication_update.h
 *
 * 
 */

#ifndef _customer_communication_update_H_
#define _customer_communication_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_communication_update_t customer_communication_update_t;

#include "any_type.h"
#include "communication_channel.h"
#include "communication_direction.h"



typedef struct customer_communication_update_t {
    char *body; // string
    communication_channel_t *channel; // custom
    char *contact_id; // string
    char *counterparty; // string
    communication_direction_t *direction; // custom
    char *occurred_at; //date time
    char *subject; // string
    any_type_t *tags; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} customer_communication_update_t;

__attribute__((deprecated)) customer_communication_update_t *customer_communication_update_create(
    char *body,
    communication_channel_t *channel,
    char *contact_id,
    char *counterparty,
    communication_direction_t *direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
);

void customer_communication_update_free(customer_communication_update_t *customer_communication_update);

customer_communication_update_t *customer_communication_update_parseFromJSON(cJSON *customer_communication_updateJSON);

cJSON *customer_communication_update_convertToJSON(customer_communication_update_t *customer_communication_update);

#endif /* _customer_communication_update_H_ */

