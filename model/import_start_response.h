/*
 * import_start_response.h
 *
 * 
 */

#ifndef _import_start_response_H_
#define _import_start_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct import_start_response_t import_start_response_t;




typedef struct import_start_response_t {
    char *job_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} import_start_response_t;

__attribute__((deprecated)) import_start_response_t *import_start_response_create(
    char *job_id
);

void import_start_response_free(import_start_response_t *import_start_response);

import_start_response_t *import_start_response_parseFromJSON(cJSON *import_start_responseJSON);

cJSON *import_start_response_convertToJSON(import_start_response_t *import_start_response);

#endif /* _import_start_response_H_ */

