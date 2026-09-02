/*
 * event_subscription.h
 *
 * 
 */

#ifndef _event_subscription_H_
#define _event_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct event_subscription_t event_subscription_t;




typedef struct event_subscription_t {
    char *callback_url; // string
    char *event_type; // string
    int *is_active; //boolean
    char *subscription_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} event_subscription_t;

__attribute__((deprecated)) event_subscription_t *event_subscription_create(
    char *callback_url,
    char *event_type,
    int *is_active,
    char *subscription_id
);

void event_subscription_free(event_subscription_t *event_subscription);

event_subscription_t *event_subscription_parseFromJSON(cJSON *event_subscriptionJSON);

cJSON *event_subscription_convertToJSON(event_subscription_t *event_subscription);

#endif /* _event_subscription_H_ */

