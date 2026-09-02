/*
 * remove_user_request.h
 *
 * 
 */

#ifndef _remove_user_request_H_
#define _remove_user_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_user_request_t remove_user_request_t;




typedef struct remove_user_request_t {
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} remove_user_request_t;

__attribute__((deprecated)) remove_user_request_t *remove_user_request_create(
    char *email
);

void remove_user_request_free(remove_user_request_t *remove_user_request);

remove_user_request_t *remove_user_request_parseFromJSON(cJSON *remove_user_requestJSON);

cJSON *remove_user_request_convertToJSON(remove_user_request_t *remove_user_request);

#endif /* _remove_user_request_H_ */

