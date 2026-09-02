/*
 * create_subscription_request.h
 *
 * 
 */

#ifndef _create_subscription_request_H_
#define _create_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_subscription_request_t create_subscription_request_t;




typedef struct create_subscription_request_t {
    char *event_type; // string
    int *is_active; //boolean
    char *name; // string
    char *secret; // string
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_subscription_request_t;

__attribute__((deprecated)) create_subscription_request_t *create_subscription_request_create(
    char *event_type,
    int *is_active,
    char *name,
    char *secret,
    char *url
);

void create_subscription_request_free(create_subscription_request_t *create_subscription_request);

create_subscription_request_t *create_subscription_request_parseFromJSON(cJSON *create_subscription_requestJSON);

cJSON *create_subscription_request_convertToJSON(create_subscription_request_t *create_subscription_request);

#endif /* _create_subscription_request_H_ */

