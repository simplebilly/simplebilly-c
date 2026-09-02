/*
 * o_auth_authorize_request.h
 *
 * 
 */

#ifndef _o_auth_authorize_request_H_
#define _o_auth_authorize_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_authorize_request_t o_auth_authorize_request_t;

#include "any_type.h"



typedef struct o_auth_authorize_request_t {
    any_type_t *config; // custom
    char *platform; // string
    char *redirect_uri; // string

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_authorize_request_t;

__attribute__((deprecated)) o_auth_authorize_request_t *o_auth_authorize_request_create(
    any_type_t *config,
    char *platform,
    char *redirect_uri
);

void o_auth_authorize_request_free(o_auth_authorize_request_t *o_auth_authorize_request);

o_auth_authorize_request_t *o_auth_authorize_request_parseFromJSON(cJSON *o_auth_authorize_requestJSON);

cJSON *o_auth_authorize_request_convertToJSON(o_auth_authorize_request_t *o_auth_authorize_request);

#endif /* _o_auth_authorize_request_H_ */

