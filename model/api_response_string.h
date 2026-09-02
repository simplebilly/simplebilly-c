/*
 * api_response_string.h
 *
 * 
 */

#ifndef _api_response_string_H_
#define _api_response_string_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_response_string_t api_response_string_t;




typedef struct api_response_string_t {
    char *data; // string
    char *error; // string
    char *message; // string
    int *success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} api_response_string_t;

__attribute__((deprecated)) api_response_string_t *api_response_string_create(
    char *data,
    char *error,
    char *message,
    int *success
);

void api_response_string_free(api_response_string_t *api_response_string);

api_response_string_t *api_response_string_parseFromJSON(cJSON *api_response_stringJSON);

cJSON *api_response_string_convertToJSON(api_response_string_t *api_response_string);

#endif /* _api_response_string_H_ */

