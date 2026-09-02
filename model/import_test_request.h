/*
 * import_test_request.h
 *
 * 
 */

#ifndef _import_test_request_H_
#define _import_test_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct import_test_request_t import_test_request_t;




typedef struct import_test_request_t {
    char *api_key; // string
    char *provider; // string

    int _library_owned; // Is the library responsible for freeing this object?
} import_test_request_t;

__attribute__((deprecated)) import_test_request_t *import_test_request_create(
    char *api_key,
    char *provider
);

void import_test_request_free(import_test_request_t *import_test_request);

import_test_request_t *import_test_request_parseFromJSON(cJSON *import_test_requestJSON);

cJSON *import_test_request_convertToJSON(import_test_request_t *import_test_request);

#endif /* _import_test_request_H_ */

