/*
 * webhook_subscription.h
 *
 * 
 */

#ifndef _webhook_subscription_H_
#define _webhook_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct webhook_subscription_t webhook_subscription_t;




typedef struct webhook_subscription_t {
    char *event_type; // string
    int *is_active; //boolean
    char *name; // string
    char *secret; // string
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} webhook_subscription_t;

__attribute__((deprecated)) webhook_subscription_t *webhook_subscription_create(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
);

void webhook_subscription_free(webhook_subscription_t *webhook_subscription);

webhook_subscription_t *webhook_subscription_parseFromJSON(cJSON *webhook_subscriptionJSON);

cJSON *webhook_subscription_convertToJSON(webhook_subscription_t *webhook_subscription);

#endif /* _webhook_subscription_H_ */

