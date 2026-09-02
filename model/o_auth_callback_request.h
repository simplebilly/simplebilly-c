/*
 * o_auth_callback_request.h
 *
 * 
 */

#ifndef _o_auth_callback_request_H_
#define _o_auth_callback_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_callback_request_t o_auth_callback_request_t;

#include "any_type.h"



typedef struct o_auth_callback_request_t {
    char *code; // string
    any_type_t *config; // custom
    char *connection_id; // string
    char *platform; // string
    char *shop_domain; // string
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_callback_request_t;

__attribute__((deprecated)) o_auth_callback_request_t *o_auth_callback_request_create(
    char *code,
    any_type_t *config,
    char *connection_id,
    char *platform,
    char *shop_domain,
    char *state
);

void o_auth_callback_request_free(o_auth_callback_request_t *o_auth_callback_request);

o_auth_callback_request_t *o_auth_callback_request_parseFromJSON(cJSON *o_auth_callback_requestJSON);

cJSON *o_auth_callback_request_convertToJSON(o_auth_callback_request_t *o_auth_callback_request);

#endif /* _o_auth_callback_request_H_ */

