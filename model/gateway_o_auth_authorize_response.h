/*
 * gateway_o_auth_authorize_response.h
 *
 * 
 */

#ifndef _gateway_o_auth_authorize_response_H_
#define _gateway_o_auth_authorize_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gateway_o_auth_authorize_response_t gateway_o_auth_authorize_response_t;




typedef struct gateway_o_auth_authorize_response_t {
    char *authorization_url; // string
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gateway_o_auth_authorize_response_t;

__attribute__((deprecated)) gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_create(
    char *authorization_url,
    char *state
);

void gateway_o_auth_authorize_response_free(gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response);

gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response_parseFromJSON(cJSON *gateway_o_auth_authorize_responseJSON);

cJSON *gateway_o_auth_authorize_response_convertToJSON(gateway_o_auth_authorize_response_t *gateway_o_auth_authorize_response);

#endif /* _gateway_o_auth_authorize_response_H_ */

