/*
 * o_auth_authorize_response.h
 *
 * 
 */

#ifndef _o_auth_authorize_response_H_
#define _o_auth_authorize_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_authorize_response_t o_auth_authorize_response_t;




typedef struct o_auth_authorize_response_t {
    char *authorization_url; // string
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_authorize_response_t;

__attribute__((deprecated)) o_auth_authorize_response_t *o_auth_authorize_response_create(
    char *authorization_url,
    char *state
);

void o_auth_authorize_response_free(o_auth_authorize_response_t *o_auth_authorize_response);

o_auth_authorize_response_t *o_auth_authorize_response_parseFromJSON(cJSON *o_auth_authorize_responseJSON);

cJSON *o_auth_authorize_response_convertToJSON(o_auth_authorize_response_t *o_auth_authorize_response);

#endif /* _o_auth_authorize_response_H_ */

