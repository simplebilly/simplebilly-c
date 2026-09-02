/*
 * update_connection_request.h
 *
 * 
 */

#ifndef _update_connection_request_H_
#define _update_connection_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_connection_request_t update_connection_request_t;

#include "any_type.h"



typedef struct update_connection_request_t {
    char *api_key; // string
    char *api_secret; // string
    any_type_t *config; // custom
    int *is_active; //boolean
    char *label; // string
    char *shop_domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_connection_request_t;

__attribute__((deprecated)) update_connection_request_t *update_connection_request_create(
    char *api_key,
    char *api_secret,
    any_type_t *config,
    int *is_active,
    char *label,
    char *shop_domain
);

void update_connection_request_free(update_connection_request_t *update_connection_request);

update_connection_request_t *update_connection_request_parseFromJSON(cJSON *update_connection_requestJSON);

cJSON *update_connection_request_convertToJSON(update_connection_request_t *update_connection_request);

#endif /* _update_connection_request_H_ */

