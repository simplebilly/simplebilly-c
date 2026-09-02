/*
 * customer_communication.h
 *
 * 
 */

#ifndef _customer_communication_H_
#define _customer_communication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct customer_communication_t customer_communication_t;

#include "any_type.h"
#include "communication_channel.h"
#include "communication_direction.h"



typedef struct customer_communication_t {
    char *body; // string
    simplebilly_api_communication_channel__e channel; //referenced enum
    char *contact_id; // string
    char *counterparty; // string
    simplebilly_api_communication_direction__e direction; //referenced enum
    char *occurred_at; //date time
    char *subject; // string
    any_type_t *tags; // custom

    int _library_owned; // Is the library responsible for freeing this object?
} customer_communication_t;

__attribute__((deprecated)) customer_communication_t *customer_communication_create(
    char *body,
    simplebilly_api_communication_channel__e channel,
    char *contact_id,
    char *counterparty,
    simplebilly_api_communication_direction__e direction,
    char *occurred_at,
    char *subject,
    any_type_t *tags
);

void customer_communication_free(customer_communication_t *customer_communication);

customer_communication_t *customer_communication_parseFromJSON(cJSON *customer_communicationJSON);

cJSON *customer_communication_convertToJSON(customer_communication_t *customer_communication);

#endif /* _customer_communication_H_ */

