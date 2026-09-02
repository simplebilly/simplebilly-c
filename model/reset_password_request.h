/*
 * reset_password_request.h
 *
 * 
 */

#ifndef _reset_password_request_H_
#define _reset_password_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reset_password_request_t reset_password_request_t;




typedef struct reset_password_request_t {
    char *new_password; // string
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reset_password_request_t;

__attribute__((deprecated)) reset_password_request_t *reset_password_request_create(
    char *new_password,
    char *token
);

void reset_password_request_free(reset_password_request_t *reset_password_request);

reset_password_request_t *reset_password_request_parseFromJSON(cJSON *reset_password_requestJSON);

cJSON *reset_password_request_convertToJSON(reset_password_request_t *reset_password_request);

#endif /* _reset_password_request_H_ */

