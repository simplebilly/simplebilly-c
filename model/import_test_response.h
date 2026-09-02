/*
 * import_test_response.h
 *
 * 
 */

#ifndef _import_test_response_H_
#define _import_test_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct import_test_response_t import_test_response_t;




typedef struct import_test_response_t {
    char *error; // string
    int *ok; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} import_test_response_t;

__attribute__((deprecated)) import_test_response_t *import_test_response_create(
    char *error,
    int *ok
);

void import_test_response_free(import_test_response_t *import_test_response);

import_test_response_t *import_test_response_parseFromJSON(cJSON *import_test_responseJSON);

cJSON *import_test_response_convertToJSON(import_test_response_t *import_test_response);

#endif /* _import_test_response_H_ */

