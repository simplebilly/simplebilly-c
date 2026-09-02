/*
 * invite_request.h
 *
 * 
 */

#ifndef _invite_request_H_
#define _invite_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_request_t invite_request_t;




typedef struct invite_request_t {
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invite_request_t;

__attribute__((deprecated)) invite_request_t *invite_request_create(
    char *email
);

void invite_request_free(invite_request_t *invite_request);

invite_request_t *invite_request_parseFromJSON(cJSON *invite_requestJSON);

cJSON *invite_request_convertToJSON(invite_request_t *invite_request);

#endif /* _invite_request_H_ */

