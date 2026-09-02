/*
 * verify_email_request.h
 *
 * 
 */

#ifndef _verify_email_request_H_
#define _verify_email_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct verify_email_request_t verify_email_request_t;




typedef struct verify_email_request_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} verify_email_request_t;

__attribute__((deprecated)) verify_email_request_t *verify_email_request_create(
    char *token
);

void verify_email_request_free(verify_email_request_t *verify_email_request);

verify_email_request_t *verify_email_request_parseFromJSON(cJSON *verify_email_requestJSON);

cJSON *verify_email_request_convertToJSON(verify_email_request_t *verify_email_request);

#endif /* _verify_email_request_H_ */

