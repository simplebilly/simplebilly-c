/*
 * totp_enable_request.h
 *
 * 
 */

#ifndef _totp_enable_request_H_
#define _totp_enable_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_enable_request_t totp_enable_request_t;




typedef struct totp_enable_request_t {
    char *code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_enable_request_t;

__attribute__((deprecated)) totp_enable_request_t *totp_enable_request_create(
    char *code
);

void totp_enable_request_free(totp_enable_request_t *totp_enable_request);

totp_enable_request_t *totp_enable_request_parseFromJSON(cJSON *totp_enable_requestJSON);

cJSON *totp_enable_request_convertToJSON(totp_enable_request_t *totp_enable_request);

#endif /* _totp_enable_request_H_ */

