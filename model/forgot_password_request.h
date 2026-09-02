/*
 * forgot_password_request.h
 *
 * 
 */

#ifndef _forgot_password_request_H_
#define _forgot_password_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forgot_password_request_t forgot_password_request_t;




typedef struct forgot_password_request_t {
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} forgot_password_request_t;

__attribute__((deprecated)) forgot_password_request_t *forgot_password_request_create(
    char *email
);

void forgot_password_request_free(forgot_password_request_t *forgot_password_request);

forgot_password_request_t *forgot_password_request_parseFromJSON(cJSON *forgot_password_requestJSON);

cJSON *forgot_password_request_convertToJSON(forgot_password_request_t *forgot_password_request);

#endif /* _forgot_password_request_H_ */

