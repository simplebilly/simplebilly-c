/*
 * gateway_o_auth_authorize_request.h
 *
 * 
 */

#ifndef _gateway_o_auth_authorize_request_H_
#define _gateway_o_auth_authorize_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gateway_o_auth_authorize_request_t gateway_o_auth_authorize_request_t;




typedef struct gateway_o_auth_authorize_request_t {
    char *gateway_type; // string
    char *redirect_uri; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gateway_o_auth_authorize_request_t;

__attribute__((deprecated)) gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_create(
    char *gateway_type,
    char *redirect_uri
);

void gateway_o_auth_authorize_request_free(gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request);

gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request_parseFromJSON(cJSON *gateway_o_auth_authorize_requestJSON);

cJSON *gateway_o_auth_authorize_request_convertToJSON(gateway_o_auth_authorize_request_t *gateway_o_auth_authorize_request);

#endif /* _gateway_o_auth_authorize_request_H_ */

