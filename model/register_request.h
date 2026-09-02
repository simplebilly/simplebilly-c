/*
 * register_request.h
 *
 * 
 */

#ifndef _register_request_H_
#define _register_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct register_request_t register_request_t;




typedef struct register_request_t {
    char *company_name; // string
    char *email; // string
    char *first_name; // string
    char *last_name; // string
    char *password; // string
    int *privacy_accepted; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} register_request_t;

__attribute__((deprecated)) register_request_t *register_request_create(
    char *company_name,
    char *email,
    char *first_name,
    char *last_name,
    char *password,
    int *privacy_accepted
);

void register_request_free(register_request_t *register_request);

register_request_t *register_request_parseFromJSON(cJSON *register_requestJSON);

cJSON *register_request_convertToJSON(register_request_t *register_request);

#endif /* _register_request_H_ */

