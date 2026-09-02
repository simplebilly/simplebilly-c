/*
 * create_connection_request.h
 *
 * 
 */

#ifndef _create_connection_request_H_
#define _create_connection_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_connection_request_t create_connection_request_t;

#include "any_type.h"



typedef struct create_connection_request_t {
    char *api_key; // string
    char *api_secret; // string
    any_type_t *config; // custom
    char *label; // string
    char *platform; // string
    char *shop_domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_connection_request_t;

__attribute__((deprecated)) create_connection_request_t *create_connection_request_create(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    char *label,
    char *platform,
    char *shop_domain
);

void create_connection_request_free(create_connection_request_t *create_connection_request);

create_connection_request_t *create_connection_request_parseFromJSON(cJSON *create_connection_requestJSON);

cJSON *create_connection_request_convertToJSON(create_connection_request_t *create_connection_request);

#endif /* _create_connection_request_H_ */

