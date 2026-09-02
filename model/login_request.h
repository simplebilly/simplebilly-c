/*
 * login_request.h
 *
 * 
 */

#ifndef _login_request_H_
#define _login_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_request_t login_request_t;




typedef struct login_request_t {
    char *email; // string
    char *password; // string
    char *totp_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} login_request_t;

__attribute__((deprecated)) login_request_t *login_request_create(
    char *email,
    char *password,
    char *totp_code
);

void login_request_free(login_request_t *login_request);

login_request_t *login_request_parseFromJSON(cJSON *login_requestJSON);

cJSON *login_request_convertToJSON(login_request_t *login_request);

#endif /* _login_request_H_ */

