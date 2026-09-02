/*
 * magic_link_verify_request.h
 *
 * 
 */

#ifndef _magic_link_verify_request_H_
#define _magic_link_verify_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct magic_link_verify_request_t magic_link_verify_request_t;




typedef struct magic_link_verify_request_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} magic_link_verify_request_t;

__attribute__((deprecated)) magic_link_verify_request_t *magic_link_verify_request_create(
    char *token
);

void magic_link_verify_request_free(magic_link_verify_request_t *magic_link_verify_request);

magic_link_verify_request_t *magic_link_verify_request_parseFromJSON(cJSON *magic_link_verify_requestJSON);

cJSON *magic_link_verify_request_convertToJSON(magic_link_verify_request_t *magic_link_verify_request);

#endif /* _magic_link_verify_request_H_ */

