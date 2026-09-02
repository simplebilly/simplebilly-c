/*
 * contact_history_response.h
 *
 * Aggregated history for a single contact: all communications plus a lightweight per-channel breakdown.
 */

#ifndef _contact_history_response_H_
#define _contact_history_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_history_response_t contact_history_response_t;

#include "customer_communication.h"



typedef struct contact_history_response_t {
    char *contact_id; // string
    long *inbound_count; //numeric
    list_t *items; //nonprimitive container
    long *outbound_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} contact_history_response_t;

__attribute__((deprecated)) contact_history_response_t *contact_history_response_create(
    char *contact_id,
    long *inbound_count,
    list_t *items,
    long *outbound_count
);

void contact_history_response_free(contact_history_response_t *contact_history_response);

contact_history_response_t *contact_history_response_parseFromJSON(cJSON *contact_history_responseJSON);

cJSON *contact_history_response_convertToJSON(contact_history_response_t *contact_history_response);

#endif /* _contact_history_response_H_ */

