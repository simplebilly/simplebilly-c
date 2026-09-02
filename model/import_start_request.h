/*
 * import_start_request.h
 *
 * 
 */

#ifndef _import_start_request_H_
#define _import_start_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct import_start_request_t import_start_request_t;




typedef struct import_start_request_t {
    char *api_key; // string
    char *provider; // string
    list_t *years; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} import_start_request_t;

__attribute__((deprecated)) import_start_request_t *import_start_request_create(
    char *api_key,
    char *provider,
    list_t *years
);

void import_start_request_free(import_start_request_t *import_start_request);

import_start_request_t *import_start_request_parseFromJSON(cJSON *import_start_requestJSON);

cJSON *import_start_request_convertToJSON(import_start_request_t *import_start_request);

#endif /* _import_start_request_H_ */

