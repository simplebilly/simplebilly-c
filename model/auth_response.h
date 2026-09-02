/*
 * auth_response.h
 *
 * 
 */

#ifndef _auth_response_H_
#define _auth_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct auth_response_t auth_response_t;

#include "model.h"



typedef struct auth_response_t {
    char *access_token; // string
    char *message; // string
    char *refresh_token; // string
    int *success; //boolean
    struct model_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} auth_response_t;

__attribute__((deprecated)) auth_response_t *auth_response_create(
    char *access_token,
    char *message,
    char *refresh_token,
    int *success,
    model_t *user
);

void auth_response_free(auth_response_t *auth_response);

auth_response_t *auth_response_parseFromJSON(cJSON *auth_responseJSON);

cJSON *auth_response_convertToJSON(auth_response_t *auth_response);

#endif /* _auth_response_H_ */

