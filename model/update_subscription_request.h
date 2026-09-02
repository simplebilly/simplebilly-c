/*
 * update_subscription_request.h
 *
 * 
 */

#ifndef _update_subscription_request_H_
#define _update_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_subscription_request_t update_subscription_request_t;




typedef struct update_subscription_request_t {
    char *event_type; // string
    int *is_active; //boolean
    char *name; // string
    char *secret; // string
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_subscription_request_t;

__attribute__((deprecated)) update_subscription_request_t *update_subscription_request_create(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
);

void update_subscription_request_free(update_subscription_request_t *update_subscription_request);

update_subscription_request_t *update_subscription_request_parseFromJSON(cJSON *update_subscription_requestJSON);

cJSON *update_subscription_request_convertToJSON(update_subscription_request_t *update_subscription_request);

#endif /* _update_subscription_request_H_ */

