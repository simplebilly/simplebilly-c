/*
 * accept_invite_request.h
 *
 * 
 */

#ifndef _accept_invite_request_H_
#define _accept_invite_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct accept_invite_request_t accept_invite_request_t;




typedef struct accept_invite_request_t {
    char *first_name; // string
    char *last_name; // string
    char *password; // string
    int *privacy_accepted; //boolean
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} accept_invite_request_t;

__attribute__((deprecated)) accept_invite_request_t *accept_invite_request_create(
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted,
    char *token
);

void accept_invite_request_free(accept_invite_request_t *accept_invite_request);

accept_invite_request_t *accept_invite_request_parseFromJSON(cJSON *accept_invite_requestJSON);

cJSON *accept_invite_request_convertToJSON(accept_invite_request_t *accept_invite_request);

#endif /* _accept_invite_request_H_ */

