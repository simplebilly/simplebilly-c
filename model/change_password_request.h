/*
 * change_password_request.h
 *
 * 
 */

#ifndef _change_password_request_H_
#define _change_password_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct change_password_request_t change_password_request_t;




typedef struct change_password_request_t {
    char *current_password; // string
    char *new_password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} change_password_request_t;

__attribute__((deprecated)) change_password_request_t *change_password_request_create(
    char *current_password,
    char *new_password
);

void change_password_request_free(change_password_request_t *change_password_request);

change_password_request_t *change_password_request_parseFromJSON(cJSON *change_password_requestJSON);

cJSON *change_password_request_convertToJSON(change_password_request_t *change_password_request);

#endif /* _change_password_request_H_ */

